#include "common.h"

struct S133_T { char pad0[0x14]; int* unk14; };

struct S133_H { void* unk0; };

struct S133_S {
    char pad0[0x4];
    S133_T* unk4;
    void* unk8;
    char padC[0x4];
    void* unk10;
    char pad14[0x58];
    char unk6C[0x8];
    int unk74;
    int unk78;
};

struct S_001344E8 { char pad0[0x6C]; char unk6C; };
struct S_001346E0 { char pad0[0x6C]; char unk6C; };

struct S_001349B0 { char pad0[0x6C]; char unk6C; };

struct S_00133F80 { char pad0[0x4]; int unk4; char pad1[0x4]; int unkC; void* unk10; };

struct VE_00134E18 { s16 unk0; s16 unk2; void (*unk4)(void*, int, int, int, int, int, int); };
struct S_00134E18 { char pad0[0x8]; VE_00134E18* unk8; };

extern "C" {
int CrcFromPathLowercase(const char*);
int func_00160170(int, int, int, int, int, int);
void func_0015F4B8(int, int);
int func_0027D400(char*, int, int*, int);
int func_00134278(void*);
int func_001317D0(void*, int);
int func_00133D38(void*, int, int, int);
int func_00133B10(void*, int, int);

int func_001376E8(int, int, int);
int func_00134380(void*);
void func_00134340(S133_H*);
void func_0022C130(void*, S133_H*);
void func_0022C210(void*, S133_H*);
int func_001348C8(S133_S*);
void func_0027B848(int, char*, int);
void func_001343B0(S133_S*);
int func_00134128(S133_S*, int);
void func_0027AC90(char*);
void func_001CE990(S133_S*, int);
S133_S* func_001CE8D0(S133_S*);
void func_0027AA70(char*);
void func_00138960(int, int);
int func_002763E0(u32, int);
void func_0027ABB0(char*, int);
void* func_00113D20(u32);
int func_00138908(void*);
extern u8 D_0033A478[];
extern u8 D_0033A5E0[];
extern int D_00368A38[] __attribute__((section(".sdata")));
void func_00119400(int, void*);
extern int D_00372AD8;
extern int D_00372AE0;
extern int D_00372AE8;
extern int D_00372AF0;
void func_0027ACF8(char*);
void func_0027C448(char*);
void func_0027D870(char*, int, int, int);
void func_00134D60(int, int);
extern int D_00369420;
void func_00160A90(int);
extern u8 D_0033A350[];
void func_00161BA0(int);
}

struct S_00134278 { char pad0[0xC]; int unkC; };
struct S_00134280 { char pad0[0xC]; int unkC; };
struct S_00134378 { char pad0[0x224]; int unk224; };
struct S_00134D20 { char pad0[0x74]; int unk74; };

INCLUDE_ASM("asm/nonmatchings/game/t_133A98", func_00133A98);

INCLUDE_ASM("asm/nonmatchings/game/t_133A98", func_00133B10);

extern "C" int func_00133CE8(S133_S* self, int a, int b, int c) {
    return func_00133D38(self, func_001317D0(self, a), b, c);
}

INCLUDE_ASM("asm/nonmatchings/game/t_133A98", func_00133D38);

extern "C" int func_00133F60(S133_S* self) {
    return func_00134278(self->unk8);
}

extern "C" S_00133F80* func_00133F80(S_00133F80* self) {
    self->unk4 = 0;
    self->unk10 = D_0033A350;
    self->unkC = 0;
    return self;
}

extern "C" void func_00133FA0(S_00133F80* self, int flags) {
    self->unk10 = D_0033A350;
    self->unk4 = 0;
    if (flags & 1) {
        func_00119400(D_00368A38[0], self);
    }
}

INCLUDE_ASM("asm/nonmatchings/game/t_133A98", func_00133FE0);

INCLUDE_ASM("asm/nonmatchings/game/t_133A98", func_00134128);

INCLUDE_ASM("asm/nonmatchings/game/t_133A98", func_00134208);

INCLUDE_ASM("asm/nonmatchings/game/t_133A98", func_00134210);

extern "C" int func_00134278(void* p) {
    S_00134278* self = (S_00134278*)p;
    return self->unkC;
}

extern "C" void func_00134280(S_00134280* self, int v) {
    self->unkC = v;
}

INCLUDE_ASM("asm/nonmatchings/game/t_133A98", func_00134288);

INCLUDE_ASM("asm/nonmatchings/game/t_133A98", func_001342B0);

extern "C" void func_001342E8(S133_H* h, void* p) {
    if (h->unk0 != p) {
        func_00134340(h);
        h->unk0 = p;
        if (p) {
            func_0022C130(p, h);
        }
    }
}

extern "C" void func_00134340(S133_H* h) {
    if (h->unk0) {
        func_0022C210(h->unk0, h);
        h->unk0 = 0;
    }
}

extern "C" int func_00134378(S_00134378* self) {
    return self->unk224;
}

extern "C" int func_00134380(void* params) {
    int v = 0;
    func_0027D870((char*)params, 0x4BB2084E, (int)&v, 0);
    return v;
}

INCLUDE_ASM("asm/nonmatchings/game/t_133A98", func_001343B0);

extern "C" void func_001344E8(S_001344E8* self) {
    func_0027ACF8(&self->unk6C);
}

INCLUDE_ASM("asm/nonmatchings/game/t_133A98", func_00134508);

extern "C" void func_001346E0(S_001346E0* self) {
    func_0027C448(&self->unk6C);
}

extern "C" S133_S* func_00134700(S133_S* self) {
    func_001CE8D0(self);
    self->unk8 = D_0033A478;
    func_0027AA70(self->unk6C);
    self->unk74 = 0;
    self->unk78 = 0;
    return self;
}

extern "C" void func_00134748(S133_S* self, int flags) {
    self->unk8 = D_0033A478;
    if (self->unk74) {
        func_00119400(D_00368A38[0], (void*)self->unk74);
        self->unk74 = 0;
    }
    func_0027AC90(self->unk6C);
    func_001CE990(self, flags);
}

INCLUDE_ASM("asm/nonmatchings/game/t_133A98", func_001347B0);

extern "C" int func_001348C8(S133_S* self) {
    int r;
    func_0027AC90(self->unk6C);
    if (self->unk74) {
        func_00138960(self->unk74, 0);
    }
    r = func_002763E0(0xFE54486D, 0);
    if (r) {
        func_0027ABB0(self->unk6C, r);
    }
    self->unk78 = 0;
    return 1;
}

extern "C" int func_00134938(S133_S* self, int a, int b) {
    func_001348C8(self);
    func_0027B848(a, self->unk6C, 0);
    if (b) {
        func_001343B0(self);
    }
    return 1;
}

INCLUDE_ASM("asm/nonmatchings/game/t_133A98", func_00134998);

extern "C" void func_001349A8(void) {
}

extern "C" void func_001349B0(S_001349B0* self, int p1, int p2) {
    func_0027D870(&self->unk6C, p1, p2, 0);
}

extern "C" int func_001349D0(S133_S* self, int x) {
    int v;
    if (func_0027D400(self->unk6C, x, &v, 0)) {
        return func_001376E8(x, func_00134380((void*)v), 0);
    }
    return 0;
}

extern "C" int func_00134A20(S133_S* self, int key) {
    int v = 0;
    func_0027D400(self->unk6C, key, &v, 0);
    return v;
}

INCLUDE_ASM("asm/nonmatchings/game/t_133A98", func_00134A50);

extern "C" int func_00134D20(S_00134D20* self) {
    return self->unk74;
}

extern "C" void func_00134D28(S133_S* self) {
    self->unk74 = func_00138908(func_00113D20(0x45A0));
}

GP_DATA(D_00372AD8);
GP_DATA(D_00372AE0);
GP_DATA(D_00372AE8);
GP_DATA(D_00372AF0);
extern "C" void func_00134D60(int a, int b) {
    if (b == 0xFFFF && a) {
        D_00372AD8 = 0x91C1EC93;
        D_00372AE0 = 0xD2C041C2;
        D_00372AE8 = 0xAEE1AF7D;
        D_00372AF0 = 0xB1A55798;
    }
}

extern "C" void func_00134DB0(void) {
    func_00134D60(1, 0xFFFF);
}

extern "C" S133_S* func_00134DD0(S133_S* self, int a) {
    func_001CE8D0(self);
    *(int*)self->unk6C = a;
    self->unk8 = D_0033A5E0;
    *(int*)(self->unk6C + 4) = 0;
    return self;
}

extern "C" void func_00134E18(S_00134E18* self, int a1, int a2, int a3, int a4, int a5, int a6) {
    VE_00134E18* e = &self->unk8[11];
    e->unk4((char*)self + e->unk0, a1, a2, a3, a4, a5, a6);
}

INCLUDE_ASM("asm/nonmatchings/game/t_133A98", func_00134E40);

struct S134FB0 { char pad0[0x70]; int unk70; };

GP_DATA(D_00369420);
extern "C" void func_00134FB0(S134FB0* self, int a, const char* b, const char* c) {
    int h = CrcFromPathLowercase(b);
    int h2;
    if (c) {
        h2 = CrcFromPathLowercase(c);
    } else {
        h2 = 0;
    }
    int r = func_00160170(D_00369420, h, a, h2, 0, 1);
    int t = self->unk70;
    if (t) func_0015F4B8(r, t);
}

GP_DATA(D_00369420);
extern "C" void func_00135048(void) {
    func_00160A90(D_00369420);
}

INCLUDE_ASM("asm/nonmatchings/game/t_133A98", func_00135068);

extern "C" int func_00135A70(void) {
    func_00161BA0(D_00369420);
    return 1;
}
