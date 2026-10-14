# Session state

The plan, rewritten by the orchestrator whenever it changes and committed before the turn ends. A new session
starts here: `dk state` prints it with the numbers it computes (progress, commits, pushed or not, worklog activity),
so no progress figures or hashes are written by hand here.

## In flight

Running (2026-10-14): workers A and C (`div.s` functions first); `decomp-forensics` on delay slots the modern gas
fills where the original leaves `nop` (unsigned `cvt.s.w` before `b`/`jr`: func_002009B0, func_001D5038,
func_001D5138, func_001B21A0, func_001E2850; volatile `sw` before `jal`: func_001B3BD0), scratch copy only.
Worker A relaunched (second round, `div.s` left, then untried; 3 more `cvt.s.w` cases from it went to the forensics:
func_0011EE38, func_0011ED68, func_0016FCD8). Worker B finished its round (12 matches, few viable candidates left);
relaunch after the forensics result. A `general-purpose` agent investigates the `dk twins` failures (patch for the skill).
Ranges for the next workers:

| Range | Files | Worklog | Last focus |
|---|---|---|---|
| A | `t_10C000` .. `t_1A9A60` | docs/worklog/A.md | twins exhausted; static-table initialisers (template in B.md), then untried 0x100..0x800 |
| B | `t_1ABAA0` .. `t_249620` | docs/worklog/B.md | untried 0x100..0x800 (was starting func_001E5C70); VU0 up to 30% |
| C | `t_24BA88` .. `t_2EB1C0` (not `t_2DFB70.c`) | docs/worklog/C.md | twins, table initialisers, untried 0x100..0x800 |

Workers: `decomp-worker` subagents (sonnet), max 3 at a time (16 GB machine), prompt = 4 lines pointing at
docs/agent_protocol.md; they pick with `dk next <files> --untried` (2,059 of the 3,248 INCLUDE_ASM functions were
never mentioned in a worklog on 2026-10-14).

## Pending integrator tasks

- Permuter: `--batch --timeout 120` stopped after ~15 of 74 (too slow with workers running), no score 0. Best:
  CFunc_DisplayLoadingScreen 175, func_00114660 225, CFunc_GetAngle 225, CFunc_SetStreamParams 260. Earlier 360 s
  runs: func_001E8CA8 60, func_0020EE10 60, func_002250F8 120. Not worth more CPU while workers run.
- `base.c does not compile` for the near miss after func_00114660 (func_00119F60?): `storage size of 'D_00375600'
  isn't known` (an incomplete array/struct extern that strip_source keeps; check).
- Names to apply when no worker runs: docs/worklog/names_pending.md (currently empty).

## Open toolchain questions (see docs/toolchain.md)

- `dk twins` failed on types/prototypes for 5 twins that worker B then did by hand (func_001DCB80, func_0022CBC0,
  func_0022CC78, func_001DCD68, func_001D0848): check why and fix dk.py in the skill.
- `if (c) r = v` becomes `movz` where the original branches (func_002251F8).
- 26 functions saving `$ra` with `sq`.
- Large static-table initialisers (>12 entries): register numbers differ from the 2nd entry (func_001F86D8).
- A leading `move` before `addiu $sp` (func_0022CB18, func_0022F3A0, func_001D55F8).
- ~650 remaining "fragments" (lone sqc2/lqc2 or epilogue-first pieces) to classify like the 58 stub-hidden ones.

## Next step

1. When workers report: integrate (scripts/integrate.sh), count how many `div.s` functions matched.
2. Relaunch workers on what remains; permuter only when no worker runs.
