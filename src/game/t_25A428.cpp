#include "common.h"

extern "C" {
void func_0014F7B8(void);
void func_0025AA28(int, int, int);
extern int D_00370540;
int func_0028DAD8(void);
int func_00289E08(int);
int func_0028E6D0(int);
int func_0028CE18(int);
int func_001EB2B0(void);
void func_0014F750(int, u32);
extern int D_003715D4[] __attribute__((section(".sdata")));
void func_00291900(int);
}

INCLUDE_ASM("asm/nonmatchings/game/t_25A428", CFunc_OnExitRun);

extern "C" int CFunc_StopAllScripts(void) {
    func_0028DAD8();
    return 1;
}

extern "C" int CFunc_FirstTimeThisIsCalled(void) {
    if (D_00370540 != 0) {
        D_00370540 = 0;
        return 1;
    }
    return 0;
}

INCLUDE_ASM("asm/nonmatchings/game/t_25A428", CFunc_StringToCharArray);

INCLUDE_ASM("asm/nonmatchings/game/t_25A428", CFunc_AppendSuffix);

extern "C" int CFunc_IsObjectScript(int a, int b) {
    return func_00289E08(b) != 0;
}

extern "C" int CFunc_StopRendering_C(void) {
    func_0014F750(0, 0xB8CA16A5);
    return 1;
}

extern "C" int CFunc_StartRendering_C(void) {
    func_0014F750(1, 0xB8CA16A5);
    return 1;
}

extern "C" void CFunc_RenderingEnabled(void) {
    func_0014F7B8();
}

INCLUDE_ASM("asm/nonmatchings/game/t_25A428", CFunc_Toggle2d);

INCLUDE_ASM("asm/nonmatchings/game/t_25A428", CFunc_SetScriptWarningLevel);

INCLUDE_ASM("asm/nonmatchings/game/t_25A428", func_0025AA28);

INCLUDE_ASM("asm/nonmatchings/game/t_25A428", CFunc_SpawnScript);

extern "C" void CFunc_SpawnScriptNow(int a, int b) {
    func_0025AA28(a, b, 1);
}

extern "C" void CFunc_SpawnScriptLater(int a, int b) {
    func_0025AA28(a, b, 0);
}

INCLUDE_ASM("asm/nonmatchings/game/t_25A428", CFunc_SetSpawnedScriptNoRepeatFor);

INCLUDE_ASM("asm/nonmatchings/game/t_25A428", CFunc_SetSpawnInstanceLimits);

INCLUDE_ASM("asm/nonmatchings/game/t_25A428", CFunc_KillSpawnedScript);

extern "C" int CFunc_UnBlockInterruptedScript(int a, int b) {
    func_0028E6D0(b);
    return 1;
}

INCLUDE_ASM("asm/nonmatchings/game/t_25A428", CFunc_PauseSpawnedScripts);

extern "C" int CFunc_UnPauseSpawnedScripts(void) {
    func_0028CE18(0);
    return 1;
}

INCLUDE_ASM("asm/nonmatchings/game/t_25A428", CFunc_UnPauseSpawnedScript);

INCLUDE_ASM("asm/nonmatchings/game/t_25A428", CFunc_DumpScripts);

extern "C" int CFunc_DumpProxims(void) {
    func_001EB2B0();
    return 1;
}

extern "C" int CFunc_DumpProximTriggers(void) {
    return 0;
}

INCLUDE_ASM("asm/nonmatchings/game/t_25A428", func_0025B238);

INCLUDE_ASM("asm/nonmatchings/game/t_25A428", CFunc_Push);

INCLUDE_ASM("asm/nonmatchings/game/t_25A428", CFunc_Pop);

INCLUDE_ASM("asm/nonmatchings/game/t_25A428", CFunc_CanPop);

INCLUDE_ASM("asm/nonmatchings/game/t_25A428", CFunc_StringLength);

INCLUDE_ASM("asm/nonmatchings/game/t_25A428", CFunc_RequireParams);

INCLUDE_ASM("asm/nonmatchings/game/t_25A428", CFunc_ShortenUIString);

INCLUDE_ASM("asm/nonmatchings/game/t_25A428", CFunc_StringRemoveTrailingWhitespace);

extern "C" int CFunc_ScriptCacheDeleteZeroUsage(void) {
    func_00291900(D_003715D4[0]);
    return 1;
}

INCLUDE_ASM("asm/nonmatchings/game/t_25A428", func_0025BC10);

INCLUDE_ASM("asm/nonmatchings/game/t_25A428", func_0025BD80);

INCLUDE_ASM("asm/nonmatchings/game/t_25A428", func_0025BFB0);

INCLUDE_ASM("asm/nonmatchings/game/t_25A428", func_0025C1C0);
