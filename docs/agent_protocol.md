# Worker protocol (agents)

Read this and `docs/decomp_guide.md` (the matching rules), then work. You own a set of `src/game` files that nobody
else edits while you run. Always run commands as `cd /Users/ketbome/Personal/gh3-decomp && ...` (zsh: `$VAR` is not
word-split; pass file lists explicitly or through xargs).

## Per function

1. Pick: `.venv/bin/python scripts/candidates.py <your files> [--max-size 0x400]` (smallest first; flags: `jtbl`
   switch, `vu0:N%` VU0 share, `lit`). Skip what your worklog lists as given up for a reason that still holds.
2. Look: `.venv/bin/python scripts/show.py <func>` prints the file, the original assembly and an m2c draft.
3. Write the C++ in place of that function's `INCLUDE_ASM` line only (never touch neighbouring lines). `extern "C"`,
   same name; declarations in the file's `extern "C" { }` block; structs local to the file, fields named by offset.
4. Check: `.venv/bin/python scripts/try.py <file> <func>` (adds needed GP_DATA lines, then compares). Iterate.
5. Near miss (only registers or instruction order differ)? Save your best attempt as
   `nonmatching/<func>.cpp` (a copy of the whole source file with your attempt in place) and list it in the worklog
   as `near miss`, and commit it (`git add nonmatching/<func>.cpp && git commit -m "near miss: <func>"`): the
   integrator runs the permuter on those (`scripts/permute.py`). Do not run it yourself.
   Give up after ~15 tries: `.venv/bin/python scripts/revert_func.py <file> <func>`; keep any prototype other code
   in the file needs (the file must compile); note the function and why in your worklog.
6. Identical functions: `.venv/bin/python scripts/twins.py <your files>` copies every matched function onto the
   functions with the same assembly in your files (renaming symbols) and keeps only what matches. Run it after
   matching anything, and prefer functions that have twins (`scripts/twins.py --list`).
7. After each match (or a few): `scripts/done.sh <file> docs/worklog/<range>.md "decomp: <file> +N functions"`.
   It fixes padding, refuses to commit if anything in the file does not match, and commits only those two paths.

Before stopping, `git status` must show none of your files modified.

## Never

- `git add -A`, `git push`, `git stash`, `git checkout/reset/restore`, or git on other people's files.
- `configure.py`, `ninja`, splat; edits to `config/`, `include/`, `scripts/`, other docs, other ranges, `asm/`.
- A non-matching function left in C++; string literals or statics; asm with ordinary instructions to force the
  compiler (only VU0/MMI/COP2 instructions belong in asm); leaked Neversoft source.
- More than one fcheck/m2c/compile at a time (16 GB RAM machine). Helper files only in your own scratch folder.

## Skip (open toolchain questions)

Split tails (fragments starting mid-function), functions saving `$31` with `sq`, functions whose only difference is
the nops before `div.s`, VU0 functions above ~40% VU0.

## Final report (under 200 words)

Matched count and approximate bytes, commits, patterns that worked (for the guide), give-ups worth a toolchain look,
confident name suggestions (address -> name -> evidence). No code.
