#include "common.h"

asm(".set D_00368A38_lui, D_00368A38");

asm(".set D_0036CDB4_lui, D_0036CDB4");

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

struct S2DAE48_V8 {
    char pad0[0x8];
    virtual ~S2DAE48_V8();
};

struct S2DAE48_V18 {
    char pad0[0x18];
    virtual void f0();
    virtual ~S2DAE48_V18();
};

struct S2DAE48_E {
    char pad0[0x14];
    void *unk14;
    S2DAE48_V18 *unk18;
    int unk1C;
    int unk20;
    int unk24;
    char pad28[0x38];
    int unk60;
    S2DAE48_V8 *unk64;
};

struct S2DAE48_G {
    char pad0[0x84];
    int unk84;
};

struct S2DAE48_V2418 {
    char pad0[0x2418];
    virtual ~S2DAE48_V2418();
};

struct S2DAE48_H {
    char pad0[0x14];
    void *unk14;
    S2DAE48_V18 *unk18;
    S2DAE48_V18 *unk1C;
    S2DAE48_V18 *unk20;
    S2DAE48_V18 *unk24;
    char pad28[0x38];
    S2DAE48_V2418 *unk60;
};

struct S2DAE48_J {
    char pad0[0x38];
    int unk38;
};

struct S2DAE48_K {
    char pad0[0x1C];
    S2DAE48_J *unk1C;
};

struct S2DAE48_L {
    char pad0[0x28];
    S2DAE48_K *unk28[2];
};

struct S2DAE48_M {
    char pad0[0x20];
    int unk20;
};

extern "C" {
void func_00221DB0(int, int);
int func_002764E8(int, int);
void func_00221BC8(int, int);
int func_001D4480(int, int, int, int);
extern int D_0036D3B0;
extern int D_00368744;
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
void func_002DB268(s32);
s32 func_002DC5B8(s32);
s32 func_002DCB98(s32);
extern s32 D_003E8420[];
extern S2DAE48_D *D_0036CDB4;
extern s32 D_003731E0[];
void func_002302D0(void);
void func_00234CB8(void);
void func_002DC188(s32);
void func_0028CE18(int);
void func_002DCD68(S2DAE48_E *, int);
extern char D_00363488[];
extern char D_00363310[];
void func_001C5610(S2DAE48_E *, int);
int func_001D1CF8(S2DAE48_V8 *, u32);
void func_00221DB8(int);
void func_00298448(int);
void func_001163B8(int);
void func_00129350(void);
void func_00249EF0(void);
int func_001287F0(int, int);
int func_0027AA70(int);
void func_0027FE88(int, int *);
void func_0028C9D0(int, int, int, int, int, int);
void func_0027AC90(int);
void func_00113250(int);
extern char D_00372258[];
extern char D_00372260[];
extern char D_003630B8[];
u32 func_0028DAB8(char *);
void func_0027C028(int, u32, int);
void func_0027C448(int, u32, int);
void func_0028C9F0(u32, int, int, int, int, int);
void func_0028CC70(char *, int, int, int);
void func_002DB110(int, int);
extern char D_003630E8[];
void func_001CE218(S2DAE48_J *, int);
void func_0027C160(int, u32, int);
extern S2DAE48_L *D_0036CDB4_lui[] asm("D_0036CDB4_lui") __attribute__((section(".sdata")));
extern int D_00368A38_lui[] asm("D_00368A38_lui") __attribute__((section(".sdata")));
extern int D_00368A38;
extern int D_00370EE0[] __attribute__((section(".sdata")));
int func_00119610(int, int);
void func_00119490(int, int);
void func_00114958(int, int);
void func_001194B8(int);
}

extern "C" int func_002DAE48(int *p) {
    int a = *p;
    int o = func_0027AA70(func_001287F0(8, 1));
    func_0027C028(o, func_0028DAB8(D_00372258), a);
    func_0028C9F0(0x179BB868, o, 0, 0, 0, 0);
    if (o != 0) {
        func_0027AC90(o);
        func_00113250(o);
    }
    return 1;
}

extern "C" int func_002DAEE0(int *p) {
    int a = *p;
    int b = a + 0x80;
    int o = func_0027AA70(func_001287F0(8, 1));
    func_0027C028(o, func_0028DAB8(D_00372258), a);
    func_0027C028(o, func_0028DAB8(D_00372260), b);
    func_0028CC70(D_003630B8, o, 0, 0);
    if (o != 0) {
        func_0027AC90(o);
        func_00113250(o);
    }
    return 1;
}

extern "C" s32 func_002DAF98(void) {
    return 1;
}

extern "C" s32 func_002DAFA0(void) {
    return 1;
}

extern "C" void func_002DAFA8(void) {
}

extern "C" int func_002DAFB0(int *p) {
    int a = *p;
    int o = func_0027AA70(func_001287F0(8, 1));
    S2DAE48_G *g = (S2DAE48_G *)*p;
    func_0027C028(o, 0xB974F2FC /* modelname */, (int)g);
    func_0027C448(o, 0x09794932 /* skeletonname */, g->unk84);
    func_002DB110(a, o);
    if (o != 0) {
        func_0027AC90(o);
        func_00113250(o);
    }
    return 1;
}

extern "C" s32 func_002DB058(s32 *arg0) {
    func_002DB268(*arg0);
    return 1;
}

extern "C" int func_002DB078(int **pp) {
    int *q = *pp;
    int a = *q++;
    int o = func_0027AA70(func_001287F0(8, 1));
    func_0027FE88(o, q);
    func_0028C9D0(a, o, 0, 0, 0, 0);
    if (o != 0) {
        func_0027AC90(o);
        func_00113250(o);
    }
    return 1;
}

struct S2DB110 {
    char pad0[0x60];
    int unk60;
    int unk64;
};
extern "C" void func_002DB110(int a, int b) {
    S2DB110 *p = (S2DB110 *)a;
    int h;
    int o;
    int g;
    if (D_00368744 != 0) {
        h = D_00368A38_lui[0];
        func_00119490(h, func_00119610(h, 0x3B));
    } else {
        h = D_00368A38_lui[0];
        func_00119490(h, func_00119610(h, 1));
    }
    if (p->unk64 != 0) {
        func_002DB268((int)p);
    }
    o = func_0027AA70(func_001287F0(8, 1));
    func_0027C448(o, 0xA1DC81F9, 0xC85B842A);
    g = D_0036D3B0;
    p->unk64 = func_001D4480(g, func_002764E8(0x34D6E197, 0), o, 0);
    if (o) {
        func_0027AC90(o);
        func_00113250(o);
    }
    func_00221BC8(func_001D1CF8((S2DAE48_V8 *)p->unk64, 0xB38129F1), p->unk60);
    func_00221DB0(func_001D1CF8((S2DAE48_V8 *)p->unk64, 0xB38129F1), b);
    func_001194B8(D_00368A38);
}

extern "C" void func_002DB268(s32 a) {
    S2DAE48_E *p = (S2DAE48_E *)a;
    if (p->unk64 != 0) {
        func_00221DB8(func_001D1CF8(p->unk64, 0xB38129F1 /* viewerobj */));
        delete p->unk64;
        p->unk64 = 0;
    }
}

struct S2DB2D0_P {
    char pad0[0x1C];
    int unk1C;
    int unk20;
    int unk24;
};

struct S2DB2D0_O {
    char pad0[0x18];
    S2DB2D0_P *unk18;
    S2DB2D0_P *unk1C;
    int unk20;
    int unk24;
    char pad28[0x38];
    int unk60;
};

extern "C" {
void func_002981A0(int, int, int, int, int, int);
extern char cb_AF98[] asm("func_002DAF98");
extern char cb_AFA0[] asm("func_002DAFA0");
extern char cb_AEE0[] asm("func_002DAEE0");
extern char cb_AFB0[] asm("func_002DAFB0");
extern char cb_B058[] asm("func_002DB058");
extern char cb_B078[] asm("func_002DB078");
extern int D_0036D020;
extern int D_00368748;
}

INCLUDE_ASM("asm/nonmatchings/game/t_2DAE48", func_002DB2D0);

extern "C" void func_002DB510(S2DAE48_E *p) {
    if (p->unk64 != 0) {
        delete p->unk64;
        p->unk64 = 0;
    }
    func_00113FB8((int)p->unk18);
    func_00113FB8(p->unk20);
    func_00113FB8(p->unk24);
    func_00113FB8(p->unk1C);
    func_00298448(p->unk60 + 4);
}

struct S2DB5_N {
    char pad0[0x18];
    int unk18;
    int unk1C;
    int unk20;
    int unk24;
    int unk28;
    int unk2C;
};

struct S2DB5_C {
    u8 r;
    u8 g;
    u8 b;
    u8 a;
    void Set(u8 r_, u8 g_, u8 b_, u8 a_) {
        r = r_;
        g = g_;
        b = b_;
        a = a_;
    }
};

struct S2DB5_O {
    char pad0[0x14];
    int unk14;
    S2DB5_N *unk18;
    S2DB5_N *unk1C;
    S2DB5_N *unk20;
    S2DB5_N *unk24;
    char pad28[0x28];
    int unk50;
    int unk54;
    int unk58;
    int unk5C;
    int unk60;
};

extern "C" {
int func_001C55A8_n(S2DB5_O *) asm("func_001C55A8");
int func_002FF118_n(int) asm("func_002FF118");
int func_00296598_n(int) asm("func_00296598");
int func_00119610_n(int, int) asm("func_00119610");
int func_00119490_n(int, int) asm("func_00119490");
int func_001194B8_n(int) asm("func_001194B8");
int func_00295E50_n(int, int, int, int, int, int, int) asm("func_00295E50");
int func_0029DB90_n(int, int, int) asm("func_0029DB90");
int func_002765E0_n(u32, int) asm("func_002765E0");
void *operator_new_n(u32, ...) asm("operator_new");
void *func_00113EA8_n(void *, int) asm("func_00113EA8");
extern char D_003630C8[];
extern char D_003630E8[];
extern char D_00363110[];
extern char D_00363130[];
extern int D_00368748;
extern int D_003717E0;
extern f32 D_003733CC;
extern f32 D_003733D0;
void func_002D8398(void);
void func_002D8450(void);
void func_002D8880(void);
void func_002DA050(void);
}

GP_DATA(D_00372230);
extern "C" S2DB5_O *func_002DB580(S2DB5_O *p) {
    func_001C55A8_n(p);
    p->unk50 = 0;
    p->unk14 = (int)D_003630E8;
    p->unk54 = 0;
    if (D_00368748 == 0) {
        int a = D_003717E0;
        int b = a + 0x28;
        func_002FF118_n(b);
        func_00296598_n(a);
        int h = D_00368A38;
        func_00119490_n(h, func_00119610_n(h, 0x2C));
        p->unk60 = func_00295E50_n(a, 0, (int)D_003630C8, 4, 0x2710, func_002FF118_n(b), 0x50);
        func_001194B8_n(D_00368A38);
        func_0029DB90_n(p->unk60, 0x22, 0);
    }
    int t21 = func_002765E0_n(0x702247A5, 0);
    S2DB5_C c;
    S2DB5_N *n1 = (S2DB5_N *)operator_new_n(0x24);
    int fa = (int)func_002D8880;
    func_00113EA8_n(n1, 0);
    n1->unk1C = fa;
    n1->unk20 = (int)p;
    n1->unk18 = (int)D_00363130;
    p->unk20 = n1;
    c.Set(0xFF, 0xFF, 0xFF, 0xFF);
    S2DB5_N *n2 = (S2DB5_N *)operator_new_n(0x30);
    int fb = (int)func_002D8450;
    func_00113EA8_n(n2, 0);
    n2->unk28 = fb;
    n2->unk24 = t21;
    n2->unk18 = (int)D_00363110;
    n2->unk2C = (int)p;
    p->unk18 = n2;
    D_003733D0 = 10.0f;
    D_003733CC = 120.0f;
    S2DB5_N *n3 = (S2DB5_N *)operator_new_n(0x24);
    int fc = (int)func_002DA050;
    func_00113EA8_n(n3, 0);
    n3->unk18 = (int)D_00363130;
    n3->unk1C = fc;
    n3->unk20 = (int)p;
    p->unk24 = n3;
    c.Set(0xFF, 0xFF, 0xFF, 0xFF);
    S2DB5_N *n4 = (S2DB5_N *)operator_new_n(0x30);
    int fd = (int)func_002D8398;
    func_00113EA8_n(n4, 0x3E8);
    n4->unk24 = t21;
    n4->unk18 = (int)D_00363110;
    n4->unk28 = fd;
    n4->unk2C = (int)p;
    p->unk1C = n4;
    D_00372230 = (int)p;
    p->unk5C = 0;
    return p;
}

extern "C" void func_002DB7B8(S2DAE48_H *p, int v) {
    p->unk14 = D_003630E8;
    delete p->unk60;
    delete p->unk18;
    delete p->unk20;
    delete p->unk24;
    delete p->unk1C;
    D_00372230 = 0;
    func_001C5610((S2DAE48_E *)p, v);
}

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

GP_DATA(D_003722B0);
GP_DATA(D_003722B4);
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

extern "C" void func_002DBA80(S2DAE48_C *p) {
    func_002302D0();
    func_00234CB8();
    func_002DC188(p->unk20);
}

INCLUDE_ASM("asm/nonmatchings/game/t_2DAE48", func_002DBAB8);

extern "C" void func_002DC168(S2DC168_0 *arg0) {
    func_00113FB8(arg0->unk18);
}

INCLUDE_ASM("asm/nonmatchings/game/t_2DAE48", func_002DC188);

extern "C" {
int func_0014ED48_n(int) asm("func_0014ED48");
extern char D_00363310[];
extern char D_00363338[];
}

extern "C" s32 func_002DC5B8(s32 a) {
    S2DB5_O *p = (S2DB5_O *)a;
    func_001C55A8_n(p);
    p->unk24 = 0;
    ((int *)p)[10] = 0;
    ((int *)p)[11] = 0;
    ((int *)p)[12] = 0;
    ((int *)p)[13] = 0;
    ((int *)p)[14] = 0;
    p->unk14 = (int)D_00363310;
    S2DB5_N *n = (S2DB5_N *)operator_new_n(0x24);
    int fa = (int)func_002DBA80;
    func_00113EA8_n(n, 0);
    n->unk1C = fa;
    n->unk20 = (int)p;
    n->unk18 = (int)D_00363338;
    p->unk18 = n;
    S2DB5_C c;
    c.Set(0xFF, 0, 0, 0xFF);
    func_0014ED48_n(D_0036D3B0);
    return a;
}

extern "C" void func_002DC670(S2DAE48_E *p, int v) {
    p->unk14 = D_00363310;
    if (p->unk24 != 0) {
        func_001163B8(p->unk24);
    }
    func_00129350();
    func_00249EF0();
    delete p->unk18;
    func_001C5610(p, v);
}

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

extern "C" int CFunc_GetButtonsPressed(int params, S2DAE48_C *script) {
    S2DAE48_K **pads = D_0036CDB4_lui[0]->unk28;
    int i;
    int idx = 0;
    int pressed = 0;
    for (i = 0; i < 2; i++) {
        S2DAE48_K *pad = *pads;
        if (pad) {
            func_001CE218(pad->unk1C, 0x8000);
            if (pad->unk1C->unk38) {
                idx = i;
                pressed = 1;
                break;
            }
        }
        pads++;
    }
    func_0027C160(script->unk20, 0xC9428A08, idx);
    func_0027C160(script->unk20, 0x4EE1B0DD, pressed);
    return 1;
}

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

GP_DATA(D_00372318);
GP_DATA(D_0037231C);
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

extern "C" {
void func_002DCE78(void);
extern char D_00363488[];
extern char D_003634B0[];
}

extern "C" s32 func_002DCB98(s32 a) {
    S2DB5_O *p = (S2DB5_O *)a;
    func_001C55A8_n(p);
    p->unk14 = (int)D_00363488;
    S2DB5_N *n = (S2DB5_N *)operator_new_n(0x24);
    int fa = (int)func_002DCE78;
    func_00113EA8_n(n, -0x7D0);
    n->unk1C = fa;
    n->unk20 = (int)p;
    n->unk18 = (int)D_003634B0;
    p->unk18 = n;
    S2DB5_C c;
    c.Set(0xFF, 0, 0, 0xFF);
    p->unk1C = 0;
    p->unk20 = 0;
    return a;
}

extern "C" void func_002DCC30(S2DAE48_E *p, int v) {
    p->unk14 = D_00363488;
    delete p->unk18;
    func_001C5610(p, v);
}

extern "C" void func_002DCC98(S2DC168_0 *p) {
    int heap = D_00368A38_lui[0];
    func_00119490(heap, func_00119610(heap, 0x3A));
    func_00114958(D_00370EE0[0] + 8, p->unk18);
    func_001194B8(D_00368A38);
}

extern "C" void func_002DCD00(S2DC168_0 *arg0) {
    func_00113FB8(arg0->unk18);
}

extern "C" void func_002DCD20(S2DAE48_E *p, int v) {
    p->unk1C = v;
    func_0028CE18(v);
    func_002DCD68(p, v);
}

extern "C" {
void func_00117AA0(int);
void func_00117B50(int);
void func_0011EB98(void);
void func_0011EBA0(void);
void func_00145558(int, int);
void func_001D48D0(int, int);
void func_00260D88(void);
void func_00260D98(void);
void func_002754D0(int);
void func_002DC6F8_a(int, int) asm("func_002DC6F8");
void func_002E7C08(void);
void func_002E7C30(void);
extern int D_003688E8;
extern int D_00369798;
extern int D_00369A64;
}

OBJECT_END();
extern "C" void func_002DCD68(S2DAE48_E *p, int v) {
    if (v != ((int *)p)[8]) {
        if (v != 0) {
            func_002E7C08();
            func_00260D88();
        } else {
            func_002E7C30();
            func_00260D98();
        }
        int t = D_003722B0;
        if (v != 0) {
            func_002DC6F8_a(t, 1);
            func_00117AA0(D_003688E8);
        } else {
            func_00117B50(D_003688E8);
        }
        func_001D48D0(D_0036D3B0, v);
        func_002754D0(v);
        func_00145558(D_00369798, v);
        D_00369A64 = v;
        ((int *)p)[8] = v;
        if (v != 0) {
            *(int *)(D_00370EE0[0] + 0x10) = 0xC;
            func_0011EB98();
            return;
        }
        int t2 = D_003722B0;
        *(int *)(D_00370EE0[0] + 0x10) = 0;
        func_002DC6F8_a(t2, 0);
        func_0011EBA0();
    }
}
