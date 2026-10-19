#include "common.h"

struct S229 {
    int unk0;
    int unk4;
    int unk8;
    char padC[0x10];
    void* unk1C;
    void* unk20;
    char pad24[0x84];
    void* unkA8;
    char padAC[0xC];
    int unkB8;
    char padBC[0x8];
    int unkC4;
    char padC8[0x4];
    void* unkCC;
};

extern "C" {
char* func_0014E948(void);
void func_001510F0(s32 a, s32 b);
void func_00236760(u32 a, s32 b, s32 c, s32 d);
void func_0022B2E8(void*);
void func_00113FB8(void*);
void func_0022B320(void*);
int func_0022CB18(void*);
extern int D_0036F608;
void func_00229538(int, int);
void func_0022B3B8(S229*);
void func_0022B700(S229*);
extern int D_00370EE0[] __attribute__((section(".sdata")));
void func_00114958(int, int);
int func_0022B1B8(void*);
void func_001342E8(void*, int);
void func_0022AE78(int, void*, int);
void* func_0022B040(char*, int);
void* func_0022C768(int, int, int);
void* func_0022C850(int, int);
void* Heap_Alloc(void*, int, int, int);
void* func_0022CD30(char*);
void* func_0022BA90(void*);
int func_0022BA90_i(void*) __asm__("func_0022BA90");
void* func_0022FE90(char*);
void* func_0022D9F0(char*);
void func_0022F3A0(void*);
extern char D_00353630[];
extern char D_003537E0[];
extern char D_00353990[];
extern char D_00353B40[];
extern char D_00353130[];
extern char D_003532E0[];
extern char D_00353E80[];
extern char D_00353CE0[];
extern char D_00354058[];
extern char D_003542A8[];
extern void* D_0036F658;
extern u32 D_0036F65C;
void func_0022C0D8(void*, int);
extern u8 D_00352CC8[];
extern u8 D_00393AD8[];
extern void* D_00368A38;
void Heap_Free(void*, void*);
extern char D_00352B48[];
void func_001C5610(void*, int);
void func_0022B688_f(char*, int) __asm__("func_0022B688");
void func_0022B5D0(void*);
void func_0022B918(void*);
void func_0011E050(int, void*);
void func_0011C408(int, void*);
int strlen(char*);
int func_0030E650(char*, char*);
}

INCLUDE_ASM("asm/nonmatchings/game/t_229D30", func_00229D30);

INCLUDE_ASM("asm/nonmatchings/game/t_229D30", func_00229D38);

INCLUDE_ASM("asm/nonmatchings/game/t_229D30", func_00229EB8);

INCLUDE_ASM("asm/nonmatchings/game/t_229D30", func_00229F38);

extern "C" void func_0022A1D8(char* p) {
    char* n = func_0014E948();
    if (n != 0) {
        do {
            char* c = *(char**)(n + 0xC);
            char* nx = (*(s32*)(c + 4) == -1) ? 0 : c;
            func_001510F0(*(s32*)(n + 4), 0);
            n = nx;
        } while (n != 0);
    }
    func_00236760(0x7A354E97, *(s32*)(p + 0x3BC), 1, 0);
}

GP_DATA(D_0036F608);
extern "C" void CFunc_ParseNodeArray(int a) {
    func_00229538(D_0036F608, a);
}

INCLUDE_ASM("asm/nonmatchings/game/t_229D30", func_0022A278);

struct D229 {
    char pad0[0x14];
    virtual ~D229();
};

GP_DATA(D_0036F65C);
GP_DATA(D_0036F658);
extern "C" void func_0022A2D8(void) {
    if (D_0036F65C >= 2) {
        D_0036F65C -= 1;
        return;
    }
    if (D_0036F658) delete (D229*)D_0036F658;
    D_0036F658 = 0;
    D_0036F65C = 0;
}

extern "C" void* func_0022A330(void* unused, s32 type) {
    char* o;
    switch (type) {
    case 6:
        o = (char*)func_0022CD30((char*)Heap_Alloc(D_00368A38, 0x3C, 1, 0));
        break;
    case 7: {
        char* p = (char*)Heap_Alloc(D_00368A38, 0x38, 1, 0);
        func_0022BA90_i(p);
        o = p;
        asm("" : "+r"(o));
        register char* vt asm("$3") = D_00353630;
        *(char**)(p + 0x34) =  vt;
        break;
    }
    case 8: {
        char* p = (char*)Heap_Alloc(D_00368A38, 0x38, 1, 0);
        func_0022BA90_i(p);
        o = p;
        asm("" : "+r"(o));
        register char* vt asm("$3") = D_003537E0;
        *(char**)(p + 0x34) =  vt;
        break;
    }
    case 9: {
        char* p = (char*)Heap_Alloc(D_00368A38, 0x38, 1, 0);
        func_0022BA90_i(p);
        o = p;
        asm("" : "+r"(o));
        register char* vt asm("$3") = D_00353990;
        *(char**)(p + 0x34) =  vt;
        break;
    }
    case 10: {
        char* p = (char*)Heap_Alloc(D_00368A38, 0x38, 1, 0);
        func_0022BA90_i(p);
        o = p;
        asm("" : "+r"(o));
        register char* vt asm("$3") = D_00353B40;
        *(char**)(p + 0x34) =  vt;
        break;
    }
    case 3: {
        char* p = (char*)Heap_Alloc(D_00368A38, 0x3C, 1, 0);
        func_0022BA90_i(p);
        o = p;
        asm("" : "+r"(o));
        *(s32*)(p + 0x38) = 0;
        register char* vt asm("$3") = D_00353130;
        *(char**)(p + 0x34) =  vt;
        break;
    }
    case 5: {
        char* p = (char*)Heap_Alloc(D_00368A38, 0x38, 1, 0);
        func_0022BA90_i(p);
        o = p;
        asm("" : "+r"(o));
        register char* vt asm("$3") = D_003532E0;
        *(char**)(p + 0x34) =  vt;
        break;
    }
    case 2: {
        char* p = (char*)Heap_Alloc(D_00368A38, 0x38, 1, 0);
        func_0022BA90_i(p);
        o = p;
        asm("" : "+r"(o));
        register char* vt asm("$3") = D_00353E80;
        *(char**)(p + 0x34) =  vt;
        break;
    }
    case 4: {
        char* p = (char*)Heap_Alloc(D_00368A38, 0x38, 1, 0);
        func_0022BA90_i(p);
        o = p;
        asm("" : "+r"(o));
        register char* vt asm("$3") = D_00353CE0;
        *(char**)(p + 0x34) =  vt;
        break;
    }
    case 12: {
        char* p = (char*)Heap_Alloc(D_00368A38, 0x44, 1, 0);
        func_0022BA90_i(p);
        o = p;
        asm("" : "+r"(o));
        *(s32*)(p + 0x40) = 0;
        register char* vt asm("$3") = D_00354058;
        *(char**)(p + 0x34) =  vt;
        break;
    }
    case 13: {
        char* p = (char*)Heap_Alloc(D_00368A38, 0x44, 1, 0);
        func_0022BA90_i(p);
        o = p;
        asm("" : "+r"(o));
        *(s32*)(p + 0x40) = 0;
        register char* vt asm("$3") = D_00354058;
        *(char**)(p + 0x34) =  vt;
        func_0022F3A0(o);
        return o;
    }
    case 18: {
        char* p = (char*)Heap_Alloc(D_00368A38, 0x38, 1, 0);
        func_0022BA90_i(p);
        o = p;
        asm("" : "+r"(o));
        register char* vt asm("$3") = D_003542A8;
        *(char**)(p + 0x34) =  vt;
        break;
    }
    case 19:
        o = (char*)func_0022FE90((char*)Heap_Alloc(D_00368A38, 0xEC, 1, 0));
        break;
    case 14:
        o = (char*)func_0022D9F0((char*)Heap_Alloc(D_00368A38, 0x3C, 1, 0));
        break;
    case 11:
    case 15:
    case 16:
    case 17:
    default:
        o = 0;
        break;
    }
    return o;
}

INCLUDE_ASM("asm/nonmatchings/game/t_229D30", func_0022A680);

struct VE22A {
    s16 delta;
    s16 pad;
    void (*fn)(char*, int);
};

extern "C" void func_0022A800(char* p, int f) {
    *(char**)(p + 0x14) = D_00352B48;
    char* a = *(char**)(p + 0xA8);
    if (a) {
        func_0022B688_f(a, 2);
        Heap_Free(D_00368A38, a);
    }
    a = *(char**)(p + 0xA4);
    if (a) {
        func_0022B688_f(a, 2);
        Heap_Free(D_00368A38, a);
    }
    char* c = *(char**)(p + 0xCC);
    if (c) {
        VE22A* e = (VE22A*)(*(char**)(c + 0x18) + 0x10);
        e->fn(c + e->delta, 3);
    }
    char* h = p + 0xAC;
    char* sent = p + 0xB0;
    char* n = *(char**)(h + 8);
    *(char**)(h + 8) = sent;
    *(char**)(h + 4) = sent;
    if (n != sent) {
        char* end = sent;
        asm("" : "+r"(end));
        do {
            char* nx = *(char**)(n + 4);
            Heap_Free(D_00368A38, n);
            n = nx;
        } while (n != end);
    }
    func_001C5610(p, f);
}

INCLUDE_ASM("asm/nonmatchings/game/t_229D30", func_0022A8F8);

INCLUDE_ASM("asm/nonmatchings/game/t_229D30", func_0022A9B0);

extern "C" void func_0022A9B8(S229* self) {
    self->unkB8 = 0;
    self->unkC4 = 0;
}

INCLUDE_ASM("asm/nonmatchings/game/t_229D30", func_0022A9C8);

struct VE229 {
    s16 delta;
    s16 pad;
    void* fn;
};

struct P229 {
    s32 unk0;
    s32 unk4;
    char pad8[0x18];
    s32 unk20;
    char pad24[0x10];
    char* unk34;
};

struct R229 {
    char pad0[0x80];
    s32 unk80;
    s32 unk84;
    s32 unk88;
    s32 unk8C;
};

struct G229 {
    char pad0[0x18];
    s32 unk18;
    s32 unk1C[1];
    char pad20[0x84];
    s32 unkA4;
    char padA8[0x10];
    s32 unkB8;
    s32 unkBC;
    s32 unkC0;
    s32 unkC4;
};

extern "C" {
s32 CrcFromPathLowercase_l(s32 n) __asm__("CrcFromPathLowercase");
s32 func_0022A8F8_l(G229* g, s32 n) __asm__("func_0022A8F8");
void func_0022A9B8_l(G229* g) __asm__("func_0022A9B8");
void func_0022C558(s32 a, s32 b, s32 c, void* d);
void func_001342E8_l(void* a, void* b) __asm__("func_001342E8");
s32 func_00275F08(u32 a, s32 b);
}

extern "C" s32* func_0022ABE8(s32* out, G229* g, s32 name, s32 sz, s32 crc, s32 flag, R229* o, s32 x) {
    if (crc == 0) {
        crc = CrcFromPathLowercase_l(name);
    }
    s32 v = sz;
    if (v == 0) {
        v = func_0022A8F8_l(g, name);
    }
    P229* n = (P229*)func_0022A330(g, v);
    n->unk0 = crc;
    n->unk20 = n->unk20 & 0x80FFFFFF;
    n->unk4 = *(s32*)((char*)g + g->unk18 * 4 + 0x1C);
    if (o != 0) {
        o->unk80 = g->unkB8;
        o->unk84 = g->unkBC;
        s32 t = g->unkC0;
        o->unk8C = 0;
        o->unk88 = t;
        if (g->unkC4 != 0) {
            func_0022A9B8_l(g);
        }
    }
    if (flag != 0) {
        func_0022C0D8(n, (s32)func_0022C768(g->unkA4, flag, *(s32*)((char*)g + g->unk18 * 4 + 0x1C)));
    }
    VE229* e = (VE229*)(n->unk34 + 0x20);
    s32 r = ((s32 (*)(void*, s32, s32, s32, void*, s32))e->fn)((char*)n + e->delta, name, 0, 0, o, x);
    if (r != 0) {
        if (func_00275F08(0x25DC7904, 0) == 0) {
            if (n != 0) {
                VE229* d = (VE229*)(n->unk34 + 0x18);
                ((void (*)(void*, s32))d->fn)((char*)n + d->delta, 3);
            }
        }
        out[0] = 0;
        out[1] = 0;
        out[2] = 0;
    } else {
        func_0022C558(g->unkA4, crc, *(s32*)((char*)g + g->unk18 * 4 + 0x1C), n);
        out[0] = 0;
        out[1] = 0;
        out[2] = 0;
        func_001342E8_l(out, n);
    }
    return out;
}

extern "C" void func_0022ADD0(int a, int** b) {
    int* t = *b;
    func_001342E8(b, 0);
    func_0022AE78(a, t, t[1]);
}

extern "C" void func_0022AE18(int a, int* b, int c) {
    int t = *b;
    func_001342E8(b, 0);
    func_0022AE78(a, (void*)t, c);
}

INCLUDE_ASM("asm/nonmatchings/game/t_229D30", func_0022AE70);

INCLUDE_ASM("asm/nonmatchings/game/t_229D30", func_0022AE78);

struct V229 {
    char pad0[0x34];
    virtual void v1();
    virtual void v2();
    virtual ~V229();
    virtual void v4();
    virtual void v5();
    virtual s32 v6();
};

extern "C" void func_0022AFC0(int a, V229* o) {
    o->v6();
    func_0022C0D8(o, 0);
    if (o) delete o;
}

extern "C" int func_0022B020(S229* self) {
    return func_0022CB18(self->unkA8) == 0;
}

extern "C" void* func_0022B040(char* p, int b) {
    void* r = func_0022C768(*(int*)(p + 0xA4), b, *(int*)(p + *(int*)(p + 0x18) * 4 + 0x1C));
    if (!r) {
        r = func_0022C768(*(int*)(p + 0xA4), b, 0);
        if (!r && *(int*)(p + 0xC8)) r = func_0022C850(*(int*)(p + 0xA4), b);
    }
    return r;
}

INCLUDE_ASM("asm/nonmatchings/game/t_229D30", func_0022B0D0);

INCLUDE_ASM("asm/nonmatchings/game/t_229D30", func_0022B168);

struct N22B {
    N22B* unk0;
    N22B* unk4;
    char* unk8;
};

struct It22B {
    int unk0;
    N22B* unk4;
    int unk8;
    int unkC;
};

struct VE22B {
    s16 delta;
    s16 pad;
    int (*fn)(char*);
};

extern "C" {
int func_0022C120(char*);
void func_0022CA20(int, char*);
void func_0022AFC0_c(char*, char*) __asm__("func_0022AFC0");
}

extern "C" int func_0022B1B8(void* pp) {
    char* p = (char*)pp;
    It22B it, end, c, d, e;
    int any = 0;
    end.unk4 = (N22B*)(p + 0xB0);
    it.unk4 = *(N22B**)(p + 0xB4);
    if (it.unk4 != end.unk4) {
        do {
            int del = 0;
            char* o = it.unk4->unk8;
            if (func_0022C120(o) == 5) {
                VE22B* v = (VE22B*)(*(char**)(o + 0x34) + 0x40);
                if (v->fn(o + v->delta) != 0) {
                    del = 1;
                    func_0022CA20(*(int*)(p + 0xA8), o);
                    func_0022AFC0_c(p, o);
                }
            } else {
                del = 1;
            }
            if (del != 0) {
                any = 1;
                N22B* n = it.unk4;
                c.unk4 = n;
                e.unk4 = n;
                N22B* nx = n->unk4;
                d.unk4 = n;
                c.unk4 = nx;
                n->unk0->unk4 = n->unk4;
                n->unk4->unk0 = n->unk0;
                Heap_Free(D_00368A38, n);
                end.unk4 = c.unk4;
                it.unk4 = c.unk4;
            } else {
                it.unk4 = it.unk4->unk4;
            }
            end.unk4 = (N22B*)(p + 0xB0);
        } while (it.unk4 != end.unk4);
    }
    return any;
}

extern "C" void func_0022B2E8(void* a) {
    while (func_0022B1B8(a)) {
    }
}

extern "C" void func_0022B320(void* self) {
    func_0022B2E8(self);
}

extern "C" void func_0022B340(char* p) {
    int v = *(int*)(p + 0xCC);
    func_00114958(D_00370EE0[0] + 8, v);
}

extern "C" void func_0022B368(S229* self) {
    func_00113FB8(self->unkCC);
}

extern "C" void func_0022B388(S229* self) {
    func_0022B320(self->unk20);
}

INCLUDE_ASM("asm/nonmatchings/game/t_229D30", func_0022B3A8);

extern "C" void func_0022B3B8(S229* self) {
    self->unk0 = 0;
    self->unk4 = 0;
    self->unk8 = 0;
}

extern "C" S229* func_0022B3C8(S229* p) {
    func_0022B3B8(p);
    return p;
}

INCLUDE_ASM("asm/nonmatchings/game/t_229D30", func_0022B3F0);

extern "C" void func_0022B5D0(void* self) {
    int* p = (int*)self;
    char* t = (char*)p[1];
    if (t) {
        char* q = t;
        u32 n = 1 << p[0];
        u32 i = 0;
        if (n) {
            do {
                char* c = *(char**)(q + 8);
                if (c) {
                    do {
                        char* nx = *(char**)(c + 8);
                        func_0011C408(0, c);
                        c = nx;
                    } while (c);
                }
                func_0022B3B8((S229*)q);
                i++;
                q += 12;
            } while (i < n);
        }
        p[2] = 0;
    }
}

extern "C" void func_0022B688(char* p, int flags) {
    if (!((u8*)p)[0x16]) {
        if (*(void**)(p + 4)) {
            func_0022B5D0(p);
            if (*(void**)(p + 4)) Heap_Free(D_00368A38, *(void**)(p + 4));
            *(void**)(p + 4) = 0;
        }
    }
    if (flags & 1) Heap_Free(D_00368A38, p);
}

extern "C" void func_0022B700(S229* self) {
    self->unk0 = 0;
    self->unk4 = 0;
    self->unk8 = 0;
}

extern "C" S229* func_0022B710(S229* p) {
    func_0022B700(p);
    return p;
}

INCLUDE_ASM("asm/nonmatchings/game/t_229D30", func_0022B738);

extern "C" void func_0022B918(void* self) {
    int* p = (int*)self;
    char* t = (char*)p[1];
    if (t) {
        char* q = t;
        u32 n = 1 << p[0];
        u32 i = 0;
        if (n) {
            do {
                char* c = *(char**)(q + 8);
                if (c) {
                    do {
                        char* nx = *(char**)(c + 8);
                        func_0011C408(0, c);
                        c = nx;
                    } while (c);
                }
                func_0022B700((S229*)q);
                i++;
                q += 12;
            } while (i < n);
        }
        p[2] = 0;
    }
}

extern "C" void func_0022B9D0(char* p, int flags) {
    if (!((u8*)p)[0x16]) {
        if (*(void**)(p + 4)) {
            func_0022B918(p);
            if (*(void**)(p + 4)) Heap_Free(D_00368A38, *(void**)(p + 4));
            *(void**)(p + 4) = 0;
        }
    }
    if (flags & 1) Heap_Free(D_00368A38, p);
}

INCLUDE_ASM("asm/nonmatchings/game/t_229D30", func_0022BA48);

extern "C" void func_0022BA70(S229* self) {
    ((void (*)(S229*))self->unk1C)(self);
}

extern "C" void* func_0022BA90(void* self) {
    char* p = (char*)self;
    *(void**)(p + 0x34) = D_00352CC8;
    int* q = (int*)(p + 0x24);
    *(u32*)(p + 0x20) &= 0x80FFFFFF;
    *(int*)(p + 0) = 0;
    int* n = (int*)(p + 0x2C);
    *(int*)(p + 4) = 0;
    *(int*)(p + 8) = 0;
    p[0xC] = 0;
    *(int*)(p + 0x10) = 0;
    *(int*)(p + 0x14) = 0;
    *(int*)(p + 0x18) = 0;
    *(int*)(p + 0x1C) = 0;
    q[1] = 0;
    *(int**)(p + 0x2C) = n;
    n[1] = (int)n;
    q[1] = (int)D_00393AD8;
    return p;
}

INCLUDE_ASM("asm/nonmatchings/game/t_229D30", func_0022BAF8);

INCLUDE_ASM("asm/nonmatchings/game/t_229D30", func_0022BBA0);

INCLUDE_ASM("asm/nonmatchings/game/t_229D30", func_0022BBD0);

struct X229 {
    char pad0[0x20];
    u32 flags;
    char pad24[0x10];
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13(int, u32);
    virtual void v14();
    virtual void v15(int, int);
};

extern "C" int func_0022BCE0(X229* o, int x, u32 y, int z, int a, int b) {
    o->flags = (o->flags & 0x80FFFFFF) | 0x01000000;
    o->v15(a, b);
    o->flags = (o->flags & 0xFF000000) | (y & 0xFFFFFF);
    o->v13(x, o->flags & 0xFFFFFF);
    return 0;
}
