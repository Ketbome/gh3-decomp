# gh3-decomp

Matching decompilation of Guitar Hero III (PS2, USA, SLUS-21672). Goal: C++ that rebuilds `SLUS_216.72` byte for byte.
Method: the [matching-decomp skill](https://github.com/Ketbome/decomp-skills); `scripts/dk.py` is a copy of its tool.

## Start of every session

1. `.venv/bin/python scripts/dk.py state` (run for you at startup, clear and compaction by `.claude/settings.json`,
   `.codex/hooks.json` and `.opencode/plugins/dk-state.js`): plan
   (`docs/STATE.md`), commits, uncommitted work, progress, worklog activity, stale documents. Trust it over memory
   and over a compacted summary.
2. If it shows uncommitted sources or a warning, deal with that first (`dk rescue`, `dk docs --commit`).

## Roles

- **Main session = orchestrator.** Plans, launches workers, integrates, fixes the toolchain, keeps the docs current.
  It does not decompile functions itself and does not read asm, m2c output, diffs, whole worklogs or agent
  transcripts: investigations go to a subagent that reports in under 200 words. Numbers, hashes and worker status
  come from `dk state`/git at the moment they are stated, never from memory.
- **Delegate to the role subagents** (this file asks for it explicitly). Definitions: `.claude/agents/`,
  `.codex/agents/`, `.opencode/agents/`; model per task and escalation rules: skill, references/orchestration.md,
  "Choosing models and effort".
  - `decomp-worker` (mid-size: Sonnet; Codex effort medium): the per-function loop on a range it owns,
    `docs/agent_protocol.md`; prompt of four lines (files, worklog, scratch folder, priority). Max 3 at a time.
  - `decomp-forensics` (strongest: Opus effort high; Codex effort xhigh): a difference repeated across many
    functions (e.g. the `div.s` nops); works in a scratch copy, the orchestrator applies the fix and runs `dk all`.
  - `decomp-runner` (smallest: Haiku effort low; Codex effort low): exact commands only (permuter batch +
    `permute_apply.py`, `dk twins`, names list, counts).

## Keeping documents current (orchestrator, every integration round)

- `scripts/integrate.sh` regenerates the progress table in README.md (`dk docs`), verifies and pushes.
- `docs/STATE.md`: rewrite in flight / pending / next step whenever the plan changes, commit before the turn ends.
  No numbers there: `dk state` computes them.
- This file: when a command, path, flag or convention changes, in the same commit.
- `docs/toolchain.md`: every verified toolchain finding, with its evidence. `docs/decomp_guide.md`: a matching
  pattern once two workers report it. Generic lessons (not about this game) go upstream to the skill repo.
- Quiet point (no worker running, everything integrated, STATE.md committed): `/clear` and start fresh; the
  startup hook reloads the state.

## Stack

- splat, m2c, pyelftools (Python, `.venv`); splat splits the executable into `asm/` (generated, not committed)
- SN Systems ee-gcc 2.95.3 build 136 (`tools/compilers/`, Windows exe run with wibo), `-O2 -G8 -fopt-stack -mno-check-zero-division -fno-exceptions -fno-rtti`
- PS2 binutils `mips-ps2-decompals` (`tools/binutils/`), ninja
- Details and evidence: `docs/toolchain.md`

## Commands

`dk` = `.venv/bin/python scripts/dk.py` (configured by `decomp.toml`).

- `scripts/setup_tools.sh`: download tools, create `.venv`
- `.venv/bin/python configure.py`: extract from the ISO, split, write `build.ninja` (rerun after editing the yaml)
- `scripts/integrate.sh`: refresh README progress, verify HEAD in a separate worktree (configure + sync + ninja),
  push if identical
- `ninja`: build and compare (`build/SLUS_216.72.ok` only when byte-identical)
- `dk state` / `dk rescue [--commit]`: recovery report / revert non-matching work in progress after an interruption
- `dk next <files> --untried [--max-size N]`: functions still in INCLUDE_ASM nobody tried, smallest first
- `dk show <func>`: asm + m2c draft; `dk try <file> <func>`: GP_DATA + compare (no link, safe in parallel)
- `dk revert <file> <func>`; `dk done <file> <worklog> <msg>`: padding, full file check, commit
- `dk twins [--list] [files]`: decompile functions identical to an already matched one
- `dk protos <file> <func>`: near miss around calls: try each callee with the other return type (void <-> int)
- `dk all`: check every C++ function (regression check after toolchain changes)
- `dk docs [--commit]`: regenerate the `<!-- dk:... -->` blocks of README.md
- `.venv/bin/python scripts/progress.py`: progress
- `scripts/permute.py <file> <func> [-j N]` then `scripts/permute_apply.py <func>`: decomp-permuter on a near miss
- `scripts/qbkeys.py key <name>` / `build <qb script dirs>`: Neversoft checksums -> `config/qbkeys.txt`

## Layout

- `src/game/t_<addr>.cpp`: game code in chunks (cpp subsegments in `config/SLUS_216.72.yaml`)
- `config/`: split and symbol names; `include/`: shared headers, assembler prelude
- `docs/`: `STATE.md` (plan), `agent_protocol.md` (workers), `decomp_guide.md` (matching rules), `toolchain.md`,
  `text_map.md`, `worklog/<range>.md` (one per worker range), `worklog/names_pending.md`
- `nonmatching/<func>.cpp`: near misses waiting for the permuter

## Conventions

- Never commit game data: the ISO, `disc/`, `asm/`, `build/` and `tools/` are ignored.
- Decompiling = replacing an INCLUDE_ASM line with C++. Workflow and rules: `docs/decomp_guide.md`. The build must
  stay byte-identical.
- Code that does not match stays as INCLUDE_ASM. C++ must not emit data of its own (rodata/literals/statics).
- Unknown names: `extern "C"` with splat names `func_XXXXXXXX` / `D_XXXXXXXX`. Real names go in `config/symbol_addrs.txt`.
- Clean-room only: never use leaked or copyrighted source code (e.g. the leaked THUG source) as a reference.
  Names come from the executable itself (strings, tables), the game's own QB scripts and our own analysis.
- Documentation states what is verified by byte match and what is inferred.
- Git identity for this repo: ketbome / pablo.moraga.san@gmail.com (local config).
