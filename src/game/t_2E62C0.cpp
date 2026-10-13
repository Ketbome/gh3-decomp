#include "common.h"

struct S2E6F10 {
    s32 unk0;
    s16 unk4;
    s16 unk6;
    char pad8[0x44];
};

extern "C" {
extern s32 D_00368748[] __attribute__((section(".sdata")));
extern s32 D_0036874C[] __attribute__((section(".sdata")));
extern s32 D_0037291C;
extern s32 D_00372920;
int func_002E2FB0(int, int);
extern S2E6F10 D_003EB000[2];
extern s32 D_003728E4;
extern s32 D_003728E8;
extern s32 D_00372910;
void func_002E3248(int);
void func_002E3E50(u32);
void func_002E6108(s16, s16);
void func_002E6160(s16, s16);
void func_002E62C0(int);
}






























INCLUDE_ASM("asm/nonmatchings/game/t_2E62C0", func_002E62C0);

extern "C" s32 func_002E6340(void) {
    s32 var_3;

    var_3 = 0;
    if ((D_00368748[0] != 0) || (D_0036874C[0] != 0)) {
        var_3 = 1;
    }
    return var_3;
}

GP_DATA(D_0037291C);
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

GP_DATA(D_00372920);
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

INCLUDE_ASM("asm/nonmatchings/game/t_2E62C0", func_002E6420);

INCLUDE_ASM("asm/nonmatchings/game/t_2E62C0", func_002E6C80);

INCLUDE_ASM("asm/nonmatchings/game/t_2E62C0", func_002E6D40);

GP_DATA(D_00372910);
GP_DATA(D_003728E4);
INCLUDE_ASM("asm/nonmatchings/game/t_2E62C0", func_002E6F10);
