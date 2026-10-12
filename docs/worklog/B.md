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
