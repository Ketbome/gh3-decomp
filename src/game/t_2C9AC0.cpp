#include "common.h"

struct S2C9_Script {
    char pad0[0x20];
    int unk20;
};

struct S2C9_Var {
    char pad0[0x8];
    int unk8;
};

asm(".set D_0036CA50_lui, D_0036CA50");
asm(".set D_0036CA80_lui, D_0036CA80");
asm(".set D_0036CA5C_lui, D_0036CA5C");

struct S2CA618_Arr {
    int unk0;
    int size;
    int data;
    int Get(int i) {
        if (size == 1) {
            return data;
        }
        return ((int *)data)[i];
    }
};

extern "C" {
int func_00275F08(int, int);
S2CA618_Arr *func_002764E8(int, int);
extern s32 D_0036C378[] __attribute__((section(".sdata")));
extern s32 D_0036CA50;
extern s32 D_0036CA5C;
extern s32 D_0036CA80;
extern s32 D_00370E40;
extern int D_0038C9A0[];
extern int D_0038C9F0[];
int func_0019EE38(int, int, int, int);
int func_001A9E88(void *);
int func_00289CF8(s32);
extern s32 D_0036CA50_lui[] asm("D_0036CA50_lui") __attribute__((section(".sdata")));
extern s32 D_0036CA80_lui[] asm("D_0036CA80_lui") __attribute__((section(".sdata")));
extern s32 D_0036CA5C_lui[] asm("D_0036CA5C_lui") __attribute__((section(".sdata")));
void func_00289C88(void *, int);
int *func_00289C80(void *);
bool func_0027D870(int, u32, void *, int);
int func_0027D1F8(int, u32, void *, int);
S2C9_Var *func_0027AF38(int, u32, int);
extern int D_00373188[];
extern int D_00373180[];
extern int D_00372180[2];
int func_002763E0(u32, int);
void func_0027D400(int, u32, void *, int);
int func_0027D828(int, u32);
extern char D_00372188[];
u32 func_001150E0(u32, char *);
}

GP_DATA(D_00372180);
extern "C" int CFunc_SetLastGuitarVolume(int params) {
    int i;
    if (func_0027D1F8(params, 0x67E6859A, &i, 0)) {
        i--;
        int v;
        if (func_0027D1F8(params, 0xFF7E8B7E, &v, 0)) {
            D_00372180[i] = v;
            return 1;
        }
    }
    return 0;
}

INCLUDE_ASM("asm/nonmatchings/game/t_2C9AC0", CFunc_UpdateNixie);

INCLUDE_ASM("asm/nonmatchings/game/t_2C9AC0", CFunc_KillPulsateStarPowerBulbs);

extern "C" s32 CFunc_ClearSceneGraph(void) {
    func_001A9E88(D_0038C9A0);
    func_001A9E88(D_0038C9F0);
    return 1;
}

extern "C" s32 CFunc_ShowStencilShadow(void) {
    D_0036CA50 = 1;
    return 1;
}

extern "C" s32 CFunc_HideStencilShadow(void) {
    D_0036CA50_lui[0] = 0;
    return 1;
}

extern "C" s32 CFunc_SetMasterBloom(void) {
    D_0036CA80 = 1;
    return 1;
}

extern "C" s32 CFunc_ClearMasterBloom(void) {
    D_0036CA80_lui[0] = 0;
    return 1;
}

extern "C" s32 CFunc_ShowDOF(void) {
    D_0036CA5C = 1;
    return 1;
}

extern "C" s32 CFunc_HideDOF(void) {
    D_0036CA5C_lui[0] = 0;
    return 1;
}

extern "C" s32 CFunc_MoviePlayerAllowController2(void) {
    D_00370E40 = 1;
    return 1;
}

extern "C" s32 CFunc_BlankScreen(void) {
    func_0019EE38(0, 0, 0, 0);
    D_0036C378[0] = 2;
    return 1;
}

extern "C" int CFunc_StarPowerFastTest_Initialise(int params, void *script) {
    func_00289C88(script, 4);
    int *p = func_00289C80(script);
    u32 k;
    func_0027D870(params, 0x1BFF0C3D, &k, 1);
    *p = func_002763E0(k, 0);
    return 1;
}

extern "C" s32 CFunc_StarPowerFastTest_Cleanup(int arg0, s32 arg1) {
    func_00289CF8(arg1);
    return 1;
}

INCLUDE_ASM("asm/nonmatchings/game/t_2C9AC0", CFunc_StarPowerFastTest);

INCLUDE_ASM("asm/nonmatchings/game/t_2C9AC0", CFunc_GuitarEvent_HitNotes_CFunc);

extern "C" int CFunc_handle_hit_note_CFunc(int params, S2C9_Script *script) {
    u32 k;
    func_0027D870(script->unk20, 0x0830ECAF, &k, 1);
    S2C9_Var *v = func_0027AF38(func_002763E0(func_001150E0(k, D_00372188), 1), 0x5D2258D2, 0);
    if (v->unk8 == 0x0203B372) {
        v->unk8 = 0xD43297CF;
    }
    return 1;
}

extern "C" int CFunc_Increment(int params, S2C9_Script *script) {
    u32 k;
    func_0027D870(params, 0, &k, 1);
    S2C9_Var *v = func_0027AF38(script->unk20, k, 0);
    v->unk8++;
    return 1;
}

extern "C" void func_002CA618(int a, int *p) {
    int v = 2;
    S2CA618_Arr *t = func_002764E8(a, 0);
    if (t) {
        int n = t->size;
        if (n) {
            int i = n - func_00275F08(0xF0F1A160, 1);
            int x = t->Get(i);
            int y = t->Get(i + 1);
            v = x + y;
        }
    }
    if (*p < v) {
        *p = v;
    }
}

INCLUDE_ASM("asm/nonmatchings/game/t_2C9AC0", func_002CA6E8);

INCLUDE_ASM("asm/nonmatchings/game/t_2C9AC0", func_002CA818);

INCLUDE_ASM("asm/nonmatchings/game/t_2C9AC0", func_002CA888);

extern "C" int CFunc_fretbar_iterator_CFunc_Setup(int params, void *script) {
    func_00289C88(script, 0x74);
    *func_00289C80(script) = 0;
    return 1;
}

extern "C" s32 CFunc_fretbar_iterator_CFunc_Cleanup(int arg0, s32 arg1) {
    func_00289CF8(arg1);
    return 1;
}

INCLUDE_ASM("asm/nonmatchings/game/t_2C9AC0", CFunc_fretbar_iterator_CFunc);

extern "C" int CFunc_fretbar_update_hammer_on_tolerance_CFunc_Setup(int params, void *script) {
    func_00289C88(script, 0x30);
    *func_00289C80(script) = 0;
    return 1;
}

extern "C" s32 CFunc_fretbar_update_hammer_on_tolerance_CFunc_Cleanup(int arg0, s32 arg1) {
    func_00289CF8(arg1);
    return 1;
}

INCLUDE_ASM("asm/nonmatchings/game/t_2C9AC0", CFunc_fretbar_update_hammer_on_tolerance_CFunc);

extern "C" int CFunc_fretbar_update_tempo_CFunc_Setup(int params, void *script) {
    func_00289C88(script, 0x34);
    *func_00289C80(script) = 0;
    return 1;
}

extern "C" s32 CFunc_fretbar_update_tempo_CFunc_Cleanup(int arg0, s32 arg1) {
    func_00289CF8(arg1);
    return 1;
}

INCLUDE_ASM("asm/nonmatchings/game/t_2C9AC0", CFunc_fretbar_update_tempo_CFunc);
