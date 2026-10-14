// Puts `dk state` in the system prompt of every main session, computed once per session and again after a
// compaction: the OpenCode counterpart of the SessionStart hooks of Claude Code and Codex. Subagent sessions skip it.
export const DkState = async ({ $, directory }) => {
  const cache = new Map()
  const children = new Set()
  const state = async () => {
    const out = await $`.venv/bin/python scripts/dk.py state 2>&1`.cwd(directory).quiet().nothrow().text()
    return out.split("\n").slice(0, 150).join("\n")
  }
  return {
    event: async ({ event }) => {
      if (event.type === "session.created" && event.properties.info.parentID) children.add(event.properties.info.id)
      if (event.type === "session.compacted") cache.delete(event.properties.sessionID)
    },
    "experimental.chat.system.transform": async (input, output) => {
      if (!input.sessionID || children.has(input.sessionID)) return
      if (!cache.has(input.sessionID)) cache.set(input.sessionID, await state())
      output.system.push("Project state from `dk state` (trust it over memory and summaries):\n" + cache.get(input.sessionID))
    },
  }
}
