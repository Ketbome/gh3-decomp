#include "common.h"

extern "C" {
extern int D_003710A4;
extern s32 D_0036D554[] __attribute__((section(".sdata")));
int func_001DAC78(int, int, int, int, int, int, f32);
int func_0027AF38(int, int, int);
}

INCLUDE_ASM("asm/nonmatchings/game/t_2B3AC8", CFunc_CalcSongScoreInfo);

extern "C" int func_002B47E0(int v) {
    int r = v & 1;
    if (r == 0) r = v;
    if (r & 0x10) r = v & 0x11;
    if (r & 0x100) r = v & 0x111;
    if (r & 0x1000) r = v & 0x1111;
    return r;
}

extern "C" int func_002B4810(int a, int b) {
    int r = b;
    if (a & 0x1000) r = b & 0x1111;
    if (a & 0x100) r = b & 0x111;
    if (a & 0x10) r = b & 0x11;
    if (a & 1) r = b & 1;
    return r;
}

INCLUDE_ASM("asm/nonmatchings/game/t_2B3AC8", func_002B4848);

INCLUDE_ASM("asm/nonmatchings/game/t_2B3AC8", func_002B48F0);

INCLUDE_ASM("asm/nonmatchings/game/t_2B3AC8", func_002B49D8);

extern "C" void func_002B4A18(s32 arg0, s32 arg1) {
    func_001DAC78(D_0036D554[0], arg0, 0x640E830A /* broadcast */, 0x36B2EE74 /* system */, arg1, 1, -1.0f);
}

INCLUDE_ASM("asm/nonmatchings/game/t_2B3AC8", func_002B4A60);

INCLUDE_ASM("asm/nonmatchings/game/t_2B3AC8", func_002B4B50);

extern "C" void func_002B4B98(int arg0, int arg1, s32 arg2) {
    int p = func_0027AF38(arg0, arg1, 0);
    if (p != 0) {
        *(s32 *)(p + 0x8) = arg2;
    }
}

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

struct S2B4CB0 {
    char pad0[4];
    int unk4;
    int unk8;
    int unkC;
    S2B4CB0 *unk10;
};
INCLUDE_ASM("asm/nonmatchings/game/t_2B3AC8", func_002B4CB0);

INCLUDE_ASM("asm/nonmatchings/game/t_2B3AC8", func_002B4CE8);

INCLUDE_ASM("asm/nonmatchings/game/t_2B3AC8", func_002B4E30);

INCLUDE_ASM("asm/nonmatchings/game/t_2B3AC8", func_002B53E0);

INCLUDE_ASM("asm/nonmatchings/game/t_2B3AC8", func_002B5528);

INCLUDE_ASM("asm/nonmatchings/game/t_2B3AC8", func_002B5888);

INCLUDE_ASM("asm/nonmatchings/game/t_2B3AC8", func_002B5990);
