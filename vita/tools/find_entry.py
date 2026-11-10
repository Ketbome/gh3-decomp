#!/usr/bin/env python3
"""
Localiza o main e o laco de frame do SLUS_216.72 no assembly gerado pelo splat.

Por que isso e' necessario: o repositorio do decomp nao contem um main() em C++.
O entry point (_start = 0x00103D08) esta em .temp_init (crt0), que o splat
extrai do disco do usuario para asm/cod/temp_init.s e nao versiona. O crt0 faz
um `jal` para o main da engine dentro de .text; este script encontra esse alvo,
depois mede o grafo de chamadas e os lacos de cada candidato.

Pre-requisito:
    .venv/bin/python configure.py      # gera asm/ e build/

Uso (a partir da raiz do clone do gh3-decomp):
    python vita/tools/find_entry.py --repo .
    python vita/tools/find_entry.py --repo . --dump func_0010C000
    python vita/tools/find_entry.py --repo . --indegree 15
"""

from __future__ import annotations

import argparse
import re
import sys
from collections import Counter
from pathlib import Path

ADDR_LINE = re.compile(r"^\s*/\*\s*([0-9A-Fa-f]{8})\s*\*/")
JAL_NUM = re.compile(r"\bjal\s+(?:0x)?([0-9A-Fa-f]{8})\b")
JAL_SYM = re.compile(r"\bjal\s+([A-Za-z_]\w*)")
J_NUM = re.compile(r"\bj\s+(?:0x)?([0-9A-Fa-f]{8})\b")
J_SYM = re.compile(r"\bj\s+([A-Za-z_]\w*)")
BRANCH = re.compile(
    r"\b(?:b|beq|bne|bgez|bgtz|blez|bltz|bgezal|bltzal|bc1t|bc1f"
    r"|beql|bnel|bgezl|bgtzl|blezl|bltzl)\s+\.L([0-9A-Fa-f]{8})"
)

TEXT_START = 0x0010C000
TEXT_END = 0x002EC0B0


class Func:
    __slots__ = ("name", "addr", "size", "src", "calls", "back_branches")

    def __init__(self, name: str, addr: int = 0, size: int = 0, src: str = ""):
        self.name = name
        self.addr = addr
        self.size = size
        self.src = src
        self.calls: list[str] = []
        self.back_branches = 0


def load_functions(repo: Path) -> dict[str, Func]:
    path = repo / "config" / "functions.txt"
    if not path.exists():
        sys.exit(f"nao encontrei {path}; rode configure.py antes")
    funcs: dict[str, Func] = {}
    for line in path.read_text(encoding="utf-8", errors="replace").splitlines():
        line = line.strip()
        if not line or line.startswith("#"):
            continue
        parts = line.split()
        if len(parts) < 3:
            continue
        name, addr, size = parts[0], int(parts[1], 0), int(parts[2], 0)
        src = parts[3] if len(parts) > 3 else ""
        funcs[name] = Func(name, addr, size, src)
    return funcs


def scan_asm(repo: Path, funcs: dict[str, Func]) -> dict[int, str]:
    """Preenche calls/back_branches e devolve addr -> nome."""
    addr_to_name = {f.addr: f.name for f in funcs.values() if f.addr}
    asm_root = repo / "asm"
    if not asm_root.exists():
        sys.exit(f"nao encontrei {asm_root}; rode configure.py antes")

    for path in asm_root.rglob("*.s"):
        name = path.stem
        fn = funcs.get(name)
        if fn is None:
            fn = Func(name)
            funcs[name] = fn

        lines = path.read_text(encoding="utf-8", errors="replace").splitlines()

        current = fn.addr
        for line in lines:
            m = ADDR_LINE.match(line)
            if m:
                current = int(m.group(1), 16)

            target: str | None = None

            m = JAL_NUM.search(line)
            if m:
                taddr = int(m.group(1), 16)
                target = addr_to_name.get(taddr)
            else:
                m = JAL_SYM.search(line)
                if m:
                    target = m.group(1)

            if target is None:
                m = J_NUM.search(line)
                if m:
                    target = addr_to_name.get(int(m.group(1), 16))
                else:
                    m = J_SYM.search(line)
                    if m:
                        target = m.group(1)

            if target and target != name:
                fn.calls.append(target)

            b = BRANCH.search(line)
            if b and current:
                taddr = int(b.group(1), 16)
                if taddr < current:
                    fn.back_branches += 1

    return addr_to_name


def find_crt0(repo: Path) -> Path | None:
    asm = repo / "asm"
    for pattern in ("cod/temp_init.s", "cod/temp_init*.s", "**/temp_init*.s"):
        hits = sorted(asm.glob(pattern))
        if hits:
            return hits[0]
    return None


def crt0_calls(crt0: Path, addr_to_name: dict[int, str]) -> list[str]:
    out: list[str] = []
    for line in crt0.read_text(encoding="utf-8", errors="replace").splitlines():
        m = JAL_NUM.search(line)
        if m:
            name = addr_to_name.get(int(m.group(1), 16))
            if name:
                out.append(name)
            continue
        m = JAL_SYM.search(line)
        if m:
            out.append(m.group(1))
    return out


def main() -> int:
    ap = argparse.ArgumentParser(description=__doc__,
                                 formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("--repo", default=".", type=Path)
    ap.add_argument("--dump", metavar="FUNC", help="mostra o .s de uma funcao")
    ap.add_argument("--indegree", type=int, default=10,
                    help="quantas funcoes mais chamadas listar (0 desliga)")
    args = ap.parse_args()

    repo: Path = args.repo
    funcs = load_functions(repo)
    addr_to_name = scan_asm(repo, funcs)

    if args.dump:
        fn = funcs.get(args.dump)
        if not fn:
            sys.exit(f"funcao desconhecida: {args.dump}")
        hits = list((repo / "asm").rglob(f"{args.dump}.s"))
        if not hits:
            sys.exit(f"assembly nao encontrado para {args.dump}")
        print(f"# {hits[0]}")
        print("\n".join(hits[0].read_text(encoding="utf-8",
                                          errors="replace").splitlines()[:400]))
        return 0

    crt0 = find_crt0(repo)
    print(f"repo      : {repo.resolve()}")
    print(f"funcoes   : {len(funcs)}")
    print(f"crt0      : {crt0 if crt0 else 'NAO ENCONTRADO (rode configure.py)'}")

    entries: list[str] = []
    if crt0:
        entries = crt0_calls(crt0, addr_to_name)
        print(f"\nchamadas do crt0 ({len(entries)}):")
        for name in entries:
            fn = funcs.get(name)
            where = ""
            if fn:
                where = f"0x{fn.addr:08X}  {fn.size:>5} bytes"
                if TEXT_START <= fn.addr < TEXT_END:
                    where += "  <- .text do jogo"
            print(f"  jal {name:<20} {where}")

    print("\ncandidatos a main (chamados pelo crt0, dentro de .text):")
    seen = set()
    for name in entries:
        if name in seen:
            continue
        seen.add(name)
        fn = funcs.get(name)
        if not fn or not (TEXT_START <= fn.addr < TEXT_END):
            continue
        callees = Counter(fn.calls)
        print(f"\n  {name}  0x{fn.addr:08X}  {fn.size} bytes  "
              f"({len(fn.calls)} chamadas, {fn.back_branches} branches para tras)")
        for callee, count in callees.most_common(12):
            print(f"      -> {callee}" + (f" x{count}" if count > 1 else ""))

    if args.indegree:
        indeg: Counter[str] = Counter()
        for fn in funcs.values():
            indeg.update(set(fn.calls))
        print(f"\nfuncoes mais chamadas (hub do laco de frame):")
        for name, count in indeg.most_common(args.indegree):
            fn = funcs.get(name)
            addr = f"0x{fn.addr:08X}" if fn and fn.addr else "?"
            print(f"  {count:>4}  {name:<24} {addr}")

    print("\nDica: --dump <func> mostra o assembly; procure o `b` de volta ao topo")
    print("      e o `jal` para o update/render por frame.")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
