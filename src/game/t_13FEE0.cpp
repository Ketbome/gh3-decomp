#include "common.h"

struct S13F_C { u8 r; u8 g; u8 b; u8 a; };

struct S13F_Y {
    char pad0[0xE8];
    S13F_C unkE8;
    char padEC[0xA4];
    float unk190;
    char pad194[0x44];
    S13F_C unk1D8;
    char pad1DC[0x20];
    float unk1FC;
    char pad200[0x44];
    int unk244;
};

struct S13F_X {
    char pad0[0x8];
    void* unk8;
    u32 unkC;
    char pad10[0x230];
    int unk240;
    int unk244;
    int unk248;
};

struct S_00141670 { char pad0[0x248]; int unk248; };
struct S_00141690 { char pad0[0x248]; int unk248; };
struct S_00141968 { char pad0[0x248]; int unk248; };
struct S_00141B50 { char pad0[0x244]; int unk244; };

struct S_00141B00 { char pad0[0xC]; int unkC; char pad10[0x230]; int unk240; int unk244; };

struct CP_13F { u8 r; u8 g; u8 b; u8 a; };
struct C_13F {
    CP_13F c;
    C_13F(const C_13F& o) : c(o.c) {}
};
struct S_00141B70 { char pad0[0xE8]; C_13F unkE8; char padEC[0xA4]; float unk190; char pad194[0x68]; float unk1FC; char pad200[0x44]; int unk244; };

extern "C" {
void func_0015EB90(int, C_13F);
int func_0013FE00(void*);
void func_0013FC78(void*, char*, int);
void func_0013FC50(void*, char*);
int func_0027D870(void*, u32, int*, int);
int func_0027D268(void*, u32, float*, int);
void func_0013A100(void*, void*);
void func_00139C18(void*, int, int, float);
void func_00141B00(void*, int);
void* func_00138790(int, int);
int func_0027E698(void*);
void func_0027E760(int, int, int);
void func_0027EDE0(int, int, int);
void func_0027C678(void*, u32, int);
void func_0027E6B0(int, int);
void func_0015EB00(int, int);
void func_0015EB30(int, float);
extern int D_00368A38[] __attribute__((section(".sdata")));
int func_00119610(int, int);
void func_00119490(int, int);
void* Heap_Alloc(int, int, int, int);
void func_001194B8(int);
int func_0011C130(void*, int, int, void*, int, int);
extern u8 D_0033AFA8[];
extern u8 D_0033AFB8[];
extern u8 D_0033B148[];
S13F_X* func_00138F20(S13F_X*);
int func_0014E968(int);
void func_0014E988(int);
void func_0014E9C8(int);
void func_001CEDE0(S13F_X*, u32);
void func_00139420(S13F_X*, int);
void func_0013B0B0(S13F_X*, void*);
void func_0027C448(void*, u32, int);
extern volatile int D_00372B88;
int func_0015B268(int, int);
void func_0015EB60(int, int);
void func_00140F80(S13F_X*, int, void*);
void func_0013A8C0(S13F_X*, int, void*);
void func_001CF538(S13F_X*, int, void*);
int func_0027B300(void*, int);
void func_00141428(void);
void func_0015E228(int);
void func_0015E2A8(int);
void func_0015E648(int);
void func_0015EA48(int, int);
void func_00141B50(S_00141B50*, int);
extern int D_003696B8;
void func_0011C2A8(int, int);
void func_0011C2E8(int, int);
}

struct S_00141608 { char pad0[0x248]; int* unk248; };

extern "C" int func_0013FEE0(void* self) {
    char buf[0x200];
    int n = func_0013FE00(self);
    if (!n) {
        return 0;
    }
    func_0013FC78(self, buf, 0x200);
    if (n > 1 && buf[n - 1] == '\\' && buf[n - 2] == '\\') {
        buf[n - 2] = 0;
    }
    buf[n - 1] = 0;
    func_0013FC50(self, buf);
    return 1;
}

INCLUDE_ASM("asm/nonmatchings/game/t_13FEE0", func_0013FF78);

INCLUDE_ASM("asm/nonmatchings/game/t_13FEE0", func_00140270);

INCLUDE_ASM("asm/nonmatchings/game/t_13FEE0", func_00140408);

INCLUDE_ASM("asm/nonmatchings/game/t_13FEE0", func_00140558);

INCLUDE_ASM("asm/nonmatchings/game/t_13FEE0", func_001406D8);

INCLUDE_ASM("asm/nonmatchings/game/t_13FEE0", func_001407D8);

extern "C" void func_00140930(void) {
    void* m;
    int heap = D_00368A38[0];
    func_00119490(heap, func_00119610(heap, 0x3A));
    m = Heap_Alloc(D_00368A38[0], 0x70, 1, 0);
    D_003696B8 = func_0011C130(m, 0x250, 0x1F4, D_0033AFA8, 1, 0);
    func_001194B8(D_00368A38[0]);
}

GP_DATA(D_003696B8);
extern "C" void func_001409B8(void) {
    func_0011C2A8(D_003696B8, 1);
}

extern "C" void func_001409D8(int a) {
    func_0011C2E8(D_003696B8, a);
}

extern "C" S13F_X* func_00140A00(S13F_X* self) {
    func_00138F20(self);
    self->unk240 = 0;
    self->unk8 = D_0033AFB8;
    self->unk248 = func_0014E968(0);
    self->unk244 = 1;
    func_001CEDE0(self, 0xB12B510A);
    return self;
}

extern "C" void func_00140A60(S13F_X* self, int flags) {
    self->unk8 = D_0033AFB8;
    if (self->unk248) {
        func_0014E988(self->unk248);
    }
    func_00139420(self, 0);
    if (flags & 1) {
        func_001409D8((int)self);
    }
}

INCLUDE_ASM("asm/nonmatchings/game/t_13FEE0", func_00140AC8);

INCLUDE_ASM("asm/nonmatchings/game/t_13FEE0", func_00140CD0);

INCLUDE_ASM("asm/nonmatchings/game/t_13FEE0", func_00140F80);

extern "C" void func_001413A0(S13F_X* self, void* list) {
    int it = func_0027B300(list, 0);
    while (it) {
        func_00140F80(self, it, list);
        func_0013A8C0(self, it, list);
        func_001CF538(self, it, list);
        it = func_0027B300(list, it);
    }
}

INCLUDE_ASM("asm/nonmatchings/game/t_13FEE0", func_00141428);

extern "C" int func_00141608(S_00141608* self) {
    return *self->unk248;
}

extern "C" void func_00141618(void) {
    func_00141428();
}

extern "C" void func_00141638(void) {
    func_00141428();
}

INCLUDE_ASM("asm/nonmatchings/game/t_13FEE0", func_00141658);

extern "C" void func_00141660(void) {
}

INCLUDE_ASM("asm/nonmatchings/game/t_13FEE0", func_00141668);

extern "C" void func_00141670(S_00141670* self) {
    func_0015E228(self->unk248);
}

extern "C" void func_00141690(S_00141690* self) {
    func_0015E2A8(self->unk248);
}

INCLUDE_ASM("asm/nonmatchings/game/t_13FEE0", func_001416B0);

extern "C" void func_00141920(S13F_X* self, void* params) {
    func_0013B0B0(self, params);
    func_0027C448(params, 0x7D99F28D, self->unk240);
}

extern "C" void func_00141968(S_00141968* self) {
    func_0015E648(self->unk248);
}

INCLUDE_ASM("asm/nonmatchings/game/t_13FEE0", func_00141988);

extern "C" void func_001419E8(S13F_X* self, int flags) {
    self->unk8 = D_0033B148;
    if (self->unk244) {
        func_0014E9C8(self->unk244);
    }
    func_00139420(self, flags);
}

INCLUDE_ASM("asm/nonmatchings/game/t_13FEE0", func_00141A40);

INCLUDE_ASM("asm/nonmatchings/game/t_13FEE0", func_00141AF8);

extern "C" void func_00141B00(void* p, int v) {
    S_00141B00* self = (S_00141B00*)p;
    self->unk240 = v;
    func_0015EB60(self->unk244, func_0015B268(D_00372B88, v));
    self->unkC |= 0x1000;
}

extern "C" void func_00141B50(S_00141B50* self, int v) {
    func_0015EA48(self->unk244, v);
}

extern "C" void func_00141B70(S_00141B70* self) {
    func_0015EB00(self->unk244, 0);
    func_0015EB30(self->unk244, self->unk1FC);
    float f = self->unk190;
    C_13F c(self->unkE8);
    if (f >= 0.0001f) {
        c.c.a = (int)(C_13F(self->unkE8).c.a * f);
    } else {
        c.c.a = 0;
    }
    func_0015EB90(self->unk244, c);
}

extern "C" void func_00141C28(S13F_Y* self, void* params) {
    S13F_C c = self->unk1D8;
    int arr = func_0027E698(func_00138790(0xC, 1));
    func_0027E760(arr, 4, 1);
    func_0027EDE0(arr, 0, c.r);
    func_0027EDE0(arr, 1, c.g);
    func_0027EDE0(arr, 2, c.b);
    func_0027EDE0(arr, 3, c.a);
    func_0027C678(params, 0x3F6BCDBA, arr);
    if (arr) {
        func_0027E6B0(arr, 3);
    }
}

INCLUDE_ASM("asm/nonmatchings/game/t_13FEE0", func_00141CF0);

INCLUDE_ASM("asm/nonmatchings/game/t_13FEE0", func_00141DC8);
