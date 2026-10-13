#!/usr/bin/env python3
"""Lists the functions still in INCLUDE_ASM in the given source files, smallest first.

Usage: .venv/bin/python scripts/candidates.py src/game/t_10C000.cpp [more files...] [--max-size 0x200]

Flags: jtbl = has a jump table (a switch: supported, see decomp_guide.md), vu0 = VU0 macro instructions (hand-written
assembly, keep), lit = loads float constants from memory (declare the existing constant as an extern).
"""

import re
import sys
from pathlib import Path

ROOT = Path(__file__).resolve().parent.parent


def main():
    args = sys.argv[1:]
    max_size = 1 << 32
    if "--max-size" in args:
        i = args.index("--max-size")
        max_size = int(args[i + 1], 0)
        del args[i:i + 2]
    rows = []
    for src in args:
        text = Path(src).read_text()
        for folder, name in re.findall(r'^INCLUDE_ASM\("([^"]+)",\s*(\w+)\);', text, re.M):
            asm = (ROOT / folder / f"{name}.s").read_text()
            size = int(re.search(r"^nonmatching \w+, 0x([0-9A-F]+)", asm, re.M).group(1), 16)
            if size > max_size:
                continue
            flags = []
            if "jtbl_" in asm:
                flags.append("jtbl")
            if re.search(r"\*/\s+(v[a-z]+\.|vcallms|qmtc2|qmfc2|lqc2|sqc2)", asm):
                flags.append("vu0")
            if re.search(r"lwc1\s+\$f\d+, %(gp_rel|lo)\(", asm):
                flags.append("lit")
            rows.append((size, name, src, ",".join(flags)))
    for size, name, src, flags in sorted(rows):
        print(f"{size:#6x}  {name}  {src}  {flags}")


if __name__ == "__main__":
    main()
