#include "common.h"

struct S002777B8 {
    char pad[0x8];
    int unk8;
};

extern "C" {
void func_00277378(void);
void func_00277540(void);
S002777B8* func_0027B300(int, int);
char* func_00278E48(int);
}

extern "C" void func_002774B8(void) {
    func_00277378();
}

INCLUDE_ASM("asm/nonmatchings/game/t_2774B8", func_002774D8);

INCLUDE_ASM("asm/nonmatchings/game/t_2774B8", func_00277538);

INCLUDE_ASM("asm/nonmatchings/game/t_2774B8", func_00277540);

extern "C" void func_002775B8(void) {
    func_00277540();
}

INCLUDE_ASM("asm/nonmatchings/game/t_2774B8", func_002775D8);

INCLUDE_ASM("asm/nonmatchings/game/t_2774B8", func_002775E8);

extern "C" char* func_002777B8(int a) {
    return func_00278E48(func_0027B300(a, 0)->unk8) + 0x18;
}

INCLUDE_ASM("asm/nonmatchings/game/t_2774B8", func_002777E0);

INCLUDE_ASM("asm/nonmatchings/game/t_2774B8", func_00277810);

INCLUDE_ASM("asm/nonmatchings/game/t_2774B8", func_00277860);

INCLUDE_ASM("asm/nonmatchings/game/t_2774B8", func_002778D8);

INCLUDE_ASM("asm/nonmatchings/game/t_2774B8", func_00277DE8);

INCLUDE_ASM("asm/nonmatchings/game/t_2774B8", func_00278098);

INCLUDE_ASM("asm/nonmatchings/game/t_2774B8", func_00278450);

INCLUDE_ASM("asm/nonmatchings/game/t_2774B8", func_002787F0);

INCLUDE_ASM("asm/nonmatchings/game/t_2774B8", func_00278910);

INCLUDE_ASM("asm/nonmatchings/game/t_2774B8", func_00278C50);

INCLUDE_ASM("asm/nonmatchings/game/t_2774B8", func_00278D78);

INCLUDE_ASM("asm/nonmatchings/game/t_2774B8", func_00278E48);

INCLUDE_ASM("asm/nonmatchings/game/t_2774B8", func_00279118);

INCLUDE_ASM("asm/nonmatchings/game/t_2774B8", func_00279150);

INCLUDE_ASM("asm/nonmatchings/game/t_2774B8", func_002791E0);

INCLUDE_ASM("asm/nonmatchings/game/t_2774B8", func_00279358);
