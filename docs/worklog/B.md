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
Session 2 stopped after t_1E75A8 (~150 functions); t_1E95C0 .. t_249620 are still untouched, and the files before
t_1D4540 only had their old give-ups retried.
Habits: `if (!c) return 0; return f();` needs `return c ? f() : 0;` (shared epilogue); list heads/iterators kept on
the stack match with two local `{s32; Node*}` structs (current and end, end re-stored each iteration); store order
of an init block usually comes out with the last store first, so write fields in the order that gives the target;
a 3-case `switch` (no jtbl) gives the `==6 / <6 / <=8` compare tree.
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

Matched 6 in session 4 (new asm_filter): func_001B47B8 func_001B5BD0 func_001B5BF8 func_001B5C20 func_001B5C50 func_001B5C80.
Given up: func_001B5CB0 (gp store placed in the bne delay slot in the original, ours schedules it before the compare; 6 tries);
func_001B46C0 not attempted.


## t_1CBB50

Matched 52: func_001CBC10 func_001CBC58 func_001CBC60 func_001CBC70 func_001CBC78 func_001CBC98 func_001CBCC0 func_001CBCC8 func_001CBCD8 func_001CBCF0 func_001CBCF8 func_001CBD10 func_001CBD20 func_001CBD28 func_001CBD30 func_001CBD48 func_001CBD70 func_001CBD78 func_001CBD88 func_001CBD90 func_001CBD98 func_001CBDA0 func_001CBDA8 func_001CBDB0 func_001CBDB8 func_001CBFE8 func_001CC050 func_001CC070 func_001CC090 func_001CC0A0 func_001CC0B0 func_001CC0C0 func_001CC0D0 func_001CC0E8 func_001CC170 func_001CC198 func_001CC258 func_001CC260 func_001CC270 func_001CC2D8 func_001CCE00 func_001CD1F0 func_001CD2B8 func_001CD640 func_001CD678 func_001CD6B0 func_001CD6B8 func_001CD6C0 func_001CD6D0 func_001CDA00 func_001CDA20 func_001CDA40

Given up:
- func_001CC310: register allocation (li v0,1 hoisted before %hi load into a0); 3 tries

## t_1C9B30

Matched 19: func_001CA000 func_001CA008 func_001CA010 func_001CA020 func_001CA038 func_001CA998 func_001CB080 func_001CB550 func_001CB558 func_001CB560 func_001CB568
func_001C9B30 func_001C9FB0 func_001CA670 CFunc_SetHostMode CFunc_SetJoinMode CFunc_MarkGameOver CFunc_ChangeLevelPending (session 2)

Given up:
- func_001CB708: matched in session 4 (new asm_filter)
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
- func_001B1E38: u16/u32 views of D_00372C30, register allocation and store order (session 4, 3 tries); func_001B1D60: short loops padded with nops
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
- func_001D5D28, func_001D5F60, func_001D59E8 (func_001D5870 matched in session 4 with the new asm_filter): D_00368A38 is macro-form (no .extern) but gp_rel when in a branch delay slot (original assembler); our gas expands the macro into the slot
- func_001D4BB0: original copies the hoisted key load (move t0,v1); 4 tries
- func_001D5CB0: callee-saved register assignment of passed-through args (2 tries)

## t_1D6598

Matched 21: func_001D67C8 func_001D6BA0 func_001D6BA8 func_001D7710 func_001D7C28 func_001D7C68 func_001D7CA8 func_001D7CE8 func_001D7D28 func_001D7D68 func_001D7DA8 func_001D7DE8 func_001D7E28 func_001D7E68 func_001D7EA8 func_001D7EE8 func_001D7F00 func_001D7F20 func_001D8058 func_001D80D8 func_001D8150

Given up:
- func_001D6738: matched in session 4 (new asm_filter)
- func_001D8208: register choice/schedule of the tail (dead u8[4] stores, vtable/255 in v1/v0 swapped); 6 tries

## t_1D85E8

Matched 16: func_001D85E8 func_001D8720 func_001D87B8 func_001D8828 func_001D8848 func_001D8878 func_001D8930 func_001D8978 func_001D89C0 func_001D8A08 func_001D8A50 func_001D8A88 func_001D8B30 func_001D8BA0 func_001D8BC8 func_001D8BF0

Given up:
- session 4 (new asm_filter + GP_DATA): matched func_001D88C0 func_001D97A0 func_001D9F40 func_001DA028 func_001DA0C8 func_001DA150 func_001DA1A0
- func_001D8AB8: D_0036D554 macro load kept out of the jal delay slot in the original, ours fills the slot (3 tries)
- func_001D9740: loop register allocation (original copies the element pointer); 3 tries

## t_1DA7B8

Matched 12: func_001DB560 func_001DB568 func_001DB570 func_001DB578 func_001DB9C0 func_001DBAC0 CFunc_BroadcastEvent CFunc_LaunchEvent CFunc_WaitForEvent CFunc_PrintEventLog func_001DC750 func_001DC760

## t_1DC968

Matched 12: func_001DC968 func_001DC978 func_001DCED0 func_001DCF30 func_001DD118 func_001DD5F8 func_001DD640 func_001DD960 func_001DE1B0 func_001DE2B0 func_001DE7A0 func_001DE8E8

Given up:
- func_001DCC38, func_001DCCB0, func_001DCE20: matched in session 4 (new asm_filter)
- func_001DD658: arg setup order (move a0,v0 after a2/a3); 5 tries incl. member call via asm label
- func_001DD148: 128-bit store built with pextlw/pcpyld from float constants; not attempted

## t_1DE968

Matched 6: func_001DE9A8 func_001DE9B0 func_001DE9B8 func_001DE9C0 func_001DF6E8 func_001E0428

Given up:
- func_001E07C0: original reloads unk98 for the second inline null-checked getter; ours CSEs it (4 tries)
- func_001DE968, func_001E0760, func_001DF890: split tail merged with the next function (alabel); cannot be written in C

## t_1E0AE8

Matched 15: func_001E0BC0 func_001E0EE0 func_001E0F00 func_001E0F08 func_001E0F18 func_001E0F38 func_001E0F48 func_001E0F78 func_001E0F98 func_001E0FA0 func_001E0FA8 func_001E12A8 func_001E12E8 func_001E1A28 func_001E1F88

Given up:
- func_001E0B60: original keeps if/else branch form for the null-checked getter and reloads unk98; ours presets 0 and CSEs (5 tries incl. volatile)
- func_001E1650: branch layout (bnezl) and and-operand order; 3 tries
- func_001E1068: v0/v1 swapped between vtable and list head; 3 tries
- func_001E19F0, func_001E0F50, func_001E1C90, func_001E0BB0: split tails

## t_1E2B90

Matched 9: func_001E2D18 func_001E2E40 func_001E2FF0 func_001E3280 func_001E32C8 func_001E32D0 func_001E32D8 func_001E3310 func_001E3380

Given up:
- func_001E3048: matched in session 4 (new asm_filter)
- func_001E2E90: register choice for the null-checked owner (a0/v1 vs ours v1/a1); 3 tries
- func_001E3220: outgoing arg move order (a2 from call result last); 5 tries incl. variadic and member-call

## t_1E4E10

Matched 10: func_001E5C50 func_001E5E90 func_001E5F38 func_001E5F58 func_001E5FD0 func_001E65A8 func_001E65B0 func_001E65B8 func_001E6920 func_001E6950

Given up:
- session 4 (new asm_filter): matched the 6 inc/dec func_001E64A0..func_001E6590 and func_001E64E8 func_001E6510 func_001E6538
- func_001E65C0 func_001E6668 func_001E6710 func_001E67B8 func_001E6830: the original builds the array address with an
  unsplit `la` (lui+addiu adjacent, same register); ours splits %hi/%lo and schedules them apart (toolchain)
- func_001E5ED0: split tail

## t_1E75A8

Matched 27: func_001E7948 func_001E7978 func_001E79F0 func_001E7A58 func_001E7AE0 func_001E7EC0 func_001E7EC8 func_001E8068 func_001E88F8 func_001E89F8 func_001E8A40 func_001E8A88 func_001E8C80 func_001E8C88 func_001E8C90 func_001E8C98 func_001E8CA0 func_001E8E20 func_001E8EB0 func_001E9008 func_001E9360 func_001E94F8 func_001E9500 func_001E9508 CFunc_SetProgressionDifficulty CFunc_GetProgressionDifficulty CFunc_SetProgressionMaxDifficulty

Given up:
- func_001E7AE8: matched in session 4 (new asm_filter; `s32 h = D_00368A38` read before the vtable store)
- func_001E8FA0: v0/v1 swapped between the global and the checksum local; 3 tries
- func_001E7998: v0/v1 choice for the vtable address; 1 try
- func_001E7EA8, func_001E8FF0, func_001E8E40: split tails

## Session 3

Hash table inlines (verified by match in t_1E95C0): table `{s32 bits; HNode* buckets; s32 count; s32 iterIdx;
HNode* iterNode; u8; u8 unk15}`, node `{u32 key; void* val; HNode* next}` (12 bytes, `mult` by 12). `Get(const u32&)`
(key spilled to the stack), `Start()` (iterIdx=-1, iterNode=0) and `GetNext()`; the exact forms are in t_1E95C0
(`Next()` with a separate `Scan(size)` for-ever loop, `GetNext` with one result variable `r`).
Base constructors take the derived constructor's arguments through (`func(p, a)`): declaring them so fixes the
prologue order (`sd s1` before `move s0,a0`) and the v0/v1 choice of the vtable store.

## t_1E95C0

Matched 26: func_001E9858 func_001E9998 func_001E9C08 func_001E9CB0 func_001E9D98 func_001E9DA8 func_001E9E48 func_001E9E58 func_001EA190 func_001EA1D0 func_001EA1E0 func_001EA208 func_001EA218 func_001EA430 func_001EA4A0 func_001EA510 func_001EA600 func_001EA6B0 func_001EA6C0 func_001EA6E8 func_001EA6F0 func_001EA988 func_001EA990 func_001EAF58 func_001EAF68 func_001EB1C0

Given up:
- func_001E99A0: D_00368A38 macro load scheduled before the vtable store in the original, ours in the jal delay slot (3 tries)
- func_001EA578: `if (a && f()) k = 0;` becomes movn in ours, branch-likely in the original (3 tries)
- func_001EB218: `!bool_call()` is xori+beqz in the original, ours folds the branch or hoists li 1 (4 tries)
- func_001EA830: arg setup order of the second func_0027CC30 call (li a2 first in ours); 7 tries
- func_001EAA68, func_001EABC0: `for (Start(), v = GetNext(); ...)`: in the folded first GetNext the loop's false block lands before the loop in ours, after it in the original (6 tries)
- func_001EB338, func_001EB2B0, func_001EA060: short loops padded with nops
- session 4 (new asm_filter): matched func_001E97C8 func_001EA798 func_001E9A00 func_001EA118 func_001EA318; func_001EB378 not retried
- func_001E99A0: new-with-vtable schedule (D_00368A38 load placed after the vtable store in the original); 3 tries
- func_001E95C0, func_001EB170, func_001EB2F0, func_001EA9D8, func_001E9980, func_001EA970: split tails / data

## t_1EB630 (`// cflags: -funroll-loops`)

Matched 9: func_001EBAB0 func_001EBAE8 func_001EBC80 func_001EBCB0 func_001EBFF0 func_001EC018 func_001ECC40 func_001ECC70 func_001ECD18

Given up:
- func_001ECC90: constructor; with the volatile first vtable store only v0/v1 differ (original moves the return value into v0 early); 5 tries
- func_001EC818, func_001EC8D0: list iterators on the stack with ldl/ldr struct copies; not attempted
- func_001EBFE0: split tail

## t_1ED6D0

Matched 20: func_001ED6D0 func_001ED858 func_001ED880 func_001ED888 func_001ED9F8 func_001EDA20 func_001EDB00 func_001EE428 func_001EE5A8 func_001EE6F8 func_001EEFE0 func_001EF2F0 func_001EF338 func_001EF368 func_001EF548 func_001EF570 func_001EF590 func_001EF5F0 func_001EF618 func_001EF688

Notes: 128-bit vectors returned in $v0 / passed in $a2 are `typedef int TI128 __attribute__((mode(TI)))` (a 16-byte
struct is returned through a hidden pointer); a union {TI128; Vec} gives the `sq` then `swc1` of one lane.
func_001ED888 is a pointer-to-member call (`(p->*a->pmf)(x, y)`, else virtual 12): both must return a value.

Given up:
- func_001EEC68: matched in session 4 (new asm_filter)
- func_001EDA50: vector constant built with pextlw/pcpyld; func_001ED720: static init with ldl/ldr copies; not attempted
- func_001EF3A8, func_001EF000: lq/pcpyud lane extraction, long; not attempted
- func_001ED938, func_001EEFB0, func_001EE600: split tails

## Session 4

Habits: stack slots of address-taken scalars do not follow declaration order; when the order is wrong an array
(`s32 s[3]`) fixes it, and in other functions plain scalars do (try both). A callee that returns a value which is
ignored still changes `$v0`/`$v1` choice later (declare it returning int). A member loaded and narrowed
(`u8 d = p->x` giving `lbu`) where the original does `lw` + `sb`: pass it through an inline function's int parameter.
`for (i < arr->GetSize())` (inline getter) reloads the pointer at the loop top where a plain `arr->count` is CSE'd.
128-bit vectors passed by value or copied: `TI128` (a 16-byte aligned struct is passed by reference).

## t_1EF6D0

Matched 13 (session 4): func_001EFA78 func_001EF9A0 func_001EFF40 func_001EFC60 func_001F0118 func_001F0438 func_001F0A30 func_001F0360 func_001EFB58 func_001EF898 func_001F0EF8 func_001EFD98 func_001F0FC8 (plus 20 earlier)

Given up:
- func_001F08D8, func_001F07E8: `if (!bool_call())` is xori+beqz in the original, ours bnezl (5 forms)
- func_001F16C0: s0/s1 swapped between `this` and a field loaded before a call (3 tries)
- func_001EF950: TI128 lane extraction (dsrl32/pcpyud + mtc1) into float args; union/struct forms go through the stack
- func_001EF7E0, func_001F01D0, func_001F0B70: 128-bit constant built with pextlw/pcpyld; not reproduced
- func_001F0B48: split tail

## t_1F1750 (`// cflags: -funroll-loops`)

Matched 35: func_001F1750 func_001F1780 func_001F17B8 func_001F17E0 func_001F1800 func_001F1840 func_001F1878 func_001F18B8 func_001F18D8 func_001F1A20 func_001F1AA8 func_001F1B50 func_001F1BB8 func_001F1C48 func_001F1D08 func_001F1D30 func_001F1D60 func_001F1D68 func_001F1E10 func_001F1F20 func_001F1F70 func_001F2108 func_001F2128 func_001F2360 func_001F2368 func_001F23E8 func_001F2440 func_001F3220 func_001F3240 func_001F32C8 func_001F3478 func_001F3560 func_001F36A0 func_001F36D0 func_001F3720 (+ empty func_001F1CE8..1D00 given real parameters)

Notes: vptr goes after ALL data members of a struct; fields after the vptr need a derived struct (`struct D : B`).
Bit tests on a u64 bitfield word (`dsll/dsra32/andi 1`) come from inline `bool B1() { return b1; }` getters.
`x & ~1 & ~2` kept unfolded = two inline `Clear(m)` calls. A 2-case switch gave the compare order of the original
where if/else chains did not. A 4-byte u8 struct passed as `const T&` from a copy (`T d = c; f(d);`) gives the
double lwl/lwr copy.

Given up:
- func_001F2000: fully unrolled sum; first `sum += f()` is mov.s in the original, add.s in ours (5 forms)
- func_001F34A0: block order of the timer branch (the `-=` block placed last in the original); 6 tries
- func_001F3268: store order of the constructor fields (li 1 first in the original); 7 orders tried
- func_001F32F0: xori+beqz `!bool` pattern (func_001F35D0 matched later with the volatile vtable store)
- func_001F1F18, func_001F2460, func_001F23D8: split tails

## t_1F3840

Matched 25: func_001F3F90 func_001F3C70 func_001F3DC0 func_001F3EF0 func_001F4780 func_001F3F68 func_001F3920 func_001F41D8 func_001F4718 func_001F56E8 func_001F4748 func_001F4208 func_001F4AF8 func_001F4B90 func_001F3F18 func_001F4B38 func_001F3C08 func_001F57B8 func_001F4168 func_001F3F98 func_001F5718 func_001F4880 func_001F4248 func_001F47A8 func_001F4070

Vector inline asm (verified by match, see the top of t_1F3840.cpp): a 128-bit vector built with
`pextlw lo,y,x; pextlw hi,w,z; pcpyld lo,hi,lo` is three asm statements in an inline `MakeVec(x,y,z,w)` (outputs
"=r", pcpyld tied with "0"(lo)); lanes read from a TI128 are `asm("mtc1 %1,%0" : "=f")` (x),
`asm("dsrl32 %0,%1,0" : "=r"(f) : "0"(q))` (y), `asm("pcpyud %0,%1,%1" ...)` (z). A first (dead) vtable store
that our gcc deletes: write it through `*(char* volatile*)`. `s32 GetInt(s, key, type) { s32 r; if (f(s,key,type,&r))
return r; ...; return 0; }` inline helpers give the precomputed-member-address schedules.

Given up:
- func_001F56A8: MakeVec register choice (const in v1 and result in v0 in the original); hi-first variant too
- func_001F3C88: 5-case switch tree has an extra `key < 0xB9832749` test and a copy of the key (4 tries)
- func_001F3DE0, func_001F3950, func_001F4DE0, func_001F4948, func_001F5510, func_001F5590: VU0 macro code
- func_001F3E68 (ldl/sdl struct copies), func_001F5820, func_001F3A40 (list iteration with stack iterators): not attempted
- func_001F4048: split tail

Session 4 retries with the new asm_filter (SN one-pass assembler model) are noted in each file's section above.
More habits: stack slots of address-taken locals follow the order in which their ADDRESS is first used
(`TI128 v; TI128* pv = &v; *pv = MakeVec(..)` puts v first). A struct built with an inline constructor that calls
out (`T t(x)`) recomputes `&t` (addiu sp) at each use where a plain local keeps it in a saved register.
Destructors with a delete flag: `if (flags & 1) func_00119400(D_00368A38, this)`; read D_00368A38 into a local before
the vtable store when the original loads it early.

## t_1F5958

Matched 17: func_001F5DC8 func_001F5E80 func_001F78A8 func_001F5DA0 func_001F5ED8 func_001F62A0 func_001F6268 func_001F77E8 func_001F5FE0 func_001F5D28 func_001F64B0 func_001F5F08 func_001F7828 func_001F5DD0 func_001F6F68 func_001F6778 func_001F78D0

Given up:
- func_001F5F88: constructor with dead u8[4] stores; register choice / sb order (10 tries)
- func_001F6440: three saved registers in the original (this not reused for the loaded count); 3 tries
- func_001F6528, func_001F6ED8: lanes of one TI128 read as three float args (dsrl32/pcpyud into separate regs)
- func_001F5C30 (ldl/sdl copies), func_001F62D0, func_001F5958, func_001F65B0: not attempted; F6DA0, F5AC8: VU0
- func_001F5CF8, func_001F5EA0, func_001F5AC0: split tails

## t_1F79D8

Matched 15: func_001F79E0 func_001F7A88 func_001F7AC8 func_001F7C28 func_001F7D28 func_001F7E28 func_001F8C08 func_001F8D40 func_001F97C0 func_001F9810 func_001F79E8 func_001F9028 func_001F9740 func_001F9860 func_001F8D90

Notes: func_001F8D90 is an inline sorted-list Find (`E* c = &node->e; if (c->key == key) return c; if (key < c->key) return 0;`).

Given up:
- func_001F9920, func_001F8C28: list Find via func_0012CEE8 plus an inline first-element getter; frame size and
  register allocation differ (1 try each, worth another look)
- func_001F7B10, func_001F7C70, func_001F7D70, func_001F7E70, func_001F8A88: VU0; func_001F7AB0, func_001F86D0: split tails

## t_1F9A48

Matched 10 (session 4, small ones only): func_001F9EC0 func_001FAEE0 func_001FAC18 func_001FAC38 func_001FAC60 func_001FADB8 func_001FADE8 func_001FAE10 func_001FAE30 func_001FAEC0

Given up:
- func_001F9E80: inline first-element getter with one stack iterator reused for the sub-list; branch polarity and
  registers (4 tries)
- func_001F9A48, func_001F9D68, func_001FA330: split tails
Not yet attempted: everything above 0x40 in this file; t_1FBAF0 .. t_249620 untouched.

## Session 5

Habit (verified by match): a `nop` right before a label inside straight-line code, with a repeated body, is a fully
unrolled loop (`-funroll-loops`): t_1FBAF0 func_001FC1E0 (`for i<3: if (!a[i]) return i+1;`) and func_001FBDE0.
Table scans unrolled x5 (`slt` on the pointer, 5 copies of the body) are `for (int i = 0; i < 50; i++) { E* e = &D[i]; ...}`
(an index loop, not a pointer loop). `&p->field` computed before the null check (`addiu a1` in the beqz delay slot)
is an inline helper taking `void** pp`.

## t_1FBAF0 (`// cflags: -funroll-loops`)

Matched 11: func_001FBB18 func_001FBB70 func_001FBC50 func_001FBDE0 func_001FBF10 func_001FC030 func_001FC1E0 func_001FCB08 func_001FD9B8 func_001FDA30 func_001FDA88

Given up:
- func_001FBEA8, func_001FBE50: `move v1,v0; bnez v1` + `li v0,1 / v0 = 0` bool return; every form gives sltu (3 tries)
- func_001FC608, func_001FC690: arg order (original loads a0 from the stack before `move a2,s1`; `sw 0` after the key ori); 4 tries
- func_001FC0A8: original saves $s0-$s7/$ra with `sq` (no -fopt-stack layout; it reads a stack argument); not reproducible from source
- func_001FC468: same arg-order schedule as FC608 plus a mid-function `return 0` block; 3 tries
- func_001FCA90: constructor with dead u8[4] stores; li s1,-1 / vtable store schedule (4 tries)
- func_001FBD68, func_001FCA38, func_001FBFC8: split tails

## t_1FDB00

Matched 6: func_001FDE48 func_001FEC48 func_001FECB8 func_001FED90 func_001FEDE8 func_001FEE90

Given up:
- func_001FDB08: only diff is `b; nop` where ours puts the last `cvt.s.w` (u32->float) in the `b` delay slot (2 tries)
- func_001FED08: MakeVec(0,0,0,1) register choice (zero in a2, hi in v1 in the original); 2 tries
- func_001FDDC0: constructor with dead u8[4] stores and u64 bit clears; not attempted
- func_001FEB48, func_001FDC60: VU0; func_001FEB08: split tail

## t_2001E0

Matched 27 (session 5): func_002005E8 func_00201A40 func_00201A70 func_00200AD8 func_00200F58 func_002019E8 func_00200C58
func_00200E10 func_00200DB8 func_00200E68 func_002004C0 func_00201C80 func_00201980 func_00200CA8 func_00201BF8
func_00200D28 func_00201008 func_00200428 func_00201460 func_002018E0 func_00200520 func_00201B50 func_00201AA0
func_002012B0 func_00201500 func_00201CF0 func_00201730

Notes (verified by match): long runs of stores (func_00201AA0): the scheduler emits the LAST store of each kind
(sw / sq / swc1) first, in source order of those, then the rest in source order; so put the store that must come
first at the end of its kind's group. `&p->m[1][i]` with an inline `f32& operator[](int)` on a row struct gives the
`(p+row) + i*4` address order. A value read right after a call into a saved reg in the branch delay slot:
`ok = f(.., &a, ..); id = a; if (ok)`. A 4-case switch whose cases each end in the same `if (!x) kill(q)` is
cross-jumped into one tail (func_00200520). `delete (T*)p` with a virtual dtor (vptr at 0x104) gives the dtor(3) call.
Toolchain (for the integrator): the original never has `div.s` or `cvt.*` in a branch/jal delay slot (0 of either
in the whole game, vs 315 mul.s); ours fills slots with them (func_002009B0, t_1FDB00 func_001FDB08).

Given up:
- func_002009B0: div.s/cvt.s.w placed in delay slots by ours only (toolchain, see above)
- func_00200380: constructor; prologue (`move s0,a0` in the jal delay slot) and member addresses s1/s2 hoisted (2 tries)
- func_00202158: 64-byte struct copies (lq/sq through a computed dst pointer; stack copy order); 2 tries
- func_002001E8: static init with ldl/sdl copies; func_00201130 func_002011C0 func_002015F8: VU0
- func_002001E0, func_00200A70: split tails

## t_202258 (`// cflags: -funroll-loops`, needed by func_00203A18)

Matched 8: func_00202D50 func_00204248 func_00203448 func_002028D8 func_00202828 func_00203A18 func_00202C88 func_00203208

Notes: a 64-byte copy done as `lq 0xA0(v1); addiu a1,v1,0xA0; addiu a2,v1,0x100; sq ...; lq 0x10(a1); sq 0x10(a2)` is an
inline `M& operator=(const M&)` copying the four u128 rows (a plain struct assignment folds every offset).
Toolchain (for the integrator): the original has `nop; nop` before a `div.s` that starts a branch target
(func_002034A8, func_00202D90); our build does not insert them.

Given up:
- func_002034A8, func_00202D90: `nop; nop; div.s` at a branch target (toolchain)
- func_00203058: &t kept in a saved register and stack slot order v/t/f (frame 0x60); 4 tries
- func_00203858: long float logic; not attempted. VU0: func_00202258 func_00202400 func_00202960 func_00203138 func_00203318 func_00203AD8 func_00202ED0
- func_00203440: split tail

## t_204298

Matched 9: func_00205680 func_002059E8 func_00205B00 func_00205E58 func_00205700 func_00204A78 func_00205EA0 func_00204498 func_00205A50

Given up:
- func_00205748: constructor; with `void* vt = D; p->unk4 = K; p->unk18 = vt;` only the two stores swap (48 orders tried)
- func_00205F00: task init; v0/v1 for the vtable vs the 0xFF byte constant (inline init helper fixed the rest); 9 tries
- func_00205F98 (list walk), func_002044F8, func_002057F8: not attempted; func_002060A0: static init (ldl/sdl)
- func_00206220/func_00206238: alabel split; VU0: func_002042A0 func_00204688 func_00205B48 func_00205C60 func_00205DF0

## Session 5 retries (new asm_filter: short-loop nops, one-pass `la`)

- t_1ABAA0: func_001ACF98 MATCH (short loop; `else if (head) {walk} else head = n` order)
- t_1BF628: func_001BFDD8 MATCH (tail `x = c->next; n->next = x; if (x) x->prev = n;`), func_001BF9C8 MATCH
  (`la` of D_00372D58 needs `extern u8 D_00372D58[] __attribute__((section(".sdata")))` so gcc emits the macro)
- t_1B00D0 (now `// cflags: -funroll-loops`): func_001B1D60 MATCH (callees take no args: a0 not preserved),
  func_001B00D0 func_001B01D8 func_001B02F0 MATCH (record walk unrolled x4; `E* e = (E*)q[0] + j;`).
  func_001B1AB8 still DIFFERS: which of count/table pointer gets the copy (`move t2,a3`); 10 forms tried.
- t_1E4E10: func_001E65C0 func_001E6668 func_001E6710 func_001E67B8 func_001E6830 MATCH (arrays declared
  `__attribute__((section(".sdata")))` so gcc emits `la`; the matched readers of the same arrays still match)
- t_1E95C0: func_001EB2B0 (`c = n; do c = c->next; while (c);`), func_001EB338, func_001EA060, func_001EB218
  (`bool missing = !f(); if (missing)` + `if (!prev) head = next; else prev->next = next;`) MATCH
- t_1EF6D0: func_001F07E8 func_001F08D8 MATCH (`bool missing = !f(...); if (missing)`)
- t_1F1750: func_001F32F0 MATCH. Habit: a checksum `switch` compares cases in VALUE order of the switch type:
  switch on `(u32)k` when the smaller-unsigned key is compared first; case bodies follow source order.
- t_1B2168: func_001B2168 (cvt.w.s now assembles; index as `*(u8*)(i + p + 0x10)`), func_001B3BA8, func_001B3C98 MATCH.
  func_001B21A0 still: the original never puts cvt.*/div.s in a delay slot (toolchain).
- t_1C7AA0 func_001C95D8 and t_1F3840 func_001F3C88 retried (u32 key, case orders): still DIFFERS.
- t_1C5A68 (now `// cflags: -funroll-loops`): func_001C67C0 MATCH (`KV e[n][32]` at 0xF4, loop unrolled x8).
  func_001C6868 (clear loop x16) still DIFFERS: original stores a register holding 0 and loops forward, ours
  reverses the loop and stores $0 (5 forms).

## t_2062E8

Matched 13: func_00207798 func_00207DD8 func_00207B78 func_00206728 func_00207090 func_00207D70 func_002081A8
func_00206D80 func_00208038 func_00207BD8 func_00206FF8 func_002070F8 func_002077E0

Notes (verified): constructors: declare the base constructor (func_001D0F68) as returning `void*` (it returns
this). That alone freed $v0 and fixed the register choice for the vtable/id stores (func_00208038), the problem
behind several older constructor give-ups. Dead u8[4] colour locals are an inline ctor `C(u8 r, u8 g, u8 b, u8 a)`.
`delete p` (virtual dtor at vptr+8) null-checks for you: `if (x) {...; delete x; x = 0;}` gives the double load.
Two identical MakeVec hi halves are CSE'd (non-volatile asm), as in the original (func_00206FF8).
- t_204298: func_00205748 func_00205F00 MATCH (base ctors func_001D0F68 / func_00113EA8 return `void*`; inline
  colour ctor; inline task init taking the callback as a parameter).
- t_1FBAF0 func_001FCA90 and t_2001E0 func_00200380 retried with the base-ctor fix: closer, still DIFFERS
  (FCA90: `li s1,-1` scheduled early; 200380: s1/s2 = member addresses computed after the first member ctor).

## t_208310

Matched 7: func_00208388 func_002083F8 func_002084F0 func_002085F0 func_00208448 func_00208640 func_002086D0

Given up:
- func_00208FA8: `sw` of the first call result lands before the arg setup in ours, in the jal delay slot in the original (4 tries)
- func_00208538: vector + 64-byte copies through a stack temp; load order/registers of the u128 vs the first row (4 tries)
- func_00208778, func_00208C50, func_00208DE0: not attempted

## t_20AD10

Matched 8: func_0020C220 func_0020CD08 func_0020C268 func_0020C540 func_0020B920 func_0020AE18 func_0020AEC8 func_0020AD50

Notes: func_0020C268 confirms the store-order rule (17 stores: the last one in source is emitted first). A key read
once into a saved register after the call that fills it: `u32 kk; f(.., &kk, ..); u32 k = kk;`.
Toolchain: `nop; nop` before `div.s` also outside branch targets (func_0020AD10: `add.s $f0` then `div.s .., $f0`),
probably an SN assembler hazard rule for div.s; ours emits none.

Given up:
- func_0020AD10: nops before div.s (toolchain)
- func_0020C460: wrap-angle loops, FP register choice (4 forms)
- func_0020C5D8: the w-lane store goes through a separate `addiu v1,s2,48` base; everything else matches (4 forms)

## t_20EE10 (`// cflags: -funroll-loops`, needed by the 3-entry slot scans)

Matched 9: func_002103C8 func_0020F400 func_00210558 func_0020F158 func_00210870 func_002102F8 func_0020EFA8
func_0020F0C0 func_00210678 (+ prototype of func_00210558 now returns int)

Notes: unrolled 3-slot scan `for (i < 3) { E* e = &arr[i]; if (!e->unk0) { e->vcall(x, y); return 1; } }` keeps a1/a2
untouched: pass the caller's extra args through (register choice a3 for e). Fields loaded before a compare in the
original: read them into locals first (func_0020F0C0, order b then a).

Given up:
- func_00210968: our gcse hoists the 0x0203B372 / 1 constants into saved regs across the calls; the original
  rematerialises them (bool via branches); 4 forms
- func_0020EF70, func_0020F040: `nop; nop` before div.s (toolchain); func_00210A18: 4 inline sub-object inits, not tried
- func_0020EEF0: stack iterators; not attempted

## Session 6 (t_211050 .. t_249620, small functions first)

Matched 153 in session 6 (t_2131A8 .. t_249620): getters/setters, pass-through wrappers, constructors with a base ctor
returning `void*`, list-head inits, TI128 copies, ctor/dtor pairs. 0x4 candidates (split tails) skipped.

Habits (verified by match):
- A wrapper that keeps `a0` untouched passes it through: `void f(void* p) { g(p); return p; }` is
  `sd s0; move s0,a0; jal g; move v0,s0`. A callee whose asm has no `a0` setup but uses it takes the caller's args.
- `return cond ? ..` early-return form: `if (!t) return 0; ...; return f() != 0;` gives the `b L; sltu` tail shape.
- Returning a virtual call's int result (`return v->fn(...)`) is what puts the fn pointer in `$v0` (func_0022BE20).
- Global read with `lui $a0; lw $a0,%lo($a0)` (macro form): declare it as `extern T D[] __attribute__((section(".sdata")))`
  with a struct T larger than 8 bytes and use `D->field`; plain `int` arrays still go `$gp` (t_223BE8 D_0036F520).
- `&D` as `addiu a0,$gp,%gp_rel(D)`: declare `extern u8 D;` (scalar), not an array (func_0022C4F0).
- Same symbol called with 1 arg elsewhere and with 3 in its own definition: second declaration with
  `__asm__("name")` under a new C name (t_243208 func_00244930_1).
- `u32* d; d[1] = (u32)(d + 1)` style: take the base pointer once (`int* d = (int*)&D; int* n = d + 1;`) so the
  `addiu` stays separate (func_002367E0, func_00246C50).
- Store order: with N stores of mixed kinds the emitted order is a permutation of the source order (first
  emitted = the last source store of the kind); solve by trying `src = [..]` permutations, see func_00248CF8.
- 0xFFFFFFFF written to a u32 field gives `lui/ori`, `-1` gives `li`.

Given up:
- func_00223360: `lui` hoisted above `move a1,a0` (2 tries); func_0022F3A0: `sw` before the macro `lw` in ours, in the jal delay slot in the original
- func_0023F700 func_0023F738 func_00241040 func_00241078: table getter, original keeps the owner in v1 (ours reuses a0, branch-likely li); 6 forms
- func_00230578: schedule of the 5-term expression with gp globals; func_002490E0: `o` in a1 vs a0 for a virtual call
- func_00243478: `swc1 $f0` of an uninitialised register; func_0022BBA0 func_002219D8: split tails; func_00248E20 MakeVec constant; func_00231A38: 8 register args
- func_00223B98 (MakeVec 0,0,0,1 + call), func_002141A8 (short-circuit with stack int): not attempted
- func_00248D50: ctor; `addiu v1,s0,0xC0` temp (ours v0) with the zero stores, 4 forms
- func_0022B168, func_002490E0: `o` of `fn(o + delta, o)` lives in a1 in the original (ours a2/a0); inline helper and `&&` forms tried
- func_0022C498: the `D_0036F748` load sits in the first bne delay slot in the original, ours schedules it above the address build
- func_00233B70: original keeps a `nop` before the final jr (list-head init like func_002367E0 which matches)
- Next untouched candidates: t_2171C8 func_00217278 onward (same `func_0027D058`/`unk20` setter family), t_21BA08, t_21DA40, t_227C68, t_2320A0 larger ones

## Session 7 (t_2171C8 onward)

### t_2171C8
Matched 11: func_00217278 func_002172D0 func_00217328 func_00217530 func_00217380 func_00217588 func_00217410 func_002174A0 func_00218088 func_00218120
(dtor: `delete (D*)x` then inline Release on a local `void** r`, then Release on `&p[7]` directly; ctor: member node init `q = p+7; q[1]=0; q[2]=0` before the key store).

### t_219920
Matched: func_00219CE0 func_0021B880 func_0021A490 func_0021AFD8 func_0021A100 func_0021A338 func_0021B290
Habit: a CFG with a shared tail block needs the m2c `goto` form (func_0021B290); a callee used with 1 arg elsewhere and 2 here: `__asm__("name")` alias.
Given up: func_0021A298, func_0021A698: virtual call `o->fn(o, ...)` keeps `o` in $a1 in the original, ours in $a0 (explicit entry, member virtual, inline helper tried).
func_0021B058: TI128 lane extraction; func_0021B8E8: unrolled + MakeVec; not attempted.

### t_21BA08
Matched: func_0021CDB0 func_0021C250 func_0021C318

### t_21DA40
Matched 12: func_0021DDB8 func_0021EFC8 func_0021E140 func_0021E658 func_0021E6E8 func_0021E0C8 func_0021F248 func_0021EB20 func_0021ED28 func_0021EF30 func_0021DBA0 func_0021E300
Given up: func_0021E848 (the key `ori` lands in the jal delay slot in the original, ours earlier); func_0021DFB0 (dead u8[4] colour stores interleaved with the sw group, constants li v1/a0 swapped; 6 tries); func_0021E038 (list-walk dtor: `h` in a0 / `e` in v1 in the original, ours swapped; the `asm("" : "+r"(end))` copy trick works, see below).
Pointer-to-member trampolines (`if (a->pm) return (p->*a->pm)(x, y); return p->v12(a->unk0);`, struct V with 11 dummy virtuals then `virtual s32 v12(int)`) match; the variant with `a->unk0` as first arg also needs the unused x,y parameters so a2/a3 stay live (func_0021A198).

### t_219920 (continued)
Matched also func_0021A198 (see above).

### t_221BC8 (now `// cflags: -funroll-loops`, needed by func_00223050)
Matched 8: func_002223B8 func_00222E60 func_002227F0 func_00222920 func_00223050 func_00223388 func_00221DF0 func_002226F8
func_00223050 clear loop: `int* q = p->unk4; int i = 0x3B; do { *q++ = 0; } while (--i != -1);`. func_00223388: strcpy callee declared returning int (ignored result changes v0/v1).
Given up: func_00222FD0 (binary search; the original keeps a second copy of the key in t5, ours does not); func_00222978 (float arg loads f13 before f12 in the original delay slots); func_002230D8 (saved register order i/p/q); func_00222A68 (min via pointer select; not attempted).

### t_223BE8
Matched 3: func_00225058 func_002244B0 func_002243A0 (empty counted loop `i = 0x3E7; do i -= 0x19; while (i != -1)` keeps its nops).
Given up: func_00224F78 (the original recomputes `key & 0xFF` after the call, ours CSEs it; 3 forms).

### t_225BF0
Matched 6: func_00226918 func_00227048 func_00227268 CFunc_CreateNodeFlag CFunc_ChangeNodeFlag func_00226030
Habit (verified): a loop bound that the original copies into a new register (`move s1,v1` before the loop) is `char* end = e; asm("" : "+r"(end));` inside the `if`, then compare with `end` (func_00226030).
`D_0036D3B0` macro form: `extern void* D_0036D3B0[] __attribute__((section(".sdata")))` and `D_0036D3B0[0]`.

### t_227C68
Matched 9: func_00227CC8 func_00227EA8 func_00228050 func_00229718 func_002280A8 func_00228368 func_00227E00 func_00227FA8 func_00227D20
Habit: `func_f(s, obj); obj = s;` (reassign after the call) puts the `move` in the jal delay slot; a switch whose cases `break` and a trailing `return r` reproduces a shared `move v0,s1` tail; byte stores `p[0x2C] = 1; p[0x2D] = 1;` are emitted in swapped order of source.
Given up: func_002297D0 (alabel entry in the middle), func_00228278 (MakeVec stack vectors, not attempted).

### t_229D30
Matched 10: func_0022A2D8 func_0022AE18 func_0022AFC0 func_0022BA90 func_0022B688 func_0022B9D0 func_0022B040 func_0022B5D0 func_0022B918 func_0022BCE0
Notes: a callee that takes the caller's untouched a1 (`func_0022C768(a, b, x)` called with b = incoming a1) needs the extra parameter declared; keep the existing prototype of an already declared function (void* self + local cast) or the file stops compiling.
Hash-bucket free loops (`do { nx = c->next; free(0, c); c = nx; } while (c)`): load the next pointer BEFORE the call (it lands in the delay slot).
Given up: func_0022B0D0 (p/o saved registers swapped: o in s0 ours, s1 original), func_00229EB8 (record shift: v0/v1 of the three loaded words and slt position; 6 forms), func_0022A8F8 (ext lookup: the found-return is a branch-likely `lw v0,4(s1)` shared epilogue), func_0022B168 (`move v1,v0; bnez v1; li v0,1` bool tail), func_0022A800 and func_0022BAF8 (D_00368A38 macro form while the rest of the file uses gp).

### t_22BD90
Matched 11: func_0022BD90 func_0022D538 func_0022DD30 func_0022D940 func_0022D048 func_0022BE60 func_0022BEE0 func_0022D0C0 func_0022DA28 func_0022DAF0 func_0022D2C8
Virtual-call helper used here: `VE22B* e = (VE22B*)(*(char**)(p + 0x34) + off); ((int (*)(char*))e->fn)(p + e->delta)` (vptr at 0x34, entry = delta s16 + fn). A callee whose result is ignored but declared `int` fixes v0/v1 (func_0011E008, func_0030B550). Call with args taken straight from incoming registers: alias with `__asm__("name")` and the extra parameters.
Given up: func_0022CEF8 func_0022D240 func_0022D6A0 func_0022DBB0 (identical wrappers `if (c) v = vcall(); BCE0(p,v,b,c,d,e)`: b/c saved registers s1/s2 swapped in ours), func_0022D728 (r/f saved registers swapped).

### Register variables (verified): local register variables pin saved registers
`register int rb asm("$17") = b; register int rc asm("$18") = c;` (then use rb/rc) reproduces the original's saved-register
assignment of passed-through arguments when ours gets them in the other order. Fixed the eight-way family
`if (c) v = vcall(); BCE0(p, v, b, c, d, e)` (t_22BD90 CEF8/D240/D6A0/DBB0, t_22DD98 DEE8/E270/E5C0/E9E8/ECC8/F098/F650/FBB8) and func_0022E980.
It only works for parameters that are used directly (binding a computed value or p to another register changed the frame).

### t_22DD98
Matched 22: func_0022EB68 func_0022EF38 func_0022F2F8 func_0022F9A8 func_0022E428 func_0022E810 func_0022E020 func_0022ED50 func_0022F120
func_0022DEE8 func_0022E270 func_0022E5C0 func_0022E9E8 func_0022ECC8 func_0022F098 func_0022F650 func_0022FBB8 func_0022E980 func_0022E648 func_0022FB30 func_0022DF70 func_0022F588
Habits: `int w = f(...); vcall(p + delta, w);` (result first, then the vptr load) when the original loads the vtable after the call; `if (!c) return 0; ...; return g();` gave the original branch layout in func_0022DF70; a virtual call whose result is unused but typed int fixes v0/v1 (func_0022E648).
Given up: func_0022E510 func_0022EC18 (and likely func_0022E8C0 func_0022EFE0 func_0022DE28): stack buffer passed as `func(buf, a1)` has `move a1,s1` before `move a0,sp` in ours, the other way in the original (4 forms); func_0022E1D0 (`li a3,0` scheduled before a2, prologue order); func_0022EA70 func_0022F6D8 (ldl/sdl struct copies); func_0022F3A0 (macro lw after sw).

### t_22FD98 (now `// cflags: -funroll-loops`, needed by func_002303D0)
Matched 3: func_002303D0 func_00230148 func_00231478
Given up: func_002317B0 (touches the 0x10000800 hardware register), func_00230428 (slot allocator with 9 args).

### t_234190
Matched 4: CFunc_GetPakManNumFreeSlots CFunc_RefreshPakManSizes CFunc_GetPakManCurrent CFunc_GetPakManCurrentName
Habit: `for (i = 0; i < t->count; i++) f(...)` (count reloaded each iteration) matches where a hand-made do/while hoisted `t + 8`; fail-first layout is `if (r == 0) { fail; r = 0; } else { ok; r = 1; } return r;`.

### t_2320A0
Matched 2: CFunc_LinkRawAsset CFunc_UnlinkRawAsset (`(f() ^ 1) != 0` keeps the xori+bnezl).
Given up: CFunc_UnloadPak (three induction variables: pointer, offset, hoisted base in a2; ours merges them).

### t_2131A8 / t_2151A8 / t_23EFF8 / t_243208 / t_249620
Matched: t_2131A8 func_00213E10 func_00213650 func_002150A8 func_00215128 func_00213CF0 func_002143F8 func_00214350 func_00213908;
t_2151A8 func_00216D78 func_00216E18; t_23EFF8 func_00240FD8 func_0023F668 func_00240F78; t_243208 func_00243558 func_00243B08 func_00243A98 func_00243B70;
t_249620 func_00249FB8 func_0024A070 CFunc_CompositeObjectExists.
Habits (verified): `if ((f() ^ 1) != 0) return 1;` early return puts `li v0,1` in the bnez delay slot (func_00213908) and keeps xori+beqz in a CFunc (CFunc_CompositeObjectExists);
`if (flags & 1) return;` early return gives `andi; bnez` where `if (!(flags & 1)) {..}` gave xori+beqz (func_002143F8);
recursive tree walkers: if/else with one result variable gives the recursion-first layout, `register u8* c asm("$16")` + `register int a asm("$17")` pins the saved registers, `asm("" : "+r"(b))` stops gcc from folding `a + (b + 1)` into `(a + 1) + b` (func_00243A98), min of two as `b = f(); if (a < b) b = a;` (func_00243B70);
a second `if (*r)` after a first `if (*r) call()` is jump-threaded by gcc: read it as `int t = *(volatile int*)r;` (func_00215128); a field `u16` test needs `*(u16*)(p + 4) & 0x8000` (lhu).
Given up: func_00243678 (t-register assignment of the add chain, 3 forms), func_00245648 (loop compare reload lands in v1 not v0; 5 forms with register variables), func_00246D48 (remove-by-value: j must reuse the dead a1, count reload in t0; register variables got within the last v0/v1 pair of the inner loop), CFunc_GetUniqueCompositeObjectID (D_0036D3B0 macro form vs gp in the rest of the file), func_002435D8 and similar (D_00368A38 macro).

### Late additions (t_2131A8, t_21FB88)
Matched: t_2131A8 func_002136A8 (two `if (p) { if (f(p)) g(p); if (p) delete (D*)p; }` blocks, D with vptr after pad 0x18 and a virtual dtor in slot 2) func_00213AA0 (57.295776f constant, $f20 kept by gcc); t_21FB88 func_00220518 func_00220A80
(u64 bit tests: copy the u64 into a local struct `BF f = *(BF*)(q + 0x50);` with `u64 pad:1, b0:1, b1:1` and inline `bool B0()`; `f.B1() ^ 1` gives the `andi; xori`; two stores in an if/else keep the duplicated tail).
Given up: func_002140D8 (cvt.s.w in the b delay slot of ours; the original has `b; nop`, toolchain as before), func_00220FE8 (reverse unrolled scan: gcc folds the n-1 == -1 test into n == 0), func_002212B8 (list iterator on the stack), func_00214498 func_00213B80 func_002141F8 (long; not attempted), func_0021BA08 (unrolled x10 destructor loop; not attempted).

## Session 8 (worker B9, larger candidates)

Habits: load a macro-form global into a local FIRST (`char* g = D_X[0];` at the top) when the original has lui/lw before
the other loads (func_001CC330). Virtual call with `a1 = original a0` and nothing else: `((void(*)(char*,char*))e->fn)(o + e->delta, p)`
(struct VE {s16 delta; s16 pad; void* fn}); when the result is ignored and the callee before it is declared `int`, fn lands in v1.

### t_1CBB50
Matched 22: func_001CC9E8 func_001CCA20 func_001CCA58 func_001CCD50 func_001CCDC8 func_001CCD88 func_001CCA90 func_001CCB10 func_001CCB60 func_001CBF68 func_001CBFA8 func_001CC010 func_001CC298 func_001CD158 func_001CD198 func_001CBB50 func_001CBDE8 func_001CD108 func_001CD2C8 func_001CD318 func_001CC330 func_001CD058
Given up:
- func_001CC1A8, func_001CD1F8: start with junk from a split tail (sw/nop/addiu sp)
- func_001CC388: dead stack stores of a pointer and zero before the call; func_001CD470: D_00368A38 gp_rel here but macro in the rest of the file
- func_001CD5C0: unrolled x6 scan, layout differs without -funroll-loops (1 try)

### t_1ABAA0
Matched 16: func_001AD128 func_001AD090 func_001AD7B8 func_001AD048 func_001AD0C8 func_001ACEA8 func_001AD168 func_001AD230 func_001AD2B8 func_001AD360 func_001AD400 func_001AD4C8 func_001AD8F8 func_001AD9D0 func_001AD588 func_001ADA68
Habits: tree walkers `sum = 0; if (f(p)) {..sum = g..} else { c = p->head; if (c) do { sum += rec(c); c = c->next } while (c) } return sum;` (single result, zero cases fall into the same `move v0,s1`); if the original has the `f(p) != 0` block first, write it first. Relative-offset pointers `a + *a` are byte offsets (cast to char*). A byte parameter stored with `sb` directly is declared `s32`.
Given up: func_001AD7F8: 64-bit mask built with the `li; dsll; ori; dsll` macro chain (ours lui/ori/dsll32; bitfield form too); func_001ACE18/E50/E80/F58/F90: tails reading an unset $v1.

### t_1CE0A8
Matched 23: func_001CF940 func_001CED98 func_001CFA08 func_001CE1D0 func_001CEDE8 func_001CEE38 func_001CEE88 func_001CF898 func_001CF768 func_001CE7C0 func_001CE810 func_001CE6D0 func_001CF640 func_001CFD00 func_001CEAD0 func_001CED20 func_001CFE38 func_001CFDB0 func_001CF980 func_001CF6A8 func_001CFA70 func_001CF7D8 func_001CE8D0
Habits: a function that returns the constant 1 from several branches wants `return 1;` in each branch (early-return form), that puts `li v0,1` before the epilogue loads (func_001CFA70, func_001CF7D8); `if (m == 0) return 0; ...; return 1;` for the other shape (func_001CF980). Constructor store order: permute the source order of the stores (helper script: all permutations through fcheck), see func_001CE8D0. A callee used with different arg counts: `__asm__("name")` alias.
Given up: func_001CEFA8, func_001CEED8: junk prefix from a split tail; func_001CF000: ours beqzl, original plain beqz with the lw a0 inside (3 tries); func_001CFB18: callee-saved prologue order; func_001CE4C8/func_001CE5A0: original keeps `andi v1,a0,0xff` of the lbu and s8 sign tests (2 tries); func_001CE410, func_001CFEB8 not attempted.

### t_1D00B0
Matched 9: func_001D1F58 func_001D1DD8 func_001D1F08 func_001D0F90 func_001D0130 func_001D03D8 func_001D0228 func_001D02A0 func_001D0330
Habits: a float stack local passed by value to a float parameter is declared `f32 v = 0` (lwc1 f12); the 7th float argument of a call goes in f12 (`-1.0f`); `0xFFFFFFFF` argument needs a `u32` parameter (lui/ori, not li -1); a macro-form global read after a call and stored into the jal delay slot: read it into a local before the store (func_001D0228).
Given up: func_001D0548/F40/0518: split tails; func_001D1438/14C0: original loads the list head after the flag store and has a nop in the loop (4 tries); func_001D1910: g/t register allocation (a2/a3), 4 tries; func_001D1598: short loop with nops.

### t_1B00D0 (session 8)
Matched 6: func_001B1D18 func_001B0850 func_001B1428 func_001B1380 func_001B0898 func_001B1EB0
Given up: func_001B1DD8 (passes a1..a3 straight from the loaded values with `a1` reused as the sum; ours copies the parameter to v0, register variables pinning $5/$6/$7 tried, 7 forms); func_001B1968, func_001B1910: junk / vector.

### t_1CBB50 (more)
Matched 5: func_001CBBB0 func_001CBE48 func_001CBEA8 func_001CBF08 func_001CC1F8 (list-node dtors, same body as func_001CBB50).

### t_1C5A68 (session 8)
Matched 6: func_001C63B8 func_001C5C78 func_001C79E0 func_001C7A40 func_001C63F0 func_001C7668
Habit: a stack object whose address is used for a field store after a call: declare `L* q = (L*)((char*)&l + 4)` AFTER the call so gcc recomputes `addiu v1,sp,4` instead of keeping a saved register (func_001C7668).
Given up: func_001C74F8 (`f1() || f2()` returning 1/0: original uses bnez with li in the delay slot, ours bnezl/sltu or movz; 5 forms).

### t_1D2508 / t_1C1A30 (session 8)
t_1D2508 matched 4: func_001D4118 func_001D4158 func_001D29E8 (128-bit local `TI128 v` read by a callee and copied with lq/sq) func_001D3538.
t_1C1A30 matched 3: func_001C2550 func_001C25A0 (`register s32 v asm("$17") = v0; register char* p asm("$16")` pins the callee-saved order) func_001C3240 (callee takes a0/a1 straight from the incoming args: declare the parameters).
Given up: func_001C2508 (constructor: `li 0x44` before the lui in the original; all store orders tried).

### t_1BF628 / t_1BD608 / t_1C7AA0 (session 8)
t_1BF628 matched 3: func_001BF6A0 func_001BFF98 func_001BFFE8 (register-pinned setter, see func_001C25A0).
t_1BD608 matched 3: func_001BF408 func_001BD9C8 func_001BF2E8. t_1C7AA0 matched 2: func_001C7AC8 func_001C86C8.
t_1F9A48 (nothing matched this time): func_001FB450 (last compare becomes movz/xor, 3 forms), func_001FB390 (TI128 return; original copies a0 to v0), func_001FAD10 (D_00370AE0 load order), func_001FAD68 (branch-likely vs plain beqz).

### misc (session 8)
t_1C3A40 func_001C5680; t_241040 func_002415E0; t_1E0AE8 func_001E1AD0 func_001E0E10 (a callee used as `int` through a `__asm__` alias).
Given up (split tails whose first instructions are the end of the previous function): func_001D8898, func_001DD488, func_001C1A30's func_001C1A8-like prefix cases; func_00223590/func_00222F10/func_0021DED8 need pextlw/ldl-sdl.

### t_1C3A40 / t_1E0AE8 (more)
t_1C3A40 matched 4: func_001C4390 func_001C43F8 func_001C55A8 func_001C5610. t_1E0AE8 matched 3: func_001E0FF8 func_001E1308 (stack list iterators: `S1E0AE8_I it, end;` two {s32; Node*} locals, do/while on it.unk4 != end.unk4, as in the session 3 note) func_001E0E70.

### late session 8
t_1E0AE8 +func_001E0BC8 func_001E0C40 (ctor/dtor); t_1C9B30 func_001CA3E8 (stack struct `B1CA3` padded to 0x30 so the frame is 0x40); t_2361E8 func_00236760 func_002366E0 (`if (q != 0 && (q + 0xB0) != 0 && *(s8*)(q + 0xB0) != 0)` keeps the redundant pointer test); t_22BD90 func_0022C308 (stack list iterators `it`/`end`, end re-stored each iteration); t_1E75A8 func_001E7A68 (read D_00368A38 into a local right after the first call).
Given up: func_001E1220 (empty do-while after a jal gets a padding nop in the original), func_001CB180 (D_00370EE0 macro form vs gp in the same file), func_001CA458/func_00248620 (`~x != 0` pointer tests).

## Session 9 (worker B11)
Matched: func_001C8258 func_001C1468 func_001C82F0 CFunc_SetMenuAutoRepeatTimes func_001E8C00 func_00225C28 func_001D4400 func_001D00B0 func_001C1DE8 func_001E2968 func_001BFC58 func_001E7CE0
Habits: virtual calls through a vtable struct (`VEnt`) put the fn pointer in $v0; a class with real `virtual void vN()` members puts it in $v1 (entry n at 8*n+8 here: v2 -> 0x18); binary search `while (step) { i = best + step; ...}` keeps `addu` unfolded; sorted-insert with `best`-style `while (c->next && !(k <= c->next->k))` loops matches except for the advance reload.
Given up: func_001CC100 (two dead `sw` to a stack slot, register v0/v1 order; volatile local, 3 forms); func_001BB100 (short loop with a jal: original has `lw s0; nop; bnez; nop`, ours no padding nop); func_001BFD58 (sorted insert: original reloads `c->next` in the bc1fl delay slot, ours `move v1,v0`; 6 forms incl. volatile/asm memory); func_00243398/func_002434E8/func_001C41C8 split tails.
More (B11): func_001C9210 func_001BDCF8 func_00234810 func_001C5828 func_001B1C80 func_001D5250
Habits: `register char* t asm("$6") = ...` pins a value that the original keeps in the argument register it is later passed in (func_001C5828); a local-struct init copied from a global with three loads then three stores is three field assignments in field order (func_001B1C80); read a gp global into a local before an unrelated store when the original loads it first (func_001D5250); a callee that the same file defines with fewer args: second declaration with `__asm__("name")`.
Given up: func_001E7FD8 (loop with an aligned head: original has `nop` before the loop top and bnezl; no align flag in this gcc); func_00244898 (original copies a1/a3 into v1/v0 in the prologue, ours uses them directly); func_001E0AE8 (null-checked getter, same class as func_001E0B60).
More (B11, part 3): func_002270A0 func_001DA500 func_001E8AB0 func_001DA8F8 func_001AEFF0 func_001AF090 func_00210720 func_002107C8 func_00226FA0 func_002271C0 func_00220270
Habits: a virtual call `o->vN(args)` written with a real `virtual` class puts the fn pointer in $v1 and `this+delta` automatically (entry k = k-th declared virtual, at 8k+8; the vptr sits after the declared data members, so pad before the first virtual); stack list iterators `I end; I it;` (declare `end` first when the original has `it` at the higher slot) with the `end` re-store; tree walker `if (leaf(p)) {leaf work} else {for children}` keeps the leaf body first; `register T* e asm("$7") = ...` pins a caller-saved value that the original passes straight on as the 4th argument (func_00210720); `f(r, a); a = r;` (assignment after the call) gives the `move` in the jal delay slot (func_00226FA0); a callee whose caller leaves a stale $a3 is a 3-arg function, do not pass the 4th.
Given up: func_001E24B0 (9-way compare chain: original has `lw; nop; beq` load-use nops and the pointer in v1, ours none/a2); func_001B3B00 (hardware register stores via lui/ori + lwu/dsll32/dsra32 sign-extend, ours folds addresses into `lui at`); func_0023A0C8 (original puts `move a1,zero` in the beqz delay slot before the jal, ours after); CFunc_EnterSurveyorMode (second `bnez` has `move v0,zero` in its delay in the original, ours uses bnezl; 5 forms); func_001C93C0/func_001CA6D0/func_001D1CF8/func_001D4C08/func_001CA4E8/func_001CA768/func_001BF6F0/func_00225D78/func_001E80C0/func_00230230 not attempted (loops with `~x != 0` tests or switches).
More (B11, part 4): func_001E8F00 func_001E8B50 func_001E8948 func_001D0170 func_00220898 func_001E92B0
Habits: a 2-case checksum switch whose original tree is `beq A; sltu (A < k) -> end; beq B; b end` with the A body first is NOT a switch here: write it with ifs/gotos (`if (k == A) goto a; if (k > A) goto end; if (k == B) goto b; goto end;`) (func_001E92B0); an if-chain `if (k==A||k==B) return; if (k==C) {...} if (p->unkC == D) vcall` reproduces gcc's reloads; `if (p->unk54 != 0) {A} else if (p->unk58 != 0) {B}` order decides the fall-through block.
Given up: func_00213D60 (float compare result materialized in v1 then branch-converted to 0/1; ours folds it to sltu), func_001D3620 (list walk with vcall returning 0/1: original `beqzl v0,exit; move v0,zero` shape, ours `bnez; nop; b exit` in 4 forms), func_001C9A80 (argument setup order of the 6-arg call), func_001C5778 (dead u8[4] colour stores), func_001E7FD8/func_001BB100 (aligned loop head nop).
More (B11, part 5): func_00248588 func_001FAF90 func_00249B78 func_001DA448 func_002210B8 func_001DF900
Habits: dead-store elimination removes `n->unkC = n` when the next store to the same field comes before any load; read `list->unk10` into a temp between them to keep both (func_00248588); an array field `s32 unk1C[9]` indexed by the variable gives `addu v0,self,v0` (operand order), a flat pointer add does not (func_001FAF90); when a matched caller passes a pass-through register to a callee declared with fewer args, widen the caller's own parameters instead of the callee (func_001FAEC0, func_00249F20); `goto` labels fix the block order of a 3-way tail (func_001DF900).
Given up: func_001D0848 (return value kept in s0 for the early `bnezl`; ours reuses v0), func_001BF838 (inverted branch layout of a 5-way float condition), func_001D3620 (see above).
