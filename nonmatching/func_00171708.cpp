#include "common.h"

extern "C" {
void func_001999C8(void);
void func_00199AA0(void);
void func_00199B88(void);
}

INCLUDE_ASM("asm/nonmatchings/game/t_1707C0", func_001707C0);

INCLUDE_ASM("asm/nonmatchings/game/t_1707C0", func_001708F8);

INCLUDE_ASM("asm/nonmatchings/game/t_1707C0", func_00170940);

INCLUDE_ASM("asm/nonmatchings/game/t_1707C0", func_00170B00);

extern "C" void func_001711B8(void) {
    func_001999C8();
}

INCLUDE_ASM("asm/nonmatchings/game/t_1707C0", func_001711D8);

INCLUDE_ASM("asm/nonmatchings/game/t_1707C0", func_00171540);

INCLUDE_ASM("asm/nonmatchings/game/t_1707C0", func_001715F8);

typedef unsigned int TI171 __attribute__((mode(TI)));

struct S171708 {
    char pad0[0x18];
    float unk18, unk1C, unk20, unk24;
    char pad28[8];
    TI171 unk30, unk40, unk50, unk60;
    int unk70;
};

extern "C" float func_0016FCD8(void);
extern "C" unsigned int func_003174C0(float);
extern int D_0036CA94 __attribute__((section(".sdata")));
extern int D_0036CA98 __attribute__((section(".sdata")));

extern "C" int func_00171708(S171708* self, int a1, S171708* o) {
    float t = func_0016FCD8();
    if (t >= 0.0f) {
        self->unk70 = o->unk70;
        float a = self->unk18, b = self->unk1C, c = self->unk20, d = self->unk24;
        self->unk18 = a + (o->unk18 - a) * t;
        self->unk1C = b + (o->unk1C - b) * t;
        self->unk20 = c + (o->unk20 - c) * t;
        float df = d - o->unk24;
        if (df > 0.5f) self->unk24 = d - 1.0f;
        else if (df < -0.5f) self->unk24 = d + 1.0f;
        float e0 = self->unk24;
        float e1 = e0 + (o->unk24 - e0) * t;
        self->unk24 = e1;
        if (e1 < 0.0f) self->unk24 = e1 + 1.0f;
        float e2 = self->unk24;
        if (e2 > 1.0f) self->unk24 = e2 - 1.0f;
        int tmp;
        register TI171 v1 asm("vf1") = o->unk30;
        register TI171 v2 asm("vf2") = self->unk30;
        register TI171 v6 asm("vf6");
        asm("mfc1 %0,%1" : "=r"(tmp) : "f"(t), "j"(v1), "j"(v2));
        asm("vsub.xyzw %0,%0,%1" : "+j"(v1) : "j"(v2) : "memory");
        asm("qmtc2.ni %1,%0" : "=j"(v6) : "r"(tmp));
        register TI171 v3 asm("vf3") = self->unk40;
        asm("vmulx.xyzw %0,%0,%1x" : "+j"(v1) : "j"(v6));
        register TI171 v4 asm("vf4") = self->unk50;
        asm("vadd.xyzw %0,%0,%1" : "+j"(v2) : "j"(v1));
        register TI171 v5 asm("vf5") = self->unk60;
        self->unk30 = v2;
        v1 = o->unk40;
        asm("vsub.xyzw %0,%0,%1" : "+j"(v1) : "j"(v3));
        asm("vmulx.xyzw %0,%0,%1x" : "+j"(v1) : "j"(v6));
        asm("vadd.xyzw %0,%0,%1" : "+j"(v3) : "j"(v1));
        self->unk40 = v3;
        v1 = o->unk50;
        asm("vsub.xyzw %0,%0,%1" : "+j"(v1) : "j"(v4));
        asm("vmulx.xyzw %0,%0,%1x" : "+j"(v1) : "j"(v6));
        asm("vadd.xyzw %0,%0,%1" : "+j"(v4) : "j"(v1));
        self->unk50 = v4;
        v1 = o->unk60;
        asm("vsub.xyzw %0,%0,%1" : "+j"(v1) : "j"(v5));
        asm("vmulx.xyzw %0,%0,%1x" : "+j"(v1) : "j"(v6));
        asm("vadd.xyzw %0,%0,%1" : "+j"(v5) : "j"(v1));
        self->unk60 = v5;
        D_0036CA94 = self->unk70;
        unsigned int r = func_003174C0(self->unk18 * 128.0f);
        unsigned int x = r - 0x80; if (r <= 0x7F) x = 0;
        D_0036CA98 = (x + (x << 8) + (x << 16)) - 0x80000000;
        return 1;
    }
    D_0036CA94 = 0;
    return 0;
}

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
