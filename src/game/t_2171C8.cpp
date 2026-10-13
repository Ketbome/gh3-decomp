#include "common.h"

struct S217 {
    char pad0[0x20];
    void* unk20;
};

extern "C" {
void func_00217A80(int, int);
void* func_00113D20(u32 size);
void* func_00218088(void*);
void func_0016C5C0(void*, int);
void func_00276D68(u32, void*, int);
extern u8 D_00390198[];
int func_0027D058(int, int, void*, int);
void func_0016CA18(int, f32);
void func_0016C4F8(int);
void func_0016C6B8(int, f32);
}

extern "C" int func_002171C8(int* p, int a) {
    f32 v[4];
    func_0027D058(a, 0, v, 1);
    if (p[8]) {
        func_0016CA18(p[8], v[0]);
        func_0016C4F8(p[8]);
    }
    return 1;
}

extern "C" int func_00217220(int* p, int a) {
    f32 v[4];
    func_0027D058(a, 0, v, 1);
    if (p[8]) {
        func_0016C6B8(p[8], v[0]);
        func_0016C4F8(p[8]);
    }
    return 1;
}

INCLUDE_ASM("asm/nonmatchings/game/t_2171C8", func_00217278);

INCLUDE_ASM("asm/nonmatchings/game/t_2171C8", func_002172D0);

INCLUDE_ASM("asm/nonmatchings/game/t_2171C8", func_00217328);

INCLUDE_ASM("asm/nonmatchings/game/t_2171C8", func_00217380);

INCLUDE_ASM("asm/nonmatchings/game/t_2171C8", func_00217410);

INCLUDE_ASM("asm/nonmatchings/game/t_2171C8", func_002174A0);

INCLUDE_ASM("asm/nonmatchings/game/t_2171C8", func_00217530);

INCLUDE_ASM("asm/nonmatchings/game/t_2171C8", func_00217588);

INCLUDE_ASM("asm/nonmatchings/game/t_2171C8", func_00217618);

extern "C" int func_00217A48(S217* self) {
    if (self->unk20) {
        func_0016C5C0(self->unk20, 1);
    }
    return 1;
}

INCLUDE_ASM("asm/nonmatchings/game/t_2171C8", func_00217A78);

INCLUDE_ASM("asm/nonmatchings/game/t_2171C8", func_00217A80);

extern "C" void func_00218010(void) {
    func_00217A80(1, 0xFFFF);
}

extern "C" void* func_00218030(void) {
    return func_00218088(func_00113D20(0x70));
}

extern "C" void func_00218058(void) {
    func_00276D68(0xC5BCEB9E, D_00390198, 0x10);
}

INCLUDE_ASM("asm/nonmatchings/game/t_2171C8", func_00218088);

INCLUDE_ASM("asm/nonmatchings/game/t_2171C8", func_00218120);

INCLUDE_ASM("asm/nonmatchings/game/t_2171C8", func_002181C8);
