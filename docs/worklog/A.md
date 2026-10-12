# Worklog A (src/game/t_10C000.cpp .. t_1A9A60.cpp)

Notes:
- 0x4 candidates and functions starting with `addiu $sp, +N` are split tails: skipped.
- Functions that save `$s` registers only match with `-fopt-stack` (official flags give `sq`): skipped until the
  flag is adopted (they are listed per file as "opt-stack").
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
