#include "common.h"

typedef unsigned int u128_14E __attribute__((mode(TI)));

struct S14E_L {
    char pad0[0x4];
    u32 unk4;
    int unk8;
    S14E_L* unkC;
    S14E_L* unk10;
    void* unk14;
};

struct S14E_V {
    int unk0;
    char pad4[0x8C];
    virtual void v1();
    virtual void v2();
};

extern "C" {
int func_00153290(int, int, int, void*);
void func_0014FF20(void*, int);
void func_00152C58(int, int);
int func_00152C50(int);
char* func_0030E720(int, void*);
void strcpy(int, int);
extern u8 D_00369A88[];
extern u8 D_00369A90[];
void func_0014F910(int, int);
extern int D_00373254[] __attribute__((section(".sdata")));
extern int D_00373258;
extern S14E_L* D_00378204[];
void func_0014E6A8(void);
int func_0028DAB8(void);
int func_0014E7E8(int);
extern u8 D_0033C3A0[];
extern u8 D_0033C388[];
void func_0014F978(S14E_L*, int);
int func_0027D268(void*, u32, float*, int);
void func_0014F150(void*);
void func_001820D0(void*);
void func_00182180(void*);
int func_001150B8(int);
extern S14E_L D_003781F8;
int func_0015D6F0(void*);
int func_00182468(void*, float);
extern int D_00368A38[] __attribute__((section(".sdata")));
void Heap_Free(int, void*);
extern int D_00369A70;
void func_001827D0(int);
void func_0011A558(int, int, int);
void func_0011A568(void);
int func_00182220(int, int, int, int, int, int, int);
void func_0022B0D0(void*, void*, int, int);
void func_00134340(void*);
extern int D_00369A74;
extern int D_00369A78;
extern u8 D_004159F0[];
extern int D_00369A6C;
void func_001822F0(void);
void func_00182338(void);
void func_00182370(void);
void func_001823A8(void);
void func_00182448(void);
void func_00182428(void);
void func_00182078(void);
void func_00182110(void);
void func_001821B8(void);
void func_001821E0(void);
void func_001822A8(void);
void func_001822E0(void);
void func_00182488(void);
void func_00182498(void*);
void func_001827B0(void);
void func_00182798(void);
void func_001827F0(void);
int func_001827A0(void);
void func_001827A8(void);
void func_00182818(void);
void func_00182820(void);
void func_00182828(void);

}

INCLUDE_ASM("asm/nonmatchings/game/t_14E7E0", func_0014E7E0);

INCLUDE_ASM("asm/nonmatchings/game/t_14E7E0", func_0014E7E8);

extern "C" int func_0014E850(void) {
    return func_0014E7E8(func_0028DAB8());
}

struct S14E_O {
    char pad0[0xC];
    int unkC;
};

INCLUDE_ASM("asm/nonmatchings/game/t_14E7E0", func_0014E878);

INCLUDE_ASM("asm/nonmatchings/game/t_14E7E0", func_0014E8E0);

extern "C" S14E_L* func_0014E948(void) {
    S14E_L* p = D_00378204[0];
    if (p->unk4 == 0xFFFFFFFF) {
        p = 0;
    }
    return p;
}

INCLUDE_ASM("asm/nonmatchings/game/t_14E7E0", func_0014E960);

extern "C" void func_0014E968(void) {
    func_001822F0();
}

extern "C" void func_0014E988(void) {
    func_00182338();
}

extern "C" void func_0014E9A8(void) {
    func_00182370();
}

extern "C" void func_0014E9C8(void) {
    func_001823A8();
}

struct VE_0014E9E8 { char pad0[0x10]; s16 unk10; s16 unk12; int (*unk14)(void*); };
struct S_0014E9E8_b { char pad0[0x34]; VE_0014E9E8* unk34; };
struct S_0014E9E8 { char pad0[0xC8]; int unkC8; };
extern S_0014E9E8* D_0036F658;

extern "C" int func_0014E9E8(int a) {
    S_0014E9E8_b* loc;
    S_0014E9E8* g = D_0036F658;
    int saved = g->unkC8;
    g->unkC8 = 1;
    func_0022B0D0(&loc, g, a, 0);
    int r = 0;
    if (loc) {
        VE_0014E9E8* e = loc->unk34;
        r = e->unk14((char*)loc + e->unk10);
    }
    func_00134340(&loc);
    D_0036F658->unkC8 = saved;
    return r;
}

INCLUDE_ASM("asm/nonmatchings/game/t_14E7E0", func_0014EA70);

extern "C" void func_0014EAC8(void) {
    func_00182448();
}

extern "C" void func_0014EAE8(void) {
    func_00182428();
}

extern "C" void func_0014EB08(void) {
    func_00182078();
}

extern "C" void func_0014EB28(void* self) {
    func_0014F150(self);
    func_001820D0(self);
}

extern "C" void func_0014EB58(void) {
    func_00182110();
}

extern "C" void func_0014EB78(void* self) {
    func_0014F150(self);
    func_00182180(self);
}

extern "C" void func_0014EBA8(void) {
    func_001821B8();
}

extern "C" void func_0014EBC8(void) {
    func_001821E0();
}

extern "C" int func_0014EBE8(int a, int b) {
    strcpy(b, a);
    char* p = func_0030E720(b, D_00369A88);
    int r = p != 0;
    if (r) *p = 0;
    char* q = func_0030E720(b, D_00369A90);
    if (q) *q = 0;
    return r;
}

extern "C" int func_0014EC58(int a, int b, int c, int d, int e, int f, int g) {
    func_0011A558(0xC05907F8, 0, 0);
    int r = func_00182220(a, b, c, d, e, f, g);
    func_0011A568();
    return r;
}

extern "C" void func_0014ED00(void) {
    func_001822A8();
}

extern "C" void func_0014ED20(void) {
    func_001822E0();
}

INCLUDE_ASM("asm/nonmatchings/game/t_14E7E0", func_0014ED40);

INCLUDE_ASM("asm/nonmatchings/game/t_14E7E0", func_0014ED50);

extern "C" u8* func_0014F0D0(void) {
    return D_004159F0;
}

INCLUDE_ASM("asm/nonmatchings/game/t_14E7E0", func_0014F0E0);

extern "C" void func_0014F130(void) {
    func_00182488();
}

extern "C" void func_0014F150(void* self) {
    func_00182498(self);
}

INCLUDE_ASM("asm/nonmatchings/game/t_14E7E0", func_0014F170);

GP_DATA(D_00369A6C);
extern "C" void func_0014F1A0(void) {
    D_00369A6C ^= 1;
}

extern "C" void func_0014F1B0(void) {
    func_001827B0();
}

extern "C" void func_0014F1D0(int a, int b) {
    D_00373254[0] = b;
    D_00373258 = a;
}

extern "C" int func_0014F1E0(void* self, float f) {
    if (func_0015D6F0(self) >= 2) {
        return 0;
    }
    return func_00182468(self, f);
}

INCLUDE_ASM("asm/nonmatchings/game/t_14E7E0", func_0014F230);

INCLUDE_ASM("asm/nonmatchings/game/t_14E7E0", func_0014F268);

extern "C" int CFunc_ToggleAddScenes(void) {
    func_0014E6A8();
    return 1;
}

INCLUDE_ASM("asm/nonmatchings/game/t_14E7E0", func_0014F298);

extern "C" void func_0014F708(void) {
    func_00182798();
}

INCLUDE_ASM("asm/nonmatchings/game/t_14E7E0", func_0014F728);

extern "C" int func_0014F738(void) {
    return D_00369A70;
}

extern "C" void func_0014F740(int v) {
    D_00369A78 = v;
}

extern "C" int func_0014F748(void) {
    return D_00369A78;
}

GP_DATA(D_00369A74);
extern "C" void func_0014F750(int a, int b) {
    if (D_00369A74) {
        if (b == D_00369A74) {
            func_001827D0(a);
            if (a) D_00369A74 = 0;
        }
    } else {
        func_001827D0(a);
        if (!a) D_00369A74 = b;
    }
}

extern "C" void func_0014F7B8(void) {
    func_001827F0();
}

INCLUDE_ASM("asm/nonmatchings/game/t_14E7E0", func_0014F7D8);

extern "C" void func_0014F7E0(void) {
    func_001827A0();
}

extern "C" void func_0014F800(void) {
    func_001827A8();
}

INCLUDE_ASM("asm/nonmatchings/game/t_14E7E0", func_0014F820);

extern "C" int CFunc_CheckFlexibleParticleStructure(void* params) {
    float f;
    return func_0027D268(params, 0x8E9A640E, &f, 0) != 0;
}

extern "C" int CFunc_CheckSplineParticleStructure(void* params) {
    float f;
    return func_0027D268(params, 0x35B65BD4, &f, 0) != 0;
}

extern "C" int CFunc_EngineConfig(void) {
    return 0;
}

extern "C" int CFunc_EngineCreateWaterRipple(void) {
    return 0;
}

extern "C" int CFunc_EngineWind(void) {
    return 0;
}

extern "C" int CFunc_EngineUpdateFXMaterial(void) {
    return 0;
}

extern "C" void func_0014F8A8(void) {
    func_00182818();
}

extern "C" void func_0014F8C8(void) {
    func_00182820();
}

extern "C" void func_0014F8E8(void) {
    func_00182828();
}

INCLUDE_ASM("asm/nonmatchings/game/t_14E7E0", func_0014F908);

extern "C" void func_0014F910(int a, int b) {
    if (b == 0xFFFF && a) {
        u32* d = (u32*)&D_003781F8;
        u32 k = 0xFFFFFFFF;
        d[5] = (u32)D_0033C3A0;
        d[1] = k;
        d[3] = (u32)d;
        d[4] = (u32)d;
        d[2] = 0;
    }
}

extern "C" void func_0014F958(u128_14E* dst, u128_14E a, u128_14E b) {
    dst[0] = a;
    dst[1] = b;
}
TEXT_PAD(20);

extern "C" void func_0014F978(S14E_L* self, int flags) {
    self->unk14 = D_0033C388;
    self->unk10->unkC = self->unkC;
    self->unkC->unk10 = self->unk10;
    self->unkC = self;
    self->unk10 = self;
    if (flags & 1) {
        Heap_Free(D_00368A38[0], self);
    }
}

extern "C" void func_0014F9D8(S14E_L* self, int flags) {
    self->unk14 = D_0033C3A0;
    func_0014F978(self, flags);
}

extern "C" void func_0014FA00(void) {
    func_0014F910(1, 0xFFFF);
}

struct N14FA20 { char pad0[4]; u32 unk4; int unk8; N14FA20* unkC; N14FA20* unk10; void* unk14; };
struct S14FA20 {
    int unk0; char pad4[8]; int unkC; char pad10[0x40]; int unk50; int unk54; void* unk58; int unk5C; int unk60; int unk64;
    int unk68; int unk6C; int unk70; int unk74; int unk78; int unk7C; int unk80; int unk84; N14FA20* unk88; N14FA20* unk8C; void* unk90;
};
extern "C" {
void func_0010F690(void*);
void func_001342B0(void*);
void* func_00152670(void*, int, int);
void* Heap_Alloc(int, int, int, int);
void* operator_new(u32);
extern u8 D_0033C510[];
extern u8 D_0033C540[];
}

extern "C" S14FA20* func_0014FA20(S14FA20* self, int n) {
    char* a = (char*)self + 0x10;
    char* b = (char*)self + 0x30;
    self->unk90 = D_0033C540;
    func_0010F690(a);
    func_0010F690((char*)self + 0x20);
    func_001342B0(a);
    func_0010F690(b);
    func_0010F690((char*)self + 0x40);
    func_001342B0(b);
    self->unk5C = 0;
    void* r;
    if (n > 0) r = func_00152670(Heap_Alloc(D_00368A38[0], 0x1C, 1, 0), n, 0);
    else r = 0;
    self->unk0 = 0;
    self->unkC = 0;
    self->unk60 = 0;
    self->unk5C = 0;
    self->unk68 = 0;
    self->unk6C = 0;
    self->unk64 = 0;
    self->unk50 = 0;
    self->unk54 = 0;
    self->unk70 = 0;
    self->unk78 = 0;
    self->unk74 = 0;
    self->unk80 = 0;
    self->unk84 = 0;
    self->unk7C = 0;
    self->unk58 = r;
    N14FA20* x = (N14FA20*)operator_new(0x18);
    x->unk4 = 0xFFFFFFFF;
    x->unk8 = 0;
    x->unk14 = D_0033C510;
    x->unkC = x;
    x->unk10 = x;
    self->unk88 = x;
    N14FA20* y = (N14FA20*)operator_new(0x18);
    y->unk4 = 0xFFFFFFFF;
    y->unk14 = D_0033C510;
    y->unk8 = 0;
    y->unkC = y;
    y->unk10 = y;
    self->unk8C = y;
    return self;
}

struct HN14F { u32 key; void* val; HN14F* next; };
struct HT14F {
    s32 bits;
    HN14F* buckets;
    s32 unk8;
    s32 iterIdx;
    HN14F* iterNode;
    u8 unk14;
    u8 unk15;

    bool Scan(s32 size) {
        for (;;) {
            if (!(++iterIdx < size)) {
                return false;
            }
            iterNode = &buckets[iterIdx];
            if (iterNode->val) {
                return true;
            }
            HN14F* nx = iterNode->next;
            if (nx) {
                iterNode = nx;
                return true;
            }
        }
    }

    bool Next() {
        s32 size = 1 << bits;
        if (iterNode) {
            iterNode = iterNode->next;
        } else if (iterIdx >= 0) {
            return false;
        }
        if (iterNode) {
            return true;
        }
        return Scan(size);
    }

    void* GetNext() {
        void* r;
        if (!Next()) {
            r = 0;
        } else {
            HN14F* n = iterNode;
            r = n ? n->val : 0;
        }
        return r;
    }

    void Start() {
        iterIdx = -1;
        iterNode = 0;
    }
};
struct VE14F { s16 delta; s16 unk2; void (*fn)(void*, int); };
struct VE14G { s16 delta; s16 unk2; int (*fn)(void*, int); };
struct VT14F { char pad0[8]; VE14F e1; VE14F e2; };
struct VT14H { char pad0[8]; VE14G e1; VE14F e2; };
struct O14F { char pad0[4]; u32 unk4; char pad8[0xC]; VT14F* unk14; VT14H* unk18; };
struct D14F { char pad0[0x58]; HT14F* unk58; char pad5C[0x14]; void* unk70; void* unk74; char pad78[0x10]; O14F* unk88; O14F* unk8C; void* unk90; };

extern "C" {
void func_00153278(void*, int);
void func_00152908(void*, int);
void func_00150DE8(void*);
void func_0015B920(void*);
}

extern "C" void func_0014FB78(D14F* self, int flags) {
    self->unk90 = D_0033C540;
    if (self->unk58) {
        self->unk58->Start();
        for (;;) {
            O14F* o = (O14F*)self->unk58->GetNext();
            if (!o) {
                break;
            }
            func_00153278(o, 0x40);
            if (!(o->unk4 & 0x100)) {
                VE14G* e = &o->unk18->e1;
                e->fn((char*)o + e->delta, 3);
            } else {
                VE14F* e = &o->unk18->e2;
                e->fn((char*)o + e->delta, 3);
            }
        }
        if (self->unk58) {
            func_00152908(self->unk58, 3);
        }
    }
    O14F* a = self->unk88;
    if (a) {
        VE14F* e = &a->unk14->e1;
        e->fn((char*)a + e->delta, 3);
    }
    O14F* b = self->unk8C;
    if (b) {
        VE14F* e = &b->unk14->e1;
        e->fn((char*)b + e->delta, 3);
    }
    func_00150DE8(self);
    if (self->unk74) {
        func_0015B920(self->unk74);
    }
    if (flags & 1) {
        Heap_Free(D_00368A38[0], self);
    }
}

INCLUDE_ASM("asm/nonmatchings/game/t_14E7E0", func_0014FD50);

INCLUDE_ASM("asm/nonmatchings/game/t_14E7E0", func_0014FF18);

struct B14FF20 { int unk0; B14FF20* unk4; int unk8; };
struct H14FF20 { int unk0; int unk4; H14FF20* unk8; };
struct O14FF20 { char pad0[0x58]; B14FF20* unk58; };
extern "C" {
void* func_0011C3A8_2(int) __asm__("func_0011C3A8");
H14FF20* func_00152648_2(void*) __asm__("func_00152648");
}

extern "C" void func_0014FF20(void* p, int key) {
    O14FF20* self = (O14FF20*)p;
    int h = func_00152C50(key);
    B14FF20* t = self->unk58;
    H14FF20* b = (H14FF20*)((char*)t->unk4 + ((h & ((1 << t->unk0) - 1)) * 0xC));
    if (b->unk4 != 0 || b->unk0 != 0) {
        H14FF20* n = (H14FF20*)func_0011C3A8_2(0);
        if (n != 0) n = func_00152648_2(n);
        n->unk0 = h;
        n->unk4 = key;
        n->unk8 = b->unk8;
        b->unk8 = n;
    } else {
        b->unk0 = h;
        b->unk4 = key;
    }
    t->unk8 = t->unk8 + 1;
}

INCLUDE_ASM("asm/nonmatchings/game/t_14E7E0", func_0014FFF0);

INCLUDE_ASM("asm/nonmatchings/game/t_14E7E0", func_00150190);

struct S150358 { char padC[0xC]; unsigned int unkC; };

extern "C" int func_00150358(S150358* a, int b, S150358* c, int d, int e, int g) {
    S150358* t = c ? c : a;
    int r = func_00153290(b, d, e, t);
    if (r) {
        if (g) func_00152C58(r, g);
        func_0014FF20(t, r);
        if (e) t->unkC |= 8;
        return func_00152C50(r);
    }
    return 0;
}

INCLUDE_ASM("asm/nonmatchings/game/t_14E7E0", func_00150400);

extern "C" void func_00150520(S14E_V* self, int x) {
    self->unk0 = func_001150B8(x);
    self->v2();
}

INCLUDE_ASM("asm/nonmatchings/game/t_14E7E0", func_00150560);

INCLUDE_ASM("asm/nonmatchings/game/t_14E7E0", func_00150568);
