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

struct S2BE_Range {
    u8 unk0;
    u8 unk1;
    f32 unk4;
    f32 unk8;
};

struct S2BE_Arr {
    int unk0;
    u32 unk4;
    int unk8;
};

extern "C" {
void func_00275648(S2BE_Range *);
int func_002763E0(int, int);
int func_0027D870_i(int, u32, int *, int) asm("func_0027D870");
int func_0027DD38_r(int, u32, S2BE_Range *, int) asm("func_0027DD38");
int func_0027D188_i(int, u32, int *, int) asm("func_0027D188");
int func_0027D470_a(int, u32, S2BE_Arr **, int) asm("func_0027D470");
int func_001150B8_s(char *) asm("func_001150B8");
void func_00145310(int *, int, int, int);
void func_001CE888(int, int *);
void func_001395D8(int, int, f32, f32);
int func_0030B550_p(char *, const char *, int, int) asm("func_0030B550");
extern char D_003720D8[];
extern int D_00369798;
}

extern "C" int CFunc_DoScreenElementMorphList(int params) {
    S2BE_Range rng;
    char buf[0x100];
    int sp110[4];
    int sp120;
    int sp124;
    S2BE_Arr *arr;
    int sp12C;
    u32 i = 0;
    func_0027D870_i(params, 0xBB3707E7, &sp120, 1);
    func_0027D188_i(params, 0x666E080B, &sp124, 1);
    func_00275648(&rng);
    func_0027DD38_r(params, 0xCC929F5B, &rng, 1);
    func_0027D470_a(func_002763E0(sp120, 1), 0xBBB5F8A2, &arr, 1);
    if (arr->unk4 != 0) {
        do {
            int e;
            if (arr->unk4 == 1) e = arr->unk8;
            else e = ((int *)arr->unk8)[i];
            func_0027D188_i(e, 0x40C698AF, &sp12C, 1);
            func_0030B550_p(buf, D_003720D8, sp12C, sp124);
            func_00145310(sp110, D_00369798, func_001150B8_s(buf), 0);
            int h = sp110[0];
            if (h != 0) {
                func_001CE888(h, sp110);
                sp110[0] = 0;
                if (h != 0) {
                    func_001395D8(h, 1, rng.unk4, rng.unk8);
                }
            }
            i++;
        } while (i < arr->unk4);
    }
    return 1;
}

INCLUDE_ASM("asm/nonmatchings/game/t_2BCDA8", CFunc_SetNoteMappings);

INCLUDE_ASM("asm/nonmatchings/game/t_2BCDA8", CFunc_GetNoteMapping);

INCLUDE_ASM("asm/nonmatchings/game/t_2BCDA8", CFunc_ClearNoteMappings);
