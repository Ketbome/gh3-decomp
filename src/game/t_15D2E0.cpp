// cflags: -funroll-loops
#include "common.h"

struct VEntry {
    s16 delta;
    s16 unk2;
    void* fn;
};

struct S0015E168 {
    char pad[0x10];
    VEntry* unk10;
};

struct S0015EF48 {
    char pad[0x18];
    VEntry* unk18;
};

struct S0015E600 {
    char pad0[0xC];
    int unkC;
    VEntry* unk10;
};

struct S0015EA48 {
    char pad0[0x14];
    int unk14;
    char pad18[0x4];
    VEntry* unk1C;
};

struct S0015EB00 {
    char pad0[0x8];
    int unk8;
    char padC[0x10];
    VEntry* unk1C;
};

struct S0015EB60 {
    char pad0[0x4];
    int unk4;
    char pad8[0x14];
    VEntry* unk1C;
};

struct S0015E408 {
    char pad0[0x4];
    float unk4;
    float unk8;
    char padC[0x4];
    VEntry* unk10;
};

struct S0015EB30 {
    char pad0[0xC];
    float unkC;
    int unk10;
    char pad14[0x8];
    VEntry* unk1C;
};

struct S0015ECB8 {
    s8 unk0;
    s8 unk1;
    s8 unk2;
    s8 unk3;
};

struct S0015EFC0 {
    char pad0[0x8];
    int unk8;
    int unkC;
    int unk10;
    s8 unk14;
    char pad15[0x3];
    void* unk18;
};

struct R_0015D5A0 { char pad0[0x34]; int unk34; };

struct N_0015DDB8 { N_0015DDB8* unk0; N_0015DDB8* unk4; };
struct L_0015DDB8 { int unk0; N_0015DDB8 unk4; };
struct S_0015DDE8 { int unk0; L_0015DDB8 unk4; L_0015DDB8 unk10; };
struct S_0015E0F8 { int unk0; float unk4; float unk8; int unkC; void* unk10; };
struct CP_0015E5C0 { u8 r; u8 g; u8 b; u8 a; };
struct C_0015E5C0 {
    CP_0015E5C0 c;
    C_0015E5C0(const C_0015E5C0& o) : c(o.c) {}
    C_0015E5C0& operator=(const C_0015E5C0& o) { *(u32*)this = *(const u32*)&o; return *this; }
};

typedef unsigned int u128_15D __attribute__((mode(TI)));
struct M2_15D { u128_15D a; u128_15D b; };
struct S_0015EA78 { int unk0; int unk4; int unk8; int unkC; int unk10; int unk14; u8 unk18[4]; void* unk1C; };
struct S_0015EB90 { char pad0[0x18]; C_0015E5C0 unk18; VEntry* unk1C; };
struct T_0015F110 { char pad0[8]; int unk8; char padC[4]; int unk10; };

struct T_0015DC18 { char pad0[0x34]; void* unk34; };

struct T_0015F070 { char pad0[8]; int unk8; int unkC; int unk10; };


extern "C" {
int func_001596E8(void*);
int func_00159710(void*);
int func_00276600(u32, int);
void func_00123040(T_0015DC18*);
void func_001CE888(void*, void**);
void func_001CE868(void*, void**);
extern char D_0033D420[];
extern int D_00372B98;
extern M2_15D D_0037DB00;
void func_0010F690(void*);
void func_001342B0(void*);
extern L_0015DDB8 D_0037DAF0;
extern char D_0033D4B0[];
extern char D_0033D480[];
int func_0015C0F8(int, int**);
int func_0015C178(int, int**);
extern int D_00368A38[] __attribute__((section(".sdata")));
void* Heap_Alloc(int, int, int, int);
void* func_0015EA78(void*, int);
void func_0011A470(void*);
void Heap_Free(int, void*);
extern int D_00369E68;
extern int D_0036CA30[] __attribute__((section(".sdata")));
extern float D_00369EC0;
extern float D_00369EB8;
R_0015D5A0* func_0015D570(int);
extern int D_00372B9C;
extern int D_00372BA0;
extern int D_00372BA4;
extern char D_0037DB20[];
extern char D_0037DB30[];
extern char D_0037DB70[];
extern int D_00372B90;
extern float D_00373264;
extern float D_00369E50;
extern float D_00369E54;
extern float D_00369EBC;
extern float D_00369EC4;
int func_0015D2E8(int, int);
void func_00189E38(void);
void func_0015DDB8(int, int);
extern u8 D_0033D750[];
void func_0015F038(S0015E168*);
void func_0015D5E8(int, int, int, int);
}

extern "C" void func_0015D2E0(void) {
}

extern "C" int func_0015D2E8(int a, int) {
    int* p;
    if (func_0015C0F8(a, &p)) return *p;
    return 0;
}

GP_DATA(D_00369E68);
extern "C" int func_0015D318(void) {
    int i;
    for (i = 0; i < 16; i++) {
        int bit = 1 << i;
        if (!(D_00369E68 & bit)) {
            D_00369E68 |= bit;
            return bit;
        }
    }
    return 0;
}

extern "C" void func_0015D3F0(int m) {
    D_00369E68 &= ~m;
}

INCLUDE_ASM("asm/nonmatchings/game/t_15D2E0", func_0015D408);

INCLUDE_ASM("asm/nonmatchings/game/t_15D2E0", func_0015D560);

extern "C" int func_0015D568(void) {
    return 0;
}

extern "C" R_0015D5A0* func_0015D570(int a) {
    int* p;
    if (func_0015C178(a, &p)) return (R_0015D5A0*)*p;
    return 0;
}

extern "C" int func_0015D5A0(int a) {
    return func_0015D570(a)->unk34;
}

extern "C" void func_0015D5C0(int a0, int a1) {
    func_0015D5E8(1, a0, a1, 0);
}

INCLUDE_ASM("asm/nonmatchings/game/t_15D2E0", func_0015D5E8);

INCLUDE_ASM("asm/nonmatchings/game/t_15D2E0", func_0015D6F0);

INCLUDE_ASM("asm/nonmatchings/game/t_15D2E0", func_0015D750);

extern "C" int func_0015D7F0(void) {
    return D_00372B90;
}

INCLUDE_ASM("asm/nonmatchings/game/t_15D2E0", func_0015D7F8);

extern "C" void func_0015DB00(int a0) {
    func_0015D2E8(a0, 0);
}

INCLUDE_ASM("asm/nonmatchings/game/t_15D2E0", func_0015DB20);

INCLUDE_ASM("asm/nonmatchings/game/t_15D2E0", func_0015DB90);

extern "C" int func_0015DBF0(int a) {
    R_0015D5A0* p = (R_0015D5A0*)func_0015D2E8(a, 1);
    if (p) return p->unk34;
    return 0;
}

extern "C" void func_0015DC18(int key, void* v) {
    T_0015DC18* t = (T_0015DC18*)func_0015D2E8(key, 1);
    if (t) {
        func_00123040(t);
        void** r = &t->unk34;
        if (*r) {
            func_001CE888(*r, r);
            *r = 0;
        }
        *r = v;
        if (v) func_001CE868(v, r);
    }
}

extern "C" void func_0015DC90(void) {
    func_00189E38();
}

extern "C" void func_0015DCB0(float v) {
    D_00373264 = v;
}

extern "C" float func_0015DCB8(void) {
    return D_00373264;
}

extern "C" void func_0015DCC0(float v) {
    D_00369E50 = v;
}

extern "C" float func_0015DCC8(void) {
    return D_00369E50;
}

extern "C" {
int func_0015D6F0(void);
float func_0031B5C8(float);
void func_001234B0(void*);
}
extern float D_00373268;

GP_DATA(D_00369E50);
extern "C" void func_0015DCD0(float v) {
    if (v == 0.0f) v = D_00369E50;
    int i = 0;
    D_00373268 = v;
    float t = func_0031B5C8(v * 0.5f * 0.017453294f);
    D_00369E54 = t / func_0031B5C8(D_00369E50 * 0.5f * 0.017453294f);
    while (i < func_0015D6F0()) {
        R_0015D5A0* o = func_0015D570(i); i++; if (o) { if (o->unk34) func_001234B0((void*)o->unk34); }
    }
}

extern "C" float func_0015DDA8(void) {
    return D_00369E54;
}

INCLUDE_ASM("asm/nonmatchings/game/t_15D2E0", func_0015DDB0);

extern "C" void func_0015DDB8(int init, int prio) {
    if (prio == 0xFFFF && init) {
        L_0015DDB8* l = &D_0037DAF0;
        l->unk4.unk0 = &l->unk4;
        l->unk4.unk0->unk4 = &l->unk4;
    }
}

static inline void L_0015DDB8_Clear(L_0015DDB8* l) {
    N_0015DDB8* n = l->unk4.unk4;
    l->unk4.unk4 = &l->unk4;
    l->unk4.unk0 = &l->unk4;
    while (n != &l->unk4) {
        N_0015DDB8* next = n->unk4;
        Heap_Free(D_00368A38[0], n);
        n = next;
    }
}

extern "C" void func_0015DDE8(S_0015DDE8* self, int flags) {
    L_0015DDB8_Clear(&self->unk10);
    L_0015DDB8_Clear(&self->unk4);
    if (flags & 1) {
        Heap_Free(D_00368A38[0], self);
    }
}

INCLUDE_ASM("asm/nonmatchings/game/t_15D2E0", func_0015DEB0);

extern "C" void func_0015E088(void) {
    func_0015DDB8(1, 65535);
}

extern "C" float func_0015E0A8(void) {
    float r = 0.5f;
    if (D_0036CA30[0] == 0) r = D_00369EB8;
    return r;
}

extern "C" float func_0015E0C8(void) {
    return D_00369EBC;
}

extern "C" float func_0015E0D0(void) {
    float r = 0.0f;
    if (D_0036CA30[0] == 0) r = D_00369EC0;
    return r;
}

extern "C" float func_0015E0F0(void) {
    return D_00369EC4;
}

INCLUDE_ASM("asm/nonmatchings/game/t_15D2E0", func_0015E0F8);

extern "C" void func_0015E128(S_0015E0F8* self, int flag) {
    self->unk10 = D_0033D4B0;
    if (flag & 1) Heap_Free(D_00368A38[0], self);
}

extern "C" void func_0015E168(S0015E168* self, int a1) {
    VEntry* e = &self->unk10[3];
    ((void (*)(void*, int))e->fn)((char*)self + e->delta, a1);
}

extern "C" void func_0015E190(S0015E168* self, void* a) {
    *(void**)self = a;
    if (a) {
        VEntry* e = &self->unk10[28];
        ((void (*)(void*, int, int))e->fn)((char*)self + e->delta, func_001596E8(a), func_00159710(a));
    }
    VEntry* f = &self->unk10[9];
    ((void (*)(void*))f->fn)((char*)self + f->delta);
}

extern "C" void func_0015E228(S0015E168* self, int a1) {
    VEntry* e = &self->unk10[34];
    ((void (*)(void*, int))e->fn)((char*)self + e->delta, a1);
}

extern "C" void func_0015E250(S0015E168* self) {
    VEntry* e = &self->unk10[15];
    ((void (*)(void*))e->fn)((char*)self + e->delta);
}

extern "C" void func_0015E278(S0015E168* self, u16 a1, u16 a2) {
    VEntry* e = &self->unk10[28];
    ((void (*)(void*, u16, u16))e->fn)((char*)self + e->delta, a1, a2);
}

extern "C" void func_0015E2A8(S0015E168* self, int a1) {
    VEntry* e = &self->unk10[14];
    ((void (*)(void*, int))e->fn)((char*)self + e->delta, a1);
}

INCLUDE_ASM("asm/nonmatchings/game/t_15D2E0", func_0015E2D0);

extern "C" void func_0015E3E0(S0015E168* self, int a1, int a2) {
    VEntry* e = &self->unk10[31];
    ((void (*)(void*, int, int))e->fn)((char*)self + e->delta, a1, a2);
}

extern "C" void func_0015E408(S0015E408* self, float f0, float f1) {
    self->unk4 = f0;
    self->unk8 = f1;
    VEntry* e = &self->unk10[9];
    ((void (*)(void*, float, float))e->fn)((char*)self + e->delta, f0, f1);
}

extern "C" void func_0015E438(S0015E168* self) {
    VEntry* e = &self->unk10[21];
    ((void (*)(void*))e->fn)((char*)self + e->delta);
}

extern "C" void func_0015E460(S0015E168* self, float x) {
    VEntry* e = &self->unk10[5];
    ((void (*)(void*, int))e->fn)((char*)self + e->delta, 0);
    VEntry* f = &self->unk10[10];
    VEntry* g = &self->unk10[12];
    ((void (*)(void*, int, float))f->fn)((char*)self + f->delta, ((int (*)(void*))g->fn)((char*)self + g->delta), x);
}

extern "C" void func_0015E4E8(S0015E168* self) {
    VEntry* e = &self->unk10[23];
    ((void (*)(void*))e->fn)((char*)self + e->delta);
}

extern "C" void func_0015E510(S0015E168* self, int a) {
    VEntry* e = &self->unk10[5];
    ((void (*)(void*, int))e->fn)((char*)self + e->delta, 1);
    VEntry* f = &self->unk10[10];
    VEntry* g = &self->unk10[11];
    ((void (*)(void*, int, float))f->fn)((char*)self + f->delta, a, ((float (*)(void*))g->fn)((char*)self + g->delta));
}

extern "C" void func_0015E598(S0015E168* self, int a1) {
    VEntry* e = &self->unk10[7];
    ((void (*)(void*, int))e->fn)((char*)self + e->delta, a1);
}

extern "C" void func_0015E5C0(S0015E168* self, C_0015E5C0* c) {
    VEntry* e = &self->unk10[26];
    ((void (*)(void*, C_0015E5C0))e->fn)((char*)self + e->delta, *c);
}

extern "C" void func_0015E600(S0015E600* self, int a1) {
    self->unkC = a1;
    VEntry* e = &self->unk10[13];
    ((void (*)(void*))e->fn)((char*)self + e->delta);
}

INCLUDE_ASM("asm/nonmatchings/game/t_15D2E0", func_0015E630);

extern "C" void func_0015E648(S0015E168* self, int a1) {
    VEntry* e = &self->unk10[35];
    ((void (*)(void*, int))e->fn)((char*)self + e->delta, a1);
}

extern "C" void func_0015E670(S0015E168* self, int a1, int a2) {
    VEntry* e = &self->unk10[36];
    ((void (*)(void*, int, int))e->fn)((char*)self + e->delta, a1, a2);
}

extern "C" void func_0015E698(S0015E168* self) {
    VEntry* e = &self->unk10[38];
    ((void (*)(void*))e->fn)((char*)self + e->delta);
}

extern "C" void func_0015E6C0(S0015E168* self) {
    VEntry* e = &self->unk10[37];
    ((void (*)(void*))e->fn)((char*)self + e->delta);
}

extern "C" void func_0015E6E8(S0015E168* self) {
    VEntry* e = &self->unk10[39];
    ((void (*)(void*))e->fn)((char*)self + e->delta);
}

extern "C" void func_0015E710(S0015E168* self) {
    VEntry* e = &self->unk10[40];
    ((void (*)(void*))e->fn)((char*)self + e->delta);
}

extern "C" void func_0015E738(S0015E168* self, int a1) {
    VEntry* e = &self->unk10[41];
    ((void (*)(void*, int))e->fn)((char*)self + e->delta, a1);
}

extern "C" void func_0015E760(S0015E168* self) {
    VEntry* e = &self->unk10[42];
    ((void (*)(void*))e->fn)((char*)self + e->delta);
}

extern "C" void func_0015E788(S0015E168* self, int a1) {
    VEntry* e = &self->unk10[43];
    ((void (*)(void*, int))e->fn)((char*)self + e->delta, a1);
}

extern "C" void func_0015E7B0(S0015E168* self) {
    VEntry* e = &self->unk10[45];
    ((void (*)(void*))e->fn)((char*)self + e->delta);
}

extern "C" void func_0015E7D8(S0015E168* self) {
    VEntry* e = &self->unk10[46];
    ((void (*)(void*))e->fn)((char*)self + e->delta);
}

extern "C" void func_0015E800(S0015E168* self) {
    VEntry* e = &self->unk10[47];
    ((void (*)(void*))e->fn)((char*)self + e->delta);
}

extern "C" void func_0015E828(S0015E168* self) {
    VEntry* e = &self->unk10[48];
    ((void (*)(void*))e->fn)((char*)self + e->delta);
}

extern "C" void func_0015E850(void) {
}

extern "C" void func_0015E858(void) {
}

extern "C" int func_0015E860(void) {
    return 0;
}

extern "C" void func_0015E868(void) {
}

extern "C" int func_0015E870(void) {
    return 0;
}

extern "C" void func_0015E878(void) {
}

extern "C" int func_0015E880(void) {
    return 0;
}

extern "C" void func_0015E888(void) {
}

extern "C" void func_0015E890(void) {
}

extern "C" float func_0015E898(void) {
    return 0.0f;
}

extern "C" int func_0015E8A8(void) {
    return 0;
}

extern "C" void func_0015E8B0(void) {
}

extern "C" void func_0015E8B8(void) {
}

extern "C" void func_0015E8C0(void) {
}

extern "C" float func_0015E8C8(void) {
    return 0.0f;
}

extern "C" float func_0015E8D8(void) {
    return 0.0f;
}

extern "C" void func_0015E8E8(void) {
}

extern "C" float func_0015E8F0(void) {
    return 0.0f;
}

extern "C" float func_0015E900(void) {
    return 0.0f;
}

extern "C" void func_0015E910(void) {
}

extern "C" float func_0015E918(void) {
    return 0.0f;
}

extern "C" void func_0015E928(void) {
}

extern "C" float func_0015E930(void) {
    return 0.0f;
}

extern "C" float func_0015E940(void) {
    return 0.0f;
}

extern "C" void func_0015E950(void) {
}

extern "C" void* func_0015E958(void* self) {
    return self;
}

extern "C" void func_0015E960(void) {
}

extern "C" int func_0015E968(void) {
    return 0;
}

extern "C" int func_0015E970(void) {
    return 0;
}

extern "C" void func_0015E978(void) {
}

extern "C" int func_0015E980(void) {
    return 0;
}

extern "C" int func_0015E988(void) {
    return 0;
}

extern "C" void func_0015E990(void) {
}

extern "C" void func_0015E998(void) {
}

extern "C" void func_0015E9A0(void) {
}

extern "C" void func_0015E9A8(void) {
}

extern "C" void func_0015E9B0(void) {
}

extern "C" void func_0015E9B8(void) {
}

extern "C" void func_0015E9C0(void) {
}

extern "C" void func_0015E9C8(void) {
}

extern "C" void func_0015E9D0(void) {
}

extern "C" void func_0015E9D8(void) {
}

extern "C" void func_0015E9E0(void) {
}

extern "C" void func_0015E9E8(void) {
}

extern "C" void func_0015E9F0(void) {
}

extern "C" void func_0015E9F8(void) {
}

extern "C" void func_0015EA00(void) {
}

extern "C" void func_0015EA08(S0015E600* self, int flag) {
    *(void**)((char*)self + 4) = D_0033D480;
    if (flag & 1) Heap_Free(D_00368A38[0], self);
}

extern "C" void func_0015EA48(S0015EA48* self, int a1) {
    self->unk14 = a1;
    VEntry* e = &self->unk1C[6];
    ((void (*)(void*))e->fn)((char*)self + e->delta);
}

extern "C" void* func_0015EA78(void* p, int a) {
    S_0015EA78* self = (S_0015EA78*)p;
    self->unk1C = D_0033D420;
    self->unk0 = a;
    self->unk8 = 1;
    self->unk4 = 0;
    self->unkC = 0;
    self->unk10 = 0;
    self->unk14 = 0;
    u8* c = self->unk18;
    c[0] = 0x80;
    c[1] = 0x80;
    c[2] = 0x80;
    c[3] = 0x80;
    return self;
}

extern "C" void func_0015EAC0(S_0015EA78* self, int flag) {
    self->unk1C = D_0033D420;
    if (flag & 1) Heap_Free(D_00368A38[0], self);
}

extern "C" void func_0015EB00(S0015EB00* self, int a1) {
    self->unk8 = a1;
    VEntry* e = &self->unk1C[5];
    ((void (*)(void*))e->fn)((char*)self + e->delta);
}

extern "C" void func_0015EB30(S0015EB30* self, float f0) {
    self->unkC = f0;
    self->unk10 = 0;
    VEntry* e = &self->unk1C[7];
    ((void (*)(void*, float))e->fn)((char*)self + e->delta, f0);
}

extern "C" void func_0015EB60(S0015EB60* self, int a1) {
    self->unk4 = a1;
    VEntry* e = &self->unk1C[6];
    ((void (*)(void*))e->fn)((char*)self + e->delta);
}

extern "C" void func_0015EB90(S_0015EB90* self, C_0015E5C0* c) {
    self->unk18 = *c;
    C_0015E5C0 tmp(self->unk18);
    VEntry* e = &self->unk1C[6];
    ((void (*)(void*))e->fn)((char*)self + e->delta);
}

extern "C" void* func_0015EBD0(void) {
    return func_0015EA78(Heap_Alloc(D_00368A38[0], 0x20, 1, 0), 0);
}

extern "C" void func_0015EC08(void) {
}

extern "C" void func_0015EC10(void) {
}

extern "C" void func_0015EC18(void) {
}

extern "C" void func_0015EC20(void) {
}

extern "C" void func_0015EC28(void) {
}

extern "C" void func_0015EC30(void) {
}

extern "C" void func_0015EC38(void) {
}

extern "C" void func_0015EC40(void) {
}

extern "C" void func_0015EC48(void) {
}

extern "C" void func_0015EC50(void) {
}

extern "C" u32 func_0015EC58(void) {
    return 0xFFFFFFFF;
}

INCLUDE_ASM("asm/nonmatchings/game/t_15D2E0", func_0015EC68);

extern "C" int func_0015EC78(void) {
    return 0;
}

extern "C" int func_0015EC80(void) {
    return 1;
}

extern "C" void func_0015EC88(void) {
}

extern "C" int func_0015EC90(void) {
    return 0;
}

extern "C" int func_0015EC98(void) {
    return 0;
}

extern "C" void func_0015ECA0(void) {
}

extern "C" void func_0015ECA8(void) {
}

extern "C" void func_0015ECB0(void) {
}

extern "C" S0015ECB8* func_0015ECB8(S0015ECB8* self) {
    self->unk0 = 0;
    self->unk1 = 0;
    self->unk2 = 0;
    self->unk3 = 0;
    return self;
}

extern "C" void func_0015ECD0(void) {
}

extern "C" int func_0015ECD8(void) {
    return 1;
}

extern "C" int func_0015ECE0(void) {
    return 0;
}

extern "C" void func_0015ECE8(void) {
}

extern "C" int func_0015ECF0(void) {
    return 0;
}

extern "C" S0015ECB8* func_0015ECF8(S0015ECB8* self) {
    self->unk0 = 0;
    self->unk1 = 0;
    self->unk2 = 0;
    self->unk3 = 0;
    return self;
}

extern "C" void func_0015ED10(void) {
}

extern "C" int func_0015ED18(void) {
    return 0;
}

extern "C" void func_0015ED20(void) {
}

extern "C" int func_0015ED28(void) {
    return 0;
}

extern "C" void func_0015ED30(void) {
}

extern "C" void func_0015ED38(void) {
}

extern "C" void func_0015ED40(void) {
}

GP_DATA(D_00372B98);
extern "C" M2_15D* func_0015ED48(void) {
    if (!D_00372B98) {
        func_0010F690(&D_0037DB00.a);
        func_0010F690(&D_0037DB00.b);
        func_001342B0(&D_0037DB00);
        D_00372B98 = 1;
    }
    return &D_0037DB00;
}

INCLUDE_ASM("asm/nonmatchings/game/t_15D2E0", func_0015EDA0);

extern "C" void func_0015EDC8(void) {
}

GP_DATA(D_00372B9C);
extern "C" void* func_0015EDD0(void) {
    if (!D_00372B9C) D_00372B9C = 1;
    return D_0037DB20;
}

extern "C" void func_0015EDF0(void) {
}

INCLUDE_ASM("asm/nonmatchings/game/t_15D2E0", func_0015EDF8);

extern "C" void func_0015EE18(void) {
}

extern "C" void func_0015EE20(void) {
}

INCLUDE_ASM("asm/nonmatchings/game/t_15D2E0", func_0015EE28);

extern "C" void func_0015EE48(void) {
}

INCLUDE_ASM("asm/nonmatchings/game/t_15D2E0", func_0015EE50);

extern "C" void func_0015EE68(void) {
}

extern "C" void func_0015EE70(void) {
}

extern "C" int func_0015EE78(void) {
    return 0;
}

extern "C" int func_0015EE80(void) {
    return 1;
}

extern "C" void func_0015EE88(void) {
}

extern "C" int func_0015EE90(void) {
    return 1;
}

extern "C" int func_0015EE98(void) {
    return 1;
}

extern "C" int func_0015EEA0(void) {
    return 0;
}

extern "C" void func_0015EEA8(void) {
}

extern "C" int func_0015EEB0(void) {
    return 0;
}

extern "C" int func_0015EEB8(void) {
    return 0;
}

extern "C" int func_0015EEC0(void) {
    return 0;
}

extern "C" int func_0015EEC8(void) {
    return 0;
}

extern "C" void func_0015EED0(void) {
}

extern "C" void func_0015EED8(void) {
}

extern "C" void func_0015EEE0(void) {
}

extern "C" void func_0015EEE8(void) {
}

extern "C" void func_0015EEF0(void) {
}

extern "C" void func_0015EEF8(void) {
}

extern "C" void func_0015EF00(void) {
}

extern "C" void func_0015EF08(void) {
}

extern "C" void func_0015EF10(void) {
}

extern "C" int func_0015EF18(void) {
    return 0;
}

extern "C" int func_0015EF20(void) {
    return 0;
}

extern "C" int func_0015EF28(void) {
    return 1;
}

extern "C" void func_0015EF30(void) {
}

extern "C" void func_0015EF38(void) {
}

extern "C" void func_0015EF40(void) {
}

extern "C" void func_0015EF48(S0015EF48* self, int a1) {
    VEntry* e = &self->unk18[61];
    ((void (*)(void*, int))e->fn)((char*)self + e->delta, a1);
}

extern "C" void func_0015EF70(void) {
}

extern "C" void func_0015EF78(S0015EF48* self) {
    VEntry* e = &self->unk18[62];
    ((void (*)(void*))e->fn)((char*)self + e->delta);
}

extern "C" void func_0015EFA0(void) {
}

extern "C" void func_0015EFA8(void) {
}

extern "C" int func_0015EFB0(void) {
    return 1;
}

extern "C" int func_0015EFB8(void) {
    return 0;
}

extern "C" S0015EFC0* func_0015EFC0(S0015EFC0* self) {
    self->unk8 = 0;
    self->unk18 = D_0033D750;
    self->unkC = 0;
    self->unk10 = 0;
    self->unk14 = 0;
    return self;
}

extern "C" void func_0015EFE8(S0015EFC0* self, int flags) {
    self->unk18 = D_0033D750;
    func_0015F038((S0015E168*)self);
    if (flags & 1) {
        Heap_Free(D_00368A38[0], self);
    }
}

extern "C" void func_0015F038(S0015E168* self) {
    if (self->unk10) {
        func_0011A470(self->unk10);
        self->unk10 = 0;
    }
}

extern "C" T_0015F070* func_0015F070(S0015E600* self, int a, int b) {
    if (func_00276600(0x15B3950D, 0)) a = 1;
    VEntry* e = &((S0015EF48*)self)->unk18[3];
    T_0015F070* t = ((T_0015F070* (*)(void*, int, int))e->fn)((char*)self + e->delta, a, b);
    if (t) {
        t->unk8 = a ? 1 : 2;
        if (self->unkC) t->unkC = self->unkC;
        t->unk10 = 0;
    }
    return t;
}

extern "C" T_0015F110* func_0015F110(S0015EF48* self, int flag, int b, int c) {
    VEntry* e = &self->unk18[4];
    T_0015F110* t = ((T_0015F110* (*)(void*, int, int, int))e->fn)((char*)self + e->delta, flag, b, c);
    if (t) {
        t->unk10 = 0;
        t->unk8 = flag ? 1 : 2;
    }
    return t;
}

extern "C" int func_0015F168(S0015EFC0* self, int a, int b, int c, int d) {
    self->unk14 = c;
    self->unk8 = 1;
    VEntry* e = &((S0015EF48*)self)->unk18[5];
    return ((int (*)(void*, int, int, int, int))e->fn)((char*)self + e->delta, a, b, c, d);
}

extern "C" void func_0015F1A0(S0015EF48* self) {
    VEntry* e = &self->unk18[6];
    ((void (*)(void*))e->fn)((char*)self + e->delta);
}

extern "C" int func_0015F1C8(S0015EF48* self, int a1) {
    VEntry* e = &self->unk18[7];
    return ((int (*)(void*, int))e->fn)((char*)self + e->delta, a1);
}

extern "C" void func_0015F1F0(S0015EF48* self) {
    VEntry* e = &self->unk18[12];
    ((void (*)(void*))e->fn)((char*)self + e->delta);
}

extern "C" void func_0015F218(S0015EF48* self, int a, int b, int c, int d) {
    VEntry* e = &self->unk18[13];
    ((void (*)(void*, int, int, int, int))e->fn)((char*)self + e->delta, a, b, c, d);
}

extern "C" int func_0015F240(S0015EF48* self, int a, int b, int c, int d) {
    VEntry* e = &self->unk18[14];
    return ((int (*)(void*, int, int, int, int))e->fn)((char*)self + e->delta, a, b, c, d);
}

extern "C" int func_0015F268(S0015EF48* self, int a, int b, C_0015E5C0* c) {
    VEntry* e = &self->unk18[16];
    return ((int (*)(void*, int, int, C_0015E5C0))e->fn)((char*)self + e->delta, a, b, *c);
}

extern "C" void func_0015F2A8(S0015EF48* self, int a1) {
    VEntry* e = &self->unk18[18];
    ((void (*)(void*, int))e->fn)((char*)self + e->delta, a1);
}

extern "C" int func_0015F2D0(S0015EF48* self) {
    VEntry* e = &self->unk18[19];
    return ((int (*)(void*))e->fn)((char*)self + e->delta);
}
