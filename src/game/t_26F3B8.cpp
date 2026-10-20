// cflags: -funroll-loops
#include "common.h"

asm(".set D_003733A0_lui, D_003733A0");
asm(".set D_003733A8_lui, D_003733A8");

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
u64 func_0011ECE8(void);
void func_0011ECE8_v(void) asm("func_0011ECE8");
extern volatile u32 D_00370D20[2];
extern u32 D_003733A8_x[] asm("D_003733A8_lui") __attribute__((section(".sdata")));
extern u32 D_003733A0_x[] asm("D_003733A0_lui") __attribute__((section(".sdata")));
int func_00271108(int, int);
int func_0026FAC8(void);
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
void func_00273428(int);
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
u32 func_00271180(int);
void func_00266928(void*, f32);
void func_0026FAE0(int, int, f32, f32);
void func_0026FC80(int, int, f32);
void func_00271590(int *, int);
void func_002733E0(int);
extern int D_0032D838[];
int func_00270E10(int, int);
extern f32 D_00370B08;
extern f32 D_00370D18;
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

GP_DATA(D_00370D18);
extern "C" void func_0026FD70(int a, int b, f32* v, int c, f32 f) {
    func_00266928(v, D_00370D18);
    int i = b * 0x14 + a * 0x1B8;
    f32* e = (f32*)(i + (int)D_003A8D40);
    *e = v[0];
    f32 y = v[1];
    ((f32*)((int)D_003A8D40 + i))[1] = y;
    if (c) func_0026FAE0(a, b, *e, y);
    if (f != 0.0f) {
        ((f32*)((int)D_003A8D40 + i))[2] = f;
        if (!func_00270E10(a, b)) f *= D_00370B08;
        if (c) func_0026FC80(a, b, f);
    }
}

extern "C" int func_0026FE70(int a, int key) {
    int k = key;
    if (a == 0) {
        key = func_00270DB8(1);
        for (int i = 12; i < 22; i++) {
            if ((key >> i) & 1) {
                if (i + 22 != k) {
                    return i + 22;
                }
            }
        }
    }
    key = func_00270DB8(0);
    for (int i = 0; i < 22; i++) {
        if ((key >> i) & 1) {
            if (i != k) {
                return i;
            }
        }
    }
    key = func_00270DB8(1);
    for (int i = 0; i < 22; i++) {
        if ((key >> i) & 1) {
            if (i + 22 != k) {
                return i + 22;
            }
        }
    }
    return -1;
}

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

extern "C" void func_002704E0(int a, int b, int c, int d) {
    S26F3B8_A *o = &D_003A8D40[a][b];
    S26F3B8_A *e = &D_003A8D40[c][d];
    e->unkE = a;
    e->unkF = b;
    o->unkE = c;
    o->unkF = d;
    e->unkC |= 2;
}


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

extern "C" void func_00270928(int a) {
    int s = func_0026FAC8();
    S26F3B8_A *e;
    if (s == 1) {
        a -= 0x16;
    }
    e = &D_003A8D40[s][a];
    if ((e->unkC >> 2) & 1) {
        func_00271108(e->unkE, e->unkF);
        e->unkC &= ~4;
        func_00270540(s, a);
    }
}

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

GP_DATA(D_00370D20);
extern "C" int func_00271028(int i) {
    u64 t;
    do {
        t = D_00370D20[i];
    } while (t != func_0011ECE8());
    D_00370D20[i];
    func_0011ECE8_v();
    u32 x = D_003733A8_x[i];
    u32 y = D_003733A0_x[i];
    return x & y;
}

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

struct S2712_Q {
    char pad0[0x10];
    int unk10;
    s16 unk14;
    s16 unk16;
    int unk18;
    int unk1C;
    int unk20;
    int unk24;
    int unk28;
    int unk2C;
};

struct S2712_A {
    int unk0;
    int unk4;
    s16 unk8;
    s16 unkA;
    int unkC;
    int unk10;
};

GP_DATA(D_00370D40);
extern "C" {
extern volatile int D_00373398;
extern int D_003733B4;
extern volatile int D_00370D40;
extern S2712_Q D_004278B0[];
extern char D_00358AA0[];
extern char D_00358AD0[];
int func_002EEA00(int);
int func_002F0AB0(int, S2712_Q *, int, int, int, int);
void func_002F0488(char *);
void func_00271480(u16, void *);
int func_002F3B80(void);
int func_002F3BD0(void);
}

static inline int S2712_Next(int &c) {
    int o = c;
    c = o + 1;
    return o;
}

extern "C" int func_00271280_r(u16 arg0, u16 arg1, S2712_A *arg2, int arg3, int arg4, int arg5, int *arg6) asm("func_00271280");

extern "C" int func_00271280_r(u16 arg0, u16 arg1, S2712_A *arg2, int arg3, int arg4, int arg5, int *arg6) {
    int t20 = arg0;
    int t21 = arg1;
    int sp0 = arg3;
    int sp4 = arg4;
    int sp8 = arg5;
    if (t20 == 0x8030) {
        func_00271480(t21, arg2);
    }
    int t23 = (D_00373398 + 1) % 32;
    S2712_Q *q = &D_004278B0[D_00373398];
    if (q->unk28 != 0) {
        int n = 0;
        while (func_002EEA00(q->unk28) >= 0) {
            if (n++ % 1000 == 0) {
                func_002F0488(D_00358AD0);
            }
        }
    }
    q->unk14 = t20;
    if (t20 == 0x8130) {
        q->unk16 = t21;
        q->unk18 = arg2->unk4;
        q->unk1C = (arg2->unk8 << 16) | arg2->unkA;
        q->unk20 = arg2->unkC;
        q->unk24 = arg2->unk10;
    } else {
        q->unk16 = t21;
        q->unk18 = (int)arg2;
        q->unk1C = sp0;
        q->unk20 = sp4;
        q->unk24 = sp8;
    }
    func_002F3B80();
    int id = D_003733B4++;
    func_002F3BD0();
    q->unk10 = id;
    if (arg6 != 0) {
        *arg6 = id;
    }
    int m = 0;
    D_00370D40 += 1;
    q->unk2C = D_00370D40;
    for (;;) {
        int r = func_002F0AB0(3, q, 0x30, 0, 0, 0);
        q->unk28 = r;
        if (r != 0) break;
        if (m++ % 1000 == 0) {
            func_002F0488(D_00358AA0);
        }
    }
    D_00373398 = t23;
    return 1;
}
