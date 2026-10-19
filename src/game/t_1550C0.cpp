// cflags: -funroll-loops
#include "common.h"

struct S_001563B0 { char pad0[0x60]; int unk60; };

typedef unsigned int u128_155 __attribute__((mode(TI)));

struct E160_155 { u64 unk0; char pad8[0x158]; };
struct EB0_155 { char pad0[0x90]; int unk90; char pad94[4]; const char* unk98; int unk9C; char padA0[0x10]; };
struct VE_155 { s16 delta; s16 unk2; void* fn; };
struct O_155 { char pad0[0x20]; VE_155* unk20; };
struct S90_155 { char pad0[0x90]; int unk90; };
struct S20_155 { char pad0[0x14]; void* unk14; char pad18[8]; void* unk20; };
struct S60_155 { char pad0[0x60]; int unk60; };

extern "C" {
EB0_155* func_00156590_r(const char*, int) __asm__("func_00156590");
int func_0027D268(int, int, void*, int);
int func_002262A8(int);
int func_0027DF00(int, int);
void func_00156CB8(float, float, float, float);
void func_00156B60(void*);
extern int D_00368A38;
extern u32 D_00369BE0;
void* Heap_Alloc(int, int, int, int);
void* func_00156FD8(void*);
void func_00155788(void*);
void* func_00223BF0(void*);
void* func_001552F0_p(void*) __asm__("func_001552F0");
extern EB0_155 D_00378220[];
int func_001550C0(const char*);
void func_00154750(void*);
void func_001547C8(void*, int);
int func_001551A8_p(void*) __asm__("func_001551A8");
extern int D_00369BE8;
extern S60_155* D_0032A558[];
EB0_155* func_001566B8(const char*);
extern int D_00369BEC;
extern u8 D_0033CBF8[];
void Heap_Free(int, void*);
extern u128_155 D_00378210;
void func_001551A8(void);
void func_001561C8(int);
void func_00156878(int, int);
void* operator_new(u32 size);
void* func_00154670(void*);
int func_00154830(void*, int);
void func_001548F8(void*);
}

struct S_00156FA8 { char pad0[0x160]; };

GP_DATA(D_00369BEC);
extern "C" int func_001550C0(const char* name) {
    EB0_155* e = func_001566B8(name);
    if (e) {
        return e->unk90;
    }
    int i = D_00369BEC;
    D_00369BEC = i + 1;
    EB0_155* n = &D_00378220[i];
    n->unk9C = 2;
    n->unk90 = i;
    D_00378220[i].unk98 = name;
    return i;
}

extern "C" u128_155 func_00155128(void) {
    return D_00378210;
}

extern "C" void* func_00155138(void) {
    return func_00156FD8(Heap_Alloc(D_00368A38, 0x24, 1, 0));
}

extern "C" int func_00155170(O_155* obj) {
    if (obj) {
        VE_155* e = &obj->unk20[1];
        ((void (*)(void*, int))e->fn)((char*)obj + e->delta, 3);
    }
    return 1;
}

INCLUDE_ASM("asm/nonmatchings/game/t_1550C0", func_001551A8);

INCLUDE_ASM("asm/nonmatchings/game/t_1550C0", func_00155290);

INCLUDE_ASM("asm/nonmatchings/game/t_1550C0", func_001552E8);

extern "C" void func_001552F0(void) {
    func_001551A8();
}

INCLUDE_ASM("asm/nonmatchings/game/t_1550C0", func_00155310);

extern "C" void* func_00155640(void) {
    return func_00154670(operator_new(0x90));
}

extern "C" void* func_00155668(void* self) {
    func_00155788(self);
    return func_001552F0_p(func_00223BF0(self));
}

INCLUDE_ASM("asm/nonmatchings/game/t_1550C0", func_001556A0);

INCLUDE_ASM("asm/nonmatchings/game/t_1550C0", func_001556A8);

INCLUDE_ASM("asm/nonmatchings/game/t_1550C0", func_00155788);

INCLUDE_ASM("asm/nonmatchings/game/t_1550C0", func_00155D40);

INCLUDE_ASM("asm/nonmatchings/game/t_1550C0", func_001561C8);

extern "C" void func_001563B0(S_001563B0* self) {
    func_001561C8(self->unk60);
}

struct T_001563D0 { char pad0[0x40]; float unk40; char pad44[0x1C]; int unk60; };
struct S_001563D0 { char pad0[0x90]; int unk90; float unk94; };

GP_DATA(D_00369BE8);
struct B_001563D0 { char pad0[0x40]; float unk40; char pad44[0x1C]; int unk60; };

extern "C" void func_001563D0(EB0_155* self, float v) {
    int i;
    int n = D_00369BE8;
    *(float*)((char*)self + 0x94) = v;
    for (i = 0; i < n; i = i + 1, n = D_00369BE8) {
        B_001563D0* b = (B_001563D0*)D_0032A558[i];
        if (b && b->unk60 && func_00154830(b, self->unk90)) {
            B_001563D0* c = (B_001563D0*)D_0032A558[i];
            c->unk40 = v;
            func_001548F8(c);
        }
    }
}

struct B_00156470 { char pad0[0x34]; int unk34; char pad38[0x28]; int unk60; };

extern "C" void func_00156470(EB0_155* self, int on) {
    int i;
    if (on) {
        self->unk9C = self->unk9C | 2;
    } else {
        self->unk9C = self->unk9C & ~2;
    }
    for (i = 0; i < D_00369BE8; i++) {
        B_00156470* b = (B_00156470*)D_0032A558[i];
        if (b && b->unk60) {
            if (func_00154830(b, self->unk90)) {
                B_00156470* c = (B_00156470*)D_0032A558[i];
                if (on) {
                    c->unk34 = c->unk34 | 2;
                } else {
                    c->unk34 = c->unk34 & ~2;
                }
            }
        }
    }
}

extern "C" void func_00156550(S90_155* self, void* x) {
    func_00154750(x);
    func_001547C8(x, self->unk90);
}

extern "C" void func_00156590(const char* name, int v) {
    int i = func_001550C0(name);
    EB0_155* e = &D_00378220[i];
    e->unk9C = v;
}

extern "C" EB0_155* func_001565D0(int p) {
    const char* n = (const char*)func_00223BF0((void*)p);
    EB0_155* e = func_001566B8(n);
    if (!e) e = func_00156590_r(n, 0);
    float f = 100.0f;
    func_0027D268(p, 0x2689291C, &f, 0);
    f = f * 0.01f;
    *(float*)((char*)e + 0x94) = f;
    if (!func_002262A8(p)) e->unk9C &= ~2;
    if ((func_0027DF00(p, 0x17FA747C) ^ 1) != 0) e->unk9C &= ~1;
    return e;
}

INCLUDE_ASM("asm/nonmatchings/game/t_1550C0", func_001566B8);

INCLUDE_ASM("asm/nonmatchings/game/t_1550C0", func_00156790);

INCLUDE_ASM("asm/nonmatchings/game/t_1550C0", func_00156870);

static inline u128_155 MakeVec155(f32 x, f32 y, f32 z, f32 w) {
    u128_155 lo, hi;
    asm("pextlw %0, %1, %2" : "=r"(lo) : "r"(y), "r"(x));
    asm("pextlw %0, %1, %2" : "=r"(hi) : "r"(w), "r"(z));
    asm("pcpyld %0, %1, %2" : "=r"(lo) : "r"(hi), "0"(lo));
    return lo;
}

struct F9_155 { char pad0[0x90]; int unk90; float unk94; int unk98; int unk9C; char padA0[4]; char unkA4; char padA5[0xB]; };
extern "C" {
extern int D_00372B58;
extern u8 D_00372B60[];
void func_00154420(void*);
}

extern "C" void func_00156878(int a, int b) {
    if (b == 0xFFFF && a) {
        D_00378210 = MakeVec155(0.0f, 1.0f, 0.0f, 1.0f);
        F9_155* p = (F9_155*)D_00378220;
        for (int i = 0x7F; i != -1; i--, p++) {
            for (int j = 3; j != -1; j--) {
            }
            p->unk94 = 1.0f;
            p->unk9C = 0;
            p->unk98 = 0;
            p->unk90 = 0;
            p->unkA4 = 0;
        }
        D_00372B58 = 0x806FFF30;
        func_00154420(D_00372B60);
    }
}
TEXT_PAD(16);

INCLUDE_ASM("asm/nonmatchings/game/t_1550C0", func_00156978);

INCLUDE_ASM("asm/nonmatchings/game/t_1550C0", func_00156AB0);

extern "C" void func_00156B40(void) {
    func_00156878(1, 0xFFFF);
}

INCLUDE_ASM("asm/nonmatchings/game/t_1550C0", func_00156B60);

extern "C" void func_00156C88(float a, float b, float c) {
    func_00156CB8(0.0f, a, b, c);
}

struct S156CB8 { int unk0; float unk4; float unk8; float unkC; float unk10; float unk14; float unk18; float unk1C; char pad20[4]; float unk24; float unk28; };
extern "C" {
float func_002EC118(float);
float func_0031B118(float);
void func_00156CB8_m(S156CB8*, float, float, float, float) __asm__("func_00156CB8");
}

extern "C" void func_00156CB8_m(S156CB8* self, float a, float b, float c, float d) {
    if (d <= 0.0f) d = 0.01f;
    long flag = 1;
    if (a != 0.0f) flag = 0;
    float diff = b - a;
    float ad = __builtin_fabsf(diff);
    *(long*)self = (*(long*)self & ~8L) | (flag << 3);
    self->unk1C = c;
    self->unk14 = a;
    self->unk18 = b;
    self->unk24 = d;
    if (ad < 0.1f) self->unk28 = d;
    else self->unk28 = (d * b) / diff;
    float t = self->unk18 / self->unk28;
    if (t >= 0.0f) self->unk8 = 2.0f * func_0031B118(t);
    else self->unk8 = 0.0f;
    float u = t * self->unk1C;
    if (u >= 0.0f) self->unk4 = 2.0f * func_0031B118(u);
    else self->unk4 = 0.0f;
    self->unkC = func_002EC118(self->unk4 * 0.5f);
    self->unk10 = func_002EC118(self->unk8 * 0.5f);
}

INCLUDE_ASM("asm/nonmatchings/game/t_1550C0", func_00156DF8);

struct E_00156E00 { char pad0[0x160]; };

extern "C" E_00156E00* func_00156E00(E_00156E00* a) {
    int i;
    E_00156E00* p = a;
    for (i = 29; i != -1; i--) {
        func_00156B60(p);
        p++;
    }
    return a;
}

struct B_00156ED0 { u64 f0 : 1; u64 f1 : 63; };

extern "C" int func_00156ED0(char* p) {
    int n = 0;
    for (;;) {
        if (!((B_00156ED0*)(p + 0x0))->f0) {
            ((B_00156ED0*)(p + 0x0))->f0 = 1;
            return n + 1;
        }
        if (!((B_00156ED0*)(p + 0x160))->f0) {
            ((B_00156ED0*)(p + 0x160))->f0 = 1;
            return n + 2;
        }
        if (!((B_00156ED0*)(p + 0x2c0))->f0) {
            ((B_00156ED0*)(p + 0x2c0))->f0 = 1;
            return n + 3;
        }
        if (!((B_00156ED0*)(p + 0x420))->f0) {
            ((B_00156ED0*)(p + 0x420))->f0 = 1;
            return n + 4;
        }
        if (((B_00156ED0*)(p + 0x580))->f0) {
            n += 5;
            p += 0x6E0;
            if (n >= 0x1E) return 0;
            continue;
        }
        ((B_00156ED0*)(p + 0x580))->f0 = 1;
        return n + 5;
    }
}

INCLUDE_ASM("asm/nonmatchings/game/t_1550C0", func_00156F80);

extern "C" S_00156FA8* func_00156FA8(S_00156FA8* p, int n) {
    n--;
    return &p[n];
}
TEXT_PAD(12);

INCLUDE_ASM("asm/nonmatchings/game/t_1550C0", func_00156FC8);

struct S_00156FD8 { char pad0[4]; int unk4; float unk8; float unkC; float unk10; float* unk14; int unk18; int unk1C; void* unk20; };

extern "C" void* func_00156FD8(void* p) {
    S_00156FD8* self = (S_00156FD8*)p;
    u32 i;
    self->unk10 = 1.0f;
    self->unk20 = D_0033CBF8;
    self->unk8 = self->unkC = 0.0f;
    self->unk14 = (float*)Heap_Alloc(D_00368A38, D_00369BE0 * 4, 1, 0);
    for (i = 0; i < D_00369BE0; i++) {
        self->unk14[i] = 1.0f;
    }
    self->unk4 = 0;
    self->unk18 = 0;
    self->unk1C = 0;
    return self;
}

extern "C" void func_00157098(S20_155* self, int flags) {
    self->unk20 = D_0033CBF8;
    if (self->unk14) {
        Heap_Free(D_00368A38, self->unk14);
        self->unk14 = 0;
    }
    if (flags & 1) {
        Heap_Free(D_00368A38, self);
    }
}
