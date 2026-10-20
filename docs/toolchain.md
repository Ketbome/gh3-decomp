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
SN's assembler forgot those sizes at the start of the next original object: our source files merge several objects,
so `TEXT_PAD` (padding at an object end) and `OBJECT_END()` (an object that ended on a 16-byte boundary, no padding
left) reset what GP_DATA declared, in `asm_filter.py` and `fix_gp_data.py`; an INCLUDE_ASM function whose assembly
ends in 2+ nops counts as an object end too. Evidence: 139 symbols are reached both ways; 654 `lui` uses after a
`%gp_rel` one, all across object boundaries; the 4 left inside one file sit at 16-byte-aligned function starts
(func_00120180, func_001CDA60, func_00276FD8, func_002DCD68) and match with `OBJECT_END();` in front;
`dk all` 5983 match, 0 differ.
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

## Delay slots

Verified with the compiler's own `as.exe` (2.9-ee-991111b, `-O2`, 2026-10-14): outside `.set noreorder` SN's
assembler moves only COP2 instructions into a branch delay slot (`lqc2`, `sqc2`, `qmfc2`, `qmtc2`, `v*`, `vcallms`;
not `ctc2`/`cfc2`, `cvt.s.w`, `mtc1`/`mfc1`, `lwc1`/`swc1`, integer ops or stores). gcc never puts an asm in a slot,
so the 287 COP2 slots of the game were filled by the assembler; 41 `cvt.s.w` and 64 volatile stores sit before a
branch with a `nop` slot. The modern gas moves anything it can: `scripts/asm_filter.py` puts a local label before
each branch whose previous instruction is not COP2 (gas does not move an instruction across a label).
With `mtc1 ..,$fN` before a label and a read of `$fN` after it, the hazard nop goes after the label (29 times,
never before); the filter writes it there. Across all 84,870 delay slots of the game, no instruction gcc cannot place in a slot
(`mtc1`, `cvt.*`, `div.s`, `ctc2`, ...) appears except COP2 ones. `gas -O1` instead breaks 11 functions (10 VU0 inline asm).
Checked: `dk all` 5796 match; func_001E0198 relied on gas moving a `move` into the slot and went back to asm
(near miss in nonmatching/).

## VU0 registers allocated by gcc

ee-gcc 2.95.3-136 allocates VU0 registers for `register TI v asm("vf1")` variables (constraint `"j"`) and emits
`lqc2`/`sqc2`/`qmfc2` itself, also copying them into branch-likely delay slots (41 in the game, 34 unmatched
functions); it writes the register without `$` (`vf1`), which gas rejects, so `scripts/asm_filter.py` adds it.
Branch-likely vs plain branch elsewhere is not a toolchain matter: 22 flag variants and all five SN compilers give
the same choice, and the 1255 branch-likely in matched functions reproduce; it follows register liveness in reorg
(C shape or permuter). Checked: `dk all` 5856 match, func_001FDC60 matches with it.

## If-conversion (`movz`/`movn`)

Not a toolchain matter. The original uses `movz`/`movn` 1365 times in 663 functions (187 of 225 files); all five SN
compilers and 2.96 convert the same test cases. Of 18 flag variants only `-O1` and `-fno-rerun-cse-after-loop` keep
the branch, and the latter breaks 209 of 5947 matched functions (`dk all` in a scratch copy) without fixing
func_0014E1B8. Cause: gcc 2.95's jump.c converts `if (c) x = v` only when `x` is a register; a value written
through a reference parameter of an inline function is still in memory at that pass, so the branch stays (source
pattern in decomp_guide.md; func_0021F020 matches with it). `cvt.w.s` is handled by the prelude macro
(`include/gcc_prelude.inc:8-12`, since 85ecf94; 25 matched functions use it).

## Open questions

- 26 functions (scattered, e.g. func_002AFE38) save every register including `$ra` with `sq`, at the offsets
  ee-gcc 2.95.2/2.95.3-114 use (ascending, `$ra` on top), although their values are plain ints. Not reproduced
  with 2.95.3-136 and `-fopt-stack` yet: skip them.
- 58 functions hide behind 16 bytes of `addiu $sp,$sp,+X; nop; addiu $sp,$sp,+Y; nop` (not code that runs: no
  path reaches it); splat starts the function there, so the real prologue sits 0x10 bytes in. Fix (to do when no
  worker runs): give the real start a symbol (`func_<addr+0x10>`), resplit, sync_src; the 16 bytes stay INCLUDE_ASM.
  About 650 other "fragments" (lone sqc2/lqc2 or epilogue-first pieces) are to be classified the same way.
