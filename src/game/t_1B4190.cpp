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
extern s32 D_0037329C;
extern s32 D_00373338;
extern s32 D_00373324;
extern s32 D_00373294;
void func_001B58B0(s32);
void func_0019BE48(s32);
extern s32 D_00373288;
extern s32 D_00373298;
extern u32* D_003732E0;
extern s32 D_00373284;
void func_001BD128(void);
void func_001BB680(void*, s32, s32, f32, f32, f32, f32, f32, f32);
void func_001BCD88(void*, f32, f32, f32, f32);
extern s32 D_0036CAA4;
extern s32 D_0036CA50;
extern s32 D_0036CA54;
void func_001B61D0(void);
void func_001B7898(void*);
void func_001B95F0(void*);
void func_001B6620(void);
}

INCLUDE_ASM("asm/nonmatchings/game/t_1B4190", func_001B4190);

INCLUDE_ASM("asm/nonmatchings/game/t_1B4190", func_001B42D8);

GP_DATA(D_0036C948);
GP_DATA(D_0036C94C);
GP_DATA(D_0036C950);
GP_DATA(D_0036C958);
GP_DATA(D_0036C954);
GP_DATA(D_0036C960);
GP_DATA(D_0036C95C);
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

extern "C" void func_001B47B8(s32 a) {
    s32 n = D_00373288;
    s32 m = D_00373298;
    u32* q = D_003732E0;
    q[0] = (a << 15) | n | q[0];
    n = n * m;
    q[3] = n;
    D_00373284 += n + 1;
}

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

extern "C" void func_001B5BD0(void) {
    func_001B58B0(D_0037329C);
}

extern "C" void func_001B5BF8(void) {
    func_001B58B0(D_00373338);
}

extern "C" void func_001B5C20(void) {
    s32 x = D_0037329C;
    if (D_00373294 != x) {
        func_0019BE48(x);
    }
}

extern "C" void func_001B5C50(void) {
    s32 x = D_00373338;
    if (D_00373294 != x) {
        func_0019BE48(x);
    }
}

extern "C" void func_001B5C80(void) {
    s32 x = D_00373324;
    if (D_00373294 != x) {
        func_0019BE48(x);
    }
}

GP_DATA(D_0036CA50);
INCLUDE_ASM("asm/nonmatchings/game/t_1B4190", func_001B5CB0);

INCLUDE_ASM("asm/nonmatchings/game/t_1B4190", func_001B5DD8);
