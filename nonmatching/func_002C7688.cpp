#include "common.h"

extern "C" {
void func_002C5970(int, int);
int func_0027D870(int, int, int *, int);
int func_002763E0(int, int);
void func_002C5FF0(int, int);
int func_0030B550(char *, char *, ...);
u32 CrcFromPathLowercase(const char *);
void *func_002764E8(u32, int);
int func_002B4848(void *);
void func_002CC540(int, u32, int);
extern char D_00362BC0[];
}

struct S2C6B_X {
    char pad0[0x18];
    int unk18;
};

struct S2C6B_E {
    int unk0;
    int unk4;
    S2C6B_X *unk8;
};

struct S2C6B_A {
    int unk0;
    int unk4;
    S2C6B_E **unk8;
};


extern "C" {
f32 func_00275DE0(u32, int);
int func_00275F08(u32, int);
int func_00276008(u32, int);
extern int D_00371FA8;
extern int D_00371FF8;
extern f32 D_003720F8;
extern int D_003720FC;
extern int D_00372100;
extern f32 D_00372104;
extern f32 D_00372108;
extern f32 D_0037210C;
extern f32 D_00372110;
extern int D_00372114;
extern f32 D_00372118;
extern int D_00373008;
extern int D_00373108;
}

GP_DATA(D_003720F8);
GP_DATA(D_003720FC);
GP_DATA(D_00371FA8);
GP_DATA(D_00372100);
GP_DATA(D_00372104);
GP_DATA(D_00372108);
GP_DATA(D_0037210C);
GP_DATA(D_00372110);
GP_DATA(D_00372114);
GP_DATA(D_00372118);
GP_DATA(D_00371FF8);
extern "C" int CFunc_CrowdReset(void) {
    int a = func_00276008(0x8320D478, 1);
    f32 b = func_00275DE0(0xA6154355, 1);
    int c = func_00275F08(0x8B911E90, 1);
    int d = func_00275F08(0x2B277F68, 1);
    int e = func_00275F08(0x5DC387E3, 0);
    f32 f = func_00275DE0(0x4655D620, 1);
    f32 g = func_00275DE0(0xC8042B53, 1);
    f32 h = func_00275DE0(0xE49AA1BC, 1);
    f32 i = func_00275DE0(0x9BF1EA43, 1);
    int j = func_00275F08(0x201B78BD, 1);
    int k = func_00275F08(0x13FD2B2A, 1);
    f32 l = func_00275DE0(0x487AF1B1, 0);
    int m = func_00275F08(0xD0A7147D, 1);
    D_00373008 = a;
    D_003720F8 = b;
    D_003720FC = c;
    D_00371FA8 = d;
    D_00372100 = e;
    D_00372104 = f;
    D_00372108 = g;
    D_0037210C = h;
    D_00372110 = i;
    D_00373108 = j;
    D_00372114 = k;
    D_00372118 = l;
    D_00371FF8 = m != 0;
    return 1;
}

INCLUDE_ASM("asm/nonmatchings/game/t_2C57B8", func_002C5970);

extern "C" void CFunc_CrowdIncrease(int arg0, int arg1) {
    int out;
    func_0027D870(arg0, 0x1BFF0C3D, &out, 1);
    func_002C5970(arg1, func_002763E0(out, 1));
}

INCLUDE_ASM("asm/nonmatchings/game/t_2C57B8", func_002C5FF0);

extern "C" void CFunc_CrowdDecrease(int arg0, int arg1) {
    int out;
    func_0027D870(arg0, 0x1BFF0C3D, &out, 1);
    func_002C5FF0(arg1, func_002763E0(out, 1));
}

extern "C" char *func_0027D828(int, u32);
extern "C" void func_002B4A18(int, int);
extern "C" char D_00362BB0[];

extern "C" int CFunc_GemArrayStepperCompressedBroadcastEvent(int a0, int *o) {
    u8 c[4];
    char buf[0x100];
    c[0] = 0xFF;
    c[1] = 0xFF;
    c[2] = 0xFF;
    c[3] = 0xFF;
    char *q = D_00362BB0;
    char *s1 = func_0027D828(o[8], 0x666E080B);
    char *s2 = func_0027D828(o[8], 0x75040615);
    char *s3 = func_0027D828(o[8], 0x818AF862);
    char *d = buf;
    if (D_00362BB0[0] != 0) {
        do {
            *d = *q;
            q++;
            d++;
        } while (*q != 0);
    }
    q = s1;
    while (*q != 0) {
        *d = *q;
        q++;
        d++;
    }
    q = s2;
    while (*q != 0) {
        *d = *q;
        q++;
        d++;
    }
    q = s3;
    while (*q != 0) {
        *d = *q;
        q++;
        d++;
    }
    *d = 0;
    func_002B4A18(CrcFromPathLowercase(buf), o[8]);
    return 1;
}

extern "C" void func_002C6B20(int name, int idx, int arg) {
    char buf[64];
    S2C6B_E *e;
    int x;
    func_0030B550(buf, D_00362BC0, name);
    S2C6B_A *a = (S2C6B_A *)func_002764E8(CrcFromPathLowercase(buf), 1);
    if (a->unk4 == 1)
        e = (S2C6B_E *)a->unk8;
    else
        e = a->unk8[idx];
    int n = func_002B4848(e);
    if (e->unk4 == 1)
        x = (int)e->unk8;
    else
        x = e->unk8->unk18;
    int o = func_002763E0(arg, 1);
    func_002CC540(o, 0xA3B56E54, n);
    if (x == 1)
        func_002CC540(o, 0xEB463FC2, 0);
    else
        func_002CC540(o, 0xEB463FC2, 1);
}

INCLUDE_ASM("asm/nonmatchings/game/t_2C57B8", CFunc_GemStep);

INCLUDE_ASM("asm/nonmatchings/game/t_2C57B8", CFunc_NoteFX);

struct S2C76_H {
    int p;
    int a;
    int b;
};
extern "C" {
void func_00145310(S2C76_H *, int, int, int);
void func_001CE868(int, S2C76_H *);
void func_001CE888(int, S2C76_H *);
void func_00145068(int, S2C76_H *, int, int, int);
void func_00144BC0(S2C76_H *, int, u32, int, int);
int func_001287F0(int, int);
int func_0027AA70(int);
void func_0027AC90(int);
void func_00113250(int);
void func_0027C448(int, u32, int);
void func_0027CB80(int, u32, int);
void func_0027C1F8(int, u32, f32);
void func_0027C5B0(int, u32, f32, f32);
void func_00139840(int, f32, f32);
void func_001395D8(int, int, f32, f32);
void func_00139E98(int, f32);
extern int D_003AC920[][5];
extern int D_00372FC8[];
extern int D_00369798;
}

extern "C" void func_002C7688(int a, int b, f32 xx, f32 yy) {
    register f32 x asm("$f21") = xx;
    register f32 y asm("$f20") = yy;
    S2C76_H h0;
    S2C76_H h1;
    S2C76_H h2;
    register int ra asm("$2") = a * 0x14;
    register int rb asm("$5") = b * 4;
    register char *bs asm("$3") = (char *)D_003AC920;
    int e = *(int *)(ra + rb + bs);
    int mgr = D_00369798;
    register char *cs asm("$6") = (char *)D_00372FC8;
    int c = *(int *)(a * 4 + cs);
    func_00145310(&h0, mgr, e, 0);
    if (h0.p) {
        h1.a = 0;
        h1.b = 0;
        h1.p = h0.p;
        func_001CE868(h0.p, &h1);
        func_00145068(mgr, &h1, 1, 0, 0);
    }
    func_00145310(&h1, mgr, c, 0);
    int o = h1.p; if (o) func_001CE888(o, &h1); h1.p = 0; if (o) {        int s = func_0027AA70(func_001287F0(8, 1));
        func_0027C448(s, 0xC2719FB0, c);
        func_0027C448(s, 0x6D80164E, 0x22C32BF2);
        func_0027C448(s, 0x54628ED7, 0x02E58C18);
        func_0027CB80(s, 0xF785EDA0, 1);
        func_0027C1F8(s, 0x8B2B1A67, 0.005f);
        func_0027C5B0(s, 0x211230C7, 4.0f, 4.0f);
        func_0027C5B0(s, 0x34A68574, 128.0f, 128.0f);
        func_00144BC0(&h2, mgr, 0xB12B510A, e, s);
        int q = h2.p;
        if (q) {
            func_001CE888(q, &h2);
            h2.p = 0;
        }
        func_00139840(q, 0.0f, 1.0f);
        func_001395D8(q, 0, x, y);
        func_00139E98(q, 10.0f);
        if (s) {
            func_0027AC90(s);
            func_00113250(s);
        }
    }
    if (h0.p) {
        func_001CE888(h0.p, &h0);
        h0.p = 0;
    }
}
