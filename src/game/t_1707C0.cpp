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

INCLUDE_ASM("asm/nonmatchings/game/t_1707C0", func_00171708);

typedef unsigned int u128_171 __attribute__((mode(TI)));

static inline u128_171 MakeVec171(f32 x, f32 y, f32 z, f32 w) {
    u128_171 lo, hi;
    asm("pextlw %0, %2, %1" : "=r"(lo) : "r"(x), "r"(y));
    asm("pextlw %0, %2, %1" : "=r"(hi) : "r"(z), "r"(w));
    asm("pcpyld %0, %1, %2" : "=r"(lo) : "r"(hi), "0"(lo));
    return lo;
}

struct S_00171928 { u32 unk0; char pad4[0x14]; float unk18; float unk1C; float unk20; float unk24; char pad28[8]; u128_171 unk30; u128_171 unk40; u128_171 unk50; char pad60[0x10]; int unk70; };

extern "C" {
int func_0027D1F8(int, u32, int*, int);
int func_0027D268(int, u32, float*, int);
int func_0027D470(int, u32, int*, int);
float func_0027EFA0(int, int);
int func_003174C0(float);
}

extern "C" int func_00171928(S_00171928* self, int props) {
    int sp0;
    float sp4;
    int sp8, spC, sp10;
    float sp14;
    if (func_0027D1F8(props, 0xF649D637, &sp0, 0)) {
        self->unk70 = sp0 > 0;
    }
    if (func_0027D268(props, 0xD5D55277, &sp4, 0)) {
        self->unk1C = sp4;
    }
    if (func_0027D268(props, 0x2689291C, &sp4, 0)) {
        self->unk18 = sp4;
    }
    if (func_0027D268(props, 0x5CB2C5F7, &sp4, 0)) {
        self->unk20 = sp4;
    }
    if (func_0027D268(props, 0x29EAA411, &sp4, 0)) {
        self->unk24 = sp4;
    }
    sp8 = 0;
    spC = 0;
    sp10 = 0;
    if (func_0027D470(props, 0x146FC080, &sp8, 0)) {
        float x = func_0027EFA0(sp8, 0);
        float y = func_0027EFA0(sp8, 1);
        float z = func_0027EFA0(sp8, 2);
        self->unk30 = MakeVec171(x, y, z, 0.0f);
    }
    if (func_0027D470(props, 0x51B4CB31, &spC, 0)) {
        float x = func_0027EFA0(spC, 0);
        float y = func_0027EFA0(spC, 1);
        float z = func_0027EFA0(spC, 2);
        self->unk40 = MakeVec171(x, y, z, 0.0f);
    }
    if (func_0027D470(props, 0x77B8ABE9, &sp10, 0)) {
        float x = func_0027EFA0(sp10, 0);
        float y = func_0027EFA0(sp10, 1);
        float z = func_0027EFA0(sp10, 2);
        self->unk50 = MakeVec171(x, y, z, 0.0f);
    }
    sp14 = 0.0f;
    func_0027D268(props, 0x906B67BA, &sp14, 0);
    self->unk0 = func_003174C0(sp14 * 1000.0f);
    return 1;
}

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
