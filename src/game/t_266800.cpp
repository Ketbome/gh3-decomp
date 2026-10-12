// cflags: -funroll-loops
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

struct S2668_Ent {
    char pad0[0x8];
    int unk8;
    char padC[0xC];
};

struct S2668_Src {
    int unk0;
    f32 unk4;
    f32 unk8;
    f32 unkC;
    int unk10;
    int unk14;
};

struct S2668_Ctx {
    int unk0;
    char pad4[0xC];
    f32 unk10;
};

struct S2668_Out {
    int unk0;
    int unk4;
    int unk8;
    f32 unkC;
    f32 unk10;
    f32 unk14;
    f32 unk18;
    f32 unk1C;
    f32 unk20;
    f32 unk24;
    f32 unk28;
    f32 unk2C;
    int unk30;
};

extern "C" {
extern int D_00370AF0;
extern int D_00370B00;
extern int D_00370AF4;
extern S2668_Ent D_003A2820[128];
void func_002709C8(void);
extern int D_00370AEC;
void func_0026FA38(int);
void func_0026FA78(void);
int func_0030A49C(int, int, int);
int func_00266778(void);
extern float D_00370AE8;
extern int D_00369CD8;
extern int D_00369A64;
extern f32 D_00370B04;
extern f32 D_00370B08;
extern f32 D_00368764;
void func_00275EE8(u32, int);
void func_0026F580(f32);
void func_0026D688(f32);
void func_0026F5A8(f32);
void func_0026D6B0(f32);
extern int D_00368A38[] __attribute__((section(".sdata")));
void func_00119400(int, void *);
extern int D_00370AE0;
extern int D_00370AE4;
void func_00266F50(int, int);
int func_00113DF0(int, int, int);
int func_00266E90(int);
}

GP_DATA(D_00370AE0);
GP_DATA(D_00370AE4);
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

GP_DATA(D_00370AF0);
GP_DATA(D_00370B00);
GP_DATA(D_00370AF4);
GP_DATA(D_00370AE8);
extern "C" void func_00266FA8(void) {
    if (func_00266778() == 0) {
        D_00370AF0 = 0;
        D_00370B00 = 0;
        for (int i = 127; i >= 0; i--) {
            D_003A2820[i].unk8 = 0;
        }
        func_002709C8();
        D_00370AF4 = 0;
        D_00370AE8 = 25.0f;
    }
}

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

extern "C" void func_00267B30(int unused, S2668_Out *out, S2668_Ctx *ctx, S2668_Src *src) {
    if (src) {
        out->unk0 = src->unk0;
        f32 x = src->unk4;
        out->unk10 = x;
        f32 y = src->unk8;
        out->unk14 = y;
        f32 z = src->unkC;
        if (z == 0.0f) {
            z = ctx->unk10;
        }
        out->unkC = z;
        out->unk20 = x;
        out->unk24 = y;
        out->unk28 = 0.0f;
        out->unk18 = x;
        out->unk1C = y;
        out->unk2C = 0.0f;
        out->unk30 = src->unk10;
        out->unk8 = src->unk14;
    } else {
        out->unk0 = 0;
        out->unk14 = out->unk10 = 100.0f;
        out->unkC = 0.0f;
        out->unk30 = 0;
        out->unk8 = 0;
    }
    out->unk4 = ctx->unk0;
}

INCLUDE_ASM("asm/nonmatchings/game/t_266800", func_00267BC8);

extern "C" int func_00267F00(void) {
    return -1;
}

INCLUDE_ASM("asm/nonmatchings/game/t_266800", func_00267F08);

INCLUDE_ASM("asm/nonmatchings/game/t_266800", func_002680D0);

INCLUDE_ASM("asm/nonmatchings/game/t_266800", func_00268130);

INCLUDE_ASM("asm/nonmatchings/game/t_266800", func_002681B0);

GP_DATA(D_00370B04);
extern "C" void func_00268228(f32 f) {
    if (func_00266778() == 0) {
        func_00275EE8(0xD7BB618D, 0);
        D_00370B04 = f;
        f = f * D_00368764 * 0.01f;
        if (f < 0.1f) {
            f = 0.0f;
        }
        func_0026F580(f);
        func_0026D688(f);
    }
}

extern "C" void func_002682B8(f32 f) {
    if (func_00266778() == 0) {
        func_00275EE8(0xD7BB618D, 0);
        if (f <= 0.01f) {
            f = 0.01f;
        }
        D_00370B08 = f;
        func_0026F5A8(f);
        func_0026D6B0(f);
    }
}

extern "C" f32 func_00268328(void) {
    return D_00370B04;
}

INCLUDE_ASM("asm/nonmatchings/game/t_266800", func_00268330);

INCLUDE_ASM("asm/nonmatchings/game/t_266800", func_00268388);

INCLUDE_ASM("asm/nonmatchings/game/t_266800", func_00268468);

INCLUDE_ASM("asm/nonmatchings/game/t_266800", func_00268480);

INCLUDE_ASM("asm/nonmatchings/game/t_266800", func_002684D8);

INCLUDE_ASM("asm/nonmatchings/game/t_266800", func_002687F0);
