#include "common.h"

extern "C" {
extern int D_00369798;
int func_002B5888(int);
void func_00144FC0(int, int, int, int, int);
int func_00119610(int, int);
void func_001194B8(int);
void func_00119490(int, int);
int func_00118F20(int, int, int, int);
extern int D_003720E8;
extern int D_003720E4;
extern int D_00368A38;
extern int D_00368744;
int func_002B5C08(int, int);
int func_002B5CA8(int, int);
int func_0027D870(int, int, int *, int);
int func_002B5BC8(int, int);
int func_0027D1F8(int, int, int *, int);
int func_002DCA40(int);
void func_0027C160(int, int, int);
}

INCLUDE_ASM("asm/nonmatchings/game/t_2BEEE0", CFunc_DumpNoteMappings);

GP_DATA(D_003720E8);
extern "C" int CFunc_TextOutputStart(void) {
    if (D_00368744 != 0) {
        int h = D_00368A38;
        func_00119490(h, func_00119610(h, 0x3B));
    }
    int m = func_00118F20(D_00368A38, 0x200000, 1, 0);
    D_003720E4 = m;
    D_003720E8 = m;
    if (D_00368744 != 0) {
        func_001194B8(D_00368A38);
    }
    return 1;
}

INCLUDE_ASM("asm/nonmatchings/game/t_2BEEE0", CFunc_TextOutput);

INCLUDE_ASM("asm/nonmatchings/game/t_2BEEE0", CFunc_TextOutputEnd);

INCLUDE_ASM("asm/nonmatchings/game/t_2BEEE0", CFunc_ApplyBossBattleGemMisses);

INCLUDE_ASM("asm/nonmatchings/game/t_2BEEE0", CFunc_DebugTransform);

INCLUDE_ASM("asm/nonmatchings/game/t_2BEEE0", func_002BF900);

INCLUDE_ASM("asm/nonmatchings/game/t_2BEEE0", CFunc_CreateGemMover);

INCLUDE_ASM("asm/nonmatchings/game/t_2BEEE0", CFunc_DestroyGem);

extern "C" int CFunc_MakeDeadWhammy(int arg0) {
    int a;
    int b;
    if (func_0027D870(arg0, 0xA1DC81F9, &a, 0) != 0 && func_0027D1F8(arg0, 0x67E6859A, &b, 0) != 0) {
        return func_002B5BC8(a, b - 1);
    }
    return 0;
}

extern "C" int CFunc_MakeStarWhammy(int arg0) {
    int a;
    int b;
    if (func_0027D870(arg0, 0xA1DC81F9, &a, 0) != 0 && func_0027D1F8(arg0, 0x67E6859A, &b, 0) != 0) {
        return func_002B5C08(a, b - 1);
    }
    return 0;
}

extern "C" int CFunc_MakeNormalWhammy(int arg0) {
    int a;
    int b;
    if (func_0027D870(arg0, 0xA1DC81F9, &a, 0) != 0 && func_0027D1F8(arg0, 0x67E6859A, &b, 0) != 0) {
        return func_002B5CA8(a, b - 1);
    }
    return 0;
}

struct SGIHBI {
    char pad0[0x20];
    int unk20;
};
extern "C" s32 CFunc_GetInputHandlerBotIndex(int arg0, SGIHBI *arg1) {
    int out;
    func_0027D1F8(arg0, 0x67E6859A, &out, 1);
    func_0027C160(arg1->unk20, 0xB30D9965, func_002DCA40(out - 1));
    return 1;
}

INCLUDE_ASM("asm/nonmatchings/game/t_2BEEE0", CFunc_UpdateGemMovers);

INCLUDE_ASM("asm/nonmatchings/game/t_2BEEE0", func_002C07E8);
