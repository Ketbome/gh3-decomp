// cflags: -funroll-loops
#include "common.h"

struct S12F_H {
    char pad0[0x34];
    virtual void v1();
    virtual int v2();
};

struct S12F_HP { S12F_H* unk0; };

struct S12F_G {
    char pad0[0x8];
    int unk8;
    char padC[0x21C];
    S12F_HP unk228;
};

struct S12F_Pool {
    u32 unk0;
    u32 unk4;
    int Has(u32 p) { return !(p < unk0) && p < unk4; }
};

typedef unsigned int u128_12F __attribute__((mode(TI)));

struct S12F_Q { u128_12F unk0[0x120]; };

struct S12F_V { u128_12F unk0; u128_12F unk10; char pad20[0x60]; };

struct S12F_W { char pad0[0x40]; S12F_V unk40[4]; };

struct S12F_C { char pad0[0x20]; S12F_Q unk20; };

struct S12F_U { char pad0[0x24]; int unk24; char pad28[0x58]; };

struct S12F_T { char pad0[0x4]; int unk4; char pad8[0x8]; int* unk10; int* unk14; };

struct S12F_P { char pad0[0x4]; S12F_T* unk4; char pad8[0x20]; int unk28; };

struct S12F_D { int unk0; void* unk4; int unk8; char padC[0x14]; };

struct S12F_E {
    char pad0[0x4];
    void* unk4;
    int unk8;
    char padC[0x8];
    void* unk14;
    char pad18[0x20C];
    S12F_D* unk224;
    char unk228[0x8];
};

struct S12F_R { char pad0[0x1C]; int unk1C; };

struct VE_00130600 { s16 unk0; s16 unk2; void (*unk4)(void*, int); };
struct S_00130600 { char pad0[0x14]; VE_00130600* unk14; };

extern "C" {
int func_002763E0(u32, int);
int func_0027D400(int, int, int*, int);
int func_001287F0(int, int);
int func_0027AA70(int);
void func_0027ABB0(int, int);
void func_0027C898(int, u32, int);
void func_001CF000(int, int);
void func_0027AC90(int);
void func_00113250(int);
void func_001342E8(S12F_HP*, S12F_H*);
void func_00134340(S12F_HP*);
void func_00131338(S12F_G*, int);
void func_00131970(S12F_G*, int);
void func_001318D0(S12F_G*, int);
void func_00132390(S12F_G*);
extern int D_003692B0;
extern S12F_Pool* D_003692A0[2];
void func_0011C2E8(S12F_Pool*, void*);
int func_00134128(S12F_P*, int);
void func_0012E628(void*, int);
void func_0012E668(void*, void*);
void func_001309A8(void*, int, int, void*);
void func_0027ACF8(int, u32);
S12F_R* func_001D1CF8(int, u32);
extern u8 D_0033A1F8[];
extern int D_00368A38;
void Heap_Free(int, void*);
void func_00131018(void);
}

struct E_00130CA8 { char pad0[0x50]; int unk50; char pad1[0x2C]; };
struct S_00130CA8 { char pad0[0x40]; E_00130CA8 unk40[1]; };

extern "C" void func_0012F9A0(void) {
}
TEXT_PAD(8);

extern "C" int func_0012F9B0(S12F_C* self, S12F_Q* dst) {
    *dst = self->unk20;
    return 1;
}

INCLUDE_ASM("asm/nonmatchings/game/t_12F9A0", func_0012F9E0);

GP_DATA(D_003692B0);
GP_DATA(D_003692A0);
extern "C" void func_0012F9E8(void* p) {
    S12F_Pool* pool = D_003692A0[D_003692B0];
    if ((pool && pool->Has((u32)p)) || ((pool = D_003692A0[D_003692B0 ^ 1]) && pool->Has((u32)p))) {
        func_0011C2E8(pool, p);
    } else if (p) {
        Heap_Free(D_00368A38, p);
    }
}

extern "C" void func_0012FA98(void* self, S12F_P* p) {
    if (p->unk28) {
        func_0027ACF8(p->unk28, 0x5DB4115F);
    }
}

extern "C" void func_0012FAC8(int u, int a, int b) {
    int loc;
    if (func_0027D400(func_002763E0(0x95807202, 1), a, &loc, 0)) {
        int t16 = func_0027AA70(func_001287F0(8, 1));
        int t17 = func_0027AA70(func_001287F0(8, 1));
        if (loc) func_0027ABB0(t17, loc);
        func_0027C898(t16, 0x5DB4115F, t17);
        func_001CF000(b, t16);
        if (t16) {
            func_0027AC90(t16);
            func_00113250(t16);
        }
    }
}

INCLUDE_ASM("asm/nonmatchings/game/t_12F9A0", func_0012FBA0);

extern "C" void func_0012FD20(S12F_E* self, int flags) {
    self->unk14 = D_0033A1F8;
    func_0012E628(self, flags);
}

extern "C" int func_0012FD48(S12F_E* self) {
    S12F_R* r = func_001D1CF8(self->unk8, 0x222756D5);
    if (r) {
        return r->unk1C;
    }
    return 0;
}

INCLUDE_ASM("asm/nonmatchings/game/t_12F9A0", func_0012FD78);

extern "C" void func_001305B8(void* self, void* params) {
    func_0012E668(self, params);
    func_001309A8(self, 0, 0, params);
}

extern "C" void func_00130600(S_00130600* self, int a1) {
    VE_00130600* e = &self->unk14[5];
    e->unk4((char*)self + e->unk0, a1);
}

INCLUDE_ASM("asm/nonmatchings/game/t_12F9A0", func_00130628);

INCLUDE_ASM("asm/nonmatchings/game/t_12F9A0", func_001306E0);

INCLUDE_ASM("asm/nonmatchings/game/t_12F9A0", func_001309A8);

extern "C" int func_00130C58(S12F_U* self, int v) {
    int i;
    for (i = 0; i < 4; i++) {
        if (self[i].unk24 == v) {
            return i;
        }
    }
    return -1;
}

extern "C" void func_00130CA8(S_00130CA8* self, int i) {
    self->unk40[i].unk50 = 1;
}

extern "C" void func_00130CC0(S_00130CA8* self, int i) {
    self->unk40[i].unk50 = 0;
}

extern "C" int func_00130CD0(S_00130CA8* self, int i) {
    return self->unk40[i].unk50;
}

extern "C" void func_00130CE0(S12F_W* self, u128_12F* v, int i) {
    *(u128_12F*)(i * 0x80 + (char*)self + 0x40) = *v;
}

extern "C" void func_00130CF8(S12F_W* self, u128_12F* v, int i) {
    *(u128_12F*)(i * 0x80 + (char*)self + 0x50) = *v;
}

extern "C" int func_00130D10(S12F_U* self) {
    int i;
    for (i = 0; i < 4; i++) {
        if ((u32)self[i].unk24 != 0xFFFFFFFF && !func_00130CD0((S_00130CA8*)self, i)) {
            return 0;
        }
    }
    return 1;
}

extern "C" void func_00130DC8(S12F_U* self) {
    int i;
    for (i = 0; i < 4; i++) {
        if ((u32)self[i].unk24 != 0xFFFFFFFF) {
            func_00130CA8((S_00130CA8*)self, i);
        }
    }
}

extern "C" void func_00130E50(S12F_U* self) {
    int i;
    for (i = 0; i < 4; i++) {
        if ((u32)self[i].unk24 != 0xFFFFFFFF) {
            func_00130CC0((S_00130CA8*)self, i);
        }
    }
}

extern "C" void func_00130ED8(S12F_U* self, u128_12F* v) {
    int i;
    for (i = 0; i < 4; i++) {
        if ((u32)self[i].unk24 != 0xFFFFFFFF) {
            func_00130CE0((S12F_W*)self, v, i);
        }
    }
}

extern "C" void func_00130F70(S12F_U* self, u128_12F* v) {
    int i;
    for (i = 0; i < 4; i++) {
        if ((u32)self[i].unk24 != 0xFFFFFFFF) {
            func_00130CF8((S12F_W*)self, v, i);
        }
    }
}

INCLUDE_ASM("asm/nonmatchings/game/t_12F9A0", func_00131008);

INCLUDE_ASM("asm/nonmatchings/game/t_12F9A0", func_00131018);

INCLUDE_ASM("asm/nonmatchings/game/t_12F9A0", func_001310E8);

INCLUDE_ASM("asm/nonmatchings/game/t_12F9A0", func_00131118);

INCLUDE_ASM("asm/nonmatchings/game/t_12F9A0", func_00131338);

INCLUDE_ASM("asm/nonmatchings/game/t_12F9A0", func_001313E8);

INCLUDE_ASM("asm/nonmatchings/game/t_12F9A0", func_001315F8);

extern "C" void func_001316B8(S12F_E* self, int flags) {
    if (self->unk224) {
        Heap_Free(D_00368A38, self->unk224);
    }
    if (self->unk4) {
        Heap_Free(D_00368A38, self->unk4);
    }
    func_00134340((S12F_HP*)self->unk228);
    if (flags & 1) {
        Heap_Free(D_00368A38, self);
    }
}

extern "C" void func_00131728(S12F_G* self, S12F_HP* h) {
    S12F_HP* hp = &self->unk228;
    if (h->unk0 != hp->unk0) {
        S12F_H* p;
        func_001342E8(hp, h->unk0);
        p = self->unk228.unk0;
        func_00131338(self, self->unk8 = p ? p->v2() : 0);
        func_00131970(self, self->unk8);
        func_001318D0(self, self->unk8);
        func_00132390(self);
    }
    func_00134340(h);
}

INCLUDE_ASM("asm/nonmatchings/game/t_12F9A0", func_001317D0);

extern "C" void func_001318B0(void) {
    func_00131018();
}

INCLUDE_ASM("asm/nonmatchings/game/t_12F9A0", func_001318D0);

struct X_00131970 { char pad0[4]; int unk4; char pad8[8]; int* unk10; };
struct B_00131970 { char pad0[4]; X_00131970* unk4; };
struct E_00131970 { int unk0; char pad4[0x1C]; };
struct S_00131970 { char pad0[0x224]; E_00131970* unk224; };

extern "C" void func_00131970(S12F_G* arg, int barg) {
    S_00131970* self = (S_00131970*)arg;
    B_00131970* b = (B_00131970*)barg;
    int i;
    for (i = 0; i < (*(X_00131970* volatile*)&b->unk4)->unk4; i++) {
        self->unk224[i].unk0 = b->unk4->unk10[i];
    }
}
