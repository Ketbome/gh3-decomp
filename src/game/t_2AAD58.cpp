#include "common.h"

extern "C" {
extern s32 D_00371EF8;
extern s32 D_003AC7C0[];
}

INCLUDE_ASM("asm/nonmatchings/game/t_2AAD58", CFunc_LightShow_BeginProcessBlock);

GP_DATA(D_00371EF8);
extern "C" s32 CFunc_LightShow_EndProcessBlock(void) {
    D_00371EF8 = 0;
    D_003AC7C0[0] = 0;
    return 1;
}

INCLUDE_ASM("asm/nonmatchings/game/t_2AAD58", CFunc_LightShow_PassEvent);

INCLUDE_ASM("asm/nonmatchings/game/t_2AAD58", CFunc_LightShow_WaitForNextEvent);

INCLUDE_ASM("asm/nonmatchings/game/t_2AAD58", func_002AB738);

INCLUDE_ASM("asm/nonmatchings/game/t_2AAD58", func_002AB848);

INCLUDE_ASM("asm/nonmatchings/game/t_2AAD58", func_002ABB00);

INCLUDE_ASM("asm/nonmatchings/game/t_2AAD58", func_002ABC18);

INCLUDE_ASM("asm/nonmatchings/game/t_2AAD58", func_002ABD58);

INCLUDE_ASM("asm/nonmatchings/game/t_2AAD58", CFunc_LightShow_SetActive);

INCLUDE_ASM("asm/nonmatchings/game/t_2AAD58", CFunc_LightShow_SetProcessors);

INCLUDE_ASM("asm/nonmatchings/game/t_2AAD58", CFunc_LightShow_SetMapping);

INCLUDE_ASM("asm/nonmatchings/game/t_2AAD58", CFunc_LightShow_SetParams);

INCLUDE_ASM("asm/nonmatchings/game/t_2AAD58", CFunc_LightShow_GetParams);

INCLUDE_ASM("asm/nonmatchings/game/t_2AAD58", CFunc_LightShow_Update);

INCLUDE_ASM("asm/nonmatchings/game/t_2AAD58", func_002ACA48);
