#include "common.h"

struct S2A34F0_1 {
    char pad0[0x20];
    s32 unk20;
};

extern "C" {
extern int D_003301E0[];
extern int D_00330260[];
extern s32 D_00368744[] __attribute__((section(".sdata")));
extern s32 D_003723D8[] __attribute__((section(".sdata")));
extern s32 D_00372EE0;
extern s32 D_00372EF8;
extern s32 D_00372F00;
extern s32 D_00372F08;
extern s32 D_00372F10;
int func_002348A0(void);
void func_00275510(f32);
int func_0027C028(s32, int, void *);
int func_0027D188(int, int, int, int);
int func_0027D268(int, int, int, int);
void func_002A48D0(s32 arg0, s32 arg1);
int func_002A5638(void);
int func_0030A970(void *, s32);
}

INCLUDE_ASM("asm/nonmatchings/game/t_2A32E0", func_002A32E0);

extern "C" s32 func_002A3340(s32 arg0) {
    f32 sp0;

    sp0 = 1.0f;
    func_0027D268(arg0, 0, (s32) &sp0, 0);
    func_00275510(sp0);
    return 1;
}

INCLUDE_ASM("asm/nonmatchings/game/t_2A32E0", func_002A3380);

extern "C" s32 func_002A33C0(void) {
    return D_00368744[0] != 0;
}

INCLUDE_ASM("asm/nonmatchings/game/t_2A32E0", func_002A33D0);

INCLUDE_ASM("asm/nonmatchings/game/t_2A32E0", func_002A34A0);

extern "C" s32 func_002A34F0(int arg0, S2A34F0_1 *arg1) {
    func_0027C028(arg1->unk20, 0x20F4889D /* save_zone */, D_003301E0);
    return 1;
}

INCLUDE_ASM("asm/nonmatchings/game/t_2A32E0", func_002A3520);

extern "C" s32 func_002A3620(void) {
    return 0;
}

extern "C" s32 func_002A3628(void) {
    func_002348A0();
    return 1;
}

INCLUDE_ASM("asm/nonmatchings/game/t_2A32E0", func_002A3648);

extern "C" s32 func_002A3698(void) {
    return 1;
}

extern "C" s32 func_002A36A0(void) {
    return 1;
}

extern "C" s32 func_002A36A8(void) {
    D_003723D8[0] = 0;
    return 1;
}

INCLUDE_ASM("asm/nonmatchings/game/t_2A32E0", func_002A36B8);

INCLUDE_ASM("asm/nonmatchings/game/t_2A32E0", func_002A3748);

INCLUDE_ASM("asm/nonmatchings/game/t_2A32E0", func_002A37E0);

INCLUDE_ASM("asm/nonmatchings/game/t_2A32E0", func_002A3818);

INCLUDE_ASM("asm/nonmatchings/game/t_2A32E0", func_002A38D0);

extern "C" s32 func_002A3E40(void) {
    return 0;
}

extern "C" s32 func_002A3E48(void) {
    return 0;
}

extern "C" s32 func_002A3E50(void) {
    return 1;
}

extern "C" s32 func_002A3E58(s32 arg0) {
    s32 sp0;
    func_0027D188(arg0, 0x61414D56 /* STRING */, (s32) &sp0, 0);
    func_0030A970(D_00330260, sp0);
    return 1;
}

extern "C" s32 func_002A3E98(void) {
    return D_00372EE0;
}

INCLUDE_ASM("asm/nonmatchings/game/t_2A32E0", func_002A3EA0);

INCLUDE_ASM("asm/nonmatchings/game/t_2A32E0", func_002A48C0);

extern "C" void func_002A48D0(s32 arg0, s32 arg1) {
    if ((arg1 == 0xFFFF) && (arg0 != 0)) {
        D_00372EF8 = 0x91C1EC93 /* create_model_from_appearance */;
        D_00372F00 = 0xD2C041C2;
        D_00372F08 = 0xAEE1AF7D;
        D_00372F10 = 0xB1A55798;
    }
}

extern "C" void func_002A4920(void) {
    func_002A48D0(1, 0xFFFF);
}

INCLUDE_ASM("asm/nonmatchings/game/t_2A32E0", func_002A4940);

extern "C" s32 func_002A49E0(void) {
    return 1;
}

extern "C" s32 func_002A49E8(void) {
    return 0;
}

extern "C" s32 func_002A49F0(void) {
    return 1;
}

extern "C" s32 func_002A49F8(void) {
    return 0;
}

extern "C" s32 func_002A4A00(void) {
    return 0;
}

extern "C" s32 func_002A4A08(void) {
    return 1;
}

extern "C" s32 func_002A4A10(void) {
    return 1;
}

extern "C" s32 func_002A4A18(void) {
    return 1;
}

extern "C" s32 func_002A4A20(void) {
    return 0;
}

extern "C" s32 func_002A4A28(void) {
    return 0;
}

extern "C" s32 func_002A4A30(void) {
    return 1;
}

extern "C" s32 func_002A4A38(void) {
    return 1;
}

extern "C" s32 func_002A4A40(void) {
    return 1;
}

extern "C" s32 func_002A4A48(void) {
    return 1;
}

extern "C" s32 func_002A4A50(void) {
    return 1;
}

extern "C" void func_002A4A58(void) {
    func_002A5638();
}

INCLUDE_ASM("asm/nonmatchings/game/t_2A32E0", func_002A4A78);

INCLUDE_ASM("asm/nonmatchings/game/t_2A32E0", func_002A4AF0);

INCLUDE_ASM("asm/nonmatchings/game/t_2A32E0", func_002A4B50);

INCLUDE_ASM("asm/nonmatchings/game/t_2A32E0", func_002A4D28);

INCLUDE_ASM("asm/nonmatchings/game/t_2A32E0", func_002A4DB8);
