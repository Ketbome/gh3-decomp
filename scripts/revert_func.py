#!/usr/bin/env python3
"""Puts functions of a source file back to their INCLUDE_ASM line (for attempts that do not match).

Usage: .venv/bin/python scripts/revert_func.py src/game/t_2361E8.cpp func_002367E0 [func_...]

Replaces the C++ definition (from its first line to the closing brace in column 0) with
INCLUDE_ASM("asm/nonmatchings/game/<file>", <name>);
"""

import re
import sys
from pathlib import Path


def main():
    if len(sys.argv) < 3:
        sys.exit(__doc__)
    path = Path(sys.argv[1])
    folder = f"asm/nonmatchings/game/{path.stem}"
    lines = path.read_text().splitlines(keepends=True)
    for name in sys.argv[2:]:
        start = next((i for i, line in enumerate(lines)
                      if re.match(rf"^(?!\s)(?!INCLUDE_ASM).*\b{name}\s*\([^;]*$", line)
                      and "{" in "".join(lines[i:i + 3])), None)
        if start is None:
            print(f"{name}: no definition found")
            continue
        end = next(i for i in range(start, len(lines)) if lines[i].startswith("}"))
        lines[start:end + 1] = [f'INCLUDE_ASM("{folder}", {name});\n']
        print(f"{name}: reverted")
    path.write_text("".join(lines))


if __name__ == "__main__":
    main()
