# Session state

The plan, rewritten by the orchestrator whenever it changes and committed before the turn ends. A new session
starts here: `dk state` prints it with the numbers it computes (progress, commits, pushed or not, worklog activity),
so no progress figures or hashes are written by hand here.

## In flight

Running (2026-10-14): `decomp-forensics` on the `div.s` nops (scratch copy only) and a `decomp-runner` permuter
batch on func_001E8CA8, func_0020EE10, func_0022E0C0, func_002250F8 (+ obsolete near-miss list, CFunc_SetShadowDirFromLight
error). Workers wait for the forensics result. Ranges for the next workers:

| Range | Files | Worklog | Last focus |
|---|---|---|---|
| A | `t_10C000` .. `t_1A9A60` | docs/worklog/A.md | twins exhausted; static-table initialisers (template in B.md), then untried 0x100..0x800 |
| B | `t_1ABAA0` .. `t_249620` | docs/worklog/B.md | untried 0x100..0x800 (was starting func_001E5C70); VU0 up to 30% |
| C | `t_24BA88` .. `t_2EB1C0` (not `t_2DFB70.c`) | docs/worklog/C.md | twins, table initialisers, untried 0x100..0x800 |

Workers: `decomp-worker` subagents (sonnet), max 3 at a time (16 GB machine), prompt = 4 lines pointing at
docs/agent_protocol.md; they pick with `dk next <files> --untried` (2,059 of the 3,248 INCLUDE_ASM functions were
never mentioned in a worklog on 2026-10-14).

## Pending integrator tasks

- Permuter: near misses in `nonmatching/`; `scripts/permute.py <file> <func> --timeout 360 -j 2`, then
  `scripts/permute_apply.py <func>`. Best so far: func_001E8CA8 (2 lines), func_0020EE10 (3), func_0022E0C0 (only
  argument load order), func_002250F8 (10). `base.c does not compile` for CFunc_SetShadowDirFromLight and two
  others: check them.
- Remove obsolete near misses whose function now matches in src (e.g. nonmatching/func_00206E48.cpp).
- Names to apply when no worker runs: docs/worklog/names_pending.md (currently empty).

## Open toolchain questions (see docs/toolchain.md)

- Two nops before `div.s` (418/700 cases), rule unknown. Biggest lever: 213 INCLUDE_ASM functions contain `div.s`
  (2026-10-14).
- 26 functions saving `$ra` with `sq`.
- Large static-table initialisers (>12 entries): register numbers differ from the 2nd entry (func_001F86D8).
- A leading `move` before `addiu $sp` (func_0022CB18, func_0022F3A0, func_001D55F8).
- ~650 remaining "fragments" (lone sqc2/lqc2 or epilogue-first pieces) to classify like the 58 stub-hidden ones.

## Next step

1. Toolchain forensics on the `div.s` nops: a `decomp-forensics` subagent (opus, effort high), while no worker
   runs; if fixed: `dk all`, commit, then workers retry the `div.s` give-ups first.
2. Relaunch workers A, B, C (focus above, `--untried`) and a `decomp-runner` for the permuter batch on the near
   misses meanwhile.
