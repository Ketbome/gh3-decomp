#!/usr/bin/env python3
"""Decompiles functions whose assembly is identical to a function already written in C/C++ ("twins").

Two functions are twins when their instructions are the same once addresses and symbol names are abstracted. For
each function still in INCLUDE_ASM with a matched twin, the twin's code is copied in place of its INCLUDE_ASM line
with the function name and the symbols it uses mapped to the new function's (in order of appearance in the
assembly), missing declarations are copied too, and the result is checked; anything that does not match is put back.

Usage: .venv/bin/python scripts/twins.py [--list] [src files...]   (default: every source)
       --list only prints the twins it would try.
"""

import collections
import re
import subprocess
import sys
from pathlib import Path

ROOT = Path(__file__).resolve().parent.parent
PY = str(ROOT / ".venv" / "bin" / "python")
INS = re.compile(r"^\s+/\* [0-9A-F]+ ([0-9A-F]{8}) [0-9A-F]{8} \*/\s+(\S+)\s*(.*)$", re.M)


def signature(path):
    """(normalized instruction tuple, symbols in order of appearance): branch labels become offsets from the start,
    call targets and %hi/%lo/%gp_rel operands become SYM."""
    ins = INS.findall(path.read_text())
    if not ins:
        return None, None
    base = int(ins[0][0], 16)
    norm, syms = [], []
    for _, op, args in ins:
        args = re.sub(r"\.L([0-9A-F]{8})", lambda m: f"L{int(m.group(1), 16) - base:x}", args)
        if op in ("jal", "j") and re.match(r"^[A-Za-z_][\w.$]*$", args.strip()):
            syms.append(args.strip())
            args = "SYM"
        else:
            def sub(m):
                syms.append(m.group(2))
                return f"%{m.group(1)}(SYM"
            args = re.sub(r"%(hi|lo|gp_rel)\(([\w.$]+)", sub, args)
        norm.append(f"{op} {args}")
    return tuple(norm), syms


def function_block(text, name):
    lines = text.splitlines(keepends=True)
    for i, line in enumerate(lines):
        if re.match(rf"^(?!\s)(?!INCLUDE_ASM).*\b{re.escape(name)}\s*\([^;]*$", line) and "{" in "".join(lines[i:i + 3]):
            j = i
            while not lines[j].startswith("}"):
                j += 1
            return "".join(lines[i:j + 1])
    return None


def declaration(text, name):
    m = re.search(rf"^[^\n]*\b{re.escape(name)}\b[^\n]*;[^\n]*$", text, re.M)
    return m.group(0) if m and "(" in m.group(0) or (m and "extern" in m.group(0)) else (m.group(0) if m else None)


def local_types(text):
    return set(re.findall(r"^(?:struct|union|class)\s+(\w+)\s*[:{]", text, re.M)) | \
        set(re.findall(r"^typedef\b[^;]*?\b(\w+)\s*;", text, re.M))


def type_block(text, name):
    """The definition of a local struct/union/class/typedef named `name` (whole lines), or None."""
    lines = text.splitlines(keepends=True)
    for i, line in enumerate(lines):
        if re.match(rf"^(?:struct|union|class)\s+{name}\b[^;]*$", line):
            j, depth = i, 0
            while True:
                depth += lines[j].count("{") - lines[j].count("}")
                if depth <= 0 and "}" in lines[j]:
                    return "".join(lines[i:j + 1])
                j += 1
        if re.match(rf"^typedef\b[^;]*\b{name}\s*;", line):
            return line
    return None


def needed_types(body, twin_text, text):
    """Type definitions the body needs from the twin's file that the target file lacks, dependencies first."""
    have, theirs = local_types(text), local_types(twin_text)
    out, seen = [], set()

    def visit(chunk):
        for word in dict.fromkeys(re.findall(r"\w+", chunk)):
            if word in theirs and word not in have and word not in seen:
                seen.add(word)
                block = type_block(twin_text, word)
                if block is None:
                    raise KeyError(word)
                visit(block)
                out.append(block)
    visit(body)
    return out


def main():
    args = sys.argv[1:]
    listing = "--list" in args
    args = [a for a in args if a != "--list"]
    only = {Path(a).resolve() for a in args}
    sources = {p.stem.split(".")[0]: p for p in (ROOT / "src" / "game").glob("*.c*")}

    # what is pending / written comes from the sources (asm/ may lag behind until the next split)
    pending, written = set(), set()
    for src in sources.values():
        text = src.read_text()
        pending |= set(re.findall(r'^INCLUDE_ASM\("[^"]+",\s*(\w+)\);', text, re.M))
        written |= set(re.findall(r"^(?!\s)(?!INCLUDE_ASM).*?\b(\w+)\s*\([^;{]*\)\s*\{", text, re.M))
    groups = collections.defaultdict(list)
    seen = set()
    for d in ("nonmatchings", "matchings"):
        for p in (ROOT / "asm" / d / "game").rglob("*.s"):
            if p.stem in seen:
                continue
            seen.add(p.stem)
            state = "nonmatchings" if p.stem in pending else "matchings" if p.stem in written else None
            if not state:
                continue
            key, syms = signature(p)
            if key and len(key) >= 4:
                groups[key].append((state, p, syms))

    work = collections.defaultdict(list)  # source -> [(pending name, twin name, twin source, mapping)]
    for members in groups.values():
        done = [m for m in members if m[0] == "matchings"]
        for d, p, syms in members:
            if d != "nonmatchings" or not done:
                continue
            src = next((sp for sp in sources.values() if re.search(rf",\s*{p.stem}\);", sp.read_text())), None)
            if not src or (only and src.resolve() not in only):
                continue
            same = [m for m in done if m[1].parent.name == p.parent.name]
            same = [m for m in same if m[1].stem != p.stem]
            done_other = [m for m in done if m[1].stem != p.stem]
            if not done_other:
                continue
            twin = (same or done_other)[0]
            if len(twin[2]) != len(syms):
                continue
            mapping = {twin[1].stem: p.stem}
            for a, b in zip(twin[2], syms):
                if a != b:
                    if mapping.get(a, b) != b:
                        mapping = None
                        break
                    mapping[a] = b
            if mapping:
                work[src].append((p.stem, twin[1].stem, sources[twin[1].parent.name], mapping))

    total = ok = 0
    for src, items in sorted(work.items()):
        for name, twin, twin_src, mapping in items:
            total += 1
            if listing:
                print(f"{src.name}: {name} <- {twin} ({twin_src.name}) {len(mapping) - 1} symbol(s) mapped")
                continue
            text = src.read_text()
            twin_text = twin_src.read_text()
            body = function_block(twin_text, twin)
            line = re.search(rf'^INCLUDE_ASM\("[^"]+",\s*{name}\);\n', text, re.M)
            if not body or not line:
                continue
            try:
                types = needed_types(body, twin_text, text) if twin_src != src else []
            except KeyError:
                continue
            new_body = body
            for a, b in mapping.items():
                new_body = re.sub(rf"\b{re.escape(a)}\b", b, new_body)
            decls = []
            for a, b in mapping.items():
                if a == twin or re.search(rf"\b{re.escape(b)}\b", text):
                    continue
                d = declaration(twin_text, a)
                if d:
                    decls.append(re.sub(rf"\b{re.escape(a)}\b", b, d.strip()) + "\n")
            new_text = text[:line.start()] + "".join(t + "\n" for t in types) + new_body + text[line.end():]
            if decls:
                m = re.search(r'^extern "C" \{\n', new_text, re.M)
                if m:
                    new_text = new_text[:m.end()] + "".join(decls) + new_text[m.end():]
                else:
                    new_text = new_text.replace('#include "common.h"\n', '#include "common.h"\n\nextern "C" {\n'
                                                + "".join(decls) + "}\n", 1)
            src.write_text(new_text)
            r = subprocess.run([PY, str(ROOT / "scripts" / "try.py"), str(src), name], cwd=ROOT,
                               capture_output=True, text=True)
            if r.stdout.strip().endswith("MATCH") and "DIFFERS" not in r.stdout and "FILE" not in r.stdout:
                ok += 1
                print(f"{src.name}: {name} MATCH (from {twin})")
            else:
                src.write_text(text)
                print(f"{src.name}: {name} no match (from {twin}), left in asm")
    print(f"{ok} of {total} twins matched" if not listing else f"{total} candidates")


if __name__ == "__main__":
    main()
