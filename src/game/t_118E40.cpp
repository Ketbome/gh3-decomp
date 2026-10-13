#include "common.h"

struct S_0011A8D0 { char pad0[0xC]; int unkC; };
struct S_0011A8E8 { char pad0[0x10]; int unk10; };
struct S_0011A8F0 { char pad0[0x10]; int unk10; };
struct S_0011ACF8 { char pad0[0x20]; int unk20; };
struct S_0011AD00 { char pad0[0x2C]; int unk2C; };
struct S_0011AD08 { char pad0[0x8]; int unk8; };
struct S_0011AD78 { char pad0[0x5C]; int unk5C; };

struct S_00119500 { char pad0[0x190]; int* unk190; };
struct S_00119510_b { char pad0[0x38]; int unk38; };
struct S_00119510 { char pad0[0x190]; S_00119510_b** unk190; };
struct S_0011A8D8 { char pad0[0x4]; int unk4; char pad1[0xC]; int unk14; };

struct S_0011A680_b { char pad0[0x38]; int unk38; };
struct S_0011A680 { char pad0[0x18]; int unk18[2]; };

struct S_0011A620 { char pad0[0x4]; int unk4; char pad1[0x4]; int unkC; int unk10; int unk14; int unk18; int unk1C; };

struct VEntry {
    s16 delta;
    s16 unk2;
    void* fn;
};

struct SA118_V {
    char pad0[0x98];
    VEntry* unk98;
};

struct SA118_H {
    char pad0[0x190];
    u32* unk190;
    u32 unk194[16];
    int unk1D4;
    char pad1D8[0x8];
    int unk1E0;
};

struct SA118_K {
    char pad0[0x4];
    int unk4;
};

struct SA118_A {
    char pad0[0x4];
    int unk4;
    int unk8;
};

struct SA118_T {
    char pad0[0x38];
    int unk38;
    int unk3C;
};

struct SA118_B {
    char pad0[0x4];
    int unk4;
    char pad8[0xC];
    int unk14;
    SA118_T* unk18[2];
};

struct SA118_L {
    char pad0[0x4];
    void* unk4;
    int unk8;
    SA118_L* unkC;
    SA118_L* unk10;
    void* unk14;
};

struct SA118_C {
    char pad0[0x4];
    SA118_L unk4;
    int unk1C;
};

extern "C" {
extern u8 D_003388D8[];
void func_0011A680_i(int, void*) __asm__("func_0011A680");
void func_0030A3A0(void*, void*, int);
void* func_0011A170_1(void*) __asm__("func_0011A170");
u32 func_0030AA88(char*);
void func_0030ADA0(char*, char*, u32);
void func_00119990(void*, int);
void* func_00113D20(u32);
extern char D_00338690[];
void func_0030B550(char*, const char*, ...);
u32 func_001150B8(const char*);
extern char D_00338680[];
void func_0030A49C(void*, int, void*);
void* func_00118F20_0(void) __asm__("func_00118F20");
int func_0011AF08(int);
extern int D_00368A98;
extern int D_00368A94;
extern int D_0032A4A0[];
extern int D_00368A38[] __attribute__((section(".sdata")));
extern u8 D_00338968[];
extern u8 D_00338898[];
extern u8 D_00414348[];
void func_00119DD8(int);
void func_00119F60(int);
void func_001194B8(int);
void func_00118E40(int, int);
void WaitSemaphore(void);
SA118_K* func_0011A170(void*, u32);
void func_00119400(int, void*);
void* func_00118F20(int, int, int, int);
void* func_001191B0(int, int, int, int);
void* func_00119270(int, int, int, int);
void* func_00119330(int, int, int, int);
int func_00113E70(int, void*);
int func_00118C80(int);
void func_00119490(SA118_H*, u32);
extern int D_003689E0;
void func_00119730(void);
void func_001198F0(void);
int func_0011A208(void*, u32, int);
}

extern "C" void func_0011A470(void*);
struct O98_00118E40 { char pad0[0x98]; VEntry* unk98; };
struct O20_00118E40 { char pad0[0x20]; VEntry* unk20; };
struct S_00118E40 { char pad0[0x1D8]; O20_00118E40* unk1D8; O98_00118E40* unk1DC; O98_00118E40* unk1E0; char pad1E4[0xA74]; int unkC58; int unkC5C; };

extern "C" void func_00118E40(int a, int flags) {
    S_00118E40* self = (S_00118E40*)a;
    if (self->unkC58) {
        func_0011A470((void*)self->unkC58);
        self->unkC58 = 0;
        self->unkC5C = 0;
    }
    O98_00118E40* o = self->unk1DC;
    VEntry* e = &o->unk98[3];
    ((void (*)(void*, int))e->fn)((char*)o + e->delta, 2);
    o = self->unk1E0;
    e = &o->unk98[3];
    ((void (*)(void*, int))e->fn)((char*)o + e->delta, 2);
    O20_00118E40* p = self->unk1D8;
    e = &p->unk20[1];
    ((void (*)(void*, int))e->fn)((char*)p + e->delta, 2);
    WaitSemaphore();
    if (flags & 1) func_00119400(D_00368A38[0], (void*)a);
}

INCLUDE_ASM("asm/nonmatchings/game/t_118E40", func_00118EF8);

INCLUDE_ASM("asm/nonmatchings/game/t_118E40", func_00118F20);

extern "C" int func_00119500(S_00119500*);
extern "C" void func_0011A9E8(int);
extern "C" void func_001187F8(void*);
extern "C" void func_00118820(void*);
extern "C" int func_00118BD8(int, int);

extern "C" int func_00119098(int self, int a, int b, SA118_V* o) {
    char loc[0x10];
    func_001187F8(loc);
    if (!o) o = (SA118_V*)func_00119500((S_00119500*)self);
    VEntry* e = &o->unk98[4];
    int r = ((int (*)(void*, int, int))e->fn)((char*)o + e->delta, a, b);
    if (r) func_0011A9E8(r);
    func_00118820(loc);
    return r;
}

extern "C" void* func_00119138(int a, void* b) {
    void* p = func_00118F20_0();
    if (p) func_0030A49C(p, 0, b);
    return p;
}

extern "C" void func_00119180(SA118_H* self) {
    SA118_V* o = *(SA118_V**)self->unk190;
    VEntry* e = &o->unk98[5];
    ((void (*)(void*))e->fn)((char*)o + e->delta);
}

extern "C" void* func_001191B0(int self, int a, int b, int obj) {
    SA118_V* o = (SA118_V*)obj;
    char loc[0x10];
    func_001187F8(loc);
    if (!o) o = (SA118_V*)func_00119500((S_00119500*)self);
    if (func_00118BD8(self, b) >= 0) {
        func_00118820(loc);
        return (void*)0;
    }
    VEntry* e = &o->unk98[6];
    int r = ((int (*)(void*, int, int))e->fn)((char*)o + e->delta, a, b);
    if (r) func_0011A9E8(r);
    func_00118820(loc);
    return (void*)r;
}

extern "C" void* func_00119270(int self, int a, int b, int obj) {
    SA118_V* o = (SA118_V*)obj;
    char loc[0x10];
    func_001187F8(loc);
    if (!o) o = (SA118_V*)func_00119500((S_00119500*)self);
    if (func_00118BD8(self, b) >= 0) {
        func_00118820(loc);
        return (void*)0;
    }
    VEntry* e = &o->unk98[7];
    int r = ((int (*)(void*, int, int))e->fn)((char*)o + e->delta, a, b);
    if (r) func_0011A9E8(r);
    func_00118820(loc);
    return (void*)r;
}

extern "C" void* func_00119330(int self, int a, int b, int obj) {
    SA118_V* o = (SA118_V*)obj;
    char loc[0x10];
    func_001187F8(loc);
    if (!o) o = (SA118_V*)func_00119500((S_00119500*)self);
    if (func_00118BD8(self, b) >= 0) {
        func_00118820(loc);
        return (void*)b;
    }
    VEntry* e = &o->unk98[8];
    int r = ((int (*)(void*, int, int))e->fn)((char*)o + e->delta, a, b);
    if (r) func_0011A9E8(r);
    func_00118820(loc);
    return (void*)r;
}

extern "C" void func_001193F0(void) {
}

extern "C" void func_001193F8(void) {
}

INCLUDE_ASM("asm/nonmatchings/game/t_118E40", func_00119400);

INCLUDE_ASM("asm/nonmatchings/game/t_118E40", func_00119488);

INCLUDE_ASM("asm/nonmatchings/game/t_118E40", func_00119490);

INCLUDE_ASM("asm/nonmatchings/game/t_118E40", func_001194B8);

extern "C" int func_00119500(S_00119500* self) {
    return *self->unk190;
}

extern "C" int func_00119510(S_00119510* self) {
    return (*self->unk190)->unk38;
}

extern "C" void func_00119520(void* self) {
    func_0011A208(self, 0x08682D24 /* skaterinfoheap */, 1);
}

extern "C" void func_00119548(void* self) {
    func_0011A208(self, 0xCD4FB93F /* profilerheap */, 1);
}

extern "C" void func_00119570(void* a, char* b) {
    char buf[0x20];
    func_0030B550(buf, D_00338680, b);
    func_0011A208(a, func_001150B8(buf), 1);
}

extern "C" void func_001195C0(void* a, char* b) {
    char buf[0x20];
    func_0030B550(buf, D_00338690, b);
    func_0011A208(a, func_001150B8(buf), 1);
}

INCLUDE_ASM("asm/nonmatchings/game/t_118E40", func_00119610);

extern "C" void func_00119710(void) {
    func_00119730();
}

INCLUDE_ASM("asm/nonmatchings/game/t_118E40", func_00119730);

extern "C" int func_001198E8(void) {
    return -1;
}

INCLUDE_ASM("asm/nonmatchings/game/t_118E40", func_001198F0);

extern "C" void func_00119970(void) {
    func_001198F0();
}

INCLUDE_ASM("asm/nonmatchings/game/t_118E40", func_00119990);

INCLUDE_ASM("asm/nonmatchings/game/t_118E40", func_00119A38);

INCLUDE_ASM("asm/nonmatchings/game/t_118E40", func_00119A60);

INCLUDE_ASM("asm/nonmatchings/game/t_118E40", func_00119B38);

struct S11A7C0 { char pad0[0x4]; int unk4; int unk8; char pad0C[0x14]; void* unk20; };
struct S119CC0 { char pad0[0x220]; void* unk220; int unk224; };
extern "C" int func_001198F0_4(void*, void*, int, void*) __asm__("func_001198F0");
extern "C" S11A7C0* func_0011A7C0(S11A7C0*, unsigned);
extern u8 D_00368A28[];

extern "C" void func_00119CC0(S119CC0* self) {
    if (!self->unk220) {
        func_00119490((SA118_H*)D_00368A38[0], ((SA118_H*)D_00368A38[0])->unk1E0);
        S11A7C0* o = func_0011A7C0((S11A7C0*)func_00113D20(0x24), 0x27100);
        self->unk220 = o;
        int r = func_001198F0_4(self, o, 1, D_00368A28);
        int g = D_00368A38[0];
        self->unk224 = r;
        func_001194B8(g);
    }
}

struct VE_119D40 { s16 unk0; s16 unk2; void (*unk4)(void*, int); };
struct V_119D40 { char pad0[8]; VE_119D40 unk8; };
struct O_119D40 { char pad0[0x20]; V_119D40* unk20; };
struct S_119D40 { char pad0[0x220]; O_119D40* unk220; int unk224; };

extern "C" void func_00119D40(S_119D40* self) {
    if (self->unk220) {
        func_00119990(self, self->unk224);
        O_119D40* o = self->unk220;
        self->unk224 = 0;
        if (o) {
            V_119D40* v = o->unk20;
            v->unk8.unk4((char*)o + v->unk8.unk0, 3);
        }
        self->unk220 = 0;
    }
}

INCLUDE_ASM("asm/nonmatchings/game/t_118E40", func_00119DA0);

extern "C" S_0011A8E8* func_0011A788_3(void*, int, int) __asm__("func_0011A788");
extern "C" void func_0011A8E8(S_0011A8E8*, int);
extern u8 D_00414320[];
extern u8 D_310000F[];
extern u8 D_58FFC00[];
extern u8 D_00368A30[];
struct S119DD8 { char pad0[0x24C]; S_0011A8E8* unk24C; int unk250; };

extern "C" void func_00119DD8(int a) {
    S119DD8* self = (S119DD8*)a;
    S_0011A8E8* o = func_0011A788_3((void*)func_00113E70(0x24, D_00414320), (u32)D_310000F & 0xFFFFFFF0u, (u32)D_58FFC00 & 0xFFFFFFF0u);
    self->unk24C = o;
    self->unk250 = func_001198F0_4(self, o, 1, D_00368A30);
    func_0011A8E8(self->unk24C, 0);
}

extern "C" void func_0011A300_3(int, u32, int) __asm__("func_0011A300");

INCLUDE_ASM("asm/nonmatchings/game/t_118E40", func_00119E60);

INCLUDE_ASM("asm/nonmatchings/game/t_118E40", func_00119F60);

INCLUDE_ASM("asm/nonmatchings/game/t_118E40", func_0011A0B0);

extern "C" void func_0011A100(void) {
    if (D_00368A38[0]) {
        func_00119DD8(D_00368A38[0]);
    }
}

extern "C" void func_0011A128(void) {
    if (D_00368A38[0]) {
        func_00119F60(D_00368A38[0]);
        func_001194B8(D_00368A38[0]);
        func_00118E40(D_00368A38[0], 2);
        D_00368A38[0] = 0;
    }
}

INCLUDE_ASM("asm/nonmatchings/game/t_118E40", func_0011A170);

extern "C" int func_0011A208(void* self, u32 key, int c) {
    SA118_K* p = func_0011A170(self, key);
    if (p) {
        return p->unk4;
    }
    return 0;
}

INCLUDE_ASM("asm/nonmatchings/game/t_118E40", func_0011A230);

struct VE_11A300 { s16 unk0; s16 unk2; void (*unk4)(void*, int); };
struct V_11A300 { char pad0[8]; VE_11A300 unk8; };
struct O_11A300 { char pad0[0x20]; V_11A300* unk20; };
struct E_11A300 { O_11A300* unk0; int unk4; int unk8; char padC[0x40]; int unk4C; };

extern "C" int func_0011A300(void* a) {
    E_11A300* e = (E_11A300*)func_0011A170_1(a);
    int r = 0;
    if (e) {
        func_00119990(a, e->unk4);
        O_11A300* o = e->unk0;
        if (o) {
            V_11A300* v = o->unk20;
            v->unk8.unk4((char*)o + v->unk8.unk0, 3);
        }
        r = 1;
        e->unk0 = 0;
        e->unk4 = 0;
        e->unk8 = 0;
        e->unk4C = 0;
    }
    return r;
}

INCLUDE_ASM("asm/nonmatchings/game/t_118E40", func_0011A378);

extern "C" void* func_0011A380(int size) {
    return func_00118F20(D_00368A38[0], size, 1, 0);
}

INCLUDE_ASM("asm/nonmatchings/game/t_118E40", func_0011A3B0);

extern "C" void* func_0011A3E0(int a, int b) {
    return func_001191B0(D_00368A38[0], a, b, 0);
}

extern "C" void* func_0011A410(int a, int b) {
    return func_00119270(D_00368A38[0], a, b, 0);
}

extern "C" void* func_0011A440(int a, int b) {
    return func_00119330(D_00368A38[0], a, b, 0);
}

extern "C" void func_0011A470(void* p) {
    func_00119400(D_00368A38[0], p);
}

extern "C" void* func_0011A498(void* a, int n) {
    void* r = 0;
    if (n) r = func_00118F20(D_00368A38[0], n, 1, 0);
    if (a) {
        if (r) func_0030A3A0(r, a, n);
        func_00119400(D_00368A38[0], a);
    }
    return r;
}

extern "C" void* func_0011A520(int n, int size) {
    return func_00118F20(D_00368A38[0], n * size, 1, 0);
}

extern "C" void func_0011A550(int v) {
    D_003689E0 = v;
}

extern "C" void func_0011A558(void) {
}

extern "C" void func_0011A560(void) {
}

extern "C" void func_0011A568(void) {
}

extern "C" void func_0011A570(void) {
}

extern "C" void func_0011A578(void) {
}

extern "C" void func_0011A580(void) {
}

extern "C" int func_0011A588(void) {
    return 0;
}

extern "C" int func_0011A590(void) {
    return 0;
}

extern "C" void func_0011A598(void) {
}

extern "C" void func_0011A5A0(void) {
}

extern "C" void func_0011A5A8(void) {
}

INCLUDE_ASM("asm/nonmatchings/game/t_118E40", func_0011A5B0);

extern "C" int func_0011A5B8(SA118_A* self, int i) {
    if (self->unk4 == 1) {
        return self->unk8;
    }
    return ((int*)self->unk8)[i];
}

extern "C" void func_0011A5E0(void* self, int flags) {
    ((void**)self)[8] = D_00338898;
    if (flags & 1) {
        func_00119400(D_00368A38[0], self);
    }
}

extern "C" void func_0011A620(S_0011A620* self, int a, int b) {
    self->unk10 = 1;
    self->unk4 = a;
    self->unk14 = b;
    self->unk1C = 0;
    self->unk18 = 0;
    self->unkC = b - a;
}

extern "C" void func_0011A648(SA118_B* self, SA118_T* t) {
    self->unk18[(t->unk38 >> 1) & 1] = t;
    t->unk3C = (t->unk38 == 1) ? self->unk4 : self->unk14;
}

extern "C" void func_0011A680(S_0011A680* self, S_0011A680_b* o) {
    self->unk18[(o->unk38 >> 1) & 1] = 0;
}

INCLUDE_ASM("asm/nonmatchings/game/t_118E40", func_0011A6A0);

struct S11A788 { char pad0[0x20]; void* unk20; };
extern "C" void func_0011A620_1(void*) __asm__("func_0011A620");

extern "C" S11A788* func_0011A788(S11A788* self) {
    self->unk20 = D_00338898;
    func_0011A620_1(self);
    return self;
}

extern u8 D_00338880[];

extern "C" S11A7C0* func_0011A7C0(S11A7C0* self, unsigned size) {
    self->unk20 = D_00338880;
    if (size) {
        size &= ~0xF;
        int p = (int)func_00118F20(D_00368A38[0], size, 1, 0);
        self->unk4 = p;
        func_0011A620((S_0011A620*)self, p, p + size);
    }
    self->unk8 = 1;
    return self;
}

INCLUDE_ASM("asm/nonmatchings/game/t_118E40", func_0011A840);

extern "C" int func_0011A8A8(SA118_B* self) {
    int a;
    int b;
    if (self->unk18[0]) {
        a = self->unk18[0]->unk3C;
    } else {
        a = self->unk4;
    }
    if (self->unk18[1]) {
        b = self->unk18[1]->unk3C;
    } else {
        b = self->unk14;
    }
    return b - a;
}

extern "C" int func_0011A8D0(S_0011A8D0* self) {
    return self->unkC;
}

extern "C" int func_0011A8D8(S_0011A8D8* self) {
    return self->unk14 - self->unk4;
}

extern "C" void func_0011A8E8(S_0011A8E8* self, int v) {
    self->unk10 = v;
}

extern "C" int func_0011A8F0(S_0011A8F0* self) {
    return self->unk10;
}

extern "C" SA118_C* func_0011A8F8(SA118_C* self) {
    SA118_L* p = &self->unk4;
    p->unk10 = p;
    p->unk4 = self;
    p->unk8 = 0;
    p->unkC = p;
    p->unk14 = D_00338968;
    self->unk1C = 0;
    return self;
}

extern "C" void func_0011A928(SA118_C* self, int flags) {
    SA118_L* p = &self->unk4;
    p->unk14 = D_00338968;
    p->unk10->unkC = p->unkC;
    p->unkC->unk10 = p->unk10;
    p->unkC = p;
    p->unk10 = p;
    if (flags & 1) {
        func_00119400(D_00368A38[0], self);
    }
}

struct S11A988 { SA118_V* unk0; unsigned int unk4; };

extern "C" S11A988* func_0011AA28(int v);

extern "C" SA118_V* func_0011A988(int v) {
    S11A988* p = func_0011AA28(v);
    SA118_V* o = p->unk0;
    VEntry* e = &o->unk98[9];
    ((void (*)(void*, void*))e->fn)((char*)o + e->delta, p);
    p->unk4 = 0xDEADDEAD;
    return o;
}

struct S11A9E8 { char pad0[4]; unsigned int unk4; };

GP_DATA(D_00368A98);
extern "C" void func_0011A9E8(int v) {
    int t = v - D_00368A98;
    ((S11A9E8*)(t - func_0011AF08(t)))->unk4 = 0xCF801FE1;
}

GP_DATA(D_00368A98);
extern "C" S11A988* func_0011AA28(int v) {
    int t = v - D_00368A98;
    return (S11A988*)(t - func_0011AF08(t));
}

INCLUDE_ASM("asm/nonmatchings/game/t_118E40", func_0011AA58);

struct S11AB60 { char pad0[0x34]; int unk34; char pad38[0x28]; SA118_L unk60; char pad78[0x20]; void* unk98; };

extern "C" void func_0011AB60(S11AB60* self, int flags) {
    self->unk98 = D_003388D8;
    func_0011A680_i(self->unk34, self);
    func_0011A928((SA118_C*)((char*)self + 0x78), 2);
    SA118_L* p = &self->unk60;
    p->unk14 = D_00338968;
    p->unk10->unkC = p->unkC;
    p->unkC->unk10 = p->unk10;
    p->unkC = p;
    p->unk10 = p;
    if (flags & 1) {
        func_00119400(D_00368A38[0], self);
    }
}

struct S11ABF8 { char pad0[0x40]; SA118_C* unk40; char pad44[0x1C]; SA118_L unk60; };

extern "C" void func_0011ABF8(S11ABF8* self) {
    SA118_C* n = func_0011A8F8((SA118_C*)func_00113D20(0x20));
    SA118_L* p = &self->unk60;
    SA118_L* q = &n->unk4;
    q->unk10 = p;
    q->unkC = p->unkC;
    p->unkC->unk10 = q;
    p->unkC = q;
    self->unk40 = n;
}

INCLUDE_ASM("asm/nonmatchings/game/t_118E40", func_0011AC50);

INCLUDE_ASM("asm/nonmatchings/game/t_118E40", func_0011ACD0);

extern "C" int func_0011ACF8(S_0011ACF8* self) {
    return self->unk20;
}

extern "C" int func_0011AD00(S_0011AD00* self) {
    return self->unk2C;
}

extern "C" int func_0011AD08(S_0011AD08* self) {
    return self->unk8;
}

extern "C" void func_0011AD10(char* self, char* s) {
    u32 n = func_0030AA88(s);
    char* d = self + 0x44;
    u32 m = (n < 0x18U) ? n : 0x17U;
    func_0030ADA0(d, s, m);
    d[m] = 0;
}

extern "C" void func_0011AD78(S_0011AD78* self, int v) {
    self->unk5C = v;
}

GP_DATA(D_00368A94);
extern "C" void func_0011AD80(int unused, int flag) {
    int i = ++D_00368A94;
    switch (flag) {
    case 0x4:
        D_0032A4A0[i] = 2;
        break;
    case 0x8:
        D_0032A4A0[i] = 3;
        break;
    case 0x10:
        D_0032A4A0[i] = 4;
        break;
    case 0x20:
        D_0032A4A0[i] = 5;
        break;
    case 0x40:
        D_0032A4A0[i] = 6;
        break;
    case 0x80:
        D_0032A4A0[i] = 7;
        break;
    case 0x100:
        D_0032A4A0[i] = 8;
        break;
    case 0x800:
        D_0032A4A0[i] = 11;
        break;
    }
}
