#include "common.h"

extern "C" {
extern void* D_00372C34[] __attribute__((section(".sdata")));
extern void* D_0036CBC0[] __attribute__((section(".sdata")));
void func_001B1EB0(void* p);
void func_001BF408(void* p);
extern s32 D_0036C7E8;
extern s32 D_0036CAC8;
extern s32 D_00372C30;
extern s32 D_0036CACC;
extern s32 D_0036CAD4;
}

INCLUDE_ASM("asm/nonmatchings/game/t_1B93E8", func_001B93E8);

INCLUDE_ASM("asm/nonmatchings/game/t_1B93E8", func_001B95F0);

INCLUDE_ASM("asm/nonmatchings/game/t_1B93E8", func_001B9C60);

INCLUDE_ASM("asm/nonmatchings/game/t_1B93E8", func_001B9D78);

INCLUDE_ASM("asm/nonmatchings/game/t_1B93E8", func_001B9E90);

INCLUDE_ASM("asm/nonmatchings/game/t_1B93E8", func_001BA110);

INCLUDE_ASM("asm/nonmatchings/game/t_1B93E8", func_001BA6D8);

INCLUDE_ASM("asm/nonmatchings/game/t_1B93E8", func_001BA7E8);

GP_DATA(D_0036CAC8);
extern "C" void func_001BB050(void) {
    D_0036CAC8 = 1;
    D_00372C30 = D_0036C7E8;
}

extern "C" void func_001BB068(void) {
    D_0036CACC = 1;
}

INCLUDE_ASM("asm/nonmatchings/game/t_1B93E8", func_001BB078);

INCLUDE_ASM("asm/nonmatchings/game/t_1B93E8", func_001BB100);

extern "C" void func_001BB180(void) {
    D_0036CAD4 = 0;
}

INCLUDE_ASM("asm/nonmatchings/game/t_1B93E8", func_001BB188);
