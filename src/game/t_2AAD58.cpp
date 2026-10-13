#include "common.h"

extern "C" {
void func_0027AC90(int);
void func_0027ABB0(int, int);
int func_0027DF00(int, int);
extern int D_00371EEC;
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

extern "C" s32 CFunc_LightShow_SetMapping(int arg0) {
    func_0027AC90(D_00371EEC);
    if ((func_0027DF00(arg0, 0x1A4E0EF9) ^ 1) != 0 && arg0 != 0) {
        func_0027ABB0(D_00371EEC, arg0);
    }
    return 1;
}

INCLUDE_ASM("asm/nonmatchings/game/t_2AAD58", CFunc_LightShow_SetParams);

INCLUDE_ASM("asm/nonmatchings/game/t_2AAD58", CFunc_LightShow_GetParams);

INCLUDE_ASM("asm/nonmatchings/game/t_2AAD58", CFunc_LightShow_Update);

INCLUDE_ASM("asm/nonmatchings/game/t_2AAD58", func_002ACA48);
