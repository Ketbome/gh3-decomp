#include "common.h"

struct S2A5_Dtor {
    void *unk0;
    void *unk4;
    char pad8[0x8];
    void *unk10;
};

struct S2A5_Card {
    char pad0[0x10];
    int unk10;
};

struct S2A6648_1 {
    char pad0[0x20];
    s32 unk20;
};

struct S2A67_Node {
    S2A67_Node *unk0;
    S2A67_Node *unk4;
};

struct S2A67_List {
    int unk0;
    S2A67_Node unk4;
};

struct S2A5_Script {
    char pad0[0x20];
    int unk20;
};

extern "C" {
extern int D_00368740[] __attribute__((section(".sdata")));
int func_0027D1F8(int, int, int *, int);
int func_002A4DB8(int, int, int);
extern int D_00371D84;
extern int D_00371D80;
void func_0028C9D0(int, int, int, int, int, int);
int func_001E40C8(u32);
void *Heap_Alloc(int, int, int, int);
void *func_0011C130(void *, int, int, int, int, int);
extern void *D_003690D8[] __attribute__((section(".sdata")));
extern int D_003690E0[] __attribute__((section(".sdata")));
extern int D_003690E8;
extern void *D_003691F8[] __attribute__((section(".sdata")));
extern int D_00369200[] __attribute__((section(".sdata")));
extern int D_00369208;
extern void *D_003692A0[] __attribute__((section(".sdata")));
extern int D_003692A8[] __attribute__((section(".sdata")));
extern int D_003692B0;
extern void *D_0036A790[] __attribute__((section(".sdata")));
extern int D_0036A798[] __attribute__((section(".sdata")));
extern int D_0036A7A0;
extern void *D_0036A6E0[] __attribute__((section(".sdata")));
extern int D_0036A6E8[] __attribute__((section(".sdata")));
extern int D_0036A6F0;
extern void *D_0036D540[] __attribute__((section(".sdata")));
extern int D_0036D548[] __attribute__((section(".sdata")));
extern int D_0036D550;
extern void *D_0036D0F0[] __attribute__((section(".sdata")));
extern int D_0036D0F8[] __attribute__((section(".sdata")));
extern int D_0036D100;
extern S2A67_List D_003AAD80;
int func_00121C18(S2A5_Card *);
int func_001E32D8(u32);
int func_002A53E0(u32, int);
void func_0027C160(s32, u32, int);
int func_001E3B60(u32);
extern char D_00362400[];
void func_0027AC90(void *);
void func_00113250(void *);
extern int D_00368A38;
void Heap_Free(int, void *);
int func_00121D78(S2A5_Card *);
int func_00275EE8(u32, int);
S2A5_Card *func_001218A0_c(s32, int, int) asm("func_001218A0");
int func_002A5478(void);
void func_00121BF8(S2A5_Card *);
int func_00121C70(S2A5_Card *);
void func_0011A558(u32, int, int);
void func_0011A560(int, int, int);
void func_0011A568(void);
void func_002A67E8(int);
void func_002882E8(int, int, int, int);
void func_0026C7A8(int);
void func_0026C878(int);
int func_0027D870(int, u32, u32 *, int);
int func_0027D188(int, u32, int *, int);
int func_0027CC30(int, u32, int, int *);
void func_0027F1E0(int, int, int);
void func_001E4448(int, int, int, void *);
void func_0027C028(int, u32, void *);
int func_001E46B0(u32);
extern int D_0036DAD0;
extern int D_0036DAD4;
extern int D_0036DAD8;
void func_002A4940(void);
void func_001E5130(void (*)(void), int, int);
void func_001E5C70(u32, int);
extern s32 D_00368E48[] __attribute__((section(".sdata")));
extern s32 D_00370AE0;
extern s32 D_00371D7C;
int CrcFromPathLowercase(void);
s32 func_001218A0(s32, int, int);
int func_001E5050(void);
int func_002691B0(s32);
int func_0026D480(int);
int func_002764E8(int, int);
int func_0027C448(s32, int, int);
int func_00288410(int, int, int, int, int);
int func_002884A8(void);
void func_002A6C10(void);
int func_002A6C40_r(void) asm("func_002A6C40");
void func_002A6C10_a(int) asm("func_002A6C10");
extern char D_003AAD18[];
extern char D_00362338[];
extern char D_00362350[];
extern char D_00362360[];
extern char D_00371D88[];
extern char D_00362370[];
extern char D_00362380[];
void func_0030B550(char *, const char *, ...);
int func_00276600(int, int);
extern char D_003AAD18[];
extern char D_00362338[];
extern char D_00362350[];
extern char D_00362360[];
extern char D_00371D88[];
extern char D_00362370[];
extern char D_00362380[];
void func_0030B550(char *, const char *, ...);
}

extern "C" int func_002A53A8(u32 a) {
    if (a == 0xDDFE0DB9) {
        return func_00275EE8(0x285FECB3, 0);
    }
    return 0;
}

INCLUDE_ASM("asm/nonmatchings/game/t_2A53A8", func_002A53E0);

extern "C" int func_002A5478(void) {
    switch (D_00368740[0]) {
    case 1:
    case 2:
    case 3:
        return 0x400;
    case 4:
        return 0x2000;
    case 5:
    case 6:
        return 0x4000;
    }
    return 1;
}

extern "C" int func_002A54C8(int a) {
    int n = func_002A5478();
    int q = a / n;
    if (a % n != 0) {
        return q * n + n;
    }
    return a;
}

extern "C" int func_002A5510(u32 key) {
    switch (key) {
    case 0xB010F357:
        return func_00276600(0x09B69777, 1);
    case 0x61A1BC57:
        return func_00276600(0x7A549C6C, 1);
    case 0x3BF882CC:
        return func_00276600(0x8AE89EC8, 1);
    case 0xCA41692D:
        return func_00276600(0xF196EF81, 1);
    case 0x62896EDF:
        return func_00276600(0x68CCB5A0, 1);
    case 0x79DAA2F9:
        return func_00276600(0xC07CC6D9, 1);
    case 0xFFFFFFFF:
        break;
    }
    return -1;
}

extern "C" char *func_002A5638(u32 key, int a) {
    switch (key) {
    case 0xCA41692D:
        func_0030B550(D_003AAD18, D_00362338, a);
        break;
    case 0xB010F357:
        func_0030B550(D_003AAD18, D_00362350, a);
        break;
    case 0x61A1BC57:
        func_0030B550(D_003AAD18, D_00362360, a);
        break;
    case 0x3BF882CC:
        func_0030B550(D_003AAD18, D_00371D88, a);
        break;
    case 0x62896EDF:
        func_0030B550(D_003AAD18, D_00362370, a);
        break;
    case 0x79DAA2F9:
        func_0030B550(D_003AAD18, D_00362380, a);
        break;
    case 0xFFFFFFFF:
        break;
    }
    return D_003AAD18;
}

INCLUDE_ASM("asm/nonmatchings/game/t_2A53A8", func_002A5748);

extern "C" int CFunc_GetMemCardSpaceAvailable(int params, S2A6648_1 *script) {
    func_0027C160(script->unk20, 0x0C37C363, 0);
    func_0027C160(script->unk20, 0x0855B2FC, 1000000);
    S2A5_Card *c = func_001218A0_c(D_00368E48[0], 0, 0);
    if (c) {
        int d = script->unk20;
        func_0027C160(d, 0x0C37C363, func_00121D78(c));
        return 1;
    }
    return 0;
}

extern "C" int CFunc_GetMemCardSpaceRequired(int params, S2A6648_1 *script) {
    u32 t = 0;
    func_0027D870(params, 0, &t, 0);
    u32 x = t;
    int r = func_002A53E0(x, func_001E32D8(x));
    func_0027C160(script->unk20, 0xEB3860C3, r);
    return 1;
}

extern "C" int CFunc_MemCardGetUniqueFileName(int params, S2A5_Script *script) {
    struct {
        int len;
        int a;
        int b;
    } l;
    int n;
    if (func_0027CC30(params, 0x37D4417D, 1, &l.len) == 0) {
        func_0027F1E0(params, 0, 1);
        n = 0;
    } else {
        n = l.len;
    }
    func_0027D870(params, 0xFADDC0B8, (u32 *)&l.a, 1);
    int a = l.a;
    func_0027D188(params, 0xC3F4169A, &l.b, 0);
    void *buf = Heap_Alloc(D_00368A38, n + 2, 1, 0);
    func_001E4448(a, l.b, n + 1, buf);
    func_0027C028(script->unk20, 0xC3F4169A, buf);
    if (buf)
        Heap_Free(D_00368A38, buf);
    return 0;
}

INCLUDE_ASM("asm/nonmatchings/game/t_2A53A8", CFunc_MemCardFileExists);

extern "C" int CFunc_DeleteMemCardFile(int params) {
    u32 n;
    func_0026C7A8(1);
    func_0026C878(1);
    func_0027D870(params, 0x11093FB5, &n, 1);
    int r = func_001E46B0(n);
    func_0026C7A8(-1);
    func_0026C878(-1);
    return r;
}

extern "C" int CFunc_FormatCard(void) {
    int r = 0;
    func_0026C7A8(1);
    func_0026C878(1);
    S2A5_Card *c = func_001218A0_c(D_00368E48[0], 0, 0);
    if (c) {
        r = func_00121C18(c);
    }
    func_0026C7A8(-1);
    func_0026C878(-1);
    return r;
}

extern "C" s32 CFunc_CardIsInSlot(void) {
    return func_001218A0(D_00368E48[0], 0, 0) != 0;
}

extern "C" int CFunc_CardIsNew(void) {
    S2A5_Card *c = func_001218A0_c(D_00368E48[0], 0, 0);
    if (c && c->unk10 == -1) {
        return 1;
    }
    return 0;
}

extern "C" int CFunc_CardIsFormatted(void) {
    S2A5_Card *c = func_001218A0_c(D_00368E48[0], 0, 0);
    if (c) {
        func_00121BF8(c);
        return func_00121C70(c);
    }
    return 0;
}

extern "C" s32 CFunc_SaveFailedDueToInsufficientSpace(void) {
    return D_00371D7C;
}

extern "C" int CFunc_GetSummaryInfo(int arg0, S2A5_Script *script) {
    int y;
    int x;
    func_0027D870(arg0, 0, (u32 *)&x, 1);
    int xs = x;
    y = 0;
    func_0027D1F8(arg0, 0xC78DABF6, &y, 0);
    if (y) {
        func_002A4DB8(script->unk20, D_00371D84, D_00371D80);
    } else {
        func_002A4DB8(script->unk20, xs, 0);
    }
    return 1;
}

extern "C" void func_002A5DB0(void) {
    func_0026D480(0);
    func_002691B0(D_00370AE0);
}

GP_DATA(D_00371D7C);
extern "C" int CFunc_SaveToMemoryCard(int params) {
    u32 n;
    func_0026C7A8(1);
    func_0026C878(1);
    D_00371D7C = 0;
    func_0027D870(params, 0x11093FB5, &n, 1);
    int r = func_001E3B60(n);
    func_0026C7A8(-1);
    func_0026C878(-1);
    if (r == 2) {
        D_00371D7C = 1;
    }
    return r == 0;
}

extern "C" int CFunc_LoadFromMemoryCard(int params, S2A5_Script *script) {
    u32 n;
    func_0027D870(params, 0x11093FB5, &n, 1);
    int r = func_001E40C8(n);
    if (r == 2) {
        func_0027C448(script->unk20, 0, 0xFBF9C22A);
    }
    if (r == 0) {
        func_0028C9D0(0x0EB9402D, params, 0, 0, 0, 0);
    }
    return r == 0;
}

INCLUDE_ASM("asm/nonmatchings/game/t_2A53A8", func_002A5EF8);

extern "C" void CFunc_GetMemCardDirectoryListing(void) {
    func_001E5050();
}

extern "C" s32 CFunc_ShowStorageSelector(void) {
    return 0;
}

extern "C" s32 CFunc_StorageSelectorFinished(void) {
    return 1;
}

extern "C" int CFunc_MemCardSystemInitialize(void) {
    D_0036DAD0 = 31000;
    D_0036DAD4 = 9000;
    D_0036DAD8 = 3000;
    func_001E5130(func_002A4940, func_002764E8(0x71ACFFE9, 0), 0);
    return 1;
}

extern "C" int CFunc_SetSaveFileName(int params) {
    u32 n;
    int s;
    func_0027D870(params, 0x11093FB5, &n, 1);
    u32 x = n;
    func_0027D188(params, 0xA1DC81F9, &s, 1);
    func_001E5C70(x, s);
    return 1;
}

extern "C" s32 CFunc_EnumContentFiles(void) {
    return 0;
}

extern "C" s32 CFunc_EnumContentFilesFinished(void) {
    return 0;
}

extern "C" s32 CFunc_NewShowStorageSelector(void) {
    return 0;
}

extern "C" s32 CFunc_GetContentFolderIndexFromFile(int arg0, S2A6648_1 *arg1) {
    func_0027C448(arg1->unk20, 0xF6D04971 /* DEVICE */, 0x1CA1FF20 /* DEFAULT */);
    return 0;
}

INCLUDE_ASM("asm/nonmatchings/game/t_2A53A8", func_002A6678);

extern "C" void func_002A6700(int init, int prio) {
    if (prio == 0xFFFF && init) {
        D_003AAD80.unk4.unk0 = &D_003AAD80.unk4;
        D_003AAD80.unk4.unk0->unk4 = &D_003AAD80.unk4;
    }
}

extern "C" void func_002A6730(S2A5_Dtor *p, int flags) {
    p->unk10 = D_00362400;
    void *q = p->unk0;
    if (q) {
        func_0027AC90(q);
        func_00113250(q);
    }
    q = p->unk4;
    if (q) {
        func_0027AC90(q);
        func_00113250(q);
    }
    if (flags & 1) {
        Heap_Free(D_00368A38, p);
    }
}

INCLUDE_ASM("asm/nonmatchings/game/t_2A53A8", func_002A67B8);

INCLUDE_ASM("asm/nonmatchings/game/t_2A53A8", func_002A67E8);

extern "C" void func_002A6B70(int a, int b, int c) {
    func_0011A560(a, 0, 0);
    func_002882E8(a, b, 0, c);
    func_0011A568();
}

extern "C" int func_002A6BD0(int arg0, int arg1, int arg2, int arg3) {
    return func_00288410(arg0, arg1, arg2, arg3, 0);
}

extern "C" void func_002A6BF0(void) {
    func_002A6C10();
}

extern "C" void func_002A6C10(void) {
    func_002884A8();
    func_002764E8(0xC472ECC5 /* nodearray */, 0);
}

extern "C" void func_002A6C40(void) {
    CrcFromPathLowercase();
}

extern "C" void func_002A6C60(void) {
    func_002A6C10_a(func_002A6C40_r());
}

extern "C" {
void func_0011A558(u32, int, int);
void func_0011A568(void);
void func_002767D8(void);
void func_0014E170(void);
void func_002A6EB8(int, int);
void func_002A6F60(int, int);
void func_002A7008(int, int);
void func_002A70B0(int, int);
void func_002A7158(int, int);
void func_002A7200(int, int);
void func_002A72A8(int, int);
void func_002769B0(int, int);
void func_00276BB0(int, int);
int func_002A1820(void);
int func_002A1828(void);
extern char D_003625A8[];
extern char D_003625C0[];
extern char D_003625D0[];
extern char D_003625E8[];
extern char D_003625F8[];
extern char D_00362610[];
extern char D_00362628[];
extern char g_cfunc_table[];
extern char D_003300D0[];
}

extern "C" void func_002A6C88(void) {
    func_0011A558(0xA76BFA95, 0, 0);
    func_002767D8();
    func_0014E170();
    func_0011A568();
    func_0011A558(0xCAA97111, 0, 0);
    func_002A6EB8(0xC8, (int)D_003625A8);
    func_0011A568();
    func_0011A558(0x154E93FF, 0, 0);
    func_002A6F60(1, (int)D_003625C0);
    func_0011A568();
    func_0011A558(0xA394CD22, 0, 0);
    func_002A7008(1, (int)D_003625D0);
    func_0011A568();
    func_0011A558(0x93D10D41, 0, 0);
    func_002A70B0(0x40, (int)D_003625E8);
    func_0011A568();
    func_0011A558(0xF4439A94, 0, 0);
    func_002A7158(0x4B, (int)D_003625F8);
    func_0011A568();
    func_0011A558(0xA63C4993, 0, 0);
    func_002A7200(0xAF, (int)D_00362610);
    func_0011A568();
    func_0011A558(0x5F405993, 0, 0);
    func_002A72A8(0x12C, (int)D_00362628);
    func_0011A568();
    func_0011A558(0xA750190B, 0, 0);
    func_002769B0((int)g_cfunc_table, func_002A1820());
    func_00276BB0((int)D_003300D0, func_002A1828());
    func_0011A568();
}

extern "C" void func_002A6E50(int a, int b) {
    func_0011A558(0x328084D7, 0, 0);
    if (b) {
        func_002A67E8(a);
    }
    func_0011A568();
}

INCLUDE_ASM("asm/nonmatchings/game/t_2A53A8", func_002A6EA8);

extern "C" void func_002A6EB8(int a, int b) {
    void **slot = &D_003690D8[D_003690E8];
    *slot = func_0011C130(Heap_Alloc(D_00368A38, 0x70, 1, 0), 0x408, a, b, 1, 0);
    D_003690E0[D_003690E8] = 1;
}

extern "C" void func_002A6F60(int a, int b) {
    void **slot = &D_003691F8[D_00369208];
    *slot = func_0011C130(Heap_Alloc(D_00368A38, 0x70, 1, 0), 0x78, a, b, 1, 0);
    D_00369200[D_00369208] = 1;
}

extern "C" void func_002A7008(int a, int b) {
    void **slot = &D_003692A0[D_003692B0];
    *slot = func_0011C130(Heap_Alloc(D_00368A38, 0x70, 1, 0), 0x30, a, b, 1, 0);
    D_003692A8[D_003692B0] = 1;
}

extern "C" void func_002A70B0(int a, int b) {
    void **slot = &D_0036A790[D_0036A7A0];
    *slot = func_0011C130(Heap_Alloc(D_00368A38, 0x70, 1, 0), 0x418, a, b, 1, 0);
    D_0036A798[D_0036A7A0] = 1;
}

extern "C" void func_002A7158(int a, int b) {
    void **slot = &D_0036A6E0[D_0036A6F0];
    *slot = func_0011C130(Heap_Alloc(D_00368A38, 0x70, 1, 0), 0xF0, a, b, 1, 0);
    D_0036A6E8[D_0036A6F0] = 1;
}

extern "C" void func_002A7200(int a, int b) {
    void **slot = &D_0036D540[D_0036D550];
    *slot = func_0011C130(Heap_Alloc(D_00368A38, 0x70, 1, 0), 0x1C, a, b, 1, 0);
    D_0036D548[D_0036D550] = 1;
}

extern "C" void func_002A72A8(int a, int b) {
    void **slot = &D_0036D0F0[D_0036D100];
    *slot = func_0011C130(Heap_Alloc(D_00368A38, 0x70, 1, 0), 0xC, a, b, 1, 0);
    D_0036D0F8[D_0036D100] = 1;
}

INCLUDE_ASM("asm/nonmatchings/game/t_2A53A8", func_002A7350);
