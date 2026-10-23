#include "common.h"

struct S00175A68 {
    char pad[0x18];
    char unk18;
};

struct S00175D48 {
    char pad[0x14];
    void* unk14;
};

extern "C" {
int func_0027D870(int, int, int*, int);
void func_0017D658(void*, int, int);
int func_00172CC0(void*);
void func_0017E068(void*, float, float);
void func_00174C20_1(void*) __asm__("func_00174C20");
extern u8 D_00341388[];
void func_0017D580(void*, int);
void func_00172A00_2(void*, int) __asm__("func_00172A00");
extern u8 D_003410A8[];
void func_00289F90(int);
void Heap_Free(int, void*);
extern int D_00368A38[] __attribute__((section(".sdata")));
extern u8 D_00340F78[];
extern u8 D_00340EF0[];
extern u8 D_00341728[];
void func_00174058(void*);
void func_0017D6D0(void*);
void func_00172810(int);
int func_00175A90(void*, int);
void func_0027C448(int, int, int);
extern u8 D_00341218[];
void func_00172A00(void*);
extern u8 D_003415B8[];
extern u8 D_00341558[];
}

struct S174C20 { char pad0[0x18]; float unk18; float unk1C; float unk20; };

extern "C" void func_00174C20(S174C20* self, float* p) {
    self->unk1C = self->unk18;
    float v = *p * self->unk20;
    *p = v;
    self->unk18 = self->unk18 + v;
}

INCLUDE_ASM("asm/nonmatchings/game/t_174C20", func_00174C48);

struct S174C90 { char pad0[0x30]; int unk30; char pad34[0x20]; int unk54; };

extern "C" int func_00174C90(S174C90* self) {
    int r = 0;
    if (self->unk30 != 0 || self->unk54 != 0) r = 1;
    return r;
}

extern "C" float func_00174CB8(float* p) {
    return p[6] / p[9];
}

extern "C" void func_00174CD8(void) {
}

extern "C" int func_00174CE0(S174C90* self) {
    int r = 0;
    if (self->unk30 != 0 || self->unk54 != 0) r = 1;
    return r;
}

struct S_00174D08 { char pad0[0x18]; float unk18; float unk1C; char pad20[4]; float unk24; float unk28; char pad2C[4]; int unk30; };

INCLUDE_ASM("asm/nonmatchings/game/t_174C20", func_00174D08);

struct S174DC8 { char pad0[0x18]; float unk18; float unk1C; char pad20[8]; float unk28; char pad2C[4]; int unk30; char unk34[1]; };

extern "C" void func_00174DC8(S174DC8* self) {
    func_00174C20_1(self);
    float f = self->unk18;
    float g = 0.0f;
    if (f < 0.0f || (g = self->unk28, g < f)) {
        self->unk18 = g;
        self->unk30 = 1;
    }
    func_0017E068(self->unk34, self->unk1C, self->unk18);
}

struct S174E38 { char pad0[0x58]; int unk58; };

extern "C" void func_00174E38(S174E38* self) {
    func_00174058(self);
    self->unk58 = 1;
}

struct S174E68 { char pad0[0x18]; float unk18; float unk1C; char pad20[8]; float unk28; char pad2C[4]; int unk30; char unk34[0x24]; int unk58; };

extern "C" void func_00174E68(S174E68* self, float* p) {
    if (self->unk58 == 0) {
        *p = -*p;
    }
    func_00174C20((S174C20*)self, p);
    while (1) {
        if (self->unk18 < 0.0f) {
            func_0017E068(self->unk34, self->unk1C, 0.0f);
            self->unk1C = 0.0f;
            self->unk30 = 1;
            self->unk58 ^= 1;
            self->unk18 = -self->unk18;
            continue;
        }
        if (self->unk28 < self->unk18) {
            func_0017E068(self->unk34, self->unk1C, self->unk28);
            self->unk1C = self->unk28;
            self->unk30 = 1;
            self->unk58 ^= 1;
            self->unk18 = 2.0f * self->unk28 - self->unk18;
            continue;
        }
        break;
    }
    func_0017E068(self->unk34, self->unk1C, self->unk18);
}

extern "C" void func_00174F68(void) {
}

INCLUDE_ASM("asm/nonmatchings/game/t_174C20", func_00174F70);

extern "C" u32 func_001750A0(void) {
    return 0xA1762145 /* PLAY */;
}

struct E_1750B0 { int unk0; int unk4; };
struct N_1750B0 { int unk0; N_1750B0* unk4; E_1750B0* unk8; };
struct L_1750B0 { int unk0; N_1750B0* unk4; N_1750B0* unk8; };
struct It_1750B0 {
    int unk0;
    N_1750B0* cur;
    It_1750B0(N_1750B0* n) : cur(n) {}
    bool operator!=(const It_1750B0& o) const { return cur != o.cur; }
    void operator++() { cur = cur->unk4; }
};
struct C_1750B0 { int unk0; L_1750B0 unk4; };
struct S_1750B0 { char pad0[0x14]; void* unk14; char pad18[0x1C]; char unk34[0x10]; C_1750B0 unk44; };

extern "C" void func_0017DFC0(void*);
static inline void Clear_1750B0(L_1750B0* l) {
    N_1750B0* s = (N_1750B0*)&l->unk4;
    N_1750B0* f = l->unk8;
    l->unk8 = s;
    l->unk4 = s;
    if (f != s) {
        N_1750B0* q = f;
        do {
            f = f->unk4;
            Heap_Free(D_00368A38[0], q);
            q = f;
        } while (f != s);
    }
}

INCLUDE_ASM("asm/nonmatchings/game/t_174C20", func_001750B0);

extern "C" u32 func_001751E0(void) {
    return 0x4F792E6C /* Cycle */;
}

INCLUDE_ASM("asm/nonmatchings/game/t_174C20", func_001751F0);

extern "C" u32 func_00175320(void) {
    return 0x3153E314 /* pingpong */;
}

INCLUDE_ASM("asm/nonmatchings/game/t_174C20", func_00175330);

INCLUDE_ASM("asm/nonmatchings/game/t_174C20", func_00175460);

struct VE_175560 { s16 unk0; s16 unk2; void (*unk4)(void*, int); };
struct V_175560 { char pad0[0x18]; VE_175560 unk18; };
struct S_175560 { V_175560* unk0; int unk4; };

extern "C" void func_00175560(S_175560* self, int a) {
    if (self->unk4 == 0) {
        func_00289F90(a);
        return;
    }
    V_175560* v = self->unk0;
    v->unk18.unk4((char*)self + v->unk18.unk0, a);
}

INCLUDE_ASM("asm/nonmatchings/game/t_174C20", func_001755B0);

INCLUDE_ASM("asm/nonmatchings/game/t_174C20", func_00175650);

INCLUDE_ASM("asm/nonmatchings/game/t_174C20", func_00175750);

extern "C" void func_001757F0(void** self, int flags) {
    *self = D_00340F78;
    if (flags & 1) {
        Heap_Free(D_00368A38[0], self);
    }
}

INCLUDE_ASM("asm/nonmatchings/game/t_174C20", func_00175830);

INCLUDE_ASM("asm/nonmatchings/game/t_174C20", func_00175930);

struct S001759F8 { char pad0[0x18]; int unk18; };
struct S001759F8_b { char pad0[0x20]; int unk20; };

INCLUDE_ASM("asm/nonmatchings/game/t_174C20", func_001759F8);

extern "C" void func_00175A68(S00175A68* self) {
    func_0017D6D0(&self->unk18);
}

extern "C" void func_00175A88(void) {
}

INCLUDE_ASM("asm/nonmatchings/game/t_174C20", func_00175A90);

extern "C" u32 func_00175CB0(void) {
    return 0xA075808C /* source */;
}

struct S175CC0 { char pad0[0x14]; void* unk14; char unk18[1]; };

extern "C" void func_00175CC0(S175CC0* self, int a) {
    self->unk14 = D_003410A8;
    func_0017D580(self->unk18, 2);
    func_00172A00_2(self, a);
}

extern "C" void func_00175D10(void) {
}

extern "C" void func_00175D18(int a0, int a1) {
    func_00172810(a1);
}

extern "C" u32 func_00175D38(void) {
    return 0xC3D43B9A /* blank */;
}

extern "C" void func_00175D48(S00175D48* self) {
    self->unk14 = D_00341218;
    func_00172A00(self);
}

struct P_00175D70 { int unk0; int unk4; int unk8; };
struct S_00175D70 { char pad0[0xC]; int unkC; char pad10[8]; float unk18; char pad1C[4]; char unk20[1]; };
extern "C" int func_0027D268(int, int, float*, int);

static inline void Follow175(P_00175D70* p, int* k) {
    int t;
    while ((p->unk8 && (func_0027D870(p->unk8, *k, &t, 0) ^ 1) == 0) ||
           (p->unk4 && (func_0027D870(p->unk4, *k, &t, 0) ^ 1) == 0)) {
        *k = t;
    }
}

extern "C" void func_00175D70(S_00175D70* self, P_00175D70* p) {
    int key;
    int key2;
    float* f = &self->unk18;
    *f = 1.0f;
    if (func_0027D268(p->unk0, 0x29461E27, f, 0) == 0) {
        int ok;
        if ((func_0027D870(p->unk0, 0x29461E27, &key, 0) ^ 1) != 0) {
            ok = 0;
        } else {
            Follow175(p, &key);
            ok = 1;
        }
        if ((ok ^ 1) == 0) {
            if (!p->unk8 || func_0027D268(p->unk8, key, f, 0) == 0) {
                if (p->unk4) {
                    func_0027D268(p->unk4, key, f, 0);
                }
            }
        }
    }
    if ((func_0027D870(p->unk0, 0x98549BA4, &key2, 1) ^ 1) == 0) {
        Follow175(p, &key2);
    }
    func_0017D658(self->unk20, self->unkC, key2);
}

INCLUDE_ASM("asm/nonmatchings/game/t_174C20", func_00175F40);

extern "C" void func_00175FB8(void) {
}

extern "C" u32 func_00175FC0(void) {
    return 0x2CC9B571 /* difference */;
}

struct S175FD0 { char pad0[0x14]; void* unk14; char pad18[8]; char unk20[1]; };

extern "C" void func_00175FD0(S175FD0* self, int a) {
    self->unk14 = D_00341388;
    func_0017D580(self->unk20, 2);
    func_00172A00_2(self, a);
}

struct P176020 { int unk0; int unk4; int unk8; };
struct S176020 { char pad0[0x18]; int unk18; char pad1C[4]; int unk20; };

INCLUDE_ASM("asm/nonmatchings/game/t_174C20", func_00176020);

INCLUDE_ASM("asm/nonmatchings/game/t_174C20", func_00176108);

INCLUDE_ASM("asm/nonmatchings/game/t_174C20", func_001761F8);

INCLUDE_ASM("asm/nonmatchings/game/t_174C20", func_001762D0);

extern "C" void func_00176598(void) {
}

INCLUDE_ASM("asm/nonmatchings/game/t_174C20", func_001765A0);

extern "C" void func_00176878(void) {
}

INCLUDE_ASM("asm/nonmatchings/game/t_174C20", func_00176880);

INCLUDE_ASM("asm/nonmatchings/game/t_174C20", func_001769A0);

extern "C" void func_001769C0(S00175D48* self) {
    self->unk14 = D_003415B8;
    func_00172A00(self);
}

extern "C" void func_001769E8(S00175D48* self) {
    self->unk14 = D_00341558;
    func_00172A00(self);
}

extern "C" u32 func_00176A10(void) {
    return 0x54628ED7 /* blend */;
}

extern "C" void func_00176A20(S00175D48* self) {
    self->unk14 = D_00341558;
    func_00172A00(self);
}

struct VE_176A48 { s16 delta; s16 unk2; void (*fn)(void*, int); };
struct V_176A48 { char pad0[0x10]; VE_176A48 unk10; };
struct W_176A48 { V_176A48* unk0; };
struct E_176A48 { int unk0; W_176A48* unk4; };
struct N_176A48 { int unk0; N_176A48* unk4; E_176A48* unk8; };
struct It_176A48 {
    int unk0;
    N_176A48* cur;
    It_176A48(N_176A48* n) : cur(n) {}
    bool operator!=(const It_176A48& o) const { return cur != o.cur; }
    void operator++() { cur = cur->unk4; }
};
struct S_176A48 { char pad0[0x14]; void* unk14; char pad18[0x10]; N_176A48 unk28; };

INCLUDE_ASM("asm/nonmatchings/game/t_174C20", func_00176A48);

INCLUDE_ASM("asm/nonmatchings/game/t_174C20", func_00176B58);
