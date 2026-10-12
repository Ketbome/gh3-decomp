#include "common.h"

struct S2CC510 {
    char pad0[0x8];
    f32 unk8;
};

extern "C" {
S2CC510 *func_0027AF38(int, int, int);
int func_00289CF8(s32);
}

INCLUDE_ASM("asm/nonmatchings/game/t_2CBC10", func_002CBC10);

extern "C" s32 func_002CBC50(int arg0, s32 arg1) {
    func_00289CF8(arg1);
    return 1;
}

INCLUDE_ASM("asm/nonmatchings/game/t_2CBC10", func_002CBC70);

extern "C" void func_002CC510(int arg0, int arg1, f32 arg2) {
    func_0027AF38(arg0, arg1, 0)->unk8 = arg2;
}

INCLUDE_ASM("asm/nonmatchings/game/t_2CBC10", func_002CC540);

INCLUDE_ASM("asm/nonmatchings/game/t_2CBC10", func_002CC570);

INCLUDE_ASM("asm/nonmatchings/game/t_2CBC10", func_002CC5A0);

INCLUDE_ASM("asm/nonmatchings/game/t_2CBC10", func_002CC768);

extern "C" s32 func_002CC7A8(int arg0, s32 arg1) {
    func_00289CF8(arg1);
    return 1;
}

INCLUDE_ASM("asm/nonmatchings/game/t_2CBC10", func_002CC7C8);

INCLUDE_ASM("asm/nonmatchings/game/t_2CBC10", func_002CC880);

INCLUDE_ASM("asm/nonmatchings/game/t_2CBC10", func_002CCFA0);

INCLUDE_ASM("asm/nonmatchings/game/t_2CBC10", func_002CD158);

extern "C" s32 func_002CD198(int arg0, s32 arg1) {
    func_00289CF8(arg1);
    return 1;
}

INCLUDE_ASM("asm/nonmatchings/game/t_2CBC10", func_002CD1B8);

INCLUDE_ASM("asm/nonmatchings/game/t_2CBC10", func_002CDB28);

extern "C" s32 func_002CDB68(int arg0, s32 arg1) {
    func_00289CF8(arg1);
    return 1;
}

INCLUDE_ASM("asm/nonmatchings/game/t_2CBC10", func_002CDB88);
