#include "common.h"

struct S2DB8A0_0 {
    char pad0[0x64];
    s32 unk64;
};

struct S2DB8F0_0 {
    char pad0[0x50];
    s32 unk50;
};

struct S2DB970_0 {
    char pad0[0x18];
    void *unk18;
};

struct S2DC168_0 {
    char pad0[0x18];
    s32 unk18;
};

struct S2DAE48_A {
    char pad0[0x28];
    s32 unk28;
    s32 unk2C;
    s32 unk30;
};
struct S2DAE48_B {
    char pad0[0x1C];
    s32 (*unk1C)(S2DAE48_B *);
    char pad20[0x8];
    s32 (*unk28)(S2DAE48_B *);
};
struct S2DAE48_C {
    char pad0[0x20];
    s32 unk20;
};
struct S2DAE48_D {
    char pad0[0x28];
    s32 unk28[2];
};

struct S2DAE48_V {
    char pad0[0x14];
    virtual ~S2DAE48_V();
};

extern "C" {
extern int D_00342398[];
extern s32 D_0037222C;
extern s32 D_00372230;
extern s32 D_003722B0;
extern s32 D_003722B4;
extern s32 D_00372318;
extern s32 D_0037231C;
extern f32 D_003733CC;
extern f32 D_003733D0;
s32 func_00113DF0(int, int, int);
int func_00113F38(int, int);
int func_00113FB8(s32);
int func_00275F08(int, int);
void func_002DAFA8(void);
int func_002DB268(s32);
s32 func_002DC5B8(s32);
s32 func_002DCB98(s32);
extern s32 D_003E8420[];
extern S2DAE48_D *D_0036CDB4;
extern s32 D_003731E0[];
void func_002302D0(void);
void func_00234CB8(void);
void func_002DC188(s32);
}

INCLUDE_ASM("asm/nonmatchings/game/t_2DAE48", func_002DAE48);

INCLUDE_ASM("asm/nonmatchings/game/t_2DAE48", func_002DAEE0);

extern "C" s32 func_002DAF98(void) {
    return 1;
}

extern "C" s32 func_002DAFA0(void) {
    return 1;
}

extern "C" void func_002DAFA8(void) {
}

INCLUDE_ASM("asm/nonmatchings/game/t_2DAE48", func_002DAFB0);

extern "C" s32 func_002DB058(s32 *arg0) {
    func_002DB268(*arg0);
    return 1;
}

INCLUDE_ASM("asm/nonmatchings/game/t_2DAE48", func_002DB078);

INCLUDE_ASM("asm/nonmatchings/game/t_2DAE48", func_002DB110);

INCLUDE_ASM("asm/nonmatchings/game/t_2DAE48", func_002DB268);

INCLUDE_ASM("asm/nonmatchings/game/t_2DAE48", func_002DB2D0);

INCLUDE_ASM("asm/nonmatchings/game/t_2DAE48", func_002DB510);

INCLUDE_ASM("asm/nonmatchings/game/t_2DAE48", func_002DB580);

INCLUDE_ASM("asm/nonmatchings/game/t_2DAE48", func_002DB7B8);

extern "C" s32 func_002DB8A0(S2DB8A0_0 *arg0) {
    return arg0->unk64;
}

extern "C" void func_002DB8A8(s32 arg0) {
    D_0037222C = arg0;
}

extern "C" void func_002DB8B0(f32 fparg0) {
    D_003733D0 = fparg0;
}

extern "C" void func_002DB8B8(f32 fparg0) {
    D_003733CC = fparg0;
}

extern "C" s32 func_002DB8C0(void) {
    func_00275F08(0xC965E06F /* resetcameratoviewerobject */, 0);
    return 1;
}

extern "C" s32 func_002DB8E8(void) {
    return D_00372230;
}

extern "C" void func_002DB8F0(S2DB8F0_0 *arg0, s32 arg1) {
    arg0->unk50 = (s32) (arg0->unk50 | arg1);
}

extern "C" s32 CFunc_ReQBRAll(void) {
    func_002DAFA8();
    return 1;
}

INCLUDE_ASM("asm/nonmatchings/game/t_2DAE48", func_002DB920);

extern "C" void func_002DB970(S2DB970_0 *arg0, s32 arg1) {
    arg0->unk18 = D_00342398;
    func_00113F38((s32) arg0, arg1);
}

extern "C" s32 func_002DB998(S2DAE48_B *p) {
    return p->unk28(p);
}

extern "C" s32 func_002DB9B8(S2DAE48_B *p) {
    return p->unk1C(p);
}

extern "C" s32 func_002DB9D8(s32 arg0) {
    if ((D_003722B0 == 0) && (arg0 != 0)) {
        D_003722B0 = func_002DC5B8(func_00113DF0(0x48, 0, 1));
    }
    D_003722B4 += 1;
    return D_003722B0;
}

extern "C" void func_002DBA28(void) {
    if ((u32)D_003722B4 >= 2) {
        D_003722B4--;
    } else {
        delete (S2DAE48_V *)D_003722B0;
        D_003722B0 = 0;
        D_003722B4 = 0;
    }
}

INCLUDE_ASM("asm/nonmatchings/game/t_2DAE48", func_002DBA80);

INCLUDE_ASM("asm/nonmatchings/game/t_2DAE48", func_002DBAB8);

extern "C" void func_002DC168(S2DC168_0 *arg0) {
    func_00113FB8(arg0->unk18);
}

INCLUDE_ASM("asm/nonmatchings/game/t_2DAE48", func_002DC188);

INCLUDE_ASM("asm/nonmatchings/game/t_2DAE48", func_002DC5B8);

INCLUDE_ASM("asm/nonmatchings/game/t_2DAE48", func_002DC670);

extern "C" void func_002DC6F8(void) {
}

INCLUDE_ASM("asm/nonmatchings/game/t_2DAE48", func_002DC700);

extern "C" void func_002DC8E0(void) {
}

INCLUDE_ASM("asm/nonmatchings/game/t_2DAE48", func_002DC8E8);

extern "C" s32 CFunc_ResumeControllerChecking(void) {
    ((S2DAE48_A *)D_003722B0)->unk30 = 0;
    return 1;
}

INCLUDE_ASM("asm/nonmatchings/game/t_2DAE48", CFunc_GetButtonsPressed);

extern "C" s32 func_002DC9D8(s32 i) {
    return D_003E8420[i];
}

extern "C" void func_002DC9F0(s32 i, s32 v) {
    D_003E8420[i] = v;
}

extern "C" s32 func_002DCA08(s32 i) {
    if (i < 2) {
        return D_0036CDB4->unk28[i];
    }
    return D_003731E0[i - 2];
}

extern "C" s32 func_002DCA40(s32 arg0) {
    return arg0 + 2;
}

INCLUDE_ASM("asm/nonmatchings/game/t_2DAE48", func_002DCA48);

extern "C" s32 CFunc_GetButtonsReleased(void) {
    return 1;
}

extern "C" s32 CFunc_GetButtonsHeld(void) {
    return 1;
}

INCLUDE_ASM("asm/nonmatchings/game/t_2DAE48", func_002DCA68);

extern "C" s32 CFunc_ShouldGameBePausedDueToSysNotification(void) {
    S2DAE48_A *p = (S2DAE48_A *)D_003722B0;
    s32 r = 0;
    if (p->unk28 || p->unk2C || p->unk30) {
        r = 1;
    }
    return r;
}

INCLUDE_ASM("asm/nonmatchings/game/t_2DAE48", func_002DCAA8);

extern "C" s32 func_002DCAD0(S2DAE48_B *p) {
    return p->unk1C(p);
}

extern "C" s32 func_002DCAF0(s32 arg0) {
    if ((D_00372318 == 0) && (arg0 != 0)) {
        D_00372318 = func_002DCB98(func_00113DF0(0x24, 0, 1));
    }
    D_0037231C += 1;
    return D_00372318;
}

extern "C" void func_002DCB40(void) {
    if ((u32)D_0037231C >= 2) {
        D_0037231C--;
    } else {
        delete (S2DAE48_V *)D_00372318;
        D_00372318 = 0;
        D_0037231C = 0;
    }
}

INCLUDE_ASM("asm/nonmatchings/game/t_2DAE48", func_002DCB98);

INCLUDE_ASM("asm/nonmatchings/game/t_2DAE48", func_002DCC30);

INCLUDE_ASM("asm/nonmatchings/game/t_2DAE48", func_002DCC98);

extern "C" void func_002DCD00(S2DC168_0 *arg0) {
    func_00113FB8(arg0->unk18);
}

INCLUDE_ASM("asm/nonmatchings/game/t_2DAE48", func_002DCD20);

INCLUDE_ASM("asm/nonmatchings/game/t_2DAE48", func_002DCD68);
