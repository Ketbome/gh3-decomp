#include "common.h"

extern "C" {
void func_001999C8(void);
void func_00199AA0(void);
void func_00199B88(void);
float func_0016FCD8(void);
void func_001993D8(void*, void*, int);
void func_001994A0(void*, void*, int);
}

typedef unsigned int u128_170 __attribute__((mode(TI)));

struct S170940 {
    char pad0[0x10];
    int unk10;
    char pad14[4];
    float f[7];
    char pad34[0xC];
    u128_170 unk40;
    u128_170 unk50;
    char pad60[4];
    int unk64;
    char pad68[0x4CA4];
    s8 unk4D0C;
    char pad4D0D[3];
    int unk4D10;
    int unk4D14;
};

INCLUDE_ASM("asm/nonmatchings/game/t_1707C0", func_001707C0);

INCLUDE_ASM("asm/nonmatchings/game/t_1707C0", func_001708F8);

extern "C" int func_00170940(S170940* self, int a1, S170940* o) {
    int r = 0;
    float t = func_0016FCD8();
    if (t >= 0.0f) {
        int v = o->unk4D10;
        self->unk4D10 = v;
        if (v == 0) self->unk4D0C = 0;
        r = 1;
        float b0 = o->f[0];
        float a0 = self->f[0];
        float n0 = a0 + (b0 - a0) * t;
        float a1f = self->f[1], a2 = self->f[2], a3 = self->f[3], a4 = self->f[4], a5 = self->f[5], a6 = self->f[6];
        int tmp;
        asm volatile("lqc2 $vf2, 0x40(%0)" : : "r"(self));
        asm volatile("lqc2 $vf3, 0x50(%0)" : : "r"(self));
        asm volatile("mfc1 %0, %1\n\tqmtc2.ni %0, $vf4" : "=&r"(tmp) : "f"(t));
        self->f[0] = n0;
        self->f[1] = a1f + (o->f[1] - a1f) * t;
        self->f[2] = a2 + (o->f[2] - a2) * t;
        self->f[3] = a3 + (o->f[3] - a3) * t;
        self->f[4] = a4 + (o->f[4] - a4) * t;
        self->f[5] = a5 + (o->f[5] - a5) * t;
        self->f[6] = a6 + (o->f[6] - a6) * t;
        asm volatile("lqc2 $vf1, 0x40(%0)" : : "r"(o));
        asm volatile("vsub.xyzw $vf1, $vf1, $vf2");
        asm volatile("vmulx.xyzw $vf1, $vf1, $vf4x");
        asm volatile("vadd.xyzw $vf2, $vf2, $vf1");
        asm volatile("sqc2 $vf2, 0x40(%0)" : : "r"(self) : "memory");
        asm volatile("lqc2 $vf1, 0x50(%0)" : : "r"(o));
        asm volatile("vsub.xyzw $vf1, $vf1, $vf3");
        self->unk64 = 1;
        asm volatile("vmulx.xyzw $vf1, $vf1, $vf4x");
        asm volatile("vadd.xyzw $vf3, $vf3, $vf1");
        asm volatile("sqc2 $vf3, 0x50(%0)" : : "r"(self) : "memory");
    }
    if (self->unk4D14 == 0) {
        func_001993D8(self, &self->unk64, self->unk10);
        self->unk4D14 = 1;
    }
    if (self->unk64 != 0) {
        self->unk64 = 0;
        func_001994A0(self, &self->unk64, self->unk10);
    }
    if (self->unk4D10 != 0) {
        if (self->unk4D0C < 2) self->unk4D0C = (u8)self->unk4D0C + 1;
    }
    return r;
}

INCLUDE_ASM("asm/nonmatchings/game/t_1707C0", func_00170B00);

extern "C" void func_001711B8(void) {
    func_001999C8();
}

INCLUDE_ASM("asm/nonmatchings/game/t_1707C0", func_001711D8);

INCLUDE_ASM("asm/nonmatchings/game/t_1707C0", func_00171540);

INCLUDE_ASM("asm/nonmatchings/game/t_1707C0", func_001715F8);

INCLUDE_ASM("asm/nonmatchings/game/t_1707C0", func_00171708);

INCLUDE_ASM("asm/nonmatchings/game/t_1707C0", func_00171928);

extern "C" void func_00171BB0(void) {
    func_00199AA0();
}

INCLUDE_ASM("asm/nonmatchings/game/t_1707C0", func_00171BD0);

INCLUDE_ASM("asm/nonmatchings/game/t_1707C0", func_00171E60);

struct S171F08 { char pad0[0x18]; int unk18; char pad1C[8]; float unk24; };

extern "C" int func_00171F08(S171F08* self) {
    int r = 0;
    if (self->unk18 != 0 && self->unk24 > 0.0f) r = 1;
    return r;
}

INCLUDE_ASM("asm/nonmatchings/game/t_1707C0", func_00171F38);

INCLUDE_ASM("asm/nonmatchings/game/t_1707C0", func_00172098);

extern "C" void func_001724D0(void) {
    func_00199B88();
}

INCLUDE_ASM("asm/nonmatchings/game/t_1707C0", func_001724F0);
