#include "common.h"

extern "C" {
extern s32 D_0036C378[] __attribute__((section(".sdata")));
extern s32 D_0036CA50;
extern s32 D_0036CA5C;
extern s32 D_0036CA80;
extern s32 D_00370E40;
extern int D_0038C9A0[];
extern int D_0038C9F0[];
int func_0019EE38(int, int, int, int);
int func_001A9E88(void *);
int func_00289CF8(s32);
}

INCLUDE_ASM("asm/nonmatchings/game/t_2C9AC0", CFunc_SetLastGuitarVolume);

INCLUDE_ASM("asm/nonmatchings/game/t_2C9AC0", CFunc_UpdateNixie);

INCLUDE_ASM("asm/nonmatchings/game/t_2C9AC0", CFunc_KillPulsateStarPowerBulbs);

extern "C" s32 CFunc_ClearSceneGraph(void) {
    func_001A9E88(D_0038C9A0);
    func_001A9E88(D_0038C9F0);
    return 1;
}

extern "C" s32 CFunc_ShowStencilShadow(void) {
    D_0036CA50 = 1;
    return 1;
}

INCLUDE_ASM("asm/nonmatchings/game/t_2C9AC0", CFunc_HideStencilShadow);

extern "C" s32 CFunc_SetMasterBloom(void) {
    D_0036CA80 = 1;
    return 1;
}

INCLUDE_ASM("asm/nonmatchings/game/t_2C9AC0", CFunc_ClearMasterBloom);

extern "C" s32 CFunc_ShowDOF(void) {
    D_0036CA5C = 1;
    return 1;
}

INCLUDE_ASM("asm/nonmatchings/game/t_2C9AC0", CFunc_HideDOF);

extern "C" s32 CFunc_MoviePlayerAllowController2(void) {
    D_00370E40 = 1;
    return 1;
}

extern "C" s32 CFunc_BlankScreen(void) {
    func_0019EE38(0, 0, 0, 0);
    D_0036C378[0] = 2;
    return 1;
}

INCLUDE_ASM("asm/nonmatchings/game/t_2C9AC0", CFunc_StarPowerFastTest_Initialise);

extern "C" s32 CFunc_StarPowerFastTest_Cleanup(int arg0, s32 arg1) {
    func_00289CF8(arg1);
    return 1;
}

INCLUDE_ASM("asm/nonmatchings/game/t_2C9AC0", CFunc_StarPowerFastTest);

INCLUDE_ASM("asm/nonmatchings/game/t_2C9AC0", CFunc_GuitarEvent_HitNotes_CFunc);

INCLUDE_ASM("asm/nonmatchings/game/t_2C9AC0", CFunc_handle_hit_note_CFunc);

INCLUDE_ASM("asm/nonmatchings/game/t_2C9AC0", CFunc_Increment);

INCLUDE_ASM("asm/nonmatchings/game/t_2C9AC0", func_002CA618);

INCLUDE_ASM("asm/nonmatchings/game/t_2C9AC0", func_002CA6E8);

INCLUDE_ASM("asm/nonmatchings/game/t_2C9AC0", func_002CA818);

INCLUDE_ASM("asm/nonmatchings/game/t_2C9AC0", func_002CA888);

INCLUDE_ASM("asm/nonmatchings/game/t_2C9AC0", CFunc_fretbar_iterator_CFunc_Setup);

extern "C" s32 CFunc_fretbar_iterator_CFunc_Cleanup(int arg0, s32 arg1) {
    func_00289CF8(arg1);
    return 1;
}

INCLUDE_ASM("asm/nonmatchings/game/t_2C9AC0", CFunc_fretbar_iterator_CFunc);

INCLUDE_ASM("asm/nonmatchings/game/t_2C9AC0", CFunc_fretbar_update_hammer_on_tolerance_CFunc_Setup);

extern "C" s32 CFunc_fretbar_update_hammer_on_tolerance_CFunc_Cleanup(int arg0, s32 arg1) {
    func_00289CF8(arg1);
    return 1;
}

INCLUDE_ASM("asm/nonmatchings/game/t_2C9AC0", CFunc_fretbar_update_hammer_on_tolerance_CFunc);

INCLUDE_ASM("asm/nonmatchings/game/t_2C9AC0", CFunc_fretbar_update_tempo_CFunc_Setup);

extern "C" s32 CFunc_fretbar_update_tempo_CFunc_Cleanup(int arg0, s32 arg1) {
    func_00289CF8(arg1);
    return 1;
}

INCLUDE_ASM("asm/nonmatchings/game/t_2C9AC0", CFunc_fretbar_update_tempo_CFunc);
