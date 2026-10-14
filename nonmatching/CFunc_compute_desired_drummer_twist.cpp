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

extern "C" {
int func_001287F0(int, int);
int func_0027AA70(int);
void func_0027AC90(int);
void func_0027C448(int, u32, int);
void func_0027C1F8(int, u32, f32);
void func_0027C898(int, u32, int);
void func_001CFA70(int, int, int);
void func_001CFB88(int, int, int);
void func_00113250(int);
}

extern "C" void func_002CC5A0(int a, int key, int v, int g, f32 f) {
    if (v == 0) return;
    int s1 = func_0027AA70(func_001287F0(8, 1));
    int s2 = func_0027AA70(func_001287F0(8, 1));
    if (key == 0x85981897) {
        func_0027C448(s1, 0xA1DC81F9, 0x2C7E20C1);
        func_001CFA70(a, s1, g);
        func_0027AC90(s1);
        func_0027C448(s1, 0, 0x2C7E20C1);
        func_0027C448(s2, 0x98549BA4, v);
        func_0027C1F8(s2, 0xBF237659, f);
        func_0027C898(s1, 0x7031F10C, s2);
        func_001CFB88(a, s1, g);
    } else {
        func_0027C448(s1, 0xA1DC81F9, 0x8B990189);
        func_001CFA70(a, s1, g);
        func_0027AC90(s1);
        func_0027C448(s1, 0, 0x8B990189);
        func_0027C448(s2, 0x98549BA4, v);
        func_0027C898(s1, 0x7031F10C, s2);
        func_001CFB88(a, s1, g);
    }
    if (s1 != 0) {
        func_0027AC90(s1);
        func_00113250(s1);
    }
}

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

struct S2CT_Script {
    char pad0[0x20];
    int unk20;
};

extern "C" void func_0027C1F8(int, u32, float);

extern "C" int CFunc_compute_desired_drummer_twist(int unused, S2CT_Script *script) {
    char buf[32];
    int sp20;
    float sp24;
    int sp28;
    float sp2C;
    float f20 = 0.0f;
    float f21 = f20;
    int t = func_002763E0(0x30786149, 1);
    int ok = func_0027CC30(t, 0xD57255D8, 1, &sp20);
    int v = sp20;
    if (ok == 0) {
        func_0027F1E0(t, 0, 1);
        v = 0;
    }
    if ((u32)(v - 0x25) < 9) {
        func_0030B550(buf, D_00362C90, v);
        int r = func_002763E0(0xC00ADCF2, 1);
        int ok2 = func_0027CC30(r, CrcFromPathLowercase(buf), 2, &sp24);
        f21 = sp24;
        if (ok2 == 0) {
            f21 = 0.0f;
            func_0027F1E0(r, 0, 1);
        }
    }
    int ok3 = func_0027CC30(t, 0xA1D671EC, 1, &sp28);
    int w = sp28;
    if (ok3 == 0) {
        func_0027F1E0(t, 0, 1);
        w = 0;
    }
    if ((u32)(w - 0x31) < 9) {
        func_0030B550(buf, D_00362C90, w);
        int r = func_002763E0(0xAF64F942, 1);
        int ok4 = func_0027CC30(r, CrcFromPathLowercase(buf), 2, &sp2C);
        f20 = sp2C;
        if (ok4 == 0) {
            f20 = 0.0f;
            func_0027F1E0(r, 0, 1);
        }
    }
    func_0027C1F8(script->unk20, 0xEEBB2F28, (f20 + f21) * 0.5f);
    return 1;
}

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

struct S2CD_St {
    int unk0;
    int unk4;
    f32 unk8;
};

struct S2CD_Obj {
    int p;
};

struct S2CD_Script {
    char pad0[0x20];
    int unk20;
};

extern "C" {
void func_00139590(int, void *, f32 *);
void func_00144FC0(int, int, int, int, int);
void func_00145310(S2CD_Obj *, int, int, int);
void func_001CE888(int, void *);
f32 func_00275DE0(u32, int);
int func_0027D870(int, u32, int *, int);
S2CD_St *func_00289C80_p(S2CD_Script *) asm("func_00289C80");
int func_002B5888(int);
extern int D_00369798;
}

INCLUDE_ASM("asm/nonmatchings/game/t_2CBC10", CFunc_kill_object_later_CFunc);
