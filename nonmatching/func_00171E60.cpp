#include "common.h"

typedef int TI128 __attribute__((mode(TI)));

static inline TI128 MakeVec(f32 x, f32 y, f32 z, f32 w) {
    TI128 lo, hi;
    asm("pextlw %0, %1, %2" : "=r"(lo) : "r"(y), "r"(x));
    asm("pextlw %0, %1, %2" : "=r"(hi) : "r"(w), "r"(z));
    asm("pcpyld %0, %1, %2" : "=r"(lo) : "r"(hi), "0"(lo));
    return lo;
}

struct S171E60 {
    int unk0;
    int unk4;
    int unk8;
    int unkC;
    int unk10;
    void* unk14;
    int unk18;
    f32 unk1C;
    f32 unk20;
    f32 unk24;
    f32 unk28;
    char pad2C[4];
    TI128 unk30;
    char pad40[0x0];
    TI128 unk40;
    int unk50;
    f32 unk54;
    int unk58;
    int unk5C;
    int unk60;
};

extern "C" {
int func_0011EF10(void);
extern u8 D_003403C0[];
extern u8 D_00347798[];
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

INCLUDE_ASM("asm/nonmatchings/game/t_1707C0", func_00171928);

extern "C" void func_00171BB0(void) {
    func_00199AA0();
}

INCLUDE_ASM("asm/nonmatchings/game/t_1707C0", func_00171BD0);

extern "C" S171E60* func_00171E60(S171E60* self) {
    self->unk0 = 0;
    self->unk8 = 0;
    self->unkC = 0;
    self->unk10 = 0;
    self->unk14 = D_003403C0;
    self->unk4 = func_0011EF10();
    TI128 v = MakeVec(0.0f, 0.0f, 0.0f, 0.0f);
    self->unk14 = D_00347798;
    self->unk40 = v;
    self->unk28 = 0.0f;
    self->unk54 = 6.0f;
    self->unk5C = 1;
    self->unk30 = v;
    self->unk18 = 0;
    self->unk1C = 0.0f;
    self->unk20 = 0.0f;
    self->unk24 = 0.0f;
    self->unk50 = 1;
    self->unk58 = 1;
    self->unk60 = 0;
    return self;
}

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
