// cflags: -ffast-math
#include "common.h"

struct S24D_Script {
    char pad0[0x20];
    int unk20;
};

struct S24D_Cam {
    char pad0[0x2C];
    int unk2C;
};

struct S24D_Node {
    char pad0[0xC];
    S24D_Cam *unkC;
    char pad10[0x4];
    S24D_Node *unk14;
    char pad18[0x4];
    int unk1C;
};

struct S24D_VObj {
    char pad0[0x44];
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void *v10();
};

struct S24D_Clip {
    char pad0[0xDC];
    f32 unkDC;
    f32 unkE0;
    void Set(f32 n, f32 f) {
        unkDC = n;
        unkE0 = f;
    }
};

struct S24D_Vec {
    f32 x;
    f32 y;
    f32 z;
    f32 w;
};

struct S24D_VC {
    char pad0[0xC];
    int unkC;
    bool B1() {
        return (unkC >> 1) & 1;
    }
};

struct S24D_LNode {
    int unk0;
    union {
        S24D_VC *unk4;
        int unk4i;
    };
    int unk8;
    S24D_LNode *unkC;
};

struct S24D_RObj {
    char pad0[0x34];
    virtual void v1();
    virtual void *v2();
};

struct S24D_Ref {
    S24D_RObj *p;
    int unk4;
};

struct S24D_AnimData {
    char pad0[0x8];
    f32 unk8;
};

struct S24D_Anim {
    char pad0[0xC];
    S24D_AnimData *unkC;
};

extern "C" {
extern int D_0036F658[] __attribute__((section(".sdata")));
void func_0022B0D0(S24D_Ref *, int, u32, int);
void func_00134340(S24D_Ref *);
void func_00153150(int, int, int, int);
void func_001628F0(void *, int, int, int);
void func_00153178(int, f32, f32, f32, f32, f32, f32, f32, f32);
S24D_LNode *func_0014E948(void);
S24D_VC *func_0014E8E0(void);
void func_0024F500(S24D_VC *, f32, f32, int);
f32 func_0031BD50(f32, f32);
int func_0027D2D8(int, u32, S24D_Vec *, int);
void func_00138B00(S24D_Vec *, S24D_Vec *, int, int, int);
void func_0016F820(void *, int, S24D_Script *);
void func_0016FAD8(void *, int, S24D_Script *);
void func_0016F6E0(void *, int, S24D_Script *);
void func_0016F5F0(void *, int, S24D_Script *);
extern f32 D_00368F70[] __attribute__((section(".sdata")));
extern f32 D_00368F74[] __attribute__((section(".sdata")));
S24D_Clip *func_0015DBF0(int);
f32 func_0031B4B8(f32);
int func_0015D5A0(int);
extern int D_0036D3B0[] __attribute__((section(".sdata")));
S24D_Node *func_001D4AC0(int, u32);
void func_0027C448(int, u32, int);
int func_0027D268(int, u32, f32 *, int);
void func_001531C8(int, f32, f32);
void func_001AD588(void);
extern int D_00372D34[] __attribute__((section(".sdata")));
extern int D_00372D38[] __attribute__((section(".sdata")));
extern int D_00372D3C[] __attribute__((section(".sdata")));
extern int D_00372D40[] __attribute__((section(".sdata")));
extern int D_00372D44[] __attribute__((section(".sdata")));
S24D_VObj *func_0015D2E8(u32, int);
void func_0016F248(void *, int, S24D_Script *);
void func_0014F1D0(int, int);
bool func_0027DF00(int, u32);
void func_00153218(int, bool);
void func_0027F1E0(int, int, int);
void func_0027C1F8(int, u32, f32);
void *func_001287F0(int, int);
void *func_0027AA70(void *);
void func_0014F298(void *);
void func_0027C7D0(int, u32, void *);
void func_0027AC90(void *);
void func_00113250(void *);
int func_0027CC30(int, u32, int, void *);
f32 func_0031B3C0(f32);
void func_0027C160(int, u32, int);
int func_0027D1F8(int, u32, void *, int);
bool func_0027D870(int, u32, void *, int);
void func_001167C8(bool);
extern int D_00373250[] __attribute__((section(".sdata")));
extern int D_0037325C[] __attribute__((section(".sdata")));
int func_0014E1B8(u32);
void func_001531F0(int);
void func_00153240(int);
void func_001531A0(int, int);
S24D_Anim *func_0024E3C0(int);
int func_0014F178(void);
}

INCLUDE_ASM("asm/nonmatchings/game/t_24DDB8", CFunc_LinearMap);

inline f32 Clamp24D(f32 v, f32 lo, f32 hi) {
    return v < lo ? lo : (hi < v ? hi : v);
}

extern "C" int CFunc_Clamp(int params, S24D_Script *script) {
    f32 v;
    f32 lo;
    f32 hi;
    func_0027D268(params, 0, &v, 1);
    func_0027D268(params, 0x5E84E22F, &lo, 1);
    func_0027D268(params, 0x6289DD76, &hi, 1);
    int dst = script->unk20;
    func_0027C1F8(dst, 0xCC419A08, Clamp24D(v, lo, hi));
    return 1;
}

INCLUDE_ASM("asm/nonmatchings/game/t_24DDB8", func_0024DF98);

extern "C" int CFunc_VectorLength(int params, S24D_Script *script) {
    S24D_Vec v;
    f32 d;
    int t;
    func_0027D2D8(params, 0xE491B7A4, &v, 1);
    int k;
    asm("lqc2 $vf2, 0(%1)\n\tvmul.xyzw $vf2, $vf2, $vf2" : "=r"(k) : "r"(&v) : "memory");
    int dst = script->unk20;
    asm volatile("vaddy.x $vf1, $vf2, $vf2y\n\tvaddz.x $vf1, $vf1, $vf2z\n\tqmfc2.ni %1, $vf1\n\tmtc1 %1, %0\n\tnop\n\tnop\n\tsqrt.s %0, %0"
        : "=f"(d), "=&r"(t) : "r"(k), "r"(dst));
    func_0027C1F8(dst, 0xFE82614D, d);
    return 1;
}

extern "C" int CFunc_MathFloor(int params, S24D_Script *script) {
    f32 v;
    f32 f;
    if (func_0027CC30(params, 0, 2, &v)) {
        f = v;
    } else {
        func_0027F1E0(params, 0, 1);
        f = 0.0f;
    }
    int dst = script->unk20;
    func_0027C160(dst, 0x41BA29D1, (int)func_0031B4B8(f));
    return 1;
}

extern "C" int CFunc_MathCeil(int params, S24D_Script *script) {
    f32 v;
    f32 f;
    if (func_0027CC30(params, 0, 2, &v)) {
        f = v;
    } else {
        func_0027F1E0(params, 0, 1);
        f = 0.0f;
    }
    int dst = script->unk20;
    func_0027C160(dst, 0x490F8C58, (int)func_0031B3C0(f));
    return 1;
}

extern "C" int CFunc_MathPow(int params, S24D_Script *script) {
    f32 w;
    f32 v;
    f32 a;
    f32 b;
    if (func_0027CC30(params, 0, 2, &w)) {
        a = w;
    } else {
        func_0027F1E0(params, 0, 1);
        a = 0.0f;
    }
    if (func_0027CC30(params, 0xF941ADE4, 2, &v)) {
        b = v;
    } else {
        func_0027F1E0(params, 0, 1);
        b = 0.0f;
    }
    int dst = script->unk20;
    func_0027C1F8(dst, 0x784BDD4A, func_0031BD50(a, b));
    return 1;
}

extern "C" int CFunc_MathMin(int params, S24D_Script *script) {
    f32 v;
    f32 a;
    f32 b;
    f32 w;
    if (func_0027CC30(params, 0x174841BC, 2, &w)) {
        a = w;
    } else {
        func_0027F1E0(params, 0, 1);
        a = 0.0f;
    }
    if (func_0027CC30(params, 0x8E411006, 2, &v)) {
        b = v;
    } else {
        func_0027F1E0(params, 0, 1);
        b = 0.0f;
    }
    func_0027C1F8(script->unk20, 0x5E84E22F, a < b ? a : b);
    return 1;
}

INCLUDE_ASM("asm/nonmatchings/game/t_24DDB8", CFunc_FeelerCheck);

INCLUDE_ASM("asm/nonmatchings/game/t_24DDB8", func_0024E3B8);

INCLUDE_ASM("asm/nonmatchings/game/t_24DDB8", func_0024E3C0);

extern "C" int CFunc_Anim_GetAnimLength(int params, S24D_Script *script) {
    S24D_Anim *a = func_0024E3C0(params);
    if (!a) {
        func_0027F1E0(params, 0, 1);
    }
    func_0027C1F8(script->unk20, 0xFE82614D, a->unkC->unk8);
    return 1;
}

extern "C" int CFunc_Anim_AnimExists(int params) {
    return func_0024E3C0(params) != 0;
}

INCLUDE_ASM("asm/nonmatchings/game/t_24DDB8", func_0024E548);

extern "C" int CFunc_GetCurrentCameraObject(int params, S24D_Script *script) {
    int id = 0;
    int cam = func_0015D5A0(0);
    S24D_Node *n;
    for (n = func_001D4AC0(D_0036D3B0[0], 0xC4E311FA); n; n = n->unk14) {
        if (n->unk1C == cam) {
            id = n->unkC->unk2C;
        }
    }
    func_0027C448(script->unk20, 0xDA3AB8C5, id);
    return 1;
}

extern "C" void CFunc_ScreenFX_AddFXInstance(int params, S24D_Script *script) {
    u32 id = 0;
    bool missing = !func_0027D870(params, 0x9FD29151, &id, 0);
    if (missing) {
        int i = 0;
        func_0027D1F8(params, 0x9FD29151, &i, 1);
        id = i;
    }
    func_0016F248(func_0015D2E8(id, 1)->v10(), params, script);
}

extern "C" void CFunc_ScreenFX_UpdateFXInstanceParams(int params, S24D_Script *script) {
    u32 id = 0;
    bool missing = !func_0027D870(params, 0x9FD29151, &id, 0);
    if (missing) {
        int i = 0;
        func_0027D1F8(params, 0x9FD29151, &i, 1);
        id = i;
    }
    func_0016F5F0(func_0015D2E8(id, 1)->v10(), params, script);
}

extern "C" void CFunc_ScreenFX_RemoveFXInstance(int params, S24D_Script *script) {
    u32 id = 0;
    bool missing = !func_0027D870(params, 0x9FD29151, &id, 0);
    if (missing) {
        int i = 0;
        func_0027D1F8(params, 0x9FD29151, &i, 1);
        id = i;
    }
    func_0016F6E0(func_0015D2E8(id, 1)->v10(), params, script);
}

extern "C" void CFunc_ScreenFX_ClearFXInstances(int params, S24D_Script *script) {
    u32 id = 0;
    bool missing = !func_0027D870(params, 0x9FD29151, &id, 0);
    if (missing) {
        int i = 0;
        func_0027D1F8(params, 0x9FD29151, &i, 1);
        id = i;
    }
    func_0016F820(func_0015D2E8(id, 1)->v10(), params, script);
}

extern "C" void CFunc_ScreenFX_FxInstanceExists(int params, S24D_Script *script) {
    u32 id = 0;
    bool missing = !func_0027D870(params, 0x9FD29151, &id, 0);
    if (missing) {
        int i = 0;
        func_0027D1F8(params, 0x9FD29151, &i, 1);
        id = i;
    }
    func_0016FAD8(func_0015D2E8(id, 1)->v10(), params, script);
}

INCLUDE_ASM("asm/nonmatchings/game/t_24DDB8", CFunc_ScreenFX_GetActiveScreenFXInstances);

extern "C" int CFunc_SetProgressive(int params) {
    int on = 0;
    func_0027D1F8(params, 0xF649D637 /* ON */, &on, 0);
    func_001167C8(on > 0);
    return 1;
}

extern "C" int CFunc_DebugLine(int params) {
    S24D_Vec start;
    S24D_Vec end;
    int color = 0xFF0000FF;
    int time = 0;
    func_0027D2D8(params, 0x6086AA70, &start, 1);
    func_0027D2D8(params, 0xFF03CC4E, &end, 1);
    func_0027D1F8(params, 0x99A9B716, &color, 0);
    func_0027D1F8(params, 0x019176C5, &time, 0);
    func_00138B00(&start, &end, color, 0, time);
    return 1;
}

extern "C" int CFunc_GetCurrentGeomStats(int params, S24D_Script *script) {
    func_001AD588();
    func_0027C160(script->unk20, 0xA472DE8F, D_00372D34[0]);
    func_0027C160(script->unk20, 0x4569AA6C, D_00372D38[0]);
    func_0027C160(script->unk20, 0xD3599F51, D_00372D3C[0]);
    func_0027C160(script->unk20, 0x3A688D8D, D_00372D44[0]);
    func_0027C160(script->unk20, 0x3FFB1C3C, D_00372D40[0]);
    return 1;
}

extern "C" int CFunc_GetCurrentParticleTimes(void) {
    return 1;
}

extern "C" int CFunc_GetCurrentAnimTimes(void) {
    return 1;
}

extern "C" int CFunc_GetMetrics(int params, S24D_Script *script) {
    void *s = func_0027AA70(func_001287F0(8, 1));
    func_0014F298(s);
    func_0027C7D0(script->unk20, 0xDD755518, s);
    if (s) {
        func_0027AC90(s);
        func_00113250(s);
    }
    return 1;
}

INCLUDE_ASM("asm/nonmatchings/game/t_24DDB8", func_0024ED80);

INCLUDE_ASM("asm/nonmatchings/game/t_24DDB8", CFunc_SetClippingDistances);

INCLUDE_ASM("asm/nonmatchings/game/t_24DDB8", CFunc_VCWibblePlayFromKeyframe);

extern "C" int CFunc_SetUVWibbleParams(int params) {
    u32 sector = 0;
    f32 a;
    f32 b;
    f32 c;
    f32 d;
    f32 e;
    f32 f;
    f32 g;
    f32 h;
    func_0027D870(params, 0xB45C2617 /* sector */, &sector, 0);
    int s = func_0014E1B8(sector);
    func_0027D268(params, 0x9773DEDA, &a, 0);
    func_0027D268(params, 0x52C2BD68, &b, 0);
    func_0027D268(params, 0xD921509D, &c, 0);
    func_0027D268(params, 0x568444F9, &d, 0);
    func_0027D268(params, 0xD0D3A40A, &e, 0);
    func_0027D268(params, 0x1562C7B8, &f, 0);
    func_0027D268(params, 0x5FB52233, &g, 0);
    func_0027D268(params, 0x676C5E64, &h, 0);
    func_00153178(s, a, b, c, d, e, f, g, h);
    return 1;
}

extern "C" int CFunc_EnableExplicitUVWibble(int params) {
    u32 sector = 0;
    func_0027D870(params, 0xB45C2617 /* sector */, &sector, 0);
    func_001531A0(func_0014E1B8(sector), 1);
    return 1;
}

extern "C" int CFunc_DisableExplicitUVWibble(int params) {
    u32 sector = 0;
    func_0027D870(params, 0xB45C2617 /* sector */, &sector, 0);
    func_001531A0(func_0014E1B8(sector), 0);
    return 1;
}

extern "C" int CFunc_SetUVWibbleOffsets(int params) {
    u32 sector = 0;
    func_0027D870(params, 0xB45C2617 /* sector */, &sector, 0);
    int s = func_0014E1B8(sector);
    if (!s) {
        return 0;
    }
    f32 u;
    f32 v;
    func_0027D268(params, 0x4F7CFCF8, &u, 0);
    func_0027D268(params, 0x08DC8628, &v, 0);
    func_001531C8(s, u, v);
    return 1;
}

extern "C" int CFunc_ResetTextureAnim(int params) {
    u32 sector = 0;
    func_0027D870(params, 0xB45C2617 /* sector */, &sector, 0);
    func_001531F0(func_0014E1B8(sector));
    return 1;
}

extern "C" int CFunc_StartTextureAnim(int params) {
    u32 sector = 0;
    func_0027D870(params, 0xB45C2617 /* sector */, &sector, 0);
    int s = func_0014E1B8(sector);
    func_00153218(s, func_0027DF00(params, 0xAF6240B2));
    return 1;
}

extern "C" int CFunc_StopTextureAnim(int params) {
    u32 sector = 0;
    func_0027D870(params, 0xB45C2617 /* sector */, &sector, 0);
    func_00153240(func_0014E1B8(sector));
    return 1;
}

INCLUDE_ASM("asm/nonmatchings/game/t_24DDB8", CFunc_ToggleRenderMetrics);

extern "C" int CFunc_SetOutlineShaderColor(void) {
    return 0;
}

extern "C" int CFunc_SetOutlineShaderParams(void) {
    return 0;
}

extern "C" int CFunc_SetShaderOverride(void) {
    return 0;
}

extern "C" int CFunc_SetShadowRenderingFlags(void) {
    return 0;
}

extern "C" int CFunc_SetShadowProjectionTexture(void) {
    return 0;
}

extern "C" int CFunc_ToggleRenderMode(void) {
    func_0014F178();
    return 1;
}

extern "C" int CFunc_SetRenderMode(int params) {
    int mode = 0;
    func_0027D1F8(params, 0x6835B854 /* MODE */, &mode, 0);
    D_00373250[0] = mode;
    return 1;
}

extern "C" int CFunc_SetWireframeMode(int params) {
    int mode = 0;
    func_0027D1F8(params, 0x6835B854 /* MODE */, &mode, 0);
    D_0037325C[0] = mode;
    return 1;
}

extern "C" int CFunc_DebugRenderIgnore(int params) {
    int b = 0;
    int a = 0;
    func_0027D1F8(params, 0xD12347A6, &a, 0);
    func_0027D1F8(params, 0xA6247730, &b, 0);
    func_0014F1D0(a, b);
    return 1;
}

extern "C" f32 func_0024F4B8(f32 a, f32 b, f32 t) {
    f32 r = b + (a - b) * t;
    if (r < 0.0f) {
        r = 0.0f;
    }
    if (r > 255.0f) {
        r = 255.0f;
    }
    return r;
}

INCLUDE_ASM("asm/nonmatchings/game/t_24DDB8", func_0024F500);

static inline S24D_LNode *S24D_Valid2(S24D_LNode *n) {
    if (n->unk4i != -1) {
        return n;
    }
    return 0;
}

extern "C" int CFunc_CompressVC(int params) {
    f32 a = 0.0f;
    func_0027D268(params, 0xB990D003, &a, 1);
    f32 b = 0.0f;
    func_0027D268(params, 0x9E497FC6, &b, 0);
    b = (100.0f - b) * 0.01f;
    int c = 0;
    func_0027D870(params, 0x7E4813A7, &c, 0);
    S24D_LNode *cur = func_0014E948();
    while (cur) {
        S24D_LNode *next = S24D_Valid2(cur->unkC);
        S24D_VC *vc = cur->unk4;
        if (!vc->B1()) {
            func_0024F500(vc, a, b, c);
        }
        cur = next;
    }
    S24D_VC *last = func_0014E8E0();
    if (last) {
        func_0024F500(last, a, b, c);
    }
    return 1;
}

INCLUDE_ASM("asm/nonmatchings/game/t_24DDB8", func_0024FAD8);
