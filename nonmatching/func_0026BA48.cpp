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

struct S26BA_E {
    int unk0;
    int unk4;
    f32 unk8;
    f32 unkC;
    char pad10[8];
    int unk18;
    char pad1C[8];
    int unk24;
    int unk28;
    int unk2C;
    char pad30[0xC];
    int unk3C;
    int unk40;
    char pad44[0x38];
    int unk7C;
};

extern "C" {
extern S26BA_E D_003A44B0_c[] asm("D_003A44B0");
extern int D_00370C3C;
extern int D_00370C10;
int func_0026B3C8(int, int, int, int, int, int, int, int, f32, int);
void func_0026ACB0(int);
}

GP_DATA(D_00370C3C);
GP_DATA(D_00370C10);
GP_DATA(D_00370C38);
extern "C" int func_0026BA48(int a, int b, int c, int d, int e, int f, f32 fp) {
    if (func_0026ABB0() == 0 && D_00370C3C == 0 && D_00370C38 == 0) {
        if (e == 0) {
            e = a;
        }
        func_0026ACB0(e);
        int r = func_0026B3C8(a, b, c, d, e, f, 0, 0, fp, 0);
        if (r != -1) {
            D_003A44B0_c[r].unkC = 25.0f;
            D_003A44B0_c[r].unk8 = 100.0f;
            D_003A44B0_c[r].unk28 = 0;
            D_003A44B0_c[r].unk2C = 1;
            D_003A44B0_c[r].unk24 = c;
            D_003A44B0_c[r].unk3C = a;
            D_003A44B0_c[r].unk40 = func_0026E138(a, 0);
            D_003A44B0_c[r].unk7C = 0;
            D_00370C10 = r;
            D_003A44B0_c[r].unk18 &= 0xFFFFFFFB;
            return D_003A44B0_c[r].unk4;
        } else {
            return 0;
        }
    }
    return 0;
}

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

INCLUDE_ASM("asm/nonmatchings/game/t_26AEF8", func_0026C250);

INCLUDE_ASM("asm/nonmatchings/game/t_26AEF8", func_0026C3D8);

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

INCLUDE_ASM("asm/nonmatchings/game/t_26AEF8", func_0026CA78);

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
