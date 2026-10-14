# Worker protocol (agents)

Read this and `docs/decomp_guide.md` (the matching rules), then work. You own a set of `src/game` files that nobody
else edits while you run. Always run commands as `cd /Users/ketbome/Personal/gh3-decomp && ...` (zsh: `$VAR` is not
word-split; pass file lists explicitly or through xargs). Below, `dk` means `.venv/bin/python scripts/dk.py`.

Your worklog: read only the notes at its top (before the first `## ` file section), not the whole file.
`grep -n <func> docs/worklog/*.md` tells you a function's history before you retry it.

## Per function

1. Pick: `dk next <your files> --untried [--max-size 0x400]` (smallest first, leaves out every function a worklog
   mentions or `nonmatching/` holds; flags: `jtbl` switch, `vu0:N%` VU0 share, `fragment?`). Without `--untried`
   only when your focus is retrying give-ups that a toolchain fix unblocked.
2. Look: `dk show <func>` prints the file, the original assembly and an m2c draft.
3. Write the C++ in place of that function's `INCLUDE_ASM` line only (never touch neighbouring lines). `extern "C"`,
   same name; declarations in the file's `extern "C" { }` block; structs local to the file, fields named by offset.
4. Check: `dk try <file> <func>` (adds needed GP_DATA lines, then compares). Iterate.
5. Near miss (only registers or instruction order differ)? Save your best attempt as
   `nonmatching/<func>.cpp` (a copy of the whole source file with your attempt in place) and list it in the worklog
   as `near miss`, and commit it (`git add nonmatching/<func>.cpp && git commit -m "near miss: <func>"`): the
   integrator runs the permuter on those (`scripts/permute.py`). Do not run it yourself.
   Give up after ~15 tries: `dk revert <file> <func>`; keep any prototype other code in the file needs (the file
   must compile); note the function and why in your worklog.
6. Identical functions: `dk twins <your files>` copies every matched function onto the functions with the same
   assembly in your files (renaming symbols) and keeps only what matches. Run it after matching anything, and
   prefer functions that have twins (`dk twins --list`).
7. After each match (or a few): `dk done <file> docs/worklog/<range>.md "decomp: <file> +N functions"`.
   It fixes padding, refuses to commit if anything in the file does not match, and commits only those two paths.

Stop only at the limit your prompt gives (time or matches) or when `dk next <your files> --untried` lists nothing
you have not tried. Running out of easy candidates is not a reason: raise `--max-size`, take twins, retry give-ups
whose reason a toolchain fix has removed.

Before stopping, `git status` must show none of your files modified.

## Never

- `git add -A`, `git push`, `git stash`, `git checkout/reset/restore`, or git on other people's files.
- `configure.py`, `ninja`, splat; edits to `config/`, `include/`, `scripts/`, other docs, other ranges, `asm/`.
- A non-matching function left in C++; string literals or statics; asm with ordinary instructions to force the
  compiler (only VU0/MMI/COP2 instructions belong in asm); leaked Neversoft source.
- More than one check/m2c/compile at a time (16 GB RAM machine). Helper files only in your own scratch folder.

## Skip (open toolchain questions)

Split tails (fragments starting mid-function), functions saving `$31` with `sq`, VU0 functions above ~40% VU0.
The nops before `div.s` are no longer a reason to skip: `scripts/asm_filter.py` copies them from the original
(docs/toolchain.md), so `dk try` shows only real differences; retry earlier `div.s` give-ups.

## Final report (under 200 words)

Matched count and approximate bytes, commits, patterns that worked (for the guide), give-ups worth a toolchain look,
confident name suggestions (address -> name -> evidence). No code.
