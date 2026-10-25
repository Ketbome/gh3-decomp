// cflags: -funroll-loops
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

struct S2E98_B {
    int unk0;
    int unk4;
    char *unk8;
    int pad0C;
    char *unk10;
    int pad14;
    int pad18;
};
struct S2E98_R {
    int unk0;
    int pad4;
    int unk8;
    int unkC;
    int unk10;
    int unk14;
    int unk18;
    int pad1C;
    int pad20;
    int pad24;
    S2E98_B unk28[2];
};

extern "C" {
extern S2E98_R D_003EB210;
extern S2E98_B D_003EB238[];
extern char D_00372948[];
int func_0011DAA0_i(int) asm("func_0011DAA0");
void func_00294FD0_r(S2E98_R *) asm("func_00294FD0");
int func_00295010_r(S2E98_R *, char *, int) asm("func_00295010");
int func_0030A260(char *, char *, int);
void *memset(void *, int, unsigned int);
}

extern "C" int func_002E9818(void) {
    int r;
    func_002E62C0(1);
    if (D_003EB210.unk14 != 0 || D_003EB210.unk8 == 0 || D_003EB210.unk0 == 0) {
        func_002E62C0(0);
        return 0;
    }
    {
        S2E98_B *b = &D_003EB238[D_003EB210.unk10];
        if (D_003EB210.unk18 != 0 && func_0011DAA0_i(D_003EB210.unk8) == 0) {
            if (func_0030A260(D_00372948, b->unk8, 4) == 0) {
                memset(b->unk8, 0, 0x30);
            }
            char *p = b->unk8 + 0x20000;
            b->unk4 -= 0x20000;
            b->unk8 = p;
            if (p == b->unk10 + b->unk0) {
                b->unk8 = b->unk10;
            }
            int t = D_003EB210.unk10 ^ 1;
            D_003EB210.unk18 = 0;
            D_003EB210.unkC += 0x20000;
            D_003EB210.unk10 = t;
            b = &D_003EB238[t];
        }
        if (D_003EB210.unk18 == 0) {
            if (b->unk4 > 0x1FFFF && D_003EB210.unkC < D_003EB210.unk0) {
                func_00295010_r(&D_003EB210, b->unk8, 0x20000);
                D_003EB210.unk18 = 1;
            }
        }
        r = 1;
        if (D_003EB210.unkC >= D_003EB210.unk0) {
            r = 0;
            func_00294FD0_r(&D_003EB210);
            memset(&D_003EB210, 0, 0x1C);
        }
        func_002E62C0(0);
        return r;
    }
}

INCLUDE_ASM("asm/nonmatchings/game/t_2E90B0", func_002E99D0);

INCLUDE_ASM("asm/nonmatchings/game/t_2E90B0", func_002E9A38);

struct S2E9C_T {
    int pad0;
    int pad4;
    int unk8;
    char pad0C[0xC];
    char *unk18;
    char pad1C[8];
    int unk24;
    char pad28[0xC];
    char *unk34;
};
struct S2E9C_E {
    int unk0;
    int unk4;
    char *unk8;
    char *unkC;
    char *unk10;
};
extern "C" {
extern S2E9C_T D_003EB230;
extern void *D_00368A38[] __attribute__((section(".sdata")));
extern int D_00372910;
extern int D_00372914;
extern int D_003728C8;
extern int D_003728CC;
extern int D_003728FC;
void *func_00119730(int, u32, int);
int func_0011A8D8(int);
void func_00119490(int, void *);
void func_001194B8(int);
void *Heap_Alloc(int, int, int, int);
void Heap_Free(int, void *);
void func_002E5938(int);
void func_002E1370(int);
void func_002E39C8(int);
}

GP_DATA(D_00372910);
GP_DATA(D_003728D4);
GP_DATA(D_003728C8);
GP_DATA(D_003728CC);
GP_DATA(D_003728D0);
GP_DATA(D_003728FC);
extern "C" int func_002E9C00(int init) {
    int r = init;
    func_002E62C0(1);
    if (init) {
        if (D_00372910 != 0) goto exit0;
        memset(&D_003EB210, 0, 0x1C);
        {
            int h = (int)D_00368A38[0];
            D_00372914 = -1;
            register int *t asm("$17") = (int *)func_00119730(h, 0xE84F4505, 1);
            register int n asm("$16") = func_0011A8D8(t[0x34 / 4]);
            int sz = (n / 0x40000) << 17;
            func_00119490(h, t);
            S2E9C_T *tb = &D_003EB230;
            for (int i = 0; i < 2; i++) {
                S2E9C_E *e = (S2E9C_E *)((char *)tb + 8 + i * 0x1C);
                char *m = (char *)Heap_Alloc((int)D_00368A38[0], sz, 1, 0);
                e->unk10 = m;
                e->unkC = m;
                e->unk8 = m;
                ((int *)e)[-2] = 0;
                *(int *)((char *)tb + 8 + i * 0x1C) = sz;
                e->unk4 = sz;
                memset(e->unk10, 0, *(int *)((char *)tb + 8 + i * 0x1C));
            }
            func_001194B8(h);
        }
        if (D_003EB230.unk18 != 0 && D_003EB230.unk34 != 0) {
            D_00372910 = 1;
        } else {
            r = 0;
        }
        if (r != 0) goto done;
    }
    if (D_00372910 == 0) {
exit0:
        func_002E62C0(0);
        return 0;
    }
    D_00372910 = 3;
    func_002E5938(6);
    func_002E5938(7);
    func_002E1370(6);
    func_002E1370(7);
    SndDrv_FlushCommands(0);
    func_002E39C8(D_003728C8);
    func_002E39C8(D_003728CC);
    D_003728D4 = -1;
    D_003728C8 = -1;
    D_003728CC = -1;
    D_003728D0 = -1;
    if (D_003EB230.unk18 != 0) Heap_Free((int)D_00368A38[0], D_003EB230.unk18);
    if (D_003EB230.unk34 != 0) Heap_Free((int)D_00368A38[0], D_003EB230.unk34);
    func_00294FD0_r(&D_003EB210);
    memset(&D_003EB210, 0, 0x1C);
    memset(&D_003EB230, 0, 0x38);
    D_00372910 = 0;
    D_003728FC = 0;
done:
    func_002E62C0(0);
    return r;
}

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

struct S2EAB18_N {
    char pad0[0x18];
    S2EAB18_N *unk18;
    char pad1C[8];
};

extern "C" {
void *Heap_Alloc(int, int, int, int);
extern void *D_00368A38[] __attribute__((section(".sdata")));
extern S2EAB18_N *D_003729B4;
extern int D_003729B8;
extern S2EAB18_N *D_003729BC_n asm("D_003729BC");
void func_002EA900(void *);
}

GP_DATA(D_003729B8);
GP_DATA(D_003729B4);
GP_DATA(D_003729BC);
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
