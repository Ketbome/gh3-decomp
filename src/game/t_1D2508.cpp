#include "common.h"

struct VEnt {
    s16 delta;
    s16 index;
    void (*fn)(void*, s32);
};

struct S001D2B08 {
    char pad0[0x20];
    s32 unk20;
    char pad24[0x130];
    s32 unk154;

    bool Test(s32 m) {
        return (unk154 & m) != 0;
    }
};

struct S0036D3B0 {
    char pad0[0x2C];
    VEnt* unk2C;
};

extern "C" {
void func_001D1418(void);
void func_001D1438(void* p, s32 v);
void func_001D14C0(void* p, s32 v);
void func_001D3818(s32 a, s32 b);
void func_0027C448(s32 a, u32 key, s32 b);
void* func_00113DF0(s32 size, s32 a, s32 b);
S0036D3B0* func_001D4260(void* p);
extern S0036D3B0* D_0036D3B0;
extern u32 D_0036D3B4;
}

INCLUDE_ASM("asm/nonmatchings/game/t_1D2508", func_001D2508);

INCLUDE_ASM("asm/nonmatchings/game/t_1D2508", func_001D2918);

extern "C" int func_001D29C8(void) {
    func_001D1418();
    return 1;
}

INCLUDE_ASM("asm/nonmatchings/game/t_1D2508", func_001D29E8);

INCLUDE_ASM("asm/nonmatchings/game/t_1D2508", func_001D2A30);

INCLUDE_ASM("asm/nonmatchings/game/t_1D2508", func_001D2A78);

extern "C" int func_001D2AC8(void* p) {
    func_001D1438(p, 1);
    return 1;
}

extern "C" int func_001D2AE8(void* p) {
    func_001D1438(p, 0);
    return 1;
}

extern "C" bool func_001D2B08(S001D2B08* p) {
    return p->Test(4);
}

extern "C" bool func_001D2B18(S001D2B08* p) {
    return p->Test(0x20);
}

INCLUDE_ASM("asm/nonmatchings/game/t_1D2508", func_001D2B28);

extern "C" int func_001D2C18(void* p) {
    func_001D14C0(p, 1);
    return 1;
}

extern "C" int func_001D2C38(void* p) {
    func_001D14C0(p, 0);
    return 1;
}

extern "C" int func_001D2C58(S001D2B08* p) {
    p->unk154 |= 1;
    return 1;
}

extern "C" int func_001D2C70(S001D2B08* p) {
    p->unk154 &= ~1;
    return 1;
}

INCLUDE_ASM("asm/nonmatchings/game/t_1D2508", func_001D2C88);

INCLUDE_ASM("asm/nonmatchings/game/t_1D2508", func_001D2E60);

INCLUDE_ASM("asm/nonmatchings/game/t_1D2508", func_001D2F00);

INCLUDE_ASM("asm/nonmatchings/game/t_1D2508", func_001D3020);

INCLUDE_ASM("asm/nonmatchings/game/t_1D2508", func_001D30B8);

INCLUDE_ASM("asm/nonmatchings/game/t_1D2508", func_001D3150);

INCLUDE_ASM("asm/nonmatchings/game/t_1D2508", func_001D3298);

INCLUDE_ASM("asm/nonmatchings/game/t_1D2508", func_001D32D8);

INCLUDE_ASM("asm/nonmatchings/game/t_1D2508", func_001D3360);

INCLUDE_ASM("asm/nonmatchings/game/t_1D2508", func_001D33D8);

INCLUDE_ASM("asm/nonmatchings/game/t_1D2508", func_001D3450);

extern "C" int func_001D3508(S001D2B08* a, void* b, S001D2B08* c) {
    s32 v = a->unk20;

    func_0027C448(c->unk20, 0x24495505 /* objtype */, v);
    return 1;
}

INCLUDE_ASM("asm/nonmatchings/game/t_1D2508", func_001D3538);

INCLUDE_ASM("asm/nonmatchings/game/t_1D2508", func_001D3580);

INCLUDE_ASM("asm/nonmatchings/game/t_1D2508", func_001D3620);

extern "C" void func_001D36D8(void) {
}

INCLUDE_ASM("asm/nonmatchings/game/t_1D2508", func_001D36E0);

INCLUDE_ASM("asm/nonmatchings/game/t_1D2508", func_001D36E8);

INCLUDE_ASM("asm/nonmatchings/game/t_1D2508", func_001D3810);

INCLUDE_ASM("asm/nonmatchings/game/t_1D2508", func_001D3818);

INCLUDE_ASM("asm/nonmatchings/game/t_1D2508", func_001D40F8);

extern "C" void func_001D4110(void) {
}

INCLUDE_ASM("asm/nonmatchings/game/t_1D2508", func_001D4118);

INCLUDE_ASM("asm/nonmatchings/game/t_1D2508", func_001D4158);

extern "C" void func_001D4198(void) {
    func_001D3818(1, 0xFFFF);
}

extern "C" S0036D3B0* func_001D41B8(s32 a) {
    if (D_0036D3B0 == 0 && a != 0) {
        D_0036D3B0 = func_001D4260(func_00113DF0(0x458, 0, 1));
    }
    D_0036D3B4++;
    return D_0036D3B0;
}

extern "C" void func_001D4208(void) {
    S0036D3B0* p;

    if (D_0036D3B4 > 1) {
        D_0036D3B4--;
    } else {
        p = D_0036D3B0;
        if (p != 0) {
            p->unk2C[1].fn((char*)p + p->unk2C[1].delta, 3);
        }
        D_0036D3B0 = 0;
        D_0036D3B4 = 0;
    }
}

INCLUDE_ASM("asm/nonmatchings/game/t_1D2508", func_001D4260);

INCLUDE_ASM("asm/nonmatchings/game/t_1D2508", func_001D4380);

INCLUDE_ASM("asm/nonmatchings/game/t_1D2508", func_001D43F8);

INCLUDE_ASM("asm/nonmatchings/game/t_1D2508", func_001D4400);

INCLUDE_ASM("asm/nonmatchings/game/t_1D2508", func_001D4480);
