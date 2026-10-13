#include "common.h"

extern "C" {
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

INCLUDE_ASM("asm/nonmatchings/game/t_2BEEE0", CFunc_MakeDeadWhammy);

INCLUDE_ASM("asm/nonmatchings/game/t_2BEEE0", CFunc_MakeStarWhammy);

INCLUDE_ASM("asm/nonmatchings/game/t_2BEEE0", CFunc_MakeNormalWhammy);

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
