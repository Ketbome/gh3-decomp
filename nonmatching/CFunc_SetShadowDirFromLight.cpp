#include "common.h"

asm(".set D_0036CDB4_lui, D_0036CDB4");
asm(".set D_0036F658_lui, D_0036F658");

struct S250_Tex {
    char pad0[0x34];
    virtual void v1();
    virtual int v2();
};

struct S250_Ref {
    S250_Tex *p;
    int unk4;
};

struct S250_Node {
    int unk0;
    int unk4;
    int unk8;
    S250_Node *unkC;
};

typedef unsigned int u128_250 __attribute__((mode(TI)));

struct S250_Vec {
    f32 x __attribute__((aligned(16)));
    f32 y, z, w;
};

struct S250_Light {
    char pad0[0x10];
    S250_Vec unk10;
    S250_Vec unk20;
    char pad30[0x4];
    int unk34;
    char pad38[0x8];
    f32 unk40;
    char pad44[0xC];
    S250_Vec unk50;
};

struct S250_Obj {
    char pad0[0x1C];
    S250_Light *unk1C;
};

struct S250_Group {
    char pad0[0x94];
    f32 unk94;
};

struct S250_Script {
    char pad0[0x20];
    int unk20;
};

struct S250_Cam {
    char pad0[0x308];
    int unk308;
};

struct S250_Key {
    int type;
    u32 id;
};

extern "C" {
void func_0027ACF8(void *, u32);
void func_001E1378(int, u32, void *, u32, S250_Key);
int func_0014F150(void);
int func_002A3EA0(void);
extern char D_00355EA0[];
extern char D_00355EB0[];
void func_00250A18(int, int, void*);
bool func_0027D870(int, u32, void*, int);
int func_0027D1F8(int, u32, void*, int);
int func_0027D2D8(int, u32, void*, int);
extern int D_0036D3B0;
int func_001D8618(int, u32);
S250_Obj *func_001D1CF8(int, u32);
S250_Group *func_001566B8(u32);
u128_250 func_00251198(int);
extern u128_250 D_00378210[];
u32 func_00251358(u32);
void func_0027C1F8(int, u32, f32);
void func_0027C4D8(int, u32, f32, f32, f32);
void func_001F3A40(S250_Obj *, int, int);
void func_00156470(S250_Group *, int);
void func_00156550(S250_Group *, S250_Light *);
int func_001565D0(int);
void func_001F56E8(S250_Obj *, int, int);
void func_0014ED20(bool);
void *func_001287F0(int, int);
void *func_0027AA98(void *, int);
void func_00251CA0(u32, void *);
void func_0027AC90(void *);
void func_00113250(void *);
extern S250_Cam *D_0036CDB4[] asm("D_0036CDB4_lui") __attribute__((section(".sdata")));
extern S250_Cam *D_0036CDB4_gp asm("D_0036CDB4");
void func_001E12A8(int);
void func_001E1220(int);
void func_001E1308(int, u32);
int func_001E1978(int, u32, int);
int func_001E12E8(int, u32 *);
bool func_001E1650(int, int);
void func_0028C9D0(u32, int, int, int, int, int);
extern int D_0036F658_lui[] asm("D_0036F658_lui") __attribute__((section(".sdata")));
extern int D_0036F658;
extern int D_00372B88;
int func_0015B2F0(int, char *);
int func_0015B268(int, u32);
u32 CrcFromPathLowercase(char *);
void func_0022ADD0(int, S250_Ref *);
void func_0022B0D0(S250_Ref *, int, u32, int);
void func_00134340(S250_Ref *);
int func_0027D268(int, u32, void*, int);
void func_001563D0(S250_Group *, f32);
void func_00154900(int, int, int);
S250_Node *func_0014E948(void);
void func_0024FAD8(int, f32);
int func_0014F8A8(void);
int func_0014F8C8(void);
int func_0014F8E8(void);
void func_0027C160(int, u32, int);
void func_0027CB80(int, u32, int);
int func_0027D188(int, u32, void*, int);
extern char D_00370398[];
void func_0030B550(char *, char *, char *);
void func_00123F18(char *, int);
void func_00123EB8(char *, int);
bool func_0027DF00(int, u32);
void func_0027AE70(void *, u32);
void func_00251F68(int);
u32 strlen(char *);
char *func_0027D828(int, u32);
extern char D_00355E70[];
extern char D_00355E78[];
void memset(void *, int, int);
char *func_0030A684(char *, int);
void strcpy(char *, char *);
void func_00275080(char *);
void func_0015DCB0(f32);
void func_0015DCD0(f32);
void func_0014F708(bool);
extern int D_0036CA30[] __attribute__((section(".sdata")));
}

extern "C" int CFunc_NudgeVC(int params) {
    f32 v = 0.0f;
    func_0027D268(params, 0x9E497FC6, &v, 1);
    v *= 0.01f;
    S250_Node *cur = func_0014E948();
    while (cur) {
        S250_Node *next = cur->unkC;
        if (next->unk4 == -1) {
            next = 0;
        }
        func_0024FAD8(cur->unk4, v);
        cur = next;
    }
    return 1;
}

extern "C" int CFunc_InitAnimCompressTable(int params) {
    char buf[0x100];
    char *name;
    u32 type;
    func_0027D188(params, 0, &name, 1);
    func_0027D870(params, 0, &type, 1);
    func_0030B550(buf, D_00370398, name);
    switch (type) {
    case 0xC6A56FE3:
        func_00123EB8(buf, 1);
        break;
    case 0xC06EAD08:
        func_00123F18(buf, 1);
        break;
    }
    return 1;
}

INCLUDE_ASM("asm/nonmatchings/game/t_250010", CFunc_InitAnimSystem);

INCLUDE_ASM("asm/nonmatchings/game/t_250010", CFunc_UpdateAnimCache);

INCLUDE_ASM("asm/nonmatchings/game/t_250010", CFunc_GetAnimCacheState);

extern "C" int CFunc_FinishRendering(void) {
    func_0014F150();
    return 1;
}

extern "C" int CFunc_TogglePass(void) {
    return 1;
}

extern "C" int CFunc_SetScreen(int params) {
    f32 a;
    if (func_0027D268(params, 0x0F7C3CAA, &a, 0)) {
        func_0015DCB0(a);
    }
    f32 b;
    if (func_0027D268(params, 0xFF7EBAF6, &b, 0)) {
        func_0015DCD0(b);
    }
    int c;
    if (func_0027D1F8(params, 0xD4328DD3, &c, 0)) {
        func_0014F708(c != 0);
    }
    func_0027D1F8(params, 0x3C57F851, &c, 0);
    int d = 0;
    if (func_0027D1F8(params, 0x1B813307, &d, 0)) {
        D_0036CA30[0] = d != 0;
    }
    return 1;
}

extern "C" int CFunc_AllowBoneLOD(int params) {
    int v = 1;
    func_0027D1F8(params, 0x81B6BF17, &v, 0);
    func_0014ED20(v > 0);
    return 1;
}

extern "C" int CFunc_PreLoadMovie(void) {
    return 0;
}

extern "C" int CFunc_StartPreLoadedMovie(void) {
    return 0;
}

extern "C" int CFunc_IsMoviePreLoaded(void) {
    return 0;
}

extern "C" int CFunc_PlayMovie(int params) {
    char *name = func_0027D828(params, 0xE2A10D90);
    char buf[32];
    buf[0] = D_00355E70[0];
    memset(buf + 1, 0, 31);
    if (!name) {
        return 0;
    }
    if (strlen(name) > 8) {
        char *u = func_0030A684(name, '_');
        if (u) {
            strcpy(name - (strlen(u) - 8), u);
        } else {
            name[8] = 0;
        }
    }
    func_0030B550(buf, D_00355E78, name);
    func_00275080(buf);
    return 1;
}

extern "C" int CFunc_KillMovie(void) {
    return 0;
}

extern "C" int CFunc_PauseMovie(void) {
    return 0;
}

extern "C" int CFunc_ResumeMovie(void) {
    return 0;
}

extern "C" int CFunc_SeekMovie(void) {
    return 0;
}

extern "C" int CFunc_StopLoopingAndFinishMovie(void) {
    return 0;
}

extern "C" int CFunc_IsMoviePlaying(void) {
    return 0;
}

extern "C" char *func_002509A0(char *path) {
    int i;
    for (i = strlen(path); i > 0; i--) {
        if (path[i - 1] == '\\' || path[i - 1] == '/') {
            break;
        }
    }
    return path + i;
}

INCLUDE_ASM("asm/nonmatchings/game/t_250010", func_00250A18);

extern "C" void CFunc_LoadTexture(int a) {
    func_00250A18(a, 0, D_00355EA0);
}

extern "C" int CFunc_UnloadTexture(int params) {
    char *name;
    u32 cs;
    u32 key = 0;
    int tex = 0;
    if (func_0027D188(params, 0, &name, 0)) {
        tex = func_0015B2F0(D_00372B88, name);
        key = CrcFromPathLowercase(func_002509A0(name));
    } else if (func_0027D870(params, 0, &cs, 0)) {
        tex = func_0015B268(D_00372B88, cs);
        key = cs;
    }
    if (tex) {
        int mgr = D_0036F658;
        S250_Ref ref;
        func_0022B0D0(&ref, mgr, key, 1);
        func_0022ADD0(mgr, &ref);
        func_00134340(&ref);
    }
    return 1;
}

INCLUDE_ASM("asm/nonmatchings/game/t_250010", func_00250C30);

INCLUDE_ASM("asm/nonmatchings/game/t_250010", CFunc_DrawDirectionalLightLines);

extern "C" int CFunc_IsTextureLoaded(int params) {
    u32 name = 0;
    func_0027D870(params, 0x40C698AF, &name, 1);
    S250_Ref ref;
    func_0022B0D0(&ref, D_0036F658_lui[0], name, 0);
    int r;
    if (ref.p) {
        r = ref.p->v2();
    } else {
        r = 0;
    }
    func_00134340(&ref);
    return r != 0;
}

extern "C" int CFunc_SetShadowMapParams(void) {
    return 0;
}

extern "C" S250_Obj *func_00250FF0(int params) {
    u32 id = 0;
    bool missing = !func_0027D870(params, 0xA1DC81F9, &id, 0);
    if (missing) {
        int n = 0;
        if (func_0027D1F8(params, 0xA1DC81F9, &n, 0)) {
            id = n;
        }
    }
    if (id) {
        int r = func_001D8618(D_0036D3B0, id);
        if (r) {
            return func_001D1CF8(r, 0xD8BFC9F7);
        }
        return 0;
    }
    return 0;
}

extern "C" S250_Group *func_00251090(int params, u32 *pkey) {
    u32 id = 0;
    u32 key = *pkey;
    bool missing = !func_0027D870(params, key, &id, 0);
    if (missing) {
        int n = 0;
        if (func_0027D1F8(params, key, &n, 0)) {
            id = n;
        }
    }
    if (id) {
        return func_001566B8(id);
    }
    return 0;
}

extern "C" int CFunc_InitLightManager(int params) {
    int a = 0;
    int b = 0;
    int c = 0;
    func_0027D1F8(params, 0x50228D9E, &a, 1);
    func_0027D1F8(params, 0x701C70AC, &b, 1);
    func_0027D1F8(params, 0xD6FDDA8C, &c, 0);
    func_00154900(a, b, c);
    return 1;
}

INCLUDE_ASM("asm/nonmatchings/game/t_250010", func_00251198);

extern "C" int CFunc_SetShadowDir(int params) {
    D_00378210[0] = func_00251198(params);
    return 1;
}

extern "C" int CFunc_SetShadowDirFromLight(int params) {
    S250_Obj *o = func_00250FF0(params);
    if (o) {
        S250_Light *light = o->unk1C;
        u128_250 v;
        int d;
        asm("lqc2 $vf1, 0(%1)" : "=r"(d) : "r"(&v), "r"(func_0027D2D8(params, 0x7F261953, &v, 0)));
        if (d) {
            asm("lqc2 $vf2, 0x10(%1)\n\tvsub.xyzw $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%2)" : "+r"(d) : "r"(light), "r"(&v));
        } else {
            v = *(u128_250 *)&light->unk20;
        }
        asm("lqc2 $vf2, 0(%1)" : "+r"(d) : "r"(&v));
        asm("vmul.xyzw $vf3, $vf2, $vf2" : "+r"(d));
        asm("vaddy.x $vf1, $vf3, $vf3y" : "+r"(d));
        asm("vaddz.x $vf1, $vf1, $vf3z\n\tnop\n\tnop\n\tvrsqrt $Q, $vf0w, $vf1x\n\tvwaitq\n\tvmulq.xyz $vf2, $vf2, $Q" : "+r"(d));
        asm("sqc2 $vf2, 0(%1)\n\tsqc2 $vf2, 0(%2)" : : "r"(d), "r"(D_00378210), "r"(&v));
        return 1;
    }
    return 0;
}

extern "C" u32 func_00251358(u32 k) {
    u32 r = 0;
    switch (k) {
    case 0x17FA747C:
        r = 1;
        break;
    case 0xAF06447B:
        r = 2;
        break;
    case 0xB454F54B:
        r = 4;
        break;
    case 0x8A897DD2:
        r = 8;
        break;
    case 0x366727CB:
        r = 0x01000000;
        break;
    case 0xA64C2114:
        r = 0x7FFFFFFF;
        break;
    }
    return r;
}

extern "C" int CFunc_SetLightFlag(int params) {
    S250_Obj *obj = func_00250FF0(params);
    if (obj) {
        S250_Light *light = obj->unk1C;
        u32 flag;
        func_0027D870(params, 0x2E0B1465, &flag, 1);
        light->unk34 |= func_00251358(flag);
        return 1;
    }
    return 0;
}

extern "C" int CFunc_ClearLightFlag(int params) {
    S250_Obj *obj = func_00250FF0(params);
    if (obj) {
        S250_Light *light = obj->unk1C;
        u32 flag;
        func_0027D870(params, 0x2E0B1465, &flag, 1);
        light->unk34 &= ~func_00251358(flag);
        return 1;
    }
    return 0;
}

extern "C" int CFunc_MoveLight(int params) {
    S250_Obj *obj = func_00250FF0(params);
    if (obj) {
        S250_Light *light = obj->unk1C;
        S250_Vec v;
        func_0027D2D8(params, 0x7F261953, &v, 1);
        light->unk10 = v;
        return 1;
    }
    return 0;
}

extern "C" int CFunc_CompactIntervals(void) {
    return 0;
}

extern "C" int CFunc_SetLightDirection(int params) {
    S250_Obj *obj = func_00250FF0(params);
    if (obj) {
        S250_Light *light = obj->unk1C;
        *(u128_250 *)&light->unk20 = func_00251198(params);
        return 1;
    }
    return 0;
}

INCLUDE_ASM("asm/nonmatchings/game/t_250010", CFunc_GetLightDirection);

extern "C" int CFunc_SetLightColor(int params, int script) {
    S250_Obj *obj = func_00250FF0(params);
    if (obj) {
        func_001F3A40(obj, params, script);
        return 1;
    }
    return 0;
}

INCLUDE_ASM("asm/nonmatchings/game/t_250010", CFunc_GetLightColor);

extern "C" int CFunc_SetLightIntensity(int params, int script) {
    S250_Obj *obj = func_00250FF0(params);
    if (obj) {
        func_001F3A40(obj, params, script);
        return 1;
    }
    return 0;
}

extern "C" int CFunc_GetLightIntensity(int params, S250_Script *script) {
    S250_Obj *obj = func_00250FF0(params);
    if (obj) {
        func_0027C1F8(script->unk20, 0x1993C98E, obj->unk1C->unk40);
        return 1;
    }
    return 0;
}

extern "C" int CFunc_SetLightGroupIntensity(int params) {
    u32 key = 0xA1DC81F9;
    S250_Group *g = func_00251090(params, &key);
    if (g) {
        f32 v = 1.0f;
        func_0027D268(params, 0x1993C98E, &v, 1);
        func_001563D0(g, v);
        return 1;
    }
    return 0;
}

extern "C" int CFunc_GetLightGroupIntensity(int params, S250_Script *script) {
    u32 key = 0xA1DC81F9;
    S250_Group *g = func_00251090(params, &key);
    if (g) {
        func_0027C1F8(script->unk20, 0x1993C98E, g->unk94);
        return 1;
    }
    return 0;
}

extern "C" int CFunc_SetDynamicShadowIntensity(void) {
    return 0;
}

extern "C" int CFunc_KillLight(void) {
    return 0;
}

extern "C" int CFunc_EnableLight(int params) {
    S250_Obj *obj = func_00250FF0(params);
    if (obj) {
        obj->unk1C->unk34 |= 2;
        return 1;
    }
    return 0;
}

extern "C" int CFunc_DisableLight(int params) {
    S250_Obj *obj = func_00250FF0(params);
    if (obj) {
        obj->unk1C->unk34 &= ~2;
        return 1;
    }
    return 0;
}

extern "C" int CFunc_EnableLightGroup(int params) {
    u32 key = 0xA1DC81F9;
    S250_Group *g = func_00251090(params, &key);
    if (g) {
        func_00156470(g, 1);
        return 1;
    }
    return 0;
}

extern "C" int CFunc_DisableLightGroup(int params) {
    u32 key = 0xA1DC81F9;
    S250_Group *g = func_00251090(params, &key);
    if (g) {
        func_00156470(g, 0);
        return 1;
    }
    return 0;
}

extern "C" int CFunc_ApplyLightGroup(void) {
    return 0;
}

extern "C" int CFunc_RemoveCurLightGroup(void) {
    return 0;
}

extern "C" int CFunc_AddLightToGroup(int params) {
    S250_Obj *obj = func_00250FF0(params);
    u32 key = 0x7E4813A7;
    S250_Group *g = func_00251090(params, &key);
    if (obj) {
        if (!g) {
            return 0;
        }
        func_00156550(g, obj->unk1C);
        return 1;
    }
    return 0;
}

INCLUDE_ASM("asm/nonmatchings/game/t_250010", CFunc_CreateLightGroup);

extern "C" int CFunc_SetModelLightsFadeTime(void) {
    return 0;
}

INCLUDE_ASM("asm/nonmatchings/game/t_250010", CFunc_SetLightVolumeParams);

extern "C" void CFunc_LoadParticleTexture(int a) {
    func_00250A18(a, 1, D_00355EB0);
}

INCLUDE_ASM("asm/nonmatchings/game/t_250010", CFunc_HackAddLight);

extern "C" int CFunc_GetDisplaySettings(int params, S250_Script *script) {
    int a = func_0014F8A8();
    int b = func_0014F8C8();
    int c = func_0014F8E8();
    func_0027C160(script->unk20, 0x73E5BAD0, a);
    func_0027C160(script->unk20, 0x0AB21AF0, b);
    func_0027CB80(script->unk20, 0x1B813307, c);
    return 1;
}

extern "C" int CFunc_SetRowHeightTables(void) {
    func_002A3EA0();
    return 1;
}

INCLUDE_ASM("asm/nonmatchings/game/t_250010", func_00251C90);

extern "C" void func_00251CA0(u32 a, void *params) {
    S250_Key k;
    k.type = 1;
    if (func_0027DF00((int)params, 0xB2EDCD7D)) {
        k.type = 0;
        func_0027AE70(params, 0xB2EDCD7D);
    }
    if (func_0027D870((int)params, 0xA2AB3C71, &k.id, 0)) {
        k.type = 2;
        func_0027ACF8(params, 0xA2AB3C71);
    }
    if (func_0027D870((int)params, 0x7C1549EC, &k.id, 0)) {
        k.type = 3;
        func_0027ACF8(params, 0x7C1549EC);
    }
    u32 name = 0;
    func_0027D870((int)params, 0xA1DC81F9, &name, 0);
    int m = D_0036CDB4[0]->unk308;
    func_001E1378(m, name, params, a, k);
}

extern "C" int CFunc_PlayIGCCam(int params, int script) {
    void *p = func_0027AA98(func_001287F0(8, 1), params);
    func_00251CA0(0x03986CD2, p);
    if (p) {
        func_0027AC90(p);
        func_00113250(p);
    }
    return 1;
}

extern "C" int CFunc_PlaySkaterCamAnim(int params, int script) {
    void *p = func_0027AA98(func_001287F0(8, 1), params);
    if (func_0027DF00((int)p, 0xEE721991)) {
        func_0027AE70(p, 0xEE721991);
        CFunc_PlayIGCCam((int)p, script);
    } else {
        func_00251CA0(0x66B7DD11, p);
    }
    if (p) {
        func_0027AC90(p);
        func_00113250(p);
    }
    return 1;
}

extern "C" int CFunc_GetSkaterCamAnimParams(int params, S250_Script *script) {
    u32 id = 0;
    func_0027D870(params, 0xA1DC81F9, &id, 0);
    return func_001E1978(D_0036CDB4[0]->unk308, id, script->unk20);
}

extern "C" int CFunc_SkaterCamAnimFinished(int params) {
    u32 id = 0;
    func_0027D870(params, 0xA1DC81F9, &id, 0);
    return func_001E12E8(D_0036CDB4[0]->unk308, &id);
}

extern "C" void func_00251F68(int params) {
    if (func_0027DF00(params, 0x230CCBF4)) {
        func_001E12A8(D_0036CDB4_gp->unk308);
    } else if (func_0027DF00(params, 0xC4E78E22)) {
        func_001E1220(D_0036CDB4_gp->unk308);
    } else {
        u32 id = 0;
        func_0027D870(params, 0xA1DC81F9, &id, 1);
        func_001E1308(D_0036CDB4[0]->unk308, id);
    }
}

extern "C" int CFunc_KillSkaterCamAnim(int params) {
    func_00251F68(params);
    bool missing = !func_001E1650(D_0036CDB4[0]->unk308, 0);
    if (missing) {
        func_0028C9D0(0x15674315, 0, 0, 0, 0, 0);
    }
    return 1;
}
