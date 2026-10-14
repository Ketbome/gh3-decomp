#include "common.h"

extern "C" {
extern void* D_00372C34[] __attribute__((section(".sdata")));
extern void* D_0036CBC0[] __attribute__((section(".sdata")));
void func_001B1EB0(void* p);
void func_001BF408(void* p);
extern s32 D_0036C7E8;
extern s32 D_0036CAC8;
extern s32 D_00372C30;
extern s32 D_0036CACC;
extern s32 D_0036CAD4;
extern char* D_00373270;
extern char* D_0037327C;
void func_0019E048(s32 a, s32 b, s32 c, s32 d, s32 e, s32 f, s32 g);
void func_0019E318(s32 a, s32 b);
}

INCLUDE_ASM("asm/nonmatchings/game/t_1B93E8", func_001B93E8);

INCLUDE_ASM("asm/nonmatchings/game/t_1B93E8", func_001B95F0);

typedef unsigned int u128_1B9 __attribute__((mode(TI)));

struct V4_1B9 {
    f32 f[4];
};

extern "C" {
extern u8 D_0038CA40[];
extern volatile f32 D_00372D18;
extern volatile f32 D_00372D1C;
extern volatile f32 D_00372CEC;
extern volatile f32 D_00372CF4;
extern volatile f32 D_00372CE8;
extern volatile f32 D_00372CF0;
}

s32 func_001B9C60_d(u128_1B9* pv, f32 r) __asm__("func_001B9C60");
s32 func_001B9C60_d(u128_1B9* pv, f32 r) {
    union {
        u128_1B9 q;
        V4_1B9 v;
    } t;
    t.q = *pv;
    t.v.f[3] = 1.0f;
    f32 nz = D_00372D18;
    asm volatile(
        "lqc2 $vf3, 0(%0)\n\tlqc2 $vf2, 0(%1)\n\tlqc2 $vf1, 0x10(%1)\n\tvmulax.xyzw $ACC, $vf2, $vf3x\n\tvmadday.xyzw $ACC, $vf1, $vf3y\n\tlqc2 $vf2, 0x20(%1)\n\tlqc2 $vf1, 0x30(%1)\n\tvmaddaz.xyzw $ACC, $vf2, $vf3z\n\tvmaddw.xyzw $vf1, $vf1, $vf3w\n\tsqc2 $vf1, 0(%0)"
        : : "r"(&t), "r"(D_0038CA40) : "memory");
    f32 x = t.v.f[0];
    f32 y = t.v.f[1];
    f32 z = t.v.f[2];
    if (r < z - nz) goto yes;
    if (r < D_00372D1C - z) goto yes;
    {
        f32 a = D_00372CEC * z;
        f32 b = D_00372CF4 * y;
        if (r < a + b) goto yes;
        if (r < a - b) goto yes;
    }
    {
        f32 c = D_00372CE8 * z;
        f32 d = D_00372CF0 * x;
        if (r < c - d) goto yes;
        if (r < c + d) goto yes;
    }
    return 0;
yes:
    return 1;
}

INCLUDE_ASM("asm/nonmatchings/game/t_1B93E8", func_001B9D78);

INCLUDE_ASM("asm/nonmatchings/game/t_1B93E8", func_001B9E90);

INCLUDE_ASM("asm/nonmatchings/game/t_1B93E8", func_001BA110);

extern "C" void func_001BA6D8(void) {
    char* p = D_00373270;
    D_0037327C = p;
    *(u32*)p = 0x10000005;
    *(u32*)(p + 4) = 0;
    D_00373270 = p + 8;
    *(u32*)(p + 8) = 0x11000000;
    D_00373270 = p + 0xC;
    *(u32*)(p + 0xC) = 0x50000002;
    D_00373270 = p + 0x10;
    func_0019E048(0xE, 1, 0, 0, 0, 1, 1);
    func_0019E318(0xF, 0);
    char* q = D_00373270;
    *(u32*)q = 0x13000000;
    D_00373270 = q + 4;
    *(u32*)(q + 4) = 0;
    D_00373270 = q + 8;
    *(u32*)(q + 8) = 0;
    D_00373270 = q + 0xC;
    *(u32*)(q + 0xC) = 0;
    D_00373270 = q + 0x10;
    func_0019E048(0xE, 1, 0, 0, 0, 1, 1);
    func_0019E318(0x3F, 0);
}

INCLUDE_ASM("asm/nonmatchings/game/t_1B93E8", func_001BA7E8);

GP_DATA(D_0036CAC8);
extern "C" void func_001BB050(void) {
    D_0036CAC8 = 1;
    D_00372C30 = D_0036C7E8;
}

extern "C" void func_001BB068(void) {
    D_0036CACC = 1;
}

struct N1B { char pad0[0x19C]; N1B* unk19C; };
struct M1B { char pad0[0x2C]; M1B* unk2C; };
extern "C" void func_001B1E38(void*);
extern "C" void func_001BF358(void*);

GP_DATA(D_0036CACC);
extern "C" void func_001BB078(void) {
    if (D_0036CACC) {
        func_001BB050();
        N1B* n = (N1B*)D_00372C34[0];
        if (n) {
            do {
                func_001B1E38(n);
                n = n->unk19C;
            } while (n);
        }
        M1B* m = (M1B*)D_0036CBC0[0];
        if (m) {
            do {
                func_001BF358(m);
                m = m->unk2C;
            } while (m);
        }
        D_0036CACC = 0;
        D_0036CAC8 = 1;
    }
}

extern "C" void func_001BB100(void) {
    if (D_0036CAC8) {
        N1B* n = (N1B*)D_00372C34[0];
        if (n) {
            do {
                func_001B1EB0(n);
                n = n->unk19C;
            } while (n);
        }
        M1B* m = (M1B*)D_0036CBC0[0];
        if (m) {
            do {
                func_001BF408(m);
                m = m->unk2C;
            } while (m);
        }
        D_0036CAC8 = 0;
    }
}

extern "C" void func_001BB180(void) {
    D_0036CAD4 = 0;
}

INCLUDE_ASM("asm/nonmatchings/game/t_1B93E8", func_001BB188);
