#include "common.h"

struct S002777B8 {
    char pad[0x8];
    int unk8;
};

extern "C" {
int func_00278450(int, int, u8);
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

struct S2777E0 {
    char pad0[2];
    u8 unk2;
    char pad3[1];
    int unk4;
};
extern "C" int func_002777E0(S2777E0 *p) {
    return func_00278450((int)p + 0xC, p->unk4, p->unk2) + 0xC;
}

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

struct S279118 {
    u16 unk0;
    u8 unk2;
    char pad3[1];
    char unk4[1];
};
struct S279118E {
    char b[8];
};
INCLUDE_ASM("asm/nonmatchings/game/t_2774B8", func_00279118);

INCLUDE_ASM("asm/nonmatchings/game/t_2774B8", func_00279150);

INCLUDE_ASM("asm/nonmatchings/game/t_2774B8", func_002791E0);

INCLUDE_ASM("asm/nonmatchings/game/t_2774B8", func_00279358);
