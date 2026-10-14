#include "common.h"

typedef unsigned int u128_10E __attribute__((mode(TI)));

union U10E {
    u128_10E q;
    float f[4];
};

struct S10E {
    u128_10E* unk0;
};

struct A10E {
    int unk0;
    int unk4;
    int unk8;
    void* unkC;
};

struct B10E {
    A10E unk0;
    A10E unk10;
    void* unk20;
};

struct C10E {
    A10E unk0;
    A10E unk10;
    int unk20;
    B10E unk24;
};

extern "C" {
extern u8 D_003378E0[];
extern u8 D_003378C8[];
extern u8 D_003378B0[];
void func_0010D818(int, int);
}

struct S_00110170 { char pad0[0x10]; float* unk10; };

struct S_0010EBD8 { int unk0; int unk4; int unk8; int unkC; };

struct S_00110150 { char pad0[0x4]; int unk4; };

extern "C" void func_0010EBD8(S_0010EBD8* self, int a, int b, int c, int d) {
    self->unk0 = a;
    self->unk4 = b;
    self->unk8 = c;
    self->unkC = d;
}

extern "C" void func_0010EBF0(void) {
    func_0010D818(1, 0xFFFF);
}
TEXT_PAD(8);

INCLUDE_ASM("asm/nonmatchings/game/t_10EBD8", func_0010EC18);

INCLUDE_ASM("asm/nonmatchings/game/t_10EBD8", func_0010EC88);

INCLUDE_ASM("asm/nonmatchings/game/t_10EBD8", func_0010F300);

extern "C" void* func_0010F690(void* p) {
    return p;
}

INCLUDE_ASM("asm/nonmatchings/game/t_10EBD8", func_0010F698);

INCLUDE_ASM("asm/nonmatchings/game/t_10EBD8", func_0010F6A8);

INCLUDE_ASM("asm/nonmatchings/game/t_10EBD8", func_0010F6C0);

extern "C" u128_10E func_0010F6D8(const u128_10E* a, const u128_10E* b) {
    u128_10E r;
    asm("lqc2 $vf2, 0(%1)\n\tlqc2 $vf1, 0(%2)\n\tvadd.xyzw $vf3, $vf2, $vf1\n\tqmfc2.ni %0, $vf3"
        : "=r"(r) : "r"(a), "r"(b));
    return r;
}

extern "C" u128_10E func_0010F6F0(const u128_10E* a, const u128_10E* b) {
    u128_10E r;
    asm("lqc2 $vf2, 0(%1)\n\tlqc2 $vf1, 0(%2)\n\tvsub.xyzw $vf3, $vf2, $vf1\n\tqmfc2.ni %0, $vf3"
        : "=r"(r) : "r"(a), "r"(b));
    return r;
}

extern "C" u128_10E func_0010F708(const u128_10E* a, float s) {
    u128_10E r;
    asm("mfc1 %0, %2\n\tqmtc2.ni %0, $vf2\n\tlqc2 $vf1, 0(%1)\n\tvmulx.xyzw $vf3, $vf1, $vf2x\n\tqmfc2.ni %0, $vf3"
        : "=&r"(r) : "r"(a), "f"(s));
    return r;
}

extern "C" float func_0010F720(const u128_10E* a, const u128_10E* b) {
    float r;
    int t;
    asm("lqc2 $vf1, 0(%2)\n\tlqc2 $vf3, 0(%3)\n\tvmul.xyzw $vf1, $vf1, $vf3\n\tvaddy.x $vf2, $vf1, $vf1y\n\tvaddz.x $vf2, $vf2, $vf1z\n\tqmfc2.ni %1, $vf2\n\tmtc1 %1, %0"
        : "=f"(r), "=&r"(t) : "r"(a), "r"(b));
    return r;
}

extern "C" void* func_0010F748(void* p) {
    return p;
}

INCLUDE_ASM("asm/nonmatchings/game/t_10EBD8", func_0010F750);

INCLUDE_ASM("asm/nonmatchings/game/t_10EBD8", func_0010F970);

INCLUDE_ASM("asm/nonmatchings/game/t_10EBD8", func_0010FC88);

INCLUDE_ASM("asm/nonmatchings/game/t_10EBD8", func_0010FC90);

INCLUDE_ASM("asm/nonmatchings/game/t_10EBD8", func_0010FE60);

struct V_10FE { int a; int b; int c; void* vp; };
struct O_10FE { V_10FE a; V_10FE b; int x; V_10FE c; V_10FE d; void* e; };

extern "C" O_10FE* func_0010FED0(O_10FE* self) {
    self->a.a = 0;
    self->a.vp = D_003378E0;
    self->a.b = 0;
    V_10FE* pb = &self->b;
    self->a.c = 0;
    pb->vp = D_003378C8;
    V_10FE* pc = &self->c;
    self->b.a = 0;
    V_10FE* pd = &self->d;
    pb->b = 0;
    pb->c = 0;
    self->x = 0;
    *(void**)((char*)pc + 0x20) = D_003378B0;
    pc->vp = D_003378C8;
    self->c.a = 0;
    pc->b = 0;
    pc->c = 0;
    pd->vp = D_003378C8;
    self->d.a = 0;
    pd->b = 0;
    pd->c = 0;
    return self;
}

INCLUDE_ASM("asm/nonmatchings/game/t_10EBD8", func_0010FF48);

extern "C" int func_00110150(S_00110150* self) {
    return self->unk4;
}

extern "C" void func_00110158(S10E* self, int i, u128_10E v) {
    u128_10E* p = self->unk0;
    p += i;
    *p = v;
}

extern "C" void func_00110170(S_00110170* self, int i, float v) {
    float* p = self->unk10;
    p += i;
    *p = v;
}

INCLUDE_ASM("asm/nonmatchings/game/t_10EBD8", func_00110188);

INCLUDE_ASM("asm/nonmatchings/game/t_10EBD8", func_00110318);

INCLUDE_ASM("asm/nonmatchings/game/t_10EBD8", func_00110A00);
