// cflags: -funroll-loops
#include "common.h"

typedef unsigned int u128_137 __attribute__((mode(TI)));


struct S137_N {
    char pad0[0x10];
    u128_137 unk10;
    char pad20[0x24];
    float unk44;
    char pad48[0x8];
};

struct S137_Y {
    char pad0[0xC];
    u32 unkC;
    char pad10[0x90];
    S137_N unkA0;
    S137_N unkF0;
    char pad140[0x10];
    u128_137 unk150;
    char pad160[0x24];
    float unk184;
};

struct S137_L { char pad0[0x4]; int unk4; char pad8[0x4]; float unkC; S137_L* unk10; };

struct S137_X {
    char pad0[0xC];
    u32 unkC;
    char pad10[0xE0];
    char unkF0[0x100];
    float unk1F0;
    float unk1F4;
};

struct S137_B { char unk0[0x38]; };

struct S137_M { char pad0[0x20]; float unk20; float unk24; float unk28; float unk2C; };

struct S137_R {
    char pad0[0x44];
    float unk44;
    char pad48[0xA8];
    S137_M unkF0;
};

struct S137_P { char pad0[0x20]; int unk20; float unk24; float unk28; float unk2C; };

struct S137_C { char pad0[0x4]; int unk4; S137_B unk8; };

struct S137_H { char pad0[0x1E0]; int unk1E0; };
struct S137_ColP { u8 r; u8 g; u8 b; u8 a; };
struct S137_Col {
    S137_ColP c;
    S137_Col(const S137_Col& o) : c(o.c) {}
};

struct S_00138958 { char pad0[0x4]; int unk4; };
struct S_00138960 { char pad0[0x4]; int unk4; };
struct S_00139580 { char pad0[0x1B8]; float unk1B8; };
struct S_00139588 { char pad0[0x1BC]; float unk1BC; };

struct S_001395C0 { char pad0[0x1E0]; float unk1E0; float unk1E4; };

struct S_001389F0 { char pad0[0x4560]; char unk4560; };

extern "C" {
void func_0013C550(void*, S137_N*);
void func_00137E30(S137_B*);
extern int D_003710A4[] __attribute__((section(".sdata")));
float func_0011ED20(void);
float func_0011ED10(void);

void func_00138B18(u128_137, u128_137, u128_137, float, float, int, int, int);
extern S137_B D_0032A520;
extern S137_B D_00377F80;
void func_00159260(void*, int, float, float, float);
void func_001389F0(S_001389F0*, void*);
extern u8 D_0033A928[];
float func_002EC118(float);
float func_002EC10C(void);
extern int D_003694D0;
void strcpy(char*, void*);
extern S137_H* D_00368A38;
void func_00119490(S137_H*, int);
void func_001194B8(S137_H*);
void func_00157738(void*, int, int);
void func_00138010(void*, S137_P*, int, S137_Col);
void func_00159768(void*, int, int);
void func_00157760(void*, int, int);
int func_001384B0(void*, S137_P*);
extern int D_00371298;
extern void* D_00371288[2];
void* func_0011C2A8(void*);
int func_00119610(S137_H*, int);
void* Heap_Alloc(S137_H*, u32, int, int);
}

struct A137 { int unk0; int unk4; void* unk8; };
extern "C" {
A137* func_002764E8(int);
int func_0027D1F8_a(void*, u32, int*, int) __asm__("func_0027D1F8");
}

static inline void* Get137(A137* a, int i) {
    if (a->unk4 == 1) return a->unk8;
    return ((void**)a->unk8)[i];
}

extern "C" void* func_00137C98(int key, int mode) {
    A137* a = func_002764E8(1);
    int n = a->unk4;
    if (mode == 0) {
        for (int i = 0; i < n; i++) {
            void* e = Get137(a, i);
            int v = -1;
            if (func_0027D1F8_a(e, 0x4B833E64, &v, 1) && v == key) return e;
        }
    }
    return 0;
}

extern "C" void func_00137E30(S137_B* dst) {
    *dst = D_0032A520;
}

extern "C" void func_00137EB0(S137_B* src) {
    D_00377F80 = *src;
}

extern "C" void func_00137F30(int v) {
    D_003694D0 = v;
}

GP_DATA(D_003694D0);
extern "C" int func_00137F38(void* self, S137_P* b, int c, int d, S137_Col color) {
    S137_H* heap = D_00368A38;
    func_00119490(heap, heap->unk1E0);
    func_00157738(self, 0, 0);
    func_001194B8(D_00368A38);
    func_00138010(self, b, d, color);
    func_001384B0(self, b);
    if (D_003694D0) {
        func_00159768(self, D_003694D0, c);
    }
    func_00157760(self, c, 0);
    return 1;
}

INCLUDE_ASM("asm/nonmatchings/game/t_137C98", func_00138010);

extern "C" int func_001384B0(void* self, S137_P* p) {
    if (p->unk20) {
        func_00159260(self, 0, p->unk24, p->unk28, p->unk2C);
        return 1;
    }
    return 0;
}

INCLUDE_ASM("asm/nonmatchings/game/t_137C98", func_001384F0);

INCLUDE_ASM("asm/nonmatchings/game/t_137C98", func_001384F8);

extern "C" void* func_00138790(u32 size) {
    void* pool = D_00371288[D_00371298];
    if (pool) {
        void* r = func_0011C2A8(pool);
        if (!r) {
            S137_H* heap = D_00368A38;
            func_00119490(heap, func_00119610(heap, 1));
            r = Heap_Alloc(D_00368A38, size, 1, 0);
            func_001194B8(D_00368A38);
        }
        return r;
    }
    return Heap_Alloc(D_00368A38, size, 1, 0);
}

extern "C" void func_00138850(int a, int b) {
    if (b == 0xFFFF && a) {
        D_00377F80 = D_0032A520;
    }
}

extern "C" void func_001388E8(void) {
    func_00138850(1, 0xFFFF);
}

extern "C" S137_C* func_00138908(S137_C* self) {
    self->unk4 = 0;
    func_00137E30(&self->unk8);
    func_001389F0((S_001389F0*)self, D_0033A928);
    return self;
}
TEXT_PAD(8);

INCLUDE_ASM("asm/nonmatchings/game/t_137C98", func_00138950);

extern "C" int func_00138958(S_00138958* self) {
    return self->unk4;
}

extern "C" void func_00138960(S_00138960* self, int v) {
    self->unk4 = v;
}

extern "C" char* func_00138968(char* p) {
    return p + 0x40;
}

extern "C" int func_00138970(void) {
    return 17696;
}

extern "C" S137_B* func_00138978(S137_B* dst, S137_C* src) {
    *dst = src->unk8;
    return dst;
}

extern "C" void func_001389F0(S_001389F0* self, void* a) {
    strcpy(&self->unk4560, a);
}

extern "C" char* func_00138A10(char* p) {
    return p + 0x4560;
}

INCLUDE_ASM("asm/nonmatchings/game/t_137C98", func_00138A18);

extern "C" void func_00138B00(void) {
}

INCLUDE_ASM("asm/nonmatchings/game/t_137C98", func_00138B08);

INCLUDE_ASM("asm/nonmatchings/game/t_137C98", func_00138B18);

extern "C" void func_00138D98(u128_137* a, u128_137* b, int c, int d, int e, float g) {
    func_00138B18(*a, b[0], b[1], g, g, c, d, e);
    func_00138B18(*a, b[1], b[2], g, g, c, d, e);
    func_00138B18(*a, b[0], b[2], g, g, c, d, e);
}

INCLUDE_ASM("asm/nonmatchings/game/t_137C98", func_00138E60);

extern "C" void func_00138E68(void) {
}

extern "C" void func_00138E70(void) {
}

INCLUDE_ASM("asm/nonmatchings/game/t_137C98", func_00138E78);

INCLUDE_ASM("asm/nonmatchings/game/t_137C98", func_00138F18);

INCLUDE_ASM("asm/nonmatchings/game/t_137C98", func_00138F20);

struct S137_Rf { int p; int unk4; int unk8; };
struct S137_D { char pad0[0x2C]; u32 unk2C; char pad30[0x3C]; S137_Rf r6C; S137_Rf r78; S137_Rf r84; S137_Rf r90; };
struct S137_T { int unk0; int unk4; int unk8; };

extern "C" {
void func_0013C280(void*, S137_T*, int);
void func_0013D1B8(void*, int);
void func_001CE888(int, void*);

void func_001CE990(void*, int);
extern char D_0033AC10[];
}

extern "C" void func_00139420(S137_D* self, int flags) {
    S137_T t;
    *(char**)((char*)self + 8) = D_0033AC10;
    t.unk4 = 0;
    t.unk8 = 0;
    t.unk0 = 0;
    func_0013C280(self, &t, 0);
    if (t.unk0) {
        func_001CE888(t.unk0, &t);
        t.unk0 = 0;
    }
    self->unk2C = 0xDEADBEEF;
    func_0013D1B8((char*)self + 0x210, 2);
    S137_Rf* q;
    q = &self->r90;
    if (q->p) { func_001CE888(q->p, q); q->p = 0; }
    q = &self->r84;
    if (q->p) { func_001CE888(q->p, q); q->p = 0; }
    q = &self->r78;
    if (q->p) { func_001CE888(q->p, q); q->p = 0; }
    q = &self->r6C;
    if (q->p) { func_001CE888(q->p, q); q->p = 0; }
    func_001CE990(self, flags);
}

extern "C" void func_00139510(S137_R* self, float* x, float* y) {
    float s = func_002EC118(self->unk44);
    float c = func_002EC10C();
    float t = *x;
    *x = t * s - *y * c;
    *y = t * c + *y * s;
}

extern "C" float func_00139580(S_00139580* self) {
    return self->unk1B8;
}

extern "C" float func_00139588(S_00139588* self) {
    return self->unk1BC;
}

extern "C" void func_00139590(S137_R* self, float* a, float* b) {
    S137_M* m = &self->unkF0;
    *a = m->unk20;
    *b = m->unk24;
}

extern "C" void func_001395A8(S137_R* self, float* a, float* b) {
    S137_M* m = &self->unkF0;
    *a = m->unk28;
    *b = m->unk2C;
}

extern "C" void func_001395C0(S_001395C0* self, float* a, float* b) {
    *a = self->unk1E0;
    *b = self->unk1E4;
}

struct S1395D8 {
    char pad0[0xC];
    u32 unkC;
    char pad10[0x90];
    S137_M unkA0;
    char pad_[0x50 - sizeof(S137_M)];
    S137_M unkF0;
    char pad__[0x50 - sizeof(S137_M)];
    S137_M unk140;
};

INCLUDE_ASM("asm/nonmatchings/game/t_137C98", func_001395D8);

INCLUDE_ASM("asm/nonmatchings/game/t_137C98", func_001396D0);

extern "C" void func_001397A8(S137_X* self, float a, float b, int flag) {
    if (self->unk1F0 != a || self->unk1F4 != b) {
        self->unk1F0 = a;
        self->unk1F4 = b;
        self->unkC |= 0x400;
        func_0013C550(self, (S137_N*)self->unkF0);
    }
    if (flag) {
        self->unkC |= 0x2000;
    } else {
        self->unkC &= ~0x2000;
    }
}

INCLUDE_ASM("asm/nonmatchings/game/t_137C98", func_00139840);

struct Q139 { char pad0[0x30]; s16 s30; s16 s32; };
struct O139 { char pad0[0xC]; u32 unkC; };

extern "C" void func_00139960(char* self, int flag, float x, float y) {
    Q139* p0 = (Q139*)(self + 0xF0);
    if ((float)p0->s30 * 0.001f != x || (float)p0->s32 * 0.001f != y) {
        Q139* p1 = (Q139*)(self + 0xA0);
        Q139* p2 = (Q139*)(self + 0x140);
        int xi = (int)(x * 1000.0f);
        int yi = (int)(y * 1000.0f);
        float b = (float)p1->s30 * 0.001f * 1000.0f;
        float a = (float)p1->s32 * 0.001f * 1000.0f;
        p2->s32 = (int)a;
        p2->s30 = (int)b;
        p0->s30 = xi;
        p0->s32 = yi;
        ((O139*)self)->unkC |= 0x400;
    }
    if (flag) {
        Q139* p1 = (Q139*)(self + 0xA0);
        if ((float)p1->s30 * 0.001f != x || (float)p1->s32 * 0.001f != y) {
            Q139* p2 = (Q139*)(self + 0x140);
            int xi = (int)(x * 1000.0f);
            int yi = (int)(y * 1000.0f);
            p1->s32 = yi;
            p1->s30 = xi;
            p2->s30 = xi;
            p2->s32 = yi;
            ((O139*)self)->unkC |= 0x400;
        }
    }
}

INCLUDE_ASM("asm/nonmatchings/game/t_137C98", func_00139AE8);

extern "C" void func_00139C18(S137_Y* self, int add, int both, float ang) {
    float r;
    S137_N* m;
    if (add) {
        ang += self->unkF0.unk44 * 57.2957763671875f;
    }
    r = ang * 0.01745329424738884f;
    m = &self->unkF0;
    if (m->unk44 != r) {
        self->unk184 = self->unkA0.unk44;
        m->unk44 = r;
        func_0013C550(self, m);
        self->unkC |= 0x400;
    }
    if (both) {
        S137_N* n = &self->unkA0;
        if (n->unk44 != r) {
            n->unk44 = r;
            self->unk184 = r;
            self->unkC |= 0x400;
        }
    }
}
