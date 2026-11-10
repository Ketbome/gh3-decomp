#!/usr/bin/env python3
"""
Gera o "cola" de link do port:

  * stubs fracos para as funcoes que ainda estao em assembly MIPS;
  * stubs para as funcoes dos arquivos que nao compilam em ARM (asm MIPS/VU0);
  * uma arena .bss que preserva o layout dos globais do jogo;
  * a lista de fontes compilaveis para o CMake.

Por que isso e' necessario
--------------------------
A arvore decompilada compila para ARM, mas:

  * 2.852 funcoes ainda sao `INCLUDE_ASM(...)`, que puxa um .s MIPS;
  * alguns .cpp tem asm MIPS inline (registradores nomeados, VU0, `pextlw`),
    que o gcc do ARM recusa — esses arquivos inteiros ficam de fora e suas
    funcoes viram stub, senao o link quebra;
  * todo global `D_XXXXXXXX` vive em `asm/data` (nao versionado).

O nome splat carrega o endereco (`D_00372A80` = 0x00372A80), o que permite
reconstruir o layout sem o binario original. A arena e' ancorada em 0x32A080
(inicio de .data), entao `gh3_data_arena + (0x372A80 - 0x32A080)` e' o
`D_00372A80` original — e o blob extraido do ISO pode ser copiado direto.

Uso (a partir da raiz do clone do gh3-decomp):
    python vita/tools/gen_stubs.py --repo . --out build-vita/generated

Saidas:
    stubs_asm.cpp         definicoes fracas
    data_arena.cpp        rotulos .bss no layout original
    engine_sources.cmake  fontes compilaveis + excluidas
    port_blockers.txt     worklist de limpeza (bloqueio por arquivo ou por funcao)
    patched/*.cpp         copia com o #include de libc que faltava
    split/*.cpp           copia dos arquivos bloqueados sem as funcoes sujas (A1)
    split/manifest.txt    o que ficou, o que saiu e por que

Fatiador por funcao (Marco A1)
------------------------------
"89 arquivos bloqueados" e' a unidade errada: nesses arquivos ha ~2.600 funcoes
ja escritas em C++ e apenas ~150 com asm MIPS/`mode(TI)`. Este gerador separa
as duas coisas: emite em split/<arquivo>.cpp o mesmo arquivo com as funcoes
sujas apagadas (linhas em branco, para o numero de linha continuar batendo com
o original) e deixa essas funcoes cobertas pelos stubs fracos. `src/game` nunca
e' alterado.
"""

from __future__ import annotations

import argparse
import hashlib
import re
import shutil
import sys
from bisect import bisect_right
from collections import Counter
from pathlib import Path

INCLUDE_ASM = re.compile(r'INCLUDE_ASM\(\s*"[^"]*"\s*,\s*([A-Za-z_]\w*)\s*\)')
FUNC_NAME = re.compile(r"\bfunc_[0-9A-Fa-f]{8}\b")
DATA_NAME = re.compile(r"\b(?:D_|jtbl_)[0-9A-Fa-f]{8}\b")
# Nomes D_XXXXXXXX que sao tags de struct/class, nao globais (o decomp batiza os
# tipos pelo endereco da vtable). Sem isso, `struct D_0018A898 { ... }` vira um
# global fantasma no link.
TAG_DECL = re.compile(r"\b(?:struct|class|union|enum)\s+(D_[0-9A-Fa-f]{8})\b")
# Declaracao/definicao que devolve float ou double (o resto dos stubs devolve int).
FLOAT_DECL = re.compile(
    r'^\s*(?:extern\s+"C"\s+)?(float|double)\s+(\w+)\s*\(', re.M)

# Inicio de .data no original (config/SLUS_216.72.yaml: vram 0x0032A080).
ARENA_BASE = 0x0032A080
# Fim de .bss: .bss comeca em 0x00373400 e bss_size = 0xB5E08 (yaml). A arena
# cobre o intervalo inteiro de dados do executavel, entao qualquer indice de
# array que era valido no PS2 continua dentro dela.
IMAGE_DATA_END = 0x00429208

# Asm que o gcc do ARM recusa. O jogo so' tem asm MIPS, mas nem todo asm()
# e' MIPS: `extern int x __asm__("D_00368A38")` e' rotulo de simbolo (vale em
# ARM) e `asm(".set a, b")` tambem. O que quebra e' instrucao de verdade, e ela
# sempre tem operando (%N), registrador ($N) ou mais de uma instrucao (\n).
ASM_LITERAL = re.compile(
    r'(?:__asm__|\basm)\s*(?:volatile\s*|__volatile__\s*)?'
    r'\(\s*"((?:[^"\\]|\\.)*)"')

# Instrucoes sem operando que ainda assim nao existem no ARM.
MIPS_BARE_MNEMONICS = {
    "nop", "sync", "sync.p", "di", "ei", "eret", "syscall", "break",
    "vcallms", "vnop", "vwaitq",
}

# Tipos que o ee-gcc aceita e o gcc do ARMv7 nao tem. TImode (inteiro de 128
# bits) nao existe em alvo de 32 bits: o typedef nem compila.
NO_ARM_TYPE = re.compile(r"mode\s*\(\s*TI\s*\)|\b__int128\b")


def asm_blocker(text: str) -> str | None:
    for body in ASM_LITERAL.findall(text):
        b = body.strip()
        if not b or b.startswith((".set ", ".extern ")):
            continue
        if "%" in b or "$" in b or "\\n" in b:
            return "asm MIPS inline"
        if b.split()[0].lower() in MIPS_BARE_MNEMONICS:
            return "asm MIPS inline"
    return None


# ee-gcc 2.95 tratava chamada sem declaracao como warning; o GCC atual erra.
# Estes nomes, quando usados sem declaracao no arquivo, ganham o #include
# correspondente numa copia em generated/patched/. Nao declaramos libc no
# prelude global porque varios arquivos do decomp declaram os mesmos simbolos
# com assinaturas proprias (ex.: `int strlen(char*)`), e isso conflitaria.
LIBC_HEADERS = {
    "string.h": "memcpy memset memmove memcmp strlen strcmp strncmp strcpy "
                "strncpy strcat strchr strrchr strstr strdup".split(),
    "math.h":   "fabs floor ceil fmod exp log log10 sin cos tan asin acos atan "
                "atan2 pow sqrt ldexp frexp modf floorf ceilf fmodf expf logf "
                "sinf cosf tanf asinf acosf atanf atan2f powf sqrtf fabsf".split(),
    "stdlib.h": "abs labs atoi atof atol rand srand qsort bsearch malloc "
                "calloc realloc free exit abort getenv system".split(),
    "stdio.h":  "printf fprintf sprintf snprintf vsnprintf sscanf puts putchar "
                "fopen fclose fread fwrite".split(),
    "ctype.h":  "toupper tolower isalpha isdigit isspace".split(),
}
LIBC_NAME_TO_HEADER = {name: header for header, names in LIBC_HEADERS.items()
                       for name in names}
LIBC_CALL = re.compile(r"\b(" + "|".join(sorted(LIBC_NAME_TO_HEADER)) + r")\s*\(")


def load_functions(repo: Path) -> dict[str, str]:
    """name -> arquivo de origem (ex.: t_10C000)."""
    path = repo / "config" / "functions.txt"
    if not path.exists():
        sys.exit(f"nao encontrei {path}; rode configure.py antes")
    funcs: dict[str, str] = {}
    for line in path.read_text(encoding="utf-8", errors="replace").splitlines():
        line = line.strip()
        if not line or line.startswith("#"):
            continue
        parts = line.split()
        if len(parts) >= 3:
            funcs[parts[0]] = parts[3] if len(parts) > 3 else ""
    return funcs


def source_files(repo: Path) -> list[Path]:
    game = repo / "src" / "game"
    if not game.is_dir():
        sys.exit(f"nao encontrei {game}")
    return sorted(list(game.glob("*.cpp")) + list(game.glob("*.c")))


def blockers(text: str) -> list[str]:
    """Todos os motivos que impedem o arquivo de compilar em ARM."""
    reasons: list[str] = []
    if NO_ARM_TYPE.search(text):
        reasons.append("inteiro de 128 bits (mode(TI))")
    if asm_blocker(text):
        reasons.append("asm MIPS inline")
    return reasons


def find_blocked(files: list[Path]) -> dict[Path, list[str]]:
    blocked: dict[Path, list[str]] = {}
    for path in files:
        text = path.read_text(encoding="utf-8", errors="replace")
        reasons = blockers(text)
        if reasons:
            blocked[path] = reasons
    return blocked


# ---------------------------------------------------------------------------
# Fatiador por funcao (Marco A1)
# ---------------------------------------------------------------------------
# O bloqueio e' por arquivo, mas o problema e' por funcao: um TU de 60 funcoes
# costuma ter 1 ou 2 com asm MIPS/`mode(TI)`. Aqui as funcoes sujas sao
# apagadas (linhas em branco, para o numero de linha continuar batendo com o
# original) e o resto do arquivo passa a compilar. As funcoes apagadas
# continuam cobertas pelos stubs fracos.

# Corpo de struct/classe/enum/namespace: nao e' funcao, nao entra na varredura.
TYPE_BLOCK = re.compile(
    r'^\s*(?:typedef\s+)?(?:struct|class|union|enum|namespace)\b')
# `extern "C" {` sem nome: as funcoes dentro contam como de topo. O mask_code
# apaga o literal "C", entao no texto mascarado a assinatura e' so' `extern`.
EXTERN_C_BLOCK = re.compile(r'^\s*extern\s*$')
CALL_NAME = re.compile(r'([A-Za-z_]\w*)\s*\(')
NOT_A_NAME = {
    "if", "for", "while", "switch", "return", "sizeof", "do", "else", "catch",
    "typeof", "__typeof__", "alignof", "_Alignof", "decltype", "static_assert",
}
# `typedef unsigned int u128_X __attribute__((mode(TI)));` -> shim de 16 bytes.
# Mantem sizeof == 16 e alinhamento 16 (o layout que o PS2 tinha). Aritmetica
# com o tipo continua sem compilar de proposito: a funcao que tentar isso vira
# suja no proximo ciclo, em vez de gerar codigo errado em silencio.
TI_TYPEDEF = re.compile(
    r'^(\s*)typedef\s+[^;{}]*?(\w+)\s+'
    r'__attribute__\s*\(\(\s*mode\s*\(\s*TI\s*\)\s*\)\)\s*;\s*$')
TI_SHIM = ("{indent}typedef struct {{ unsigned long long lo, hi; }} {name} "
           "__attribute__((aligned(16)));  // A1: mode(TI) -> shim")


class FuncSpan:
    __slots__ = ("start", "end", "name", "is_static", "header", "reason")

    def __init__(self, start: int, end: int, name: str, is_static: bool,
                 header: str = ""):
        self.start = start      # primeiro caractere da assinatura
        self.end = end          # '}' que fecha o corpo
        self.name = name
        self.is_static = is_static
        self.header = header    # assinatura crua, para o prototipo de reserva
        self.reason = ""        # vazio = funcao limpa


def mask_code(text: str) -> str:
    """Troca comentarios/strings/caracteres por espacos, mantendo os offsets.

    Sem isso um `{` dentro de comentario ou de string desalinha a contagem de
    chaves. Os proprios comentarios deste repo dizem "asm MIPS inline".
    """
    out = list(text)
    i, n = 0, len(text)
    while i < n:
        c = text[i]
        if c == "/" and i + 1 < n and text[i + 1] == "/":
            j = text.find("\n", i)
            j = n if j < 0 else j
        elif c == "/" and i + 1 < n and text[i + 1] == "*":
            j = text.find("*/", i + 2)
            j = n if j < 0 else j + 2
        elif c in "\"'":
            j = i + 1
            while j < n:
                if text[j] == "\\":
                    j += 2
                    continue
                if text[j] == c:
                    j += 1
                    break
                j += 1
        else:
            i += 1
            continue
        for k in range(i, min(j, n)):
            if out[k] != "\n":
                out[k] = " "
        i = j
    return "".join(out)


def _header_of(masked: str, open_pos: int) -> tuple[int, str]:
    """Inicio (1o char nao-branco) e texto da assinatura antes de `{`."""
    j = open_pos - 1
    while j >= 0 and masked[j] not in ";{}":
        j -= 1
    start = j + 1
    while start < open_pos and masked[start].isspace():
        start += 1
    return start, masked[start:open_pos]


def _function_name(header: str) -> str:
    names = [m.group(1) for m in CALL_NAME.finditer(header)
             if m.group(1) not in NOT_A_NAME
             and not m.group(1).startswith("__")]
    return names[-1] if names else ""


def find_functions(text: str) -> tuple[list[FuncSpan], str]:
    """Funcoes definidas no nivel de arquivo (topo ou dentro de extern "C")."""
    masked = mask_code(text)
    pairs: list[tuple[int, int, int]] = []   # (open, close, parent_open)
    stack: list[int] = []
    for i, c in enumerate(masked):
        if c == "{":
            stack.append(i)
        elif c == "}" and stack:
            pairs.append((stack.pop(), i, stack[-1] if stack else -1))

    kind: dict[int, str] = {}
    header: dict[int, tuple[int, str]] = {}
    for open_pos, _close, _parent in pairs:
        start, h = _header_of(masked, open_pos)
        header[open_pos] = (start, h)
        hs = h.strip()
        if EXTERN_C_BLOCK.match(hs):
            kind[open_pos] = "extern"
        elif TYPE_BLOCK.match(hs):
            kind[open_pos] = "type"
        elif ")" in hs:
            kind[open_pos] = "func"
        else:
            kind[open_pos] = "other"

    out: list[FuncSpan] = []
    for open_pos, close_pos, parent in pairs:
        if kind[open_pos] != "func":
            continue
        # `if (x) {` dentro de uma funcao tem parent "func": nao e' definicao.
        if parent != -1 and kind.get(parent) != "extern":
            continue
        start, h = header[open_pos]
        name = _function_name(h)
        if not name:
            continue
        raw_header = " ".join(text[start:open_pos].split())
        out.append(FuncSpan(start, close_pos, name,
                            bool(re.search(r"\bstatic\b", h)),
                            raw_header))
    out.sort(key=lambda s: s.start)
    return out, masked


def split_text(text: str) -> tuple[str, list[FuncSpan], list[FuncSpan]] | None:
    """Devolve (arquivo fatiado, funcoes mantidas, funcoes removidas).

    None quando nao ha nada a salvar (nenhuma funcao de arquivo ou nenhuma
    funcao limpa).
    """
    spans, masked = find_functions(text)
    if not spans:
        return None

    # Funcao cuja assinatura usa um tipo mode(TI) nao cabe na ABI do ARM (128
    # bits voltam por ponteiro oculto): trata como suja mesmo com corpo limpo.
    ti_names = {m.group(2)
                for m in (TI_TYPEDEF.match(line) for line in text.splitlines())
                if m}

    clean: list[FuncSpan] = []
    dirty: list[FuncSpan] = []
    for span in spans:
        body = text[span.start:span.end + 1]
        if NO_ARM_TYPE.search(body):
            span.reason = "mode(TI)/__int128 no corpo"
        elif asm_blocker(body):
            span.reason = "asm MIPS inline"
        elif any(re.search(r"\b" + re.escape(n) + r"\b", body) for n in ti_names):
            span.reason = "usa tipo mode(TI)"
        if span.reason:
            dirty.append(span)
        else:
            clean.append(span)

    # Fechamento: helper `static inline` removido e' chamado por funcao limpa ->
    # a limpa tambem nao compila (nao ha stub para simbolo static). Itera ate'
    # estabilizar.
    helpers = {s.name for s in dirty if s.is_static}
    changed = True
    while changed and helpers:
        changed = False
        for span in list(clean):
            body = text[span.start:span.end + 1]
            if any(re.search(r"\b" + re.escape(h) + r"\b", body)
                   for h in helpers):
                span.reason = "chama helper removido"
                clean.remove(span)
                dirty.append(span)
                changed = True
                if span.is_static:
                    helpers.add(span.name)

    if not clean:
        return None

    lines = text.splitlines(keepends=True)
    offsets = [0]
    for line in lines:
        offsets.append(offsets[-1] + len(line))

    def line_index(off: int) -> int:
        return min(bisect_right(offsets, off) - 1, len(lines) - 1)

    drop = [False] * len(lines)
    for span in dirty:
        for i in range(line_index(span.start), line_index(span.end) + 1):
            drop[i] = True

    # Funcao suja vira so' o prototipo. Duas razoes: (a) quem chama a funcao
    # depois no arquivo continua com a declaracao em escopo — sem isso o GCC
    # moderno recusa a chamada ("not declared in this scope"), o que o ee-gcc
    # 2.95 aceitava; (b) a ordem original e' preservada, entao qualquer chamada
    # ja' declarada antes continua valida. O corpo e' coberto pelo stub fraco.
    decl_at: dict[int, str] = {}
    for span in dirty:
        if span.header:
            decl_at[line_index(span.start)] = span.header + ";"

    out: list[str] = []
    shimmed: set[str] = set()
    for i, line in enumerate(lines):
        if drop[i]:
            if i in decl_at:
                out.append(decl_at[i] + "\n")
            else:
                out.append("\n" if line.endswith("\n") else "")
            continue
        m = TI_TYPEDEF.match(line)
        if m:
            # O mesmo typedef pode aparecer duas vezes no arquivo (t_20EE10).
            # Repetir o shim criaria dois tipos anonimos distintos com o mesmo
            # nome; so' o primeiro vale.
            if m.group(2) not in shimmed:
                shimmed.add(m.group(2))
                out.append(TI_SHIM.format(indent=m.group(1),
                                          name=m.group(2)) + "\n")
            else:
                out.append("\n" if line.endswith("\n") else "")
            continue
        out.append(line)

    result = "".join(out)
    # Sobrou mode(TI) fora de funcao e que nao era um typedef conhecido: nao ha
    # como compilar a copia, entao o arquivo inteiro continua excluido.
    if NO_ARM_TYPE.search(mask_code(result)):
        return None
    return result, clean, dirty


def split_blocked_files(blocked: dict[Path, list[str]], out: Path
                        ) -> tuple[dict[Path, Path], set[str]]:
    """Emite generated/split/<arquivo> e devolve (mapa, funcoes liberadas)."""
    split_dir = out / "split"
    if split_dir.is_dir():
        shutil.rmtree(split_dir)
    split_dir.mkdir(parents=True, exist_ok=True)

    mapping: dict[Path, Path] = {}
    freed: set[str] = set()
    manifest: list[str] = [
        "# Fatiador por funcao (Marco A1) - gerado por vita/tools/gen_stubs.py",
        "# <arquivo> mantidas=<n> removidas=<n>",
        "#   - <funcao>  <motivo>  sha1=<hash do corpo removido>",
    ]

    for path in sorted(blocked):
        text = path.read_text(encoding="utf-8", errors="replace")
        split = split_text(text)
        if split is None:
            manifest.append(f"{path.name} mantidas=0 removidas=0 "
                            f"(bloqueio de arquivo)")
            continue
        body, clean, dirty = split
        body = patch_text(body, path.name)
        dst = split_dir / path.name
        dst.write_text(body, encoding="utf-8")
        mapping[path] = dst
        freed |= {span.name for span in clean}
        manifest.append(f"{path.name} mantidas={len(clean)} "
                        f"removidas={len(dirty)}")
        for span in dirty:
            digest = hashlib.sha1(
                text[span.start:span.end + 1].encode("utf-8", "replace")
            ).hexdigest()[:12]
            manifest.append(f"  - {span.name}  {span.reason}  sha1={digest}")

    (split_dir / "manifest.txt").write_text("\n".join(manifest) + "\n",
                                            encoding="utf-8")
    return mapping, freed



def declared_in_line(line: str, name: str) -> bool:
    """A linha declara `name` (prototipo local), sem ser chamada?"""
    s = line.strip()
    if not s.endswith(";") or "=" in s:
        return False
    if s.startswith(("return", "if", "while", "for", "else", "case", "}")):
        return False
    # Tipo(s) + nome + parametros + ';', sem '=' (nao e' chamada).
    return bool(re.match(r'^(?:extern\s+"C"\s+)?(?:[A-Za-z_]\w*[\s\*]+)+'
                         r'[*\s]*' + name + r'\s*\(', s))


def declared_names(text: str, used: set[str]) -> set[str]:
    """Nomes de `used` que o arquivo declara (prototipo local)."""
    out: set[str] = set()
    for line in text.splitlines():
        for name in used - out:
            if declared_in_line(line, name):
                out.add(name)
    return out


# ee-gcc 2.95 lia `T f();` como "parametros nao especificados" e aceitava
# chamar f com qualquer numero de argumentos; C++ moderno le `()` como "sem
# parametros" e recusa a chamada. O original precisa continuar byte-identico
# para a arvore de matching, entao a correcao vai so na copia em patched/.
# Formato: (arquivo, regex, substituicao).
PORT_FIXUPS: list[tuple[str, str, str]] = [
    # chamada: func_002DDBB0(p, buf), com S2DD9F0 *p e char buf[8].
    ("t_2DCE78.cpp", r"float func_002DDBB0\(\)",
     "float func_002DDBB0(S2DD9F0 *, char *)"),
    ("t_2DCE78.cpp", r"float func_002DDBB0\(void\)",
     "float func_002DDBB0(S2DD9F0 *, char *)"),
]


def patch_text(text: str, name: str) -> str:
    """Aplica os ajustes de compilacao a um texto (original ou fatiado).

    Ver patch_sources(): include do header de libc implicito, remocao das
    declaracoes locais conflitantes e as reescrituras de PORT_FIXUPS.
    """
    used = set(LIBC_CALL.findall(text))
    missing = used - declared_names(text, used) if used else set()
    headers = sorted({LIBC_NAME_TO_HEADER[n] for n in missing
                      if n in LIBC_NAME_TO_HEADER})

    # Nomes que os headers escolhidos passam a declarar: as declaracoes
    # locais deles viram redundantes e potencialmente conflitantes.
    header_names = {n for h in headers for n in LIBC_HEADERS[h]}
    drop = declared_names(text, header_names) if header_names else set()

    fixups = [(pat, rep) for fname, pat, rep in PORT_FIXUPS if fname == name]
    if not headers and not drop and not fixups:
        return text

    lines = text.splitlines()
    if drop:
        lines = [l for l in lines
                 if not any(declared_in_line(l, n) for n in drop)]

    insert_at = 0
    for i, line in enumerate(lines):
        if line.lstrip().startswith("#include"):
            insert_at = i + 1

    body = "\n".join(lines[:insert_at] +
                     [f"#include <{h}>" for h in headers] +
                     lines[insert_at:]) + "\n"
    for pattern, replacement in fixups:
        body = re.sub(pattern, replacement, body)
    return body


def patch_sources(files: list[Path], out: Path) -> dict[Path, Path]:
    """Copia para generated/patched/ os arquivos que precisam de ajuste.

    O original nunca e' alterado. Cada copia leva:
      * o `#include` do header de libc cujas funcoes o arquivo chama sem
        declarar (o ee-gcc 2.95 so avisava);
      * a remocao das declaracoes locais dessas mesmas funcoes, que o header
        passa a fornecer com a assinatura certa — sem isso um arquivo que
        declara `void memset(void*, int, int)` conflita com <string.h>;
      * as reescritas de PORT_FIXUPS, que existem porque o original nao e'
        C++ valido fora do ee-gcc.
    """
    patched_dir = out / "patched"
    mapping: dict[Path, Path] = {}

    for path in files:
        text = path.read_text(encoding="utf-8", errors="replace")
        body = patch_text(text, path.name)
        if body == text:
            continue
        patched_dir.mkdir(parents=True, exist_ok=True)
        dst = patched_dir / path.name
        dst.write_text(body, encoding="utf-8")
        mapping[path] = dst

    return mapping


def collect(files: list[Path], game_funcs: dict[str, str],
            blocked: dict[Path, list[str]], freed: set[str]
            ) -> tuple[set[str], set[str], dict[str, str]]:
    text = "\n".join(p.read_text(encoding="utf-8", errors="replace")
                     for p in files)

    asm_funcs = set(INCLUDE_ASM.findall(text))
    referenced = set(FUNC_NAME.findall(text))

    # Funcao de arquivo bloqueado que nao sobreviveu ao fatiador nao sera
    # compilada: vira stub. As que sobreviveram estao na copia split/.
    blocked_stems = {p.stem for p in blocked}
    from_blocked = {name for name, src in game_funcs.items()
                    if src in blocked_stems} - freed

    # Funcao do jogo que nao esta em INCLUDE_ASM esta implementada em C++.
    # Qualquer outro nome referenciado (Sony SDK, GameSpy, libm) nao existe no
    # repositorio: vira stub.
    stubs = asm_funcs | from_blocked | (referenced - set(game_funcs))

    # Retorno float/double muda o registrador de retorno no ARM (s0/d0 em vez
    # de r0): o stub precisa da assinatura certa. Ver write_stubs().
    float_returns: dict[str, str] = {}
    for typ, name in FLOAT_DECL.findall(text):
        if name in stubs:
            float_returns.setdefault(name, typ)

    data_names = set(DATA_NAME.findall(text)) - set(TAG_DECL.findall(text))
    return stubs, data_names, float_returns


def write_stubs(out: Path, stubs: set[str],
                float_returns: dict[str, str]) -> None:
    lines = [
        "// Gerado por vita/tools/gen_stubs.py - nao editar.",
        "// Definicoes fracas: qualquer implementacao forte linkada vence.",
        "//",
        "// Telemetria (Marco B1): cada stub tem contador estatico e chama",
        "// gh3::hle::stub_hit() uma unica vez, na primeira execucao. O caminho",
        "// quente custa um incremento; o resto (strcmp, log, relatorio) so",
        "// acontece no primeiro acerto.",
        '#include "gh3/ps2hle.h"',
        "",
        'extern "C" {',
    ]
    for name in sorted(stubs):
        # ABI: no ARM (hard-float) float/double voltam em s0/d0, nao em r0. Um
        # stub `int f(void)` faria o chamador ler lixo de s0. Quando o decomp
        # declara o retorno como float/double, o stub devolve 0.0 no registrador
        # certo.
        ret = float_returns.get(name, "int")
        zero = {"float": "0.0f", "double": "0.0"}.get(ret, "0")
        # __builtin_return_address(0) e' o LR salvo na entrada do stub: aponta
        # para dentro de quem chamou, que e' o que o relatorio precisa.
        lines.append(f'__attribute__((weak)) {ret} {name}(void) {{')
        lines.append('    static unsigned hits = 0;')
        lines.append('    static bool seen = false;')
        lines.append('    ++hits;')
        lines.append('    if (!seen) {')
        lines.append('        seen = true;')
        lines.append(f'        gh3::hle::stub_hit("{name}", &hits,'
                     ' __builtin_return_address(0));')
        lines.append('    }')
        lines.append(f'    return {zero};')
        lines.append('}')
    lines += ["}", ""]
    (out / "stubs_asm.cpp").write_text("\n".join(lines), encoding="utf-8")


def write_data_arena(out: Path, data_names: set[str], tail: int) -> tuple[int, int]:
    # Agrupa por endereco para preservar aliases (mesmo endereco, nomes varios).
    by_addr: dict[int, list[str]] = {}
    for name in data_names:
        addr = int(name.split("_", 1)[1], 16)
        by_addr.setdefault(addr, []).append(name)

    below = sorted(a for a in by_addr if a < ARENA_BASE)
    if below:
        print(f"aviso: {len(below)} simbolo(s) abaixo de 0x{ARENA_BASE:08X} "
              f"ignorados", file=sys.stderr)

    addrs = sorted(a for a in by_addr if a >= ARENA_BASE)

    if not addrs:
        (out / "data_arena.cpp").write_text(
            "// Gerado por vita/tools/gen_stubs.py - nenhum global referenciado.\n",
            encoding="utf-8")
        return 0, 0

    last = addrs[-1]
    # Cobre o .bss inteiro do original, mesmo que o ultimo global referenciado
    # seja anterior: arrays sem tamanho declarado podem ir alem dele.
    end = max(last + tail, IMAGE_DATA_END)

    asm: list[str] = [
        ".section .bss",
        ".balign 128",
        ".globl gh3_data_arena",
        "gh3_data_arena:",
    ]

    cursor = ARENA_BASE
    for addr in addrs:
        gap = addr - cursor
        if gap > 0:
            asm.append(f".space {gap:#x}")
        for name in sorted(by_addr[addr]):
            asm.append(f".globl {name}")
            asm.append(f"{name}:")
        cursor = addr

    asm += [
        f".space {end - last:#x}",
        ".globl gh3_data_arena_end",
        "gh3_data_arena_end:",
        ".text",
    ]

    size = end - ARENA_BASE
    src = [
        "// Gerado por vita/tools/gen_stubs.py - nao editar.",
        "//",
        f"// Arena unica ancorada em 0x{ARENA_BASE:08X} (inicio de .data) e",
        f"// estendida ate 0x{end:08X} (cobre o .bss do original, com folga).",
        "// Os globais ficam nos mesmos offsets relativos; aliases continuam aliases.",
        "//",
        "// Ainda zerada: o carregador de assets deve copiar os bytes de",
        "// .data/.rodata/.sdata (ROM 0x22A080..0x272A40) para gh3_data_arena.",
        "",
        'extern "C" {',
        "extern unsigned char gh3_data_arena[];",
        "extern unsigned char gh3_data_arena_end[];",
        "}",
        "",
        '__asm__(',
    ]
    for line in asm:
        src.append(f'    "{line}\\n"')
    src += [");", ""]

    (out / "data_arena.cpp").write_text("\n".join(src), encoding="utf-8")
    return last, size


def write_engine_sources(out: Path, files: list[Path],
                         blocked: dict[Path, list[str]],
                         patched: dict[Path, Path],
                         split: dict[Path, Path]) -> tuple[int, int]:
    # Bloqueado mas fatiado: compila a copia sem as funcoes sujas. Bloqueado e
    # nao fatiado: fica de fora e todas as funcoes dele viram stub.
    compilable = [split.get(p, patched.get(p, p))
                  for p in files if p not in blocked or p in split]
    excluded = sorted(p for p in blocked if p not in split)

    lines = [
        "# Gerado por vita/tools/gen_stubs.py - nao editar.",
        "set(GH3_ENGINE_SOURCES",
    ]
    for path in compilable:
        lines.append(f'    "{path.resolve().as_posix()}"')
    lines += [")", "", "set(GH3_ENGINE_EXCLUDED"]
    for path in excluded:
        lines.append(f'    "{path.resolve().as_posix()}"')
    lines += [")", ""]

    (out / "engine_sources.cmake").write_text("\n".join(lines),
                                              encoding="utf-8")
    return len(compilable), len(excluded)


def write_blockers(out: Path, blocked: dict[Path, list[str]],
                   split: dict[Path, Path]) -> None:
    lines = [
        "# Arquivos que nao compilam no ARM sem limpeza, por motivo:",
        "#   asm MIPS inline            instrucao MIPS/VU0 (%, $, \\n, vcallms)",
        "#   inteiro de 128 bits        mode(TI)/__int128 (nao existe em ARMv7)",
        "# Gerado por vita/tools/gen_stubs.py.",
        "#",
        "# BLOQUEADO  arquivo inteiro fora do build; todas as funcoes sao stub.",
        "# FATIADO    so' as funcoes sujas sairam (ver split/manifest.txt).",
    ]
    for path, labels in sorted(blocked.items()):
        if path in split:
            continue
        lines.append(f"BLOQUEADO {path.name}: {', '.join(labels)}")
    for path in sorted(split):
        lines.append(f"FATIADO   {path.name}: funcoes sujas removidas da copia")
    (out / "port_blockers.txt").write_text("\n".join(lines) + "\n",
                                           encoding="utf-8")


def main() -> int:
    ap = argparse.ArgumentParser(
        description=__doc__,
        formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("--repo", default=".", type=Path)
    ap.add_argument("--out", default="build-vita/generated", type=Path)
    ap.add_argument("--data-tail", type=lambda s: int(s, 0), default=0x10000,
                    help="bytes reservados depois do ultimo global (default 0x10000)")
    args = ap.parse_args()

    repo: Path = args.repo
    out: Path = args.out
    out.mkdir(parents=True, exist_ok=True)

    # generated/patched/ e generated/split/ sao recriados do zero: uma copia
    # velha de um arquivo que virou bloqueado nao pode continuar no build.
    if (out / "patched").is_dir():
        shutil.rmtree(out / "patched")

    game_funcs = load_functions(repo)
    files = source_files(repo)
    blocked = find_blocked(files)
    patched = patch_sources(files, out)
    split, freed = split_blocked_files(blocked, out)

    stubs, data_names, float_returns = collect(files, game_funcs, blocked, freed)

    write_stubs(out, stubs, float_returns)
    last, size = write_data_arena(out, data_names, args.data_tail)
    compilable, excluded = write_engine_sources(out, files, blocked, patched,
                                                split)
    write_blockers(out, blocked, split)

    kinds = Counter()
    for name in stubs:
        if name in game_funcs:
            kinds["jogo (asm/bloqueado)"] += 1
        else:
            kinds["SDK/lib externa"] += 1

    print(f"repo            : {repo}")
    print(f"saida           : {out}")
    print(f"fontes          : {compilable} compilaveis, {excluded} bloqueadas")
    if patched:
        print(f"patched/        : {len(patched)} arquivo(s) copiado(s) "
              f"(libc implicita e/ou PORT_FIXUPS)")
    if split:
        print(f"split/          : {len(split)} arquivo(s) fatiado(s), "
              f"{len(freed)} funcao(oes) liberada(s) "
              f"({len(blocked) - len(split)} arquivo(s) ainda inteiros)")
    print(f"funcoes do jogo : {len(game_funcs)}")
    print(f"stubs gerados   : {len(stubs)}")
    for kind, count in kinds.most_common():
        print(f"  {kind:<22} {count}")
    if float_returns:
        print(f"  retorno float/double   {len(float_returns)} "
              f"(ABI: s0/d0, nao r0)")
    if size:
        print(f"arena de dados  : 0x{ARENA_BASE:08X}..0x{ARENA_BASE + size:08X} "
              f"({size / 1024:.0f} KiB, ultimo global 0x{last:08X}, "
              f"{len(data_names)} simbolos)")
    else:
        print("arena de dados  : nenhum global referenciado")
    print(f"bloqueios ARM   : {excluded} arquivos (ver port_blockers.txt)")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
