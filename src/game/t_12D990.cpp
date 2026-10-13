#include "common.h"

struct S_0012DA38;
struct S_0012DA40;

extern "C" void func_00119400(int, void*);
extern "C" int D_00368A38[] __attribute__((section(".sdata")));

inline void operator delete[](void* p) {
    func_00119400(D_00368A38[0], p);
}

struct S12D_F { char pad0[0x20]; float unk20; };

struct S12D_AB {
    char pad0[0xC];
    virtual ~S12D_AB();
};

struct S12D_A : S12D_AB {
    char pad10[0xC];
};

struct S12D_E {
    char pad0[0x4];
    S12D_F* unk4;
    int unk8;
    char padC[0x4];
    int unk10;
    void* unk14;
    int unk18;
    int unk1C;
    int unk20;
    int unk24;
    int unk28;
    int unk2C;
    int unk30;
    int unk34;
    int unk38;
    int unk3C;
    char pad40[0x20];
    float unk60;
    int unk64;
    char pad68[0x4];
    S12D_A* unk6C;
    u32 unk70;
};

struct S12D_R { char pad0[0x1C]; int unk1C; };

struct S_0012E600 { char pad0[0x4]; int unk4; int unk8; int unkC; int unk10; void* unk14; };

extern "C" {
float func_0012A1B0(void*);
void func_0012E290(void*, float, float);
void func_0012A590_i(int) __asm__("func_0012A590");
int func_00124630(int);
int func_0012FA98_i(void*, int) __asm__("func_0012FA98");
void func_0012FAC8(void*, int, int);
void func_001277C0(float, float, int, int, int, int, int, int);
int func_0012F228_p(void*) __asm__("func_0012F228");
void func_00124688(int, int);
void func_0012F9E8(S12D_E*);
int func_0014EBA8(void);
void func_0012E628(S12D_E*, int);
S12D_R* func_001D1CF8(int, u32);
void func_0012A448(void*);
extern int D_00368A38[] __attribute__((section(".sdata")));
void func_00119400(int, void*);
int func_0027D870(void*, u32, int*, int);
extern int D_00369208;
extern int D_003691F8[2];
extern int D_003692B0;
extern int D_003692A0[2];
void* func_00118F20(int, int, int, int);
void* func_0011C2A8(int, int);
extern u8 D_00339F58[];
extern u8 D_00339F18[];
extern u8 D_00339ED8[];
extern u8 D_00339F98[];
void func_0014EBC8(int);
int func_0016E810(int, int, int);
int func_0015FAA0(int, int, int);
void func_00127940(S12D_A*, int);
float func_0012F3E0(S12D_E*);
int func_0016E7A8(int, int);
int func_001F9E80(S12D_R*);
void func_00126588(int, int, int, int, int, int, int, float);
void func_0012E668(S12D_E*, void*);
int func_0012DA38(S_0012DA38*);
void func_0012DA40(S_0012DA40*, int);
int func_0012E6D0(S12D_E*);
extern u8 D_00339D88[];
}

struct S_0012DA38 { char pad0[0x3C]; int unk3C; };
struct S_0012DA40 { char pad0[0x3C]; int unk3C; };
struct S_0012E5F0 { char pad0[0x68]; int unk68; };

extern "C" int func_0012D990(S12D_E* self, float t) {
    if (t == 0.0f) {
        func_0012DA40((S_0012DA40*)self, 0);
    }
    if (func_0012DA38((S_0012DA38*)self) == 2) {
        func_0012DA40((S_0012DA40*)self, 1);
        self->unk60 = t;
        return 1;
    }
    return 0;
}

extern "C" void func_0012D9F8(void) {
}

extern "C" void func_0012DA00(S12D_E* self) {
    func_0012A448((char*)self + 4);
    self->unk3C = 0;
    self->unk60 = 0;
    self->unk64 = 0;
}

extern "C" int func_0012DA38(S_0012DA38* self) {
    return self->unk3C;
}

extern "C" void func_0012DA40(S_0012DA40* self, int v) {
    self->unk3C = v;
}

extern "C" int func_0012DA48(S_0012DA38* self) {
    return func_0012DA38(self) == 1;
}

INCLUDE_ASM("asm/nonmatchings/game/t_12D990", func_0012DA70);

extern "C" void func_0012DF30(S12D_E* self) {
    if (self->unk70 && self->unk6C) {
        self->unk70 = 0;
        delete[] self->unk6C;
        self->unk6C = 0;
    }
}

INCLUDE_ASM("asm/nonmatchings/game/t_12D990", func_0012DFC8);

extern "C" void func_0012E228(S12D_E* self) {
    u32 i;
    for (i = 0; i < self->unk70; i++) {
        func_00127940(&self->unk6C[i], 1);
    }
}

INCLUDE_ASM("asm/nonmatchings/game/t_12D990", func_0012E290);

GP_DATA(D_00369208);
GP_DATA(D_003691F8);
extern "C" void* func_0012E3B8(int size) {
    int heap = D_003691F8[D_00369208];
    if (heap) {
        return func_0011C2A8(heap, 1);
    }
    return func_00118F20(D_00368A38[0], size, 1, 0);
}

INCLUDE_ASM("asm/nonmatchings/game/t_12D990", func_0012E410);

extern "C" int func_0012E5F0(S_0012E5F0* self) {
    return self->unk68;
}

INCLUDE_ASM("asm/nonmatchings/game/t_12D990", func_0012E5F8);

extern "C" S_0012E600* func_0012E600(S_0012E600* self, int a) {
    self->unk4 = a;
    self->unk10 = 0;
    self->unk14 = D_00339D88;
    self->unk8 = 0;
    self->unkC = 0;
    return self;
}

extern "C" void func_0012E628(S12D_E* self, int flags) {
    self->unk14 = D_00339D88;
    if (flags & 1) {
        func_00119400(D_00368A38[0], self);
    }
}

extern "C" void func_0012E668(S12D_E* self, void* params) {
    int v = 0;
    func_0027D870(params, 0x40C698AF, &v, 0);
    self->unk10 = v;
}

extern "C" void func_0012E6B0(void) {
}

extern "C" int func_0012E6B8(void) {
    return 0;
}

extern "C" void func_0012E6C0(void) {
}

extern "C" int func_0012E6C8(void) {
    return 2;
}

extern "C" int func_0012E6D0(S12D_E* self) {
    return func_0012E5F0((S_0012E5F0*)self->unk4);
}

extern "C" int func_0012E6F0(S12D_E* self) {
    S12D_R* r = func_001D1CF8(func_0012E6D0(self), 0x222756D5);
    if (r) {
        return r->unk1C;
    }
    return 0;
}

extern "C" S12D_E* func_0012E728(S12D_E* self, int a) {
    func_0012E600((S_0012E600*)self, a);
    self->unk20 = 0;
    self->unk14 = D_00339F98;
    self->unk24 = func_001F9E80(func_001D1CF8(func_0012E6D0(self), 0x7149B753));
    self->unk1C = 0;
    self->unk28 = -1;
    return self;
}

extern "C" void func_0012E790(S12D_E* self, int flags) {
    self->unk14 = D_00339F98;
    if (self->unk1C) {
        func_00124688(self->unk1C, self->unk28);
    }
    if (self->unk20) {
        func_0014EBC8(self->unk20);
        self->unk20 = 0;
    }
    self->unk1C = 0;
    func_0012E628(self, 0);
    if (flags & 1) {
        func_0012F9E8(self);
    }
}

GP_DATA(D_003692B0);
GP_DATA(D_003692A0);
extern "C" void* func_0012E818(int size) {
    int heap = D_003692A0[D_003692B0];
    if (heap) {
        return func_0011C2A8(heap, 1);
    }
    return func_00118F20(D_00368A38[0], size, 1, 0);
}

extern "C" void func_0012E870(S12D_E* self, void* params) {
    func_0012E668(self, params);
}

INCLUDE_ASM("asm/nonmatchings/game/t_12D990", func_0012E890);

struct O12E9E0 { char pad0[4]; char unk4[1]; char pad5[0x1B]; float unk20; char pad24[0x14]; int unk38; };
struct S12E9E0 { char pad0[4]; O12E9E0* unk4; char pad8[0x14]; int unk1C; int unk20; int unk24; };

extern "C" void func_0012E9E0(S12E9E0* self) {
    float old = self->unk4->unk20;
    self->unk4->unk20 = func_0012A1B0(self->unk4->unk4);
    func_0012E290(self->unk4, old, self->unk4->unk20);
    if (self->unk4->unk20 < old) {
        if (self->unk20 != 0) {
            self->unk1C = func_0016E7A8(self->unk20, 0);
        } else {
            int t = self->unk4->unk38;
            self->unk1C = func_0015FAA0(self->unk24 + t, 1, t != 0);
        }
    }
}

struct O12EA80 { char pad0[0x38]; int unk38; };
struct S12EA80 { char pad0[4]; O12EA80* unk4; char pad8[0x14]; int unk1C; int unk20; int unk24; int unk28; };

extern "C" void func_0012EA80(S12EA80* self, int n) {
    int h;
    int t = self->unk1C;
    if (t != 0) {
        h = n != 0;
        func_00124688(t, self->unk28);
    } else {
        int b = n != 0;
        self->unk1C = func_0015FAA0(self->unk24 + n, 1, b);
        h = b;
    }
    int u = self->unk20;
    if (u != 0) {
        func_0014EBC8(u);
        self->unk20 = 0;
    }
    char* p = (char*)self + 0x2C;
    int r = func_0015FAA0(self->unk24 + n, 1, h);
    self->unk1C = r;
    self->unk28 = func_00124630(r);
    self->unk4->unk38 = n;
    func_0012FA98_i(p, func_0012E6D0((S12D_E*)self));
    func_0012FAC8(p, n, func_0012E6D0((S12D_E*)self));
}

struct S12EB68 { char pad0[4]; int unk4; char pad8[0x14]; int unk1C; int unk20; int unk24; int unk28; };

extern "C" void func_0012EB68(S12EB68* self, int a) {
    func_0012A590_i(self->unk4 + 4);
    int t = self->unk20;
    if (t != 0) {
        self->unk1C = func_0016E810(t, self->unk24 + a, a);
    } else {
        self->unk1C = func_0015FAA0(self->unk24 + a, 1, a != 0);
    }
    char* p = (char*)self + 0x2C;
    self->unk28 = func_00124630(self->unk1C);
    func_0012FA98_i(p, func_0012E6D0((S12D_E*)self));
    func_0012FAC8(p, a, func_0012E6D0((S12D_E*)self));
}

INCLUDE_ASM("asm/nonmatchings/game/t_12D990", func_0012EC20);

extern "C" S12D_E* func_0012ED80(S12D_E* self, int a, int b) {
    func_0012E600((S_0012E600*)self, a);
    self->unk14 = D_00339F58;
    if (a) {
        self->unk8 = func_0012E6D0(self);
    } else {
        self->unk8 = b;
    }
    self->unk20 = func_001F9E80(func_001D1CF8(self->unk8, 0x7149B753));
    self->unk18 = 0;
    self->unk24 = 0;
    return self;
}

extern "C" void func_0012EE08(S12D_E* self, int flags) {
    self->unk14 = D_00339F58;
    if (self->unk1C) {
        func_0014EBC8(self->unk1C);
        self->unk1C = 0;
    }
    self->unk18 = 0;
    func_0012E628(self, flags);
}

extern "C" void func_0012EE68(S12D_E* self, void* params) {
    func_0012E668(self, params);
}

struct S12EE88 { char pad0[0x18]; int unk18; int unk1C; char pad20[4]; float unk24; };

extern "C" int func_0012EE88(S12EE88* self, int a) {
    if (self->unk18) {
        int t = self->unk1C;
        if (t && !(self->unk24 <= 0.0f)) {
            self->unk18 = func_0016E7A8(t, 0);
            func_001277C0(self->unk24, 1.0f, self->unk18, a, a + 0x800, func_0012F228_p(self) + 0xC, 0, self->unk1C);
            func_0016E7A8(self->unk1C, 1);
            return 1;
        }
    }
    return 0;
}

extern "C" void func_0012EF48(void) {
}

extern "C" void func_0012EF50(S12D_E* self, int n) {
    if (self->unk1C) {
        func_0014EBC8(self->unk1C);
        self->unk1C = 0;
    }
    self->unk1C = func_0014EBA8();
    func_0016E7A8(self->unk1C, 0);
    if (self->unk1C) {
        self->unk18 = func_0016E810(self->unk1C, self->unk20 + n, n);
    } else {
        self->unk18 = func_0015FAA0(self->unk20 + n, 1, n != 0);
    }
}

extern "C" void func_0012EFE0(S12D_E* self, int n) {
    if (self->unk1C) {
        self->unk18 = func_0016E810(self->unk1C, self->unk20 + n, n);
    } else {
        self->unk18 = func_0015FAA0(self->unk20 + n, 1, n != 0);
    }
}

INCLUDE_ASM("asm/nonmatchings/game/t_12D990", func_0012F040);

extern "C" int func_0012F228(S12D_E* self) {
    S12D_R* r = func_001D1CF8(self->unk8, 0x222756D5);
    if (r) {
        return r->unk1C;
    }
    return 0;
}

extern "C" S12D_E* func_0012F258(S12D_E* self, int a) {
    func_0012E600((S_0012E600*)self, a);
    self->unk14 = D_00339F18;
    self->unk2C = 0;
    self->unk18 = 0;
    self->unk1C = 0;
    self->unk20 = 0;
    self->unk24 = 0;
    self->unk28 = 0;
    self->unk30 = func_0014EBA8();
    self->unk34 = func_0016E7A8(self->unk30, 0);
    self->unk38 = func_001F9E80(func_001D1CF8(func_0012E6D0(self), 0x7149B753));
    return self;
}

extern "C" void func_0012F2E0(S12D_E* self, int flags) {
    self->unk14 = D_00339F18;
    if (self->unk30) {
        func_0014EBC8(self->unk30);
        self->unk30 = 0;
    }
    if (self->unk34) {
        self->unk34 = 0;
    }
    func_0012E628(self, flags);
}

extern "C" void func_0012F348(S12D_E* self, void* params) {
    func_0012E668(self, params);
}

extern "C" int func_0012F368(S12D_E* self, int a) {
    int b = a + 0x800;
    int r = func_0012E6F0(self);
    func_00126588(self->unk34, a, b, r + 0xC, 0, -1, self->unk30, self->unk4->unk20);
    func_0016E7A8(self->unk30, 1);
    return 1;
}

INCLUDE_ASM("asm/nonmatchings/game/t_12D990", func_0012F3E0);

extern "C" void func_0012F5B0(S12D_E* self) {
    float old = self->unk4->unk20;
    self->unk4->unk20 = func_0012F3E0(self);
    if (self->unk4->unk20 < old) {
        self->unk34 = func_0016E7A8(self->unk30, 0);
    }
}

extern "C" void func_0012F618(void) {
}

INCLUDE_ASM("asm/nonmatchings/game/t_12D990", func_0012F620);

extern "C" S12D_E* func_0012F8D0(S12D_E* self, int a) {
    func_0012E600((S_0012E600*)self, a);
    self->unk14 = D_00339ED8;
    for (int i = 0x7F; i != -1; i -= 0x20) {
    }
    for (int j = 0x7F; j != -1; j -= 0x20) {
    }
    return self;
}

extern "C" void func_0012F958(S12D_E* self, int flags) {
    self->unk14 = D_00339ED8;
    func_0012E628(self, flags);
}

extern "C" void func_0012F980(S12D_E* self, void* params) {
    func_0012E668(self, params);
}
