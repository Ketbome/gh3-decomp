#include "common.h"

extern "C" {
extern s32 D_00368748[] __attribute__((section(".sdata")));
extern s32 D_0036874C[] __attribute__((section(".sdata")));
extern s32 D_0037291C;
extern s32 D_00372920;
int func_002E2FB0(int, int);
}

INCLUDE_ASM("asm/nonmatchings/game/t_2E4FD0", func_002E4FD0);

INCLUDE_ASM("asm/nonmatchings/game/t_2E4FD0", func_002E5088);

INCLUDE_ASM("asm/nonmatchings/game/t_2E4FD0", func_002E50C8);

INCLUDE_ASM("asm/nonmatchings/game/t_2E4FD0", func_002E5138);

INCLUDE_ASM("asm/nonmatchings/game/t_2E4FD0", func_002E5188);

INCLUDE_ASM("asm/nonmatchings/game/t_2E4FD0", func_002E53B8);

INCLUDE_ASM("asm/nonmatchings/game/t_2E4FD0", func_002E5408);

INCLUDE_ASM("asm/nonmatchings/game/t_2E4FD0", func_002E54D8);

INCLUDE_ASM("asm/nonmatchings/game/t_2E4FD0", func_002E5598);

INCLUDE_ASM("asm/nonmatchings/game/t_2E4FD0", func_002E5610);

INCLUDE_ASM("asm/nonmatchings/game/t_2E4FD0", func_002E5660);

INCLUDE_ASM("asm/nonmatchings/game/t_2E4FD0", func_002E56E8);

INCLUDE_ASM("asm/nonmatchings/game/t_2E4FD0", func_002E5718);

INCLUDE_ASM("asm/nonmatchings/game/t_2E4FD0", func_002E5758);

INCLUDE_ASM("asm/nonmatchings/game/t_2E4FD0", func_002E5788);

INCLUDE_ASM("asm/nonmatchings/game/t_2E4FD0", func_002E5860);

INCLUDE_ASM("asm/nonmatchings/game/t_2E4FD0", func_002E5938);

INCLUDE_ASM("asm/nonmatchings/game/t_2E4FD0", func_002E59A0);

INCLUDE_ASM("asm/nonmatchings/game/t_2E4FD0", func_002E5A78);

INCLUDE_ASM("asm/nonmatchings/game/t_2E4FD0", func_002E5B50);

INCLUDE_ASM("asm/nonmatchings/game/t_2E4FD0", func_002E5BB8);

INCLUDE_ASM("asm/nonmatchings/game/t_2E4FD0", func_002E5CA8);

INCLUDE_ASM("asm/nonmatchings/game/t_2E4FD0", func_002E5E28);

INCLUDE_ASM("asm/nonmatchings/game/t_2E4FD0", func_002E5F38);

INCLUDE_ASM("asm/nonmatchings/game/t_2E4FD0", func_002E5FF8);

INCLUDE_ASM("asm/nonmatchings/game/t_2E4FD0", func_002E6108);

INCLUDE_ASM("asm/nonmatchings/game/t_2E4FD0", func_002E6160);

INCLUDE_ASM("asm/nonmatchings/game/t_2E4FD0", func_002E61D0);

INCLUDE_ASM("asm/nonmatchings/game/t_2E4FD0", func_002E6270);

INCLUDE_ASM("asm/nonmatchings/game/t_2E4FD0", func_002E62C0);

extern "C" s32 func_002E6340(void) {
    s32 var_3;

    var_3 = 0;
    if ((D_00368748[0] != 0) || (D_0036874C[0] != 0)) {
        var_3 = 1;
    }
    return var_3;
}

extern "C" void func_002E6370(s32 arg0) {
    s32 var_4;

    var_4 = arg0;
    if (var_4 < 0) {
        if (var_4 != -2) {
            D_0037291C ^= 1;
        }
        var_4 = D_0037291C;
    }
    if (var_4 > 0) {
        func_002E2FB0(0x18, 0x2F);
        return;
    }
    func_002E2FB0(0, 0x17);
}

extern "C" void func_002E63C8(s32 arg0) {
    s32 var_4;

    var_4 = arg0;
    if (var_4 < 0) {
        if (var_4 != -2) {
            D_00372920 ^= 1;
        }
        var_4 = D_00372920;
    }
    if (var_4 > 0) {
        func_002E2FB0(0x18, 0x2F);
        return;
    }
    func_002E2FB0(0x10, 0x17);
}

INCLUDE_ASM("asm/nonmatchings/game/t_2E4FD0", func_002E6420);

INCLUDE_ASM("asm/nonmatchings/game/t_2E4FD0", func_002E6C80);

INCLUDE_ASM("asm/nonmatchings/game/t_2E4FD0", func_002E6D40);

INCLUDE_ASM("asm/nonmatchings/game/t_2E4FD0", func_002E6F10);
