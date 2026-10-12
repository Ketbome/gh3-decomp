#include "common.h"

struct S1E6920_L {
    S1E6920_L* unk0;
    S1E6920_L* unk4;
};

struct S1E6920 {
    s32 unk0;
    S1E6920_L unk4;
};

struct S1E5E90_S {
    char pad0[0x60];
    s32 unk60;
    s32 unk64;
    s32 unk68;
};

struct S1E5E90 {
    char pad0[0x10];
    S1E5E90_S unk10;
};

extern "C" {
extern s32 D_00371038;
extern s32 D_00371238;
extern s32 D_00370FB8;
extern void (*D_0036DA4C)(void);
s32 func_001E65A8(void);
s32 func_001E65B0(void);
s32 func_001E65B8(void);
void func_001E5E90(s32 a, s32 b);
extern S1E6920 D_0038ED60;
extern u32 D_00372DC0;
extern s32 D_00372DB8;
extern S1E5E90 D_0038EC50;
void func_001E64A0(void);
void func_001E64B8(void);
void func_001E64D0(void);
s32 func_001E64E8(void);
s32 func_001E6510(void);
s32 func_001E6538(void);
void func_001E6560(void);
void func_001E6578(void);
void func_001E6590(void);
}

INCLUDE_ASM("asm/nonmatchings/game/t_1E4E10", func_001E4E10);

INCLUDE_ASM("asm/nonmatchings/game/t_1E4E10", func_001E5050);

INCLUDE_ASM("asm/nonmatchings/game/t_1E4E10", func_001E5128);

extern "C" void func_001E5C50(void) {
    D_0036DA4C();
}

INCLUDE_ASM("asm/nonmatchings/game/t_1E4E10", func_001E5C70);

INCLUDE_ASM("asm/nonmatchings/game/t_1E4E10", func_001E5D98);

extern "C" void func_001E5E90(s32 a, s32 b) {
    if (b == 0xFFFF && a != 0) {
        S1E5E90* o = &D_0038EC50;
        D_00372DC0 = 0xC6D10F83;
        S1E5E90_S* t = &o->unk10;
        t->unk60 = 0;
        t->unk64 = 0;
        t->unk68 = 0;
        D_00372DB8 = 0;
    }
}

INCLUDE_ASM("asm/nonmatchings/game/t_1E4E10", func_001E5ED0);

extern "C" void func_001E5F38(void) {
    func_001E5E90(1, 0xFFFF);
}

extern "C" s32 func_001E5F58(void) {
    func_001E64A0();
    func_001E64B8();
    func_001E64D0();
    if (func_001E64E8() != 0 && func_001E6510() != 0 && func_001E6538() != 0) {
        return 1;
    }
    func_001E6560();
    func_001E6578();
    func_001E6590();
    return 0;
}

extern "C" s32 func_001E5FD0(void) {
    if (func_001E65A8() != 0 || func_001E65B0() != 0 || func_001E65B8() != 0) {
        func_001E6560();
        func_001E6578();
        func_001E6590();
        return 1;
    }
    return 1;
}

INCLUDE_ASM("asm/nonmatchings/game/t_1E4E10", func_001E6030);

INCLUDE_ASM("asm/nonmatchings/game/t_1E4E10", func_001E62A0);

INCLUDE_ASM("asm/nonmatchings/game/t_1E4E10", func_001E64A0);

INCLUDE_ASM("asm/nonmatchings/game/t_1E4E10", func_001E64B8);

INCLUDE_ASM("asm/nonmatchings/game/t_1E4E10", func_001E64D0);

INCLUDE_ASM("asm/nonmatchings/game/t_1E4E10", func_001E64E8);

INCLUDE_ASM("asm/nonmatchings/game/t_1E4E10", func_001E6510);

INCLUDE_ASM("asm/nonmatchings/game/t_1E4E10", func_001E6538);

INCLUDE_ASM("asm/nonmatchings/game/t_1E4E10", func_001E6560);

INCLUDE_ASM("asm/nonmatchings/game/t_1E4E10", func_001E6578);

INCLUDE_ASM("asm/nonmatchings/game/t_1E4E10", func_001E6590);

extern "C" s32 func_001E65A8(void) {
    return D_00371038;
}

extern "C" s32 func_001E65B0(void) {
    return D_00371238;
}

extern "C" s32 func_001E65B8(void) {
    return D_00370FB8;
}

INCLUDE_ASM("asm/nonmatchings/game/t_1E4E10", func_001E65C0);

INCLUDE_ASM("asm/nonmatchings/game/t_1E4E10", func_001E6668);

INCLUDE_ASM("asm/nonmatchings/game/t_1E4E10", func_001E6710);

INCLUDE_ASM("asm/nonmatchings/game/t_1E4E10", func_001E67B8);

INCLUDE_ASM("asm/nonmatchings/game/t_1E4E10", func_001E6830);

INCLUDE_ASM("asm/nonmatchings/game/t_1E4E10", func_001E68A8);

extern "C" void func_001E6920(s32 a, s32 b) {
    if (b == 0xFFFF && a != 0) {
        S1E6920* o = &D_0038ED60;
        S1E6920_L* h = &o->unk4;
        h->unk0 = h;
        h->unk4 = h;
    }
}

extern "C" void func_001E6950(void) {
    func_001E6920(1, 0xFFFF);
}

INCLUDE_ASM("asm/nonmatchings/game/t_1E4E10", func_001E6970);
