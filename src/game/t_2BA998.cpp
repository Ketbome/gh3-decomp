#include "common.h"

struct S2BA998_I {
    char pad0[0x28];
    int unk28;
};
struct S2BA998_G {
    char pad0[0xC];
    S2BA998_I *unkC;
    char pad10[4];
    S2BA998_G *unk14;
    char pad18[0x1F8];
    int unk210;
};

extern "C" {
extern int D_0036D3B0;
S2BA998_G *func_001D4AC0(int, int);
void func_00161EE0(int, int);
int func_0027DD88(int, int);
bool func_0027D870_b(int, int, int *, int) asm("func_0027D870");
bool func_0027D1F8_b(int, int, int *, int) asm("func_0027D1F8");
bool func_0027D268_b(int, int, float *, int) asm("func_0027D268");
int func_002763E0(int, int);
int func_002764E8(int, int);
void func_002BAFB0(int, int, int, int, float, int, int, int);
}

INCLUDE_ASM("asm/nonmatchings/game/t_2BA998", CFunc_SetGemConstants);

INCLUDE_ASM("asm/nonmatchings/game/t_2BA998", func_002BAFB0);

extern "C" int CFunc_Create2DGem(int a) {
    int s0;
    int s4;
    int s8;
    int sC;
    float f;
    int s14;
    int s18;
    int s1C;
    if (func_0027D870_b(a, 0x1BFF0C3D, &s0, 0)) {
        int h = func_002763E0(s0, 1);
        if ((func_0027D1F8_b(a, 0x67E6859A, &s4, 0) ^ 1) == 0) {
            s4 -= 1;
            if ((func_0027D870_b(a, 0x99A9B716, &s8, 0) ^ 1) == 0 && (func_0027D1F8_b(a, 0x7D30DF01, &sC, 0) ^ 1) == 0 &&
                (func_0027D268_b(a, 0x906B67BA, &f, 0) ^ 1) == 0 && (func_0027D1F8_b(a, 0xD4DE628F, &s14, 0) ^ 1) == 0 &&
                (func_0027D1F8_b(a, 0xEDBD8D9B, &s18, 0) ^ 1) == 0) {
                if ((func_0027D870_b(a, 0xCC12115E, &s1C, 0) ^ 1) == 0) {
                    int o = func_002764E8(s1C, 1);
                    func_002BAFB0(h, s4, s8, sC, f, s14, s18, o);
                    return 1;
                }
                return 0;
            }
        }
        return 0;
    }
    return 0;
}

INCLUDE_ASM("asm/nonmatchings/game/t_2BA998", CFunc_Create2DFretbar);

extern "C" int CFunc_MakeGemsVisibleOnAllViewports(void) {
    S2BA998_G *g = func_001D4AC0(D_0036D3B0, 0x286A8D26);
    if (g) {
        do {
            int t = g->unkC->unk28;
            if (t && func_0027DD88(t, 0x66AF794F)) {
                func_00161EE0(g->unk210, 0xFFFF);
            }
            g = g->unk14;
        } while (g);
    }
    return 1;
}

INCLUDE_ASM("asm/nonmatchings/game/t_2BA998", CFunc_CalculateGemTime);

INCLUDE_ASM("asm/nonmatchings/game/t_2BA998", CFunc_UpdateWhammyBarProps);
