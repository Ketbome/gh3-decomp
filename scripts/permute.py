#!/usr/bin/env python3
"""Runs decomp-permuter on one function, to close register-allocation / scheduling near misses automatically.

Usage: .venv/bin/python scripts/permute.py <src file or attempt file> <func> [-j 2] [--timeout SECONDS] [--setup-only]
                                         [-- permuter args]
       .venv/bin/python scripts/permute.py --batch [--timeout SECONDS] [-j 2]   (every nonmatching/<func>.* in turn)

The source must contain a C/C++ attempt of <func> (it does not have to match). The permuter (tools/decomp-permuter,
set up by scripts/setup_tools.sh) mutates it at random and prints every better-scoring version to
build/permute/<func>/output-*/; score 0 is a match: scripts/permute_apply.py copies it back and checks it with `dk try`.

What it builds in build/permute/<func>/:
- base.c: the file reduced to its declarations plus <func>, `extern "C"` removed, preprocessed (the permuter parses C);
- target.o: the original assembly of <func>;
- compile.sh: our real toolchain (SN ee-gcc as C++ inside `extern "C"`, scripts/asm_filter.py, gas).
Only the code of <func> may differ in C++-only ways that pycparser cannot read: wrap such parts in PERM_IGNORE().
"""

import os
import re
import shlex
import signal
import subprocess
import sys
from pathlib import Path

ROOT = Path(__file__).resolve().parent.parent
sys.path.insert(0, str(ROOT))
import configure  # noqa: E402

PERMUTER = ROOT / "tools" / "decomp-permuter"
DEF = re.compile(r"^(?!\s)(?!INCLUDE_ASM|TEXT_PAD|GP_DATA|typedef|struct|union|class|enum|#)(.*?)\b(\w+)\s*\([^;]*$")


def strip_source(text, func):
    """Declarations + the target function; other functions reduced to prototypes, INCLUDE_ASM/TEXT_PAD/GP_DATA lines
    dropped."""
    lines = text.splitlines()
    out = []
    i = 0
    in_c_block = False
    while i < len(lines):
        line = lines[i]
        if line.strip() == 'extern "C" {':
            in_c_block = True
            i += 1
            continue
        if in_c_block and line.strip() == "}":
            in_c_block = False
            i += 1
            continue
        if re.match(r"^(INCLUDE_ASM|TEXT_PAD|GP_DATA)\(", line) or line.startswith("// cflags:"):
            i += 1
            continue
        m = DEF.match(line)
        if m and "{" in "\n".join(lines[i:i + 3]) and not line.rstrip().endswith(";"):
            j = i
            while not lines[j].startswith("}"):
                j += 1
            body = lines[i:j + 1]
            keep = m.group(2) == func or "inline" in m.group(1)
            if keep:
                out += body
            else:
                sig = "\n".join(body)
                out.append(sig[:sig.index("{")].rstrip() + ";")
            i = j + 1
            continue
        out.append(line)
        i += 1
    text = "\n".join(out) + "\n"
    text = re.sub(r'\bextern "C"\s*', "", text)
    return text


def main():
    args = sys.argv[1:]
    extra = []
    if "--" in args:
        k = args.index("--")
        args, extra = args[:k], args[k + 1:]
    setup_only = "--setup-only" in args
    args = [a for a in args if a != "--setup-only"]
    timeout = None
    if "--timeout" in args:
        k = args.index("--timeout")
        timeout = int(args[k + 1])
        del args[k:k + 2]
    if "--batch" in args:
        args.remove("--batch")
        for f in sorted((ROOT / "nonmatching").glob("*.c*")):
            subprocess.run([sys.executable, __file__, str(f), f.stem, "--timeout", str(timeout or 600)] + args)
        return
    jobs = "2"
    if "-j" in args:
        k = args.index("-j")
        jobs = args[k + 1]
        del args[k:k + 2]
    src, func = Path(args[0]).resolve(), args[1]
    stem = re.sub(r"\..*$", "", src.name)
    asm = next((p for d in ("nonmatchings", "matchings") for p in (ROOT / "asm" / d / "game").rglob(f"{func}.s")), None)
    if not asm:
        sys.exit(f"{func}: no .s")
    stem = asm.parent.name
    out = ROOT / "build" / "permute" / func
    out.mkdir(parents=True, exist_ok=True)

    reduced = out / "reduced.c"
    reduced.write_text("#define PERMUTER 1\n" + strip_source(src.read_text(), func))
    pre = subprocess.run(["cc", "-E", "-P", "-x", "c", "-I", str(ROOT / "include"), "-DPERMUTER",
                          "-D__asm__=asm", str(reduced)], capture_output=True, text=True)
    if pre.returncode:
        sys.exit("preprocessing failed:\n" + pre.stderr[:2000])
    base = pre.stdout
    # C++ keywords pycparser does not know: only the parser sees these typedefs
    # The permuter parses C (pycparser): only the target function is shown to it. Everything before it passes
    # through untouched (PERM_IGNORE) and the parser is told which names are types (PERM_PRETEND typedefs).
    m = re.search(rf"^[^\n;{{}}]*\b{re.escape(func)}\s*\([^;{{]*\)\s*\{{", base, re.M)
    if not m:
        sys.exit(f"{func}: no definition found in {src.name}")
    depth, j = 0, m.end() - 1
    while True:
        depth += {"{": 1, "}": -1}.get(base[j], 0)
        if depth == 0:
            break
        j += 1
    prefix, target, suffix = base[:m.start()], base[m.start():j + 1], base[j + 1:]
    names = set(re.findall(r"\b(?:struct|union|class|enum)\s+(\w+)", prefix))
    names |= set(re.findall(r"\btypedef\b[^;]*?\b(\w+)\s*(?:\[[^\]]*\])?\s*;", prefix))
    names |= {"bool"}
    pretend = "".join(f"PERM_PRETEND(typedef int {n};)\n" for n in sorted(names))
    base = pretend + "PERM_IGNORE(\n" + prefix + "\n)\n" + target + "\n" + (
        "PERM_IGNORE(\n" + suffix + "\n)\n" if suffix.strip() else "")
    (out / "base.c").write_text(base)

    (out / "target.s").write_text('.include "macro.inc"\n.set noat\n.set noreorder\n.section .text\n'
                                  + asm.read_text())
    subprocess.run([str(ROOT / configure.BINUTILS) + "as", "-EL", "-march=r5900", "-mabi=eabi", "-G0",
                    "-no-pad-sections", "-I", str(ROOT / "include"), str(out / "target.s"), "-o",
                    str(out / "target.o")], check=True)

    flags = configure.CC_FLAGS + " " + configure.extra_cflags(src)
    asflags = "-O0" if "-O0" in flags.split() else ""
    cc = " ".join(shlex.quote(str(ROOT / part)) if i < 2 else part
                  for i, part in enumerate(configure.CC.split()))
    (out / "compile.sh").write_text(f"""#!/bin/sh
# Invoked by the permuter as: compile.sh input.c -o output.o
set -e
in=$1; obj=$3
tmp=$(mktemp -d)
trap 'rm -rf "$tmp"' EXIT
{{ echo 'extern "C" {{'; cat "$in"; echo '}}'; }} > "$tmp/x.cpp"
cd {shlex.quote(str(ROOT))}
{cc} {flags.replace('-Iinclude', '-I' + shlex.quote(str(ROOT / 'include')))} -S "$tmp/x.cpp" -o "$tmp/x.s"
{shlex.quote(sys.executable)} scripts/asm_filter.py "$tmp/x.s" {stem}
{ROOT / configure.BINUTILS}as {configure.CC_AS_FLAGS} {asflags} include/gcc_prelude.inc "$tmp/x.s" -o "$obj"
""")
    (out / "compile.sh").chmod(0o755)
    (out / "settings.toml").write_text(
        f'func_name = "{func}"\ncompiler_type = "gcc"\n'
        f'objdump_command = "{ROOT / configure.BINUTILS}objdump -drz -m mips:5900"\n')
    plain = out / "base_plain.c"
    plain_text = re.sub(r"^PERM_PRETEND\(.*\)$", "", base, flags=re.M)
    plain_text = plain_text.replace("PERM_IGNORE(\n", "", 2)
    plain_text = re.sub(r"\n\)\n", "\n", plain_text)
    plain.write_text(plain_text)
    test = subprocess.run([str(out / "compile.sh"), str(plain), "-o", str(out / "base.o")],
                          capture_output=True, text=True)
    if test.returncode:
        sys.exit("base.c does not compile:\n" + (test.stderr or test.stdout)[:3000])
    print(f"set up in {out.relative_to(ROOT)}")
    if setup_only:
        return
    proc = subprocess.Popen([sys.executable, str(PERMUTER / "permuter.py"), str(out), "-j", jobs, "--best-only",
                             "--stop-on-zero", "--quiet"] + extra, cwd=PERMUTER, start_new_session=True,
                            stdout=subprocess.DEVNULL, stderr=subprocess.DEVNULL)
    try:
        proc.wait(timeout=timeout)
    except subprocess.TimeoutExpired:
        os.killpg(proc.pid, signal.SIGTERM)
        proc.wait()
    scores = sorted(int(d.name.split("-")[1]) for d in out.glob("output-*"))
    print(f"{func}: best score {scores[0] if scores else 'none'}" + ("  <- MATCH, see " + str(
        next(out.glob("output-0-*")).relative_to(ROOT)) if scores and scores[0] == 0 else ""))


if __name__ == "__main__":
    main()
