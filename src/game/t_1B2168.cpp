#include "common.h"

struct S001B2230 {
    char pad0[0x20];
    void* unk20;
};

extern "C" {
void func_001BF628(void* p, s32 a);
void func_001BF6A0(void* p);
void func_001B3D28(s32 a, s32 b);
extern char D_00349220[];
extern s32 D_0036C850;
extern s32 D_0036C854;
extern s32 D_00372B18;
void func_0019ECE8(void);
void func_001B3C98(void);
int func_002EED08(int);
int func_002EE390(int, s32);
int func_002EEC38(int);
int func_002EE360(int, s32);
extern s32 D_0036C848;
extern s32 D_0036C84C;
}

struct E1B2168 {
    u16 unk0;
    u16 unk2;
    u16 unk4;
    u16 unk6;
    u16 unk8;
};

extern "C" void func_001B2168(char* p, s8 i, f32 f) {
    E1B2168* e = &(*(E1B2168**)(p + 0xC))[*(u8*)(i + p + 0x10)];
    e->unk4 = e->unk0 + (s32)f;
}

extern "C" float func_001B21A0(char* p, s8 i) {
    u16* e = (u16*)(*(char**)(p + 0xC) + *(u8*)(p + i + 0x10) * 10);
    return (float)(e[2] - e[0]);
}

extern "C" void* func_001B21E0(char* p) {
    func_001BF628(p, 1);
    *(s32*)(p + 0x54) = 0x54628ED7;
    *(char**)(p + 0x20) = D_00349220;
    *(s32*)(p + 0x30) = -1;
    *(s32*)(p + 0x28) = 0;
    return p;
}

extern "C" void func_001B2230(S001B2230* p) {
    p->unk20 = D_00349220;
    func_001BF6A0(p);
}

extern "C" void func_001B2258(void) {
}

INCLUDE_ASM("asm/nonmatchings/game/t_1B2168", func_001B2260);

INCLUDE_ASM("asm/nonmatchings/game/t_1B2168", func_001B24A8);

INCLUDE_ASM("asm/nonmatchings/game/t_1B2168", func_001B3220);

INCLUDE_ASM("asm/nonmatchings/game/t_1B2168", func_001B3368);

INCLUDE_ASM("asm/nonmatchings/game/t_1B2168", func_001B3370);

INCLUDE_ASM("asm/nonmatchings/game/t_1B2168", func_001B3B00);

extern "C" void func_001B3BA8(void) {
    func_0019ECE8();
    func_001B3C98();
}

extern "C" {
int func_002EE370(int, void*, int);
int func_002EE340(int, void*, int);
void func_0030C538(int);
void func_002EED70(int);
void func_002EECA0(int);
void func_0019E440(void);
void func_0019E670(void);
}
extern "C" void func_001B3BD0(void) {
    D_0036C848 = func_002EE370(2, (void*)func_0019E440, 0);
    if (D_0036C848 == -1) func_0030C538(1);
    *(volatile s32*)0x1000E010 = 4;
    func_002EED70(2);
    D_0036C84C = func_002EE340(0, (void*)func_0019E670, 0);
    if (D_0036C84C == -1) func_0030C538(1);
    *(volatile u64*)0x12001010 = 0xFE00;
    func_002EECA0(0);
    *(volatile s32*)0x10003C20 = 7;
    *(volatile s32*)0x10003010 = 4;
}

GP_DATA(D_0036C848);
GP_DATA(D_0036C84C);
extern "C" void func_001B3C98(void) {
    func_002EED08(2);
    if (D_0036C848 >= 0) {
        func_002EE390(2, D_0036C848);
        D_0036C848 = -1;
    }
    func_002EEC38(0);
    if (D_0036C84C >= 0) {
        func_002EE360(0, D_0036C84C);
        D_0036C84C = -1;
    }
}

extern "C" void func_001B3CF8(s32 v) {
    D_0036C850 = v;
}

GP_DATA(D_0036C854);
extern "C" void func_001B3D00(s32 v) {
    D_00372B18 = v;
    D_0036C854 = v;
}

extern "C" s32 func_001B3D10(void) {
    return D_0036C850;
}

extern "C" s32 func_001B3D18(void) {
    return D_0036C854;
}

INCLUDE_ASM("asm/nonmatchings/game/t_1B2168", func_001B3D20);

INCLUDE_ASM("asm/nonmatchings/game/t_1B2168", func_001B3D28);

extern "C" void func_001B3DB0(void) {
    func_001B3D28(1, 0xFFFF);
}

INCLUDE_ASM("asm/nonmatchings/game/t_1B2168", func_001B3DD0);

INCLUDE_ASM("asm/nonmatchings/game/t_1B2168", func_001B3F48);
