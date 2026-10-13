#include "common.h"

struct S29F598_0 {
    char pad0[0x3148];
    s32 unk3148;
};

struct S29F628_0 {
    char pad0[0x3158];
    s32 unk3158;
};

struct S29F638_0 {
    char pad0[0x30AC];
    s32 unk30AC;
};

struct S29F970_0 {
    char pad0[0x30CC];
    s32 unk30CC;
};

struct S29FA00_0 {
    char pad0[0x30D8];
    s32 unk30D8;
};

struct S29F288_A {
    char pad0[0x30D8];
    int unk30D8;
};

extern "C" {
void func_0027AC90(void *);
extern char D_0035CC10[];
void func_00121668(void);
extern char D_0035CC28[];
void func_00117168(void);
extern char D_0035CC40[];
void func_001C5730(void);
extern char D_0035CC58[];
void func_002750F0(void);
void func_00119400(int, void *);
void *func_00118F20(int, int, int, int);
int func_00297458(void *);
extern int D_00368A38;
int func_0011EF10(void);
int func_002763E0(int, int);
void func_0027ABB0(int, int);
void func_0029ABB8(void *, int);
extern char D_0035C858[];
void func_0027AA70(void *);
extern char D_0035C830[];
int func_0011A128(void);
int func_0027D400(int, int, int, int);
int func_0029AFF0(void);
void func_0029F9F8(int, int);
}

INCLUDE_ASM("asm/nonmatchings/game/t_29F288", func_0029F288);

INCLUDE_ASM("asm/nonmatchings/game/t_29F288", func_0029F4F8);

struct S29F500 {
    char pad0[0x3150];
    u32 unk3150;
};
extern "C" void func_0029F500(S29F500 *p, int n) {
    u32 t = func_0011EF10() + n;
    if (p->unk3150 < t) {
        p->unk3150 = t;
    }
}

INCLUDE_ASM("asm/nonmatchings/game/t_29F288", func_0029F548);

struct S29F550 {
    char pad0[0x3144];
    int unk3144;
};
extern "C" void func_0029F550(S29F550 *p) {
    volatile int v = 4;
    p->unk3144 = (p->unk3144 & ~1) | 4;
}

INCLUDE_ASM("asm/nonmatchings/game/t_29F288", func_0029F578);

extern "C" s32 func_0029F598(S29F598_0 *arg0) {
    s32 x = arg0->unk3148 & 4;
    return x != 0;
}

extern "C" s32 func_0029F5A8(S29F598_0 *arg0) {
    return arg0->unk3148 & 1;
}

extern "C" s32 func_0029F5B8(S29F598_0 *arg0) {
    s32 x = arg0->unk3148 & 2;
    return x != 0;
}

INCLUDE_ASM("asm/nonmatchings/game/t_29F288", func_0029F5C8);

extern "C" void func_0029F628(S29F628_0 *arg0, s32 arg1) {
    arg0->unk3158 = arg1;
}

extern "C" s32 func_0029F630(S29F628_0 *arg0) {
    return arg0->unk3158;
}

extern "C" void func_0029F638(S29F638_0 *arg0, s32 arg1) {
    arg0->unk30AC = arg1;
}

extern "C" s32 func_0029F640(S29F638_0 *arg0) {
    return arg0->unk30AC;
}

INCLUDE_ASM("asm/nonmatchings/game/t_29F288", func_0029F648);

INCLUDE_ASM("asm/nonmatchings/game/t_29F288", func_0029F790);

INCLUDE_ASM("asm/nonmatchings/game/t_29F288", func_0029F840);

extern "C" s32 func_0029F970(S29F970_0 *arg0) {
    return arg0->unk30CC;
}

extern "C" void func_0029F978(S29F970_0 *arg0, s32 arg1) {
    arg0->unk30CC = arg1;
    switch (arg1) {                                 /* irregular */
    case 1:
        func_0029F9F8((s32) arg0, 0x1068);
        return;
    case 0:
        func_0029F9F8((s32) arg0, 0x61A80);
        break;
    case 2:
        func_0029F9F8((s32) arg0, 0xC3500);
        break;
    }
}

extern "C" void func_0029F9F8(int p, int v) {
    ((S29F288_A *)p)->unk30D8 = v;
}

extern "C" s32 func_0029FA00(S29FA00_0 *arg0) {
    return arg0->unk30D8;
}

INCLUDE_ASM("asm/nonmatchings/game/t_29F288", func_0029FA08);

INCLUDE_ASM("asm/nonmatchings/game/t_29F288", func_0029FB40);

INCLUDE_ASM("asm/nonmatchings/game/t_29F288", func_0029FBA8);

INCLUDE_ASM("asm/nonmatchings/game/t_29F288", func_0029FC10);

INCLUDE_ASM("asm/nonmatchings/game/t_29F288", func_0029FC80);

INCLUDE_ASM("asm/nonmatchings/game/t_29F288", func_0029FCE8);

struct S29FD08 {
    char pad0[4];
    char unk4[8];
    void *unkC;
};
extern "C" S29FD08 *func_0029FD08(S29FD08 *p) {
    p->unkC = D_0035C830;
    func_0027AA70(p->unk4);
    return p;
}

extern "C" void func_0029FD40(S29FD08 *p, int b) {
    p->unkC = D_0035C830;
    func_0027AC90(p->unk4);
    if (b & 1) {
        func_00119400(D_00368A38, p);
    }
}

INCLUDE_ASM("asm/nonmatchings/game/t_29F288", func_0029FD98);

extern "C" s32 func_0029FDA8(s32 arg0, s32 arg1) {
    s32 sp0;

    sp0 = 0;
    func_0027D400(arg0 + 4, arg1, (s32) &sp0, 0);
    return sp0;
}

INCLUDE_ASM("asm/nonmatchings/game/t_29F288", func_0029FDD8);

extern "C" int func_0029FE00(int a, int b, int c) {
    int out = 0;
    if ((func_0027D400(a + 4, b, (int)&out, 0) ^ 1) != 0) {
        return 0;
    }
    if (c != 0) {
        func_0027ABB0(out, c);
    }
    return 1;
}

INCLUDE_ASM("asm/nonmatchings/game/t_29F288", func_0029FE58);

extern "C" int func_0029FE60(int a, int b) {
    int r = func_002763E0(b, 1);
    if (r != 0) {
        func_0027ABB0(a + 4, r);
    }
    return 1;
}

INCLUDE_ASM("asm/nonmatchings/game/t_29F288", func_0029FEA0);

struct S29FEA8 {
    char pad0[0x20];
    int unk20;
};
extern "C" int func_0029FEA8(S29FEA8 *p) {
    p->unk20 = func_00297458(func_00118F20(D_00368A38, 0x98, 1, 0));
    return 1;
}

extern "C" s32 func_0029FEF0(void) {
    return 1;
}

extern "C" s32 func_0029FEF8(void) {
    return 0;
}

extern "C" s32 func_0029FF00(void) {
    return 1;
}

extern "C" s32 func_0029FF08(void) {
    return 0;
}

extern "C" s32 func_0029FF10(void) {
    return 0;
}

extern "C" s32 func_0029FF18(void) {
    return 0;
}

struct S29FF20 {
    char pad0[0x2418];
    void *unk2418;
};
extern "C" S29FF20 *func_0029FF20(S29FF20 *p) {
    func_0029ABB8(p, 0);
    p->unk2418 = D_0035C858;
    return p;
}

extern "C" s32 func_0029FF58(void) {
    return 0;
}

extern "C" void func_0029FF60(void) {
}

extern "C" void func_0029FF68(void) {
}

extern "C" void func_0029FF70(void) {
}

extern "C" s32 func_0029FF78(void) {
    return 0;
}

extern "C" s32 func_0029FF80(void) {
    return 1;
}

extern "C" void func_0029FF88(void) {
}

extern "C" void func_0029FF90(void) {
}

extern "C" void func_0029FF98(void) {
}

extern "C" void func_0029FFA0(void) {
}

extern "C" void func_0029FFA8(void) {
}

extern "C" s32 func_0029FFB0(void) {
    return 0;
}

INCLUDE_ASM("asm/nonmatchings/game/t_29F288", func_0029FFB8);

extern "C" void func_002A0000(void) {
    func_0029AFF0();
}

INCLUDE_ASM("asm/nonmatchings/game/t_29F288", func_002A0020);

extern "C" void func_002A0098(void) {
    func_0011A128();
}

INCLUDE_ASM("asm/nonmatchings/game/t_29F288", func_002A00B8);

INCLUDE_ASM("asm/nonmatchings/game/t_29F288", func_002A1078);

INCLUDE_ASM("asm/nonmatchings/game/t_29F288", func_002A1110);

struct Sfunc_002A1170 {
    char pad0[0xC];
    void *unkC;
};
extern "C" void func_002A1170(Sfunc_002A1170 *p, int b) {
    p->unkC = D_0035CC58;
    func_002750F0();
    if (b & 1) {
        func_00119400(D_00368A38, p);
    }
}

struct Sfunc_002A11C0 {
    char pad0[0xC];
    void *unkC;
};
extern "C" void func_002A11C0(Sfunc_002A11C0 *p, int b) {
    p->unkC = D_0035CC40;
    func_001C5730();
    if (b & 1) {
        func_00119400(D_00368A38, p);
    }
}

struct Sfunc_002A1210 {
    char pad0[0xC];
    void *unkC;
};
extern "C" void func_002A1210(Sfunc_002A1210 *p, int b) {
    p->unkC = D_0035CC28;
    func_00117168();
    if (b & 1) {
        func_00119400(D_00368A38, p);
    }
}

struct Sfunc_002A1260 {
    char pad0[0xC];
    void *unkC;
};
extern "C" void func_002A1260(Sfunc_002A1260 *p, int b) {
    p->unkC = D_0035CC10;
    func_00121668();
    if (b & 1) {
        func_00119400(D_00368A38, p);
    }
}
