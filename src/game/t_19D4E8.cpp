#include "common.h"

struct S_0019F318 { char pad0[0xC]; int unkC; };

struct U64P_19D { u64 v; } __attribute__((packed));

extern "C" {
extern int D_0036C420;
extern U64P_19D* D_00373270;
extern int* D_003732E0;
extern char* D_00373280;
extern int D_00373284;
extern int D_0036C384;
int func_0019ED80(void);
void func_0019EC80(void);
void func_001BB100(void);
extern int D_003732E8;
}

INCLUDE_ASM("asm/nonmatchings/game/t_19D4E8", func_0019D4E8);

INCLUDE_ASM("asm/nonmatchings/game/t_19D4E8", func_0019D9B0);

INCLUDE_ASM("asm/nonmatchings/game/t_19D4E8", func_0019DC48);

INCLUDE_ASM("asm/nonmatchings/game/t_19D4E8", func_0019E020);

extern "C" void func_0019E090(int a, int b, int c, int d, int f) {
    int* p = (int*)D_00373270;
    D_003732E0 = p;
    p[1] = (b << 28) | (c << 26) | (d << 15) | (f << 14);
    p[2] = a;
    p[0] = 0;
    p[3] = 0;
    D_00373270 = (U64P_19D*)(p + 4);
}

INCLUDE_ASM("asm/nonmatchings/game/t_19D4E8", func_0019E0D8);

extern "C" void func_0019E178(void) {
    int* p = (int*)D_00373270;
    D_003732E0 = p;
    p[1] = 0x10000000;
    p[2] = 0xE;
    p[0] = 0;
    p[3] = 0;
    D_00373270 = (U64P_19D*)(p + 4);
}

extern "C" void func_0019E1B0(int n) {
    int* e = D_003732E0;
    *e = *e | ((n << 15) | (((char*)D_00373270 - (char*)e - 16) >> 4));
}

INCLUDE_ASM("asm/nonmatchings/game/t_19D4E8", func_0019E1E8);

INCLUDE_ASM("asm/nonmatchings/game/t_19D4E8", func_0019E2B8);

INCLUDE_ASM("asm/nonmatchings/game/t_19D4E8", func_0019E318);

INCLUDE_ASM("asm/nonmatchings/game/t_19D4E8", func_0019E340);

INCLUDE_ASM("asm/nonmatchings/game/t_19D4E8", func_0019E380);

INCLUDE_ASM("asm/nonmatchings/game/t_19D4E8", func_0019E440);

INCLUDE_ASM("asm/nonmatchings/game/t_19D4E8", func_0019E670);

INCLUDE_ASM("asm/nonmatchings/game/t_19D4E8", func_0019E978);

INCLUDE_ASM("asm/nonmatchings/game/t_19D4E8", func_0019EAA0);

extern "C" void func_0019EB10(int n) {
    U64P_19D* p = D_00373270;
    char* base = D_00373280;
    int* e = D_003732E0;
    int q = ((char*)p - base - 4) >> 4;
    int v = (n << 15) | (q - 1) | e[0];
    base[2] = q;
    e[3] = q - 1;
    e[0] = v;
    D_00373284 += q;
}

INCLUDE_ASM("asm/nonmatchings/game/t_19D4E8", func_0019EB68);

INCLUDE_ASM("asm/nonmatchings/game/t_19D4E8", func_0019EB70);

INCLUDE_ASM("asm/nonmatchings/game/t_19D4E8", func_0019EC08);

INCLUDE_ASM("asm/nonmatchings/game/t_19D4E8", func_0019EC10);

extern "C" void func_0019EC80(void) {
}

GP_DATA(D_0036C384);
extern "C" int func_0019EC88(void) {
    if (func_0019ED80()) {
        if (++D_0036C384 > 0x300001) {
            func_0019EC80();
            D_0036C384 = 0;
        }
        return 0;
    }
    func_001BB100();
    D_0036C384 = 0;
    return 1;
}

INCLUDE_ASM("asm/nonmatchings/game/t_19D4E8", func_0019ECE8);

INCLUDE_ASM("asm/nonmatchings/game/t_19D4E8", func_0019ED10);

extern "C" int func_0019ED80(void) {
    return D_003732E8;
}

INCLUDE_ASM("asm/nonmatchings/game/t_19D4E8", func_0019ED88);

INCLUDE_ASM("asm/nonmatchings/game/t_19D4E8", func_0019ED90);

INCLUDE_ASM("asm/nonmatchings/game/t_19D4E8", func_0019EE30);

INCLUDE_ASM("asm/nonmatchings/game/t_19D4E8", func_0019EE38);

GP_DATA(D_0036C420);
extern "C" void func_0019F2F0(S_0019F318* self) {
    if (!(self->unkC & 8)) {
        self->unkC |= 8;
        D_0036C420 = 1;
    }
}

extern "C" void func_0019F318(S_0019F318* self) {
    self->unkC |= 0x10;
}

INCLUDE_ASM("asm/nonmatchings/game/t_19D4E8", func_0019F328);

INCLUDE_ASM("asm/nonmatchings/game/t_19D4E8", func_0019F450);
