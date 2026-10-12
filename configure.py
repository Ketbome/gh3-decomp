#!/usr/bin/env python3
"""Extracts the executable from the disc image, splits it with splat and writes build.ninja.

Usage: .venv/bin/python configure.py && ninja
"""

import hashlib
import os
import re
import shlex
import subprocess
import sys
from pathlib import Path

ROOT = Path(__file__).resolve().parent
ISO = ROOT / "Guitar Hero III - Legends of Rock (USA).iso"
DISC = ROOT / "disc"
ELF = DISC / "SLUS_216.72"
ROM = DISC / "SLUS_216.72.rom"
YAML = "config/SLUS_216.72.yaml"
BINUTILS = "tools/binutils/mips-ps2-decompals-"

ELF_SHA1 = "15992cec17deb6bf8e3d8fa4a2a5f1ef1b60f47e"

AS_FLAGS = "-EL -march=r5900 -mabi=eabi -G0 -no-pad-sections -Iinclude"

# The game was built with SN Systems' ee-gcc 2.95.3 (build 136) at -O2: see docs/toolchain.md.
# It is a Windows program, run with wibo (tools/wibo/wibo-macos on macOS, wibo-i686 on Linux).
WIBO = "tools/wibo/wibo-macos" if sys.platform == "darwin" else "tools/wibo/wibo-i686"
CC = f"{WIBO} tools/compilers/ee-gcc2.95.3-136/bin/ee-gcc.exe"
CC_FLAGS = "-O2 -G8 -fno-exceptions -fno-rtti -Iinclude"
# Compiler output is assembled as o64 so that address arithmetic on 32-bit pointers expands to
# addiu/addu as SN's assembler did; with eabi the modern gas emits daddiu/daddu.
CC_AS_FLAGS = "-EL -march=r5900 -mabi=o64 -no-pad-sections -mno-pdr -Iinclude"

LD_SCRIPTS = ["build/SLUS_216.72.ld", "build/undefined_funcs_auto.txt",
              "build/undefined_syms_auto.txt", "config/linker_script_extra.ld"]


def run(cmd, **kwargs):
    print("$", " ".join(shlex.quote(str(c)) for c in cmd))
    subprocess.run(cmd, check=True, cwd=ROOT, **kwargs)


def extract():
    if not ELF.exists():
        iso = next((p for p in (ISO, DISC / ISO.name) if p.exists()), None)
        if not iso:
            sys.exit(f"missing disc image: {ISO.name}")
        run(["7z", "x", "-y", f"-o{DISC}", iso, "SYSTEM.CNF", "SLUS_216.72"], stdout=subprocess.DEVNULL)
    if hashlib.sha1(ELF.read_bytes()).hexdigest() != ELF_SHA1:
        sys.exit(f"{ELF.relative_to(ROOT)} does not match the USA release (sha1 {ELF_SHA1})")


def make_rom():
    run([BINUTILS + "objcopy", "-O", "binary", "--gap-fill=0x00", ELF, ROM])


def split():
    # splat shells out to mips-linux-gnu-* binutils; tools/bin aliases them.
    env = dict(os.environ, PATH=f"{ROOT / 'tools' / 'bin'}{os.pathsep}{os.environ['PATH']}")
    run([sys.executable, "-m", "splat", "split", ROOT / YAML], env=env,
        stdout=subprocess.DEVNULL, stderr=subprocess.DEVNULL)


def patch_ld_script():
    """The original link aligned .sbss and .bss to 128 bytes; splat's script only aligns to 16."""
    path = ROOT / "build" / "SLUS_216.72.ld"
    text = path.read_text()
    # `.` inside an output section is relative to its start, so the section itself is aligned first.
    text = text.replace(".cod_bss (NOLOAD) :", ".cod_bss ALIGN(0x80) (NOLOAD) :")
    text = text.replace("        cod_BSS_START = .;", "        . = ALIGN(., 0x80);\n        cod_BSS_START = .;")
    path.write_text(text)


def linked_c_files():
    """C/C++ files named by `c`/`cpp` subsegments in the splat yaml: the ones the linker script uses."""
    text = (ROOT / YAML).read_text()
    return {Path("src") / f"{name}.{kind}"
            for kind, name in re.findall(r"\[0x[0-9A-Fa-f]+, (cpp|c), ([\w/]+)\]", text)}


def write_ninja():
    asm = [p.relative_to(ROOT) for p in sorted((ROOT / "asm").rglob("*.s")) if "nonmatchings" not in p.parts]
    linked = linked_c_files()
    srcs = sorted(p for p in linked if (ROOT / p).exists())
    headers = " ".join(str(p.relative_to(ROOT)) for p in sorted((ROOT / "include").rglob("*.h")))

    out = [
        f"as = {BINUTILS}as",
        f"ld = {BINUTILS}ld",
        f"objcopy = {BINUTILS}objcopy",
        f"as_flags = {AS_FLAGS}",
        "",
        "rule as",
        "  command = $as $as_flags $in -o $out",
        "  description = AS $in",
        "",
        # Compile to assembly and assemble with the modern gas; gcc_prelude.inc makes `move`
        # encode as daddu, the way SN's assembler did.
        "rule cc",
        f"  command = {CC} {CC_FLAGS} -S $in -o $out.s && "
        f"$as {CC_AS_FLAGS} include/gcc_prelude.inc $out.s -o $out && "
        f"{sys.executable} scripts/set_eabi64.py $out",
        "  description = CC $in",
        "",
        "rule ld",
        "  command = $ld -EL $scripts -Map $out.map -o $out",
        "  description = LD $out",
        "",
        "rule rom",
        "  command = $objcopy -O binary --gap-fill=0x00 $in $out",
        "  description = OBJCOPY $out",
        "",
        "rule check",
        "  command = cmp $in && touch $out",
        "  description = CHECK $in",
        "",
    ]
    objs = []
    for src in asm:
        obj = Path("build") / src.with_suffix(".o")
        objs.append(obj)
        out.append(f"build {obj}: as {src} | include/macro.inc include/labels.inc")
    for src in srcs:
        obj = Path("build") / src.with_suffix(".o")
        objs.append(obj)
        out.append(f"build {obj}: cc {src} | {headers} include/gcc_prelude.inc")
    out += [
        f"build build/SLUS_216.72.elf: ld | {' '.join(map(str, objs))} {' '.join(LD_SCRIPTS)}",
        f"  scripts = {' '.join('-T ' + s for s in LD_SCRIPTS)}",
        "build build/SLUS_216.72.rom: rom build/SLUS_216.72.elf",
        f"build build/SLUS_216.72.ok: check build/SLUS_216.72.rom {ROM.relative_to(ROOT)}",
        "default build/SLUS_216.72.ok",
        "",
    ]
    (ROOT / "build.ninja").write_text("\n".join(out))


def main():
    extract()
    make_rom()
    split()
    patch_ld_script()
    write_ninja()


if __name__ == "__main__":
    main()
