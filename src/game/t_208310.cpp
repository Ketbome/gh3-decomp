#include "common.h"

struct VEntry208 {
    s16 delta;
    s16 unk2;
    void* fn;
};

struct S208b {
    char pad0[0x20];
    int unk20;
    char pad24[0xAC];
    f32 unkD0;
};

struct S208 {
    char pad0[0x18];
    VEntry208* unk18;
    S208b* unk1C;
};

extern "C" {
void func_002082B0(int, int);
void func_00208778(int, int);
void* func_00113D20(u32 size);
void* func_00208388(void*);
void* func_00208910(void*);
void func_00276D68(u32, void*, int);
extern u8 D_0038FD28[];
extern u8 D_0038FD68[];
void func_0027C1F8(int, u32, f32);
}

extern "C" void func_00208310(void) {
    func_002082B0(1, 0xFFFF);
}

extern "C" void* func_00208330(void) {
    return func_00208388(func_00113D20(0x20));
}

extern "C" void func_00208358(void) {
    func_00276D68(0xC4E311FA, D_0038FD28, 0x10);
}

INCLUDE_ASM("asm/nonmatchings/game/t_208310", func_00208388);

INCLUDE_ASM("asm/nonmatchings/game/t_208310", func_002083F8);

INCLUDE_ASM("asm/nonmatchings/game/t_208310", func_00208448);

extern "C" void func_002084C8(S208* self, int a) {
    VEntry208* e = &self->unk18[3];
    ((void (*)(void*, int))e->fn)((char*)self + e->delta, a);
}

INCLUDE_ASM("asm/nonmatchings/game/t_208310", func_002084F0);

INCLUDE_ASM("asm/nonmatchings/game/t_208310", func_00208538);

extern "C" int func_002085C0(S208* self, int a, S208b* b) {
    func_0027C1F8(b->unk20, 0x3770EBFC, self->unk1C->unkD0);
    return 1;
}

INCLUDE_ASM("asm/nonmatchings/game/t_208310", func_002085F0);

INCLUDE_ASM("asm/nonmatchings/game/t_208310", func_00208640);

extern "C" int func_002086C8(void) {
    return 2;
}

INCLUDE_ASM("asm/nonmatchings/game/t_208310", func_002086D0);

extern "C" void func_00208770(void) {
}

INCLUDE_ASM("asm/nonmatchings/game/t_208310", func_00208778);

extern "C" void func_00208898(void) {
    func_00208778(1, 0xFFFF);
}

extern "C" void* func_002088B8(void) {
    return func_00208910(func_00113D20(0x6D0));
}

extern "C" void func_002088E0(void) {
    func_00276D68(0xEA0EEAFB, D_0038FD68, 0x10);
}

INCLUDE_ASM("asm/nonmatchings/game/t_208310", func_00208910);

INCLUDE_ASM("asm/nonmatchings/game/t_208310", func_00208C50);

INCLUDE_ASM("asm/nonmatchings/game/t_208310", func_00208DE0);

extern "C" void func_00208F80(S208* self, int a) {
    VEntry208* e = &self->unk18[3];
    ((void (*)(void*, int))e->fn)((char*)self + e->delta, a);
}

INCLUDE_ASM("asm/nonmatchings/game/t_208310", func_00208FA8);

INCLUDE_ASM("asm/nonmatchings/game/t_208310", func_00209008);
