#include "common.h"

struct S001A9D98 {
    char pad[0x1C];
    int unk1C;
};

typedef unsigned int u128_1A9 __attribute__((mode(TI)));
struct S_1A9 { u128_1A9 unk0; char pad10[0xC]; int unk1C; void* unk20; char pad24[4]; void* unk28; char pad2C[8]; int unk34; };
struct Q50_1A9 { u128_1A9 v[5]; };

extern "C" {
u128_1A9 func_001AF7C0(S_1A9*);
}

extern "C" void func_001A9A60(S_1A9* self, S_1A9* owner) {
    u32 f = self->unk1C;
    if (f & 2) {
        self->unk28 = 0;
        self->unk1C = f & ~2u;
    } else {
        self->unk28 = owner->unk20;
    }
    owner->unk20 = self;
}

INCLUDE_ASM("asm/nonmatchings/game/t_1A9A60", func_001A9A98);

INCLUDE_ASM("asm/nonmatchings/game/t_1A9A60", func_001A9B08);

INCLUDE_ASM("asm/nonmatchings/game/t_1A9A60", func_001A9B80);

INCLUDE_ASM("asm/nonmatchings/game/t_1A9A60", func_001A9C68);

extern "C" Q50_1A9* func_001A9CF0(Q50_1A9* dst, Q50_1A9* src) {
    *dst = *src;
    return dst;
}

extern "C" void func_001A9D28(S_1A9* self, int x) {
    if (!(self->unk1C & 0x200)) {
        self->unk34 = x;
        self->unk0 = func_001AF7C0(self);
    }
}

extern "C" void func_001A9D68(S_1A9* self, int b) {
    if (b) {
        self->unk1C |= 0x4000000;
    } else {
        self->unk1C &= ~0x4000000;
    }
}

extern "C" int func_001A9D98(S001A9D98* self) {
    return ((self->unk1C >> 26) & 1);
}

INCLUDE_ASM("asm/nonmatchings/game/t_1A9A60", func_001A9DA8);

INCLUDE_ASM("asm/nonmatchings/game/t_1A9A60", func_001A9E78);

INCLUDE_ASM("asm/nonmatchings/game/t_1A9A60", func_001A9ED0);

INCLUDE_ASM("asm/nonmatchings/game/t_1A9A60", func_001A9F70);

INCLUDE_ASM("asm/nonmatchings/game/t_1A9A60", func_001AA448);

INCLUDE_ASM("asm/nonmatchings/game/t_1A9A60", func_001AAB00);
