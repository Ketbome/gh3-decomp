#include "common.h"

extern "C" {
extern int D_00368740[] __attribute__((section(".sdata")));
void func_001163F8(void);
int func_00116638(void);
int func_001163F0(void);
int func_00116400(void);
extern int D_0036CDB4[] __attribute__((section(".sdata")));
void func_001C74F8(int);
}

INCLUDE_ASM("asm/nonmatchings/game/t_2626E0", CFunc_SetViewerModel);

INCLUDE_ASM("asm/nonmatchings/game/t_2626E0", CFunc_SetViewerAnim);

INCLUDE_ASM("asm/nonmatchings/game/t_2626E0", CFunc_SetViewerLODDist);

INCLUDE_ASM("asm/nonmatchings/game/t_2626E0", CFunc_GetViewerObjectID);

INCLUDE_ASM("asm/nonmatchings/game/t_2626E0", CFunc_ReloadViewerAnim);

INCLUDE_ASM("asm/nonmatchings/game/t_2626E0", CFunc_ResetModelViewerCamera);

INCLUDE_ASM("asm/nonmatchings/game/t_2626E0", CFunc_SetViewMode);

INCLUDE_ASM("asm/nonmatchings/game/t_2626E0", CFunc_ClearViewerObject);

INCLUDE_ASM("asm/nonmatchings/game/t_2626E0", func_00262AB0);

INCLUDE_ASM("asm/nonmatchings/game/t_2626E0", CFunc_ResetPS2);

INCLUDE_ASM("asm/nonmatchings/game/t_2626E0", CFunc_ResetHD);

INCLUDE_ASM("asm/nonmatchings/game/t_2626E0", CFunc_LoadExecPS2);

extern "C" int CFunc_ExitDemo(void) {
    func_00116638();
    return 1;
}

INCLUDE_ASM("asm/nonmatchings/game/t_2626E0", func_00262C48);

INCLUDE_ASM("asm/nonmatchings/game/t_2626E0", CFunc_IsPS2);

extern "C" int CFunc_IsPS3(void) {
    return 0;
}

extern "C" int CFunc_IsNGC(void) {
    return D_00368740[0] == 5;
}

extern "C" int CFunc_IsXBOX(void) {
    return D_00368740[0] == 4;
}

extern "C" int CFunc_IsXENON(void) {
    return D_00368740[0] == 6;
}

extern "C" int CFunc_IsWIN32(void) {
    return D_00368740[0] == 9;
}

INCLUDE_ASM("asm/nonmatchings/game/t_2626E0", CFunc_GetPlatform);

INCLUDE_ASM("asm/nonmatchings/game/t_2626E0", CFunc_GetPlatformExt);

extern "C" int CFunc_StartDelaySystemUI(void) {
    func_001163F0();
    return 1;
}

extern "C" int CFunc_StopDelaySystemUI(void) {
    func_00116400();
    return 1;
}

extern "C" void CFunc_SystemUIDelayed(void) {
    func_001163F8();
}

INCLUDE_ASM("asm/nonmatchings/game/t_2626E0", func_00262E28);

INCLUDE_ASM("asm/nonmatchings/game/t_2626E0", CFunc_ControllerDebounce);

INCLUDE_ASM("asm/nonmatchings/game/t_2626E0", func_00262F18);

INCLUDE_ASM("asm/nonmatchings/game/t_2626E0", func_002634B8);

INCLUDE_ASM("asm/nonmatchings/game/t_2626E0", CFunc_ControllerPressed);

INCLUDE_ASM("asm/nonmatchings/game/t_2626E0", CFunc_ControllerMake);

INCLUDE_ASM("asm/nonmatchings/game/t_2626E0", CFunc_EnableActuators);

INCLUDE_ASM("asm/nonmatchings/game/t_2626E0", CFunc_VibrateController);

extern "C" void CFunc_PadsPluggedIn(void) {
    func_001C74F8(D_0036CDB4[0]);
}

INCLUDE_ASM("asm/nonmatchings/game/t_2626E0", CFunc_GetAnalogueInfo);

INCLUDE_ASM("asm/nonmatchings/game/t_2626E0", CFunc_RightAnalogHeld);

INCLUDE_ASM("asm/nonmatchings/game/t_2626E0", CFunc_BindFrontEndToController);

extern "C" int CFunc_ReAcquireControllers(void) {
    return 1;
}

INCLUDE_ASM("asm/nonmatchings/game/t_2626E0", func_00263ED8);

INCLUDE_ASM("asm/nonmatchings/game/t_2626E0", CFunc_SetScreenMode);

INCLUDE_ASM("asm/nonmatchings/game/t_2626E0", CFunc_GetScreenMode);

INCLUDE_ASM("asm/nonmatchings/game/t_2626E0", CFunc_CreateViewport);

INCLUDE_ASM("asm/nonmatchings/game/t_2626E0", CFunc_DestroyViewport);

INCLUDE_ASM("asm/nonmatchings/game/t_2626E0", func_00264040);

INCLUDE_ASM("asm/nonmatchings/game/t_2626E0", CFunc_ViewportExists);

INCLUDE_ASM("asm/nonmatchings/game/t_2626E0", CFunc_SetViewportProperties);

INCLUDE_ASM("asm/nonmatchings/game/t_2626E0", CFunc_GetViewport2DPosFrom3D);

INCLUDE_ASM("asm/nonmatchings/game/t_2626E0", CFunc_GetViewportCameraPos);

INCLUDE_ASM("asm/nonmatchings/game/t_2626E0", CFunc_GetViewportCameraOrient);

INCLUDE_ASM("asm/nonmatchings/game/t_2626E0", CFunc_SetViewportCameraPos);

INCLUDE_ASM("asm/nonmatchings/game/t_2626E0", CFunc_SetViewportCameraOrient);
