#include "common.h"

struct S23D {
    int unk0;
    s16 unk4;
    char pad6[0x2];
    S23D* unk8;
    void* unkC;
};

extern "C" {
extern u8 D_00354F08[];
extern int D_0036FE9C;
extern int D_0036FEA0;
void func_0023DD50(void);
}

INCLUDE_ASM("asm/nonmatchings/game/t_23C840", func_0023C840);

INCLUDE_ASM("asm/nonmatchings/game/t_23C840", func_0023CA18);

INCLUDE_ASM("asm/nonmatchings/game/t_23C840", func_0023CCC0);

INCLUDE_ASM("asm/nonmatchings/game/t_23C840", func_0023CFD8);

INCLUDE_ASM("asm/nonmatchings/game/t_23C840", func_0023D920);

INCLUDE_ASM("asm/nonmatchings/game/t_23C840", func_0023DA90);

extern "C" void* func_0023DC68(void* p) {
    ((s16*)p)[2] = 0;
    ((void**)p)[3] = D_00354F08;
    ((int*)p)[2] = 0;
    return p;
}

INCLUDE_ASM("asm/nonmatchings/game/t_23C840", func_0023DC88);

extern "C" void func_0023DCF8(int* p, int v) {
    int* q = (int*)p[2];
    p[0] = v;
    if (q) *q = v;
}

extern "C" void func_0023DD10(void) {
}

extern "C" int func_0023DD18(void) {
    return 0;
}

INCLUDE_ASM("asm/nonmatchings/game/t_23C840", func_0023DD20);

INCLUDE_ASM("asm/nonmatchings/game/t_23C840", func_0023DD50);

GP_DATA(D_0036FE9C);
extern "C" void func_0023E628(void) {
    D_0036FE9C = 1;
    func_0023DD50();
    D_0036FE9C = 0;
}

GP_DATA(D_0036FEA0);
extern "C" void func_0023E650(void) {
    D_0036FEA0 = 1;
    func_0023DD50();
    D_0036FEA0 = 0;
}

INCLUDE_ASM("asm/nonmatchings/game/t_23C840", func_0023E678);
