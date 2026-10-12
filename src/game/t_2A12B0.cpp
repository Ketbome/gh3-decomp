#include "common.h"

struct S2A1758_1 {
    char pad0[0x20];
    s32 unk20;
};

struct S2A2550_0 {
    s32 unk0;
    s32 unk4;
    s32 unk8;
    s32 unkC;
};

extern "C" {
extern f32 D_0036CA70[] __attribute__((section(".sdata")));
extern s32 D_0036F520[] __attribute__((section(".sdata")));
extern s32 D_0036F608[] __attribute__((section(".sdata")));
extern s32 D_00372318[] __attribute__((section(".sdata")));
extern s32 D_00372EF0[] __attribute__((section(".sdata")));
int func_00222F90(int);
void func_00225BF0(int, int);
int func_002297A8(s32);
int func_002297D8(s32, s32);
s32 func_002765E0(int, int);
int func_0027C1F8(s32, int, f32);
int func_0027C448(s32, int, s32);
int func_0027D188(int, int, int, int);
int func_0027D870(int, int, int, int);
int func_002A1840(int, int);
int func_002A1AE0(int, int, int);
int func_002A2568(int, int, int);
int func_002DCD20(s32, int);
}

INCLUDE_ASM("asm/nonmatchings/game/t_2A12B0", func_002A12B0);

INCLUDE_ASM("asm/nonmatchings/game/t_2A12B0", func_002A1300);

INCLUDE_ASM("asm/nonmatchings/game/t_2A12B0", func_002A1350);

INCLUDE_ASM("asm/nonmatchings/game/t_2A12B0", func_002A13A0);

INCLUDE_ASM("asm/nonmatchings/game/t_2A12B0", func_002A13F0);

INCLUDE_ASM("asm/nonmatchings/game/t_2A12B0", func_002A1440);

INCLUDE_ASM("asm/nonmatchings/game/t_2A12B0", func_002A1490);

INCLUDE_ASM("asm/nonmatchings/game/t_2A12B0", func_002A14E0);

INCLUDE_ASM("asm/nonmatchings/game/t_2A12B0", func_002A1530);

INCLUDE_ASM("asm/nonmatchings/game/t_2A12B0", func_002A1580);

INCLUDE_ASM("asm/nonmatchings/game/t_2A12B0", func_002A15D0);

INCLUDE_ASM("asm/nonmatchings/game/t_2A12B0", func_002A1620);

INCLUDE_ASM("asm/nonmatchings/game/t_2A12B0", func_002A1670);

INCLUDE_ASM("asm/nonmatchings/game/t_2A12B0", func_002A16C0);

extern "C" s32 func_002A16D0(void) {
    return 0;
}

extern "C" s32 func_002A16D8(void) {
    return 0;
}

extern "C" s32 func_002A16E0(void) {
    return 0;
}

extern "C" s32 func_002A16E8(void) {
    return 0;
}

extern "C" s32 func_002A16F0(void) {
    return 0;
}

extern "C" s32 func_002A16F8(void) {
    return 0;
}

extern "C" s32 func_002A1700(void) {
    return 0;
}

extern "C" s32 func_002A1708(void) {
    return 0;
}

extern "C" s32 func_002A1710(void) {
    return 0;
}

extern "C" s32 func_002A1718(void) {
    return 0;
}

extern "C" s32 func_002A1720(s32 arg0) {
    s32 sp0;
    func_0027D870(arg0, 0, (s32) &sp0, 1);
    D_00372EF0[0] = sp0;
    return 1;
}

extern "C" s32 func_002A1758(int arg0, S2A1758_1 *arg1) {
    func_0027C448(arg1->unk20, 0x91652189 /* ps2_saveload_successor_checksum */, D_00372EF0[0]);
    return 1;
}

INCLUDE_ASM("asm/nonmatchings/game/t_2A12B0", func_002A1788);

extern "C" s32 func_002A17F0(int arg0, S2A1758_1 *arg1) {
    func_0027C1F8(arg1->unk20, 0x6FEC35E2, D_0036CA70[0]);
    return 1;
}

extern "C" s32 func_002A1820(void) {
    return 0x3AF;
}

extern "C" s32 func_002A1828(void) {
    return 0x43;
}

INCLUDE_ASM("asm/nonmatchings/game/t_2A12B0", func_002A1830);

INCLUDE_ASM("asm/nonmatchings/game/t_2A12B0", func_002A1840);

extern "C" void func_002A1868(void) {
    func_002A1840(1, 0xFFFF);
}

INCLUDE_ASM("asm/nonmatchings/game/t_2A12B0", func_002A1888);

INCLUDE_ASM("asm/nonmatchings/game/t_2A12B0", func_002A18E0);

INCLUDE_ASM("asm/nonmatchings/game/t_2A12B0", func_002A1918);

INCLUDE_ASM("asm/nonmatchings/game/t_2A12B0", func_002A1AE0);

extern "C" void func_002A1C50(s32 arg0) {
    s32 sp0;
    func_0027D870(arg0, 0, (s32) &sp0, 1);
    func_00222F90(sp0);
}

extern "C" void func_002A1C80(s32 arg0) {
    func_002297D8(D_0036F608[0], arg0);
}

INCLUDE_ASM("asm/nonmatchings/game/t_2A12B0", func_002A1CA8);

extern "C" int func_002A1CF0(int arg0, int arg1) {
    return func_002A1AE0(arg0, arg1, 8);
}

extern "C" int func_002A1D10(int arg0, int arg1) {
    return func_002A1AE0(arg0, arg1, 6);
}

extern "C" int func_002A1D30(int arg0, int arg1) {
    return func_002A1AE0(arg0, arg1, 1);
}

extern "C" int func_002A1D50(int arg0, int arg1) {
    return func_002A1AE0(arg0, arg1, 2);
}

extern "C" int func_002A1D70(int arg0, int arg1) {
    return func_002A1AE0(arg0, arg1, 3);
}

INCLUDE_ASM("asm/nonmatchings/game/t_2A12B0", func_002A1D90);

extern "C" s32 func_002A1E30(void) {
    return 1;
}

extern "C" void func_002A1E38(void) {
    func_002297A8(D_0036F608[0]);
}

INCLUDE_ASM("asm/nonmatchings/game/t_2A12B0", func_002A1E60);

INCLUDE_ASM("asm/nonmatchings/game/t_2A12B0", func_002A1EF0);

INCLUDE_ASM("asm/nonmatchings/game/t_2A12B0", func_002A2030);

extern "C" s32 func_002A2098(s32 arg0) {
    s32 sp0;
    func_0027D188(arg0, 0, (s32) &sp0, 1);
    func_00225BF0(D_0036F520[0], sp0);
    return 1;
}

extern "C" s32 func_002A20D0(void) {
    return 1;
}

extern "C" s32 func_002A20D8(void) {
    return 1;
}

extern "C" s32 func_002A20E0(void) {
    return func_002765E0(0x2A648514 /* cas_artist */, 0) != 0;
}

INCLUDE_ASM("asm/nonmatchings/game/t_2A12B0", func_002A2108);

INCLUDE_ASM("asm/nonmatchings/game/t_2A12B0", func_002A2200);

INCLUDE_ASM("asm/nonmatchings/game/t_2A12B0", func_002A2230);

extern "C" int func_002A2260(int arg0, int arg1) {
    return func_002A2568(arg0, arg1, 1);
}

extern "C" int func_002A2280(int arg0, int arg1) {
    return func_002A2568(arg0, arg1, 0);
}

extern "C" int func_002A22A0(int arg0, int arg1) {
    return func_002A2568(arg0, arg1, 2);
}

extern "C" int func_002A22C0(int arg0, int arg1) {
    return func_002A2568(arg0, arg1, 5);
}

INCLUDE_ASM("asm/nonmatchings/game/t_2A12B0", func_002A22E0);

extern "C" void func_002A2550(S2A2550_0 *arg0, s32 arg1, s32 arg2) {
    arg0->unk0 = arg1;
    arg0->unk4 = arg2;
    arg0->unkC = 0;
    arg0->unk8 = 0;
}

INCLUDE_ASM("asm/nonmatchings/game/t_2A12B0", func_002A2568);

INCLUDE_ASM("asm/nonmatchings/game/t_2A12B0", func_002A26F0);

INCLUDE_ASM("asm/nonmatchings/game/t_2A12B0", func_002A29A8);

INCLUDE_ASM("asm/nonmatchings/game/t_2A12B0", func_002A2BE0);

INCLUDE_ASM("asm/nonmatchings/game/t_2A12B0", func_002A2E68);

INCLUDE_ASM("asm/nonmatchings/game/t_2A12B0", func_002A2FB0);

INCLUDE_ASM("asm/nonmatchings/game/t_2A12B0", func_002A3110);

INCLUDE_ASM("asm/nonmatchings/game/t_2A12B0", func_002A3218);

extern "C" s32 func_002A3270(void) {
    func_002DCD20(D_00372318[0], 0);
    return 1;
}

INCLUDE_ASM("asm/nonmatchings/game/t_2A12B0", func_002A3298);
