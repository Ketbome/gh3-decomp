#include "common.h"

struct S2EBDE0_0 {
    s32 unk0;
    s32 unk4;
    s32 unk8;
};

INCLUDE_ASM("asm/nonmatchings/game/t_2EB1C0", func_002EB1C0);

INCLUDE_ASM("asm/nonmatchings/game/t_2EB1C0", func_002EB1C8);

INCLUDE_ASM("asm/nonmatchings/game/t_2EB1C0", func_002EB280);

INCLUDE_ASM("asm/nonmatchings/game/t_2EB1C0", func_002EB4C8);

INCLUDE_ASM("asm/nonmatchings/game/t_2EB1C0", func_002EB550);

INCLUDE_ASM("asm/nonmatchings/game/t_2EB1C0", func_002EB568);

INCLUDE_ASM("asm/nonmatchings/game/t_2EB1C0", func_002EB680);

INCLUDE_ASM("asm/nonmatchings/game/t_2EB1C0", func_002EB738);

INCLUDE_ASM("asm/nonmatchings/game/t_2EB1C0", func_002EB858);

INCLUDE_ASM("asm/nonmatchings/game/t_2EB1C0", func_002EB970);

INCLUDE_ASM("asm/nonmatchings/game/t_2EB1C0", func_002EBA98);

INCLUDE_ASM("asm/nonmatchings/game/t_2EB1C0", func_002EBC18);

INCLUDE_ASM("asm/nonmatchings/game/t_2EB1C0", func_002EBCF8);

INCLUDE_ASM("asm/nonmatchings/game/t_2EB1C0", func_002EBDD8);

extern "C" void func_002EBDE0(S2EBDE0_0 *arg0) {
    arg0->unk0 = 0;
    arg0->unk4 = 0;
    arg0->unk8 = 0;
}

extern "C" S2EBDE0_0 *func_002EBDF0(S2EBDE0_0 *self) {
    func_002EBDE0(self);
    return self;
}

INCLUDE_ASM("asm/nonmatchings/game/t_2EB1C0", func_002EBE18);

INCLUDE_ASM("asm/nonmatchings/game/t_2EB1C0", func_002EBFF8);
