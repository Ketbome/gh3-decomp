#!/usr/bin/env python3
"""Adds GP_DATA(sym) in front of C++ functions whose original reaches a global through $gp outside a delay slot.

SN's assembler only did that for symbols whose size it already knew, i.e. data the original object defined itself
(see scripts/asm_filter.py). A function defined under an alias (`f_i(...) __asm__("f")`) is looked up as `f`.
Idempotent: a symbol already declared with GP_DATA earlier in the file is skipped.

Usage: .venv/bin/python scripts/fix_gp_data.py [src files...]   (default: all of src/game)
"""

import re
import sys
from pathlib import Path

ROOT = Path(__file__).resolve().parent.parent
DEF = re.compile(r"^(?!\s)(?!INCLUDE_ASM)(?!TEXT_PAD)(?!GP_DATA).*?\b(\w+)\s*\([^;]*$")
# splat indents a delay-slot instruction by one more space
GP_OUTSIDE_SLOT = re.compile(r"^    /\* [0-9A-F]+ [0-9A-F]{8} [0-9A-F]{8} \*/  \S+\s+.*%gp_rel\(([\w.]+)", re.M)


def asm_of(stem, name):
    for d in ("matchings", "nonmatchings"):
        path = ROOT / "asm" / d / "game" / stem / f"{name}.s"
        if path.exists():
            return path.read_text()
    return None


def included_object_end(line):
    m = re.match(r'^INCLUDE_ASM\("([^"]+)",\s*(\w+)\)', line)
    path = m and ROOT / m.group(1) / f"{m.group(2)}.s"
    if not path or not path.exists():
        return False
    tail = path.read_text().split("endlabel", 1)
    return len(tail) > 1 and len(re.findall(r"\*/\s+nop\s*$", tail[1], re.M)) >= 2


def fix(path):
    text = path.read_text()
    lines = text.splitlines(keepends=True)
    alias = dict(re.findall(r"\b(\w+)\s*\([^;{]*?\)\s*__asm__\(\"(\w+)\"\)", text))
    declared = set()
    out = []
    added = 0
    for i, line in enumerate(lines):
        if re.match(r"^(TEXT_PAD|OBJECT_END)\(", line) or included_object_end(line):
            declared.clear()
        m = re.match(r"^GP_DATA\((\w+)\);", line)
        if m:
            declared.add(m.group(1))
        d = DEF.match(line)
        if d and "{" in "".join(lines[i:i + 3]):
            asm = asm_of(path.stem, alias.get(d.group(1), d.group(1)))
            if asm:
                for sym in dict.fromkeys(GP_OUTSIDE_SLOT.findall(asm)):
                    if sym not in declared and not sym.startswith("."):
                        out.append(f"GP_DATA({sym});\n")
                        declared.add(sym)
                        added += 1
        out.append(line)
    if added:
        path.write_text("".join(out))
    return added


def main():
    files = [Path(p) for p in sys.argv[1:]] or sorted((ROOT / "src" / "game").glob("*.c*"))
    print(f"{sum(fix(p) for p in files)} GP_DATA added")


if __name__ == "__main__":
    main()
