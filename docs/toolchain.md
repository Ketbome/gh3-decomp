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

Flags: `-O2 -G8 -fopt-stack -mno-check-zero-division -fno-exceptions -fno-rtti`. The game has no divide-by-zero
traps (292 divisions, no `break 7`). `-fopt-stack` is an SN option ("Optimise stack
frame"): without it saved `$s` registers are stored as 128-bit (`sq`) above `$ra`; with it they are `sd`, below `$ra`,
as in the game. Adding it changed none of the 721 functions matched at the time. Some objects also used
`-funroll-loops` (per-file `// cflags:` line, see decomp_guide.md). The binary has no RTTI type names and an almost empty
`.gcc_except_table`. `-G8` is verified by byte match (a getter/setter of a 4-byte global reached through `$gp`).

The compiler is a Windows executable, run with [wibo](https://github.com/decompals/wibo). Its output is assembled
with the modern binutils (`mips-ps2-decompals`), as o64 so that 32-bit address arithmetic stays `addiu`/`addu`;
`include/gcc_prelude.inc` makes `move` encode as `daddu`, and `scripts/asm_filter.py` rewrites `li.s` as the
inline `lui`/`ori`/`mtc1` SN's assembler produced (the modern gas would use `.lit4`), and expands global
loads/stores the way SN's one-pass assembler did: ee-gcc writes the `.extern sym,size` at the end of the file, so
outside delay slots the size was not known yet (`lui`+`%lo`), while in a delay slot (`nomacro`) it used `%gp_rel`.
Data the object defined itself was known small (`GP_DATA` in the source). Verified on 1,471 matched functions.
Switch jump tables: the compiler's table is dropped and the code is pointed at the game's `jtbl_` (k-th table of a
function = k-th `jtbl_` of its original assembly); the case labels are defined in `build/jlabels.ld`.
Short loops are padded with nops before the backward branch up to 6 instructions (the R5900 short-loop erratum,
which SN's assembler worked around). The prelude also stops gas from adding a hazard nop after `mfc1` (SN's assembler kept the ones after `mtc1` and
between an FPU compare and `bc1t`/`bc1f`). `scripts/set_eabi64.py` then sets the object's ABI flags
back to EABI64 so the linker accepts it next to the assembly.

## C++ names

gcc 2.95 mangling (`f1__Fv`, `__3Big` for a constructor, `__builtin_new` for `operator new`). Until a function's
real class and signature are known, decompiled code uses `extern "C"` with the splat names (`func_XXXXXXXX`).

## SDK

Sony libraries 3.0.0 (`PsIIlibgraph3000`, `PsIIlibmc2 3010`, ...), GameSpy SDK (built as `.cpp`), libstdc++
(`bad_alloc`). None of their ranges are mapped yet.

## `div.s` nops

`div.s` is preceded by two nops in most of the game (418 of ~700) and by none elsewhere. Verified (2026-10-14):
ee-gcc 2.95.3-136 and every SN build emit none; Sony's ee-gcc 2.96/3.2 always emit `nop; nop; div.s` (the 29 `div.s`
of Sony's libraries in the game all have two); the `as.exe` shipped with the compiler inserts none. So the game's
SN assembler added them, and its rule is not known: identical sequences (`lwc1; lwc1; div.s`) get 0 in one place and
2 in another, and a decision tree on the 4 preceding and 3 following instructions predicts 79% (always-2: 76%).
`sqrt.s` has two nops in 213 of 214 cases; workers write them in their `asm()`.
Inferred, not derived: `scripts/asm_filter.py` gives the k-th `div.s` of a function the nop count of the k-th one in
its original assembly (as with `jtbl_`), under `.set noreorder`. Checked: the 7 matched functions with `div.s` stay
identical; func_00174CB8, func_00122FF8, func_002B7108 match with it and not without.

## Open questions

- 26 functions (scattered, e.g. func_002AFE38) save every register including `$ra` with `sq`, at the offsets
  ee-gcc 2.95.2/2.95.3-114 use (ascending, `$ra` on top), although their values are plain ints. Not reproduced
  with 2.95.3-136 and `-fopt-stack` yet: skip them.
- 58 functions hide behind 16 bytes of `addiu $sp,$sp,+X; nop; addiu $sp,$sp,+Y; nop` (not code that runs: no
  path reaches it); splat starts the function there, so the real prologue sits 0x10 bytes in. Fix (to do when no
  worker runs): give the real start a symbol (`func_<addr+0x10>`), resplit, sync_src; the 16 bytes stay INCLUDE_ASM.
  About 650 other "fragments" (lone sqc2/lqc2 or epilogue-first pieces) are to be classified the same way.
