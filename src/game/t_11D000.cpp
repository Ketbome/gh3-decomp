#include "common.h"

struct S_0011DAA0 { char pad0[0x40]; int unk40; };
struct S_0011DB50 { char pad0[0x4]; int unk4; int unk8; int unkC; };

struct S_0011E8F8 { char pad0[0x18]; int unk18; };

struct S_0011E998 { char pad0[0x1C]; void (*unk1C)(void); };

struct VE_0011DB60 { s16 unk0; s16 unk2; int (*unk4)(void*); };
struct S_0011DB60 { char pad0[0x44]; VE_0011DB60* unk44; };

struct VEntry {
    s16 delta;
    s16 unk2;
    void* fn;
};

struct SA11D_O {
    int unk0;
    int unk4;
    int unk8;
    int unkC;
    u32 unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    int unk24;
    int unk28;
    int unk2C;
    int unk30;
    int unk34;
    char pad38[0x8];
    int unk40;
    VEntry* unk44;
};

struct SA11D_V {
    char pad0[0x14];
    VEntry* unk14;
};

struct SA11D_E {
    int unk0;
    int unk4;
    int unk8;
};

extern "C" {
int func_0011A380(int);
void func_0011A440(int, int);
int func_0011DB60_v(void*) __asm__("func_0011DB60");
int func_0011DBB8_v(void*, int, int, int) __asm__("func_0011DBB8");
void func_0011DB50_v(void*, int, int, int) __asm__("func_0011DB50");
int func_0011E190(void);
int func_0011DD68_5(int, int, int, int, int) __asm__("func_0011DD68");
void func_0011E3B8(int);
void* func_0011DF78(int, int, int, int);
extern int D_00368748[] __attribute__((section(".sdata")));
extern int D_00368D74;
int func_0011E008(void*);
void func_0011EA30(void);
int func_002EE340(int, void*, int);
void func_002EECA0(int);
int func_002F49C8(void);
void func_002F4BB8(int);
extern u8 func_0011E9E0[];
void func_001C5610(void*, int);
extern u8 D_00338C20[];
void func_002F4CD0(int);
void func_002F4AB0(int);
void func_002EE360(int, int);
extern int D_00368D10;
extern int D_00368D14;
void func_00317588(float);
extern float D_00376528[];
extern volatile long D_00368CE0;
extern volatile u32 D_00368CD4;
extern float D_00368D00;
extern int D_00368C1C;
extern SA11D_V* D_00368C24;
extern u32 D_00368C28;
extern int D_00368C18;
extern int D_00368C10[2];
extern SA11D_E D_00414FF0[][16];
extern int D_00370EE0[] __attribute__((section(".sdata")));
extern int D_00368A38[] __attribute__((section(".sdata")));
extern u8 D_00338C68[];
u32 func_001150B8(const char*);
void func_0011D220(u32);
void func_0011D370(u32);
void func_0011E540(void);
void func_0011E560(void);
void func_00114958(void*, int);
void func_00119400(int, void*);
int func_00113DF0(int, int, int);
SA11D_V* func_0011E7D8(int);
void* func_001C55A8(int);
void* func_00113EA8(void*, int);
void* func_00113D20(u32);
extern u8 D_00338C48[];
void func_0011E918(void);
extern long D_00368CF0;
extern float D_00368D04;
extern float D_00368D08;
extern float D_00368CE8;
extern float D_00368CEC;
extern int D_00368C04;
void func_002EA460(void);
void func_00120DF0(void);
void func_00120DF8(void);
void func_00113FB8(int);
void func_00113F38(void);
void func_0011D830(int, int);
extern int D_00368C00;
void func_00120C80(void);
}

INCLUDE_ASM("asm/nonmatchings/game/t_11D000", func_0011D000);

INCLUDE_ASM("asm/nonmatchings/game/t_11D000", func_0011D220);

extern "C" void func_0011D348(const char* s) {
    func_0011D220(func_001150B8(s));
}

INCLUDE_ASM("asm/nonmatchings/game/t_11D000", func_0011D370);

extern "C" void func_0011D4F8(const char* s) {
    func_0011D370(func_001150B8(s));
}

INCLUDE_ASM("asm/nonmatchings/game/t_11D000", func_0011D520);

INCLUDE_ASM("asm/nonmatchings/game/t_11D000", func_0011D530);

struct S11D720 { char pad0[0x10]; int unk10; };

extern "C" int func_0011D720(int a, int* out, int b, int c, int d, int e) {
    S11D720* p = (S11D720*)func_0011DF78(a, 0, 0x64, 0);
    int n = func_0011DB60_v(p);
    int v;
    if (e == 0) {
        v = func_0011A380((n + 0x7FF) & ~0x7FF);
    } else {
        v = e;
    }
    if (b) {
        p->unk10 = 8;
        func_0011DB50_v(p, b, c, d);
    }
    func_0011DBB8_v(p, v, 1, n);
    func_0011E008(p);
    if (e == 0 && v != 0) func_0011A440(n, v);
    if (out) *out = n;
    return v;
}

INCLUDE_ASM("asm/nonmatchings/game/t_11D000", func_0011D828);

INCLUDE_ASM("asm/nonmatchings/game/t_11D000", func_0011D830);

extern "C" void func_0011D968(void) {
    func_0011D830(1, 0xFFFF);
}

extern "C" void func_0011D988(void) {
    func_002EA460();
}

struct S11D9A8 { char pad0[0x44]; void* unk44; };
extern "C" void func_0011D9E0(void*);

extern "C" S11D9A8* func_0011D9A8(S11D9A8* self) {
    self->unk44 = D_00338C68;
    func_0011D9E0(self);
    return self;
}

INCLUDE_ASM("asm/nonmatchings/game/t_11D000", func_0011D9E0);

extern "C" void func_0011DA60(SA11D_O* self, int flags) {
    self->unk44 = (VEntry*)D_00338C68;
    if (flags & 1) {
        func_00119400(D_00368A38[0], self);
    }
}

extern "C" int func_0011DAA0(S_0011DAA0* self) {
    return self->unk40 > 0;
}

INCLUDE_ASM("asm/nonmatchings/game/t_11D000", func_0011DAB0);

INCLUDE_ASM("asm/nonmatchings/game/t_11D000", func_0011DAF8);

extern "C" void func_0011DB08(SA11D_O* self, int a) {
    self->unk14 = 0;
    self->unk18 = a;
    VEntry* e = &self->unk44[13];
    ((void (*)(void*, int))e->fn)((char*)self + e->delta, a);
}

INCLUDE_ASM("asm/nonmatchings/game/t_11D000", func_0011DB40);

extern "C" void func_0011DB50(S_0011DB50* self, int a, int b, int c) {
    self->unk4 = a;
    self->unk8 = b;
    self->unkC = c;
}

extern "C" int func_0011DB60(S_0011DB60* self) {
    VE_0011DB60* e = &self->unk44[22];
    return e->unk4((char*)self + e->unk0);
}

extern "C" int func_0011DB88(SA11D_O* self, int a) {
    self->unk14 = 2;
    VEntry* e = &self->unk44[16];
    return ((int (*)(void*, int))e->fn)((char*)self + e->delta, a);
}

extern "C" int func_0011DBB8(SA11D_O* self, int a, int b, int c) {
    self->unk14 = 3;
    VEntry* e = &self->unk44[17];
    return ((int (*)(void*, int, int, int))e->fn)((char*)self + e->delta, a, b, c);
}

extern "C" int func_0011DBE8(SA11D_O* self, int a, int b) {
    self->unk14 = 5;
    VEntry* e = &self->unk44[20];
    return ((int (*)(void*, int, int))e->fn)((char*)self + e->delta, a, b);
}

extern "C" int func_0011DC18(SA11D_O* self) {
    self->unk14 = 7;
    VEntry* e = &self->unk44[21];
    return ((int (*)(void*))e->fn)((char*)self + e->delta);
}

INCLUDE_ASM("asm/nonmatchings/game/t_11D000", func_0011DC48);

INCLUDE_ASM("asm/nonmatchings/game/t_11D000", func_0011DCD8);

extern "C" int func_0011DD68(SA11D_O* self, int a, int b, int c, int d) {
    self->unk20 = b;
    self->unk2C = c;
    self->unk14 = 1;
    VEntry* e = &self->unk44[6];
    return ((int (*)(void*, int, int))e->fn)((char*)self + e->delta, a, d);
}

INCLUDE_ASM("asm/nonmatchings/game/t_11D000", func_0011DDA8);

extern "C" void func_0011DDF8(void) {
}

extern "C" int func_0011DE00(void) {
    return 0;
}

extern "C" int func_0011DE08(void) {
    return 0;
}

extern "C" int func_0011DE10(void) {
    return 0;
}

extern "C" int func_0011DE18(void) {
    return 0;
}

extern "C" int func_0011DE20(void) {
    return 0;
}

extern "C" void func_0011DE28(void) {
}

extern "C" void func_0011DE30(void) {
}

extern "C" void func_0011DE38(void) {
}

extern "C" void func_0011DE40(void) {
}

extern "C" void func_0011DE48(void) {
}

extern "C" int func_0011DE50(void) {
    return 0;
}

extern "C" int func_0011DE58(void) {
    return 0;
}

extern "C" int func_0011DE60(void) {
    return 0;
}

extern "C" int func_0011DE68(void) {
    return 0;
}

extern "C" int func_0011DE70(void) {
    return 0;
}

extern "C" int func_0011DE78(void) {
    return 0;
}

GP_DATA(D_00368BF8);
INCLUDE_ASM("asm/nonmatchings/game/t_11D000", func_0011DE80);

GP_DATA(D_00368C00);
extern "C" void func_0011DEE0(void) {
    D_00368C00 = 0;
    func_00120C80();
}

INCLUDE_ASM("asm/nonmatchings/game/t_11D000", func_0011DF00);

extern "C" void* func_0011DF78(int a, int b, int c, int d) {
    int t = func_0011E190();
    if (t) {
        if (func_0011DD68_5(t, a, b, c, d) == 0) {
            func_0011E3B8(t);
            return 0;
        }
        return (void*)t;
    }
    return 0;
}

INCLUDE_ASM("asm/nonmatchings/game/t_11D000", func_0011E008);

INCLUDE_ASM("asm/nonmatchings/game/t_11D000", func_0011E050);

GP_DATA(D_00368C1C);
extern "C" void func_0011E130(void) {
    D_00368C1C = 0;
    func_0011E540();
    func_0011E560();
    D_00368C1C = 1;
}

GP_DATA(D_00368C04);
extern "C" int func_0011E160(void) {
    return D_00368C04 > 0;
}

extern "C" void func_0011E170(void) {
    func_00120DF0();
}

INCLUDE_ASM("asm/nonmatchings/game/t_11D000", func_0011E190);

INCLUDE_ASM("asm/nonmatchings/game/t_11D000", func_0011E3B8);

INCLUDE_ASM("asm/nonmatchings/game/t_11D000", func_0011E4E8);

extern "C" void func_0011E540(void) {
    func_00120DF8();
}

INCLUDE_ASM("asm/nonmatchings/game/t_11D000", func_0011E560);

GP_DATA(D_00368C24);
GP_DATA(D_00368C28);
extern "C" SA11D_V* func_0011E730(int a) {
    if (D_00368C24 == 0 && a) {
        D_00368C24 = func_0011E7D8(func_00113DF0(0x1C, 0, 1));
    }
    D_00368C28++;
    return D_00368C24;
}

extern "C" void func_0011E780(void) {
    if (D_00368C28 >= 2) {
        D_00368C28--;
    } else {
        SA11D_V* p = D_00368C24;
        if (p) {
            VEntry* e = &p->unk14[1];
            ((void (*)(void*, int))e->fn)((char*)p + e->delta, 3);
        }
        D_00368C24 = 0;
        D_00368C28 = 0;
    }
}

struct S_0011E7D8_b { char pad0[0x18]; void* unk18; void* unk1C; void* unk20; };
struct S_0011E7D8_a { char pad0[0x14]; void* unk14; S_0011E7D8_b* unk18; };
struct C_0011E7D8 { u8 r, g, b, a; };

extern "C" SA11D_V* func_0011E7D8(int a) {
    S_0011E7D8_a* self = (S_0011E7D8_a*)a;
    func_001C55A8((int)self);
    self->unk14 = D_00338C20;
    S_0011E7D8_b* o = (S_0011E7D8_b*)func_00113D20(0x24);
    void* fn = (void*)func_0011E918;
    func_00113EA8(o, 0);
    o->unk1C = fn;
    o->unk20 = self;
    o->unk18 = D_00338C48;
    C_0011E7D8 c;
    c.a = 0xFF;
    self->unk18 = o;
    c.g = 0xFF;
    c.b = 0xFF;
    c.r = 0xFF;
    return (SA11D_V*)self;
}

struct VE_11E868 { s16 unk0; s16 unk2; void (*unk4)(void*, int); };
struct V_11E868 { char pad0[0x10]; VE_11E868 unk10; };
struct O_11E868 { char pad0[0x18]; V_11E868* unk18; };
struct S_11E868 { char pad0[0x14]; void* unk14; O_11E868* unk18; };

extern "C" void func_0011E868(S_11E868* self, int flags) {
    self->unk14 = D_00338C20;
    O_11E868* o = self->unk18;
    if (o) {
        V_11E868* v = o->unk18;
        v->unk10.unk4((char*)o + v->unk10.unk0, 3);
    }
    func_001C5610(self, flags);
}

extern "C" void func_0011E8D0(S_0011E8F8* self) {
    int a = self->unk18;
    func_00114958((char*)D_00370EE0[0] + 8, a);
}

extern "C" void func_0011E8F8(S_0011E8F8* self) {
    func_00113FB8(self->unk18);
}

extern "C" void func_0011E918(void) {
    func_0011E540();
    func_0011E560();
}

extern "C" void func_0011E940(void) {
    func_00113F38();
}

extern "C" void func_0011E960(const char* fmt, ...) {
}

extern "C" void func_0011E998(S_0011E998* self) {
    self->unk1C();
}

extern "C" void func_0011E9B8(void) {
}

INCLUDE_ASM("asm/nonmatchings/game/t_11D000", func_0011E9C0);

extern "C" void func_0011E9D8(void) {
}

INCLUDE_ASM("asm/nonmatchings/game/t_11D000", func_0011E9E0);

INCLUDE_ASM("asm/nonmatchings/game/t_11D000", func_0011EA30);

GP_DATA(D_00368D14);
GP_DATA(D_00368D10);
extern "C" void func_0011EAD8(void) {
    func_0011EA30();
    D_00368D14 = func_002EE340(2, func_0011E9E0 + 0x28, 0);
    func_002EECA0(2);
    int t = D_00368D10;
    if (t != -1 || (D_00368D10 = func_002F49C8()) != t) {
        func_002F4BB8(D_00368D10);
    }
}

GP_DATA(D_00368D10);
GP_DATA(D_00368D14);
extern "C" void func_0011EB48(void) {
    if (D_00368D10 != -1) {
        func_002F4CD0(D_00368D10);
        func_002F4AB0(D_00368D10);
        D_00368D10 = -1;
    }
    func_002EE360(2, D_00368D14);
    D_00368D14 = -1;
}

extern "C" void func_0011EB98(void) {
}

extern "C" void func_0011EBA0(void) {
}

INCLUDE_ASM("asm/nonmatchings/game/t_11D000", func_0011EBA8);

extern "C" long func_0011ECE8(void) {
    return D_00368CF0;
}

GP_DATA(D_00368CD4);
extern "C" u64 func_0011ECF0(void) {
    return D_00368CD4;
}

GP_DATA(D_00368CE0);
extern "C" long func_0011ED00(void) {
    return D_00368CE0;
}

extern "C" float func_0011ED10(void) {
    return D_00368D04;
}

extern "C" float func_0011ED18(void) {
    return D_00368D08;
}

extern "C" float func_0011ED20(void) {
    return D_00368CE8;
}

extern "C" void func_0011ED28(float v) {
    D_00368CEC = v;
}

GP_DATA(D_00368D04);
extern "C" void func_0011ED30(float f) {
    float old = D_00368D04;
    D_00368D04 = f;
    D_00368D00 = old;
}

extern "C" void func_0011ED40(void) {
    func_00317588(D_00376528[0]);
}

INCLUDE_ASM("asm/nonmatchings/game/t_11D000", func_0011ED68);

INCLUDE_ASM("asm/nonmatchings/game/t_11D000", func_0011EE38);

INCLUDE_ASM("asm/nonmatchings/game/t_11D000", func_0011EF00);

INCLUDE_ASM("asm/nonmatchings/game/t_11D000", func_0011EF18);

struct S_0011EF20 { int unk0; unsigned int unk4; };

extern "C" S_0011EF20* func_00120F78(int, int);
extern "C" int D_00368D78;

GP_DATA(D_00368D74);
extern "C" unsigned int func_0011EF20(int a) {
    S_0011EF20* p;
    if (!D_00368748[0] || !D_00368D74) return 0;
    if (!D_00368D78 || !(p = func_00120F78(a, D_00368D78))) return 0;
    return p->unk4 & 0x7FFFFFFF;
}

struct VE_11EF78 { s16 unk0; s16 unk2; void (*unk4)(void*); };
struct V_11EF78 { char pad0[8]; VE_11EF78 unk8; };
struct O_11EF78 { char pad0[0x44]; V_11EF78* unk44; };

GP_DATA(D_00368D74);
extern "C" int func_0011EF78(int a, int b) {
    O_11EF78* o;
    if (!D_00368748[0] || !D_00368D74 || !(o = (O_11EF78*)func_0011DF78(a, 0, 0x64, 0))) return 0;
    func_0011DB88((SA11D_O*)o, b);
    V_11EF78* v = o->unk44;
    v->unk8.unk4((char*)o + v->unk8.unk0);
    func_0011E008(o);
    return 1;
}
