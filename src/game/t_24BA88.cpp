// cflags: -funroll-loops
#include "common.h"

struct S24B_Script {
    char pad0[0x20];
    int unk20;
    char pad24[0xA0];
    int unkC4;
};

struct S24B_Node {
    char pad0[0x2C];
    int unk2C;
};

struct S24B_Ref {
    int p;
    int unk4;
};

struct S0024C8A8 {
    char pad[0x8];
    int unk8;
};

struct S24B_Obj {
    char pad0[0x14];
    S24B_Obj *next;
    char pad18[0x14];
    int unk2C;
    char pad30[0xA4];
    int unkD4;
};

struct S24B_PBase {
    char pad0[0x18];
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual int Destroy(u32);
};

struct S24B_FBase {
    char pad0[0x8];
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void Kill();
};

struct S24B_FObj {
    char pad0[0xC];
    S24B_FBase *unkC;
    char pad10[0x4];
    S24B_FObj *next;
};

extern "C" {
void func_00113528(char *);
char *func_0030E6D0(char *, int);
void func_002A6B70(char *, int, u32);
extern char D_00370268[];
extern int D_0036D3B0;
S24B_Obj *func_001D4AC0(int, u32);
void func_0016BBC0(int, u32);
void func_001EB1C0(void);
void func_002A6BF0(u32);
u32 func_001150B8(char *);
extern u32 D_00399AA8[15];
extern void* D_0036E010[] __attribute__((section(".sdata")));
int func_001573D8(void);
extern int D_00370EE0[] __attribute__((section(".sdata")));
void func_002754B0(int);
extern int D_00369A4C[] __attribute__((section(".sdata")));
void func_0016BB28(int);
bool func_0027D870(int, u32, void *, int);
int func_0027D1F8(int, u32, void *, int);
int func_0027D188(int, u32, void *, int);
int func_0027D268(int, u32, void *, int);
bool func_0027DF00(int, u32);
void func_00275BD0(u32);
void func_0027C448(int, u32, int);
void func_0027C028(int, u32, char *);
char *func_001133E0(void);
void func_0014F1A0(void);
void func_0022DDB0(bool);
void func_002759F0(bool);
extern int D_0036D410[] __attribute__((section(".sdata")));
int func_001D7EE8(int);
void func_001D62D0(int, int);
extern char D_003702B0[];
void func_0014F1B0(char *, int);
void func_0027C1F8(int, u32, f32);
f32 func_0031B770(f32);
f32 func_0031B870(f32);
f32 func_0031B118(f32);
f32 func_002EC118(f32);
f32 func_002EC100(f32);
f32 func_0031B5C8(f32);
int func_00224220(u32, int);
void func_0027C7D0(int, u32, int);
S24B_Node *func_00289E08(S24B_Script *);
extern int D_0036F658[] __attribute__((section(".sdata")));
void func_0022B0D0(S24B_Ref *, int, u32, int);
void func_00134340(S24B_Ref *);
void func_001D5D28(int, int, int, int);
void func_0027C160(int, u32, int);
int func_0027D400(int, u32, void *, int);
void func_0027ABB0(int, int);
extern char D_00370268[];
void func_00113528(char *);
char *func_0030E6D0(char *, int);
extern u32 D_00399AA8[];
void func_002A6B70(char *, int, u32);
u32 func_001150B8(char *);
}

INCLUDE_ASM("asm/nonmatchings/game/t_24BA88", CFunc_IsInArray);

extern "C" int CFunc_Test(void) {
    return 1;
}

extern "C" int CFunc_DetectOldGlobalReferences(void) {
    return 1;
}

extern "C" int CFunc_EnableLookUpSymbolNotInMainThreadTest(void) {
    return 1;
}

extern "C" int CFunc_SetAsianFontScale(void) {
    return 1;
}

extern "C" int CFunc_EnableDuplicateSymbolWarning(int params) {
    bool off = !func_0027DF00(params, 0xD443A2BC);
    func_0022DDB0(off);
    func_002759F0(!off);
    return 1;
}

extern "C" int CFunc_DumpCompositeObjects(void) {
    return 1;
}

extern "C" int CFunc_ConvertPippedScriptGlobalToModifiable(int params) {
    u32 k = 0;
    func_0027D870(params, 0x17FA747C, &k, 1);
    func_00275BD0(k);
    return 1;
}

extern "C" int CFunc_DestroyAllParticles(void) {
    if (D_00369A4C[0] != 0) {
        func_0016BB28(D_00369A4C[0]);
    }
    return 1;
}

extern "C" int CFunc_DestroyParticlesByGroupID(int params) {
    u32 id = 0;
    func_0027D870(params, 0x87FA53ED, &id, 1);
    if (D_00369A4C[0]) {
        func_0016BBC0(D_00369A4C[0], id);
    }
    for (S24B_Obj *o = func_001D4AC0(D_0036D3B0, 0xA9DB601E); o; o = o->next) {
        ((S24B_PBase *)o)->Destroy(id);
    }
    return 1;
}

extern "C" int CFunc_DestroyAllFastParticles(void) {
    S24B_FObj *o;
    for (o = (S24B_FObj *)func_001D4AC0(D_0036D3B0, 0xC5BCEB9E); o; o = o->next) {
        o->unkC->Kill();
    }
    for (o = (S24B_FObj *)func_001D4AC0(D_0036D3B0, 0xA9DB601E); o; o = o->next) {
        o->unkC->Kill();
    }
    return 1;
}

INCLUDE_ASM("asm/nonmatchings/game/t_24BA88", CFunc_Change);

INCLUDE_ASM("asm/nonmatchings/game/t_24BA88", CFunc_SetEventHandlerOnObject);

extern "C" int CFunc_GetNode(int params, S24B_Script *script) {
    u32 k;
    func_0027D870(params, 0, &k, 1);
    int node = func_00224220(k, 0);
    if (!node) {
        return 0;
    }
    func_0027C7D0(script->unk20, 0x7A8017BA, node);
    return 1;
}

extern "C" int CFunc_GetNodeName(int params, S24B_Script *script) {
    if (func_00289E08(script)) {
        S24B_Node *n = func_00289E08(script);
        if (n && n->unk2C) {
            func_0027C448(script->unk20, 0x9F92BA78, n->unk2C);
            return 1;
        }
    }
    return 0;
}

extern "C" int CFunc_GetTriggerNodeName(int params, S24B_Script *script) {
    if (script->unkC4) {
        func_0027C448(script->unk20, 0x9F92BA78, script->unkC4);
        return 1;
    }
    return 0;
}

extern "C" int CFunc_GetNodeProfileInfo(int params, S24B_Script *script) {
    u32 k;
    func_0027D870(params, 0x7A8017BA, &k, 1);
    int node = func_00224220(k, 1);
    if (node) {
        int s = 0;
        if (func_0027D400(node, 0x7EA855F0, &s, 0)) {
            int out = script->unk20;
            if (s) {
                func_0027ABB0(out, s);
            }
            return 1;
        }
    }
    return 0;
}

extern "C" int CFunc_InitCOIM(int params) {
    int a = 0;
    int b = 0;
    func_0027D1F8(params, 0x083FDB95, &a, 1);
    func_0027D1F8(params, 0xB0847D54, &b, 1);
    func_001D5D28(D_0036D410[0], a, b, params);
    return 1;
}

extern "C" int CFunc_ReserveCOIMBlocksForPermObjects(int params) {
    int n;
    func_0027D1F8(params, 0, &n, 1);
    int m = D_0036D410[0];
    int cnt = n;
    func_001D62D0(func_001D7EE8(m), cnt);
    return 1;
}

extern "C" int CFunc_IsCOIMInited(void) {
    return 1;
}

INCLUDE_ASM("asm/nonmatchings/game/t_24BA88", func_0024C810);

extern "C" int CFunc_ProximCleanup(void) {
    S24B_Obj *o;
    for (o = func_001D4AC0(D_0036D3B0, 0x07713C7B); o; o = o->next) {
        o->unkD4 = 0;
    }
    for (o = func_001D4AC0(D_0036D3B0, 0x0F1641E3); o; o = o->next) {
        o->unk2C = 0;
    }
    func_001EB1C0();
    return 1;
}

extern "C" int CFunc_Inside(void) {
    return ((S0024C8A8*)D_0036E010[0])->unk8;
}

extern "C" int CFunc_LoadQB(int params) {
    struct {
        u32 x;
        char *name;
    } a;
    a.x = 0x0FA33D9B;
    a.name = 0;
    func_0027D188(params, 0, &a.name, 0);
    func_0027D870(params, 0x42D6DD1E, &a.x, 0);
    if (func_0027DF00(params, 0x6DD1DECF)) {
        u32 *p = D_00399AA8;
        for (int i = 0; i < 15; i++) {
            if (*p == 0) {
                *p = func_001150B8(a.name);
                break;
            }
            p++;
        }
        func_002A6B70(a.name, 1, a.x);
    } else {
        func_002A6B70(a.name, 0, a.x);
    }
    return 1;
}

extern "C" int CFunc_UnloadQB(int params) {
    char *name = 0;
    func_0027D188(params, 0, &name, 0);
    u32 k = func_001150B8(name);
    func_002A6BF0(k);
    for (int i = 0; i < 15; i++) {
        if (k == D_00399AA8[i]) {
            D_00399AA8[i] = 0;
        }
    }
    return 1;
}

extern "C" int CFunc_ScreenShot(int params) {
    char *name;
    if (!func_0027D188(params, 0xC3F4169A, &name, 0)) {
        name = D_003702B0;
    }
    func_0014F1B0(name, 0);
    return 1;
}

extern "C" int CFunc_ResetEngine(void) {
    func_002754B0(D_00370EE0[0]);
    return 1;
}

extern "C" int CFunc_ToggleMetrics(int params) {
    int x;
    if (!func_0027D1F8(params, 0x6835B854, &x, 0)) {
        func_0014F1A0();
    }
    return 1;
}

extern "C" int CFunc_GetMetricsMode(void) {
    return 1;
}

extern "C" int CFunc_IsTextureInDictionary(int params) {
    u32 name = 0;
    func_0027D870(params, 0x7D99F28D, &name, 0);
    S24B_Ref ref;
    func_0022B0D0(&ref, D_0036F658[0], name, 0);
    int r = ref.p != 0;
    func_00134340(&ref);
    return r;
}

INCLUDE_ASM("asm/nonmatchings/game/t_24BA88", CFunc_GetRelativePath);

extern "C" int CFunc_GetFileNameFromPath(int params, S24B_Script *script) {
    char *path = D_00370268;
    func_0027D188(params, 0xF4AB74F0, &path, 1);
    func_00113528(path);
    char *s = func_0030E6D0(path, '\\');
    if (!s) {
        s = func_0030E6D0(path, '/');
        if (!s) {
            func_0027C028(script->unk20, 0xC3F4169A, path);
        } else {
            func_0027C028(script->unk20, 0xC3F4169A, s + 1);
        }
    } else {
        func_0027C028(script->unk20, 0xC3F4169A, s + 1);
    }
    return 1;
}

extern "C" int CFunc_LoadDBG(void) {
    return 1;
}

extern "C" int CFunc_GetCCallstack(void) {
    return 0;
}

INCLUDE_ASM("asm/nonmatchings/game/t_24BA88", CFunc_StringRemove);

INCLUDE_ASM("asm/nonmatchings/game/t_24BA88", CFunc_DisplayLoadingScreen);

extern "C" int CFunc_HideLoadingScreen(void) {
    func_001573D8();
    return 1;
}

extern "C" int CFunc_InitFileCache(void) {
    return 1;
}

extern "C" int CFunc_CachePlatFile(void) {
    return 1;
}

extern "C" int CFunc_CacheFile(void) {
    return 1;
}

extern "C" int CFunc_IsFileCached(void) {
    return 1;
}

extern "C" int CFunc_WaitForFileCache(void) {
    return 1;
}

extern "C" int CFunc_IsFileCacheFinished(void) {
    return 1;
}

extern "C" int CFunc_ResizeFileCacheStreamBuff(void) {
    return 1;
}

extern "C" int CFunc_ToggleFileCaching(void) {
    return 1;
}

extern "C" int CFunc_GetBuildVersion(int params, S24B_Script *script) {
    int s = script->unk20;
    func_0027C028(s, 0xA2982417, func_001133E0());
    return 1;
}

INCLUDE_ASM("asm/nonmatchings/game/t_24BA88", func_0024D060);

INCLUDE_ASM("asm/nonmatchings/game/t_24BA88", func_0024D068);

INCLUDE_ASM("asm/nonmatchings/game/t_24BA88", func_0024D128);

extern "C" int CFunc_Sin(int params, S24B_Script *script) {
    f32 v;
    func_0027D268(params, 0, &v, 1);
    func_0027C1F8(script->unk20, 0x483C6C55, func_002EC100(v * 0.0174532942f));
    return 1;
}

extern "C" int CFunc_Cos(int params, S24B_Script *script) {
    f32 v;
    func_0027D268(params, 0, &v, 1);
    func_0027C1F8(script->unk20, 0x6146047A, func_002EC118(v * 0.0174532942f));
    return 1;
}

extern "C" int CFunc_Tan(int params, S24B_Script *script) {
    f32 v;
    func_0027D268(params, 0, &v, 1);
    func_0027C1F8(script->unk20, 0x85AAF0D8, func_0031B5C8(v * 0.0174532942f));
    return 1;
}

extern "C" int CFunc_ASin(int params, S24B_Script *script) {
    f32 v;
    func_0027D268(params, 0, &v, 1);
    func_0027C1F8(script->unk20, 0x15A3FA3D, func_0031B870(v) * 57.2957764f);
    return 1;
}

extern "C" int CFunc_ACos(int params, S24B_Script *script) {
    f32 v;
    func_0027D268(params, 0, &v, 1);
    func_0027C1F8(script->unk20, 0x3CD99212, func_0031B770(v) * 57.2957764f);
    return 1;
}

extern "C" int CFunc_ATan(int params, S24B_Script *script) {
    f32 v;
    func_0027D268(params, 0, &v, 1);
    func_0027C1F8(script->unk20, 0xD83566B0, func_0031B118(v) * 57.2957764f);
    return 1;
}

INCLUDE_ASM("asm/nonmatchings/game/t_24BA88", CFunc_Sqrt);

extern "C" int CFunc_Mod(int params, S24B_Script *script) {
    int a;
    int b;
    func_0027D1F8(params, 0x174841BC, &a, 1);
    func_0027D1F8(params, 0x8E411006, &b, 1);
    func_0027C160(script->unk20, 0xE80BACB7, a % b);
    return 1;
}

INCLUDE_ASM("asm/nonmatchings/game/t_24BA88", CFunc_NormalizeVector);

INCLUDE_ASM("asm/nonmatchings/game/t_24BA88", CFunc_GetVectorComponents);

INCLUDE_ASM("asm/nonmatchings/game/t_24BA88", CFunc_SetVectorComponents);

INCLUDE_ASM("asm/nonmatchings/game/t_24BA88", CFunc_GetAngle);

INCLUDE_ASM("asm/nonmatchings/game/t_24BA88", CFunc_RotateVector);
