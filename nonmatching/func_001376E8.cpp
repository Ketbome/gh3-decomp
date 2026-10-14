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

INCLUDE_ASM("asm/nonmatchings/game/t_135A98", func_00137070);

extern "C" int func_00137448(void) {
    func_00161960(D_00369420);
    return 1;
}

INCLUDE_ASM("asm/nonmatchings/game/t_135A98", func_00137470);

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

struct A1376E8 { char pad0[4]; u32 unk4; int* unk8; };
extern "C" A1376E8* func_002764E8_a(int, int) __asm__("func_002764E8");

extern "C" int func_001376E8(int x, int id) {
    A1376E8* a = func_002764E8_a(x, 0);
    int r = 0;
    if (a != 0) {
        int found = 0;
        if (id == 0) return 0;
        u32 i = 0;
        u32 t0 = a->unk4;
        u32 n;
        u32 t;
        if (t0 != 0) {
            n = t0;
            do {
                int v;
                if (n == 1) v = (int)a->unk8;
                else v = a->unk8[i];
                if (func_001376B8((void*)v) == id) {
                    found = v;
                    break;
                }
                i++;
                t = a->unk4;
                n = t;
            } while (i < t);
        }
        r = found;
    }
    return r;
}

INCLUDE_ASM("asm/nonmatchings/game/t_135A98", func_001377B8);

INCLUDE_ASM("asm/nonmatchings/game/t_135A98", func_001377C8);
