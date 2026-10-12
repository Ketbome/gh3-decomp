#include "common.h"

struct VEntry21B {
    s16 delta;
    s16 unk2;
    void* fn;
};

struct S21B {
    char pad0[0xC];
    void* unkC;
    char pad10[0x8];
    VEntry21B* unk18;
    char pad1C[0xC];
    int unk28;
    int unk2C;
    int unk30;
};

extern "C" {
void* func_00113D20(u32 size);
void* func_0021C318(void*);
void func_00276D68(u32, void*, int);
extern u8 D_00390530[];
int func_001D1CF8(void*, u32);
}

INCLUDE_ASM("asm/nonmatchings/game/t_21BA08", func_0021BA08);

INCLUDE_ASM("asm/nonmatchings/game/t_21BA08", func_0021BB38);

INCLUDE_ASM("asm/nonmatchings/game/t_21BA08", func_0021BB40);

INCLUDE_ASM("asm/nonmatchings/game/t_21BA08", func_0021C250);

extern "C" void* func_0021C2C0(void) {
    return func_0021C318(func_00113D20(0x54));
}

extern "C" void func_0021C2E8(void) {
    func_00276D68(0x6DCFEC46, D_00390530, 0x10);
}

INCLUDE_ASM("asm/nonmatchings/game/t_21BA08", func_0021C318);

INCLUDE_ASM("asm/nonmatchings/game/t_21BA08", func_0021C3A8);

INCLUDE_ASM("asm/nonmatchings/game/t_21BA08", func_0021C530);

INCLUDE_ASM("asm/nonmatchings/game/t_21BA08", func_0021CDB0);

extern "C" void func_0021CE10(S21B* self, int a) {
    VEntry21B* e = &self->unk18[3];
    ((void (*)(void*, int))e->fn)((char*)self + e->delta, a);
}

INCLUDE_ASM("asm/nonmatchings/game/t_21BA08", func_0021CE38);

INCLUDE_ASM("asm/nonmatchings/game/t_21BA08", func_0021D8F8);
