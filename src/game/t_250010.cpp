#include "common.h"

extern "C" {
int func_0014F150(void);
int func_002A3EA0(void);
extern char D_00355EA0[];
extern char D_00355EB0[];
void func_00250A18(int, int, void*);
}

INCLUDE_ASM("asm/nonmatchings/game/t_250010", CFunc_NudgeVC);

INCLUDE_ASM("asm/nonmatchings/game/t_250010", CFunc_InitAnimCompressTable);

INCLUDE_ASM("asm/nonmatchings/game/t_250010", CFunc_InitAnimSystem);

INCLUDE_ASM("asm/nonmatchings/game/t_250010", CFunc_UpdateAnimCache);

INCLUDE_ASM("asm/nonmatchings/game/t_250010", CFunc_GetAnimCacheState);

extern "C" int CFunc_FinishRendering(void) {
    func_0014F150();
    return 1;
}

extern "C" int CFunc_TogglePass(void) {
    return 1;
}

INCLUDE_ASM("asm/nonmatchings/game/t_250010", CFunc_SetScreen);

INCLUDE_ASM("asm/nonmatchings/game/t_250010", CFunc_AllowBoneLOD);

extern "C" int CFunc_PreLoadMovie(void) {
    return 0;
}

extern "C" int CFunc_StartPreLoadedMovie(void) {
    return 0;
}

extern "C" int CFunc_IsMoviePreLoaded(void) {
    return 0;
}

INCLUDE_ASM("asm/nonmatchings/game/t_250010", CFunc_PlayMovie);

extern "C" int CFunc_KillMovie(void) {
    return 0;
}

extern "C" int CFunc_PauseMovie(void) {
    return 0;
}

extern "C" int CFunc_ResumeMovie(void) {
    return 0;
}

extern "C" int CFunc_SeekMovie(void) {
    return 0;
}

extern "C" int CFunc_StopLoopingAndFinishMovie(void) {
    return 0;
}

extern "C" int CFunc_IsMoviePlaying(void) {
    return 0;
}

INCLUDE_ASM("asm/nonmatchings/game/t_250010", func_002509A0);

INCLUDE_ASM("asm/nonmatchings/game/t_250010", func_00250A18);

extern "C" void CFunc_LoadTexture(int a) {
    func_00250A18(a, 0, D_00355EA0);
}

INCLUDE_ASM("asm/nonmatchings/game/t_250010", CFunc_UnloadTexture);

INCLUDE_ASM("asm/nonmatchings/game/t_250010", func_00250C30);

INCLUDE_ASM("asm/nonmatchings/game/t_250010", CFunc_DrawDirectionalLightLines);

INCLUDE_ASM("asm/nonmatchings/game/t_250010", CFunc_IsTextureLoaded);

extern "C" int CFunc_SetShadowMapParams(void) {
    return 0;
}

INCLUDE_ASM("asm/nonmatchings/game/t_250010", func_00250FF0);

INCLUDE_ASM("asm/nonmatchings/game/t_250010", func_00251090);

INCLUDE_ASM("asm/nonmatchings/game/t_250010", CFunc_InitLightManager);

INCLUDE_ASM("asm/nonmatchings/game/t_250010", func_00251198);

INCLUDE_ASM("asm/nonmatchings/game/t_250010", CFunc_SetShadowDir);

INCLUDE_ASM("asm/nonmatchings/game/t_250010", CFunc_SetShadowDirFromLight);

INCLUDE_ASM("asm/nonmatchings/game/t_250010", func_00251358);

INCLUDE_ASM("asm/nonmatchings/game/t_250010", CFunc_SetLightFlag);

INCLUDE_ASM("asm/nonmatchings/game/t_250010", CFunc_ClearLightFlag);

INCLUDE_ASM("asm/nonmatchings/game/t_250010", CFunc_MoveLight);

extern "C" int CFunc_CompactIntervals(void) {
    return 0;
}

INCLUDE_ASM("asm/nonmatchings/game/t_250010", CFunc_SetLightDirection);

INCLUDE_ASM("asm/nonmatchings/game/t_250010", CFunc_GetLightDirection);

INCLUDE_ASM("asm/nonmatchings/game/t_250010", CFunc_SetLightColor);

INCLUDE_ASM("asm/nonmatchings/game/t_250010", CFunc_GetLightColor);

INCLUDE_ASM("asm/nonmatchings/game/t_250010", CFunc_SetLightIntensity);

INCLUDE_ASM("asm/nonmatchings/game/t_250010", CFunc_GetLightIntensity);

INCLUDE_ASM("asm/nonmatchings/game/t_250010", CFunc_SetLightGroupIntensity);

INCLUDE_ASM("asm/nonmatchings/game/t_250010", CFunc_GetLightGroupIntensity);

extern "C" int CFunc_SetDynamicShadowIntensity(void) {
    return 0;
}

extern "C" int CFunc_KillLight(void) {
    return 0;
}

INCLUDE_ASM("asm/nonmatchings/game/t_250010", CFunc_EnableLight);

INCLUDE_ASM("asm/nonmatchings/game/t_250010", CFunc_DisableLight);

INCLUDE_ASM("asm/nonmatchings/game/t_250010", CFunc_EnableLightGroup);

INCLUDE_ASM("asm/nonmatchings/game/t_250010", CFunc_DisableLightGroup);

extern "C" int CFunc_ApplyLightGroup(void) {
    return 0;
}

extern "C" int CFunc_RemoveCurLightGroup(void) {
    return 0;
}

INCLUDE_ASM("asm/nonmatchings/game/t_250010", CFunc_AddLightToGroup);

INCLUDE_ASM("asm/nonmatchings/game/t_250010", CFunc_CreateLightGroup);

extern "C" int CFunc_SetModelLightsFadeTime(void) {
    return 0;
}

INCLUDE_ASM("asm/nonmatchings/game/t_250010", CFunc_SetLightVolumeParams);

extern "C" void CFunc_LoadParticleTexture(int a) {
    func_00250A18(a, 1, D_00355EB0);
}

INCLUDE_ASM("asm/nonmatchings/game/t_250010", CFunc_HackAddLight);

INCLUDE_ASM("asm/nonmatchings/game/t_250010", CFunc_GetDisplaySettings);

extern "C" int CFunc_SetRowHeightTables(void) {
    func_002A3EA0();
    return 1;
}

INCLUDE_ASM("asm/nonmatchings/game/t_250010", func_00251C90);

INCLUDE_ASM("asm/nonmatchings/game/t_250010", func_00251CA0);

INCLUDE_ASM("asm/nonmatchings/game/t_250010", CFunc_PlayIGCCam);

INCLUDE_ASM("asm/nonmatchings/game/t_250010", CFunc_PlaySkaterCamAnim);

INCLUDE_ASM("asm/nonmatchings/game/t_250010", CFunc_GetSkaterCamAnimParams);

INCLUDE_ASM("asm/nonmatchings/game/t_250010", CFunc_SkaterCamAnimFinished);

INCLUDE_ASM("asm/nonmatchings/game/t_250010", func_00251F68);

INCLUDE_ASM("asm/nonmatchings/game/t_250010", CFunc_KillSkaterCamAnim);
