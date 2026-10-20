#!/usr/bin/env python3
"""dk: the decomp kit. One tool for the per-function loop and for recovering interrupted sessions in a matching
decompilation (splat-style layout: one .s per function, C/C++ sources with INCLUDE_ASM lines).

Configured by a `decomp.toml` at the project root (see templates/decomp.toml). Commands:

  dk show <func> [--no-m2c]           original assembly (compact) + an m2c draft + where the function lives
  dk next <src...> [--max-size N] [--untried]
                                      functions still in INCLUDE_ASM, smallest first, with flags (jtbl, vu0:N%, ...);
                                      --untried leaves out functions named in a worklog or saved as a near miss
  dk check <src> <func...> | --all    compile <src> privately and compare functions with the original bytes;
                                      relocated fields are compared by symbol (+ addend), not by value
  dk try <src> <func...>              run the configured pre-check hooks on <src>, then `check`
  dk revert <src> <func...>           put functions back to their INCLUDE_ASM line
  dk done <src> <worklog> <message>   pre-commit hooks, every function of <src> must match, commit <src> + <worklog>
  dk all [<src>...]                   check every C/C++ function (regression check after a toolchain change)
  dk twins [--list] [<src>...]        copy matched functions onto functions with identical assembly (symbols renamed,
                                      local types copied), keep only what matches
  dk protos <src> <func>              redeclare the functions <func> calls with the other return type (void <-> int,
                                      through `__asm__` aliases used only by <func>), one and two at a time; writes a
                                      combination that matches into <src>, else reports the closest (registers around
                                      a call follow the callee's declared return type)
  dk state                            recovery report: the session state file, last commits, uncommitted sources
                                      and whether they match, progress, worklog activity, stale documents
  dk docs [--commit]                  rewrite the generated blocks of the documents (<!-- dk:NAME --> ... <!-- /dk:NAME -->)
                                      with the output of their commands; --commit commits the changed documents
  dk rescue [--commit]                after an interruption: for every modified source, revert the functions that do
                                      not match (only those that were INCLUDE_ASM at HEAD), then optionally commit

Exit status is 0 only when everything checked matches. Architecture support for relocations: MIPS (PS1, PS2, N64,
PSP). Requires Python 3.9+, pyelftools, and tomllib (3.11+) or tomli.
"""

import fnmatch
import glob
import itertools
import os
import re
import shlex
import subprocess
import sys
import tempfile
from pathlib import Path

try:
    import tomllib
except ImportError:  # Python < 3.11
    try:
        import tomli as tomllib
    except ImportError:
        sys.exit("dk: needs Python 3.11+ or `pip install tomli`")


# --------------------------------------------------------------------------------------------------------------------
# configuration

def find_root():
    here = Path.cwd().resolve()
    for d in [here, *here.parents]:
        if (d / "decomp.toml").exists():
            return d
    sys.exit("dk: no decomp.toml in this directory or above (copy templates/decomp.toml to the project root)")


ROOT = find_root()
CFG = tomllib.loads((ROOT / "decomp.toml").read_text())
T, TC, L = CFG.get("target", {}), CFG.get("toolchain", {}), CFG.get("layout", {})
HOOKS = CFG.get("hooks", {})


def cfg_path(value):
    return ROOT / value if value else None


IMAGE = cfg_path(T.get("image"))
IMAGE_VRAM = int(str(T.get("image_vram", 0)), 0)
ASM_DIRS = [cfg_path(d) for d in L.get("asm_dirs", ["asm/nonmatchings", "asm/matchings"])]
SOURCES = L.get("sources", ["src/**/*.c", "src/**/*.cpp"])
INCLUDE_ASM = L.get("include_asm", "INCLUDE_ASM")
STATE = cfg_path(L.get("state", "docs/STATE.md"))
WORKLOGS = L.get("worklogs", ["docs/worklog/*.md"])
WORKLOGS = [WORKLOGS] if isinstance(WORKLOGS, str) else WORKLOGS
NEAR_MISSES = cfg_path(L.get("near_misses", "nonmatching"))
DOCS = CFG.get("docs", {})
FLAG_MARKER = TC.get("file_flags_marker", "// cflags:")


def sh(cmd, **kw):
    """Run a command line (string, shell-split) from the project root."""
    return subprocess.run(cmd if isinstance(cmd, list) else shlex.split(cmd), cwd=ROOT, **kw)


def source_files():
    out = []
    for pattern in SOURCES:
        out += [Path(p) for p in glob.glob(str(ROOT / pattern), recursive=True)]
    return sorted(set(out))


def rel(p):
    try:
        return str(Path(p).resolve().relative_to(ROOT))
    except ValueError:
        return str(p)


# --------------------------------------------------------------------------------------------------------------------
# original functions (per-function .s files)

ADDR_RE = re.compile(r"^\s+/\* [0-9A-Fa-f]+ ([0-9A-Fa-f]{8}) ([0-9A-Fa-f]{8}) \*/(\s+)(\S+)[ \t]*(.*)$", re.M)
SYM_RE = re.compile(r"%(hi|lo|gp_rel)\(([\w.$]+)(?:\s*\+\s*(0x[0-9A-Fa-f]+|\d+))?\)")


def find_asm(name):
    for d in ASM_DIRS:
        if d and d.exists():
            hit = next(d.rglob(f"{name}.s"), None)
            if hit:
                return hit
    return None


def parse_asm(path):
    """(start address, size, [(offset, mnemonic, operands, in_delay_slot)], {offset: (kind, symbol, addend)})."""
    text = path.read_text()
    insns = [(int(m.group(1), 16), m.group(4), m.group(5).strip(), len(m.group(3)) > 2) for m in ADDR_RE.finditer(text)]
    if not insns:
        sys.exit(f"dk: {path} has no instructions")
    start = insns[0][0]
    m = re.search(r"^nonmatching \S+, 0x([0-9A-Fa-f]+)", text, re.M)
    if m:
        size = int(m.group(1), 16)
    else:
        end = text.find("endlabel")
        body = [i for i in insns if end < 0 or text.find(f"{i[0]:08X}") < end]
        size = body[-1][0] + 4 - start
    refs = {}
    for addr, op, args, _ in insns:
        off = addr - start
        if op in ("jal", "j") and re.match(r"^[A-Za-z_][\w.$]*$", args):
            refs[off] = ("26", args, 0)
            continue
        s = SYM_RE.search(args)
        if s:
            refs[off] = (s.group(1), s.group(2), int(s.group(3) or "0", 0))
    return start, size, insns, refs


# --------------------------------------------------------------------------------------------------------------------
# compiling one source file privately

def file_flags(src):
    for line in Path(src).read_text().splitlines()[:10]:
        if line.startswith(FLAG_MARKER):
            return line[len(FLAG_MARKER):].strip()
    return ""


def compile_object(src, tmp):
    src = Path(src).resolve()
    asm, obj = tmp / "out.s", tmp / "out.o"
    stem = src.name.split(".")[0]
    extra = file_flags(src)
    cc = TC["cc"].format(root=ROOT)
    r = sh(shlex.split(cc) + shlex.split(TC.get("cflags", "")) + shlex.split(extra) + ["-S", str(src), "-o", str(asm)],
           capture_output=True, text=True)
    if r.returncode:
        raise RuntimeError((r.stderr or r.stdout)[-3000:])
    if TC.get("asm_filter"):
        sh(TC["asm_filter"].format(asm=asm, stem=stem, src=src, root=ROOT), check=True)
    asflags = shlex.split(TC.get("asflags", ""))
    for flag, add in TC.get("asflags_when_cflag", {}).items():
        if flag in extra.split():
            asflags += shlex.split(add)
    prelude = [TC["as_prelude"]] if TC.get("as_prelude") else []
    r = sh([TC["as"]] + asflags + prelude + [str(asm), "-o", str(obj)], capture_output=True, text=True)
    if r.returncode:
        raise RuntimeError((r.stderr or r.stdout)[-3000:])
    return obj


# --------------------------------------------------------------------------------------------------------------------
# comparing

R_MIPS = {4: ("26", 0x03FFFFFF), 5: ("hi", 0xFFFF), 6: ("lo", 0xFFFF), 7: ("gp_rel", 0xFFFF)}
ALLOWED_SECTIONS = {".text", ".reginfo", ".mdebug.eabi64", ".mdebug.abi32", ".comment", ".symtab", ".strtab",
                    ".shstrtab", ".pdr", ".gnu.attributes", ".MIPS.abiflags", ".note.GNU-stack"}


def object_function(obj, name):
    from elftools.elf.elffile import ELFFile
    from elftools.elf.relocation import RelocationSection
    elf = ELFFile(open(obj, "rb"))
    sym = next((s for s in elf.get_section_by_name(".symtab").iter_symbols()
                if s.name == name and s["st_info"]["type"] == "STT_FUNC"), None)
    if sym is None:
        return None, None
    index = sym["st_shndx"]
    lo, size = sym["st_value"], sym["st_size"]
    data = elf.get_section(index).data()[lo:lo + size]
    refs = {}
    for sec in elf.iter_sections():
        if not isinstance(sec, RelocationSection) or sec["sh_info"] != index:
            continue
        syms = elf.get_section(sec["sh_link"])
        for r in sec.iter_relocations():
            off = r["r_offset"] - lo
            if not 0 <= off < size:
                continue
            kind, mask = R_MIPS.get(r["r_info_type"], (str(r["r_info_type"]), 0))
            word = int.from_bytes(data[off:off + 4], "little")
            addend = (word & 0xFFFF) - ((word & 0x8000) << 1) if kind in ("lo", "gp_rel") else 0
            target = syms.get_symbol(r["r_info_sym"])
            refs[off] = (kind, target.name or f"<section {target['st_shndx']}>", addend, mask)
    return data, refs


def stray_data(obj):
    from elftools.elf.elffile import ELFFile
    elf = ELFFile(open(obj, "rb"))
    return [f"{s.name} ({s['sh_size']:#x})" for s in elf.iter_sections()
            if s.name not in ALLOWED_SECTIONS and not s.name.startswith(".rel") and s["sh_type"] != "SHT_NULL"
            and s["sh_size"]]


def definition_order(obj, src):
    """Complaint if the object lays its functions out in another order than the original (address order)."""
    from elftools.elf.elffile import ELFFile
    elf = ELFFile(open(obj, "rb"))
    index = next((i for i, sec in enumerate(elf.iter_sections()) if sec.name == ".text"), None)
    if index is None:
        return None
    syms = [s for s in elf.get_section_by_name(".symtab").iter_symbols()
            if s["st_info"]["type"] == "STT_FUNC" and s["st_shndx"] == index]
    placed = []
    for s in sorted(syms, key=lambda s: s["st_value"]):
        path = find_asm(s.name)
        if path:
            placed.append((s.name, parse_asm(path)[0]))
    for (a, x), (b, y) in zip(placed, placed[1:]):
        if x > y:
            return (f"{Path(src).name}: {a} is defined before {b}; definitions must follow address order "
                    f"(put it where its {INCLUDE_ASM} line was)")
    return None


def disasm(addr, data):
    with tempfile.NamedTemporaryFile(suffix=".bin") as f:
        f.write(data)
        f.flush()
        out = subprocess.run([TC["objdump"], "-D", "-z", "-b", "binary", "-m", TC.get("objdump_arch", "mips"),
                              "-EL" if T.get("endian", "little") == "little" else "-EB",
                              f"--adjust-vma={addr:#x}", f.name], capture_output=True, text=True).stdout
    return [line.split("\t", 2)[-1].strip() for line in out.splitlines() if re.match(r"^\s+[0-9a-f]+:\t", line)]


def check_function(obj, name, image):
    path = find_asm(name)
    if not path:
        return f"{name}: no original .s"
    start, size, _, orig_refs = parse_asm(path)
    data, refs = object_function(obj, name)
    if data is None:
        return f"{name}: not defined in the object (name, linkage?)"
    orig = image[start - IMAGE_VRAM:start - IMAGE_VRAM + size]
    problems = []
    if len(data) != len(orig):
        problems.append(f"size {len(data):#x}, original {len(orig):#x}")
    mine, theirs = disasm(start, data), disasm(start, orig)
    for off in range(0, min(len(data), len(orig)), 4):
        a = int.from_bytes(data[off:off + 4], "little")
        b = int.from_bytes(orig[off:off + 4], "little")
        mask = refs[off][3] if off in refs else 0
        bad = (a & ~mask) != (b & ~mask)
        if off in refs and not bad:
            kind, sym, addend, _ = refs[off]
            want = orig_refs.get(off)
            bad = want is None or want[1] != sym or (kind != "hi" and want[2] != addend)
        elif off not in refs and off in orig_refs:
            bad = True
        if bad:
            i = off // 4
            note = f" [{refs[off][1]}]" if off in refs else ""
            onote = f" [{orig_refs[off][1]}]" if off in orig_refs else ""
            problems.append(f"  {start + off:08X}: {(mine[i] if i < len(mine) else '?') + note:46} | original: "
                            f"{(theirs[i] if i < len(theirs) else '?')}{onote}")
    return f"{name}: MATCH" if not problems else f"{name}: DIFFERS\n" + "\n".join(problems[:40])


def defined_functions(src):
    """Functions written in C/C++ in a source file (definitions in column 0 that have an original .s)."""
    text = Path(src).read_text()
    names = re.findall(rf"^(?!\s)(?!{INCLUDE_ASM})(?!#).*?\b(\w+)\s*\([^;{{]*\)\s*(?:const\s*)?\{{", text, re.M)
    return [n for n in dict.fromkeys(names) if find_asm(n)]


def run_check(src, names, quiet=False):
    image = IMAGE.read_bytes()
    with tempfile.TemporaryDirectory() as tmp:
        try:
            obj = compile_object(src, Path(tmp))
        except RuntimeError as e:
            print(f"{rel(src)}: does not compile\n{e}")
            return False, [], []
        results = [check_function(obj, n, image) for n in names]
        stray = stray_data(obj)
        order = definition_order(obj, src)
    if order:
        results.append("FILE: " + order)
    if stray:
        results.append("FILE: the object has data of its own (would shift the game's data): " + ", ".join(stray))
    if not quiet:
        print("\n".join(results))
    ok = [r.split(":")[0] for r in results if r.endswith(": MATCH")]
    bad = [r.split(":")[0] for r in results if not r.endswith(": MATCH")]
    return not bad, ok, bad


# --------------------------------------------------------------------------------------------------------------------
# editing sources

def include_line(src, name):
    folder = None
    text = Path(src).read_text()
    m = re.search(rf'^{INCLUDE_ASM}\("([^"]+)",', text, re.M)
    if m:
        folder = m.group(1)
    else:
        path = find_asm(name)
        folder = rel(path.parent).replace("/matchings/", "/nonmatchings/")
    return f'{INCLUDE_ASM}("{folder}", {name});'


def revert(src, names):
    lines = Path(src).read_text().splitlines(keepends=True)
    done = []
    for name in names:
        start = next((i for i, line in enumerate(lines)
                      if re.match(rf"^(?!\s)(?!{INCLUDE_ASM}).*\b{name}\s*\([^;]*$", line)
                      and "{" in "".join(lines[i:i + 3])), None)
        if start is None:
            continue
        end = next(i for i in range(start, len(lines)) if lines[i].startswith("}"))
        lines[start:end + 1] = [include_line(src, name) + "\n"]
        done.append(name)
    Path(src).write_text("".join(lines))
    return done


def run_hooks(kind, src):
    for cmd in HOOKS.get(kind, []):
        sh(cmd.format(file=rel(src), root=ROOT), capture_output=True)


# --------------------------------------------------------------------------------------------------------------------
# git

def git(*args, check=False):
    return subprocess.run(["git", *args], cwd=ROOT, capture_output=True, text=True, check=check)


def modified_sources():
    out = git("status", "--porcelain").stdout.splitlines()
    files = [line[3:] for line in out if line[:2].strip() in ("M", "MM", "AM", "A")]
    pats = SOURCES
    return [ROOT / f for f in files if any(fnmatch.fnmatch(f, p.replace("**/", "*")) or fnmatch.fnmatch(f, p) for p in pats)]


def commit(paths, message):
    for _ in range(8):
        r = git("add", *[rel(p) for p in paths])
        if r.returncode == 0:
            r = git("commit", "-q", "-m", message)
            if r.returncode == 0:
                return git("log", "--oneline", "-1").stdout.strip()
        if "index.lock" not in (r.stderr or ""):
            break
        import time
        time.sleep(3)
    return None


# --------------------------------------------------------------------------------------------------------------------
# commands

def cmd_show(args):
    name = args[0]
    path = find_asm(name)
    if not path:
        sys.exit(f"{name}: no .s in {', '.join(rel(d) for d in ASM_DIRS)}")
    srcs = [s for s in source_files() if re.search(rf"\b{name}\b", s.read_text())]
    print(f"function {name}   asm {rel(path)}   source {', '.join(rel(s) for s in srcs) or '?'}")
    for line in path.read_text().splitlines():
        m = ADDR_RE.match(line + "\n") if line.strip().startswith("/*") else None
        if m:
            print(f"{m.group(1)}{' ' if len(m.group(3)) > 2 else ''} {m.group(4):10} {m.group(5).strip()}")
        elif re.match(r"^\s+(\.L\w+:|jlabel|alabel)", line):
            print("  " + line.strip())
    if "--no-m2c" not in args and TC.get("m2c"):
        r = sh(TC["m2c"].format(asm=path, root=ROOT), capture_output=True, text=True)
        print("--- m2c ---")
        print((r.stdout or r.stderr).strip()[:6000])


def worklogs():
    return sorted({p for pattern in WORKLOGS for p in glob.glob(str(ROOT / pattern))})


def tried_functions():
    """Functions named in a worklog or saved as a near miss."""
    names = set()
    for log in worklogs():
        names |= set(re.findall(r"\b\w+\b", Path(log).read_text()))
    if NEAR_MISSES and NEAR_MISSES.exists():
        names |= {p.stem for p in NEAR_MISSES.iterdir()}
    return names


def cmd_next(args):
    max_size = 1 << 32
    if "--max-size" in args:
        k = args.index("--max-size")
        max_size = int(args[k + 1], 0)
        args = args[:k] + args[k + 2:]
    skip = set()
    if "--untried" in args:
        args = [a for a in args if a != "--untried"]
        skip = tried_functions()
    files = [Path(a) for a in args] or source_files()
    rows = []
    for src in files:
        for folder, name in re.findall(rf'^{INCLUDE_ASM}\("([^"]+)",\s*(\w+)\);', Path(src).read_text(), re.M):
            if name in skip:
                continue
            path = ROOT / folder / f"{name}.s"
            if not path.exists():
                path = find_asm(name)
                if not path:
                    continue
            start, size, insns, _ = parse_asm(path)
            if size > max_size:
                continue
            text = path.read_text()
            flags = []
            if "jtbl_" in text:
                flags.append("jtbl")
            vu = sum(1 for _, op, _, _ in insns if re.match(r"^(v[a-z]+(\.\w+)?|vcallms\w*|qm[tf]c2\S*|lqc2|sqc2)$", op))
            if vu:
                flags.append(f"vu0:{100 * vu // len(insns)}%")
            if insns[0][1] in ("sqc2", "lqc2") or (insns[0][1] == "addiu" and re.match(r"\$(29|sp), \$(29|sp), 0x", insns[0][2])):
                flags.append("fragment?")
            rows.append((size, name, rel(src), ",".join(flags)))
    for size, name, src, flags in sorted(rows):
        print(f"{size:#7x}  {name:28} {src}  {flags}")


def cmd_check(args):
    src = Path(args[0])
    names = defined_functions(src) if args[1:] == ["--all"] else args[1:]
    ok, _, _ = run_check(src, names)
    sys.exit(0 if ok else 1)


def cmd_try(args):
    run_hooks("pre_check", Path(args[0]))
    cmd_check(args)


def cmd_revert(args):
    for name in revert(Path(args[0]), args[1:]):
        print(f"{name}: reverted")


def cmd_done(args):
    src, log, message = Path(args[0]), Path(args[1]), args[2]
    run_hooks("pre_check", src)
    run_hooks("pre_commit", src)
    ok, good, bad = run_check(src, defined_functions(src), quiet=True)
    if not ok:
        print("NOT COMMITTED: does not match or does not compile: " + " ".join(bad))
        sys.exit(1)
    print(f"{len(good)} functions match")
    line = commit([src, log] if log.exists() else [src], message)
    print(line or "commit failed")
    sys.exit(0 if line else 1)


def cmd_all(args):
    files = [Path(a) for a in args] or source_files()
    total_ok, total_bad, broken = 0, [], []
    for src in files:
        names = defined_functions(src)
        if not names:
            continue
        ok, good, bad = run_check(src, names, quiet=True)
        total_ok += len(good)
        if bad and not good and len(bad) == 1 and bad[0].startswith(rel(src)):
            broken.append(rel(src))
        total_bad += bad
    print(f"match {total_ok}, differ {len(total_bad)}" + (f": {' '.join(total_bad)}" if total_bad else ""))
    sys.exit(0 if not total_bad else 1)


def cmd_state(args):
    print("== session state (" + rel(STATE) + ")")
    print(STATE.read_text().strip() if STATE and STATE.exists() else "(none: write one, see references/recovery.md)")
    print("\n== last commits")
    print(git("log", "--oneline", "-8").stdout.strip())
    unpushed = git("log", "--oneline", "@{u}..HEAD").stdout.strip()
    print(f"\n== not pushed: {len(unpushed.splitlines()) if unpushed else 0} commits")
    print("\n== uncommitted sources")
    mods = modified_sources()
    if not mods:
        print("none")
    for src in mods:
        names = defined_functions(src)
        ok, good, bad = run_check(src, names, quiet=True)
        print(f"{rel(src)}: {len(good)} match" + (f", differ: {' '.join(bad)}" if bad else ""))
    if TC.get("progress"):
        print("\n== progress")
        print(sh(TC["progress"], capture_output=True, text=True).stdout.strip())
    print("\n== worklogs (last commit, lines)")
    warnings, long = [], []
    for log in worklogs():
        lines = len(Path(log).read_text().splitlines())
        when = git("log", "-1", "--format=%cr", "--", rel(log)).stdout.strip() or "never committed"
        print(f"{rel(log)}: {when}, {lines} lines")
        if lines > 400:
            long.append(f"{Path(log).name} {lines}")
    if long:
        warnings.append(f"long worklogs ({', '.join(long)} lines): workers read only the notes at the top and use "
                        "`dk next --untried`")
    last = git("log", "-1", "--format=%H %cr", "--", rel(STATE)).stdout.strip() if STATE else ""
    if last:
        sha, when = last.split(" ", 1)
        ago = git("rev-list", "--count", "HEAD", f"^{sha}").stdout.strip()
        print(f"{rel(STATE)}: {when}, {ago} commits ago")
    stale = [f for f, _ in render_docs()]
    if stale:
        warnings.append(f"generated blocks out of date in {', '.join(rel(f) for f in stale)}: run `dk docs --commit`")
    if warnings:
        print("\n== warnings")
        print("\n".join(warnings))


def render_docs():
    """(path, new text) for every configured document whose generated blocks are out of date."""
    out = []
    blocks = {name: None for name in DOCS.get("blocks", {})}
    for doc in DOCS.get("files", []):
        path = ROOT / doc
        text = new = path.read_text()
        for name, cmd in DOCS.get("blocks", {}).items():
            if f"<!-- dk:{name} -->" not in new:
                continue
            if blocks[name] is None:
                blocks[name] = sh(cmd, capture_output=True, text=True).stdout.strip()
            new = re.sub(rf"(<!-- dk:{name} -->\n).*?(\n?<!-- /dk:{name} -->)",
                         lambda m: m.group(1) + blocks[name] + "\n" + m.group(2).lstrip("\n"), new, flags=re.S)
        if new != text:
            out.append((path, new))
    return out


def cmd_docs(args):
    changed = render_docs()
    for path, text in changed:
        path.write_text(text)
        print(f"{rel(path)}: updated")
    if not changed:
        print("documents up to date")
    elif "--commit" in args:
        print(commit([p for p, _ in changed], "docs: progress") or "commit failed")


def cmd_rescue(args):
    mods = modified_sources()
    rescued = []
    for src in mods:
        run_hooks("pre_check", src)
        names = defined_functions(src)
        ok, good, bad = run_check(src, names, quiet=True)
        head = git("show", f"HEAD:{rel(src)}").stdout
        to_revert = [n for n in bad if re.search(rf"{INCLUDE_ASM}\([^)]*\b{n}\);", head)]
        lost = [n for n in bad if n not in to_revert]
        if to_revert:
            revert(src, to_revert)
        ok2, good2, bad2 = run_check(src, defined_functions(src), quiet=True)
        print(f"{rel(src)}: reverted {len(to_revert)} work-in-progress function(s); {len(good2)} match"
              + (f"; STILL DIFFERS (was C++ at HEAD, investigate): {' '.join(bad2)}" if bad2 else ""))
        if ok2:
            run_hooks("pre_commit", src)
            rescued.append(src)
    if "--commit" in args and rescued:
        print(commit(rescued, "decomp: rescue work in progress after an interruption") or "commit failed")


def asm_signature(path):
    """(instructions with labels made relative and symbols abstracted, symbols in order of appearance)."""
    _, _, insns, _ = parse_asm(path)
    base = insns[0][0]
    norm, syms = [], []
    for _, op, args, _ in insns:
        args = re.sub(r"\.L([0-9A-Fa-f]{8})", lambda m: f"L{int(m.group(1), 16) - base:x}", args)
        if op in ("jal", "j") and re.match(r"^[A-Za-z_][\w.$]*$", args):
            syms.append(args)
            args = "SYM"
        else:
            def sub(m):
                syms.append(m.group(2))
                return f"%{m.group(1)}(SYM"
            args = re.sub(r"%(hi|lo|gp_rel)\(([\w.$]+)", sub, args)
        norm.append(f"{op} {args}")
    return tuple(norm), syms


def function_text(text, name):
    lines = text.splitlines(keepends=True)
    for i, line in enumerate(lines):
        if re.match(rf"^(?!\s)(?!{INCLUDE_ASM}).*\b{re.escape(name)}\s*\([^;]*$", line) and "{" in "".join(lines[i:i + 3]):
            j = i
            while not lines[j].startswith("}"):
                j += 1
            return "".join(lines[i:j + 1])
    return None


def local_type_names(text):
    return set(re.findall(r"^(?:struct|union|class)\s+(\w+)\s*[:{]", text, re.M)) | \
        set(re.findall(r"^typedef\b[^;]*?\b(\w+)\s*(?:__attribute__\(\(.*?\)\)\s*)?;", text, re.M)) | \
        set(re.findall(r"^(?:struct|union|class)\s+(\w+)\s*;", text, re.M))


def type_definition(text, name):
    lines = text.splitlines(keepends=True)
    for i, line in enumerate(lines):
        if re.match(rf"^(?:struct|union|class)\s+{name}\b[^;{{]*\{{.*\}}\s*;\s*$", line):
            return line
        if re.match(rf"^(?:struct|union|class)\s+{name}\s*;", line):
            return line
        if re.match(rf"^(?:struct|union|class)\s+{name}\b[^;]*$", line):
            j, depth = i, 0
            while True:
                depth += lines[j].count("{") - lines[j].count("}")
                if depth <= 0 and "}" in lines[j]:
                    return "".join(lines[i:j + 1])
                j += 1
        if re.match(rf"^typedef\b[^;]*\b{name}\s*(?:__attribute__\(\(.*?\)\)\s*)?;", line):
            return line
    return None


def twin_declaration(ttext, name):
    """A declaration line of `name` (function or variable) in the twin's file, as a line with C linkage."""
    for line in ttext.splitlines():
        if not line or line[0] in " \t#" or line.startswith(INCLUDE_ASM) or not re.search(rf"\b{re.escape(name)}\b", line):
            continue
        s = line.strip()
        d = re.match(rf"^(.*\b{re.escape(name)}\s*\(.*\))\s*(?:const\s*)?\{{\s*$", s)
        if d:
            s = d.group(1) + ";"
        elif "{" in s.split("//")[0].replace("{}", "") and not s.endswith(";") or not re.search(r";\s*(//.*)?$", s):
            continue
        if re.match(r"^(typedef|struct|union|class|return)\b", s) or "=" in s.split("(")[0] and "__asm__" not in s:
            continue
        if not re.search(rf"\b{re.escape(name)}\s*(\(|\[|;|__)", s):
            continue
        if s.startswith('extern "C"'):
            return s + "\n"
        return 'extern "C" ' + (s[7:] if s.startswith("extern ") else s) + "\n"
    return None


def adapt_signature(body, name, known):
    """If `name` is already prototyped in the target file with other types, give the definition the prototype's
    types and bind the twin's parameters by cast. Returns (body, error)."""
    proto = re.search(rf"^(?!\s)(?!{INCLUDE_ASM})([^\n(=]*?)\b{name}\s*\(([^)]*)\)\s*;", known, re.M)
    sig = re.search(rf"^(.*?)\b{name}\s*\(([^)]*)\)\s*\{{[^\n]*\n", body)
    if not proto or not sig:
        return body, None
    norm = lambda s: re.sub(r"\s+", "", s.replace('extern "C"', "").replace("extern", ""))
    if norm(proto.group(2)) == norm(sig.group(2)):
        return body, None
    if norm(proto.group(1)) != norm(sig.group(1)):
        return body, f"return type differs from the prototype in the file ({proto.group(0).strip()})"
    old = [x.strip() for x in sig.group(2).split(",")] if sig.group(2).strip() else []
    new = [x.strip() for x in proto.group(2).split(",")] if proto.group(2).strip() else []
    if len(old) != len(new) or any("(" in x or "[" in x for x in old + new):
        return body, f"parameters differ from the prototype in the file ({proto.group(0).strip()})"
    params, casts = [], []
    for i, (o, n) in enumerate(zip(old, new)):
        om, nm = re.match(r"^(.*?)(\w+)$", o), re.match(r"^(.*?)(\w+)$", n)
        if norm(o) == norm(n):
            params.append(o)
        elif not om or not om.group(1).strip():
            return body, f"parameter {i} cannot be rebound to the prototype ({proto.group(0).strip()})"
        else:
            ntype = n if not nm or not nm.group(1).strip() else nm.group(1).strip()
            params.append(f"{ntype} a{i}")
            casts.append(f"    {o} = ({om.group(1).strip()})a{i};\n")
    head = f"{sig.group(1)}{name}({', '.join(params)}) {{\n"
    return head + "".join(casts) + body[sig.end():], None


def cmd_twins(args):
    listing = "--list" in args
    only = {Path(a).resolve() for a in args if a != "--list"}
    srcs = source_files()
    texts = {s: s.read_text() for s in srcs}
    owner, pending, written = {}, set(), set()
    for s, t in texts.items():
        for n in re.findall(rf'^{INCLUDE_ASM}\("[^"]+",\s*(\w+)\);', t, re.M):
            pending.add(n)
            owner[n] = s
        for n in re.findall(r"^(?!\s)(?!#).*?\b(\w+)\s*\([^;{]*\)\s*(?:const\s*)?\{", t, re.M):
            written.add(n)
            owner.setdefault(n, s)
    groups = {}
    for name in pending | written:
        path = find_asm(name)
        if not path:
            continue
        key, syms = asm_signature(path)
        if len(key) >= 4:
            groups.setdefault(key, []).append((name, syms))
    total = ok = 0
    for members in groups.values():
        done = [m for m in members if m[0] in written and m[0] not in pending]
        for name, syms in members:
            if name not in pending or not done or (only and owner[name].resolve() not in only):
                continue
            src = owner[name]
            twin, tsyms = next(((n, s) for n, s in done if owner[n] == src), done[0])
            if len(tsyms) != len(syms):
                continue
            mapping = {twin: name}
            for a, b in zip(tsyms, syms):
                if a != b and mapping.setdefault(a, b) != b:
                    mapping = None
                    break
            if not mapping:
                continue
            total += 1
            if listing:
                print(f"{rel(src)}: {name} <- {twin} ({rel(owner[twin])})")
                continue
            text, ttext = src.read_text(), owner[twin].read_text()
            body = function_text(ttext, twin)
            line = re.search(rf'^{INCLUDE_ASM}\("[^"]+",\s*{name}\);\n', text, re.M)
            if not body or not line:
                continue
            for a, b in mapping.items():
                body = re.sub(rf"\b{re.escape(a)}\b", b, body)
            decls, missing, shapes, conflicts = [], [], [], []
            known = re.sub(rf"^{INCLUDE_ASM}[^\n]*\n", "", text, flags=re.M)
            body, err = adapt_signature(body, name, known)
            if err:
                print(f"{rel(src)}: {name} skipped: {err}; change the prototype or write it by hand")
                continue
            for a in dict.fromkeys(tsyms):
                b = mapping.get(a, a)
                if a == twin:
                    continue
                if re.search(rf"\b{re.escape(b)}\b", known):
                    mine, theirs_d = twin_declaration(known, b), twin_declaration(ttext, a)
                    flat = lambda d: re.sub(r"\s|\b(?:extern|static)\b|\"C\"", "", re.sub(r"\b[su]32\b", "int", d.split("__")[0]))
                    flat = lambda d, f=flat: f(re.sub(rf"\b(?:{re.escape(a)}|{re.escape(b)})\b", "N",
                                                      re.sub(r"(?<=[\w*&])\s+\w+(?=\s*[,)\[])", "", d)))
                    if mine and theirs_d and flat(mine) != flat(theirs_d):
                        if "__asm__" not in theirs_d:
                            alias = f"{b}__{name}"
                            decls.append(re.sub(rf"\b{re.escape(a)}\b", alias, re.sub(r";\s*(//.*)?$", "", theirs_d.strip()))
                                         + f' __asm__("{b}");\n')
                            body = re.sub(rf"\b{re.escape(b)}\b", alias, body)
                            continue
                        conflicts.append(f"{b}: file has `{mine.strip()}`, twin has `{theirs_d.strip()}`")
                    if mine and theirs_d and "(" not in mine.split("__")[0] and "(" not in theirs_d.split("__")[0]:
                        shape = lambda d: re.match(rf"^(.*?)\b{re.escape(b if d is mine else a)}\s*(\[[^\]]*\])?",
                                                   d.replace('extern "C"', "").replace("extern", ""))
                        sm, st = shape(mine), shape(theirs_d)
                        ty = lambda m: re.sub(r"\s", "", re.sub(r"\b[su]32\b", "int", m.group(1)).replace("unsignedint", "u32"))
                        if sm and st and ty(sm) == ty(st):
                            if st.group(2) is None and sm.group(2) is not None:
                                body = re.sub(rf"\b{re.escape(b)}\b(?!\s*\[)", f"{b}[0]", body)
                            elif st.group(2) is not None and sm.group(2) is None:
                                if re.search(rf"\b{re.escape(b)}\b(?!\[0\])", body):
                                    shapes.append(b)
                                body = re.sub(rf"\b{re.escape(b)}\[0\]", b, body)
                    continue
                d = twin_declaration(ttext, a)
                if d:
                    decls.append(re.sub(rf"\b{re.escape(a)}\b", b, d))
                else:
                    missing.append(a)
            if shapes:
                print(f"{rel(src)}: {name} skipped: {' '.join(shapes)} is an array in {rel(src)} but a scalar in "
                      f"{rel(owner[twin])} and the twin uses it as a pointer; adapt by hand")
                continue
            if missing:
                print(f"{rel(src)}: {name} skipped: no declaration of {' '.join(missing)} found in {rel(owner[twin])}; "
                      f"declare it in {rel(src)} and retry")
                continue
            types, have, theirs = [], local_type_names(text), local_type_names(ttext)
            try:
                seen = set()

                def visit(chunk):
                    for w in dict.fromkeys(re.findall(r"\w+", chunk)):
                        if w in theirs and w not in have and w not in seen:
                            seen.add(w)
                            block = type_definition(ttext, w)
                            if block is None:
                                raise KeyError(w)
                            visit(block)
                            types.append(block)
                if owner[twin] != src:
                    visit(body)
                    visit("".join(decls))
            except KeyError as e:
                print(f"{rel(src)}: {name} skipped: cannot copy the definition of type {e.args[0]} from "
                      f"{rel(owner[twin])}; define it in {rel(src)} and retry")
                continue
            new = text[:line.start()] + "".join(t + "\n" for t in types) + "".join(decls) + body + text[line.end():]
            src.write_text(new)
            run_hooks("pre_check", src)
            good, _, _ = run_check(src, [name], quiet=True)
            if good:
                ok += 1
                print(f"{rel(src)}: {name} MATCH (from {twin})")
            else:
                src.write_text(text)
                print(f"{rel(src)}: {name} no match (from {twin})")
                for c in conflicts:
                    print(f"  declaration differs from the twin's file, the copied body may need casts: {c}")
    print(f"{total} candidates" if listing else f"{ok} of {total} twins matched")


def cmd_protos(args):
    src, name = Path(args[0]), args[1]
    text = src.read_text()
    body = function_text(text, name)
    if not body:
        sys.exit(f"{name}: not defined in {rel(src)}")
    called = set(re.findall(r"\b(\w+)\s*\(", body)) - {name}
    decl = re.compile(r'^(?:extern "C"\s+)?(void|int|s32|u32|unsigned int)\s+(\w+)\s*(\([^;{]*\))[^;{]*;')
    decls = {}
    for line in text.splitlines():
        m = decl.match(line)
        if m and m.group(2) in called:
            label = re.search(r'(?:__asm__|asm)\("([\w.$]+)"\)', line)
            decls[m.group(2)] = (m.group(1), m.group(3), label.group(1) if label else m.group(2))
    image = IMAGE.read_bytes()

    def variant(combo):
        head, new = "", body
        for n in combo:
            ret, params, label = decls[n]
            head += f'extern "C" {"int" if ret == "void" else "void"} {n}__r{params} __asm__("{label}");\n'
            new = re.sub(rf"\b{re.escape(n)}(?=\s*\()", f"{n}__r", new)
        return text.replace(body, head + new, 1)

    def score(candidate):
        with tempfile.TemporaryDirectory() as tmp:
            path = Path(tmp) / src.name
            path.write_text(candidate)
            try:
                obj = compile_object(path, Path(tmp))
            except RuntimeError:
                return None
            r = check_function(obj, name, image)
        return 0 if r.endswith(": MATCH") else len(r.splitlines())

    base = score(text)
    print(f"{name}: {len(decls)} callees to try, {base} difference lines now")
    best = None
    for k in (1, 2):
        for combo in itertools.combinations(sorted(decls), k):
            candidate = variant(combo)
            sc = score(candidate)
            flips = ", ".join(f'{n} as {"int" if decls[n][0] == "void" else "void"}' for n in combo)
            if sc == 0:
                src.write_text(candidate)
                print(f"{name}: MATCH with {flips} (alias declarations written to {rel(src)})")
                return
            if sc is not None and base is not None and sc < base and (best is None or sc < best[0]):
                best = (sc, flips)
    print(f"{name}: no match; closest: {best[1]} ({best[0]} lines)" if best else f"{name}: no flip gets closer")
    sys.exit(1)


COMMANDS = {"show": cmd_show, "next": cmd_next, "check": cmd_check, "try": cmd_try, "revert": cmd_revert,
            "done": cmd_done, "all": cmd_all, "twins": cmd_twins, "protos": cmd_protos, "state": cmd_state, "rescue": cmd_rescue,
            "docs": cmd_docs}


def main():
    if len(sys.argv) < 2 or sys.argv[1] not in COMMANDS:
        sys.exit(__doc__)
    COMMANDS[sys.argv[1]](sys.argv[2:])


if __name__ == "__main__":
    main()
