#include "common.h"

typedef int TI128 __attribute__((mode(TI)));

extern "C" {
void func_00244C40(void*);
void func_00245220(void*);
void func_00244930(void*);
void func_00246B08(void*);
void func_002456B0(void*);
extern int D_0036FE9C;
void func_0023E678(void);
extern int D_0036FEA0;
void func_0023F310(void*);
extern u8 D_00354E30[];
void func_0023DC88(void*);
extern u8 D_00354D48[];
}

GP_DATA(D_0036FE9C);
extern "C" void func_0023EFF8(void) {
    D_0036FE9C = 1;
    func_0023E678();
    D_0036FE9C = 0;
}

GP_DATA(D_0036FEA0);
extern "C" void func_0023F020(void) {
    D_0036FEA0 = 1;
    func_0023E678();
    D_0036FEA0 = 0;
}

INCLUDE_ASM("asm/nonmatchings/game/t_23EFF8", func_0023F048);

INCLUDE_ASM("asm/nonmatchings/game/t_23EFF8", func_0023F098);

extern "C" void func_0023F0D0(void** p) {
    p[3] = D_00354E30;
    func_0023DC88(p);
}

INCLUDE_ASM("asm/nonmatchings/game/t_23EFF8", func_0023F0F8);

INCLUDE_ASM("asm/nonmatchings/game/t_23EFF8", func_0023F1A0);

extern "C" void func_0023F240(void** p) {
    p[3] = D_00354D48;
    func_0023F0D0(p);
}

extern "C" void func_0023F268(int* p, int v) {
    *p = v;
}

extern "C" void func_0023F270(char* p, TI128* q) {
    *(TI128*)(p + 0x50) = *q;
    func_0023F310(p);
}

extern "C" char* func_0023F298(char* p) {
    return p + 0x50;
}

INCLUDE_ASM("asm/nonmatchings/game/t_23EFF8", func_0023F2A0);

extern "C" char* func_0023F2D8(char* p) {
    return p + 0x20;
}

extern "C" void func_0023F2E0(char* p, TI128* q) {
    *(TI128*)(p + 0x10) = *q;
    func_0023F310(p);
}

extern "C" char* func_0023F308(char* p) {
    return p + 0x10;
}

INCLUDE_ASM("asm/nonmatchings/game/t_23EFF8", func_0023F310);

INCLUDE_ASM("asm/nonmatchings/game/t_23EFF8", func_0023F408);

INCLUDE_ASM("asm/nonmatchings/game/t_23EFF8", func_0023F4F0);

INCLUDE_ASM("asm/nonmatchings/game/t_23EFF8", func_0023F558);

INCLUDE_ASM("asm/nonmatchings/game/t_23EFF8", func_0023F608);

INCLUDE_ASM("asm/nonmatchings/game/t_23EFF8", func_0023F628);

INCLUDE_ASM("asm/nonmatchings/game/t_23EFF8", func_0023F668);

extern "C" int func_0023F6D0(char* p, int a, char* q) {
    *(f32*)(p + 0x14) = *(f32*)(q + 0x3C);
    if (*(u8*)(q + 0xA) != 0) {
        return a;
    }
    *(int*)(p + 0x10) = a;
    return a + *(u16*)(q + 8);
}

INCLUDE_ASM("asm/nonmatchings/game/t_23EFF8", func_0023F700);

INCLUDE_ASM("asm/nonmatchings/game/t_23EFF8", func_0023F738);

INCLUDE_ASM("asm/nonmatchings/game/t_23EFF8", func_0023F770);

extern "C" void func_0023F7D0(void) {
}

INCLUDE_ASM("asm/nonmatchings/game/t_23EFF8", func_0023F7D8);

extern "C" void func_0023F988(void** p) {
    func_00244C40(p[2]);
}

extern "C" void func_0023F9A8(void** p) {
    func_00245220(p[2]);
}

INCLUDE_ASM("asm/nonmatchings/game/t_23EFF8", func_0023F9C8);

INCLUDE_ASM("asm/nonmatchings/game/t_23EFF8", func_0023FAF8);

INCLUDE_ASM("asm/nonmatchings/game/t_23EFF8", func_00240050);

INCLUDE_ASM("asm/nonmatchings/game/t_23EFF8", func_002405D0);

INCLUDE_ASM("asm/nonmatchings/game/t_23EFF8", func_00240A90);

extern "C" void func_00240F18(void** p) {
    func_00244930(p[2]);
}

extern "C" void func_00240F38(void** p) {
    func_00246B08(p[2]);
}

extern "C" void func_00240F58(void** p) {
    func_002456B0(p[2]);
}

INCLUDE_ASM("asm/nonmatchings/game/t_23EFF8", func_00240F78);

INCLUDE_ASM("asm/nonmatchings/game/t_23EFF8", func_00240FD8);
