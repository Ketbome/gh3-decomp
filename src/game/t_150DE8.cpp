#include "common.h"

struct VE_00151988 { s16 unk0; s16 unk2; void (*unk4)(void*, int); };
struct S_00151988 { char pad0[0x90]; VE_00151988* unk90; };

struct S_00152610 { u8 unk0; u8 unk1; u8 unk2; u8 unk3; };

struct S_00152638 { int unk0; int unk4; int unk8; };

struct E_001510D8 { char pad0[0x18]; };
struct S_001510D8 { char pad0[0x68]; E_001510D8* unk68; };

struct S_001510D0 { char pad0[0x64]; int unk64; };
struct S_00152C50 { int unk0; };
struct S_00152C58 { int unk0; };
struct S_00152C60 { char pad0[0x10]; int unk10; };
struct S_00152C68 { char pad0[0x10]; int unk10; };

struct VE_150 { s16 delta; s16 unk2; void* fn; };
struct S150_A { char pad0[0xC]; u32 unkC; };
struct S150_R { char pad0[0x10]; int unk10; int unk14; };
struct S150_B { char pad0[0x90]; VE_150* unk90; };
struct S150_L {
    char pad0[0xC];
    S150_L* unkC;
    S150_L* unk10;
    void* unk14;
};
struct S150_O { char pad0[0xC]; VE_150* unkC; };
struct S150_F { char pad0[0x4]; u16 unk4; };
struct S150_C {
    char pad0[0x4];
    int unk4;
    int unk8;
    int unkC;
    void* unk10;
    void* unk14;
    VE_150* unk18;
};
struct S150_D { char pad0[0x18]; VE_150* unk18; };
struct S150_E { char pad0[0x10]; S150_D* unk10; };

extern "C" void Heap_Free(int, void*);
extern "C" int D_00368A38;

inline void operator delete[](void* p) {
    Heap_Free(D_00368A38, p);
}

inline void operator delete(void* p) {
    Heap_Free(D_00368A38, p);
}

struct S150_VB { char pad0[0xC]; virtual ~S150_VB(); };
struct S150_V : S150_VB { char pad10[0x8]; };
struct S150_V2 { char pad0[0x18]; virtual ~S150_V2(); };
struct S150_G {
    char pad0[0xC];
    u32 unkC;
    char pad10[0x4C];
    void* unk5C;
    void* unk60;
    int unk64;
    S150_V* unk68;
};
struct HI_150 { u32 key; void* value; HI_150* next; };
struct HT_150 { int bits; HI_150* items; int count; char padC[9]; u8 unk15; u8 unk16; };

extern "C" {
void func_00151120(S150_A*);
extern u8 D_0033C528[];
extern u8 D_0033C4F8[];
extern u8 D_0033C6B8[];
extern int D_00372B58;
void func_00152C78(S150_C*, int);
void func_0015F4B8(void*, int);
void func_0015F2A8(void*);
int func_0015F2D0(void*);
void func_0015F2F8(void*, int);
int func_0015F320(void*);
int func_0015F348(void*);
void func_00246F48(void*, int);
void func_0011D220(void*);
void func_0011C408(int, void*);
void func_00152850(HT_150*);
}

extern "C" int func_00150DE8(S150_G* self) {
    if (self->unk5C) {
        func_00246F48(self->unk5C, 3);
        self->unk5C = 0;
    }
    if (self->unk68) {
        delete[] self->unk68;
        self->unk68 = 0;
        self->unk64 = 0;
    }
    if (self->unk60) {
        func_0011D220(self->unk60);
        self->unk60 = 0;
    }
    self->unkC |= 4;
    return 1;
}

INCLUDE_ASM("asm/nonmatchings/game/t_150DE8", func_00150EB8);

INCLUDE_ASM("asm/nonmatchings/game/t_150DE8", func_001510C8);

extern "C" int func_001510D0(S_001510D0* self) {
    return self->unk64;
}

extern "C" E_001510D8* func_001510D8(S_001510D8* self, int i) {
    return &self->unk68[i];
}

extern "C" int func_001510F0(S150_A* self) {
    if (self->unkC & 8) {
        func_00151120(self);
        return 1;
    }
    return 0;
}

INCLUDE_ASM("asm/nonmatchings/game/t_150DE8", func_00151120);

INCLUDE_ASM("asm/nonmatchings/game/t_150DE8", func_00151940);

extern "C" S150_R* func_00151950(S150_B* self) {
    VE_150* e = &self->unk90[8];
    S150_R* r = ((S150_R* (*)(void*))e->fn)((char*)self + e->delta);
    r->unk10 = 0;
    r->unk14 = 0;
    return r;
}

extern "C" void func_00151988(S_00151988* self, int a1) {
    VE_00151988* e = &self->unk90[11];
    e->unk4((char*)self + e->unk0, a1);
}

extern "C" void func_001519B0(void) {
}

INCLUDE_ASM("asm/nonmatchings/game/t_150DE8", func_001519B8);

INCLUDE_ASM("asm/nonmatchings/game/t_150DE8", func_00152540);

extern "C" void func_001525C8(void) {
}

extern "C" void func_001525D0(void) {
}

extern "C" void func_001525D8(void) {
}

extern "C" int func_001525E0(void) {
    return 0;
}

extern "C" int func_001525E8(void) {
    return 0;
}

extern "C" int func_001525F0(void) {
    return 0;
}

extern "C" int func_001525F8(void) {
    return 0;
}

extern "C" int func_00152600(void) {
    return 0;
}

extern "C" void func_00152608(void) {
}

extern "C" S_00152610* func_00152610(S_00152610* self) {
    self->unk0 = 0x80;
    self->unk1 = 0x80;
    self->unk2 = 0x80;
    self->unk3 = 0x80;
    return self;
}

INCLUDE_ASM("asm/nonmatchings/game/t_150DE8", func_00152630);

extern "C" void func_00152638(S_00152638* self) {
    self->unk0 = 0;
    self->unk4 = 0;
    self->unk8 = 0;
}

extern "C" S_00152638* func_00152648(S_00152638* self) {
    func_00152638(self);
    return self;
}

INCLUDE_ASM("asm/nonmatchings/game/t_150DE8", func_00152670);

extern "C" void func_00152850(HT_150* t) {
    if (t->items) {
        u32 n = 1 << t->bits;
        HI_150* e = t->items;
        for (u32 i = 0; i < n; i++) {
            HI_150* c = e->next;
            while (c) {
                HI_150* nx = c->next;
                func_0011C408(0, c);
                c = nx;
            }
            func_00152638((S_00152638*)e);
            e++;
        }
        t->count = 0;
    }
}

extern "C" void func_00152908(HT_150* self, int flags) {
    if (!self->unk16 && self->items) {
        func_00152850(self);
        if (self->items) {
            Heap_Free(D_00368A38, self->items);
        }
        self->items = 0;
    }
    if (flags & 1) {
        Heap_Free(D_00368A38, self);
    }
}
TEXT_PAD(20);

extern "C" void func_00152990(S150_L* self, int flags) {
    self->unk14 = D_0033C528;
    self->unk10->unkC = self->unkC;
    self->unkC->unk10 = self->unk10;
    self->unkC = self;
    self->unk10 = self;
    if (flags & 1) {
        Heap_Free(D_00368A38, self);
    }
}

extern "C" void func_001529F0(S150_L* self, int flags) {
    self->unk14 = D_0033C528;
    self->unk10->unkC = self->unkC;
    self->unkC->unk10 = self->unk10;
    self->unkC = self;
    self->unk10 = self;
    if (flags & 1) {
        Heap_Free(D_00368A38, self);
    }
}

extern "C" void func_00152A50(S150_L* self, int flags) {
    self->unk14 = D_0033C4F8;
    self->unk10->unkC = self->unkC;
    self->unkC->unk10 = self->unk10;
    self->unkC = self;
    self->unk10 = self;
    if (flags & 1) {
        Heap_Free(D_00368A38, self);
    }
}

extern "C" void func_00152AB0(S150_L* self, int flags) {
    self->unk14 = D_0033C4F8;
    self->unk10->unkC = self->unkC;
    self->unkC->unk10 = self->unk10;
    self->unkC = self;
    self->unk10 = self;
    if (flags & 1) {
        Heap_Free(D_00368A38, self);
    }
}

INCLUDE_ASM("asm/nonmatchings/game/t_150DE8", func_00152B10);

INCLUDE_ASM("asm/nonmatchings/game/t_150DE8", func_00152B38);

extern "C" void func_00152B88(S150_C* self, int flags) {
    self->unk18 = (VE_150*)D_0033C6B8;
    if (self->unk14 && (self->unk4 & 2)) {
        delete (S150_V*)self->unk14;
    }
    if (self->unk10) {
        delete (S150_V2*)self->unk10;
    }
    if (flags & 1) {
        Heap_Free(D_00368A38, self);
    }
}

extern "C" void func_00152C20(S150_E* self) {
    S150_D* o = self->unk10;
    VE_150* e = &o->unk18[2];
    ((void (*)(void*))e->fn)((char*)o + e->delta);
}

extern "C" int func_00152C50(S_00152C50* self) {
    return self->unk0;
}

extern "C" void func_00152C58(S_00152C58* self, int v) {
    self->unk0 = v;
}

extern "C" int func_00152C60(S_00152C60* self) {
    return self->unk10;
}

extern "C" void func_00152C68(S_00152C68* self, int v) {
    self->unk10 = v;
}

INCLUDE_ASM("asm/nonmatchings/game/t_150DE8", func_00152C70);

extern "C" void func_00152C78(S150_C* self, int v) {
    if (v != self->unk8) {
        self->unk8 = v;
        VE_150* e = &self->unk18[4];
        ((void (*)(void*))e->fn)((char*)self + e->delta);
    }
    if (self->unk10) {
        func_0015F4B8(self->unk10, v);
    }
}

extern "C" void func_00152CE0(S150_C* self) {
    if (self->unk10) {
        func_0015F2A8(self->unk10);
    }
}

extern "C" int func_00152D08(S150_C* self) {
    if (self->unk10) {
        return func_0015F2D0(self->unk10);
    }
    return 0;
}

extern "C" void func_00152D30(S150_C* self, int b) {
    S150_F* f = (S150_F*)self->unk14;
    if (f) {
        if (b) {
            f->unk4 &= ~4;
        } else {
            f->unk4 |= 4;
        }
    }
    if (self->unk10) {
        func_0015F2F8(self->unk10, b);
    }
}

extern "C" int func_00152D80(S150_C* self) {
    if (self->unk10) {
        return func_0015F320(self->unk10);
    }
    return ((((S150_F*)self->unk14)->unk4 >> 2) ^ 1) & 1;
}

extern "C" int func_00152DC8(S150_C* self) {
    if (self->unk10) {
        return func_0015F348(self->unk10);
    }
    S150_O* o = (S150_O*)self->unk14;
    VE_150* e = &o->unkC[23];
    return ((int (*)(void*))e->fn)((char*)o + e->delta);
}
