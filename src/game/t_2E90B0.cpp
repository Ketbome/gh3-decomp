#include "common.h"

struct S2EA7_E {
    int unk0;
    s16 unk4;
    s16 unk6;
    char pad8[0x30];
    int unk38;
    char pad3C[8];
    int unk44;
    int unk48;
};

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
int func_002E3F50(int, void *);
int func_002E56E8(void);
extern int D_00373228;
extern int D_003728D8;
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
int SndDrv_FlushCommands(int);
int func_002E3E50(int);
int func_002E62C0(int);
int func_002EA898(int, int);
extern S2EA7_E D_003EB000[];
extern s32 D_003728E4;
extern s32 D_003728E8;
int func_002E6270(s16);
}

extern "C" void func_002E90B0(int a) {
    func_002E12D8(0, func_002E3770(a));
    func_002E12D8(1, func_002E3770(a));
}

extern "C" void func_002E90F8(void) {
    func_002E62C0(1);
    func_002E3E50(0);
    func_002E3E50(1);
    SndDrv_FlushCommands(0);
    D_00372900 = 3;
    func_002E62C0(0);
}

GP_DATA(D_003728D8);
extern "C" int func_002E9140(void) {
    struct {
        char pad0[0x12];
        u8 unk12;
        char pad13[0x3D];
    } q;
    u8 t;
    u8 u;
    if (func_002E3F50(0, &q) == 0 && (t = q.unk12) == 1 && func_002E3F50(1, &q) == 0 && (u = q.unk12) == t &&
        func_002E56E8() == -1) {
        if (D_003728D8++ >= 0xB) {
            D_00373228 = u;
        }
    }
    return D_00373228;
}

INCLUDE_ASM("asm/nonmatchings/game/t_2E90B0", func_002E91E8);

extern "C" void func_002E9510(int i, int a, int b, int n, int *out) {
    out[0] = 0;
    out[1] = 0;
    if (a) {
        int d = b - a;
        n -= d;
        out[i] += d;
        i ^= 1;
    }
    int q = n / b / 2 * b;
    out[0] += q;
    out[1] += q;
    n -= q * 2;
    if (n >= b) {
        n -= b;
        out[i] += b;
        i ^= 1;
    }
    if (n)
        out[i] += n;
}

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
    SndDrv_FlushCommands(0);
    func_002EA268();
    SndDrv_FlushCommands(0);
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

GP_DATA(D_003728E4);
GP_DATA(D_003728E8);
extern "C" u32 func_002EA7E0(void) {
    if (D_003728E4 == -1 || D_003728E8 == 0)
        return 0;
    u32 a = func_002E6270(D_003EB000[D_003728E4].unk4);
    return a * 70 / (D_003EB000[D_003728E4].unk38 / 25) * 20 / (D_003EB000[D_003728E4].unk48 / 5) + D_003EB000[D_003728E4].unk44;
}

INCLUDE_ASM("asm/nonmatchings/game/t_2E90B0", func_002EA898);

extern "C" void func_002EA8E0(void) {
    func_002EA898(1, 0xFFFF);
}

INCLUDE_ASM("asm/nonmatchings/game/t_2E90B0", func_002EA900);

GP_DATA(D_003729B0);
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
