#include "common.h"

extern "C" {
extern s32 D_00368A38[] __attribute__((section(".sdata")));
extern s32 D_00371FF0;
extern s32 D_003720D0;
s32 func_00118F20(s32, int, int, int);
s32 func_002D58B0(s32, int, int);
int func_002D5B48(s32, int);
}

extern "C" s32 CFunc_SetNetworkPreference(void) {
    return 0;
}

GP_DATA(D_00371FF0);
extern "C" s32 CFunc_InitAtoms(void) {
    if (D_00371FF0 == 0) {
        D_00371FF0 = func_002D58B0(func_00118F20(D_00368A38[0], 0x1C, 1, 0), 2, 0);
    }
    return 1;
}

extern "C" s32 CFunc_DeinitAtoms(void) {
    if (D_00371FF0 != 0) {
        func_002D5B48(D_00371FF0, 3);
    }
    return 1;
}

INCLUDE_ASM("asm/nonmatchings/game/t_2BCDA8", CFunc_DeRegisterAtoms);

INCLUDE_ASM("asm/nonmatchings/game/t_2BCDA8", CFunc_RegisterAtoms);

INCLUDE_ASM("asm/nonmatchings/game/t_2BCDA8", CFunc_UpdateAtoms);

INCLUDE_ASM("asm/nonmatchings/game/t_2BCDA8", CFunc_ClearGlobalTags);

INCLUDE_ASM("asm/nonmatchings/game/t_2BCDA8", CFunc_SetGlobalTags);

INCLUDE_ASM("asm/nonmatchings/game/t_2BCDA8", CFunc_GetGlobalTags);

INCLUDE_ASM("asm/nonmatchings/game/t_2BCDA8", CFunc_PushGlobalTags);

INCLUDE_ASM("asm/nonmatchings/game/t_2BCDA8", CFunc_PopGlobalTags);

INCLUDE_ASM("asm/nonmatchings/game/t_2BCDA8", CFunc_GlobalTagExists);

extern "C" s32 CFunc_OutputGlobalTags(void) {
    return 1;
}

INCLUDE_ASM("asm/nonmatchings/game/t_2BCDA8", func_002BDC48);

INCLUDE_ASM("asm/nonmatchings/game/t_2BCDA8", func_002BDCD0);

INCLUDE_ASM("asm/nonmatchings/game/t_2BCDA8", func_002BDEA8);

INCLUDE_ASM("asm/nonmatchings/game/t_2BCDA8", CFunc_AddCrowdModelCam);

GP_DATA(D_003720D0);
extern "C" s32 CFunc_ClearCrowdModelCams(void) {
    D_003720D0 = 0;
    return 1;
}

INCLUDE_ASM("asm/nonmatchings/game/t_2BCDA8", func_002BE288);

extern "C" s32 CFunc_UpdateGuitarFuncs(void) {
    return 1;
}

extern "C" s32 CFunc_DumpOpen(void) {
    return 1;
}

extern "C" s32 CFunc_DumpWrite(void) {
    return 1;
}

extern "C" s32 CFunc_DumpClose(void) {
    return 1;
}

INCLUDE_ASM("asm/nonmatchings/game/t_2BCDA8", CFunc_GetActiveControllers);

INCLUDE_ASM("asm/nonmatchings/game/t_2BCDA8", CFunc_HideObjectByType);

INCLUDE_ASM("asm/nonmatchings/game/t_2BCDA8", CFunc_DoScreenElementMorphList);

INCLUDE_ASM("asm/nonmatchings/game/t_2BCDA8", CFunc_SetNoteMappings);

INCLUDE_ASM("asm/nonmatchings/game/t_2BCDA8", CFunc_GetNoteMapping);

INCLUDE_ASM("asm/nonmatchings/game/t_2BCDA8", CFunc_ClearNoteMappings);
