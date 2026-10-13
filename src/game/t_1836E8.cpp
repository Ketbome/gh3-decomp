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
int func_001BDCF8(int, int, int, int, int, int);
int func_001BDA28(int, int, int, int);
s16 func_001BF348(int);
s16 func_001BF350(int);
void func_00157538(void*);
extern u8 D_00343C50[];
extern u8 D_00343A98[];
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

INCLUDE_ASM("asm/nonmatchings/game/t_1836E8", func_001841F8);

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

INCLUDE_ASM("asm/nonmatchings/game/t_1836E8", func_00185068);

INCLUDE_ASM("asm/nonmatchings/game/t_1836E8", func_00185130);

INCLUDE_ASM("asm/nonmatchings/game/t_1836E8", func_00185480);
