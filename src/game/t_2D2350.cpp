#include "common.h"

extern "C" {
extern s32 D_0036CBF4[] __attribute__((section(".sdata")));
extern f32 D_003721D8;
f32 func_00275DE0(int, int);
s32 func_00275F08(int, int);
int func_002B4CB0(int, int);
int func_002D2110(int);
}

extern "C" void func_002D2350(void) {
    if (func_00275F08(0x0AA160D8 /* replay_suspend */, 0) != 1) {
        func_002D2110(0x26C80B0D /* Replay */);
    }
}

INCLUDE_ASM("asm/nonmatchings/game/t_2D2350", func_002D2390);

INCLUDE_ASM("asm/nonmatchings/game/t_2D2350", func_002D2758);

INCLUDE_ASM("asm/nonmatchings/game/t_2D2350", CFunc_script_callback_script_cfunc);

INCLUDE_ASM("asm/nonmatchings/game/t_2D2350", func_002D31E0);

INCLUDE_ASM("asm/nonmatchings/game/t_2D2350", CFunc_update_guitar_volume_cfunc);

INCLUDE_ASM("asm/nonmatchings/game/t_2D2350", CFunc_CheckButtonsBoss);

GP_DATA(D_003721D8);
extern "C" s32 CFunc_CheckBossCutoff(void) {
    f32 temp_f1;

    if (D_003721D8 > 0.0f) {
        temp_f1 = D_003721D8 - func_00275DE0(0x6D735468 /* current_deltatime */, 1);
        D_003721D8 = temp_f1;
        if (temp_f1 <= 0.0f) {
            func_002B4CB0(0xE5E9AAE8 /* boss_pattern */, 0);
        }
    }
    return 1;
}

INCLUDE_ASM("asm/nonmatchings/game/t_2D2350", CFunc_StarPowerOn);

extern "C" s32 CFunc_ResetWhammyCachedRows(void) {
    D_0036CBF4[0] = 0;
    return 1;
}

INCLUDE_ASM("asm/nonmatchings/game/t_2D2350", CFunc_proj_gh3c_build_gs_available_guitar_array_last_loop);

INCLUDE_ASM("asm/nonmatchings/game/t_2D2350", CFunc_select_guitar_build_brand_array);
