#!/usr/bin/env python3
"""Traduz os enderecos de retorno de reachability.txt em nomes de funcao.

O relatorio gerado pelo port (ux0:data/gh3/reachability.txt) traz, para cada
stub alcancado, o endereco de retorno de quem o chamou. Esse endereco e' de
execucao: o eboot e' realocado no load, entao so vira offset estavel depois de
descontar a base do modulo (o proprio relatorio informa a base).

Este script faz essa conta contra o ELF do build e mostra qual funcao chamou
cada stub. Nao depende de pyelftools: usa o readelf/nm do VitaSDK.

Uso:
    vita/tools/symbolize.py build-vita/gh3_vita ux0:data/gh3/reachability.txt
    vita/tools/symbolize.py --top 40 <elf> <relatorio>

O ajuste entre a base do modulo em execucao e o primeiro PT_LOAD do ELF e'
calibrado com a "ancora" que o relatorio imprime (endereco de
gh3::hle::stub_hit), portanto nao depende de o vita-elf-create preservar os
enderecos virtuais.
"""

from __future__ import annotations

import argparse
import os
import re
import shutil
import subprocess
import sys
from pathlib import Path


def tool(name: str) -> str:
    """Acha a ferramenta no VitaSDK antes de cair no PATH do host."""
    sdk = os.environ.get("VITASDK")
    if sdk:
        candidate = Path(sdk) / "bin" / f"arm-vita-eabi-{name}"
        if candidate.is_file():
            return str(candidate)
    found = shutil.which(f"arm-vita-eabi-{name}") or shutil.which(name)
    if not found:
        sys.exit(f"nao encontrei {name} (defina VITASDK ou ponha no PATH)")
    return found


def run(cmd: list[str]) -> str:
    out = subprocess.run(cmd, capture_output=True, text=True)
    if out.returncode != 0:
        sys.exit(f"{cmd[0]} falhou: {out.stderr.strip()}")
    return out.stdout


def min_load_vaddr(elf: Path) -> int:
    """Menor VirtAddr entre os PT_LOAD: o offset 0 do modulo."""
    text = run([tool("readelf"), "-lW", str(elf)])
    addrs = []
    for line in text.splitlines():
        parts = line.split()
        if parts and parts[0] == "LOAD":
            try:
                addrs.append(int(parts[2], 16))
            except (IndexError, ValueError):
                continue
    if not addrs:
        sys.exit(f"nenhum PT_LOAD em {elf}")
    return min(addrs)


def symbols(elf: Path) -> list[tuple[int, str]]:
    """(VA, nome) de todo simbolo de codigo definido, ordenado por VA."""
    text = run([tool("nm"), "-C", "--defined-only", str(elf)])
    out: list[tuple[int, str]] = []
    for line in text.splitlines():
        parts = line.split(maxsplit=2)
        if len(parts) != 3 or parts[1].lower() not in ("t", "w"):
            continue
        try:
            out.append((int(parts[0], 16), parts[2]))
        except ValueError:
            continue
    out.sort()
    return out


def read_report(path: Path) -> tuple[int, int, list[tuple[int, int, str]]]:
    """(base do modulo, ancora, [(chamadas, retorno, simbolo)])"""
    base = anchor = 0
    rows: list[tuple[int, int, str]] = []
    for line in path.read_text(encoding="utf-8", errors="replace").splitlines():
        m = re.match(r"modulo\s*:\s*0x([0-9A-Fa-f]+)", line)
        if m:
            base = int(m.group(1), 16)
            continue
        m = re.match(r"ancora\s*:\s*0x([0-9A-Fa-f]+)", line)
        if m:
            anchor = int(m.group(1), 16)
            continue
        m = re.match(r"\s*(\d+)\s+(\S+)\s+0x([0-9A-Fa-f]+)\s+(\S+)", line)
        if m:
            rows.append((int(m.group(1)), int(m.group(3), 16), m.group(4)))
    return base, anchor, rows


def main() -> int:
    ap = argparse.ArgumentParser(description=__doc__,
                                 formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("elf", type=Path, help="ELF do build (gh3_vita)")
    ap.add_argument("report", type=Path, help="reachability.txt")
    ap.add_argument("--top", type=int, default=0,
                    help="mostra so as N linhas mais chamadas")
    args = ap.parse_args()

    base, anchor, rows = read_report(args.report)
    if not base:
        sys.exit("o relatorio nao traz a base do modulo (module_base() = 0)")

    lo = min_load_vaddr(args.elf)
    syms = symbols(args.elf)

    # Calibracao: quanto a base de execucao difere do primeiro PT_LOAD.
    delta = 0
    if anchor:
        anchor_va = next((va for va, name in syms if "stub_hit" in name), 0)
        if anchor_va:
            delta = (anchor - base) - (anchor_va - lo)
            if delta:
                print(f"# ajuste de base: {delta:+#x} "
                      f"(vita-elf-create nao preserva os VAs do ELF)")

    def containing(va: int) -> str:
        best = None
        for sym_va, name in syms:
            if sym_va > va:
                break
            best = (sym_va, name)
        if best is None:
            return "?"
        return f"{best[1]}+0x{va - best[0]:X}"

    rows.sort(key=lambda r: (-r[0], r[2]))
    if args.top:
        rows = rows[: args.top]

    print(f"# {len(rows)} stub(s) alcancado(s); base 0x{base:08X}")
    print(f"# {'chamadas':>10}  {'retorno':>10}  simbolo")
    for hits, caller, name in rows:
        va = caller - base - delta + lo
        print(f"{hits:12d}  0x{caller:08X}  {name:<24} <- {containing(va)}")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
