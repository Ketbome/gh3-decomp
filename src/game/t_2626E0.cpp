// cflags: -funroll-loops
#include "common.h"

struct S2626_Ctl {
    char pad0[0x28];
    int unk28[2];
};

struct S2626_Range {
    u8 unk0;
    u8 unk1;
    f32 unk4;
    f32 unk8;
};

struct S2626_Pad {
    char pad0[0x30];
    int unk30[4];
    char pad40[0x3C - 0x40 + 0x4];
};

struct S2626_Act {
    char pad0[0x3C];
    int unk3C;
    char pad40[0xC];
    int unk4C;
};

struct S2626_Obj {
    char pad0[0x2C];
    int unk2C;
    char pad30[0x154 - 0x30];
    int unk154;
};

struct S2626_Script {
    char pad0[0x20];
    int unk20;
};

struct S2626_Mgr {
    char pad0[0x28];
    int pads[2];
};

struct S2626_ActEnt {
    int on;
    char pad4[0xC];
};

struct S2626_ActMgr {
    char pad0[0x3C];
    S2626_ActEnt act[2];
};

struct S262D1C {
    char pad0[0x20];
    int unk20;
};

extern "C" {
extern char D_00370870[];
extern char D_00370878[];
extern char D_00370880[];
int func_002F2D48(char *, int, int, int, int, int);
int func_002FFF50(int *);
int func_00262F18(int, u32);
int func_002634B8(int, u32);
void func_00275648(S2626_Range *);
bool func_0027DD38(int, u32, S2626_Range *, int);
void func_001EF368(int, int, f32);
extern int D_003688E8[] __attribute__((section(".sdata")));
int func_00117940(int, int, int);
void func_001183C8(int, int, int);
void func_001C7558(void);
extern int D_0036D020;
void func_001CD678(int, int);
void func_001CD640(int, int);
void func_00221DE0(int, int, u32);
int func_0027CC30(int, u32, int, void *);
void func_0027F1E0(int, int, int);
void func_0015D0D0(u32, int, u32, int);
extern int D_00370820;
void func_002DB8A8(int);
void func_00252FC0(u32, int, int);
int func_0027D1F8(int, u32, int *, int);
void func_002DB8C0(int, int);
void func_002DB110(int, int);
void func_00221DC8(int, u32);
void func_0015C3B0(u32, int);
int func_002DB8E8(void);
void func_002DB268(int);
int func_0027D870(int, u32, u32 *, int);
int func_0027D188(int, u32, int *, int);
void func_0015D408(u32);
void func_00116630(int);
void func_0015D7F8(u32);
int func_0015D2E8(u32, int);
int func_00117030(void);
void func_0027C028(int, u32, int);
int func_0015D7F0(void);
void func_0027C448(int, u32, int);
int func_002DB8A0(int);
int func_001D1CF8(int, u32);
void func_00221DC0(int);
extern int D_00368740[] __attribute__((section(".sdata")));
void func_001163F8(void);
int func_00116638(void);
int func_001163F0(void);
int func_00116400(void);
extern int D_0036CDB4[] __attribute__((section(".sdata")));
void func_001C74F8(int);
}

GP_DATA(D_00370820);
extern "C" int CFunc_SetViewerModel(int params) {
    int v = func_002DB8E8();
    D_00370820 = 1;
    func_002DB8A8(1);
    if (D_00370820 == 0) {
        func_00252FC0(0x967C138C, 0, 0);
    } else {
        func_00252FC0(0xEB17151B, 0, 0);
    }
    if (v) {
        func_002DB8C0(v, params);
        func_002DB110(v, params);
    }
    return 1;
}

extern "C" int CFunc_SetViewerAnim(int params) {
    int v = func_002DB8E8();
    if (v) {
        u32 anim;
        func_0027D870(params, 0, &anim, 1);
        S2626_Obj *o = (S2626_Obj *)func_002DB8A0(v);
        if (o) {
            if (o->unk154 & 1) {
                o->unk154 &= ~1;
            }
            func_00221DC8(func_001D1CF8((int)o, 0xB38129F1), anim);
        }
    }
    return 1;
}

extern "C" int CFunc_SetViewerLODDist(int params) {
    int v = func_002DB8E8();
    if (v) {
        S2626_Range r;
        func_00275648(&r);
        bool missing = !func_0027DD38(params, 0, &r, 0);
        if (missing) {
            return 0;
        }
        int o = func_002DB8A0(v);
        if (o) {
            func_001EF368(func_001D1CF8(o, 0x286A8D26), (int)r.unk4, r.unk8);
        }
    }
    return 1;
}

extern "C" int CFunc_GetViewerObjectID(int params, S2626_Script *script) {
    int v = func_002DB8E8();
    if (v) {
        S2626_Obj *o = (S2626_Obj *)func_002DB8A0(v);
        func_0027C448(script->unk20, 0x0830ECAF, o->unk2C);
        func_0027C448(script->unk20, 0x52280066, o->unk2C);
    }
    return 1;
}

extern "C" int CFunc_ReloadViewerAnim(int params) {
    int v = func_002DB8E8();
    if (v) {
        int o = func_002DB8A0(v);
        if (o) {
            u32 anim;
            int name;
            bool ok = 0;
            if (func_0027D870(params, 0, &anim, 0)) {
                ok = func_0027D188(params, 0, &name, 0) != 0;
            }
            if (ok) {
                func_00221DE0(func_001D1CF8(o, 0xB38129F1), name, anim);
            }
        }
    }
    return 1;
}

extern "C" int CFunc_ResetModelViewerCamera(void) {
    func_00221DC0(func_001D1CF8(func_002DB8A0(func_002DB8E8()), 0xB38129F1));
    return 1;
}

extern "C" int CFunc_SetViewMode(int params) {
    int mode;
    func_0027D1F8(params, 0, &mode, 1);
    D_00370820 = mode;
    func_002DB8A8(mode);
    if (D_00370820 == 0) {
        func_00252FC0(0x967C138C, 0, 0);
    } else {
        func_00252FC0(0xEB17151B, 0, 0);
    }
    int v = func_002DB8E8();
    if (v) {
        func_002DB268(v);
    }
    return 1;
}

extern "C" int CFunc_ClearViewerObject(void) {
    int v = func_002DB8E8();
    if (v) {
        func_002DB268(v);
    }
    return 1;
}

INCLUDE_ASM("asm/nonmatchings/game/t_2626E0", func_00262AB0);

extern "C" int CFunc_ResetPS2(void) {
    while (func_002F2D48(D_00370870, 0x4402, 0, 0, 0, 0) < 0) {
    }
    int r;
    while (!func_002FFF50(&r) || r != 0) {
    }
    return 1;
}

extern "C" int CFunc_ResetHD(void) {
    func_002F2D48(D_00370878, 0x5003, 0, 0, 0, 0);
    while (func_002F2D48(D_00370880, 0x4806, 0, 0, 0, 0) < 0) {
    }
    while (func_002F2D48(D_00370870, 0x4402, 0, 0, 0, 0) < 0) {
    }
    int r;
    while (!func_002FFF50(&r) || r != 0) {
    }
    return 1;
}

extern "C" int CFunc_LoadExecPS2(int params) {
    int name;
    func_0027D188(params, 0x233BCFE0, &name, 1);
    func_00116630(name);
    return 1;
}

extern "C" int CFunc_ExitDemo(void) {
    func_00116638();
    return 1;
}

INCLUDE_ASM("asm/nonmatchings/game/t_2626E0", func_00262C48);

inline int Platform2626() {
    return D_00368740[0];
}

extern "C" int CFunc_IsPS2(void) {
    if (Platform2626() == 1 || Platform2626() == 2 || Platform2626() == 3) {
        return 1;
    }
    return 0;
}

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

extern "C" int CFunc_GetPlatform(int, S262D1C *s) {
    u32 v = 0;
    switch (D_00368740[0]) {
    case 1:
    case 2:
    case 3:
        v = 0x988A3508;
        break;
    case 5:
        v = 0xBCF00D45;
        break;
    case 4:
        v = 0x87D839B8;
        break;
    case 6:
        v = 0xF6A179C0;
        break;
    case 9:
        v = 0x4AF45E2E;
        break;
    }
    func_0027C448(s->unk20, 0xC6AD2F34, v);
    return 1;
}

extern "C" int CFunc_GetPlatformExt(int params, S2626_Script *script) {
    int d = script->unk20;
    func_0027C028(d, 0x480A9BEE, func_00117030());
    return 1;
}

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

extern int D_0039A3D8[];
extern "C" int func_001CD5C0(int);
extern "C" u32 func_0011EF10(void);
extern "C" int func_003174C0(u32, f32);
extern "C" int func_0027D268(int, int, f32 *, int);

struct S262E38 {
    u32 v;
    f32 t;
};

INCLUDE_ASM("asm/nonmatchings/game/t_2626E0", CFunc_ControllerDebounce);

INCLUDE_ASM("asm/nonmatchings/game/t_2626E0", func_00262F18);

INCLUDE_ASM("asm/nonmatchings/game/t_2626E0", func_002634B8);

extern "C" int CFunc_ControllerPressed(int params) {
    S2626_Mgr *m = (S2626_Mgr *)D_0036CDB4[0];
    u32 button = 0;
    if (!func_0027D870(params, 0, &button, 0)) {
        return 0;
    }
    int n;
    if (func_0027D1F8(params, 0, &n, 0)) {
        return func_00262F18(m->pads[n], button) != 0;
    }
    for (int i = 0; i < 2; i++) {
        if (func_00262F18(m->pads[i], button)) {
            return 1;
        }
    }
    return 0;
}

extern "C" int CFunc_ControllerMake(int params) {
    S2626_Mgr *m = (S2626_Mgr *)D_0036CDB4[0];
    u32 button = 0;
    if (!func_0027D870(params, 0, &button, 0)) {
        return 0;
    }
    int n;
    if (func_0027D1F8(params, 0, &n, 0)) {
        return func_002634B8(m->pads[n], button) != 0;
    }
    for (int i = 0; i < 2; i++) {
        if (func_002634B8(m->pads[i], button)) {
            return 1;
        }
    }
    return 0;
}

extern "C" int CFunc_EnableActuators(int params) {
    int on = 1;
    func_0027D1F8(params, 0, &on, 0);
    int dev = D_0036D020;
    for (int i = 0; i < 2; i++) {
        if (((S2626_ActMgr *)D_0036CDB4[0])->act[i].on) {
            if (on) {
                func_001CD678(dev, i);
            } else {
                func_001CD640(dev, i);
            }
        }
    }
    return 1;
}

extern "C" int CFunc_VibrateController(int params) {
    int a;
    int b;
    int c;
    func_0027D1F8(params, 0xBC6EA233, &a, 1);
    func_0027D1F8(params, 0x114FC131, &b, 1);
    func_0027D1F8(params, 0x9E497FC6, &c, 1);
    int pad = func_00117940(D_003688E8[0], a, 0);
    if (pad) {
        func_001183C8(pad, b, c);
        return 1;
    }
    return 0;
}

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

extern "C" int CFunc_SetScreenMode(int params) {
    u32 mode = 0;
    func_0027D870(params, 0, &mode, 1);
    func_0015D7F8(mode);
    return 1;
}

extern "C" int CFunc_GetScreenMode(int params, S2626_Script *script) {
    int d = script->unk20;
    func_0027C448(d, 0x688B4DDB, func_0015D7F0());
    return 1;
}

extern "C" int CFunc_CreateViewport(int params) {
    u32 id;
    int v;
    u32 c;
    func_0027D870(params, 0x40C698AF, &id, 1);
    u32 i = id;
    int x;
    if (func_0027CC30(params, 0x9D5923D8, 1, &v)) {
        x = v;
    } else {
        func_0027F1E0(params, 0, 1);
        x = 0;
    }
    func_0027D870(params, 0xCC424795, &c, 1);
    func_0015D0D0(i, x, c, params);
    return 1;
}

extern "C" int CFunc_DestroyViewport(int params) {
    u32 id;
    func_0027D870(params, 0x40C698AF, &id, 1);
    func_0015D408(id);
    return 1;
}

INCLUDE_ASM("asm/nonmatchings/game/t_2626E0", func_00264040);

extern "C" int CFunc_ViewportExists(int params) {
    u32 id;
    func_0027D870(params, 0x40C698AF, &id, 1);
    return func_0015D2E8(id, 0) != 0;
}

extern "C" int CFunc_SetViewportProperties(int params) {
    u32 id = 0;
    if (func_0027D870(params, 0x9FD29151, &id, 0)) {
        func_0015C3B0(id, params);
    } else {
        int i = 0;
        func_0027D1F8(params, 0x9FD29151, &i, 1);
        func_0015C3B0(i, params);
    }
    return 1;
}

INCLUDE_ASM("asm/nonmatchings/game/t_2626E0", CFunc_GetViewport2DPosFrom3D);

typedef unsigned int u128 __attribute__((mode(TI)));
struct S2626_M4 {
    u128 a, b, c, d;
};
struct S2626_Cam {
    char pad0[0x90];
    S2626_M4 unk90;
};
struct S2626_VP {
    char pad0[0x34];
    S2626_Cam *unk34;
};
struct S2626_Node {
    char pad0[0xC];
    char *unkC;
    char pad10[4];
    S2626_Node *unk14;
    char pad18[4];
    S2626_Cam *unk1C;
};
extern "C" {
S2626_VP *func_0015D568(int, int);
S2626_VP *func_0015DB00(int);
S2626_Node *func_001D4AC0(int, u32);
int func_0027D2D8(int, u32, u128 *, int);
extern int D_0036D3B0[] __attribute__((section(".sdata")));
}

static inline f32 Get262X(u128 q) {
    f32 f;
    asm("mtc1 %1, %0" : "=f"(f) : "r"(q));
    return f;
}
static inline f32 Get262Y(u128 q) {
    u32 t;
    f32 f;
    asm("dsrl32 %0, %1, 0" : "=r"(t) : "r"(q));
    asm("mtc1 %1, %0" : "=f"(f) : "r"(t));
    return f;
}
static inline f32 Get262Z(u128 q) {
    u32 t;
    f32 f;
    asm("pcpyud %0, %1, %1" : "=r"(t) : "r"(q));
    asm("mtc1 %1, %0" : "=f"(f) : "r"(t));
    return f;
}
extern "C" void func_0027C4D8(int, int, f32, f32, f32);

extern "C" int CFunc_GetViewportCameraPos(int params, S2626_Script *script) {
    struct { int id; int k; int i; } t;
    S2626_VP *vp;
    t.id = 0;
    if (func_0027D1F8(params, 0x76F7AF65, &t.k, 0)) {
        func_0027D870(params, 0x9FD29151, (u32 *)&t.id, 1);
        int kk = t.k;
        vp = func_0015D568(t.id, kk);
    } else if (func_0027D870(params, 0x9FD29151, (u32 *)&t.id, 0)) {
        vp = (S2626_VP *)func_0015D2E8(t.id, 1);
    } else {
        t.i = 0;
        func_0027D1F8(params, 0x9FD29151, &t.i, 0);
        vp = func_0015DB00(t.i);
    }
    S2626_Cam *c = vp->unk34;
    if (c) {
        u128 q = *(u128 *)((char *)c + 0x80);
        func_0027C4D8(script->unk20, 0x7F261953, Get262X(q), Get262Y(q), Get262Z(q));
    }
    return 1;
}

extern "C" int CFunc_GetViewportCameraOrient(int params, S2626_Script *script) {
    struct { int id; int k; int i; } t;
    S2626_VP *vp;
    t.id = 0;
    if (func_0027D1F8(params, 0x76F7AF65, &t.k, 0)) {
        func_0027D870(params, 0x9FD29151, (u32 *)&t.id, 1);
        int kk = t.k;
        vp = func_0015D568(t.id, kk);
    } else if (func_0027D870(params, 0x9FD29151, (u32 *)&t.id, 0)) {
        vp = (S2626_VP *)func_0015D2E8(t.id, 1);
    } else {
        t.i = 0;
        func_0027D1F8(params, 0x9FD29151, &t.i, 0);
        vp = func_0015DB00(t.i);
    }
    S2626_Cam *c = vp->unk34;
    if (c) {
        func_0027C4D8(script->unk20, 0x95A802C3, Get262X(c->unk90.c), Get262Y(c->unk90.c), Get262Z(c->unk90.c));
        func_0027C4D8(script->unk20, 0x85981897, Get262X(c->unk90.a), Get262Y(c->unk90.a), Get262Z(c->unk90.a));
        func_0027C4D8(script->unk20, 0xBC6B118F, Get262X(c->unk90.b), Get262Y(c->unk90.b), Get262Z(c->unk90.b));
    }
    return 1;
}

INCLUDE_ASM("asm/nonmatchings/game/t_2626E0", CFunc_SetViewportCameraPos);

INCLUDE_ASM("asm/nonmatchings/game/t_2626E0", CFunc_SetViewportCameraOrient);
