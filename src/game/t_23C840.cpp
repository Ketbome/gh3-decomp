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
void func_0023DD50(void*);
}

INCLUDE_ASM("asm/nonmatchings/game/t_23C840", func_0023C840);

INCLUDE_ASM("asm/nonmatchings/game/t_23C840", func_0023CA18);

INCLUDE_ASM("asm/nonmatchings/game/t_23C840", func_0023CCC0);

INCLUDE_ASM("asm/nonmatchings/game/t_23C840", func_0023CFD8);

INCLUDE_ASM("asm/nonmatchings/game/t_23C840", func_0023D920);

INCLUDE_ASM("asm/nonmatchings/game/t_23C840", func_0023DA90);

INCLUDE_ASM("asm/nonmatchings/game/t_23C840", func_0023DC68);

INCLUDE_ASM("asm/nonmatchings/game/t_23C840", func_0023DC88);

INCLUDE_ASM("asm/nonmatchings/game/t_23C840", func_0023DCF8);

extern "C" void func_0023DD10(void) {
}

INCLUDE_ASM("asm/nonmatchings/game/t_23C840", func_0023DD18);

INCLUDE_ASM("asm/nonmatchings/game/t_23C840", func_0023DD20);

INCLUDE_ASM("asm/nonmatchings/game/t_23C840", func_0023DD50);

INCLUDE_ASM("asm/nonmatchings/game/t_23C840", func_0023E628);

INCLUDE_ASM("asm/nonmatchings/game/t_23C840", func_0023E650);

INCLUDE_ASM("asm/nonmatchings/game/t_23C840", func_0023E678);
