#include "common.h"

struct SHT_N {
    int key;
    int val;
    SHT_N *next;
};
struct SHT {
    int bits;
    SHT_N *tab;
    char pad8[0xD];
    u8 unk15;
};
static inline int SHT_Find(SHT *t, const int &k) {
    SHT_N *n;
    if (t->tab == 0) {
        return 0;
    }
    n = &t->tab[k & ((1 << t->bits) - 1)];
    if (n == 0) {
        return 0;
    }
    do {
        if (n->key == k) {
            int v = n->val;
            if (t->unk15 != 0 || v != 0) {
                return v;
            }
        }
        n = n->next;
    } while (n);
    return 0;
}

extern "C" {
int func_0027D870(int, int, int *, int);
extern SHT D_003AD040;
extern s32 D_00368A38[] __attribute__((section(".sdata")));
extern s32 D_00371FF0;
extern s32 D_003720D0;
s32 Heap_Alloc(s32, int, int, int);
s32 func_002D58B0(s32, int, int);
int func_002D5B48(s32, int);
}

extern "C" s32 CFunc_SetNetworkPreference(void) {
    return 0;
}

GP_DATA(D_00371FF0);
extern "C" s32 CFunc_InitAtoms(void) {
    if (D_00371FF0 == 0) {
        D_00371FF0 = func_002D58B0(Heap_Alloc(D_00368A38[0], 0x1C, 1, 0), 2, 0);
    }
    return 1;
}

extern "C" s32 CFunc_DeinitAtoms(void) {
    if (D_00371FF0 != 0) {
        func_002D5B48(D_00371FF0, 3);
    }
    return 1;
}

INCLUDE_ASM("asm/nonmatchings/game/t_2BCDA8", CFunc_DeRegisterAtoms);

INCLUDE_ASM("asm/nonmatchings/game/t_2BCDA8", CFunc_RegisterAtoms);

INCLUDE_ASM("asm/nonmatchings/game/t_2BCDA8", CFunc_UpdateAtoms);

INCLUDE_ASM("asm/nonmatchings/game/t_2BCDA8", CFunc_ClearGlobalTags);

INCLUDE_ASM("asm/nonmatchings/game/t_2BCDA8", CFunc_SetGlobalTags);

INCLUDE_ASM("asm/nonmatchings/game/t_2BCDA8", CFunc_GetGlobalTags);

INCLUDE_ASM("asm/nonmatchings/game/t_2BCDA8", CFunc_PushGlobalTags);

INCLUDE_ASM("asm/nonmatchings/game/t_2BCDA8", CFunc_PopGlobalTags);

extern "C" int CFunc_GlobalTagExists(int arg0) {
    int out;
    int k;
    func_0027D870(arg0, 0, &out, 1);
    k = out;
    return SHT_Find(&D_003AD040, k) != 0;
}

extern "C" s32 CFunc_OutputGlobalTags(void) {
    return 1;
}

extern "C" int func_002BDC48(int arg0) {
    int k = arg0;
    return SHT_Find(&D_003AD040, k);
}

INCLUDE_ASM("asm/nonmatchings/game/t_2BCDA8", func_002BDCD0);

INCLUDE_ASM("asm/nonmatchings/game/t_2BCDA8", func_002BDEA8);

struct S2BCDA8_O {
    char pad0[0x1C];
    int unk1C;
};
struct S2BCDA8_L {
    int a;
    int b;
};
extern "C" {
extern int D_0036D3B0;
extern char D_003B1150[];
extern int D_003E56C8[];
extern int D_003E56E8[];
extern int D_003E5708[];
extern int D_003E5728[];
int func_0027D2D8(int, int, void *, int);
int func_0027D1F8(int, int, void *, int);
int func_001D8618(int, int);
S2BCDA8_O *func_001D1CF8(int, int, void *);
int func_0015D2E8(int, int);
}

GP_DATA(D_0036D3B0);
GP_DATA(D_003720D0);
extern "C" int CFunc_AddCrowdModelCam(int params) {
    S2BCDA8_L l;
    func_0027D2D8(params, 0x7F261953, D_003B1150 + D_003720D0 * 16, 1);
    func_0027D870(params, 0xC4E311FA, &l.a, 1);
    int o = func_001D8618(D_0036D3B0, l.a);
    int *t6 = &D_003E56C8[D_003720D0];
    *t6 = o;
    S2BCDA8_O *q = func_001D1CF8(*t6, 0xC4E311FA, t6);
    D_003E56E8[D_003720D0] = q->unk1C;
    func_0027D870(params, 0x9FD29151, &l.b, 1);
    int r = func_0015D2E8(l.b, 1);
    int t3 = D_003720D0 * 4;
    int *t7 = (int *)((char *)D_003E5728 + t3);
    *(int *)((char *)D_003E5708 + t3) = r;
    *t7 = 0;
    func_0027D1F8(params, 0xEFA5F9B9, t7, 0);
    D_003720D0++;
    return 1;
}

GP_DATA(D_003720D0);
extern "C" s32 CFunc_ClearCrowdModelCams(void) {
    D_003720D0 = 0;
    return 1;
}

INCLUDE_ASM("asm/nonmatchings/game/t_2BCDA8", func_002BE288);

extern "C" s32 CFunc_UpdateGuitarFuncs(void) {
    return 1;
}

extern "C" s32 CFunc_DumpOpen(void) {
    return 1;
}

extern "C" s32 CFunc_DumpWrite(void) {
    return 1;
}

extern "C" s32 CFunc_DumpClose(void) {
    return 1;
}

INCLUDE_ASM("asm/nonmatchings/game/t_2BCDA8", CFunc_GetActiveControllers);

INCLUDE_ASM("asm/nonmatchings/game/t_2BCDA8", CFunc_HideObjectByType);

INCLUDE_ASM("asm/nonmatchings/game/t_2BCDA8", CFunc_DoScreenElementMorphList);

INCLUDE_ASM("asm/nonmatchings/game/t_2BCDA8", CFunc_SetNoteMappings);

INCLUDE_ASM("asm/nonmatchings/game/t_2BCDA8", CFunc_GetNoteMapping);

INCLUDE_ASM("asm/nonmatchings/game/t_2BCDA8", CFunc_ClearNoteMappings);
