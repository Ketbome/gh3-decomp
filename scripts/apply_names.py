#!/usr/bin/env python3
"""Renames splat names (func_XXXXXXXX, D_XXXXXXXX) in src/ and include/ to the names listed in the symbol files
the yaml uses. Run it after adding names, then configure.py (which splits with the new names).

Usage: .venv/bin/python scripts/apply_names.py
"""

import re
from pathlib import Path

ROOT = Path(__file__).resolve().parent.parent
YAML = ROOT / "config" / "SLUS_216.72.yaml"


def main():
    names = {}
    for rel in re.findall(r"^\s+- (config/\S+\.txt)$", YAML.read_text(), re.M):
        if "reloc" in rel:
            continue
        for m in re.finditer(r"^(\w+) = 0x([0-9A-Fa-f]+);", (ROOT / rel).read_text(), re.M):
            addr = int(m.group(2), 16)
            names[f"func_{addr:08X}"] = m.group(1)
            names[f"D_{addr:08X}"] = m.group(1)
    token = re.compile(r"\b(?:func|D)_[0-9A-F]{8}\b")
    changed = 0
    for path in list((ROOT / "src").rglob("*.c*")) + list((ROOT / "include").rglob("*.h")):
        text = path.read_text()
        new = token.sub(lambda m: names.get(m.group(0), m.group(0)), text)
        if new != text:
            path.write_text(new)
            changed += 1
    print(f"{changed} files renamed")


if __name__ == "__main__":
    main()
