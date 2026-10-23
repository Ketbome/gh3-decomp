#include "common.h"

extern "C" {
int func_00273588(int);
f32 func_00268328(int);
void func_00273070(f32);
extern int D_00370AE0;
int func_00273510(int);
extern int D_00370C60;
extern int D_00370C38;
extern int D_00370C5C;
int func_00273F08(int, int);
int func_00275EE8(u32, int);
extern int D_00370C40;
int func_0026B1B0(int, f32);
void func_00273B20(int);
extern int D_00370C24;
extern char D_003A66F0[];
void func_0026AEA8(int);
extern int D_00368748;
extern int D_00370C30;
int func_0026ABA8(void);
void func_0026AE70(void);
extern int D_00370C18;
void func_00273B80(int);
int func_0026ABB0(void);
extern int D_00370C34;
extern int D_00370C28;
extern int D_00370C50;
extern f32 D_00370C1C;
extern f32 D_00370C20;
int func_0026AD48(int, int);
int func_0026DC68(int);
int func_0026E138(int, int *);
}

struct S26C_I {
    int unk0;
    int unk4;
};

struct S26C_E {
    int unk0;
    char pad4[0xC];
    int unk10;
    char pad14[8];
    int unk1C;
    char pad20[0xC];
    int unk2C;
    char pad30[0xC];
    S26C_I items[2];
    char pad4C[0x34];
};

extern "C" {
extern S26C_E D_003A44B0[];
extern int D_00372E98;
}

extern "C" void func_0026AEF8(void) {
    if (func_0026ABB0() == 0) {
        func_00273B80(1);
    }
}

INCLUDE_ASM("asm/nonmatchings/game/t_26AEF8", func_0026AF28);

INCLUDE_ASM("asm/nonmatchings/game/t_26AEF8", func_0026B150);

extern "C" int func_0026B158(int a, f32 f) {
    if (func_0026ABA8() == 0) {
        if (func_00273510(a) != 0) {
            func_00273070(f);
            return 1;
        }
    }
    return 0;
}

extern "C" int func_0026B1B0(int a, f32 f) {
    if (func_0026ABA8() == 0) {
        if (func_00273588(a) != 0) {
            func_00273070(f);
            return 1;
        }
    }
    return 0;
}

INCLUDE_ASM("asm/nonmatchings/game/t_26AEF8", func_0026B208);

INCLUDE_ASM("asm/nonmatchings/game/t_26AEF8", func_0026B3C8);

struct S26B_E {
    int unk0;
    int unk4;
    char pad8[8];
    int unk10;
    int unk14;
    char pad18[0x18];
    int unk30;
    char pad34[4];
    int unk38;
    char pad3C[0x40];
    int unk7C;
};

extern "C" {
extern S26B_E D_003A44B0_b[] asm("D_003A44B0");
int func_0028DAB8(void);
int func_0026B208(int, int *, int);
void func_00273B48(int, int);
int func_00273A80(int, int, int, int, int);
s64 func_0011ECE8(void *);
}

INCLUDE_ASM("asm/nonmatchings/game/t_26AEF8", func_0026B628);

INCLUDE_ASM("asm/nonmatchings/game/t_26AEF8", func_0026B768);

INCLUDE_ASM("asm/nonmatchings/game/t_26AEF8", func_0026B770);

INCLUDE_ASM("asm/nonmatchings/game/t_26AEF8", func_0026BA48);

INCLUDE_ASM("asm/nonmatchings/game/t_26AEF8", func_0026BBA8);

INCLUDE_ASM("asm/nonmatchings/game/t_26AEF8", func_0026BC98);

GP_DATA(D_00370C50);
extern "C" int func_0026BCA0(void) {
    return D_00370C50 >= 0;
}

GP_DATA(D_00370C58);
INCLUDE_ASM("asm/nonmatchings/game/t_26AEF8", func_0026BCB0);

INCLUDE_ASM("asm/nonmatchings/game/t_26AEF8", func_0026BD80);

INCLUDE_ASM("asm/nonmatchings/game/t_26AEF8", func_0026BDF8);

GP_DATA(D_00370C10);
INCLUDE_ASM("asm/nonmatchings/game/t_26AEF8", func_0026BE00);

INCLUDE_ASM("asm/nonmatchings/game/t_26AEF8", func_0026BEA8);

INCLUDE_ASM("asm/nonmatchings/game/t_26AEF8", func_0026C110);

INCLUDE_ASM("asm/nonmatchings/game/t_26AEF8", func_0026C120);

struct S26C2_I {
    int unk0;
    int unk4;
};

struct S26C2_E {
    int unk0;
    char pad4[0xC];
    int unk10;
    char pad14[8];
    int unk1C;
    char pad20[4];
    int unk24;
    int unk28;
    int unk2C;
    char pad30[0xC];
    S26C2_I items[2];
    char pad4C[0x34];
};

extern "C" {
extern S26C2_E D_003A44B0_d[] asm("D_003A44B0");
int func_0026AD48(int, int);
int func_0026DC68(int);
}

extern "C" int func_0026C250(int a, int b, int c) {
    if (func_0026ABB0() == 0) {
        int idx = -1;
        if (c != 0) {
            for (int i = 0; i < D_00372E98; i++) {
                if (D_003A44B0_d[i].unk1C == c && D_003A44B0_d[i].unk0 == a && func_0026DC68(D_003A44B0_d[i].unk10) != 1) {
                    idx = i;
                    break;
                }
            }
        } else {
            idx = func_0026AD48(a, 1);
        }
        if (idx >= 0) {
            S26C2_E *e = &D_003A44B0_d[idx];
            int n0 = e->unk2C;
            if (n0 > 0) {
                if (e->items[0].unk0 == b) {
                    for (int j = 1; j < e->unk2C; j++) {
                        e->items[j - 1] = e->items[j];
                    }
                    int n = e->unk2C;
                    int t = e->unk28;
                    e->unk2C = n - 1;
                    if (t >= 0) {
                        e->unk28 = t - 1;
                        if (t - 1 < 0) {
                            e->unk28 = n - 2;
                            if (e->unk24 >= 0) {
                                e->unk24 = e->unk24 + 1;
                            }
                        }
                    }
                    return 1;
                }
                return 1;
            }
        }
    }
    return 0;
}

typedef unsigned int u128_26C __attribute__((mode(TI)));

struct S26C3_Ob {
    char pad0[0xC];
    int unkC;
};
struct S26C3_E {
    char pad0[4];
    int unk4;
    f32 unk8;
    f32 unkC;
    int unk10;
    char pad14[4];
    int unk18;
    S26C3_Ob *unk1C;
    int unk20;
    char pad24[0x10];
    int unk34;
    char pad38[0x48];
};
struct S26C3_O1 {
    f32 a;
    f32 b;
    char pad[0x18];
};

extern "C" {
extern S26C3_E D_003A44B0_e[] asm("D_003A44B0");
void func_00266898_c(void *) __asm__("func_00266898");
void func_00266BE8_c(void *) __asm__("func_00266BE8");
void func_002668F8_c(void *, int) __asm__("func_002668F8");
void func_00266928_c(void *, f32, f32) __asm__("func_00266928");
void func_00273298_c(int, f32, f32) __asm__("func_00273298");
int func_0026DC68_c(int, int, int *, S26C3_E *, int *, int) __asm__("func_0026DC68");
void func_002687F0_c(int, void *, u128_26C *, int, int, int, char *, f32) __asm__("func_002687F0");
int func_0015D5C0_c(int, int) __asm__("func_0015D5C0");
int func_001FC030_c(void *, int, char *) __asm__("func_001FC030");
u128_26C func_001FBFD0_c(void *, int) __asm__("func_001FBFD0");
}

extern "C" int func_0026C3D8(int arg) {
    S26C3_O1 o1;
    char buf[0x10];
    u128_26C v;
    int i;
    if (func_0026ABB0() == 0) {
        S26C3_E *e = &D_003A44B0_e[arg];
        S26C3_Ob *ob = e->unk1C;
        i = 0;
        if (D_00372E98 > 0) {
            int *tp = (int *)((char *)ob + 0x1C) + e->unk20;
            int *p10 = &e->unk10;
            for (; i < D_00372E98; i++) {
                if (D_003A44B0_e[i].unk4 == *tp) {
                    S26C3_E *ce = &D_003A44B0_e[i];
                    if (func_0026DC68_c(*p10, i + 1, p10, D_003A44B0_e, tp, D_00372E98) != 1) {
                        func_00266898_c(&o1);
                        int o = D_00370AE0;
                        if (ce->unk18 & 1) {
                            int r = func_0015D5C0_c(ob->unkC + 0x80, 0);
                            if (r) {
                                char *q = func_001FC030_c(ob, r, buf) ? buf : 0;
                                v = func_001FBFD0_c(ob, r);
                                func_002687F0_c(o, &o1, &v, ce->unk34, 0, r, q, ce->unkC);
                            } else {
                                func_00266BE8_c(&o1);
                            }
                        } else {
                            o1.a = o1.b = ce->unk8;
                        }
                        if (ce->unk8 != 100.0f) func_00266928_c(&o1, ce->unk8, o1.b);
                        func_00273298_c(ce->unk10, o1.a, o1.b);
                        func_002668F8_c(&o1, 2);
                        return 1;
                    }
                    break;
                }
            }
        }
    }
    return 0;
}

INCLUDE_ASM("asm/nonmatchings/game/t_26AEF8", func_0026C5A0);

GP_DATA(D_00370C30);
extern "C" int func_0026C5A8(void) {
    if (D_00368748 != 0) {
        if (D_00370C30 == 0) {
            return 0;
        }
        func_0026AE70();
        func_0026AEA8(-1);
    }
    return 0;
}

INCLUDE_ASM("asm/nonmatchings/game/t_26AEF8", func_0026C5E8);

GP_DATA(D_00370C40);
extern "C" void func_0026C738(int a, f32 f) {
    if (func_0026ABA8() == 0) {
        func_00273B20(0);
        if (f < 0.0f) {
            f = D_00370C20;
        }
        func_0026B1B0(a, f);
        D_00370C40 = 1;
    }
}

GP_DATA(D_00370C5C);
GP_DATA(D_00370C34);
extern "C" void func_0026C7A8(int a) {
    if (func_0026ABA8() == 0) {
        switch (a) {
        case -1:
            if (D_00370C5C == 0) {
                func_0026C7A8(0);
            }
            break;
        case 1: {
            func_00275EE8(0xD7BB618D, 0);
            int t = D_00370C34;
            D_00370C34 = a;
            D_00370C5C = t;
            func_00273F08(1, 1);
            break;
        }
        case 0:
            func_00275EE8(0xD7BB618D, 0);
            D_00370C34 = 0;
            func_00273F08(0, 1);
            break;
        }
    }
}

extern "C" int func_0026C870(void) {
    return D_00370C34;
}

GP_DATA(D_00370C60);
GP_DATA(D_00370C38);
extern "C" void func_0026C878(int a) {
    if (func_0026ABB0() == 0) {
        switch (a) {
        case -1:
            if (D_00370C60 == 0) {
                func_0026C878(0);
            }
            break;
        case 1: {
            func_00275EE8(0xD7BB618D, 0);
            int t = D_00370C38;
            D_00370C38 = a;
            D_00370C60 = t;
            func_00273F08(1, 0);
            break;
        }
        case 0:
            func_00275EE8(0xD7BB618D, 0);
            D_00370C38 = 0;
            func_00273F08(0, 0);
            break;
        }
    }
}

GP_DATA(D_00370C18);
extern "C" void func_0026C940(f32 f) {
    if (func_0026ABA8() == 0 && !(f > 100.0f) && !(f < 0.0f)) {
        D_00370C1C = f;
        if (D_00370C30 != 0 && D_00370C40 == 0 && (D_00370C18 == 0 || func_00275EE8(0x450BAE2D, 0) != 0)) {
            func_00273070(f);
        }
    }
}

extern "C" f32 func_0026C9E0(void) {
    return D_00370C1C;
}

extern "C" void func_0026C9E8(f32 f) {
    if (func_0026ABA8() == 0 && !(f > 100.0f) && !(f < 0.0f)) {
        D_00370C20 = f;
        if (D_00370C30 != 0 && D_00370C40 == 1) {
            func_00273070(f);
        }
    }
}

extern "C" f32 func_0026CA70(void) {
    return D_00370C20;
}

struct S26CA_R {
    char b[0x12];
};

extern "C" {
extern char D_003A47B0[];
extern S26CA_R D_00358940;
unsigned int strlen(const char *);
char *strcpy(char *, const char *);
int func_00274178(char *, int);
void func_0030ADA0(void *, int, int);
}

extern "C" void func_0026CA78(char *name, int idx, int data) {
    if (func_0026ABA8() == 0) {
        char *e = D_003A66F0 + idx * 0xCB0;
        int n = *(int *)(e + 0xC80);
        if (n < 0x50) {
            u32 i = 0;
            char *dst = e + n * 0x28;
            strcpy(dst, name);
            char *p = dst;
            while (i < strlen(dst)) {
                u8 c = *p;
                if ((u8)(c - 0x61) < 0x1A) {
                    *p = c - 0x20;
                }
                p++;
                i++;
            }
            if (idx == 0) {
                char *r = D_003A47B0 + *(int *)(e + 0xC80) * 0x64;
                if (data) {
                    func_0030ADA0(r, data, 0x64);
                    r[0x63] = 0;
                } else {
                    *(S26CA_R *)r = D_00358940;
                }
            }
            if (func_00274178(dst, 1)) {
                *(int *)(e + 0xCA8) = 0;
                *(int *)(e + 0xC80) = *(int *)(e + 0xC80) + 1;
            }
        }
    }
}

extern "C" void func_0026CBE8(int a) {
    if (func_0026ABA8() == 0) {
        char *p = D_003A66F0 + a * 0xCB0;
        *(int *)(p + 0xCA8) = 1;
        *(int *)(p + 0xC80) = 0;
        *(u64 *)(p + 0xC88) = 0;
        *(u64 *)(p + 0xC90) = 0;
        *(u64 *)(p + 0xC98) = 0;
        *(u64 *)(p + 0xCA0) = 0;
    }
}

GP_DATA(D_00370C18);
extern "C" void func_0026CC48(void) {
    if (func_0026ABA8() == 0 && D_00370C18 == 0) {
        func_0026AE70();
    }
}

GP_DATA(D_00370C24);
extern "C" void func_0026CC80(int a) {
    if (func_0026ABA8() == 0) {
        D_00370C24 = a != 0;
        char *p = D_003A66F0 + D_00370C18 * 0xCB0;
        *(u64 *)(p + 0xC98) = 0;
        *(u64 *)(p + 0xCA0) = 0;
    }
}

extern "C" void func_0026CCD8(int v) {
    D_00370C28 = v;
}

extern "C" void func_0026CCE0(void) {
    int r = func_00275EE8(0x450BAE2D, 0);
    if (D_00370C18 == 1 && r == 0) {
        func_00273070(func_00268328(D_00370AE0));
    }
}

INCLUDE_ASM("asm/nonmatchings/game/t_26AEF8", func_0026CD30);
