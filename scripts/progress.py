#!/usr/bin/env python3
"""Reports how much of .text is decompiled, from the last linked build.

Counts bytes of .text that come from compiled objects (build/src/**), minus functions those
files still pull in from assembly with INCLUDE_ASM. Library code (Sony SDK, libc, GameSpy...) is
still in the denominator: its ranges are not mapped yet (docs/toolchain.md).
"""

import re
from pathlib import Path

ROOT = Path(__file__).resolve().parent.parent
TEXT = (0x10C000, 0x32101C)


def main():
    map_path = ROOT / "build" / "SLUS_216.72.elf.map"
    if not map_path.exists():
        print("no build/SLUS_216.72.elf.map, run ninja first")
        return
    done = 0
    for m in re.finditer(r"^ \.text\s+0x([0-9a-f]+)\s+0x([0-9a-f]+)\s+(build/src/\S+\.o)$",
                         map_path.read_text(), re.M):
        done += int(m.group(2), 16)
    for src in (ROOT / "src").rglob("*.c*"):
        for name in re.findall(r"^INCLUDE_ASM\([^,]+,\s*(\w+)\);", src.read_text(), re.M):
            path = next((ROOT / "asm" / "nonmatchings").rglob(f"{name}.s"), None)
            m = path and re.search(r"^nonmatching \w+, 0x([0-9A-F]+)", path.read_text(), re.M)
            done -= int(m.group(1), 16) if m else 0
    asm_funcs = sum(len(re.findall(r"^glabel ", p.read_text(), re.M))
                    for p in (ROOT / "asm" / "cod").glob("*.s"))
    total = TEXT[1] - TEXT[0]
    print(f"SLUS_216.72: {done:#x} / {total:#x} bytes of .text in C++ ({100 * done / total:.3f}%)")
    print(f"    functions still in assembly: {asm_funcs}")


if __name__ == "__main__":
    main()
