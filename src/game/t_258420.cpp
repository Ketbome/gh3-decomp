#include "common.h"

struct S258_Arr {
    char pad0[2];
    u8 unk2;
    char pad3[1];
    int unk4;
    int unk8;
};

struct S2584_Range {
    u8 unk0;
    u8 unk1;
    f32 unk4;
    f32 unk8;
};

struct S00259228 {
    char pad[0x20];
    int unk20;
};

extern "C" {
void *func_001287F0(int, int);
void *func_0027AA98(void *, int);
void func_0027C448_p(void *, u32, u32) asm("func_0027C448");
void func_00289FB0(void *, int);
void func_0027AC90(void *);
void func_00113250(void *);
void func_0028DCF8(void *, u32, u32, u32, int, int, int);
bool func_0027D400_b(int, u32, int *, int) asm("func_0027D400");
void *func_002899B0(void *);
int func_0028C590(void *, u32);
void func_0028DE38(void *, u32);
bool func_0027D870_b(int, u32, u32 *, int) asm("func_0027D870");
u32 func_001150E0(u32, int);
void func_0028A2D0(void *, u32, int, int);
int func_00289E08(void *);
int func_002764E8(u32, int);
void func_0028DE68(void *, int, u32);
int func_0027CC30(int, u32, int, void *);
extern char D_003704B8[];
void strcpy(char *, char *);
void func_00113528(char *);
void func_001135A0(char *);
int func_0027D1F8(int, u32, int *, int);
int func_0027D870(int, u32, u32 *, int);
int func_0027D188(int, u32, int *, int);
extern int D_00370534;
void func_0028DDE8(void *, u32);
void func_00275648(S2584_Range *);
int func_0027DD38(int, u32, S2584_Range *, int);
void func_0027C448(int, u32, u32);
int func_0027DD88(int, u32);
void func_0028E210(void *, u32);
int func_0027D400(int, u32, int *, int);
void func_0027C028(int, u32, int);
void func_0027F1E0(int, int, int);
int func_0028A010(int);
int func_0028A018(int);
void func_00258E28(int, int);
int func_0027DF00(int, u32);
extern int D_00368428[] __attribute__((section(".sdata")));
void func_002592E0(void*, int, int, int);
int func_0027D470(int, int, void*, int);
void func_0027ACF8(int, u32);
S258_Arr *func_00256848(int, S00259228 *, int);
int func_0010C050(int);
void func_0027C160(int, u32, int);
void func_0027C7D0(int, u32, int);
void func_0027C678(int, u32, int);
f32 func_0027EFA0(S258_Arr *, int);
void func_0027C1F8(int, u32, f32);
}

static inline int Elem258(S258_Arr *e, int i) {
    int r;
    if (e->unk4 == 1) {
        r = e->unk8;
    } else {
        r = ((int *)e->unk8)[i];
    }
    return r;
}

INCLUDE_ASM("asm/nonmatchings/game/t_258420", CFunc_GetRandomArrayElement);

INCLUDE_ASM("asm/nonmatchings/game/t_258420", CFunc_PermuteArray);

extern "C" int CFunc_GotParam(int params, S00259228 *script) {
    u32 n = 0;
    func_0027D870(params, 0, &n, 1);
    return func_0027DD88(script->unk20, n) != 0;
}

extern "C" int CFunc_Goto(int params, void *script) {
    u32 name;
    int s;
    func_0027D870(params, 0, &name, 0);
    s = 0;
    func_0027D400(params, 0x7031F10C, &s, 0);
    func_0028A2D0(script, name, s, func_00289E08(script));
    return 1;
}

INCLUDE_ASM("asm/nonmatchings/game/t_258420", func_00258A00);

INCLUDE_ASM("asm/nonmatchings/game/t_258420", func_00258E28);

extern "C" int CFunc_FormatText(int a, S00259228* b) {
    func_00258E28(b->unk20, a);
    return 1;
}

extern "C" int CFunc_ExtendCrc(int params, S00259228 *script) {
    u32 crc;
    int str = 0;
    u32 name;
    func_0027D870(params, 0, &crc, 0);
    func_0027D188(params, 0, &str, 1);
    func_0027D870(params, 0x46159266, &name, 1);
    u32 h = func_001150E0(crc, str);
    func_0027C448(script->unk20, name, h);
    return 1;
}

INCLUDE_ASM("asm/nonmatchings/game/t_258420", func_002592E0);

GP_DATA(D_00370534);
extern "C" int CFunc_EnableScriptPrintf(int params) {
    int v = 1;
    func_0027D1F8(params, 0, &v, 0);
    D_00370534 = v != 0;
    return 1;
}

extern "C" int CFunc_Printf(void) {
    return 1;
}

extern "C" int CFunc_SetGlobalPrintfEnabledStatus(int a) {
    D_00368428[0] = func_0027DF00(a, 0x203B372);
    return 1;
}

extern "C" int CFunc_PrintStruct(void) {
    return 1;
}

INCLUDE_ASM("asm/nonmatchings/game/t_258420", CFunc_Dump);

extern "C" int CFunc_ScriptAssert(int params, S00259228 *script) {
    char buf[0x400];
    func_0027F1E0(script->unk20, 2, 1);
    func_002592E0(buf, 0x400, params, (int)script);
    return 1;
}

extern "C" int CFunc_SoftAssert(int a, int b) {
    char buf[0x400];
    func_002592E0(buf, 0x400, a, b);
    return 1;
}

extern "C" int CFunc_ScriptUsageSoftAssert(void) {
    return 1;
}

extern "C" int CFunc_PrintScriptInfo(void) {
    return 1;
}

extern "C" int CFunc_IfDebugOn(int a, int b) {
    func_0028A010(b);
    return 1;
}

extern "C" int CFunc_IfDebugOff(int a, int b) {
    func_0028A018(b);
    return 1;
}

extern "C" int CFunc_StructureContains(int params, S00259228 *script) {
    int st = 0;
    u32 n;
    u32 k;
    bool missing = !func_0027D400_b(params, 0x90FEC815, &st, 0);
    if (missing) {
        bool ok = 0;
        if (func_0027D870(params, 0x90FEC815, &n, 0)) {
            ok = script->unk20 != 0;
        }
        if (ok) {
            func_0027D400(script->unk20, n, &st, 0);
        }
    }
    if (st) {
        if (!func_0027D870(params, 0xA1DC81F9, &k, 0)) {
            func_0027D870(params, 0, &k, 0);
        }
        if (func_0027DD88(st, k)) {
            return 1;
        }
        return func_0027DF00(st, k);
    }
    return 0;
}

extern "C" int CFunc_MangleChecksums(int params, S00259228 *script) {
    int sub = 0;
    u32 a;
    u32 b;
    func_0027D1F8(params, 0xDEA7E576, &sub, 0);
    bool missing = !func_0027D870_b(params, 0x174841BC, &a, 0);
    if (missing) {
        func_0027D1F8(params, 0x174841BC, (int *)&a, 1);
    }
    missing = !func_0027D870_b(params, 0x8E411006, &b, 0);
    if (missing) {
        func_0027D1F8(params, 0x8E411006, (int *)&b, 1);
    }
    func_0027C448(script->unk20, 0xFBA40626, sub ? a - b : a + b);
    return 1;
}

extern "C" int CFunc_AppendSuffixToChecksum(int params, S00259228 *script) {
    u32 c;
    int s;
    func_0027D870(params, 0x3F4B019E, &c, 1);
    func_0027D188(params, 0x94542EEA, &s, 1);
    int d = script->unk20;
    func_0027C448(d, 0xAFB911C6, func_001150E0(c, s));
    return 1;
}

extern "C" int CFunc_GetUpperCaseString(int params, S00259228 *script) {
    char buf[0x80];
    char *v;
    char *s;
    if (func_0027CC30(params, 0, 3, &v)) {
        s = D_003704B8;
        if (func_0027D188(params, 0, (int *)&s, 1)) {
            strcpy(buf, s);
            func_001135A0(buf);
            func_0027C028(script->unk20, 0xFE366B7B, (int)buf);
        }
    }
    return 1;
}

extern "C" int CFunc_GetLowerCaseString(int params, S00259228 *script) {
    char buf[0x80];
    char *v;
    char *s;
    if (func_0027CC30(params, 0, 3, &v)) {
        s = D_003704B8;
        if (func_0027D188(params, 0, (int *)&s, 1)) {
            strcpy(buf, s);
            func_00113528(buf);
            func_0027C028(script->unk20, 0x81736D99, (int)buf);
        }
    }
    return 1;
}

extern "C" int CFunc_GenerateUTF16FromASCII(int params, S00259228 *script) {
    int str = 0;
    func_0027D188(params, 0x61414D56, &str, 1);
    func_0027C028(script->unk20, 0x667EBDEF, str);
    return 1;
}

INCLUDE_ASM("asm/nonmatchings/game/t_258420", CFunc_ScriptExists);

INCLUDE_ASM("asm/nonmatchings/game/t_258420", CFunc_SymbolIsCFunc);

extern "C" int CFunc_ScriptIsRunning(int params) {
    u32 id = 0;
    void *p;
    func_0027D870(params, 0, &id, 0);
    for (p = func_002899B0(0); p; p = func_002899B0(p)) {
        if (func_0028C590(p, id)) {
            return 1;
        }
    }
    return 0;
}

extern "C" int CFunc_IsArray(int a) {
    int x = 0;
    return func_0027D470(a, 0, &x, 0) != 0;
}

INCLUDE_ASM("asm/nonmatchings/game/t_258420", func_00259E40);

extern "C" int CFunc_IsPair(int params) {
    S2584_Range r;
    func_00275648(&r);
    return func_0027DD38(params, 0, &r, 0) != 0;
}

extern "C" int CFunc_IsStructure(int params, S00259228 *script) {
    u32 n;
    int s;
    func_0027D870(params, 0, &n, 0);
    s = 0;
    return func_0027D400(script->unk20, n, &s, 0) != 0;
}

extern "C" int CFunc_Block(int params, void *script) {
    u32 type;
    void *st = 0;
    if (func_0027D870(params, 0x2C3A27A4, &type, 0)) {
        st = func_0027AA98(func_001287F0(8, 1), params);
        func_0027C448_p(st, 0x7321A8D6, type);
    }
    if (st) {
        func_00289FB0(script, (int)st);
        func_0027AC90(st);
        func_00113250(st);
    } else {
        func_00289FB0(script, params);
    }
    return 1;
}

extern "C" int CFunc_IsTrue(int params) {
    int v = 0;
    func_0027D1F8(params, 0, &v, 0);
    return v != 0;
}

extern "C" int CFunc_AddFlag(int params, S00259228 *script) {
    u32 f;
    func_0027D870(params, 0, &f, 0);
    func_0027C448(script->unk20, 0, f);
    return 1;
}

INCLUDE_ASM("asm/nonmatchings/game/t_258420", CFunc_CleanUpAndRemoveSymbol);

INCLUDE_ASM("asm/nonmatchings/game/t_258420", CFunc_SetEventHandler);

extern "C" int CFunc_SetExceptionHandler(int params, void *script) {
    u32 a = 0;
    u32 b;
    u32 g;
    int p;
    func_0027D870(params, 0xF8728BEC, &a, 1);
    u32 x = a;
    b = 0;
    func_0027D870(params, 0xA6D2D890, &b, 1);
    u32 y = b;
    g = 0x1CA1FF20;
    func_0027D870(params, 0x923FBB3A, &g, 0);
    p = 0;
    func_0027D400(params, 0x7031F10C, &p, 0);
    func_0028DCF8(script, x, y, g, 1, 0, p);
    return 1;
}

extern "C" int CFunc_ResetEventHandlersFromTable(int params, void *script) {
    u32 t;
    u32 g;
    func_0027D870(params, 0, &t, 1);
    int x = func_002764E8(t, 0);
    g = 0x1CA1FF20;
    func_0027D870(params, 0x923FBB3A, &g, 0);
    func_0028DE68(script, x, g);
    return 1;
}

extern "C" int CFunc_ClearEventHandler(int params, void *script) {
    u32 t;
    func_0027D870(params, 0, &t, 1);
    func_0028DDE8(script, t);
    return 1;
}

extern "C" int CFunc_ClearEventHandlerGroup(int params, void *script) {
    u32 g = 0x1CA1FF20;
    bool missing = !func_0027D870_b(params, 0, &g, 0);
    if (missing) {
        func_0027D870(params, 0x923FBB3A, &g, 0);
    }
    func_0028DE38(script, g);
    return 1;
}

extern "C" int CFunc_OnExceptionRun(int params, void *script) {
    u32 n = 0;
    func_0027D870(params, 0, &n, 0);
    func_0028E210(script, n);
    return 1;
}
