#include "common.h"

extern "C" {
extern s32 D_0036D554[] __attribute__((section(".sdata")));
int func_001DAC78(int, int, int, int, int, int, f32);
int func_0027AF38(int, int, int);
}

INCLUDE_ASM("asm/nonmatchings/game/t_2B3AC8", CFunc_CalcSongScoreInfo);

INCLUDE_ASM("asm/nonmatchings/game/t_2B3AC8", func_002B47E0);

INCLUDE_ASM("asm/nonmatchings/game/t_2B3AC8", func_002B4810);

INCLUDE_ASM("asm/nonmatchings/game/t_2B3AC8", func_002B4848);

INCLUDE_ASM("asm/nonmatchings/game/t_2B3AC8", func_002B48F0);

INCLUDE_ASM("asm/nonmatchings/game/t_2B3AC8", func_002B49D8);

extern "C" void func_002B4A18(s32 arg0, s32 arg1) {
    func_001DAC78(D_0036D554[0], arg0, 0x640E830A /* broadcast */, 0x36B2EE74 /* system */, arg1, 1, -1.0f);
}

INCLUDE_ASM("asm/nonmatchings/game/t_2B3AC8", func_002B4A60);

INCLUDE_ASM("asm/nonmatchings/game/t_2B3AC8", func_002B4B50);

INCLUDE_ASM("asm/nonmatchings/game/t_2B3AC8", func_002B4B98);

INCLUDE_ASM("asm/nonmatchings/game/t_2B3AC8", func_002B4BC8);

extern "C" void func_002B4C08(s32 arg0, s32 arg1, f32 fparg0) {
    s32 temp_2;

    temp_2 = func_0027AF38(arg0, arg1, 0);
    if (temp_2 != 0) {
        (*(f32 *)((char *)(temp_2) + 0x8)) = fparg0;
    }
}

INCLUDE_ASM("asm/nonmatchings/game/t_2B3AC8", func_002B4C38);

INCLUDE_ASM("asm/nonmatchings/game/t_2B3AC8", func_002B4C70);

INCLUDE_ASM("asm/nonmatchings/game/t_2B3AC8", func_002B4CB0);

INCLUDE_ASM("asm/nonmatchings/game/t_2B3AC8", func_002B4CE8);

INCLUDE_ASM("asm/nonmatchings/game/t_2B3AC8", func_002B4E30);

INCLUDE_ASM("asm/nonmatchings/game/t_2B3AC8", func_002B53E0);

INCLUDE_ASM("asm/nonmatchings/game/t_2B3AC8", func_002B5528);

INCLUDE_ASM("asm/nonmatchings/game/t_2B3AC8", func_002B5888);

INCLUDE_ASM("asm/nonmatchings/game/t_2B3AC8", func_002B5990);
