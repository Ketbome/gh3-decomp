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

struct S2D23_Arr {
    int unk0;
    int size;
    int data;
    int Get(int i) {
        if (size == 1) {
            return data;
        }
        return ((int *)data)[i];
    }
};

extern "C" {
int func_0027CC30(int, u32, int, int *);
void func_0027F1E0(int, int, int);
S2D23_Arr *func_002764E8(int, int);
int func_0027D1F8(int, u32, int *, int);
int func_002B4848(int);
extern int D_00373088[];
extern int D_00372F58[];
}

GP_DATA(D_003721D8);
extern "C" int CFunc_CheckButtonsBoss(int arg0) {
    int idx;
    int bi;
    int ok = func_0027CC30(arg0, 0x67E6859A, 1, &idx);
    int k = idx;
    if (ok == 0) {
        func_0027F1E0(arg0, 0, 1);
        k = 0;
    }
    k -= 1;
    int a = D_00373088[k];
    int c18 = func_00275F08(0xE2593B84, 1);
    int c20 = func_00275F08(0x28A23CD9, 1);
    S2D23_Arr *t = func_002764E8(D_00372F58[k], 1);
    func_0027D1F8(arg0, 0x5CA15C8F, &bi, 1);
    S2D23_Arr *x = (S2D23_Arr *)t->Get(bi);
    int mx = 0;
    func_002B4CB0(0x33FE9EEF, bi);
    int r19 = func_002B4848((int)x);
    int sz = x->size;
    int sz2 = sz;
    int i = 0;
    do {
        i++;
        int v;
        if (sz == 1) {
            v = x->data;
        } else {
            v = ((int *)x->data)[i];
        }
        if (mx < v) mx = v;
    } while (i < 5);
    int e6;
    if (sz2 != 1) {
        e6 = ((int *)x->data)[6];
    } else {
        e6 = x->data;
    }
    D_003721D8 = -1.0f;
    func_002B4CB0(0x080957F5, a);
    int flag;
    if (e6 == 1 && c18 < c20) {
        c18++;
        flag = 0;
    } else {
        c18 = 0;
        flag = 1;
    }
    func_002B4CB0(0xE5E9AAE8, r19);
    func_002B4CB0(0xE2593B84, c18);
    func_002B4CB0(0x242B6AEA, flag);
    float f = 1.0f;
    if (mx >= 0x3D) {
        f = (float)mx * 0.001f + 1.0f;
    }
    D_003721D8 = f;
    return 1;
}

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

INCLUDE_ASM("asm/nonmatchings/game/t_2D2350", CFunc_StarPowerOn);

extern "C" s32 CFunc_ResetWhammyCachedRows(void) {
    D_0036CBF4[0] = 0;
    return 1;
}

INCLUDE_ASM("asm/nonmatchings/game/t_2D2350", CFunc_proj_gh3c_build_gs_available_guitar_array_last_loop);

INCLUDE_ASM("asm/nonmatchings/game/t_2D2350", CFunc_select_guitar_build_brand_array);
