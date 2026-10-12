#include "common.h"

struct S20A {
    char pad0[0x490];
    int unk490;
    char pad494[0x4C];
    int unk4E0;
    char pad4E4[0x4C];
    int unk530;
    char pad534[0x4C];
    int unk580;
    char pad584[0x4C];
    int unk5D0;
    char pad5D4[0x4C];
    int unk620;
    char pad624[0x4C];
    int unk670;
};

INCLUDE_ASM("asm/nonmatchings/game/t_20AD10", func_0020AD10);

INCLUDE_ASM("asm/nonmatchings/game/t_20AD10", func_0020AD50);

INCLUDE_ASM("asm/nonmatchings/game/t_20AD10", func_0020AE18);

INCLUDE_ASM("asm/nonmatchings/game/t_20AD10", func_0020AEC8);

INCLUDE_ASM("asm/nonmatchings/game/t_20AD10", func_0020AF80);

INCLUDE_ASM("asm/nonmatchings/game/t_20AD10", func_0020B148);

INCLUDE_ASM("asm/nonmatchings/game/t_20AD10", func_0020B570);

INCLUDE_ASM("asm/nonmatchings/game/t_20AD10", func_0020B7B0);

INCLUDE_ASM("asm/nonmatchings/game/t_20AD10", func_0020B8B8);

INCLUDE_ASM("asm/nonmatchings/game/t_20AD10", func_0020B920);

extern "C" int func_0020B9C0(void) {
    return 2;
}

extern "C" void func_0020B9C8(void) {
}

INCLUDE_ASM("asm/nonmatchings/game/t_20AD10", func_0020B9D0);

INCLUDE_ASM("asm/nonmatchings/game/t_20AD10", func_0020BF60);

extern "C" void func_0020C0D8(S20A* self) {
    self->unk580 = 0;
    self->unk4E0 = 0;
    self->unk5D0 = 0;
    self->unk530 = 0;
    self->unk620 = 0;
    self->unk670 = 0;
    self->unk490 = 0;
}

INCLUDE_ASM("asm/nonmatchings/game/t_20AD10", func_0020C0F8);

INCLUDE_ASM("asm/nonmatchings/game/t_20AD10", func_0020C1F0);

INCLUDE_ASM("asm/nonmatchings/game/t_20AD10", func_0020C220);

INCLUDE_ASM("asm/nonmatchings/game/t_20AD10", func_0020C268);

INCLUDE_ASM("asm/nonmatchings/game/t_20AD10", func_0020C2B8);

INCLUDE_ASM("asm/nonmatchings/game/t_20AD10", func_0020C428);

INCLUDE_ASM("asm/nonmatchings/game/t_20AD10", func_0020C460);

INCLUDE_ASM("asm/nonmatchings/game/t_20AD10", func_0020C540);

INCLUDE_ASM("asm/nonmatchings/game/t_20AD10", func_0020C5A0);

INCLUDE_ASM("asm/nonmatchings/game/t_20AD10", func_0020C5D8);

INCLUDE_ASM("asm/nonmatchings/game/t_20AD10", func_0020C690);

INCLUDE_ASM("asm/nonmatchings/game/t_20AD10", func_0020CAE8);

INCLUDE_ASM("asm/nonmatchings/game/t_20AD10", func_0020CB78);

INCLUDE_ASM("asm/nonmatchings/game/t_20AD10", func_0020CD08);
