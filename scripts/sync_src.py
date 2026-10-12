#!/usr/bin/env python3
"""Adds INCLUDE_ASM lines for functions splat knows but a source file does not mention.

A new symbol can split what splat took for one function into two; splat writes the .s for the new one but never
edits a source file that exists. This inserts the missing INCLUDE_ASM lines in address order (after the function
just before it) and lists names the source mentions that splat no longer has. Run configure.py again afterwards.

Usage: .venv/bin/python scripts/sync_src.py
"""

import re
from pathlib import Path

ROOT = Path(__file__).resolve().parent.parent
ADDR = re.compile(r"^\s+/\* [0-9A-F]+ ([0-9A-F]{8}) ", re.M)


def functions(stem):
    """{name: address} of the functions splat wrote for a source file."""
    out = {}
    for d in ("nonmatchings", "matchings"):
        for path in (ROOT / "asm" / d / "game" / stem).glob("*.s"):
            m = ADDR.search(path.read_text())
            if m:
                out[path.stem] = int(m.group(1), 16)
    return out


def end_of(lines, name):
    """Index of the last line belonging to `name` (its INCLUDE_ASM line, or closing brace and TEXT_PAD)."""
    for i, line in enumerate(lines):
        if line.startswith("INCLUDE_ASM(") and re.search(rf",\s*{name}\);", line):
            return i
        if re.match(rf"^(?!\s)(?!INCLUDE_ASM).*\b{name}\s*\([^;]*$", line) and "{" in "".join(lines[i:i + 3]):
            j = i
            while not lines[j].startswith("}"):
                j += 1
            if j + 1 < len(lines) and lines[j + 1].startswith("TEXT_PAD("):
                j += 1
            return j
    return None


def main():
    added = 0
    for src in sorted((ROOT / "src" / "game").glob("*.cpp")):
        funcs = functions(src.stem)
        if not funcs:
            continue
        lines = src.read_text().splitlines(keepends=True)
        text = "".join(lines)
        missing = [n for n in funcs if not re.search(rf"\b{n}\b(?!\s*\([^)]*\)\s*;)", text)]
        for name in sorted(missing, key=funcs.get):
            before = [n for n in funcs if funcs[n] < funcs[name] and n not in missing]
            prev = max(before, key=funcs.get) if before else None
            at = end_of(lines, prev) if prev else None
            if at is None:
                at = next(i for i, line in enumerate(lines) if line.startswith(("INCLUDE_ASM(", "extern \"C\" void", "extern \"C\" int"))) - 1
            lines[at + 1:at + 1] = ["\n", f'INCLUDE_ASM("asm/nonmatchings/game/{src.stem}", {name});\n']
            missing_done = name
            added += 1
            print(f"{src.relative_to(ROOT)}: + {missing_done}")
        if missing:
            src.write_text("".join(lines))
        for name in re.findall(r'^INCLUDE_ASM\("[^"]+",\s*(\w+)\);', text, re.M):
            if name not in funcs:
                print(f"{src.relative_to(ROOT)}: INCLUDE_ASM of {name}, which splat no longer has")
    print(f"{added} INCLUDE_ASM lines added")


if __name__ == "__main__":
    main()
