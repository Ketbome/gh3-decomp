#!/usr/bin/env python3
"""Checks single functions of a source file against the original, without linking the game.

Usage: .venv/bin/python scripts/fcheck.py src/game/t_2001E0.cpp func_00200308 [func_... ...]
       .venv/bin/python scripts/fcheck.py src/game/t_2001E0.cpp --all

Compiles the file into a private temporary folder (so several checks can run at once), takes each function out
of the object and compares it with the original bytes. Fields that the linker fills in (call targets, %hi/%lo,
%gp_rel) are compared by symbol: the object must reference the same symbol and offset as the original assembly
in asm/nonmatchings. Prints MATCH or the differing instructions.
"""

import re
import subprocess
import sys
import tempfile
from pathlib import Path

from elftools.elf.elffile import ELFFile
from elftools.elf.relocation import RelocationSection

ROOT = Path(__file__).resolve().parent.parent
sys.path.insert(0, str(ROOT))
import configure  # noqa: E402

ROM = ROOT / "disc" / "SLUS_216.72.rom"
ROM_BASE = 0x100000
BINUTILS = ROOT / configure.BINUTILS
R_MIPS_26, R_MIPS_HI16, R_MIPS_LO16, R_MIPS_GPREL16 = 4, 5, 6, 7
MASKS = {R_MIPS_26: 0x03FFFFFF, R_MIPS_HI16: 0xFFFF, R_MIPS_LO16: 0xFFFF, R_MIPS_GPREL16: 0xFFFF}
SYM_OPERAND = re.compile(r"%(hi|lo|gp_rel)\(([\w.]+)(?: \+ (0x[0-9A-Fa-f]+))?\)|^(?:jal|j)\s+(\w+)$")


def compile_object(src, out_dir):
    asm = out_dir / "out.s"
    obj = out_dir / "out.o"
    cc = [str(ROOT / part) if i < 2 else part for i, part in enumerate(configure.CC.split())]
    flags = configure.CC_FLAGS.split() + configure.extra_cflags(src).split()
    subprocess.run(cc + flags + ["-S", str(src), "-o", str(asm)], cwd=ROOT, check=True)
    subprocess.run([sys.executable, str(ROOT / "scripts" / "asm_filter.py"), str(asm), Path(src).stem], check=True)
    asflags = ["-O0"] if "-O0" in configure.extra_cflags(src).split() else []
    subprocess.run([f"{BINUTILS}as"] + configure.CC_AS_FLAGS.split() + asflags
                   + ["include/gcc_prelude.inc", str(asm), "-o", str(obj)], cwd=ROOT, check=True)
    return obj


def original(name):
    """(address, size, {offset: (kind, symbol, addend)}) from the function's asm/nonmatchings file."""
    path = next((p for d in ("nonmatchings", "matchings") for p in (ROOT / "asm" / d).rglob(f"{name}.s")), None)
    if not path:
        sys.exit(f"{name}: no asm/nonmatchings or asm/matchings file")
    text = path.read_text()
    size = int(re.search(r"^nonmatching \w+, 0x([0-9A-F]+)", text, re.M).group(1), 16)
    refs = {}
    start = None
    for m in re.finditer(r"^[ \t]+/\* [0-9A-F]+ ([0-9A-F]{8}) [0-9A-F]{8} \*/[ \t]+(\S+)[ \t]*(.*)$", text, re.M):
        addr = int(m.group(1), 16)
        start = addr if start is None else start
        op = f"{m.group(2)} {m.group(3).strip()}"
        for s in SYM_OPERAND.finditer(op if m.group(2) in ("jal", "j") else m.group(3)):
            if s.group(4):
                refs[addr - start] = ("26", s.group(4), 0)
            else:
                refs[addr - start] = (s.group(1), s.group(2), int(s.group(3) or "0", 16))
    return start, size, refs


def object_function(obj, name):
    """(bytes, {offset: (kind, symbol, addend)}) of a function in an object file."""
    elf = ELFFile(open(obj, "rb"))
    symtab = elf.get_section_by_name(".symtab")
    sym = next((s for s in symtab.iter_symbols() if s.name == name and s["st_info"]["type"] == "STT_FUNC"), None)
    if sym is None:
        return None, None
    text_index = sym["st_shndx"]
    text = elf.get_section(text_index)
    lo = sym["st_value"]
    size = sym["st_size"]
    data = text.data()[lo:lo + size]
    refs = {}
    for sec in elf.iter_sections():
        if not isinstance(sec, RelocationSection) or sec["sh_info"] != text_index:
            continue
        syms = elf.get_section(sec["sh_link"])
        for rel in sec.iter_relocations():
            off = rel["r_offset"] - lo
            if not 0 <= off < size:
                continue
            kind = rel["r_info_type"]
            target = syms.get_symbol(rel["r_info_sym"])
            word = int.from_bytes(data[off:off + 4], "little")
            addend = 0
            if kind in (R_MIPS_LO16, R_MIPS_GPREL16):
                addend = (word & 0xFFFF) - ((word & 0x8000) << 1)
            label = {R_MIPS_26: "26", R_MIPS_HI16: "hi", R_MIPS_LO16: "lo", R_MIPS_GPREL16: "gp_rel"}.get(kind, str(kind))
            refs[off] = (label, target.name or f"<section {target['st_shndx']}>", addend, MASKS.get(kind, 0))
    return data, refs


ALLOWED_SECTIONS = {".text", ".reginfo", ".mdebug.eabi64", ".comment", ".symtab", ".strtab", ".shstrtab", ".pdr",
                    ".gnu.attributes", ".MIPS.abiflags"}


def stray_data(obj):
    """Sections with contents other than code: the linker would put them in front of the game's own data."""
    elf = ELFFile(open(obj, "rb"))
    out = []
    for sec in elf.iter_sections():
        if sec.name in ALLOWED_SECTIONS or sec.name.startswith(".rel") or sec["sh_type"] == "SHT_NULL":
            continue
        if sec["sh_size"]:
            out.append(f"{sec.name} ({sec['sh_size']:#x} bytes)")
    return out


def disasm(addr, data):
    with tempfile.NamedTemporaryFile(suffix=".bin") as f:
        f.write(data)
        f.flush()
        out = subprocess.run([f"{BINUTILS}objdump", "-D", "-b", "binary", "-m", "mips:5900", "-EL",
                              f"--adjust-vma={addr:#x}", f.name], capture_output=True).stdout.decode()
    return [line.split("\t", 2)[-1].strip() for line in out.splitlines() if re.match(r"^\s+[0-9a-f]+:\t", line)]


def check(obj, name, rom):
    addr, size, orig_refs = original(name)
    data, refs = object_function(obj, name)
    if data is None:
        return f"{name}: not defined in the object (check extern \"C\" and the name)"
    orig = rom[addr - ROM_BASE:addr - ROM_BASE + size]
    problems = []
    if len(data) != len(orig):
        problems.append(f"size {len(data):#x}, original {len(orig):#x}")
    mine_dis = disasm(addr, data)
    orig_dis = disasm(addr, orig)
    for off in range(0, min(len(data), len(orig)), 4):
        a = int.from_bytes(data[off:off + 4], "little")
        b = int.from_bytes(orig[off:off + 4], "little")
        mask = refs[off][3] if off in refs else 0
        bad = (a & ~mask) != (b & ~mask)
        if off in refs and not bad:
            kind, sym, addend, _ = refs[off]
            want = orig_refs.get(off)
            if want is None or want[1] != sym or (kind != "hi" and want[2] != addend):
                bad = True
        elif off not in refs and off in orig_refs:
            bad = True
        if bad:
            i = off // 4
            mine = mine_dis[i] if i < len(mine_dis) else "?"
            theirs = orig_dis[i] if i < len(orig_dis) else "?"
            note = f"  [{refs[off][1]}]" if off in refs else ""
            problems.append(f"  {addr + off:08X}: {mine:40}{note}  | original: {theirs}"
                            + (f"  [{orig_refs[off][1]}]" if off in orig_refs else ""))
    if not problems:
        return f"{name}: MATCH"
    return f"{name}: DIFFERS\n" + "\n".join(problems[:40])


def main():
    if len(sys.argv) < 3:
        sys.exit(__doc__)
    src = Path(sys.argv[1]).resolve()
    names = sys.argv[2:]
    if names == ["--all"]:
        text = src.read_text()
        known = {p.stem for d in ("nonmatchings", "matchings") for p in (ROOT / "asm" / d / "game" / src.stem).glob("*.s")}
        names = [n for n in re.findall(r"^(?!\s)(?!INCLUDE_ASM).*?\b(\w+)\s*\([^;{]*\)\s*(?:const\s*)?\{", text, re.M)
                 if n in known]
    rom = ROM.read_bytes()
    with tempfile.TemporaryDirectory() as tmp:
        obj = compile_object(src, Path(tmp))
        results = [check(obj, name, rom) for name in names]
        stray = stray_data(obj)
        if stray:
            results.append("FILE: the object has data of its own, which would shift the game's data: " + ", ".join(stray)
                           + " (use the existing D_ symbols as externs instead of literals/statics)")
    print("\n".join(results))
    sys.exit(0 if all(r.endswith("MATCH") for r in results) else 1)


if __name__ == "__main__":
    main()
