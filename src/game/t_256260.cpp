#include "common.h"

extern "C" {
void func_002E9818(void);
void func_002E99D0(void);
void func_002E8318(void);
int func_002E7BC8(void);
int func_002E7BE8(void);
void func_00256740(int, int);
int func_0028C470(int, int);
bool func_0027DF00(int, u32);
void func_002E9C00(int);
}

extern "C" int CFunc_PauseSound(void) {
    return 0;
}

INCLUDE_ASM("asm/nonmatchings/game/t_256260", CFunc_PauseAllSounds);

INCLUDE_ASM("asm/nonmatchings/game/t_256260", CFunc_SetPositionalSoundSilenceOverrideMode);

extern "C" int CFunc_OutputFModCPUUsage(void) {
    return 1;
}

extern "C" int CFunc_DumpSounds(void) {
    return 1;
}

extern "C" int CFunc_EnableRemoveSoundEntry(void) {
    return 0;
}

extern "C" int CFunc_TerrainSoundCalculatePitchAndVolFast(void) {
    return 0;
}

extern "C" int CFunc_IsFmodEnabled(void) {
    return 0;
}

extern "C" int CFunc_EnableUserMusic(void) {
    return 0;
}

INCLUDE_ASM("asm/nonmatchings/game/t_256260", func_00256340);

INCLUDE_ASM("asm/nonmatchings/game/t_256260", CFunc_AddSfxHeader);

INCLUDE_ASM("asm/nonmatchings/game/t_256260", CFunc_HackSetReverbPlease);

extern "C" int CFunc_HackSetEffect(void) {
    return 0;
}

INCLUDE_ASM("asm/nonmatchings/game/t_256260", CFunc_ResetWhammyPitchShift);

extern "C" void CFunc_EnableMenuMusic(int a) {
    func_002E9C00(!func_0027DF00(a, 0xB0BAB2AE));
}

extern "C" void CFunc_LoadMoreMenuMusic(void) {
    func_002E9818();
}

extern "C" void CFunc_MenuMusicPreloaded(void) {
    func_002E99D0();
}

extern "C" void CFunc_KeyOffAllSfx(void) {
    func_002E8318();
}

extern "C" int CFunc_PauseAllSFX(void) {
    func_002E7BC8();
    return 1;
}

extern "C" int CFunc_UnPauseAllSFX(void) {
    func_002E7BE8();
    return 1;
}

INCLUDE_ASM("asm/nonmatchings/game/t_256260", CFunc_SetMenuMusicVolume);

extern "C" void func_00256740(int a, int b) {
}

extern "C" void func_00256748(void) {
    func_00256740(1, 0xFFFF);
}

INCLUDE_ASM("asm/nonmatchings/game/t_256260", CFunc_GetTerrainTypeParam);

INCLUDE_ASM("asm/nonmatchings/game/t_256260", func_00256838);

INCLUDE_ASM("asm/nonmatchings/game/t_256260", func_00256848);

INCLUDE_ASM("asm/nonmatchings/game/t_256260", CFunc_Wait);

extern "C" int CFunc_WaitOneGameFrame(int a, int b) {
    func_0028C470(b, 1);
    return 1;
}

INCLUDE_ASM("asm/nonmatchings/game/t_256260", CFunc_CastToInteger);

INCLUDE_ASM("asm/nonmatchings/game/t_256260", CFunc_StringToInteger);

INCLUDE_ASM("asm/nonmatchings/game/t_256260", CFunc_WideStringToInteger);

INCLUDE_ASM("asm/nonmatchings/game/t_256260", CFunc_IntegerEquals);

INCLUDE_ASM("asm/nonmatchings/game/t_256260", CFunc_ChecksumEquals);

INCLUDE_ASM("asm/nonmatchings/game/t_256260", CFunc_StringEquals);

INCLUDE_ASM("asm/nonmatchings/game/t_256260", CFunc_LocalizedStringEquals);

INCLUDE_ASM("asm/nonmatchings/game/t_256260", CFunc_ArrayContains);

INCLUDE_ASM("asm/nonmatchings/game/t_256260", func_002571C8);

INCLUDE_ASM("asm/nonmatchings/game/t_256260", CFunc_GetArraySize);

INCLUDE_ASM("asm/nonmatchings/game/t_256260", CFunc_SetArrayElement);

INCLUDE_ASM("asm/nonmatchings/game/t_256260", CFunc_AddParams);

INCLUDE_ASM("asm/nonmatchings/game/t_256260", CFunc_AddParam);

INCLUDE_ASM("asm/nonmatchings/game/t_256260", CFunc_RemoveComponent);

INCLUDE_ASM("asm/nonmatchings/game/t_256260", CFunc_GlobalExists);

INCLUDE_ASM("asm/nonmatchings/game/t_256260", CFunc_RemoveParameter);

INCLUDE_ASM("asm/nonmatchings/game/t_256260", CFunc_RemoveFlag);

INCLUDE_ASM("asm/nonmatchings/game/t_256260", CFunc_GetRandomValue);

INCLUDE_ASM("asm/nonmatchings/game/t_256260", CFunc_ForEachIn);

INCLUDE_ASM("asm/nonmatchings/game/t_256260", CFunc_GetElement);

INCLUDE_ASM("asm/nonmatchings/game/t_256260", CFunc_GetNextArrayElement);
