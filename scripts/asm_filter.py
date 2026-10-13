#!/usr/bin/env python3
"""Rewrites ee-gcc's assembly output in place where the modern gas would assemble it differently from SN's assembler.

- `li.s $fN, <value>`: SN's assembler built every float constant inline, `lui $at` (+ `ori $at` when the low half is
  not zero) and `mtc1 $at, $fN`; the modern gas puts constants with a non-zero low half in `.lit4`.
- Loads and stores of a global written as a macro (`lw $2,D_X`): ee-gcc puts the `.extern D_X,4` that gives the size at
  the END of the file, and SN's one-pass assembler did not know yet that the symbol was small: it expanded the macro to
  `lui`+`%lo` unless the size had been seen earlier. In a delay slot (`.set nomacro`) only one instruction fits, and it
  used `%gp_rel`. The modern gas reads the whole file and uses `%gp_rel` everywhere, so both cases are written out.
- `la` of a global follows the same one-pass rule (`lui`+`addiu %lo` / `addiu $28,%gp_rel` in a delay slot), and
  `usd` (unaligned 64-bit store) was expanded `sdr` then `sdl`, the other way round from the modern gas.
- Short loops: SN's assembler worked around the R5900 short-loop erratum by padding a loop of fewer than 6
  instructions (from its head label through the delay slot of the backward branch) with nops before the branch.

- Jump tables: the game's tables stay in its .rodata (asm/data), so the table ee-gcc writes for a switch is dropped
  and the code is pointed at the original one: the k-th table of a function becomes the k-th `jtbl_` symbol its
  original assembly uses. The case labels the original table points at are defined by configure.py (jlabels.ld).

Usage: scripts/asm_filter.py <file.s> [<source stem, e.g. t_16E670>]
       (run between the compiler and the assembler; configure.py and fcheck.py do)
"""

import re
import struct
import sys
from pathlib import Path

LI_S = re.compile(r"^(\s*)li\.s\s+(\$f\d+),\s*(\S+)\s*$", re.M)
MEM = re.compile(r"^(\s*)(lb|lbu|lh|lhu|lw|lwu|ld|lq|sb|sh|sw|sd|sq|lwc1|swc1|l\.s|s\.s)\s+(\$f?\d+),\s*([A-Za-z_.$][\w.$]*(?:\s*[-+]\s*\d+)?)\s*$")
STORES = {"sb", "sh", "sw", "sd", "sq", "swc1", "s.s"}
LA = re.compile(r"^(\s*)la\s+(\$\d+),\s*([A-Za-z_.][\w.$]*(?:\s*[-+]\s*\d+)?)\s*$")
USD = re.compile(r"^(\s*)usd\s+(\$\d+),\s*(-?\d+)\((\$\d+)\)\s*$")
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
        u = USD.match(line)
        if u:
            indent, reg, off, base = u.groups()
            off = int(off)
            out += [f"{indent}.set\tnoreorder", f"{indent}sdr\t{reg},{off}({base})",
                    f"{indent}sdl\t{reg},{off + 7}({base})", f"{indent}.set\treorder"]
            continue
        a = LA.match(line)
        if a:
            indent, reg, sym = a.groups()
            sym = sym.replace(" ", "")
            name = re.match(r"[\w.$]+", sym).group(0)
            if nomacro:
                out.append(f"{indent}addiu\t{reg},$28,%gp_rel({sym})")
            elif name in small:
                out.append(line)
            else:
                out += [f"{indent}.set\tnoreorder", f"{indent}lui\t{reg},%hi({sym})",
                        f"{indent}addiu\t{reg},{reg},%lo({sym})", f"{indent}.set\treorder"]
            continue
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


BRANCH = re.compile(r"^\s*(b\w*|j)\s+(?:[^,]+,\s*)*(\$L\d+)\s*$")
LABEL = re.compile(r"^(\$L\d+):")


def instructions(line):
    """Machine instructions a line of compiler output assembles to (0 for directives, labels and comments)."""
    code = line.split("#", 1)[0].strip()
    if not code or code.startswith(".") or code.endswith(":"):
        return 0
    op, _, args = code.partition(" ") if " " in code else code.partition("\t")
    op = op.strip()
    args = args.strip()
    if op == "la":
        return 2
    if op in ("li", "dli"):
        value = args.split(",")[-1].strip()
        try:
            v = int(value, 0)
        except ValueError:
            return 2
        return 1 if -0x8000 <= v <= 0xFFFF else 2
    return 1


def short_loops(text):
    lines = text.split("\n")
    out = []
    count = 0
    heads = {}
    noreorder = False
    for line in lines:
        stripped = line.strip()
        if stripped.startswith(".set"):
            if stripped.endswith("noreorder"):
                noreorder = True
            elif stripped.endswith("reorder"):
                noreorder = False
        m = LABEL.match(line)
        if m:
            heads[m.group(1)] = count
        b = BRANCH.match(line)
        if b and b.group(2) in heads:
            body = count - heads[b.group(2)]
            pad = 6 - (body + 2)
            if pad > 0:
                indent = re.match(r"\s*", line).group(0)
                out += [f"{indent}nop"] * pad
                count += pad
        out.append(line)
        count += instructions(line)
        # outside noreorder the assembler fills the delay slot of a branch itself, here with a nop
        if not noreorder and re.match(r"^\s*(b\w*|j\w*)\s", line):
            count += 1
    return "\n".join(out)


ROOT = Path(__file__).resolve().parent.parent
FUNC_LABEL = re.compile(r"^([A-Za-z_][\w.$]*):")


def original_tables(stem, func):
    for d in ("matchings", "nonmatchings"):
        path = ROOT / "asm" / d / "game" / stem / f"{func}.s"
        if path.exists():
            return list(dict.fromkeys(re.findall(r"jtbl_[0-9A-F]{8}", path.read_text())))
    return []


def jump_tables(text, stem):
    lines = text.split("\n")
    out = []
    func = None
    mapping = {}
    seen = {}
    i = 0
    while i < len(lines):
        line = lines[i]
        m = FUNC_LABEL.match(line)
        if m and not m.group(1).startswith("$"):
            func = m.group(1)
        if line.strip() in (".rdata", ".section\t.rodata", ".section .rodata") and func:
            j = i + 1
            while j < len(lines) and lines[j].strip() != ".text":
                j += 1
            block = lines[i + 1:j]
            labels = [re.match(r"^(\$L\d+):", b).group(1) for b in block if re.match(r"^\$L\d+:", b)]
            words = [b for b in block if b.strip().startswith(".word")]
            if labels and words and all(re.match(r"^\s*\.word\s+\$L\d+\s*$", w) for w in words):
                tables = original_tables(stem, func) if stem else []
                for label in labels:
                    k = seen.get(func, 0)
                    if k < len(tables):
                        mapping[label] = tables[k]
                    seen[func] = k + 1
                i = j  # keep the .text line
                continue
        out.append(line)
        i += 1
    text = "\n".join(out)
    for label, sym in mapping.items():
        text = re.sub(re.escape(label) + r"(?![0-9])", sym, text)
    return text


def li_s(m):
    indent, reg, value = m.groups()
    bits = struct.unpack("<I", struct.pack("<f", float(value)))[0]
    hi, lo = bits >> 16, bits & 0xFFFF
    seq = [f"lui\t$1,0x{hi:x}"] + ([f"ori\t$1,$1,0x{lo:x}"] if lo else []) + [f"mtc1\t$1,{reg}"]
    return "\n".join([f"{indent}.set\tnoat"] + [f"{indent}{s}" for s in seq] + [f"{indent}.set\tat"])


def main():
    path = Path(sys.argv[1])
    stem = sys.argv[2] if len(sys.argv) > 2 else None
    text = path.read_text()
    new = short_loops(memory_macros(LI_S.sub(li_s, jump_tables(text, stem))))
    if new != text:
        path.write_text(new)


if __name__ == "__main__":
    main()
