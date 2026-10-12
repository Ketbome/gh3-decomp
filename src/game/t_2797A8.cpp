#include "common.h"

struct S0027AA58 {
    char pad[0x2];
    u8 unk2;
    u8 unk3;
    int unk4;
};

struct S0027B300 {
    char pad[0x4];
    int unk4;
    char pad1[0x4];
    int unkC;
};

extern "C" {
extern u8 D_003711D8;
void func_0027AA58(S0027AA58 *);
}

INCLUDE_ASM("asm/nonmatchings/game/t_2797A8", func_002797A8);

INCLUDE_ASM("asm/nonmatchings/game/t_2797A8", func_002798B0);

INCLUDE_ASM("asm/nonmatchings/game/t_2797A8", func_002798B8);

INCLUDE_ASM("asm/nonmatchings/game/t_2797A8", func_00279F10);

INCLUDE_ASM("asm/nonmatchings/game/t_2797A8", func_0027A9B8);

GP_DATA(D_003711D8);
extern "C" void func_0027AA58(S0027AA58* p) {
    p->unk4 = 0;
    p->unk2 = 0;
    p->unk3 = D_003711D8;
}

extern "C" S0027AA58 *func_0027AA70(S0027AA58 *p) {
    func_0027AA58(p);
    return p;
}

INCLUDE_ASM("asm/nonmatchings/game/t_2797A8", func_0027AA98);

INCLUDE_ASM("asm/nonmatchings/game/t_2797A8", func_0027AAD8);

INCLUDE_ASM("asm/nonmatchings/game/t_2797A8", func_0027ABB0);

INCLUDE_ASM("asm/nonmatchings/game/t_2797A8", func_0027AC80);

INCLUDE_ASM("asm/nonmatchings/game/t_2797A8", func_0027AC90);

INCLUDE_ASM("asm/nonmatchings/game/t_2797A8", func_0027ACF8);

INCLUDE_ASM("asm/nonmatchings/game/t_2797A8", func_0027ADA0);

INCLUDE_ASM("asm/nonmatchings/game/t_2797A8", func_0027AE70);

INCLUDE_ASM("asm/nonmatchings/game/t_2797A8", func_0027AF38);

extern "C" int func_0027B300(S0027B300* a, S0027B300* b) {
    if (b == 0) {
        return a->unk4;
    }
    return b->unkC;
}

INCLUDE_ASM("asm/nonmatchings/game/t_2797A8", func_0027B318);

INCLUDE_ASM("asm/nonmatchings/game/t_2797A8", func_0027B4D0);

INCLUDE_ASM("asm/nonmatchings/game/t_2797A8", func_0027B678);
