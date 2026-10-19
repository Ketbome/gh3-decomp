#include "common.h"

struct S135_A { char pad0[0x4]; u32 unk4; };

struct S135_G { char pad0[0x4]; int unk4; };

struct S_00135DD0 { char pad0[0x6C]; char unk6C; };

extern "C" {
int func_001349D0_1(S_00135DD0*) __asm__("func_001349D0");
extern int D_00368A38;
void* Heap_Alloc(int, int, int, int);
void Heap_Free(int, void*);
int func_0027D4E0(int, int, void*, int);
int func_0012D028(int, int);
int func_002899D8(int);
void func_0028A140(int, void*, int, S_00135DD0*);
int func_0028C200(int);
void func_00289B40(int, int);
int func_0027D870(void*, u32, int*, int);
int func_0027D870_i(int, int, int*, int) __asm__("func_0027D870");
int func_0027D188(int, int, int*, int);
int func_0027D400(char*, u32, int*, int);
extern int D_00369424;
int func_00132070(int, int);
extern int D_00372AF8;
extern int D_00372B00;
extern int D_00372B08;
extern int D_00372B10;
extern S135_G* D_0036942C;
int func_001349D0(S_00135DD0*, void*);
int func_0027D470(int, u32, S135_A**, int);
int func_0027EF20(S135_A*, u32);
void func_00123AB0(S135_G*, int);
extern S_00135DD0* D_00369428;
extern int D_00369420;
void func_0027ACF8(char*);
void func_00161AC8(int);
void func_00160730(int);
void func_00161138(int);
void func_00161960(int);
}

INCLUDE_ASM("asm/nonmatchings/game/t_135A98", func_00135A98);

INCLUDE_ASM("asm/nonmatchings/game/t_135A98", func_00135D20);

GP_DATA(D_00369428);
extern "C" int func_00135DD0(void) {
    func_0027ACF8(&D_00369428->unk6C);
    return 1;
}

GP_DATA(D_00369420);
extern "C" int func_00135DF8(void) {
    func_00161AC8(D_00369420);
    return 1;
}

INCLUDE_ASM("asm/nonmatchings/game/t_135A98", func_00135E20);

INCLUDE_ASM("asm/nonmatchings/game/t_135A98", func_00135ED8);

extern "C" int func_00135F28(void) {
    int v = 0;
    if (func_0027D400(&D_00369428->unk6C, 0x812684EF, &v, 0)) {
        return func_00132070(D_00369424, v);
    }
    return 0;
}

INCLUDE_ASM("asm/nonmatchings/game/t_135A98", func_00135F78);

INCLUDE_ASM("asm/nonmatchings/game/t_135A98", func_00136318);

extern "C" int func_001364C8(void) {
    func_00160730(D_00369420);
    return 1;
}

INCLUDE_ASM("asm/nonmatchings/game/t_135A98", func_001364F0);

extern "C" int func_00136740(void) {
    func_00161138(D_00369420);
    return 1;
}

INCLUDE_ASM("asm/nonmatchings/game/t_135A98", func_00136768);

INCLUDE_ASM("asm/nonmatchings/game/t_135A98", func_00136A28);

struct VE_00136C48 { char pad0[0x68]; s16 unk68; s16 unk6A; int (*unk6C)(void*, int, int, int); };
struct S_00136C48 { char pad0[8]; VE_00136C48* unk8; };

INCLUDE_ASM("asm/nonmatchings/game/t_135A98", func_00136C48);

INCLUDE_ASM("asm/nonmatchings/game/t_135A98", func_00136D40);

extern "C" {
int func_00134A20_a(int, u32) __asm__("func_00134A20");
int func_001349D0_a(int, u32) __asm__("func_001349D0");
int func_0027D1F8_a(int, u32, int*, int) __asm__("func_0027D1F8");
void func_0027D870_a(int, u32, int*, int) __asm__("func_0027D870");
void func_0027C160_a(int, u32, int) __asm__("func_0027C160");
int func_0027DF00_a(int, u32) __asm__("func_0027DF00");
extern int D_00369428_i __asm__("D_00369428");
}

#define SET137(t) \
    func_0027C160_a(t, 0x6E94F918, s0); \
    func_0027C160_a(t, 0xE4F130F4, s4); \
    func_0027C160_a(t, 0x949BC47B, s8); \
    func_0027C160_a(t, 0x97DBDDE6, 0)

extern "C" int func_00137070(void) {
    int s0, s4, s8, sc;
    u32 k1 = 0x650FAB6D;
    int h = func_00134A20_a(D_00369428_i, k1);
    u32 k2 = 0x7E54E2A2;
    u32 k3 = 0x0571DA24;
    if (h == 0) {
        h = func_00134A20_a(D_00369428_i, 0x0FC85BAE);
        k1 = 0x0FC85BAE;
        k2 = 0x7C53B658;
        k3 = 0x74E37E2A;
        if (h == 0) {
            return 0;
        }
    }
    if (func_0027D1F8_a(h, 0x6E94F918, &s0, 0) != 0) {
        func_0027D1F8_a(h, 0xE4F130F4, &s4, 0);
        func_0027D1F8_a(h, 0x949BC47B, &s8, 0);
    } else {
        h = func_001349D0_a(D_00369428_i, k1);
        if (h != 0) {
            func_0027D1F8_a(h, 0xC6CC7F7F, &s0, 1);
            func_0027D1F8_a(h, 0x4CA9B693, &s4, 1);
            func_0027D1F8_a(h, 0x3CC3421C, &s8, 1);
        }
    }
    int* psc = &sc;
    sc = 0;
    h = func_00134A20_a(D_00369428_i, 0xA921D236);
    if (h != 0) {
        func_0027D870_a(h, 0x4BB2084E, psc, 1);
        if (sc != 0x806FFF30) {
            SET137(h);
        }
    }
    h = func_001349D0_a(D_00369428_i, k2);
    if (h != 0 && func_0027DF00_a(h, 0xE8505D4B) != 0) {
        h = func_00134A20_a(D_00369428_i, k2);
        if (h != 0) {
            SET137(h);
        }
    }
    h = func_00134A20_a(D_00369428_i, k3);
    if (h != 0) {
        SET137(h);
    }
    h = func_001349D0_a(D_00369428_i, 0xEB307E68);
    if (h != 0 && func_0027DF00_a(h, 0xF11C6E74) != 0) {
        h = func_00134A20_a(D_00369428_i, 0xEB307E68);
        if (h != 0) {
            SET137(h);
        }
    }
    h = func_00134A20_a(D_00369428_i, 0x2457F44D);
    if (h != 0) {
        SET137(h);
    }
    return 1;
}

extern "C" int func_00137448(void) {
    func_00161960(D_00369420);
    return 1;
}

extern "C" int func_00137470(int a, int b, int c) {
    int o = func_001349D0_1(D_00369428);
    if (o) {
        int* blk = (int*)Heap_Alloc(D_00368A38, 8, 1, 0);
        blk[0] = 0;
        blk[1] = 0;
        if (func_0027D4E0(o, c, blk, 0)) {
            int t = func_002899D8(func_0012D028(0x10C, 1));
            func_0028A140(t, blk, 0, D_00369428);
            while (func_0028C200(t)) {
            }
            if (t) func_00289B40(t, 3);
        }
        Heap_Free(D_00368A38, blk);
    }
    return 1;
}

INCLUDE_ASM("asm/nonmatchings/game/t_135A98", func_00137558);

GP_DATA(D_00372AF8);
GP_DATA(D_00372B00);
GP_DATA(D_00372B08);
GP_DATA(D_00372B10);
extern "C" void func_00137618(int a, int b) {
    if (b == 0xFFFF && a) {
        D_00372AF8 = 0x91C1EC93;
        D_00372B00 = 0xD2C041C2;
        D_00372B08 = 0xAEE1AF7D;
        D_00372B10 = 0xB1A55798;
    }
}

INCLUDE_ASM("asm/nonmatchings/game/t_135A98", func_00137668);

INCLUDE_ASM("asm/nonmatchings/game/t_135A98", func_00137690);

extern "C" int func_001376B8(void* params) {
    int v;
    func_0027D870(params, 0x4BB2084E, &v, 1);
    return v;
}

INCLUDE_ASM("asm/nonmatchings/game/t_135A98", func_001376E8);

INCLUDE_ASM("asm/nonmatchings/game/t_135A98", func_001377B8);

INCLUDE_ASM("asm/nonmatchings/game/t_135A98", func_001377C8);
