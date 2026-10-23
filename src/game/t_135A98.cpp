#include "common.h"

struct S135_A { char pad0[0x4]; u32 unk4; };

struct S135_G { char pad0[0x4]; int unk4; };

struct S_00135DD0 { char pad0[0x6C]; char unk6C; };

extern "C" {
int func_001349D0_1(S_00135DD0*) __asm__("func_001349D0");
extern int D_00368A38;
void* Heap_Alloc(int, int, int, int);
void Heap_Free(int, void*);
int func_0027D4E0(int, int, void*, int);
int func_0012D028(int, int);
int func_002899D8(int);
void func_0028A140(int, void*, int, S_00135DD0*);
int func_0028C200(int);
void func_00289B40(int, int);
int func_0027D870(void*, u32, int*, int);
int func_0027D870_i(int, int, int*, int) __asm__("func_0027D870");
int func_0027D188(int, int, int*, int);
int func_0027D400(char*, u32, int*, int);
extern int D_00369424;
int func_00132070(int, int);
extern int D_00372AF8;
extern int D_00372B00;
extern int D_00372B08;
extern int D_00372B10;
extern S135_G* D_0036942C;
int func_001349D0(S_00135DD0*, void*);
int func_0027D470(int, u32, S135_A**, int);
int func_0027EF20(S135_A*, u32);
void func_00123AB0(S135_G*, int);
extern S_00135DD0* D_00369428;
extern int D_00369420;
void func_0027ACF8(char*);
void func_00161AC8(int);
void func_00160730(int);
void func_00161138(int);
void func_00161960(int);
}

INCLUDE_ASM("asm/nonmatchings/game/t_135A98", func_00135A98);

INCLUDE_ASM("asm/nonmatchings/game/t_135A98", func_00135D20);

GP_DATA(D_00369428);
extern "C" int func_00135DD0(void) {
    func_0027ACF8(&D_00369428->unk6C);
    return 1;
}

GP_DATA(D_00369420);
extern "C" int func_00135DF8(void) {
    func_00161AC8(D_00369420);
    return 1;
}

INCLUDE_ASM("asm/nonmatchings/game/t_135A98", func_00135E20);

INCLUDE_ASM("asm/nonmatchings/game/t_135A98", func_00135ED8);

extern "C" int func_00135F28(void) {
    int v = 0;
    if (func_0027D400(&D_00369428->unk6C, 0x812684EF, &v, 0)) {
        return func_00132070(D_00369424, v);
    }
    return 0;
}

INCLUDE_ASM("asm/nonmatchings/game/t_135A98", func_00135F78);

typedef unsigned int u128_135 __attribute__((mode(TI)));

static inline u128_135 MakeVec135(f32 x, f32 y, f32 z, int w) {
    u128_135 lo, hi;
    asm("pextlw %0, %1, %2" : "=r"(hi) : "r"(w), "r"(z));
    asm("pextlw %0, %1, %2" : "=&r"(lo) : "r"(y), "r"(x));
    asm("pcpyld %0, %1, %2" : "=r"(lo) : "r"(hi), "0"(lo));
    return lo;
}

extern "C" {
int func_0014DC60(float*, int);
int func_00134A20_h(int, int) __asm__("func_00134A20");
int func_0027DD88_h(int, u32) __asm__("func_0027DD88");
int func_0027D1F8_h(int, u32, int*, int) __asm__("func_0027D1F8");
void func_00161F48(int, void*);
}

extern "C" int func_00136318(void) {
    u128_135 v = MakeVec135(1.0f, 1.0f, 1.0f, 0x3F800000);
    int sp10;
    int sp14, sp18, sp1C, sp20;
    if (func_0014DC60((float*)&v, (int)&D_00369428->unk6C) != 0 ||
        (sp10 = 0, func_0027D400(&D_00369428->unk6C, 0x812684EF, &sp10, 0)) && func_0014DC60((float*)&v, sp10)) {
        func_00161F48(D_00369420, &v);
        return 1;
    }
    int o = func_00134A20_h((int)D_00369428, 0x8B314358);
    if (o) {
        if (func_0027DD88_h(o, 0x5A96985D)) {
            func_0027D1F8_h(o, 0x5A96985D, &sp14, 0);
            if (sp14 == 0) {
                int ok = 0;
                if (func_0027D1F8_h(o, 0x7323E97C, &sp18, 0) && func_0027D1F8_h(o, 0x0424D9EA, &sp1C, 0)) {
                    ok = func_0027D1F8_h(o, 0x9D2D8850, &sp20, 0) != 0;
                }
                if (ok) {
                    u128_135 wv;
                    float* w = (float*)&wv;
                    w[0] = (float)sp18 * 0.01f;
                    w[1] = (float)sp1C * 0.01f;
                    w[2] = (float)sp20 * 0.01f;
                    w[3] = 1.0f;
                    func_00161F48(D_00369420, &wv);
                }
                return 1;
            }
        }
    }
    return 0;
}

extern "C" int func_001364C8(void) {
    func_00160730(D_00369420);
    return 1;
}

extern "C" {
int func_00134A20_g(int, int) __asm__("func_00134A20");
int func_001349D0_g(int, int) __asm__("func_001349D0");
int func_0027DD88_g(int, u32) __asm__("func_0027DD88");
int func_0027D1F8_g(int, u32, int*, int) __asm__("func_0027D1F8");
void func_001611C0_g(int, int, float, float, float) __asm__("func_001611C0");
void func_00161580_g(int, int) __asm__("func_00161580");
}

extern "C" int func_001364F0(int self, int params) {
    int a;
    func_0027D870_i(params, 0xB6F08F39, &a, 1);
    int o = func_00134A20_g((int)D_00369428, a);
    if (o != 0) {
        int b = 0;
        func_0027D870_i(o, 0x4BB2084E, &b, 0);
        int isb = 0;
        if (b == 0x64E9DAEF || b == 0x92986E0D) {
            isb = 1;
        }
        if (isb != 0) {
            return 0;
        }
        int c = 0;
        if (func_0027DD88_g(o, 0x97DBDDE6) == 0) {
            c = 1;
        } else {
            func_0027D1F8_g(o, 0x97DBDDE6, &c, 0);
        }
        if (c != 0) {
            int found = 0;
            int o2 = func_001349D0_g((int)D_00369428, a);
            int d, e, f;
            if (o2 != 0 && func_0027D1F8_g(o2, 0xC6CC7F7F, &d, 0) != 0 && func_0027D1F8_g(o2, 0x4CA9B693, &e, 0) != 0) {
                found = func_0027D1F8_g(o2, 0x3CC3421C, &f, 0) != 0;
            }
            if (found != 0) {
                float fe = (float)e * 0.01f;
                float fd = (float)d;
                float ff = (float)f * 0.01f;
                func_001611C0_g(D_00369420, params, fd, fe, ff);
                return 0;
            }
            func_00161580_g(D_00369420, params);
            return 0;
        }
        int found = 0;
        int g, h, i;
        if (func_0027D1F8_g(o, 0x6E94F918, &g, 0) != 0 && func_0027D1F8_g(o, 0xE4F130F4, &h, 0) != 0) {
            found = func_0027D1F8_g(o, 0x949BC47B, &i, 0) != 0;
        }
        if (found != 0) {
            func_001611C0_g(D_00369420, params, (float)g, (float)h * 0.01f, (float)i * 0.01f);
        }
    }
    return 1;
}

extern "C" int func_00136740(void) {
    func_00161138(D_00369420);
    return 1;
}

INCLUDE_ASM("asm/nonmatchings/game/t_135A98", func_00136768);

INCLUDE_ASM("asm/nonmatchings/game/t_135A98", func_00136A28);

struct VE_00136C48 { char pad0[0x68]; s16 unk68; s16 unk6A; int (*unk6C)(void*, int, int, int); };
struct S_00136C48 { char pad0[8]; VE_00136C48* unk8; };

INCLUDE_ASM("asm/nonmatchings/game/t_135A98", func_00136C48);

INCLUDE_ASM("asm/nonmatchings/game/t_135A98", func_00136D40);

INCLUDE_ASM("asm/nonmatchings/game/t_135A98", func_00137070);

extern "C" int func_00137448(void) {
    func_00161960(D_00369420);
    return 1;
}

extern "C" int func_00137470(int a, int b, int c) {
    int o = func_001349D0_1(D_00369428);
    if (o) {
        int* blk = (int*)Heap_Alloc(D_00368A38, 8, 1, 0);
        blk[0] = 0;
        blk[1] = 0;
        if (func_0027D4E0(o, c, blk, 0)) {
            int t = func_002899D8(func_0012D028(0x10C, 1));
            func_0028A140(t, blk, 0, D_00369428);
            while (func_0028C200(t)) {
            }
            if (t) func_00289B40(t, 3);
        }
        Heap_Free(D_00368A38, blk);
    }
    return 1;
}

INCLUDE_ASM("asm/nonmatchings/game/t_135A98", func_00137558);

GP_DATA(D_00372AF8);
GP_DATA(D_00372B00);
GP_DATA(D_00372B08);
GP_DATA(D_00372B10);
extern "C" void func_00137618(int a, int b) {
    if (b == 0xFFFF && a) {
        D_00372AF8 = 0x91C1EC93;
        D_00372B00 = 0xD2C041C2;
        D_00372B08 = 0xAEE1AF7D;
        D_00372B10 = 0xB1A55798;
    }
}

INCLUDE_ASM("asm/nonmatchings/game/t_135A98", func_00137668);

INCLUDE_ASM("asm/nonmatchings/game/t_135A98", func_00137690);

extern "C" int func_001376B8(void* params) {
    int v;
    func_0027D870(params, 0x4BB2084E, &v, 1);
    return v;
}

INCLUDE_ASM("asm/nonmatchings/game/t_135A98", func_001376E8);

INCLUDE_ASM("asm/nonmatchings/game/t_135A98", func_001377B8);

INCLUDE_ASM("asm/nonmatchings/game/t_135A98", func_001377C8);
