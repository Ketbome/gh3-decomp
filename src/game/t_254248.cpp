#include "common.h"

extern "C" {
void func_0026C870(void);
int func_0026A030(void);
int func_0026E8B8(void);
int func_002EA460(void);
int func_002E8968(void);
int func_00266D20(void);
int func_0026AE70(void);
int func_0026CC48(void);
extern int D_00370AE0[] __attribute__((section(".sdata")));
void func_00267A00(int);
int func_0027D870(int, int, void*, int);
int func_0027DF00(int, u32);
void func_0026CBE8(int);
void func_002E7010(int);
}

extern "C" int CFunc_AddSoundEventData(void) {
    return 0;
}

extern "C" int CFunc_RequestNewSoundEvent(void) {
    return 0;
}

INCLUDE_ASM("asm/nonmatchings/game/t_254248", CFunc_StopSoundEvent);

extern "C" int CFunc_IsSoundEventPlaying(void) {
    return 0;
}

extern "C" int CFunc_AddSoundEventScript(void) {
    return 0;
}

extern "C" int CFunc_RemoveSoundEventScript(void) {
    return 0;
}

INCLUDE_ASM("asm/nonmatchings/game/t_254248", CFunc_LoadSound);

extern "C" int CFunc_UnloadAllSFX(void) {
    func_0026A030();
    return 1;
}

INCLUDE_ASM("asm/nonmatchings/game/t_254248", CFunc_ResetBCSND);

INCLUDE_ASM("asm/nonmatchings/game/t_254248", CFunc_LoadFSB);

INCLUDE_ASM("asm/nonmatchings/game/t_254248", CFunc_UnLoadFSB);

extern "C" int CFunc_LockDSP(void) {
    return 0;
}

extern "C" int CFunc_UnLockDSP(void) {
    return 0;
}

extern "C" int CFunc_PlayStream(int a) {
    int x = 0;
    return func_0027D870(a, 0, &x, 0) != 0;
}

INCLUDE_ASM("asm/nonmatchings/game/t_254248", CFunc_StreamExists);

INCLUDE_ASM("asm/nonmatchings/game/t_254248", CFunc_AddStream);

INCLUDE_ASM("asm/nonmatchings/game/t_254248", CFunc_RemoveStream);

INCLUDE_ASM("asm/nonmatchings/game/t_254248", CFunc_StopSoundStream);

INCLUDE_ASM("asm/nonmatchings/game/t_254248", CFunc_StopStream);

extern "C" int CFunc_StopSoundsByBuss(int a) {
    int x = 0;
    func_0027D870(a, 0, &x, 0);
    return 1;
}

extern "C" int CFunc_StopAudioStreams(void) {
    return 0;
}

INCLUDE_ASM("asm/nonmatchings/game/t_254248", CFunc_IsStreamPlaying);

INCLUDE_ASM("asm/nonmatchings/game/t_254248", CFunc_SetStreamParams);

extern "C" int CFunc_PreprocessStreamSets(void) {
    func_0026E8B8();
    return 1;
}

INCLUDE_ASM("asm/nonmatchings/game/t_254248", CFunc_PlayStreamFromSet);

INCLUDE_ASM("asm/nonmatchings/game/t_254248", CFunc_LoadSoundRAM);

INCLUDE_ASM("asm/nonmatchings/game/t_254248", CFunc_PlayTrack);

INCLUDE_ASM("asm/nonmatchings/game/t_254248", CFunc_PlayMusicStream);

INCLUDE_ASM("asm/nonmatchings/game/t_254248", CFunc_LoadStreamFrameAmp);

INCLUDE_ASM("asm/nonmatchings/game/t_254248", CFunc_FreeStreamFrameAmp);

extern "C" int CFunc_BCSND_UpdateSound(void) {
    func_002EA460();
    return 1;
}

INCLUDE_ASM("asm/nonmatchings/game/t_254248", CFunc_SetStereoSound);

INCLUDE_ASM("asm/nonmatchings/game/t_254248", CFunc_PlaySound);

extern "C" int CFunc_IsSoundLoaded(void) {
    return 0;
}

INCLUDE_ASM("asm/nonmatchings/game/t_254248", CFunc_StopSound);

extern "C" int CFunc_StopAllSounds(void) {
    func_002E8968();
    return 1;
}

extern "C" int CFunc_SetSoundSeekPosition(void) {
    return 0;
}

extern "C" int CFunc_IsSoundSeekDone(void) {
    return 0;
}

extern "C" int CFunc_PauseSoundsByBuss(void) {
    return 0;
}

extern "C" int CFunc_UnPauseSoundsByBuss(void) {
    return 0;
}

INCLUDE_ASM("asm/nonmatchings/game/t_254248", CFunc_SetSoundParams);

INCLUDE_ASM("asm/nonmatchings/game/t_254248", CFunc_IsSoundPlaying);

extern "C" int CFunc_IsSoundPlayingByID(void) {
    return 0;
}

INCLUDE_ASM("asm/nonmatchings/game/t_254248", CFunc_AddSoundBanks);

INCLUDE_ASM("asm/nonmatchings/game/t_254248", CFunc_ClearSoundBank);

extern "C" int CFunc_RemoveAllSoundBanks(void) {
    func_00267A00(D_00370AE0[0]);
    return 1;
}

INCLUDE_ASM("asm/nonmatchings/game/t_254248", CFunc_RemoveSoundGroup);

extern "C" int CFunc_ClearSoundGroups(void) {
    func_00266D20();
    return 1;
}

INCLUDE_ASM("asm/nonmatchings/game/t_254248", CFunc_SetDefaultSoundPriority);

INCLUDE_ASM("asm/nonmatchings/game/t_254248", CFunc_SetSfxReverb);

INCLUDE_ASM("asm/nonmatchings/game/t_254248", CFunc_SetSfxDropoff);

INCLUDE_ASM("asm/nonmatchings/game/t_254248", CFunc_SetSfxVolume);

INCLUDE_ASM("asm/nonmatchings/game/t_254248", CFunc_SetGlobalPitchModulation);

INCLUDE_ASM("asm/nonmatchings/game/t_254248", CFunc_SetMusicVolume);

INCLUDE_ASM("asm/nonmatchings/game/t_254248", CFunc_SetMusicStreamVolume);

extern "C" int CFunc_StopMusic(void) {
    func_0026AE70();
    return 1;
}

INCLUDE_ASM("asm/nonmatchings/game/t_254248", CFunc_PauseMusic);

INCLUDE_ASM("asm/nonmatchings/game/t_254248", CFunc_PauseStream);

INCLUDE_ASM("asm/nonmatchings/game/t_254248", CFunc_PauseStreamNum);

INCLUDE_ASM("asm/nonmatchings/game/t_254248", CFunc_PauseStreamID);

INCLUDE_ASM("asm/nonmatchings/game/t_254248", CFunc_LoadMusicHeader);

INCLUDE_ASM("asm/nonmatchings/game/t_254248", CFunc_LoadStreamHeader);

INCLUDE_ASM("asm/nonmatchings/game/t_254248", CFunc_AddMusicTrack);

INCLUDE_ASM("asm/nonmatchings/game/t_254248", CFunc_ChangeTrackState);

INCLUDE_ASM("asm/nonmatchings/game/t_254248", CFunc_TrackEnabled);

extern "C" void CFunc_MusicIsPaused(void) {
    func_0026C870();
}

extern "C" int CFunc_ClearMusicTrackList(int a) {
    func_0026CBE8(func_0027DF00(a, 0x389129E4) == 0);
    return 1;
}

extern "C" int CFunc_SkipMusicTrack(void) {
    func_0026CC48();
    return 1;
}

INCLUDE_ASM("asm/nonmatchings/game/t_254248", CFunc_SetMusicMode);

INCLUDE_ASM("asm/nonmatchings/game/t_254248", CFunc_SetRandomMode);

INCLUDE_ASM("asm/nonmatchings/game/t_254248", CFunc_SetMusicLooping);

INCLUDE_ASM("asm/nonmatchings/game/t_254248", CFunc_GetCurrentTrack);

INCLUDE_ASM("asm/nonmatchings/game/t_254248", CFunc_GetValueFromVolume);

INCLUDE_ASM("asm/nonmatchings/game/t_254248", CFunc_PreLoadStream);

INCLUDE_ASM("asm/nonmatchings/game/t_254248", CFunc_PreLoadSoundStream);

INCLUDE_ASM("asm/nonmatchings/game/t_254248", CFunc_PreLoadChecksumStream);

extern "C" void CFunc_PreLoadStreamDone(int a) {
    int x;
    func_0027D870(a, 0, &x, 1);
    func_002E7010(x);
}

INCLUDE_ASM("asm/nonmatchings/game/t_254248", CFunc_IsSoundStreamPlaying);

INCLUDE_ASM("asm/nonmatchings/game/t_254248", CFunc_StartPreLoadedStream);
