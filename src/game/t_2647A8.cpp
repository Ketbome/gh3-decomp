#include "common.h"

extern "C" {
int func_001EBFE8(void);
void func_002663F8(int, int);
}

INCLUDE_ASM("asm/nonmatchings/game/t_2647A8", CFunc_CreateViewportTextureOverride);

extern "C" int CFunc_DestroyViewportTextureOverride(void) {
    return 0;
}

INCLUDE_ASM("asm/nonmatchings/game/t_2647A8", CFunc_AddPrepassViewport);

INCLUDE_ASM("asm/nonmatchings/game/t_2647A8", CFunc_PrepassViewportExists);

INCLUDE_ASM("asm/nonmatchings/game/t_2647A8", CFunc_RemovePrepassViewport);

INCLUDE_ASM("asm/nonmatchings/game/t_2647A8", CFunc_AddZoneProfiles);

INCLUDE_ASM("asm/nonmatchings/game/t_2647A8", CFunc_RemoveZoneProfiles);

INCLUDE_ASM("asm/nonmatchings/game/t_2647A8", CFunc_SetZoneProfiles);

extern "C" int CFunc_PrintLoadedProfiles(void) {
    func_001EBFE8();
    return 1;
}

INCLUDE_ASM("asm/nonmatchings/game/t_2647A8", CFunc_CreateRandomAppearance);

INCLUDE_ASM("asm/nonmatchings/game/t_2647A8", CFunc_AddEditableList);

INCLUDE_ASM("asm/nonmatchings/game/t_2647A8", CFunc_RemoveEditableList);

INCLUDE_ASM("asm/nonmatchings/game/t_2647A8", CFunc_ForEachInEditableList);

INCLUDE_ASM("asm/nonmatchings/game/t_2647A8", CFunc_SelectFrom);

INCLUDE_ASM("asm/nonmatchings/game/t_2647A8", func_00264B70);

INCLUDE_ASM("asm/nonmatchings/game/t_2647A8", func_00264BE8);

INCLUDE_ASM("asm/nonmatchings/game/t_2647A8", func_00264C58);

INCLUDE_ASM("asm/nonmatchings/game/t_2647A8", func_00264F60);

INCLUDE_ASM("asm/nonmatchings/game/t_2647A8", func_00264F90);

INCLUDE_ASM("asm/nonmatchings/game/t_2647A8", func_00265008);

INCLUDE_ASM("asm/nonmatchings/game/t_2647A8", func_002650F8);

INCLUDE_ASM("asm/nonmatchings/game/t_2647A8", func_00265388);

INCLUDE_ASM("asm/nonmatchings/game/t_2647A8", func_00265428);

INCLUDE_ASM("asm/nonmatchings/game/t_2647A8", func_00265580);

INCLUDE_ASM("asm/nonmatchings/game/t_2647A8", func_00265680);

INCLUDE_ASM("asm/nonmatchings/game/t_2647A8", CFunc_UpdateMaterialProperty);

INCLUDE_ASM("asm/nonmatchings/game/t_2647A8", func_002663F0);

INCLUDE_ASM("asm/nonmatchings/game/t_2647A8", func_002663F8);

INCLUDE_ASM("asm/nonmatchings/game/t_2647A8", func_00266428);

INCLUDE_ASM("asm/nonmatchings/game/t_2647A8", func_002664F8);

extern "C" void func_00266600(void) {
    func_002663F8(1, 0xFFFF);
}

INCLUDE_ASM("asm/nonmatchings/game/t_2647A8", func_00266620);

INCLUDE_ASM("asm/nonmatchings/game/t_2647A8", func_00266780);
