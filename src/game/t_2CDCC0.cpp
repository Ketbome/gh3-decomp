#include "common.h"

extern "C" {
void func_002CDD30(char *);
s32 func_00289C88(s32, s32);
char *func_00289C80(s32);
int func_00289CF8(s32);
}

INCLUDE_ASM("asm/nonmatchings/game/t_2CDCC0", func_002CDCC0);

INCLUDE_ASM("asm/nonmatchings/game/t_2CDCC0", func_002CDCF8);

INCLUDE_ASM("asm/nonmatchings/game/t_2CDCC0", func_002CDD30);

extern "C" s32 CFunc_check_for_star_power_CFunc_Setup(int arg0, s32 arg1) {
    func_00289C88(arg1, 0x44);
    func_002CDD30(func_00289C80(arg1));
    return 1;
}

extern "C" s32 CFunc_check_for_star_power_CFunc_Cleanup(int arg0, s32 arg1) {
    func_00289CF8(arg1);
    return 1;
}

INCLUDE_ASM("asm/nonmatchings/game/t_2CDCC0", func_002CDDD0);

INCLUDE_ASM("asm/nonmatchings/game/t_2CDCC0", func_002CDF70);

INCLUDE_ASM("asm/nonmatchings/game/t_2CDCC0", CFunc_check_for_star_power_CFunc);

extern "C" s32 CFunc_GuitarEvent_Note_Window_Open_CFunc_Setup(int arg0, s32 arg1) {
    func_00289C88(arg1, 0x8);
    *(s32 *)(func_00289C80(arg1) + 0x0) = 0;
    return 1;
}

extern "C" s32 CFunc_GuitarEvent_Note_Window_Open_CFunc_Cleanup(int arg0, s32 arg1) {
    func_00289CF8(arg1);
    return 1;
}

INCLUDE_ASM("asm/nonmatchings/game/t_2CDCC0", CFunc_GuitarEvent_Note_Window_Open_CFunc);

extern "C" s32 CFunc_strum_iterator_CFunc_Setup(int arg0, s32 arg1) {
    func_00289C88(arg1, 0x28);
    *(s32 *)(func_00289C80(arg1) + 0x24) = 0;
    return 1;
}

extern "C" s32 CFunc_strum_iterator_CFunc_Cleanup(int arg0, s32 arg1) {
    func_00289CF8(arg1);
    return 1;
}

INCLUDE_ASM("asm/nonmatchings/game/t_2CDCC0", CFunc_strum_iterator_CFunc);

INCLUDE_ASM("asm/nonmatchings/game/t_2CDCC0", CFunc_wait_for_correct_frame_cfunc);

extern "C" s32 CFunc_rock_meter_star_power_on_CFunc_Setup(int arg0, s32 arg1) {
    func_00289C88(arg1, 0x20);
    *(s32 *)(func_00289C80(arg1) + 0x1C) = 0;
    return 1;
}

extern "C" s32 CFunc_rock_meter_star_power_on_CFunc_Cleanup(int arg0, s32 arg1) {
    func_00289CF8(arg1);
    return 1;
}

INCLUDE_ASM("asm/nonmatchings/game/t_2CDCC0", CFunc_rock_meter_star_power_on_CFunc);
