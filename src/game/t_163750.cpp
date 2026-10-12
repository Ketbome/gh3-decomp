#include "common.h"

typedef unsigned int u128_163 __attribute__((mode(TI)));
struct B2E0_163 { u64 f0 : 13; u64 f13 : 1; u64 f14 : 50; };
struct L_163 { char pad0[0xC]; L_163* unkC; L_163* unk10; void* unk14; };
struct S_00163AD8 { char pad0[0x90]; u128_163 unk90; char padA0[0x238]; int unk2D8; char pad2DC[4]; B2E0_163 unk2E0; };

extern "C" {
extern u8 D_0033E068[];
extern int D_00368A38;
void func_00119400(int, void*);
}

INCLUDE_ASM("asm/nonmatchings/game/t_163750", func_00163750);

INCLUDE_ASM("asm/nonmatchings/game/t_163750", func_00163868);

INCLUDE_ASM("asm/nonmatchings/game/t_163750", func_00163938);

INCLUDE_ASM("asm/nonmatchings/game/t_163750", func_00163A08);

extern "C" void func_00163AD8(S_00163AD8* self, u128_163* v) {
    if (self->unk2D8 & 0x10000) {
        self->unk90 = *v;
    }
}

extern "C" void func_00163B00(S_00163AD8* self, int b) {
    if (b) {
        self->unk2D8 |= 0x10000;
    } else {
        self->unk2D8 &= ~0x10000;
    }
    self->unk2E0.f13 = b;
}

INCLUDE_ASM("asm/nonmatchings/game/t_163750", func_00163B50);

INCLUDE_ASM("asm/nonmatchings/game/t_163750", func_00164AA0);

INCLUDE_ASM("asm/nonmatchings/game/t_163750", func_00164B20);

INCLUDE_ASM("asm/nonmatchings/game/t_163750", func_00164E40);

extern "C" void func_00164E58(void) {
}

extern "C" void func_00164E60(L_163* self, int flags) {
    self->unk14 = D_0033E068;
    self->unk10->unkC = self->unkC;
    self->unkC->unk10 = self->unk10;
    self->unkC = self;
    self->unk10 = self;
    if (flags & 1) {
        func_00119400(D_00368A38, self);
    }
}

INCLUDE_ASM("asm/nonmatchings/game/t_163750", func_00164EC0);

INCLUDE_ASM("asm/nonmatchings/game/t_163750", func_001650A0);

INCLUDE_ASM("asm/nonmatchings/game/t_163750", func_00165210);

INCLUDE_ASM("asm/nonmatchings/game/t_163750", func_00165448);
