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

struct S2BD_N {
    int key;
    int val;
    S2BD_N *next;
};

struct S2BD_T {
    int bits;
    S2BD_N *tab;
    int count;
};

extern "C" {
void *func_0011C3A8_g(int) __asm__("func_0011C3A8");
S2BD_N *func_002D5C88(void *);
int func_0027D400(int, int, int *, int);
void func_0027BFD0(int, int);
void func_0027ABB0(int, int);
int func_0027AA70(void *);
void *func_001287F0(int, int);
}

extern "C" int CFunc_SetGlobalTags(int params) {
    int name;
    int sp4;
    func_0027D870(params, 0, &name, 1);
    sp4 = 0;
    func_0027D400(params, 0x7031F10C, &sp4, 1);
    int k = name;
    int f = SHT_Find(&D_003AD040, k);
    int v = f;
    if (v) {
        if (sp4) {
            func_0027ABB0(v, sp4);
        }
    } else {
        v = func_0027AA70(func_001287F0(8, 1));
        if (sp4) {
            func_0027ABB0(v, sp4);
        }
        int h = name;
        S2BD_T *t = (S2BD_T *)&D_003AD040;
        S2BD_N *b = &t->tab[h & ((1 << D_003AD040.bits) - 1)];
        if (b->val != 0 || b->key != 0) {
            S2BD_N *n = (S2BD_N *)func_0011C3A8_g(0);
            if (n) {
                n = func_002D5C88(n);
            }
            n->key = h;
            n->val = v;
            n->next = b->next;
            b->next = n;
        } else {
            b->key = h;
            b->val = v;
        }
        t->count = t->count + 1;
    }
    if (name == 0x77C71B72) {
        func_0027BFD0(v, 0x32BA3FA2);
        *((char *)v + 3) = 1;
    }
    return 1;
}

struct S2BD_Comp {
    u32 b0 : 8;
    u32 b8 : 1;
    u32 type : 7;
    u16 unk2;
    int key;
    int val;
    int next;
};

struct S2BD_Script {
    char pad0[0x20];
    int unk20;
};

extern "C" {
int func_0027D1F8(int, int, void *, int);
int func_0027DD88(int, int);
void *func_001D0900(int, int);
void func_00279358(void *, int, int, int);
void func_0027BDB0(int, void *, int);
void func_0027ABB0(int, int);
}

extern "C" int CFunc_GetGlobalTags(int params, S2BD_Script *script) {
    int sp0 = 1;
    int out;
    int arg;
    func_0027D1F8(params, 0x226F401B, &sp0, 0);
    func_0027D870(params, 0, &out, 1);
    int k = out;
    int v = SHT_Find(&D_003AD040, k);
    if (v == 0) {
        return 0;
    }
    if (func_0027D870(params, 0x5B058376, &arg, 0)) {
        int r = func_0027DD88(v, arg);
        if (r != 0) {
            S2BD_Comp *c = (S2BD_Comp *)func_001D0900(0x10, 1);
            c->key = 0;
            c->next = 0;
            c->val = 0;
            c->b8 = 0;
            c->type = 0;
            c->unk2 = 0;
            func_00279358(c, r, 0, 0);
            func_0027BDB0(script->unk20, c, 0);
            return 1;
        }
        return 0;
    }
    func_0027ABB0(script->unk20, v);
    return 1;
}


static inline int SHT_Find0(SHT *t, const int &k) {
    int r;
    if (t->tab == 0) {
        r = 0;
    } else {
        SHT_N *n = &t->tab[k & ((1 << t->bits) - 1)];
        r = 0;
        if (n != 0) {
            do {
                if (n->key == k) {
                    int v = n->val;
                    if (t->unk15 != 0 || v != 0) {
                        r = v;
                        break;
                    }
                }
                n = n->next;
            } while (n);
        }
    }
    return r;
}
extern "C" void func_0027C7D0(int, int, int);
extern "C" int CFunc_PushGlobalTags(int params) {
    int a;
    int b;
    func_0027D870(params, 0, &a, 1);
    func_0027D870(params, 0xD28C8510, &b, 1);
    int k1 = a;
    int v1 = SHT_Find0(&D_003AD040, k1);
    int k2 = b;
    int f = SHT_Find(&D_003AD040, k2);
    int v = f;
    if (v == 0) {
        v = func_0027AA70(func_001287F0(8, 1));
        int h = b;
        S2BD_T *t = (S2BD_T *)&D_003AD040;
        S2BD_N *bk = &t->tab[h & ((1 << D_003AD040.bits) - 1)];
        if (bk->val != 0 || bk->key != 0) {
            S2BD_N *n = (S2BD_N *)func_0011C3A8_g(0);
            if (n) {
                n = func_002D5C88(n);
            }
            n->key = h;
            n->val = v;
            n->next = bk->next;
            bk->next = n;
        } else {
            bk->key = h;
            bk->val = v;
        }
        t->count = t->count + 1;
    }
    func_0027C7D0(v, a, v1);
    return 1;
}

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

INCLUDE_ASM("asm/nonmatchings/game/t_2BCDA8", CFunc_DoScreenElementMorphList);

INCLUDE_ASM("asm/nonmatchings/game/t_2BCDA8", CFunc_SetNoteMappings);

INCLUDE_ASM("asm/nonmatchings/game/t_2BCDA8", CFunc_GetNoteMapping);

INCLUDE_ASM("asm/nonmatchings/game/t_2BCDA8", CFunc_ClearNoteMappings);
