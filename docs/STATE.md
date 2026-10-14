# Session state

Rewritten by the orchestrator whenever the plan changes. A new session starts here (`dk state` prints it).

## Verified

- Last integrated and pushed commit: `add2c79` — 22.05% of game code, 5,754 functions in C++ (byte-identical build).

## In flight

Nothing running (2026-10-14, all three workers stopped by the session rate limit; their work was rescued with
`dk rescue --commit` and integrated). Relaunch from the worklogs:

| Range | Files | Worklog | Last focus |
|---|---|---|---|
| A | `t_10C000` .. `t_1A9A60` | docs/worklog/A.md | twins exhausted; static-table initialisers (template in B.md), then untried 0x100..0x800 |
| B | `t_1ABAA0` .. `t_249620` | docs/worklog/B.md | untried 0x100..0x800 (was starting func_001E5C70); VU0 up to 30% |
| C | `t_24BA88` .. `t_2EB1C0` (not `t_2DFB70.c`) | docs/worklog/C.md | twins, table initialisers, untried 0x100..0x800 |

Workers: mid-size model (sonnet), max 3 at a time (16 GB machine), prompt = 4 lines pointing at
docs/agent_protocol.md.

## Pending integrator tasks

- Permuter: near misses in `nonmatching/`; `scripts/permute.py <file> <func> --timeout 360 -j 2`, then
  `scripts/permute_apply.py <func>`. Best so far: func_001E8CA8 (2 lines), func_0020EE10 (3), func_0022E0C0 (only
  argument load order), func_002250F8 (10). `base.c does not compile` for CFunc_SetShadowDirFromLight and two
  others: check them.
- Remove obsolete near misses whose function now matches in src (e.g. nonmatching/func_00206E48.cpp).
- Names to apply when no worker runs: docs/worklog/names_pending.md (currently empty).

## Open toolchain questions (see docs/toolchain.md)

- Two nops before `div.s` (418/700 cases), rule unknown.
- 26 functions saving `$ra` with `sq`.
- Large static-table initialisers (>12 entries): register numbers differ from the 2nd entry (func_001F86D8).
- A leading `move` before `addiu $sp` (func_0022CB18, func_0022F3A0, func_001D55F8).
- ~650 remaining "fragments" (lone sqc2/lqc2 or epilogue-first pieces) to classify like the 58 stub-hidden ones.

## Next step

`dk state`, then relaunch the three workers (A, B, C) with the focus above and run the permuter batch on the near
misses while they work.
