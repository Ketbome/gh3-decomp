#include "common.h"

extern "C" {
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

INCLUDE_ASM("asm/nonmatchings/game/t_2C3468", CFunc_GetRandomSeeds);

INCLUDE_ASM("asm/nonmatchings/game/t_2C3468", CFunc_SetRandomSeeds);

INCLUDE_ASM("asm/nonmatchings/game/t_2C3468", CFunc_SetNewWhammyValue);

INCLUDE_ASM("asm/nonmatchings/game/t_2C3468", CFunc_SetAllWhammyValues);

INCLUDE_ASM("asm/nonmatchings/game/t_2C3468", CFunc_SetButtonData);

INCLUDE_ASM("asm/nonmatchings/game/t_2C3468", CFunc_ATan2);

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
