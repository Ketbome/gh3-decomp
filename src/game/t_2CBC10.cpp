#include "common.h"

struct S2CC510 {
    char pad0[0x8];
    f32 unk8;
};

struct S2CC7C8_Arr {
    int unk0;
    int size;
    int data;
};

extern "C" {
void func_0030B550(char *, const char *, ...);
extern char D_00362C90[];
int CrcFromPathLowercase(char *);
int func_002763E0(u32, int);
int func_0027CC30(int, int, int, void *);
void func_0027F1E0(int, int, int);
int func_0010C050(int);
s32 *func_00289C80(s32);
void func_00289C88(s32, s32);
S2CC510 *func_0027AF38(int, int, int);
int func_00289CF8(s32);
}

extern "C" s32 CFunc_FretFingers_iterator_CFunc_Setup(int arg0, s32 arg1) {
    func_00289C88(arg1, 0x3C);
    *func_00289C80(arg1) = 0;
    return 1;
}

extern "C" s32 CFunc_FretFingers_iterator_CFunc_Cleanup(int arg0, s32 arg1) {
    func_00289CF8(arg1);
    return 1;
}

INCLUDE_ASM("asm/nonmatchings/game/t_2CBC10", CFunc_FretFingers_iterator_CFunc);

extern "C" void func_002CC510(int arg0, int arg1, f32 arg2) {
    func_0027AF38(arg0, arg1, 0)->unk8 = arg2;
}

extern "C" void func_002CC540(int arg0, int arg1, s32 arg2) {
    *(s32 *)&func_0027AF38(arg0, arg1, 0)->unk8 = arg2;
}

extern "C" void func_002CC570(int arg0, int arg1, s32 arg2) {
    *(s32 *)&func_0027AF38(arg0, arg1, 0)->unk8 = arg2;
}

INCLUDE_ASM("asm/nonmatchings/game/t_2CBC10", func_002CC5A0);

extern "C" s32 CFunc_Drum_iterator_CFunc_Setup(int arg0, s32 arg1) {
    func_00289C88(arg1, 0x24);
    *func_00289C80(arg1) = 0;
    return 1;
}

extern "C" s32 CFunc_Drum_iterator_CFunc_Cleanup(int arg0, s32 arg1) {
    func_00289CF8(arg1);
    return 1;
}

extern "C" int func_002CC7C8(int a) {
    char buf[0x20];
    S2CC7C8_Arr *arr;
    int crc;
    int h;
    int idx;
    int ok;
    S2CC7C8_Arr *t;
    func_0030B550(buf, D_00362C90, a);
    crc = CrcFromPathLowercase(buf);
    h = func_002763E0(0xCF26CFAD, 0);
    ok = func_0027CC30(h, crc, 0xC, &arr);
    t = arr;
    if (ok == 0) {
        func_0027F1E0(h, 0, 1);
        t = 0;
    }
    idx = func_0010C050(t->size);
    int r;
    if (t->size == 1) {
        r = t->data;
    } else {
        r = ((int *)t->data)[idx];
    }
    return r;
}

INCLUDE_ASM("asm/nonmatchings/game/t_2CBC10", CFunc_Drum_iterator_CFunc);

INCLUDE_ASM("asm/nonmatchings/game/t_2CBC10", CFunc_compute_desired_drummer_twist);

extern "C" s32 CFunc_gem_array_stepper_CFunc_Setup(int arg0, s32 arg1) {
    func_00289C88(arg1, 0x4C);
    *(s32 *)(func_00289C80(arg1) + 0x0) = 0;
    return 1;
}

extern "C" s32 CFunc_gem_array_stepper_CFunc_Cleanup(int arg0, s32 arg1) {
    func_00289CF8(arg1);
    return 1;
}

INCLUDE_ASM("asm/nonmatchings/game/t_2CBC10", CFunc_gem_array_stepper_CFunc);

extern "C" s32 CFunc_kill_object_later_CFunc_Setup(int arg0, s32 arg1) {
    func_00289C88(arg1, 0xC);
    *(s32 *)(func_00289C80(arg1) + 0x0) = 0;
    return 1;
}

extern "C" s32 CFunc_kill_object_later_CFunc_Cleanup(int arg0, s32 arg1) {
    func_00289CF8(arg1);
    return 1;
}

INCLUDE_ASM("asm/nonmatchings/game/t_2CBC10", CFunc_kill_object_later_CFunc);
