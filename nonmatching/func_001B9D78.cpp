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

INCLUDE_ASM("asm/nonmatchings/game/t_1B93E8", func_001B9C60);

typedef unsigned int u128_1B9 __attribute__((mode(TI)));
struct V1B9 {
    f32 x, y, z, w;
} __attribute__((aligned(16)));

extern "C" {
extern char D_0038CA40[];
extern f32 D_00372D18;
extern f32 D_00372D1C;
extern f32 D_00372CEC;
extern f32 D_00372CF4;
extern f32 D_00372CE8;
extern f32 D_00372CF0;
}

extern "C" s32 func_001B9D78(const u128_1B9* a, f32 r) {
    V1B9 v;
    *(u128_1B9*)&v = *a;
    v.w = 1.0f;
    f32 lim = D_00372D18;
    asm volatile("lqc2 $vf3, %1\n\tlqc2 $vf2, 0(%2)\n\tlqc2 $vf1, 0x10(%2)\n\tvmulax.xyzw $ACC, $vf2, $vf3x\n\tvmadday.xyzw $ACC, $vf1, $vf3y\n\tlqc2 $vf2, 0x20(%2)\n\tlqc2 $vf1, 0x30(%2)\n\tvmaddaz.xyzw $ACC, $vf2, $vf3z\n\tvmaddw.xyzw $vf1, $vf1, $vf3w\n\tsqc2 $vf1, %0"
        : "=m"(v) : "m"(v), "r"(D_0038CA40));
    f32 z = v.z;
    f32 x = v.x;
    f32 y = v.y;
    if (r < z - lim || r < D_00372D1C - z) return 0;
    f32 a1 = D_00372CEC * z;
    f32 b1 = D_00372CF4 * y;
    if (r < a1 + b1 || r < a1 - b1) return 0;
    f32 a2 = D_00372CE8 * z;
    f32 b2 = D_00372CF0 * x;
    if (r < a2 - b2 || r < a2 + b2) return 0;
    return 1;
}

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
