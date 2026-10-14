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
- (SOLVED round 5 after the short-loop fix) func_002979D8 / func_00297838 (red-black tree increment/decrement).

### t_26F3B8 (+14)
func_00271180, func_00270EE0, func_00271158, func_00270E10, func_00271198, func_0026FFE8, func_00270FF0,
func_0026F7E8, func_00270020, func_002710B8, func_00271108, func_00270540, func_0026F6E8, func_0026F768
(func_00270EE0 shows DIFFERS in scripts/fcheck.py only because of the `nop` parsing bug; it matches.)
Given up:
- func_0026FAC8 (`a >= 22` as 0/1): original keeps a branch, every form gives slt/xori.
- func_0026F580: original copies the float arg to $f0 and stores it in the jal delay slot (4 forms tried).
- (SOLVED round 5: plain externs, last one `volatile`) func_00270FC0: zeroes six globals; the macro-form (`lui $at`) store last must stay out of the `jr` delay slot,
  ours (sdata-attr array) is put in it. gcc `-mno-split-addresses` would give the original form.
- func_00270F08: see round 5. (SOLVED round 5, file now `-funroll-loops`) func_002709C8 (nested 2x22 slot clear).

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
- (SOLVED round 5, file now `-funroll-loops`) func_00266FA8 (`for (i = 127; i >= 0; i--)` clear), func_00267B30
  (two groups of three float stores come out in reverse group order). func_00266E08, func_00266D20: not tried.

### t_2DCE78 (+4)
CFunc_StartNetworkGame, func_002DD0B0, func_002DEE18, func_002DE220
Given up:
- (SOLVED round 5: func_002DD0D0, func_002DD738 -- `do { i -= 0x19; } while (i != -1);` array-ctor loop)
- func_002DE578: original keeps the node in $a0 and copies it to $v0 for the null test (2 forms tried).
- func_002DD0D0, func_002DD738: short loops. func_002DD288: D_0036F608 is read both via `$gp` and `lui` in
  one function. func_002DD670/func_002DD490/func_002DE638: loops unrolled by 4 (not tried).

### t_268EB8 (+5)
func_0026AC30, func_0026AE70, func_00269FE0, func_0026ABB8, func_00269F08
Given up:
- (SOLVED round 5, file now `-funroll-loops`) func_00269888.
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
- (SOLVED round 5, t_26D280 now `-funroll-loops`) t_26D280 func_0026E138: one-entry table scan loop.

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
- CFunc_GetLightColor: retried after the mfc1 fix: original converts through a pointer to the stack vector (`addiu a3,sp,16`, interleaved `sb`); plain, inline, and unrolled-loop forms (with -funroll-loops) all reorder. 5 forms.
- func_00250A18 (dead stores at sp+0xA0/0xA4), CFunc_HackAddLight (pextlw vector build), CFunc_UpdateAnimCache,
  (func_00251CA0 SOLVED round 5: 8-byte key struct passed by value; `m = ...->unk308` read into a local first.)

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
- func_0028D578: hash lookup + alias chase (see t_2754A0 func_00276008). (SOLVED round 5, file now `-funroll-loops`:
  func_0028E8A0 (CScript ctor: component array-ctor loop written `for (i = 19; i != -1; i--) { inline clears; c++; }`),
  func_0028E9B0 (one `int i` shared by both loops).)
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
- CFunc_PlayCutscene (round 5): by-value key struct fine, but the `D_0036CDB4` load is scheduled into the memset
  `jal` delay slot (original counted the macro load as 2 insns); scalar, unknown-size and volatile forms fail.
- Cutscene destroy-list functions, TestNetSetup, SetConfig: not tried.

### t_2626E0 (+18, viewer/controller CFuncs)
CFunc_ClearViewerObject, CFunc_DestroyViewport, CFunc_IsPS2, CFunc_LoadExecPS2, CFunc_SetScreenMode,
CFunc_ViewportExists, CFunc_GetPlatformExt, CFunc_GetScreenMode, CFunc_ResetModelViewerCamera, CFunc_SetViewMode,
CFunc_SetViewerModel, CFunc_SetViewerAnim, CFunc_GetViewerObjectID, CFunc_SetViewportProperties,
CFunc_SetViewerLODDist, CFunc_VibrateController, CFunc_ReloadViewerAnim, CFunc_CreateViewport
(IsPS2: `x == 1 || x == 2 || x == 3` on a global folds into a range test; reading the global through an inline
getter per comparison (`Platform() == 1 || Platform() == 2 ...`) keeps the beq chain.)
Given up:
- (SOLVED round 5) CFunc_ControllerPressed/CFunc_ControllerMake/CFunc_EnableActuators: the `nop` is the loop
  alignment of a 2-iteration loop fully unrolled; the file now has `// cflags: -funroll-loops`.
- CFunc_BindFrontEndToController: register choice for the pad table pointer (2 forms).
- (SOLVED round 5 after the short-loop fix) CFunc_ResetPS2/CFunc_ResetHD.

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
- (SOLVED after the mfc1 prelude fix: `if (a > b)` swap) CFunc_GetRandomValue.
- CFunc_GetElement: args of the final calls (`script->unk20` loaded before the inner call, `move a0` before
  `move a2`) and an unfilled `beqz` delay slot; 5 forms (locals, member calls with asm labels).
- CFunc_HackSetReverbPlease, CFunc_AddSfxHeader: flag set by branches (original keeps `x = 0; if (c == K) x = 1`
  as branches / uses the `missing` register in an sltu); 3 forms each.
- CFunc_GetTerrainTypeParam: original keeps `&y` (sp+4) in s0 across the first call; 2 forms.
- CFunc_GlobalExists: not tried. func_00256838/func_002571C8: split fragments.

### t_2908A0 (+14, script loop stack / intrusive node list)
func_002908A0, func_00290908, func_002909A8, func_00290BD0, func_00290CA0, func_00290D18, func_00290D68,
func_00290FE8, func_00291020, func_00291080, func_00291900, func_00291D00, func_00292078, func_00291C40 (pool free)
(func_00290908: unrotated `while` (test at top, `b` back) came from `if (f()) { g(); continue; } break;` as the
end of the body. Stores of two zeroes come out in reverse source order. `delete` of a non-virtual object =
`if (n) dtor(n, 3)`. Loop labels get an 8-byte `.align` nop from gcc itself.)
Given up:
- func_00290A40: original enters the loop with `b test` (test at the bottom, decrement shares its address);
  5 loop forms give the duplicated-test shape.
- func_00290C40 (fragment + `alabel`), func_00291C40/func_00291F08/func_00291FC0/func_00292130 (hash table, short
  loops in 291FC0): not tried.

### t_286A60 (+13)
func_00287578, func_00287EB0, func_00287EF0, func_00287F50, func_002880B8, func_00288170, func_002881F8,
func_00288238, func_00288410, func_002886F8, func_002887D8, func_00288808, func_00288910
(Pool free templates: `if (pl && pl->Has(p))` with `Has` an inline `p >= start && p < end`, and the pool index
global read again for `[idx ^ 1]`. A `la` of an extern 8-byte array the original expanded to lui/addiu: keep the
old `extern T D[] __attribute__((section(".sdata")))` declaration (asm_filter does not rewrite `la`).
func_00288678+8 is a real function start: referenced as `(char *)func_00288678 + 8`.)
Given up:
- func_00288888: bit-7 test is `lbu; dsrl 7` in the original; u32 bitfield, inline bool getter and u8 read give
  `andi`/`srl` (3 forms).
- func_00288000 (pool alloc): `if (r) return r;` comes out `bnez` (gcc knows v0 == s0) instead of
  `bnezl` + `move v0,s0`; 4 forms.
- func_002874A8 (movz bracket counter loop), func_00288A20, func_002882E8, func_002884A0: not tried.
- func_00286A60/func_00287498/func_002882C0/func_002882D8/func_00287F30/func_00288778/func_00288990: fragments.

### t_2754A0 round 5 (+7, pool create templates)
func_00276DC8, func_00276E88, func_00276F30, func_00276FD8, func_00277080, func_00277128
(`void **slot = &pools[cur]; *slot = func_0011C130(func_00118F20(heap, 0x70, 1, 0), size, a, b, 1, 0);
flags[cur] = 1;` -- the slot address is computed before the calls. The round-3 entries for these six and for
func_002756A8, func_00276720, func_00277298 were not in the file (lost before commit); the six are now in,
plus func_002756A8 (strdup into heap 5).)
- func_00277298: original adds the region sizes to the `D_7000100` address in registers (`lui/ori` + `addu`);
  gcc folds symbol+constant. func_00276720: pool alloc, same problem as t_286A60 func_00288000.

### t_28AB28 (+8) -- file now has `// cflags: -funroll-loops`
func_0028AB70, func_0028ADE8, func_0028B738, func_0028B7D0, func_0028B840, func_0028B910, func_0028C590,
func_0028C770 (search loops unrolled by 4); func_0028C570 now forwards `(p, v)`.
(Flag test kept as `srl 10; andi 1`: inline `bool B10() { return (word >> 10) & 1; }`; clears of two bits as
1-bit bitfields keep two `and`s; `b = !b` written as `if (b) b = 0; else b = 1;` stays branchy. vptr placed
after the data members: data that follows the vptr goes in a derived struct.)
Given up:
- func_0028ACA8, func_0028AD40: push `stack[++n] = v` gives `addu base,idx` (original `addu idx,base`) and the
  pop load is scheduled differently; 4 forms (inline Push/Pop).
- func_0028BE80: 2-case switch tree rooted at 0x20 here, at 0x21 in the original (case order does not matter).
- func_0028C518, func_0028C4B0: u32->float; the original leaves the `b` delay slot after `cvt.s.w` empty (gas
  fills it). Toolchain.

### Round 5 retries after the short-loop / `la` / usd fixes (+4)
- t_296A10 func_002979D8, func_00297838; t_2DCE78 func_002DD0D0, func_002DD738.
- Still failing: t_2949F0 func_00295D40 (store scheduling at the end: the original counted the lui-form store as
  2 insns; 4 orders); t_26F3B8 func_00270F08 (two copies of the bit-scan loop, `li v1,1` hoisted; 3 forms);
  t_2754A0 func_00276008/func_002762F0 (hash lookup + alias chase; loop shapes differ, 2 forms).
- Note: t_2DCE78 cannot take `-funroll-loops` (func_002DD738's empty array-ctor loop disappears), so its
  unrolled-by-4 functions stay.

### t_24BA88 (+6) -- file now has `// cflags: -funroll-loops`
CFunc_ProximCleanup, CFunc_DestroyParticlesByGroupID, CFunc_UnloadQB (15-entry clear unrolled by 5),
CFunc_GetFileNameFromPath (`if (!s) {...} else {...}` order and two calls cross-jumped), CFunc_DestroyAllFastParticles,
CFunc_LoadQB (two out locals in a local struct to get their stack order)
(Virtual call vptr/fn register choice depends on the declared return type: int vs void.)
Given up:
- CFunc_Sqrt: with `-ffast-math` + `__builtin_sqrtf` only the `lwc1; nop; nop; sqrt.s` placement differs (SN
  assembler hazard nops before sqrt.s, like the `div.s` nops of t_24DDB8 CFunc_LinearMap). Toolchain.
- func_0024D068, func_0024D128: pool alloc (same as t_286A60 func_00288000).
- CFunc_GetVectorComponents (TImode vector), CFunc_StringRemove, CFunc_IsInArray, ...: not tried.

### t_29D230 (+10, object list iterators)
func_0029D238, func_0029D530, func_0029D5C8, func_0029D600, func_0029D630, func_0029D688, func_0029D838,
func_0029D898, func_0029D9A8, func_0029EC08
(Iterator object on the stack {?, cur, vptr at 8}: the inline ctor/dtor are explicit `it.vptr = D_0034ACA8`
stores, the dtor store at every exit. `n->unk4 == -1 ? 0 : n` as an inline function gives the extra
`move v0,v1`. `delete obj` on a class whose vptr is at 0x3160.)
Given up:
- func_0029D8F8: second list walk with inline begin/next; original keeps separate exits; 1 form.
- func_0029E388/func_0029E548 etc.: fragments with the real function after a stack-fix prefix (no label).

### t_298A30 (+14)
func_00298A30, func_002999C8, func_00299A08, func_00299A48 (dtors: vptr at 8 + optional free), func_00298A70
(dtor + unlink, self-link stores written 0x10 then 0xC), func_0029A660, func_0029A740, func_0029A778,
func_0029A5F0 (virtual calls through the vptr at 0x2418; `v4` declared returning int for its register choice),
func_00299CB8, func_0029A6A8 (iterator walk), func_00299838 (`now = *t->unk10` read before the test; min via
`if (d > lim) d = lim` -> movn), func_00299640, func_002997D0 (message struct built on the stack)
Given up:
- func_0029A590: soft-float double constant built with `dli` (low word non-zero; gas gives a different
  sequence; toolchain, as t_260658 func_00260D98).

### t_2A32E0 (+8)
CFunc_SetSaveZoneNameToCurrent, CFunc_DoesWaypointExist, CFunc_GetSlomo, CFunc_ProfileTasks, CFunc_Debounce,
func_002A4AF0, func_002A4A78, func_002A4940 (factory: vptr stored twice, base then derived)
(`if (...) { ...; return 1; } return 1;` keeps the `li v0,1` duplicated in both paths like the original.)
Given up:
- CFunc_IsObjectDestructing: bit-7 flag test `lbu; dsrl 7; bnez` (same as t_286A60 func_00288888); u32 and u64
  bitfields give `lw/andi`.
- func_002A3818: `if (a == K) r = K2;` is if-converted to movz here, branchy in the original; 2 forms.
- CFunc_GetWaypointPos/Dir (TImode vector kept in s0), CFunc_DestroyZoneEntities, func_002A4B50: not tried.

### t_25A428 (+8)
CFunc_UnPauseSpawnedScript, CFunc_PauseSpawnedScripts, CFunc_DumpScripts, CFunc_SpawnScript (returns
func_0025AA28's result), CFunc_OnExitRun, CFunc_KillSpawnedScript, CFunc_StringLength, CFunc_Toggle2d
Given up:
- CFunc_CanPop: original keeps `xori 1; sltiu 1` on the second bool result (`!!b`), gcc folds it; 3 forms.

### Toolchain notes for the integrator (round 5)
- `li.d` / `dli` of a double whose low word is non-zero (0.001f as double): gas puts li.d in .rodata and expands
  dli differently from SN (`li hi; dsll 16; ori; dsll 16; ori; dsll n` with trailing-zero shift). Blocks
  t_260658 func_00260D98, t_298A30 func_0029A590.
- u32->float conversion: SN left the `b` delay slot after `cvt.s.w` empty; gas fills it (t_28AB28 func_0028C518,
  func_0028C4B0; t_260658 CFunc_TimeGreaterThan).
- `sqrt.s` / `div.s`: SN put two nops before them after a `lwc1` (t_24BA88 CFunc_Sqrt, t_24DDB8 CFunc_LinearMap).
- -O0 files t_2E2FB0/t_2E4FD0 are C (`-x c`, no `-fopt-stack`), and SN's assembler did not fill delay slots at
  -O0 (gcc emits them in reorder mode); with `// cflags: -O0 -fno-opt-stack -x c` only the gas delay-slot
  filling differs. t_2E4FD0 also has -O2 functions (func_002E6340..).
- Volatile struct-field stores are still moved into `jr`/`jal` delay slots by gas (t_292928 func_002931F0,
  func_00293218).

### Round 6 (agent C7), small functions across the range
Matched (46): t_2CBC10 func_002CC540, func_002CC570, CFunc_Drum/FretFingers_iterator_CFunc_Setup, gem_array_stepper,
kill_object_later Setup; t_2CDCC0 Note_Window_Open, rock_meter_star_power_on, strum_iterator, check_for_star_power Setup;
t_2D0150 AnimatedTextureLoop, MissedNote, UnnecessaryNote Setup, CFunc_get_anim_speed_for_tempo_cfunc;
t_2AD528 func_002AE0A0, func_002AF438, func_002AE9F8; t_2D4468 func_002D5888/5C88/5CC0; t_2EB1C0 func_002EBDF0;
t_282268 func_00282ED0; t_2E90B0 func_002EA5F0; t_26AEF8 func_0026AEF8, func_0026CC48; t_2774B8 func_002777E0;
t_26D280 func_0026DC68, func_0026E0B8 (+ func_0026E190 now takes the pointer); t_2848B0 func_00285948/85A30/85A60;
t_2B3AC8 func_002B47E0, func_002B4810, func_002B4B98; t_2DEE90 func_002DF718, func_002DF150; t_25C450 CFunc_DumpHeaps,
CFunc_PushMemProfile; t_271480 func_00272020; t_29F288 func_0029FD08, func_0029FF20; t_252068 CFunc_CreateBussSystem;
t_254248 CFunc_GetCurrentTrack.
(Notes: `if (c) {...; return 1;} return 0;` and `if (a == K) return X; return f();` fix swapped branch layouts. A callee
declared `int` instead of `void` changed scheduling in func_00272020. CFuncs take (script?, args) and pass $a0 through
untouched: call the helpers with the incoming first argument. A movz/movn chain `r = b; if (a&0x1000) r = ...;` is
written bottom-up. A function returning `call(...) + 0xC` looks like a copy of `this`; check m2c.
The -O0 `sq $30` frame-pointer functions of t_2E4FD0 (func_002E56E8, func_002E5718, func_002E5758) and t_2DEE90
func_002DFE78 were skipped.)
Given up:
- func_0026E1B0: original has a `nop` after the jal (3 forms); func_0026E158: only the `lui` is scheduled before
  `addiu sp` here (6 forms).
- func_0028D1B0: 10-arg forwarder, original saves ra with `sq`.
- func_002B4CB0, func_002CDCC0, func_002CDCF8: hash-chain search; original keeps the node in v0 and loads into v1 with
  an empty `beqz` delay slot (while/for/goto forms), same v0/v1 swap as above.
- func_00279118: gcc reassociates `q + i*8` / `q + unk0*8 + i` (4 forms).

Round 6 part 2 (+31): t_266800 func_00266CE0; t_26D280 func_0026DC20, func_0026DAB0 (struct S0026D660 now has the
full 0xCB0 stride), func_0026DBD8; t_273498 func_00275038; t_27D828 func_0027EF20/EF60, func_0027E6B0;
t_2848B0 func_00285A90; t_29F288 func_0029F550 (`volatile int v = 4;` for the dead stack store), func_0029FE60,
func_0029F500; t_2B3AC8 func_002B49D8, func_002B4B50; t_268EB8 func_0026AE30; t_26AEF8 func_0026C5A8;
t_26F3B8 func_00270060; t_2797A8 func_0027AA98; t_2DCE78 func_002DE5B8 (virtual call, vtable index 72);
t_2DEE90 func_002DF1A0, func_002DF7E8; t_25C450 CFunc_SetMemThreadSafe; t_271480 func_002733E0;
t_282268 func_00282F00, func_002838E8, func_00283930, func_00283978, func_002839C0; t_2A74C0 func_002A75F0;
t_2E90B0 func_002E90B0.
Quirks: (1) a run of constant stores `x->a=0; ... x->z=0;` comes out last-source-first (the delay slot gets the
second to last): write the stores in the original's order shifted -- for `40,0,4,...,3C` write ascending 0..40 (matched: t_2CDCC0 func_002CDD30). (2) `if (t == A) return x; if (t == B) return f(); return 0;`
gives the shared-epilogue layout of the `switch`-like accessors; an `r` variable or `r = 0; if..` gives v1 moves.
(3) Early `return 0` inside the inner `if` gives the second `daddu v0,zero` delay-slot layout (func_0026C5A8).
(4) Invert the test to get the original's branch layout (`if (a == K) return X; return f();`).
Given up:
- func_002A7EA8: `lui` for D_003AB260 scheduled before `addiu sp` in the original, after here.
- func_0029FFB8: `li a1,0x4480` goes in the jal delay slot in the original; ours hoists it (3 forms).
- CFunc_ResetPulseEvents: store order solved (ascending), registers differ (lui in a0/a1 in the original).
- func_002859D0, func_0027E300: short loops with nop padding.

Round 6 part 3 (+17): t_2AD528 CFunc_IsGuitarController; t_26F3B8 func_00270E40, func_00270E88; t_273498 func_00273C20
(now takes two args), func_00275138, func_00273C68; t_27D828 func_0027D828; t_29AA58 func_0029AA58; t_29F288
func_0029FEA8; t_2C57B8 CFunc_CrowdDecrease/Increase; t_254248 CFunc_LoadFSB, CFunc_StreamExists; t_266800
func_00266898, func_002672C0; t_282268 func_00283020; t_2C3468 func_002C34C8.
(Quirks: a1 that is never written before a call is an incoming argument: pass it through. `if (x == K) A else B`
with different constants stores gives the `bnel` + store-in-delay-slot form. When a run of stores comes out in the
wrong order, a permutation search over the source order finds it (func_00283020: 20,14,18,1C,4).
`r = out; if (!call) { ...; return 0; }` style needs `r` loaded before the test.)
Given up: func_002AEB48 (virtual call: original copies `this` into a2 at entry, ours a3 + moves), func_0026E0E8
(movz bracket, return-0 delay slot).

Round 6 part 4 (+19): t_2DEE90 func_002DF9B8; t_268EB8 func_002691B0, func_0026AC60, func_0026AEA8; t_2774B8 func_00277810;
t_2B5BC8 func_002B5DA0; t_29F288 func_002A1170/11C0/1210/1260 (deleting dtors, vptr at 0xC), func_0029FD40, func_0029FE00;
t_2D0150 CFunc_hero_get_skill_level_cfunc; t_25C450 func_0025E170 (func_0025DFE0 now takes a pointer); t_266800
func_00266F50 (func_00266FA8 takes an int); t_26AEF8 func_0026CC80; t_296A10 func_00296D88, func_00296EC0;
t_2DCE78 func_002DD108.
(Quirks: `extern int D_X[2]` (8 bytes, small data) makes `&D_X[i]` an `addiu v0,gp,off` -- larger arrays use lui.
Two u64 stores come out in reverse source order. Check which arg registers a call leaves untouched: func_0027B300(p, 0)
had `a0` passed through, the wrapper has only (p, n).)
Given up: CFunc_LightShow_GetParams (the original loads D_00371EE8 straight into a1 after `move s0,a1`; ours loads
v0 first, 3 forms).

Round 6 part 5 (+11): t_2BEEE0 CFunc_GetInputHandlerBotIndex; t_2AD528 CFunc_LightShow_AppendSnapshotParams,
CFunc_LightShow_GetPyroScript; t_2AAD58 CFunc_LightShow_SetMapping; t_254248 CFunc_PauseStreamNum; t_296A10
func_00296F18; t_2B5BC8 func_002B6270; t_2E90B0 func_002EAE00; t_266800 func_00267A00 (the existing
`void func_002679E0(void)` wrapper is called through `int f(int) asm("func_002679E0")`); t_268EB8 func_0026A660;
t_26AEF8 func_0026CBE8.
(Quirks: stores come out in a rotated order, `[s0, s_last, s1, s2, ...]` for 6 stores, so source order is
`[first, 3rd..last, 2nd]` of the wanted output. `func_X(a)` where only a0 reaches the callee unchanged, e.g.
func_002B6098(a) with `a*4` kept in a2. A tail that reads a global in both paths is the plain `p->x = G; G = p;`
after the `if`, not a hoisted local.)
Given up:
- func_00297400 (ctor): `move v0,s0` is after the five `sb` stores in the original, before them here.
- func_002711D0, func_00271228: macro-form load of D_003733B0 must not be in the bnez delay slot (ours is gp-relative
  and filled). func_00270DB8: sll/lui scheduling.
- func_002AEB98: indirect call whose result gates a call with a1/a2 passed through; func_00289F90 has a 3-arg
  prototype in this file already.
- func_0025D680, func_0025D6E0: struct returned by value (ldl/ldr), not tried. func_0025C6A0: mixed bitfield clear, not tried.

Round 6 part 6 (+12): t_282268 func_00282F48 (kept `void *` param, other callers use it); t_2949F0 func_00296738
(strcpy via the `func_0030A970_2` alias); t_2C0FC8 func_002C25D0 (prototype now void); t_2D0150 func_002D0240
(`char buf[0x10]` for the stack object); t_2D8368 func_002D9FF0; t_2C3468 CFunc_CameraCut_GetCameraIndex; t_266800
func_002676F0; t_27D828 func_0027DC58; t_254248 CFunc_ChangeTrackState; t_2AD528 CFunc_EnableInput; t_2AF598
CFunc_GuitarControllerMake; t_296A10 func_00296A90.
Given up: func_002680D0 (original adds 8 to the %lo address in a separate addiu, ours folds symbol+8);
func_0027F6C8/func_0027F728 (s0/s1 swapped between b and c, 3 forms); func_0029F5C8 (`max(r, 500)` is slti+movn in
the original, slt 499 + movz here, 5 forms); func_00295278, func_002704E0, func_002774D8: not tried.

Round 6 part 7 (+8): t_254248 CFunc_StopStream; t_273498 func_00275180; t_27D828 func_0027E180; t_296A10 func_00297470 (delete via
func_00297CF0); t_25C450 CFunc_AnalyzeHeap; t_26D280 func_0026E560 (func_00277378 reached through an `asm` alias with
(int, int)); t_2797A8 func_0027AC90; t_2DCE78 func_002DE4C8 (call the arg-producing function first: `int r = f(p);` then the
virtual call, otherwise `p + delta` is evaluated before it and an extra saved register appears).
Given up: CFunc_PrintMemInfo (original hoists `addiu a2,sp,0x40` above the global load; a pointer local removes the
reload of `out`), func_002E99D0 (`move v0,s0` one slot off), func_002E7B60 (`movz` result with the constant 1 kept in s1),
CFunc_LoadMusicHeader (D_00368A38 read by both `$gp` and `lui` in one function, not tried), func_0027E700, func_00267048,
func_0026EAA0, func_00286330 (loops with goto-shaped control flow, not tried).

Round 6 part 8 (+7): t_2BEEE0 CFunc_MakeDeadWhammy/MakeNormalWhammy/MakeStarWhammy; t_254248 CFunc_AddStream, CFunc_RemoveStream;
t_2D0150 CFunc_get_song_rhythm_track_cfunc; t_2C0FC8 CFunc_LaunchGemEvent.
(`if (a(x) && b(x)) return c(...); return 0;` with two out locals is the shape of most script-command getters; the first
helper call takes the incoming first argument unchanged.)
Round 6 total (agent C7): 151 functions. Not yet tried in this range: func_0026E5C8, func_00289ED8 (hash search + loop),
the t_2E2FB0/t_2E4FD0/t_2E0E90 -O0 frame-pointer functions, ~600 larger candidates (> 0x60 bytes).

### Round 8 (agent C8)
Candidate filter: skip functions whose .s starts with `addiu sp,sp,0x10; nop` (split-fragment prefix: t_29F288 dtors
func_0029FB40/BA8/FC10/FC80/func_002A1110 have it twice and cannot match).
Matched (+17 so far): t_254248 CFunc_StopSound, CFunc_PauseStreamID; t_273498 func_00273510, func_00273588; t_2848B0
func_00286160; t_27D828 func_0027E410, func_0027DCB8; t_2D4468 func_002D5B48; t_2774B8 func_00277540 (old void prototype
kept as `func_00277540_v` asm alias for func_002775B8); t_266800 func_002681B0, func_00267760; t_282268 func_00282FA8;
t_25C450 CFunc_MemDeleteHeap, CFunc_MemInitHeap, CFunc_GetNumUsedStructs; t_268EB8 func_00269F60 (4-entry table scan, a
plain `for` under `-funroll-loops`); t_2BEEE0 CFunc_TextOutputStart.
(Quirks: `int h1 = s->unk20; ... int h2 = s->unk20;` one fresh local per use fixes s0/s1 assignment; a value read
right after a call and tested later (`lw s1,0(sp)` before the next call) is a local copy `int o = out;`; two global
stores where the second lands in the `beqz` delay slot: swap the source order.)
Given up:
- func_002704E0 (2D table stores, v0/v1), func_00273498 (gcc folds the movz chain), func_002964D8 (dtor, v0/v1 + s0/s1),
  CFunc_AddMusicTrack (bool kept in s0), func_0026DCC8 (original keeps `bgez` + nop, ours `bltzl`), func_002A74C0 (macro
  load of D_00368A38 costed 1 insn), func_00268130 (`& 0xFFFFFFFE & 0xFFFFFFFB` stays unfolded in the original).
Round 8 part 2 (+17): t_2A53A8 func_002A6EB8, func_002A6F60, func_002A7008, func_002A70B0, func_002A7158, func_002A7200,
func_002A72A8 (pool create templates, same shape as t_2754A0 func_00276DC8); t_2AD528 CFunc_SetInput; t_254248
CFunc_LoadSoundRAM; t_25C450 CFunc_GetHeapSize; t_29AA58 func_0029B5F8; t_2BA998 CFunc_MakeGemsVisibleOnAllViewports;
t_2949F0 func_00295FA8 (`delete` through a vptr at 0x2418), func_00296138; t_2D0150 func_002D0150; t_2DCE78 func_002DD8F8;
t_266800 func_00267660 (func_00268388 gets the incoming a0 passed through).
(Quirks: `if (ok) { call; return 1; } return 0;` gives the original's `bnez` + inline `b/v0=0` even when the source test
was `ok == 0`; a store of 0 that sits in a call's delay slot means the zeroed local is declared after the argument call;
`return v` read after the call, not hoisted, is `if (!call) {...; return 0;} return v;`.)
Given up: CFunc_DestroyGem (original keeps bnezl + conditional load, ours if-converts to movz), func_002861D8 (s0/s1
swapped, 4 forms), t_27F8C8 func_0027F8C8/F938/F9B0 (the original copies the arg into two pseudos: `move v0,a2; move s1,v0`).
Round 8 part 3 (+12): t_2A53A8 CFunc_LoadFromMemoryCard; t_288B10 func_0028A5A0; t_2D0150 CFunc_play_stance_transition_cfunc;
t_2C3468 CFunc_GetRandomSeeds, CFunc_SetRandomSeeds (six scalar locals, not an array, give the original arg-load order);
t_252068 CFunc_SetActiveCamera (test inverted: `if (call) {A} else {B}`); t_254248 CFunc_PlayTrack (a 0x30 char buffer at
sp+0 whose address is stored into a local); hash-bucket list free: t_27D828 func_0027E358, t_2D4468 func_002D5A90 /
func_002D5BD0, t_2AD528 func_002ADFE8, t_268EB8 func_002694D8 (files t_27D828/t_2D4468/t_2AD528 now `-funroll-loops`: the
original aligns the outer loop with a nop; `char *h = p->unk4; if (h) { n = h; ...}` keeps the head in a0).
Given up: func_0026A3F0 (macro-form store of D_00373394 lands in a delay slot), CFunc_WhammyFXOffAll (prologue order
`move a2,sp` before `sd ra`), func_002D8398 (struct pointer in a2 not v1), func_00269420 / func_002D5EC8 (hash-chain remove:
`prev` lives in a0 in the original, a3 here), CFunc_MemPushContext (D_00368A38 mixed gp/lui), func_0026D9F8 (movz result).
Round 8 part 4 (+8): t_29AA58 func_0029B510 (heap lock, object + intrusive list link: write `n->unk10 = h->unk10;` before
`n->unkC = h;`); t_296A10 func_00297E98; t_2848B0 func_002858C0 (D_00371344/48 list, struct S285A60 moved to the top);
t_2C9AC0 func_002CA618 (script array `Get(i)` inline); t_254248 CFunc_PlayMusicStream (read `out` into a local between the
call and its test); t_25C450 func_0025C478, func_0025C530, func_0025C5E8 (pool-free templates with a2/a3 = index/array
passed to func_0011C2E8; the final func_00119400 call is the 2-arg form; the sdata arrays are re-declared through
asm-label aliases `D_X_P`).
Given up: the 10-function hash-table ctor family func_00269240 / func_0026A768 / func_0026A980 / func_0027E4B0 /
func_00291D28 / func_00292D98 / func_002AE0C8 / func_002D58B0 / func_002D5CE8 / func_002D5F80 (0x1e0 bytes, two inlined
array-ctor loops under `-funroll-loops`; the original keeps t in s4 and the alloc result in s3, plus a 7th saved register for the
`-1` constant; ours is 5 instructions shorter, 4 forms incl. an inline helper); func_002B4848 / func_002B48F0 (script array
bitmask: the data pointer is CSE'd in the original); CFunc_SetGlobalPitchModulation / CFunc_SetSfxReverb (`mov.s f12,f20` goes
before the jal and `move a1` into its delay slot in the original); CFunc_LoadAnim (stack slots of the two out locals swapped).
Round 8 part 5 (+11): t_266800 func_00266E90 (44-element clear: an indexed `for (i = 0; i < 44; i++) D[i].f = 0` is unrolled 4x by
`-funroll-loops`, a pointer loop is not); t_2DCE78 func_002DD810 (required-int getters, fresh out local per call),
func_002DE418 (dtor: `delete` of an object whose destructor is the SECOND virtual -> vtable entry at 0x10/0x14, add a dummy
`virtual void v0();` before `virtual ~X()`); t_2DEE90 func_002DF630 (same dummy-virtual trick); t_26AEF8 func_0026C738,
func_0026C7A8, func_0026C878; t_25E580 CFunc_IsAssetLoaded, CFunc_LoadAnim, CFunc_UnloadAnim, CFunc_UnloadScene.
KEY QUIRK (fixes many "v0/v1 swap" give-ups): declare void callees as returning `int` (func_0026B1B0, func_00275EE8,
func_00273F08 here): the original kept an unused return-value pseudo, which moves later temporaries from v0 to v1.
Stack-slot order of address-taken locals follows the FIRST `&x` that is expanded: to put the second out param at the lower
address take its address early (`int *pv = &v;` at the top and pass `pv`); `((int *)obj)[7 + n] = 0` gives `addu v0,v0,base`
(index first) where `obj->arr[n]` gives `addu base,idx`. A stack store listed in a call's delay slot means the local is
assigned (`v = 0;`) right before that call, not at its declaration.
Given up: CFunc_ReloadAnim (original: call result in s2 + `movn s2,v1,v1`; ours movz with name in s1, 5 forms),
func_002DCD68 (D_003722B0 is gp-relative file-wide through GP_DATA but this function reads it with lui: needs a split object),
func_0028BDA8 (tail merge of the `sw` after `b`), func_002890C8 (n/l saved registers swapped), CFunc_GetHeldPattern (only
`move a0,s0` vs `ori a2,sp,8` order), func_002964D8 (after the int-return fix only s0/s1 are swapped).
Round 8 part 6 (+9): t_2A53A8 CFunc_GetSummaryInfo; t_254248 CFunc_IsStreamPlaying, CFunc_PlayStreamFromSet; t_296A10 func_00296CB8,
func_00296DE0 (string holder ctors: local `u8`/`u16` copies whose addresses go to func_00296B28); t_25C450 CFunc_DisplayFreeMem
(locals `m1 = D_003568B0; m2 = D_003568C0;` before the calls; every `a - b` operand in its own local so the calls come out in
source order); t_2E7010 func_002E8968, func_002E8440 (16 explicit calls per iteration), func_002E8A18.
Stack-slot rule confirmed: the FIRST address-taken local gets the LOWEST slot; to make an earlier-declared local sit lower than
the one whose address is taken first, take its address first (`int *pa = &a;` and pass `pa`).
Given up: CFunc_PreLoadStream / CFunc_PreLoadSoundStream (`flag = (x == K)` becomes xor+sltiu, original is a branch),
func_002E70B0 / func_002E7D80 (two compare blocks: alignment nop + an extra saved register), func_002E8FF0 (address register
allocation for the 0x1C-stride globals).
Round 8 part 7 (+4): t_2D4468 func_002D4B38 (key search `for (i = 0; i < n; i++) if (k == keys[i]) return vals[i]; return 0x0C3AA5D7;`
unrolled 4x by `-funroll-loops`); t_2C7900 CFunc_WhammyFXOff (file now `-funroll-loops`; script array `Get(i)` inline),
CFunc_GetStrumPattern (`bool` aliases for the two getters, `missing` flags); t_2AAD58 CFunc_LightShow_Update (`if (!flag) return 0;`
first gives the original block order; with an `r` variable gcc adds an extra register).
Given up: CFunc_WhammyFXOffAll (prologue: original has `move a2,sp` before `sd ra` and the nested-call argument first; 6 forms),
func_00289D30 (0x30-stride key search is not unrolled in our source forms), func_00269420-style hash remove (see above).
Round 8 part 8 (+4): t_298A30 func_00299E18 (file now `-funroll-loops`: `for (i = 1; i < 0x100; i++) if (f(a, i) == 0) return i;` is unrolled
by 5); t_27F8C8 func_0027FDF8 (heap lock); t_26F3B8 func_00270928 (reassign the parameter, `if (s == 1) a -= 0x16;`, to keep it in the
same register and get the movz), func_00271028 (`u64 t = D_00370D20[i]` polled until it equals a u64-returning call, the second call
through a void alias; the two lui-addressed arrays through `.set X_lui, X` aliases give adjacent lui/addiu).
Given up: func_0029B468 / func_0029B3A8 (inline list-iterator search: loop shape and `movn` register differ).
Round 8 part 9 (+14): t_282268 func_00283498; t_273498 func_00273A80 (m2c's goto form `r = 0; if (d) goto call; ... call: r = f()` matches
exactly -- try the goto text from m2c when the plain forms give the wrong block order); t_271480 func_00272160 (callee `void`,
here int-return makes it worse: always try both); t_266800 func_00267A80, func_00266928 (float scale loop unrolled 4x, `u32 i` vs `(u32)n`);
t_2BCDA8/t_2EB1C0 hash lookups func_002BDC48, func_002EB4C8, CFunc_GlobalTagExists via an inline
`SHT_Find(SHT *t, const int &k)` and a local `int k = arg0;` (the by-reference key is spilled to the stack but read from its
register); t_2DCE78 func_002DCE78; t_2DAE48 func_002DB110; t_2DEE90 func_002DEEC0, func_002DF050, func_002DEF48 (checksum
if-chains, `v != K ? a : b` to get movz), func_002DFA08 (virtual call through a vtable at +0xEE00 with `s16 delta`, one-argument
alias of a function declared without arguments).
Given up: func_00298390/func_00298448 (only temp register numbers), func_00273CF8 (third call: a0 moved before mov.s f12),
func_002D0E08 (float compare return layout), func_0027AE70/func_0027ADA0, symbol lookup func_00276008/62F0/63E0/64E8, func_002A79A8
(loop alignment), CFunc_UpdateAtoms (node + value from a lookup loop), CFunc_hero_play_tempo_anim_cfunc (order of one store).

### Round 9 (agent C9)
Skip list for candidates: functions starting `addiu sp,sp,0x10; nop` are split fragments; t_2E2FB0/t_2E4FD0/t_2E0E90 are -O0 frame-pointer code (not tried).
Part 1 (+16): t_2DCE78 func_002DD9F0/DA40/DA90 (squares a float in place if func_0027D058 succeeds), func_002DDAE0 (two early `return 1`
give the original's `li v0,1` in the branch delay slots), func_002DDB68 (extra unused `char buf[8]` passed as 2nd arg), func_002DDBB0 (float
constant 16899999744.0f); t_2D2350 func_002D31E0; t_2848B0 func_00285978 (union f32/u32); t_2AD528 func_002AED18 (`if (x != 0) return 0.0f;
return f();`); t_2B3AC8 func_002B4BC8; t_266800 func_00268330 (declare the callee with the float FIRST: `f(f32, int, int)` puts `mov.s f12`
before the int moves), func_00268480 (57.295776f, the compiler's parse of 57.29578f is one ulp off); t_26AEF8 func_0026CCE0, func_0026B158;
t_2D0150 CFunc_get_song_tempo_cfunc; t_268EB8 func_0026A6C0.
Given up: func_002B4C38 / func_002B4C70 (hash chain walk, v0/v1 swapped; 4 forms), func_002B5BC8 (callee takes a float pair in f12/f13 and
ints from a2; our ABI numbers ints from a0), func_002B7108 (original has 2 nops before div.s), func_0027DD38 (f0/f1 swapped, 4 forms),
func_0027EFA0 (nop in the jr delay slot after cvt.s.w), func_0026BD80 (original computes `off + base` twice), func_002DFF28 and
t_2E2FB0 family (-O0).
Part 2 (+11): t_26AEF8 func_0026C9E8, func_0026C940; t_2C3468 CFunc_ATan2; t_254248 CFunc_AddSoundBanks (`i = 0; h = global;` assigned before the
`if (arr[1] != 0)` test gives the original order); t_2CDCC0 CFunc_wait_for_correct_frame_cfunc (m2c's goto form `goto no; ... r = 1; if (t) { no: r = 0; }`
beats every if/else form: those if-convert to movz/movn); t_25A428 CFunc_SetScriptWarningLevel (switch where cases 2 and 3 share a store:
`case B: lvl=1; goto store; case C: lvl=2; store: D=lvl; break;`; the arg0 is passed through to func_0027D870); t_2A74C0 func_002A7EF0;
t_2E90B0 func_002EA758; t_273498 func_00273B80 (`int live = ((x >> 1) & 1) ^ 1; if (live)` keeps andi before xori; call
func_00273B48 with its second argument through an asm alias).
Given up: func_0027A9B8 (s0/s1 save order swapped), func_0026A5D0 (original lays out `return 0` first with bnezl, 5 forms),
func_0027E288 (loop shorter than 6 instrs).
Part 3 (+9): t_2797A8 func_0027ACF8 (list remove: `while (next != 0)` condition on the loaded next, `if (prev != 0) prev->next = ..; else head = ..`);
t_26D280 func_0026E008; t_2D0150 func_002D0CF0 (assign the float to a local in both branches, then store); t_268EB8 func_002696C8 (clear loops
`for (i < 2)` and `for (i < 4)` with a running `n++`, unrolled by -funroll-loops); t_292928 func_00293360 (callbacks passed as `(void *)func`; callee
args a1/a2 skipped = unused parameters); t_2949F0 func_00296798 (load the global object pointer into a local right after the `old != v` test; callee
func_002965C0 reached by an asm alias with 3 args, func_00296798 itself aliased as `_1` for the 1-arg caller).
Toolchain notes: functions that save s0..s5 + ra (7 registers) use `sq` in the original while we emit `sd` (44 functions in the asm have `sq $17`,
e.g. t_2AF598 func_002AFE38, t_26AEF8 func_0026B3C8): skipped. Short `flag = (x == K)` as 0/1 stays xor+sltiu (t_2AD528 CFunc_LightShow_SetTime).
Given up: t_2AD528 CFunc_LightShow_SetTime (see above), t_2EB1C0 func_002EB680 (list node pointer in a2 instead of a1, 4 forms), t_2C7900 func_002C7900
(extra saved register caching the address of an stack array), t_26AEF8 func_0026BE00 (saved register for the result), func_0026BCB0 (the original keeps
three copies of the entry pointer), t_268EB8 func_002698C8 (first two clears address the data through D_003A3484), func_0026A5D0 (return 0 first),
t_2DEE90 func_002DF1F0 (iterator object with vptr store at the end), t_292928 func_002936C0 (volatile busy loop), t_2E90B0 func_002EA898 (empty loop).
Part 4 (+4): t_2D4468 CFunc_SetPS2DOFZ; t_2E7010 func_002E7E20 (`r = 0x3FFF; if (!(x > 0.99f)) r = (int)(x * 16383.0f);` puts the li in the branch slot), func_002E8510 (the 5th
arg is unused); t_2E90B0 func_002E9140 (`a && (t = q.u12) == 1 && b && (u = q.u12) == t && c` chain, then `return global`).
Given up: t_2E7010 func_002E7010 (identical except `beql` instead of `beq` on the `D = 0 / D += 1` branch, 8 forms), func_002E7C58 (original has a nop after
the last jal of the first if-block), func_002E8318 (needs -funroll-loops, file does not have it); t_2E90B0 func_002EA9E0 (checksum switch: tail layout
differs by 8 bytes, 4 forms), func_002EA620; t_27D828 func_0027F610 (arg copied into v1 first: the F8C8 family problem); t_292928 func_00292AF0 (arg moves order);
t_2D0150 CFunc_event_spawner_cfunc (`lw a0,16(sp)` in the delay slot of bnez vs ours bnezl, or moves order: pick one, never both).
Part 5 (+4, 39 total): t_2848B0 func_00285828 (list search; `int c` parameter compared with an lhu field, a u16 parameter adds an andi); t_296A10
func_002972F8 (RLE decode: file now `-funroll-loops`, `while (n != 0) { c = *src; ... }` with two inner do-whiles), t_2797A8 func_0027ABB0
(`if (a->unk4 == 0) { call(); return a; }` first, bitfield struct S27B_Comp copied; callee with no args through an asm alias), t_2CBC10 func_002CC7C8
(script array Get as `int r; if (size == 1) r = data; else r = ((int*)data)[idx]; return r;` gives the original's bnel; `ok = f(&out); t = out; if (!ok) {...; t = 0;}`).
Given up: t_29F288 func_002A0020 (DMA register constants: original materialises 0x10008020 once in a0 and reuses it; every volatile/local form
re-materialises), t_268EB8 func_0026ACB0 (original strength-reduces to a base+16 induction pointer), t_25C450 func_0025C6F8 (a zero register compared
with a loaded field), t_26AEF8 func_0026BCB0.
Part 6 (+3, 42 total): t_2B3AC8 func_002B4A60 (unused 4-byte colour local: `u8 c[4]; u8 *p = c; c[0] = p[1] = p[2] = p[3] = 0xFF` written in index order, gcc's
scheduler reorders the stores itself; the second parameter is reassigned `b = Alloc(...)` so it keeps its saved register); t_292928 func_00293EE0 (ring buffer
two-span getter: read `p->unk0` in both branches, no local; `%` is fine now), t_2949F0 func_00295140 (`int n = avail; if (want < n) n = want;` gives slt+movn; D_00370E44 plain
extern).
Given up: t_2949F0 func_002952D8 / t_292928 func_00293A88 (identical ring-buffer copy; the original re-issues `move a0,s3` before the first memcpy, ours keeps a0), t_2797A8
func_0027AAD8 (list copy: saved registers s2/s3 swapped and the loop-top nop), t_29D230 func_0029D2A0 (u16 spilled and re-read as two lb).
Part 7 (+3, 45 total): t_2C0FC8 CFunc_FillInputArray (`(f_b(..) ^ 1) == 0 && ...` with bool-returning asm aliases of the getters; the float-taking callee declared
float-first `f(float, int, int, int, int)` fixes the arg load order); t_254248 CFunc_SetSfxReverb, CFunc_SetGlobalPitchModulation (callee declared `(int h, f32 x, int w, int r)`:
float in the second slot gives `move a0` / `mov.s f12` / delay-slot `move a1`; locals xx/yy/hh read in that order, global read just before the last call).
General rule: when `mov.s f12` order is wrong, try float first, float second, float last in the prototype.
Given up: t_2CDCC0 CFunc_GuitarEvent_Note_Window_Open_CFunc (`for(;;) switch` state machine; return value reuses the state register, 6 forms).
Part 8 (+3, jump-table switches now supported by the build): t_2626E0 CFunc_GetPlatform, t_2A53A8 func_002A5478, t_2A32E0 func_002A4D28 (read the table in
asm/data/cod/rodata.rodata.s; case bodies in the order of their labels in the .s; a `char` parameter is `int a; int c = (char)a;` to get the leading sll/sra; with few cases
gcc emits a compare chain, add empty `case N: break;` to fill the table).
Given up: t_2A53A8 func_002A53E0 (quotient gets a new saved register), t_2848B0 func_00286108 (table has 28 entries pointing into another function), t_271480 func_00272920.
Round 9 total: 48 functions (earlier part headers in this round over-count by 5: the real per-part counts are 16, 9, 6, 4, 4, 3, 3, 3 plus part 8 = see git log).

### Round 10 (agent C10): jtbl switches first
Matched jtbl (14): t_27D828 func_0027E1E8, func_0027E9D8, func_0027F008; t_288B10 func_00289630; t_286A60 func_002873A0;
t_2A12B0 func_002A2108; t_2797A8 func_002797A8; t_2908A0 func_00292808; t_2774B8 func_002787F0, func_002791E0;
t_282268 func_00283DB8 (movz bracket skip loop = `do { p = f(p); if (*p == 3) n++; else if (*p == 4) n--; } while (n)`),
func_00283A08 (block-local `int a` per case; `p = (p+4)&~3` then `p += ...` as two statements); t_25A428 func_0025B238.
(Quirks: the table range is fixed by the lowest/highest case value: add empty `case MIN:`/`case MAX:` when the table
has default entries at both ends; cases are written in the order of their labels in the .s; an `int`-returning
prototype for a void callee fixes a v0/v1 swap; `a*4 + t; size += 3 + n; size &= ~3u` as separate statements fixes
temp register choice; the `base` pointer written as if/else (`if (k == 1) base = &p->x; else base = ...`) with the type
byte read first matched func_002797A8.)
Given up:
- t_2774B8 func_00277860 (original copies both args into new pseudos, move t0,a0 / move a3,a1), func_00278C50 (n/e saved
  registers s1/s2 swapped), t_27F8C8 func_0027FCD8 (original copies the 3rd arg to a3 first), t_292928 func_002929F0
  (sibling of func_00292808 but register order of the size expression differs, 10 forms).
- t_27D828 func_0027F410 (original copies the unused first arg to a2), t_282268 func_00282CC8 / func_002826C0 (hash lookup
  + alias chase / u32->float compare), t_25A428 func_0025BC10 (vector compare).
Round 10 other matches (+7): t_27D828 func_0027F410 (callee func_0027F1E8 takes the incoming first arg as 3rd param), t_268EB8 func_00268EB8,
t_2A74C0 func_002A7540 (delete through vptr at 0x14, dtor first virtual), t_25C450 func_0025CAE8, t_2C3468 CFunc_CameraCut_SwapLookAts.
Given up: t_2B5BC8 func_002B5C08 (call not tail-merged), t_25E580 func_0025EB48 (two arg moves swapped, 12 forms), t_288B10 func_00288F90
(s0/s1 swapped), t_27F8C8 func_0027FA40 (saved register order), all `sq $31` functions (func_002AFE38, func_0026B3C8, ...: ra saved with sq
cannot be produced by u128 locals/args; only s-regs go sq), CFunc_GetWaypointPos/Dir (TImode lane extraction not reproducible).
Lesson: when replacing a function with a python slice up to the next INCLUDE_ASM, never swallow neighbours (func_0027EB70 was lost once and restored).

### Round 11 (agent C11): jtbl first
Matched jtbl: t_2A12B0 func_002A1918 (dispatcher; `int junk`/register tricks are wrong: the else-branch call is `f(s, 0, 1)`, beql slot comes from the arg setup).
Given up: t_282268 func_00282838 (compare by type; original puts the label of the `c.lt.s` hazard nop BEFORE the nop, ours after: toolchain, 1 insn off),
t_2848B0 func_00285400 (types 14/22.. share a tail; original runs `lw t->0` before the `move s1,v0` of the call result; cases 3/5 with `break` match, goto-tail form leaves
only that order: 12 forms).
Matched other: t_29D230 func_0029D730 (iterator local `S29D_It` + two virtual calls through the 0x2418 object: slot k has delta at 8*(k+1); own struct with `virtual int v5()`).
Given up: t_258420 CFunc_GetRandomArrayElement (original loads p->unk20 and the key into a0/a1 BEFORE the element-size branch; locals/ternary/inline/two calls all keep them after, 6 forms),
t_2E4FD0 func_002E6F10 (all but the second block's `addiu v1,s0,76` placement and the `li a0,1` delay slot; `int one = 1` for the store constant fixed the saved-register layout),
t_2774B8 func_002775E8 (nested jump tables, serializer).
Matched other: t_2E7010 func_002E7E80 (signature `(int, int, int, f32 unused, f32 x)`: floats take f12,f13.. by float index independent of the int slots, the 1st float is passed on unchanged to the first call; params reused as locals for a/c, fresh locals for the call results h/h2 fix the saved-register order).
Given up: t_273498 func_00274F08 (only v0/v1 of two globals swapped, 8 forms; int-returning prototypes for the void callees fixed the others), t_2A53A8 func_002A5638 (checksum switch: original tree has root = 4th of 6 cases, gcc 2.95 balance gives the 3rd; needs one extra range case, not found),
t_2E4FD0 func_002E5FF8 (-O0 body with frame pointer).
Quirk: gcc 2.95 balances case trees at index (n + ranges + 1)/2 (cost table only for values < 128): compare with the original's root to count hidden cases.
Matched other: t_28AB28 func_0028AE28 (bytecode operand reader: types 0x2C/0x2D/0x16; `p->unk14 = q; v = bytes...; p->unk14 = s + N;` keeps the second pointer store after the loads).
Matched other (+2): t_2A53A8 func_002A5510, func_002A5638 (checksum switch compare trees: the original tree has one more node than the visible cases; adding a dummy `case 0xFFFFFFFF: break;` above the highest case reproduces it exactly (no compare is emitted for it). Case bodies in the order of the body addresses so the last `bne` falls through).
Matched other: t_2AAD58 func_002ABB00 (call with 10 args: reading the first register argument into a local first (`int q = p->unk4;`) makes the scheduler issue that load before the stack-arg stores of the zeros, like the original).
Matched other: t_25A428 func_0025AA28 (same trick: `int u = s->unkC4;` before the 10-arg call, passed as the 5th arg).

### Round 12 (agent C12)
t_2E7010 (+1, file now `-funroll-loops`): func_002E8318 (`for (i = 0x10; i < 0x30; i++) { f(i, 0xD); g(i); }` unrolled 8x; both callees
declared `int`); func_002E8440 and func_002E8968 rewritten as the plain `for (i = 0x10; i < 0x30; i++) g(i)` (unrolled 16x by the flag,
the explicit 16-call bodies broke under it).
Round 12 matches: t_2A32E0 CFunc_DestroyZoneEntities (first call passes the incoming a0; `a = 0` right before it); t_292928 func_002943A0
(DMA register snapshot: volatile `*(volatile int *)0x1000B410` reads, `while (reg & 0xF0) {}` busy loop; the busy-loop short-loop padding now matches;
prototype changed to `int func_002943A0(int)`).
Round 12 given up: t_2E7010 func_002E7C58 (the two-entry unrolled compare matches as straight-line blocks except the alignment nop before the
second block; loop forms (index, pointer, do-while) give a different base register, 6 forms), t_26F3B8 func_0026F930 (only v0/v1 of the last
global `|=` differ, int/void callee variants tried), t_2754A0 func_00275F08 (hash lookup + alias chase, as func_00276008).
Round 12 matches (cont.): t_2BA998 CFunc_Create2DGem (callee `(int,int,int,int,float,int,int,int)`: the float at its argument position gives the original load order;
`int o = f(..)` for the nested call first), t_2C9AC0 func_002CA6E8 (`int`-returning sprintf-like callee fixes the move scheduling), func_002CA888.

### Round 14 (agent C14)
Note: fcheck/try output is misaligned after any `nop` word (objdump collapses zero words into `...`); the flagged address is still right.
Matched vu0: t_252068 CFunc_CamDistFromPosLessThan (one `asm volatile` with the whole VU0 sequence + `qmfc2.ni t; mtc1 t,f; nop; nop; sqrt.s f,f` (the two nops are in the original,
gas does not add them); volatile keeps the lwc1 loads after it).
Given up: t_24DDB8 CFunc_VectorLength (original sqrt.s encodes the source in the ft field (0x460C0304 = sqrt.s f12,f12 with fs=0), gas puts it in fs: differs unless the register is $f0; toolchain),
t_2AD528 func_002AE3C0 / t_2DAE48 func_002DB920 / t_252068 func_002532A0 (start with a lone `sqcw2`/`qmfc2` before the prologue: split tails).
Near miss: t_250010 CFunc_SetShadowDirFromLight (nonmatching/CFunc_SetShadowDirFromLight.cpp): VU0 stages as separate non-volatile asms chained by a dummy "=r"/"+r" int (volatile or output-less asms stop the compiler interleaving the lui/addiu/li between them; this chain reproduces it);
left: gcc fills the beqz delay slot with a likely-branch copy of `lq` (`beqzl`), original has the asm's `lqc2 $vf1` (moved by gas) in the slot; `li v0,1` and the lui/addiu of D_00378210 sit one slot off.

### Round 15 (agent C15)
Stub splits: matched func_002DE0C8, func_00288998, func_0028C848, func_002758A0 (file now `-funroll-loops`: `for (i = 0; i < 0x8000; i++) p[i] = 0`),
func_002769B0 (unrolled loop; `u32 i = 0; if (n) { q = p; do {...; i++} while (i < n); }` with `int n`: the pointer copy inside the `if` puts `move s4,a0` after the branch).
Near miss: func_002884A8 (nonmatching/func_002884A8.cpp): only `move a0,s0` / `move a1,zero` order before func_00119610(h, 0) differs
(original sets a1 first and a0 in the delay slot). Loop forms that mattered: first loop `while ((it = f(it)))` with `if (x == key) n++` gives movz; second `e = f(0); if (e) { w = arr; do {...} while (e); }`; last `for (o = f(0); o; o = f(o))`.
Sqrt retries: CFunc_Sqrt, CFunc_VectorLength match. Pattern: `asm volatile("lwc1 %0,%1; nop; nop; sqrt.s %0,%0" : "=f"(d) : "m"(x))`; for VectorLength the VU0 part is split in two asms:
the first (`lqc2; vmul`, output dummy `k`, `"memory"` clobber) then `int dst = script->unk20;` then `asm volatile` (vaddy, vaddz, qmfc2.ni t, mtc1, nop, nop, sqrt.s) taking `k` and `dst` as inputs, so the `lw a0` lands between the stages and the `lui` after.
Round 15 matches (cont.): t_271480 func_00271E88, func_00273308, func_00271F28 (event structs: `(unkC >> 3) & 1` selects `(int)(unk28 * D_00370B08)` vs raw int; the float arg is passed on to the first callee unchanged),
t_2EB1C0 func_002EBFF8 (hash remove via a const-int& inline; node zeroing order key, val inside the `prev == 0` else), func_002EB1C8 (`S2EB_L *next = n->next; f(...); n = next;` keeps the next pointer in its own register),
t_25C450 func_0025D500/5C0/680/6E0 (20-byte struct `operator+`/`-`/`+=`/`-=`: `S f(S *a, S *b)` returning by value; the compound forms are `*a = f(a, b); return a;`),
t_27D828 func_0027E760 (array ctor: `if (n != 0) { if (n != 1) {...} } else {...}` order), t_273498 func_00274240 (func_00273F78 takes one arg), t_288B10 func_00288EA8,
t_25A428 CFunc_ShortenUIString, CFunc_StringRemoveTrailingWhitespace (`bool` alias of an int callee via `asm("func_...")` gives the `xori`; locals `{key; s}` in a struct fix the stack order; init order in the struct fixes the store order),
t_254248 CFunc_SetSoundParams (all locals in one struct; `int *p4 = &sp4` before the first call keeps the address in a saved register; `l.b = l.a = l.c` chain gives the store order),
t_24BA88 CFunc_SetEventHandlerOnObject (copy each out-value to a fresh local right after its call, otherwise gcc loads them late at the final call),
t_2AF598 CFunc_SongArraySet (`int ix = l.idx;` before the `if (a->unk4 == 1)` picks a0 for the index), CFunc_GuitarGetAnalogueInfo (plain code, `0.0f` constant lands in $f20),
t_2C57B8 CFunc_CrowdReset (13 config reads into locals then 13 stores), t_260658 CFunc_TestNetSetup (`else if` chain where each arm repeats the whole call sequence: gcc cross-jumps them and leaves the per-arm `a1 = 0`), CFunc_SetConfig (switch on checksum, 5 cases, plain `extern int` globals give gp in delay slots / lui elsewhere).
Near misses saved (nonmatching/): func_002884A8 (a0/a1 order before func_00119610(h, 0)), func_00293120 (store order, unrolled clear), CFunc_ControllerDebounce (u32 -> float conversion srl/andi order),
CFunc_DisplayLoadingScreen (temp register v1 vs a1), CFunc_AddCrowdModelCam (a2 vs a3 for a pointer used as arg and store), func_0028A140 (unrolled byte copy, counter in a2 vs a3),
CFunc_GetActiveControllers (2-iteration loop: original keeps the index in a register for the call argument, ours folds the constant), CFunc_PlaySound (store order of four floats, lw a0 placement),
func_00271708 (register numbering s1..s4), CFunc_Pop (s0/s1 swapped in two cases), CFunc_Push (lw a1/a2 order in one call).
Given up: func_0027F9B0 (original copies the first arg to v1 first, like func_0027FCD8), CFunc_LightShow_EnableSpotlights (`en = (v == K)` always folds to xor/sltiu; original keeps bne + li; 5 forms),
func_00273DE8 (if-chain: gcc merges the `4 || 3` tests), func_0026DD48 (3-slot test: original keeps &p->unk1C and the table address in s1/s3), func_002EA900 (free-list init x4 unrolled: original derives nodes from one base, ours rotates registers),
func_00296028 (ctor: everything matches with -funroll-loops and `do {} while (--i != -1)` except the frame: original has 32 unused bytes of locals), func_0026DAF8 (basename loop), func_00271480 (bit-mask tables, first-case registers),
func_00267910 (call with 8 args taken from leftover registers), func_002E6C80 (partial struct copy on the stack after sprintf), func_0029F790 (inlined list iterator), func_002DFAC0/func_002DF750/func_002DF8A8/func_002EAE78 (start mid-function: split tails).
Twins (scripts/twins.py): t_26AEF8 func_0026B1B0 (copy of func_0026B158).

### Round 16 (agent C16): +27
Division now works (`-mno-check-zero-division` is in the global flags), so `/` and `%` functions are fair game.
Matches: t_2B5BC8 func_002B5CA8; t_2C57B8 func_002C6B20; t_252068 func_002538C0; t_2AAD58 CFunc_LightShow_SetParams;
t_2A53A8 CFunc_MemCardGetUniqueFileName; t_2CDCC0 func_002CDDD0, func_002CDF70; t_2E90B0 func_002EA7E0, func_002E9510 (division);
t_254248 CFunc_LoadMusicHeader (gp read first, then `lui`: `asm(".set D_X_lui, D_X")` alias); t_25C450 CFunc_MemPushContext;
t_29AA58 func_0029AAA0; t_26D280 func_0026E1B0, func_0026E0E8, func_0026E470, func_0026EB08, func_0026EC08, func_0026ED98, func_0026D9F8;
t_266800 func_00267048; t_2848B0 func_00286330; t_2908A0 func_00291FC0, func_00292130; t_2DCE78 func_002DD308;
t_2AD528 func_002AE510, func_002AE5E8; t_2BEEE0 CFunc_TextOutputEnd.
Files that gained `// cflags: -funroll-loops` (nop before a loop label, loop heads aligned): t_29AA58, t_2848B0, t_2908A0, t_2BEEE0.
A scan with the flag prepended (fcheck of every `extern "C"` function) shows these files still fully match with it, so they can take it when a
function needs it: t_252068 t_254248 t_25A428 t_25C450 t_25E580 t_260658 t_2647A8 t_26AEF8 t_271480 t_273498 t_2774B8 t_2797A8 t_27B7D0
t_27F8C8 t_282268 t_288B10 t_292928 t_29D230 t_29F288 t_2A53A8 t_2A74C0 t_2AAD58 t_2AF598 t_2B3AC8 t_2B5BC8 t_2B8088 t_2BA998 t_2BCDA8 t_2C0FC8
t_2C3468 t_2C57B8 t_2C9AC0 t_2CBC10 t_2CDCC0 t_2D0150 t_2D2350 t_2D8368 t_2DAE48 t_2DEE90 t_2E62C0 t_2E90B0 t_2EB1C0
(not t_24DDB8, t_250010, t_258420, t_286A60, t_2949F0, t_2A12B0, t_2A32E0, t_2DCE78: other functions change).
Patterns that worked:
- Out-value tested after a call (`lw` in the branch delay slot, `move v0,zero` on the other arm): `if (call(&v) == 0) { f(); w = 0; } else w = v;`
  (neither a pre-read copy nor `v = 0` in the arm).
- Address of a local used after calls and passed to one of them: `int *p = &l.x;` before the first call keeps it in a saved register.
- A loop that `-funroll-loops` fully removed (lone nop before a label): the one-iteration table scan `for (i = 0; i < 1; i++)`.
  Unrolled search loops are plain `for (u32 i = 0; i < n; i++)` (declare `u32 i = 0` first, no extra `if (n)` guard: the guard comes from the unroller).
- Weighted pick (func_0026EB08): `while (n) { sel = n; r -= n->w; if (r <= 0) break; n = next(n); }`; the first `b` into the loop is gcc's rotation.
- `x ^ 1` of an int call gives `xori`; `int r = 0; if ((a ^ b) == 0) r = 1;` gives the `movz` (a direct `==` gives `sltiu`).
- `if (D) { ...all...; return r; } return 0;` positive-first layout; `int r = f(); if (!r) {...; r = g(); } return r;` gives the `move v0,s0`.
- Independent stores whose order the scheduler changes: brute-force the permutations of the source order (func_002AE510: unk4, unk8, unkC;
  func_002AE5E8 same) with a script that rewrites the statements and runs fcheck.
- A vector<int> dtor/copy ctor: element = `struct { int a; }` (unrolled x4 gives `+0x10`), `const int &last` for the copy loop, locals read in order res, first, last.
- `D_X` with `GP_DATA` file-wide but read through `lui`: alias `asm(".set D_X_lui, D_X")` (not needed when the first use is outside a delay slot).
Near misses saved (nonmatching/): CFunc_GetAngle, func_0028C8F8 (v0/v1 of one constant), CFunc_LightShow_PassEvent (lui/lw hoist and register numbering),
func_002B6C10 (lui/addiu order), func_002949F0 (v0/v1 of the first slt), CFunc_SetStreamParams (s0/s1), func_00272058 (v0/v1), func_0026EAA0,
func_0026DAF8 (a0/a1 for the index copy), func_00277220 (`move v0,zero` in the slot of the first bne), func_00289ED8 (p in v0 vs v1),
func_002891A8 (s0/s1 of i and this), func_002B4CE8 (one extra `move`), CFunc_GetNoteMapping (load order after the second call).
Given up: func_0027F938 (original copies arg3 to v0 first, like func_0027FCD8), func_002E62C0 (original hoists `li s0,1`), CFunc_LightShow_PlaySnapshot
(`x = (v == K)` folds to xor/sltiu again, hoists constants), func_002DD288 (original keeps the two `return 0` tails separate, we cross-jump them),
func_002DCD68 (last call's `lui/lw` of D_003722B0 goes into the jal slot instead of the store), func_00279150 / func_00276698 (peeled first
iteration of a pointer-chase loop), func_002763E0/func_002764E8/func_00276110 (alias chase: the original keeps p5/p6 copies inside the loops),
func_00289D30 (unrolled search: the original combines the biv increments, we keep four `i++`), func_002982B8 (list walk: `movn v0,a0` form needs a live copy),
func_00290A40 (rotated loop that enters at the test), CFunc_LightShow_BeginProcessBlock (we cross-jump the two case tails), CFunc_HideObjectByType (obj in a2 vs a0),
func_0029DA40 / func_0029A0E8 (stack iterator with vptr + virtual calls, not tried further), func_002B53E0 (string builder with short loops).

## Session 2 (div.s retry)
- func_002B7108 MATCH (store `*p` after computing the result so the branch follows the div).
- CFunc_Sqrt already matches (asm workaround present).
- CFunc_LinearMap: near miss, nonmatching/CFunc_LinearMap.cpp (clamps now match with `if (t<0) t=0; if (t>1) u=1 else u=t`; only float register numbers (lo f0 vs f2) and mtc1 placement differ).
- func_00271C10 MATCH (t_271480).
- Near misses (nonmatching/): func_002C10E8 (div.s now fine; only f-register numbers of the x0/y0/t temporaries differ), func_00299910 (only v0/v1 of the flag load), CFunc_LightShow_SetActive (`key == K` becomes sltiu; original is `bne; move v0,0; li v0,1`).
- Gave up: func_00286270 (while(p) loop with a self-looping `case 0`, gcc hoists the constants; 4 forms), func_00266C08 (the `s=2,k=1; while (s<0x80 && k<12)` loop is constant-folded by gcc; original is not), func_00275CE8 (iterator with two duplicated tails), func_002EB738/func_002EB858 (hash-table iterator inlined).
- Vector-to-3-floats pattern (`lq; dsrl32; pcpyud; mtc1 x3` before a call taking f12..f14: CFunc_GetViewportCameraPos, CFunc_GetWaypointDir, CFunc_NormalizeVector): union of u128/f32[4], aligned f32x4 struct and u32 bit-casts all go through the stack or emit `dsll32/dsra32`; inline asm (`dsrl32`/`pcpyud`/`mtc1`) gets within register numbering. Real source construct unknown.
- Twins round (dk twins after fix 5b03625): 4 of 10 matched (t_24BA88, t_268EB8, t_2908A0, t_2D4468). Skips: t_286A60 func_00288000 (struct/decl differs: Pool1DC vs S2867_Pool, D_00371330 vs D_0036D540), t_2754A0 func_00276720 (return type differs from the prototype), t_266800 func_00266E08 (D_00370B10 is int, twin has HTable*), t_2DCE78 func_002DE578 (needs S29D_Valid inline from t_29D230).
- Matched this session: func_002B7108, func_00271C10, func_00273428, func_002730D0, func_002DD160 (+4 twins). Lessons: float global state functions match well; do not wrap repeated expressions in an inline helper (it adds `move` copies), reuse the same variable in place; for an `asm("name")` alias definition, add GP_DATA by hand.

## Session 3
- func_002C8930 (div.s): near miss, nonmatching/func_002C8930.cpp; only one thing differs: the original keeps the table value `D_003CDFC8[idx].v[D_00372128[idx]]` in a callee-saved float ($f21, four float saves) while we use $f1. Findings: `.extern sym,4` gp arrays must be declared `[2]` (size <= 8) or gcc emits lui itself; read-then-fallback `if (call(&a)) x = a; else { F1E0(); x = 0; }` puts the lw in the bnez slot like the original.
- CFunc_LinearMap: nonmatching/CFunc_LinearMap.cpp refreshed (inline helper with args evaluated first puts lw a0/a1 before the compare; only the order of two lwc1 (start vs val) differs).
- func_00292928 MATCH (list walk with tail delete).
- func_00278D78 MATCH (binary search over {key,val} entries; hoist the table base `(char*)(t+1)` into its own variable before the key sum).
- func_0026AD48 MATCH (two linear scans over 0x80-byte entries; the loop continues when the call returns 1, so write `!= 1` then return i).
- func_00252FC0 MATCH (64-byte matrix copy of two 128-bit-member structs through pointer locals, source pointer declared first; gcc 2.x vtable entry vt[2]={delta,_,fn}).
- func_0028ABB0 MATCH (push onto a global stack then virtual dispatch; `if (id==K1) A; else if (id==K2) A; else B` with the same call twice gives the shared tail; stack slot written as `*(int*)(n*4 + (int)c + 0x1C)` with the value read first to get `addu idx,base` order (c->Push gave `addu base,idx`)).
- func_00274B08 MATCH (sprintf then in-place upcase/slash loop: index the buffer `dst[i]` with an unsigned i instead of a walking pointer; `u8 c` and `(char)c == '/'` give the lbu + sll/sra shape).
- func_00272F70 MATCH (loop over 0x40-byte entries: take the entry as `&arr[i]` inside the body, not a separate walking pointer, so the table address is set up after the loop test; inline S271Flags(id) for the sentinel flag lookup).
- func_002B5888 MATCH (linear search over int table with the 4x unrolled body; needed `// cflags: -funroll-loops` in t_2B3AC8, every function of the file still matches).
- func_0028C518, func_0028C4B0 MATCH after toolchain cf046cf (u32 -> f32 cast, `(f32)v`).
- CFunc_TimeGreaterThan MATCH (retry after cf046cf; read the start time before the second call, convert elapsed to float first, then multiply).
- func_0027EFA0 MATCH (retry after cf046cf; reassign the parameter pointer to its data to reuse a0).
- Near misses (nonmatching/): func_0026FC80 (lw a0 vs v1 and `slt v1,zero,s0` v1 known-zero CSE), func_002684D8 (5-entry fuzzy table, unrolled; leaves duplicate the tail `mul` in delay slots, we share it; size 0x304 vs 0x318), func_00269780 (a/b register swap, clear block addressing), func_002AB738 (two insns swapped around `sltiu t0,a0,1`), func_002530A8 (original has `addiu s2,s1,52` in the `beqz` delay slot; gcc leaves nop: toolchain/delay-slot question).
- Gave up: func_00299D20 (stack iterator with vptr), func_002EBC18 (hash iterator), func_002DD578 (unrolled search returning a u128 constant {0,0,0,1.0}), CFunc_DebugTransform (pextlw/pcpyld vector build), func_00292928-style hash chain functions func_002978C0/func_002996C0/func_00275BD0 not tried further, func_002677E0 (unrolled pool free-list).
- Session 3 total: 14 matches (func_00292928, func_00278D78, func_0026AD48, func_00252FC0, func_0028ABB0, func_00274B08, func_00272F70, func_002B5888, func_0028C518, func_0028C4B0, CFunc_TimeGreaterThan, func_0027EFA0).

## Session 4 (untried 0x100..0x1000)
- func_0026FD70 MATCH (index into the table as `i = b*0x14 + a*0x1B8`, reload `(int)D_003A8D40 + i` for the second store).
- func_0026F828: near miss, nonmatching/func_0026F828.cpp (struct store order around the trunc.w.s; all 720 orders of the six stores tried; final D_00370D10 reload v0 vs v1).
- func_002532C8: near miss, nonmatching/func_002532C8.cpp (only v0/v1 of the loop-end length load vs the sll i*4; ~8 loop forms).
- func_0028C658 gave up: three inlined hash-bucket lookups (key at +4, next at +0x10) with a loop over 0x30-byte entries; -funroll-loops unrolls the do-while, goto form is not unrolled but the shared 'return 0' tail and the register split differ (6 forms).
- func_002EB568: node-pool push loop (sprintf name + hash lookup); original keeps hash constant 0xAD7928D4 in s2 (loop-invariant li hoisted, call in loop uses move a0,s2); we rematerialise it, 6 forms (H local, while/for).
- func_0028A020 MATCH (constructor-like init: `func_00291230(table, b, &sp)` keeps a1 = original arg; reuse v for the call result; read sp[0] into a local before storing the previous result).
- func_00290AA8: script step loop (count at 0x14C+n*8, 0x148 first ptr). Body matches; original is a real loop entered with `b` to the test at the bottom, with s+0x14C and both D_ hi parts hoisted into s1/s3/s4; every while/for/goto form we tried either duplicates the test before the loop or does not hoist (9 forms).
- func_0029A7B8 MATCH (xor-encode copy, first arg unused 'this'; 2-byte struct copy from the stack key gives the lb/lb/sb/sb; separate copy `int m = n` for the call and loop counter fixed the arg move order; pointer-walking do/while under -funroll-loops).
- func_0026C120 gave up: search loop matches; the tail `cnt = &D[idx].unk2C; n = *cnt; *cnt = n+1; items[n] = ..; f(b, cnt)` keeps folding the +0x2C into the table base (s0 = D+44) where the original keeps s0 = D and a1 = (s0+44)+(idx<<7); 8 forms.
- func_00273940 MATCH (slot allocator: two unused-by-name float params f12/f13 are passed straight to func_002730D0(float,float), the third float is the real one in f14; D_00370DB4 declared volatile so the store stays out of the jal delay slot).
- func_00273600 MATCH (early-return guards instead of nested ifs; D_00372EC4 re-declared as a struct pointer through an asm alias).
