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
int func_0013B608_4(void*, u32, void*, void*) __asm__("func_0013B608");
int func_0013DA80(void*);
int func_0013DCA8(void*, int);
int func_0013DD50(void*);
void func_0027C028(int, u32, int);
void func_0027C160(int, u32, int);
void func_0027D188(void*, int, int*, int);
int func_0013FC78_i(void*, char*, int) __asm__("func_0013FC78");
int func_0027DF00(void*, u32);
int func_00140558(void*, int, int, int);
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

struct S1402;

extern "C" {
void func_001CE868(void*, void*);
void func_001CE888(void*, void*);
void func_00139D50(S1402*, S13F_C*, int);
void func_00139840(S1402*, float, float);
void func_001395D8(S1402*, int, float, float);
void func_00140408(void*);
}

struct Ref1402 {
    S1402* p;
    int unk4;
    int unk8;
    Ref1402(S1402* x) {
        unk4 = 0;
        unk8 = 0;
        p = x;
        if (p) {
            func_001CE868(p, this);
        }
    }
    ~Ref1402() {
        if (p) {
            func_001CE888(p, this);
            p = 0;
        }
    }
    Ref1402& operator=(S1402* x) {
        if (p) {
            func_001CE888(p, this);
            p = 0;
        }
        p = x;
        if (p) {
            func_001CE868(p, this);
        }
        return *this;
    }
};

struct S1402 {
    char pad0[0x8];
    union { u64 q; u32 w[2]; } unk8;
    char pad10[0x68];
    S1402* unk78;
    char pad7C[8];
    S1402* unk84;
    char pad88[0x60];
    S13F_C unkE8;
    char padEC[0x104];
    float unk1F0;
    float unk1F4;
    char pad1F8[0x64];
    float unk25C;
    float unk260;
    float unk264;
    float unk268;
    float unk26C;
    int unk270;
};

extern "C" void func_00140270(S1402* self) {
    if (self->unk8.w[1] & 0x1000) {
        float y = (self->unk260 + 1.0f) * (self->unk1F4 - self->unk26C) * 0.5f;
        Ref1402 r(self->unk78);
        for (int i = 0; i < self->unk270; i++) {
            S13F_C c = self->unkE8;
            func_00139D50(r.p, &c, 1);
            func_00139840(r.p, self->unk25C, -1.0f);
            func_001395D8(r.p, 0, (self->unk25C + 1.0f) * self->unk1F0 * 0.5f, y);
            S1402* next = r.p->unk84;
            y += r.p->unk1F4 * self->unk264 * self->unk268;
            r = next;
        }
    }
    if (self->unk8.q & ((u64)0xC000 << 29)) {
        func_00140408(self);
    }
}

INCLUDE_ASM("asm/nonmatchings/game/t_13FEE0", func_00140408);

INCLUDE_ASM("asm/nonmatchings/game/t_13FEE0", func_00140558);

struct P_001406D8 { char pad0[0x20]; int unk20; };

extern "C" int func_001406D8(S13F_X* self, u32 key, void* a2, P_001406D8* a3) {
    int buf[1];
    switch (key) {
    case 0xAFE66453:
        func_0027D188(a2, 0, buf, 1);
        return func_0013DCA8(self, buf[0]);
    case 0xB3104E54:
        return func_0013DD50(self);
    case 0x7DAB7D15:
        if (self->unk240) {
            func_0027C028(a3->unk20, 0x61414D56, self->unk240);
        }
        return 1;
    case 0xE268510E: {
        int t = a3->unk20;
        func_0027C160(t, 0xFE82614D, func_0013DA80(self));
        return 1;
    }
    default:
        return func_0013B608_4(self, key, a2, a3);
    }
}

extern "C" int func_001407D8(S13F_X* self, u32 key, void* a2, P_001406D8* a3) {
    char buf[0x200];
    int val;
    switch (key) {
    case 0xAFE66453: {
        int v;
        func_0027D188(a2, 0, &val, 1);
        v = val;
        return func_00140558(self, v, func_0027DF00(a2, 0x27E7A420), func_0027DF00(a2, 0xB8C08F55));
    }
    case 0xB3104E54:
        return func_0013FEE0(self);
    case 0x7DAB7D15:
        if (func_0013FC78_i(self, buf, 0x200)) {
            func_0027C028(a3->unk20, 0x61414D56, (int)buf);
        }
        return 1;
    case 0xE268510E: {
        int t2 = a3->unk20;
        func_0027C160(t2, 0xFE82614D, func_0013FE00(self));
        return 1;
    }
    default:
        return func_0013B608_4(self, key, a2, a3);
    }
}

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


extern "C" int func_00141608(S_00141608* self);

struct VE_141 { s16 delta; s16 unk2; void* fn; };
struct VO_141 { char pad0[0x34]; VE_141* unk34; };
struct H_141 { VO_141* unk0; int unk4; int unk8; };
struct S_141 { char pad0[0xC]; u32 unkC; char pad10[0x1E0]; float unk1F0; float unk1F4; char pad1F8[0x48]; int unk240; int pad244; int unk248; };

extern "C" {
void func_0022B0D0(H_141*, int, int, int);
void func_00134340(H_141*);
void func_001342E8(H_141*, int);
void func_0015E190(int, int);
int func_001596E8(int);
int func_00159710(int);
void func_001397A8(S_141*, int, float, float);
void func_00139AE8(S_141*, int, int, float, float);
extern int D_0036F658;
void func_00141428_i(S_141* self, int a) __asm__("func_00141428");
}

void func_00141428_i(S_141* self, int a) {
    H_141 h;
    func_0022B0D0(&h, D_0036F658, a, 0);
    bool none = h.unk0 == 0;
    func_00134340(&h);
    if (none) {
        a = 0xE9CA7F30;
        self->unkC |= 0x400000;
    }
    self->unk240 = a;
    func_0022B0D0(&h, D_0036F658, a, 0);
    if (h.unk0 == 0) {
        H_141 h2;
        func_0022B0D0(&h2, D_0036F658, 0xE9CA7F30, 0);
        if (h2.unk0) func_001342E8(&h, (int)h2.unk0);
        func_00134340(&h2);
    }
    VO_141* o = h.unk0;
    func_0015E190(self->unk248, o ? ((int (*)(void*))o->unk34[2].fn)((char*)o + o->unk34[2].delta) : 0);
    if (self->unkC & 0x2000) {
        float x = self->unk1F0 / (float)func_001596E8(func_00141608((S_00141608*)self));
        func_00139AE8(self, 0, 0, x, self->unk1F4 / (float)func_00159710(func_00141608((S_00141608*)self)));
    }
    float w = (float)func_001596E8(func_00141608((S_00141608*)self));
    func_001397A8(self, 0, w, (float)func_00159710(func_00141608((S_00141608*)self)));
    self->unkC |= 0x1000;
    func_00134340(&h);
}

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
