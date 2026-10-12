#!/usr/bin/env python3
"""Adds TEXT_PAD(n) after C++ functions that the original follows with 8 or more bytes of padding.

The padding behind a function is kept in its asm/nonmatchings file (the nops after `endlabel`). The compiler
reproduces up to 4 bytes of it (the next function is 8-byte aligned); more than that marks the end of an original
object file, whose code the linker aligned to 16 bytes, and has to be written out. Idempotent.

Usage: .venv/bin/python scripts/fix_padding.py [src files...]   (default: all of src/game)
"""

import re
import sys
from pathlib import Path

ROOT = Path(__file__).resolve().parent.parent
DEF = re.compile(r"^(?!\s)(?!INCLUDE_ASM)(?!TEXT_PAD).*\b(func_[0-9A-F]{8}|\w+)\s*\([^;]*\)\s*(const\s*)?\{?\s*$")


def trailing_padding(asm_path):
    text = asm_path.read_text()
    tail = text.split("endlabel", 1)[1].splitlines()[1:] if "endlabel" in text else []
    return 4 * sum(1 for line in tail if re.search(r"\*/\s+nop\s*$", line))


def fix(path):
    folder = ROOT / "asm" / "nonmatchings" / "game" / path.stem
    lines = path.read_text().splitlines(keepends=True)
    out = []
    i = 0
    added = 0
    while i < len(lines):
        line = lines[i]
        out.append(line)
        m = DEF.match(line)
        name = m and m.group(1)
        asm = folder / f"{name}.s" if name else None
        if asm and asm.exists() and ("{" in line or (i + 1 < len(lines) and lines[i + 1].startswith("{"))):
            j = i
            while not lines[j].startswith("}"):
                j += 1
                out.append(lines[j])
            i = j
            pad = trailing_padding(asm)
            k = i + 1
            while k < len(lines) and lines[k].strip() == "":
                k += 1
            has = k < len(lines) and lines[k].startswith("TEXT_PAD(")
            if pad >= 8 and not has:
                out.append(f"TEXT_PAD({pad});\n")
                added += 1
        i += 1
    if added:
        path.write_text("".join(out))
    return added


def main():
    files = [Path(p) for p in sys.argv[1:]] or sorted((ROOT / "src" / "game").glob("*.cpp"))
    total = sum(fix(p) for p in files)
    print(f"{total} TEXT_PAD added")


if __name__ == "__main__":
    main()
