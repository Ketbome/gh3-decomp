#include "common.h"

extern "C" {
extern s32 D_00373008[] __attribute__((section(".sdata")));
}

INCLUDE_ASM("asm/nonmatchings/game/t_2AF598", CFunc_GetHeldPattern);

INCLUDE_ASM("asm/nonmatchings/game/t_2AF598", func_002AF698);

INCLUDE_ASM("asm/nonmatchings/game/t_2AF598", CFunc_GuitarGetAnalogueInfo);

INCLUDE_ASM("asm/nonmatchings/game/t_2AF598", CFunc_GuitarControllerMake);

extern "C" s32 CFunc_StartWildcardSearch(void) {
    return 0;
}

extern "C" s32 CFunc_GetWildcardFile(void) {
    return 0;
}

extern "C" s32 CFunc_EndWildcardSearch(void) {
    return 0;
}

INCLUDE_ASM("asm/nonmatchings/game/t_2AF598", CFunc_InputArrayCreate);

INCLUDE_ASM("asm/nonmatchings/game/t_2AF598", func_002AFE38);

INCLUDE_ASM("asm/nonmatchings/game/t_2AF598", CFunc_InputArrayAddElement);

INCLUDE_ASM("asm/nonmatchings/game/t_2AF598", CFunc_SongArraySet);

extern "C" s32 func_002B0370(void) {
    s32 var_4;

    var_4 = 0;
    if ((D_00373008[0] == 0xF8B928FD /* p2_career */) || (D_00373008[0] == 0xA572DCB2 /* p2_coop */)) {
        var_4 = 1;
    }
    return var_4;
}

extern "C" s32 func_002B03A8(void) {
    s32 var_4;

    var_4 = 0;
    if ((D_00373008[0] == 0x4BA430F2 /* p2_faceoff */) || (D_00373008[0] == 0xC3FA2BF0 /* p2_pro_faceoff */)) {
        var_4 = 1;
    }
    return var_4;
}

INCLUDE_ASM("asm/nonmatchings/game/t_2AF598", CFunc_UpdateScoreFastInit);
