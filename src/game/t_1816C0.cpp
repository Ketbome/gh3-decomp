// cflags: -funroll-loops
#include "common.h"

typedef unsigned int u128_181 __attribute__((mode(TI)));
struct M2_181 { u128_181 a; u128_181 b; };
struct VE_181 { s16 delta; s16 unk2; void* fn; };
struct V_181 { VE_181* vt; };
struct S_001821E0 { char pad0[0x414]; VE_181* unk414; };
struct S_00182180 { char pad0[0x18]; VE_181* unk18; };
struct S_001822A8 { char pad0[0xBC]; VE_181* unkBC; };
struct S_00182338 { char pad0[0x10]; VE_181* unk10; };
struct S_001823A8 { char pad0[0x1C]; VE_181* unk1C; };

extern "C" {
int func_0010C050(int);
int func_00116660(void*);
int func_003000E0(void*);
void func_00320A78(void*);
void memset(void*, int, int);
void func_0030B550(char*, const char*, ...);
char* func_00116E90();
void func_001575C0(int, char*, int, int);
extern char D_00343970[];
extern char D_0036B4B8[];
void func_0018AD80(void*, int, int, int, int, int, int);
void* operator_new(u32);
void func_0014E988(int);
extern void* D_00372BB8;
extern int D_00372BBC;
void func_001A8198(void);
void func_0019EE38(int, int, int, int);
extern int D_0036C378;
float func_0015DCB8(void);
void func_0011ED68(void);
void func_001A8168(void);
void func_001A84E0(void);
void func_0014F750(int, int);
extern int D_00368A38[] __attribute__((section(".sdata")));
void* Heap_Alloc(int, int, int, int);
void* func_00188D00(void*, int);
extern int D_0036CA4C[] __attribute__((section(".sdata")));
void func_0019ED90(void);
void func_001A8758(char*, char*, char*, char*, int);
extern int D_0036876C[] __attribute__((section(".sdata")));
void func_001A8120(int);
void func_001818F8(M2_181*, u128_181*, u128_181*);
extern int D_0036CA40;
extern u8 D_0036B460[];
extern u8 D_0037DBD0[];
void func_0019EC10(void);
void func_001A8810(void);
void func_001A88E8(void);
void func_001B9C60(void);
void func_0019ECE8(void);
void func_001C3DF0(void);
void func_001B4A88(void);
void func_001B4A90(void);
int func_00182870(int, int);
int func_0016E728(int);
}

INCLUDE_ASM("asm/nonmatchings/game/t_1816C0", func_001816C0);

struct I_1817 { char pad0[0x28]; float f28; float f2C; float f30; };
struct N_1817 { char pad0[4]; N_1817* next; char pad8[8]; I_1817 in; char pad4C[0]; };
struct O_1817 { char pad0[0x24]; N_1817* head; };

extern "C" void func_001817F8(O_1817* o, int n, float a, float b) {
    struct { int x; N_1817* q; } it;
    it.q = o->head;
    for (unsigned i = 0; i < (unsigned)n; i++) it.q = it.q->next;
    if (b == 0.0f) {
        I_1817* t = &it.q->in;
        t->f2C = a;
        t->f28 = a;
        *(float*)((char*)it.q + 0x40) = 0.0f;
    } else {
        I_1817* t = &it.q->in;
        t->f30 = (a - t->f28) / b;
        *(float*)((char*)it.q + 0x44) = a;
    }
}

extern "C" void func_001818F8(M2_181* d, u128_181* a, u128_181* b) {
    d->a = *a;
    d->b = *b;
}

extern "C" M2_181* func_00181910(M2_181* d, u128_181* a, u128_181* b) {
    func_001818F8(d, a, b);
    return d;
}

INCLUDE_ASM("asm/nonmatchings/game/t_1816C0", func_00181938);

INCLUDE_ASM("asm/nonmatchings/game/t_1816C0", func_00181BB0);

INCLUDE_ASM("asm/nonmatchings/game/t_1816C0", func_00181BD8);

extern "C" void func_00181C38(void) {
    func_0019EC10();
}

extern "C" void func_00181C58(void) {
    if (D_0036CA4C[0]) func_0019ED90();
}

INCLUDE_ASM("asm/nonmatchings/game/t_1816C0", func_00181C80);

INCLUDE_ASM("asm/nonmatchings/game/t_1816C0", func_00181ED8);

struct S181EE0 { char pad0[0xC]; u32 unkC; };

extern "C" {
S181EE0* func_00189E90(void*);
void func_0018A078(S181EE0*, int, int);
int func_001AD4C8(int, int, int, int*);
int func_00187F48(int);
}

extern "C" S181EE0* func_00181EE0(int a0, int a1, int a2, int a3, int a4) {
    S181EE0* o = func_00189E90(Heap_Alloc(D_00368A38[0], 0xB0, 1, 0));
    if (a2) {
        o->unkC |= 1;
    } else {
        o->unkC &= ~1;
    }
    if (a3) {
        o->unkC |= 2;
    } else {
        o->unkC &= ~2;
    }
    if (a4) {
        o->unkC |= 0x40;
    } else {
        o->unkC &= ~0x40;
    }
    o->unkC &= ~0x20;
    int out;
    int g = func_00187F48(a1);
    int t = a4 == 0;
    func_0018A078(o, func_001AD4C8(a0, g, a3 ? (t | 2) : t, &out), out);
    return o;
}

INCLUDE_ASM("asm/nonmatchings/game/t_1816C0", func_00182020);

INCLUDE_ASM("asm/nonmatchings/game/t_1816C0", func_00182078);

struct VE_1820D0 { s16 unk0; s16 unk2; void (*unk4)(void*, int); };
struct V_1820D0 { char pad0[8]; VE_1820D0 unk8; };
struct S_1820D0 { char pad0[0x58]; V_1820D0* unk58; };

extern "C" int func_001820D0(S_1820D0* self) {
    if (!self) return 0;
    V_1820D0* v = self->unk58;
    v->unk8.unk4((char*)self + v->unk8.unk0, 3);
    return 1;
}

INCLUDE_ASM("asm/nonmatchings/game/t_1816C0", func_00182110);

extern "C" int func_00182180(S_00182180* p) {
    if (p) {
        VE_181* e = &p->unk18[1];
        ((void (*)(void*, int))e->fn)((char*)p + e->delta, 3);
    }
    return 1;
}

extern "C" int func_001821B8(void) {
    int r0 = func_00182870(1048, 1);
    return func_0016E728(r0);
}

extern "C" void func_001821E0(S_001821E0* p) {
    if (p) {
        VE_181* e = &p->unk414[1];
        ((void (*)(void*, int))e->fn)((char*)p + e->delta, 3);
    }
}

INCLUDE_ASM("asm/nonmatchings/game/t_1816C0", func_00182218);

extern "C" void func_00182220(int u, int a, int b, int c, int d, int e, int g) {
    func_0018AD80(operator_new(0xE0), a, b, c, d, e, g);
}

extern "C" int func_001822A8(S_001822A8* p) {
    if (p) {
        VE_181* e = &p->unkBC[1];
        ((void (*)(void*, int))e->fn)((char*)p + e->delta, 3);
    }
    return 1;
}

extern "C" void func_001822E0(void) {
}

INCLUDE_ASM("asm/nonmatchings/game/t_1816C0", func_001822E8);

INCLUDE_ASM("asm/nonmatchings/game/t_1816C0", func_001822F0);

extern "C" int func_00182338(S_00182338* p) {
    if (p) {
        VE_181* e = &p->unk10[1];
        ((void (*)(void*, int))e->fn)((char*)p + e->delta, 3);
    }
    return 1;
}

extern "C" void* func_00182370(void) {
    return func_00188D00(Heap_Alloc(D_00368A38[0], 0x24, 1, 0), 0);
}

extern "C" int func_001823A8(S_001823A8* p) {
    if (p) {
        VE_181* e = &p->unk1C[1];
        ((void (*)(void*, int))e->fn)((char*)p + e->delta, 3);
    }
    return 1;
}

INCLUDE_ASM("asm/nonmatchings/game/t_1816C0", func_001823E0);

extern "C" void func_001823F0(int n, char* m, int c) {
    if (n == 4) func_001A8758(m, m + 0x10, m + 0x20, m + 0x30, c);
}

extern "C" void func_00182428(void) {
    func_001A8810();
}

extern "C" void func_00182448(void) {
    func_001A88E8();
}

extern "C" void func_00182468(void) {
    func_001B9C60();
}

extern "C" void* func_00182488(void) {
    return D_0036B460;
}

extern "C" void func_00182498(void) {
    func_0019ECE8();
}

extern "C" u8 BcdToInt(u32 v) {
    return (v >> 4) * 10 + (v & 0xF);
}

struct S_001824D8 { int unk0; int unk4; int unk8; int unkC; int unk10; int unk14; int unk18; int unk1C; };

extern "C" void func_001824D8(S_001824D8* self) {
    u8 b[8];
    func_003000E0(b);
    int ok = b[0];
    if (ok) {
        self->unk14 = func_0010C050(0x1C) & 0xFF;
        self->unkC = func_0010C050(0xC) & 0xFF;
        self->unk4 = 0x802;
        self->unk18 = func_0010C050(0x18) & 0xFF;
        self->unk0 = func_0010C050(0x3C) & 0xFF;
        self->unk8 = func_0010C050(0x3C) & 0xFF;
        self->unk1C = func_0010C050(0x3E8);
    } else {
        func_00320A78(b);
        self->unk14 = BcdToInt(b[5]);
        self->unkC = BcdToInt(b[6]);
        self->unk4 = BcdToInt(b[7]) + 0x7D0;
        self->unk18 = BcdToInt(b[3]);
        self->unk0 = BcdToInt(b[2]);
        self->unk8 = BcdToInt(b[1]);
        self->unk1C = func_0010C050(0x3E8);
    }
    self->unk10 = func_00116660(self);
}

struct N_001825E0 { char pad0[4]; u32 unk4; char pad8[4]; N_001825E0* unkC; };
struct T_001825E0 { char pad0[4]; int unk4; int unk8; int unkC; int unk10; int unk14; };
extern "C" {
int func_001287F0(int, int);
int func_0027AA70(int);
N_001825E0* func_0014E948(void);
int func_0018A070(int);
void func_001AD168(int, void*);
void func_0027C160(int, u32, int);
void func_0027C1F8(int, u32, float);
void func_0027C898(int, u32, int);
void Heap_Free(int, void*);
}
extern "C" void func_001825E0(int a) {
    int h = func_0027AA70(func_001287F0(8, 1));
    T_001825E0* t = (T_001825E0*)operator_new(0x18);
    func_0027C160(h, 0xD55CD658, 1);
    N_001825E0* n = func_0014E948();
    if (n) {
        do {
            N_001825E0* c = n->unkC;
            N_001825E0* next = c->unk4 == 0xFFFFFFFF ? 0 : c;
            func_001AD168(func_0018A070(n->unk4), t);
            func_0027C160(h, 0xD55CD658, 0);
            n = next;
        } while (n);
    }
    func_0027C160(h, 0x3DD01EA1, t->unk4);
    func_0027C160(h, 0x3960FF18, t->unk8);
    func_0027C160(h, 0x4DE5330C, t->unkC);
    func_0027C160(h, 0x94927839, t->unk10);
    func_0027C160(h, 0x169EE151, t->unk14);
    func_0027C1F8(h, 0x58785E10, (float)t->unk10 / (float)t->unk14);
    func_0027C1F8(h, 0x3B75D7CC, (float)t->unk14 / (float)t->unkC);
    func_0027C1F8(h, 0xBC56249D, (float)t->unk14 / (float)t->unk8);
    func_0027C898(a, 0x26861025, h);
    Heap_Free(D_00368A38[0], t);
}

extern "C" void func_00182798(int v) {
    D_0036CA40 = v;
}

extern "C" int func_001827A0(void) {
    return 640;
}

extern "C" int func_001827A8(void) {
    return 448;
}

extern "C" void func_001827B0(void) {
    func_001C3DF0();
}

extern "C" void func_001827D0(void) {
    func_001B4A88();
}

extern "C" void func_001827F0(void) {
    func_001B4A90();
}

INCLUDE_ASM("asm/nonmatchings/game/t_1816C0", func_00182810);

extern "C" int func_00182818(void) {
    return 640;
}

extern "C" int func_00182820(void) {
    return 448;
}

extern "C" int func_00182828(void) {
    return func_0015DCB8() > 1.7f;
}

INCLUDE_ASM("asm/nonmatchings/game/t_1816C0", func_00182868);

struct Pool_func_00182870 { int unk0; };
extern "C" {
extern Pool_func_00182870* D_0036A790[2];
extern int D_0036A7A0;
int func_0011C2A8(Pool_func_00182870*);
int func_00119610(int, int);
void func_00119490(int, int);
void func_001194B8(int);
}

extern "C" int func_00182870(int size, int unused) {
    Pool_func_00182870* pool = D_0036A790[D_0036A7A0];
    if (pool) {
        int r = func_0011C2A8(pool);
        if (!r) {
            int heap = D_00368A38[0];
            func_00119490(heap, func_00119610(heap, 1));
            r = (int)Heap_Alloc(D_00368A38[0], size, 1, 0);
            func_001194B8(D_00368A38[0]);
        }
        return r;
    }
    return (int)Heap_Alloc(D_00368A38[0], size, 1, 0);
}

extern "C" void* func_00182930(void) {
    return D_0037DBD0;
}

INCLUDE_ASM("asm/nonmatchings/game/t_1816C0", func_00182940);

INCLUDE_ASM("asm/nonmatchings/game/t_1816C0", func_00182DA8);

INCLUDE_ASM("asm/nonmatchings/game/t_1816C0", func_00182DB0);

INCLUDE_ASM("asm/nonmatchings/game/t_1816C0", func_00182E50);

extern "C" void func_00183460(float x) {
    func_001A8120((int)(x * (float)D_0036876C[0]));
}

extern "C" void func_00183498(void) {
    func_001A8198();
    if (D_0036C378 >= 0) {
        func_0019EE38(1, 0, 0, 0);
        D_0036C378 = -1;
    }
}

extern "C" void func_001834E0(void) {
    func_0011ED68();
    func_001A8168();
    func_001A84E0();
    func_0014F750(1, 0x48A06AC3);
}

INCLUDE_ASM("asm/nonmatchings/game/t_1816C0", func_00183520);

struct VE_183678 { s16 unk0; s16 unk2; void (*unk4)(void*, int); };
struct V_183678 { char pad0[8]; VE_183678 unk8; };
struct O_183678 { char pad0[8]; V_183678* unk8; };

extern "C" void func_00183678(void) {
    if (D_00372BBC) {
        func_0014E988(D_00372BBC);
        D_00372BBC = 0;
    }
    if (D_00372BB8) {
        V_183678* v = ((O_183678*)D_00372BB8)->unk8;
        v->unk8.unk4((char*)D_00372BB8 + v->unk8.unk0, 3);
        D_00372BB8 = 0;
    }
    func_001A8168();
    func_001A84E0();
}
