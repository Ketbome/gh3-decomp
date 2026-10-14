# gh3-decomp

A work-in-progress matching decompilation of **Guitar Hero III: Legends of Rock** for the PlayStation 2 (USA
release, SLUS-21672): the game's code rewritten as C++ that compiles, with the compiler the developers used, to
exactly the bytes on the disc.

This repository contains **no game data and no copy of the game**. To build it you need your own disc image of
that release; the build checks its result against it.

## Status

<!-- dk:progress -->
| Binary | Code in matching C++ | Functions in C++ | Functions still in assembly |
|---|---|---|---|
| `SLUS_216.72` (game code, 9,002 functions) | 22.05% | 5,754 | 3,248 |
<!-- /dk:progress -->

The rebuilt executable is byte-identical to the original. The table is regenerated at every integration
(`scripts/dk.py docs`); `.venv/bin/python scripts/progress.py` prints the current numbers.

## Building

You need:

- your disc image, placed in the repository's top folder (or in `disc/`) as
  `Guitar Hero III - Legends of Rock (USA).iso`;
- `7z`, `ninja`, `curl` and Python 3.9+;
- the tools in `tools/` (not part of this repository): `scripts/setup_tools.sh` downloads the PS2 binutils,
  SN Systems' `ee-gcc` 2.95.3 (from the [decompme compilers](https://github.com/decompme/compilers) release),
  [wibo](https://github.com/decompals/wibo) to run it, and creates `.venv` with [splat](https://github.com/ethteck/splat), [m2c](https://github.com/matt-kempster/m2c)
  and pyelftools.

```
scripts/setup_tools.sh
.venv/bin/python configure.py && ninja
```

`configure.py` extracts the executable from your disc image, checks it is the USA release, splits it and writes the
build file; `ninja` assembles, compiles, links and compares.

Works on macOS (arm64) and Linux (x86-64).

## Layout

| Path | Contents |
|---|---|
| `src/`, `include/` | The decompiled code |
| `config/` | How the binary is split (`SLUS_216.72.yaml`) and the symbol names |
| `scripts/` | Tool setup, `dk.py` (per-function check, candidates, commit, recovery), progress, integration, permuter |
| `docs/` | [decomp_guide.md](docs/decomp_guide.md) (how to contribute), [toolchain.md](docs/toolchain.md), [text_map.md](docs/text_map.md), [STATE.md](docs/STATE.md) (current plan) |

Names of functions and variables are ours unless stated; the executable is stripped. Names come only from the
executable itself (strings, the script command table), the game's own scripts and our own analysis: no leaked or
otherwise copyrighted source code is used. A function that does not match
yet stays as the original assembly.

## How it is made

With AI agents following the [matching-decomp skill](https://github.com/Ketbome/decomp-skills) (method, `dk`
tool, session recovery), every function verified byte for byte before it is committed.

## Licence

What is ours in this repository (the names, comments, documentation, scripts and build configuration, and the work
of reconstruction) is dedicated to the public domain under [CC0 1.0](LICENSE). That dedication cannot and does not
cover the game itself: the program this code reproduces belongs to its rights holders.

## Legal

This project is not affiliated with or endorsed by Activision, Neversoft, Budcat Creations or any other rights
holder. It exists for preservation, study and interoperability. You need your own legally obtained copy of the game
to use anything here.
