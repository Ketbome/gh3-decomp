#include "common.h"

extern "C" {
extern s32 D_0037236C;
extern f32 D_00372370;
extern f32 D_00372374;
extern f32 D_00372378;
extern s32 D_00372580;
extern s32 D_00372584;
extern s32 D_00372DC8[] __attribute__((section(".sdata")));
extern s32 D_00372DF8[] __attribute__((section(".sdata")));
extern s32 D_00372E10[] __attribute__((section(".sdata")));
extern int D_0038EE10[];
extern int D_0038F1F0[];
extern int D_0038F230[];
s32 func_00113D20(int);
s32 func_00113DF0(int, int, int);
int func_001ECC90(s32);
int func_001F35D0(s32);
int func_00276D68(s32, void *, int);
int func_002DD738(int, int);
int func_002DDBD8(int, int);
s32 func_002DE280(s32);
}

INCLUDE_ASM("asm/nonmatchings/game/t_2DCE78", func_002DCE78);

INCLUDE_ASM("asm/nonmatchings/game/t_2DCE78", func_002DCF10);

INCLUDE_ASM("asm/nonmatchings/game/t_2DCE78", func_002DD080);

INCLUDE_ASM("asm/nonmatchings/game/t_2DCE78", func_002DD0B0);

INCLUDE_ASM("asm/nonmatchings/game/t_2DCE78", func_002DD0D0);

INCLUDE_ASM("asm/nonmatchings/game/t_2DCE78", func_002DD108);

INCLUDE_ASM("asm/nonmatchings/game/t_2DCE78", func_002DD160);

INCLUDE_ASM("asm/nonmatchings/game/t_2DCE78", func_002DD288);

INCLUDE_ASM("asm/nonmatchings/game/t_2DCE78", func_002DD308);

extern "C" void func_002DD3C0(s32 arg0, f32 fparg0, f32 fparg1, f32 fparg2) {
    D_0037236C = arg0;
    D_00372370 = fparg0;
    D_00372374 = fparg1;
    D_00372378 = fparg2;
}

INCLUDE_ASM("asm/nonmatchings/game/t_2DCE78", func_002DD3D8);

INCLUDE_ASM("asm/nonmatchings/game/t_2DCE78", func_002DD3E0);

INCLUDE_ASM("asm/nonmatchings/game/t_2DCE78", func_002DD490);

INCLUDE_ASM("asm/nonmatchings/game/t_2DCE78", func_002DD578);

INCLUDE_ASM("asm/nonmatchings/game/t_2DCE78", func_002DD670);

INCLUDE_ASM("asm/nonmatchings/game/t_2DCE78", func_002DD738);

extern "C" void func_002DD778(void) {
    func_002DD738(1, 0xFFFF);
}

extern "C" s32 func_002DD798(void) {
    return 0;
}

INCLUDE_ASM("asm/nonmatchings/game/t_2DCE78", func_002DD7A0);

extern "C" s32 func_002DD808(void) {
    return 1;
}

INCLUDE_ASM("asm/nonmatchings/game/t_2DCE78", func_002DD810);

INCLUDE_ASM("asm/nonmatchings/game/t_2DCE78", func_002DD8F8);

extern "C" s32 func_002DD980(void) {
    return 0xDDFE0DB9 /* PROGRESS */;
}

INCLUDE_ASM("asm/nonmatchings/game/t_2DCE78", func_002DD990);

INCLUDE_ASM("asm/nonmatchings/game/t_2DCE78", func_002DD9F0);

INCLUDE_ASM("asm/nonmatchings/game/t_2DCE78", func_002DDA40);

INCLUDE_ASM("asm/nonmatchings/game/t_2DCE78", func_002DDA90);

INCLUDE_ASM("asm/nonmatchings/game/t_2DCE78", func_002DDAE0);

INCLUDE_ASM("asm/nonmatchings/game/t_2DCE78", func_002DDB68);

INCLUDE_ASM("asm/nonmatchings/game/t_2DCE78", func_002DDBA8);

INCLUDE_ASM("asm/nonmatchings/game/t_2DCE78", func_002DDBB0);

INCLUDE_ASM("asm/nonmatchings/game/t_2DCE78", func_002DDBD0);

INCLUDE_ASM("asm/nonmatchings/game/t_2DCE78", func_002DDBD8);

extern "C" void func_002DDDA8(void) {
    func_002DDBD8(1, 0xFFFF);
}

INCLUDE_ASM("asm/nonmatchings/game/t_2DCE78", func_002DDDC8);

INCLUDE_ASM("asm/nonmatchings/game/t_2DCE78", func_002DE0C0);

extern "C" void func_002DE0F0(void) {
    func_00276D68(D_00372E10[0], D_0038F230, 0x10);
}

extern "C" void func_002DE120(void) {
    func_001F35D0(func_00113D20(0xC0));
}

extern "C" void func_002DE148(void) {
    func_00276D68(D_00372DF8[0], D_0038F1F0, 0x10);
}

extern "C" void func_002DE178(void) {
    func_001ECC90(func_00113D20(0xA0));
}

extern "C" void func_002DE1A0(void) {
    func_00276D68(D_00372DC8[0], D_0038EE10, 0x10);
}

extern "C" s32 func_002DE1D0(s32 arg0) {
    if ((D_00372580 == 0) && (arg0 != 0)) {
        D_00372580 = func_002DE280(func_00113DF0(0x10F00, 0, 1));
    }
    D_00372584 += 1;
    return D_00372580;
}

INCLUDE_ASM("asm/nonmatchings/game/t_2DCE78", func_002DE220);

INCLUDE_ASM("asm/nonmatchings/game/t_2DCE78", func_002DE280);

INCLUDE_ASM("asm/nonmatchings/game/t_2DCE78", func_002DE418);

INCLUDE_ASM("asm/nonmatchings/game/t_2DCE78", func_002DE4C8);

extern "C" void func_002DE530(void) {
}

INCLUDE_ASM("asm/nonmatchings/game/t_2DCE78", func_002DE538);

INCLUDE_ASM("asm/nonmatchings/game/t_2DCE78", func_002DE578);

INCLUDE_ASM("asm/nonmatchings/game/t_2DCE78", func_002DE5A8);

extern "C" void func_002DE5B0(void) {
}

INCLUDE_ASM("asm/nonmatchings/game/t_2DCE78", func_002DE5B8);

extern "C" void func_002DE5F8(void) {
}

extern "C" void func_002DE600(void) {
}

extern "C" void func_002DE608(void) {
}

extern "C" void func_002DE610(void) {
}

extern "C" s32 func_002DE618(void) {
    return 0;
}

extern "C" void func_002DE620(void) {
}

extern "C" void func_002DE628(void) {
}

extern "C" void func_002DE630(void) {
}

INCLUDE_ASM("asm/nonmatchings/game/t_2DCE78", func_002DE638);

extern "C" s32 func_002DE700(void) {
    return 0;
}

extern "C" s32 func_002DE708(void) {
    return 0;
}

extern "C" s32 func_002DE710(void) {
    return 0;
}

extern "C" void func_002DE718(void) {
}

extern "C" void func_002DE720(void) {
}

extern "C" void func_002DE728(void) {
}

extern "C" s32 func_002DE730(void) {
    return 0;
}

INCLUDE_ASM("asm/nonmatchings/game/t_2DCE78", func_002DE738);

INCLUDE_ASM("asm/nonmatchings/game/t_2DCE78", func_002DEA78);

INCLUDE_ASM("asm/nonmatchings/game/t_2DCE78", func_002DEE18);

extern "C" s32 func_002DEE40(void) {
    return 0;
}

INCLUDE_ASM("asm/nonmatchings/game/t_2DCE78", func_002DEE48);

INCLUDE_ASM("asm/nonmatchings/game/t_2DCE78", CFunc_StartNetworkGame);
