#include "common.h"

struct S00267628 {
    char pad[0x4];
    int unk4;
};

struct S266800_A {
    f32 unk0;
    f32 unk4;
    f32 unk8;
    f32 unkC;
    f32 unk10;
    int unk14;
};

extern "C" {
extern int D_00370AEC;
void func_0026FA38(int);
void func_0026FA78(void);
int func_0030A49C(int, int, int);
int func_00266778(void);
extern float D_00370AE8;
extern int D_00369CD8;
extern int D_00369A64;
extern f32 D_00370B04;
extern int D_00368A38[] __attribute__((section(".sdata")));
void func_00119400(int, void *);
extern int D_00370AE0;
extern int D_00370AE4;
void func_00266F50(int, int);
int func_00113DF0(int, int, int);
int func_00266E90(int);
}

extern "C" int func_00266800(int a) {
    if (D_00370AE0 == 0 && a != 0) {
        D_00370AE0 = func_00266E90(func_00113DF0(0xC, 0, 1));
    }
    D_00370AE4++;
    return D_00370AE0;
}

extern "C" void func_00266850(void) {
    if ((u32)D_00370AE4 >= 2) {
        D_00370AE4--;
    } else {
        if (D_00370AE0 != 0) {
            func_00266F50(D_00370AE0, 3);
        }
        D_00370AE0 = 0;
        D_00370AE4 = 0;
    }
}

INCLUDE_ASM("asm/nonmatchings/game/t_266800", func_00266898);

INCLUDE_ASM("asm/nonmatchings/game/t_266800", func_002668E8);

extern "C" void func_002668F8(void *p, int flags) {
    if (flags & 1) {
        func_00119400(D_00368A38[0], p);
    }
}

INCLUDE_ASM("asm/nonmatchings/game/t_266800", func_00266928);

INCLUDE_ASM("asm/nonmatchings/game/t_266800", func_00266A20);

extern "C" int func_00266B60(S266800_A *p) {
    if (p->unk0 != 0.0f || p->unk4 != 0.0f) {
        return 0;
    }
    if (p->unk14 == 2) {
        if (p->unk8 != 0.0f || p->unkC != 0.0f || p->unk10 != 0.0f) {
            return 0;
        }
    }
    return 1;
}

extern "C" void func_00266BE8(int a) {
    func_0030A49C(a, 0, 20);
}

INCLUDE_ASM("asm/nonmatchings/game/t_266800", func_00266C08);

INCLUDE_ASM("asm/nonmatchings/game/t_266800", func_00266CE0);

INCLUDE_ASM("asm/nonmatchings/game/t_266800", func_00266D20);

INCLUDE_ASM("asm/nonmatchings/game/t_266800", func_00266E08);

INCLUDE_ASM("asm/nonmatchings/game/t_266800", func_00266E90);

INCLUDE_ASM("asm/nonmatchings/game/t_266800", func_00266F50);

INCLUDE_ASM("asm/nonmatchings/game/t_266800", func_00266FA8);

INCLUDE_ASM("asm/nonmatchings/game/t_266800", func_00267048);

INCLUDE_ASM("asm/nonmatchings/game/t_266800", func_002670B0);

INCLUDE_ASM("asm/nonmatchings/game/t_266800", func_002672C0);

extern "C" void func_00267310(float v) {
    if (func_00266778() == 0) {
        D_00370AE8 = v;
    }
}

INCLUDE_ASM("asm/nonmatchings/game/t_266800", func_00267340);

INCLUDE_ASM("asm/nonmatchings/game/t_266800", func_00267348);

INCLUDE_ASM("asm/nonmatchings/game/t_266800", func_00267610);

extern "C" int func_00267628(S00267628* p) {
    if (p->unk4 != 0) {
        return 0;
    }
    if (D_00369CD8 != 0) {
        return 1;
    }
    return D_00369A64 != 0;
}

INCLUDE_ASM("asm/nonmatchings/game/t_266800", func_00267658);

INCLUDE_ASM("asm/nonmatchings/game/t_266800", func_00267660);

INCLUDE_ASM("asm/nonmatchings/game/t_266800", func_002676F0);

INCLUDE_ASM("asm/nonmatchings/game/t_266800", func_00267750);

extern "C" void func_00267758(void* p, int v) {
    D_00370AEC = v;
}

INCLUDE_ASM("asm/nonmatchings/game/t_266800", func_00267760);

INCLUDE_ASM("asm/nonmatchings/game/t_266800", func_002677E0);

extern "C" void func_002678F0(int a, int b) {
    func_0026FA38(b);
}

INCLUDE_ASM("asm/nonmatchings/game/t_266800", func_00267910);

extern "C" void func_002679E0(void) {
    func_0026FA78();
}

INCLUDE_ASM("asm/nonmatchings/game/t_266800", func_00267A00);

INCLUDE_ASM("asm/nonmatchings/game/t_266800", func_00267A60);

INCLUDE_ASM("asm/nonmatchings/game/t_266800", func_00267A80);

INCLUDE_ASM("asm/nonmatchings/game/t_266800", func_00267B30);

INCLUDE_ASM("asm/nonmatchings/game/t_266800", func_00267BC8);

extern "C" int func_00267F00(void) {
    return -1;
}

INCLUDE_ASM("asm/nonmatchings/game/t_266800", func_00267F08);

INCLUDE_ASM("asm/nonmatchings/game/t_266800", func_002680D0);

INCLUDE_ASM("asm/nonmatchings/game/t_266800", func_00268130);

INCLUDE_ASM("asm/nonmatchings/game/t_266800", func_002681B0);

INCLUDE_ASM("asm/nonmatchings/game/t_266800", func_00268228);

INCLUDE_ASM("asm/nonmatchings/game/t_266800", func_002682B8);

extern "C" f32 func_00268328(void) {
    return D_00370B04;
}

INCLUDE_ASM("asm/nonmatchings/game/t_266800", func_00268330);

INCLUDE_ASM("asm/nonmatchings/game/t_266800", func_00268388);

INCLUDE_ASM("asm/nonmatchings/game/t_266800", func_00268468);

INCLUDE_ASM("asm/nonmatchings/game/t_266800", func_00268480);

INCLUDE_ASM("asm/nonmatchings/game/t_266800", func_002684D8);

INCLUDE_ASM("asm/nonmatchings/game/t_266800", func_002687F0);
