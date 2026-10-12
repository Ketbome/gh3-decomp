#include "common.h"

struct S25A_Script {
    char pad0[0x20];
    int unk20;
};

extern "C" {
bool func_0027D870(int, u32, void *, int);
bool func_0027D400(int, u32, void *, int);
bool func_0027D470(int, u32, void *, int);
int func_0027D1F8(int, u32, void *, int);
int func_0027D188(int, u32, void *, int);
int func_0027CC30(int, u32, int, void *);
bool func_0027DF00(int, u32);
int func_0027DD88(int, u32);
void func_0027C160(int, u32, int);
void func_0028CE90(u32);
void func_0028CF18(void *);
void func_0028DC28(int);
void func_0028E220(void *, u32, int);
void func_0028D668(u32);
void func_0028D720(u32);
int func_00113900(char *);
int func_0014F748(void);
void func_0014F740(int);
extern u32 D_00372E70;
void func_0014F7B8(void);
int func_0025AA28(int, int, int);
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

extern "C" int CFunc_OnExitRun(int params, void *script) {
    u32 a = 0;
    func_0027D870(params, 0, &a, 0);
    int b = 0;
    func_0027D400(params, 0x7031F10C, &b, 0);
    func_0028E220(script, a, b);
    return 1;
}

extern "C" int CFunc_StopAllScripts(void) {
    func_0028DAD8();
    return 1;
}

GP_DATA(D_00370540);
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

extern "C" int CFunc_Toggle2d(int params) {
    int old = func_0014F748();
    if (func_0027DD88(params, 0xF649D637)) {
        func_0014F740(1);
    } else if (func_0027DD88(params, 0xD443A2BC)) {
        func_0014F740(0);
    } else {
        func_0014F740(func_0014F748() == 0);
    }
    return old;
}

INCLUDE_ASM("asm/nonmatchings/game/t_25A428", CFunc_SetScriptWarningLevel);

INCLUDE_ASM("asm/nonmatchings/game/t_25A428", func_0025AA28);

extern "C" int CFunc_SpawnScript(int params, int script) {
    int f = 0;
    func_0027D1F8(params, 0xEE67888A, &f, 0);
    return func_0025AA28(params, script, f != 0);
}

extern "C" void CFunc_SpawnScriptNow(int a, int b) {
    func_0025AA28(a, b, 1);
}

extern "C" void CFunc_SpawnScriptLater(int a, int b) {
    func_0025AA28(a, b, 0);
}

INCLUDE_ASM("asm/nonmatchings/game/t_25A428", CFunc_SetSpawnedScriptNoRepeatFor);

INCLUDE_ASM("asm/nonmatchings/game/t_25A428", CFunc_SetSpawnInstanceLimits);

extern "C" int CFunc_KillSpawnedScript(int params) {
    u32 id;
    if (func_0027D870(params, 0xA1DC81F9, &id, 0)) {
        func_0028D668(id);
        return 1;
    }
    u32 n;
    if (func_0027D870(params, 0x40C698AF, &n, 0)) {
        func_0028D720(n);
        return 1;
    }
    return 1;
}

extern "C" int CFunc_UnBlockInterruptedScript(int a, int b) {
    func_0028E6D0(b);
    return 1;
}

extern "C" int CFunc_PauseSpawnedScripts(int params, void *script) {
    func_0028CE18(1);
    func_0028CF18(script);
    return 1;
}

extern "C" int CFunc_UnPauseSpawnedScripts(void) {
    func_0028CE18(0);
    return 1;
}

extern "C" int CFunc_UnPauseSpawnedScript(int params) {
    u32 id;
    func_0027D870(params, 0, &id, 1);
    func_0028CE90(id);
    return 1;
}

extern "C" int CFunc_DumpScripts(int params) {
    if (!func_0027DF00(params, 0x202ED1B4)) {
        func_0028DC28(func_0027DF00(params, 0x2AB71EEF));
    }
    return 1;
}

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

extern "C" int CFunc_StringLength(int params, S25A_Script *script) {
    int n = 0;
    int tmp;
    if (func_0027CC30(params, 0x61414D56, 3, &tmp)) {
        char *s = 0;
        func_0027D188(params, 0x61414D56, &s, 0);
        n = func_00113900(s);
    }
    func_0027C160(script->unk20, 0xCC91E842, n);
    return 1;
}

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
