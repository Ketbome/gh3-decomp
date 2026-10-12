#include "common.h"

struct S_14A { char pad0[0x8]; void* unk8; char padC[0x14]; u32 unk20; char pad24[0x22C]; int unk250; int unk254; void* unk258; char pad25C[0x2C]; int unk288; };
struct C24_14A { char b[0x18]; };
struct S2_14A { char pad0[0x500]; C24_14A unk500; };
struct S3_14A { char pad0[0x30]; char unk30[0x20]; float unk50; };

struct S4_14A { char pad0[0x20]; float unk20; };

struct S5_14A { int unk0; int unk4; int unk8; };
struct S6_14A { char pad0[0x500]; C24_14A unk500; C24_14A unk518; int unk530; int unk534; };
struct S7_14A { void* unk0; int unk4; int unk8; };
struct S8_14A { char pad0[0x2C]; int unk2C; };
struct S9_14A { char pad0[0x34]; void* unk34; };

struct HI_14A { u32 key; void* value; HI_14A* next; };
struct HT_14A { int bits; HI_14A* items; int count; char padC[9]; u8 unk15; };

extern "C" {
void func_0011C408(int, void*);
S5_14A* func_0014C390(u32);
void func_0014C4A8(void*, int*);
extern u8 D_00377FC0[];
int func_0011EF10(void);
void* func_00118F20(int, int, int, int);
void func_0030A49C(void*, int, int);
S9_14A* func_0015D2E8(int, int);
void func_00123040(void*);
void func_001CE888(void*, void*);
int func_0013B608(void*, u32);
void func_0015D408(int);
void func_001232E8(void*, int);
void func_00140A60(void*, int);
void func_0014AE10_p(void*) __asm__("func_0014AE10");
extern int D_00372B40;
extern int D_00368A38;
void func_00119400(int, void*);
extern u8 D_0033BAD8[];
extern u8 D_0033BB00[];
extern u8 D_0033BA38[];
extern u8 D_0033BA60[];
extern u8 D_0033BE38[];
void func_001498D0(void*);
void* func_00149820(void*);
void func_0014B368(void*);
void* func_00140A00(void*);
void func_00123200(void*);
void func_0014AC58(void*, int);
float func_0010EC98(void*, void*, void*, int);
void func_0011A380(void);
void func_0011A470(void);
void func_0014B168(int, int);
}

struct S_0014C470 { int unk0; int unk4; int unk8; };

struct S_0014ABF8 { char pad0[0x50]; };

extern "C" S_14A* func_0014A6B0(S_14A* self) {
    func_00149820(self);
    self->unk258 = D_0033BAD8;
    self->unk8 = D_0033BB00;
    self->unk288 = 1;
    return self;
}

extern "C" void func_0014A6F8(S_14A* self) {
    self->unk258 = D_0033BAD8;
    self->unk8 = D_0033BB00;
    func_001498D0(self);
}

extern "C" S_14A* func_0014A728(S_14A* self) {
    func_00149820(self);
    self->unk258 = D_0033BA38;
    self->unk8 = D_0033BA60;
    self->unk288 = 0;
    return self;
}

extern "C" void func_0014A770(S_14A* self) {
    self->unk258 = D_0033BA38;
    self->unk8 = D_0033BA60;
    func_001498D0(self);
}

INCLUDE_ASM("asm/nonmatchings/game/t_14A6B0", func_0014A7A0);

INCLUDE_ASM("asm/nonmatchings/game/t_14A6B0", func_0014A7A8);

extern "C" void func_0014A910(void* self, int flags) {
    if (flags & 1) {
        func_00119400(D_00368A38, self);
    }
}

INCLUDE_ASM("asm/nonmatchings/game/t_14A6B0", func_0014A940);

extern "C" S_0014ABF8* func_0014ABF8(S_0014ABF8* p, int i) {
    return &p[i];
}

extern "C" void func_0014AC08(S2_14A* self, C24_14A* p, int x) {
    self->unk500 = *p;
    func_0014AC58(self, x);
}

extern "C" void func_0014AC58(void* p, int v) {
    S6_14A* self = (S6_14A*)p;
    if (!v) {
        self->unk518 = self->unk500;
    }
    self->unk534 = v;
    self->unk530 = func_0011EF10();
}

INCLUDE_ASM("asm/nonmatchings/game/t_14A6B0", func_0014ACB8);

extern "C" void func_0014ADF0(void) {
    func_0011A380();
}

extern "C" void func_0014AE10(void) {
    func_0011A470();
}

extern "C" S_14A* func_0014AE30(S_14A* self) {
    func_00140A00(self);
    self->unk8 = D_0033BE38;
    self->unk250 = 0;
    self->unk254 = 0;
    func_00123200((char*)self + 0x260);
    self->unk20 = 0x99A27B69;
    return self;
}

extern "C" void func_0014AE80(S_14A* self, int flags) {
    self->unk8 = D_0033BE38;
    if (self->unk250) {
        func_0015D408(((S8_14A*)self)->unk2C);
    }
    func_001232E8((char*)self + 0x260, 2);
    func_00140A60(self, 0);
    if (flags & 1) {
        func_0014AE10_p(self);
    }
}

INCLUDE_ASM("asm/nonmatchings/game/t_14A6B0", func_0014AEF8);

extern "C" int func_0014B0F8(S8_14A* self, u32 key) {
    if (key == 0x6D09B0BE) {
        S9_14A* p = func_0015D2E8(self->unk2C, 1);
        func_00123040(p);
        void** r = &p->unk34;
        if (*r) {
            func_001CE888(*r, r);
            *r = 0;
        }
        *r = 0;
        return 1;
    }
    return func_0013B608(self, key);
}

GP_DATA(D_00372B40);
extern "C" void func_0014B168(int a, int b) {
    if (b == 0xFFFF && a) {
        D_00372B40 = 0x8CB9E318;
    }
}

extern "C" void func_0014B190(void) {
    func_0014B168(1, 0xFFFF);
}

INCLUDE_ASM("asm/nonmatchings/game/t_14A6B0", func_0014B1B0);

extern "C" S7_14A* func_0014B1F8(S7_14A* self, int n) {
    self->unk4 = n;
    self->unk0 = 0;
    self->unk8 = 0;
    if (n) {
        self->unk0 = func_00118F20(D_00368A38, n * 4, 1, 0);
        func_0030A49C(self->unk0, 0, self->unk4 * 4);
    }
    return self;
}

INCLUDE_ASM("asm/nonmatchings/game/t_14A6B0", func_0014B260);

extern "C" void func_0014B368(void* p) {
    S7_14A* self = (S7_14A*)p;
    if (self->unk4 == 0) {
        return;
    }
    if (self->unk0 == 0) {
        return;
    }
    for (u32 i = 0; i < (u32)self->unk4; i++) {
        if (((void**)self->unk0)[i]) {
            func_00119400(D_00368A38, ((void**)self->unk0)[i]);
            ((void**)self->unk0)[i] = 0;
        }
    }
    if (self->unk0) {
        func_00119400(D_00368A38, self->unk0);
    }
    self->unk0 = 0;
}

INCLUDE_ASM("asm/nonmatchings/game/t_14A6B0", func_0014B410);

INCLUDE_ASM("asm/nonmatchings/game/t_14A6B0", func_0014BCB8);

extern "C" void func_0014C348(void* self, int flags) {
    func_0014B368(self);
    if (flags & 1) {
        func_00119400(D_00368A38, self);
    }
}

static inline void* HT_14A_Get(HT_14A* t, const u32& key) {
    if (!t->items) {
        return 0;
    }
    HI_14A* e = &t->items[key & ((1 << t->bits) - 1)];
    if (!e) {
        return 0;
    }
    while (e) {
        if (e->key == key && (t->unk15 || e->value)) {
            return e->value;
        }
        e = e->next;
    }
    return 0;
}

extern "C" S5_14A* func_0014C390(u32 key) {
    return (S5_14A*)HT_14A_Get((HT_14A*)D_00377FC0, key);
}

extern "C" void func_0014C418(int x) {
    S5_14A* s = func_0014C390(x);
    if (--s->unk8 == 0) {
        func_0014C4A8(D_00377FC0, &x);
        if (s) {
            func_0014C348(s, 3);
        }
    }
}

extern "C" void func_0014C470(S_0014C470* self) {
    self->unk0 = 0;
    self->unk4 = 0;
    self->unk8 = 0;
}

extern "C" S_0014C470* func_0014C480(S_0014C470* self) {
    func_0014C470(self);
    return self;
}

extern "C" void func_0014C4A8(void* p, int* key) {
    HT_14A* t = (HT_14A*)p;
    if (!t->items) {
        return;
    }
    HI_14A* e = &t->items[*key & ((1 << t->bits) - 1)];
    HI_14A* prev = 0;
    while (e) {
        HI_14A* next = e->next;
        if (e->key == (u32)*key && e->value) {
            if (prev) {
                prev->next = next;
                func_0011C408(0, e);
            } else {
                e->key = 0;
                e->value = 0;
            }
            t->count--;
            return;
        }
        prev = e;
        e = next;
    }
}

INCLUDE_ASM("asm/nonmatchings/game/t_14A6B0", func_0014C560);
