#include "common.h"

extern "C" {
int func_0027D268(int, int, f32 *, int);
void func_0027C1F8(int, int, f32);
f32 func_0031B970(f32, f32);
void func_0010C170(int, int, int, int, int, int);
void func_0010C120(int *, int *, int *, int *, int *, int *);
int func_0027D1F8(int, int, int *, int);
void func_0027C160(int, int, int);
extern int D_003E7F60[];
void *func_0027AF38(int, int, int);
int func_00289CF8(s32);
}

struct SCCGCI {
    char pad0[0x20];
    int unk20;
};
extern "C" s32 CFunc_CameraCut_GetCameraIndex(int arg0, SCCGCI *arg1) {
    int out;
    func_0027D1F8(arg0, 0xD6445C38, &out, 1);
    func_0027C160(arg1->unk20, 0xD6445C38, D_003E7F60[out]);
    return 1;
}

struct S2C34C8 {
    char pad0[8];
    u32 unk8;
};
extern "C" void func_002C34C8(int a) {
    S2C34C8 *p = (S2C34C8 *)func_0027AF38(a, 0x26205DB6, 0);
    if (p != 0) {
        if (p->unk8 == 0x3AC1877C) {
            p->unk8 = 0x6E965B60;
        } else {
            p->unk8 = 0x3AC1877C;
        }
    }
}

struct SCSLA {
    char pad0[0x20];
    int unk20;
};
extern "C" {
int func_002763E0(u32, int);
int func_0027D870(int, u32, int *, int);
int func_0027D400(int, u32, int *, int);
}
extern "C" s32 CFunc_CameraCut_SwapLookAts(int arg0, SCSLA *arg1) {
    int type;
    int a;
    int b;
    int c;
    func_0027D870(func_002763E0(0xD95930AC, 1), 0x765E3856, &type, 1);
    if (type == 0x6E965B60) {
        func_0027D400(arg1->unk20, 0xB4347460, &a, 1);
        func_002C34C8(a);
        if (func_0027D400(a, 0x7031F10C, &b, 0)) {
            func_002C34C8(b);
            if (func_0027D400(b, 0x3FB0CCC9, &c, 0)) {
                func_002C34C8(c);
            }
            if (func_0027D400(b, 0xA6B99D73, &c, 0)) {
                func_002C34C8(c);
            }
        }
    }
    return 1;
}

extern "C" int CFunc_GetRandomSeeds(int arg0, SCCGCI *script) {
    int v[6];
    func_0010C120(&v[0], &v[1], &v[2], &v[3], &v[4], &v[5]);
    func_0027C160(script->unk20, 0x9504329E, v[0]);
    func_0027C160(script->unk20, 0x0C0D6324, v[1]);
    func_0027C160(script->unk20, 0x7B0A53B2, v[2]);
    func_0027C160(script->unk20, 0xE56EC611, v[3]);
    func_0027C160(script->unk20, 0x9269F687, v[4]);
    func_0027C160(script->unk20, 0x0B60A73D, v[5]);
    return 1;
}

extern "C" int CFunc_SetRandomSeeds(int arg0) {
    int v0, v1, v2, v3, v4, v5;
    func_0027D1F8(arg0, 0x9504329E, &v0, 1);
    func_0027D1F8(arg0, 0x0C0D6324, &v1, 1);
    func_0027D1F8(arg0, 0x7B0A53B2, &v2, 1);
    func_0027D1F8(arg0, 0xE56EC611, &v3, 1);
    func_0027D1F8(arg0, 0x9269F687, &v4, 1);
    func_0027D1F8(arg0, 0x0B60A73D, &v5, 1);
    func_0010C170(v0, v1, v2, v3, v4, v5);
    return 1;
}

INCLUDE_ASM("asm/nonmatchings/game/t_2C3468", CFunc_SetNewWhammyValue);

INCLUDE_ASM("asm/nonmatchings/game/t_2C3468", CFunc_SetAllWhammyValues);

struct S2C3468_BD {
    int key;
    int a;
    int o;
    f32 f[11];
};
extern "C" {
bool func_0027D870_b(int, u32, int *, int) asm("func_0027D870");
bool func_0027D268_b(int, int, f32 *, int) asm("func_0027D268");
void func_0027C5B0(int, u32, f32, f32);
}

extern "C" int CFunc_SetButtonData(int params) {
    S2C3468_BD l;
    if (!func_0027D870(params, 0x99A9B716, &l.key, 0)) return 0;
    bool m = !func_0027D870_b(params, 0x5EF31148, &l.a, 0);
    if (m) return 0;
    int t = func_002763E0(l.a, 0);
    l.o = 0;
    func_0027D400(t, l.key, &l.o, 0);
    if (func_0027D268(params, 0x960061E4, &l.f[0], 0)) {
        bool m1 = !func_0027D268_b(params, 0xE1075172, &l.f[1], 0);
        if (m1) return 0;
        bool m2 = !func_0027D268_b(params, 0x9DFC39BC, &l.f[2], 0);
        if (m2) return 0;
        func_0027C5B0(l.o, 0xE7B824CE, l.f[0], l.f[1]);
        func_0027C5B0(l.o, 0x82030150, l.f[2], l.f[1]);
        return 1;
    }
    bool n0 = !func_0027D268_b(params, 0xFF7EBAF6, &l.f[3], 0);
    if (n0) return 0;
    bool n1 = !func_0027D268_b(params, 0x7AC1EB13, &l.f[4], 0);
    if (n1) return 0;
    bool n2 = !func_0027D268_b(params, 0x0DC6DB85, &l.f[5], 0);
    if (n2) return 0;
    bool n3 = !func_0027D268_b(params, 0x9FD5AB86, &l.f[6], 0);
    if (n3) return 0;
    bool n4 = !func_0027D268_b(params, 0xE8D29B10, &l.f[7], 0);
    if (n4) return 0;
    bool n5 = !func_0027D268_b(params, 0x6D13EE75, &l.f[8], 0);
    if (n5) return 0;
    bool n6 = !func_0027D268_b(params, 0x9429F3DE, &l.f[9], 0);
    if (n6) return 0;
    bool n7 = !func_0027D268_b(params, 0xF482E2AE, &l.f[10], 0);
    if (n7) return 0;
    func_0027C5B0(l.o, 0x734D06F5, l.f[4], l.f[5]);
    func_0027C5B0(l.o, 0x09A7DC2E, l.f[6], l.f[7]);
    func_0027C5B0(l.o, 0x30802989, l.f[8], l.f[5]);
    func_0027C5B0(l.o, 0x1E75D948, l.f[9], l.f[7]);
    func_0027C1F8(l.o, 0xFF7EBAF6, l.f[3]);
    func_0027C1F8(l.o, 0xF482E2AE, l.f[10]);
    return 1;
}

extern "C" s32 CFunc_ATan2(int arg0, SCCGCI *arg1) {
    f32 x;
    f32 y;
    func_0027D268(arg0, 0x0424D9EA, &x, 1);
    func_0027D268(arg0, 0x7323E97C, &y, 1);
    func_0027C1F8(arg1->unk20, 0xD83566B0, func_0031B970(x, y) * 57.295776f);
    return 1;
}

extern "C" s32 CFunc_Init2DParticles(void) {
    return 1;
}

extern "C" s32 CFunc_Exit2DParticles(void) {
    return 1;
}

extern "C" s32 CFunc_Create2DParticleSystem(void) {
    return 1;
}

extern "C" s32 CFunc_Destroy2DParticleSystem(void) {
    return 0;
}

extern "C" s32 CFunc_Update2DParticleSystems(void) {
    return 1;
}

INCLUDE_ASM("asm/nonmatchings/game/t_2C3468", CFunc_ButtonCheckerInit);

INCLUDE_ASM("asm/nonmatchings/game/t_2C3468", CFunc_ButtonCheckerPerFrame);

extern "C" s32 CFunc_ButtonCheckerCleanup(int arg0, s32 arg1) {
    func_00289CF8(arg1);
    return 1;
}

INCLUDE_ASM("asm/nonmatchings/game/t_2C3468", func_002C5308);
