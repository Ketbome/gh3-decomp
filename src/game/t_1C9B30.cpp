#include "common.h"

struct S001C9FB0 {
    char pad0[0x3C];
    s32 unk3C;
    s32 unk40;
    char pad44[0x78];
    s32 unkBC;
    char padC0[0x4];
    s32 unkC4;
    s32 unkC8;
    char padCC[0x81A8 - 0xCC];
    s32 unk81A8;
    s32 unk81AC[2];
    s32 unk81B4;
};

struct S001CB080 {
    char pad0[0x18];
    void* unk18;
};

extern "C" {
void func_00113FB8(void* p);
}

INCLUDE_ASM("asm/nonmatchings/game/t_1C9B30", func_001C9B30);

INCLUDE_ASM("asm/nonmatchings/game/t_1C9B30", func_001C9B70);

INCLUDE_ASM("asm/nonmatchings/game/t_1C9B30", func_001C9DD8);

INCLUDE_ASM("asm/nonmatchings/game/t_1C9B30", func_001C9EB8);

INCLUDE_ASM("asm/nonmatchings/game/t_1C9B30", func_001C9FB0);

INCLUDE_ASM("asm/nonmatchings/game/t_1C9B30", func_001C9FF0);

extern "C" s32 func_001CA000(S001C9FB0* p) {
    return p->unkC4;
}

extern "C" s32 func_001CA008(S001C9FB0* p) {
    return p->unkC8;
}

extern "C" s32 func_001CA010(S001C9FB0* p) {
    return p->unk81A8;
}

extern "C" s32 func_001CA020(S001C9FB0* p, s32 i) {
    return p->unk81AC[i];
}

extern "C" s32 func_001CA038(S001C9FB0* p) {
    return p->unk81B4;
}

INCLUDE_ASM("asm/nonmatchings/game/t_1C9B30", func_001CA048);

INCLUDE_ASM("asm/nonmatchings/game/t_1C9B30", func_001CA120);

INCLUDE_ASM("asm/nonmatchings/game/t_1C9B30", func_001CA210);

INCLUDE_ASM("asm/nonmatchings/game/t_1C9B30", func_001CA3E8);

INCLUDE_ASM("asm/nonmatchings/game/t_1C9B30", func_001CA458);

INCLUDE_ASM("asm/nonmatchings/game/t_1C9B30", func_001CA4E8);

INCLUDE_ASM("asm/nonmatchings/game/t_1C9B30", func_001CA590);

INCLUDE_ASM("asm/nonmatchings/game/t_1C9B30", func_001CA670);

INCLUDE_ASM("asm/nonmatchings/game/t_1C9B30", func_001CA6D0);

INCLUDE_ASM("asm/nonmatchings/game/t_1C9B30", func_001CA768);

INCLUDE_ASM("asm/nonmatchings/game/t_1C9B30", func_001CA808);

INCLUDE_ASM("asm/nonmatchings/game/t_1C9B30", func_001CA898);

extern "C" void* func_001CA998(S001C9FB0* p) {
    return &p->unk40;
}

INCLUDE_ASM("asm/nonmatchings/game/t_1C9B30", func_001CA9A0);

INCLUDE_ASM("asm/nonmatchings/game/t_1C9B30", func_001CAFB0);

INCLUDE_ASM("asm/nonmatchings/game/t_1C9B30", func_001CB078);

extern "C" void func_001CB080(S001CB080* p) {
    func_00113FB8(p->unk18);
}

INCLUDE_ASM("asm/nonmatchings/game/t_1C9B30", func_001CB0A0);

INCLUDE_ASM("asm/nonmatchings/game/t_1C9B30", func_001CB180);

INCLUDE_ASM("asm/nonmatchings/game/t_1C9B30", func_001CB200);

INCLUDE_ASM("asm/nonmatchings/game/t_1C9B30", func_001CB478);

INCLUDE_ASM("asm/nonmatchings/game/t_1C9B30", func_001CB548);

extern "C" void func_001CB550(S001C9FB0* p, s32 v) {
    p->unkBC = v;
}

extern "C" s32 func_001CB558(S001C9FB0* p) {
    return p->unkBC;
}

extern "C" void func_001CB560(S001C9FB0* p, s32 v) {
    p->unk3C = v;
}

extern "C" s32 func_001CB568(S001C9FB0* p) {
    return p->unk3C;
}

INCLUDE_ASM("asm/nonmatchings/game/t_1C9B30", func_001CB570);

INCLUDE_ASM("asm/nonmatchings/game/t_1C9B30", CFunc_MarkGameOver);

INCLUDE_ASM("asm/nonmatchings/game/t_1C9B30", CFunc_SetJoinMode);

INCLUDE_ASM("asm/nonmatchings/game/t_1C9B30", CFunc_SetHostMode);

INCLUDE_ASM("asm/nonmatchings/game/t_1C9B30", CFunc_IsHost);

INCLUDE_ASM("asm/nonmatchings/game/t_1C9B30", CFunc_ChangeLevelPending);

INCLUDE_ASM("asm/nonmatchings/game/t_1C9B30", func_001CB708);

INCLUDE_ASM("asm/nonmatchings/game/t_1C9B30", func_001CB750);

INCLUDE_ASM("asm/nonmatchings/game/t_1C9B30", CFunc_EnterSurveyorMode);

INCLUDE_ASM("asm/nonmatchings/game/t_1C9B30", CFunc_ExitSurveyorMode);

INCLUDE_ASM("asm/nonmatchings/game/t_1C9B30", func_001CB8D8);

INCLUDE_ASM("asm/nonmatchings/game/t_1C9B30", func_001CBAE0);
