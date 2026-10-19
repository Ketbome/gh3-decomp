// cflags: -funroll-loops
#include "common.h"

struct S2562_Script {
    char pad0[0x20];
    int unk20;
};

struct S2562_Snd {
    int unk0;
    int unk4;
};

struct S2562_Surf {
    f32 unk0;
    int unk4;
    f32 unk8;
    f32 unkC;
    f32 unk10;
    int unk14;
    f32 unk18;
    int unk1C;
};

struct S2562_Arr {
    char pad0[0x2];
    u8 type;
    char pad3;
    int size;
    int data;
    S2562_Arr *Get(int i) {
        if (size == 1) {
            return (S2562_Arr *)data;
        }
        return ((S2562_Arr **)data)[i];
    }
    int GetI(int i) {
        if (size == 1) {
            return data;
        }
        return ((int *)data)[i];
    }
};

struct S2562_Comp {
    u32 b0 : 8;
    u32 b8 : 1;
    u32 type : 7;
    u16 unk2;
    u32 key;
    u32 val;
};

extern "C" {
int func_0010C050(int);
void func_0027C1F8(int, u32, f32);
int func_0010C050(int);
void func_0027C1F8(int, u32, f32);
int func_0011A5B8(S2562_Arr *, int);
char *func_0027EF60(S2562_Arr *, int);
int func_0030E650(char *, char *);
void *func_001287F0(int, int);
int func_0027AA70(void *);
void func_0027C898(int, u32, int);
void func_0027C678(int, u32, int);
S2562_Comp *func_0027B300(int, S2562_Comp *);
bool func_0027D470(int, u32, void *, int);
S2562_Arr *func_002764E8(u32, int);
S2562_Arr *func_00256848(int, S2562_Script *, int);
int strlen(char *);
extern char D_003704B8[];
int func_00249960(u32);
int func_00249F20(int *, int, u32);
void func_0027C7D0(int, u32, int);
int func_0026A1A8(u32, int, int, int, int);
bool func_0027D870(int, u32, void *, int);
bool func_0027D1F8(int, u32, void *, int);
bool func_0027D188(int, u32, void *, int);
bool func_0027D268(int, u32, void *, int);
bool func_0027D400(int, u32, void *, int);
void func_0027ABB0(int, int);
void func_0027AE70(int, u32);
void func_0027ACF8(int, u32);
void func_0027C160(int, u32, int);
void func_002E8C08(u32);
int func_002E8C28(u32, int);
void func_002E7C08(void);
void func_002E7C30(void);
void func_002EA758(f32);
int func_001139E0(char *, char *);
int func_0028DAB8(char *);
extern S2562_Snd *D_00370AE0;
void func_002E9818(void);
void func_002E99D0(void);
void func_002E8318(void);
int func_002E7BC8(void);
int func_002E7BE8(void);
void func_00256740(int, int);
int func_0028C470(int, int);
bool func_0027DF00(int, u32);
void func_002E9C00(int);
}

extern "C" int CFunc_PauseSound(void) {
    return 0;
}

extern "C" int CFunc_PauseAllSounds(int params) {
    int p = 1;
    func_0027D1F8(params, 0x28656D12, &p, 0);
    if (p == 1) {
        func_002E7C08();
    } else {
        func_002E7C30();
    }
    return 1;
}

extern "C" int CFunc_SetPositionalSoundSilenceOverrideMode(int params) {
    int v = 1;
    func_0027D1F8(params, 0, &v, 1);
    D_00370AE0->unk4 = v != 0;
    return 1;
}

extern "C" int CFunc_OutputFModCPUUsage(void) {
    return 1;
}

extern "C" int CFunc_DumpSounds(void) {
    return 1;
}

extern "C" int CFunc_EnableRemoveSoundEntry(void) {
    return 0;
}

extern "C" int CFunc_TerrainSoundCalculatePitchAndVolFast(void) {
    return 0;
}

extern "C" int CFunc_IsFmodEnabled(void) {
    return 0;
}

extern "C" int CFunc_EnableUserMusic(void) {
    return 0;
}

extern "C" void func_00256340(S2562_Surf *out, int params) {
    func_0027D268(params, 0xB83FD2C4, &out->unk0, 0);
    func_0027D268(params, 0x46393859, &out->unk8, 0);
    func_0027D268(params, 0xE9F3E637, &out->unkC, 0);
    func_0027D268(params, 0x2D1BD620, &out->unk10, 0);
    func_0027D268(params, 0x61B8FCE2, &out->unk18, 0);
    int a = 0;
    int b = 0;
    int c = 0;
    func_0027D1F8(params, 0x4A1295A1, &a, 0);
    func_0027D1F8(params, 0x01DAD3EB, &b, 0);
    func_0027D1F8(params, 0xF0FEE45B, &c, 0);
    out->unk4 = a;
    out->unk14 = b;
    out->unk1C = c;
}

INCLUDE_ASM("asm/nonmatchings/game/t_256260", CFunc_AddSfxHeader);

INCLUDE_ASM("asm/nonmatchings/game/t_256260", CFunc_HackSetReverbPlease);

extern "C" int CFunc_HackSetEffect(void) {
    return 0;
}

extern "C" int CFunc_ResetWhammyPitchShift(int params) {
    u32 id;
    func_0027D870(params, 0, &id, 1);
    int r = 0;
    if (id) {
        func_002E8C08(id);
        r = 1;
    }
    return r;
}

extern "C" void CFunc_EnableMenuMusic(int a) {
    func_002E9C00(!func_0027DF00(a, 0xB0BAB2AE));
}

extern "C" void CFunc_LoadMoreMenuMusic(void) {
    func_002E9818();
}

extern "C" void CFunc_MenuMusicPreloaded(void) {
    func_002E99D0();
}

extern "C" void CFunc_KeyOffAllSfx(void) {
    func_002E8318();
}

extern "C" int CFunc_PauseAllSFX(void) {
    func_002E7BC8();
    return 1;
}

extern "C" int CFunc_UnPauseAllSFX(void) {
    func_002E7BE8();
    return 1;
}

extern "C" int CFunc_SetMenuMusicVolume(int params) {
    int v = 11;
    if (func_0027D1F8(params, 0xF6A36814, &v, 0)) {
        func_002EA758(v * (1.0f / 11.0f));
    }
    return 1;
}

extern "C" void func_00256740(int a, int b) {
}

extern "C" void func_00256748(void) {
    func_00256740(1, 0xFFFF);
}

INCLUDE_ASM("asm/nonmatchings/game/t_256260", CFunc_GetTerrainTypeParam);

INCLUDE_ASM("asm/nonmatchings/game/t_256260", func_00256838);

extern "C" S2562_Arr *func_00256848(int params, S2562_Script *script, int unused) {
    S2562_Arr *r = 0;
    int search = 0;
    bool global = func_0027DF00(params, 0x0281513F);
    if (!func_0027D470(params, 0, &r, 0)) {
        search = script->unk20 != 0;
    }
    if (search) {
        S2562_Comp *p = func_0027B300(params, 0);
        while (p) {
            if (p->type == 0xD) {
                if (global) {
                    r = func_002764E8(p->val, 0);
                } else {
                    func_0027D470(script->unk20, p->val, &r, 0);
                }
                if (r) {
                    goto done;
                }
            }
            p = func_0027B300(params, p);
        }
    }
    return r;
done:
    return r;
}

INCLUDE_ASM("asm/nonmatchings/game/t_256260", CFunc_Wait);

extern "C" int CFunc_WaitOneGameFrame(int a, int b) {
    func_0028C470(b, 1);
    return 1;
}

extern "C" int CFunc_CastToInteger(int params, S2562_Script *script) {
    u32 name = 0;
    bool missing = !func_0027D870(params, 0, &name, 0);
    if (missing) {
        return 0;
    }
    f32 f = 0.0f;
    int v;
    if (func_0027D268(script->unk20, name, &f, 0)) {
        v = (int)f;
    } else {
        int i;
        if (!func_0027D870(script->unk20, name, &i, 0)) {
            return 0;
        }
        v = i;
    }
    func_0027ACF8(script->unk20, name);
    func_0027C160(script->unk20, name, v);
    return 1;
}

extern "C" int CFunc_StringToInteger(int params, S2562_Script *script) {
    u32 name;
    bool missing = !func_0027D870(params, 0, &name, 0);
    if (missing) {
        return 0;
    }
    char *str = D_003704B8;
    missing = !func_0027D188(script->unk20, name, &str, 0);
    if (missing) {
        return 0;
    }
    int v = 0;
    int len = strlen(str);
    char *p = str;
    for (int i = 0; i < len; i++) {
        v = v * 10 + *p - '0';
        p++;
    }
    func_0027ACF8(script->unk20, name);
    func_0027C160(script->unk20, name, v);
    return 1;
}

extern "C" int CFunc_WideStringToInteger(int params, S2562_Script *script) {
    u32 name = 0;
    bool missing = !func_0027D870(params, 0, &name, 0);
    if (missing) {
        return 0;
    }
    char *str;
    missing = !func_0027D188(script->unk20, name, &str, 0);
    int st = script->unk20;
    if (missing) {
        return 0;
    }
    char *p = str;
    int v = 0;
    int sign = 1;
    if (*p == '-') {
        sign = -1;
        p++;
    }
    while (*p) {
        v = v * 10 + *p - '0';
        p++;
    }
    v *= sign;
    func_0027ACF8(st, name);
    func_0027C160(script->unk20, name, v);
    return 1;
}

extern "C" int CFunc_IntegerEquals(int params) {
    int a = 0;
    func_0027D1F8(params, 0x174841BC, &a, 0);
    int b = 0;
    func_0027D1F8(params, 0x8E411006, &b, 0);
    return a == b;
}

extern "C" int CFunc_ChecksumEquals(int params) {
    u32 a = 0;
    func_0027D870(params, 0x174841BC, &a, 0);
    u32 b = 0;
    func_0027D870(params, 0x8E411006, &b, 0);
    return a == b;
}

extern "C" int CFunc_StringEquals(int params) {
    char *a;
    char *b;
    func_0027D188(params, 0x174841BC, &a, 1);
    func_0027D188(params, 0x8E411006, &b, 1);
    int x = func_0028DAB8(a);
    return x == func_0028DAB8(b);
}

extern "C" int CFunc_LocalizedStringEquals(int params) {
    char *a;
    char *b;
    func_0027D188(params, 0x174841BC, &a, 1);
    func_0027D188(params, 0x8E411006, &b, 1);
    return func_001139E0(a, b) == 0;
}

extern "C" int CFunc_ArrayContains(int params) {
    S2562_Arr *a;
    u32 i = 0;
    func_0027D470(params, 0x5EF31148, &a, 1);
    int type = a->type;
    for (; i < a->size; i++) {
        switch (type) {
            case 1: {
                int v;
                func_0027D1F8(params, 0x71059581, &v, 1);
                if (func_0011A5B8(a, i) == v) {
                    return 1;
                }
                break;
            }
            case 0xD: {
                u32 c;
                func_0027D870(params, 0x71059581, &c, 1);
                if (c == (u32)a->Get(i)) {
                    return 1;
                }
                break;
            }
            case 3: {
                char *str;
                func_0027D188(params, 0x71059581, &str, 1);
                if (func_0030E650(str, func_0027EF60(a, i)) == 0) {
                    return 1;
                }
                break;
            }
        }
    }
    return 0;
}

INCLUDE_ASM("asm/nonmatchings/game/t_256260", func_002571C8);

extern "C" int CFunc_GetArraySize(int params, S2562_Script *script) {
    S2562_Arr *a = func_00256848(params, script, 1);
    int i = 0;
    if (func_0027D1F8(params, 0x0BA453B9, &i, 0)) {
        a = a->Get(i);
        if (func_0027D1F8(params, 0x92AD0203, &i, 0)) {
            a = a->Get(i);
            if (func_0027D1F8(params, 0xE5AA3295, &i, 0)) {
                a = a->Get(i);
            }
        }
    }
    int n = 0;
    if (a) {
        n = a->size;
    }
    func_0027C160(script->unk20, 0x7F5B3D4D, n);
    return 1;
}

INCLUDE_ASM("asm/nonmatchings/game/t_256260", CFunc_SetArrayElement);

extern "C" int CFunc_AddParams(int params, S2562_Script *script) {
    int s = script->unk20;
    if (params) {
        func_0027ABB0(s, params);
    }
    return 1;
}

extern "C" {
void func_0027C028(int, u32, int);
void func_0027C448(int, u32, int);
}

extern "C" int CFunc_AddParam(int params, S2562_Script *script) {
    u32 name;
    u32 key;
    int target;
    func_0027D870(params, 0xA1DC81F9, &name, 1);
    target = 0;
    if (func_0027D870(params, 0x10C6F3DB, &key, 0)) {
        func_0027D400(script->unk20, key, &target, 0);
        if (target == 0) {
            target = func_0027AA70(func_001287F0(8, 1));
            func_0027C898(script->unk20, key, target);
        }
    } else {
        target = script->unk20;
    }
    S2562_Comp *p = func_0027B300(params, 0);
    while (p) {
        S2562_Comp *next = func_0027B300(params, p);
        if (p->key == 0xE288A7CB) {
            switch (p->type) {
            case 1:
                func_0027C160(target, name, p->val);
                break;
            case 2:
                func_0027C1F8(target, name, *(f32 *)&p->val);
                break;
            case 13:
                func_0027C448(target, name, p->val);
                break;
            case 3:
                func_0027C028(target, name, p->val);
                break;
            case 10:
                func_0027C7D0(target, name, p->val);
                break;
            case 12:
                func_0027C678(target, name, p->val);
                break;
            }
        }
        p = next;
    }
    return 1;
}

extern "C" int CFunc_RemoveComponent(int params, S2562_Script *script) {
    u32 name;
    bool missing = !func_0027D870(params, 0xA1DC81F9, &name, 0);
    if (missing) {
        func_0027D870(params, 0, &name, 1);
    }
    u32 k;
    int s = script->unk20;
    if (func_0027D870(params, 0x10C6F3DB, &k, 0)) {
        func_0027D400(script->unk20, k, &s, 1);
    }
    func_0027ACF8(s, name);
    return 1;
}

INCLUDE_ASM("asm/nonmatchings/game/t_256260", CFunc_GlobalExists);

extern "C" int CFunc_RemoveParameter(int params, S2562_Script *script) {
    u32 n;
    func_0027D870(params, 0, &n, 0);
    int s = script->unk20;
    func_0027ACF8(s, n);
    func_0027AE70(s, n);
    return 1;
}

extern "C" int CFunc_RemoveFlag(int params, S2562_Script *script) {
    u32 n;
    func_0027D870(params, 0, &n, 0);
    func_0027AE70(script->unk20, n);
    return 1;
}

extern "C" int CFunc_GetRandomValue(int params, S2562_Script *script) {
    u32 name;
    func_0027D870(params, 0xA1DC81F9, &name, 0);
    if (func_0027DF00(params, 0xA5F054F4)) {
        int a = 0;
        int b = 0;
        func_0027D1F8(params, 0x174841BC, &a, 0);
        func_0027D1F8(params, 0x8E411006, &b, 0);
        if (a > b) {
            int t = a;
            a = b;
            b = t;
        }
        int st = script->unk20;
        u32 n = name;
        func_0027C160(st, n, a + func_0010C050(b - a + 1));
    } else {
        int res = 1000;
        func_0027D1F8(params, 0x022CF075, &res, 0);
        f32 a = 0.0f;
        f32 b = 0.0f;
        func_0027D268(params, 0x174841BC, &a, 0);
        func_0027D268(params, 0x8E411006, &b, 0);
        int st = script->unk20;
        u32 n = name;
        func_0027C1F8(st, n, a + (f32)func_0010C050(res) * (b - a) / ((f32)res - 1.0f));
    }
    return 1;
}

INCLUDE_ASM("asm/nonmatchings/game/t_256260", CFunc_ForEachIn);

extern "C" int CFunc_GetElement(int params, S2562_Script *script) {
    S2562_Arr *r = func_00256848(params, script, 0);
    int idx = 0;
    func_0027D1F8(params, 0x7F8C98FE, &idx, 0);
    func_0027ACF8(script->unk20, 0xBEBFA1C6);
    if (!r) {
        return 1;
    }
    if (idx < 0) {
        return 0;
    }
    int n = r->size;
    if (!(idx < n)) {
        return 0;
    }
    switch (r->type) {
    case 10: {
        int o = func_0027AA70(func_001287F0(8, 1));
        int v = r->GetI(idx);
        if (v) {
            func_0027ABB0(o, v);
        }
        func_0027C898(script->unk20, 0xBEBFA1C6, o);
        return 1;
    }
    case 12: {
        int st = script->unk20;
        func_0027C678(st, 0xBEBFA1C6, r->GetI(idx));
        return 1;
    }
    case 1: {
        int st = script->unk20;
        int v = func_0011A5B8(r, idx);
        func_0027C160(st, 0xBEBFA1C6, v);
        return 1;
    }
    }
    return 1;
}

extern "C" f32 func_0027EFA0(S2562_Arr *, int);

extern "C" int CFunc_GetNextArrayElement(int params, S2562_Script *script) {
    S2562_Arr *r = func_00256848(params, script, 0);
    int idx = -1;
    func_0027D1F8(script->unk20, 0x7F8C98FE, &idx, 0);
    func_0027ACF8(script->unk20, 0x7F8C98FE);
    func_0027ACF8(script->unk20, 0xBEBFA1C6);
    if (!r) {
        return 0;
    }
    int n = r->size;
    if (idx < 0) {
        idx = 0;
        if (n == 0) {
            return 0;
        }
    } else {
        idx++;
        if (!(idx < n)) {
            return 0;
        }
    }
    switch (r->type) {
    case 10: {
        int st = script->unk20;
        register u32 key asm("$5") = 0xBEBFA1C6;
        func_0027C7D0(st, key, r->GetI(idx));
        break;
    }
    case 12: {
        int st = script->unk20;
        register u32 key asm("$5") = 0xBEBFA1C6;
        func_0027C678(st, key, r->GetI(idx));
        break;
    }
    case 1: {
        int st = script->unk20;
        register u32 key asm("$5") = 0xBEBFA1C6;
        func_0027C160(st, key, r->GetI(idx));
        break;
    }
    case 2: {
        int st = script->unk20;
        func_0027C1F8(st, 0xBEBFA1C6, func_0027EFA0(r, idx));
        break;
    }
    case 13: {
        int st = script->unk20;
        register u32 key asm("$5") = 0xBEBFA1C6;
        func_0027C448(st, key, r->GetI(idx));
        break;
    }
    case 3: {
        int st = script->unk20;
        func_0027C028(st, 0xBEBFA1C6, (int)func_0027EF60(r, idx));
        break;
    }
    }
    func_0027C160(script->unk20, 0x7F8C98FE, idx);
    return 1;
}
