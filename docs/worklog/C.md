# Worklog C: src/game/t_24BA88.cpp .. t_2EB1C0.cpp

## Notes

- (Fixed by the integrator with `-fopt-stack`) saved `$s` registers used to come out as `sq`.
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
- Short loops cannot match yet: the original pads loops shorter than 6 instructions with nops before the closing
  branch (R5900 short-loop erratum, done by the original assembler). gcc puts the branch in `.set noreorder`, so
  modern gas `-mfix-r5900` does not help either. Toolchain question; skip functions with tiny loops.
- Division cannot match yet: the game has 292 `div`/`divu` and no `break 7`, so it was built without the
  divide-by-zero trap. Verified: func_00295098 and func_002950D8 (t_2949F0) MATCH when compiled with
  `-mno-check-zero-division` added to the flags. Skip functions with `/` or `%` until the flags change.
- Loops unrolled by 4 with a remainder prologue (t_2DCE78 func_002DD670/func_002DD490) and a 2-entry table scan
  (t_268EB8 func_00269888) point to `-funroll-loops`: func_00269888 written as a plain `for (i = 0; i < 2; i++)`
  loop MATCHES with `-funroll-loops` (instruction for instruction), and does not without it.
- Float constants with non-zero low bits (0.01f = 0x3C23D70A): the original builds them inline
  (`lui $at; ori $at; mtc1`), our gas puts gcc's `li.s` in `.lit4` (stray data). Skip unless a D_ constant exists.
- Masks like `and` with `-0x101`/`-0x201` then `sb` at +2: bitfields in a u32 (clear bit 8, bit 9, byte field at 16).
- A `$gp` scalar and a `%hi/%lo` access to the same symbol can coexist: declare the extra view with an asm label
  (`extern T name_x asm("D_...")`), but gas decides `$gp` per symbol, so macro-form `lw $4,D` uses cannot mix.

## Files

### t_2DAE48 (+11)
CFunc_GetButtonsReleased, CFunc_ResumeControllerChecking, func_002DC9D8, func_002DC9F0, func_002DB998,
func_002DB9B8, func_002DCAD0, CFunc_ShouldGameBePausedDueToSysNotification, func_002DCA08, func_002DBA28,
func_002DCB40
Round 2 after `-fopt-stack` (+11): func_002DBA80, func_002DCD20, func_002DCC30, func_002DB268, func_002DB510,
func_002DC670, func_002DB078, func_002DAE48, func_002DAEE0, func_002DAFB0, func_002DB7B8
Given up:
- CFunc_GetButtonsPressed: D_0036CDB4 needs the macro `lui` form here but `$gp` in func_002DCA08 (same file);
  the explicit split is scheduled before `addiu sp`. Otherwise matches.
- func_002DCC98: D_00368A38 read via `lui` and via `$gp` in the same function.
- func_002DC5B8, func_002DCB98 (constructors): unused byte-color local kept on the stack; not solved.

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

### t_296A10 (+17)
func_00297CC0, func_00298170, func_00296A10, func_00296AF0, func_002973C0, func_002974D8, func_00297528,
func_00297D18, func_00297D78, func_00297DD8, func_00297E38, func_00297F30, func_00297F90, func_00297FF0,
func_00298050, func_002980B0, func_00298110
(func_002974D8/func_00297528: red-black tree rotate left/right; func_00297Dxx..func_00298110: destructors that
unlink from an intrusive list and free through func_00119400(D_00368A38, p).)
Given up:
- func_002979D8 / func_00297838 (red-black tree increment/decrement): short loops, original has the R5900 nops.

### t_26F3B8 (+14)
func_00271180, func_00270EE0, func_00271158, func_00270E10, func_00271198, func_0026FFE8, func_00270FF0,
func_0026F7E8, func_00270020, func_002710B8, func_00271108, func_00270540, func_0026F6E8, func_0026F768
(func_00270EE0 shows DIFFERS in scripts/fcheck.py only because of the `nop` parsing bug; it matches.)
Given up:
- func_0026FAC8 (`a >= 22` as 0/1): original keeps a branch, every form gives slt/xori.
- func_0026F580: original copies the float arg to $f0 and stores it in the jal delay slot (4 forms tried).
- func_00270FC0: zeroes six globals; the macro-form (`lui $at`) store last must stay out of the `jr` delay slot,
  ours (sdata-attr array) is put in it. gcc `-mno-split-addresses` would give the original form.
- func_00270F08: short loops; func_002709C8: unrolled clear loop, not tried.

### t_273498 (+12)
func_00273910, func_00274AD8, func_00273CB8, func_00273B48, func_00274310, func_00274178, func_002741F8,
func_002750F0, func_002750A0, func_00273F08, func_00274688, func_00273D88
(func_00274688 shows DIFFERS in scripts/fcheck.py only because of the `nop` parsing bug; it matches.)
Given up:
- func_002741B8: gcc schedules `lui` before `move a1,a0`; the macro-form load of D_00368748 is costed as one insn
  by our sdata-attr trick (original compiler counted two).
- func_002738C0: original keeps `& 0xFF000000 & 0x08000000` as two `and`s; ours folds to a bit test.
- func_00273EB0: delay-slot stealing differs (`li v0,2` from the branch target), 4 forms tried.
- func_00275010: has an `alabel`.

### t_2949F0 (+9)
func_00295068, func_00296920, func_002969B0, func_002969E0, func_002965E8, func_00296948, func_00295E08,
func_00295DB8, func_002961C8
Given up:
- func_00295118: min() register allocation (copy in $a2, slt in $v1), 8 forms tried.
- func_00296550: original reloads p->unk1C after the first test; ours folds the redundant test.
- func_00295CF8: handwritten (`ei`).
Round 2 (+7): file now has `// cflags: -mno-check-zero-division`; func_00295098, func_002950D8, func_00295010,
func_00294FD0, func_00296678, func_002966D8, func_00296868 (strcmp/strcpy pair: declaring func_0030A970 as
returning `char *` moves the constant 1 to $v1).
- func_00296470 (constructor): store order of the embedded list node, 5 orders tried.
- func_00295D40: short loop.

### t_266800 (+5)
func_00268328, func_002668F8, func_00266850, func_00266800, func_00266B60
Given up:
- func_002682B8, func_00268228: float literals 0.01f/0.1f built inline by the original (see notes).
- func_00266E08, func_00266D20, func_00267B30, func_00266FA8: not tried (loops/unrolled clears).

### t_2DCE78 (+4)
CFunc_StartNetworkGame, func_002DD0B0, func_002DEE18, func_002DE220
Given up:
- func_002DE578: original keeps the node in $a0 and copies it to $v0 for the null test (2 forms tried).
- func_002DD0D0, func_002DD738: short loops. func_002DD288: D_0036F608 is read both via `$gp` and `lui` in
  one function. func_002DD670/func_002DD490/func_002DE638: loops unrolled by 4 (not tried).

### t_268EB8 (+5)
func_0026AC30, func_0026AE70, func_00269FE0, func_0026ABB8, func_00269F08
Given up:
- func_00269888: needs `-funroll-loops` (see notes).
- func_0026A368 (and the identical t_266800 func_00266E08): hash-chain lookup, not tried yet.

### t_260658 (+6)
CFunc_OnServer, CFunc_ResetTimer, CFunc_IncrementSongTimer, func_00260AC8, func_00260D50, CFunc_ResetSongTimer
Given up:
- CFunc_NotCD: D_00368748 read through macro `lui $v0` here but `$gp` in CFunc_CD/SetConfig of the same file;
  explicit split uses `$v1`.
- func_00261C98 (static init of an intrusive list head at D_0039A3C8): original builds the address with an
  unfolded `la` then `+4`; 3 forms tried.
