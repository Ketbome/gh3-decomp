# gh3-decomp

Matching decompilation of Guitar Hero III (PS2, USA, SLUS-21672). Goal: C++ that rebuilds `SLUS_216.72` byte for byte.

## Stack

- splat, m2c, pyelftools (Python, `.venv`); splat splits the executable into `asm/` (generated, not committed)
- SN Systems ee-gcc 2.95.3 build 136 (`tools/compilers/`, Windows exe run with wibo), `-O2 -G8 -fopt-stack -mno-check-zero-division -fno-exceptions -fno-rtti`
- PS2 binutils `mips-ps2-decompals` (`tools/binutils/`), ninja
- Details and evidence: `docs/toolchain.md`

## Commands

- `scripts/setup_tools.sh`: download tools, create `.venv`
- `.venv/bin/python configure.py`: extract from the ISO, split, write `build.ninja` (rerun after editing the yaml)
- `scripts/integrate.sh`: verify HEAD in a separate worktree (configure + sync + ninja) and push if identical
- `ninja`: build and compare (`build/SLUS_216.72.ok` only when byte-identical)
- `.venv/bin/python scripts/progress.py`: progress
- `.venv/bin/python scripts/fcheck.py <file.cpp> <func...|--all>`: check functions without linking (safe in parallel)
- `.venv/bin/python scripts/candidates.py <files...>`: functions still in INCLUDE_ASM, smallest first
- `.venv/bin/m2c -t mipsee-gcc-c <func.s>`: first C draft of a function
- `scripts/show.py <func>` (asm + m2c), `scripts/try.py <file> <func>` (GP_DATA + fcheck),
  `scripts/done.sh <file> <worklog> <msg>` (padding, full check, commit): the worker loop, see `docs/agent_protocol.md`
- `scripts/check_all.py`: fcheck every C++ function (regression check after toolchain changes)
- `scripts/qbkeys.py key <name>` / `build <qb script dirs>`: Neversoft checksums -> `config/qbkeys.txt`

## Conventions

- Never commit game data: the ISO, `disc/`, `asm/`, `build/` and `tools/` are ignored.
- Game code is split in `src/game/t_<addr>.cpp` chunks (cpp subsegments in the yaml); decompiling = replacing an
  INCLUDE_ASM line with C++. Workflow and rules: `docs/decomp_guide.md`. The build must stay byte-identical.
- Code that does not match stays as INCLUDE_ASM. C++ must not emit data of its own (rodata/literals/statics).
- Unknown names: `extern "C"` with splat names `func_XXXXXXXX` / `D_XXXXXXXX`. Real names go in `config/symbol_addrs.txt`.
- Clean-room only: never use leaked or copyrighted source code (e.g. the leaked THUG source) as a reference.
  Names come from the executable itself (strings, tables), the game's own QB scripts and our own analysis.
- Documentation states what is verified by byte match and what is inferred.
- Git identity for this repo: ketbome / pablo.moraga.san@gmail.com (local config).
