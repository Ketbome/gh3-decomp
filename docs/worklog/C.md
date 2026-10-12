# Worklog C: src/game/t_24BA88.cpp .. t_2EB1C0.cpp

## Notes

- Functions that save `$s0`-`$s7`/`$fp` cannot match yet: the game code saves them with `sd`, our ee-gcc 2.95.3-136
  build always emits `sq` (and a different frame layout). Skipped as a class until the toolchain question is solved.
- `delete p` on a class with a virtual destructor (vptr at 0x14, gcc 2.x vtable entries {s16 delta, s16, fn}) matches
  the singleton release pattern (`if (refs >= 2) refs--; else { delete obj; obj = 0; refs = 0; }`).
- A pointer loaded from `$gp` used only on one branch: read the global inside the branch, not into a local first.

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
