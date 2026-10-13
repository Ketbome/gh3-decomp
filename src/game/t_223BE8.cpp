#include "common.h"

struct Big223 {
    struct S223* unk0;
    int unk4[3];
};

struct E223 {
    int unk0;
    int unk4;
    int unk8;
    char padC[0x14];
};

struct S223b {
    char pad0[0x3C];
    int unk3C;
};

struct S223 {
    E223 unk0[0x100];
    char pad2000[0x4];
    int unk2004;
    char pad2008[0x800];
    S223b* unk2808;
    int unk280C;
    int unk2810;
};

extern "C" {
extern Big223 D_0036F520[] __attribute__((section(".sdata")));
void func_002243A0(int, int);
void func_002250F8(S223*);
void func_002251B8(S223*);
int func_002251C8(S223*);
int func_002251E8(S223*);
void func_002250C8(S223*, int);
void func_002251F8(S223*, int);
void func_002252C0(S223*, int);
void* func_00224F78(S223*, void*, int);
void* func_00225058(S223*, void*, int);
void func_00224E10(S223*, int, int*, int*);
void func_0027D870(void*, u32, int*, int);
}

INCLUDE_ASM("asm/nonmatchings/game/t_223BE8", func_00223BE8);

extern "C" int func_00223BF0(void* a) {
    int tmp = 0;
    func_0027D870(a, 0xA1DC81F9, &tmp, 0);
    return tmp;
}

INCLUDE_ASM("asm/nonmatchings/game/t_223BE8", func_00223C20);

INCLUDE_ASM("asm/nonmatchings/game/t_223BE8", func_00223C28);

INCLUDE_ASM("asm/nonmatchings/game/t_223BE8", func_00223C78);

extern "C" void* func_00224220(void* a, int b) {
    return func_00224F78(D_0036F520->unk0, a, b);
}

extern "C" void func_00224250(void* a, int b) {
    func_00225058(D_0036F520->unk0, a, b);
}

extern "C" void func_00224280(int a) {
    func_002250C8(D_0036F520->unk0, a);
}

extern "C" void func_002242A8(void) {
    func_002250F8(D_0036F520->unk0);
}

extern "C" void func_002242D0(void) {
    func_002251B8(D_0036F520->unk0);
}

extern "C" void func_002242F8(void) {
    func_002251C8(D_0036F520->unk0);
}

extern "C" void func_00224320(void) {
    func_002251E8(D_0036F520->unk0);
}

extern "C" void func_00224348(int a) {
    func_002251F8(D_0036F520->unk0, a);
}

extern "C" void func_00224370(int a) {
    func_002252C0(D_0036F520->unk0, a);
}

INCLUDE_ASM("asm/nonmatchings/game/t_223BE8", func_00224398);

INCLUDE_ASM("asm/nonmatchings/game/t_223BE8", func_002243A0);

extern "C" void func_002243F8(void) {
    func_002243A0(1, 0xFFFF);
}

INCLUDE_ASM("asm/nonmatchings/game/t_223BE8", func_00224418);

INCLUDE_ASM("asm/nonmatchings/game/t_223BE8", func_00224468);

INCLUDE_ASM("asm/nonmatchings/game/t_223BE8", func_002244B0);

INCLUDE_ASM("asm/nonmatchings/game/t_223BE8", func_00224520);

INCLUDE_ASM("asm/nonmatchings/game/t_223BE8", func_00224B00);

INCLUDE_ASM("asm/nonmatchings/game/t_223BE8", func_00224D18);

INCLUDE_ASM("asm/nonmatchings/game/t_223BE8", func_00224E10);

INCLUDE_ASM("asm/nonmatchings/game/t_223BE8", func_00224F78);

INCLUDE_ASM("asm/nonmatchings/game/t_223BE8", func_00225058);

INCLUDE_ASM("asm/nonmatchings/game/t_223BE8", func_002250B8);

extern "C" void func_002250C8(S223* self, int a) {
    self->unk280C = 0;
    self->unk2810 = 0;
    if (a) {
        func_00224E10(self, a, &self->unk280C, &self->unk2810);
    }
}

INCLUDE_ASM("asm/nonmatchings/game/t_223BE8", func_002250F8);

extern "C" void func_002251B8(S223* self) {
    self->unk280C = -1;
}

extern "C" int func_002251C8(S223* self) {
    int n = self->unk2004;
    if (n >= 0) {
        return self->unk0[n].unk8;
    }
    return 0;
}

extern "C" int func_002251E8(S223* self) {
    return self->unk2808->unk3C;
}

INCLUDE_ASM("asm/nonmatchings/game/t_223BE8", func_002251F8);

INCLUDE_ASM("asm/nonmatchings/game/t_223BE8", func_002252C0);

extern "C" void func_002253A8(S223* self, S223b* v) {
    self->unk2808 = v;
}

extern "C" int func_002253B0(S223* self) {
    int n = self->unk2004;
    if (n >= 0) {
        return ((E223*)(n * 32 + (char*)self))->unk4;
    }
    return 0;
}

INCLUDE_ASM("asm/nonmatchings/game/t_223BE8", func_002253D0);

INCLUDE_ASM("asm/nonmatchings/game/t_223BE8", func_002255E8);

INCLUDE_ASM("asm/nonmatchings/game/t_223BE8", func_00225A78);
