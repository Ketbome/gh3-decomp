# Worklog C: src/game/t_24BA88.cpp .. t_2EB1C0.cpp

## Notes

- Functions that save `$s0`-`$s7`/`$fp` cannot match yet: the game code saves them with `sd`, our ee-gcc 2.95.3-136
  build always emits `sq` (and a different frame layout). Skipped as a class until the toolchain question is solved.
- `delete p` on a class with a virtual destructor (vptr at 0x14, gcc 2.x vtable entries {s16 delta, s16, fn}) matches
  the singleton release pattern (`if (refs >= 2) refs--; else { delete obj; obj = 0; refs = 0; }`).
- A pointer loaded from `$gp` used only on one branch: read the global inside the branch, not into a local first.
- `scripts/fcheck.py` bug (not fixed, scripts/ is not mine): its line regex uses `\s+`, so an operand-less line
  (`nop` in a delay slot) swallows the next line and that instruction's relocation is lost; a `jal` right after a
  `nop` delay slot then shows as DIFFERS. Also `--all` only checks `func_XXXXXXXX` names, not `CFunc_*`. I verify
  with a private copy using `[ \t]+` and `--all` over every `extern "C"` definition.
- `if (ok) return call(x); return 0;` gives the single-epilogue form (`beqz` with `v0 = 0` in the delay slot);
  `if (ok) { ...; return 1; } return 0;` gives the inline `b` + `v0 = 0` form.
- Float fields zeroed with `mtc1 $0`: chained assignment `a = b = c = 0.0f` (separate statements store `sw $0`);
  store order follows the chain in a non-obvious way (4, C, 8 for `p->4 = p->8 = p->C`).
- Masks like `and` with `-0x101`/`-0x201` then `sb` at +2: bitfields in a u32 (clear bit 8, bit 9, byte field at 16).
- A `$gp` scalar and a `%hi/%lo` access to the same symbol can coexist: declare the extra view with an asm label
  (`extern T name_x asm("D_...")`), but gas decides `$gp` per symbol, so macro-form `lw $4,D` uses cannot mix.

## Files

### t_2DAE48 (+11)
CFunc_GetButtonsReleased, CFunc_ResumeControllerChecking, func_002DC9D8, func_002DC9F0, func_002DB998,
func_002DB9B8, func_002DCAD0, CFunc_ShouldGameBePausedDueToSysNotification, func_002DCA08, func_002DBA28,
func_002DCB40
Given up: func_002DBA80 (saves $s0: sd vs sq).

### t_254248 (+21)
CFunc_ResetBCSND, CFunc_PauseStream, CFunc_FreeStreamFrameAmp, CFunc_IsSoundPlaying, CFunc_LoadStreamFrameAmp,
CFunc_PauseMusic, CFunc_SetRandomMode, CFunc_UnLoadFSB, CFunc_IsSoundStreamPlaying, CFunc_LoadSound,
CFunc_SetMusicLooping, CFunc_SetMusicMode, CFunc_SetMusicStreamVolume, CFunc_SetMusicVolume,
CFunc_SetDefaultSoundPriority, CFunc_StopSoundStream, CFunc_SetSfxVolume, CFunc_SetStereoSound,
CFunc_LoadStreamHeader, CFunc_RemoveSoundGroup, CFunc_SetSfxDropoff
Given up:
- CFunc_ClearSoundBank: reads D_00370AE0 through $gp, while the file's other uses need the lui/lw macro form
  (array declared `.sdata` without size); one file cannot have both.
- CFunc_StopSoundEvent: prologue scheduling (`move a2,sp` before `sd ra`), loop forms tried.
- CFunc_TrackEnabled: u64 bit test arms laid out differently (5 variants tried).

### t_2754A0 (+10)
func_00275648, func_002755F0, func_002759F8, func_00275750, func_00275510, func_00275540, func_00275868,
func_00275780, func_002757D8, func_00275988
(func_00275540 shows DIFFERS in scripts/fcheck.py only because of the `nop` parsing bug above; it matches.)
Given up:
- func_00276668: original leaves the first `beqz` delay slot empty (we fill it with the loop's first load).
- func_00277220 (path compare, '/'=='\\', case-insensitive): `v0 = 0` not stolen into the `bne` delay slot.
- func_00276698: original copies the hash-chain loop test before the loop (header duplication); 3 forms tried.
- func_00275660, func_00275610: contain an `alabel` (two entry points); skip.
