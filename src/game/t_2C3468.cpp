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

INCLUDE_ASM("asm/nonmatchings/game/t_2C3468", CFunc_CameraCut_SwapLookAts);

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

INCLUDE_ASM("asm/nonmatchings/game/t_2C3468", CFunc_SetButtonData);

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
