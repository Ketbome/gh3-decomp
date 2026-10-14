#!/usr/bin/env python3
"""Reports how much of the game's own code is decompiled to C++.

Every function of the game range (0x10C000-0x2EC0B0) lives in a src/game file, either as C++ or as an
INCLUDE_ASM line; the bytes still included from asm/nonmatchings are subtracted. Library code (GameSpy, Sony SDK, libc, libstdc++,
libm) is excluded: see docs/text_map.md.
"""

import re
import sys
from pathlib import Path

ROOT = Path(__file__).resolve().parent.parent


def main():
    sizes = {}
    paths = list((ROOT / "asm" / "nonmatchings" / "game").rglob("*.s"))
    paths += list((ROOT / "asm" / "matchings" / "game").rglob("*.s"))
    for path in paths:
        m = re.search(r"^nonmatching (\w+), 0x([0-9A-F]+)", path.read_text(), re.M)
        if m:
            sizes[m.group(1)] = int(m.group(2), 16)
    if not sizes:
        print("no asm/nonmatchings, run configure.py first")
        return
    asm_bytes = asm_funcs = c_funcs = 0
    for src in (ROOT / "src").rglob("*.c*"):
        text = src.read_text()
        for name in re.findall(r"^INCLUDE_ASM\([^,]+,\s*(\w+)\);", text, re.M):
            asm_bytes += sizes.get(name, 0)
            asm_funcs += 1
    # Sizes without the alignment padding between functions; splat writes a .s for every function (disassemble_all):
    # asm/matchings for the ones in C++, asm/nonmatchings for the others.
    total = sum(sizes.values())
    c_funcs = len(sizes) - asm_funcs
    done = total - asm_bytes
    if "--markdown" in sys.argv:
        print("| Binary | Code in matching C++ | Functions in C++ | Functions still in assembly |")
        print("|---|---|---|---|")
        print(f"| `SLUS_216.72` (game code, {len(sizes):,} functions) | {100 * done / total:.2f}% | {c_funcs:,} | {asm_funcs:,} |")
        return
    print(f"SLUS_216.72: {done:#x} / {total:#x} bytes of game code in C++ ({100 * done / total:.2f}%)")
    print(f"    functions: {c_funcs} in C++, {asm_funcs} still INCLUDE_ASM")


if __name__ == "__main__":
    main()
