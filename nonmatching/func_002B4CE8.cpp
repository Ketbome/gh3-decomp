#include "common.h"

extern "C" {
int func_001287F0(int, int);
int func_0027AA70(int);
void func_0027AC90(int);
void func_00113250(int);
int func_0028D1D8(int, int, int, int, int, int, int, int, int, int);
int func_0028C200(int);
extern int D_003710A4;
extern s32 D_0036D554[] __attribute__((section(".sdata")));
int func_001DAC78(int, int, int, int, int, int, f32);
int func_0027AF38(int, int, int);
extern int D_00371F90[2];
int func_0027CC30(int, u32, int, int *);
void func_0027F1E0(int, int, int);
int func_0027D1F8(int, u32, int *, int);
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

extern "C" int func_002B49D8(int a) {
    if (a == 0x10000 || a == 0x1000 || a == 0x100) {
        return 1;
    }
    if (a == 0x10) {
        return 1;
    }
    return a == 1;
}

extern "C" void func_002B4A18(s32 arg0, s32 arg1) {
    func_001DAC78(D_0036D554[0], arg0, 0x640E830A /* broadcast */, 0x36B2EE74 /* system */, arg1, 1, -1.0f);
}

extern "C" void func_002B4A60(int a, int b) {
    u8 c[4];
    u8 *p = c;
    c[0] = 0xFF;
    p[1] = 0xFF;
    p[2] = 0xFF;
    p[3] = 0xFF;
    if (b != 0) {
        int r = func_0028D1D8(a, b, 0, 0, 0, 0, 0, 0, 0, 0);
        if (r != 0) {
            func_0028C200(r);
        }
    } else {
        b = func_0027AA70(func_001287F0(8, 1));
        int r = func_0028D1D8(a, b, 0, 0, 0, 0, 0, 0, 0, 0);
        if (r != 0) {
            func_0028C200(r);
        }
        if (b != 0) {
            func_0027AC90(b);
            func_00113250(b);
        }
    }
}

extern "C" int func_002B4B50(int arg0, int arg1, int arg2) {
    int p = func_0027AF38(arg0, arg1, 0);
    int r = arg2;
    if (p != 0) {
        r = *(int *)(p + 8) + arg2;
        *(int *)(p + 8) = r;
    }
    return r;
}

extern "C" void func_002B4B98(int arg0, int arg1, s32 arg2) {
    int p = func_0027AF38(arg0, arg1, 0);
    if (p != 0) {
        *(s32 *)(p + 0x8) = arg2;
    }
}

extern "C" f32 func_002B4BC8(int arg0, int arg1, f32 v) {
    int p = func_0027AF38(arg0, arg1, 0);
    f32 r = v;
    if (p != 0) {
        r = *(f32 *)(p + 8) + v;
        *(f32 *)(p + 8) = r;
    }
    return r;
}

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

struct S2B4C_A {
    int unk0;
    int unk4;
    int *unk8;
};

extern "C" S2B4C_A *func_002764E8_p(u32, int) asm("func_002764E8");

GP_DATA(D_00371F90);
extern "C" int func_002B4CE8(int target, int slot) {
    int s = D_00371F90[slot];
    int v;
    int cur;
    int done = 0;
    if (func_0027CC30(s, 0xCA0FB2, 1, &v) == 0) {
        func_0027F1E0(s, 0, 1);
        cur = 0;
    } else {
        cur = v;
    }
    S2B4C_A *arr = func_002764E8_p(0xD85ACCCE, 0);
    do {
        int i = cur + 1;
        int idx = i;
        if (i < arr->unk4) {
            int item;
            if (arr->unk4 == 1)
                item = (int)arr->unk8;
            else
                item = arr->unk8[idx];
            int out;
            func_0027D1F8(item, 0x906B67BA, &out, 1);
            if (target < out) {
                done = 1;
            } else {
                cur = idx;
                func_002B4B50(D_00371F90[slot], 0xCA0FB2, 1);
            }
        } else {
            done = 1;
        }
    } while (!done);
    return cur;
}

INCLUDE_ASM("asm/nonmatchings/game/t_2B3AC8", func_002B4E30);

INCLUDE_ASM("asm/nonmatchings/game/t_2B3AC8", func_002B53E0);

INCLUDE_ASM("asm/nonmatchings/game/t_2B3AC8", func_002B5528);

INCLUDE_ASM("asm/nonmatchings/game/t_2B3AC8", func_002B5888);

INCLUDE_ASM("asm/nonmatchings/game/t_2B3AC8", func_002B5990);
