# Session state

The plan, rewritten by the orchestrator whenever it changes and committed before the turn ends. A new session
starts here: `dk state` prints it with the numbers it computes (progress, commits, pushed or not, worklog activity),
so no progress figures or hashes are written by hand here.

## In flight

Resumed 2026-10-23: A round 9 (round 8: 15/33), C idle (round 12: 5/40, yield dropping); B running on per-file `-funroll-loops` for t_1E95C0,
t_1D00B0, t_225BF0, t_1D4540, t_1BB500 (forensics 5: the "short-loop padding" give-ups were unrolling; mtc1
hazard at `.p2align` fixed in asm_filter.py, func_0013F258 given to A). Were stopped
mid-round on 2026-10-20: A round 8
(had just started: func_001207A0 from the `dk protos` sweep, then the movn sentinel family), B retrying near misses
blocked by kept register copies (forensics starting points in scratchpad/forensics3/x/), C round 10 (committed the
three volatile t_292928 matches; the stale "Volatile accesses and delay slots" note at the top of C.md still needs
correcting: delay_slots() in asm_filter.py already handles it). The scratchpad paths belong to the
session that wrote them and may be gone in a new one.
Today's forensics (all C shape, in decomp_guide.md and toolchain.md): movz/movn if-conversion, kept register
copies, movn/movz select polarity, gp loads in delay slots; toolchain fix: OBJECT_END() resets GP_DATA at object
ends; fix_padding resolves alias-defined functions.
Ranges:

| Range | Files | Worklog | Last focus |
|---|---|---|---|
| A | `t_10C000` .. `t_1A9A60` | docs/worklog/A.md | twins exhausted; static-table initialisers (template in B.md), then untried 0x100..0x800 |
| B | `t_1ABAA0` .. `t_249620` | docs/worklog/B.md | untried 0x100..0x800 (was starting func_001E5C70); VU0 up to 30% |
| C | `t_24BA88` .. `t_2EB1C0` (not `t_2DFB70.c`) | docs/worklog/C.md | twins, table initialisers, untried 0x100..0x800 |

Workers: `decomp-worker` subagents (sonnet), max 3 at a time (16 GB machine), prompt = 4 lines pointing at
docs/agent_protocol.md; they pick with `dk next <files> --untried` (2,059 of the 3,248 INCLUDE_ASM functions were
never mentioned in a worklog on 2026-10-14).

## Pending integrator tasks

- Permuter when no worker runs: ~100 new near misses (B round 5 added 12, C round 5 ~20) this session (mostly register numbering, s1/s2 save order,
  one scheduled instruction): run `permute.py --batch --timeout 360 -j 4` overnight with no worker.
- Permuter: `--batch --timeout 120` stopped after ~15 of 74 (too slow with workers running), no score 0. Best:
  CFunc_DisplayLoadingScreen 175, func_00114660 225, CFunc_GetAngle 225, CFunc_SetStreamParams 260. Earlier 360 s
  runs: func_001E8CA8 60, func_0020EE10 60, func_002250F8 120. Not worth more CPU while workers run.
- `base.c does not compile` for the near miss after func_00114660 (func_00119F60?): `storage size of 'D_00375600'
  isn't known` (an incomplete array/struct extern that strip_source keeps; check).
- Names to apply when no worker runs: docs/worklog/names_pending.md (currently empty).

## Open toolchain questions (see docs/toolchain.md)

- `dk twins` (skill 1.6.5) declares conflicting symbols through `__asm__` aliases: func_001D0848, func_00288000,
  func_00266E08 now come out automatically (tested on a reverted copy). Still skipped: a twin whose own return type
  differs from the file's prototype (func_00276720).
- Vector to three floats (`lq; dsrl32; pcpyud; mtc1`): solved in C with lane helpers (t_24BA88, C.md:1011);
  B still blocked on func_00217618, func_00243228: point B at that helper.
- Short empty loops: the original has nop padding our gas does not emit (func_00226B28).
- QB alias-lookup family (func_00282268 and six others): one gcc shape never reproduced; also hash-iterator and
  stack list-iterator functions (range C).
- Unknown COP1 opcodes `c1 0x544` / `c1 0x10004` in some functions (range C).
- Same global reached through `$gp` and through `lui` in one function (func_0011F238).
- GS register constants built from bitfields (func_001A0710, func_001A04A0).
- asm_filter: label/hazard-nop position after `c.cond.s` before `bc1t/f` (func_00127ED0: only two `b` targets
  differ); two extra nops before a loop head after `li.s` (func_00160E80); unroll 4x where the original is 2x
  (func_00142398, func_00123D08, func_00137C98).
- `x = 0; if (n) x = n->f;` after a call: original keeps `move x,zero` in the branch delay slot (func_0022F7D8,
  func_001C5AE0).
- 26 functions saving `$ra` with `sq`.
- Large static-table initialisers (>12 entries): register numbers differ from the 2nd entry (func_001F86D8).
- A leading `move` before `addiu $sp` (func_0022CB18, func_0022F3A0, func_001D55F8).
- ~650 remaining "fragments" (lone sqc2/lqc2 or epilogue-first pieces) to classify like the 58 stub-hidden ones.

## Next step

1. Integrate the rounds as they report.
   Quiet point (no worker): split t_17D4D8 around func_0017F298 (needs `-funroll-loops`, neighbours break), split t_223BE8 between func_002243A0 and func_00224E10 (func_00224E10 matches with
   `-funroll-loops`, nonmatching/func_00224E10.cpp; func_002243A0 needs it off), and the cpp subsegment of t_152E18 at 0x153958 (func_001535E8 needs `-funroll-loops`,
   func_00153958/3AB0/3C28 after it need it off; A's attempt is in its worklog).
2. Retry the movz give-ups with the inline-reference pattern (func_001E1B28, func_0014E1B8 near misses; grep
   worklogs for movz/movn) and the `cvt.w.s` give-ups (func_001ADC90).
3. Quiet point as soon as A and B finish: the three file splits above, then the permuter batch with no worker
   (366 files in nonmatching/; yields of C and B are down, near misses are the biggest pool now).
4. New focus for B and C after that: functions over 0x1000, or the families a toolchain fix unblocks.
5. Idea, not decided: a naming/struct pass with a Ghidra-based assistant (e.g. REA, rea.tools; needs EE support in
   Ghidra), results into docs/worklog/names_pending.md. REA does not do matching.
