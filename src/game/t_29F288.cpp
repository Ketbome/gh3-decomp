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

INCLUDE_ASM("asm/nonmatchings/game/t_29F288", func_0029F500);

INCLUDE_ASM("asm/nonmatchings/game/t_29F288", func_0029F548);

INCLUDE_ASM("asm/nonmatchings/game/t_29F288", func_0029F550);

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

INCLUDE_ASM("asm/nonmatchings/game/t_29F288", func_0029FD40);

INCLUDE_ASM("asm/nonmatchings/game/t_29F288", func_0029FD98);

extern "C" s32 func_0029FDA8(s32 arg0, s32 arg1) {
    s32 sp0;

    sp0 = 0;
    func_0027D400(arg0 + 4, arg1, (s32) &sp0, 0);
    return sp0;
}

INCLUDE_ASM("asm/nonmatchings/game/t_29F288", func_0029FDD8);

INCLUDE_ASM("asm/nonmatchings/game/t_29F288", func_0029FE00);

INCLUDE_ASM("asm/nonmatchings/game/t_29F288", func_0029FE58);

INCLUDE_ASM("asm/nonmatchings/game/t_29F288", func_0029FE60);

INCLUDE_ASM("asm/nonmatchings/game/t_29F288", func_0029FEA0);

INCLUDE_ASM("asm/nonmatchings/game/t_29F288", func_0029FEA8);

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

INCLUDE_ASM("asm/nonmatchings/game/t_29F288", func_002A1170);

INCLUDE_ASM("asm/nonmatchings/game/t_29F288", func_002A11C0);

INCLUDE_ASM("asm/nonmatchings/game/t_29F288", func_002A1210);

INCLUDE_ASM("asm/nonmatchings/game/t_29F288", func_002A1260);
