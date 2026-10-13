#include "common.h"

struct VEntry21B {
    s16 delta;
    s16 unk2;
    void* fn;
};

struct S21B {
    char pad0[0xC];
    void* unkC;
    char pad10[0x8];
    VEntry21B* unk18;
    char pad1C[0xC];
    int unk28;
    int unk2C;
    int unk30;
};

extern "C" {
void* func_00113D20(u32 size);
void* func_0021C318(void*);
void func_00276D68(u32, void*, int);
extern u8 D_00390530[];
int func_001D1CF8(void*, u32);
void* func_001D0F68(void*);
f32 func_0011ED10(void);
extern u8 D_00351888[];
}

INCLUDE_ASM("asm/nonmatchings/game/t_21BA08", func_0021BA08);

INCLUDE_ASM("asm/nonmatchings/game/t_21BA08", func_0021BB38);

INCLUDE_ASM("asm/nonmatchings/game/t_21BA08", func_0021BB40);

struct E21B {
    char pad0[0x18];
    int unk18;
};

extern "C" void func_0021C250(char* p) {
    u32 i;
    char* q;
    i = 1;
    if (i < *(u32*)(p + 0x38)) {
        q = p + 0x8C;
        do {
            i++;
            (*(E21B**)q)->unk18 = 0;
            q += 0x50;
        } while (i < *(u32*)(p + 0x38));
    }
    i = 0;
    if (*(u32*)(p + 0x870)) {
        q = p + 0x680;
        do {
            i++;
            (*(E21B**)q)->unk18 = 0;
            q += 4;
        } while (i < *(u32*)(p + 0x870));
    }
}

extern "C" void* func_0021C2C0(void) {
    return func_0021C318(func_00113D20(0x54));
}

extern "C" void func_0021C2E8(void) {
    func_00276D68(0x6DCFEC46, D_00390530, 0x10);
}

struct C21B {
    u8 r, g, b, a;
    C21B(u8 r_, u8 g_, u8 b_, u8 a_) {
        r = r_;
        g = g_;
        b = b_;
        a = a_;
    }
};

extern "C" void* func_0021C318(void* self) {
    char* p = (char*)self;
    func_001D0F68(p);
    char** n = (char**)(p + 0x20);
    n[0] = p + 0x20;
    *(void**)(p + 0x18) = D_00351888;
    n[1] = p + 0x20;
    *(u32*)(p + 4) = 0x6DCFEC46;
    *(int*)(p + 0x28) = 0;
    *(int*)(p + 0x2C) = 0;
    *(int*)(p + 0x30) = 0;
    *(int*)(p + 0x3C) = 0;
    *(int*)(p + 0x38) = 0;
    C21B c(0, 0xFF, 0, 0xFF);
    *(f32*)(p + 0x34) = func_0011ED10();
    *(int*)(p + 0x40) = 0;
    *(int*)(p + 0x44) = 0;
    *(int*)(p + 0x48) = 0;
    *(int*)(p + 0x4C) = 0;
    return p;
}

INCLUDE_ASM("asm/nonmatchings/game/t_21BA08", func_0021C3A8);

INCLUDE_ASM("asm/nonmatchings/game/t_21BA08", func_0021C530);

extern "C" void func_0021CDB0(S21B* p) {
    p->unk28 = (int)func_001D1CF8(p->unkC, 0xCE0CA665);
    p->unk2C = (int)func_001D1CF8(p->unkC, 0x222756D5);
    p->unk30 = (int)func_001D1CF8(p->unkC, 0x286A8D26);
}

extern "C" void func_0021CE10(S21B* self, int a) {
    VEntry21B* e = &self->unk18[3];
    ((void (*)(void*, int))e->fn)((char*)self + e->delta, a);
}

INCLUDE_ASM("asm/nonmatchings/game/t_21BA08", func_0021CE38);

INCLUDE_ASM("asm/nonmatchings/game/t_21BA08", func_0021D8F8);
