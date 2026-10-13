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
extern u32 D_0036F524;
void func_00224D18(void*, int);
void* func_00113DF0(int, int, int);
int func_00224B00(void*);
int func_0027D400(int, u32, int*, int);
void func_0011A470(int);
void func_00223050(void*);
extern u8 D_00390830[];
}

INCLUDE_ASM("asm/nonmatchings/game/t_223BE8", func_00223BE8);

extern "C" int func_00223BF0(void* a) {
    int tmp = 0;
    func_0027D870(a, 0xA1DC81F9, &tmp, 0);
    return tmp;
}

INCLUDE_ASM("asm/nonmatchings/game/t_223BE8", func_00223C20);

extern "C" int func_00223C28(int a, int* out) {
    int v = 0;
    if (func_0027D400(a, 0x7EA855F0, &v, 0)) {
        *out = v;
        return 1;
    }
    return 0;
}

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

extern "C" void func_002243A0(int a, int b) {
    if (b == 0xFFFF && a) {
        func_00223050(D_00390830);
        int i = 0x3E7;
        do {
            i -= 0x19;
        } while (i != -1);
    }
}

extern "C" void func_002243F8(void) {
    func_002243A0(1, 0xFFFF);
}

GP_DATA(D_0036F520);
GP_DATA(D_0036F524);
extern "C" int func_00224418(int a) {
    if (D_0036F520->unk0 == 0 && a) {
        D_0036F520->unk0 = (S223*)func_00224B00(func_00113DF0(0x2814, 0, 1));
    }
    D_0036F524 += 1;
    return (int)D_0036F520->unk0;
}

GP_DATA(D_0036F524);
GP_DATA(D_0036F520);
extern "C" void func_00224468(void) {
    if (D_0036F524 >= 2) {
        D_0036F524 -= 1;
        return;
    }
    if (D_0036F520->unk0) {
        func_00224D18(D_0036F520->unk0, 3);
    }
    D_0036F520->unk0 = 0;
    D_0036F524 = 0;
}

extern "C" void func_002244B0(int* p) {
    p[0] = 0;
    int a = p[5];
    p[4] = 0;
    p[1] = 0;
    p[2] = 0;
    if (a) func_0011A470(a);
    int b = p[6];
    if (b) func_0011A470(b);
    int c = p[7];
    p[5] = 0;
    p[6] = 0;
    if (c) {
        func_0011A470(c);
        p[7] = 0;
    }
}

INCLUDE_ASM("asm/nonmatchings/game/t_223BE8", func_00224520);

INCLUDE_ASM("asm/nonmatchings/game/t_223BE8", func_00224B00);

INCLUDE_ASM("asm/nonmatchings/game/t_223BE8", func_00224D18);

INCLUDE_ASM("asm/nonmatchings/game/t_223BE8", func_00224E10);

INCLUDE_ASM("asm/nonmatchings/game/t_223BE8", func_00224F78);

extern "C" void* func_00225058(S223* p, void* a, int b) {
    int v[2];
    v[0] = -1;
    v[1] = 0;
    func_00224E10(p, (int)a, &v[0], &v[1]);
    if (v[0] != -1) return *(void**)((char*)p + v[0] * 32 + 0x10);
    return 0;
}

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
