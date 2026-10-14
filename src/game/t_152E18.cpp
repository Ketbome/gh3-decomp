#include "common.h"

struct S_00154180 { char pad0[0x58]; struct S_00154180* unk58; };
struct S_001537C0 { s16 unk0; s16 unk2; s16 unk4; s16 unk6; s16 unk8; };

struct VE_001530D8 { s16 unk0; s16 unk2; void (*unk4)(void*, int); };
struct S_001530D8 { char pad0[0x18]; VE_001530D8* unk18; };

struct VE_00153498 { s16 unk0; s16 unk2; int (*unk4)(void*, int, int, int); };
struct S_00153498 { char pad0[0x8]; VE_00153498* unk8; };

struct VE_001534C0 { s16 unk0; s16 unk2; void (*unk4)(void*, int, int); };
struct S_001534C0 { char pad0[0x8]; VE_001534C0* unk8; };

struct VE_001534E8 { s16 unk0; s16 unk2; void (*unk4)(void*, int); };
struct S_001534E8 { char pad0[0x8]; VE_001534E8* unk8; };

struct VE_001535C0 { s16 unk0; s16 unk2; void (*unk4)(void*, int, int, int, int); };
struct S_001535C0 { char pad0[0x8]; VE_001535C0* unk8; };

struct S_00153150 { char pad0[0x10]; void* unk10; };
struct VE_5C { s16 unk0; s16 unk2; void (*unk4)(void*); };
struct S_00153D80 { int unk0; char pad4[0x20]; float unk24; char pad28[0x10]; int unk38; char pad3C[4]; int unk40; char pad44[8]; int unk4C; char pad50[4]; int unk54; char pad58[4]; VE_5C* unk5C; };
struct N_00154510 { char pad0[8]; N_00154510* unk8; N_00154510* unkC; };
struct S_00154510 { N_00154510* unk0; };
struct S_00154640 { char pad0[0x84]; void* unk84; };

struct S_00153430 { char pad0[8]; void* unk8; };
struct S_00153F08 { char pad0[0xC]; float unkC; float unk10; float unk14; float unk18; float unk1C; float unk20; char pad24[4]; float unk28; char pad2C[4]; int unk30; char pad34[0x10]; int unk44; int unk48; char pad4C[4]; int unk50; char pad54[8]; VE_5C* unk5C; };
struct VE_C { s16 unk0; s16 unk2; int (*unk4)(void*); };
struct VE_Cv { s16 unk0; s16 unk2; void (*unk4)(void*); };
struct O_00152E88 { char pad0[0xC]; VE_C* unkC; };
struct S_00152E88 { char pad0[0x10]; void* unk10; O_00152E88* unk14; };
struct S_00153588 { int unk0; char pad4[4]; VE_Cv* unk8; };
struct A_00153100 { char pad0[8]; int unk8; };
struct S_00153100 { char pad0[0x10]; void* unk10; A_00153100* unk14; };
struct S_00154608 { char pad0[0x58]; void* unk58; char pad5C[4]; int unk60; int unk64; int unk68; char pad6C[0x18]; void* unk84; void* unk88; };
struct S_00154670 { char pad0[0xC]; int unkC; char pad10[0x28]; int unk38; char pad3C[4]; int unk40; char pad44[0xC]; float unk50[3]; char pad5C[4]; int unk60; int unk64; int unk68; char pad6C[0x18]; void* unk84; void* unk88; };

struct N_001544B8 { char pad0[8]; N_001544B8* unk8; N_001544B8* unkC; };
struct S_001544B8 { N_001544B8* unk0; };
struct U_001547C8 { char pad0[0xA4]; u8 unkA4; };
struct S_001547C8 { char pad0[0x68]; int unk68; void* unk6C[1]; };
struct O_00152E18 { char pad0[0xC]; VE_Cv* unkC; };
struct S_00152E18 { char pad0[4]; int unk4; char pad8[8]; void* unk10; O_00152E18* unk14; };

struct VE_00153510 { s16 unk0; s16 unk2; void (*unk4)(void*, int); };
struct S_00153510 { char pad0[8]; VE_00153510* unk8; };
struct S_00153810 { int unk0; int unk4; int unk8; int unkC; int unk10; int unk14; int unk18; float unk1C; float unk20; int unk24; int unk28; char pad2C[8]; u8 unk34[4]; u32 unk38; int unk3C; int unk40; char pad44[8]; int unk4C; int unk50; int unk54; int unk58; void* unk5C; };

extern "C" {
void func_00240F58(void*, int);
int func_00152E88_r(void) __asm__("func_00152E88");
void func_0015F460(int, int);
extern char D_0033C800[];
int func_00154830(S_001547C8*, void*);
U_001547C8* func_00156790(void*);
void func_0015F3C0(void*, int);
void func_0015F410(void*, int);
void Heap_Free(int, void*);
extern int D_00368A38;
extern char D_0033C840[];
extern void* D_00369B88;
int func_0015F3E8(void*);
void func_0015F488(void*, int);
void* func_00154430(void*, void*);
void func_001544B8(void*, void*);
void func_00154750(void*);
extern char D_0033C9C0[];
void func_00153E70(void*);
void func_00154708(S_00154608*);
void func_0015F720(void*);
void func_0015F748(void*);
void func_0015F770(void*);
void func_0015F798(void*);
void func_0015F848(void*);
void func_0015F870(void*);
void func_0015F898(void*);
void func_00154540(void*, void*);
extern char D_00372B60[];
void func_00189540(void);
extern S_00154180* D_00369B8C;
void func_00154540_f(void*, void*, float) __asm__("func_00154540");
void* Heap_Alloc(int, int, int, int);
void func_00119490(int, int);
void func_001194B8(int);
void func_0030ADA0(void*, void*, int);
void func_001537E0(S_001537C0*, int);
}

inline void operator delete[](void* p) {
    Heap_Free(D_00368A38, p);
}

struct H_152 { char pad0[0x1E8]; int unk1E8; };
struct S_00153DE0 { char pad0[0x8]; void* unk8; char padC[0x50]; VE_C* unk5C; };
struct S_00153E70 { char pad0[0x4]; S_001537C0* unk4; void* unk8; };
struct N_00154430 { char pad0[0x4]; void* unk4; N_00154430* unk8; N_00154430* unkC; };
struct S_00154430 { N_00154430* unk0; };

struct S_00153268 { char pad0[0x4]; int unk4; };
struct S_00154420 { int unk0; };

struct S_00153140 { char pad0[0x14]; int unk14; };
struct S_00153148 { char pad0[0x4]; int unk4; };

INCLUDE_ASM("asm/nonmatchings/game/t_152E18", func_00152E18);

extern "C" int func_00152E88(S_00152E88* self) {
    if (self->unk10 != 0) return func_0015F3E8(self->unk10);
    O_00152E88* o = self->unk14;
    VE_C* e = &o->unkC[9];
    return e->unk4((char*)o + e->unk0);
}

INCLUDE_ASM("asm/nonmatchings/game/t_152E18", func_00152ED8);

INCLUDE_ASM("asm/nonmatchings/game/t_152E18", func_00152F48);

struct VE_152F78 { s16 unk0; s16 unk2; void (*unk4)(void*, int, int); };
struct V_152F78 { char pad0[0xC8]; VE_152F78 unkC8; };
struct O_152F78 { char pad0[0xC]; V_152F78* unkC; };
struct S_152F78 { char pad0[4]; unsigned int unk4; char pad8[8]; int unk10; O_152F78* unk14; };

extern "C" void func_00152F78(S_152F78* self, int a) {
    O_152F78* o = self->unk14;
    if (o) {
        V_152F78* v = o->unkC;
        VE_152F78* e = &v->unkC8;
        e->unk4((char*)o + e->unk0, func_00152E88_r(), a);
        if (self->unk4 & 0x40) self->unk4 |= 0x20;
    }
    if (self->unk10) func_0015F460(self->unk10, a);
}

INCLUDE_ASM("asm/nonmatchings/game/t_152E18", func_00153010);

INCLUDE_ASM("asm/nonmatchings/game/t_152E18", func_00153078);

struct F_00153080 { char pad0[0x4]; u16 unk4; };
struct S_00153080 { char pad0[0x14]; F_00153080* unk14; };

extern "C" void func_00153080(S_00153080* self, int on) {
    F_00153080* f = self->unk14;
    if (f) {
        if (!on) {
            f->unk4 = f->unk4 & 0xFF7F;
        } else {
            u16 v = f->unk4;
            if (!(v & 0x80)) {
                f->unk4 = v | 0x80;
                func_00240F58(self->unk14, v);
            }
        }
    }
}

extern "C" void func_001530D8(S_001530D8* self, int a1) {
    VE_001530D8* e = &self->unk18[3];
    e->unk4((char*)self + e->unk0, a1);
}

extern "C" int func_00153100(S_00153100* self, A_00153100* a) {
    if (self->unk14) return 0;
    self->unk14 = a;
    if (self->unk10) func_0015F488(self->unk10, a->unk8);
    return 1;
}

extern "C" int func_00153140(S_00153140* self) {
    return self->unk14;
}

extern "C" int func_00153148(S_00153148* self) {
    return self->unk4;
}

extern "C" void func_00153150(S_00153150* self) {
    if (self->unk10) func_0015F720(self->unk10);
}

extern "C" void func_00153178(S_00153150* self) {
    if (self->unk10) func_0015F748(self->unk10);
}

extern "C" void func_001531A0(S_00153150* self) {
    if (self->unk10) func_0015F770(self->unk10);
}

extern "C" void func_001531C8(S_00153150* self) {
    if (self->unk10) func_0015F798(self->unk10);
}

extern "C" void func_001531F0(S_00153150* self) {
    if (self->unk10) func_0015F848(self->unk10);
}

extern "C" void func_00153218(S_00153150* self) {
    if (self->unk10) func_0015F870(self->unk10);
}

extern "C" void func_00153240(S_00153150* self) {
    if (self->unk10) func_0015F898(self->unk10);
}

extern "C" void func_00153268(S_00153268* self, int v) {
    self->unk4 |= v;
}

extern "C" void func_00153278(S_00153268* self, int v) {
    self->unk4 &= ~v;
}

INCLUDE_ASM("asm/nonmatchings/game/t_152E18", func_00153290);

extern "C" void func_001533F0(void) {
}

extern "C" void func_001533F8(void) {
}

extern "C" int func_00153400(void) {
    return 0;
}

INCLUDE_ASM("asm/nonmatchings/game/t_152E18", func_00153408);

GP_DATA(D_00369B88);
extern "C" void func_00153430(S_00153430* self, int flag) {
    self->unk8 = D_0033C840;
    if (D_00369B88 == self) D_00369B88 = 0;
    if (flag & 1) Heap_Free(D_00368A38, self);
}

extern "C" void func_00153478(S_00153268* self) {
    self->unk4++;
}

extern "C" void func_00153488(S_00153268* self) {
    self->unk4--;
}

extern "C" int func_00153498(S_00153498* self, int a1, int a2, int a3) {
    VE_00153498* e = &self->unk8[3];
    return e->unk4((char*)self + e->unk0, a1, a2, a3);
}

extern "C" void func_001534C0(S_001534C0* self, int a1, int a2) {
    VE_001534C0* e = &self->unk8[4];
    e->unk4((char*)self + e->unk0, a1, a2);
}

extern "C" void func_001534E8(S_001534E8* self, int a1) {
    VE_001534E8* e = &self->unk8[5];
    e->unk4((char*)self + e->unk0, a1);
}

extern "C" void func_00153510(S_00153510* self, int a) {
    if (a) {
        if ((S_00153510*)D_00369B88 != self) {
            if (D_00369B88) func_00153488((S_00153268*)D_00369B88);
            D_00369B88 = self;
            if (self) func_00153478((S_00153268*)self);
        }
    }
    VE_00153510* e = &self->unk8[6];
    e->unk4((char*)self + e->unk0, a);
}

extern "C" void func_00153588(S_00153588* self) {
    VE_Cv* e = &self->unk8[7];
    e->unk4((char*)self + e->unk0);
    self->unk0 = 0;
}

extern "C" void func_001535C0(S_001535C0* self, int a1, int a2, int a3, int a4) {
    VE_001535C0* e = &self->unk8[10];
    e->unk4((char*)self + e->unk0, a1, a2, a3, a4);
}

INCLUDE_ASM("asm/nonmatchings/game/t_152E18", func_001535E8);

extern "C" int func_00153760(void) {
    return 0;
}

extern "C" int func_00153768(void) {
    return 0;
}

extern "C" void func_00153770(void) {
}

extern "C" void func_00153778(void) {
}

extern "C" void func_00153780(void) {
}

extern "C" void func_00153788(void) {
}

extern "C" int func_00153790(void) {
    return 0;
}

extern "C" int func_00153798(void) {
    return 0;
}

extern "C" void func_001537A0(void) {
}

extern "C" void func_001537A8(void) {
}

extern "C" float func_001537B0(void) {
    return 0.0f;
}

extern "C" S_001537C0* func_001537C0(S_001537C0* self) {
    self->unk0 = 0;
    self->unk2 = 0;
    self->unk4 = 0x4000;
    self->unk6 = 0x4000;
    self->unk8 = 0;
    return self;
}

extern "C" void func_001537E0(S_001537C0* self, int flags) {
    if (flags & 1) {
        Heap_Free(D_00368A38, self);
    }
}

extern "C" S_00153810* func_00153810(S_00153810* self, int a) {
    self->unk5C = D_0033C800;
    self->unk0 = 0;
    self->unk4 = 0;
    self->unkC = 0;
    self->unk10 = 0;
    self->unk14 = 0;
    self->unk18 = 0;
    self->unk1C = 1.0f;
    self->unk20 = 1.0f;
    self->unk24 = 0;
    self->unk28 = 0;
    u8* c = self->unk34;
    c[0] = 0x80;
    c[1] = 0x80;
    c[2] = 0x80;
    c[3] = 0x80;
    self->unk38 = 0x54628ED7;
    self->unk4C = 1;
    self->unk54 = a;
    self->unk3C = 0;
    self->unk40 = 0;
    self->unk50 = 0;
    self->unk58 = 0;
    self->unk8 = 0;
    return self;
}

struct E_00153898 { char pad0[0xA]; };

struct S_00153898 { char pad0[4]; E_00153898* unk4; void* unk8; char padC[0x50]; void* unk5C; };

extern "C" void func_00153898(S_00153898* self, int flags) {
    self->unk5C = D_0033C800;
    if (self->unk8) Heap_Free(D_00368A38, self->unk8);
    E_00153898* a = self->unk4;
    if (a) {
        E_00153898* e = (E_00153898*)((char*)a + ((int*)a)[-4] * 10);
        if (a != e) {
            do {
                e--;
                func_001537E0((S_001537C0*)e, 0);
            } while (self->unk4 != e);
        }
        Heap_Free(D_00368A38, (char*)self->unk4 - 0x10);
        self->unk4 = 0;
    }
    if (flags & 1) Heap_Free(D_00368A38, self);
}

INCLUDE_ASM("asm/nonmatchings/game/t_152E18", func_00153958);

struct VE_00153C28 { char pad0[0x20]; s16 unk20; s16 unk22; void (*unk24)(void*); };
struct S_00153C28 { char pad0[4]; char* unk4; char pad8[0x54]; VE_00153C28* unk5C; };
extern "C" void func_00153AB0(S_00153C28* self, int idx, float f, float g) {
    if (self->unk4 == 0) {
        int n = 0x5F;
        func_00119490(D_00368A38, *(int*)(D_00368A38 + 0x1E8));
        int* h = (int*)Heap_Alloc(D_00368A38, 0x3D0, 1, 0);
        char* base = (char*)(h + 4);
        *h = 0x60;
        char* p = base;
        do {
            n -= 0xC;
            func_001537C0((S_001537C0*)p);
            func_001537C0((S_001537C0*)(p + 0xA));
            func_001537C0((S_001537C0*)(p + 0x14));
            func_001537C0((S_001537C0*)(p + 0x1E));
            func_001537C0((S_001537C0*)(p + 0x28));
            func_001537C0((S_001537C0*)(p + 0x32));
            func_001537C0((S_001537C0*)(p + 0x3C));
            func_001537C0((S_001537C0*)(p + 0x46));
            func_001537C0((S_001537C0*)(p + 0x50));
            func_001537C0((S_001537C0*)(p + 0x5A));
            func_001537C0((S_001537C0*)(p + 0x64));
            func_001537C0((S_001537C0*)(p + 0x6E));
            p += 0x78;
        } while (n != -1);
        self->unk4 = base;
        func_001194B8(D_00368A38);
    }
    *(s16*)(self->unk4 + idx * 10 + 4) = (s16)(f * 16384.0f);
    *(s16*)(self->unk4 + idx * 10 + 6) = (s16)(g * 16384.0f);
    VE_00153C28* e = self->unk5C;
    e->unk24((char*)self + e->unk20);
}

extern "C" void func_00153C28(S_00153C28* self, int idx, float f) {
    if (self->unk4 == 0) {
        int n = 0x5F;
        func_00119490(D_00368A38, *(int*)(D_00368A38 + 0x1E8));
        int* h = (int*)Heap_Alloc(D_00368A38, 0x3D0, 1, 0);
        char* base = (char*)(h + 4);
        *h = 0x60;
        char* p = base;
        do {
            n -= 0xC;
            func_001537C0((S_001537C0*)p);
            func_001537C0((S_001537C0*)(p + 0xA));
            func_001537C0((S_001537C0*)(p + 0x14));
            func_001537C0((S_001537C0*)(p + 0x1E));
            func_001537C0((S_001537C0*)(p + 0x28));
            func_001537C0((S_001537C0*)(p + 0x32));
            func_001537C0((S_001537C0*)(p + 0x3C));
            func_001537C0((S_001537C0*)(p + 0x46));
            func_001537C0((S_001537C0*)(p + 0x50));
            func_001537C0((S_001537C0*)(p + 0x5A));
            func_001537C0((S_001537C0*)(p + 0x64));
            func_001537C0((S_001537C0*)(p + 0x6E));
            p += 0x78;
        } while (n != -1);
        self->unk4 = base;
        func_001194B8(D_00368A38);
    }
    *(s16*)(self->unk4 + idx * 10 + 8) = (s16)(f * 16384.0f);
    VE_00153C28* e = self->unk5C;
    e->unk24((char*)self + e->unk20);
}

extern "C" void func_00153D80(S_00153D80* self, int v) {
    self->unk4C = v;
    VE_5C* e = &self->unk5C[3];
    e->unk4((char*)self + e->unk0);
}

extern "C" void func_00153DB0(S_00153D80* self, int v) {
    self->unk0 = v;
    VE_5C* e = &self->unk5C[4];
    e->unk4((char*)self + e->unk0);
}

extern "C" int func_00153DE0(S_00153DE0* self, void* s) {
    if (self->unk8 == 0) {
        func_00119490(D_00368A38, ((H_152*)D_00368A38)->unk1E8);
        self->unk8 = Heap_Alloc(D_00368A38, 0x60, 1, 0);
        func_001194B8(D_00368A38);
    }
    func_0030ADA0(self->unk8, s, 0x5F);
    VE_C* e = &self->unk5C[4];
    return e->unk4((char*)self + e->unk0);
}

extern "C" void func_00153E70(void* p) {
    S_00153E70* self = (S_00153E70*)p;
    if (self->unk8) {
        Heap_Free(D_00368A38, self->unk8);
        self->unk8 = 0;
    }
    if (self->unk4) {
        S_001537C0* e = self->unk4 + ((int*)self->unk4)[-4];
        while (self->unk4 != e) {
            --e;
            func_001537E0(e, 0);
        }
        Heap_Free(D_00368A38, (char*)self->unk4 - 0x10);
        self->unk4 = 0;
    }
}

extern "C" void func_00153F08(S_00153F08* self, float a, float b) {
    self->unkC = a;
    self->unk10 = b;
    VE_5C* e = &self->unk5C[4];
    e->unk4((char*)self + e->unk0);
}

extern "C" void func_00153F38(S_00153F08* self, float a, float b) {
    self->unk14 = a;
    self->unk18 = b;
    VE_5C* e = &self->unk5C[4];
    e->unk4((char*)self + e->unk0);
}

extern "C" void func_00153F68(S_00153F08* self, float a, float b) {
    self->unk1C = a;
    self->unk20 = b;
    VE_5C* e = &self->unk5C[4];
    e->unk4((char*)self + e->unk0);
}

extern "C" void func_00153F98(S_00153D80* self, float v) {
    self->unk24 = v;
    VE_5C* e = &self->unk5C[4];
    e->unk4((char*)self + e->unk0);
}

extern "C" void func_00153FC8(S_00153F08* self, float a) {
    self->unk28 = a;
    self->unk50 = 0;
    VE_5C* e = &self->unk5C[5];
    e->unk4((char*)self + e->unk0);
}

extern "C" void func_00153FF8(S_00153F08* self, int a) {
    self->unk30 = a;
    self->unk50 = 1;
    VE_5C* e = &self->unk5C[5];
    e->unk4((char*)self + e->unk0);
}

INCLUDE_ASM("asm/nonmatchings/game/t_152E18", func_00154030);

extern "C" void func_00154078(S_00153D80* self, int v) {
    self->unk38 = v;
    VE_5C* e = &self->unk5C[4];
    e->unk4((char*)self + e->unk0);
}

extern "C" void func_001540A8(S_00153D80* self, int v) {
    self->unk40 = v;
    VE_5C* e = &self->unk5C[4];
    e->unk4((char*)self + e->unk0);
}

extern "C" void func_001540D8(S_00153F08* self, int a, int b) {
    self->unk48 = b;
    self->unk44 = a;
    VE_5C* e = &self->unk5C[4];
    e->unk4((char*)self + e->unk0);
}

extern "C" void func_00154108(S_00153D80* self, int v) {
    self->unk54 = v;
    VE_5C* e = &self->unk5C[6];
    e->unk4((char*)self + e->unk0);
}

extern "C" void func_00154138(void) {
}

extern "C" void func_00154140(void) {
}

extern "C" void func_00154148(void) {
}

extern "C" void func_00154150(void) {
}

extern "C" void func_00154158(void) {
}

extern "C" void func_00154160(void) {
    func_00189540();
}

GP_DATA(D_00369B8C);
extern "C" S_00154180* func_00154180(void) {
    S_00154180* p = D_00369B8C;
    if (p) D_00369B8C = p->unk58;
    return p;
}

extern "C" void func_001541A0(S_00154180* self) {
    func_00153D80((S_00153D80*)self, 1);
    func_00153E70(self);
    self->unk58 = D_00369B8C;
    D_00369B8C = self;
}

INCLUDE_ASM("asm/nonmatchings/game/t_152E18", CFunc_LightShow_UpdateLightingTweaks);

typedef unsigned int u128_154380 __attribute__((mode(TI)));
struct O_154380 { char pad0[0x40]; f32 unk40; char pad44[0xC]; u128_154380 unk50; };
struct S_154380 { f32 unk0; O_154380* unk4; };
extern "C" {
f32 func_0010F698(void*);
f32 func_0010F6A8(void*);
f32 func_0010F6C0(void*);
void func_00127818(void*, f32);
void func_00127820(void*, f32);
void func_00127828(void*, f32);
f32 func_00156AB0(void*);
}

extern "C" void func_00154380(S_154380* self, f32 scale) {
    u128_154380 v = self->unk4->unk50;
    func_00127818(&v, func_0010F698(&v) * 0.0078125f);
    func_00127820(&v, func_0010F6A8(&v) * 0.0078125f);
    func_00127828(&v, func_0010F6C0(&v) * 0.0078125f);
    f32 t = self->unk4->unk40;
    t = t * func_00156AB0(&v);
    self->unk0 = t * scale;
}

extern "C" S_00154420* func_00154420(S_00154420* self) {
    self->unk0 = 0;
    return self;
}

extern "C" void* func_00154430(void* p, void* a) {
    S_00154430* self = (S_00154430*)p;
    N_00154430* n = (N_00154430*)Heap_Alloc(D_00368A38, 0x10, 1, 0);
    n->unk4 = a;
    n->unk8 = 0;
    n->unkC = self->unk0;
    if (self->unk0) {
        self->unk0->unk8 = n;
    }
    self->unk0 = n;
    func_00154540_f(self, n, 1.0f);
    return n;
}

extern "C" void func_001544B8(void* l, void* p) {
    S_001544B8* list = (S_001544B8*)l;
    N_001544B8* n = (N_001544B8*)p;
    if (list->unk0 == n) list->unk0 = n->unkC;
    if (n->unk8) n->unk8->unkC = n->unkC;
    if (n->unkC) n->unkC->unk8 = n->unk8;
    Heap_Free(D_00368A38, n);
}

extern "C" void func_00154510(S_00154510* list, N_00154510* prev, N_00154510* b, N_00154510* a, N_00154510* next) {
    if (prev) prev->unkC = a; else list->unk0 = a;
    b->unk8 = a;
    b->unkC = next;
    a->unk8 = prev;
    a->unkC = b;
    if (next) next->unk8 = b;
}

INCLUDE_ASM("asm/nonmatchings/game/t_152E18", func_00154540);

extern "C" void func_00154608(S_00154608* self) {
    self->unk84 = func_00154430(D_00372B60, self);
}

extern "C" void func_00154640(S_00154640* self) {
    if (self->unk84) func_00154540(D_00372B60, self->unk84);
}

extern "C" S_00154670* func_00154670(S_00154670* self) {
    self->unk88 = D_0033C9C0;
    self->unk60 = 0;
    self->unk64 = 0;
    self->unk68 = 0;
    self->unkC = 0;
    self->unk38 = 0;
    self->unk40 = 0;
    float* p = self->unk50;
    p[0] = 128.0f;
    p[1] = 128.0f;
    p[2] = 128.0f;
    self->unk84 = 0;
    return self;
}

extern "C" void func_001546B8(S_00154608* self, int flag) {
    self->unk88 = D_0033C9C0;
    func_00154708(self);
    if (flag & 1) Heap_Free(D_00368A38, self);
}

extern "C" void func_00154708(S_00154608* self) {
    if (self->unk84) {
        func_001544B8(D_00372B60, self->unk84);
        self->unk84 = 0;
    }
    func_00154750(self);
    self->unk60 = 0;
}

extern "C" void func_00154750(void* p) {
    S_001547C8* self = (S_001547C8*)p;
    int i;
    for (i = 0; i < self->unk68; i++) {
        func_00156790(self->unk6C[i])->unkA4--;
    }
    self->unk68 = 0;
}

extern "C" void func_001547C8(S_001547C8* self, void* x) {
    if (func_00154830(self, x)) return;
    func_00156790(x)->unkA4++;
    self->unk6C[self->unk68] = x;
    self->unk68++;
}

INCLUDE_ASM("asm/nonmatchings/game/t_152E18", func_00154830);

extern "C" void func_001548F8(void) {
}

INCLUDE_ASM("asm/nonmatchings/game/t_152E18", func_00154900);

INCLUDE_ASM("asm/nonmatchings/game/t_152E18", func_001549B0);
