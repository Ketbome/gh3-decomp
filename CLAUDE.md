# gh3-decomp

Matching decompilation of Guitar Hero III (PS2, USA, SLUS-21672). Goal: C++ that rebuilds `SLUS_216.72` byte for byte.

## Stack

- splat (Python, `.venv`) splits the executable into `asm/` (generated, not committed)
- SN Systems ee-gcc 2.95.3 build 136 (`tools/compilers/`, Windows exe run with wibo), `-O2 -G8 -fno-exceptions -fno-rtti`
- PS2 binutils `mips-ps2-decompals` (`tools/binutils/`), ninja
- Details and evidence: `docs/toolchain.md`

## Commands

- `scripts/setup_tools.sh`: download tools, create `.venv`
- `.venv/bin/python configure.py`: extract from the ISO, split, write `build.ninja` (rerun after editing the yaml)
- `ninja`: build and compare (`build/SLUS_216.72.ok` only when byte-identical)
- `.venv/bin/python scripts/progress.py`: progress

## Conventions

- Never commit game data: the ISO, `disc/`, `asm/`, `build/` and `tools/` are ignored.
- A function moves to C++ by adding a `cpp` subsegment in `config/SLUS_216.72.yaml` at its ROM offset
  (VRAM - 0x100000), followed by an `asm` subsegment for the rest. The build must stay byte-identical.
- Code that does not match stays as assembly.
- Unknown names: `extern "C"` with splat names `func_XXXXXXXX` / `D_XXXXXXXX`. Real names go in `config/symbol_addrs.txt`.
- Documentation states what is verified by byte match and what is inferred.
- Git identity for this repo: ketbome / pablo.moraga.san@gmail.com (local config).
