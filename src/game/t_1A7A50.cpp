#include "common.h"

struct E_1A8520 { int* unk0; char pad4[0x6C]; };

extern "C" {
void func_001A4730(int);
extern int D_0036C5D8;
int func_002EE340(int, void*, int);
extern int D_00372C08;
extern int D_00372C0C;
extern u8 func_001A7118[];
extern void* D_0036C6B0;
extern u32 D_0036C6B4;
void* func_00113DF0(int, int, int);
extern int D_00368A38;
void func_00119400(int, void*);
void func_001A9128(int, int);
int func_001A46E0(int);
extern int D_0036C660;
extern u8 D_0038C450[];
extern int D_0036C65C;
extern u8 func_001A8560[];
void func_0030CAA8(void*, int, int, void*);
}

INCLUDE_ASM("asm/nonmatchings/game/t_1A7A50", func_001A7A50);

GP_DATA(D_0036C5D8);
extern "C" void func_001A8120(int x) {
    if (D_0036C5D8 < 0) {
        D_00372C08 = x;
        D_00372C0C = 0;
        D_0036C5D8 = func_002EE340(2, func_001A7118 + 8, -1);
    }
}

INCLUDE_ASM("asm/nonmatchings/game/t_1A7A50", func_001A8168);

INCLUDE_ASM("asm/nonmatchings/game/t_1A7A50", func_001A8198);

INCLUDE_ASM("asm/nonmatchings/game/t_1A7A50", func_001A84E0);

INCLUDE_ASM("asm/nonmatchings/game/t_1A7A50", func_001A8518);

GP_DATA(D_0036C65C);
extern "C" void func_001A8520(int* p) {
    u32 n = D_0036C65C;
    if (n < 12) {
        ((E_1A8520*)D_0038C450)[n].unk0 = p;
        *p = 1;
        D_0036C65C = n + 1;
    }
}

INCLUDE_ASM("asm/nonmatchings/game/t_1A7A50", func_001A8560);

GP_DATA(D_0036C65C);
extern "C" void func_001A85A8(void) {
    func_0030CAA8(D_0038C450, D_0036C65C, 112, func_001A8560);
}

INCLUDE_ASM("asm/nonmatchings/game/t_1A7A50", func_001A85D8);

INCLUDE_ASM("asm/nonmatchings/game/t_1A7A50", func_001A8758);

INCLUDE_ASM("asm/nonmatchings/game/t_1A7A50", func_001A8810);

INCLUDE_ASM("asm/nonmatchings/game/t_1A7A50", func_001A88E8);

INCLUDE_ASM("asm/nonmatchings/game/t_1A7A50", func_001A8A60);

INCLUDE_ASM("asm/nonmatchings/game/t_1A7A50", func_001A8B10);

GP_DATA(D_0036C660);
extern "C" int func_001A90D0(void) {
    int r0 = func_001A46E0(0);
    D_0036C660 = r0;
    return r0;
}

extern "C" void func_001A90F8(void) {
    if (D_0036C660) {
        func_001A4730(0);
        D_0036C660 = 0;
    }
}

INCLUDE_ASM("asm/nonmatchings/game/t_1A7A50", func_001A9120);

INCLUDE_ASM("asm/nonmatchings/game/t_1A7A50", func_001A9128);

extern "C" void func_001A9220(void) {
    func_001A9128(1, 65535);
}

GP_DATA(D_0036C6B0);
GP_DATA(D_0036C6B4);
extern "C" void* func_001A9240(int a) {
    if (!D_0036C6B0 && a) {
        D_0036C6B0 = func_00113DF0(0x30, 0, 1);
    }
    D_0036C6B4++;
    return D_0036C6B0;
}

extern "C" void func_001A9288(void) {
    if (D_0036C6B4 >= 2) {
        D_0036C6B4--;
        return;
    }
    if (D_0036C6B0) {
        func_00119400(D_00368A38, D_0036C6B0);
    }
    D_0036C6B0 = 0;
    D_0036C6B4 = 0;
}

struct V3_1A92D0 { int a, b, c; };
extern V3_1A92D0 D_0038CFE0;
extern V3_1A92D0 D_0038CFF0;
extern float D_0038CB70[];
extern float D_0038CB74[];
extern float D_0038CB78[];

extern "C" int func_001A92D0(int u, float* p, float* q) {
    int r = 0;
    if ((D_0038CFE0.a != 0 && q[0] + p[0] <= D_0038CB70[0]) ||
        (D_0038CFE0.b != 0 && q[1] + p[1] <= D_0038CB74[0]) ||
        (D_0038CFE0.c != 0 && q[2] + p[2] <= D_0038CB78[0]) ||
        (D_0038CFF0.a != 0 && D_0038CB70[0] <= q[0] - p[0]) ||
        (D_0038CFF0.b != 0 && D_0038CB74[0] <= q[1] - p[1]) ||
        (D_0038CFF0.c != 0 && D_0038CB78[0] <= q[2] - p[2])) {
        r = 1;
    }
    return r;
}

INCLUDE_ASM("asm/nonmatchings/game/t_1A7A50", func_001A93F8);
