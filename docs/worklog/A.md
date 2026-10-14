# Worklog A (src/game/t_10C000.cpp .. t_1A9A60.cpp)

Notes:
- 0x4 candidates and functions starting with `addiu $sp, +N` are split tails: skipped.
- Functions that save `$s` registers needed `-fopt-stack` ("opt-stack"); configure.py now has it (85ecf94), so the
  "opt-stack" entries below are worth a retry.
- Old-assembler artifact: `.sdata` globals read/written outside a delay slot appear as `lui`+`%lo` (macro
  expansion, `$at` for stores); declare them `extern T D[] __attribute__((section(".sdata")))`. Inside a delay slot
  they are `%gp_rel`: declare them as scalars. A symbol used both ways in one file can't be matched with one declaration.
- Divisions: the original has no divide-by-zero `break` checks; ours needs `-mno-check-zero-division` ("nozdiv").
- `cvt.w.s` (float->int, `.word 0x46..` in the asm) is rejected by the assembler for r5900: skipped ("cvt.w.s").
- fcheck nop bug (false DIFFERS after an operand-less nop) fixed in 85ecf94: retry those entries.
- Virtual calls whose result is returned (`return fn(...)`) allocate vt/delta/fn registers differently from void
  calls: if the registers are off, try returning the result.

## t_187930

Matched 22 (first pass): func_00188360 func_00188420 func_00188448 func_00188700 func_001888D0 func_00188908
func_00188940 func_00188998 func_001889E0 func_00188A00 func_00188A38 func_00188AD0 func_00188AE8 func_00188B70
func_00188C50 func_00188C70 func_00188C88 func_00188E38 func_00189078 func_001893D0 func_001894C8 func_00189508

Matched 21 (after -fopt-stack): func_00187F00 func_00188120 func_001882A8 func_001883A8 func_00188520 func_00188568 func_00188618 func_00188680 func_00188870 func_00188A70 func_00188D68 func_00188DD0 func_00188F80 func_00188FB8 func_00189010 func_00189040 func_00189180 func_001892F8 func_00189360 func_00189718 func_00189818

Matched 1 (gp retry, solved): func_001891A0

Given up:
- func_00189400: last stores load source/dest in the other order (scheduling); 5 tries
- func_00187E08: lui/lhu register swap (v0/v1); 6 tries
- func_001885B0, func_00188D00, func_00189290: alloc args set in order a2,a3,a1 in the original; 3 tries

## t_10C000

Matched 3: func_0010C120 func_0010D420 func_0010C2E0
Matched 3 (gp retry, solved): func_0010C170 func_0010C050 func_0010C0B8

Given up:
- func_0010C330: 4x4 determinant, float scheduling; 2 tries
- func_0010C1A0: hand-written asm (float constants via lui/ori, `c1` sqrt)
- func_0010D548, func_0010D438: 128-bit vector lane code (pextlw/pcpyud), not attempted

## t_10EBD8

Matched 1: func_00110158

Given up:
- func_0010F698, func_0010F6A8, func_0010F6C0: float lane of a 128-bit load (lq+mtc1); unions go through the stack
- func_0010FE60: last store not in the delay slot (switch tail); 5 tries
- func_0010FED0: inline ctor store scheduling; 4 tries

## t_110D00

Matched 2: func_00111A08 func_00111A20

Given up:
- func_00112CB0: float lane of a 128-bit load
- func_001117F8: inline ctor store scheduling (like func_0010FED0), not attempted

## t_112D48

Matched 10: func_00113528 func_00113930 func_00113B68 func_00113BA0 func_001140B0 func_001140F0 func_00114460
func_001149D8 func_00114A18 func_00114A78

Given up:
- func_00113988 (strcmp), func_001139E0 (stricmp): loop/branch layout; ~12 variants
- func_00113A70, func_00113AC8 (strcat): solved after the short-loop padding fix (A6)
- func_00113770: c/r register swap (a0 vs v1); 5 tries
- func_00113BF8, func_00114C70: unrolled loops (-funroll-loops style), not attempted

## t_114DC8

Matched 8: func_00115028 func_00116288 func_001162B8 func_001163B8 func_00116578 func_00116590 func_001165C8
func_001167C8 (func_001150B8 retyped to pass its argument)
Matched 1 (gp retry, solved): func_001153C8

Given up:
- func_00116660: nozdiv; with the flag only a scheduling diff left
- func_001150E0, func_001165E8: split tails

## t_116E38

Matched 8: func_00116E90 func_00117118 func_00117168 func_00117C20 func_00117C60 func_00117CC0 func_00118640
func_00118700
Matched 2 (gp retry, solved): func_001187D0 func_00118798

Given up:
- func_001183C8: cvt.w.s now fine; original copies the u8 (`move a2,v1`) before the `== 1` test/store; 4 tries
- func_001179F8, func_00117940: iterator on the stack, not attempted

## t_118E40

Matched 16: func_00119180 func_0011A100 func_0011A208 func_0011A380 func_0011A3E0 func_0011A410 func_0011A440
func_0011A470 func_0011A520 func_0011A5B8 func_0011A5E0 func_0011A648 func_0011A8A8 func_0011A8F8 func_0011A928
func_0011AD80
Matched 1 (gp retry, solved): func_0011A128

Given up:
- func_00119490, func_001194B8: address order (n*4+self)+0x194 vs ours (self+0x194)+n*4; 6 tries
- func_0011A0B0: `move a0,v0` scheduled before the global store; 2 tries
- func_0011A170, func_00119A60: unrolled loops
- func_00118EF8: split tail

## t_11AEB0

Matched 6: func_0011AF30 func_0011AF90 func_0011AFF0 func_0011C2A8 func_0011C3A8 func_0011C480
Matched 1 (gp retry, solved): func_0011C408

## t_11D000

Matched 16: func_0011D348 func_0011D4F8 func_0011DA60 func_0011DB08 func_0011DB88 func_0011DBB8 func_0011DBE8
func_0011DC18 func_0011DD68 func_0011E130 func_0011E730 func_0011E780 func_0011E8D0 func_0011E918 func_0011E960
func_0011ED30
Matched 2 (retry, solved): func_0011ED00 func_0011ECF0

- func_0011ED00/func_0011ECF0: the counters are `volatile` (load kept out of the delay slot, `lw`+dsll32/dsrl32
  instead of `lwu` for the u64 return), plus GP_DATA.

Given up:
- func_0011ED68, func_0011EE38: all match except the unsigned->float `b` keeps a nop in its delay slot (ours puts
  the cvt.s.w there); D_0036876C must be read into an int local; 4 tries
- func_0011E4E8: 2D array push, two extra instructions; 4 tries
- func_0011D9E0: init store scheduling; 1 try
- func_0011D830: unrolled loops

## t_11F000

Matched 3: func_0011F4D8 func_0011F510 func_0011F598

Given up:
- func_0011F3A8: li -1 lands in v0 instead of v1; 1 try
- func_00120E00: globals are `volatile` (DI/EI around them, fixes the delay slot), but the xori lands in v0
  instead of v1; 5 tries
- func_001206D0: two-entry search, original keeps nops in delay slots; 3 tries (also not -funroll-loops, not volatile)
- func_0011FA98, func_0011F8D0, func_0011F9A8, func_001208C0: unrolled/loop code, not attempted

## t_1210C8

Matched 14: func_00121618 func_00121668 func_00121870 func_001218A0 func_00121B18 func_00121B68 func_00121C18
func_00121CD8 func_00121D78 func_00121DD0 func_00122460 func_00122490 func_00122608 func_001226A0
(func_00121BD0, func_00121BF8 retyped to pass their arguments)
Matched 2 (gp retry, solved): func_00122DE0 func_00122F88 (dtor: load the Ref field into a local before the
static counter decrement, keep `&field` in a variable)

Given up:
- func_001224F8: final `lw` not in the jr delay slot (branch-target label); 1 try
- func_00122FF8: div.s with two hazard nops before it (assembler); C is `p->unkC / p->unk10`, ours fills the jr slot

## t_1230D0

Matched 16: func_00123138 func_001232E8 func_00123540 func_00123678 func_00123690 func_001236D0 func_00123720
func_001238F8 func_00123920 func_00123948 func_00123EB8 func_00123F18 func_001244C8 func_00124510 func_00124630
func_00124688

Given up:
- func_00123568: matched on retry (inline li.s now works)
- func_00123778: `li a2,512` / `sw` order swapped; 1 try
- func_00123E68: solved (A6): `for (i = 0xFF; i >= 0; i -= 0x20) {}` after the call
- func_00123B68, func_00123BB0, func_00123C00, func_00123C60: list iterator kept on the stack, not attempted

## t_1277C0

Matched 16: func_001277C0 func_001279A8 func_00127A60 func_00128098 func_001283A8 func_00128460 func_001288B0 func_00128940 func_00128980 func_001289C0 func_00128A00 func_00128A40 func_00128AC0 func_00128B08 func_00129080 func_00129350 

Given up:
- func_001277F8: split tail
- larger candidates (>0x60) not attempted yet

## t_1298B0 (`// cflags: -ffast-math -funroll-loops`)

Matched 16: func_00129F70 func_0012A3A0 func_0012A3E8 func_0012A448 func_0012A478 func_0012A4D0 func_0012A510
func_0012A538 func_0012A590 func_0012A5E8 func_0012A648 func_0012A6F8 func_0012A778 func_0012A7D8 (+ func_0012A4B0
retyped)
Matched 2 (gp retry, solved): func_0012A048 func_0012A0F8 (pooled delete/new; `return r` inside the pool branch)

- `min.s`/`max.s` in the original (func_0012A590) are only emitted with `-ffast-math`; the other functions of the
  file still match with it. func_00129F70 is a loop unrolled 5x (`-funroll-loops`).
- A `u32` field set to 0xFFFFFFFF gives `lui 0xffff; ori 0xffff` (an `int` gives `li -1`).

Given up:
- func_0012A9A0: `andi`/`lw` scheduling of `((x >> 29) & 1) ^ 1` argument; 8 tries (bitfields too)
- func_0012A828: `ori a1`/`move a0` order before some calls, delay slot fill; 2 tries
- func_0012A038, func_001298B0, func_0012B700: split tails / odd fragments
- func_0012A1B0: float wrap loops, not attempted yet

## t_12B970

Matched 12: func_0012BD10 func_0012BD58 func_0012BD98 func_0012BDD0 func_0012C1B8 func_0012C200 func_0012C878
func_0012C8A8 func_0012C920 func_0012C958 func_0012D318 func_0012D630 (func_0012BC90, func_0012BCB8 retyped to
pass (self, n))

- `nor/movz/addiu -4/movz` = list node `Get()` (unk4 == 0xFFFFFFFF -> 0) then a null-checked cast to the
  object 4 bytes before; `delete n` on a class with a virtual destructor at vptr 0x14 gives the `lh 8/lw 0xC/jalr`
  call with 3.

Given up:
- func_0012D298: matched later (base ctor declared returning a pointer)
- func_0012C780: `sra` in the jal delay slot then `andi s0; move v0,s0` after the call; 8 tries (same quirk as
  func_0012A9A0)
- func_0012D028, func_0012D0E8: solved after the one-pass `la` fix (A6). Was: pooled new/delete, blocked: gcc emits
  `la $3,D_00371470` (8-byte array, small) and asm_filter does not expand `la` to lui/addiu like SN's assembler;
  declaring it unsized makes gcc split lui/addiu itself and schedule them apart
- func_0012BD38, func_0012D000, func_0012C750, func_0012BCD8, func_0012CEE0, func_0012D210: split tails
- func_0012CF40: iterator on the stack; func_0012BF38: jtbl
- func_0012D1A0: solved (A6): two empty `for (i = 0x7F; i != -1; i -= 0x20) {}` loops
- func_0012BE38: not attempted yet (virtual call through container)

## t_12D990

Matched 22: func_0012D990 func_0012DA00 func_0012DF30 func_0012E228 func_0012E3B8 func_0012E628 func_0012E668
func_0012E6D0 func_0012E6F0 func_0012E728 func_0012E790 func_0012E818 func_0012ED80 func_0012EE08 func_0012EF50
func_0012EFE0 func_0012F228 func_0012F258 func_0012F2E0 func_0012F368 func_0012F5B0 func_0012F958
(func_0012E870, func_0012EE68, func_0012F348, func_0012F980 retyped to pass (self, params))

- `delete[]` of an array of objects with a virtual destructor (func_0012DF30): 16-byte cookie, dtor called with 0;
  the file defines `inline void operator delete[](void* p) { func_00119400(D_00368A38[0], p); }`, which matches.
- Store order: gcc often emits a run of stores as [last, first, second, ...]; permute the source.

Given up:
- func_0012F8D0: solved (A6): two empty delay loops; each needs its own loop variable (`int i`, `int j`)
- func_0012E5F8: split tail
- larger ones (>0x90) not attempted yet

## t_12F9A0 (`// cflags: -funroll-loops`)

Matched 17: func_0012F9A0 func_0012F9B0 func_0012F9E8 func_0012FA98 func_0012FD20 func_0012FD48 func_001305B8
func_00130C58 func_00130CE0 func_00130CF8 func_00130D10 func_00130DC8 func_00130E50 func_00130ED8 func_00130F70
func_001316B8 func_00131728

- The 4-entry checks (func_00130C58, func_00130DC8...) are `for (i = 0; i < 4; i++)` loops fully unrolled.
- func_0012F9B0: 0x1200-byte struct assignment = lq/sq loop. func_00130CE0: `i * 0x80 + (char*)self + 0x40`
  gives the original operand order.
- func_0012F9E8 = pooled `operator delete` (two pools D_003692A0[D_003692B0], [^1], else func_00119400); reading
  D_003692B0 twice (not a local) matches.

Given up:
- func_00131970, func_001318D0: loop reloads p->unk4 at the top in the original (ours keeps the condition's load;
  -fno-gcse fixes them but breaks func_0012F9E8); 3 tries
- func_00131338, func_001310E8: 128-bit vector constants (por/pcpyld); func_00131008, func_00130628: vu0
- func_0012F9E0: split tail

## t_1319D0

Matched 5: func_00131FC0 func_00132000 func_001323F8 func_00132438 func_00132480

Given up:
- func_001324D0: float lanes of a 128-bit value (dsrl32/pcpyud + mtc1); func_00132390: 128-bit vector constant
- func_00132F50: split tail

## t_133A98

Matched 14: func_00133CE8 func_00133F60 func_00133FA0 func_001342E8 func_00134340 func_00134380 func_00134748
func_001348C8 func_00134938 func_001349D0 func_00134A20 func_00134D28 func_00134D60 func_00134DD0
(func_00134278 retyped to take void*)

Given up:
- func_00134288: `move v0,a1` in the bne delay slot + movn; 5 tries (if-conversion picks movz)
- func_00134700: matched later (base ctor declared returning a pointer)
- func_00133A98: prologue `move s2,a0`/`sd s3` order; 3 tries
- func_00134210: loop layout (`bnezl body; b ret0` vs our beqz); 3 tries
- func_001342B0: 128-bit vector constants; func_00134998, func_00134208: split tails

## t_135A98

Matched 3: func_00135F28 func_00137618 func_001376B8

Given up:
- func_00135D20: `move s0,zero` (loop counter init) scheduled before the count load in the original; 5 tries
- func_00135ED8, func_00135E20: 128-bit vector constant / float lanes
- func_00137668, func_00137690, func_001377B8: split tails

## t_137C98

Matched 10: func_001384B0 func_00138850 func_00138908 func_00138978 func_00138D98 func_00139510 func_00139590
func_001395A8 func_001397A8 func_00139C18 (func_001389F0 retyped to pass its 2nd argument)
Matched 1 (gp retry, solved): func_00137F38 (color by value = class with copy ctor, passed by invisible reference)

- ldl/ldr/sdl/sdr = assignment of a 0x38-byte char-aligned struct. func_002EC118(float)/func_002EC10C(void) are the
  VU0 sin/cos start/result helpers (gamespy.s). u128 arguments go in one register each (func_00138D98); the
  callee's float params come right after the u128s.
- Float literals must be the exact float (57.2957763671875f, 0.01745329424738884f) or the low bits differ.

Given up:
- func_00137E30, func_00137EB0: the last `sdr` is not put in the jr delay slot by SN's assembler (ours fills it);
  still differs after the usd fix (A6, `*dst = D_0032A520`)
- func_00138E78: `li 0x19F1C; addu; lw 0` not folded in the original (ours folds the offset); 3 tries
- func_001396D0: 128-bit != compare (pceqw/ppacb), gcc 2.95 rejects TImode compares
- func_00138790: solved after the `la` fix (A6)
- func_00138A18: float lanes of 128-bit values; func_00138B08, func_00138950, func_00138E60: split tails

## t_139CE8

Matched 7: func_00139CE8 func_00139EB0 func_00139EE0 func_00139FC0 func_0013A010 func_0013A060 func_0013B038

- func_0013A060: ref-counted pointer (func_001CE868 attach / func_001CE888 detach, 12-byte {p, 0, 0}) written as
  an inline class with ctor taking `S139_X* const&`, dtor and operator=; the dtor's final check survives only that way.
- func_00139EE0: `andi; movz` comes from an inline `if (x & 0x4000) return 1; return 0;` helper.

Given up:
- func_00139F98: last sibling walk; the original reloads `c->unk84` in the bnezl delay slot and its loop is not
  rotated; while/for/goto forms tried (A6), 4 tries

## t_13BE78

Matched 10: func_0013C1B0 func_0013CAA0 func_0013CC28 func_0013CC70 func_0013CC98 func_0013CFC8 func_0013D000
func_0013D2D0 func_0013D360 func_0013D6E8

- Constructors: declare the base-class ctor as returning the pointer (`S* func(S*)`), not void; otherwise the
  vtable address lands in v0 instead of v1 (func_0013CC28). This also explains func_00134700 / func_0012D298.

Given up:
- func_0013C678, func_0013C5F8: solved after the short-loop padding fix (A6): recursive walks over unk78/unk84
- func_0013CE58, func_0013CF78: recursive bool check; our gcc either tail-converts or adds `move v1,v0`; 5 tries
- func_0013C1F0: parent walk with a ref temp; loop variable copied (move a0,s0) and rotated; 3 tries

## t_13DEB8

Matched 7: func_0013DEB8 func_0013DF18 func_0013EB38 func_0013EC10 func_0013EC98 func_0013ED28 func_0013FE00

- func_0013FE00: same ref-counted pointer class (here the ctor takes the pointer by value, plus
  `operator=(const Ref&)`); declaring `int n = 0` before the Ref local gives the original order and loop shape.

## t_13FEE0

Matched 8: func_0013FEE0 func_00140930 func_00140A00 func_00140A60 func_001413A0 func_00141920 func_001419E8
func_00141C28 (func_00141B50 retyped to pass its 2nd argument)
Matched 1 (retry, solved): func_00141B00 (D_00372B88 `volatile`: keeps its load out of the jal delay slot)

- A 4-byte char-aligned color struct copies with lwl/lwr; passing it by value through a hidden stack copy (as
  func_00141B70 does) needs a user copy constructor (TREE_ADDRESSABLE).
- A member function can be bound to a splat name with `__asm__("func_...")` on its declaration (fcheck accepts it).

Given up:
- func_00141B70: solved after the mfc1 prelude fix 703ed82 (color class with copy ctor; `C(self->unkE8).c.a`)
- func_00141A40: `ori a1`/`move a0` order around the `int x = 0` stack init before the getter calls; 7 tries
- func_00141988 (split), func_00141658, func_00141668, func_00141AF8: split tails

## t_152E18

Matched 35: func_00153150 func_00153178 func_001531A0 func_001531C8 func_001531F0 func_00153218 func_00153240
func_00153D80 func_00153DB0 func_00153F98 func_00154078 func_001540A8 func_00154108 func_00154510 func_00154640
func_00153430 func_00153F08 func_00153F38 func_00153F68 func_00153FC8 func_00153FF8 func_001540D8 func_00152E88
func_00153100 func_00153588 func_00154608 func_00154708 func_001546B8 func_00154670 func_001541A0 func_001544B8
func_001547C8 func_00153510 func_00154750 func_00153810
Matched 4 (gp retry, solved): func_001537E0 func_00154430 func_00153DE0 func_00153E70 (manual `delete[]` loop of
10-byte elements, `while (self->unk4 != e)`; func_00154540 also takes a float: bound as `func_00154540_f`)

- An asm-label alias (`extern int X_lo[] __asm__("D_00368A38") __attribute__((section(".sdata")))` next to the
  scalar) does NOT solve the both-forms problem: gcc emits `lw $4,D_00368A38` for both and the scalar's
  `.extern D_00368A38,4` makes gas pick %gp_rel for every use. A real fix needs asm_filter (scripts/) to expand
  non-delay-slot loads of .sdata symbols to lui/%lo like SN's assembler did.
- func_00152E88: returning the virtual call's result fixed the vt/fn register order.

Given up:
- func_00152E18, func_00152ED8: original keeps the 2nd arg in a1 until the delay slot and loads the object into
  a2; ours moves a1 to s1 first; 2 tries
- func_00152F48: dead `lw v0,0x10(a0)` before a virtual call, not reproduced
- func_00153408, func_00153078, func_00153010: split tails

## t_18B9C0

Matched 33: func_0018BBA8 func_0018BC08 func_0018BCA8 func_0018CBD8 func_0018CFF0 func_0018D020 func_0018D480
func_0018C3F8 func_0018BBD0 func_0018D668 func_0018D780 func_0018CB98 func_0018BAE8 func_0018D6A0 func_0018D0D0
func_0018BF68 func_0018C1A8 func_0018BF10 func_0018C150 func_0018D588 func_0018BA88 func_0018D118 func_0018CC08
func_0018BC30 func_0018C948 func_0018D050 func_0018D200 func_0018CEC0 func_0018D178 func_0018D5E0 func_0018D3F0
func_0018D350 func_0018CF48 func_0018BCD0 func_0018CDC8 func_0018C9C8 (func_001ACF30 / func_001B1898 retyped)
Matched 1 (gp retry, solved): func_0018D718 (calls func_0018D6A0 with a 4th argument: asm-label alias
`func_0018D6A0_4`)

- func_0018D6A0: the base ctor takes the 3rd argument too (a2 left in place across the call).
- func_0018D350: temp object on the stack; `r = 0` must be in an else branch (otherwise hoisted to a 3rd saved
  register); base ctor returning a pointer fixes v0/v1.
- func_0018BCD0: function-static object (guard D_00372BC4, object D_00381C30); `return &(D_00381C30 = f(x));`
  with f returning the 32-byte struct by value gives the original register use.

Given up:
- func_0018D4B8: loop is laid out jump-to-test in the original (ours rotates it); 1 try
- func_0018CAA0: stray `nop` after the 64-byte copy through a stack temp, copy order differs; 1 try
- func_0018B9E0, func_0018BB28: 4-byte color returned through a hidden pointer from callees returning it in v0
- func_0018BE00: pextlw/pcpyld packing
- func_0018D280, func_0018D7B8: split tails

## t_15D2E0

Matched 28: func_0015D3F0 func_0015E0D0 func_0015E0A8 func_0015D5A0 func_0015DBF0 func_0015EDD0 func_0015F240
func_0015F218 func_0015DDB8 func_0015D2E8 func_0015D570 func_0015F168 func_0015EBD0 func_0015F038 func_0015E128
func_0015EA08 func_0015E5C0 func_0015EAC0 func_0015F268 func_0015EB90 func_0015EA78 func_0015F110 func_0015ED48
func_0015DC18 func_0015E460 func_0015E510 func_0015E190 func_0015F070
Matched 2 (gp retry, solved): func_0015DDE8 func_0015EFE8

- func_0015DDE8: dtor of two embedded lists; inline clear helper writing `&l->unk4` each time (no local for the
  sentinel), stores next-then-prev.

- Virtual calls that load the vtable into t0/t1 pass the caller's own a1..a3(/t0) straight through: give the
  function and the call those extra parameters.
- func_0015DDB8 is a static-init function (init, priority 0xFFFF): list head at D_0037DAF0+4 set to itself; go
  through `L* l = &D` so the base is not folded.
- 4-byte char-aligned color passed by value: class with a user copy ctor (`c(o.c)`, lwl/lwr) and an operator=
  copying one u32 (lw/sw). func_0015EB90 builds an unused copy (`C tmp(self->unk18);`).

Given up:
- func_0015D6F0 (and the same list walks func_0015DB20, func_0015DB90, func_0015D750): iterator objects on the
  stack; everything matches except the first `it != end` test, which the original reloads from memory; 7 tries
- func_0015EDF8, func_0015EE28: function-static guards with a stray `nop` after the guard store; 2 tries
- func_0015E0F8: ctor, vtable address lands in v1 instead of v0 (also tried a real ctor via asm label); 3 tries
- func_0015D318: 8x unrolled loop (file has no -funroll-loops); func_0015EE50, func_0015EDA0: 128-bit returns
- func_0015EC68, func_0015E630, func_0015D560, func_0015DDB0: split tails

## t_16C498

Matched 20: func_0016C6C0 func_0016D0F8 func_0016DDA0 func_0016E458 func_0016C620 func_0016C638 func_0016C6D0
func_0016C798 func_0016D108 func_0016DDB0 func_0016E468 func_0016D318 func_0016D468 func_0016E120 func_0016C650
func_0016C9C0 func_0016C5C0 func_0016D3E8 func_0016C4A0 func_0016C4F8
Matched 1 (gp retry, solved): func_0016E070

- func_0016D3E8: static init of two 4-byte globals; byte stores to non-gp .sdata symbols via section arrays,
  first byte of each via %gp_rel scalars.

Given up:
- func_0016C878: element address must be `(i*4 + self) + 0x154` unfolded; 5 address forms tried
- func_0016CD28: dtor clearing the same list (self+4) twice; ours keeps self+4 in a saved register across both
  loops (CSE), the original recomputes it (v1/v0 + copy); 3 tries (helper as in t_15D2E0 func_0015DDE8)
- func_0016CDF0: not attempted yet (0x154, stack list node copy); func_0016CCB0: pextlw
- func_0016D070 (inside func_0016D060), func_0016D370 and other 0x4..0x10 fragments: split tails

## t_189938

Matched 23: func_0018A078 func_0018A510 func_0018B398 func_0018B028 func_0018B3C0 func_0018A350 func_0018A388
func_0018A430 func_0018A860 func_00189AA8 func_0018ACD8 func_00189E90 func_0018AFD8 func_00189AE8 func_00189E38
func_0018A3D8 func_0018AD18 func_0018A7A0 func_0018A800 func_0018A468 func_0018A898 func_0018A5A0 func_0018AF58
Matched 3 (gp retry, solved): func_0018AC50 func_0018B128 func_0018AEA0 (bit 1 of a 64-bit load spanning two
int fields: `(int)(*(long*)&self->unkC8 >> 1) & 1` gives dsll 31/dsra32/andi)

- Stack iterators that match (func_0018A7A0, func_0018A800): class {int; Node* cur;} with ctor `cur(n)`,
  `operator!=(const It&) const` and `operator++`; declare `end(head)` first (lower stack slot), then
  `it(head->next)`, `for (; it != end; ++it)`.
- func_0018AF58: `(u32)u64field & 1` gives the lw test; index the array directly (`s->arr[i].f`), no local
  element pointer, to get `(i*8) + base` in the loop.

Given up:
- func_0018B070: 128-bit consts
- func_0018A4D0: color returned through a hidden pointer; func_0018A538, func_0018B058: split tails

## t_1816C0

Matched 12: func_001818F8 func_00181910 func_001824B8 func_00181C58 func_001821E0 func_00182180 func_001822A8
func_00182338 func_001823A8 func_00182370 func_001823F0 func_00183460

- func_001824B8 (BCD byte -> int): parameter is u32, return u8.
- func_00183460: `(int)(x * (float)D_0036876C[0])` with D_0036876C an int section(".sdata") array; cvt.w.s matches.
- Not attempted yet: the 0x3C+ candidates of this file.

## t_14E7E0 (committed by the integrator's rescue commit dfab98d)

Matched 13: CFunc_ToggleAddScenes func_0014E850 func_0014E948 CFunc_CheckFlexibleParticleStructure
CFunc_CheckSplineParticleStructure func_0014EB28 func_0014EB78 func_0014F1D0 func_0014F1E0 func_0014F958
func_0014F978 func_0014F9D8 func_00150520 (func_0014F150 retyped to pass self)

Given up / open:
- func_0014F910: static list-node init; register/store order not found yet (several permutations)
- func_0014E7E8 (list search), func_0014F0E0 (split), split tails: not attempted

## t_146580

Matched 18: CFunc_DumpScreenElements CFunc_ScreenElementExists CFunc_SetRootScreenElement CFunc_ResolveScreenElementID
func_001482F8 func_00148350 func_00148508 CFunc_DoScreenElementMorph func_00146DE0 CFunc_SetScreenElementLock
CFunc_ScreenElementSystemInit func_00148258 CFunc_SetScreenElementProps CFunc_CreateScreenElement
CFunc_DestroyScreenElement CFunc_GetScreenElementPosition CFunc_GetScreenElementDims CFunc_MenuSelectedIndexIs

- Element lookups return a ref-counted handle {p,0,0} on the stack (func_00145488/func_00145310), released by hand
  (`if (r.p) { func_001CE888(r.p, &r); r.p = 0; }`); `if (lookup) {...; return 1;} return 0;` gives the original
  branch layout. func_0027DF00 returns bool (`!x` is xori). GetScreenElementDims: `float w = field;` then
  `int iw = (int)(w * call())`.

Given up:
- func_00148490 (ctor): store order of 13 fields not reproduced; 5 orders tried (base ctor returning a pointer
  fixed v0/v1)
- func_001468A8, func_00146E78: unrolled loops; func_001481E0: split head
- not attempted yet: func_001483B0, func_00146778, func_00148530, func_00146C10, func_00146580

## Small-function pass (agent A5)

Matched: t_1550C0 func_00155128 (u128 return of a global) · t_15B258 func_0015B370 · t_16E670 func_0016E990 ·
t_1727C8 func_00172960 (unused 0x40-byte local keeps the frame) · t_17D4D8 func_0017F280 · t_1965D0 func_00197ED8 ·
t_1992F8 func_00199D28 · t_19B448 func_0019BF10 · t_19D4E8 func_0019F318 · t_1A37A8 func_001A46D0

## t_14A6B0

Matched 18: func_0014B168 func_0014A910 func_0014A728 func_0014C348 func_0014AC08 func_0014AE30 func_0014C480
func_0014A6F8 func_0014A770 func_0014A6B0 func_0014C418 func_0014AC58 func_0014B1F8 func_0014AE80 func_0014B0F8
func_0014C390 func_0014C4A8 func_0014B368

- Hash table (items of {key, value, next}, 12 bytes; table {bits, items, count, ..., u8 unk15}): Get through an
  inline taking `const u32& key` (stores the key to the stack); Remove has no `if (!e)` check (loop guard only).
- `Ref = 0` (func_0014B0F8): `void** r = &p->unk34; if (*r) { detach; *r = 0; } *r = 0;`.
- func_0014AE10 is defined as `void(void)` but called with self: alias `func_0014AE10_p` via asm label.

Given up:
- func_0014B1B0: matched after the prelude fix 703ed82 (keeps the c.le.s/bc1t nop)
- larger ones (>0x100) not attempted

## t_148688

Matched 8: func_00149FF0 func_00149780 func_001497F0 func_001497A8 func_00149730 func_00148FF0 func_001498D0
func_00149658 (same selected-index logic as CFunc_MenuSelectedIndexIs)

Given up / open:
- func_00148C98: matched after the prelude fix 703ed82
- func_00149818: split head (alabel func_00149820); >0x150 ones not attempted

## t_1443D0

Matched 6: func_001443D8 func_00144448 func_00144498 func_00145488 func_00145558 func_00144FC0

- Ref handle {p, 0, 0}: constructing one from a pointer is `unk4(0), unk8(0) { p = x; if (p) attach; }` (stores
  4, 8, then p). Passed by value (func_00144FC0 -> func_00145068) it is a class with that copy-like ctor and no
  dtor (the caller never releases the temp).
- func_00145558: list walk with node `Get()` = `n->unk4 != -1 ? n : 0` (nor/movn).

Open: func_00145ED0, func_00145508 split heads; func_00146280 (0xF8, Ref-returning parent search) and larger not
attempted.

## t_14C740

Matched 7: func_0014D7A0 func_0014E4B0 func_0014CF18 func_0014E118 func_0014CFD8 CFunc_SetFontNonProportionalNumbers
func_0014E098

Given up / open:
- func_0014DC38: matched after the prelude fix 703ed82
- func_0014D010: 0x222E0 `lui a1` hoisted before the prologue in ours; 1 try
- func_0014E6A8: list walk; head uses `v0 = 0; movn v0,a0,...`, ours movz; 2 tries
- func_0014C740: solved (A6): call + empty delay loop
- func_0014E148: split head

## t_1550C0

Matched 8 (+ func_00155128 earlier): func_00156C88 func_00155138 func_00155668 func_00155170 func_00156550
func_00157098 func_00156590 func_001550C0

- func_001551A8 / func_001552F0 are defined `void(void)` but called with arguments: asm-label aliases `_p`.
- func_001550C0: `EB0* n = &D[i]` for two stores and `D[i].unk98` for the third gives both operand orders.

Given up:
- func_00156F80: `(i-1)*0x160` -- original adds -352 to the product, ours folds it into the ld/sd offset; 3 tries
- func_00155290: a0/a1 swapped for the index/pointer; 3 tries

## t_161580

Matched 15: func_00161FD8 func_00162358 func_001628B8 func_00161960 func_001618A0 func_001618F8 func_00162420
func_00163328 func_00162140 func_00162378 func_00162EE8 func_00161E78 func_00161EE0 func_00162070 func_001620D8

- u64 flag word at 0x50: setting a bit = u64 bitfield (`ld/and/or/sd`); testing bit 0 = `(u32)*(u64*)& & 1` (lw).
- Embedded list at self+0x14 walked with stack iterators (`It end(&head); It it(head.next)`), as in t_189938.
- func_00162140: the vcall passes the function's 2nd argument through (vtable lands in a2).

Given up:
- func_001623B8 (ctor): vptr store scheduled before `move a0,s1` instead of in the jal delay slot; 2 tries
- func_00161950, func_001623A0, func_001629C0: split fragments

## t_19D4E8

Matched 6: func_0019F2F0 func_0019E178 func_0019E1B0 func_0019E090 func_0019EC88 func_0019EB10 (+ func_0019F318
earlier)

- DMA packet helpers: packet pointer D_00373270, current tag D_003732E0, base D_00373280. func_0019EB10: the char
  store `base[2] = q` aliases everything, so `e[0]` is read into a temp before it.

Given up:
- func_0019E318: solved after the usd fix (A6)
- func_0019E340: usd fixed, but the 2nd store goes through `a1 = p+8` (ours folds `8(p)`); inline/post-increment
  forms tried (A6), 4 tries
- func_0019E2B8: same as func_0019EB10 with `/ 12`; e/v0 register swap left; 2 tries
- func_0019ECE8: solved (A6): `while (!func_0019EC88()) {}`

## t_19F538

Matched 4: func_0019F9F8 func_0019F750 func_0019F6F8 func_0019F7E0 (doubly linked chain, head D_00373300 / tail
D_00373304, prev at 0x4C; func_0019F7E0 = the unlink inline with first == last)

Given up:
- func_001A01F0, func_001A0468: u64 bitfield at 0x10; `move v0,a0` / v0-v1 order differs; 2 tries each
- func_0019F790, func_0019FEB0, func_001A1330: solved (A6); func_0019F790 needs `if (!*head)` then `p = *head`
  in the else
- func_001A1318: split fragment

## t_19B448

Matched 3 (+ func_0019BF10 earlier): func_0019C208 func_0019B668 func_0019CFE8 (`E* e = &D[n]` for two stores,
`D[n].unk8` for the third; early `return 0` first)

Given up:
- func_0019B778: pad-to-16 byte loop; ours increments in place, original copies `p+1` through another register; 4 tries
- func_0019B978: usd fixed; register allocation of table/value (a1/v1 vs v1/a1) and p+8/p+12 order; 5 tries (A6)
- func_0019D248: split head (alabel func_0019D258)

## t_185918

Matched 4: func_00185B98 func_001873D8 func_00187430 func_00187480 (value getter inline: flag bit 2 -> `*p`, bit 0 ->
`p`, else 0)

## t_163750

Matched 3: func_00163AD8 func_00163B00 func_00164E60 (dtor unlinking an embedded list node, as t_1298B0 func_0012A3E8)

## t_1A7A50

Matched 5: func_001A90F8 func_001A8520 func_001A8120 func_001A9240 func_001A9288

Given up:
- func_001A8168, func_001A84E0: the -1 lands in v1 (ours v0); also tried returning the callee's value; 2 tries
- func_001A8560 (qsort comparator, args are the elements): `bnezl`/`li v1,1` vs ours `bnez`; 3 tries (keeping it
  needs the `extern u8 func_001A8560[]` declaration turned into a prototype and a `(void*)` cast at the call)

## t_1A9A60

Matched 4: func_001A9D68 func_001A9A60 func_001A9CF0 (0x50-byte u128 struct copy = lq/sq loop) func_001A9D28

- func_001A9A60: reading the flags into a `u32` local makes `& ~2u` a lui/ori mask and gives the beqzl layout.
- func_001A9E78: split head (alabel func_001A9E88); its loop has nops.

## t_16E670 (A6)

Matched 20: func_0016E728 func_0016E778 func_0016E7A8 func_0016E7E8 func_0016E810 func_0016E900 func_0016E9A0
func_0016ED28 func_0016ED90 func_0016EE18 func_0016EF20 func_0016FDC8 func_0016FE10 func_0016FEF0 func_0016EFC8
func_0016FB98 func_0016FC10 func_0016E670 func_0016E850 func_0016FAD8

- `v >= old ? 1 : -1` gives `li 1; movn -1` (the `<` form picks movz).
- func_0016E670 = the same hash Remove as t_14A6B0 func_0014C4A8; func_0016E850 = pooled delete with %gp_rel pools.
- List iterators: `for (It it(l->head.next); it != It(&self->unk0->head); ++it)` re-stores the end temp each pass
  (func_0016FB98, func_0016FAD8). Copying an iterator (`It it = b;`, func_0016FC10) needs a user copy ctor
  (otherwise ldl/sdl); `if (l) {...; return n;} return 0;` gives its branch layout.

Given up:
- func_0016EF40: list unlink; the original reloads `p->unk0` in the bnel delay slot (no CSE), as t_139CE8
  func_00139F98; 3 tries
- func_0016F5F0: v0/v1 swap on the iterator init only (vcalls fixed by typing them as returning int); 5 tries
- func_0016FCD8: unsigned->float `b` keeps a nop + two nops before div.s (assembler), as func_0011ED68
- func_0016FE50: pextlw/pcpyld; func_0016F030 (alabel), split tails

## t_15B258 (A6)

Matched 21: func_0015B2F0 func_0015B568 func_0015B770 func_0015B7B0 func_0015B8C0 func_0015B8E8 func_0015B920
func_0015B968 func_0015B9C0 func_0015B9E8 func_0015BB20 func_0015D160 func_0015B380 func_0015B438 func_0015B4B0
func_0015B808 func_0015BAB0 func_0015BCA8 func_0015BE58 func_0015C0F8 func_0015C178

- Hash table again (Remove = t_14A6B0's; func_0015B380 = Clear, func_0015B438 = dtor).
- `while (p->next) p = p->next;` reloads `p->next` in the bnel delay slot (that is plain gcc, not a quirk).
- func_0015BE58: `bool missing = !f(); if (missing)` gives `xori 1; beqz` (a direct `if (!f())` gives bnez).
  Lookup-or-assert inline: `int t; if (!func_0027CC30(...,&t)) { func_0027F1E0(s,0,1); return 0; } return t;`.
- List iterator with `T*& operator*()` returning `cur->unk8`, bound to a reference before the test, gives the
  original copy/`+8` registers (func_0015C0F8, func_0015C178).
- sprintf func_0030B550 declared variadic (no stray `move a3,zero`).
- func_0015BC80 is defined `void(void)` but its result is used: alias `func_0015BC80_r`.

Given up:
- func_0015B268 (hash Get through `self->unk8`): original loads unk8 before the `addiu sp` and shares one
  `return 0` block; 5 forms tried
- func_0015BB80: static init of 12 x 16-byte entries, scheduled stores; func_0015D0D0: not attempted

## t_150DE8 (A6)

Matched 18: func_001510F0 func_00151950 func_00152648 func_00152990 func_001529F0 func_00152A50 func_00152AB0
func_00152C20 func_00152C78 func_00152CE0 func_00152D08 func_00152D30 func_00152D80 func_00152DC8 func_00150DE8
func_00152850 func_00152908 func_00152B88

- `delete p` / `delete[] p` through file-local inline `operator delete`/`operator delete[]` calling
  func_00119400(D_00368A38, p). A vptr at 0xC with members after it needs a base {pad[0xC]; virtual ~B();} and a
  derived struct for the rest (otherwise gcc puts the vptr last).
- func_00152850/func_00152908: hash Clear/dtor again (entry reset func_00152638).

Given up:
- func_00152B38 (ctor): the D_00372B58 argument load is in the jal delay slot in the original, ours hoists it
  above the field stores; 1 try
- func_00152B10: pextlw/pcpyld; func_00152670 (0x1E0) not attempted

## t_15F2F8 (A6)

Matched 20: func_0015F4E0 func_0015F698 func_0015F900 func_0015F9D0 func_0015FAA0 func_0015FD88 func_00160100
func_00160610 func_00160658 func_00160730 func_001607F0 func_001608D0 func_00160930 func_00160A40 func_00160768
func_00160970 func_00160DE8 func_00160FF8 func_001610A0 func_00161138

- Embedded list at self+0x14, iterator pattern as t_189938 (`It end(&head); It it(head.next);`).
- First-element checks (func_00160610/func_00160658): test `self->unk14.unk4 != &self->unk14` first and build
  the iterator inside the if; then the original loads before `addiu sp` (frame setup lands in the delay slot).
- func_00160970: u64 flag word at 0x50; bit tests as `(int)(*(s64*)&self->unk50 >> n) & 1`, the store as a u64
  bitfield from a `u32` parameter (dsll32/dsrl 31).
- func_0015F7C0 is defined with one float but called with two: alias `func_0015F7C0_2`.
- `r |= f(...) != 0` gives sltu/or.

Given up:
- func_0015FC88 (dtor with list clear): self/list register assignment differs (s1/s2/s3); 3 tries
- func_0015FBD8, func_0015FB68: 128-bit constants (pextlw/pcpyld)

## t_1992F8 (A6, `// cflags: -funroll-loops`)

Matched 14: func_00199398 func_00199960 func_001999F0 func_00199A30 func_00199AC8 func_00199B08 func_00199BB0
func_00199C60 func_00199D38 func_0019A2E0 func_0019A5D8 func_0019A640 func_00199C18 func_0019AE30

- The file needs -funroll-loops: func_00199C18 (16 zero stores, descending) is `for (i = 0; i < 16; i++) m[i] = 0;`
  and func_0019AE30 (octree count) is a 16-child loop unrolled 8x; all other functions still match with it.
- Clone helpers (func_00199960...): `p = ctor(new(size)); *p = *self; return p;` with a u128-array struct
  (lq/sq copy loop).
- func_00199D38: `tbl->m[i]` (array inside a struct) gives `addu base, index`; a plain `int*` gives the reverse.

Given up:
- func_00199CB8: `sra` on lbu values (ours srl; `/ 8` also srl); 2 tries
- func_001993D8: body matches, but the original keeps an empty trailing loop (`li -3; addiu 1; slti 4`) that
  our -funroll-loops build deletes, and hoists two constants; 3 tries

## A7 pass (small functions, smallest first; tails without `jr` and `alabel` splits skipped)

Matched 36: func_0016AFC0 func_00179110 func_00157280 func_001572D0 func_0017B528 func_00172940 func_00174C90
func_00174CE0 func_0011ED40 func_001162E8 func_001573D8 func_00174C20 func_00174E38 func_0011AA28 func_00159738
func_0016BAF0 func_00171F08 func_0017D680 func_0011A788 func_0011C4C0 func_0011D9A8 func_00117F18 func_00117DD0
func_00118388 func_00157580 func_0015A7B8 func_0015B218 func_0011A9E8 func_001576A8 func_001757F0 func_00177838
func_00177890 func_001834E0 func_00157378 func_00182828 func_00120BC0

- `int one = 1; self->unk6 = one;` stops gcc sharing the `li 1` register of an earlier store (func_0015A7B8).
- `if (r) return f(r); return 0;` gives the `bnez` call-first layout (func_0015B218); `return f() > 1.7f;` gives
  the bc1t + delay-slot `li 1` (func_00182828).
- A float global read as `extern float D_X[]; D_X[0]` gives `lui`+`lwc1 %lo` outside the delay slot (func_0011ED40).
- A call whose result is used by the caller's expression (`(t - f(t))->x`) must be written that way (func_0011A9E8).
- When the callee is already defined with another signature, declare an alias:
  `void f_1(void*) __asm__("func_0011A620");`.

Given up (A7):
- func_00174CB8: div.s with two hazard nops before it (assembler); func_0017F7F0: lq/addu scheduling; 2 tries
- func_0017E658: `mov.s f0,f12` copy + `move v0,a0`; 3 tries
- func_001576E0, func_00183760: vcall delta/this register (t3 / a1 vs a0); 3 tries each
- func_001820D0: `move a2,a0` self copy for the 3rd arg lands in a3; 1 try
- func_001A4730: lui placed before the sll in ours; func_0011E008: s0/s1 swap; func_0011DAB0: loop-tail nop
- func_00178860, func_00179B90, func_0011EF00, func_00157298 (pextlw), func_001170D8, func_00172CC8 (stack temp): not matchable / fragments

A7 pass, part 2. Matched 26: func_00119138 func_00119570 func_001195C0 func_00121F28 func_00183498 func_0011EB48
func_0011F548 func_00175560 func_00183760 func_001820D0 func_00175CC0 func_00175FD0 func_0017A190 func_0017A5D0
func_0017E468 func_001A46E0 func_00114528 func_00117270 func_0011ABF8 func_0011F710 func_001A4488 func_00114580
func_00114770 func_001148F8 func_0017E518 func_0011B468

- m2c's extra call arguments are often leftover registers: when a vcall/call has `move a2,a0` style copies the
  original never sets (e.g. a1/a2 not written before `jalr`), call with fewer args (func_00175560, func_001820D0,
  func_00183760), or declare an alias with the real arity: `void f_2(void*, int) __asm__("func_00172A00");`.
  Callers that pass nothing also need an alias (func_0011B468_v).
- A vcall whose result type is `int` (return it) flips the vt/fn register pair; a void call keeps the first
  pair (func_00183760 returns `int`, func_001820D0 stays `void` with `if (!self) return 0;` first).
- Store runs: `unk44 = 0; unk48 = 0;` came out as 0x48 first (func_001148F8), as in t_12D990.

Given up (A7, part 2):
- func_00182020: s0/s1 swap and beqzl; func_00182078, func_00197FC8: pooled new, the original loads D_003689E8
  (`lui a2`/`lw`) before building D_003670F0 (ours the other way, volatile and a local did not help)
- func_00120C08: original has an extra nop between `lw` and `beqz` in the wait loop; 3 tries
- func_001A42E0: bitfield word updates, register order; func_001822F0 (alloc arg order a2,a3,a1)
- func_0011DDA8, func_0011E9E0 (handwritten), func_001708F8 (pcpyud), func_00154030 (unaligned struct), func_00174C48

A7 pass, part 3. Matched 20: func_00127AB0 func_0011C030 func_00128160 func_001281C0 func_00157318 func_0016AFE0
func_00119D40 func_0011C248 func_00197398 func_0011F478 func_00157100 func_00157190 func_0016C0F8 func_0017E4B8
func_001A2868 func_001A3178 func_0011AD10 func_0011E868 func_001279F8 func_001283F8

- Base-ctor calls (`jal; move s0,a0` in the delay slot) pass `this`: `func_001CE7A8(self)`. Without the argument the
  constant load lands in v0 instead of v1 (func_0016C0F8).
- Two vcalls through the same `self->vt` reload it after the first call: write `self->unk20->...` twice, not a
  shared local (func_00157100).
- `*(int*)((i * 4 + (char*)D) + j * 0x28)` (table + two indexes) gives the original `s0 += ...` chain
  (func_001A2868); `D[i + j*10]` and the `(int)D` forms do not.
- if/else on a global: `if (!(b & 3)) { G = 1; } else { G = 0; }` gives the bnezl + gp store layout (func_00157318).

Given up (A7, part 3): func_00127948 (return-0 branch order), func_0011DE80 (wait loop nops), func_0017D580
(andi scheduled into the beqz slot), func_00181BD8 (constant lands in v0), func_001A0D38 (unrolled 4x loop in a
file without -funroll-loops), func_00113D20/func_00113D88 (alloc arg order).

A7 pass, part 4. Matched 17: func_00112CE0 func_00112D48 func_0014EBE8 func_0015ADF8 func_00167D70 func_0019F538
func_0011EAD8 func_00168170 func_00168708 func_00169A70 func_00169E70 func_0016A6A8 func_0016ABA0 func_0019ED10
func_00183678 func_00183840 func_00174DC8

- `bnel` list walk (func_0019F538): write the equal case first (`if (p->k == a) {...} else p = p->next;`).
- A constant that gcc loads after `ori` of a mask: hold the global address in a local before the mask
  (`void* d = D_X; u32 t = x & MASK; ...; self->f = d;`) to get its `lui` scheduled first (func_00183840).
- Address of a handwritten function + offset (`func_0011E9E0 + 0x28`) works with `extern u8 func_0011E9E0[]`.
- Call arguments that m2c shows as `sp`/extra registers are real stack temporaries only when the asm stores to them
  before the call; `int t[2]` then pass `t` (func_0015ADF8, call takes (x, t) only).

Given up (A7, part 4): func_00162F48 (second constant must come through a1, ours goes v1 then move),
func_0011BD30 (constant -1 and D lui order/regs, 7 variants), func_00128338 (beqz/beqzl in an else-if chain),
func_001A9A98 (list unlink: gcc rewrites self as p after `p == self`, original keeps a0), func_0011FB70,
func_0011FBE0, func_0011FC50, func_0011FCC0 (struct return/stack args to func_00120A40), func_00182110.

A7 pass, part 5. Matched 19: func_00184188 func_001842B0 func_001290C8 func_0019EC10 func_00118290 func_0017F478
func_001870E0 func_00187158 func_0019D038 func_00113FB8 func_0011A300 func_0014E560 func_0011F768 func_00113F38
func_0017D5E0 func_001164F8 func_001280E0 func_0014DDB0 func_0014E4E0

- Stack/register arguments: count the incoming registers, not m2c's argument list (func_001842B0 has 7 parameters
  because the callee gets a2,a3,t0,t1,t2 and a1 is skipped).
- `if (f(A)) *o = 1; else if (f(B)) *o = 2; else if (f(C)) *o = 3;` shares one `sw` tail like the original (func_0014DDB0).
- Keep `&self->field` in a local when the original holds it in an s-register across calls (`int* pc = &self->unkC;`,
  func_0017D5E0); hoist a format-string pointer into a local (`char* fmt = D_X;`) to get the lui before the branch
  (func_0014E4E0).
- `s16`/`int` array `+ i` with `SA127_Z** base = self->unk28; base + i` gives `addiu v0,s1,0x28; addu` (func_001290C8).
- Callee declared returning `int` (result unused) moves the loop test register v0 -> v1 (func_0019D038).
- Store runs: gcc emits the last source store first; to get [4C, 0, 4, 8] write [0, 4, 8, 4C] (func_0011A300).

Given up (A7, part 5): func_0019EAA0 (DMA packet builder: p lands in a2 not v1), func_001A9A98/func_001A9B08 (list
unlink and walk, equivalence copy-prop and loop nop), func_001198F0 (result copied to a1 before the array store),
func_00157420 (byte stores scheduled differently), func_00175F40/func_00118308/func_00161CC8/func_00161FF8
(address-taken locals on the stack), func_0016BE38/func_0016BEB0 (128-bit lanes).

A7 pass, part 6. Matched 12: func_00182220 func_001292D0 func_0011A498 func_0011EF78 func_0011DF78 func_00120598
func_00123040 func_0014C7E0 func_00134FB0 func_00152F78 func_0011AB60 (+ func_0011EF78's file declarations)

- vcall with the entry address kept in a register: `VE* e = &v->unkC8; e->unk4((char*)o + e->unk0, ...)` (func_00152F78).
- `if (!A || !B || !(o = f(...))) return 0;` reproduces the shared `return 0` block (func_0011EF78).
- Lock/unlock pairs (`func_002F3B80`/`BD0`) around `--G` and `--self->f` (func_0011DCD8): the original re-reads the
  volatile outside the delay slot and uses `lui at; sw` for the global; not reproduced (GP_DATA is file-wide).

Given up (A7, part 6): func_00123310 (struct copy: a3/t0 register assignment), func_0019EB70 (64-byte word copy,
ours uses ldl/ldr for every struct form), func_00120710 (the pointer to the 2-entry table is kept in s regs from the
prologue), func_0011DC48 (`li 1` after the `lw` of the flags), func_0017D4F0/func_00178880 (end-of-list address
hoisted before the base-class call), func_001A9C68 (float stores scheduled 2 slots earlier in ours).

A7 pass, part 7. Matched 14: func_0016AF18 func_00150358 func_0013C550 func_00187E58 func_00188478 func_0015AD38
func_0012EE88 func_0016C8F8 func_001841F8 func_00122558 func_0015A5A0 func_0012EB68 func_0012E9E0 func_001A9DA8

- A base-ctor/callee declared `void` -> `void*` (result ignored) moves the following constant load from v0 to v1
  (func_00187E58); same effect as passing `this` in func_0016C0F8.
- When a branch result is stored through the same field in both arms (`self->f = a(); ... else self->f = b();`) the
  original keeps both stores and reloads the field afterwards (func_0012EB68, func_0012E9E0); the arm that tests
  `!= 0` goes first.
- Float arguments evaluated before the integer ones: declare the callee with the floats first and pass them first
  (func_0012EE88, `func_001277C0(float, float, int...)`).
- `if (call() != 0) { ...store... } else { vcall }` order matters for the `beqzl` layout (func_0015A5A0).

Given up (A7, part 7): func_00143BC0 (s1/s2 swap of loop counter and self), func_0014C870 (`-1 < x` compare kept in
a register), func_00129710 (returns not merged in the original), func_00112DB0 (hi part of a symbol reused),
func_00186E40/func_00187898 (second bit-test of the flags is re-evaluated in the original), func_0015B168
(`move a1,zero` vs `move a0,s0` delay-slot choice).

A7 pass, part 8. Matched 5: func_001A92D0 func_0013D730 func_0011D720 func_00185068 func_0012EA80
(A7 pass total: 148 functions in parts 1-8)

- Float globals read with `lui` + `lwc1 %lo(v0)` (not `$gp`, not the `$at` macro form): declare `extern float D_X[];`
  and read `D_X[0]` (func_001A92D0; same trick as func_0011ED40).
- Signed flag fields: `(self->unk4 >> 2) & 1` needs `int unk4` (an `unsigned` field gives `srl`, func_00185068).
- Assign a bool temp to the saved copy only after the call (`self->f = g(..., b); h = b;`) to keep `sltu v0` /
  `move s0,v0` (func_0012EA80).

Given up (A7, part 8): func_0018AD80 (store order / mask register, bitfield variants), func_0011BC38 (register
reuse of the first subtraction), func_00182870/func_001287F0 (prologue `sd` before `lui`), func_00163868/
func_00163938 (delay-slot `lw` hoist), func_0011F7E0 (assembler nops), func_001681E0 family (6 functions: random
float table fill; floats match, ours swaps s0/s1 and the order of the two argument loads).

A8 pass, part 1. Matched 12: func_0011A988 func_0011EF20 func_0017A6D8 func_0014F750 func_001A1118 func_001574C0
func_001284B0 func_0011A7C0 func_00119CC0 func_00119DD8 func_00113EA8 func_0014E9E8

- vcall where m2c shows extra trailing operands (`fn(this+delta, p, fn)`): they are register residue; call with the
  real arguments only (func_0011A988, func_0014E9E8).
- `if (x) return 0; if (!y || !(p = f(..))) return 0;` merges the zero returns (func_0011EF20); a callee that
  receives an untouched `a0` needs the caller to keep that argument as a parameter (`f(int a)`, `g(a, x)`).
- Global load before a store keeps the store in the call's delay slot: `int g = D[0]; self->f = r; call(g);`
  gives lui/lw before `jal` and `sw` in the slot (func_00119CC0).
- Masks written as `0xFFFFFFF0u` (not `~0xF`) give `lui/ori`; `(u32)D_X & 0xFFFFFFF0u` on a symbol address
  (func_00119DD8).
- Dead local struct stores: write them in memory order [0,1,2,3] to get the original [3,0,1,2] (func_00113EA8).
- Scalar `extern T* D;` re-reads with lui+lw after a call; `extern T* D[]` hoists the lui into an s-register.

Given up (A8, part 1): func_0014E878/func_0014E8E0 (inlined list-first with branch form), func_001759F8 (switch
matches except a nop in the delay slot of the second compare), func_00164AA0 (u64 flag lands in a1 not a2),
func_00183798 (copy ctor: pointer moved to a1 after alloc), func_0011FD38 (move s3,a1 scheduled before the load),
func_001A41D0 (n and r share a1 in the original), func_00179360 (stack slot store before vcall), func_0017B678
(unrolled busy loop), func_00179518 (min.s).

A8 pass, part 2. Matched 6: func_0010CBA0 func_0010CC30 func_0010CCC0 func_0011E7D8 func_00163380 (+ part 1 total 12)

- Rows of float/zero stores: the compiler reorders the last stores of a row; brute-force the source order of the
  row (all permutations of 3 lines) instead of reasoning (`agentA8s/perm.py` style: compile each, look for MATCH).
- sin/cos callees `float f()` called with the caller's untouched `f12`: declare them without parameters.
- Compute `d = D + x; f = a & ~1; g = b & ~M;` into temporaries and store afterwards to get loads before stores
  (func_00163380).
- A void callee whose result the original ignores: declaring it `void*` moves a following constant load v0 -> v1
  (func_0011E7D8).

Given up (A8, part 2): func_001180D8 (switch: case 0 returns the leftover slti value, tried 6 layouts),
func_001234B0 (div.s before jal with nop in the slot), func_00162920 (6-byte struct copy: src/dst register choice),
func_0011F3E8 (do-while with two nops), func_0010C... none else.

A8 pass, part 3. Matched 6: func_001235E0 func_0011BF98 func_001167E0 func_0011C310 func_00119098 func_00161D40

- Stack iterator on `It_161` (t_161580) works for list walks; a by-value 4-byte struct argument shows as two
  lwl/lwr copies: `B4 t1 = *a; O* o = *pp; B4 t2 = t1; fn(..., &t2)` (func_00161D40).
- `for (n = head; n; n = n->next)` gives the jump-to-test layout; computing `p = n + t` only inside the branch
  that uses it fixes register choice (func_0011BF98). Declaring strcpy as returning `char*` moves a later
  address temp from v0 to v1 (func_001167E0).
- `int slot = &D[idx];` taken before the allocation call keeps the address in an s-register (func_0011C310).

Given up (A8, part 3): func_00188BB8 (the 64-bit constant is kept in s2 in the original; ours rematerializes),
func_00182DB0 (a3/a0 argument setup order around a branch), func_001144A0 (iterator with vptr reset on the stack;
x/v share one register in the original, 6 variants), func_00114340/func_0011AC50 same family, not attempted.

A8 pass, part 4. Matched 6: func_00161DD8 func_0013DCA8 func_0013CED0 func_0014EC58 func_00197E30 (+ func_00161D40 listed above)

- `if (a) { if (b) {...; return 1;} } return 0;` (nested, separate temporaries `a`, `n = a + f()`) keeps two compares
  instead of the merged unsigned range check (func_0013DCA8).
- One `int v` declared at function top and reused in different branches ties registers like the original
  (func_0013CED0); `int idx = D; int* c = &base[idx]; ... D_00381C50 + idx * 4 + n * 8` (func_00197E30).
- A scalar `extern int D_X;` + `int* base = &D_X;` + GP_DATA gives `addiu v,gp,%gp_rel` for a gp array.

Given up (A8, part 4): func_00120628 (partly unrolled 2-entry search), func_0019ED90 (call argument order + xori),
func_001A1078 (entry pointer copied to the saved register), func_00186EE8/F90/87038 family (second flag load
register), func_0017A630 (case order matched; `move a0,a2` hoisted into the first delay slot).

A8 pass, part 5. Matched 3: func_001184C0 func_00156ED0 func_0016BBC0

- 64-bit flag word tests must be a `u64` bitfield (`struct { u64 f0:1; u64 f1:63; }`): `(long & 1)` adds dsll32/dsra32.
  Last test of an unrolled-by-hand chain is the positive form `if (f0) { n += 5; p += 0x6E0; if (n >= 0x1E) return 0; continue; }`.
- Intrusive list walk with `-0xC`: loop variable copy (`cur = o; ...; o = nx;`) and the vcall without the m2c extra
  third operand (func_0016BBC0).

Given up (A8, part 5): func_00117AA0 / func_001171C0 / func_00117B50 (stack iterator with vptr reset: the original
stores `it.cur` through a register copy of &it), func_0015B0B8 (loop without rotation, entry jump with the hoisted
global load in its delay slot), func_001200D0 (volatile counters: reread register v0/v1 swapped).

A8 pass, part 6. Matched 8: func_0019B6B8 func_001191B0 func_00119270 func_00119330 func_0012FAC8 func_00188060
func_001824D8 func_0011BA48

- `if (cmp >= 0) { f(loc); return 0; } vcall...; f(loc); return r;` (early-return form) gives `bltzl` like the
  original (func_001191B0 family); the vcall index is `o->unk98[n]` with n = 6/7/8.
- Reuse a parameter for a later temporary (`n = sz + a->unkC;`) to keep the original saved-register count
  (func_0011BA48); `& 0xFFFFFFFCu` for the lui/ori mask.
- Swap the arms of `if (a != 0) {...} else {...}` to match which side is the fall-through (func_00188060).
- Callee `int f(void*)` instead of `void` (result unused) moves a byte load v0 -> v1 (func_001824D8); duplicated
  trailing call in both arms is cross-jumped by gcc.

Given up (A8, part 6): func_00159790 (scheduling of a 4-lane texel fetch), func_00136C48 (arg setup scheduling),
func_00119E60 (hi/lo hoisting of the format symbols), func_00197EE8 (address CSE across the loop),
func_00113308/func_0013D048/func_0014D7C8/func_0016DFB8 (hash remove: key copied into a3 first), func_00174D08
(0.0f arg not CSE'd with the compare constant), func_0019E1E8 (0x34000000 built through mtc1/mfc1).

A9 pass, part 1. Matched 4: operator_new func_00189878 func_0017CFB8 func_00176C78

- Argument evaluation order follows the prototype's parameter order: when the original loads the float arg
  (`lwc1 f12`) before/after the int args, reorder the callee prototype (`f(void*, float, int)`, call with the same
  order) instead of fighting the scheduler (func_0017CFB8, func_00176C78). Registers are unaffected.
- Compare chain `switch (key)` on hash constants (no jump table) compiles directly to the beq chain.
- Four independent float->int casts: brute-force the statement order (func_00189878 needed x,y,w,h).
- `scripts`-less permutation search (24 perms of 4 lines, 1 s each) is cheap; 720 perms is ~12 min.

Given up (A9): func_001145D8 (store order of two inline list nodes, 5-line perms), func_0014CF50 (hash lookup,
key kept on the stack + copy in a0, 4 tries), func_001233A8 (div.s before jal, nop in slot), func_0017F4F0 (float
reg numbering fi/fj/q), func_00188E68 (n/f/g register roles v1/v0/a0, 5 tries), func_00176108 (`li v0,1` vs
`sw` in the delay slot of the join), func_001395D8 (store/load scheduling, 720 perms), func_00172D00/D80 (stack
iterator), func_001204D8/func_00120010/func_0011FF58 (scoped lock/trace object on the stack).

A9 pass, part 2. Matched 4: func_00128220 func_001565D0 func_0014ACB8 func_0017A060

- A hash constant compared against a loaded value (`x != 0xF649D637`) swaps the v1/a0 choice; keep the constant
  in a local (`u32 kk = 0xF649D637; ... x != kk`) to get the original register pair (func_0017A060).
- A shared tail call reached from two switch cases (`goto call`): set every argument in both arms
  (`pp = p; asm("" : "+r"(pp))`) or the arg move lands in the delay slot (func_0017A060).
- `(f(...) ^ 1) != 0` with an int-returning callee reproduces the `xori`+branch (func_00128220).
- Vectors read by a script helper: `struct {float x,y,z,w;}` locals at 0x10 strides (func_0014ACB8).

Given up (A9, part 2): func_00176020 + func_00176880/B58/78D0/78FF0 family (script-param chain lookup; all
match except `addiu a2,sp,4` where ours emits `ori a2,sp,4`; tried struct/array/scalar/s16/float locals),
func_0013B8F8 (float reg numbering with -3276.75 hidden through asm), func_00137470 (original has 2 extra nops
in a 2-instruction busy-wait loop), func_0015CFC8 (stack list iterator).

A9 pass, part 3. Matched 1: func_0012B970 (small table filled through a moving pointer `d += 1; *d = ..; d += 1; d[0]=..; d[1]=..`).

Given up (A9, part 3): func_0012EC20 (switch on hashes: layout matches [5F49][AF2F][C683] but epilogue/likely-branch
shape differs), func_0019ED90 (needs `xori` after slt: forced with asm, but x/y/z registers end up a0 instead of v0).

A9 pass, part 4. Matched 1: func_001849A0 (flag word via `int f` so `sra` not `srl`).

- Reusing one `int t` for the first inline getter result and the reloaded flag word (`t = Get(self); if (t) { t = self->unk4; ... }`)
  gives the original `beqz` + `lw` in the delay slot and the shared register (func_001874E0 first half).

Given up (A9, part 4): func_001874E0 (and the 187708/877D0 siblings): second half only differs by the delay
slot of the `beqz a0` (ours puts `move v0,zero` there; original `sra`), 5 variants; func_00122A10 (flat compare
ladder, original splits the shared store block; 4 layouts).

A9 pass, part 5. Matched 2: func_00127858 func_001575C0

- Range checks on floats with four nested `if`s and `return a <= v && v <= b;` come out right (func_00127858).
- `void` vcall at the end that the original treats as value-returning: declare the slot `int (*fn)(...)` and
  `return` it; also load the vtable pointer after the preceding call and before the store (func_001575C0).

Given up (A9, part 5): func_0015AE88 (hash-bucket insert; saved regs right after `int h2 = h; asm(h)`, but
v0/v1 and a0/a1 of the mask expression swapped, 6 variants), func_00187650 (three inline getters, register roles).

A9 pass, part 6: no new matches. func_00122940 (5-entry compare ladder): everything matches except the final
`sw %gp_rel` not landing in the `b` delay slot (ours fills it with the epilogue `ld s0`); `asm("" : "+r"(s))`
on the first call result fixed the s0/s1 roles. GP_DATA(D_00368738) is needed for the gp store.

## A10 pass (mid-size 0x100-0x400)

Given up (A10): func_00117E10 (inner `switch (u16)` with case 0xFFFF/0xFFF9 folds to one compare; store order of F8/1C/24 differs; 3 tries)
- func_0012C0B0: all matches except v0/v1 of the two li (2, 0x45) feeding the sh/sb of a stack message struct; 11 tries
Matched (A10) t_174C20: func_00174E68 (0x100, float wrap loop)
Matched (A10) t_11D000: func_0011E3B8 (0x130; 4-wide table slot search as a for loop with 4 ifs; D_00368C00 volatile + int return)
Matched (A10) t_133A98: func_00133FE0 (0x144; 8 relocated offsets, -1 stays +1; loads into temps then natural-order stores)
Matched (A10) t_16E670: func_0016EEC0 (jtbl switch, 5 cases)
Matched (A10) t_19F538: func_001A1028 func_001A1180 (jtbl switches; byte-offset table index)
Matched (A10) t_19F538: func_001A11D8 (0x13c; table search + switch)
Matched (A10) t_114DC8: func_00116748 (jtbl digit switch)
Matched (A10) t_116E38: func_00117030 func_00117D40 (jtbl; explicit 'case 0: return;' keeps the table starting at 0)
- func_0019B9C8 (jtbl, tag switch with stack push/pop): all matches except D_003732AC load not landing in the beqz delay slot / n in a3 not a0; needs 'case 7: return 0' and '(h<<4)+0x10' in a local to get the table and operand order; 9 tries
- func_00116F90, func_00116EE58(0x64): start with junk (addiu sp / nop) = split heads
- func_001A4D20 (DMA packet writer, long arg): matches except v0/v1 roles of hi-word and li 0x42 (and the same for the two long loads); two-pointer form p/q/r with stores [hi,lo,const] needed; 14 tries
- func_00139840: float adjust with sp0/sp4 passed by address; original reloads sp0/sp4 after the first pair of stores (only reproducible with asm memory barrier, then f-reg numbering of the loads differs); 11 tries
- func_001881A0: alloc+ctor then inline flag getters; matches except the tail (original shares 'move v0,v1; sw' and reloads the flag word); 11 variants incl. int t reuse, goto, inline Get
- func_00189938 (5x unrolled alloc+ctor+list push, 2 iterations): original puts 'sw D_00369DB4' in the Heap_Alloc jal delay slot after the D_00368A38 lui/lw; ours puts the gp load of D_00368A38 there; volatile on either, reorder, comma args tried; 7 tries
Matched (A10) t_157100: func_001577B8 (0x150; 8 vcalls via an inline helper; last vcall declared int-returning)
Matched (A10) t_157100: func_00157908 (0x150; texture-ish buffer alloc with two vcalls)
- func_00119B38: chain of operator_new+ctor+attach; original frame is 0x30 (0x20 bytes of unused locals) and the two-way size branch shares one call with a nop delay slot; ours has frame 0x10; 5 tries
Matched (A10) t_116E38: func_00118168 (0x128; ctor with list head node + three memsets; ctor declared returning void*)
Matched (A10) t_1816C0: func_001825E0 (0x1b8; script struct builder, list walk with nor/movz next)
Matched (A10) t_17D4D8: func_0017DB68 (0x110; ref-pointer swap + draw call with float args)
- func_00134E40: globals bookkeeping + vcall; original keeps D_0036F658 in t3 (loaded first) and a3->s0/a4->s3, a store lands in the jal delay slot; ours swaps s0/s3 and the g reg; 4 tries
- func_00115660: int-array tree unlink via three global arrays (cast int to int*); body matches, differs in the first branch (original keeps y in v0 and r in t0 via bne delay slot 'move t0,v0') and a nop before the do-while; 6 tries
- func_00156CB8: body matches except the hazard nop before div.s after mul.s (SN assembler; same as func_00122FF8) and bc1fl layout; 4 tries. Note: functions with div.s right after another FP op will always miss that nop
- func_0018DD68 (family func_0018FD08/001928E0/00192EE0/001935F8/001940C8/00194C18/00198040: ctor = base ctor, lookup via func_0022B0D0 + vcall at +0x34[2], flag-word getter, store to +0x2F8/0x308): same blocker as func_001881A0; the original recomputes (flags>>2)&1 in the second test (no CSE) and keeps the flag copy in v1, shares the final store through 'move v0,v1'; inline getters, goto form, flag local all tried (7); best variant 0x114 vs 0x11c bytes
Matched (A10) t_11AEB0: func_0011BB28 (0x110; error path kept out of line with goto err at the end; compare as p+a->unk8 != b)
- func_00187F50: loop with alloc+ctor and flag set; as a for loop the structure matches; remaining: ours loads n->unk4 before the 'sh n->unkE' store and keeps the list ptr in v1 then 'move a2,v1' (original loads a2 directly); 12 tries
Matched (A10) t_152E18: func_00153C28 (0x154; 12x unrolled by hand do-while, cvt.w.s via (s16) cast)
Matched (A10) t_152E18: func_00153AB0 (0x178; sibling of func_00153C28 with two s16 stores)
- func_00139D50: 4-byte color compare + copies through one stack temp; original does lbu/sb pairs (no load grouping) so the temp is probably a class with copy ctor/operator= (not tried); plain struct copies group the loads; 5 tries
Matched (A10) t_14C740: func_0014E290 (0x1dc; init sequence with profiler markers func_0011A558/568; 1.3333334f literal inline)

## A11 pass (jtbl / u128 / mid-size)

Matched (A11) t_112D48: func_001135A0 (jtbl, toupper with accents: explicit negative case values, c - 0x20 group first)
Matched (A11) t_118E40: func_00119610 (jtbl 63 entries, every default index its own case; callees via int-returning asm aliases so v0 passes through)
- func_0019E978 (jtbl, 0x128): everything matches except `dsrl` of the flag byte for the 0x60 branch (ours `srl`; u64 variants add dsll32/dsra32 or daddiu); ~25 tries. Needed: `if (dc >= d8) {simple} else {div}` order, `dc` reused as the movz target, `dc * q`, case 74 `tail:` label with goto from 80/81
- func_0011F5C0 (jtbl, 0x150): switch layout fine but the original keeps nops in many branch delay slots and a dead volatile-less `lw 0x40` in case 6 (dropped by gcc); 3 tries
Reverted (A11) t_12B970: func_0012BF38 (jtbl float-compare table; all matches except the c.eq.s hazard nop, which the original places after the shared tail label and gas before it; only fixable with `asm("nop")`, which is not allowed)
Matched (A11) t_1210C8: func_00122778 (jtbl, key-code to byte encoder; u16 value masked once before the sign test; unused jtbl indexes as explicit cases + default continue)
Matched (A11) t_1277C0: func_00128528 (jtbl stream deserializer: memcpy func_0030A2F4 declared returning void* moves the *pp temp to v1; locals declared at function scope in order f,i4,u128 a1,a2,b1,b2,i5,i6 give the distinct stack slots; 16-byte locals as TI typedef)
Matched (A11) t_14A6B0: func_0014B260 (array alloc + insert into the global hash table D_00377FC0; pooled node func_0011C3A8(0); write the occupied case first and store key before value in the free slot to get the likely-branch layout)
Matched (A11) t_118E40: func_0011AA58 (ctor, counterpart of dtor func_0011AB60; pointer temps per 12-byte block, store unk4 before unk8 to get [8,4]; m2c's 3-arg call to func_0011A8F8 is residue)
- func_00120938 (0x108, 16x6 entry init loop): the original keeps every sub-entry address `p+0x14k` in its own register with a hoisted loop bound and a nop before the loop; our unroll (-funroll-loops, array form) or by-hand unroll folds the offsets into the stores (size 0x104/0xf8); 8 tries
- func_0014B260/func_0011AA58 matched (see A11 below)
- func_0019FE18 (0x98, sq-ra prologue): body (call + 0x100 byte u128 struct copy) matches but saves s0/s1/ra with sq (open question in toolchain.md); skipped
- func_0011C130 (pool ctor, 0x118): all but the order/regs of the unk8*unkC product and q copies (ours mult dest a3, sum in v1 vs original v1/v0, store of unk14 uses p copy); 12 tries. Needs `P* self` param (int a + cast keeps a second copy of the pointer)
- func_0019FA28 (0x3F0, GS upload with sq-all saves), func_00159260 (0x47c jtbl), func_0013CB18/func_001147D0/func_0013B7E0: not attempted/skipped (variant getters with copy ctor, stack iterator with vptr, nops inside loop)
- func_00161BA0 (stack iterator, flag bits): all matches except n=it.cur lands in t0 instead of a2 (+8 bytes of moves); 8 tries (hoisting `all = key == K` first and `s16 i` were needed)
- func_0015AAA0 (0x138, virtual create + insert into hash table like func_0014B260): the key is held in a2 then copied (move s3,a2) in the original, ours keeps it in s1; also nop in the bnez slot; 5 tries

## A12 pass (unrolled loops / untried 0x100..0x500)

Matched (A12) t_112D48 (now `// cflags: -funroll-loops`, whole file still matches): func_00113BF8 (strncpy: `while (n != 0) { if (*s) *d++ = *s++; else *d++ = 0; n--; }`, unrolled 4x)
- func_00114C70 (CRC32 table loop, unrolled 4x): structure/unroll matches but ours copies the args into t1/t3/t0 at entry (original uses a0-a2 in place), 6 forms tried (for/while/do-while/end pointer)
Matched (A12) t_11D000 (now `// cflags: -funroll-loops`, whole file still matches): func_0011D830 (zero fill: `for (i<100) int[i]=0; for (i<200) 16-byte entry fields = 0`, unrolled 10x)
Matched (A12) t_118E40 (now `// cflags: -funroll-loops`): func_0011A170 (32 entries of 0x50 at +0x254; key at +8, flag at +0x4C; returns the entry)
- func_00119A60 (search `a[i]==key` returns a[i+1], unrolled 4x): all but the second `blez t0` zero-iteration guard (original has it on a copy t0 of n; ours elides it); 6 forms tried
Matched (A12) t_11F000 (now `// cflags: -funroll-loops`): func_0011F8D0 (search 0x10-byte entries at +0x4C by key, count at +0x14C, returns field +4), func_0011F9A8 (same, returns entry)
- func_0011FA98 (remove-by-swap-with-last on the same table, not unrolled; count volatile fits the reloads): original lays the found block before the loop and computes `i*16` at the exit while ours strength-reduces it (and `a3`=key copy); 5 forms (goto found, break) tried
Matched (A12) t_11F000: func_001208C0 (ring search over D_00415188[0x5F+1] entries of 0x14, from D_00368DA4-1 backwards; callers use alias `func_001208C0_v`; `int i = 0x5F; if (D >= 1) i = D - 1;` gives the movz; `do { if (p->k != id) {step} else return p; } while (p != e); return 0;` gives the original bnel layout)
- func_0012BF38 (retried without instruction asm): source is the old one minus `asm volatile("nop")`; size matches and everything is identical except the shared tail label sits after the hazard nop in the original (`mtc1; L: nop; c.eq.s`) and before it in ours (`mtc1; nop; L: c.eq.s`), so the three `b` targets differ by 4. Only an explicit nop gets it; left as INCLUDE_ASM.
- func_001206D0, func_00120628 (2-entry table under the DI/EI lock; fully unrolled `for (i<2)`): with `-funroll-loops` the code is the same but ours fills the `jr`/branch delay slots with the stores and the original leaves nops; volatile blocks the unroll; 4 tries
- func_00120628 (lock + 2-entry table alloc, unrolled): matches except `b .L; (nop)` -- gcc leaves the slot unfilled (`sw; b`) and our gas moves the `sw` into the slot, SN's assembler did not. Same cause as func_001206D0 and the older "last sdr/sw not in the jr/b slot" entries (func_00137E30, func_00122940, func_001224F8): a store (or load) directly before an unfilled `b`/`jr` stays in place in the original. Needs an asm_filter change (keep such slots `nop` / noreorder), not source.
Matched (A12) t_15D2E0 (now `// cflags: -funroll-loops`): func_0015D318 (allocate a free bit of D_00369E68: `for (i<16) { bit = 1<<i; if (!(D & bit)) { D |= bit; return bit; } } return 0;`, unrolled 8x)
Matched (A12) t_146580 (now `// cflags: -funroll-loops`): func_001468A8 (`v == arr[i]` over self->unk768 ints at +0x6A8; operand order v first), func_00146E78 (max of the `val` of flagged 0x18-byte entries at +0x5C8 (10 of them, unrolled 5x) compared with func_0013CFC0(ref); compare into a local before releasing the ref)
Matched (A12) t_19F538 (now `// cflags: -funroll-loops`): func_001A0D38 (`for (i<4) f(self, self + i*0x3C8, i)`; hand-unrolled calls schedule differently, the loop form matches)
Matched (A12) t_17B448 (now `// cflags: -funroll-loops`): func_0017B678 (empty busy loop `for (i = 0; i < self->unk208; i++) {}`, unrolled 4x; comparing against the field gives the `move a0,v0` copy and the guard)
Matched (A12) t_11D000: func_0011DAB0 (`do { f(); g(); } while (h(self)); return *(volatile int*)self;` -- the volatile load keeps gcc from filling the bnez slot with the epilogue `ld ra`, which is the original's `nop`)
Matched (A12) t_11D000: func_0011DE80 (wait loop `while (((volatile S*)self)->unk30 < 0) {...}` + `return` of the volatile field: this is what leaves the original's `nop` in every delay slot of a wait loop; D_00368BF8 is a plain u64)
- QUIRK: nops in delay slots of a polling/wait loop = the polled field is volatile (cast the whole struct pointer to `volatile S*`; a `volatile int*` local changes the loop shape).
Matched (A12) t_11F000: func_0011F3E8 (sprintf into a 0x80 buf, then `do {} while (!f(out, buf))` polling with a 0x30-byte out struct declared first (`int out[12]`); the two nops are the short-loop padding)
- func_00120C08 (wait loop on a volatile field): matches except a `nop` between the loop's `lw` and `beqz` in the original (SN assembler load-delay nop in a reorder-mode region after a volatile load); no source form found, 3 tries
- func_00137470: source found (alloc 8 bytes, DI-less poll `while (func_0028C200(t)) {}`); only diff is the poll loop: original `jal; move; nop; nop; bnez; nop`, ours `jal; move; nop; bnez; nop`. asm_filter pads 2 nops, but when the loop branch is followed by a `.set noreorder` block gas moves the last pad nop into the branch delay slot (reproduced with a 12-line .s), so one nop is lost (also the nop before the loop is only the .p2align). Needs an asm_filter fix (pad 3 in that case); left as INCLUDE_ASM. Same effect likely behind func_0017B678-style loops that are not followed by a noreorder block.
- func_0012D530 (sorted insert into the pointer array at +0x40, count at +0x58; `k = e->unkC` hoisted into a local, shift loop `for (j = n; j > i; j--) a[j] = a[j-1]` unrolled 4x): MATCHES with `// cflags: -funroll-loops`, but that flag deletes the empty delay loops of func_0012D1A0 (and func_0012F8D0-style ones) in the same file, so t_12B970.cpp mixes an unrolled object (0x12D530..) and a plain one. Left as INCLUDE_ASM: needs the file split at 0x12D530 (separate cflags). Source (verified MATCH): struct E{pad[0xC]; int unkC}, S{pad[0x40]; E* unk40[6]; int unk58}; `int k = e->unkC; for (i=0;i<self->unk58;i++) if (self->unk40[i]->unkC < k) { for (j = self->unk58; j > i; j--) self->unk40[j] = self->unk40[j-1]; break; } self->unk40[i] = e; self->unk58++;`
- func_00175460 (+ identical func_00175650, func_00175830; vtable-setting dtor that removes every node whose value == self from a list with a stack-iterator `first = erase(first)` loop): frame size/slots match (7 stack objects: Pred{char,char,int self} at 0, end It at 0x10, first It 0x20, erase return temp 0x30, then 3 temporaries 0x40/0x50/0x60) using `It{int;N* cur}` with copy ctor/operator=, an inline `It erase(It pos)` and `first = erase(first)`; remaining diff is the order of the three temp stores (original: 0x44=cur, 0x64=cur, 0x54=cur, 0x44=next; ours 0x54, 0x64, 0x44 or similar) and the beql/bnel layout; ~14 variants (permutation scripts over temp declaration order / roles). Solving one solves three.
- func_0019B448 (32-entry bit-spread table + 3 pool allocs): body matches except the original keeps the constant 1 in a register (`li a2,1` before the loop, `sll a0,a2,16`, `or a0,a0,a2`) and uses branches, ours folds 1<<n into constants and if-converts (movn); `int one = 1`, register, u32/u8/s16/long variants all fold; 6 tries
- func_00113420: split head (3 junk `addiu sp` + nop before alabel func_00113438), skipped
- func_001137E8 (escape-sequence tokenizer: `\_` -> space, `\n`, `^`, newline, NUL; compare chain on the char): both a switch and a goto form reproduce the structure, but the original uses two registers for 0x20 (one for the `== ' '` compare, `li t3,32` for the `\_` store) while ours CSEs them, and some blocks land in a different order; 3 tries

## A12 VU0 pass
Matched (A12) t_10EBD8: func_0010F6D8 (vadd) func_0010F6F0 (vsub) func_0010F708 (vector * scalar; `mfc1` temp is the same register as the 128-bit result: one `"=&r"(r)` operand) func_0010F720 (dot3 returning float: `"=f"` output + `"=&r"` temp for qmfc2/mtc1)
Matched (A12) t_110D00: func_00112CC8 (xyz copy via vmove; asm volatile with memory clobber, void). func_00179130/func_0017B448/func_0017F268/func_00131008 are split tails (start at sqc2 / addiu sp), skipped.
- func_0018BE88 (vsub of two vectors into a stack temp + 3 float copies + branch): body matches with two asm volatile blocks (lqc2 x2 / vsub+sqc2 ="m"(d)) and a local for the first store pointer; only left: the original hoists `li a0,2` to the top (compare constant) and p lands in v1; 8 tries. func_0018C368/func_00156AB0/func_001728A0/func_001729C8/func_0010D508/func_001A4698: (almost) all VU0 or pextlw constants, skipped.
Matched (A12) t_16A2F0: func_0016AD20 (qsort comparator by squared distance to the camera: one asm block for the lqc2..qmfc2/mtc1 run, temp int tied to the camera pointer with a "0" constraint so qmfc2 uses v0 like the original, 2nd asm `mtc1`; the `mtc1 $0,$f2` zero stays compiler-placed)
- func_00163750 (+ func_00163868/163938 not looked at): LOD-style interpolation with one VU block (squared distance to camera): the VU asm blocks (lqc2 pair + vsub / vmul..mtc1) and the float math match instruction for instruction; left: the original keeps the 2nd argument in a stack slot (sw a1,0(sp) at entry, `lw v0,0(sp)` reloaded at every exit even before any call, result of an inline min via two stack refs + movn) while ours forwards it from a1 at the first exit; volatile version changes the layout; 8 tries

## A13 pass (VU0 candidates, then untried plain)

Matched (A13) t_16A2F0: func_0016B1B8 (intrusive list search by key at +0x1D4; inline `Get` (nor/movz sentinel -> 0) and `Cast` (`m ? m-0xC : 0`) as two separate inline helpers: `Cast(Get(x))` reproduces the `move v0,v1` copy before the null test)
Matched (A13) t_118E40: Heap_Free (lock pair func_001187F8/func_00118820 around index lookup func_00118BD8 + pool free via D_00375600[i]; func_0011C2E8 alias `_i` taking the pool index/pointer)
- func_0017F630 (vector normalize, vu0:33%): asm matches (the two `nop`s before `vrsqrt` belong to the VU0 sequence, they are in every vrsqrt block of the game) but the original schedules `ld ra` between the `vmul` and the `vaddy`; ours puts it after `sqc2` (barrier effect of the asm statements); ~10 asm variants
- func_00110188, func_0016BCE8, func_001A4050, func_00123F80 (c1 sqrt): not matchable (vf register spill around a call / pextlw packing / c1)
Matched (A13) t_1A37A8: func_001A4258 (highest set bit of the byte at +1 via `for (v = 8; v; v >>= 1) if (v & b) break;`, then `switch ((int)v)` with explicit case 1: gives slti)
Matched (A13) t_1277C0 (now `// cflags: -funroll-loops`, whole file still matches): func_00129148 (`for (i<50) a[i] = 0; b[i] = 0xFFFFFFFF;` unrolled 10x; b is u32 for lui/ori)
- Lesson: a hand-unrolled-looking loop with count li N-1 / bgez / addiu -K is -funroll-loops output; test the plain loop with the flag in a scratch copy of the file before fighting the prologue order.
Matched (A13) t_159258 (now `// cflags: -funroll-loops`, whole file still matches): func_00159858 (strided copy of one word `*dst = *src; dst += stride`, unrolled 4x with the Duff-style remainder)
- func_00175750 (pointer-to-member call `(o->*pmf)()`, virtual-capable: `struct O { virtual int vf(); }` makes gcc emit the idx/delta lookup): everything matches except `move a3,zero` scheduled before the `sd ra` and the 64-bit vtable entry in t0 instead of v0 (the original keeps a1/a2/a3 live to the call); 4 tries

## A14 pass (VU0 candidates, jtbl, plain)

Most vu0/jtbl candidates are split heads/tails (junk `addiu sp`/`sqc2` first, e.g. func_001288F8 func_0019E020 func_0016D0D0 func_00181BB0 func_001791E0 func_0014DB30 func_0016EE58) or need `c1`/pextlw (func_0017F690 func_0018C1F8 func_0010D5C8).
- near miss: func_00170940 (lerp with VU0 blocks; one asm statement per run, `b0 = o->f[0]` loaded first; left: `li v0,1` for the unk64 store hoisted in the original, f0 load order, lqc2/add.s order); nonmatching/func_00170940.cpp. Siblings func_00171F38/func_00171708/func_0016FF60 not tried.
- near miss: func_00114660 (intrusive list dtor; goto-loop so b/flag are computed inside the retry loop; left: original keeps a second pointer copy of self+0xC in s3 for the loop (`move s3,s1`), gcc merges them); nonmatching/func_00114660.cpp.
- func_00130628 (two-element unrolled loop of lqc2/vadd, file has -funroll-loops): original is a loop of 2 bodies with i+=2; ours unrolls fully or uses extra induction registers; 6 tries.
- func_00174F70/001750B0/001751F0/00175330/func_0013D1B8: list-clear dtor with stack iterator (sp+4/sp+0x14), not attempted.
- func_0013D1B8 (same dtor family as func_00174F70 etc.): volatile stack iterators `It{int;N* cur;int;int}` x2 at sp+0/sp+0x10 match the first loop; the two list clears are an inline Clear(l) but the original keeps extra pointer copies (`move s3,v1`, end iterator copies, 3 more instructions); 5 tries, size 0x100 vs 0x10c. Tip for the family: loop-1 iterator is `volatile`.

## A15 pass (36 un-stubbed functions, then plain/jtbl 0x80..0x500)

Matched (A15): func_0011ACD8 func_0011A3B8 (t_118E40), func_0014F7E0 (t_14E7E0), func_00157168 (t_157100), func_001836F0 (t_1836E8), func_00113B28 func_00113E70 func_00114980 func_00113DF0 (t_112D48), func_00145510 (t_1443D0), func_00153080 (t_152E18), func_00121C70 (t_1210C8)
- func_00157168: a virtual call that looks like it drops args (`addu a0,a0,a3` with the delta in a3) passes its own a1/a2 through: declare `(self, int a, int b)` and call `fn(this, a, b)` and `return` it.
- func_00113B28 (printf-like varargs wrapper): `void f(int a, int b, int c, ...) { g(a, b, c, (char*)__builtin_next_arg(c) - 0x28); }` (the va pointer is the a3 save slot; `__builtin_saveregs()` emits a libcall instead).
- func_00153080: write the `!flag` branch first to get the original's fall-through order.
- near miss: func_001897C0 (ctor + `Heap_Alloc(D_00368A38[0],8,1,0)` + call; body identical but the vtable address lives in v0 and its `sw` is scheduled after `li a2`, original uses v1 and stores earlier); nonmatching/func_001897C0.cpp; 7 tries.
Matched (A15, cont.): func_00152548 (t_150DE8; local `fmt` pointer declared first), func_0015A7F8 (t_159258), func_0016BB28 (t_16A2F0; list walk: `cur = o; next = Cast(Get(cur->unk18)); o = next; if (cur) vcall; while (next)`), func_00149820 (t_148688; two locals pin the lui order), func_00121E40 (t_1210C8; the `&buf` passed is a 0x40-byte local `int buf[16]`, the "out" is buf[4])
- skipped (stack iterator): func_00160858, func_00160698, func_0012CCF8
Matched (A15, cont.): func_0017B488 (t_17B448; `self[0x82] = n; for (i<n) self[i] = i;` with the file's -funroll-loops), func_00153898 (t_152E18; array `delete[]` of 10-byte elements with a plain destructor function: no class needed, write the loop by hand: `e = (E*)((char*)a + ((int*)a)[-4]*10); if (a != e) do { e--; dtor((S*)e, 0); } while (self->unk4 != e); Heap_Free(D, (char*)self->unk4 - 0x10);` -- a member `~E() __asm__("name")` is treated as trivial and the call vanishes), func_0017DFC0 (t_17D4D8; `delete[]` of 0x1C-byte objects with a virtual dtor: base class `{pad[0xC]; virtual ~B();}` + derived `{pad[0xC];}` puts the vptr at 0xC, one-class form puts it at 0x18; the file defines `inline operator delete[]` -> Heap_Free)
- near miss: func_00186F90 (+ identical func_00187038, func_001875A8: variant getters on S_001873D8 with the Get/GetF/Get2F helpers; gcc keeps `f` in a different register: ours a1/self a2, original v1/self a1, 6 forms); nonmatching/func_00186F90.cpp
- near miss: func_001800E8 (list-free dtor: original copies the sentinel `v1` into s2 for the loop only, ours keeps it in s1; also swaps self/sentinel saves); nonmatching/func_001800E8.cpp
- func_00173FB8, func_001150D8: start with a stray `ori $2,$2,0xC23B; nop` / `daddu $2,$7,$0; nop` (head fragments of the previous function), skipped. func_00154900/func_0014DA60: loop of N stores unrolled (needs -funroll-loops) in files that cannot take the flag (t_152E18 has an empty-loop function? / t_14C740 func_0014C740 delay loops); func_0014DA60 stores via D+0x1C base = fully unrolled `for (i<16) D[i].unk18 = 0`.
- func_0019BF20, func_0019C648: constants 1 and 5 held in registers (`li s2,1; li s3,5; bne a,s3`), same quirk as func_0019B448.
Matched (A15, cont.): func_0011A230 (t_118E40; first free slot of 32 x 0x50 entries at +0x254, `for` + break), func_00124558 (t_1230D0; vector of owned objects deleted via virtual dtor vtbl call 3, one variable shared by the loop index and the later `r` makes self land in s1), func_0019F928 (t_19F538), func_00166F40 (t_1662C8)
- QUIRK: return type of a callee changes register choice: a callee declared `void*`/`int` whose result is ignored keeps v0 busy, so the compare temp goes to v1 (func_00166F40: `int func_0014EB28(void*)` matches, `void` gave v0); the opposite for func_0019F928 (`void` alias via __asm__ gave v0, the real `void*` gave v1). If only v0/v1 differ in a temp after calls, flip the callee's return type.
Matched (A15, cont.): func_00156470 (t_1550C0; second reload of the table entry in a fresh local `c` -> v1), func_00156E00 (t_1550C0, now `// cflags: -funroll-loops`, whole file still matches; ctor loop over 30 elements of 0x160: `for (i = 29; i != -1; i--) { ctor(p); p++; }` gives the `li s3,-1; bne s1,s3` counter form, `i < 30` gives a pointer-compare form)
- near miss: func_001A0380 (heap block unlink + pool bitmap clear with u64 bitfields; original materializes `li a0,1` in both ternary arms (join-block first insn copied into the `b` delay slot) and keeps the byte in v0, ours byte in a0 and `li` later); nonmatching/func_001A0380.cpp
- func_00154900 (t_152E18; 64 x func_00155640(0) stores, unrolled 8x, signature (unused, b): matches with `// cflags: -funroll-loops` and `for (i<64) D_0032A558[i] = f(0)` but that flag breaks func_00153AB0 (same file): needs the file split at 0x154900 (loop body matched; the only diff was the argument register, fixed by the (unused, b) signature, not re-run).
- func_001566B8 (+ sibling func_00156790 with key at +0x90; search of 0xB0-byte entries D_00378220[] up to D_00369BEC, unrolled 4x with the funroll file flag): body matches with the pointer form `p = D; for (; i < D_00369BEC; i++) { if (p->unk98 == name) return p; p++; }`, but the original reads the count once into v0, copies it to a3 and keeps a second `blez a3` guard + computes the table address after the `andi 3`; ours folds the guard / address earlier; 7 forms.
Matched (A15, cont.): func_001291E0 (clear 50 owned objects at +8: `for (i<50) if (a[i]) { f(a[i], 3); a[i] = 0; }`, unrolled 5x, then tail+delete), func_001297B8 (50 slots: objs at +8, keys at +0xD0; unrolled 2x) (t_1277C0)
- func_0011D220 (t_11D000; 200 entries {a,b,c,d} cleared when key matches and refcount hits 0, 2 entries per iteration): original keeps two extra induction pointers (D+4, D+0xC) and is NOT unrolled further; ours unrolls 6-8x; hand-unrolled pointer forms also unroll; 4 tries.
Matched (A15, cont.): func_0011CCC8 (t_11AEB0, now `// cflags: -funroll-loops`, whole file still matches; 100 string slots at D_00375700: free + clear those equal (strcmp-like func_0030E650 == 0), returns whether any)
- func_00119F60 (t_118E40; 6 x {func_00119990(self, h); delete obj via vtbl entry 1} then func_0011A300_3, func_00119E60, func_00119D40): body (inline Del helper) matches instruction for instruction except the original frame is 0x30 (a 32-byte unused local at sp+0..0x20) while ours is 0x10; no source form for the dead local found; nonmatching/func_00119F60.cpp
- func_001A85D8 (t_1A7A50; compact the 0x70-byte table D_0038C450 from the back: `for (i = n-1; i >= 0; i--) { e = &T[i]; if (e->unk60 && (int)e < (int)&T[9]) e->unk60 = 0; else { *e->unk0 = 0; n--; } } D = n`, needs the funroll flag which this file takes): shape right, but the original layout puts the `unk60 = 0` arm in the bnezl delay slot and merges n with i (`move a2,a3` in the first unrolled body); ours inverts the branch and keeps n--; 4 tries.
- near miss: func_0014C560 (+ identical-shape siblings func_0014D880, func_0016D138, func_0016DDD8, func_0016E490, func_0016E9C8?, func_0015B590?: hash table ctor (self, bits, storage): n = 1<<bits entries of 0xC, each built by an element ctor in a loop `for (i = n-1; i != -1; i--) { ctor(p); p++; }` (needs -funroll-loops: 4x + remainder); the code is identical to ours except register numbering: original keeps self in s4, storage in s5, the heap array in s3 and uses TWO different regs for the -1 loop bound (s5 in the Heap branch, s6 in the storage branch) so it saves s0-s6; ours shares one -1 and uses s0-s5; 4 forms incl. inline loop helper. Solving one solves ~5.); nonmatching/func_0014C560.cpp
Matched (A15, cont.): func_0011D370 (t_11D000; 200-entry search unrolled 10x, falls back to func_0011CE08(key)), func_00119730 (t_118E40; checksum switch, 13 cases returning self fields; defined through an `__asm__("func_00119730")` alias because the stub caller declares it void(void))
- func_0012D380 (t_12B970; factory switch on a checksum read by func_0027D870: 5 cases 0xCB4533FF/0x7E1940A1/0x6D941203/0xCFC5B380/0x26205DB6 -> operator_new(size) + ctor, then priority via func_0027D1F8, vcall entry 5): all bodies/arg order right, but the original's compare tree has root 0x6D941203 (left 0x26205DB6, right 0xCB4533FF with 0x7E1940A1/0xCFC5B380) while ours is the balanced tree rooted at 0x7E1940A1; adding a 6th dummy case lower than 0x26205DB6 gives the right root but emits that compare. So the original switch has one more case-node weight (a range? a case folded into default?) -- unknown; 3 tries.
Matched (A15, cont.): func_001406D8 func_001407D8 (t_13FEE0; script-command switch handlers: case order = block order of the original, `return 1` shared: `case K: if (c) { call } return 1;`, the loaded `a3->unk20` kept in a local across the call), func_001563D0 (t_1550C0; `int n = D_00369BE8; store; for (i = 0; i < n; i = i + 1, n = D_00369BE8)` puts the global load before the first store), func_00156FD8 (t_1550C0; `self->unk8 = self->unkC = 0.0f;` is what makes the original's `mtc1 $0,$f0; swc1; swc1` instead of two `sw $0`)
- QUIRK: chained assignment of float 0.0f (`a = b = 0.0f`) goes through an FPR (mtc1 + swc1); two separate `= 0.0f` stores use `sw $0`.
- func_0019F848 (t_19F538; one bubble-sort pass over the list at D_003732FC->unk4C ordering by float key then flag bit 0, swapping neighbours and fixing D_00373300 head; links unk0/unk4C): control flow and every store match (swap block, head update via goto, outer `while (swapped)` reloading owner->unk4C); only diff is the constant-1-in-a-register quirk (`li t2,1` hoisted, `move a2,t2; movz a2,zero` for the flag compare vs ours sltu) -- same family as func_0019B448 / func_0019BF20; 5 forms (ternary, if-assign, inline Less()).
Matched (A15, cont.): func_0019F450 (t_19D4E8; sorted insert into the 0x4C-linked list; the else path re-tests \`!(n->key < head->key)\` before the walk), func_00168778 func_00169AE0 func_00169EE0 (t_1682D8) func_0016A718 func_0016AC10 (t_16A2F0) (five identical particle-init functions: fill unkA0 floats at the allocated array with \`(a + (b-a) * rand(10000) * 0.0001f) * 2pi\`; \`if (n > 0) { float d = b - a; i = 0; do { ... i++; } while (i < n); }\` -- the hoisted \`sub.s\` sits after the guard)
- TIP: look for groups of byte-identical functions (same size and same m2c) -- one solution gives several matches (e.g. above; still open: the hash-table ctors func_0014C560/0014D880/0016D138/0016DDD8/0016E490, variant getters func_00186F90/00187038/001875A8).
Matched (A15, cont.): func_00113308 (t_112D48) func_0013D048 (t_13BE78) func_0014D7C8 (t_14C740) func_0016DFB8 (t_16C498): four copies of the hash table item flush (same body as HashTable_FlushItem in t_14A6B0: bucket = &buckets[*key & ((1<<bits)-1)], walk chain, unlink via func_0011C408(0, e) or clear key/val of the head, count--)
- near miss: func_0018FD08 (+ identical func_001928E0 func_00192EE0 func_001935F8 func_00194C18 func_00198040: object ctor (self, a1, a2, key, p4, p5): base ctor with pass-through a1/a2, two vtable-ish stores, stack Ref `r` built by func_0022B0D0(&r, D_0036F658, key, 1), vcall through r.p->unk34 entry at +0x10, func_00134340(&r), variant pick `(f>>2)&1 ? v->unk10->unkC (if non-null) : Get(v)`, then `self->unk300 = func_001A4770(p4, p5)`): register use matches once `key` and the vcall result share one variable (`key = 0; if (r) key = (int)call;`, 4 saved regs like the original); left: the original keeps D_0036F658 loaded before the vtable stores (lui a1 right after the base ctor), uses `a1` directly for r.p (no copy), duplicates the bit-2 test; ours is 0x104 vs 0x11c; ~9 tries. Solving it solves six. nonmatching/func_0018FD08.cpp
Matched (A16): func_00123B68 func_00123BB0 func_00123C00 func_00123C60 (t_1230D0; embedded list at self+0x14 walked with the stack iterator `It{int; N* cur}`, `It end(&head); It it(head.next); for (; it != end; ++it)`; the iterator pairs sit at sp+0/sp+0x10 as in t_189938)
- A16 finding: func_0018FD08 (and its 5 twins) differ from the original in the second flag test being re-evaluated (not jump-threaded): compiling with `-fno-thread-jumps` gives the original block structure and 71/71 instructions (score 44 -> 30); remaining diffs are the a1/a2 register of the vcall's `this` (`lw a1,0(sp)` kept in a1 in the original), the lui/lw order of D_0036F658, `lw v0; move v1,v0` for the flags and the prologue move order. The vcall is a real virtual member call (`struct R {char pad[0x34]; virtual void v0(); virtual void* v1(R*);}`, `r->v1(r)`), same code as the manual vtable struct.
Matched (A16): func_0019B7E0 (t_19B448; DMA packet pad-to-16 loop: `for (; p < end; ) { *p = 0; D = p + 1; p = D; }` re-reads the global; `(long)((x & 0x3FF) << 16)` gives dsll, `(u32)((x & 0x3FF) << 16)` gives sll+or)
Matched (A16): func_0019B778 (same pad-to-16 loop as func_0019B7E0)
- near miss: func_0019E0D8 (t_19D4E8; flag-dependent divisor switch: original has tests 1, 0, 2 (balanced tree of cases 0,1,2) and a case 0 target distinct from default; ours merges case 0 into default and drops its test: 3 instrs differ); nonmatching/func_0019E0D8.cpp
- func_00131018 (t_12F9A0): search of 0x20-byte entries (count at +0x220, array at +0x224), unrolled 4x; the original has the entry test `blez n -> return 0` AND a second unroll guard; ours merges them (12 forms); called as void(void) so needs an asm-label alias
- func_00131018 (t_12F9A0): search of 0x20-byte entries (count at +0x220, array at +0x224), unrolled 4x; the original has the entry test `blez n -> return 0` AND a second unroll guard; ours merges them (12 forms); called as void(void) so needs an asm-label alias
- func_001A9ED0 (t_1A9A60): body is trivial (list walk) but the store of 0x9000100010001000 is a 64-bit `li` that the old assembler expanded as ori/dsll19/ori/dsll16/ori/dsll13/ori; ours expands it lui/ori/dsll/ori (toolchain: li64 expansion); 1 try
Matched (A16): func_0013DD50 (t_13BE78; strip trailing backslash from a 0x80 buffer copy)
Matched (A16): func_00121A68 (t_1210C8; `int b = buf[1]; f(arg, buf[0], b)` gives the a2-before-a1 load order)
Matched (A16): func_001A8A60 (t_1A7A50; round-robin over 0x60-byte entries: `&T[D_0036C658++]`, count of processed in n < 4)
- near miss: func_0013D100 (+ identical func_00137558 in t_135A98 with D_00371470/D_00371480: pooled delete like func_0012F9E8 but the pool array/index are lui-reached globals; original keeps idx in a2 (copy of the load) and the array base in a3 (copied in the first beqz delay slot), ours swaps them; 30 forms); nonmatching/func_0013D100.cpp
Matched (A16): func_00118580 (t_116E38; test the counter through a raw `*(int*)((char*)self + 0xD0)` and build `SA116_C* c = &self->unkCC` only at the end: the original recomputes the address in each branch delay slot)
Matched (A16): func_00187708 func_001877D0 func_00186E40 func_00186EE8 func_00186F90 func_00187038 func_001875A8 (t_185918, now `// cflags: -fno-cse-skip-blocks`, whole file still matches). KEY FINDING: the original did not CSE across 'if (x) y = z;' diamonds (cse-skip-blocks): repeated inline getters (Get(self) tested then Get(self) again, `int f = self->unk4` shared by the second getter pair) are recomputed in the original, merged by default. Try this flag on any near miss with 'the original recomputes/reloads X' (func_0018FD08 family, func_00139F98, func_0016EF40...).
Matched (A16): func_001800E8 (t_17F4F0, now `// cflags: -fno-gcse`; the near-miss attempt matches as is: gcse hoisted the sentinel copy). Flag sweep (-fno-gcse, -fno-thread-jumps, -fno-cse-skip-blocks...) is cheap: run it over every near miss before the permuter.
Matched (A16): func_00139F98 (t_139CE8; the 'original reloads c->unk84 in the bnezl delay slot' pattern is a volatile read of the TEST load: `while (c) { if (!*(T* volatile*)&c->unk84) break; c = c->unk84; }`; equivalent to -fno-gcse for that function, which the file cannot take globally. Try volatile on the test load for func_0016EF40, func_001318D0/00131970 and the iterator list walks that 'reload the test from memory')
Matched (A16): func_0016EF40 (t_16E670; singly linked unlink: `S* h = *head; if (h == self) {...} S* p = h; while (p) { S* n = *(S* volatile*)&p->unk0; if (!n) break; if (n == self) break; p = p->unk0; }` -- volatile on the TEST load gives the delay-slot reload)
Matched (A16): func_00131970 (t_12F9A0; same trick: the loop condition reads b->unk4 through a volatile pointer: `for (i = 0; i < (*(X* volatile*)&b->unk4)->unk4; i++) self->unk224[i].unk0 = b->unk4->unk10[i];`)
- func_001318D0 (t_12F9A0): same loop with a call; 14 forms (do-while with guard, volatile on guard/cond); the original keeps the call result in v0 (`move v0,zero` in the beqz slot) and loads self->unk4 after it; ours allocates a2
- near miss: func_0015D6F0 (+ same walks func_0015DB20, func_0015DB90, func_0015D750; count of flagged nodes with movn): everything matches (L* l = &D so the base is not folded; `n = f ? n+1 : n` gives movn) except the first `it != end`, which the original reloads from sp+4 after both iterator stores; volatile cur / volatile compare variants tried; nonmatching/func_0015D6F0.cpp
- near miss: func_00175930 (t_174C20; walk a->unk8 / a->unk4 with func_0027D870 (declared bool: `!f()` = xori), update-then-retest loop with the update block at the loop top and `b` into the test): goto form matches the block order; differences are the loop-head alignment nop (gcc only aligns real loops) and `ori a2,sp,4` vs the original's addiu; while/for forms put the second call block before the update; nonmatching/func_00175930.cpp
- near miss: func_00134210 (t_133A98; `for (;;) { if (target < start) { start = f(self, self->unk4->unk14[start]); if (start == target) return 1; } else return 0; }` now has the original layout (bnezl body / b ret0), only registers differ: original keeps start in a1 (no `move v1,a1`) and the unk4 temp in v0; 15 forms incl. callee return types; nonmatching/func_00134210.cpp
Matched (A16): func_00134128 (t_133A98, now `// cflags: -funroll-loops`, whole file still matches; index of key in an int array: `for (i = 0; i < self->unk4->unk4; i++) if (key == self->unk4->unk10[i]) return i; return 0;` -- key on the left gives the beq a1,v0 operand order)
Matched (A16): func_001A8810 (t_1A7A50, now `// cflags: -funroll-loops`; `u32 i = 0; if (D_0036C654) { do { E* e = &T[i]; if (e->unk8 == key) e->unk4 = val; i++; } while (i < D_0036C654); }` -- i declared (=0) before the guard so the zero lands in the beqz delay slot, bound re-read from the global)
Matched (A16): func_001317D0 (t_12F9A0; index of the 0x20-byte entry whose first word is key: `p = arr; end = p + count; for (; p != end; p++) if (key == p->unk0) return p - self->unk224; return -1;`)
Matched (A16): func_00189098 (t_187930, now `// cflags: -funroll-loops`, all 40+ functions of the file still match; `for (i = 0; i < 16; i++) self->unkC->unk15C[i] = src[i];` unrolled 8x)
Matched (A16): func_00114AD8 (t_112D48; CRC32 over (buf, len) with the D_0032A080 table, defined through an asm-label alias because the stub caller declares it void(void): `for (i = 0; i < n; i++) crc = T[(crc ^ p[i]) & 0xFF] ^ ((crc >> 8) & 0xFFFFFF);`)
Matched (A16): func_00114C70 (t_112D48; the same CRC32 loop with the running crc as 3rd argument)
Matched (A16): func_001A9128 (t_1A7A50; PS2 busy-wait delay: `if (b == 0xFFFF && a) { for (i = 0xFF; i != -1; i--) for (j = 3; j != -1; j--) {} for (k = 11; k != -1; k--) for (l = 4; l != -1; l--) {} }`, four separate loop variables; the empty inner loops compile to the nop blocks)
Matched (A16): func_00183AB8 (t_1836E8; dtor: vtable store, variant getter tested then reused, then the owned block with three optional members; plain natural code)
Matched (A16): func_001874E0 (t_185918; same getter-dispatch shape as func_00187708 with func_001BF4A0 / func_001C3578). Tip: group identical bodies by asm with symbols normalised (scripts/twins.py only clones when the symbols map)
- near miss: func_001287F0 (+ identical func_00182870 in t_1816C0 with D_0036A790/D_0036A7A0): pooled operator new (pool from a lui-reached array indexed by a global, func_0011C2A8 or Heap_Alloc with the 0x59.. heap lock sequence) -- body identical to func_0012A0F8's; the only diff is the position of the lui/addiu of the pool array relative to the sd s1 in the prologue (4 instrs); nonmatching/func_001287F0.cpp
Matched (A16): func_001287F0 (t_1277C0; pooled operator new with lui-reached pools: declaring the pool array with its real size `extern P* D_00371228[2];` (unsized gives the lui/addiu in the wrong place) -- the near miss was only that). Try sized array declarations on every 'address computed one slot too early' near miss (func_0013D100 ...).
Matched (A16): func_00182870 (t_1816C0; twin of func_001287F0 with D_0036A790[2] / D_0036A7A0)
Matched (A16): func_0013D100 (t_13BE78; the near miss was fixed by sizing the array: `extern P* D_00371288[2];`, plain version without locals). Its twin func_00137558 (t_135A98) starts with a split stub (addiu sp,+16; nop), skipped.

## Session 5 (this run)
- t_1727C8 func_00172D80 MATCH (stack list count + vcall returning f32; `if (n == 0) return 0.0f;` first, call last)
- t_161580 func_00161F48 MATCH (TI128 lanes via inline GetX/GetY/GetZ asm with "r"(q) inputs, not "0"; used inside the `||` chain)
- func_00116178 (t_114DC8) give up: struct init with `char name[16]="xxxx"`-like 5-byte copy + memset(11); ours hoists the D_00337F90 lui/move a1 differently, _start/D_C000 regs swap; 8 forms

## Session 6 (A17: div.s retries after the asm_filter nop fix, then untried)
Matched (A17): func_00174CB8 (t_174C20; `p[6] / p[9]`), func_00122FF8 (t_1210C8; `float* q = (float*)(p + 4); return q[3] / q[4]`), func_001233A8 and func_001234B0 (t_1230D0; plain float math, the earlier "nop in the slot" give-ups), func_00156CB8 (t_1550C0; body was right, the layout needs `if (t >= 0) x = 2*f(t); else x = 0;` for the bc1fl; flags word is a 64-bit RMW `*(long*)self = (*(long*)self & ~8L) | (flag << 3)` over a struct whose floats start at +4)
Matched (A17): func_00179B90 (t_178FE8, twin found by dk twins), func_0015DCD0 (t_15D2E0; second read of `o->unk34`: `if (o) { if (o->unk34) f(o->unk34); }` gives the `lw v0; move a0,v0` form), func_001A37A8 (t_1A37A8; `for (i=0; i < (*src+2)*16; i += 16) *d++ = *s++` with u128, base kept and returned, the while/do-while forms get the registers wrong), func_00114298 (t_112D48; sorted list insert: hoist the key `int key = m->unk8` out of the loop, store `m->unk10` before `m->unkC`), func_0014FF20 (t_14E7E0; hash bucket insert, `if (b->unk4 != 0 || b->unk0 != 0) alloc else fill`, store h before key; the operator-new helper takes ONE argument), func_0014FA20 (t_14E7E0; ctor with two operator_new'd list heads, first try), func_001A0D98 (t_19F538; 11x11 `E[j][i]` with `1<<j`, `1<<i`, needs the file's -funroll-loops)
Tip: a call that leaves an argument register untouched (`func_002764E8(x, 0)` where `a0` is the caller's own `a0`) means the first parameter is passed through: declare it, do not pass 0.
Near misses saved in nonmatching/ (all from this session, registers/scheduling only unless noted): func_0017E7E0 (prologue save order swc1 vs sd), CFunc_DecompressFonts (move a1,zero placement), func_0014E708, func_001376E8 (copy of the count in v1/v0), func_001761F8 (shared tail with the c.lt result kept across the join; ours materialises it), func_0012D6B0 (s1/s2 swapped), func_0010CA50 (float temp numbering), func_00136A28 (s2/s3/s4 order), func_001A0F60 (the original keeps `move a0,a1`), func_00123998 (dtor with erase loop: everything but self=s1/end=s2), func_0017E068 (entry pointer in a2 vs a0), func_0014CC88 (needs `// cflags: -funroll-loops` in t_14C740: the 2x unroll then matches; only `lui/addiu v0,%lo(D_00377FE0)` then `addiu s1,v0,24` as two steps is missing, the nonmatching file has the asm barrier trick and the flag), func_001778D0 (structure close, s0/s1 swapped and the join shape)
Given up (A17): func_00174C48 (body matches incl. the volatile stack slot at 4(sp); original keeps `b` in a2, ours a1; 8 tries), func_0011EE38 / func_0011ED68 / func_0016FCD8 (u32->float: the original keeps `cvt.s.w` before the `b` and a `nop` in its slot; toolchain), func_0015E2D0 (everything matches but the hazard-nop/label order: original `mtc1 $0,$f0; L: nop; c.lt`, ours `nop; L:` -- same as func_0012BF38, toolchain), func_00183520 (18 byte globals copied: ours 8 bytes bigger, register pressure differs), func_00138E78 (hash bucket lookup, original duplicates the first iteration), func_001556A8 (original unrolls x2, ours x4: the original body is bigger), func_0012D790 / func_00154830 / func_001A0D98-style unrolled searches in files without the flag, func_00176A48 and func_0016C7B8 / func_00113B20-style entries are split fragments.

## Round 2 (div.s retry)

Matched: func_001817F8 (needs `-funroll-loops` cflags; list walk through a local struct so the pointer stays in memory), func_00141428 (`__asm__` rename to keep the old `void(void)` prototype for its two callers).
Given up:
- func_0013C6E0: everything matches except the tail (`lq` then `mtc1`/`swc1` of the low two floats of a 128-bit out value from func_0027D2D8; `*(float*)&q` goes through memory and the register allocation (s2/s3) shifts, a u64 union gives integer stores); 10 tries
- func_0012F3E0: near miss (nonmatching/func_0012F3E0.cpp): only f0/f12 allocation of the int->float temp and one sub.s order; 8 tries
- func_00165210 (hash-switch float waveform): nested-if form from m2c gives 0x21c vs 0x238 bytes, case order/epilogue duplication differs; 3 tries, reverted
- dk twins (5b03625): func_001681E0 matched (from func_0016A718). Skipped: func_0014CF50 (from func_002BDC48: D_003781A0 is HT_14CF50 here, SHT in the twin; also SHT_Find undeclared), func_0014F910 (from func_00246C50: D_003781F8 is S14E_L here, u8[] in the twin; strcpy declared as void(int,int) in the file)
- func_0019E380 (opcode field patcher, 6/7, 0x16/0x17, 0x50 + empty 0x34..0x37): compare tree reproduced with a switch (empty cases 0x34-0x37 needed) but the exit block placement/shared tail differs (0xb4 vs 0xc0); 6 tries
- func_001A1A18 (4x16 table-driven byte gather): original keeps 4 separate pointer temps and does not strength-reduce, ours is 0x24 bytes smaller; 3 tries
- func_001965D0 (xorshift float RNG, 2x unrolled with odd entry): -funroll-loops gives 4x, hand-written 2x gotos differ in scheduling; 4 tries
- func_001422A8: near miss (nonmatching/func_001422A8.cpp, needs // cflags: -funroll-loops: 25 slots unrolled x5 matches; only self/array-base register choice s1/s2 differs); func_00139420 matched
- func_0017DC80: near miss (nonmatching/func_0017DC80.cpp): only the second `addiu s2,s0,12` is CSE'd away in ours (4 bytes), and bnez vs bnezl; 6 tries
- func_00172B38: near miss (nonmatching/func_00172B38.cpp): structure right, this/q saved registers s1/s2 swapped and the beqz delay-slot fill differs; 12 tries
- func_0011F028: near miss (nonmatching/func_0011F028.cpp): all matches except the 6-byte copy of D_00368D88 (original lw %lo(v0)/addiu v1/lhu through a2/a3 with the u16 as 4th arg of func_0030ADA0; ours loads in other order via two lui); strchr(name,':') is func_0030A684; 10 tries
- func_0012E290: near miss (nonmatching/func_0012E290.cpp): virtual call loop fine; original keeps the `a<b` / `b<a` result in the FP condition bit (c.lt; bnez; c.lt; bc1fl), ours materialises it with li/move; 12 tries
- func_0019EAA0: near miss (nonmatching/func_0019EAA0.cpp): GS packet header, registers/schedule only (v1/a2 base reg, order of the lui loads)
- func_001293A0: near miss (nonmatching/func_001293A0.cpp): loop of 50 slots matches instruction for instruction under the file's -funroll-loops; only saved-register assignment (self/p s0-s1, flag/-1/counter s3-s5) differs
- func_0012D870: near miss (nonmatching/func_0012D870.cpp): only self/counter saved registers s1/s2 swapped (the loop counter should be the lower register)
Matched (A18): func_0011ED68 func_0011EE38 (t_11D000), func_0015E2D0 (t_15D2E0), func_0016FCD8 (t_16E670; u32->float and u32 compare now fine after the delay-slot fix: natural code with u32 types)
- near miss: func_0016FCD8 (t_16E670; u32 timer fraction, natural code; only FP register numbering differs: original t=f3 r=f4 old=f2, ours t=f2 r=f3 old=f0; 9 forms); nonmatching/func_0016FCD8.cpp
Matched (A18): func_0012BF38 (t_12B970; the old source minus the asm nop, hazard nop after the join label now right)
Matched (A18): func_00137E30, func_00137EB0 (t_137C98; `*dst = D_0032A520` / `D_00377F80 = *src` with the 0x38-byte struct), func_001224F8 (t_1210C8; switch (op) 0 set / 1 add / 2 `unk48 - a`, return field)
- func_00122940 (t_1210C8) retry: five-way strcmp-like chain with func_0030E650, storing D_00368738; layout fine but original has n in s0 and the table base in s1, ours the reverse; 6 forms
Matched (A18): func_001206D0 (t_11F000; `for (i<2) if (D[i].unk8 == key) { *(volatile int*)&D[i].unk4 = 0; return; }` -- a volatile store is what leaves the original's `sw; jr; nop`; with -funroll-loops)
- func_00120628 (t_11F000) retry: same table, alloc with size test + volatile flag store + func_002F3BD0(D, &D[0].unk4, 1) (needs an asm-label alias, callers declare void(void)); original is a 2x unroll with a1 = copy of the stepped pointer, ours loops or reorders; 6 forms
- TIP: an __asm__-alias definition (`f_d(..) __asm__("f")`) is invisible to `dk done`'s check: run `dk try` on it yourself before committing.
Matched (A18): func_0010FE60 (t_10EBD8; rotate/negate pair by op 1/2/3: needs an empty 'case 0:' to get the original compare tree (1, <2, 2, 3), the stores inside each case so the tail is shared, loads in the order b = *x; a = *y; b = -b;)
Matched (A18): func_00137470 (t_135A98; alloc 8-byte block, request, poll loop `while (func_0028C200(t)) {}` now gets its nops from the filter)
- func_00120E00 (t_11F000) retry: lock + toggle D_00368C18 ^= 1 (volatile) + D_00368C08 = 0 + unlock; only the xori temp is v0 (original v1); 6 forms
- func_001755B0 (t_174C20): PMF call `(o->*self->pm)(self+0x10, self, o)` (virtual-capable, 3 args after this; o = self->unk4 ? *self->unk4 : 0); structure right, but the original moves self into a2 at entry and o into a3 (t0/t1 for the entry), ours keeps self in t0; 7 forms (same as func_00175750)
- near miss: func_00171E60 (t_1707C0; ctor with two vtable-like stores and a 128-bit zero vec built with the pextlw/pcpyld MakeVec of t_1F3840 stored at +0x30/+0x40): structure and values right, left: pextlw hi operands swapped (original z shares the register of x/y, w gets the second mfc1) and the order of the first stores after the sq; 8 forms; nonmatching/func_00171E60.cpp
Matched (A18): func_001315F8 (t_12F9A0; copy of the 0x20-byte entries: unk8, unk0 then a u128 at +0x10, count at +0x220, first try)
Matched (A18): func_0013DDF8 (t_13BE78; alloc 0x540 object, copy a 4-byte char colour: `C tmp(self->unkE8); t->unk538 = tmp; C tmp2(t->unk538);` with the copy-ctor/operator= colour class of t_15D2E0 gives the lwl/lwr + lw/sw + dead lwl/lwr)
- near miss: func_00161AC8 (t_161580; list teardown: stack It_161 walk freeing each node's object (func_0014EB78(*o), func_00134340(o+0xC), Heap_Free), then reset the sentinel at +0x14 and free the nodes, clear s16 +0x52/+0x54): code identical but self is s2 / end-copy s1 (original s1 / s2) and the second node walk reloads; 8 forms; nonmatching/func_00161AC8.cpp
Matched (A18): func_00180578 (t_17F4F0; list walk with an iterator whose operator-> returns node+0x10: `for (It it(first); it != It(&self->unk20); ++it)` -- the temp end iterator in the condition is what re-stores the end slot every pass; `it->a >= it->b` (not `b <= a`) gives the load order; `it.cur->unk40 = 0` for the raw node field)
- near miss: func_00186310 (t_185918; setpixel-like: variant getter, then `d[(h - (y+1)) * w + x] = Table[func_00185130(self, colour)]` with a 4-byte char colour passed by value as a hidden copy; everything matches except the stack: original has the hidden copy at sp+0 and the incoming param spilled at sp+0x10, ours the reverse (param at 0, copy at 0x10); 14 forms; nonmatching/func_00186310.cpp)
- near miss: func_001750B0 (+ identical func_001751F0, func_00175330, t_174C20; dtor: vptr store, walk of the list at +0x4C clearing node->unk8->unk4, two inlined Clear() of the same list (sentinel = header+4), then func_0017DFC0(self+0x34), func_00172A00(self, flags)): the walk with the temp end iterator is right but gcc does not invert the loop here (jump-to-test, 0x114 vs 0x12c bytes); the same walk form inverts fine in t_17F4F0 func_00180578; 22 forms incl. do-while, cflags sweep; nonmatching/func_001750B0.cpp
Matched (A18): func_00181EE0 (t_1816C0; new obj + flag bits `if (a) f |= 1; else f &= ~1;` + out-param call; locals `int g = f(a1); int t = a4 == 0;` after the bit updates give the sltiu after the call and the movz)
- near miss: func_0014A548 (t_148688; two size-scaled floats via func_00148248/func_00148250 and a 2-float stack out pair): all instructions match, only f20/f21 are swapped for the field-times-getter products (original keeps the field load in f20); 8 forms; nonmatching/func_0014A548.cpp
- func_0011EA30 (t_11D000; init of the two timing structs D_00376510/D_00376530 + float flag init): 1 try, original reaches D_00376510 both as symbol (lui a0 + %lo) and through a copied pointer s0; ours reduces to one base
Matched (A18): func_0019B550 (t_19B448; recursive free of a 16-ary tree: with -funroll-loops `for (i < 16) f(a, child[i], depth - 1)` matches, but the flag breaks func_0019B778/func_0019B7E0 of the file, so the committed source is the hand-unrolled 8x form `c = 15; do { c -= 8; f(p[0..7]); p += 8; } while (c >= 0)`)
- near miss: func_00176B58 (+ siblings func_00178FF0 t_178FE8 (flags 1 on the walk/last set), func_0017B6E0 t_17B448 (starts with a 8-byte return-1 tail fragment)): QB property chain walk (D268 get, D870 follow `unk8` then `unk4` links with the xori bool idiom); with the first test + loop in a static inline bool function and `(f ^ 1) == 0` tests the size and structure match, left: a/pv saved registers swapped (s0/s1) and one beqzl vs beqz; 22 forms; nonmatching/func_00176B58.cpp
- near miss: func_00128F48 (t_1277C0; first free slot among 6 triples of lazily allocated 0x408 blocks: alloc via func_00128A80(func_0012A0F8(0x408, 1)), memset(+4) and memset(+0x204) of 0x200, return index): structure and register use match (explicit slot 0/1/2 with `k = i + 1` temps, shared tail), only the store of the new pointer is in the memset jal delay slot in the original but before the argument setup in ours (gcc picks li a2); 7 forms; nonmatching/func_00128F48.cpp
- near miss: func_00113640 (t_112D48; thousands separator formatter: negative sign, sprintf, strlen, separator by language key (0x41D88638/0x0C8B4164/0x6F2ADD9F '.', 0x4C9908C7 ' ', else ','), copy with separator every 3 digits; the `sep = ','; if (k == C) goto dot;` gotos are needed (no movz), `while (len != 0) { *p++ = *s++; len--; if (len != 0 && len % 3 == 0) *p++ = sep; }`): only the separator register is a3 instead of a1 (the original reuses the key register; separator assigned in the beq delay slots); 20 forms; nonmatching/func_00113640.cpp
Matched (A18): func_00134508 (t_133A98; QB script property copy with 6 stack out-vars; declaring func_0027D1F8 as returning int (result ignored) moves a later load from v0 to v1 -- try return types of the callees when only a temp register differs; callee names re-declared through __asm__ aliases since the file declares them with other signatures)
Matched (A18): func_00128F48 (t_1277C0; memset declared returning void* -- changes the delay slot choice of the call from the arg setup to the preceding store; explicit slot 0/1/2 in a do-while with `if (p[2] != 0) { i += 3; p += 3; continue; }` before the third fill puts the shared tail where the original has it). Near-miss file nonmatching/func_00128F48.cpp matches and can be deleted.
- TIP (A18): a callee declared void but returning a value in the original changes temp/delay-slot choices: func_00134508 needed func_0027D1F8 as int, func_00128F48 needed memset as void*; scripts-free sweep: flip each callee's return type (void/int/void*) on near misses (func_00161AC8 17 -> from 21 diff lines with func_0014EB78 int)
Matched (A18): func_00153958 (t_152E18; array-new style init of 0x60 ten-byte entries: hand-unrolled 12x do-while (the file cannot take -funroll-loops: func_00153AB0/func_00153C28 break), header word 0x60 at blk[0], entries at blk+0x10; s16 stores through `(s16*)(off + (int)self->unk4)` -- off first gives the addu operand order; the s16 params must be int or gcc sign-extends them)
Matched (A18): func_00120C80 (t_11F000; 16 lazily created 0x15C-byte objects: `if (T[i] != 0) reuse(T[i]); else T[i] = ctor(Heap_Alloc(...))` with -funroll-loops; GP_DATA(D_00368A38) is needed for the beql whose slot holds the gp load; then a stack struct passed to func_00120A40(&t, 0, 1, -1) with fields assigned after `int v = D_00368748[0]` (u16 store of an int global keeps the lw), constants in the order 0x10000 then 0x64)
Matched (A18): func_00120E40 (t_11F000; split path into dir/name hashes: copy with '/'->'\' using u8 c and (s8)c compare, index i reused for the backward scan, pointers written as `(char*)(len + (int)full)` (index first = the addu operand order), while-loop with the found case first and break; three 0x80 stack buffers)
- near miss: func_00120F78 (t_11F000; find the item with name hash in the dir table of an object: entries {u32 count (-1 ends), dir hash, items*} items stride 0xC, hash at +8; returns the item or 0, no table -> func_001210C8(name, obj); split with func_00120E40): everything matches except the count test: original tests a temp (lw v0; beqz v0) and copies it to the loop bound a3 in the delay slot; 14 forms; nonmatching/func_00120F78.cpp
- near miss: func_001940C8 (+ twin-family func_0018E6C8 t_18DD30 with D_00345A78/D_00345A90, unk308/300/30C/334): object ctor: base ctor, two vtable stores, func_0022B0D0 handle lookup, virtual getter call (unk34[2]), 3-way flags getter chain stored at +0x2F8, 64-bit func_001A4770 at +0x2F0; left: the lui/addiu pair order of the two D_ vtables (original v1 then v0), the flag copy (move v1,v0) before the sra and a branch-likely; 5 forms; nonmatching/func_001940C8.cpp
- near miss: func_0017A1E0 (t_178FE8; same QB chain walk as func_00176B58 twice (flag 1 on the first lookup) then func_002763E0 + D870 + func_0017D658; static inline Walk(a, key, int* out)): size 0x16c vs 0x178 and the saved registers of a/&v/&v2/&out/self are numbered differently; nonmatching/func_0017A1E0.cpp
Matched (A18): func_0019A088 (t_1992F8; 16-ary box tree walk marking leaf node bytes: overlap tests on 4 u8 coordinates, child boxes built in a stack K struct; the loop must be written 2x unrolled by hand (`do { child i; child i+1; i += 2; p += 2; } while (i < 16)`) -- the plain 16-iteration loop under -funroll-loops moves the first sra out of the loop and adds a nop)
Matched (A18): func_0019A320 (t_1992F8; same walk as func_0019A088, leaf accumulates six floats into the output: `out[i] = out[i] + n[i]`)
Matched (A18): func_00199D90 (t_1992F8; recursive slot allocator of a 16-ary table: pick `m[key & 15]`, create the child (leaf form when depth == 1) or fall back to the next used slot func_00199D38, then try each slot round robin until one recursion returns non-null; first try)
- near miss: CFunc_LightShow_UpdateLightingTweaks (t_152E18; five script params: static inline Get(s, key) = `ok = func_0027CC30(s, key, 2, &t); v = t; if (!ok) { func_0027F1E0(s, 0, 1); v = 0; }` (value loaded in the bnez slot) stored to D_00369BF0/F4/F8, int param type 0xC then four func_0027EFA0(d, i) into D_0032A658, last param -> D_00369BFC): all instructions identical, only the saved registers differ (original s0 = lui D_0032A658, s1 = D+lo, s2 = &t5 hoisted, s3 = d, s4 = s; ours &t5 in s0, lui s1, pv s2); nonmatching/CFunc_LightShow_UpdateLightingTweaks.cpp
