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
