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
- func_0026B628 gave up: table slot init (D_003A44B0 + (idx<<7)); original keeps base and offset in two saved registers across the calls and recomputes each field address (copies via daddu); gcc CSEs/rematerialises them (5 forms).
- func_00276BB0 MATCH (sibling of func_002769B0: copy the pointer into a local inside the if; r[2] = 9).
- func_002727E8 MATCH (final three stores in the order unkC &= ~4, unk4 = 1, unk8 = 7; found by trying the six orders).
- func_002729C0: near miss, nonmatching/func_002729C0.cpp (body matches; gcc cross-jumps the two identical func_00271A98 call tails (0x30 vs 0x70 branches), the original keeps both copies, size 0x150 vs 0x168; func_00273D88 takes no argument).
- func_002ABC18 MATCH (array iterate with the stack object passed to func_0028C9F0; do/while with i++ before the call; the else branch and the fall-through both end in the same global store).
- func_002ABD58 MATCH (twin of func_002ABC18 with other keys and D_00372F20; dk twins did not see it because the constants differ).
- func_0027F788 MATCH (string copy into a buffer after a header; reassign the buffer parameter to the call result and keep the original in a local for the length).
- func_00266A20 MATCH (max of fabsf over 5 or 2 floats, count chosen by field 0x14 == 2; plain for loop under -funroll-loops).
- CFunc_FlushCutsceneDestroyList gave up: std::list-style destroy loop with two stack iterators (end at sp4, cur at sp14) then clear; the original keeps hi(D_0039A3C8) in s2 across the loop and reads the head before adding 4 to the sentinel address; we fold the +4 first and rematerialise lui (5 forms).
- CFunc_GetRelativePath gave up: everything matches except the return-0 tails: the original keeps a separate `b end; move v0,0` block between the strlen add and the second func_0027DF00 call (reached from both the null result and the r==0 test), gcc merges all return-0 paths into one at the end (9 forms: ret var, nested ifs, r==0 placement).
- CFunc_AppendSuffix MATCH (stack buffers 112 + 32 bytes; ints cap/num read through func_0027D1F8, key through func_0027D870).
- CFunc_RequireParams MATCH (early return 0 for null array; result flags c/d as ints so the branches keep the two delay-slot v0=0 forms).
- CFunc_kill_object_later_CFunc gave up: state machine (0 = init, 1 = go, else spin) body is simple; the original keeps constant 1 in s1 (loop-weighted) and uses `move a0,sp` for the stack object, we cache &obj in s1; goto and for/while forms tried (4).
- CFunc_RegisterAtoms: near miss, nonmatching/CFunc_RegisterAtoms.cpp (hash insert like func_0014FF20; only a0/a1 swap between the node pointer x (= items pointer when no node is allocated, passed to func_0011A568) and the constant 12; the original also has a nop after jal func_002D5888).
- func_00293D80 gave up: DMA setup; loops match (use `long` for the sd -1 stores, `off + (int)ptr` operand order) but the three hardware-register addresses 0x1000B420/B410/B430 are lui/ori'd into registers shared with the func_00293C70(5, B430, B410) arguments in the original; gcc folds them into the stores (lui at + offset). Only an asm barrier gets close (not used).
- func_0029A8E8: near miss, nonmatching/func_0029A8E8.cpp (decode twin of func_0029A7B8; only the `move a2,s1` is scheduled before the two header lb/sb in ours, after them in the original).
- func_0026F5A8: near miss, nonmatching/func_0026F5A8.cpp (do/while pair loop, volatile u32 hi = 0xFFFFF000 for the stack word, mask = flags | hi then movn; only the numbering of s-registers (e, mask, j, one, p+1) differs).
- func_002EAB18: near miss, nonmatching/func_002EAB18.cpp (needs // cflags: -funroll-loops in t_2E90B0, not added: the original unrolls an empty n-1..0 loop and the free-list build; ours differs in register numbering and in which Heap_Alloc argument constant lands in the jal delay slot).
- func_002E81B8: near miss, nonmatching/func_002E81B8.cpp (two-entry loop over 0x4C-byte sound records unrolled; only the last iteration differs: original loads e[1].unk0 before bumping the pointer in the bne delay slot, ours bumps first; u32 -> float uses the bltz/add.s sequence correctly).
- func_002E8C28: two-record sound-driver toggle; the original does not loop: record 0 is reached through s0 = D+0x20 with negative offsets plus a direct D+0x20 reload via s1 for the last field, record 1 through s0 = D+0x6C; for-loop over D_003EB000[2] gives a different layout (1 form).
- func_00273748 MATCH (sibling of func_00273600 with two extra guards: g == 0 && f(b) != 1, h == 0 && f(c) != 1, early return 0 each).
- func_002738C0: the original ANDs the loaded word with 0xFF000000 and then 0x08000000 in two separate and insns (lui/lui/and/and/sltu); gcc folds the constants in every plain form (u32 temp, casts, struct); func_001210C8 is called with the caller's a0 unchanged (take an int parameter).
- func_002EBCF8: near miss, nonmatching/func_002EBCF8.cpp. Decoded the inlined hash-table iterator that CFunc_ClearGlobalTags, func_002A7650, func_0026A030, func_002EB738/858/BC18 also use: table {bits@0, nodes@4, idx@0xC, cur@0x10}, node {key, val, next@8}, Begin = idx=-1,cur=0; Next = (cur ? cur=cur->next : idx>=0 ? fail) then scan idx+1.. while node.val==0 && node.next==0; value = cur ? cur->val : 0. Structure now matches (nonmatching file); remaining: the original loads the global into v0, stores idx/cur through v0, then copies to a2 (move a2,v0) and has a nop before the loop; size 0xd4 vs 0xe0.
- func_002B7140: near miss, nonmatching/func_002B7140.cpp (best-of-5 float search with the Arr.Get helper; only i is in a1 instead of v1 and the invariant sll/lui/addu hoist order differs; 8 loop/declaration forms).
- func_002A1AE0: near miss, nonmatching/func_002A1AE0.cpp (script flag check + list walk calling func_002A1918(x, mode, s, params, 1); only s1/s2 swapped between params and the loop index i, 4 declaration orders).
- func_002CC5A0 MATCH (two script-struct builders with a key test; plain straight translation; final `if (s1) { AC90(s1); 13250(s1); }` delete).
- func_0026FAE0: near miss, nonmatching/func_0026FAE0.cpp (two-float clamp-to-15-bit writer; `b = a | (b << 1)` reuses the parameter; only the numbering of s-registers differs: original keeps b in s0 and the second clamped value in s3).
- func_00270340: near miss, nonmatching/func_00270340.cpp (flag set/clear on D_003A8D40 records plus two func_00271198 writes; original keeps hi(D_003A8D40) in s6 and indexes (b*0x14 + a*0x1B8) + base; ours swaps a/b registers and the hi copy).
- CFunc_compute_desired_drummer_twist: near miss, nonmatching/CFunc_compute_desired_drummer_twist.cpp (value read after the call: `int ok = call(); v = sp20; if (!ok) {...; v = 0;}`; only the two float accumulators land in swapped registers (f20/f21) and the mov.s f21,f20 is scheduled after the first call; 6 forms).
- func_002D02A0: script event dispatcher (4 branches over func_00275F08/func_0027CC30 reads, ends in func_002D0240(key, arg)); straight translation is 0x204 vs 0x220 and params/arg land in swapped s-registers; 1 form.
- func_00295E50: near miss, nonmatching/func_00295E50.cpp (object factory: virtual calls through the vptr at 0x2418 are entries f9() and f15(int, u16) of a class with 15+ virtuals declared after a pad[0x2418]; intrusive list push at +0x1808; only the s-register of the reassigned parameter e (s3 in ours, s5 in the original) and the delay-slot a1=flags move differ).
- func_00289B40 MATCH (destructor with delete flag: unlink from the global list, free members; the array of two sub-objects 0x30 apart is a countdown loop that -funroll-loops unrolls completely (the lone nop 8-aligns .L00289C58), so t_288B10 now has `// cflags: -funroll-loops`; `int *pc = &t->unkC8` before the test keeps the addiu in the beqz delay slot).
- func_00253678 MATCH (lazy-init of five defaults, then five `t == 0 || (read ^ 1) != 0 -> default` blocks; the result flag `int r = t != 0` computed right after t is kept in its own s-register (sltu in the beqz delay slot)).
- func_002AF170 MATCH (pad-state reset: every byte store goes through `o->unk1C->b[i]` so the u8 stores alias the pointer and gcc reloads it each time; stores in the asm order, then the flag bits, then the second run).
- CFunc_LightShow_RefreshSpotlightOverrideParams: near miss, nonmatching/CFunc_LightShow_RefreshSpotlightOverrideParams.cpp (everything but the prologue save order matches: ours emits sd s3 before sd s1/s2; 4 declaration orders).
- CFunc_Dump MATCH (script-struct builder: sprintf into a 0x400 stack buffer, a 0x10-byte component record initialised in the func_0027ABB0 order key/next/val/b8/type/unk2, then func_00279358 copy and key patch; same `if (o) { AC90; 13250 }` delete tail).
- func_002592E0 MATCH (value-to-text helper: struct branch builds a script struct and reads a string, int branch, float branch (func_00317588 returns the double bits in a 64-bit long); returns 1 on every path, so declare it int).
- func_0026D480: near miss, nonmatching/func_0026D480.cpp (two 0x80-stride record loops plus the tail dispatch; body matches, the original builds D_003A44B0 with lui/addiu and adds the field offset (+0x1C / +0x38) in a separate addiu, we fold it into the symbol or the access offsets; the same 4 forms: struct index, int* field pointer).
- func_002D2120 MATCH (frame-timer window check: swap two func_002CDCF8 float slots, optional func_002D2118, then spawn a script when prev < t*0.001 <= now; plain translation, aliases (asm names) for the declarations the file already has with other types).
- CFunc_DoScreenElementMorphList: near miss, nonmatching/CFunc_DoScreenElementMorphList.cpp (array loop over morph entries; stack layout matches with a 16-byte ref at 0x110 (int[4]); original hoists the buffer address, &ref, lui hi(D_003720D8) and the constant 1 into s3/s1/s4/s5 and keeps i in s2, ours keeps fewer invariants and swaps s2/s3; size 0x190 vs 0x198).
- func_002DB2D0: gave up (nonmatching/func_002DB2D0.cpp is a first draft, not a near miss): registers seven callbacks through func_002981A0 then fixes two table entries; ours is 0x21c vs 0x23c and the saved-register assignment (o s5, base s6, y s4, hoisted 0xB0 and base+8 in s2/s3) differs.

## Round 3 (priority: VU0 register variables in branch-likely slots, then untried 0x100..0x1000)

- Branch-likely + lqc2/sqc2/qmfc2 slot scan of my files: only func_00252090 (0xcc0, 26% VU0), func_002687F0 (0x6c4),
  func_002BE288 (0x364, 36% VU0). All three are large mixed VU0 code with vrsqrt/matrix products; skipped, not attempted.
- CFunc_SetVectorComponents MATCH: lanes of a TI128 as three float args: x `mtc1 %1,%0` ("=f"), y/z as TWO asms each:
  `dsrl32`/`pcpyud` into `u32 t` ("=r"), then `mtc1` from t into "=f" (a single asm with "=r"(f) gives a different schedule).
- CFunc_GetVectorComponents, CFunc_NormalizeVector MATCH (same lane helpers; NormalizeVector: one `asm volatile` with
  lqc2/vmul/vaddy/vaddz/qmfc2 `$2`/mtc1 `$f0`/nop/nop/sqrt.s as in t_1D2508, clobbers "$2","$f0"; then
  `1.0f/len` -> `mfc1` -> `qmtc2.ni`/`vmulx`/`sqc2` in a second asm with a "memory" clobber). This solves the
  "vector to 3 floats" pattern listed above as not reproduced.

## t_2626E0 (round 3)
- CFunc_GetViewportCameraPos, CFunc_GetViewportCameraOrient MATCH (lane helpers as in t_24BA88). Stack layout of the
  three lookup temporaries (id=0, key, i) only matched as one local struct `{int id; int k; int i;}` (separate
  locals in any declaration order gave id/k swapped), and `int kk = t.k;` before the call to get lw a1 before lw a0.
  Passing `c->unk90.x` directly to the lane helpers (no local u128) gives the original register choice.

### Round 4 (twins and pool allocators)
- Matched: func_0024D068 (t_24BA88), func_00288000 (t_286A60), func_00276720 (t_2754A0), func_002AEB48 (t_2AD528),
  func_00266E08 (t_266800, hash Get via asm-label alias of the int global), func_002DE578 (t_2DCE78).
- `dk twins` failed on these only for declaration/type clashes; writing the twin by hand with the local types works.
- Skipped (tiny loops): func_00276620, func_00276668, func_00276698 (t_2754A0).
- func_002DD3E0 (t_2DCE78): sin/cos + MakeVec store; near (0xb4 vs 0xb0): original does two separate idx*0x30 mults, dsrl32 hoisted first, w=0x3F800000 as u32 GPR (lui), y=0.0f via mtc1; ours CSEs the mult. Given up.
- func_00269D38 (t_268EB8): hash Get (as t_1E95C0 HTable::Get, const u32& key) + first-free-of-4 slot insert; hash part never gets the original's separate `!n` test when the result is consumed afterwards (0x10c vs 0x114). Given up.
- CFunc_RemoveFromCutsceneDestroyList (t_260658) MATCH: stack list iterators `It end, it, b, c, d, e` (16 bytes, cur at +4), read
  `it` from the list before `end`; `void *hp = D_00368A38[0]` read right before the unlink stores (as in func_00225FA0).
- CFunc_AddToCutsceneDestroyList: ldl/ldr struct copy into a list node, not attempted.
- func_002AEA30 (t_2AD528): near miss, nonmatching/func_002AEA30.cpp: stack-iterator unlink inside a dtor; all slots/stores right except gcc tail-merges the final `it = x` store of then/else (original keeps then: it, d; else: it).
- CFunc_LightShow_OverrideColor (t_2AD528): near miss, nonmatching/CFunc_LightShow_OverrideColor.cpp; everything matches (MakeVec with `pextlw %0,%2,%1` operands (x,y)/(z,w), `sc` stack int + separate `c` copy) except one swap: original `move a0,s0` before `li a2,6` for the func_0027CC30 call (ours li first); 6 forms.
- func_00250C30 (t_250010) MATCH: lane getters (mtc1 / dsrl32+mtc1 / pcpyud+mtc1) and `Vec(x,y,z,w)` as `pextlw %0,%2,%1` with operands (x,y)/(z,w)
  (this operand order gives the original's register choice; `%1,%2` with (y,x) swaps the mfc1 targets); color word
  `0xFF000000 | (c[2] << 16) | (c[1] << 8) | c[0]` computed after the two vectors; vectors p then q.
- func_0027CA28 (t_27B7D0) MATCH: compound value type 6 with a vec4 source `u128*`: `Get(*src)` reloaded each use (lq again after a
  swc1 store), W = pcpyud + dsrl32 + mtc1, `if (w >= 0) v = src else v = -src`.
- func_0027D560 (t_27B7D0): skipped, `c1 0x10004` (unknown COP1 encoding after vaddy/vaddz/qmfc2, 1 - len^2 clamped at 0).
- CFunc_GetValueFromVolume: skipped (cvt.w.s `.word` + div by 10 + mfc1 hazard).
- CFunc_SetViewportCameraPos (t_2626E0) MATCH: same lookup as the Get* siblings; `int d = D_0036D3B0[0]` read before the quad store so the
  sq lands in the jal delay slot; the copy temp needs `register u128 q asm("$3") = v` (original uses v1 there, pin = last resort).
- CFunc_SetViewportCameraOrient: near miss (nonmatching/CFunc_SetViewportCameraOrient.cpp). VU0 pattern: `register u128 vf3/vf2/vf1 asm(..)
  = x/y/z; asm("vsub.w %0,$vf0,$vf0" : "+j"(..))` x3 then stores back; node copy of 0x40 bytes twice with `struct B64{char b[0x40];}
  __attribute__((aligned(16)))`, `S* src = &c->unk90` and separate `d1`/`d2` dest pointers (this gives the original base registers). Only
  the position of `lui/lw D_0036D3B0` vs `lq 0x20(sp)` differs (original reads D before the lq, ours after).
- func_0026BA48 (t_26AEF8): near miss (0x164 vs 0x160), nonmatching/func_0026BA48.cpp: everything matches (in-place `if (e == 0) e = a` gives movz, array-indexed `D[r].f` each time to avoid CSE, `&= 0xFFFFFFFB` for lui/ori) except the r == -1 return: original is `bne; lui; b L; move v0,zero` inline, ours `beq L'` to a separate zero block; 6 structural forms.
- func_002910E0 (t_2908A0): near miss, nonmatching/func_002910E0.cpp; loop/branch structure right (heap handle search: for(;;) { if (len-0x1000 < size || !(f() < g())) { n = l->tail; if (n) {erase; continue} if (f() != g()) { if (cur==a) cur=b, continue; if (cur==b) cur=c, continue; } } return cur; }); only scheduling of the `cur = a` copy differs (original keeps it in the bnez delay slot, ours hoists it after the first heap call) and the D_00368A38 reload form in the size>0x6400 branch.
- func_00282268 (t_282268), also func_00283698, func_002837C0, func_0027B678 (same alias-resolving hash lookups D_003710A4[key & 0x7FFF] -> chain unk10, entry type byte at +2 in {0xD,0x1A} -> follow unkC): near miss nonmatching/func_00282268.cpp (0x128 vs 0x12c) with `static inline N* Find(key){ for (n = t[key & 0x7FFF]; n; n = n->unk10) if (n->unk4 == key) return n; return 0; }` called twice; plain `while` forms give 0x100 (gcc threads the redundant null tests the original keeps). Not solved; the other three share the lookup.
- CFunc_AddParam (t_256260) MATCH: `switch (p->type)` on the QB component type; the case order in the source must follow the jump-table
  target addresses (13, 3, 10, 12 after 1, 2), loop `next = f(params, p)` before the body.
- CFunc_GetNextArrayElement (t_256260) MATCH: `int n = r->size` read before the `if (idx < 0)` (puts the lw in the bgez delay slot); inline
  `GetI(i)` member (`size == 1 ? data : ((int*)data)[i]`, early return form) gives the `lw a2,idx` delay-slot shape; the
  int/name/pair cases need `int st = script->unk20; register u32 key asm("$5") = 0xBEBFA1C6;` (pin: without it gcc rematerialises the constant
  after the branches, the original loads lui/ori before the size test), float/string cases `int st = script->unk20;` before the inner call.
- CFunc_GetElement (t_256260): near miss, nonmatching/CFunc_GetElement.cpp: structure (return 1 if no array, 0 if idx out of range, switch 10/12/1 in that source order, `int n = r->size`, `int st = script->unk20` first in the 12/1 cases) matches except two scheduling swaps: case 10 tail `lui a1` before `lw a0` (original beqz+nop, ours beqzl) and case 1 `move a0,s0` before `move a2,v0`; pins on $4/$5 do not change it.
- CFunc_ForEachIn (t_256260): near miss, nonmatching/CFunc_ForEachIn.cpp: all structure matches (switch (mode) with case 12 (array, do/while, GetI) before case 10 (struct components, `(flags & 0xFE00) == 0x1400`); `mode = f() ? 10 : 0`), only differences are a v0/v1 swap in the first array-size load and the call setup order `move a0,s0` before `move a2,v0` (same swap as CFunc_GetElement case 1: original moves the callee-saved first arg before the call result; ours the other way round). Possible toolchain/scheduler item: arg moves of f(saved_reg, x, call()).
- CFunc_GetGlobalTags (t_2BCDA8) MATCH: SHT_Find inline + `if (v == 0) return 0;` first, inner `if (r != 0) {...; return 1;} return 0;` (this form keeps the first return-0 stub that the later failure jumps back to); comp init order key, next, val, b8, type, unk2.
- CFunc_SetGlobalTags (t_2BCDA8): near miss (0x1e8 vs 0x1ec), nonmatching/CFunc_SetGlobalTags.cpp: SHT_Find + hash insert (template func_0014FF20: `b->val != 0 || b->key != 0` -> n = func_0011C3A8(0); if (n) n = func_002D5C88(n); ...; else key/val; count++) with the same D_003AD040 symbol (cast, not an asm alias, so the lui is shared); remaining: k/tab register numbers (a1/a2 swapped) and the arg-setup order of the first call.
- func_0027BBF8 (t_27B7D0) MATCH: hash table built from a component list (alloc in heap 5, `func_0027E4B0`, insert template of func_0014FF20: `b->val != 0 || b->key != 0` -> n = func_0011C3A8(0); if (n) n = func_0027E488(n) ...; count++), then a type-0x1B component with val = table. Needs the key copy (`int key = k; asm("" : "+r"(key))` + `register int key asm("$18")`) and three more pins (ix $2, it $4, bv $3) for the register numbers / v0-v1 choice: last resort, probably a gcc pseudo-numbering artefact of an inline Insert(table, key, value).
- CFunc_SetGlobalTags (t_2BCDA8) MATCH (was a near miss; nonmatching copy removed): the Find result goes through a separate variable (`int f = SHT_Find(&D, k); int v = f;`) which keeps the original's `move s1,v0` copy after the inlined lookup (v is assigned again on the insert path); hash insert as func_0014FF20 on the same D_003AD040 symbol.
- func_00297578 (t_296A10) MATCH: SGI STL `_Rb_tree_rebalance` verbatim (color unk0: red 0, black 1; parent unk4, left unk8, right unkC; rotate_left = func_002974D8, rotate_right = func_00297528).
- func_002976E8 (t_296A10) MATCH: `_Rb_tree::_M_insert` (header at +4, count +8, node value at +0x10 {int key; struct{int,int} second}); placement-new check `if (&n->value != 0)`; the 8-byte struct copy gives the ldl/ldr/sdl/sdr pair for free; node pointer must go through a separate local `n` (`z = n` after the if), otherwise z lives in a saved register of its own (5 saved regs instead of 4).
- func_00298858 (t_296A10): not solved, no near miss kept: event dispatch over a list with the stack iterator {+4 cur, +8 vptr D_0035C4B8} (Valid = nor/movz idiom as S29D_Valid), jalr obj->unk18(ev, obj), result chain 0/2/5/3 return, 4 break; the original keeps &it in s2, lui(D) in s8 and the constants 2,5,3,4 hoisted into s6..s3; ours differs in frame (0x70 vs 0x60) and iterator access (member inline First/Next did not reproduce the bnez/b/move v0,zero null test).
- func_002BDCD0 (t_2BCDA8) and the other hash-iterating CFuncs (CFunc_DeRegisterAtoms, CFunc_ClearNoteMappings, func_002EB970): tried the HTable Start/GetNext(&key) iterator of t_1E95C0 (Start; key = 0; peeled first GetNext + while): 0x1c0 vs 0x1d4. The original keeps both a lui reg (bits read directly from the symbol in the loop) and the full address in s-registers (5 saved regs), i.e. D.bits is read through the symbol while the iterator fields go through a table pointer; not reproduced.
- CFunc_StarPowerOn (t_2D2350): near miss (0x24c vs 0x244), nonmatching/CFunc_StarPowerOn.cpp: handles R{p} on the stack (a,b,c) filled by func_00145310(&h, sys, id, 0), release `if (h.p) { func_001CE888(h.p, &h); h.p = 0; }` c,b,a, colour from a QB array (GetI 0..3 stored as s8, 4-byte struct copy via lwl/lwr/swl/swr), i read after the call (`if (!f) {g; i = 0;} else i = sp50`, pin $3); remaining: table-address/index scheduling and an extra address copy for the second handle.
- func_0026C250 (t_26AEF8) MATCH: scan of the 0x80-byte entries (found = unk1C == c && unk0 == a && f(unk10) != 1), remove-first shift loop `for (j = 1; j < e->unk2C; j++) e->items[j-1] = e->items[j];` (index form: an explicit pointer p made n and p interfere and moved n from a0 to a2); no GP_DATA for D_00372E98 (lui first, gp only in delay slots); `return 1` when the first item does not match, `return 0` when the count is 0.
- func_0026CA78 (t_26AEF8) MATCH: add a name to a table (0x28-byte slots at +n*0x28 in the 0xCB0 entry, uppercase loop `while (i < strlen(dst))`, 18-byte default record copy `struct {char b[0x12];}` = ldl/ldr x2 + lb/sb x2); `char *p = dst` written after strcpy (a call-delay-slot copy), count re-read from the entry for the record slot.
- func_0026C5E8 (t_26AEF8): near miss (0x144 vs 0x150), nonmatching/func_0026C5E8.cpp: logic right (strcpy to D_003A8050, tempo f = D_00370C1C or f(D_00370AE0), search of the 0x28 name slots with func_0028DAB8 compare, then func_0026D6D0(i,1,t)); the original places the loop's found-stub (func_0026D6D0 call + return) physically between the `if (t != 0)` test and the `f = func_00268328()` block; layout not reproduced.
- CFunc_InputArrayAddElement (t_2AF598): near miss (0x240 vs 0x244), nonmatching/CFunc_InputArrayAddElement.cpp: like CFunc_SongArraySet (8 components via `bool m = !f(...); if (m) return 0;`), then the same QB alias lookup (`D_003710A4[h & 0x7FFF]` chain unk10) which here is peeled once and keeps a key copy (`move v0,a0`) and uses the cursor itself as result; for-return Find gives 0x240, plain while 0x22c. The alias-lookup family (func_00282268/00283698/002837C0/00283540/0027B678/0027BA18/0027D650) all share this one gcc shape that I could not reproduce.
- CFunc_MemCardFileExists (t_2A53A8) MATCH: file name builder per platform `switch (D_00368740[0])` (6: strcpy(buf, f(d, p1)); 4: s = func_002A5638(d, p1), printf(buf, D_00371D90, r, r) after func_00121BF0; 1,2,3,5: printf(buf, D_00362390, v, buf2, v, buf2)); stale a1: `func_002A4A58(d, p1)` result unused; 3-arg `func_001224F8(f, 0, 2)`; the release is a manual vtable call `vt->fn((char*)f + vt->delta, 3)` with `register S2A5_VT *vt asm("$3")` (original has vptr in v1, fn in v0, unlike the usual virtual-class form).
- func_002EBA98 (t_2EB1C0) MATCH: sound-driver event retire: func_002EBFF8(D_003729D0, &t) with t = e->unk0 (2 args; a2 stale), item list to freelist with switch 0/1/2 in source order, scan of the active list (`u32 ec = e->unk1C` read first, found flag), func_0011EF10(cur) with the null cursor as stale a0, push on D_003729C8 or D_003729C4.
- func_002EAC68 (t_2E90B0): near miss (0x19c vs 0x194), nonmatching/func_002EAC68.cpp: sound event allocation from the freelist D_003729BC, 5-way checksum switch (1,2,4,5,3 in ascending checksum order) with `li v0,N` in the beq delay slots of the original, then the `name_%d` lookup loop; original keeps 0x69812EAC hoisted in s2 for the loop (`register int key asm("$18")` reproduces it) and &sp14 in s0; remaining diff: the switch targets (ours has unfilled `li/b` stubs).
- func_002DCF10 (t_2DCE78): near miss (frame 0x50 vs 0x40), nonmatching/func_002DCF10.cpp: a stack Color `c` whose four bytes are re-set to 0xFF before every call (dead stores: `c.Set(0xFF,0xFF,0xFF,0xFF)` member gives the sb 0x10(sp) + sb 1..3(s1) pointer shape), calls func_002EA460/func_0028C9F0/func_0028CF40/..., heap-5 push; the original keeps flag and the heap handle in the same s0 and the 255 constant in s2 (3 saved regs), ours needs a 4th.
- func_002DC700 (t_2DAE48): near miss (0x1d8 vs 0x1dc), nonmatching/func_002DC700.cpp: two small switches (sel 0/1/2 sets flag ptr base+0x28/2C/30 and two checksums; mode 0x10001/0x10002 toggles the flag and calls func_0028D1D8). `u32 sel` makes the first switch compile as the original's ==1, ==0, ==2 compare sequence (signed gives slti range tests); the second switch is a binary tree in the original (== 0x10002, sltu > exit, == 0x10001, constants hoisted) but a plain sequence in ours.
- func_002DE738 (t_2DCE78): near miss (same size, scheduling only), nonmatching/func_002DE738.cpp: 20 event registrations func_002981A0(func_001CA010(self) + 4, id, fn, mode, self, level) between func_001C98F0(self) and func_002DE5B0(self); the original leaves `addiu a0,v0,4` as the last arg insn (jal delay slot), ours computes it first. Same "first argument last" ordering seen in CFunc_GetElement/ForEachIn (call-result-derived arg vs constants).
- func_002A77E0 (t_2A74C0): near miss (only s1/s2 numbering of the array pointer and loop counter swapped), nonmatching/func_002A77E0.cpp: heap-5 push, QB array copied element by element (GetI) into a new object (func_002A74C0 / func_002A75F0), hash insert as func_0027BBF8 on D_003AC7A0 (func_0011C3A8(0); n = func_002AE0A0(n)), heap flag +0x188 set 0 then 1. `register` on i or pins change the loop to bnez/nop.
- func_0028BC70 (t_28AB28): near miss (0x134 vs 0x138), nonmatching/func_0028BC70.cpp: ring of 0x14-byte entries with inline first slot (+0x28), moved to a 200-byte heap buffer when the cursor is still the inline slot (5-int struct copy = ldl/ldr x2 + lw; pointers of the 0x30-byte items rebased), then `p = p ? p + 1 : unk3C` as p-in-place; the original schedules `move a1,zero` (loop counter) after the struct copy and `li a1,1` after the lw, ours hoists both.
- func_00267F08 (t_266800, -funroll-loops file; unrolled x2 scan of the 0x58-byte table D_003A1900 for the entry with the smallest (unk4C, unk50) that passes func_00270E40 != 0 && func_00270E88 == 0 && i != a2): not matched, no near miss kept: the original stores a0, a1, a2 at sp+0/4/8 and reloads a2 from memory in the loop (the three arguments live in memory: address taken / struct-like), by-value struct and plain ints both differ; the first unrolled half also keeps best/best2 in s1/s4.
- func_002670B0 (t_266800) MATCH: two scans of the 44-entry table (0x58 stride) with -funroll-loops: first `unk0 == key && func_00270E40(i)` returns i, second `unk4 == key && ...` runs func_00275EE8(0x6D2E270E, 0) == 0 -> func_00275EE8(0xD7BB618D, 0) then returns i; -1 at the end (func_00275EE8 needs an int-returning alias there).
- func_00270A90 (t_26F3B8): near miss (two preheader insns swapped: `addiu s2,v0,1` (T+1 induction pointer) vs `li s5,1`), nonmatching/func_00270A90.cpp: sound voice table `D_003A90B0[8]` of {s8 a, s8 b}; entry = D_003A8D40[a][b] (0x14 stride, 0x1B8 per row); `n = e->unk10 - 1; if (n < 0) a = -1; else if (func_00273EB0(n) == 1) { func_00271108(a, b); e->unk10 = 0; a = -1; }` unrolled x2 by -funroll-loops.
- func_0029F840 (t_29F288): not matched, no near miss kept: two stack list iterators (cur +4 / vptr +8, second at +0x14/+0x18) walked inline (`Valid1` = movz form for the first element, `Valid2` = `~x != 0 ? x : 0` movn form in the loop, `bnez/b/move v0,zero` null tests, iterator address kept in a register) clearing a byte (+0x24 resp. +0x18) of every object; plain stack structs with static-inline Valid functions give 0xfc bytes vs 0x12c. Same family: func_0029F090/F648/FA08, func_00298858, func_0029EAC8.
- func_0026A1A8 (t_268EB8): near miss (0x1b8 vs 0x1bc, register allocation: the original keeps the key and the four other arguments in s-registers from the start, 8 saved registers, ours 6), nonmatching/func_0026A1A8.cpp: HTable::Get(const u32&) (key on the stack) then Heap_Alloc(D_00368A38, 0x1C, 1, 0) object {unk18=a1, unk4=-1, unkC=a2, unk10=a3, unk14=a4, unk0=-1, unk8=key} and the func_0027BBF8-style insert (h = key copy for the chained node, key for the empty slot), count++, return 1/0.
- CFunc_CheckNoteHoldWait (t_2C7900, -funroll-loops file): not matched, no near miss kept: result 1 unless a hold bit (0x10000 >> 4*j, j < 5) of D_00372120[player-1] is set; for a set bit the handle func_00145310(&h, D_00369798, D_003BEE18[i*5+j], 0) is created and destroyed (inline dtor: `if (h.p) { func_001CE888(h.p, &h); h.p = 0; }`) and the function returns 0. The original has the handle test as a condition expression (`(get, h.p == 0) || (dtor, h.p == 0)`), the first fret peeled and the loop unrolled x2 (7 saved regs, 0x1a4 bytes); the straightforward loop with break is 0xcc bytes and not unrolled.
- CFunc_GetViewport2DPosFrom3D (t_2626E0) MATCH: viewport lookup as the siblings (id via func_0027D870, else func_0015DB00(idx)), func_001230D0(vp, &v, &x, &y, &z, 1), the three results returned through func_0027C1F8; the last one is `(f32)(u32)z` (bltz/srl/andi/or/cvt/add.s idiom) and needs the arguments before the branches: `int st = script->unk20; register u32 key asm("$5") = 0x42CDBE75;` (same trick as CFunc_GetNextArrayElement). Declarations are asm-label aliases because the file declares the callees later with other types.
- CFunc_DumpNoteMappings (t_2BEEE0): near miss (0x154 vs 0x14c), nonmatching/CFunc_DumpNoteMappings.cpp: only iterates the table D_003720E0 (HTable Start/GetNext, empty body): `t = D; if (t) { t->Start(); if (t->GetNext()) while (D_003720E0->GetNext()) {} } return 1;` gives the right shape (first element through t in a1, loop through a reload of the global) but the failure stub of the peeled first scan is laid out before the loop in ours, after it in the original.
- func_002A2568 (t_2A12B0) MATCH: the flag command core (Send/Clear/Query/SendException call it with mode 0/1/2/5): ctx on the stack {int id; S2A2550_0 r} (return r.unk8 = sp+0xC), `func_002A2550(&ctx.r, sp28, mode)`, func_001D83D0(D_0036D3B0, func_002A2200, &ctx) for a single name, or the name list (func_00223388(sp30, &n, 1), u16 count, do/while with arr++/i++) with func_002A2230; the mode==5 branch reads the argument through func_0027D870 into a temp first.
- CFunc_SetSoundBussEffects (t_252068): near miss (same size; prologue order of 3 insns and `move a0,s2` vs `move a0,s0` for the key argument), nonmatching/CFunc_SetSoundBussEffects.cpp: do/while over buss index i from 1 (i < 2 uses the fixed key 0x499F6E0D, otherwise printf(buf, D_00370430, i) and func_001150E0(key, buf)), reads two QB values from the found struct, switch on the type checksum (0x0F36AD93 reads a float then func_00269888; six others read a float at 0x906B67BA); the checksum constant hoisted into s2 needs `register int c asm("$18")` and the loop key `register int key asm("$16") = c`.
- func_002A77E0 update: with `int h2 = key; asm("" : "+r"(h2));` for the chained node key (original `move s1,s4`) and `S2A77_HT *t = &D_003AC7A0` only the loop-register numbering (a in s1 / i in s2, original reversed) and loop shape differ; `register u32 i asm("$17")` fixes the numbers but turns the loop's bnezl into bnez/nop.
- CFunc_SetViewportCameraOrient (t_2626E0) MATCH (was a near miss; nonmatching copy removed): the remaining difference was the order of the D_0036D3B0 load vs the `lq 0x20(sp)`; reading both through volatile (`int d = *(volatile int *)&D_0036D3B0[0]; register u128 ya asm("$2") = *(volatile u128 *)&y;`) keeps the source order (volatile reads are not reordered against each other), plus the earlier pins (ya $2, za $3), the VU0 register variables vf3/vf2/vf1 with `vsub.w`, and the 0x40-byte aligned B64 block copies through `src`/`d1`/`d2` pointers. Generic trick for scheduler-order differences between two loads.

## Round 2 (untried 0x100..0x1000)

- CFunc_CreateGemMover (t_2BEEE0): near miss (same size, only the load order of the final call's arguments differs: original loads t0/f12../a2/f19/a3/t1 interleaved, ours loads a2,a3,t1 first), nonmatching/CFunc_CreateGemMover.cpp: 15-arg func_002BF900 call after 12 QB reads; `&b` must be held in a pointer (`int *pb = &b` taken first: the original keeps it in s0 and b gets slot 0x14), `f32 v = w;` read before the `if (!ok)` branch puts w in $f20, call func_0027F1E0 before `v = 0.0f`.
- func_0026A488 (t_268EB8): not matched, no near miss kept: inline hash Get (key copy through a `const u32&` temp: pass an `int` so it is bound to a temporary) then func_002E8610(..., z * 0.01f); the original keeps the table in a3 and the record in t1 and lays out the null-items path as `bnezl` fallthrough; ours has table t0 / record a3 and `beqz`. 12 tries.
- func_002DE280 (t_2DCE78): not matched, no near miss kept: ctor with three operator_new(0x24)+func_00113EA8 nodes and a dead Color c (sb 0xFF x4 re-set before each new); original keeps 0xFFFFFFFF in a2 (stored to +4 and passed to func_0029FD08, 3 args) and p+0x8000 in s5 (6 saved regs); ours rematerialises the constant and ends 4 bytes short or long; the +0x10ED0 store is computed as `lui/ori/addu` in the original, `lui s3` shared in ours. 14 tries.
- func_002AE6C8 (t_2AD528) MATCH (-funroll-loops file): counted array {data+0, size 4, 8, C, cap 0x10} of 0xC-byte elements (cookie count at data-0x10): `if (!data) { cap = n; cnt = n+1; m = Heap_Alloc(h, cnt*0xC+0x10, 1, 0); *m = cnt; for (i = n; i != -1; i--) ctor(q+4), q += 0xC; data = m+0x10; C = 0; 8 = 0; 4 = cap+1 } else { destroy backwards (do { e -= 0xC; dtor(e+4); } while (data != e); free(data-0x10); reset fields; recurse }`. Store order in the epilogue: unkC before unk8 before unk4 in source gives the original's `sw 0xC` before `sw 4`.
- func_0027E820 (t_27D828): near miss (only the s1/s2 numbering of the two arguments: original p in s1, idx in s2; ours idx in s1, p in s2; `register ... asm` pins break the unrolling), nonmatching/func_0027E820.cpp: erase element idx of the small-vector {u32 unk0, int size +4, int data/inline +8} (S27E9D8_A of the file): size 1 -> size = 0; size 2 -> remaining element `idx == 0 ? src[1] : src[0]` stored inline at +8; else heap-5 alloc func_0011A380((size-1)*4), copy [0,idx) then (idx, size) with unrolled loops, func_0011A470(src), data = new, size--.
- CFunc_SetSpawnedScriptNoRepeatFor (t_25A428): near miss, ONE instruction (`addu s0,v1,s0` vs original `addu s0,s0,v1` at the final `table += idx*8` before `sw time,4(s0)`), nonmatching/CFunc_SetSpawnedScriptNoRepeatFor.cpp: ring buffer of 30 {int id; int time} at D_0039A2D8 (head D_00370550, count D_0037054C, both $gp); search backwards from head (`off = idx*8` kept in s1; id read as `*(int*)((char*)D + off)`, time pointer `(char*)D + 4 + off` inside the found branch), found: `now - last < (u32)f(t * 1000.0f)` -> func_0028A300(script) else refresh time; not found: head++ wrap 0x1E, count++ cap 0x1E, store id and time. Needed `register int key asm("$2") = script->unkD4; register int e0 asm("$4") = tab[off];` (pins) and `if (e0 == key)` to get the right registers.
- func_002DDDC8 (t_2DCE78) MATCH: factory registration table `func_001D4600(D_0036D3B0, key, create, destroy)` x24 (handle loaded once into s0 via `lui/lw`, keys as hex constants, some creators are mid-function addresses written `(char *)func_001F5EA0 + 0x10`, a null destroyer is the literal 0, last three keys are loaded from the sdata words D_00372E10/DF8/DC8); generated from the asm with a script, first try. The callee needs an alias with (int, u32, void *, void *) because pointer arguments of mixed types.
- func_002DEA78 (t_2DCE78) MATCH: event registration `func_001C9B78(self, b, f)` then 9 x `func_002981A0(e = b + 4, id, fn, mode, self, level)` and 18 more under `if (f)`; written straight from the asm (e as `s32 e = (s32)b + 4`, asm-label aliases for the callees, handlers declared `void f(void)`), first try. Straight-line registration functions are the cheap wins of this range.
- func_002E8D68 (t_2E7010): not matched, no near miss kept (sound driver init: globals, two 0x1C-byte buffer descriptors {unk0, size +8, size2 +C, ptr +10/+14, buf +18} at D_003EB1D8, memset of each, two func_002E3830 handles, `if (D_003728F4)` two func_002E02D8/4CB8/3ED0 setups with 0x3FFF masks): registers and the call/branch skeleton match with pins `register char *a0 asm("$18") = b0; register char *a1 asm("$19") = b1;`, but the original keeps memory operations in source order through two bases (`s0` and `v1 = s0+8` with `sw zero,-8(v1)`, `lw a2,8(s0)` reloaded after the stores), ours folds -8(v1) into 0(s0), forwards the size and schedules the stores freely. 10 tries.
- func_002E9A38 (t_2E90B0): near miss (registers of 3 temps in the wrap-around path: original base->v0, unk0->a0, slt->v1; ours a0/v1/v0), nonmatching/func_002E9A38.cpp: ring buffer {cap +0, count +4, rd +8, wr +C, base +10} read of n bytes through func_0030A2F4(dst_ring, src, n): early `return 0` when count == 0 || n == 0 || count < n; linear case (rd < wr: k = min(n, wr-rd)), wrap case with three outcomes (tail fits / total < n / split copy). Needed pins `register int n asm("$18")` is NOT used (it removes the `move a2,s2`); working pins are `register u32 rd asm("$5")`, `register u32 wr asm("$3")`, `register int lin asm("$17")` (first path only), and `return` inside each branch (no shared `ret` variable).
- func_002AE2A8 (t_2AD528): not matched, no near miss kept: LightShow state init (`if (a1 == 0xFFFF && a0)`): u128 {1.0f x4} built with pextlw/pcpyld from `lui 0x3F80` stored to D_003AB710 and D_003AB700, zero stores through `D+0x10` bases (D_003AAE10 +0x420/424/428, D_003AB260/D_003AB4B0 +0x220/224/228, D_003AB720 +0x1020/1024/1028), list head D_003AC770 {1,1,0,0,0,0,self,..,self+0x20}, func_002AE0C8(D_003AC7A0, 5, 0, &head, p8..p11), func_002AE0C8-style init func_0027AA70(D_003AC7C0+4). Straight transcription compiles to 0x13c bytes with 4 saved registers (the original is 0x118, only `ra` saved, all pointers in t0-t6 recomputed): the original does not keep the four `+0x10` pointers across the call.
- func_0028DE68 (t_28CC70): not matched, no near miss kept: transcription of the QB array walk (heap-5 push around a loop over `a->unk4` elements with the `unk4 == 1 ? inline : array[i]` element read, checksum flags f1/f2 from `e->unk8` (0x6D62F5BB / 0x84FD71D0), chain e->unkC x3, func_001D8CD0(o->unkF0, o, ..., g, f1, f2, last), g spilled to 0(sp)) is right, but the original loop is NOT unrolled while this file is compiled with -funroll-loops (ours 0x294 bytes vs 0x19c); tried do/while with `++i < n` and `i++`. Probably this function came from an object without the flag (or the loop shape defeats the unroller in a way not found): toolchain/file-boundary question.
- func_0026F3B8 (t_26F3B8): near miss (same size 0x1b0; only prologue order and the temporaries of the 2-byte copy: original `addiu a3,v0,lo; lb v1,0(a3); lb a0,1(a3)`, ours `addiu v1,v0,lo; lb a1,0(v0); lb a2,1(v1)`), nonmatching/func_0026F3B8.cpp: read up to 26 QB ints named by the 2-char key counter (`signed char k[2]` copied from D_00370CC0, func_001150B8(k) gives the name, k[0]++ per item) with a SINGLE do/while (`*p = tmp` stored before the break test; `key = f(k); tmp = 0; ok = func_0027D870(a0, key, &tmp, 0)`) that -funroll-loops turns into the original's x2 body (writing the x2 body by hand makes it x4); then `func_0026F158(h, arr, n, 0,0,0,a1) || (t2 = 0, get, func_0026EED8(...))` -> read optional list, return 1/0. `register int a0 asm("$20") = b0` fixes the s4/s5 numbering.
- func_0029D370 (t_29D230): near miss (0x1a8 vs 0x1bc: the original keeps `a6` and the heap flag in separate saved registers (s5/s6, plus s7 for a5) and computes `c = (flags & 0x80) ? a6 != 0 : 0` with a branch and `sltu` in the delay slot; ours if-converts it to sltu/andi/movz and shares one register), nonmatching/func_0029D370.cpp: send of a 16-byte packet {s16 2, s16 func_002FF0D8(key & 0xFFFF, 2), int x} built after `obj->vcall(buf, 0x10)` (vtable slot 0x40 = 8th virtual when the first is at 0x8) and memset; if flags & 0x20 the data goes through func_0029A7B8 into obj+0x186C, else optionally copied to a heap block with a u16 length prefix (Heap_Alloc/func_0030A2F4/Heap_Free); result `r < 0 && vcall slot 0x18 (r) == 0 -> 1`. Sibling of func_0029D530.
- CFunc_PushGlobalTags (t_2BCDA8): near miss (same size; the first lookup's loop layout and the registers of the table pointer / the second key copy: original table in t0 and `lw a3,4(sp)` after the `bnez`, ours a3/a2), nonmatching/CFunc_PushGlobalTags.cpp: two QB names (second `0xD28C8510`) read into a, b; first lookup (nested `if (tab == 0) r = 0; else { ... }` form: `SHT_Find0`, key copy at 8(sp)) gives the old handle, second lookup (the early-return SHT_Find, key copy at 0xC(sp)) is get-or-create as CFunc_SetGlobalTags, then func_0027C7D0(v, a, old).
- func_00299260 (t_298A30): not matched, no near miss kept (network packet handler: 3-byte header {u8 type, u16 len} copied bytewise into stack slots (0x230/0x232/0x233 with `lbu/lb/lb` and `sb`), Heap_Alloc(len), type 1 -> func_002972F8(pkt+3, (int)(unk8-3), buf, &sz) (64-bit field truncated with dsll32/dsra32), type 2 -> func_00115EE8(...) - buf, then a second 3-byte header from the decoded buffer, data copy, func_00298858(a->unk10 + 4, &msg, unk10, unk18) and two guarded Heap_Free): logic written, but the frame is 0x20 bytes larger than the original's (0x290 vs 0x270: the 0x230-byte message struct is not what the original has), the header bytes come out as `lbu` instead of `lb`, and sz sits at 0x250 instead of 0x238. Same family as func_00299418.
- func_00269B70 (t_268EB8): near miss (0x1cc vs 0x1c8; the original peels the first check of the inner 4-entry loop on `&D_003A3420[0]` (s2) and addresses the other three through a separate `D_003A3420 + 4` induction register (s1) created inside the outer loop, ours hoists that pointer out), nonmatching/func_00269B70.cpp: 4 sound-config entries {id, f32 scale} at D_003A3460: `func_0027D400(params, id, &sp0, 0)` then two optional floats (0x688845C3 scaled by 0.01f, 0xF6A36814 through func_0026A6C0 then 0.01f) and, for each of the 4 voices D_003A3420[j], `if (voice.unk4 && *voice.unk4 == id) func_00269F08(&voice)`.
- CFunc_SetNoteMappings (t_2BCDA8): near miss (same size; two instructions of the `func_0027AA98(func_001287F0(8,1), v)` argument setup swapped (original `move a0,v0` then `move a1,s0` in the jal delay slot, ours reversed) and the temporaries v0/v1 of the bucket index), nonmatching/CFunc_SetNoteMappings.cpp: lazy `D_003720E0 = func_002D5CE8(Heap_Alloc(h, 0x1C, 1, 0), 4, 0)`, array of entries read with `if (arr->unk4 == 1) v = arr->unk8 else v = arr->unk8[i]`, each {a = name, c = field 0x26A3E1B2}: key = c + a, 12-byte record {a, c, func_0027AA98(func_001287F0(8, 1), v)} inserted in the hash like CFunc_SetGlobalTags (index and chained node key through the copy `h`: `register int h asm("$20") = key; asm("" : "+r"(h));`; empty slot: store key then val; `register int cc asm("$3") = c;` gives the v1 for the record's second field), count++.
- func_0027FAC8 (t_27F8C8) MATCH: QB value dumper: `n = a ? func_0027B300(a, 0) : 0; while (n) { if (cb) cb(); switch ((n->unk0 >> 9) & 0x7F) { ... r = formatter(n->unk4, n->unk8, p, rem) } if (!r) return 0; rem -= r; p += r; n = func_0027B300(a, n); } if (rem == 0) return 0; rem--; *p = 0; return len - rem;`. Case table read from the jump table in asm/data/cod/rodata.rodata.s (type 1 f410, 2 f610(float), 3 f788, 5 f8C8, 6 f938, 7 f6C8 with the constant 0xB9C4F664, 10 f9B0(+flag), 12 fA40(+flag), 13 f6C8, 26 f728). `rem -= r` before `p += r` and the final test written `if (rem == 0) return 0;` give the original order; the callback is a function pointer parameter (a separate int copy costs a saved register). The earlier prototype in the file was changed to `(int, char *, int, int, void (*)(void))`.

Round 2026-10-19 (C7): 15 matches / 31 attempted (limit 15/40)

- func_0029D370 (t_29D230) MATCH (was a near miss; nonmatching copy removed): `int c = 0; Pick(c, flags, a6)` with `static inline void Pick(int &c, int flags, u32 a6) { if (flags & 0x80) c = a6 != 0; }` keeps the branch; func_002FF0D8 takes ONE argument (a1 left alone); tail `if (r < 0) { int t = vcall(r); if (t != 0) return 0; } return 1;` gives bgezl.

- CFunc_DestroyGem (t_2BEEE0) MATCH: the inner lookup moved into a `static inline void Pick(int &v, int arg0) { int b; if (call(arg0, key, &b, 0)) v = b; }` keeps the bnezl + conditional load (the helper must contain the call, a helper taking the condition and value did not).

- func_002A3818 (t_2A32E0) MATCH: `int r = A; if (flex(arg0,0) || spline(arg0,0)) { if (get(K1,&a,1)) Set(r, a, X) else if (get(K2,&b,1)) Set(r, b, Y) }` with `static inline void Set(int &r, int v, int k) { if (v == k) r = K2; }` (the reference helper turns the movz into the original branch; the check calls get arg0 in a0 untouched).

- CFunc_GetValueFromVolume (t_254248) MATCH: u32 key switch (cases 0x8D6F6554 first, then 0xA5162BD2 sharing the tail through a goto label, then 0xE32F3525 with its own copy), `h = arg->unk20; f = callee(); func(h, key, (int)f / 10)`: the float returns are `f32`, `(int)f / 10` with cvt.w.s + div works now.

- func_0029F5C8 (t_29F288): near miss (0x5c vs 0x60), nonmatching/func_0029F5C8.cpp: slti 500 + movn needs `if (v * 2 < 500) return 500; return v * 2;` (`r = ...; if (r < 500) r = 500` and the ternary give slt 499 + movz); the original lays out the 1000 early return as `beqz else; sw; b end; li 1000` where ours is `bnez end; li 1000`; `int r` joined forms break the movn.

- func_002E7B60 (t_2E7010): near miss, nonmatching/func_002E7B60.cpp: frame (info struct padded to 0x50) and the whole shape match with `u32 lo = arg0 & 0xFF` first and `int r = 1; Clear(r, info.unk11)` (ref helper `if (x == 1) r = 0`); only the movz direction and v0/v1 differ (ours `move v0,zero; movn v0,s1,v1`, original `move v0,s1; movz v0,zero,v1`), 5 forms.

- func_00273498 (t_273498) MATCH (movz chain was a give-up): `ok = 1; do { int r = f(i++, -1.0f); ok = r && ok; } while (i < D)` inside `if (D > 0)`; the `&&` form gives the movz/movn pair.

- CFunc_ReloadAnim (t_25E580) MATCH (was a movz give-up): `static inline void Pick(int &h, int crc, const int &name) { h = crc; if (name) h = name; }` called as `Pick(h, CrcFromPathLowercase(path), name)` after `obj = D_0036F658`: the helper must assign h itself (gives the extra move + `movn h,name,name`); name is a stack variable whose address was passed to the lookup.

- func_0029B468 / func_0029B3A8 (t_29AA58), retried with First/Next static inlines (movz Valid1, movn Valid2, return-style null tests): the loop and Next part match; the first element's null test is `bnez/b/move v0,zero` in the original and `beqz + lw` here, x lives in a0 (ours a2) and the file's unroll flag adds a `nop` before the loop label; no near miss kept.

- CFunc_CompressVC (t_24DDB8): near miss, nonmatching/CFunc_CompressVC.cpp: with `static inline LNode *Valid2(n) { if (n->unk4i != -1) return n; return 0; }` (gives the original movn), `next = Valid2(cur->unkC)` before `vc = cur->unk4`, and the call `f(vc, c, a, b)` (a/b/c stack variables) everything matches but the register of vc (a2, original a1) and the order of `lw a1,8(sp)` vs `lwc1 f13` before the call; the same Valid2 + next-before-vc walk is the pattern for CFunc_CenterCamera/SkatersAreReady.

- CFunc_CenterCamera (t_260658) MATCH: `if (cur) do { next = Valid2(cur->unkC); vc = cur->unk4; if (vc->B7()) f(vc, a, b, c, d, e); cur = next; } while (cur)` with Valid2 `if (n->unk4 != -1) return n; return 0` (gives movn), the call prototype with the int LAST (`(vc, f32, f32, f32, f32, int)`: the order of the argument loads follows the declaration, the original loads the int in the jal slot), and the bit test as `int t = unkC >> 7; return t & 1` (`(x >> 7) & 1` is narrowed to lbu+dsrl).

- CFunc_CompressVC (t_24DDB8) MATCH (near miss resolved, nonmatching copy removed): the same prototype trick, `func_0024F500(vc, f32 a, f32 b, int c)` with the int last, fixed the argument load order and the vc register.

- CFunc_SkatersAreReady (t_260658) MATCH (movz list walk give-up): vcall through the vtable at +0xEE00 (entry +0x148: s16 delta, fn at +4), count walk `while ((q = Valid1(p))) { n++; p = q->unkC; }` (a separate q gives the extra `move v0,v1`), `if (call) { ...; if (n != 0 || IsObserving(0,0)) return 1; } return 0;`; CFunc_IsObserving takes 2 args via an asm-label prototype.

- func_00275A90 (t_2754A0): not matched, no near miss kept (hash bucket find + flag update; original 0x138, ours 0x118..0x128): registers come out right with `obj = func_002759F8(obj)` (reusing s1), but the original sets found=0 in the delay slots of the null exits and peels the first bucket compare with `beq; move v0,key; lw next; nop`; for/while/peeled forms and found assigned in both branches all lay it out differently. Also skipped as too large (0x1000+, unrolled byte-copy loops/jtbl or 40+ callees): func_002811F0, CFunc_UpdateScoreFastPerFrame, CFunc_UpdateScoreFastInit, func_002D8880, CFunc_GuitarInputLogicPerFrame, func_0028EBA0, func_002D6160, CFunc_LightShow_Init.

- CFunc_SetAllWhammyValues (t_2C3468): near miss, nonmatching/CFunc_SetAllWhammyValues.cpp: the file needs `// cflags: -funroll-loops` (not yet verified against the file's other functions with dk done); with a plain `for (i = 0; i < n; i++) f(o, i, v)` the unrolled loop with the 3-way remainder switch matches exactly, and a reference helper `Key(int &key, int mode)` gives the original's real if/else for the key (ternary or return-style helpers if-convert to movn); only the delay slot of the `bne` differs (original `move a1,zero` there, ours nop and the move after the join), 7 forms.

- CFunc_GetCamOffset (t_252068) MATCH: callee with 10 arguments (the CFunc's own params in a0 passed through, 8 in registers, 2 pointers on the stack), stack struct {int a,b,c,d; u128 v1; f32 f1; pad; u128 v2; f32 f2, f3} (locals start at sp+0x10), the vectors passed as three floats with the X/Y/Z asm helpers (mtc1 / dsrl32+mtc1 / pcpyud+mtc1 as in t_2626E0), `(f32)(int)(f1 + 0.499999f)`.

- func_002EBE18 (t_2EB1C0): near miss, nonmatching/func_002EBE18.cpp (needs `// cflags: -funroll-loops` for the file, not verified against its other functions): hash table ctor (bits, optional preallocated array) with two copies of the unrolled `for (i = n - 1; i != -1; i--) ctor(q++)` loop (guarded by `if (n != 0)`), the structure and the unrolling match; only the saved-register numbering differs (original: t in s4, mem in s5, a copy of mem in s2, the allocation result in s3, -1 in s5/s6, 7 saved registers; ours 6) and 4 bytes of size.

- func_002917B0 (t_2908A0): near miss (0x150 vs 0x148), nonmatching/func_002917B0.cpp: two inline hash lookups (the SHT_Find shape of t_2EB1C0: `n = &tab[k & ((1 << bits) - 1)]`, `unk15 != 0 || v != 0`) around func_00291080(obj, e, t) / func_00291230(obj, key, 0); passing `(int)key` to the `const int &` parameter keeps the key in s0 (a plain `key` spills the parameter); the first lookup matches, the second differs in registers (t in a2/a3, key copy) and the final `if (e2)` is folded into a branch-likely with the epilogue; func_00291080 is declared with 3 args through an asm-label alias.

- func_0029B258 (t_29AA58): near miss, nonmatching/func_0029B258.cpp: update loop over the stack list iterator with the real First/Next functions (func_0029D5C8(list, &it) / func_0029D600(list, &it) through asm-label aliases) and the result test as `if (r != 0) { if (r == 2) {...return 1} if (r == 3) {...return 0} }` (a switch compares 3 before the null case); with `register char *list asm("$18")` and `next asm("$19")` the s-register numbering matches (without the pins list/next come out swapped); what remains is the delay-slot placement of `addiu a0,list,4` and the load order of the two fields (original v0 = unk3130 first, then s0 = unk3134).

- func_0026FE70 (t_26F3B8, -funroll-loops) MATCH: first free slot search over three bitmasks from func_00270DB8(1/0/1) (one argument; a1 is left alone): `k = key; ... key = f(1); for (i = 12; i < 22; i++) if ((key >> i) & 1) if (i + 22 != k) return i + 22;` etc.; the mask must be assigned back into the PARAMETER (original keeps the mask in a1, the compare copy in s0), a separate mask variable lands in a0.

- func_0025DFE8 (t_25C450, now `// cflags: -funroll-loops`) MATCH: pad a name with spaces: `strcpy(buf, name); strcat(buf, D_003705E0); for (u32 n = strlen(buf); n < len + 2; n++) strcat(buf, D_003705E8); strcat(buf, D_00356E50); f(out, buf, a1, k, func_00113640(k, 0))` (func_0030A554 is strcat; keeping the bound as `len + 2` in the condition gives the original's late add and the unrolled loop with the 0..3 remainder switch). The flag was added to the whole file: dk done verifies the other functions.

- func_002E9818 (t_2E90B0): near miss, ONE register (`li v0,1` for `unk18 = 1` in the refill branch, original `li v1,1`), nonmatching/func_002E9818.cpp: the double-buffer ring pump on D_003EB210 (buffers D_003EB238[2] of 0x1C bytes): the failure exit must come FIRST (`if (unk14 != 0 || unk8 == 0 || unk0 == 0) { f(0); return 0; }`), D_003EB210 as one struct and the buffers as a separate array, func_0011DAA0 takes one argument; local constant, reference helper and pointer forms of the store all give v0.

- func_00270BD0 (t_26F3B8): near miss, nonmatching/func_00270BD0.cpp: sound register init (4 writes, F7E8, 9C8, then `for (i = 0; i < 2; i++) for (j = 0; j < 24; j++) { w(0x8010, (i | j*2 | 0x300) & 0xFFFF, 0xFF); w(.., (i | j*2 | 0x400) & 0xFFFF, 0x1FC0); if (j < 22) D_003A8D40[i][j].unkC &= 0xFFFE; }`): the loops and the unrolling by 3 match instruction for instruction; only the s6/s7 numbering of i and the 3-step index, and `move s,zero` for i (we hoist it into the delay slot of the first write call, the original into the slot of F7E8), differ; for/do-while and declaration forms give the same.

- CFunc_KillPulsateStarPowerBulbs (t_2C9AC0): near miss (0x22c vs 0x230), nonmatching/CFunc_KillPulsateStarPowerBulbs.cpp: stack struct {handle a, b, c (0x10 each), int idx, f32 f}, func_0027D1F8 gets the CFunc's params in a0, handles built by func_00145310(&h, heap, tbl[idx][i], 0) and destroyed by `if (h.p) { func_001CE888(h.p, &h); h.p = 0; }`, tables as `int [][6]`; structure and calls match, only the loop-invariant hoisting differs (original keeps 0x898B0C73 in s4 and hoists D_003AC9A8 but not D_003AC978; ours hoists both table bases and rebuilds the constant).

- func_0027BDB0 (t_27B7D0): not matched, no near miss kept (0x1ac vs 0x180): QB component list insert-with-dedupe (walk with prev, key equality, type pairs 0x200/0x400 compat, 0x1A00/0x3400 value compare, unlink + func_002791E0(cur, 1) + func_0025C5E8(cur)); the original keeps only 512 in a saved register and uses `movn a3,1,k` for the mode == 1 case and 6 saved registers, ours hoists 0x1A00/0x3400/1 into saved registers (9); the type comparison is probably a switch or an inline helper.

- func_002B8308 (t_2B8088): near miss, nonmatching/func_002B8308.cpp: QB struct fill (func_0027AA70(func_001287F0(8, 1)), five setters with keys, table lookups `D_xxx[arg0]`, `Arr.Get(i > -1 ? i : 0)` with the inline size == 1 test, clamp `v > 0x6DDCFF ? 0 : v`); correct except the order of adjacent independent instructions (original `addiu v0,v0,lo` of each table base BEFORE `move a0,h`, ours after) and v1 for the last table base; `D_00371FB0`/`D_00371FC8` need `__attribute__((section(".sdata")))` to be reached through $gp (GP_DATA alone leaves lui for arrays); byte-offset forms fold the lo part (wrong).

- CFunc_CalculateGemTime (t_2BA998, file flags now `-funroll-loops -ffast-math`) MATCH: curve interpolation: `t = 0; v = t; sum = t; f(params, 0, &v, 1); ...; t = v; t = t * 1024.0f;` (the zero lives in one callee-saved FPR that later becomes t), `i0 = (int)t % size`, `i1 = (int)(t + 1.0f) % size`, `frac = t - func_0031B4B8(t)`, a plain `for (; i < i0; i++) sum += f(arr, i)` (4x unrolled with the 0..3 remainder switch; -ffast-math turns the first `0 + x` into `mov.s`), result `sum + frac * (f(arr, i1) - f(arr, i0))`.

- func_002B62C8 (t_2B5BC8): near miss, nonmatching/func_002B62C8.cpp: song-section cache (`D_xxx[idx]` tables, Arr.Get(i) with the size == 1 test, `func_0027D870(params, key, &a0, 1); int a = a0;` then `int ok = func_0027CC30(params, key2, 1, &b0); b = b0; if (ok == 0) { func_0027F1E0(params, 0, 1); b = 0; }`, then the update block, stores of -1 in the order 0x30, 0x28); only the prologue order of the argument copies (original copies a0, a2, a3 first and a1 last) and the position of `lw s1,0(sp)` against `move a0,s0` differ.

- func_002B64D8 (t_2B5BC8): near miss (0x234 vs 0x230), nonmatching/func_002B64D8.cpp: song-time lookup (flag from D_00373008 == 0x2AED7570 / D_00373104 == 1 / D_00371FA8 == 1, `ok = f(...,&v); w = v; if (!ok) {...; w = 0}`, k = w - 1, func_002B62C8, `while (t >= *pl) if (!func_002B6098(k)) break`, range test, counter bump, Arr.Get(ai).Get(7)); the pointer `tab = D_00372018` kept in a variable gives the original's s7 base register; remaining: `sll` into a temp + `move s2,v0` (original `sll s2,s1,2`) and the constant 1 stored and returned from two registers (original one `li v0,1` used for both: `sw v0,0(s5)` in the `b` delay slot).

- CFunc_CreateGemMover (t_2BEEE0) MATCH (near miss resolved, nonmatching copy removed): declare the callee with the arguments in the order the original LOADS them, not in register order: `func_002BF900(int a, int flag, f32 f0..f6, int g, f32 f7, int c, int d, int b, f32 v)` (floats and ints interleave freely, each still goes to its own register class); the loads then come out f12..f18, a2, f19, a3, t1 as in the original. General trick for every call whose argument-load order differs (also fixed CFunc_CenterCamera/CompressVC).

- func_0029A8E8 (t_298A30) retried: still a near miss (nonmatching/func_0029A8E8.cpp kept): the only difference is `move a2,len` for the memcpy length scheduled before the 2-byte struct copy (lb/lb/sb/sb) in ours and after it in the original; `int m = len` / direct `len` / initialised declarations do not change it.

- CFunc_Push (t_25A428) MATCH (near miss resolved, nonmatching copy removed): the swapped `lw a1,0(sp)` / `lw a2,8(sp)` before `func_0027C740(l.a, l.key, l.arr)` came out right by reading the stack variables into temporaries in the order the original loads them (`int ta = l.a; int tarr = l.arr; int tkey = l.key; f(ta, tkey, tarr)`). Same idea as the prototype-order trick: the load order follows the order of the reads in the source. Candidates for the same fix (one swapped pair of independent instructions, same size): CFunc_ControllerDebounce, CFunc_LightShow_OverrideColor, CFunc_LinearMap, func_002884A8, CFunc_SetSpawnedScriptNoRepeatFor (operand order of addu), func_00270A90, func_00277220, func_0028C8F8.

Round 2026-10-19 (C8): 4 matches / 17 attempted (limit 15/40)

- C8 near misses updated (no match): func_0026FAE0 (b computed inside each branch, `b <<= 1; b |= a;`: only s0..s3 numbering left; original b=s0, lo=s1, hi=s2, vy=s3), func_00272058 (nonmatching refreshed: volatile unk1C and `y = unk1C; if (y < x) x = y;` give the original movn tail; left: v0/v1 of the unk3C/unk20 sum and a `move s0,v0` for n = h), func_002A1AE0 (hoisting `i` makes it worse), func_002532C8 (v0/v1 of the loop-end length load, unchanged).
- CFunc_GemArrayStepperCompressedBroadcastEvent (t_2C57B8) MATCH: four inline string appends into `char buf[0x100]` (first from the global D_00362BB0 read as `char *q = D_00362BB0` before the calls and tested as `D_00362BB0[0] != 0`, then `q = s; while (*q) { *d = *q; q++; d++; }`), a dead `u8 c[4]` set to 0xFF (stores kept plain, no volatile; the source order 0,1,2,3 gives the emitted order 3,0,1,2 with the last in the jal slot; volatile or an asm "m" operand break the slot filling).

- func_0026B208 (t_26AEF8): near miss (0x1c4 vs 0x1bc, only s3/s4/s7/s8 numbering of cnt/t/skip/ivs), nonmatching/func_0026B208.cpp: voice picker over 0x80-byte entries (prio +0x14, flags +0x18, time +0x30; three pointer ivs come out by themselves): `cnt += f(i) < i` must come BEFORE reading the entry's prio (else prio lives across the call and costs a saved register), time compare as `(u64)(s64)field < (u64)t` with `s64 t = (int)func()` keeps the dsll32/dsra32 once, `if (skip >= 0) { r = f(skip); if (r >= 0) return r; }` gives the shared epilogue, `r = sel; if (r >= 0) *out = 1;`. Declaration order of the locals changes nothing (all permutations tried).
- func_00292BF0 (t_292928): near miss, nonmatching/func_00292BF0.cpp: hash get-or-create (Find through `S292_Find(t, volatile int *kp, int *outp)` with `if (n != 0) { do {...} while (n); }`): reading the key through a volatile pointer gives the original `move t1,sp` + reload in the loop; left: `move t2,a0` and v0/v1 of the `unk15 = 1` store.
- func_002E8A98 (t_2E7010): near miss (0x168 vs 0x16c), nonmatching/func_002E8A98.cpp: two-entry voice table loop written with `p++`/`i++` and `D[i].x`; only numbering and where the base addresses are hoisted differ.
- CFunc_StartPreLoadedStream (t_254248): near miss (same size 0x23c; register numbering and the stack slot of `&s28`: original spills the pointer to 0x2C(sp) with s28 at 0x28, ours keeps it in a register unless forced), nonmatching/CFunc_StartPreLoadedStream.cpp (uses two `asm("" : "+r")` barriers: not committable as is): `char buf[0x10]`, `int i = 1; do { u32 key = ck; if (i >= 2) { sprintf(buf, D, i); key = f(key, buf); } ... i++; } while (!done)` (the `i >= 2` is not folded in this form), hoisting 0x499F6E0D into a saved register needs an opaque variable.
- func_00272520 (t_271480): near miss (0x2b4 vs 0x2c4: the two concat calls are cross-jumped in ours, the original keeps `move a2,len` in each delay slot; registers h0/path swapped v1/a0), nonmatching/func_00272520.cpp: stream open (voice object init, strcpy + strcat of D_00370DD8/DE0 into a stack buffer, `(char *)((int)buf | 1)` gives the `ori a0,sp,1`; store the handle inside each arm (`o->unk14 = f(...)`) and test `o->unk14 == 0` after the join to get the original reload; `func_0011DBE8(int, u64, int)` with `(u32)(x << 11)` gives dsll32/dsrl32).
- CFunc_WhammyFXOn (t_2C7900) MATCH: the sibling CFunc_WhammyFXOff template (S2C79_Arr::Get) plus the `func_0027CC30(h, key, 10, &g)` call: `int ok = call(&g); int v = g; if (ok == 0) { fallback(); v = 0; }` (reading g after the call, before the test, puts the lw in the beqz/bnez delay slot; the if/else form gives bnezl).
- CFunc_CheckButtonsBoss (t_2D2350): near miss (same size 0x23c; only the registers of the 5-step max loop: original size a2 (copy a3), i a0, data v1, value v1 with `slt v0,s1,v1; movn s1,v1,v0`; ours a3/t0/a2/a1/a0), nonmatching/CFunc_CheckButtonsBoss.cpp: S2D23_Arr::Get template, `int ok = call(arg0, key, 1, &idx); int k = idx; if (!ok) { fallback; k = 0; }`, after the loop `x->Get(6)`, `-1.0f` store before the flag logic; ternary/if/explicit-size forms of the max all give the same registers.
- CFunc_LoadScene (t_25E580) MATCH: two scene loads (`func_0022ABE8(&h, obj, path, 4|3, 0, hash, 0, &qb)`) each followed by an inline handle release `if (h.unk0) { vcall }`; the vcall entry is declared `int (*fn)(void *)` even though the result is unused: with `void (*fn)` the vptr lands in v0 and the entry in v1 (original: vptr v1, entry v0), with the int return it matches. Also: read the string pointer into a local (`char *nm = name`) and take the format string address (`char *fmt = D_...`) before the `if`, the first QB string is passed twice to sprintf, `func_0030B550(buf, fmt, nm, nm, v8)`; `if (strcmp-like(...) != 0) t18 = 1;` gives the movn.
- CFunc_StarPowerFastTest (t_2C9AC0): near miss, ONE instruction (the original has `move s0,s1`, a copy of the switch index made after the first equality test; the rest is identical), nonmatching/CFunc_StarPowerFastTest.cpp: 4-case u32 switch whose blocks are in the order A7EE98D5, 4149710D, B8B425FF, 7D5E1202 (source order = block order), `u32 t0 = type;` read BEFORE `func_00289C80(script)` (original loads it in that call's delay slot) and `switch (t0)`; the shared "return 0" is a label inside the last case (`r = 1; if (x17 == 0) { none: r = 0; } return r;`) reached with `goto none` from the other cases; each case's flag has its own variable (a shared `x` costs a saved register); `int ok = f(h, key, n, &v); T v2 = v; if (!ok) { fallback; v2 = 0; }`.
- CFunc_CheckNoteHoldEnd (t_2C7900): near miss (0x2cc vs 0x2c4: v0/v1 of the D_00372F78[idx] address, `&D_00372120` in a3 instead of a2, one alignment nop), nonmatching/CFunc_CheckNoteHoldEnd.cpp: with the file's `-funroll-loops` the plain `for (i = 0; i < 5; i++)` gives the original peeled/unrolled shape; the weak-handle inline is the t_148688 H148 template (`func_00145310(&h, D_00369798, key, 0); int t = h.unk0; if (h.unk0) { func_001CE888(h.unk0, &h); h.unk0 = 0; } if (t) {...}`); `func_002B4C08(a, key, int *, float)` takes a FLOAT last argument (`mtc1 zero,$f12`); D_00371F90/D_00372120 are `[2]`-sized sdata arrays (declare them with size 2 and the address is `addiu a0,gp,..`); the 5-int rows are addressed `*(int *)((char *)D_003BEE40 + idx * 20 + i * 4)` (the 2-D array form gives other registers).
- func_002E6D40 (t_2E62C0): near miss (0x1d0 vs 0x1cc), nonmatching/func_002E6D40.cpp (needs `// cflags: -funroll-loops` on the file, not verified against its other functions): sound voice release: `for (i < 8) if (D_003EB0B8[i] == k) { func_002E1370(i); D_003EB0B8[i] = -1; }` fully unrolled by the flag matches exactly; the second loop (entries {a, b} of 8 bytes at D_003EB198: `if (E[i].b == k) { j = 0; while (j < 2) { if (D_003EB000[j].unk0 == E[i].a) { D_003EB000[j].unk0 = 0; break; } j++; } E[i].b = -1; f(E[i].a, j); }`) has the right shape; ours hoists the full address of D_003EB000 into a saved register where the original keeps only its `lui` part (s4) and the saved k*4 in s5, 5 extra bytes of frame.
- func_00271708 (t_271480) MATCH (near miss resolved, nonmatching copy removed): four changes to the old attempt: (1) `int n; int idx = 0; int hi = 0; n = func_003174C0(...)` (declare n first, assign after: numbering s1..s4 right, idx/hi live across the call), (2) the cap to 15 only gives the original `movz` through a copy: `int m = n; if (m >= 0x10) m = 0xF; n = m;` (in place or ternary = branch `beqzl`), the `<= -1` clamp as `static inline void Zero(int &n) { if (n <= -1) n = 0; }`, (3) the final read-modify-write written `p->unk0 = (p->unk0 & ..) | n; p->unk4 = (p->unk4 & ..) | ..;` (unk0 first) so the early delay-slot load is unk0, (4) float args are passed in a1/a2 (float a, float b) and re-passed as the call's third argument.
- func_002DCD68 (t_2DAE48) MATCH (unblocked by the integrator's `OBJECT_END();` before the function; no `_lui` alias): `int t = D_003722B0;` read right after the first if/else (the original hoists the load into both arms, `lw a0,gp` in the join branch's slot) and used in the `v != 0` arm, a second `int t2 = D_003722B0;` read BEFORE the `D_00370EE0[0] + 0x10 = 0` store in the final arm; the callee func_002DC6F8 is already an empty stub in the file, so the 2-arg view is an asm-label alias. (func_00276FD8 was already C++ in t_2754A0.)
- func_0026FC80 retried (t_26F3B8): still a near miss: with the early return `if (e->unk10)` gcc keeps the loaded value in v1 and reuses it as the known zero in `slt v1,v1,s0` (original: value in a0, `slt v1,zero,s0`); if/else shape or the copy trick do not change it. func_00272E18 needs the unroll flag on t_271480 (not tried).
- func_00272058 (t_271480) MATCH (near miss resolved, nonmatching copy removed): the KEY QUIRK (callee `func_0011DBB8` declared `int`, result unused) fixed all the v0/v1 numbering; then `off = p->unk38 + h * a; n = h;` (the `n = h` copy AFTER the multiply gives `move s0,v0` after the mult) and the tail `int x = p->unk20; int y = p->unk1C; if (y < x) x = y; p->unk20 = x;` with `unk1C`/`unk20` volatile fields (both volatile keeps the load order 32 then 28 and the movn). RETRY every old near miss that has a void callee with this quirk.
- C8 retries with the int-return quirk (no match): func_002E8A98 (same diff: base/ivs hoisting), func_0026FAE0 (b/hi/lo still allocated in reverse order s2/s1/s0), CFunc_StartPreLoadedStream (without the asm barriers and with int callees the size is 0x23c, only the saved-register order differs: original key s0, h s1, i s2, obj s3, const s4, ck s5, done s6, mode s7, &s1c s8), CFunc_CheckButtonsBoss (movn loop registers unchanged, ref-helper Max too), CFunc_StarPowerFastTest (the missing `move s0,s1` is not reproduced by an if-chain either).
- func_00271280 (t_26F3B8) MATCH: sound command queue push (7 args, the last an optional `int *` out id; ring of 0x30-byte entries at D_004278B0, index D_00373398): `D_00373398` declared `volatile` (the original reads it twice: index and `(i + 1) % 32`; `(i + 1) % 32` gives the sra/movn signed-mod idiom), `D_00370D40` volatile + GP_DATA (`D += 1; q->unk2C = D;` reloads), the spin loops `while (func_002EEA00(q->unk28) >= 0) { if (n++ % 1000 == 0) log(); }` (post-increment inside the test: the div sees the old n, the addiu lands in the bnez delay slot, the first spin logs) and `for (;;) { r = f(3, q, 0x30, 0, 0, 0); q->unk28 = r; if (r) break; if (m++ % 1000 == 0) log(); }`, `int id = D_003733B4++;` (post-increment keeps the loaded value and a copy: `lw v1; move s1,v1; addiu v1,v1,1`), the callees func_002F3B80/func_002F3BD0 declared `int` (KEY QUIRK again: v0 vs v1), `func_00271480(u16, void *)` takes the masked value without sign extension, struct fields `s16 unk8, unkA` (lh), the 7-arg view through an asm-label alias because the file prototypes it with `int`s.
- func_002700A0 (t_26F3B8): near miss (0x294 vs 0x29c; same code, only register allocation: the original builds the four sdata-less globals D_00372EA8/EA0/EB8/EB0 directly into s3..s6 at entry with `lui s3; addiu s3,s3,lo` and keeps `1` in s0 and the D_003A8D40 base in s7; ours builds them through v0/v1 temporaries), nonmatching/func_002700A0.cpp: sound reset: `for (i < 8) { if (V[i].a >= 0) f(V[i].a, V[i].b); V[i].a = -1; }` (unrolled by the file flag), `memset(sp, 0, 8)`, per bank `m = func_00270DB8(i)` and a 22-channel scan `if (!(m & (1 << j)) && (e->unkC >> 2 & 1)) sp[e->unkE] |= 1 << e->unkF` with the row walked as `(char *)D_003A8D40 + off; off += 0x1B8`, then the EA8/EB0/EB8/EA0 initialisation written through local `u32 *` copies declared at the top.
- func_002530A8 retried (t_252068, int-return callees, `&vp->unk34` written inline twice): size now equal (0x118) but two things remain: the vptr/entry registers of the vcall (original vptr v0 / entry v1, ours the reverse with void or int entry) and the shared `addiu s2,s1,52` which the original places in the beqz delay slot after the `lw a0,52(s1)` (ours schedules it before the load and the slot stays a nop).
- func_002AF698 (t_2AF598): near miss, SAME SIZE 0x250, only the numbering of the saved registers (original c s0, r17 s1, a0 s2, r19 s3; ours r17 s0, c s1, r19 s2, a0 s3: pairs swapped; every declaration order of the four locals gives the same), nonmatching/func_002AF698.cpp: controller button-mask builder; the `r17` chain is updated IN PLACE (`r17 = 0x10000; if (x == 0) r17 = 0; if (a) r17 |= 0x1000; ...` gives `movz/movn s1,..` on the same register; separate temporaries per step or ternaries give other code), the branch for unkF is `r17 = r19; if (t->unkF) r17 = r19 | 0x10000;` (still if-converted here; the original branches), the `func_002AF438(c, a0) != 0` arm first, `if (c->unk1C != 0) { ...; return 1; } return 0;`, D_00371F90 as the gp-relative int array, the 3 out pointers written under `!= 0` tests, a4 kept as `sp8`.
- func_002D0F08 (t_2D0150): near miss, SAME SIZE 0x22c, only the saved-register numbering (original t16 s0, t17 s1, t18 s2; ours t17 s0, t18 s1, t16 s2; declaration order and call order change nothing), nonmatching/func_002D0F08.cpp: three-way branch on the field at +0x2C (0x3AC1877C / 0x6E965B60 / other) with a float read `ok = func_0027CC30(h, 0x36EC0682, 2, &fN); v = fN; if (ok == 0) goto fail;` per arm (the float is read between the call and the test: it lands in the delay slot of the `beqz`), the fallbacks are SHARED labels written as in m2c (`block18: var4 = t16; block19: func_0027F1E0(var4, 0, 1); v = 0.0f;` inside the last arm, `goto block18/block19` from the others, `if (...) {} else goto block18` for the arms that fall out on success), result `0xDE7A971B` / `< 0.66f` -> `0x7DD4C604` / `> 1.33f` -> `0x937BB16D`.
- func_0028E278 (t_28CC70, `-funroll-loops`): not matched, no near miss kept: element teardown loop (`for (i = unk40 - 1; i != -1; i--) { e = base + i*0x30; e->unk14 = 0; if (h = e->unk18) { release(h); free(h); e->unk18 = 0; } }`, re-reading `p->unkA4` after each pair of calls); the unrolled shape with the 3-way remainder switch comes out (0x274 vs 0x27c) but gcc folds the guard `(n - 1) != -1` into `beqz n` where the original keeps `li v0,-1; addiu s4,s4,-1; beq s4,v0`; `i >= 0` / explicit offset IV / `int n` copies all fold or change the unroll.
- func_002B8088 (t_2B8088): near miss, SAME SIZE 0x280 (ours 0x278 by dk: one saved register more: s4), nonmatching/func_002B8088.cpp: song-score rating (two handles D_00371F90[2] gp-relative / D_00371F94 as an unsized lui array, D_00371FF8 with GP_DATA): `int h = D[arg0]; int ok = f(h, 0xA675A409, 1, &sp0); int v = sp0; if (ok == 0) { v = 0; fb(h); }` (note `v = 0` BEFORE the fallback call in the first two reads, after it in the third), the two-player branch with `goto block12 / block13` into the else arm exactly as m2c (`slot = &D[arg0]` and `f(*slot, ...)`), rating key by `v >= 30 / >= 20 / else`, final `if (v >= 10) {...}`; the original keeps base and arg0*4 in two saved registers (s2, s3) and re-adds them at each use, ours CSEs `&D[arg0]` into a third.
- func_00270A90 retried (t_26F3B8, `int func_00273EB0(int)` prototype): SAME SIZE 0x140, the only difference is the order of two preheader instructions (`addiu s2,v0,1` before `li s5,1` in ours, the original has `li s5,1` first and `addiu s2,v0,1` last); do-while, `1 == f()`, inverted test, `i != 8` forms all give the same preheader. A permuter candidate (nonmatching/func_00270A90.cpp refreshed).
- CFunc_PlaySound (t_254248) retried: the final call `func_0026A488(int a, f32 x, int b, int c, f32 y, f32 z)` declared with the float in its argument position (registers unchanged: a0 a1 a2 + f12 f13 f14) fixes the original load order `lw a0 / lwc1 f12 / lw a1`; what remains are the order of the six `swc1 $f0` of the 100.0f initialisation (original 54, 50, 48, 4C; ours 4C, 54, 50, 48 for ANY chain or statement order: all 24 chain orders x 6 second-chain orders tried) and of the second chain (original 4C then 48). nonmatching/CFunc_PlaySound.cpp refreshed.
- func_002D0F08 retried (call order variants only move the call order itself): still the register numbering near miss.
- func_002DCF10 (t_2DCE78) MATCH (near miss resolved, nonmatching copy removed): the "4th saved register" was the heap handle read BEFORE the `flag == 0` test: read it AFTER the if instead (`if (flag == 0) { int t = D_00368A38; f490(t, f610(t, 1)); f4B8(D_00368A38); } int h = D_00368A38; f490(h, f610(h, 1));`), then flag and h share s0 (the join load goes into the bnez delay slot); the dead colour is `S2DCF_Col c` with the inline member `c.Set(0xFF,0xFF,0xFF,0xFF)` before every call (pointer `addiu s1,sp,0x10` + `sb 0x10(sp)`), callees func_002EA460 / func_0028CF40 / func_0028C200 declared `int`, and NO GP_DATA for D_00372228 (the original reads it with lui).
- func_002DB580 (t_2DAE48) MATCH: scene/event object ctor: base ctor, `unk14 = D_003630E8`, optional heap-5 allocation of a 0x2C object under `D_00368748 == 0`, then FOUR nodes made with `operator_new(0x24 | 0x30)` + `func_00113EA8(n, 0 | 0x3E8)` and field stores (vtable-like words at 0x18, handler addresses at 0x1C/0x28, owner at 0x20/0x2C), the two 0x30 ones preceded by `S2DB5_C c; c.Set(0xFF,0xFF,0xFF,0xFF)` (dead stack colour, sb x4 before the operator_new call); the handler address is held in a local BEFORE the ctor call (`int fa = (int)func_002D8880; ctor(n1, 0); n1->unk1C = fa;`): that reproduces the original `lui/addiu` into a saved register before the call and the 7th saved register; operator_new declared variadic through an asm-label alias, every callee `int`.
- func_002DCB98 (t_2DAE48) MATCH (was a "unused byte colour" give-up): same recipe as func_002DB580: one node `operator_new(0x24)` + `func_00113EA8(n, -0x7D0)` with the handler address in a local before the ctor call, then `S2DB5_C c; c.Set(0xFF, 0, 0, 0xFF);` written AFTER the last node store and before `p->unk1C = 0` (the emitted sb order is 3, 0, 1, 2), returns the incoming pointer.
- func_002DC5B8 (t_2DAE48) MATCH (the second "unused byte colour" ctor): six zeroed fields (0x24..0x38) before `unk14`, one node as in func_002DCB98 (handler address in a local before the ctor call, `n->unk18` last), `S2DB5_C c; c.Set(0xFF, 0, 0, 0xFF);` after `p->unk18 = n`, then `func_0014ED48(D_0036D3B0)` (one argument); returns the incoming pointer. The whole ctor family (func_002DB580 / func_002DCB98 / func_002DC5B8, and the like in other files with `operator_new` + `func_00113EA8` + a dead colour) is solved by: asm-label aliases with `int` results, handler address into a local before the ctor call, dead colour as a struct with an inline `Set` right where the asm stores it.
- func_002DE280 (t_2DCE78): near miss (0x19c vs 0x194), nonmatching/func_002DE280.cpp: the ctor recipe (3 nodes, handler address in a local before each ctor call, `S2DCF_Col c; c.Set(0xFF,0xFF,0xFF,0xFF)` before the 2nd and 3rd `operator_new` and at the end, `0xFFFFFFFF` as a `u32` literal (`lui/ori`, not `li -1`), `s3 = 0xFF` comes out) gets everything but the register of `p + 0x8000` (original s5 with p in s4, ours s6) and the constant 0xFFFFFFFF, which the original builds once into a2 and uses for both the store at +4 and the 3rd argument of func_0029FD08 (ours builds it twice; a local, or re-reading the stored field, does not merge them).

Round 2026-10-19 (C8) final: 11 matches / 40 attempted.
Round 2026-10-20 (C9): 15 matches / 27 attempted (limit 15/40) FINAL
- func_00277220 (t_2754A0) MATCH (near miss resolved, nonmatching copy removed): nested compare `if (c1 == c2) { if (c2 == 0) return 1; } else return 0;` in the for(;;) (instead of `if (c1 != c2) return 0; if (c2 == 0) return 1;`) puts `v0 = 0` in the bne delay slot as the original.
- func_0028C8F8 (t_28AB28) MATCH (near miss resolved, nonmatching copy removed): only `func_00296AF0` (void, result unused) declared `int` fixed the -1 in v1.
- func_002E9818 (t_2E90B0) MATCH (near miss resolved, nonmatching copy removed): `func_00295010` (void, result unused) declared `int` gives `li v1,1` for the flag store.
- func_002532C8 (t_252068) MATCH (near miss resolved, nonmatching removed): `func_00269998` (void, result unused) declared `int`.
- func_00299910 (t_298A30) MATCH (near miss resolved, nonmatching removed): `func_00296AF0` (void, result unused) called through an `int` alias (`func_00296AF0_i`, the file keeps the void declaration for others); local `S298_Small` message struct.
- func_002949F0 (t_2949F0) MATCH (near miss resolved, nonmatching removed): `func_002EE6A0` (void, result unused) declared `int` swapped the v0/v1 of the count compare.
- func_002DE738 (t_2DCE78) MATCH (near miss resolved, nonmatching removed): the registration helper `func_002981A0` (void, result unused) called through an `int` alias (`func_002981A0_i`; the file's other users keep the void alias). Found by an automatic sweep: flip each callee's declared void/int return in every near miss (singles and pairs) and recompile.
- func_0028E010 (t_28CC70): near miss (0x200 both, 5 instructions: in the loop the original computes the element as `lw v0,164(s1); li v1,4; addu s0,s6,v0; addiu s0,s0,28`, ours `lw v1; addu v1,s6,v1; addiu s0,v1,28; ... li v1,4` later), nonmatching/func_0028E010.cpp: element teardown/handler dispatch; the element at `(char*)(i*0x30) + (int)o->unkA4` (offset FIRST gives `addu s6,v0`), helper-less duplicated sites, `S28E0_Ent *t = &ENT(o,i); t->unk4 = f(g(8,1))` (address before the call), first site with `&key`, loop site with 0 for the third argument of func_00288EA8; the file's -funroll-loops flag is already there.
- Retried without match (nonmatching copies kept): func_002884A8 (arg order a0/a1 before func_00119610: prototype variants, alias types, volatile zero: nothing moves it), CFunc_LightShow_OverrideColor (li a2,6 vs move a0 order; callee return/arg tricks no change), func_002E7B60 (v0/v1 fixed by declaring func_002E3F50 int, remaining: original `move v0,s1; movz v0,zero,x^1` against ours `move v0,zero; movn v0,s1,x^1`: helper-reference, ternary, inverted helper, one-var forms all give the movn shape), func_002891A8 (s0/s1 numbering and beqzl vs beqz at the entry: declaration order, for-form, hoisted i do not change it), func_00289ED8 (QB chain lookup: p in v1 vs v0), func_0029F5C8 (layout: original `beqz else; sw pad; b end; li v0,1000`, ours inverts the branch with li in the slot: if/else, early return, ternary forms), CFunc_ForEachIn (callee flip to int helps only partly; the `lw v1,8(sp)` arr load order remains).
- func_0028A140 (t_288B10) MATCH (near miss resolved, nonmatching copy removed): the copy loop as `while (i < (u32)n) { *dst++ = *src++; i++; }` with `char *src; char *dst; u32 i = 0;` declared in that order (the do/while inside `if (n != 0)` gave a3/a2 swapped counter/compare registers).
- func_00293120 (t_292928) MATCH (near miss resolved, nonmatching copy removed): fields +8 and +C of the struct declared `volatile` keep the original store order (C, 0, 4, 10, 8) against the scheduler; the unrolled clear loop needs `// cflags: -funroll-loops`, now added to t_292928 (every function of the file still matches).
- func_0026DAF8 (t_26D280) MATCH (near miss resolved, nonmatching copy removed): last-path-separator scan as `if (c == '\' || c == '/') p = path + (i + 1); i++;` (the old attempt used a shared `j = i + 1`; separate `i + 1` and `i++` give the original two registers).
- func_00288A20 (t_286A60) MATCH (untried-by-retry): value setter: `if (func_00288E30(v, a)) { r = Heap_Alloc(D_00368A38, 0x10, 1, 0); r->0 = 0; r->4 = 0; *(char **)((char *)r + 0xC) = D_0035AF80; r->8 = 0; v->value = r; v->b4 = func_002892B0(v, a, r); p = v->value; if (p->unk4 == 0) { delete p; v->value = 0; } if (v->type == 4) func_002891A8(v); v->b7 = 1; }` with `struct S2867_R { int unk0, unk4, unk8; virtual ~S2867_R(); }` (vptr lands at 0xC); the inlined ctor's vptr store is written by hand (an extern char vtable symbol), in the original order 0, 4, vptr, 8.
- func_002882E8 (t_286A60) MATCH: file loader: `len = strlen(name); ext = func_00117030(); if (name[len - 4] == '.' && func_0030E650(name + len - 3, ext) == 0) { f490(D_00368A38, f730(D_00368A38, c, 1)); h = f_0011D000(name, 0, 0, 0, 0); f4B8(D_00368A38); func_00287EB0(name, h, a); } else { f490(D_00368A38, *(int *)(D_00368A38 + 0x1DC)); h = ...; f4B8; func_00287578(name, h, a, 0); func_0011D348(name); } func_002882E0(1)` (the empty func_002882E0 called with an argument through an alias).
- func_002874A8 (t_286A60) MATCH: bracket skipper with three counters, plain `if (t == K) n++/--` statements (no helper needed here: gcc if-converts them to the original `movz` chain): `int b = 0, a = 0, c = 0;` (declaration order gives s3, s2, s1), statements in the order t==3 b++, t==5 a++, t==14 c++, t==4 b--, t==6 a--, t==15 c-- (the scheduler emits them in the opposite order of the source pair), and `if (b != 0 || a != 0 || c != 0 || !f(p)) { p = next(p); continue; } next(p); return;` for the original block layout.
- func_002774D8 (t_2774B8) MATCH: bucket lookup `if (D_00368744 == 0) return 0; n = D_00371178[key & 0xFFFF]; for (; n; n = n->next) if (n->key == key) return n->val; return 0;` ({key, val, next} nodes, table pointer in $gp). The file declares it as `char *func_002774D8(void)` for its caller (which passes its own a0 through untouched), so the definition goes through an asm-label alias (`char *func_002774D8_k(int) __asm__("func_002774D8")`).
- func_002704E0 (t_26F3B8) MATCH: link of two table cells (partner of func_00270540): `int a, b, c, d` parameters (an s8 parameter adds sll/sra), `S26F3B8_A *o = &D_003A8D40[a][b]; S26F3B8_A *e = &D_003A8D40[c][d]; e->unkE = a; e->unkF = b; o->unkE = c; o->unkF = d; e->unkC |= 2;`. Found by brute force over the statement order (2 address orders x positions x 24 store orders); the saved s0 in the frame comes out by itself.
- func_00295278 (t_2949F0): not matched, no near miss kept (0x64 vs 0x60): ring-buffer window (`sz = *(int *)(base + 0x50008); end = base + sz; cur = a->unk8 + 4; if (cur >= end) cur -= sz; len = a->unkC - 4; n = min(end - cur, len)`, `> 0`) has every instruction and the movz/movn pair; only the register numbering (original keeps base copy in a3, sz in v1, len in t0, n in a3 via `movn a3,t0`; ours base v1, len in a3 and `movz a3,v1`): all orders of the four statements, ternary forms and pointer-typed `end` tried.
