# gh-vita — camada de port

Port nativo de **Guitar Hero III (PS2, SLUS-21672)** para o PS Vita, sobre o
`gh3-decomp` (C++17 + SDL2 + vitaGL + VitaSDK).

Este diretório é a camada de plataforma. Ele **não** substitui a árvore de
matching: a raiz do clone continua sendo a referência byte-idêntica, compilada
com `ninja` e o ee-gcc. O CMake daqui só constrói o alvo Vita, e sempre em
`build-vita/` (nunca em `build/`, que pertence ao `configure.py`).

---

## 1. O que o `gh3-decomp` realmente é (e o que isso muda no port)

| Fato | Consequência para o port |
|---|---|
| O alvo original é **PS2 EE (MIPS R5900)**, não PC/Windows | Não existe camada Win32 para remover. O que existe é Sony SDK 3.0 + GS + VU1 + IOP. |
| `config/symbols/symbol_addrs.txt` só define `_start = 0x00103D08` | `_start` está em `.temp_init` (crt0), extraído do ISO pelo `configure.py` e **não versionado**. Não há `main()` em C++ no repositório. |
| 9.003 funções; 6.150 em C++, **2.852 ainda em `INCLUDE_ASM`** | Compilar `src/game` hoje produz um binário ARM com 2.852 símbolos indefinidos e `asm(...)` MIPS. Só faz sentido depois de stubs/shim. |
| Globais em endereços absolutos (`D_0037xxxx`) e acesso via `$gp` | No código recompilado para ARM os acessos viram relocations de símbolo — ok — mas os símbolos precisam existir no link do port. |
| `INCLUDE_ASM`, `GP_DATA`, `TEXT_PAD`, `OBJECT_END` emitem diretivas MIPS | Precisam virar no-op no build de port (`include/gh3/port_prelude.h`). |

Resumo: o port é **PS2 → Vita**, e o pré-requisito real é a fase 3 do
`ROADMAP.md` (build shiftable), não uma "limpeza de Windows".

---

## 2. Onde ficam o loop e a inicialização

Mapa verificado em `docs/text_map.md` + `config/`:

| Endereço | O que é | Arquivo |
|---|---|---|
| `0x00100000`–`0x00103E88` | crt0 (`.temp_init`); `_start = 0x103D08` | `asm/cod/temp_init.s` (gerado, não versionado) |
| `0x0010C000` | primeiro símbolo de `.text` — **candidato a `main`** | `src/game/t_10C000.cpp` (`func_0010C000`, 0x50 bytes) |
| `0x0010C000`–`0x002EC0B0` | engine Neversoft *nxcommon* + código GH3 | `src/game/t_*.cpp` |
| `0x002DFB70`–`0x002E62C0` | driver de som no EE (blocos de comando p/ thread IOP, 48 vozes) | `src/game/t_2DFB70.c`, `t_2DEE90.cpp` … `t_2E62C0.cpp` |
| `0x002EC0B0`–`0x002ED018` | GameSpy SDK | `asm/lib/gamespy` |
| `0x002ED018`–`0x0030C6C8` | Sony SDK 3.0: libpad2, libdma, libkernl, sifrpc, stdio, libdbc, libmc2, socket, libcdvd, libipu | `asm/lib/sce` |
| `0x0031F5D0`–`0x0032101C` | libgraph (`sceGsPutDrawEnv`) | `asm/lib/sce` |
| `0x00321080` | microcódigo VU1 (`.vutext`) | `asm/cod/vutext` |

Primitivas de frame já nomeadas (evidência: `config/symbols/cfuncs.txt`):

- `CFunc_WaitOneGameFrame` `0x00256B80` → `func_0028C470(b, 1)`: o "espera 1 frame" dos scripts QB.
- `CFunc_StartRendering_C` / `CFunc_StopRendering_C` `0x0025A8B0` / `0x0025A478` → `func_0014F750`.
- `CFunc_Update*PerFrame` (`GuitarInputLogicPerFrame` `0x002B8ED8`, `CheckNoteHoldPerFrame` `0x002C8C00`, …): chamadas por frame, não o loop.

Para confirmar `main` e o loop no **seu** ISO:

```bash
.venv/bin/python configure.py
python vita/tools/find_entry.py --repo .
python vita/tools/find_entry.py --repo . --dump func_0010C000
```

O script lê `asm/cod/temp_init.s`, lista os `jal` do crt0, mede o grafo de
chamadas e conta branches para trás (laço) de cada candidato.

---

## 3. Estrutura

```
<raiz do clone do gh3-decomp>/
  CMakeLists.txt                # raiz do port (toolchain VitaSDK autodetectado)
  src/game/t_*.cpp              # engine decompilada (referência, matching)
  include/                      # headers do decomp
  config/                       # split, símbolos, funções
  vita/
    CMakeLists.txt              # alvo, deps, .self/.vpk
    include/gh3/
      platform.h                # video/audio/input/tempo/log
      port.h                    # contrato engine <-> plataforma
      fs.h                      # VFS: caminhos PS2 -> ux0:data/gh3
      ps2hle.h                  # substituição da Sony SDK
      port_prelude.h            # no-op das macros MIPS no build de port
    src/
      main.cpp                  # init -> loop -> shutdown
      platform_vita.cpp         # vitaGL + SDL2 + SceCtrl
      fs_vita.cpp               # normalização de caminho e leitura
      ps2hle.cpp                # registro de handlers + log de faltantes
      engine_stub.cpp           # versões fracas (permite rodar hoje)
      engine_vita.cpp           # versões fortes: arena de dados + entrada do jogo
    tools/find_entry.py
    tools/gen_stubs.py          # stubs fracos + arena de dados
    tools/extract_data.py       # .data/.rodata/.sdata -> gh3_data.bin
```

O `CMakeLists.txt` da raiz só faz `add_subdirectory(vita)` e aponta
`GH3_DECOMP_DIR` para o próprio diretório; ele não interfere no `build.ninja`
do decomp.

O port é um **overlay local**: `vita/`, `CMakeLists.txt` e `build-vita/` estão
listados em `.git/info/exclude` (não versionado) para que `git status` continue
limpo e o fluxo do decomp (`dk state`, `scripts/integrate.sh`) não confunda o
cross-compile com trabalho de matching. Um clone novo precisa repetir essas
três linhas no `exclude`.

Ordem de inicialização (igual à do crt0 → `main`):

```
platform::init  ->  fs::init  ->  hle::init  ->  port::init
loop: pump_events -> begin_frame -> hle::vblank -> port::frame -> end_frame
```

`port::init/frame/shutdown/audio_render` são `weak` em `engine_stub.cpp` e
fortes em `engine_vita.cpp` (que só entra no build com
`-DGH3_BUILD_ENGINE=ON`, porque usa a arena gerada). Sem a flag, o binário roda
o stub: tela preta, pad lido, áudio em silêncio, combo START+SELECT sai.

Não há janela SDL: no Vita o driver de vídeo do SDL2 e o vitaGL disputam o GXM,
e quem manda no vídeo é o vitaGL. O SDL2 fica com áudio, timer e eventos.

Todo `platform::log` vai para `stderr` **e** para `ux0:data/gh3/log.txt`
(append, com timestamp). É o que permite diagnosticar o bring-up no hardware.

---

## 4. Build

Requer VitaSDK com SDL2 e vitaGL. No Windows, use WSL2 ou MSYS2 — o VitaSDK
oficial não roda no PowerShell nativo.

```bash
# instala sem sudo, num diretorio do usuario (~/vitasdk)
git clone --depth 1 https://github.com/vitasdk/vdpm ~/vdpm
VITASDK=$HOME/vitasdk bash ~/vdpm/bootstrap-vitasdk.sh
export VITASDK=$HOME/vitasdk
export PATH=$VITASDK/bin:$PATH

# os pacotes do canal sao minúsculos: `sdl2`, mas `vitaGL`
vdpm install sdl2 vitaGL
```

```bash
# ja com o VitaSDK instalado e no PATH
# na raiz do clone do gh3-decomp
cmake -S . -B build-vita -DCMAKE_BUILD_TYPE=Release
cmake --build build-vita -j
# build-vita/vita/gh3_vita.vpk
```

`build-vita/` é obrigatório: `build/` é do `configure.py`/`ninja` do decomp
(`build.ninja`, `build/SLUS_216.72.elf`). O CMake aborta se você apontar
`-B build`.

Verificado em 2026-11 (Ubuntu 26.04 / WSL2):

| Item | Versão |
|---|---|
| VitaSDK | série `2026.08`, instalada em `~/vitasdk` (sem sudo) |
| compilador | `arm-vita-eabi-gcc` 15.2.0 |
| CMake | 4.2.3 (gerador Makefiles) |
| SDL2 | `sdl2` 2.32.8, `vitaGL` r1488 |

Com `-DGH3_BUILD_ENGINE=ON` o configure gera `build-vita/generated/`, compila
os **224** arquivos de `src/game` (só `t_20CD50.cpp` fica de fora) e linka
tudo: `.text` 1,25 MiB, `.bss` 3,23 MiB (arena de 1082 KiB + libc + SDL),
`.vpk` 1.053.806 bytes. Nenhum erro.
`func_0010C050` sai como símbolo forte (`T`) e `func_0010C000` como fraco
(`W`), que é o esperado enquanto a entrada for `INCLUDE_ASM`.

Instalar:

```bash
# via VitaShell (USB/FTP): copie o .vpk para ux0: e instale
# ou:
curl -T build-vita/vita/gh3_vita.vpk ftp://<ip>:1337/ux0:/
```

Assets em `ux0:data/gh3/` (o `.pak` do disco do usuário; nada de dados do jogo
entra no repositório).

---

## 5. Stubs e arena de dados (`gen_stubs.py`)

Ligar `src/game` no ARM falha por quatro motivos, e o gerador resolve todos:

| Problema | Solução |
|---|---|
| 2.852 funções `INCLUDE_ASM` puxam `.s` MIPS | `stubs_asm.cpp`: `int func_XXXXXXXX(void)` **fraco**, loga uma vez e devolve 0 |
| 64 arquivos têm asm MIPS inline (`lqc2`, `mtc1`, `pextlw`, `register x asm("$7")`) | o **fatiador** (abaixo) apaga só as funções sujas e mantém o resto do arquivo |
| 59 arquivos usam `__attribute__((mode(TI)))` (inteiro de 128 bits) | o typedef vira um shim de 16 bytes alinhado a 16; quem faz aritmética com ele é marcado como sujo |
| Globais `D_XXXXXXXX` vivem em `asm/data` (não versionado) | `data_arena.cpp`: uma `.bss` com um rótulo por endereço, no **mesmo offset relativo** do original |

### 5.1 Fatiador por função (Marco A1)

"Arquivo bloqueado" era a unidade errada: nos 89 arquivos há **2.736 funções já
escritas em C++** e apenas **229** com asm MIPS/`mode(TI)`. O gerador varre cada
arquivo com contagem de chaves (ignorando comentários e strings), separa as
definições de topo (inclusive dentro de `extern "C" { }`) e emite em
`generated/split/<arquivo>.cpp` a mesma árvore **sem** as funções sujas.

Regras:

- a função suja é **apagada**, mas o protótipo dela fica no lugar (`assinatura;`).
  Sem isso, quem chama a função depois no arquivo falha com "not declared in this
  scope" — o ee-gcc 2.95 aceitava, o GCC 15 não. O corpo é coberto pelo stub
  fraco, e o linker resolve;
- as linhas apagadas viram **linhas em branco**, então o número de linha da
  cópia continua igual ao do original (útil para mapear erro de compilação →
  função);
- `static inline` removido e chamado por função limpa: a função limpa também é
  marcada como suja (não existe stub para símbolo `static`);
- typedef `mode(TI)` vira `typedef struct { unsigned long long lo, hi; } NOME
  __attribute__((aligned(16)));` — `sizeof` 16 e alinhamento 16, como no PS2.
  Aritmética com o tipo continua sem compilar **de propósito**: a função vira
  suja em vez de gerar código errado em silêncio;
- `src/game` nunca é alterado. O manifesto
  (`generated/split/manifest.txt`) lista, por arquivo, quantas funções ficaram,
  quais saíram, o motivo e o `sha1` do corpo removido.

Resultado: **88 dos 89 arquivos** passam a compilar; 2.505 funções entram no
build sem decompilar nada. `t_20CD50.cpp` continua inteiro fora porque sua única
função usa `register f32 k asm("$f20")` — não sobra nada para salvar.

O stub é `int f(void)` por padrão, mas **14 símbolos** são declarados no decomp
como retorno `float`/`double`. No ARM (hard-float) esses valores voltam em
`s0`/`d0`, não em `r0`: um stub `int` faria o chamador ler lixo. O gerador lê a
assinatura e emite `float f(void) { …; return 0.0f; }` nesses casos.

Structs devolvidos por valor (142 símbolos) ficam sem tratamento: no AAPCS o
chamador passa o endereço do buffer de retorno em `r0`, então o stub não escreve
nada e o chamador fica com lixo — sem crash, mas com dados inválidos. Se o tipo
tiver destrutor, o risco sobe. É worklist, não bloqueio de link.

`asm_blocker()` distingue três casos que parecem iguais:

- `extern int x __asm__("D_00368A38");` — rótulo de símbolo, **válido em ARM**, fica;
- `asm(".set a, b");` — alias do assembler, **válido em ARM**, fica;
- `asm("pextlw %0, %1, %2");` — instrução MIPS de verdade (tem `%N`, `$N` ou
  `\n`), **bloqueia o arquivo**.

O nome splat carrega o endereço (`D_00372A80` = `0x00372A80`), então o layout é
reconstruído sem o binário. Aliases (`D_00368A38_p` declarado com
`__asm__("D_00368A38")`) continuam sendo o mesmo endereço, não dois buffers.

```bash
python vita/tools/gen_stubs.py --repo . --out build-vita/generated
```

Saídas em `build-vita/generated/`:

| Arquivo | Papel |
|---|---|
| `stubs_asm.cpp` | definições fracas (asm MIPS + funções sujas + SDK) |
| `data_arena.cpp` | `.bss` de `0x32A080` até o fim de `.bss` (`0x429208`) |
| `engine_sources.cmake` | `GH3_ENGINE_SOURCES` / `GH3_ENGINE_EXCLUDED` |
| `port_blockers.txt` | worklist: `BLOQUEADO` (arquivo inteiro) / `FATIADO` |
| `patched/*.cpp` | cópia de arquivos que chamam libc sem declarar (ver abaixo) |
| `split/*.cpp` | cópia dos bloqueados sem as funções sujas (Marco A1) |
| `split/manifest.txt` | o que ficou, o que saiu, motivo e `sha1` |

Estado atual neste clone:

```
fontes          : 224 compilaveis, 1 bloqueada
split/          : 88 arquivos fatiados, 2505 funcoes liberadas
patched/        : 3 arquivos (2 libc implicita + 1 PORT_FIXUPS)
stubs gerados   : 3213  (3046 do jogo, 167 da SDK/lib externa)
                  retorno float/double: 14 (ABI: s0/d0)
arena de dados  : 0x0032A080..0x00438798 (1082 KiB, 1644 simbolos)
```

O decomp foi compilado com **ee-gcc 2.95**, que aceitava chamada implícita de
libc (`strlen`, `strcpy`) como warning. O GCC atual trata como erro, e não dá
para declarar libc no prelude global: vários arquivos declaram os mesmos
símbolos com assinatura própria (`int strlen(char*)`), o que conflitaria. Por
isso o gerador detecta o caso **por arquivo** e escreve uma cópia em
`patched/` com o `#include <string.h>`/`<math.h>` que faltava. O original nunca
é alterado.

A cópia também **remove** as declarações locais das funções que o header passa
a fornecer: `t_225BF0.cpp` declara `void memset(void*, int, int)` (assinatura
do ee-gcc), que conflita com o `void *memset(void*, int, size_t)` de
`<string.h>`. Sem a remoção, o `#include` quebra o arquivo.

Dois outros ajustes, ambos só na cópia:

| Caso | Por quê | Onde |
|---|---|---|
| `-fpermissive` no `gh3_engine` | `func_001D4600_r(h, key, func_X, func_Y)` passa ponteiro de função onde o parâmetro é `void*`; erro em C++, warning no ee-gcc | `vita/CMakeLists.txt` |
| `PORT_FIXUPS` | `t_2DCE78.cpp` declara `float func_002DDBB0();` e chama com 2 argumentos (`()` = "sem parâmetros" em C++ moderno). A cópia reescreve declaração e definição para `(S2DD9F0 *, char *)` | `gen_stubs.py` |

O CMake roda o gerador no **configure** (`execute_process`), não no build: a
lista de fontes é entrada do `add_library`, não um artefato posterior.

```bash
cmake -S . -B build-vita -DGH3_BUILD_ENGINE=ON   # roda gen_stubs.py
cmake --build build-vita -j
```

Ordem de link (importante):

```
gh3_engine       (forte, código real)  ->  gh3_engine_stubs  (fraco, lacunas)
```

Se os stubs viessem antes, o linker resolveria tudo por eles e nunca puxaria os
objetos reais da engine.

> A arena nasce **zerada**. `engine_vita.cpp` copia para ela o bloco de dados
> inicializados do executável (`gh3_data.bin`, ver seção 6); sem esse arquivo o
> port sobe, mas strings, tabelas `jtbl_*` e constantes `float` ficam zeradas.

> `GH3_BUILD_ENGINE=ON` compila a engine em ARM e `vita/src/engine_vita.cpp`
> define as versões fortes de `port::*`. Como a entrada (`func_0010C000`) ainda é
> `INCLUDE_ASM`, quem responde é o stub fraco — e o log diz isso. Hoje o único
> objeto real de `gh3_engine` que entra no binário é `t_10C000.o`, puxado pelo
> smoke test do RNG (`func_0010C050`); sem ele a biblioteca inteira ficaria de
> fora do `.self`. Quando a entrada for decompilada, o mesmo `extern "C"` passa
> a resolver para a versão forte e o `t_10C000.o` vem junto, sem mudar nada.

---

## 6. Dados do executável (`extract_data.py`)

O código recompilado para ARM acessa `D_XXXXXXXX` como símbolos — o linker do
Vita resolve o endereço, mas **o conteúdo** desses símbolos não existe em lugar
nenhum: no PS2 ele vinha de `.data`/`.rodata`/`.sdata` do executável. A arena
recria o *layout*; o blob preenche o *conteúdo*.

```bash
# na raiz do clone do gh3-decomp, uma vez: extrai disc/SLUS_216.72.rom do ISO
python configure.py

# no port: recorta o bloco inicializado
python vita/tools/extract_data.py   # -> build-vita/gh3_data.bin (290 KiB)
```

| | |
|---|---|
| Origem | ROM `0x22A080..0x272A40` (imagem plana: `vram - 0x100000`) |
| Destino | `vram 0x32A080..0x372A40` = início de `gh3_data_arena` |
| Conteúdo | `.data`, `.rodata`, `.gcc_except_table`, `.sdata` |
| Fora | `.sbss`/`.bss` (`0x372A80`+), que nascem zerados |

O intervalo é copiado **sem realocar nada**: `gh3_data_arena + (0x368080 -
0x32A080)` é exatamente o `D_00368080` original, incluindo ponteiros de vtable e
`jtbl_*` que apontam para funções do jogo. Como as funções viram stubs, esses
ponteiros apontam para código que ainda não existe — é o que o log de
`hle::unimplemented` vai revelar na ordem real de uso.

Copie o resultado para `ux0:data/gh3/gh3_data.bin`. Sem o arquivo o port sobe
com a arena zerada e loga o aviso (o bring-up atual, com a entrada em stub, não
lê esses dados).

---

## 7. Fases

1. **Bring-up** (este esqueleto): tela, pad, áudio, VFS, saída limpa.
2. **HLE da SDK**: mapear `0x2ED018`–`0x30C6C8` e `0x31F5D0`–`0x32101C` para
   `platform`/`fs`/vitaGL. O log de `hle::unimplemented` dá a ordem real.
3. **Stubs das 2.852 funções em asm**: `vita/tools/gen_stubs.py` (feito) +
   `-DGH3_BUILD_ENGINE=ON`. Hoje **224 dos 225** arquivos de `src/game`
   compilam: o fatiador (Marco A1) liberou 2.505 funções que estavam presas em
   arquivos com 1 ou 2 funções de asm MIPS. Sobram 229 funções com
   `lqc2/sqc2`, `mtc1/mfc1`, `pextlw/pcpyld` ou `mode(TI)`, mais as 2.852
   `INCLUDE_ASM`, para reescrever em C++/NEON.
4. **Entrada do jogo**: `func_0010C000` (`0x0010C000`) ainda é `INCLUDE_ASM`.
   Enquanto isso, `engine_vita.cpp` chama o stub e o log confirma o caminho.
   Decompilar essa função (ou reimplementá-la) é o que faz o port *rodar*.
5. **Substituir o renderer**: GS + VU1 → vitaGL. É a maior parte do trabalho.
6. **Áudio**: driver EE/IOP → SDL2 (mixer + streaming das músicas).
7. **Input**: libpad2 → SceCtrl (bits já compatíveis) + mapeamento de guitarra.

Enquanto a engine não compila em ARM (passo 3), o binário Vita roda o stub:
útil para validar toolchain, VPK, vsync, áudio e o combo de saída.
