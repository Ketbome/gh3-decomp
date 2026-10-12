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

- **Volatile accesses and delay slots (toolchain finding, not fixed: scripts/ is not mine).** gcc prints
  `#.set volatile` / `#.set novolatile` (commented out) around every volatile load/store; SN's assembler kept those
  out of branch delay slots, our gas fills `jal`/`jr` delay slots with them. Rewriting them in
  `scripts/asm_filter.py` as `.set noreorder` / `.set reorder` makes t_292928 func_00293C00, func_00293C70 and
  func_00293218 (fields 8 and C volatile) MATCH, and every matched function of that file still matches (checked
  with a private fcheck copy). Likely also t_292928 func_002931F0 and t_26F3B8 func_00270FC0.
- **Systematic v0/v1 swap.** Many simple read-modify-write functions (`f = (f & ~0xF) | n`, `p->a += n; p->b += n`,
  `(x + 0x7FF) / 2048 * 2048`) get the loaded value in v1 and the constant in v0 in the original, the other way in
  ours; no source form or `-f` flag tried (-O3, -fno-schedule-insns[2], -fno-regmove, -fno-gcse, ...) changes it.
- **Mixed `$gp` / `lui` uses of one symbol now match** (round 3): keep the normal declaration (`extern T D_X;`, gas
  makes it `$gp` from gcc's `.extern D_X, 4`) and add a lui-form view through a gas alias:
  `asm(".set D_X_lui, D_X");` at the top, `extern T D_X_lui[] asm("D_X_lui") __attribute__((section(".sdata")));`.
  The alias has no `.extern` size so gas expands it with `lui`; relocations still name `D_X` (checked with objdump,
  the alias does not even reach the symbol table). Unblocks the old "read via `$gp` and `lui`" give-ups.
- `xori v0,v0,1` + `beqz` after a bool call: `bool missing = !f(...); if (missing)` (a direct `if (!f())` folds
  into `bnez`).
- `if (p) { ...; return 1; } return 0;` gives the `bnez` + `b end / v0 = 0` layout seen in most CFuncs.
- A 16-byte float struct with `__attribute__((aligned(16)))` on the struct is BLKmode (copied with lq/sq, kept on
  the stack); the original kept some in registers (`dsrl32`/`pcpyud` field extraction): not reproduced yet.
- `mfc1` followed by a use of the register: our gas inserts a `nop` (hazard), SN's did not. Toolchain question;
  skip functions where `cvt.w.s`/`mfc1` result is used by the next instruction.
- Two-case checksum `if/else if` laid out "second case first": write it as a `switch` (source order of cases).

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
Round 3 (+13): func_00275570, func_00275830, func_00275A40, func_00276D68, func_002756A8, func_00276720,
func_00277298, func_00276DC8/E88/F30/FD8, func_00277080, func_00277128 (pool-alloc templates; `.set` alias for
D_00368A38, D_00371088, D_00371098). func_00275A20/func_00276D48 wrappers now carry the real signatures.
- func_00276008, func_002762F0, func_00277378: short loops. func_00275898/func_002754C0/func_00276620: `alabel`.

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
- (SOLVED round 5: plain externs, last one `volatile`) func_00270FC0: zeroes six globals; the macro-form (`lui $at`) store last must stay out of the `jr` delay slot,
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
- (SOLVED round 5, inline li.s) func_002682B8, func_00268228.
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
- CFunc_NotCD (solved round 3): D_00368748 read through macro `lui $v0` here but `$gp` in CFunc_CD/SetConfig of the same file;
  explicit split uses `$v1`.
- (SOLVED round 5, see t_2647A8) func_00261C98 (static init of an intrusive list head at D_0039A3C8): original builds the address with an
  unfolded `la` then `+4`; 3 forms tried.

### Small batch across files (+10)
- t_2A12B0: CFunc_OverwriteCorruptMemcardContent
- t_26AEF8: func_0026C9E0, func_0026CA70
- t_29F288: func_0029F9F8
- t_2D4468: func_002D5BC0, func_002D5CB0
- t_2A74C0: func_002A7638
- t_2AD528: func_002AED50
- t_2DEE90: func_002DF4A0
- t_2E90B0: func_002EAE58
Given up:
- t_2C9AC0 CFunc_HideStencilShadow/CFunc_ClearMasterBloom/CFunc_HideDOF: matched in round 3 with the `.set` alias.
- t_292928 func_002931F0: original leaves the `jr` delay slot empty after two stores (modern gas fills it even
  with volatile stores).
- t_29F288 func_0029F578: dead stack store of 4 kept; ours turns `(x & 4) == 0` into a shift.
- t_2E7010 func_002E8C08: register allocation (base $v0, constant $v1).
- t_26D280 func_0026E138: one-entry table scan; looks like an unrolled loop (`-funroll-loops`).

### Wrapper batch (+9)
- t_268EB8: func_00269218, func_0026A740, func_0026A958 (call init, return this)
- t_26D280: func_0026DFC0; t_271480: func_00271590; t_2797A8: func_0027AA70; t_27D828: func_0027E488
- t_2A53A8: func_002A6C60; t_25C450: func_0025DFB8
Given up:
- t_282268 func_00283070: seven stores, 6 orders tried, scheduler order never matches.

### t_250010 (+34)
func_00250FF0, func_00251090, CFunc_SetShadowDir, CFunc_SetLightFlag, CFunc_ClearLightFlag, CFunc_MoveLight,
CFunc_SetLightDirection, CFunc_SetLightColor, CFunc_SetLightIntensity, CFunc_GetLightIntensity,
CFunc_GetLightGroupIntensity, CFunc_EnableLight, CFunc_DisableLight, CFunc_EnableLightGroup,
CFunc_DisableLightGroup, CFunc_AddLightToGroup, CFunc_AllowBoneLOD, CFunc_PlayIGCCam, CFunc_GetSkaterCamAnimParams,
CFunc_SkaterCamAnimFinished, CFunc_KillSkaterCamAnim, CFunc_IsTextureLoaded, CFunc_SetLightGroupIntensity,
CFunc_InitLightManager, CFunc_NudgeVC, CFunc_GetDisplaySettings, CFunc_InitAnimCompressTable, func_00251358,
CFunc_PlaySkaterCamAnim, func_00251F68, func_002509A0, CFunc_PlayMovie, CFunc_SetScreen, CFunc_UnloadTexture
Given up:
- CFunc_CreateLightGroup: original `move v1,v0; bnez v1` + `li v0,1 / v0 = 0`; every form gives `sltu` (5 tried).
- CFunc_SetLightVolumeParams: arg moves order (a0 last, in the jal delay slot); 2 forms tried.
- CFunc_GetLightDirection: light->dir kept in a TImode register (see notes); 3 forms tried.
- CFunc_GetLightColor: matches except the `mfc1` hazard nops (see notes).
- func_00250A18 (dead stores at sp+0xA0/0xA4), CFunc_HackAddLight (pextlw vector build), CFunc_UpdateAnimCache,
  func_00251CA0 (ldl/ldr struct copy): not tried yet.

### t_2C9AC0 (+10)
CFunc_HideStencilShadow, CFunc_ClearMasterBloom, CFunc_HideDOF (`.set` alias), CFunc_fretbar_iterator_CFunc_Setup,
CFunc_fretbar_update_tempo_CFunc_Setup, CFunc_fretbar_update_hammer_on_tolerance_CFunc_Setup, CFunc_Increment,
CFunc_StarPowerFastTest_Initialise, CFunc_handle_hit_note_CFunc, CFunc_SetLastGuitarVolume
Given up:
- CFunc_UpdateNixie: -1 built as 64-bit `lui/ori 0xffff` and scheduled before the index; 4 forms tried.
- func_002CA818: original loads the call result into a0 last (jal delay slot), same as t_250010
  CFunc_SetLightVolumeParams; member-call form tried too.

### Round 3 retries with the `.set` alias (+4)
- t_2DAE48: CFunc_GetButtonsPressed (`pads++` at the end of the loop body), func_002DCC98
- t_254248: CFunc_ClearSoundBank (reverse alias: `.set D_00370AE0_gp, D_00370AE0` + scalar `extern int ... asm(...)`)
- t_260658: CFunc_NotCD (`return D ^ 1`)
Given up:
- t_2DCE78 func_002DD288 (now only a layout problem): original keeps separate `b end / v0 = 0` returns and leaves
  call delay slots empty; plain, volatile and guard-object forms tried.

### t_288B10 (+17)
func_002896E0, func_00289710, func_00289868, func_00288D88, func_00288DC0, func_00288DF8, func_00289CF8,
func_0028A558, func_00289898, func_002898E8, func_00289C88, func_00288E30, func_00288B10 (`delete` through a
virtual destructor, vptr at 0xC), func_00288B88, func_00289048, func_002897E8, func_00289750
(S288_Val: {obj, value, flags}; low 4 bits of flags = type, bit 6 tested with `((u32)f >> 6) & 1`; the
virtual-call wrappers pass their incoming a1 through as the first argument.)
Given up:
- func_00288C00, func_00288C48, func_00288D20, func_00288C90: `type = n` (`(f & ~0xF) | n`) allocates the loaded
  word in v1 and -16 in v0; original the other way. Bitfield, temp, `&= ; |=`, operand-order forms tried.
- func_0028AAC0: arg moves order (a0 last, in the jal delay slot); `&a` of the parameter fixed the rest.
- func_002891A8, func_00289228: original reloads p->unk4 before the loop and has a `nop` before the loop label;
  3 forms tried.
- func_00289E10: handle-assign inline; everything matches except the original keeps the second `if (obj)`
  after the inlined setter (ours folds it). 4 forms tried.
- func_00289938: starts with a stray `addiu sp,0x10; nop` fragment (split boundary).

### t_292928 (+11)
func_00292D70, func_002939A0, func_002939D8, func_00293A08, func_002934D0, func_00292BB0, func_00293BB8,
func_00293678, func_00294818, func_00293A38 (32-byte local), func_002947C0 (`volatile` hardware registers)
Wrappers func_002934A8/func_00293578 now carry their real signatures.
Given up:
- func_00293C00, func_00293C70, func_00293218: match only with the volatile delay-slot fix (see notes).
- func_00293288, func_002932E0, func_00293FD0, func_00294868, func_00293038: v0/v1 swap (see notes).
- func_00293530 (16-byte struct argument in a1/a2 copied to the stack): ours builds a second copy.
- func_00293D08: store scheduling around a semaphore-param struct. (SOLVED round 5 with plain externs:
  func_002930B8, func_00292FB0.)

### t_27B7D0 (+26, script structure components)
Getters func_0027D188/D1F8/D268/D400/D470 (+ name wrappers func_0027CFA8/D000/D058/D0B0/D118), func_0027D378;
adders func_0027C0D0/C160/C1F8/C448/C740/C898/C028/C5B0/CB80/C4D8/C678/C7D0/C928; func_0027B800, func_0027BFD0.
(Component: u32 bitfield word {b0:8, b8:1, type:7} + u16 at 2, key, value, next. The inline constructor clears
b8/type/u16/next/value; `next = 0` before `value = 0` except in the int/float adders. Types seen: 1 int, 2 float,
3 string, 5 pair, 6 vector, 7 blob, 0xA structure, 0xC array, 0xD checksum, 0x1A name.)
Given up:
- func_0027D4E0: saved-register assignment (key/out/req in s3/s1/s2); 3 forms tried.
- func_0027D2D8 (vector getter, pextlw build of {x,y,z,1.0f}), func_0027B7D0/func_0027BF30: short loops / not tried.

### t_28CC70 (+20, object list walkers over func_002899B0)
func_0028DAD8, func_0028DBD0, func_0028EB50, func_0028DE38, func_0028EAC0, func_0028EB18, func_0028D168,
func_0028CE18, func_0028DA40, func_0028CD90, func_0028CE90, func_0028D668, func_0028D7D8, func_0028CCE8,
func_0028D720, func_0028D878, func_0028D490, func_0028D940, func_0028DC30, func_0028E220
(Single-call walk `a0 = 0; b test; ...; a0 = s0; test: jal` = `for (p = next(0); p; p = next(p))` (cross-jumped);
`p = next(0); while (p) { n = next(p); ...; p = n; }` for the two-call form. `srl/andi/bnezl` bit test =
inline `bool B1() { return (*(u32 *)this >> 1) & 1; }`; `hit = a || b || c` as a 0/1 flag = `bool hit = ...; if (hit)`.
func_0028D490: 10-arg call, arg loads ordered by declaring locals for a0, a2, t0, t1 first.)
Given up:
- func_0028DA08: original keeps the first `return 0` inline (`bnezl`); 6 forms tried (inline member gets close).
- func_0028DDE8, func_0028CC70, func_0028DCF8, func_0028D098: saved-register assignment of the args (3-4 forms each).
- func_0028E610: only the prologue save order (s0/s2) differs; 3 forms tried. func_0028E4F8 (same pattern in a
  loop): original keeps `n - 1 != -1` unfolded.
- func_0028DB50: original hoists `a == 0` (sltiu) after the duplicated loop test; bool local gets it except prologue.
- func_0028D578: short loops. func_0028E8A0/func_0028E9B0: loops unrolled (`-funroll-loops`, not set for the file).
- 0x4/0xC functions (`addiu sp; nop`) are split fragments.

### t_24DDB8 (+29, math/render CFuncs) — file now has `// cflags: -ffast-math`
CFunc_SetProgressive, CFunc_SetRenderMode, CFunc_SetWireframeMode, CFunc_ResetTextureAnim, CFunc_StopTextureAnim,
CFunc_EnableExplicitUVWibble, CFunc_DisableExplicitUVWibble, func_0024F4B8, CFunc_DebugRenderIgnore,
CFunc_StartTextureAnim, CFunc_Anim_GetAnimLength, CFunc_GetMetrics, CFunc_MathCeil, CFunc_MathFloor,
CFunc_GetCurrentCameraObject, CFunc_SetUVWibbleOffsets, CFunc_Clamp, CFunc_GetCurrentGeomStats,
CFunc_ScreenFX_AddFXInstance/ClearFXInstances/FxInstanceExists/RemoveFXInstance/UpdateFXInstanceParams,
CFunc_MathMin, CFunc_MathPow, CFunc_DebugLine, CFunc_SetUVWibbleParams
(`min.s`/`max.s` need `-ffast-math` (as t_1298B0): `x < y ? x : y` emits `min.s y, x`. Inlined required
GetFloat = `if (func_0027CC30(p, key, 2, &v)) f = v; else { func_0027F1E0(p, 0, 1); f = 0.0f; }` with a fresh `v`
per call. `script->unk20` loaded before a libm call: put it in a local first. Virtual call through vptr at 0x44,
entry 0x50 = 10th virtual (entry n at 8*n).)
Given up:
- CFunc_SetClippingDistances: only `sd ra` vs `ori a1` order in the prologue (inline setter fixed the body).
- CFunc_LinearMap: original has two `nop`s before `div.s` (assembler hazard padding we do not reproduce).
- CFunc_CompressVC: list walk with `movn`; loop variable register / load order differ (7 forms).
- CFunc_VCWibblePlayFromKeyframe: sdata-attr macro load of D_0036F658 goes into a branch delay slot (original
  counted it as 2 insns); plain extern splits through v0 instead of a1. Rest of the structure matches.
- CFunc_FeelerCheck (TImode vector fields), CFunc_ToggleRenderMetrics/func_0024E3C0 (handle refs), not tried.

### t_2A12B0 (+27)
func_002A12B0..func_002A1670 (13 destructors: set vtable at +0xC, call the base dtor, free with func_00119400 when
`flags & 1`), func_002A1840, func_002A2200, func_002A2230, func_002A18E0, func_002A1888, CFunc_c_PauseGame,
CFunc_GameIsPaused, CFunc_Create, CFunc_DEBUG_set_DofZDepth, CFunc_NodeArrayManLoad, CFunc_LoadNodeArray,
CFunc_SetGSIdleProcParams, CFunc_SpawnSound, CFunc_ReLoadNodeArray
(`$gp` views of D_00372EF0/D_0036F608 via `.set X_gp, X` + scalar asm-label extern, since the file declares
them as sdata arrays; D_0036CA58 is stored both ways in one function: scalar + `_lui` alias.
CFunc_NodeArrayManLoad/Unload now take `(params, script)`; ReLoadNodeArray calls them with both.)
Given up:
- func_002A2E68, func_002A2FB0: inlined hash-table lookup inside a `movn` list walk (same walk as t_24DDB8
  CFunc_CompressVC, which does not match); not tried further.
- func_002A1830/func_002A3218 etc.: split fragments.

### t_260658 round 2 (+21)
CFunc_GetSongTime, CFunc_GetTrueStartTime, CFunc_GetStartTime, CFunc_SetMovementVelocity, CFunc_SetRotateVelocity,
CFunc_SetServerMode, CFunc_AllowAssetLoading, CFunc_SetSearchAllAssetContexts, CFunc_GetMicroseconds,
CFunc_PushAssetContext, CFunc_SetDeltaTime, CFunc_Randomize, CFunc_GetSongTimeMs, CFunc_GetDeltaTime,
CFunc_LoadNetworkDrivers, CFunc_GetTerritory, CFunc_SetNetworkMode, CFunc_TimeMarkerReached_SetParams,
CFunc_LaunchViewer, CFunc_GetLocalSystemTime, CFunc_TimeMarkerReached
(GetTerritory: case tree rooted at 1 = `case 2/1/3` plus `case 0: default:` (cases 1..3 alone root at 2).
PushAssetContext: `int i = n + 1; u32 *p = &a[i]; n = i; *p = v;` fixes register choice. TimeMarkerReached: script
array accessor `size == 1 ? data : ((int *)data)[i]` as an inline member.)
Given up:
- func_00260D98: matches except the double constant 0.001f: gcc emits `li.d $5,...` which SN's assembler expanded
  to `li 0xfd41; dsll; ori; dsll; ori; dsll 14` (asm_filter only rewrites li.s; toolchain question).
- CFunc_TimeGreaterThan: u32->float conversion; original leaves the `b` delay slot empty after cvt.s.w.
- CFunc_CenterCamera, CFunc_SkatersAreReady: `movn`/`movz` list walks (see t_24DDB8 CompressVC).
- Cutscene destroy-list functions, PlayCutscene (ldl/ldr struct copy), TestNetSetup, SetConfig: not tried.

### t_2626E0 (+18, viewer/controller CFuncs)
CFunc_ClearViewerObject, CFunc_DestroyViewport, CFunc_IsPS2, CFunc_LoadExecPS2, CFunc_SetScreenMode,
CFunc_ViewportExists, CFunc_GetPlatformExt, CFunc_GetScreenMode, CFunc_ResetModelViewerCamera, CFunc_SetViewMode,
CFunc_SetViewerModel, CFunc_SetViewerAnim, CFunc_GetViewerObjectID, CFunc_SetViewportProperties,
CFunc_SetViewerLODDist, CFunc_VibrateController, CFunc_ReloadViewerAnim, CFunc_CreateViewport
(IsPS2: `x == 1 || x == 2 || x == 3` on a global folds into a range test; reading the global through an inline
getter per comparison (`Platform() == 1 || Platform() == 2 ...`) keeps the beq chain.)
Given up:
- CFunc_ControllerPressed/CFunc_ControllerMake (match except one `nop` the original has before the 8-aligned
  `return 0` label), CFunc_EnableActuators (same: `nop` before an 8-aligned branch target). Assembler/toolchain
  question like the short-loop nops.
- CFunc_BindFrontEndToController: register choice for the pad table pointer (2 forms).
- CFunc_ResetPS2/CFunc_ResetHD: loops with `nop nop` after the jal (short-loop padding).

### t_258420 (+22, script-control CFuncs)
CFunc_IsTrue, CFunc_EnableScriptPrintf, CFunc_ClearEventHandler, CFunc_IsPair, CFunc_AddFlag, CFunc_GotParam,
CFunc_OnExceptionRun, CFunc_IsStructure, CFunc_GenerateUTF16FromASCII, CFunc_ScriptAssert, CFunc_ScriptIsRunning,
CFunc_ClearEventHandlerGroup, CFunc_AppendSuffixToChecksum, CFunc_Goto, CFunc_ExtendCrc,
CFunc_ResetEventHandlersFromTable, CFunc_GetLowerCaseString, CFunc_GetUpperCaseString, CFunc_Block,
CFunc_SetExceptionHandler, CFunc_MangleChecksums, CFunc_StructureContains
(`xori v0,1; beqz` needs the callee declared `bool` (asm-label alias `func_0027D870_b`), then
`bool missing = !f(); if (missing)`.)
Given up:
- CFunc_SetEventHandler: `b = resp == K` comes out `sltiu`; original computes it as `sltu v0,s1,v0; xori` using the
  zeroed register of `b`, and the two flag registers are swapped (1 form).
- CFunc_ScriptExists, CFunc_SymbolIsCFunc, CFunc_CleanUpAndRemoveSymbol: inlined symbol-hash lookups with short loops.

### t_2A53A8 (+14, memory card CFuncs)
func_002A53A8, CFunc_CardIsNew, func_002A54C8, CFunc_CardIsFormatted, func_002A6E50, func_002A6B70,
CFunc_DeleteMemCardFile, CFunc_MemCardSystemInitialize, CFunc_SetSaveFileName, CFunc_FormatCard,
CFunc_GetMemCardSpaceRequired, CFunc_SaveToMemoryCard, func_002A6730 (destructor), CFunc_GetMemCardSpaceAvailable
(Three global stores came out rotated: source order DAD0, DAD4, DAD8 gives the original DAD4, DAD8, DAD0.)
Given up / not tried:
- (SOLVED round 5, see t_2647A8) func_002A6700 (self-linked list head at D_003AAD80+4 built as `la` then `+4`, same as t_260658 func_00261C98).
- func_002A6678, func_002A67B8: split fragments.

### Toolchain notes for the integrator (round 4)
- `li.d` (double constant into a GPR, soft-float): SN's assembler expanded it to `li; dsll; ori; dsll; ...`, our gas
  rejects `li.d` on r5900. Blocks t_260658 func_00260D98.
- Several functions match except for one `nop` the original has right before an 8-byte aligned branch-target label
  (t_2626E0 CFunc_ControllerPressed/ControllerMake/EnableActuators). Looks like assembler padding, not gcc.

### Round 5: retries after the one-pass assembler filter (+5)
- t_26F3B8 func_00270FC0, t_292928 func_002930B8/func_00292FB0, t_266800 func_00268228/func_002682B8.
- A global store that the original keeps out of the `jr` delay slot (lui/%lo form): declare that global
  `volatile` (gcc does not put volatile insns in delay slots, and the macro expansion is `.set noreorder`).
- Still failing: t_273498 func_002741B8 (scheduler puts `lui` of the address arg before `move a1,a0`, 4 forms);
  t_24DDB8 CFunc_VCWibblePlayFromKeyframe (unknown-size `extern int D[]` fixes the load, but the two zero inits are
  put in delay slots, 3 forms); t_260658 func_00260D98 (`li.d` of 0.001f-as-double: low word non-zero, gas puts it
  in .rodata; a u64 constant gives gas's different `dli` sequence); t_292928 func_002931F0/func_00293218 (volatile
  struct stores still pulled into delay slots by gas).

### t_2647A8 (+18)
CFunc_CreateViewportTextureOverride, CFunc_AddPrepassViewport, CFunc_PrepassViewportExists,
CFunc_RemovePrepassViewport, CFunc_AddZoneProfiles, CFunc_RemoveZoneProfiles, CFunc_SetZoneProfiles,
CFunc_CreateRandomAppearance, CFunc_AddEditableList, CFunc_RemoveEditableList, CFunc_ForEachInEditableList,
CFunc_SelectFrom, func_00264BE8, func_00264F60, func_00264F90, func_00265680, func_002663F8, func_00266780
(Static-init list head `la D; +4` unfolded: `D.head.next = &D.head; D.head.next->prev = &D.head;` -- also solved
t_260658 func_00261C98 and t_2A53A8 func_002A6700. Stack slot order sp+0 = third out param, +4/+8 the first two:
a `u32 v[3]` local. List clear: load `D.head.unk4` first, then store unk4 before unk0.)
Given up:
- func_00264B70: address of D_0039A4F0 built in v0 instead of v1 (v0/v1 swap, 3 forms).
- func_00265388, func_00265008, func_00265580, func_002664F8 (STL list/vector copies), func_00266428 (short loop).

### t_256260 (+19) -- file now has `// cflags: -funroll-loops`
CFunc_PauseAllSounds, CFunc_SetPositionalSoundSilenceOverrideMode, CFunc_ResetWhammyPitchShift,
CFunc_SetMenuMusicVolume, CFunc_CastToInteger, CFunc_IntegerEquals, CFunc_ChecksumEquals, CFunc_StringEquals,
CFunc_LocalizedStringEquals, CFunc_RemoveComponent, CFunc_RemoveParameter, CFunc_RemoveFlag, CFunc_AddParams,
CFunc_WideStringToInteger, CFunc_GetArraySize, CFunc_StringToInteger (strlen-counted loop unrolled by 4),
CFunc_ArrayContains, func_00256340, func_00256848
(`if (r) goto done; ... return r; done: return r;` inside a list walk gives the plain `bnez` to the epilogue that
`return r` turns into `bnezl`. A value loaded right after a call and before the result test (`lw t2,0x20(s1)`):
read it into a local there. `int r = 0; if (x) { f(x); r = 1; } return r;` gives `beqz` + `v0 = 0` delay.)
Given up:
- CFunc_GetRandomValue: needs the `nop` SN's assembler put between `mtc1` and `cvt.s.w` (toolchain); rest matched.
- CFunc_GetElement: args of the final calls (`script->unk20` loaded before the inner call, `move a0` before
  `move a2`) and an unfilled `beqz` delay slot; 5 forms (locals, member calls with asm labels).
- CFunc_HackSetReverbPlease, CFunc_AddSfxHeader: flag set by branches (original keeps `x = 0; if (c == K) x = 1`
  as branches / uses the `missing` register in an sltu); 3 forms each.
- CFunc_GetTerrainTypeParam: original keeps `&y` (sp+4) in s0 across the first call; 2 forms.
- CFunc_GlobalExists: not tried. func_00256838/func_002571C8: split fragments.

### t_2908A0 (+14, script loop stack / intrusive node list)
func_002908A0, func_00290908, func_002909A8, func_00290BD0, func_00290CA0, func_00290D18, func_00290D68,
func_00290FE8, func_00291020, func_00291080, func_00291900, func_00291D00, func_00292078
(func_00290908: unrotated `while` (test at top, `b` back) came from `if (f()) { g(); continue; } break;` as the
end of the body. Stores of two zeroes come out in reverse source order. `delete` of a non-virtual object =
`if (n) dtor(n, 3)`. Loop labels get an 8-byte `.align` nop from gcc itself.)
Given up:
- func_00290A40: original enters the loop with `b test` (test at the bottom, decrement shares its address);
  5 loop forms give the duplicated-test shape.
- func_00290C40 (fragment + `alabel`), func_00291C40/func_00291F08/func_00291FC0/func_00292130 (hash table, short
  loops in 291FC0): not tried.
