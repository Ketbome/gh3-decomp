# Worklog B (src/game/t_1ABAA0.cpp .. t_249620.cpp)

The 0x4 candidates are tails of the previous function (splat split errors): skipped, as are other split tails (functions starting with `addiu $sp, +N` or ending without `jr`).

Skipped as a class (toolchain, not source): functions that save `$s0..$s7` (original `sd`, our build `sq`), and
most loads of non-gp globals done as `lui $x; lw $x, %lo(..)($x)` into one register (assembler-macro form in the
original; our gcc splits `%hi` into a separate register, it only lines up by chance).

Toolchain findings (for the integrator, not fixable from source):
- `scripts/fcheck.py --all` only checks `func_*` names; check `CFunc_*` and other names explicitly.
- `scripts/fcheck.py` drops the relocation of an instruction that follows a bare `nop` (the `\s+` in its line regex
  eats the newline), so such functions report DIFFERS even when identical (t_1B2168 func_001B3BA8, func_001B3C98).
- Loops unrolled x4/x8/x16 (`andi n,3` preconditioning, `li 31; addiu -16; bgez`) come out byte-identical with
  `-funroll-loops` added; -O2 alone never unrolls. Other files (t_1ABAA0 func_001ACCC0) match without it, so the
  flag looks per object.
- Short loops padded with 3 nops before the back branch (SN assembler r5900 short-loop fix); our gas does not pad.
- `cvt.w.s` (float to int) is rejected by our assembler for r5900.

Session 2 (toolchain with -fopt-stack): `sd` saves now match. Macro-form global loads (`lui $x; lw $x, %lo($x)`
into the SAME register) are gcc treating the symbol as small data (`lw $x, sym` macro, not split) while gas has no
`.extern` size for it: declare `extern T D_X[] __attribute__((section(".sdata")));` (incomplete type = no `.extern`,
section .sdata = gcc does not split). For another type on the same symbol use `__asm__("D_X")` on a second declaration.
The original assembler used gp_rel for such a symbol only when the load sits in a branch delay slot; our gas
expands the macro there (warning), so those functions cannot match. A symbol is either gp or macro per file.
Virtual calls: vptr after the data members (`char pad[off]; virtual ...`), entry n of the vtable at 8*n (lh delta, lw pfn).

Compiler habits that helped: single-bit tests `andi+sltu` need an inline member `bool Test(m) { return (f & m) != 0; }`
(a direct `(x & 4) != 0` folds to a shift); a callee declared to return int changes `$v0`/`$v1` choice; returning
the pointer from a call (`return r;`) gives the `move $v1,$v0` copy; arguments passed through untouched (a1..a3
live) show as the virtual-call temporaries moving to `$a2`/`$t0`, so declare and pass them; returning a virtual
call's result puts the function pointer in `$v0`; `(int)x & ~1` gives `li -2` where a u32 gives `lui/ori`.

## t_1ABAA0

Matched 0.

Given up:
- func_001ACF98: short loop padded with 3 nops (assembler short-loop fix); C otherwise lines up

## t_1BF628

Matched 0.

Given up:
- func_001BF9C8: address of D_00372D58 built by an la macro (nop in the branch delay slot); ours splits it and hoists lui
- func_001BFDD8: short loop padded with 3 nops (SN assembler r5900 short-loop fix), our gas does not pad

## t_1B4190

Matched 0. func_001B5BD0..func_001B5C80 and func_001B47B8, func_001B46C0: macro-form non-gp global loads/stores
(tried func_001B5BD0..5C80: `%hi` lands in another register).


## t_1CBB50

Matched 52: func_001CBC10 func_001CBC58 func_001CBC60 func_001CBC70 func_001CBC78 func_001CBC98 func_001CBCC0 func_001CBCC8 func_001CBCD8 func_001CBCF0 func_001CBCF8 func_001CBD10 func_001CBD20 func_001CBD28 func_001CBD30 func_001CBD48 func_001CBD70 func_001CBD78 func_001CBD88 func_001CBD90 func_001CBD98 func_001CBDA0 func_001CBDA8 func_001CBDB0 func_001CBDB8 func_001CBFE8 func_001CC050 func_001CC070 func_001CC090 func_001CC0A0 func_001CC0B0 func_001CC0C0 func_001CC0D0 func_001CC0E8 func_001CC170 func_001CC198 func_001CC258 func_001CC260 func_001CC270 func_001CC2D8 func_001CCE00 func_001CD1F0 func_001CD2B8 func_001CD640 func_001CD678 func_001CD6B0 func_001CD6B8 func_001CD6C0 func_001CD6D0 func_001CDA00 func_001CDA20 func_001CDA40

Given up:
- func_001CC310: register allocation (li v0,1 hoisted before %hi load into a0); 3 tries

## t_1C9B30

Matched 19: func_001CA000 func_001CA008 func_001CA010 func_001CA020 func_001CA038 func_001CA998 func_001CB080 func_001CB550 func_001CB558 func_001CB560 func_001CB568
func_001C9B30 func_001C9FB0 func_001CA670 CFunc_SetHostMode CFunc_SetJoinMode CFunc_MarkGameOver CFunc_ChangeLevelPending (session 2)

Given up:
- func_001CB708: needs D_00370EE0 in macro form while func_001C9B30 uses it gp-relative; gas applies the `.extern` size to every use of the symbol in the file, so both cannot coexist
- CFunc_IsHost: last `x ? 1 : 0` of a u64 callee is a branch (move v1,v0; bnez) in the original, ours sltu/movz (5 tries)

## t_1CBB50

Matched 52: func_001CBC10 func_001CBC58 func_001CBC60 func_001CBC70 func_001CBC78 func_001CBC98 func_001CBCC0 func_001CBCC8 func_001CBCD8 func_001CBCF0 func_001CBCF8 func_001CBD10 func_001CBD20 func_001CBD28 func_001CBD30 func_001CBD48 func_001CBD70 func_001CBD78 func_001CBD88 func_001CBD90 func_001CBD98 func_001CBDA0 func_001CBDA8 func_001CBDB0 func_001CBDB8 func_001CBFE8 func_001CC050 func_001CC070 func_001CC090 func_001CC0A0 func_001CC0B0 func_001CC0C0 func_001CC0D0 func_001CC0E8 func_001CC170 func_001CC198 func_001CC258 func_001CC260 func_001CC270 func_001CC2D8 func_001CCE00 func_001CD1F0 func_001CD2B8 func_001CD640 func_001CD678 func_001CD6B0 func_001CD6B8 func_001CD6C0 func_001CD6D0 func_001CDA00 func_001CDA20 func_001CDA40

Given up:
- func_001CC310: register allocation (li v0,1 hoisted before %hi load into a0); 3 tries

## t_1C9B30

Matched 11: func_001CA000 func_001CA008 func_001CA010 func_001CA020 func_001CA038 func_001CA998 func_001CB080 func_001CB550 func_001CB558 func_001CB560 func_001CB568

Given up:
- func_001C9B30, func_001C9FB0, func_001CA670, CFunc_SetHostMode, CFunc_SetJoinMode: save $s0 with sd (our build emits sq)
- CFunc_MarkGameOver, CFunc_ChangeLevelPending: D_00369A60 loaded with lui/lw into the same register (assembler macro); our gcc splits %hi into another register
- func_001CB708: needs D_00370EE0 via %hi/%lo while func_001C9B30 uses it gp-relative (one declaration per file)

## t_1B00D0

Matched 3: func_001B1478 func_001B1C40 func_001B1C60

Given up:
- func_001B1E38, func_001B1D60: global stores through $at / mixed gp and %hi access of one symbol (assembler macro form)
- func_001B00D0, func_001B01D8, func_001B02F0, func_001B1AB8: loops unrolled by 4 (our -O2 does not unroll)

## t_1BB500

Matched 2: func_001BD158 func_001BD438

## t_1BD608

Matched 2: func_001BF230 func_001BF258

Given up:
- func_001BE498: two nops before a branch and a different load schedule after a 0x60-byte struct copy
- func_001BF5C0: argument register allocation (a kept in $a0 in the original); 3 tries

## t_1B2168

Matched 6: func_001B2230 func_001B3CF8 func_001B3D00 func_001B3D10 func_001B3D18 func_001B3DB0

Given up:
- func_001B2168: float->int cvt.w.s rejected by our assembler for r5900
- func_001B21A0: cvt.s.w lands in the jr delay slot in ours, original keeps a nop
- func_001B3BA8, func_001B3C98: MATCH with a fixed parser, but scripts/fcheck.py misses the reloc of an instruction that follows a bare nop (regex \s+ eats the newline) and reports DIFFERS; left as INCLUDE_ASM until fcheck is fixed (C3C98 needs callees declared returning int)

## t_1C1A30

Matched 5: func_001C2C30 func_001C2C88 func_001C2CD8 func_001C2D08 func_001C3278

## t_1C3A40

Matched 3: func_001C50B8 func_001C56E0 func_001C5730

Given up:
- func_001C4460: original reloads q->unk4 at a merge point (no CSE); 4 tries (plain, inline helper, volatile)

## t_1C5A68

Matched 5: func_001C5CB8 func_001C5CD8 func_001C5D28 CFunc_SetAnalogStickActiveForMenus CFunc_SetEnableMovies

Given up:
- func_001C6868, func_001C67C0: loops unrolled (x16 / x8); our -O2 does not unroll

## t_1C7AA0

Matched 13: func_001C7AA0 func_001C7B18 func_001C7B38 func_001C7B98 func_001C8470 func_001C8568 func_001C8E98 func_001C8ED0 func_001C91D8 func_001C9368 func_001C9468 func_001C94A8 func_001C94C0

Given up:
- func_001C95D8: our gcc turns the last compare into movz/movn (if-chain, early returns, switch, default-first: 5 tries)

## t_1CE0A8

Matched 25: func_001CE218 func_001CE670 func_001CE778 func_001CE7A8 func_001CE868 func_001CE888 func_001CE8C0 func_001CEB48 func_001CEBA8 func_001CEDE0 func_001CEF30 func_001CEF58 func_001CEF80 func_001CEFD8 func_001CF120 func_001CF748 func_001CF7B8 func_001CF8E8 func_001CF910 func_001CFA50 func_001CFB88 func_001CFBA8 func_001CFD78 func_001CFD98 func_001CFF58

## t_1D00B0

Matched 13: func_001D03B8 func_001D0788 func_001D0F18 func_001D0F38 func_001D0F68 func_001D1000 func_001D1030 func_001D1038 func_001D1068 func_001D1418 func_001D1610 func_001D1EA8 func_001D1ED8

Given up:
- func_001D1D90: passes a 128-bit vector loaded with lq as three float args (pcpyud); not attempted

## t_1D2508

Matched 13: func_001D29C8 func_001D2AC8 func_001D2AE8 func_001D2B08 func_001D2B18 func_001D2C18 func_001D2C38 func_001D2C58 func_001D2C70 func_001D3508 func_001D4198 func_001D41B8 func_001D4208

Given up:
- func_001D2A30: passes a 128-bit vector loaded with lq as three float args (pcpyud); not attempted

## t_1D4540

Matched 32: func_001D4540 func_001D4560 func_001D4580 func_001D45A0 func_001D4600 func_001D4650 func_001D48A0 func_001D4AA0 func_001D4CF0 func_001D4D48 func_001D5000 func_001D5018 func_001D5020 func_001D5028 func_001D5030 func_001D51F8 func_001D52E8 func_001D5348 func_001D5350 func_001D54A0 func_001D5570 func_001D5588 func_001D55C0 func_001D57F0 func_001D57F8 func_001D5800 func_001D5848 func_001D5858 func_001D5B60 func_001D6450 func_001D6460 func_001D6488

Given up:
- func_001D55D8: xor operand/load order of two flag bits (5 tries, plain, temps, bitfields)
- func_001D5870, func_001D5D28, func_001D5F60, func_001D59E8: D_00368A38 is macro-form (no .extern) but gp_rel when in a branch delay slot (original assembler); our gas expands the macro into the slot
- func_001D4BB0: original copies the hoisted key load (move t0,v1); 4 tries
- func_001D5CB0: callee-saved register assignment of passed-through args (2 tries)

## t_1D6598

Matched 21: func_001D67C8 func_001D6BA0 func_001D6BA8 func_001D7710 func_001D7C28 func_001D7C68 func_001D7CA8 func_001D7CE8 func_001D7D28 func_001D7D68 func_001D7DA8 func_001D7DE8 func_001D7E28 func_001D7E68 func_001D7EA8 func_001D7EE8 func_001D7F00 func_001D7F20 func_001D8058 func_001D80D8 func_001D8150

Given up:
- func_001D6738: D_00368A38 gp_rel in a jal delay slot (macro symbol in this file)
- func_001D8208: register choice/schedule of the tail (dead u8[4] stores, vtable/255 in v1/v0 swapped); 6 tries
