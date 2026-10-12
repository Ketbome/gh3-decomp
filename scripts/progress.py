#!/usr/bin/env python3
"""Reports how much of the game's own code is decompiled to C++.

Every function of the game range (0x10C000-0x2EC0B0) lives in a src/game file, either as C++ or as an
INCLUDE_ASM line; the bytes still included from asm/nonmatchings are subtracted. Library code (GameSpy, Sony SDK, libc, libstdc++,
libm) is excluded: see docs/text_map.md.
"""

import re
from pathlib import Path

ROOT = Path(__file__).resolve().parent.parent


def main():
    sizes = {}
    for path in (ROOT / "asm" / "nonmatchings" / "game").rglob("*.s"):
        m = re.search(r"^nonmatching (\w+), 0x([0-9A-F]+)", path.read_text(), re.M)
        if m:
            sizes[m.group(1)] = int(m.group(2), 16)
    if not sizes:
        print("no asm/nonmatchings, run configure.py first")
        return
    asm_bytes = asm_funcs = c_funcs = 0
    for src in (ROOT / "src").rglob("*.cpp"):
        text = src.read_text()
        for name in re.findall(r"^INCLUDE_ASM\([^,]+,\s*(\w+)\);", text, re.M):
            asm_bytes += sizes.get(name, 0)
            asm_funcs += 1
        c_funcs += len(re.findall(r"^(?!INCLUDE_ASM)\S.*\b(func_[0-9A-F]{8}|\w+__\w*)\s*\([^;]*\)\s*\{", text, re.M))
    # Sizes without the alignment padding between functions; splat writes a .s for every function, matched or not.
    total = sum(sizes.values())
    done = total - asm_bytes
    print(f"SLUS_216.72: {done:#x} / {total:#x} bytes of game code in C++ ({100 * done / total:.2f}%)")
    print(f"    functions: {c_funcs} in C++, {asm_funcs} still INCLUDE_ASM")


if __name__ == "__main__":
    main()
