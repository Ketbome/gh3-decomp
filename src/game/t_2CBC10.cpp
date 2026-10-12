#include "common.h"

struct S2CC510 {
    char pad0[0x8];
    f32 unk8;
};

extern "C" {
S2CC510 *func_0027AF38(int, int, int);
int func_00289CF8(s32);
}

INCLUDE_ASM("asm/nonmatchings/game/t_2CBC10", CFunc_FretFingers_iterator_CFunc_Setup);

extern "C" s32 CFunc_FretFingers_iterator_CFunc_Cleanup(int arg0, s32 arg1) {
    func_00289CF8(arg1);
    return 1;
}

INCLUDE_ASM("asm/nonmatchings/game/t_2CBC10", CFunc_FretFingers_iterator_CFunc);

extern "C" void func_002CC510(int arg0, int arg1, f32 arg2) {
    func_0027AF38(arg0, arg1, 0)->unk8 = arg2;
}

INCLUDE_ASM("asm/nonmatchings/game/t_2CBC10", func_002CC540);

INCLUDE_ASM("asm/nonmatchings/game/t_2CBC10", func_002CC570);

INCLUDE_ASM("asm/nonmatchings/game/t_2CBC10", func_002CC5A0);

INCLUDE_ASM("asm/nonmatchings/game/t_2CBC10", CFunc_Drum_iterator_CFunc_Setup);

extern "C" s32 CFunc_Drum_iterator_CFunc_Cleanup(int arg0, s32 arg1) {
    func_00289CF8(arg1);
    return 1;
}

INCLUDE_ASM("asm/nonmatchings/game/t_2CBC10", func_002CC7C8);

INCLUDE_ASM("asm/nonmatchings/game/t_2CBC10", CFunc_Drum_iterator_CFunc);

INCLUDE_ASM("asm/nonmatchings/game/t_2CBC10", CFunc_compute_desired_drummer_twist);

INCLUDE_ASM("asm/nonmatchings/game/t_2CBC10", CFunc_gem_array_stepper_CFunc_Setup);

extern "C" s32 CFunc_gem_array_stepper_CFunc_Cleanup(int arg0, s32 arg1) {
    func_00289CF8(arg1);
    return 1;
}

INCLUDE_ASM("asm/nonmatchings/game/t_2CBC10", CFunc_gem_array_stepper_CFunc);

INCLUDE_ASM("asm/nonmatchings/game/t_2CBC10", CFunc_kill_object_later_CFunc_Setup);

extern "C" s32 CFunc_kill_object_later_CFunc_Cleanup(int arg0, s32 arg1) {
    func_00289CF8(arg1);
    return 1;
}

INCLUDE_ASM("asm/nonmatchings/game/t_2CBC10", CFunc_kill_object_later_CFunc);
