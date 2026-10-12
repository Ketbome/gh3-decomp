#include "common.h"

struct S001AFAC8 {
    char pad0[0x1C];
    u32 unk1C;
    char pad20[0x14];
    f32* unk34;
};

INCLUDE_ASM("asm/nonmatchings/game/t_1ADBA8", func_001ADBA8);

INCLUDE_ASM("asm/nonmatchings/game/t_1ADBA8", func_001ADC90);

INCLUDE_ASM("asm/nonmatchings/game/t_1ADBA8", func_001ADF60);

INCLUDE_ASM("asm/nonmatchings/game/t_1ADBA8", func_001AE1D8);

INCLUDE_ASM("asm/nonmatchings/game/t_1ADBA8", func_001AE520);

INCLUDE_ASM("asm/nonmatchings/game/t_1ADBA8", func_001AE7A0);

INCLUDE_ASM("asm/nonmatchings/game/t_1ADBA8", func_001AEB80);

INCLUDE_ASM("asm/nonmatchings/game/t_1ADBA8", func_001AEFF0);

INCLUDE_ASM("asm/nonmatchings/game/t_1ADBA8", func_001AF090);

INCLUDE_ASM("asm/nonmatchings/game/t_1ADBA8", func_001AF130);

INCLUDE_ASM("asm/nonmatchings/game/t_1ADBA8", func_001AF3C8);

INCLUDE_ASM("asm/nonmatchings/game/t_1ADBA8", func_001AF608);

INCLUDE_ASM("asm/nonmatchings/game/t_1ADBA8", func_001AF7C0);

INCLUDE_ASM("asm/nonmatchings/game/t_1ADBA8", func_001AF990);

extern "C" void func_001AFAC8(S001AFAC8* p, f32 a, f32 b, f32 c, f32 d, f32 e, f32 f, f32 g, f32 h) {
    p->unk34[0] = a;
    p->unk34[1] = e;
    p->unk34[2] = c;
    p->unk34[3] = g;
    p->unk34[4] = b;
    p->unk34[5] = f;
    p->unk34[6] = d;
    p->unk34[7] = h;
}

extern "C" void func_001AFB10(S001AFAC8* p, s32 v) {
    p->unk1C = v ? p->unk1C | 0x10000 : p->unk1C & ~0x10000;
}

extern "C" void func_001AFB40(S001AFAC8* p, f32 a, f32 b) {
    p->unk34[8] = a;
    p->unk34[9] = b;
}

INCLUDE_ASM("asm/nonmatchings/game/t_1ADBA8", func_001AFB58);
