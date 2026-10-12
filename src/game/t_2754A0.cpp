#include "common.h"

struct S002754A0 {
    char pad[0x4];
    int unk4;
    char pad1[0xF0];
    int unkF8;
    int unkFC;
};

struct S2754A0_A {
    char pad0[0x1];
    u8 unk1;
    char pad2[0x2];
    f32 unk4;
    f32 unk8;
    f32 unkC;
};

struct S2754A0_B {
    char pad0[0x4];
    int unk4;
    char pad8[0x8];
    S2754A0_B *unk10;
};

struct S2754A0_C {
    u32 b0 : 8;
    u32 b8 : 1;
    u32 b9 : 1;
    u32 b10 : 6;
    u32 b16 : 8;
    u32 b24 : 8;
    int unk4;
    int unk8;
    int unkC;
    int unk10;
};

struct S2754A0_D {
    u32 unk0;
    int unk4;
    int unk8;
    int unkC;
    int unk10;
    S2754A0_D *unk14;
};

struct S2754A0_E {
    u32 lo : 9;
    u32 f : 7;
    u32 hi : 16;
};
extern "C" {
extern int D_003710A0;
extern char D_00359058[];
void func_0011A470(void);
void func_00275A40(void);
void func_00275DE0(void);
void func_00275F08(int, int);
void func_00276110(void);
void func_002762F0(void);
void func_002763E0(void);
void func_002764E8(void);
void func_00276600(int, int);
void func_00276D68(void);
extern S2754A0_B **D_003710A4;
extern S2754A0_D *D_003710B4;
extern f32 D_00370F48;
extern int D_00370F40;
extern int D_00370F44;
void func_00275540(void);
int func_00275570(void);
void func_0011ED28(f32);
int func_0011EF10(void);
}

extern "C" void func_002754A0(S002754A0* p, int v) {
    p->unkF8 = v;
    p->unkFC = 0;
}

extern "C" void func_002754B0(S002754A0* p) {
    p->unk4 = 1;
}

INCLUDE_ASM("asm/nonmatchings/game/t_2754A0", func_002754C0);

extern "C" void func_00275510(f32 f) {
    func_00275540();
    D_00370F48 = f;
    func_0011ED28(f);
}

extern "C" void func_00275540(void) {
    D_00370F40 += func_00275570();
    D_00370F44 = func_0011EF10();
}

INCLUDE_ASM("asm/nonmatchings/game/t_2754A0", func_00275570);

extern "C" void* func_002755E0(void) {
    return D_00359058;
}

extern "C" S2754A0_A *func_002755F0(S2754A0_A *p) {
    p->unk1 = 0;
    p->unk4 = p->unk8 = p->unkC = 0.0f;
    return p;
}

INCLUDE_ASM("asm/nonmatchings/game/t_2754A0", func_00275610);

extern "C" S2754A0_A *func_00275648(S2754A0_A *p) {
    p->unk1 = 0;
    p->unk4 = p->unk8 = 0.0f;
    return p;
}

INCLUDE_ASM("asm/nonmatchings/game/t_2754A0", func_00275660);

extern "C" int func_00275688(void) {
    return 0;
}

extern "C" int func_00275690(void) {
    return 0;
}

extern "C" void func_00275698(void) {
}

extern "C" void func_002756A0(void) {
}

INCLUDE_ASM("asm/nonmatchings/game/t_2754A0", func_002756A8);

extern "C" void func_00275730(void) {
    func_0011A470();
}

extern "C" int func_00275750(u32 *p) {
    u32 v = *p & 0xFE00;
    if (v == 0x2800 || v == 0x2A00) {
        return 1;
    }
    return 0;
}

extern "C" void func_00275780(S2754A0_E *p) {
    switch (p->f) {
    case 10:
        p->f = 20;
        break;
    case 12:
        p->f = 21;
        break;
    }
}

extern "C" void func_002757D8(S2754A0_E *p) {
    switch (p->f) {
    case 20:
        p->f = 10;
        break;
    case 21:
        p->f = 12;
        break;
    }
}

INCLUDE_ASM("asm/nonmatchings/game/t_2754A0", func_00275830);

extern "C" void func_00275868(S2754A0_C *p) {
    p->unk8 = 0;
    p->unk4 = 0;
    p->unkC = 0;
    p->unk10 = 0;
    p->b8 = 0;
    p->b9 = 0;
    p->b16 = 0;
}

INCLUDE_ASM("asm/nonmatchings/game/t_2754A0", func_00275898);

INCLUDE_ASM("asm/nonmatchings/game/t_2754A0", func_00275978);

extern "C" void func_00275988(S2754A0_B *p) {
    S2754A0_B **t = D_003710A4;
    int i = p->unk4 & 0x7FFF;
    S2754A0_B *prev = 0;
    S2754A0_B *n;
    for (n = t[i]; n != 0; n = n->unk10) {
        if (n == p) {
            if (prev) {
                prev->unk10 = n->unk10;
            } else {
                t[i] = n->unk10;
            }
            n->unk10 = 0;
            return;
        }
        prev = n;
    }
}

INCLUDE_ASM("asm/nonmatchings/game/t_2754A0", func_002759E8);

extern "C" void func_002759F0(int v) {
    D_003710A0 = v;
}

extern "C" S2754A0_B *func_002759F8(S2754A0_B *p) {
    S2754A0_B **t = D_003710A4;
    int i = p->unk4 & 0x7FFF;
    p->unk10 = t[i];
    t[i] = p;
    return p;
}

extern "C" void func_00275A20(void) {
    func_00275A40();
}

INCLUDE_ASM("asm/nonmatchings/game/t_2754A0", func_00275A40);

INCLUDE_ASM("asm/nonmatchings/game/t_2754A0", func_00275A90);

INCLUDE_ASM("asm/nonmatchings/game/t_2754A0", func_00275BC8);

INCLUDE_ASM("asm/nonmatchings/game/t_2754A0", func_00275BD0);

INCLUDE_ASM("asm/nonmatchings/game/t_2754A0", func_00275CE8);

extern "C" void func_00275DC0(void) {
    func_00275DE0();
}

INCLUDE_ASM("asm/nonmatchings/game/t_2754A0", func_00275DE0);

extern "C" void func_00275EE8(int a, int b) {
    func_00275F08(a, b);
}

INCLUDE_ASM("asm/nonmatchings/game/t_2754A0", func_00275F08);

INCLUDE_ASM("asm/nonmatchings/game/t_2754A0", func_00276008);

INCLUDE_ASM("asm/nonmatchings/game/t_2754A0", func_002760D8);

extern "C" void func_002760E0(void) {
    func_00276110();
}

INCLUDE_ASM("asm/nonmatchings/game/t_2754A0", func_00276100);

INCLUDE_ASM("asm/nonmatchings/game/t_2754A0", func_00276110);

INCLUDE_ASM("asm/nonmatchings/game/t_2754A0", func_002761F8);

extern "C" void func_002762D0(void) {
    func_002762F0();
}

INCLUDE_ASM("asm/nonmatchings/game/t_2754A0", func_002762F0);

extern "C" void func_002763C0(void) {
    func_002763E0();
}

INCLUDE_ASM("asm/nonmatchings/game/t_2754A0", func_002763E0);

extern "C" void func_002764C8(void) {
    func_002764E8();
}

INCLUDE_ASM("asm/nonmatchings/game/t_2754A0", func_002764E8);

INCLUDE_ASM("asm/nonmatchings/game/t_2754A0", func_002765D0);

extern "C" void func_002765E0(int a, int b) {
    func_00276600(a, b);
}

extern "C" void func_00276600(int a, int b) {
    func_00275F08(a, b != 0);
}

INCLUDE_ASM("asm/nonmatchings/game/t_2754A0", func_00276620);

INCLUDE_ASM("asm/nonmatchings/game/t_2754A0", func_00276668);

INCLUDE_ASM("asm/nonmatchings/game/t_2754A0", func_00276698);

INCLUDE_ASM("asm/nonmatchings/game/t_2754A0", func_00276720);

INCLUDE_ASM("asm/nonmatchings/game/t_2754A0", func_002767D8);

INCLUDE_ASM("asm/nonmatchings/game/t_2754A0", func_002769A8);

INCLUDE_ASM("asm/nonmatchings/game/t_2754A0", func_00276BB0);

extern "C" void func_00276D48(void) {
    func_00276D68();
}

INCLUDE_ASM("asm/nonmatchings/game/t_2754A0", func_00276D68);

INCLUDE_ASM("asm/nonmatchings/game/t_2754A0", func_00276DC8);

INCLUDE_ASM("asm/nonmatchings/game/t_2754A0", func_00276E70);

INCLUDE_ASM("asm/nonmatchings/game/t_2754A0", func_00276E88);

INCLUDE_ASM("asm/nonmatchings/game/t_2754A0", func_00276F30);

INCLUDE_ASM("asm/nonmatchings/game/t_2754A0", func_00276FD8);

INCLUDE_ASM("asm/nonmatchings/game/t_2754A0", func_00277080);

INCLUDE_ASM("asm/nonmatchings/game/t_2754A0", func_00277128);

INCLUDE_ASM("asm/nonmatchings/game/t_2754A0", func_002771D0);

extern "C" void func_00277208(void) {
}
TEXT_PAD(16);

INCLUDE_ASM("asm/nonmatchings/game/t_2754A0", func_00277220);

INCLUDE_ASM("asm/nonmatchings/game/t_2754A0", func_00277298);

INCLUDE_ASM("asm/nonmatchings/game/t_2754A0", func_00277368);

INCLUDE_ASM("asm/nonmatchings/game/t_2754A0", func_00277378);
