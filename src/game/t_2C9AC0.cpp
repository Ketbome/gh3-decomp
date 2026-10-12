#include "common.h"

extern "C" {
extern s32 D_0036C378[] __attribute__((section(".sdata")));
extern s32 D_0036CA50;
extern s32 D_0036CA5C;
extern s32 D_0036CA80;
extern s32 D_00370E40;
extern int D_0038C9A0[];
extern int D_0038C9F0[];
int func_0019EE38(int, int, int, int);
int func_001A9E88(void *);
int func_00289CF8(s32);
}

INCLUDE_ASM("asm/nonmatchings/game/t_2C9AC0", func_002C9AC0);

INCLUDE_ASM("asm/nonmatchings/game/t_2C9AC0", func_002C9B48);

INCLUDE_ASM("asm/nonmatchings/game/t_2C9AC0", func_002C9BB0);

extern "C" s32 func_002C9DE0(void) {
    func_001A9E88(D_0038C9A0);
    func_001A9E88(D_0038C9F0);
    return 1;
}

extern "C" s32 func_002C9E10(void) {
    D_0036CA50 = 1;
    return 1;
}

INCLUDE_ASM("asm/nonmatchings/game/t_2C9AC0", func_002C9E20);

extern "C" s32 func_002C9E30(void) {
    D_0036CA80 = 1;
    return 1;
}

INCLUDE_ASM("asm/nonmatchings/game/t_2C9AC0", func_002C9E40);

extern "C" s32 func_002C9E50(void) {
    D_0036CA5C = 1;
    return 1;
}

INCLUDE_ASM("asm/nonmatchings/game/t_2C9AC0", func_002C9E60);

extern "C" s32 func_002C9E70(void) {
    D_00370E40 = 1;
    return 1;
}

extern "C" s32 func_002C9E80(void) {
    func_0019EE38(0, 0, 0, 0);
    D_0036C378[0] = 2;
    return 1;
}

INCLUDE_ASM("asm/nonmatchings/game/t_2C9AC0", func_002C9EB8);

extern "C" s32 func_002C9F28(int arg0, s32 arg1) {
    func_00289CF8(arg1);
    return 1;
}

INCLUDE_ASM("asm/nonmatchings/game/t_2C9AC0", func_002C9F48);

INCLUDE_ASM("asm/nonmatchings/game/t_2C9AC0", func_002CA158);

INCLUDE_ASM("asm/nonmatchings/game/t_2C9AC0", func_002CA540);

INCLUDE_ASM("asm/nonmatchings/game/t_2C9AC0", func_002CA5C0);

INCLUDE_ASM("asm/nonmatchings/game/t_2C9AC0", func_002CA618);

INCLUDE_ASM("asm/nonmatchings/game/t_2C9AC0", func_002CA6E8);

INCLUDE_ASM("asm/nonmatchings/game/t_2C9AC0", func_002CA818);

INCLUDE_ASM("asm/nonmatchings/game/t_2C9AC0", func_002CA888);

INCLUDE_ASM("asm/nonmatchings/game/t_2C9AC0", func_002CAA08);

extern "C" s32 func_002CAA48(int arg0, s32 arg1) {
    func_00289CF8(arg1);
    return 1;
}

INCLUDE_ASM("asm/nonmatchings/game/t_2C9AC0", func_002CAA68);

INCLUDE_ASM("asm/nonmatchings/game/t_2C9AC0", func_002CB400);

extern "C" s32 func_002CB440(int arg0, s32 arg1) {
    func_00289CF8(arg1);
    return 1;
}

INCLUDE_ASM("asm/nonmatchings/game/t_2C9AC0", func_002CB460);

INCLUDE_ASM("asm/nonmatchings/game/t_2C9AC0", func_002CB830);

extern "C" s32 func_002CB870(int arg0, s32 arg1) {
    func_00289CF8(arg1);
    return 1;
}

INCLUDE_ASM("asm/nonmatchings/game/t_2C9AC0", func_002CB890);
