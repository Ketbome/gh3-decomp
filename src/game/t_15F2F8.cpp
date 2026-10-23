#include "common.h"

struct VEntry {
    s16 delta;
    s16 unk2;
    void* fn;
};

struct S0015F320 {
    char pad[0x18];
    VEntry* unk18;
};

struct S0015FA10 {
    char pad[0x4];
    VEntry* unk4;
};

struct S0015FDE8 {
    char pad[0x58];
    VEntry* unk58;
};

struct S0015F940 {
    char pad[0x8];
    VEntry* unk8;
};

struct S0015F488 {
    char pad[0xC];
    int unkC;
};

struct S0015F838 {
    char pad[0x14];
    u8 unk14;
};

struct S0015F8E8 {
    char pad[0x4];
    int unk4;
    void* unk8;
};

struct S0015F9B8 {
    int unk0;
    void* unk4;
};

struct S15F_A { char pad0[0x10]; void* unk10; };
struct S15F_B { char pad0[0x8]; void* unk8; };
struct S15F_C { char pad0[0x4]; void* unk4; };
struct O15F_H { char pad0[0x34]; VEntry* unk34; };
struct H15F { O15F_H* unk0; int unk4; int unk8; };
struct S15F_D { char pad0[0x4]; int unk4; int unk8; int unkC; char pad10[0x48]; VEntry* unk58; };
struct S15F_P { char pad0[0x4]; int unk4; char pad8[0x218]; int unk220; };
struct Y15F { int unk0; int unk4; int unk8; O15F_H* unkC; char pad10[0x8]; void* unk18; };
struct N15F { N15F* unk0; N15F* unk4; Y15F* unk8; };
struct It15F {
    int unk0;
    N15F* cur;
    It15F() {}
    It15F(N15F* n) : cur(n) {}
    bool operator!=(const It15F& o) const { return cur != o.cur; }
    void operator++() { cur = cur->unk4; }
    It15F& operator--() { cur = cur->unk0; return *this; }
};
struct L15F { char pad0[0x14]; N15F unk14; };
struct B50_15F {
    u64 f0 : 1;
    u64 f1 : 1;
    u64 f2 : 1;
    u64 f3 : 61;
};
struct S15F_E { char pad0[0x14]; N15F unk14; char pad20[0x30]; B50_15F unk50; };
struct LL15F { int unk0; N15F unk4; };
struct S15F_F { char pad0[0x10]; LL15F unk10; char pad20[0x10]; void* unk30; char pad34[0x24]; void* unk58; };

extern "C" {
extern u8 D_0033DAC0[];
extern u8 D_0033DA98[];
void func_0018D668(void);
void func_0018D718(void);
void func_0018D780(void);
extern int D_00368A38;
void Heap_Free(int, void*);
void func_0030A2F4(void*, void*, int);
extern int D_0036F658;
void func_0022B0D0(H15F*, int, int, int);
void func_00134340(H15F*);
int func_00160768(L15F*);
void func_001607F0(L15F*, int);
int func_00160970(S15F_E*, u32);
void func_0015F1F0(int);
int func_0015F7C0_2(S0015F320*, int, int, float, float) __asm__("func_0015F7C0");
int func_0015F7E8(S0015F320*, int, int, int);
int func_0015F810(S0015F320*, int, int);
extern u8 D_0033DD30[];
void func_00155170(void*);
void func_0014C418(int);
void func_00161AC8(S15F_F*);
}

extern "C" void func_0015F2F8(S0015F320* self, int a1) {
    VEntry* e = &self->unk18[20];
    ((void (*)(void*, int))e->fn)((char*)self + e->delta, a1);
}

extern "C" int func_0015F320(S0015F320* self) {
    VEntry* e = &self->unk18[21];
    return ((int (*)(void*))e->fn)((char*)self + e->delta);
}

extern "C" int func_0015F348(S0015F320* self) {
    VEntry* e = &self->unk18[25];
    return ((int (*)(void*))e->fn)((char*)self + e->delta);
}

extern "C" int func_0015F370(S0015F320* self) {
    VEntry* e = &self->unk18[27];
    return ((int (*)(void*))e->fn)((char*)self + e->delta);
}

extern "C" void func_0015F398(S0015F320* self, int a1) {
    VEntry* e = &self->unk18[26];
    ((void (*)(void*, int))e->fn)((char*)self + e->delta, a1);
}

extern "C" void func_0015F3C0(S0015F320* self, int a1) {
    VEntry* e = &self->unk18[28];
    ((void (*)(void*, int))e->fn)((char*)self + e->delta, a1);
}

extern "C" int func_0015F3E8(S0015F320* self) {
    VEntry* e = &self->unk18[29];
    return ((int (*)(void*))e->fn)((char*)self + e->delta);
}

extern "C" void func_0015F410(S0015F320* self, int a1) {
    VEntry* e = &self->unk18[30];
    ((void (*)(void*, int))e->fn)((char*)self + e->delta, a1);
}

extern "C" int func_0015F438(S0015F320* self) {
    VEntry* e = &self->unk18[34];
    return ((int (*)(void*))e->fn)((char*)self + e->delta);
}

extern "C" void func_0015F460(S0015F320* self, int a1) {
    VEntry* e = &self->unk18[35];
    ((void (*)(void*, int))e->fn)((char*)self + e->delta, a1);
}

extern "C" void func_0015F488(S0015F488* self, int v) {
    self->unkC = v;
}

extern "C" void func_0015F490(S0015F320* self, int a1) {
    VEntry* e = &self->unk18[37];
    ((void (*)(void*, int))e->fn)((char*)self + e->delta, a1);
}

extern "C" void func_0015F4B8(S0015F320* self, int a1) {
    VEntry* e = &self->unk18[38];
    ((void (*)(void*, int))e->fn)((char*)self + e->delta, a1);
}

extern "C" void func_0015F4E0(S0015F320* self, int a, int b, int c, int d, int e) {
    VEntry* v = &self->unk18[40];
    ((void (*)(void*, int, int, int, int, int))v->fn)((char*)self + v->delta, a, b, c, d, e);
}

extern "C" void func_0015F508(S0015F320* self, int a1, int a2) {
    VEntry* e = &self->unk18[41];
    ((void (*)(void*, int, int))e->fn)((char*)self + e->delta, a1, a2);
}

extern "C" int func_0015F530(S0015F320* self, int a1) {
    VEntry* e = &self->unk18[43];
    return ((int (*)(void*, int))e->fn)((char*)self + e->delta, a1);
}

extern "C" int func_0015F558(S0015F320* self, int a1) {
    VEntry* e = &self->unk18[44];
    return ((int (*)(void*, int))e->fn)((char*)self + e->delta, a1);
}

extern "C" int func_0015F580(S0015F320* self, int a1) {
    VEntry* e = &self->unk18[49];
    return ((int (*)(void*, int))e->fn)((char*)self + e->delta, a1);
}

extern "C" void func_0015F5A8(S0015F320* self, int a1) {
    VEntry* e = &self->unk18[50];
    ((void (*)(void*, int))e->fn)((char*)self + e->delta, a1);
}

extern "C" void func_0015F5D0(S0015F320* self, int a1) {
    VEntry* e = &self->unk18[51];
    ((void (*)(void*, int))e->fn)((char*)self + e->delta, a1);
}

extern "C" int func_0015F5F8(S0015F320* self, int a1) {
    VEntry* e = &self->unk18[45];
    return ((int (*)(void*, int))e->fn)((char*)self + e->delta, a1);
}

extern "C" int func_0015F620(S0015F320* self) {
    VEntry* e = &self->unk18[46];
    return ((int (*)(void*))e->fn)((char*)self + e->delta);
}

extern "C" int func_0015F648(S0015F320* self) {
    VEntry* e = &self->unk18[47];
    return ((int (*)(void*))e->fn)((char*)self + e->delta);
}

extern "C" int func_0015F670(S0015F320* self) {
    VEntry* e = &self->unk18[48];
    return ((int (*)(void*))e->fn)((char*)self + e->delta);
}

extern "C" void func_0015F698(S0015F320* self, void* dst) {
    int n = func_0015F580(self, 0);
    if (!((S15F_A*)self)->unk10) {
        func_0015F5D0(self, (int)dst);
    } else {
        func_0030A2F4(dst, ((S15F_A*)self)->unk10, n * 4);
    }
}

extern "C" void func_0015F6F8(S0015F320* self, int a1) {
    VEntry* e = &self->unk18[53];
    ((void (*)(void*, int))e->fn)((char*)self + e->delta, a1);
}

extern "C" void func_0015F720(S0015F320* self, int a1, int a2, int a3) {
    VEntry* e = &self->unk18[54];
    ((void (*)(void*, int, int, int))e->fn)((char*)self + e->delta, a1, a2, a3);
}

extern "C" void func_0015F748(S0015F320* self) {
    VEntry* e = &self->unk18[55];
    ((void (*)(void*))e->fn)((char*)self + e->delta);
}

extern "C" void func_0015F770(S0015F320* self, int a1) {
    VEntry* e = &self->unk18[56];
    ((void (*)(void*, int))e->fn)((char*)self + e->delta, a1);
}

extern "C" void func_0015F798(S0015F320* self) {
    VEntry* e = &self->unk18[57];
    ((void (*)(void*))e->fn)((char*)self + e->delta);
}

extern "C" int func_0015F7C0(S0015F320* self, int a1, int a2, float f0) {
    VEntry* e = &self->unk18[58];
    return ((int (*)(void*, int, int, float))e->fn)((char*)self + e->delta, a1, a2, f0);
}

extern "C" int func_0015F7E8(S0015F320* self, int a1, int a2, int a3) {
    VEntry* e = &self->unk18[59];
    return ((int (*)(void*, int, int, int))e->fn)((char*)self + e->delta, a1, a2, a3);
}

extern "C" int func_0015F810(S0015F320* self, int a1, int a2) {
    VEntry* e = &self->unk18[60];
    return ((int (*)(void*, int, int))e->fn)((char*)self + e->delta, a1, a2);
}

extern "C" bool func_0015F838(S0015F838* self) {
    return self->unk14 != 0;
}

extern "C" void func_0015F848(S0015F320* self) {
    VEntry* e = &self->unk18[63];
    ((void (*)(void*))e->fn)((char*)self + e->delta);
}

extern "C" void func_0015F870(S0015F320* self, int a1) {
    VEntry* e = &self->unk18[64];
    ((void (*)(void*, int))e->fn)((char*)self + e->delta, a1);
}

extern "C" void func_0015F898(S0015F320* self) {
    VEntry* e = &self->unk18[65];
    ((void (*)(void*))e->fn)((char*)self + e->delta);
}

INCLUDE_ASM("asm/nonmatchings/game/t_15F2F8", func_0015F8C0);

extern "C" void func_0015F8C8(void) {
    func_0018D668();
}

extern "C" S0015F8E8* func_0015F8E8(S0015F8E8* self) {
    self->unk4 = 0;
    self->unk8 = D_0033DAC0;
    return self;
}

extern "C" void func_0015F900(S15F_B* self, int flags) {
    self->unk8 = D_0033DAC0;
    if (flags & 1) {
        Heap_Free(D_00368A38, self);
    }
}

extern "C" void func_0015F940(S0015F940* self) {
    VEntry* e = &self->unk8[2];
    ((void (*)(void*))e->fn)((char*)self + e->delta);
}

extern "C" void func_0015F968(S0015F940* self) {
    VEntry* e = &self->unk8[3];
    ((void (*)(void*))e->fn)((char*)self + e->delta);
}

extern "C" void func_0015F990(S0015F940* self, int a1) {
    VEntry* e = &self->unk8[4];
    ((void (*)(void*, int))e->fn)((char*)self + e->delta, a1);
}

extern "C" S0015F9B8* func_0015F9B8(S0015F9B8* self, int a1) {
    self->unk0 = a1;
    self->unk4 = D_0033DA98;
    return self;
}

extern "C" void func_0015F9D0(S15F_C* self, int flags) {
    self->unk4 = D_0033DA98;
    if (flags & 1) {
        Heap_Free(D_00368A38, self);
    }
}

extern "C" int func_0015FA10(S0015FA10* self) {
    VEntry* e = &self->unk4[3];
    return ((int (*)(void*))e->fn)((char*)self + e->delta);
}

extern "C" void func_0015FA38(void) {
    func_0018D718();
}

extern "C" void func_0015FA58(void) {
    func_0018D780();
}

extern "C" int func_0015FA78(void) {
    return 0;
}

extern "C" void func_0015FA80(void) {
}

extern "C" void func_0015FA88(void) {
}

extern "C" void func_0015FA90(void) {
}

extern "C" void func_0015FA98(void) {
}

extern "C" int func_0015FAA0(int a, int b) {
    H15F h;
    func_0022B0D0(&h, D_0036F658, a, b);
    int r;
    if (h.unk0) {
        VEntry* e = &h.unk0->unk34[2];
        r = ((int (*)(void*))e->fn)((char*)h.unk0 + e->delta);
    } else {
        r = 0;
    }
    func_00134340(&h);
    return r;
}

extern "C" int func_0015FB08(void) {
    return 1;
}

extern "C" void func_0015FB10(void) {
}

extern "C" int func_0015FB18(void) {
    return 0;
}

extern "C" int func_0015FB20(void) {
    return 1;
}

extern "C" int func_0015FB28(void) {
    return 1;
}

extern "C" int func_0015FB30(void) {
    return 1;
}

extern "C" int func_0015FB38(void) {
    return 1;
}

extern "C" int func_0015FB40(void) {
    return 1;
}

extern "C" int func_0015FB48(void) {
    return 1;
}

extern "C" int func_0015FB50(void) {
    return 1;
}

extern "C" int func_0015FB58(void) {
    return 1;
}

extern "C" int func_0015FB60(void) {
    return 1;
}

INCLUDE_ASM("asm/nonmatchings/game/t_15F2F8", func_0015FB68);

extern "C" void func_0015FBD0(void) {
}

INCLUDE_ASM("asm/nonmatchings/game/t_15F2F8", func_0015FBD8);

INCLUDE_ASM("asm/nonmatchings/game/t_15F2F8", func_0015FC88);

extern "C" int func_0015FD88(S15F_D* self, S15F_P* o) {
    if (!self->unkC) {
        self->unk8 = o->unk220;
        VEntry* e = &self->unk58[2];
        ((int (*)(void*, int))e->fn)((char*)self + e->delta, o->unk220);
        self->unkC = o->unk4;
    }
    return 1;
}

extern "C" int func_0015FDE8(S0015FDE8* self, int a1) {
    VEntry* e = &self->unk58[3];
    return ((int (*)(void*, int))e->fn)((char*)self + e->delta, a1);
}

INCLUDE_ASM("asm/nonmatchings/game/t_15F2F8", func_0015FE10);

extern "C" int func_00160100(L15F* self, S15F_P* o) {
    It15F end(&self->unk14);
    It15F it(self->unk14.unk4);
    for (; it != end; ++it) {
        func_0015F508(*(S0015F320**)it.cur->unk8, o->unk4, o->unk220);
    }
    return 1;
}

INCLUDE_ASM("asm/nonmatchings/game/t_15F2F8", func_00160168);

INCLUDE_ASM("asm/nonmatchings/game/t_15F2F8", func_00160170);

struct Y160 { int unk0; int unk4; int unk8; char padC[0xC]; int unk18; };
struct B160 {
    u64 f0 : 1;
    u64 f1 : 3;
    u64 f4 : 1;
    u64 f5 : 59;
};
struct S160 {
    char pad0[0x14];
    N15F unk14;
    char pad20[0x10];
    int unk30;
    int unk34;
    char pad38[0x18];
    B160 unk50;
};
extern "C" {
void* Heap_Alloc(int, int, int, int);
extern int D_003689E8[] __attribute__((section(".sdata")));
void* func_00162378(void*);
int func_0015F558_r(int, int) __asm__("func_0015F558");
void func_0015F490_r(int, int) __asm__("func_0015F490");
int func_001608D0_r(S160*, int) __asm__("func_001608D0");
}

extern "C" int func_00160458(S160* self, int a1, int a2, int a3) {
    It15F c;
    self->unk50.f0 = 0;
    Y160* y;
    if (a3 != 0) {
        y = (Y160*)func_00162378(Heap_Alloc(D_00368A38, 0x1C, 1, 0));
    } else {
        y = (Y160*)Heap_Alloc(D_00368A38, 0x1C, D_003689E8[0], 0);
        y = y ? (Y160*)func_00162378(y) : y;
        if (!y) {
            return 0;
        }
    }
    y->unk0 = a1;
    func_0015F558_r(a1, (int)(*(s64*)&self->unk50 >> 4) & 1);
    y->unk8 = a2;
    *(int*)&self->unk14.unk8 |= 1 << *(s16*)((char*)self + 0x52);
    y->unk4 = 0;
    if (self->unk30) {
        func_0015F490_r(y->unk0, self->unk30);
    }
    y->unk18 = 0;
    It15F a(&self->unk14);
    It15F b(&self->unk14);
    N15F* last = self->unk14.unk0;
    N15F* n = (N15F*)Heap_Alloc(D_00368A38, 0xC, 1, 0);
    N15F tmp;
    tmp.unk0 = last;
    tmp.unk4 = &self->unk14;
    tmp.unk8 = (Y15F*)y;
    if (n) {
        *n = tmp;
    }
    self->unk14.unk0 = n;
    n->unk0->unk4 = n;
    c.cur = (--a).cur;
    (*(u16*)((char*)self + 0x52))++;
    func_001608D0_r(self, 0);
    if (*(s16*)((char*)self + 0x52) == 1) {
        self->unk34 = 0;
    }
    return y->unk0;
}

extern "C" void func_00160610(L15F* self, S15F_D* o) {
    if (self->unk14.unk4 != &self->unk14) {
        It15F it(self->unk14.unk4);
        Y15F* y = it.cur->unk8;
        if (y && !y->unk18) {
            o->unk8++;
            y->unk18 = o;
        }
    }
}

extern "C" void* func_00160658(L15F* self) {
    void* r = 0;
    if (self->unk14.unk4 != &self->unk14) {
        It15F it(self->unk14.unk4);
        Y15F* y = it.cur->unk8;
        if (y) {
            r = y->unk18;
        }
    }
    return r;
}

extern "C" int func_00160688(void) {
    return 0;
}

INCLUDE_ASM("asm/nonmatchings/game/t_15F2F8", func_00160690);

INCLUDE_ASM("asm/nonmatchings/game/t_15F2F8", func_00160698);

extern "C" int func_00160730(L15F* self) {
    func_001607F0(self, func_00160768(self));
    return 1;
}

extern "C" int func_00160768(L15F* self) {
    int r = 0;
    It15F end(&self->unk14);
    It15F it(self->unk14.unk4);
    for (; it != end; ++it) {
        O15F_H* o = it.cur->unk8->unkC;
        if (o) {
            VEntry* e = &o->unk34[2];
            char* y = ((char* (*)(void*))e->fn)((char*)o + e->delta);
            if (y) {
                r |= *(int*)(y + 0xB0);
            }
        }
    }
    return r;
}

extern "C" void func_001607F0(L15F* self, int a) {
    It15F end(&self->unk14);
    It15F it(self->unk14.unk4);
    for (; it != end; ++it) {
        func_0015F530(*(S0015F320**)it.cur->unk8, a);
    }
}

INCLUDE_ASM("asm/nonmatchings/game/t_15F2F8", func_00160850);

INCLUDE_ASM("asm/nonmatchings/game/t_15F2F8", func_00160858);

INCLUDE_ASM("asm/nonmatchings/game/t_15F2F8", func_001608C8);

extern "C" int func_001608D0(S15F_D* self, int v) {
    int r = 0;
    if (v != self->unk4) {
        VEntry* e = &self->unk58[4];
        r = ((int (*)(void*))e->fn)((char*)self + e->delta);
        if (r) {
            self->unk4 = v;
        }
    }
    return r;
}

extern "C" void func_00160930(S15F_E* self, int b) {
    self->unk50.f2 = b;
    func_00160970(self, b ^ 1);
}

extern "C" int func_00160970(S15F_E* self, u32 v) {
    if (((int)(*(s64*)&self->unk50 >> 2) & 1) && v) {
        return 0;
    }
    if (((int)(*(s64*)&self->unk50 >> 1) & 1) == v) {
        return 1;
    }
    It15F end(&self->unk14);
    It15F it(self->unk14.unk4);
    for (; it != end; ++it) {
        func_0015F2F8(*(S0015F320**)it.cur->unk8, v);
    }
    self->unk50.f1 = v;
    return 1;
}

extern "C" int func_00160A40(L15F* self, int key) {
    It15F end(&self->unk14);
    It15F it(self->unk14.unk4);
    for (; it != end; ++it) {
        if (key == it.cur->unk8->unk8) {
            return it.cur->unk8->unk0;
        }
    }
    return 0;
}

extern "C" {
char* strcpy(char*, char*);
void func_00113528(char*);
char* func_0030E720(char*, char*);
void func_0030A554(char*, char*);
extern char D_00369FF0[];
int func_0015B218(int, char*, int);
void func_00275F08(int, int);
}

struct S160A90 { char pad0[0x14]; N15F unk14; char pad20[0x38]; VEntry* unk58; };
extern char D_00369FF8[];
extern "C" int func_0015B168(int, char*, char*);

extern "C" int func_00160A90(S160A90* self, int key, char* name, char* name2) {
    int all = key == (int)0xC4E78E22;
    VEntry* e = &self->unk58[11];
    ((int (*)(void*))e->fn)((char*)self + e->delta);
    char buf[0x200];
    strcpy(buf, name);
    int ret = 0;
    func_00113528(buf);
    if (func_0030E720(buf, D_00369FF0) == 0 && func_0030E720(buf, D_00369FF8) == 0) {
        func_0030A554(buf, D_00369FF0);
    }
    char buf2[0x200];
    strcpy(buf2, name2);
    func_00113528(buf2);
    char* p = func_0030E720(buf2, D_00369FF0);
    if (p != 0 || (p = func_0030E720(buf2, D_00369FF8), p != 0)) {
        *p = 0;
    }
    It15F end(&self->unk14);
    It15F it(self->unk14.unk4);
    for (; it != end; ++it) {
        int k = it.cur->unk8->unk8;
        if (key == k || all || k == 0) {
            if (it.cur->unk8->unk4 != 0) {
                if (func_0015B168(it.cur->unk8->unk4, buf, buf2) != 0) ret = 1;
            }
        }
    }
    if (ret == 0) {
        func_00275F08(0x2A648514, 0);
    }
    e = &self->unk58[12];
    ((int (*)(void*))e->fn)((char*)self + e->delta);
    return ret;
}

static inline int Q_160C58(int a) {
    H15F h;
    func_0022B0D0(&h, D_0036F658, a, 1);
    int r;
    if (h.unk0) {
        VEntry* e = &h.unk0->unk34[2];
        r = ((int (*)(void*))e->fn)((char*)h.unk0 + e->delta);
    } else {
        r = 0;
    }
    func_00134340(&h);
    return r;
}

struct S160C58 { char pad0[0x14]; N15F unk14; char pad20[0x38]; VEntry* unk58; };

extern "C" int func_00160C58(S160C58* self, int key, char* name, int hkey) {
    int ret = 0;
    int all = key == 0xC4E78E22;
    VEntry* e = &self->unk58[11];
    ((int (*)(void*))e->fn)((char*)self + e->delta);
    char buf[0x200];
    strcpy(buf, name);
    func_00113528(buf);
    if (func_0030E720(buf, D_00369FF0) == 0) {
        func_0030A554(buf, D_00369FF0);
    }
    int v = Q_160C58(hkey);
    It15F end(&self->unk14);
    It15F it(self->unk14.unk4);
    for (; it != end; ++it) {
        Y15F* y = it.cur->unk8;
        if (key == y->unk8 || all) {
            if (y->unk4 != 0) {
                if (func_0015B218(y->unk4, buf, v) != 0) ret = 1;
            }
        }
    }
    if (ret == 0) {
        func_00275F08(0x2A648514, 0);
    }
    e = &self->unk58[12];
    ((int (*)(void*))e->fn)((char*)self + e->delta);
    return ret;
}

extern "C" int func_00160DE8(L15F* self, int key) {
    int any = key == (int)0xC4E78E22;
    int found = 0;
    It15F end(&self->unk14);
    It15F it(self->unk14.unk4);
    for (; it != end; ++it) {
        Y15F* y = it.cur->unk8;
        if (key == y->unk8 || any) {
            func_0015F1F0(y->unk0);
            found = 1;
        }
    }
    return found;
}

INCLUDE_ASM("asm/nonmatchings/game/t_15F2F8", func_00160E80);

extern "C" int func_00160FF8(L15F* self, int a, int b, float f, float g) {
    int r = 0;
    It15F end(&self->unk14);
    It15F it(self->unk14.unk4);
    for (; it != end; ++it) {
        r |= func_0015F7C0_2(*(S0015F320**)it.cur->unk8, a, b, f, g) != 0;
    }
    return r;
}

extern "C" int func_001610A0(L15F* self, int a, int b, int c) {
    int r = 0;
    It15F end(&self->unk14);
    It15F it(self->unk14.unk4);
    for (; it != end; ++it) {
        r |= func_0015F7E8(*(S0015F320**)it.cur->unk8, a, b, c) != 0;
    }
    return r;
}

extern "C" int func_00161138(L15F* self, int a, int b) {
    int r = 0;
    It15F end(&self->unk14);
    It15F it(self->unk14.unk4);
    for (; it != end; ++it) {
        r |= func_0015F810(*(S0015F320**)it.cur->unk8, a, b) != 0;
    }
    return r;
}

INCLUDE_ASM("asm/nonmatchings/game/t_15F2F8", func_001611C0);
