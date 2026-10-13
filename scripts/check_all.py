#!/usr/bin/env python3
"""Runs fcheck over every function written in C++ in the given files and prints a summary.

Usage: .venv/bin/python scripts/check_all.py [src files...]   (default: all of src/game)

Use it to make sure a toolchain change (flags, scripts/asm_filter.py, include/gcc_prelude.inc) breaks nothing:
every function listed as DIFFERS matched before or is someone's work in progress.
"""

import re
import sys
import tempfile
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parent))
import fcheck  # noqa: E402

ROOT = fcheck.ROOT


def main():
    files = [Path(p) for p in sys.argv[1:]] or sorted((ROOT / "src" / "game").glob("*.c*"))
    rom = fcheck.ROM.read_bytes()
    ok, bad, broken = 0, [], []
    for src in files:
        src = src.resolve()
        text = src.read_text()
        known = {p.stem for d in ("nonmatchings", "matchings") for p in (ROOT / "asm" / d / "game" / src.stem).glob("*.s")}
        names = [n for n in re.findall(r"^(?!\s)(?!INCLUDE_ASM).*?\b(\w+)\s*\([^;{]*\)\s*(?:const\s*)?\{", text, re.M)
                 if n in known]
        with tempfile.TemporaryDirectory() as tmp:
            try:
                obj = fcheck.compile_object(src, Path(tmp))
            except Exception:
                broken.append(src.name)
                continue
            for name in names:
                if fcheck.check(obj, name, rom).endswith("MATCH"):
                    ok += 1
                else:
                    bad.append(name)
    print(f"match {ok}, differ {len(bad)}, files that do not compile {len(broken)}")
    if bad:
        print("differ:", " ".join(bad))
    if broken:
        print("do not compile:", " ".join(broken))
    sys.exit(1 if bad or broken else 0)


if __name__ == "__main__":
    main()
