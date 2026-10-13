// cflags: -funroll-loops
#include "common.h"

struct S_00146E68 { char pad0[0x5B4]; int unk5B4; };
struct S_00148248 { char pad0[0x34]; float unk34; };
struct S_00148250 { char pad0[0x38]; float unk38; };
struct S_00148348 { char pad0[0x250]; int unk250; };

struct R_146 { void* p; int unk4; int unk8; };
struct P_146 { char pad0[0x20]; void* unk20; };
struct S_001482F8 { char pad0[0x8]; void* unk8; char padC[0x244]; int unk250; };

struct VE_146 { s16 delta; s16 unk2; void* fn; };
struct O_146 { char pad0[0x8]; VE_146* unk8; };
struct Sys_146 { char pad0[0x2C]; VE_146* unk2C; char pad30[0x1C]; R_146 unk4C; };
struct S_00148490 { char pad0[0x8]; void* unk8; char padC[0x234]; int unk240; int unk244; int unk248; int unk24C; int unk250; int unk254; char pad258[4]; int unk25C; float unk260; int unk264; int unk268; int unk26C; int unk270; };

struct O2_146 { char pad0[0x2C]; int unk2C; };

struct O3_146 { char pad0[0xA0]; char unkA0[0x150]; float unk1F0; float unk1F4; };

struct O4_146 { char pad0[0x240]; int unk240; };

extern "C" {
int func_0027D1F8(void*, int, int*, int);
int func_0013A060(void*);
float func_00148248(S_00148248*);
float func_00148250(S_00148250*);
void func_0027C160(void*, u32, int);
float func_00139580(void*);
float func_00139588(void*);
void func_00139590(void*, float*, float*);
void func_001395A8(void*, float*, float*);
void func_0027C5B0(void*, u32, float, float);
void func_001CEDE0(void*, u32);
int func_0015BAB0(int, int, int, int);
void func_00139840(void*, float, float);
void func_001395D8(void*, int, float, float);
void func_001397A8(void*, int, float, float);
void func_00144FC0(int, int, bool, bool, void*);
int func_0027D870(void*, u32, int*, int);
extern int D_00372DA8;
void func_00144BC0(R_146*, int, int, int, void*);
extern int D_00368A38;
void func_00145310(R_146*, Sys_146*, int, int);
u32 func_0013CFC0(void*);
void func_001CE868(void*, R_146*);
void* func_00138F20(void*);
bool func_0027DF00(void*, u32);
void func_00139EE0(void*, int);
int func_00119610(int, int);
void func_00119490(int, int);
void func_001194B8(int);
void* operator_new(int);
void* func_00148258(void*);
void* func_0013CC28(void*);
void func_001CED20(void*, u32);
extern int D_00369798;
void func_00145488(R_146*, int, void*, u32, int);
int func_00145B10(int, void*, u32, int*);
void func_001CE888(void*, R_146*);
void func_00146DE0(int, int);
void func_0027C448(void*, u32, int);
extern u8 D_0033B638[];
extern u8 D_0033B8B0[];
void func_0015BB20(int);
void func_0013CC70(void*, int);
void func_00139420(void*);
}

INCLUDE_ASM("asm/nonmatchings/game/t_146580", func_00146580);

INCLUDE_ASM("asm/nonmatchings/game/t_146580", func_00146778);

extern "C" void func_001468A0(void) {
}

struct S_1468A8 { char pad0[0x6A8]; int unk6A8[1]; char pad6AC[0xBC]; int unk768; };

extern "C" int func_001468A8(S_1468A8* self, int v) {
    int i;
    for (i = 0; i < self->unk768; i++) {
        if (v == self->unk6A8[i]) {
            return 1;
        }
    }
    return 0;
}

INCLUDE_ASM("asm/nonmatchings/game/t_146580", func_00146970);

INCLUDE_ASM("asm/nonmatchings/game/t_146580", func_00146C10);

extern "C" void func_00146DE0(int sys, int id) {
    Sys_146* self = (Sys_146*)sys;
    R_146 r;
    func_00145310(&r, self, id, 1);
    R_146* d = &self->unk4C;
    if (d->p) {
        func_001CE888(d->p, d);
        d->p = 0;
    }
    d->p = r.p;
    if (d->p) {
        func_001CE868(d->p, d);
    }
    if (r.p) {
        func_001CE888(r.p, &r);
        r.p = 0;
    }
}

extern "C" int func_00146E68(S_00146E68* self) {
    return self->unk5B4 > 0;
}

struct E_146E78 { u32 unk0; int unk4; char pad8[0x10]; };
struct S_146E78 { char pad0[0x5C8]; E_146E78 unk5C8[10]; };

extern "C" int func_00146E78(S_146E78* self, int id) {
    int i;
    u32 m = 0;
    R_146 r;
    func_00145310(&r, (Sys_146*)self, id, 1);
    u32 v = func_0013CFC0(r.p);
    for (i = 0; i < 10; i++) {
        if (self->unk5C8[i].unk4 != 0) {
            u32 t = self->unk5C8[i].unk0;
            m = m < t ? t : m;
        }
    }
    int eq = v == m;
    if (r.p) {
        func_001CE888(r.p, &r);
        r.p = 0;
    }
    return eq;
}

GP_DATA(D_00369798);
extern "C" int CFunc_CreateScreenElement(void* params, P_146* script) {
    int type;
    func_0027D870(params, 0x7321A8D6, &type, 0);
    int id = D_00372DA8;
    func_0027D870(params, 0x40C698AF, &id, 0);
    R_146 r;
    func_00144BC0(&r, D_00369798, type, id, params);
    id = 0xB7A78544;
    if (r.p) {
        id = ((O2_146*)r.p)->unk2C;
    }
    func_0027C448(script->unk20, 0x40C698AF, id);
    if (r.p) {
        func_001CE888(r.p, &r);
        r.p = 0;
    }
    return 1;
}

extern "C" int CFunc_DestroyScreenElement(void* params, void* script) {
    int sys = D_00369798;
    int id;
    if (!func_00145B10(sys, params, 0x40C698AF, &id)) {
        return 0;
    }
    bool a = !func_0027DF00(params, 0x4D374A6D);
    bool b = func_0027DF00(params, 0xF42548F8);
    if (!a && b) {
        return 1;
    }
    func_00144FC0(sys, id, a, b, script);
    return 1;
}

INCLUDE_ASM("asm/nonmatchings/game/t_146580", CFunc_RunScriptOnScreenElement);

extern "C" int CFunc_SetScreenElementProps(void* params) {
    int heap = D_00368A38;
    func_00119490(heap, func_00119610(heap, 0x3A));
    R_146 r;
    func_00145488(&r, D_00369798, params, 0x40C698AF, 1);
    O_146* o = (O_146*)r.p;
    VE_146* e = &o->unk8[2];
    ((void (*)(void*, void*))e->fn)((char*)o + e->delta, params);
    func_001194B8(D_00368A38);
    if (r.p) {
        func_001CE888(r.p, &r);
        r.p = 0;
    }
    return 1;
}

GP_DATA(D_00369798);
extern "C" int CFunc_DoScreenElementMorph(void* params) {
    R_146 r;
    func_00145488(&r, D_00369798, params, 0x40C698AF, 1);
    O_146* o = (O_146*)r.p;
    VE_146* e = &o->unk8[12];
    ((void (*)(void*, void*))e->fn)((char*)o + e->delta, params);
    if (r.p) {
        func_001CE888(r.p, &r);
        r.p = 0;
    }
    return 1;
}

extern "C" int CFunc_SetScreenElementLock(void* params) {
    R_146 r;
    func_00145488(&r, D_00369798, params, 0x40C698AF, 1);
    if (func_0027DF00(params, 0xD443A2BC)) {
        func_00139EE0(r.p, 0);
    } else {
        func_00139EE0(r.p, 1);
    }
    if (r.p) {
        func_001CE888(r.p, &r);
        r.p = 0;
    }
    return 1;
}

extern "C" int CFunc_ScreenElementSystemInit(void) {
    int heap = D_00368A38;
    func_00119490(heap, func_00119610(heap, 0x3A));
    void* e = func_00148258(operator_new(0x260));
    func_001194B8(D_00368A38);
    func_001CED20(e, 0x56A1EAE3);
    Sys_146* sys = (Sys_146*)D_00369798;
    VE_146* v = &sys->unk2C[2];
    ((void (*)(void*, void*))v->fn)((char*)sys + v->delta, e);
    return 1;
}

extern "C" int CFunc_GetScreenElementDims(void* params, P_146* script) {
    R_146 r;
    func_00145488(&r, D_00369798, params, 0x40C698AF, 1);
    float w = ((O3_146*)r.p)->unk1F0;
    int iw = (int)(w * func_00148248((S_00148248*)((O3_146*)r.p)->unkA0));
    float h = ((O3_146*)r.p)->unk1F4;
    int ih = (int)(h * func_00148250((S_00148250*)((O3_146*)r.p)->unkA0));
    func_0027C160(script->unk20, 0x73E5BAD0, iw);
    func_0027C160(script->unk20, 0x0AB21AF0, ih);
    if (r.p) {
        func_001CE888(r.p, &r);
        r.p = 0;
    }
    return 1;
}

extern "C" int CFunc_GetScreenElementPosition(void* params, P_146* script) {
    R_146 r;
    func_00145488(&r, D_00369798, params, 0x40C698AF, 1);
    float x, y;
    if (func_0027DF00(params, 0x592089A9)) {
        x = func_00139580(r.p);
        y = func_00139588(r.p);
    } else if (func_0027DF00(params, 0x74297717)) {
        func_00139590(r.p, &x, &y);
    } else {
        func_001395A8(r.p, &x, &y);
    }
    func_0027C5B0(script->unk20, 0x062A4596, x, y);
    if (r.p) {
        func_001CE888(r.p, &r);
        r.p = 0;
    }
    return 1;
}

extern "C" int CFunc_MenuSelectedIndexIs(void* params) {
    R_146 r;
    func_00145488(&r, D_00369798, params, 0x40C698AF, 1);
    O4_146* o = (O4_146*)r.p;
    int sel = o->unk240;
    if (sel == -1) {
        if (r.p) {
            func_001CE888(r.p, &r);
            r.p = 0;
        }
        return 0;
    }
    int res = 0;
    int idx;
    if (func_0027D1F8(params, 0, &idx, 0)) {
        res = sel == idx;
    } else if (func_0027DF00(params, 0x6D8E11A8)) {
        res = sel == 0;
    } else if (func_0027DF00(params, 0xB524565F)) {
        res = sel == func_0013A060(o) - 1;
    }
    if (r.p) {
        func_001CE888(r.p, &r);
        r.p = 0;
    }
    return res;
}

GP_DATA(D_00369798);
extern "C" int CFunc_ScreenElementExists(void* params) {
    R_146 r;
    func_00145488(&r, D_00369798, params, 0x40C698AF, 0);
    if (r.p) {
        func_001CE888(r.p, &r);
        r.p = 0;
        return 1;
    }
    return 0;
}

INCLUDE_ASM("asm/nonmatchings/game/t_146580", CFunc_GetScreenElementProps);

extern "C" int CFunc_SetRootScreenElement(void* params) {
    int sys = D_00369798;
    int id;
    if (func_00145B10(sys, params, 0x40C698AF, &id)) {
        func_00146DE0(sys, id);
        return 1;
    }
    return 0;
}

INCLUDE_ASM("asm/nonmatchings/game/t_146580", CFunc_CreateMultipleTextElements);

INCLUDE_ASM("asm/nonmatchings/game/t_146580", CFunc_GetScreenElementChildren);

extern "C" int CFunc_ResolveScreenElementID(void* params, P_146* script) {
    int id = 0;
    if (func_00145B10(D_00369798, params, 0x40C698AF, &id)) {
        func_0027C448(script->unk20, 0x28E66B14, id);
        return 1;
    }
    return 0;
}

INCLUDE_ASM("asm/nonmatchings/game/t_146580", func_001481D0);

extern "C" int CFunc_DumpScreenElements(void) {
    return 1;
}

INCLUDE_ASM("asm/nonmatchings/game/t_146580", func_001481E0);

extern "C" float func_00148248(S_00148248* self) {
    return self->unk34;
}

extern "C" float func_00148250(S_00148250* self) {
    return self->unk38;
}

extern "C" void* func_00148258(void* p) {
    S_001482F8* self = (S_001482F8*)p;
    func_0013CC28(self);
    self->unk8 = D_0033B638;
    func_001CEDE0(self, 0xA13ADBB7);
    self->unk250 = func_0015BAB0(0, 0, 0x280, 0x1C0);
    func_00139840(self, -1.0f, -1.0f);
    func_001395D8(self, 1, 0.0f, 0.0f);
    func_001397A8(self, 0, 640.0f, 448.0f);
    return self;
}

extern "C" void func_001482F8(S_001482F8* self, int flags) {
    self->unk8 = D_0033B638;
    func_0015BB20(self->unk250);
    func_0013CC70(self, flags);
}

extern "C" int func_00148348(S_00148348* self) {
    return self->unk250;
}

extern "C" void func_00148350(int* a, int* b, int n) {
    if (*a < 0) {
        *b += *a;
        *a = 0;
        if (*b < 0) {
            *b = 0;
        }
    } else if (*a + *b > n) {
        if (*a < n) {
            *b = n - *a;
        } else {
            *a = n - 1;
            *b = 0;
        }
    }
}

INCLUDE_ASM("asm/nonmatchings/game/t_146580", func_001483B0);

INCLUDE_ASM("asm/nonmatchings/game/t_146580", func_00148490);

extern "C" void func_00148508(S_001482F8* self) {
    self->unk8 = D_0033B8B0;
    func_00139420(self);
}

INCLUDE_ASM("asm/nonmatchings/game/t_146580", func_00148530);
