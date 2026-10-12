#include "common.h"

struct S001B49A0 {
    char pad0[0x6];
    s16 unk6;
    char pad8[0x4];
    s32 unkC;
};

extern "C" {
extern s32 D_0036C948;
extern s32 D_0036C94C;
extern s32 D_0036C950;
extern s32 D_0036C954;
extern s32 D_0036C958;
extern s32 D_0036C95C;
extern s32 D_0036C960;
extern s32 D_0036C964;
extern s32 D_0036CA4C;
}

INCLUDE_ASM("asm/nonmatchings/game/t_1B4190", func_001B4190);

INCLUDE_ASM("asm/nonmatchings/game/t_1B4190", func_001B42D8);

extern "C" void func_001B4330(void) {
    D_0036C948 = 0;
    D_0036C94C = 0;
    D_0036C950 = 0;
    D_0036C958 = 0;
    D_0036C954 = 0;
    D_0036C960 = 0;
    D_0036C95C = 0;
    D_0036C964 = 0;
}

INCLUDE_ASM("asm/nonmatchings/game/t_1B4190", func_001B4358);

INCLUDE_ASM("asm/nonmatchings/game/t_1B4190", func_001B4468);

INCLUDE_ASM("asm/nonmatchings/game/t_1B4190", func_001B46B0);

INCLUDE_ASM("asm/nonmatchings/game/t_1B4190", func_001B46C0);

INCLUDE_ASM("asm/nonmatchings/game/t_1B4190", func_001B47B8);

INCLUDE_ASM("asm/nonmatchings/game/t_1B4190", func_001B4808);

INCLUDE_ASM("asm/nonmatchings/game/t_1B4190", func_001B4828);

INCLUDE_ASM("asm/nonmatchings/game/t_1B4190", func_001B48D8);

extern "C" s32 func_001B49A0(S001B49A0* p) {
    s32 v = p->unk6;
    return v & 1;
}

extern "C" void func_001B49B0(S001B49A0* p, s32 v) {
    p->unkC += v;
}

INCLUDE_ASM("asm/nonmatchings/game/t_1B4190", func_001B49C0);

extern "C" void func_001B4A88(s32 v) {
    D_0036CA4C = v;
}

extern "C" s32 func_001B4A90(void) {
    return D_0036CA4C;
}

INCLUDE_ASM("asm/nonmatchings/game/t_1B4190", func_001B4A98);

INCLUDE_ASM("asm/nonmatchings/game/t_1B4190", func_001B4E70);

INCLUDE_ASM("asm/nonmatchings/game/t_1B4190", func_001B5240);

INCLUDE_ASM("asm/nonmatchings/game/t_1B4190", func_001B58A8);

INCLUDE_ASM("asm/nonmatchings/game/t_1B4190", func_001B58B0);

INCLUDE_ASM("asm/nonmatchings/game/t_1B4190", func_001B5BD0);

INCLUDE_ASM("asm/nonmatchings/game/t_1B4190", func_001B5BF8);

INCLUDE_ASM("asm/nonmatchings/game/t_1B4190", func_001B5C20);

INCLUDE_ASM("asm/nonmatchings/game/t_1B4190", func_001B5C50);

INCLUDE_ASM("asm/nonmatchings/game/t_1B4190", func_001B5C80);

INCLUDE_ASM("asm/nonmatchings/game/t_1B4190", func_001B5CB0);

INCLUDE_ASM("asm/nonmatchings/game/t_1B4190", func_001B5DD8);
