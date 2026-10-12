# Worklog B (src/game/t_1ABAA0.cpp .. t_249620.cpp)

The 0x4 candidates are tails of the previous function (splat split errors): skipped, as are other split tails (functions starting with `addiu $sp, +N` or ending without `jr`).

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
