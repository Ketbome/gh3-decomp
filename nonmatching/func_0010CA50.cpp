#include "common.h"

struct SA10C {
    int unk0;
    int unk4;
    int unk8;
    int unkC;
};

struct M10C { float m[16]; };

extern "C" {
float func_002EC100();
float func_002EC124();
extern int D_00372A80;
extern int D_00372A84;
extern int D_00372A88;
extern int D_00372A8C;
extern int D_00372A90;
extern int D_00372A94;
}

INCLUDE_ASM("asm/nonmatchings/game/t_10C000", func_0010C000);

extern "C" int func_0010C050(int n) {
    int a = D_00372A80 * D_00372A84 + D_00372A88;
    D_00372A84 = (D_00372A84 ^ a) + (a >> 4);
    D_00372A88 += (a >> 3) - 0x10101010;
    D_00372A80 = a;
    return ((a & 0xFFFF) * n) >> 16;
}

extern "C" int func_0010C0B8(int n) {
    int a = D_00372A8C * D_00372A90 + D_00372A94;
    D_00372A90 = (D_00372A90 ^ a) + (a >> 4);
    D_00372A94 += (a >> 3) - 0x10101010;
    D_00372A8C = a;
    return ((a & 0xFFFF) * n) >> 16;
}

extern "C" void func_0010C120(int* a, int* b, int* c, int* d, int* e, int* g) {
    if (a) *a = D_00372A80;
    if (b) *b = D_00372A84;
    if (c) *c = D_00372A88;
    if (d) *d = D_00372A8C;
    if (e) *e = D_00372A90;
    if (g) *g = D_00372A94;
}

extern "C" void func_0010C170(int a, int b, int c, int d, int e, int f) {
    D_00372A80 = a;
    D_00372A84 = b;
    D_00372A88 = c;
    D_00372A8C = d;
    D_00372A90 = e;
    D_00372A94 = f;
}

INCLUDE_ASM("asm/nonmatchings/game/t_10C000", func_0010C1A0);

extern "C" float func_0010C2E0(float a, float b, float c) {
    c = __builtin_fabsf(c);
    if (a < b) {
        if (b - a > c) {
            return b - c;
        }
        return a;
    } else {
        if (a - b > c) {
            return b + c;
        }
        return a;
    }
}

INCLUDE_ASM("asm/nonmatchings/game/t_10C000", func_0010C330);

INCLUDE_ASM("asm/nonmatchings/game/t_10C000", func_0010C428);

extern "C" {
float func_002EC10C_v(void) __asm__("func_002EC10C");
float func_002EC118_v(float) __asm__("func_002EC118");
}

extern "C" float* func_0010CA50(float* m, float a, float b, float c) {
    float f23 = func_002EC118_v(a);
    float f22 = func_002EC10C_v();
    float f24 = func_002EC118_v(b);
    float f21 = func_002EC10C_v();
    float f20 = func_002EC118_v(c);
    float f0 = func_002EC10C_v();
    float f2 = f22 * f21;
    float* p5 = m + 4;
    float f4 = f23 * f21;
    float* p3 = m + 8;
    float* p4 = m + 12;
    float f9 = f22 * f0;
    float f2b = f2 * f0;
    float f1 = (-f2 * f20) + (f23 * f0);
    float f6 = -f24 * f0;
    float f3 = -f4 * f0;
    m[0] = f24 * f20;
    m[4] = f1;
    m[1] = f6;
    m[2] = -f21;
    p5[2] = -f22 * f24;
    p5[1] = f2b + (f23 * f20);
    m[8] = (f4 * f20) + f9;
    p3[1] = f3 + (f22 * f20);
    p3[2] = f23 * f24;
    m[3] = 0;
    p5[3] = 0;
    p3[3] = 0;
    m[12] = 0;
    p4[3] = 1.0f;
    p4[2] = 0;
    p4[1] = 0;
    return m;
}

INCLUDE_ASM("asm/nonmatchings/game/t_10C000", func_0010CB90);

extern "C" M10C* func_0010CBA0(M10C* self) {
    float s = func_002EC100();
    float c = func_002EC124();
    float* r1 = self->m + 4;
    float* r2 = self->m + 8;
    float* r3 = self->m + 12;
    self->m[1] = 0;
    self->m[0] = 1.0f;
    self->m[2] = 0;
    self->m[3] = 0;
    self->m[4] = 0;
    r1[2] = s;
    r1[1] = c;
    r1[3] = 0;
    self->m[8] = 0;
    r2[1] = -s;
    r2[2] = c;
    r2[3] = 0;
    self->m[12] = 0;
    r3[3] = 1.0f;
    r3[2] = 0;
    r3[1] = 0;
    return self;
}

extern "C" M10C* func_0010CC30(M10C* self) {
    float s = func_002EC100();
    float c = func_002EC124();
    float* r1 = self->m + 4;
    float* r2 = self->m + 8;
    float* r3 = self->m + 12;
    self->m[0] = c;
    self->m[1] = 0;
    self->m[2] = -s;
    self->m[3] = 0;
    self->m[4] = 0;
    r1[1] = 1.0f;
    r1[2] = 0;
    r1[3] = 0;
    self->m[8] = s;
    r2[2] = c;
    r2[1] = 0;
    r2[3] = 0;
    self->m[12] = 0;
    r3[3] = 1.0f;
    r3[2] = 0;
    r3[1] = 0;
    return self;
}

extern "C" M10C* func_0010CCC0(M10C* self) {
    float s = func_002EC100();
    float c = func_002EC124();
    float* r1 = self->m + 4;
    float* r2 = self->m + 8;
    float* r3 = self->m + 12;
    self->m[0] = c;
    self->m[1] = s;
    self->m[2] = 0;
    self->m[4] = -s;
    self->m[3] = 0;
    r1[1] = c;
    r1[2] = 0;
    r1[3] = 0;
    self->m[8] = 0;
    r2[1] = 0;
    r2[2] = 1.0f;
    r2[3] = 0;
    self->m[12] = 0;
    r3[3] = 1.0f;
    r3[2] = 0;
    r3[1] = 0;
    return self;
}

INCLUDE_ASM("asm/nonmatchings/game/t_10C000", func_0010CD50);

INCLUDE_ASM("asm/nonmatchings/game/t_10C000", func_0010CEE8);

INCLUDE_ASM("asm/nonmatchings/game/t_10C000", func_0010D1E8);

extern "C" SA10C* func_0010D420(SA10C* self, int a, int b, int c, int d) {
    self->unk0 = a;
    self->unk4 = b;
    self->unk8 = c;
    self->unkC = d;
    return self;
}

INCLUDE_ASM("asm/nonmatchings/game/t_10C000", func_0010D438);

INCLUDE_ASM("asm/nonmatchings/game/t_10C000", func_0010D508);

INCLUDE_ASM("asm/nonmatchings/game/t_10C000", func_0010D538);

INCLUDE_ASM("asm/nonmatchings/game/t_10C000", func_0010D548);

INCLUDE_ASM("asm/nonmatchings/game/t_10C000", func_0010D5C8);

INCLUDE_ASM("asm/nonmatchings/game/t_10C000", func_0010D768);

INCLUDE_ASM("asm/nonmatchings/game/t_10C000", func_0010D808);
