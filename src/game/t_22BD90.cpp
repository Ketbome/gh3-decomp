#include "common.h"

struct S22B {
    char pad0[0x10];
    int unk10;
    char pad14[0x8];
    int unk1C;
    u32 unk20_0 : 24;
    u32 unk20_24 : 7;
    u32 unk20_31 : 1;
};

extern "C" {
extern u8 D_00352CB8[];
extern u8 D_00352F78[];
extern u8 D_0036F838[];
extern u8 D_003532D0[];
void func_0022C4F0(int, int);
void func_0011A470(int);
extern u8 D_00352F88[];
void* func_0022BA90(void*);
extern u8 D_00353480[];
int func_001162E8(void*);
extern u8 D_00372E50;
extern u8 D_00393AD8[];
void* func_0022C3C8(void);
void func_0030A2F4(void*, int, int);
extern int D_0036F748;
extern u8 D_0041ACB0[];
void func_0022C030(int*);
void func_0014E708(int, int);
void func_00150DE8(int);
void func_002886F8(int);
void func_0028D700(int);
int func_0022BCE0(void*, int, int, int, int, int);
int func_0011E008(int);
int func_0011DC18(int);
void func_0022C498(void*);
void func_0011D220(int);
int func_0014F130(void);
void func_0030B550(int, void*, int, int);
extern u8 D_0036F8D8[];
void func_0022BBB0(void*, int, int, int, int, int);
int func_0030E720(int, void*);
int func_0030B550_3(int, void*, int) __asm__("func_0030B550");
extern u8 D_0036F8E0[];
extern u8 D_0036F8E8[];
void func_00287EB0(int, int, int);
int func_0028DAB8(int);
int func_0022BE60_3(char*, int, int) __asm__("func_0022BE60");
int func_0014E560(int, int, int, int, int, int, int);
void func_00150EB8(int, int, int);
int func_001510D8(int, int);
}

struct VE22B {
    s16 delta;
    s16 unk2;
    void* fn;
};

#define VCALL22B(o, vp, off, T) ((T)((VE22B*)(*(char**)((char*)(o) + (vp)) + (off)))->fn)
#define VADJ22B(o, vp, off) ((char*)(o) + ((VE22B*)(*(char**)((char*)(o) + (vp)) + (off)))->delta)

extern "C" int func_0022BD90(char* p) {
    func_0022C030((int*)p);
    VE22B* e = (VE22B*)(*(char**)(p + 0x34) + 0x58);
    ((void (*)(char*, int))e->fn)(p + e->delta, 0);
    *(u32*)(p + 0x20) &= 0x80FFFFFF;
    return 0;
}

extern "C" void func_0022BDE8(S22B* self) {
    self->unk20_24 = 5;
}

inline int type_0022BE08(S22B* self) {
    return self->unk20_24;
}

extern "C" int func_0022BE08(S22B* self) {
    return type_0022BE08(self) == 4;
}

extern "C" int func_0022BE20(char* p) {
    struct VT {
        char pad[0x68];
        s16 delta;
        s16 pad6A;
        int (*fn)(char*, int, u32);
    };
    VT* v = *(VT**)(p + 0x34);
    return v->fn(p + v->delta, *(int*)(p + 0x14), *(u32*)(p + 0x20) & 0xFFFFFF);
}

extern "C" int func_0022BE60(char* p) {
    if (*(char**)(p + 0x18)) {
        int v = *(int*)(*(char**)(p + 0x18) + 0x8C);
        if (v) {
            func_0011E008(v);
            *(int*)(*(char**)(p + 0x18) + 0x8C) = 0;
        }
        if (*(char**)(p + 0x18)) {
            func_0022C498(*(char**)(p + 0x18));
            *(int*)(p + 0x18) = 0;
        }
    }
    *(u32*)(p + 0x20) = (*(u32*)(p + 0x20) & 0x80FFFFFF) | 0x04000000;
    return 1;
}

extern "C" int func_0022BEE0(char* p) {
    if (*(char**)(p + 0x18)) {
        int v = *(int*)(*(char**)(p + 0x18) + 0x8C);
        if (v) {
            func_0011DC18(v);
            func_0011E008(*(int*)(*(char**)(p + 0x18) + 0x8C));
            *(int*)(*(char**)(p + 0x18) + 0x8C) = 0;
        }
    }
    *(u32*)(p + 0x20) = (*(u32*)(p + 0x20) & 0x80FFFFFF) | 0x06000000;
    return 1;
}

INCLUDE_ASM("asm/nonmatchings/game/t_22BD90", func_0022BF58);

extern "C" void func_0022C030(int* p) {
    if (p[5]) {
        func_0011A470(p[5]);
        p[5] = 0;
    }
}

extern "C" void func_0022C068(char* p, int a) {
    void* r = func_0022C3C8();
    *(void**)(p + 0x18) = r;
    if (a) {
        func_0030A2F4(r, a, 0x80);
    }
}

extern "C" int func_0022C0B0(void) {
    return 0x90;
}

extern "C" void* func_0022C0B8(void) {
    return D_00352CB8;
}

extern "C" int func_0022C0C8(S22B* self) {
    return self->unk10;
}

extern "C" void func_0022C0D0(S22B* self, int v) {
    self->unk10 = v;
}

extern "C" void func_0022C0D8(char* p, char* q) {
    char* o = *(char**)(p + 0x1C);
    if (o) {
        o[0xC] = o[0xC] - 1;
    }
    *(char**)(p + 0x1C) = q;
    if (q) {
        q[0xC] = q[0xC] + 1;
    }
}

extern "C" int func_0022C110(S22B* self) {
    return self->unk1C;
}

INCLUDE_ASM("asm/nonmatchings/game/t_22BD90", func_0022C118);

extern "C" int func_0022C120(S22B* self) {
    return self->unk20_24;
}

INCLUDE_ASM("asm/nonmatchings/game/t_22BD90", func_0022C130);

INCLUDE_ASM("asm/nonmatchings/game/t_22BD90", func_0022C210);

INCLUDE_ASM("asm/nonmatchings/game/t_22BD90", func_0022C308);

extern "C" int func_0022C380(char* p) {
    int r = 0;
    if (*(char**)(p + 0x30) == p + 0x2C) {
        if (*(u8*)(p + 0xC) == 0) {
            r = func_0022C120((S22B*)p) == 5;
        }
    }
    return r;
}

INCLUDE_ASM("asm/nonmatchings/game/t_22BD90", func_0022C3C8);

INCLUDE_ASM("asm/nonmatchings/game/t_22BD90", func_0022C498);

INCLUDE_ASM("asm/nonmatchings/game/t_22BD90", func_0022C4E8);

GP_DATA(D_00372E50);
extern "C" void func_0022C4F0(int a, int b) {
    if (b == 0xFFFF) {
        if (a) {
            func_001162E8(&D_00372E50);
            u16* d = (u16*)D_00393AD8;
            u16* t = d + 1;
            t[1] = 0;
            t[2] = 0;
        }
    }
}

extern "C" void func_0022C538(void) {
    func_0022C4F0(1, 0xFFFF);
}

INCLUDE_ASM("asm/nonmatchings/game/t_22BD90", func_0022C558);

INCLUDE_ASM("asm/nonmatchings/game/t_22BD90", func_0022C768);

INCLUDE_ASM("asm/nonmatchings/game/t_22BD90", func_0022C850);

INCLUDE_ASM("asm/nonmatchings/game/t_22BD90", func_0022CA20);

INCLUDE_ASM("asm/nonmatchings/game/t_22BD90", func_0022CB10);

INCLUDE_ASM("asm/nonmatchings/game/t_22BD90", func_0022CB18);

INCLUDE_ASM("asm/nonmatchings/game/t_22BD90", func_0022CBA8);

INCLUDE_ASM("asm/nonmatchings/game/t_22BD90", func_0022CBC0);

INCLUDE_ASM("asm/nonmatchings/game/t_22BD90", func_0022CC78);

extern "C" void* func_0022CD30(char* p) {
    func_0022BA90(p);
    *(int*)(p + 0x38) = 0;
    *(u8**)(p + 0x34) = D_00352F88;
    return p;
}

INCLUDE_ASM("asm/nonmatchings/game/t_22BD90", func_0022CD68);

extern "C" void func_0022CEF8(char* p, int a, int b, int c, int d, int e) {
    register int rb asm("$17") = b;
    register int rc asm("$18") = c;
    int v = a;
    if (rc) {
        VE22B* f = (VE22B*)(*(char**)(p + 0x34) + 0x70);
        v = ((int (*)(char*))f->fn)(p + f->delta);
    }
    func_0022BCE0(p, v, rb, rc, d, e);
}

INCLUDE_ASM("asm/nonmatchings/game/t_22BD90", func_0022CF80);

extern "C" void func_0022D048(char* p) {
    VE22B* e = (VE22B*)(*(char**)(p + 0x34) + 0x10);
    if (((int (*)(char*))e->fn)(p + e->delta)) {
        VE22B* f = (VE22B*)(*(char**)(p + 0x34) + 0x10);
        char* o = (char*)((int (*)(char*))f->fn)(p + f->delta);
        if (o) {
            VE22B* g = (VE22B*)(*(char**)(o + 8) + 8);
            ((void (*)(char*, int))g->fn)(o + g->delta, 3);
        }
    }
    func_0022BD90(p);
}

extern "C" void func_0022D0C0(int* p) {
    if (p[14]) {
        func_0011D220(p[14]);
    } else {
        if (p[5]) func_0011A470(p[5]);
    }
    p[14] = 0;
    p[5] = 0;
}

extern "C" void* func_0022D118(void) {
    return D_00352F78;
}

extern "C" int func_0022D128(void) {
    return 6;
}

INCLUDE_ASM("asm/nonmatchings/game/t_22BD90", func_0022D130);

INCLUDE_ASM("asm/nonmatchings/game/t_22BD90", func_0022D160);

extern "C" void func_0022D240(char* p, int a, int b, int c, int d, int e) {
    register int rb asm("$17") = b;
    register int rc asm("$18") = c;
    int v = a;
    if (rc) {
        VE22B* f = (VE22B*)(*(char**)(p + 0x34) + 0x70);
        v = ((int (*)(char*))f->fn)(p + f->delta);
    }
    func_0022BCE0(p, v, rb, rc, d, e);
}

extern "C" void func_0022D2C8(char* p, int a1, int a2) {
    char* o = (char*)func_0022C110((S22B*)p);
    VE22B* e = (VE22B*)(*(char**)(o + 0x34) + 0x10);
    int r = ((int (*)(char*))e->fn)(o + e->delta);
    char* q = *(char**)(p + 0x18);
    int w = func_0014E560((int)q, a1, r, *(int*)(q + 0x94), *(int*)(q + 0x98), *(int*)(q + 0x9C), *(int*)(q + 0xA0));
    VE22B* f = (VE22B*)(*(char**)(p + 0x34) + 0x58);
    ((void (*)(char*, int))f->fn)(p + f->delta, w);
    func_0022BE60_3(p, a1, a2);
}

INCLUDE_ASM("asm/nonmatchings/game/t_22BD90", func_0022D360);

extern "C" void func_0022D538(char* p) {
    VE22B* e = (VE22B*)(*(char**)(p + 0x34) + 0x10);
    if (((int (*)(char*))e->fn)(p + e->delta)) {
        VE22B* f = (VE22B*)(*(char**)(p + 0x34) + 0x10);
        func_0014E708(((int (*)(char*))f->fn)(p + f->delta), 0);
    }
    func_0022BD90(p);
}

extern "C" void* func_0022D5A0(void) {
    return D_0036F838;
}

extern "C" int func_0022D5B0(void) {
    return 3;
}

INCLUDE_ASM("asm/nonmatchings/game/t_22BD90", func_0022D5B8);

extern "C" int func_0022D5E0(void) {
    return 0xA4;
}

INCLUDE_ASM("asm/nonmatchings/game/t_22BD90", func_0022D5E8);

extern "C" void func_0022D6A0(char* p, int a, int b, int c, int d, int e) {
    register int rb asm("$17") = b;
    register int rc asm("$18") = c;
    int v = a;
    if (rc) {
        VE22B* f = (VE22B*)(*(char**)(p + 0x34) + 0x70);
        v = ((int (*)(char*))f->fn)(p + f->delta);
    }
    func_0022BCE0(p, v, rb, rc, d, e);
}

INCLUDE_ASM("asm/nonmatchings/game/t_22BD90", func_0022D728);

INCLUDE_ASM("asm/nonmatchings/game/t_22BD90", func_0022D7E0);

extern "C" void func_0022D940(char* p) {
    VE22B* e = (VE22B*)(*(char**)(p + 0x34) + 0x10);
    if (((int (*)(char*))e->fn)(p + e->delta)) {
        char* o = (char*)func_0022C110((S22B*)p);
        VE22B* f = (VE22B*)(*(char**)(o + 0x34) + 0x10);
        func_00150DE8(((int (*)(char*))f->fn)(o + f->delta));
    }
    func_0022BD90(p);
}

extern "C" void* func_0022D9A8(void) {
    return D_003532D0;
}

extern "C" int func_0022D9B8(void) {
    return 5;
}

INCLUDE_ASM("asm/nonmatchings/game/t_22BD90", func_0022D9C0);

extern "C" int func_0022D9E8(void) {
    return 0x98;
}

extern "C" void* func_0022D9F0(char* p) {
    func_0022BA90(p);
    *(int*)(p + 0x38) = 0;
    *(u8**)(p + 0x34) = D_00353480;
    return p;
}

extern "C" void func_0022DA28(char* p, int a1, int a2, int a3, int a4, int a5) {
    VE22B* e = (VE22B*)(*(char**)(p + 0x34) + 0x78);
    ((void (*)(char*, int, int))e->fn)(p + e->delta, a4, a5);
    int t = *(int*)(p + 0x18);
    func_0030B550(t, D_0036F8D8, a1, func_0014F130());
    func_0022BBB0(p, *(int*)(p + 0x18), a2, a3, a4, a5);
}

extern "C" void func_0022DAF0(char* p, int a1, int a2) {
    int t = func_0030E720(*(int*)(p + 0x18), D_0036F8E0);
    func_0030B550_3(t, D_0036F8E8, func_0014F130());
    func_00287EB0(*(int*)(p + 0x18), a1, 1);
    *(int*)(p + 0x38) = func_0028DAB8(*(int*)(p + 0x18));
    VE22B* e = (VE22B*)(*(char**)(p + 0x34) + 0x58);
    ((void (*)(char*, int))e->fn)(p + e->delta, a1);
    func_0022BE60_3(p, a1, a2);
}

extern "C" void func_0022DBB0(char* p, int a, int b, int c, int d, int e) {
    register int rb asm("$17") = b;
    register int rc asm("$18") = c;
    int v = a;
    if (rc) {
        VE22B* f = (VE22B*)(*(char**)(p + 0x34) + 0x70);
        v = ((int (*)(char*))f->fn)(p + f->delta);
    }
    func_0022BCE0(p, v, rb, rc, d, e);
}

INCLUDE_ASM("asm/nonmatchings/game/t_22BD90", func_0022DC38);

extern "C" void func_0022DD30(char* p) {
    VE22B* e = (VE22B*)(*(char**)(p + 0x34) + 0x10);
    if (((int (*)(char*))e->fn)(p + e->delta)) {
        VE22B* f = (VE22B*)(*(char**)(p + 0x34) + 0x10);
        func_002886F8(((int (*)(char*))f->fn)(p + f->delta));
        func_0028D700(*(int*)(p + 0x38));
    }
    func_0022BD90(p);
}
