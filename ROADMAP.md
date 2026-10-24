# Roadmap

Where this project is going after the matching decompilation, and how to help. Current progress is in the
[README](README.md#status). Phases 1 and 2 run now; everything after phase 3 is a plan, not a commitment, and will
be refined as the code gets clearer.

## Why the PS2 version

Guitar Hero III was built by different teams per platform: Neversoft made the Xbox 360 and PS3 versions, the PS2
version was done with Budcat Creations, the Wii version by Vicarious Visions and the PC/Mac version by Aspyr.

- The PS2 executable was built with SN Systems' ee-gcc 2.95.3, which is deterministic, well studied and available
  (splat, m2c, the decomp.me compilers): a byte-matching decompilation was feasible from day one.
- The Xbox 360 version means MSVC on PowerPC, where matching tooling is still at an early stage. For 360 games,
  static recompilation (XenonRecomp-style) is the realistic route to a PC build, not a matching decomp.
- GH3 already has an official PC release with an active modding scene. The PS2 version is the one nobody had
  preserved.

## Phases

### 1. Matching (in progress)

Every function rewritten as C++ that compiles to the exact original bytes. The build is verified byte for byte at
every integration. Workflow: [docs/decomp_guide.md](docs/decomp_guide.md).

### 2. Names and types (in progress, in parallel)

Function and variable names, types, structs, classes and headers. None of these change the output bytes, so this
does not have to wait for 100%: every rename is checked by the same byte-identical build. Names come only from the
executable itself (strings, the script command table), the game's own QB scripts and our own analysis. No leaked
or otherwise copyrighted source code is ever used.

### 3. Shiftable build

A build that relinks without the original fixed addresses: code and data can grow or move and the game still runs.
This is the prerequisite for any mod that changes code and for a port.

### 4. Code cleanup

Once phases 1 to 3 are done, a separate non-matching tree where the code is made readable: compiler-shaped
constructs rewritten as natural C++, dead workarounds removed, comments and documentation added. The matching tree
stays as the reference. Every cleanup step is checked against the matching build by behaviour (the game boots,
menus work, songs play and score the same) instead of by bytes. AI assistants can help here, with every change
verified the same way.

### 5. Mods

Make community mods easy to write, share and combine.

- Much of GH3 is driven by its QB scripts (song lists, menus, career, note tracks), so many mods are data, not code.
  Goal: document the QB format and the script command table, and load mod files (songs, scripts, textures) from a
  mod folder without rebuilding archives.
- Code mods on top of the shiftable build: hooks at documented points (song loading, scoring, input, menus) so a mod
  does not have to patch the executable.
- A mod format with a manifest (name, version, what it changes) so several mods can be installed together and
  conflicts are reported instead of silently breaking the game.

### 6. PC port

Replace the PS2 platform layer with portable backends while the game logic stays the same:

- rendering (GS, VU1 microcode) with a modern graphics API;
- audio (IOP, SPU2 streaming);
- input (pads, USB guitar and drum controllers);
- saves (memory card) and file access (CD/DVD).

### 7. Extras (ideas)

- Loaders for the HD versions' asset formats (textures, models, audio from the Xbox 360/PS3 releases): game logic
  and QB scripts are largely shared across versions, the formats are per platform, and the new renderer of phase 6
  is where such loaders would live. You need your own copy of any version whose assets you load.
- Widescreen, higher resolutions and frame rates, online leaderboards for custom songs.

## How to help

Open an issue before starting, so work does not overlap with someone else's (human or agent).

- **Decompile functions** (phase 1): needs your own disc image of the USA release and the toolchain
  ([Building](README.md#building)); the loop and the rules are in [docs/decomp_guide.md](docs/decomp_guide.md).
- **Names, types and structs** (phase 2): no compiling needed. Strings, QB scripts and a disassembler are enough;
  proposed names go to [docs/worklog/names_pending.md](docs/worklog/names_pending.md) with the evidence for each.
- **Tooling**: the open questions in [docs/toolchain.md](docs/toolchain.md) (compiler and assembler quirks that
  block families of functions), the permuter setup, progress reporting.
- **Formats** (phases 5 to 7): documenting the QB script format, archives, textures, models and audio of the PS2
  version.

What is ours here is public domain (CC0 1.0, see [LICENSE](LICENSE)); contributions are accepted under the same
terms. Never contribute game data or anything taken from leaked source code.
