// cflags: -funroll-loops
#include "common.h"

struct S_00127818 { float unk0; };
struct S_00127820 { char pad0[0x4]; float unk4; };
struct S_00127828 { char pad0[0x8]; float unk8; };
struct S_00127830 { char pad0[0xC]; float unkC; };
struct S_00127940 { char pad0[0x8]; int unk8; };
struct S_001288F0 { char pad0[0xC]; float unkC; };

struct S_00128A80 { char pad0[0x404]; s16 unk404; };
struct S_00129070 { char pad0[0x480]; int unk480; };

struct S_00127838 { int unk0; int unk4; int unk8; void* unkC; };

struct SA127_K {
    S_00127838 unk0;
    int unk10;
};

struct SA127_F {
    S_00127838 unk0;
    float unk10;
};

struct SA127_P {
    char pad0[0x4];
    int unk4;
};

struct SA127_Q {
    char pad0[0xC];
    SA127_P* unkC;
};

struct SA127_Z {
    char pad0[0x4];
    int unk4;
    char pad8[0x4];
    int unkC;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    char pad20[0x4];
    int unk24;
    char pad28[0x48];
    u8 unk70;
    u8 unk71;
    char pad72[0x392];
    s16 unk404;
    char pad406[0x6E];
    u16 unk474;
    u8 unk476;
    char pad477[0x9];
    int unk480;
};

struct VE_001284B0 { char pad0[0x40]; s16 unk40; s16 unk42; void (*unk44)(void*); };
struct SA127_VO { char pad0[0x8]; VE_001284B0* unk8; };

extern "C" {
void* Heap_Alloc(int, int, int, int);
void* func_0030A2F4(char*, char*, int);
void* func_00127B10(void*, int, void*, void*, int);
int func_0027D1F8(int, int, void*, int);
int func_0027D268(int, int, void*, int);
int func_0027D400(int, int, void*, int);
void func_0011A230(int, int, int, void*, int);
void* operator_new(u32);
int func_00129148(void*);
void func_00129F70(int, int, int);
extern u8 D_00339900[];
void func_0027AC90(int);
void func_00113250(int);
extern u8 D_003398A0[];
int func_002763C0(int, int);
void func_001234B0(void*);
int func_0027AA70(int);
int func_001287F0(int, int);
void func_0027ABB0(int, int);
void func_002765E0(int, int);
void func_0028C9D0(int, int, int, int, int, int);
extern int D_00368A38[] __attribute__((section(".sdata")));
extern u8 D_00339800[];
extern u8 D_00339878[];
extern u8 D_00339850[];
extern u8 D_003397D8[];
extern u8 D_003397B0[];
int func_00125740(void*, int, int, int, int, int);
void Heap_Free(int, void*);
void func_001291E0(int, int);
void func_0011A300(int, u32, int);
void memset(void*, int, int);
int func_00128F48(void*);
extern int D_003690EC;
extern u8 D_003398C8[];
void func_0012A048(void*);
int func_0027D870(int, int, int*, int);
SA127_VO* func_001D0680(int);
}

extern "C" int func_001277C0(SA127_Q* self, int a, int b, int c, int d, int e) {
    if (self->unkC->unk4 & 0x800000) {
        return func_00125740(self, a, b, c, d, e);
    }
    return 0;
}

INCLUDE_ASM("asm/nonmatchings/game/t_1277C0", func_001277F8);

extern "C" void func_00127818(S_00127818* self, float v) {
    self->unk0 = v;
}

extern "C" void func_00127820(S_00127820* self, float v) {
    self->unk4 = v;
}

extern "C" void func_00127828(S_00127828* self, float v) {
    self->unk8 = v;
}

extern "C" void func_00127830(S_00127830* self, float v) {
    self->unkC = v;
}

extern "C" S_00127838* func_00127838(S_00127838* self, int a, int b) {
    self->unkC = D_003398C8;
    self->unk0 = a;
    self->unk4 = b;
    self->unk8 = 0;
    return self;
}

struct S127858 { char pad0[4]; int unk4; };

extern "C" int func_00127858(S127858* self, int incl, float lo, float hi) {
    if (incl) {
        if (lo < hi) {
            float v = (float)self->unk4;
            return lo <= v && v <= hi;
        }
        float v = (float)self->unk4;
        return v <= lo && hi <= v;
    }
    if (lo < hi) {
        float v = (float)self->unk4;
        return lo <= v && v < hi;
    }
    float v = (float)self->unk4;
    return v <= lo && hi < v;
}

extern "C" void func_00127940(S_00127940* self, int v) {
    self->unk8 = v;
}

INCLUDE_ASM("asm/nonmatchings/game/t_1277C0", func_00127948);

extern "C" SA127_F* func_001279A8(SA127_F* self, int a, float f) {
    func_00127838(&self->unk0, 1, a);
    self->unk10 = f;
    self->unk0.unkC = D_00339878;
    return self;
}

struct S1279F8 { char pad0[0x10]; float unk10; };
struct T1279F8 { char pad0[0xD0]; float unkD0; };

extern "C" int func_001279F8(S1279F8* self, T1279F8* o) {
    func_002765E0(0x2F510F45, 0);
    o->unkD0 = self->unk10 * 57.295776f;
    func_001234B0(o);
    return 1;
}

extern "C" SA127_K* func_00127A60(SA127_K* self, int a, int b) {
    func_00127838(&self->unk0, 4, a);
    self->unk10 = b;
    self->unk0.unkC = D_00339850;
    return self;
}

struct S127AB0 { char pad0[0x10]; int unk10; };

extern "C" int func_00127AB0(S127AB0* self, int a) {
    func_002765E0(0x2F510F45, 0);
    func_0028C9D0(self->unk10, 0, a, 0, 0, 0);
    return 1;
}

INCLUDE_ASM("asm/nonmatchings/game/t_1277C0", func_00127B10);

INCLUDE_ASM("asm/nonmatchings/game/t_1277C0", func_00127CD0);

INCLUDE_ASM("asm/nonmatchings/game/t_1277C0", func_00127ED0);

extern "C" S_00127838* func_00128098(S_00127838* self, int a) {
    func_00127838(self, 3, a);
    self->unkC = D_00339800;
    return self;
}

extern "C" int func_001280D8(void) {
    return 1;
}

struct S1280E0 { char pad0[0xC]; void* unkC; char pad10[8]; int unk18; };

extern "C" void func_001280E0(S1280E0* self, int flags) {
    int t = self->unk18;
    self->unkC = D_003398A0;
    if (t) {
        func_0027AC90(t);
        func_00113250(t);
        self->unk18 = 0;
    }
    self->unkC = D_003398C8;
    if (flags & 1) {
        Heap_Free(D_00368A38[0], self);
    }
}

struct S128160 { char pad0[4]; int unk4; int unk8; char padC[4]; int unk10; int unk14; int unk18; };

extern "C" void func_00128160(S128160* self, int a, int b, int c) {
    self->unk4 = a;
    self->unk8 = 0;
    self->unk10 = b;
    int t = func_0027AA70(func_001287F0(8, 1));
    self->unk18 = t;
    if (c) func_0027ABB0(t, c);
}

extern "C" void func_001281C0(S128160* self, int a, int b, int c) {
    self->unk4 = a;
    self->unk8 = 0;
    self->unk14 = b;
    int t = func_0027AA70(func_001287F0(8, 1));
    self->unk18 = t;
    if (c) func_0027ABB0(t, c);
}

extern "C" void func_00128220(S128160* self, int p) {
    int a = 0;
    float f;
    int b;
    int c;
    if ((func_0027D1F8(p, 0x4A07C332, &a, 0) ^ 1) != 0) {
        f = 0.0f;
        func_0027D268(p, 0x906B67BA, &f, 1);
        a = (int)(f * 60.0f);
    }
    b = 0;
    func_0027D400(p, 0x7031F10C, &b, 0);
    if (func_0027D870(p, 0xC451F558, &c, 0)) {
        func_00128160(self, a, c, b);
        return;
    }
    if (func_0027D870(p, 0xA6D2D890, &c, 0)) {
        func_001281C0(self, a, c, b);
    }
}

INCLUDE_ASM("asm/nonmatchings/game/t_1277C0", func_00128338);

extern "C" SA127_K* func_001283A8(SA127_K* self, int a, int b) {
    func_00127838(&self->unk0, 5, a);
    self->unk10 = b;
    self->unk0.unkC = D_003397D8;
    return self;
}

struct S1283F8 { char pad0[0x10]; int unk10; };

extern "C" int func_001283F8(S1283F8* self) {
    func_002765E0(0x2F510F45, 0);
    int t = func_002763C0(self->unk10, 1);
    if (t) func_0028C9D0(0xBDF7F843, t, 0, 0, 0, 0);
    return 1;
}

extern "C" SA127_K* func_00128460(SA127_K* self, int a, int b) {
    func_00127838(&self->unk0, 6, a);
    self->unk10 = b;
    self->unk0.unkC = D_003397B0;
    return self;
}

extern "C" int func_001284B0(SA127_Z* self) {
    func_002765E0(0x2F510F45, 0);
    int h = func_002763C0(self->unk10, 1);
    if (h) {
        int loc;
        func_0027D870(h, 0xA1DC81F9, &loc, 1);
        SA127_VO* o = func_001D0680(loc);
        VE_001284B0* e = o->unk8;
        e->unk44((char*)o + e->unk40);
    }
    return 1;
}

struct H128528 { int a; int type; int size; };
typedef unsigned int u128_128528 __attribute__((mode(TI)));

extern "C" void* func_00128528(char** pp) {
    H128528 h;
    float f;
    int i4;
    u128_128528 a1, a2;
    u128_128528 b1, b2;
    int i5;
    int i6;
    func_0030A2F4((char*)&h, *pp, 12);
    char* p = *pp + 12;
    *pp = p;
    switch (h.type) {
    case 1: {
            func_0030A2F4((char*)&f, *pp, 4);
        *pp += 4;
        return func_001279A8((SA127_F*)Heap_Alloc(D_00368A38[0], 0x14, 1, 0), h.a, f);
    }
    case 4: {
        func_0030A2F4((char*)&i4, *pp, 4);
        *pp += 4;
        return func_00127A60((SA127_K*)Heap_Alloc(D_00368A38[0], 0x14, 1, 0), h.a, i4);
    }
    case 2: {
        func_0030A2F4((char*)&a1, *pp, 16);
        *pp += 16;
        func_0030A2F4((char*)&a2, *pp, 16);
        *pp += 16;
        return func_00127B10(Heap_Alloc(D_00368A38[0], 0x40, 1, 0), h.a, &a2, &a1, 0);
    }
    case 7: {
        func_0030A2F4((char*)&b1, *pp, 16);
        *pp += 16;
        func_0030A2F4((char*)&b2, *pp, 16);
        *pp += 16;
        return func_00127B10(Heap_Alloc(D_00368A38[0], 0x40, 1, 0), h.a, &b2, &b1, 1);
    }
    case 3: {
        *pp += 0x20;
        return func_00128098((S_00127838*)Heap_Alloc(D_00368A38[0], 0x10, 1, 0), h.a);
    }
    case 5: {
        func_0030A2F4((char*)&i5, *pp, 4);
        *pp += 4;
        return func_001283A8((SA127_K*)Heap_Alloc(D_00368A38[0], 0x14, 1, 0), h.a, i5);
    }
    case 6: {
        func_0030A2F4((char*)&i6, *pp, 4);
        *pp += 4;
        return func_00128460((SA127_K*)Heap_Alloc(D_00368A38[0], 0x14, 1, 0), h.a, i6);
    }
    default:
        *pp = p + h.size;
        return 0;
    }
}

INCLUDE_ASM("asm/nonmatchings/game/t_1277C0", func_001287F0);

extern "C" void func_001288B0(S_00127838* self, int flags) {
    self->unkC = D_003398C8;
    if (flags & 1) {
        Heap_Free(D_00368A38[0], self);
    }
}

extern "C" void func_001288F0(S_001288F0* self, float v) {
    self->unkC = v;
}

INCLUDE_ASM("asm/nonmatchings/game/t_1277C0", func_001288F8);

extern "C" void func_00128940(S_00127838* self, int flags) {
    self->unkC = D_003398C8;
    if (flags & 1) {
        Heap_Free(D_00368A38[0], self);
    }
}

extern "C" void func_00128980(S_00127838* self, int flags) {
    self->unkC = D_003398C8;
    if (flags & 1) {
        Heap_Free(D_00368A38[0], self);
    }
}

extern "C" void func_001289C0(S_00127838* self, int flags) {
    self->unkC = D_003398C8;
    if (flags & 1) {
        Heap_Free(D_00368A38[0], self);
    }
}

extern "C" void func_00128A00(S_00127838* self, int flags) {
    self->unkC = D_003398C8;
    if (flags & 1) {
        Heap_Free(D_00368A38[0], self);
    }
}

extern "C" void func_00128A40(S_00127838* self, int flags) {
    self->unkC = D_003398C8;
    if (flags & 1) {
        Heap_Free(D_00368A38[0], self);
    }
}

extern "C" S_00128A80* func_00128A80(S_00128A80* self) {
    self->unk404 = 0;
    return self;
}

extern "C" void func_00128A90(void* self, int flags) {
    if (flags & 1) func_0012A048(self);
}

INCLUDE_ASM("asm/nonmatchings/game/t_1277C0", func_00128AB8);

extern "C" void func_00128AC0(SA127_Z* self) {
    memset((char*)self + 4, 0, 0x200);
    memset((char*)self + 0x204, 0, 0x200);
    self->unk404 = 0;
}

extern "C" SA127_Z* func_00128B08(SA127_Z* self) {
    self->unk18 = 0;
    self->unk1C = 0;
    self->unk4 = 0;
    self->unk476 = 0;
    self->unk70 = 0;
    self->unk71 = 0;
    self->unk10 = 0;
    self->unk14 = 0;
    self->unk24 = 0;
    self->unk474 = 0;
    self->unkC = 0;
    self->unk480 = 0;
    return self;
}

INCLUDE_ASM("asm/nonmatchings/game/t_1277C0", func_00128B40);

INCLUDE_ASM("asm/nonmatchings/game/t_1277C0", func_00128D48);

extern "C" void func_00128F40(void) {
}

INCLUDE_ASM("asm/nonmatchings/game/t_1277C0", func_00128F48);

extern "C" int func_00129070(S_00129070* self) {
    return self->unk480 != 0;
}

extern "C" int func_00129080(SA127_Z* self) {
    int r = func_00128F48(self);
    if (r != -1) {
        self->unk474++;
    }
    return r;
}

struct S1290C8 { char pad0[0x28]; SA127_Z* unk28[1]; char pad2C[0x448]; u16 unk474; };

extern "C" void func_001290C8(S1290C8* self, int i) {
    if (self->unk474 != 0 && i >= 0) {
        SA127_Z** base = self->unk28;
        SA127_Z** p = base + i;
        func_00128AC0(*p);
        if (*p) func_00128A90(*p, 3);
        *p = 0;
        self->unk474 = self->unk474 - 1;
    }
}

INCLUDE_ASM("asm/nonmatchings/game/t_1277C0", func_00129138);

struct S_00129148 { char pad0[4]; int unk4; int a[50]; u32 b[50]; int unk198; int unk19C; int unk1A0; int unk1A4; int unk1A8; int unk1AC; int unk1B0; int unk1B4; };

extern "C" int func_00129148(void* p) {
    S_00129148* self = (S_00129148*)p;
    for (int i = 0; i < 50; i++) {
        self->a[i] = 0;
        self->b[i] = 0xFFFFFFFF;
    }
    self->unk1A4 = 0;
    self->unk1A8 = 0;
    self->unk1AC = 0;
    self->unk1B0 = 0;
    self->unk1A0 = 0;
    self->unk1B4 = 0;
    self->unk4 = 0;
    self->unk198 = 0;
    self->unk19C = 0;
    return (int)self;
}

INCLUDE_ASM("asm/nonmatchings/game/t_1277C0", func_001291E0);

GP_DATA(D_003690EC);
extern "C" void func_001292D0(int a, int b, int c) {
    if (D_003690EC == 0) {
        func_0011A230(D_00368A38[0], 0x8F21A798, a, D_00339900, 0);
        int t = func_00129148(operator_new(0x1B8));
        D_003690EC = t;
        func_00129F70(t, b, c);
    }
}

GP_DATA(D_003690EC);
extern "C" void func_00129350(void) {
    if (D_003690EC) {
        func_001291E0(D_003690EC, 3);
    }
    D_003690EC = 0;
    func_0011A300(D_00368A38[0], 0x8F21A798, 1);
}

extern "C" int func_00129390(void) {
    return D_003690EC;
}

extern "C" void func_00129398(void) {
}

INCLUDE_ASM("asm/nonmatchings/game/t_1277C0", func_001293A0);

INCLUDE_ASM("asm/nonmatchings/game/t_1277C0", func_001294B8);

INCLUDE_ASM("asm/nonmatchings/game/t_1277C0", func_001294C0);

INCLUDE_ASM("asm/nonmatchings/game/t_1277C0", func_00129710);

INCLUDE_ASM("asm/nonmatchings/game/t_1277C0", func_001297B8);
