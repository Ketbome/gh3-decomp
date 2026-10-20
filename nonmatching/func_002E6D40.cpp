// cflags: -funroll-loops
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
void SndDrv_FlushCommands(int);
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

struct S2E6D_B {
    int a;
    int b;
};

extern "C" {
extern int D_003EB0B8[8];
extern S2E6D_B D_003EB198[8];
extern int D_003EB098[];
void func_002E1370(int);
void func_002698C8(int, int);
void func_002E39C8(int);
}

extern "C" void func_002E6D40(int arg0) {
    int k = arg0 - 1;
    int i;
    for (i = 0; i < 8; i++) {
        if (D_003EB0B8[i] == k) {
            func_002E1370(i);
            D_003EB0B8[i] = -1;
        }
    }
    for (i = 0; i < 8; i++) {
        if (D_003EB198[i].b == k) {
            int j = 0;
            while (j < 2) {
                if (D_003EB000[j].unk0 == D_003EB198[i].a) {
                    D_003EB000[j].unk0 = 0;
                    break;
                }
                j++;
            }
            D_003EB198[i].b = -1;
            func_002698C8(D_003EB198[i].a, j);
        }
    }
    SndDrv_FlushCommands(0);
    func_002E39C8(k);
    D_003EB098[k] = 0;
}

GP_DATA(D_00372910);
GP_DATA(D_003728E4);
INCLUDE_ASM("asm/nonmatchings/game/t_2E62C0", func_002E6F10);
