#include "common.h"

extern "C" {
int func_002B5C08(int, int);
int func_002B5CA8(int, int);
int func_0027D870(int, int, int *, int);
int func_002B5BC8(int, int);
int func_0027D1F8(int, int, int *, int);
int func_002DCA40(int);
void func_0027C160(int, int, int);
}

INCLUDE_ASM("asm/nonmatchings/game/t_2BEEE0", CFunc_DumpNoteMappings);

INCLUDE_ASM("asm/nonmatchings/game/t_2BEEE0", CFunc_TextOutputStart);

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
