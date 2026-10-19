#include "common.h"

extern "C" {
void func_001999C8(void);
void func_00199AA0(void);
void func_00199B88(void);
int func_0011EF10(void);
extern char D_003403C0[];
extern char D_00347628[];
}

INCLUDE_ASM("asm/nonmatchings/game/t_1707C0", func_001707C0);

INCLUDE_ASM("asm/nonmatchings/game/t_1707C0", func_001708F8);

INCLUDE_ASM("asm/nonmatchings/game/t_1707C0", func_00170940);

INCLUDE_ASM("asm/nonmatchings/game/t_1707C0", func_00170B00);

extern "C" void func_001711B8(void) {
    func_001999C8();
}

INCLUDE_ASM("asm/nonmatchings/game/t_1707C0", func_001711D8);

typedef unsigned int TI171 __attribute__((mode(TI)));
struct M171 { TI171 r0, r1, r2, r3; };
struct S171 {
    int unk0;
    int unk4;
    int unk8;
    int unkC;
    int unk10;
    void* unk14;
    f32 unk18;
    f32 unk1C;
    f32 unk20;
    int unk24;
    char pad28[8];
    M171 m;
    int unk70;
};

extern "C" S171* func_00171540(S171* self) {
    self->unk0 = 0;
    self->unk8 = 0;
    self->unkC = 0;
    self->unk10 = 0;
    self->unk14 = D_003403C0;
    self->unk4 = func_0011EF10();
    self->unk14 = D_00347628;
    M171* m = &self->m;
    self->unk20 = 1.0f;
    m->r1 = (u64)0xFE00 << 46;
    self->unk1C = 1.0f;
    self->m.r0 = 0x3F800000;
    self->unk24 = 0;
    self->unk18 = 1.0f;
    m->r2 = (TI171)0x3F800000 << 64;
    m->r3 = (TI171)((u64)0xFE00 << 46) << 64;
    self->unk70 = 0;
    return self;
}

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
