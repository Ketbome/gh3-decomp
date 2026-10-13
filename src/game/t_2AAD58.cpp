#include "common.h"

struct S2AAD58_L {
    char pad0[8];
    int unk8;
    char padC[4];
    int unk10;
    f32 unk14;
    char pad18[0x10];
    f32 unk28;
};

extern "C" {
int func_001E2968(S2AAD58_L *, int);
f32 func_001E2850(S2AAD58_L *, int);
extern S2AAD58_L D_003AC770;
extern int D_00371EF0;
void func_0027AC90(int);
void func_0027ABB0(int, int);
int func_0027DF00(int, int);
extern int D_00371EEC;
extern s32 D_00371EF8;
extern s32 D_003AC7C0[];
}

INCLUDE_ASM("asm/nonmatchings/game/t_2AAD58", CFunc_LightShow_BeginProcessBlock);

GP_DATA(D_00371EF8);
extern "C" s32 CFunc_LightShow_EndProcessBlock(void) {
    D_00371EF8 = 0;
    D_003AC7C0[0] = 0;
    return 1;
}

INCLUDE_ASM("asm/nonmatchings/game/t_2AAD58", CFunc_LightShow_PassEvent);

INCLUDE_ASM("asm/nonmatchings/game/t_2AAD58", CFunc_LightShow_WaitForNextEvent);

INCLUDE_ASM("asm/nonmatchings/game/t_2AAD58", func_002AB738);

INCLUDE_ASM("asm/nonmatchings/game/t_2AAD58", func_002AB848);

INCLUDE_ASM("asm/nonmatchings/game/t_2AAD58", func_002ABB00);

INCLUDE_ASM("asm/nonmatchings/game/t_2AAD58", func_002ABC18);

INCLUDE_ASM("asm/nonmatchings/game/t_2AAD58", func_002ABD58);

INCLUDE_ASM("asm/nonmatchings/game/t_2AAD58", CFunc_LightShow_SetActive);

INCLUDE_ASM("asm/nonmatchings/game/t_2AAD58", CFunc_LightShow_SetProcessors);

extern "C" s32 CFunc_LightShow_SetMapping(int arg0) {
    func_0027AC90(D_00371EEC);
    if ((func_0027DF00(arg0, 0x1A4E0EF9) ^ 1) != 0 && arg0 != 0) {
        func_0027ABB0(D_00371EEC, arg0);
    }
    return 1;
}

INCLUDE_ASM("asm/nonmatchings/game/t_2AAD58", CFunc_LightShow_SetParams);

INCLUDE_ASM("asm/nonmatchings/game/t_2AAD58", CFunc_LightShow_GetParams);

GP_DATA(D_00371EF0);
extern "C" int CFunc_LightShow_Update(void) {
    if (!D_00371EF0) {
        return 0;
    }
    int t = func_001E2968(&D_003AC770, D_003AC770.unk8);
    f32 f = func_001E2850(&D_003AC770, t);
    f32 d = f - func_001E2850(&D_003AC770, D_003AC770.unk10);
    D_003AC770.unk28 = f;
    D_003AC770.unk10 = t;
    D_003AC770.unk14 = d;
    return 1;
}

INCLUDE_ASM("asm/nonmatchings/game/t_2AAD58", func_002ACA48);
