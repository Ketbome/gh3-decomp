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
extern int D_00368A94;
extern int D_0032A4A0[];
extern int D_00368A38[] __attribute__((section(".sdata")));
extern u8 D_00338968[];
extern u8 D_00338898[];
extern u8 D_00414348[];
void func_00119DD8(int);
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

INCLUDE_ASM("asm/nonmatchings/game/t_118E40", func_00118E40);

INCLUDE_ASM("asm/nonmatchings/game/t_118E40", func_00118EF8);

INCLUDE_ASM("asm/nonmatchings/game/t_118E40", func_00118F20);

INCLUDE_ASM("asm/nonmatchings/game/t_118E40", func_00119098);

INCLUDE_ASM("asm/nonmatchings/game/t_118E40", func_00119138);

extern "C" void func_00119180(SA118_H* self) {
    SA118_V* o = *(SA118_V**)self->unk190;
    VEntry* e = &o->unk98[5];
    ((void (*)(void*))e->fn)((char*)o + e->delta);
}

INCLUDE_ASM("asm/nonmatchings/game/t_118E40", func_001191B0);

INCLUDE_ASM("asm/nonmatchings/game/t_118E40", func_00119270);

INCLUDE_ASM("asm/nonmatchings/game/t_118E40", func_00119330);

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

INCLUDE_ASM("asm/nonmatchings/game/t_118E40", func_00119570);

INCLUDE_ASM("asm/nonmatchings/game/t_118E40", func_001195C0);

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

INCLUDE_ASM("asm/nonmatchings/game/t_118E40", func_00119CC0);

INCLUDE_ASM("asm/nonmatchings/game/t_118E40", func_00119D40);

INCLUDE_ASM("asm/nonmatchings/game/t_118E40", func_00119DA0);

INCLUDE_ASM("asm/nonmatchings/game/t_118E40", func_00119DD8);

INCLUDE_ASM("asm/nonmatchings/game/t_118E40", func_00119E60);

INCLUDE_ASM("asm/nonmatchings/game/t_118E40", func_00119F60);

INCLUDE_ASM("asm/nonmatchings/game/t_118E40", func_0011A0B0);

extern "C" void func_0011A100(void) {
    if (D_00368A38[0]) {
        func_00119DD8(D_00368A38[0]);
    }
}

INCLUDE_ASM("asm/nonmatchings/game/t_118E40", func_0011A128);

INCLUDE_ASM("asm/nonmatchings/game/t_118E40", func_0011A170);

extern "C" int func_0011A208(void* self, u32 key, int c) {
    SA118_K* p = func_0011A170(self, key);
    if (p) {
        return p->unk4;
    }
    return 0;
}

INCLUDE_ASM("asm/nonmatchings/game/t_118E40", func_0011A230);

INCLUDE_ASM("asm/nonmatchings/game/t_118E40", func_0011A300);

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

INCLUDE_ASM("asm/nonmatchings/game/t_118E40", func_0011A498);

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

INCLUDE_ASM("asm/nonmatchings/game/t_118E40", func_0011A788);

INCLUDE_ASM("asm/nonmatchings/game/t_118E40", func_0011A7C0);

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

INCLUDE_ASM("asm/nonmatchings/game/t_118E40", func_0011A988);

INCLUDE_ASM("asm/nonmatchings/game/t_118E40", func_0011A9E8);

INCLUDE_ASM("asm/nonmatchings/game/t_118E40", func_0011AA28);

INCLUDE_ASM("asm/nonmatchings/game/t_118E40", func_0011AA58);

INCLUDE_ASM("asm/nonmatchings/game/t_118E40", func_0011AB60);

INCLUDE_ASM("asm/nonmatchings/game/t_118E40", func_0011ABF8);

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

INCLUDE_ASM("asm/nonmatchings/game/t_118E40", func_0011AD10);

extern "C" void func_0011AD78(S_0011AD78* self, int v) {
    self->unk5C = v;
}

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
