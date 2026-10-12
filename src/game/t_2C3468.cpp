#include "common.h"

extern "C" {
int func_00289CF8(s32);
}

INCLUDE_ASM("asm/nonmatchings/game/t_2C3468", CFunc_CameraCut_GetCameraIndex);

INCLUDE_ASM("asm/nonmatchings/game/t_2C3468", func_002C34C8);

INCLUDE_ASM("asm/nonmatchings/game/t_2C3468", CFunc_CameraCut_SwapLookAts);

INCLUDE_ASM("asm/nonmatchings/game/t_2C3468", CFunc_GetRandomSeeds);

INCLUDE_ASM("asm/nonmatchings/game/t_2C3468", CFunc_SetRandomSeeds);

INCLUDE_ASM("asm/nonmatchings/game/t_2C3468", CFunc_SetNewWhammyValue);

INCLUDE_ASM("asm/nonmatchings/game/t_2C3468", CFunc_SetAllWhammyValues);

INCLUDE_ASM("asm/nonmatchings/game/t_2C3468", CFunc_SetButtonData);

INCLUDE_ASM("asm/nonmatchings/game/t_2C3468", CFunc_ATan2);

extern "C" s32 CFunc_Init2DParticles(void) {
    return 1;
}

extern "C" s32 CFunc_Exit2DParticles(void) {
    return 1;
}

extern "C" s32 CFunc_Create2DParticleSystem(void) {
    return 1;
}

extern "C" s32 CFunc_Destroy2DParticleSystem(void) {
    return 0;
}

extern "C" s32 CFunc_Update2DParticleSystems(void) {
    return 1;
}

INCLUDE_ASM("asm/nonmatchings/game/t_2C3468", CFunc_ButtonCheckerInit);

INCLUDE_ASM("asm/nonmatchings/game/t_2C3468", CFunc_ButtonCheckerPerFrame);

extern "C" s32 CFunc_ButtonCheckerCleanup(int arg0, s32 arg1) {
    func_00289CF8(arg1);
    return 1;
}

INCLUDE_ASM("asm/nonmatchings/game/t_2C3468", func_002C5308);
