#include "common.h"

struct S135_A { char pad0[0x4]; u32 unk4; };

struct S135_G { char pad0[0x4]; int unk4; };

struct S_00135DD0 { char pad0[0x6C]; char unk6C; };

extern "C" {
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

INCLUDE_ASM("asm/nonmatchings/game/t_135A98", func_001376E8);

INCLUDE_ASM("asm/nonmatchings/game/t_135A98", func_001377B8);

INCLUDE_ASM("asm/nonmatchings/game/t_135A98", func_001377C8);
