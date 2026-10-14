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

struct SAtomH {
    int unk0;
    int unk4;
    SAtomH *unk8;
};
struct SAtomT {
    int bits;
    SAtomH *items;
    int count;
};

extern "C" {
void func_0011A558(u32, int, int);
void func_0011A568(void *);
int func_001E7EC8(int);
void func_001E7FD8(int, int);
int func_0027D470(int, int, int *, int);
void *func_0011C3A8_i(int) __asm__("func_0011C3A8");
SAtomH *func_002D5888(void *);
extern SAtomT *D_00371FF0_p asm("D_00371FF0");
}

extern "C" s32 CFunc_RegisterAtoms(int params) {
    int sp0;
    int sp4;
    func_0011A558(0x9C2E2488, 0, 0);
    func_0027D870(params, 0xA1DC81F9, &sp0, 1);
    func_0027D470(params, 0, &sp4, 1);
    int a = func_001E7EC8(Heap_Alloc(D_00368A38[0], 0x20, 1, 0));
    func_001E7FD8(a, sp4);
    SAtomT *t = D_00371FF0_p;
    int key = sp0;
    int m = (1 << t->bits) - 1;
    SAtomH *x = t->items;
    SAtomH *e = (SAtomH *)((char *)x + ((key & m) * 0xC));
    if (e->unk4 != 0 || e->unk0 != 0) {
        x = (SAtomH *)func_0011C3A8_i(0);
        if (x) x = func_002D5888(x);
        x->unk0 = key;
        x->unk4 = a;
        x->unk8 = e->unk8;
        e->unk8 = x;
    } else {
        e->unk0 = key;
        e->unk4 = a;
    }
    t->count++;
    func_0011A568(x);
    return 1;
}

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
INCLUDE_ASM("asm/nonmatchings/game/t_2BCDA8", CFunc_AddCrowdModelCam);

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

struct S2BCDA8_C {
    char pad0[0x20];
    int unk20;
};
struct S2BCDA8_M {
    char pad0[0x28];
    S2BCDA8_C *unk28[2];
};
struct S2BCDA8_S {
    char pad0[0x20];
    int unk20;
};
extern "C" {
extern S2BCDA8_M *D_0036CDB4;
void func_0027E698(void *);
void func_0027E760(void *, int, int);
void func_0027EDE0(void *, int, int);
void func_0027E6B0(void *, int);
void func_0027C678(int, u32, void *);
int func_00117F10(int, int);
}

GP_DATA(D_0036CDB4);
INCLUDE_ASM("asm/nonmatchings/game/t_2BCDA8", CFunc_GetActiveControllers);

INCLUDE_ASM("asm/nonmatchings/game/t_2BCDA8", CFunc_HideObjectByType);

INCLUDE_ASM("asm/nonmatchings/game/t_2BCDA8", CFunc_DoScreenElementMorphList);

INCLUDE_ASM("asm/nonmatchings/game/t_2BCDA8", CFunc_SetNoteMappings);

INCLUDE_ASM("asm/nonmatchings/game/t_2BCDA8", CFunc_GetNoteMapping);

INCLUDE_ASM("asm/nonmatchings/game/t_2BCDA8", CFunc_ClearNoteMappings);
