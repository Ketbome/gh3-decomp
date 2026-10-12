#include "common.h"

extern "C" {
int func_00289CF8(s32);
}

INCLUDE_ASM("asm/nonmatchings/game/t_2CDCC0", func_002CDCC0);

INCLUDE_ASM("asm/nonmatchings/game/t_2CDCC0", func_002CDCF8);

INCLUDE_ASM("asm/nonmatchings/game/t_2CDCC0", func_002CDD30);

INCLUDE_ASM("asm/nonmatchings/game/t_2CDCC0", CFunc_check_for_star_power_CFunc_Setup);

extern "C" s32 CFunc_check_for_star_power_CFunc_Cleanup(int arg0, s32 arg1) {
    func_00289CF8(arg1);
    return 1;
}

INCLUDE_ASM("asm/nonmatchings/game/t_2CDCC0", func_002CDDD0);

INCLUDE_ASM("asm/nonmatchings/game/t_2CDCC0", func_002CDF70);

INCLUDE_ASM("asm/nonmatchings/game/t_2CDCC0", CFunc_check_for_star_power_CFunc);

INCLUDE_ASM("asm/nonmatchings/game/t_2CDCC0", CFunc_GuitarEvent_Note_Window_Open_CFunc_Setup);

extern "C" s32 CFunc_GuitarEvent_Note_Window_Open_CFunc_Cleanup(int arg0, s32 arg1) {
    func_00289CF8(arg1);
    return 1;
}

INCLUDE_ASM("asm/nonmatchings/game/t_2CDCC0", CFunc_GuitarEvent_Note_Window_Open_CFunc);

INCLUDE_ASM("asm/nonmatchings/game/t_2CDCC0", CFunc_strum_iterator_CFunc_Setup);

extern "C" s32 CFunc_strum_iterator_CFunc_Cleanup(int arg0, s32 arg1) {
    func_00289CF8(arg1);
    return 1;
}

INCLUDE_ASM("asm/nonmatchings/game/t_2CDCC0", CFunc_strum_iterator_CFunc);

INCLUDE_ASM("asm/nonmatchings/game/t_2CDCC0", CFunc_wait_for_correct_frame_cfunc);

INCLUDE_ASM("asm/nonmatchings/game/t_2CDCC0", CFunc_rock_meter_star_power_on_CFunc_Setup);

extern "C" s32 CFunc_rock_meter_star_power_on_CFunc_Cleanup(int arg0, s32 arg1) {
    func_00289CF8(arg1);
    return 1;
}

INCLUDE_ASM("asm/nonmatchings/game/t_2CDCC0", CFunc_rock_meter_star_power_on_CFunc);
