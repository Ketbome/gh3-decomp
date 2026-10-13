// cflags: -funroll-loops
#include "common.h"

struct S0026FAB8 {
    char pad[0x1C];
    int unk1C;
};

struct S26F3B8_A {
    int unk0;
    int unk4;
    int unk8;
    u16 unkC;
    s8 unkE;
    s8 unkF;
    int unk10;
};

struct S26F3B8_B {
    int unk0;
    int unk4;
    s16 unk8;
    s16 unkA;
    int unkC;
    int unk10;
};

struct S26F_Pair {
    s8 a;
    s8 b;
};

extern "C" {
u32 func_00271158(int);
int func_00270DB8(int);
int func_00270E40(int);
void func_0026F930(int, int);
void func_002700A0(void);
void func_00292FB0(int);
void func_0026F828(int, int, f32);
extern S26F_Pair D_003A90B0[8];
extern int D_003733C8;
void func_00293038(void);
void func_00293098(void);
void func_002930B8(void);
void func_0026F768(void);
void func_00270A90(void);
extern u32 D_003733A0[] __attribute__((section(".sdata")));
void func_00271280(u16, u16, int, int, int, int, int);
void func_002705A0(int, int, int, int, f32, f32, f32);
void func_00271198(u16, u16, int);
extern u32 D_00372EA8[] __attribute__((section(".sdata")));
extern S26F3B8_A D_003A8D40[][22];
extern int D_00370D10;
extern int D_003733A8;
extern int D_00370D30;
extern int D_00370D38;
extern int D_00370D34;
extern int D_00370D3C;
extern volatile int D_003733AC;
extern int D_00370D14;
void func_0026F6E8(void);
}

INCLUDE_ASM("asm/nonmatchings/game/t_26F3B8", func_0026F3B8);

INCLUDE_ASM("asm/nonmatchings/game/t_26F3B8", func_0026F568);

INCLUDE_ASM("asm/nonmatchings/game/t_26F3B8", func_0026F580);

INCLUDE_ASM("asm/nonmatchings/game/t_26F3B8", func_0026F5A8);

GP_DATA(D_00370D14);
GP_DATA(D_00370D10);
extern "C" void func_0026F6E8(void) {
    S26F3B8_B v;
    v.unk8 = 0;
    v.unkA = 0;
    v.unkC = 0;
    v.unk10 = 0;
    v.unk4 = 0;
    D_00370D14 = 0;
    D_00370D10 = 0;
    func_00271198(0x8010, 0xB80, 0);
    func_00271198(0x8010, 0xC80, D_00370D10);
    func_00271198(0x8030, 0x1900, 0);
    func_00271198(0x8030, 0x1B00, 0);
    func_00271198(0x8130, 0, (int)&v);
}

extern "C" void func_0026F768(void) {
    if (D_00370D10 == D_00370D14) {
        return;
    }
    if (D_00370D14 < D_00370D10) {
        D_00370D14 += 0x334;
        if (D_00370D10 < D_00370D14) {
            D_00370D14 = D_00370D10;
        }
    } else {
        D_00370D14 -= 0x334;
        if (D_00370D14 < D_00370D10) {
            D_00370D14 = D_00370D10;
            if (D_00370D10 == 0) {
                func_0026F6E8();
            }
        }
    }
    func_00271198(0x8010, 0xB80, D_00370D14);
    func_00271198(0x8010, 0xC80, D_00370D14);
}

extern "C" void func_0026F7E8(void) {
    func_00271198(0x8050, 0x1C00, 0x1F521F);
    func_00271198(0x8050, 0x1D00, 0x1FFFFF);
}

INCLUDE_ASM("asm/nonmatchings/game/t_26F3B8", func_0026F828);

INCLUDE_ASM("asm/nonmatchings/game/t_26F3B8", func_0026F930);

extern "C" void func_0026FA38(void) {
    func_00293038();
}

extern "C" void func_0026FA58(void) {
    func_00293098();
}

extern "C" int func_0026FA78(void) {
    return D_003733C8;
}

extern "C" void func_0026FA80(void) {
    func_002930B8();
}

INCLUDE_ASM("asm/nonmatchings/game/t_26F3B8", func_0026FAA0);

extern "C" int func_0026FAB8(S0026FAB8* p) {
    return p->unk1C != 0;
}

INCLUDE_ASM("asm/nonmatchings/game/t_26F3B8", func_0026FAC8);

INCLUDE_ASM("asm/nonmatchings/game/t_26F3B8", func_0026FAE0);

INCLUDE_ASM("asm/nonmatchings/game/t_26F3B8", func_0026FC80);

INCLUDE_ASM("asm/nonmatchings/game/t_26F3B8", func_0026FD70);

INCLUDE_ASM("asm/nonmatchings/game/t_26F3B8", func_0026FE70);

extern "C" void func_0026FFE8(int a, int b, f32 *v, int d, f32 f) {
    func_002705A0(b, a, -1, d, v[0], v[1], f);
}

extern "C" void func_00270020(int a, int b, int c, f32 *v, int d, f32 f) {
    func_002705A0(c, a, b, d, v[0], v[1], f);
}

extern "C" void func_00270060(int a, int b) {
    if (func_00270E40(a) != 0) {
        func_0026F930(a, b);
    }
}

INCLUDE_ASM("asm/nonmatchings/game/t_26F3B8", func_002700A0);

INCLUDE_ASM("asm/nonmatchings/game/t_26F3B8", func_00270340);

INCLUDE_ASM("asm/nonmatchings/game/t_26F3B8", func_002704E0);

extern "C" void func_00270540(int a, int b) {
    S26F3B8_A *e = &D_003A8D40[a][b];
    S26F3B8_A *o = &D_003A8D40[e->unkE][e->unkF];
    o->unkE = -1;
    o->unkF = -1;
    e->unkE = -1;
    e->unkF = -1;
    o->unkC &= ~2;
}

INCLUDE_ASM("asm/nonmatchings/game/t_26F3B8", func_002705A0);

INCLUDE_ASM("asm/nonmatchings/game/t_26F3B8", func_00270928);

extern "C" void func_002709C8(void) {
    func_002700A0();
    func_00292FB0(-1);
    func_0026F828(0, 0, 0.0f);
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 22; j++) {
            S26F3B8_A *s = &D_003A8D40[i][j];
            s->unk0 = 0;
            s->unk4 = 0;
            s->unk8 = 0;
            s->unk10 = 0;
        }
    }
    for (int k = 0; k < 8; k++) {
        D_003A90B0[k].a = -1;
    }
}

INCLUDE_ASM("asm/nonmatchings/game/t_26F3B8", func_00270A90);

INCLUDE_ASM("asm/nonmatchings/game/t_26F3B8", func_00270BD0);

INCLUDE_ASM("asm/nonmatchings/game/t_26F3B8", func_00270DB0);

INCLUDE_ASM("asm/nonmatchings/game/t_26F3B8", func_00270DB8);

extern "C" int func_00270E10(int a, int b) {
    if (a == 1 && !((0xFFF >> b) & 1)) {
        return 1;
    }
    return 0;
}

extern "C" int func_00270E40(int a) {
    int h = 0;
    if (a >= 0x16) {
        h = 1;
        a -= 0x16;
    }
    return ((func_00270DB8(h) >> a) ^ 1) & 1;
}

extern "C" int func_00270E88(int a) {
    int h = 0;
    if (a >= 0x16) {
        h = 1;
        a -= 0x16;
    }
    return (func_00271158(h) & (1 << a)) != 0;
}

INCLUDE_ASM("asm/nonmatchings/game/t_26F3B8", func_00270ED8);

extern "C" void func_00270EE0(void) {
    func_0026F768();
    func_00270A90();
}

INCLUDE_ASM("asm/nonmatchings/game/t_26F3B8", func_00270F08);

GP_DATA(D_00370D30);
GP_DATA(D_00370D38);
extern "C" void func_00270FC0(void) {
    D_003733A8 = 0;
    D_00370D30 = 0;
    D_00370D38 = 0;
    D_00370D34 = 0;
    D_00370D3C = 0;
    D_003733AC = 0;
}

extern "C" void func_00270FF0(void) {
    func_00271198(0x8040, 0x1700, 0);
    func_00271198(0x8040, 0x1701, 0);
}

INCLUDE_ASM("asm/nonmatchings/game/t_26F3B8", func_00271028);

extern "C" int func_002710B8(int i, int bit) {
    u32 m = 1 << bit;
    u32 old = D_003733A0[i];
    u32 nw = old & ~m;
    D_00372EA8[i] |= m;
    D_003733A0[i] = nw;
    return (old ^ nw) != 0;
}

extern "C" int func_00271108(int i, int bit) {
    u32 m = 1 << bit;
    u32 old = D_003733A0[i];
    u32 nw = old | m;
    D_00372EA8[i] &= ~m;
    D_003733A0[i] = nw;
    return (old ^ nw) != 0;
}

extern "C" u32 func_00271158(int i) {
    return ~D_003733A0[i] & 0x3FFFFF;
}

extern "C" u32 func_00271180(int i) {
    return D_003733A0[i];
}

extern "C" void func_00271198(u16 a, u16 b, int c) {
    func_00271280(a, b, c, 0, 0, 0, 0);
}

INCLUDE_ASM("asm/nonmatchings/game/t_26F3B8", func_002711C8);

INCLUDE_ASM("asm/nonmatchings/game/t_26F3B8", func_002711D0);

INCLUDE_ASM("asm/nonmatchings/game/t_26F3B8", func_00271228);

INCLUDE_ASM("asm/nonmatchings/game/t_26F3B8", func_00271280);
