#include "common.h"

struct S2ADFD8_0 {
    s32 unk0;
    s32 unk4;
    s32 unk8;
};

extern "C" {
int func_002AE2A8(int, int);
extern f32 D_00373130[] __attribute__((section(".sdata")));
}

INCLUDE_ASM("asm/nonmatchings/game/t_2AD528", CFunc_LightShow_AppendSnapshotParams);

INCLUDE_ASM("asm/nonmatchings/game/t_2AD528", CFunc_LightShow_OverrideColor);

INCLUDE_ASM("asm/nonmatchings/game/t_2AD528", CFunc_LightShow_SetTime);

INCLUDE_ASM("asm/nonmatchings/game/t_2AD528", CFunc_LightShow_GetPyroScript);

INCLUDE_ASM("asm/nonmatchings/game/t_2AD528", func_002AD7F0);

INCLUDE_ASM("asm/nonmatchings/game/t_2AD528", CFunc_LightShow_PlaySnapshot);

INCLUDE_ASM("asm/nonmatchings/game/t_2AD528", CFunc_LightShow_CycleNextSnapshot);

INCLUDE_ASM("asm/nonmatchings/game/t_2AD528", CFunc_LightShow_RefreshSpotlightOverrideParams);

INCLUDE_ASM("asm/nonmatchings/game/t_2AD528", CFunc_LightShow_EnableSpotlights);

extern "C" void func_002ADFD8(S2ADFD8_0 *arg0) {
    arg0->unk0 = 0;
    arg0->unk4 = 0;
    arg0->unk8 = 0;
}

INCLUDE_ASM("asm/nonmatchings/game/t_2AD528", func_002ADFE8);

INCLUDE_ASM("asm/nonmatchings/game/t_2AD528", func_002AE0A0);

INCLUDE_ASM("asm/nonmatchings/game/t_2AD528", func_002AE0C8);

INCLUDE_ASM("asm/nonmatchings/game/t_2AD528", func_002AE2A8);

INCLUDE_ASM("asm/nonmatchings/game/t_2AD528", func_002AE3C0);

INCLUDE_ASM("asm/nonmatchings/game/t_2AD528", func_002AE430);

INCLUDE_ASM("asm/nonmatchings/game/t_2AD528", func_002AE4A0);

INCLUDE_ASM("asm/nonmatchings/game/t_2AD528", func_002AE510);

INCLUDE_ASM("asm/nonmatchings/game/t_2AD528", func_002AE5E8);

INCLUDE_ASM("asm/nonmatchings/game/t_2AD528", func_002AE6C8);

INCLUDE_ASM("asm/nonmatchings/game/t_2AD528", func_002AE870);

INCLUDE_ASM("asm/nonmatchings/game/t_2AD528", func_002AE9F8);

INCLUDE_ASM("asm/nonmatchings/game/t_2AD528", func_002AEA30);

INCLUDE_ASM("asm/nonmatchings/game/t_2AD528", func_002AEB48);

INCLUDE_ASM("asm/nonmatchings/game/t_2AD528", func_002AEB98);

INCLUDE_ASM("asm/nonmatchings/game/t_2AD528", func_002AEBF0);

extern "C" void func_002AECF8(void) {
    func_002AE2A8(1, 0xFFFF);
}

INCLUDE_ASM("asm/nonmatchings/game/t_2AD528", func_002AED18);

extern "C" f32 func_002AED50(void *p, int i) {
    return D_00373130[i];
}

INCLUDE_ASM("asm/nonmatchings/game/t_2AD528", CFunc_MonitorControllerStates);

extern "C" s32 CFunc_AllocateDataBuffer(void) {
    return 0;
}

extern "C" s32 CFunc_ClearDataBuffer(void) {
    return 0;
}

extern "C" s32 CFunc_WriteDataBuffer(void) {
    return 0;
}

extern "C" s32 CFunc_ReadDataBuffer(void) {
    return 0;
}

extern "C" s32 CFunc_DataBufferPutChecksum(void) {
    return 0;
}

extern "C" s32 CFunc_DataBufferPutInt(void) {
    return 0;
}

extern "C" s32 CFunc_DataBufferPutFloat(void) {
    return 0;
}

extern "C" s32 CFunc_DataBufferPutString(void) {
    return 0;
}

extern "C" s32 CFunc_DataBufferGetChecksum(void) {
    return 0;
}

extern "C" s32 CFunc_DataBufferGetInt(void) {
    return 0;
}

extern "C" s32 CFunc_DataBufferGetFloat(void) {
    return 0;
}

extern "C" s32 CFunc_DataBufferGetString(void) {
    return 0;
}

extern "C" s32 CFunc_GetBufferFileCount(void) {
    return 0;
}

extern "C" s32 CFunc_ReplayInput(void) {
    return 0;
}

extern "C" s32 CFunc_RecordInput(void) {
    return 0;
}

INCLUDE_ASM("asm/nonmatchings/game/t_2AD528", func_002AF170);

INCLUDE_ASM("asm/nonmatchings/game/t_2AD528", CFunc_SetInput);

INCLUDE_ASM("asm/nonmatchings/game/t_2AD528", CFunc_EnableInput);

INCLUDE_ASM("asm/nonmatchings/game/t_2AD528", func_002AF438);

INCLUDE_ASM("asm/nonmatchings/game/t_2AD528", CFunc_IsGuitarController);

extern "C" s32 CFunc_UnBindGuitarControllerStatus(void) {
    return 1;
}

INCLUDE_ASM("asm/nonmatchings/game/t_2AD528", func_002AF4B0);
