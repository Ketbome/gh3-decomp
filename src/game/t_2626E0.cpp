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

extern "C" {
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

INCLUDE_ASM("asm/nonmatchings/game/t_2626E0", CFunc_ResetPS2);

INCLUDE_ASM("asm/nonmatchings/game/t_2626E0", CFunc_ResetHD);

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

INCLUDE_ASM("asm/nonmatchings/game/t_2626E0", CFunc_GetPlatform);

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

INCLUDE_ASM("asm/nonmatchings/game/t_2626E0", CFunc_ControllerDebounce);

INCLUDE_ASM("asm/nonmatchings/game/t_2626E0", func_00262F18);

INCLUDE_ASM("asm/nonmatchings/game/t_2626E0", func_002634B8);

INCLUDE_ASM("asm/nonmatchings/game/t_2626E0", CFunc_ControllerPressed);

INCLUDE_ASM("asm/nonmatchings/game/t_2626E0", CFunc_ControllerMake);

INCLUDE_ASM("asm/nonmatchings/game/t_2626E0", CFunc_EnableActuators);

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

INCLUDE_ASM("asm/nonmatchings/game/t_2626E0", CFunc_GetViewportCameraPos);

INCLUDE_ASM("asm/nonmatchings/game/t_2626E0", CFunc_GetViewportCameraOrient);

INCLUDE_ASM("asm/nonmatchings/game/t_2626E0", CFunc_SetViewportCameraPos);

INCLUDE_ASM("asm/nonmatchings/game/t_2626E0", CFunc_SetViewportCameraOrient);
