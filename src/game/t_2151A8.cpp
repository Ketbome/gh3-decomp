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
int func_0027D0B0(int, int, void*, int);
void func_0016C798(int, int, void*);
int func_0027D058(int, int, void*, int);
void func_0016C650(int, f32);
}

INCLUDE_ASM("asm/nonmatchings/game/t_2151A8", func_002151A8);

extern "C" void func_002167D8(void) {
}

extern "C" void func_002167E0(S215* p) {
    p->unk2C = func_001D1CF8(p->unkC, 0xCE0CA665);
}

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

extern "C" int func_00216F80(int* p, int a) {
    int v[4];
    func_0027D0B0(a, 0, v, 1);
    if (p[8]) {
        func_0016C798(p[8], 0, v);
    }
    return 1;
}

extern "C" int func_00216FD0(int* p, int a) {
    int v[4];
    func_0027D0B0(a, 0, v, 1);
    if (p[8]) {
        func_0016C798(p[8], 1, v);
    }
    return 1;
}

extern "C" int func_00217020(int* p, int a) {
    int v[4];
    func_0027D0B0(a, 0, v, 1);
    if (p[8]) {
        func_0016C798(p[8], 2, v);
    }
    return 1;
}

INCLUDE_ASM("asm/nonmatchings/game/t_2151A8", func_00217070);

extern "C" int func_002170C8(int* p, int a) {
    f32 v[4];
    func_0027D058(a, 0, v, 1);
    if (p[8]) {
        func_0016C650(p[8], v[0]);
    }
    return 1;
}

INCLUDE_ASM("asm/nonmatchings/game/t_2151A8", func_00217118);

INCLUDE_ASM("asm/nonmatchings/game/t_2151A8", func_00217170);
