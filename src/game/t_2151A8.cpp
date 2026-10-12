#include "common.h"

struct S215 {
    char pad0[0xC];
    void* unkC;
    char pad10[0x10];
    void* unk20;
    char pad24[0x8];
    int unk2C;
};

extern "C" {
void func_0016C638(void*);
void func_0016C620(void*);
int func_001D1CF8(void*, u32);
}

INCLUDE_ASM("asm/nonmatchings/game/t_2151A8", func_002151A8);

extern "C" void func_002167D8(void) {
}

INCLUDE_ASM("asm/nonmatchings/game/t_2151A8", func_002167E0);

extern "C" void func_00216818(S215* self) {
    if (self->unk20) {
        func_0016C638(self->unk20);
    }
}

extern "C" void func_00216840(S215* self) {
    if (self->unk20) {
        func_0016C620(self->unk20);
    }
}

INCLUDE_ASM("asm/nonmatchings/game/t_2151A8", func_00216868);

INCLUDE_ASM("asm/nonmatchings/game/t_2151A8", func_00216BD8);

INCLUDE_ASM("asm/nonmatchings/game/t_2151A8", func_00216D78);

INCLUDE_ASM("asm/nonmatchings/game/t_2151A8", func_00216E18);

extern "C" void func_00216E70(void) {
}

INCLUDE_ASM("asm/nonmatchings/game/t_2151A8", func_00216E78);

INCLUDE_ASM("asm/nonmatchings/game/t_2151A8", func_00216ED0);

INCLUDE_ASM("asm/nonmatchings/game/t_2151A8", func_00216F28);

INCLUDE_ASM("asm/nonmatchings/game/t_2151A8", func_00216F80);

INCLUDE_ASM("asm/nonmatchings/game/t_2151A8", func_00216FD0);

INCLUDE_ASM("asm/nonmatchings/game/t_2151A8", func_00217020);

INCLUDE_ASM("asm/nonmatchings/game/t_2151A8", func_00217070);

INCLUDE_ASM("asm/nonmatchings/game/t_2151A8", func_002170C8);

INCLUDE_ASM("asm/nonmatchings/game/t_2151A8", func_00217118);

INCLUDE_ASM("asm/nonmatchings/game/t_2151A8", func_00217170);
