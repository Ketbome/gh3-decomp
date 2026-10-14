#!/usr/bin/env python3
"""Shows what is needed to start on a function in one go: where it is, its original assembly (compact) and an m2c draft.

Usage: .venv/bin/python scripts/show.py <func> [--no-m2c]
"""

import re
import subprocess
import sys
from pathlib import Path

ROOT = Path(__file__).resolve().parent.parent


def main():
    name = sys.argv[1]
    path = next((p for d in ("nonmatchings", "matchings") for p in (ROOT / "asm" / d / "game").rglob(f"{name}.s")), None)
    if not path:
        sys.exit(f"{name}: no .s under asm/(non)matchings/game")
    src = next((ROOT / "src" / "game").glob(f"{path.parent.name}.c*"))
    print(f"file: {src.relative_to(ROOT)}   asm: {path.relative_to(ROOT)}")
    for line in path.read_text().splitlines():
        m = re.match(r"^\s+/\* [0-9A-F]+ ([0-9A-F]{8}) [0-9A-F]{8} \*/(\s+)(.*)$", line)
        if m:
            print(f"{m.group(1)[-5:]}{' ' if len(m.group(2)) > 2 else ''} {m.group(3)}")
        elif re.match(r"^\s+(\.L|jlabel)", line):
            print(line.strip())
    if "--no-m2c" not in sys.argv:
        out = subprocess.run([str(ROOT / ".venv" / "bin" / "m2c"), "-t", "mipsee-gcc-c", str(path)],
                             capture_output=True, text=True)
        print("--- m2c ---")
        print(out.stdout.strip() or out.stderr.strip()[:2000])


if __name__ == "__main__":
    main()
