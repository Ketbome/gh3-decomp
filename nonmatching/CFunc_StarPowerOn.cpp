#include "common.h"

extern "C" {
void func_00269E50(f32, f32);
extern s32 D_0036CBF4[] __attribute__((section(".sdata")));
extern f32 D_003721D8;
f32 func_00275DE0(int, int);
s32 func_00275F08(int, int);
int func_002B4CB0(int, int);
int func_002D2110(int);
}

extern "C" void func_002D2350(void) {
    if (func_00275F08(0x0AA160D8 /* replay_suspend */, 0) != 1) {
        func_002D2110(0x26C80B0D /* Replay */);
    }
}

INCLUDE_ASM("asm/nonmatchings/game/t_2D2350", func_002D2390);

INCLUDE_ASM("asm/nonmatchings/game/t_2D2350", func_002D2758);

INCLUDE_ASM("asm/nonmatchings/game/t_2D2350", CFunc_script_callback_script_cfunc);

extern "C" void func_002D31E0(f32 a, f32 b) {
    func_00269E50(a * 0.01f, b * 0.01f);
}

INCLUDE_ASM("asm/nonmatchings/game/t_2D2350", CFunc_update_guitar_volume_cfunc);

INCLUDE_ASM("asm/nonmatchings/game/t_2D2350", CFunc_CheckButtonsBoss);

GP_DATA(D_003721D8);
extern "C" s32 CFunc_CheckBossCutoff(void) {
    f32 temp_f1;

    if (D_003721D8 > 0.0f) {
        temp_f1 = D_003721D8 - func_00275DE0(0x6D735468 /* current_deltatime */, 1);
        D_003721D8 = temp_f1;
        if (temp_f1 <= 0.0f) {
            func_002B4CB0(0xE5E9AAE8 /* boss_pattern */, 0);
        }
    }
    return 1;
}

struct S2D_H {
    int p;
    char pad4[0xC];
};

struct S2D_Col {
    s8 r;
    s8 g;
    s8 b;
    s8 a;
};

struct S2D_Arr {
    char pad0[4];
    int size;
    int data;
    int GetI(int i) {
        if (size == 1) {
            return data;
        }
        return ((int *)data)[i];
    }
};

extern "C" {
int func_0027CC30(int, int, int, int *);
void func_0027F1E0(int, int, int);
void func_00145310(S2D_H *, int, int, int);
void func_00139CE8(int, int, f32);
void func_00139D50(int, S2D_Col *, int);
S2D_Arr *func_002764E8(int, int);
void func_002B4A60(int, int);
void func_001CE888(int, void *);
extern int D_00369798;
extern int D_00372F60[];
extern int D_00372F68[];
extern int D_00372F70[];
}

extern "C" int CFunc_StarPowerOn(int params) {
    S2D_H a;
    S2D_H b;
    S2D_H c;
    S2D_Col col;
    S2D_Col col2;
    int sp50;
    register int i asm("$3");
    if (!func_0027CC30(params, 0x67E6859A, 1, &sp50)) {
        func_0027F1E0(params, 0, 1);
        i = 0;
    } else {
        i = sp50;
    }
    int k = i - 1;
    int sys = D_00369798;
    int t1 = D_00372F68[k];
    int t2 = D_00372F70[k];
    func_00145310(&a, sys, D_00372F60[k], 0);
    func_00145310(&b, sys, t1, 0);
    func_00145310(&c, sys, t2, 0);
    if (a.p) {
        func_00139CE8(a.p, 1, 1.0f);
    }
    if (b.p) {
        func_00139CE8(b.p, 1, 1.0f);
    }
    if (c.p) {
        S2D_Arr *arr = func_002764E8(0x7FD3D839, 1);
        col.r = arr->GetI(0);
        col.g = arr->GetI(1);
        col.b = arr->GetI(2);
        col.a = arr->GetI(3);
        col2 = col;
        func_00139D50(c.p, &col2, 1);
    }
    if (func_00275F08(0xA2660D69, 1) == 1) {
        func_002B4A60(0xDFF7E48B, 0);
    }
    if (c.p) {
        func_001CE888(c.p, &c);
        c.p = 0;
    }
    if (b.p) {
        func_001CE888(b.p, &b);
        b.p = 0;
    }
    if (a.p) {
        func_001CE888(a.p, &a);
        a.p = 0;
    }
    return 1;
}

extern "C" s32 CFunc_ResetWhammyCachedRows(void) {
    D_0036CBF4[0] = 0;
    return 1;
}

INCLUDE_ASM("asm/nonmatchings/game/t_2D2350", CFunc_proj_gh3c_build_gs_available_guitar_array_last_loop);

INCLUDE_ASM("asm/nonmatchings/game/t_2D2350", CFunc_select_guitar_build_brand_array);
