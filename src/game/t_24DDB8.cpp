#include "common.h"

extern "C" {
int func_0024E3C0(void);
int func_0014F178(void);
}

INCLUDE_ASM("asm/nonmatchings/game/t_24DDB8", CFunc_LinearMap);

INCLUDE_ASM("asm/nonmatchings/game/t_24DDB8", CFunc_Clamp);

INCLUDE_ASM("asm/nonmatchings/game/t_24DDB8", func_0024DF98);

INCLUDE_ASM("asm/nonmatchings/game/t_24DDB8", CFunc_VectorLength);

INCLUDE_ASM("asm/nonmatchings/game/t_24DDB8", CFunc_MathFloor);

INCLUDE_ASM("asm/nonmatchings/game/t_24DDB8", CFunc_MathCeil);

INCLUDE_ASM("asm/nonmatchings/game/t_24DDB8", CFunc_MathPow);

INCLUDE_ASM("asm/nonmatchings/game/t_24DDB8", CFunc_MathMin);

INCLUDE_ASM("asm/nonmatchings/game/t_24DDB8", CFunc_FeelerCheck);

INCLUDE_ASM("asm/nonmatchings/game/t_24DDB8", func_0024E3B8);

INCLUDE_ASM("asm/nonmatchings/game/t_24DDB8", func_0024E3C0);

INCLUDE_ASM("asm/nonmatchings/game/t_24DDB8", CFunc_Anim_GetAnimLength);

extern "C" int CFunc_Anim_AnimExists(void) {
    return func_0024E3C0() != 0;
}

INCLUDE_ASM("asm/nonmatchings/game/t_24DDB8", func_0024E548);

INCLUDE_ASM("asm/nonmatchings/game/t_24DDB8", CFunc_GetCurrentCameraObject);

INCLUDE_ASM("asm/nonmatchings/game/t_24DDB8", CFunc_ScreenFX_AddFXInstance);

INCLUDE_ASM("asm/nonmatchings/game/t_24DDB8", CFunc_ScreenFX_UpdateFXInstanceParams);

INCLUDE_ASM("asm/nonmatchings/game/t_24DDB8", CFunc_ScreenFX_RemoveFXInstance);

INCLUDE_ASM("asm/nonmatchings/game/t_24DDB8", CFunc_ScreenFX_ClearFXInstances);

INCLUDE_ASM("asm/nonmatchings/game/t_24DDB8", CFunc_ScreenFX_FxInstanceExists);

INCLUDE_ASM("asm/nonmatchings/game/t_24DDB8", CFunc_ScreenFX_GetActiveScreenFXInstances);

INCLUDE_ASM("asm/nonmatchings/game/t_24DDB8", CFunc_SetProgressive);

INCLUDE_ASM("asm/nonmatchings/game/t_24DDB8", CFunc_DebugLine);

INCLUDE_ASM("asm/nonmatchings/game/t_24DDB8", CFunc_GetCurrentGeomStats);

extern "C" int CFunc_GetCurrentParticleTimes(void) {
    return 1;
}

extern "C" int CFunc_GetCurrentAnimTimes(void) {
    return 1;
}

INCLUDE_ASM("asm/nonmatchings/game/t_24DDB8", CFunc_GetMetrics);

INCLUDE_ASM("asm/nonmatchings/game/t_24DDB8", func_0024ED80);

INCLUDE_ASM("asm/nonmatchings/game/t_24DDB8", CFunc_SetClippingDistances);

INCLUDE_ASM("asm/nonmatchings/game/t_24DDB8", CFunc_VCWibblePlayFromKeyframe);

INCLUDE_ASM("asm/nonmatchings/game/t_24DDB8", CFunc_SetUVWibbleParams);

INCLUDE_ASM("asm/nonmatchings/game/t_24DDB8", CFunc_EnableExplicitUVWibble);

INCLUDE_ASM("asm/nonmatchings/game/t_24DDB8", CFunc_DisableExplicitUVWibble);

INCLUDE_ASM("asm/nonmatchings/game/t_24DDB8", CFunc_SetUVWibbleOffsets);

INCLUDE_ASM("asm/nonmatchings/game/t_24DDB8", CFunc_ResetTextureAnim);

INCLUDE_ASM("asm/nonmatchings/game/t_24DDB8", CFunc_StartTextureAnim);

INCLUDE_ASM("asm/nonmatchings/game/t_24DDB8", CFunc_StopTextureAnim);

INCLUDE_ASM("asm/nonmatchings/game/t_24DDB8", CFunc_ToggleRenderMetrics);

extern "C" int CFunc_SetOutlineShaderColor(void) {
    return 0;
}

extern "C" int CFunc_SetOutlineShaderParams(void) {
    return 0;
}

extern "C" int CFunc_SetShaderOverride(void) {
    return 0;
}

extern "C" int CFunc_SetShadowRenderingFlags(void) {
    return 0;
}

extern "C" int CFunc_SetShadowProjectionTexture(void) {
    return 0;
}

extern "C" int CFunc_ToggleRenderMode(void) {
    func_0014F178();
    return 1;
}

INCLUDE_ASM("asm/nonmatchings/game/t_24DDB8", CFunc_SetRenderMode);

INCLUDE_ASM("asm/nonmatchings/game/t_24DDB8", CFunc_SetWireframeMode);

INCLUDE_ASM("asm/nonmatchings/game/t_24DDB8", CFunc_DebugRenderIgnore);

INCLUDE_ASM("asm/nonmatchings/game/t_24DDB8", func_0024F4B8);

INCLUDE_ASM("asm/nonmatchings/game/t_24DDB8", func_0024F500);

INCLUDE_ASM("asm/nonmatchings/game/t_24DDB8", CFunc_CompressVC);

INCLUDE_ASM("asm/nonmatchings/game/t_24DDB8", func_0024FAD8);
