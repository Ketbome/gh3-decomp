#!/usr/bin/env python3
"""Rewrites ee-gcc's assembly output in place where the modern gas would assemble it differently from SN's assembler.

- `li.s $fN, <value>`: SN's assembler built every float constant inline, `lui $at` (+ `ori $at` when the low half is
  not zero) and `mtc1 $at, $fN`; the modern gas puts constants with a non-zero low half in `.lit4`.

Usage: scripts/asm_filter.py <file.s>   (run between the compiler and the assembler; configure.py and fcheck.py do)
"""

import re
import struct
import sys
from pathlib import Path

LI_S = re.compile(r"^(\s*)li\.s\s+(\$f\d+),\s*(\S+)\s*$", re.M)


def li_s(m):
    indent, reg, value = m.groups()
    bits = struct.unpack("<I", struct.pack("<f", float(value)))[0]
    hi, lo = bits >> 16, bits & 0xFFFF
    seq = [f"lui\t$1,0x{hi:x}"] + ([f"ori\t$1,$1,0x{lo:x}"] if lo else []) + [f"mtc1\t$1,{reg}"]
    return "\n".join([f"{indent}.set\tnoat"] + [f"{indent}{s}" for s in seq] + [f"{indent}.set\tat"])


def main():
    path = Path(sys.argv[1])
    text = path.read_text()
    new = LI_S.sub(li_s, text)
    if new != text:
        path.write_text(new)


if __name__ == "__main__":
    main()
