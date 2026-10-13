#include "common.h"

struct S2EAB08_0 {
    char pad0[0x14];
    void *unk14;
};

struct S2E90B0_A {
    char pad0[0x14];
    S2E90B0_A *unk14;
};

struct S2E90B0_L {
    char pad0[0xC];
    S2E90B0_A *unkC;
    S2E90B0_A *unk10;
};

extern "C" {
void func_002E11F0(int, int, int);
int func_002E7E20(f32);
extern int D_003728D0;
extern int D_003728D4;
extern int D_003728E0;
extern void *D_003729BC;
int func_002E3770(int);
void func_002E12D8(int, int);
void func_002EA268(void);
extern s32 D_003728F0;
extern s32 D_003728F4;
extern s32 D_00372900;
extern void * D_003729B0;
int func_002E3248(int);
int func_002E3E50(int);
int func_002E62C0(int);
int func_002EA898(int, int);
}

extern "C" void func_002E90B0(int a) {
    func_002E12D8(0, func_002E3770(a));
    func_002E12D8(1, func_002E3770(a));
}

extern "C" void func_002E90F8(void) {
    func_002E62C0(1);
    func_002E3E50(0);
    func_002E3E50(1);
    func_002E3248(0);
    D_00372900 = 3;
    func_002E62C0(0);
}

INCLUDE_ASM("asm/nonmatchings/game/t_2E90B0", func_002E9140);

INCLUDE_ASM("asm/nonmatchings/game/t_2E90B0", func_002E91E8);

INCLUDE_ASM("asm/nonmatchings/game/t_2E90B0", func_002E9510);

INCLUDE_ASM("asm/nonmatchings/game/t_2E90B0", func_002E95C0);

INCLUDE_ASM("asm/nonmatchings/game/t_2E90B0", func_002E9818);

INCLUDE_ASM("asm/nonmatchings/game/t_2E90B0", func_002E99D0);

INCLUDE_ASM("asm/nonmatchings/game/t_2E90B0", func_002E9A38);

INCLUDE_ASM("asm/nonmatchings/game/t_2E90B0", func_002E9C00);

INCLUDE_ASM("asm/nonmatchings/game/t_2E90B0", func_002E9E70);

INCLUDE_ASM("asm/nonmatchings/game/t_2E90B0", func_002EA268);

INCLUDE_ASM("asm/nonmatchings/game/t_2E90B0", func_002EA460);

INCLUDE_ASM("asm/nonmatchings/game/t_2E90B0", func_002EA5E8);

extern "C" void func_002EA5F0(void) {
    func_002E3248(0);
    func_002EA268();
    func_002E3248(0);
}

INCLUDE_ASM("asm/nonmatchings/game/t_2E90B0", func_002EA620);

extern "C" void func_002EA740(s32 arg0) {
    D_003728F4 = arg0 ^ 1;
}

extern "C" void func_002EA750(s32 arg0) {
    D_003728F0 = arg0;
}

GP_DATA(D_003728D0);
GP_DATA(D_003728D4);
GP_DATA(D_003728E0);
extern "C" void func_002EA758(f32 f) {
    int v = func_002E7E20(f * 0.89f);
    D_003728E0 = v;
    if (D_003728D0 != -1 && D_003728D4 != -1) {
        if (D_003728F4 != 0) {
            func_002E11F0(D_003728D0, v, v);
            func_002E11F0(D_003728D4, D_003728E0, D_003728E0);
            return;
        }
        func_002E11F0(D_003728D0, v, 0);
        func_002E11F0(D_003728D4, 0, D_003728E0);
    }
}

INCLUDE_ASM("asm/nonmatchings/game/t_2E90B0", func_002EA7E0);

INCLUDE_ASM("asm/nonmatchings/game/t_2E90B0", func_002EA898);

extern "C" void func_002EA8E0(void) {
    func_002EA898(1, 0xFFFF);
}

INCLUDE_ASM("asm/nonmatchings/game/t_2E90B0", func_002EA900);

INCLUDE_ASM("asm/nonmatchings/game/t_2E90B0", func_002EA9E0);

GP_DATA(D_003729B0);
extern "C" void func_002EAB08(S2EAB08_0 *arg0) {
    arg0->unk14 = (void *) D_003729B0;
    D_003729B0 = arg0;
}

INCLUDE_ASM("asm/nonmatchings/game/t_2E90B0", func_002EAB18);

INCLUDE_ASM("asm/nonmatchings/game/t_2E90B0", func_002EAC68);

struct S2EAE00_N {
    char pad0[0x14];
    S2EAE00_N *unk14;
};
struct S2EAE00 {
    char pad0[0xC];
    S2EAE00_N *unkC;
    char pad10[8];
    void *unk18;
};
GP_DATA(D_003729BC);
extern "C" void func_002EAE00(S2EAE00 *p) {
    if (p->unkC != 0) {
        S2EAE00_N *next;
        do {
            S2EAE00_N *n = p->unkC;
            next = n->unk14;
            func_002EAB08((S2EAB08_0 *)n);
            p->unkC = next;
        } while (next != 0);
    }
    p->unk18 = D_003729BC;
    D_003729BC = p;
}

extern "C" void func_002EAE58(S2E90B0_L *l, S2E90B0_A *n) {
    if (l->unkC != 0) {
        l->unk10->unk14 = n;
    } else {
        l->unkC = n;
    }
    l->unk10 = n;
    n->unk14 = 0;
}

INCLUDE_ASM("asm/nonmatchings/game/t_2E90B0", func_002EAE78);

INCLUDE_ASM("asm/nonmatchings/game/t_2E90B0", func_002EAF00);
