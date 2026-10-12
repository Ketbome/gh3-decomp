#include "common.h"

struct L10 {
    char pad0[0xC];
    L10* unkC;
    L10* unk10;
};

struct S001C5A68 {
    char pad0[0x8];
    L10 unk8;
    char pad1C[0x4];
    s32 unk20;
};

struct S001C5A68_B {
    char pad0[0x8];
    s32 unk8;
    s32 unkC;
    L10* unk10;
};

extern "C" void func_001C5A68(S001C5A68* p, S001C5A68_B* b) {
    L10* n = b->unk10;
    L10* h = &p->unk8;

    L10* nx = h->unk10;

    n->unkC = h;
    n->unk10 = nx;
    h->unk10->unkC = n;
    h->unk10 = n;
}

extern "C" void func_001C5A90(S001C5A68* p, S001C5A68_B* b) {
    L10* n = b->unk10;

    n->unk10->unkC = n->unkC;
    n->unkC->unk10 = n->unk10;
    n->unkC = n;
    n->unk10 = n;
}

extern "C" void func_001C5AB8(S001C5A68* p, S001C5A68_B* b) {
    if (b->unkC == 0) {
        b->unk8 = 1;
        p->unk20 = 1;
    }
}

INCLUDE_ASM("asm/nonmatchings/game/t_1C5A68", func_001C5AD8);

INCLUDE_ASM("asm/nonmatchings/game/t_1C5A68", func_001C5AE0);

INCLUDE_ASM("asm/nonmatchings/game/t_1C5A68", func_001C5BE0);

INCLUDE_ASM("asm/nonmatchings/game/t_1C5A68", func_001C5C10);

INCLUDE_ASM("asm/nonmatchings/game/t_1C5A68", func_001C5C78);

INCLUDE_ASM("asm/nonmatchings/game/t_1C5A68", func_001C5CB8);

INCLUDE_ASM("asm/nonmatchings/game/t_1C5A68", func_001C5CD8);

INCLUDE_ASM("asm/nonmatchings/game/t_1C5A68", func_001C5D28);

INCLUDE_ASM("asm/nonmatchings/game/t_1C5A68", func_001C5D80);

INCLUDE_ASM("asm/nonmatchings/game/t_1C5A68", func_001C6058);

INCLUDE_ASM("asm/nonmatchings/game/t_1C5A68", func_001C6188);

INCLUDE_ASM("asm/nonmatchings/game/t_1C5A68", func_001C6298);

INCLUDE_ASM("asm/nonmatchings/game/t_1C5A68", func_001C63B8);

INCLUDE_ASM("asm/nonmatchings/game/t_1C5A68", func_001C63F0);

INCLUDE_ASM("asm/nonmatchings/game/t_1C5A68", func_001C6450);

INCLUDE_ASM("asm/nonmatchings/game/t_1C5A68", func_001C6650);

INCLUDE_ASM("asm/nonmatchings/game/t_1C5A68", func_001C67C0);

INCLUDE_ASM("asm/nonmatchings/game/t_1C5A68", func_001C6868);

INCLUDE_ASM("asm/nonmatchings/game/t_1C5A68", func_001C68D8);

INCLUDE_ASM("asm/nonmatchings/game/t_1C5A68", func_001C6BE8);

INCLUDE_ASM("asm/nonmatchings/game/t_1C5A68", func_001C6F60);

INCLUDE_ASM("asm/nonmatchings/game/t_1C5A68", func_001C74F8);

INCLUDE_ASM("asm/nonmatchings/game/t_1C5A68", func_001C7548);

INCLUDE_ASM("asm/nonmatchings/game/t_1C5A68", func_001C7668);

INCLUDE_ASM("asm/nonmatchings/game/t_1C5A68", func_001C76C0);

extern "C" s32 func_001C7760(void) {
    return 0;
}

INCLUDE_ASM("asm/nonmatchings/game/t_1C5A68", CFunc_SetMenuAutoRepeatTimes);

INCLUDE_ASM("asm/nonmatchings/game/t_1C5A68", CFunc_SetMenuPadMappings);

INCLUDE_ASM("asm/nonmatchings/game/t_1C5A68", CFunc_SetButtonEventMappings);

INCLUDE_ASM("asm/nonmatchings/game/t_1C5A68", CFunc_SetAnalogStickActiveForMenus);

INCLUDE_ASM("asm/nonmatchings/game/t_1C5A68", CFunc_SetEnableMovies);

INCLUDE_ASM("asm/nonmatchings/game/t_1C5A68", func_001C79B0);

INCLUDE_ASM("asm/nonmatchings/game/t_1C5A68", func_001C79E0);

INCLUDE_ASM("asm/nonmatchings/game/t_1C5A68", func_001C7A40);
