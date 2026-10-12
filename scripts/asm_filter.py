#!/usr/bin/env python3
"""Rewrites ee-gcc's assembly output in place where the modern gas would assemble it differently from SN's assembler.

- `li.s $fN, <value>`: SN's assembler built every float constant inline, `lui $at` (+ `ori $at` when the low half is
  not zero) and `mtc1 $at, $fN`; the modern gas puts constants with a non-zero low half in `.lit4`.
- Loads and stores of a global written as a macro (`lw $2,D_X`): ee-gcc puts the `.extern D_X,4` that gives the size at
  the END of the file, and SN's one-pass assembler did not know yet that the symbol was small: it expanded the macro to
  `lui`+`%lo` unless the size had been seen earlier. In a delay slot (`.set nomacro`) only one instruction fits, and it
  used `%gp_rel`. The modern gas reads the whole file and uses `%gp_rel` everywhere, so both cases are written out.

Usage: scripts/asm_filter.py <file.s>   (run between the compiler and the assembler; configure.py and fcheck.py do)
"""

import re
import struct
import sys
from pathlib import Path

LI_S = re.compile(r"^(\s*)li\.s\s+(\$f\d+),\s*(\S+)\s*$", re.M)
MEM = re.compile(r"^(\s*)(lb|lbu|lh|lhu|lw|lwu|ld|lq|sb|sh|sw|sd|sq|lwc1|swc1|l\.s|s\.s)\s+(\$f?\d+),\s*([A-Za-z_.$][\w.$]*(?:\s*[-+]\s*\d+)?)\s*$")
STORES = {"sb", "sh", "sw", "sd", "sq", "swc1", "s.s"}
EXTERN = re.compile(r"^\s*\.extern\s+([\w.$]+)\s*,\s*(\d+)")


def memory_macros(text):
    out = []
    nomacro = False
    small = set()
    for line in text.split("\n"):
        stripped = line.strip()
        if stripped.startswith(".set"):
            if "nomacro" in stripped:
                nomacro = True
            elif stripped.split()[-1] == "macro":
                nomacro = False
        m = EXTERN.match(line)
        if m and int(m.group(2)) <= 8:
            small.add(m.group(1))
        m = MEM.match(line)
        if not m or m.group(4).startswith("$"):
            out.append(line)
            continue
        indent, op, reg, sym = m.groups()
        sym = sym.replace(" ", "")
        name = re.match(r"[\w.$]+", sym).group(0)
        if nomacro:
            out.append(f"{indent}{op}\t{reg},%gp_rel({sym})($28)")
        elif name in small or name.startswith("$"):
            out.append(line)
        elif op in STORES or reg.startswith("$f"):
            out += [f"{indent}.set\tnoat", f"{indent}.set\tnoreorder", f"{indent}lui\t$1,%hi({sym})",
                    f"{indent}{op}\t{reg},%lo({sym})($1)", f"{indent}.set\treorder", f"{indent}.set\tat"]
        else:
            out += [f"{indent}.set\tnoreorder", f"{indent}lui\t{reg},%hi({sym})",
                    f"{indent}{op}\t{reg},%lo({sym})({reg})", f"{indent}.set\treorder"]
    return "\n".join(out)


def li_s(m):
    indent, reg, value = m.groups()
    bits = struct.unpack("<I", struct.pack("<f", float(value)))[0]
    hi, lo = bits >> 16, bits & 0xFFFF
    seq = [f"lui\t$1,0x{hi:x}"] + ([f"ori\t$1,$1,0x{lo:x}"] if lo else []) + [f"mtc1\t$1,{reg}"]
    return "\n".join([f"{indent}.set\tnoat"] + [f"{indent}{s}" for s in seq] + [f"{indent}.set\tat"])


def main():
    path = Path(sys.argv[1])
    text = path.read_text()
    new = memory_macros(LI_S.sub(li_s, text))
    if new != text:
        path.write_text(new)


if __name__ == "__main__":
    main()
