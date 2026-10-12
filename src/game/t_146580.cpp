#include "common.h"

struct S_00146E68 { char pad0[0x5B4]; int unk5B4; };

struct S_00148248 { char pad0[0x34]; float unk34; };
struct S_00148250 { char pad0[0x38]; float unk38; };
struct S_00148348 { char pad0[0x250]; int unk250; };

INCLUDE_ASM("asm/nonmatchings/game/t_146580", func_00146580);

INCLUDE_ASM("asm/nonmatchings/game/t_146580", func_00146778);

extern "C" void func_001468A0(void) {
}

INCLUDE_ASM("asm/nonmatchings/game/t_146580", func_001468A8);

INCLUDE_ASM("asm/nonmatchings/game/t_146580", func_00146970);

INCLUDE_ASM("asm/nonmatchings/game/t_146580", func_00146C10);

INCLUDE_ASM("asm/nonmatchings/game/t_146580", func_00146DE0);

extern "C" int func_00146E68(S_00146E68* self) {
    return self->unk5B4 > 0;
}

INCLUDE_ASM("asm/nonmatchings/game/t_146580", func_00146E78);

INCLUDE_ASM("asm/nonmatchings/game/t_146580", CFunc_CreateScreenElement);

INCLUDE_ASM("asm/nonmatchings/game/t_146580", CFunc_DestroyScreenElement);

INCLUDE_ASM("asm/nonmatchings/game/t_146580", CFunc_RunScriptOnScreenElement);

INCLUDE_ASM("asm/nonmatchings/game/t_146580", CFunc_SetScreenElementProps);

INCLUDE_ASM("asm/nonmatchings/game/t_146580", CFunc_DoScreenElementMorph);

INCLUDE_ASM("asm/nonmatchings/game/t_146580", CFunc_SetScreenElementLock);

INCLUDE_ASM("asm/nonmatchings/game/t_146580", CFunc_ScreenElementSystemInit);

INCLUDE_ASM("asm/nonmatchings/game/t_146580", CFunc_GetScreenElementDims);

INCLUDE_ASM("asm/nonmatchings/game/t_146580", CFunc_GetScreenElementPosition);

INCLUDE_ASM("asm/nonmatchings/game/t_146580", CFunc_MenuSelectedIndexIs);

INCLUDE_ASM("asm/nonmatchings/game/t_146580", CFunc_ScreenElementExists);

INCLUDE_ASM("asm/nonmatchings/game/t_146580", CFunc_GetScreenElementProps);

INCLUDE_ASM("asm/nonmatchings/game/t_146580", CFunc_SetRootScreenElement);

INCLUDE_ASM("asm/nonmatchings/game/t_146580", CFunc_CreateMultipleTextElements);

INCLUDE_ASM("asm/nonmatchings/game/t_146580", CFunc_GetScreenElementChildren);

INCLUDE_ASM("asm/nonmatchings/game/t_146580", CFunc_ResolveScreenElementID);

INCLUDE_ASM("asm/nonmatchings/game/t_146580", func_001481D0);

INCLUDE_ASM("asm/nonmatchings/game/t_146580", CFunc_DumpScreenElements);

INCLUDE_ASM("asm/nonmatchings/game/t_146580", func_001481E0);

extern "C" float func_00148248(S_00148248* self) {
    return self->unk34;
}

extern "C" float func_00148250(S_00148250* self) {
    return self->unk38;
}

INCLUDE_ASM("asm/nonmatchings/game/t_146580", func_00148258);

INCLUDE_ASM("asm/nonmatchings/game/t_146580", func_001482F8);

extern "C" int func_00148348(S_00148348* self) {
    return self->unk250;
}

INCLUDE_ASM("asm/nonmatchings/game/t_146580", func_00148350);

INCLUDE_ASM("asm/nonmatchings/game/t_146580", func_001483B0);

INCLUDE_ASM("asm/nonmatchings/game/t_146580", func_00148490);

INCLUDE_ASM("asm/nonmatchings/game/t_146580", func_00148508);

INCLUDE_ASM("asm/nonmatchings/game/t_146580", func_00148530);
