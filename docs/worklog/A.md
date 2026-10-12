# Worklog A (src/game/t_10C000.cpp .. t_1A9A60.cpp)

Notes:
- 0x4 candidates and functions starting with `addiu $sp, +N` are split tails: skipped.
- Functions that save `$s` registers only match with `-fopt-stack` (official flags give `sq`): skipped until the
  flag is adopted (they are listed per file as "opt-stack").
- Old-assembler artifact: `.sdata` globals read/written outside a delay slot appear as `lui`+`%lo` (macro
  expansion, `$at` for stores); declare them `extern T D[] __attribute__((section(".sdata")))`. Inside a delay slot
  they are `%gp_rel`: declare them as scalars. A symbol used both ways in one file can't be matched with one declaration.
- scripts/fcheck.py drops the relocation of an instruction that follows a `nop` (regex `\s+` eats the newline), so
  a `jal`/`%lo` right after a `nop` reports DIFFERS: skipped ("fcheck nop bug").

## t_187930

Matched 22: func_00188360 func_00188420 func_00188448 func_00188700 func_001888D0 func_00188908 func_00188940
func_00188998 func_001889E0 func_00188A00 func_00188A38 func_00188AD0 func_00188AE8 func_00188B70 func_00188C50
func_00188C70 func_00188C88 func_00188E38 func_00189078 func_001893D0 func_001894C8 func_00189508

Given up:
- func_00189400: last stores load source/dest in the other order (scheduling); 5 tries
- func_00189180: store via assembler macro (`lui $at`), not reproducible
- func_00188870: fcheck nop bug (matches otherwise)
- opt-stack: func_00187E08 func_00187F00 func_001883A8 func_00188520 func_00188568 func_00188A70 func_00188F80
  func_00188FB8 func_00189010 func_00189040 func_00189818

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
