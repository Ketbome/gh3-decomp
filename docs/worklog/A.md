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

Given up:
- func_00189400: last stores load source/dest in the other order (scheduling); 5 tries
- func_00187E08: lui/lhu register swap (v0/v1); 6 tries
- func_001885B0, func_00188D00, func_00189290: alloc args set in order a2,a3,a1 in the original; 3 tries
- func_001891A0: D_0036C7EC both lui/%lo and %gp_rel

## t_10C000

Matched 3: func_0010C120 func_0010D420 func_0010C2E0

Given up:
- func_0010C170, func_0010C050, func_0010C0B8: same .sdata symbols both as lui/%lo and %gp_rel (see notes)
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
- func_00113A70, func_00113AC8 (strcat): original has nops inside the short loop (assembler R5900 fix)
- func_00113770: c/r register swap (a0 vs v1); 5 tries
- func_00113BF8, func_00114C70: unrolled loops (-funroll-loops style), not attempted

## t_114DC8

Matched 8: func_00115028 func_00116288 func_001162B8 func_001163B8 func_00116578 func_00116590 func_001165C8
func_001167C8 (func_001150B8 retyped to pass its argument)

Given up:
- func_00116660: nozdiv; with the flag only a scheduling diff left
- func_001153C8: .sdata symbols both lui/%lo and %gp_rel
- func_001150E0, func_001165E8: split tails

## t_116E38

Matched 8: func_00116E90 func_00117118 func_00117168 func_00117C20 func_00117C60 func_00117CC0 func_00118640
func_00118700

Given up:
- func_001183C8: cvt.w.s
- func_001187D0, func_00118798: D_00373248 used both lui/%lo and %gp_rel in this file
- func_001179F8, func_00117940: iterator on the stack, not attempted

## t_118E40

Matched 16: func_00119180 func_0011A100 func_0011A208 func_0011A380 func_0011A3E0 func_0011A410 func_0011A440
func_0011A470 func_0011A520 func_0011A5B8 func_0011A5E0 func_0011A648 func_0011A8A8 func_0011A8F8 func_0011A928
func_0011AD80

Given up:
- func_00119490, func_001194B8: address order (n*4+self)+0x194 vs ours (self+0x194)+n*4; 6 tries
- func_0011A0B0: `move a0,v0` scheduled before the global store; 2 tries
- func_0011A128: D_00368A38 both lui/%lo and %gp_rel in one function
- func_0011A170, func_00119A60: unrolled loops
- func_00118EF8: split tail

## t_11AEB0

Matched 6: func_0011AF30 func_0011AF90 func_0011AFF0 func_0011C2A8 func_0011C3A8 func_0011C480

Given up:
- func_0011C408: needs D_00368A38 as %gp_rel, the rest of the file uses lui/%lo

## t_11D000

Matched 16: func_0011D348 func_0011D4F8 func_0011DA60 func_0011DB08 func_0011DB88 func_0011DBB8 func_0011DBE8
func_0011DC18 func_0011DD68 func_0011E130 func_0011E730 func_0011E780 func_0011E8D0 func_0011E918 func_0011E960
func_0011ED30

Given up:
- func_0011ED00, func_0011ECF0: `ld`/`lw` %gp_rel kept out of the jr delay slot (old assembler macro); ours fills it
- func_0011E4E8: 2D array push, two extra instructions; 4 tries
- func_0011D9E0: init store scheduling; 1 try
- func_0011D830: unrolled loops
- func_0011EE38, func_0011ED68: not attempted (unsigned->float, D_0036876C lui)

## t_11F000

Matched 3: func_0011F4D8 func_0011F510 func_0011F598

Given up:
- func_0011F3A8: li -1 lands in v0 instead of v1; 1 try
- func_00120E00: .sdata store macro in a delay slot (gcc thinks 1 insn; the original kept it out)
- func_001206D0: two-entry search, original keeps nops in delay slots; 2 tries (also not -funroll-loops)
- func_0011FA98, func_0011F8D0, func_0011F9A8, func_001208C0: unrolled/loop code, not attempted

## t_1210C8

Matched 14: func_00121618 func_00121668 func_00121870 func_001218A0 func_00121B18 func_00121B68 func_00121C18
func_00121CD8 func_00121D78 func_00121DD0 func_00122460 func_00122490 func_00122608 func_001226A0
(func_00121BD0, func_00121BF8 retyped to pass their arguments)

Given up:
- func_001224F8: final `lw` not in the jr delay slot (branch-target label); 1 try
- func_00122F88, func_00122DE0: same .sdata symbol both lui/%lo and %gp_rel
- func_00122FF8: div.s with hazard nops, not attempted

## t_1230D0

Matched 16: func_00123138 func_001232E8 func_00123540 func_00123678 func_00123690 func_001236D0 func_00123720
func_001238F8 func_00123920 func_00123948 func_00123EB8 func_00123F18 func_001244C8 func_00124510 func_00124630
func_00124688

Given up:
- func_00123568: matched on retry (inline li.s now works)
- func_00123778: `li a2,512` / `sw` order swapped; 1 try
- func_00123E68: delay loop with nops, not attempted
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

- `min.s`/`max.s` in the original (func_0012A590) are only emitted with `-ffast-math`; the other functions of the
  file still match with it. func_00129F70 is a loop unrolled 5x (`-funroll-loops`).
- A `u32` field set to 0xFFFFFFFF gives `lui 0xffff; ori 0xffff` (an `int` gives `li -1`).

Given up:
- func_0012A9A0: `andi`/`lw` scheduling of `((x >> 29) & 1) ^ 1` argument; 8 tries (bitfields too)
- func_0012A828: `ori a1`/`move a0` order before some calls, delay slot fill; 2 tries
- func_0012A048, func_0012A0F8: D_00368A38 both %gp_rel and lui/%lo (the file uses lui)
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
- func_0012D028, func_0012D0E8: D_00368A38 both %gp_rel and lui/%lo
- func_0012BD38, func_0012D000, func_0012C750, func_0012BCD8, func_0012CEE0, func_0012D210: split tails
- func_0012CF40: iterator on the stack; func_0012D1A0: nop delay loops; func_0012BF38: jtbl
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
- func_0012F8D0: nop delay loops; func_0012E5F8: split tail
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

- ldl/ldr/sdl/sdr = assignment of a 0x38-byte char-aligned struct. func_002EC118(float)/func_002EC10C(void) are the
  VU0 sin/cos start/result helpers (gamespy.s). u128 arguments go in one register each (func_00138D98); the
  callee's float params come right after the u128s.
- Float literals must be the exact float (57.2957763671875f, 0.01745329424738884f) or the low bits differ.

Given up:
- func_00137E30, func_00137EB0: the last `sdr` is not put in the jr delay slot by SN's assembler (ours fills it)
- func_00138E78: `li 0x19F1C; addu; lw 0` not folded in the original (ours folds the offset); 3 tries
- func_001396D0: 128-bit != compare (pceqw/ppacb), gcc 2.95 rejects TImode compares
- func_00137F38, func_00138790: D_00368A38 both %gp_rel and lui/%lo
- func_00138A18: float lanes of 128-bit values; func_00138B08, func_00138950, func_00138E60: split tails

## t_139CE8

Matched 7: func_00139CE8 func_00139EB0 func_00139EE0 func_00139FC0 func_0013A010 func_0013A060 func_0013B038

- func_0013A060: ref-counted pointer (func_001CE868 attach / func_001CE888 detach, 12-byte {p, 0, 0}) written as
  an inline class with ctor taking `S139_X* const&`, dtor and operator=; the dtor's final check survives only that way.
- func_00139EE0: `andi; movz` comes from an inline `if (x & 0x4000) return 1; return 0;` helper.

Given up:
- func_00139F98: has assembler load-delay nops (`lw; nop; beqz`), not gcc -O2 output

## t_13BE78

Matched 10: func_0013C1B0 func_0013CAA0 func_0013CC28 func_0013CC70 func_0013CC98 func_0013CFC8 func_0013D000
func_0013D2D0 func_0013D360 func_0013D6E8

- Constructors: declare the base-class ctor as returning the pointer (`S* func(S*)`), not void; otherwise the
  vtable address lands in v0 instead of v1 (func_0013CC28). This also explains func_00134700 / func_0012D298.

Given up:
- func_0013C678, func_0013C5F8: short loops with an assembler-inserted nop before the back branch (R5900 fix)
- func_0013CE58, func_0013CF78: recursive bool check; our gcc either tail-converts or adds `move v1,v0`; 5 tries
- func_0013C1F0: parent walk with a ref temp; loop variable copied (move a0,s0) and rotated; 3 tries

## t_13DEB8

Matched 7: func_0013DEB8 func_0013DF18 func_0013EB38 func_0013EC10 func_0013EC98 func_0013ED28 func_0013FE00

- func_0013FE00: same ref-counted pointer class (here the ctor takes the pointer by value, plus
  `operator=(const Ref&)`); declaring `int n = 0` before the Ref local gives the original order and loop shape.

## t_13FEE0

Matched 8: func_0013FEE0 func_00140930 func_00140A00 func_00140A60 func_001413A0 func_00141920 func_001419E8
func_00141C28 (func_00141B50 retyped to pass its 2nd argument)

- A 4-byte char-aligned color struct copies with lwl/lwr; passing it by value through a hidden stack copy (as
  func_00141B70 does) needs a user copy constructor (TREE_ADDRESSABLE).
- A member function can be bound to a splat name with `__asm__("func_...")` on its declaration (fcheck accepts it).

Given up:
- func_00141B70: matches except our assembler inserts a nop after `mfc1 v0` before `sb v0` (hazard), SN's did not
- func_00141A40, func_00141B00: `ori a1`/`move a0` order and .sdata load scheduling around calls; 4 tries
- func_00141988 (split), func_00141658, func_00141668, func_00141AF8: split tails
