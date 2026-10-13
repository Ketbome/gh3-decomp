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
}

INCLUDE_ASM("asm/nonmatchings/game/t_2BA998", CFunc_SetGemConstants);

INCLUDE_ASM("asm/nonmatchings/game/t_2BA998", func_002BAFB0);

INCLUDE_ASM("asm/nonmatchings/game/t_2BA998", CFunc_Create2DGem);

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
