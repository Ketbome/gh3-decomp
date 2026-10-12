#include "common.h"

typedef unsigned int u128_181 __attribute__((mode(TI)));
struct M2_181 { u128_181 a; u128_181 b; };
struct VE_181 { s16 delta; s16 unk2; void* fn; };
struct V_181 { VE_181* vt; };
struct S_001821E0 { char pad0[0x414]; VE_181* unk414; };
struct S_00182180 { char pad0[0x18]; VE_181* unk18; };
struct S_001822A8 { char pad0[0xBC]; VE_181* unkBC; };
struct S_00182338 { char pad0[0x10]; VE_181* unk10; };
struct S_001823A8 { char pad0[0x1C]; VE_181* unk1C; };

extern "C" {
extern int D_00368A38[] __attribute__((section(".sdata")));
void* func_00118F20(int, int, int, int);
void* func_00188D00(void*, int);
extern int D_0036CA4C[] __attribute__((section(".sdata")));
void func_0019ED90(void);
void func_001A8758(char*, char*, char*, char*, int);
extern int D_0036876C[] __attribute__((section(".sdata")));
void func_001A8120(int);
void func_001818F8(M2_181*, u128_181*, u128_181*);
extern int D_0036CA40;
extern u8 D_0036B460[];
extern u8 D_0037DBD0[];
void func_0019EC10(void);
void func_001A8810(void);
void func_001A88E8(void);
void func_001B9C60(void);
void func_0019ECE8(void);
void func_001C3DF0(void);
void func_001B4A88(void);
void func_001B4A90(void);
int func_00182870(int, int);
int func_0016E728(int);
}

INCLUDE_ASM("asm/nonmatchings/game/t_1816C0", func_001816C0);

INCLUDE_ASM("asm/nonmatchings/game/t_1816C0", func_001817F8);

extern "C" void func_001818F8(M2_181* d, u128_181* a, u128_181* b) {
    d->a = *a;
    d->b = *b;
}

extern "C" M2_181* func_00181910(M2_181* d, u128_181* a, u128_181* b) {
    func_001818F8(d, a, b);
    return d;
}

INCLUDE_ASM("asm/nonmatchings/game/t_1816C0", func_00181938);

INCLUDE_ASM("asm/nonmatchings/game/t_1816C0", func_00181BB0);

INCLUDE_ASM("asm/nonmatchings/game/t_1816C0", func_00181BD8);

extern "C" void func_00181C38(void) {
    func_0019EC10();
}

extern "C" void func_00181C58(void) {
    if (D_0036CA4C[0]) func_0019ED90();
}

INCLUDE_ASM("asm/nonmatchings/game/t_1816C0", func_00181C80);

INCLUDE_ASM("asm/nonmatchings/game/t_1816C0", func_00181ED8);

INCLUDE_ASM("asm/nonmatchings/game/t_1816C0", func_00181EE0);

INCLUDE_ASM("asm/nonmatchings/game/t_1816C0", func_00182020);

INCLUDE_ASM("asm/nonmatchings/game/t_1816C0", func_00182078);

INCLUDE_ASM("asm/nonmatchings/game/t_1816C0", func_001820D0);

INCLUDE_ASM("asm/nonmatchings/game/t_1816C0", func_00182110);

extern "C" int func_00182180(S_00182180* p) {
    if (p) {
        VE_181* e = &p->unk18[1];
        ((void (*)(void*, int))e->fn)((char*)p + e->delta, 3);
    }
    return 1;
}

extern "C" int func_001821B8(void) {
    int r0 = func_00182870(1048, 1);
    return func_0016E728(r0);
}

extern "C" void func_001821E0(S_001821E0* p) {
    if (p) {
        VE_181* e = &p->unk414[1];
        ((void (*)(void*, int))e->fn)((char*)p + e->delta, 3);
    }
}

INCLUDE_ASM("asm/nonmatchings/game/t_1816C0", func_00182218);

INCLUDE_ASM("asm/nonmatchings/game/t_1816C0", func_00182220);

extern "C" int func_001822A8(S_001822A8* p) {
    if (p) {
        VE_181* e = &p->unkBC[1];
        ((void (*)(void*, int))e->fn)((char*)p + e->delta, 3);
    }
    return 1;
}

extern "C" void func_001822E0(void) {
}

INCLUDE_ASM("asm/nonmatchings/game/t_1816C0", func_001822E8);

INCLUDE_ASM("asm/nonmatchings/game/t_1816C0", func_001822F0);

extern "C" int func_00182338(S_00182338* p) {
    if (p) {
        VE_181* e = &p->unk10[1];
        ((void (*)(void*, int))e->fn)((char*)p + e->delta, 3);
    }
    return 1;
}

extern "C" void* func_00182370(void) {
    return func_00188D00(func_00118F20(D_00368A38[0], 0x24, 1, 0), 0);
}

extern "C" int func_001823A8(S_001823A8* p) {
    if (p) {
        VE_181* e = &p->unk1C[1];
        ((void (*)(void*, int))e->fn)((char*)p + e->delta, 3);
    }
    return 1;
}

INCLUDE_ASM("asm/nonmatchings/game/t_1816C0", func_001823E0);

extern "C" void func_001823F0(int n, char* m, int c) {
    if (n == 4) func_001A8758(m, m + 0x10, m + 0x20, m + 0x30, c);
}

extern "C" void func_00182428(void) {
    func_001A8810();
}

extern "C" void func_00182448(void) {
    func_001A88E8();
}

extern "C" void func_00182468(void) {
    func_001B9C60();
}

extern "C" void* func_00182488(void) {
    return D_0036B460;
}

extern "C" void func_00182498(void) {
    func_0019ECE8();
}

extern "C" u8 func_001824B8(u32 v) {
    return (v >> 4) * 10 + (v & 0xF);
}

INCLUDE_ASM("asm/nonmatchings/game/t_1816C0", func_001824D8);

INCLUDE_ASM("asm/nonmatchings/game/t_1816C0", func_001825E0);

extern "C" void func_00182798(int v) {
    D_0036CA40 = v;
}

extern "C" int func_001827A0(void) {
    return 640;
}

extern "C" int func_001827A8(void) {
    return 448;
}

extern "C" void func_001827B0(void) {
    func_001C3DF0();
}

extern "C" void func_001827D0(void) {
    func_001B4A88();
}

extern "C" void func_001827F0(void) {
    func_001B4A90();
}

INCLUDE_ASM("asm/nonmatchings/game/t_1816C0", func_00182810);

extern "C" int func_00182818(void) {
    return 640;
}

extern "C" int func_00182820(void) {
    return 448;
}

INCLUDE_ASM("asm/nonmatchings/game/t_1816C0", func_00182828);

INCLUDE_ASM("asm/nonmatchings/game/t_1816C0", func_00182868);

INCLUDE_ASM("asm/nonmatchings/game/t_1816C0", func_00182870);

extern "C" void* func_00182930(void) {
    return D_0037DBD0;
}

INCLUDE_ASM("asm/nonmatchings/game/t_1816C0", func_00182940);

INCLUDE_ASM("asm/nonmatchings/game/t_1816C0", func_00182DA8);

INCLUDE_ASM("asm/nonmatchings/game/t_1816C0", func_00182DB0);

INCLUDE_ASM("asm/nonmatchings/game/t_1816C0", func_00182E50);

extern "C" void func_00183460(float x) {
    func_001A8120((int)(x * (float)D_0036876C[0]));
}

INCLUDE_ASM("asm/nonmatchings/game/t_1816C0", func_00183498);

INCLUDE_ASM("asm/nonmatchings/game/t_1816C0", func_001834E0);

INCLUDE_ASM("asm/nonmatchings/game/t_1816C0", func_00183520);

INCLUDE_ASM("asm/nonmatchings/game/t_1816C0", func_00183678);
