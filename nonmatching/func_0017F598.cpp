// cflags: -fno-gcse
#include "common.h"

struct S17F4F0 { char pad0[4]; int unk4; float* unk8; };

struct N_001800E8 { char pad0[4]; N_001800E8* unk4; };
struct L_001800E8 { char pad0[4]; void* unk4; void* unk8; };
struct S_001800E8 { char pad0[0x14]; void* unk14; void* unk18; };

extern "C" {
void Heap_Free(int, void*);
void func_00172A00(void*, int);
extern u8 D_003435E0[];
extern int D_00368A38[] __attribute__((section(".sdata")));
}

INCLUDE_ASM("asm/nonmatchings/game/t_17F4F0", func_0017F4F0);

INCLUDE_ASM("asm/nonmatchings/game/t_17F4F0", func_0017F590);

typedef unsigned int u128_17F __attribute__((mode(TI)));
extern "C" u8 D_00373ED0[];

static inline f32 GetX17F(u128_17F q) {
    f32 f;
    asm volatile("mtc1 %1, %0" : "=f"(f) : "r"(q));
    return f;
}
static inline f32 GetY17F(u128_17F q) {
    f32 f;
    asm volatile("dsrl32 %0, %1, 0" : "=r"(f) : "r"(q));
    return f;
}
static inline f32 GetZ17F(u128_17F q) {
    f32 f;
    asm volatile("pcpyud %0, %1, %1" : "=r"(f) : "r"(q));
    return f;
}

extern "C" void func_0017F598(float* v, float* out) {
    u128_17F q = *(u128_17F*)v;
    float x = GetX17F(q);
    float y = GetY17F(q);
    float z = GetZ17F(q);
    float a = __builtin_fabsf(x);
    float b = __builtin_fabsf(y);
    float c = __builtin_fabsf(z);
    int i = 0;
    int j = 1;
    int k = 2;
    if (b < a) {
        a = b;
        j = 0;
        i = 1;
    }
    if (c < a) k = i;
    *(u128_17F*)out = *(u128_17F*)D_00373ED0;
    out[3] = v[k];
    out[3] = -v[j];
}

INCLUDE_ASM("asm/nonmatchings/game/t_17F4F0", func_0017F630);

INCLUDE_ASM("asm/nonmatchings/game/t_17F4F0", func_0017F690);

INCLUDE_ASM("asm/nonmatchings/game/t_17F4F0", func_0017F7F0);

INCLUDE_ASM("asm/nonmatchings/game/t_17F4F0", func_0017F810);

INCLUDE_ASM("asm/nonmatchings/game/t_17F4F0", func_0017F9A0);

extern "C" void func_001800E8(S_001800E8* self, int flags) {
    self->unk14 = D_003435E0;
    if (self->unk18) {
        Heap_Free(D_00368A38[0], self->unk18);
        self->unk18 = 0;
    }
    L_001800E8* l = (L_001800E8*)((char*)self + 0x1C);
    N_001800E8* end = (N_001800E8*)((char*)self + 0x20);
    N_001800E8* p = (N_001800E8*)l->unk8;
    l->unk8 = end;
    l->unk4 = end;
    if (p != end) {
        N_001800E8* e = (N_001800E8*)((char*)l + 4);
        do {
            N_001800E8* n = p;
            p = p->unk4;
            Heap_Free(D_00368A38[0], n);
        } while (p != e);
    }
    func_00172A00(self, flags);
}

INCLUDE_ASM("asm/nonmatchings/game/t_17F4F0", func_00180190);

struct O_00180578 { char pad0[0x28]; float unk28; float unk2C; float unk30; float unk34; };
struct N_00180578 { char pad0[4]; N_00180578* unk4; char pad8[0x38]; int unk40; };
struct It_00180578 {
    int unk0;
    N_00180578* cur;
    It_00180578(N_00180578* n) : cur(n) {}
    bool operator!=(const It_00180578& o) const { return cur != o.cur; }
    void operator++() { cur = cur->unk4; }
    O_00180578* operator->() const { return (O_00180578*)((char*)cur + 0x10); }
};
struct L_00180578 { char pad0[0x20]; N_00180578 unk20; };

extern "C" void func_00180578(L_00180578* self, float* dt) {
    for (It_00180578 it(self->unk20.unk4); it != It_00180578(&self->unk20); ++it) {
        if (it->unk30 != 0.0f) {
            float d = it->unk30 * *dt;
            it->unk28 = it->unk28 + d;
            if ((d > 0.0f && it->unk28 >= it->unk34) || (d < 0.0f && it->unk28 <= it->unk34)) {
                it->unk28 = it->unk34;
                it.cur->unk40 = 0;
            }
            it->unk2C = it->unk28;
        }
    }
}

INCLUDE_ASM("asm/nonmatchings/game/t_17F4F0", func_00180660);
