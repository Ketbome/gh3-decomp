# Toolchain

## The executable

`SLUS_216.72` (sha1 `15992cec17deb6bf8e3d8fa4a2a5f1ef1b60f47e`), MIPS R5900, stripped: no symbol table, `.mdebug.eabi64`
is empty and the disc has no map file.

| Section | VRAM | Size | ROM offset |
|---|---|---|---|
| `.temp_init` (crt0, overlapped by `.stack` at run time) | `0x100000` | `0x3E88` | `0x000000` |
| `.text` | `0x10C000` | `0x21501C` | `0x00C000` |
| `.vutext` (VU1 microcode) | `0x321080` | `0x9000` | `0x221080` |
| `.data` | `0x32A080` | `0xD738` | `0x22A080` |
| `.rodata` | `0x337800` | `0x3078C` | `0x237800` |
| `.gcc_except_table` | `0x368000` | `0x5C` | `0x268000` |
| `.sdata` | `0x368080` | `0xA9C0` | `0x268080` |
| `.sbss` | `0x372A80` | `0x968` | - |
| `.bss` | `0x373400` | `0xB54A0` | - |

ROM offsets are into `disc/SLUS_216.72.rom`, the flat image `objcopy -O binary` makes of the ELF; the build compares
against it. `_gp` is `0x370070` (`.sdata` + `0x7FF0`). The `.DVP.overlay.*` sections are VU microcode that is not
loaded, so they are not part of the image.

`.sbss` and `.bss` start on 128-byte boundaries; splat's linker script only aligns to 16, so `configure.py`
patches it (`patch_ld_script`).

## Compiler: SN Systems ee-gcc 2.95.3, build 136, `-O2`

Verified by byte match (`src/game/probe.cpp`, `func_00200308`..`func_00200350`).

What points to it:

- Source paths left in `.rodata`: `c:/nxcommon_gh3c/...` (Neversoft's *nxcommon* engine, C++) and the crt0 string
  `crt0.s detected ProView`: ProView is SN Systems' debugger, so ProDG.
- No sibling calls (`jal f` at the end of a function, not `j f`): gcc 3.x makes them.
- Constructors return `this` (`return new X;` returns the constructor's `$v0` directly): gcc 2.x C++ ABI.
- Callee-saved registers are saved with `sd`/`ld`. The other SN builds in the decompme set (2.95.2-273a, -274,
  2.95.3-107, -114) save `$ra` with `sq`/`lq`; only 2.95.3-136 matches.
- Sony's ee-gcc 2.96 orders the prologue differently (`lui` before `subu $sp`).

Flags: `-O2 -G8 -fopt-stack -fno-exceptions -fno-rtti`. `-fopt-stack` is an SN option ("Optimise stack
frame"): without it saved `$s` registers are stored as 128-bit (`sq`) above `$ra`; with it they are `sd`, below `$ra`,
as in the game. Adding it changed none of the 721 functions matched at the time. Some objects also used
`-funroll-loops` (per-file `// cflags:` line, see decomp_guide.md). The binary has no RTTI type names and an almost empty
`.gcc_except_table`. `-G8` is verified by byte match (a getter/setter of a 4-byte global reached through `$gp`).

The compiler is a Windows executable, run with [wibo](https://github.com/decompals/wibo). Its output is assembled
with the modern binutils (`mips-ps2-decompals`), as o64 so that 32-bit address arithmetic stays `addiu`/`addu`;
`include/gcc_prelude.inc` makes `move` encode as `daddu`. `scripts/set_eabi64.py` then sets the object's ABI flags
back to EABI64 so the linker accepts it next to the assembly.

## C++ names

gcc 2.95 mangling (`f1__Fv`, `__3Big` for a constructor, `__builtin_new` for `operator new`). Until a function's
real class and signature are known, decompiled code uses `extern "C"` with the splat names (`func_XXXXXXXX`).

## SDK

Sony libraries 3.0.0 (`PsIIlibgraph3000`, `PsIIlibmc2 3010`, ...), GameSpy SDK (built as `.cpp`), libstdc++
(`bad_alloc`). None of their ranges are mapped yet.
