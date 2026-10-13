#include "common.h"

struct S00183828 {
    int unk0;
    int unk4;
    int unk8;
    int unkC;
};

struct S00183728 {
    char pad[0x18];
    void* unk18;
};

extern "C" {
void Heap_Free(int, void*);
void func_001BDE38(int);
extern int D_00368A38[] __attribute__((section(".sdata")));
int func_001BDB28(int, int, int, int, int);
void func_001BF200(int, int);
void func_001BB068(void);
int func_001BDCF8(int, int, int, int, int, int);
int func_001BDA28(int, int, int, int);
s16 func_001BF348(int);
s16 func_001BF350(int);
void func_00157538(void*);
extern u8 D_00343C50[];
extern u8 D_00343A98[];
extern u8 D_0033C6B8[];
void* Heap_Alloc(int, int, int, int);
void func_00152B88(void*);
}

INCLUDE_ASM("asm/nonmatchings/game/t_1836E8", func_001836E8);

extern "C" void func_00183728(S00183728* self) {
    self->unk18 = D_00343A98;
    func_00152B88(self);
}

extern "C" void func_00183750(void) {
}

extern "C" int func_00183758(void) {
    return 0;
}

struct VE_183760 { s16 unk0; s16 unk2; int (*unk4)(void*); };
struct V_183760 { char pad0[0xB8]; VE_183760 unkB8; };
struct S_183760a { char pad0[0xC]; V_183760* unkC; };
struct S_183760 { char pad0[0x14]; S_183760a* unk14; };

extern "C" int func_00183760(S_183760* self) {
    S_183760a* o = self->unk14;
    V_183760* v = o->unkC;
    return v->unkB8.unk4((char*)o + v->unkB8.unk0);
}

extern "C" void func_00183790(void) {
}

struct S00183798 {
    int unk0;
    int unk4;
    int unk8;
    int unkC;
    int unk10;
    int unk14;
    void* unk18;
};

static inline void init_00183798(S00183798* p, S00183798* o) {
    p->unk18 = D_0033C6B8;
    p->unk0 = o->unk0;
    p->unk4 = o->unk4;
    p->unk8 = o->unk8;
    p->unkC = o->unkC;
    p->unk10 = o->unk10;
    p->unk18 = D_00343A98;
    p->unk14 = o->unk14;
}

INCLUDE_ASM("asm/nonmatchings/game/t_1836E8", func_00183798);

INCLUDE_ASM("asm/nonmatchings/game/t_1836E8", func_00183820);

extern "C" S00183828* func_00183828(S00183828* self) {
    self->unk0 = 0;
    self->unk4 = 0;
    self->unk8 = 0;
    self->unkC = 0;
    return self;
}

struct S183840 { char pad0[4]; unsigned int unk4; void* unk8; s16 unkC; s16 unkE; int unk10; };

extern "C" S183840* func_00183840(S183840* self, int a) {
    func_00157538(self);
    void* d = D_00343C50;
    unsigned int t = self->unk4 & 0x0FFFF000;
    self->unk8 = d;
    self->unkE = 0;
    self->unkC = 0;
    self->unk4 = t;
    self->unk10 = 0;
    if (a) self->unk4 = t | 8;
    return self;
}

INCLUDE_ASM("asm/nonmatchings/game/t_1836E8", func_001838B0);

INCLUDE_ASM("asm/nonmatchings/game/t_1836E8", func_00183AB8);

INCLUDE_ASM("asm/nonmatchings/game/t_1836E8", func_00183BD0);

struct S184188 { char pad0[4]; unsigned int unk4; char pad8[4]; s16 unkC; s16 unkE; int unk10; };

extern "C" int func_00184188(S184188* self, int a, int b, int c) {
    int t = func_001BDA28(a, b, c, ((int)self->unk4 >> 3) & 1);
    self->unk10 = t;
    if (t) {
        self->unk4 = self->unk4 | 1;
        self->unkC = func_001BF348(t);
        self->unkE = func_001BF350(self->unk10);
    }
    return self->unk10 != 0;
}

extern "C" int func_001841F8(S184188* self, int a, int b, int c, int d) {
    int t = func_001BDB28(a, b, c, d, ((int)self->unk4 >> 3) & 1);
    self->unk10 = t;
    if (t) {
        self->unk4 = self->unk4 | 1;
        self->unkC = func_001BF348(t);
        self->unkE = func_001BF350(self->unk10);
        if (c == 1 && d == c) {
            func_001BF200(self->unk10, 1);
            func_001BB068();
        }
    }
    return self->unk10 != 0;
}

extern "C" int func_001842B0(S184188* self, int a1, int a2, int a3, int a4, int a5, int a6) {
    int t = func_001BDCF8(a2, a3, a4, a5, 1, a6);
    self->unk10 = t;
    if (t) {
        self->unk4 = self->unk4 | 1;
        self->unkC = func_001BF348(t);
        self->unkE = func_001BF350(self->unk10);
    }
    return self->unk10 != 0;
}

INCLUDE_ASM("asm/nonmatchings/game/t_1836E8", func_00184320);

INCLUDE_ASM("asm/nonmatchings/game/t_1836E8", func_001849A0);

INCLUDE_ASM("asm/nonmatchings/game/t_1836E8", func_00184A48);

INCLUDE_ASM("asm/nonmatchings/game/t_1836E8", func_00184D58);

struct O185068 { void* unk0; void* unk4; void* unk8; int unkC; };
struct S185068 { char pad0[4]; int unk4; char pad8[8]; O185068* unk10; };

extern "C" int func_00185068(S185068* self) {
    O185068* v;
    if ((self->unk4 >> 2) & 1) {
        v = (O185068*)self->unk10->unk0;
    } else {
        v = 0;
        if (self->unk4 & 1) v = self->unk10;
    }
    if (self->unk10->unk8) Heap_Free(D_00368A38[0], self->unk10->unk8);
    if (self->unk10->unk4) Heap_Free(D_00368A38[0], self->unk10->unk4);
    if (self->unk10->unkC) func_001BDE38(self->unk10->unkC);
    Heap_Free(D_00368A38[0], self->unk10);
    self->unk10 = v;
    self->unk4 = self->unk4 & 0xFFFFFFFB;
    return 1;
}

INCLUDE_ASM("asm/nonmatchings/game/t_1836E8", func_00185130);

INCLUDE_ASM("asm/nonmatchings/game/t_1836E8", func_00185480);
