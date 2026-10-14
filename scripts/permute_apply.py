#!/usr/bin/env python3
"""Puts the permuter's best version of a function back into its near-miss file and checks it.

Usage: .venv/bin/python scripts/permute_apply.py <func> [--output DIR]

Takes build/permute/<func>/output-<lowest score>-*/source.c (or the given output dir), extracts the function and
any helper functions the permuter added (e.g. `inline_fn`), writes nonmatching/<func>.<ext> with them in place of
the old attempt, and runs scripts/try.py on it. The file is updated only if the result is not worse.
"""

import re
import shutil
import subprocess
import sys
import tempfile
from pathlib import Path

ROOT = Path(__file__).resolve().parent.parent
PY = str(ROOT / ".venv" / "bin" / "python")


def block(text, name):
    """(start, end) of the definition of `name` in text (from its first line to the matching closing brace)."""
    m = re.search(rf"^[^\n;{{}}]*\b{re.escape(name)}\s*\([^;{{]*\)\s*\{{", text, re.M)
    if not m:
        return None
    depth, j = 0, m.end() - 1
    while True:
        depth += {"{": 1, "}": -1}.get(text[j], 0)
        if depth == 0:
            return m.start(), j + 1
        j += 1


def score_of(result):
    out = result.stdout
    if out.strip().endswith("MATCH") and "DIFFERS" not in out:
        return 0
    return len([line for line in out.splitlines() if re.match(r"^\s+[0-9A-F]{8}:", line)]) or 999


def main():
    func = sys.argv[1]
    work = ROOT / "build" / "permute" / func
    outs = sorted(work.glob("output-*"), key=lambda d: int(d.name.split("-")[1]))
    if "--output" in sys.argv:
        outs = [Path(sys.argv[sys.argv.index("--output") + 1])]
    if not outs:
        sys.exit(f"{func}: no permuter output in {work}")
    best = (outs[0] / "source.c").read_text()
    base = (work / "base.c").read_text()
    target = next(iter(sorted((ROOT / "nonmatching").glob(f"{func}.*"))), None)
    if not target:
        sys.exit(f"{func}: no nonmatching/{func}.*")
    text = target.read_text()

    span = block(best, func)
    new_func = best[span[0]:span[1]]
    header_end = new_func.index("(")
    if 'extern "C"' not in new_func[:header_end] and target.suffix != ".c":
        new_func = 'extern "C" ' + new_func.lstrip()
    helpers = []
    for m in re.finditer(r"^(?:static\s+)?inline\b[^\n]*\b(\w+)\s*\(", best, re.M):
        name = m.group(1)
        if name not in base:
            h = block(best, name)
            if h:
                helpers.append("static " + best[h[0]:h[1]].replace("static ", "", 1) + "\n\n")
    old = block(text, func)
    if not old:
        sys.exit(f"{func}: no definition in {target}")
    candidate = text[:old[0]] + "".join(helpers) + new_func + text[old[1]:]

    src = next((p for p in (ROOT / "src" / "game").glob("*.c*")
                if re.search(rf",\s*{func}\);", p.read_text()) or re.search(rf"\b{func}\s*\(", p.read_text())), None)
    stem = src.name if src else target.name
    with tempfile.TemporaryDirectory() as tmp:
        before_file = Path(tmp) / "before" / stem
        after_file = Path(tmp) / "after" / stem
        before_file.parent.mkdir()
        after_file.parent.mkdir()
        before_file.write_text(text)
        after_file.write_text(candidate)
        before = subprocess.run([PY, str(ROOT / "scripts" / "try.py"), str(before_file), func], cwd=ROOT,
                                capture_output=True, text=True)
        after = subprocess.run([PY, str(ROOT / "scripts" / "try.py"), str(after_file), func], cwd=ROOT,
                               capture_output=True, text=True)
        print(after.stdout.strip()[:3000])
        if score_of(after) <= score_of(before):
            shutil.copy(after_file, target)
            print(f"{target.relative_to(ROOT)} updated ({score_of(before)} -> {score_of(after)} differing lines)")
        else:
            print(f"kept {target.relative_to(ROOT)} ({score_of(before)} differing lines, permuter's gives {score_of(after)})")


if __name__ == "__main__":
    main()
