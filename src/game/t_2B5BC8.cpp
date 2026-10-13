#include "common.h"

extern "C" {
int func_002B6098(int);
extern int D_00372010[2];
extern int D_00372018[2];
void func_002B4B98(int, int, int);
extern int D_00371F90[2];
}

INCLUDE_ASM("asm/nonmatchings/game/t_2B5BC8", func_002B5BC8);

INCLUDE_ASM("asm/nonmatchings/game/t_2B5BC8", func_002B5C08);

INCLUDE_ASM("asm/nonmatchings/game/t_2B5BC8", func_002B5CA8);

GP_DATA(D_00371F90);
extern "C" void func_002B5DA0(int i) {
    int *p = &D_00371F90[i];
    func_002B4B98(*p, 0x907542B6, 0);
    func_002B4B98(*p, 0xE59AA425, 0);
}

INCLUDE_ASM("asm/nonmatchings/game/t_2B5BC8", func_002B5DF0);

INCLUDE_ASM("asm/nonmatchings/game/t_2B5BC8", func_002B6098);

GP_DATA(D_00372010);
GP_DATA(D_00372018);
extern "C" int func_002B6270(int a, int b) {
    if (b >= D_00372010[a]) {
        if (b < D_00372018[a]) {
            return func_002B6098(a);
        }
    }
    return 0;
}

INCLUDE_ASM("asm/nonmatchings/game/t_2B5BC8", func_002B62C8);

INCLUDE_ASM("asm/nonmatchings/game/t_2B5BC8", func_002B64D8);

INCLUDE_ASM("asm/nonmatchings/game/t_2B5BC8", func_002B6708);

INCLUDE_ASM("asm/nonmatchings/game/t_2B5BC8", func_002B68E8);

INCLUDE_ASM("asm/nonmatchings/game/t_2B5BC8", func_002B6C10);

INCLUDE_ASM("asm/nonmatchings/game/t_2B5BC8", func_002B6D90);

INCLUDE_ASM("asm/nonmatchings/game/t_2B5BC8", func_002B6D98);

INCLUDE_ASM("asm/nonmatchings/game/t_2B5BC8", func_002B7108);

INCLUDE_ASM("asm/nonmatchings/game/t_2B5BC8", func_002B7140);

INCLUDE_ASM("asm/nonmatchings/game/t_2B5BC8", func_002B72C0);

INCLUDE_ASM("asm/nonmatchings/game/t_2B5BC8", func_002B7A60);
