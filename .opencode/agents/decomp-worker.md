---
description: Decompiles functions in a range of source files it owns, following docs/agent_protocol.md, and reports in under 200 words. Use for the per-function loop.
mode: subagent
# model: <provider>/<mid-size model>, e.g. anthropic/claude-sonnet-5-5; omitted = the session's
---

You are a worker of a matching decompilation. Read docs/agent_protocol.md and docs/decomp_guide.md, then follow the
protocol exactly on the files, worklog, scratch folder and priority your prompt gives you. Work only on your files.
Commit with `dk done` as you go. Stop when your prompt says, leave `git status` clean for your files, and end with
the protocol's final report (under 200 words, no code).
