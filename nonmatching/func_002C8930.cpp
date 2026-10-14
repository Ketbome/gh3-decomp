// cflags: -funroll-loops
#include "common.h"

struct S2C79_Arr {
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

struct S2C79_Scr {
    char pad0[0x20];
    int unk20;
};

extern "C" {
void func_0027C160(int, int, int);
int func_002B4848(int);
bool func_0027D1F8_b(int, int, int *, int) asm("func_0027D1F8");
bool func_0027D870_b(int, int, int *, int) asm("func_0027D870");
void func_002C7900(int, int, int);
S2C79_Arr *func_002764E8(int, int);
int func_002763E0(int, int);
int func_0027D1F8(int, int, int *, int);
int func_0027D870(int, int, int *, int);
int func_0027CC30(int, u32, int, void *);
void func_0027F1E0(int, int, int);
f32 func_00260D08_f(void) asm("func_00260D08");
f32 func_002B4BC8(int, int, f32);
extern int D_00372128[2];
extern f32 D_00372138[2];
extern f32 D_00372140[2];
extern int D_00372148[2];
extern f32 D_00373080[];
extern f32 D_00373158[];
extern f32 D_00373198[];
struct S2C79_Row {
    f32 v[4000];
};
extern S2C79_Row D_003CDFC8[];
}

INCLUDE_ASM("asm/nonmatchings/game/t_2C7900", func_002C7900);

INCLUDE_ASM("asm/nonmatchings/game/t_2C7900", CFunc_WhammyFXOn);

extern "C" int CFunc_WhammyFXOff(int arg0) {
    int a;
    int b;
    int c;
    int d;
    int e;
    int i;
    int mask;
    S2C79_Arr *x;
    S2C79_Arr *t;
    func_0027D870(arg0, 0xCC12115E, &a, 1);
    func_0027D1F8(arg0, 0x5CA15C8F, &b, 1);
    t = func_002764E8(a, 1);
    x = (S2C79_Arr *)t->Get(b);
    mask = 0x10000;
    func_0027D870(arg0, 0x1BFF0C3D, &c, 1);
    func_0027D1F8(func_002763E0(c, 1), 0x67E6859A, &d, 1);
    d -= 1;
    func_0027D1F8(arg0, 0x5C430371, &e, 1);
    for (i = 0; i < 5; i++) {
        if (e & mask) {
            if (x->Get(i + 1) > 0) {
                func_002C7900(d, i, 1);
            }
        }
        mask >>= 4;
    }
    return 1;
}

INCLUDE_ASM("asm/nonmatchings/game/t_2C7900", CFunc_WhammyFXOffAll);

extern "C" int CFunc_GetStrumPattern(int arg0, S2C79_Scr *script) {
    int a;
    int b;
    bool missing = !func_0027D870_b(arg0, 0xCC12115E, &a, 0);
    if (!missing) {
        S2C79_Arr *t = func_002764E8(a, 1);
        missing = !func_0027D1F8_b(arg0, 0xD4DE628F, &b, 0);
        if (!missing) {
            int v = t->Get(b);
            func_0027C160(script->unk20, 0x55CC895E, func_002B4848(v));
            return 1;
        }
    }
    return 0;
}

INCLUDE_ASM("asm/nonmatchings/game/t_2C7900", CFunc_CheckNoteHoldInit);

INCLUDE_ASM("asm/nonmatchings/game/t_2C7900", CFunc_CheckNoteHoldWait);

INCLUDE_ASM("asm/nonmatchings/game/t_2C7900", CFunc_CheckNoteHoldStart);

GP_DATA(D_00372128);
GP_DATA(D_00372148);
GP_DATA(D_00372138);
GP_DATA(D_00372140);
extern "C" void func_002C8930(int s, int unused, int idx, int flag, int arg4) {
    int a;
    int b;
    f32 c;
    int lvl;
    int two;
    f32 div;
    f32 mul;
    f32 scale;
    if (!flag || idx != 1) {
        if (func_0027CC30(s, 0xA675A409, 1, &a)) {
            lvl = a;
        } else {
            func_0027F1E0(s, 0, 1);
            lvl = 0;
        }
        if (func_0027CC30(s, 0x92BE3D33, 1, &b)) {
            two = b;
        } else {
            func_0027F1E0(s, 0, 1);
            two = 0;
        }
        if (func_0027CC30(s, 0x3498FBC5, 2, &c)) {
            div = c;
        } else {
            func_0027F1E0(s, 0, 1);
            div = 0.0f;
        }
        mul = D_00373158[idx];
        scale = 4.0f;
        if (lvl < 10) {
            scale = 1.0f;
        } else if (lvl < 20) {
            scale = 2.0f;
        } else if (lvl < 30) {
            scale = 3.0f;
        }
        if (two == 1) {
            scale += scale;
        }
        f32 base = D_003CDFC8[idx].v[D_00372128[idx]];
        if (arg4) {
            func_002B4BC8(s, 0xCD66C8AE, (base - (f32)D_00372148[idx]) * scale * D_00373198[idx]);
        } else {
            f32 now = D_00373080[idx] + func_00260D08_f() * 1000.0f;
            f32 last = D_00372138[idx];
            if (last < now) {
                D_00372138[idx] = now;
                f32 acc = D_00372140[idx] + (now - last) / div * mul;
                int d = (int)acc - D_00372148[idx];
                D_00372140[idx] = acc;
                if (d >= 2) {
                    func_002B4BC8(s, 0xCD66C8AE, (f32)d * scale * D_00373198[idx]);
                    D_00372148[idx] += d;
                }
            }
        }
    }
}

INCLUDE_ASM("asm/nonmatchings/game/t_2C7900", CFunc_CheckNoteHoldPerFrame);

INCLUDE_ASM("asm/nonmatchings/game/t_2C7900", CFunc_CheckNoteHoldEnd);

INCLUDE_ASM("asm/nonmatchings/game/t_2C7900", CFunc_UpdateGuitarVolume);
