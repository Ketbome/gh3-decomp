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

INCLUDE_ASM("asm/nonmatchings/game/t_2C57B8", func_002C7688);
