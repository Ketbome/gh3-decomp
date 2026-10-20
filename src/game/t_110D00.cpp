#include "common.h"

extern "C" {
void Heap_Free(int, void*);
extern int D_00368A38[] __attribute__((section(".sdata")));
extern u8 D_003378E0[];
}

struct S_00112A38 { char pad0[0x24]; float* unk24; char pad1[0x10]; float* unk38; };

struct S_00111A38 { char pad0[0x4]; int unk4; };
struct S_00112A30 { char pad0[0x28]; int unk28; };
struct S_00112A50 { char pad0[0x3C]; int unk3C; };

struct SA110 {
    float* unk0;
    char pad4[0xC];
    float* unk10;
};

INCLUDE_ASM("asm/nonmatchings/game/t_110D00", func_00110D00);

INCLUDE_ASM("asm/nonmatchings/game/t_110D00", func_00111290);

struct V_1117 { int a; int b; int c; void* vp; };
struct O_1117 { V_1117 a; V_1117 b; int x; V_1117 c; int y; V_1117 d; };
extern "C" char D_003378C8[];

extern "C" O_1117* func_001117F8(O_1117* self) {
    self->a.a = 0;
    self->a.b = 0;
    self->a.vp = D_003378C8;
    V_1117* pb = &self->b;
    self->a.c = 0;
    V_1117* pc = &self->c;
    pb->vp = D_003378C8;
    V_1117* pd = &self->d;
    self->b.a = 0;
    pb->b = 0;
    pb->c = 0;
    self->x = 0;
    pc->vp = D_003378C8;
    self->c.a = 0;
    pc->b = 0;
    pc->c = 0;
    self->y = 0;
    pd->vp = D_003378C8;
    self->d.a = 0;
    pd->b = 0;
    pd->c = 0;
    return self;
}

struct FA_111860 { float* unk0; u32 unk4; u32 unk8; };
extern "C" {
void* Heap_Alloc_f(int, int, int, int) __asm__("Heap_Alloc");
void Heap_Free_f(int, void*) __asm__("Heap_Free");
}

static inline void Set_111860(FA_111860* a, u32 n) {
    if (n == 0) {
        if (a->unk0 != 0) {
            a->unk4 = 0;
            if (a->unk0 != 0) Heap_Free_f(D_00368A38[0], a->unk0);
            a->unk0 = 0;
        }
    } else {
        float* t = (float*)Heap_Alloc_f(D_00368A38[0], n * 4, 1, 0);
        for (u32 i = 0; i < n && i < a->unk4; i++) {
            t[i] = a->unk0[i];
        }
        if (a->unk0 != 0) Heap_Free_f(D_00368A38[0], a->unk0);
        a->unk0 = t;
        a->unk4 = n;
        a->unk8 = n;
    }
}

extern "C" void func_00111860_s(FA_111860* self, u32 n) __asm__("func_00111860");
void func_00111860_s(FA_111860* self, u32 n) {
    Set_111860(self, n);
    Set_111860((FA_111860*)((char*)self + 0x10), n);
}

extern "C" void func_00111A08(SA110* self, int i, float* v) {
    float* p = self->unk0;
    p += i;
    *p = *v;
}

extern "C" void func_00111A20(SA110* self, int i, float* v) {
    float* p = self->unk10;
    p += i;
    *p = *v;
}

extern "C" int func_00111A38(S_00111A38* self) {
    return self->unk4;
}

INCLUDE_ASM("asm/nonmatchings/game/t_110D00", func_00111A40);

INCLUDE_ASM("asm/nonmatchings/game/t_110D00", func_00111E38);

INCLUDE_ASM("asm/nonmatchings/game/t_110D00", func_00112830);

extern "C" int func_00112A30(S_00112A30* self) {
    return self->unk28;
}

extern "C" float func_00112A38(S_00112A38* self, int i) {
    float* p = self->unk24;
    p += i;
    return *p;
}

extern "C" int func_00112A50(S_00112A50* self) {
    return self->unk3C;
}

extern "C" float func_00112A58(S_00112A38* self, int i) {
    float* p = self->unk38;
    p += i;
    return *p;
}

INCLUDE_ASM("asm/nonmatchings/game/t_110D00", func_00112A70);

INCLUDE_ASM("asm/nonmatchings/game/t_110D00", func_00112CB0);

extern "C" void func_00112CC8(void* dst, const void* src) {
    asm volatile("lqc2 $vf2, 0(%1)\n\tlqc2 $vf1, 0(%0)\n\tvmove.xyz $vf1, $vf2\n\tsqc2 $vf1, 0(%0)"
        : : "r"(dst), "r"(src) : "memory");
}

struct S112CE0 { void* unk0; int unk4; char pad8[4]; void* unkC; };

extern "C" void func_00112CE0(S112CE0* self, int flags) {
    self->unkC = D_003378E0;
    void* p = self->unk0;
    if (p) {
        self->unk4 = 0;
        Heap_Free(D_00368A38[0], p);
        self->unk0 = 0;
    }
    if (flags & 1) {
        Heap_Free(D_00368A38[0], self);
    }
}
