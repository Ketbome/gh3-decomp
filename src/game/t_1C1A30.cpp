#include "common.h"

struct N0 {
    N0* unk0;
};

struct S001C2670 {
    char pad0[0x8];
    f32 unk8;
    f32 unkC;
    s32 unk10;
    char pad14[0x20];
    N0* unk34;
};

struct S001C3538 {
    char pad0[0x8];
    u8 unk8;
    char pad9[0x7];
    u64 unk10_0 : 26;
    u64 unk10_26 : 4;
    u64 unk10_30 : 4;
    u64 unk10_34 : 17;
    u64 unk10_51 : 4;
    u64 unk10_55 : 9;
};

INCLUDE_ASM("asm/nonmatchings/game/t_1C1A30", func_001C1A30);

INCLUDE_ASM("asm/nonmatchings/game/t_1C1A30", func_001C1DE8);

INCLUDE_ASM("asm/nonmatchings/game/t_1C1A30", func_001C1E70);

INCLUDE_ASM("asm/nonmatchings/game/t_1C1A30", func_001C2508);

INCLUDE_ASM("asm/nonmatchings/game/t_1C1A30", func_001C2550);

INCLUDE_ASM("asm/nonmatchings/game/t_1C1A30", func_001C25A0);

INCLUDE_ASM("asm/nonmatchings/game/t_1C1A30", func_001C25F8);

extern "C" void func_001C2670(S001C2670* p) {
    p->unk34 = 0;
}

extern "C" void func_001C2678(void) {
}

INCLUDE_ASM("asm/nonmatchings/game/t_1C1A30", func_001C2680);

extern "C" void func_001C2C18(void) {
}

extern "C" void func_001C2C20(S001C2670* p, N0* n) {
    n->unk0 = p->unk34;
    p->unk34 = n;
}

INCLUDE_ASM("asm/nonmatchings/game/t_1C1A30", func_001C2C30);

INCLUDE_ASM("asm/nonmatchings/game/t_1C1A30", func_001C2C88);

extern "C" void func_001C2CB0(S001C2670* p, f32 a, f32 b) {
    p->unk8 = a;
    p->unkC = b;
}

extern "C" void func_001C2CC0(S001C2670* p, s32 v) {
    p->unk10 = v;
}

extern "C" s32 func_001C2CC8(S001C2670* p) {
    return p->unk10;
}

INCLUDE_ASM("asm/nonmatchings/game/t_1C1A30", func_001C2CD0);

INCLUDE_ASM("asm/nonmatchings/game/t_1C1A30", func_001C2CD8);

INCLUDE_ASM("asm/nonmatchings/game/t_1C1A30", func_001C2D08);

INCLUDE_ASM("asm/nonmatchings/game/t_1C1A30", func_001C2D28);

INCLUDE_ASM("asm/nonmatchings/game/t_1C1A30", func_001C3150);

INCLUDE_ASM("asm/nonmatchings/game/t_1C1A30", func_001C3240);

INCLUDE_ASM("asm/nonmatchings/game/t_1C1A30", func_001C3278);

INCLUDE_ASM("asm/nonmatchings/game/t_1C1A30", func_001C32A0);

INCLUDE_ASM("asm/nonmatchings/game/t_1C1A30", func_001C3348);

extern "C" u16 func_001C3538(S001C3538* p) {
    return 1 << (u16)p->unk10_26;
}

extern "C" u16 func_001C3558(S001C3538* p) {
    return 1 << (u16)p->unk10_30;
}

INCLUDE_ASM("asm/nonmatchings/game/t_1C1A30", func_001C3578);

extern "C" s32 func_001C35E0(S001C3538* p) {
    u32 v = p->unk10_51;

    switch (v) {
    case 0:
        return 32;
    case 1:
        return 24;
    case 2:
        return 16;
    }
    return 0;
}

extern "C" u8 func_001C3638(S001C3538* p) {
    return p->unk8 + 1;
}

INCLUDE_ASM("asm/nonmatchings/game/t_1C1A30", func_001C3648);

INCLUDE_ASM("asm/nonmatchings/game/t_1C1A30", func_001C3718);

INCLUDE_ASM("asm/nonmatchings/game/t_1C1A30", func_001C3888);

extern "C" s32 func_001C3890(void) {
    return 1;
}

INCLUDE_ASM("asm/nonmatchings/game/t_1C1A30", func_001C3898);

INCLUDE_ASM("asm/nonmatchings/game/t_1C1A30", func_001C3960);
