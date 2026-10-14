#include "common.h"

asm(".set D_0036D554_lui, D_0036D554");

struct S288_Ent {
    int unk0;
    int unk4;
    int unk8;
    int unkC;
};

struct S288_EntList {
    S288_Ent *unk0;
    u32 unk4;
};

struct S288_Owner {
    int unk0;
    S288_EntList *unk4;
};

struct S288_VC {
    char pad0[0xC];
    virtual ~S288_VC();
};

struct S288_List {
    char *unk0;
    u32 unk4;
};

asm(".set D_00368A38_lui, D_00368A38");

struct S288_V18 {
    char pad0[0x18];
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7(int, int);
};

struct S288_V0 {
    virtual void v1();
    virtual void v2(int, int);
};

struct S288_Val {
    void *unk0;
    int unk4;
    int unk8;
};

struct S288_Obj {
    char pad0[0xC8];
    int unkC8;
    char padCC[0x20];
    void *unkEC;
    int unkF0;
};

struct S00289C80 {
    char pad[0xEC];
    int unkEC;
};

struct S00289E08 {
    char pad[0xC8];
    int unkC8;
};

struct S0028A000 {
    char pad[0x14];
    int unk14;
};

struct S002899B0 {
    char pad[0x8];
    int unk8;
};

struct S00289608 {
    int unk0;
};

struct S00289EA0_2 {
    char pad[0xC];
    int unkC;
};

struct S00289EA0 {
    char pad[0xC8];
    S00289EA0_2* unkC8;
};

struct S28A5A0_E {
    char pad0[0xC];
    int unkC;
    char pad10[0x20];
};
struct S28A5A0 {
    char pad0[0x40];
    int unk40;
    char pad44[0x60];
    S28A5A0_E *unkA4;
    char padA8[0x20];
    int unkC8;
};

extern "C" {
void func_00289E10(void *, int);
void func_001CEB48(int, void *);
extern int D_00371484;
void func_00289F90(char*);
extern int D_0037148C;
int func_00288910(void*);
int func_00288998(void*);
int func_00288888(void*);
void func_00288D20(void*, void*, int);
void func_0028A020(int, int, int, int, int);
extern int D_00368A38_lui[] asm("D_00368A38_lui") __attribute__((section(".sdata")));
extern int D_0037141C;
int func_0027D470(int, u32, void *, int);
int func_0027D870(int, u32, void *, int);
void func_0011A470(void *);
void func_001DA0C8(int, S288_Obj *);
void func_001D9658(int, u32);
void func_00288A20(S288_Val *, int);
extern int D_003715D4[] __attribute__((section(".sdata")));
int func_00291230(int, int, int *);
void func_0028A650(S288_Obj *, int, int, int, int, int);
void func_0028C200(S288_Obj *);
int func_00119610(int, int);
void func_00119490(int, int);
void func_001194B8(int);
void *func_0011A380(int);
void func_00289228(S288_Val *);
int func_00288F90(int, int, char *);
extern int D_0036D554_lui[] asm("D_0036D554_lui") __attribute__((section(".sdata")));
extern u32 D_00370F40[] __attribute__((section(".sdata")));
u32 func_00275570(void);
void func_001DB708(int, int, int);
void func_001DB8A8(int, int, int);
f32 func_0011ED18(void);
f32 func_0011ED10(void);
void func_00289D30(S288_Obj *, int);
void func_001CE888(int, int *);
void func_001CE868(int, int *);
void func_001CEAD0(int, S288_Obj *);
}

extern "C" void func_00288B10(S288_Val *p) {
    if (p->unk4) {
        if ((p->unk8 & 0xF) == 4) {
            func_00289228(p);
        }
        delete (S288_VC *)p->unk4;
        p->unk4 = 0;
        p->unk8 &= ~0x80;
    }
}

extern "C" void func_00288B88(S288_Val *p, int b, f32 f) {
    func_00288888(p);
    if (b) {
        p->unk8 = (p->unk8 & ~0xF) | 3;
    } else {
        p->unk8 = (p->unk8 & ~0xF) | 2;
    }
    *(f32 *)&p->unk4 = f;
    p->unk8 &= ~0x40;
}

INCLUDE_ASM("asm/nonmatchings/game/t_288B10", func_00288C00);

INCLUDE_ASM("asm/nonmatchings/game/t_288B10", func_00288C48);

INCLUDE_ASM("asm/nonmatchings/game/t_288B10", func_00288C90);

INCLUDE_ASM("asm/nonmatchings/game/t_288B10", func_00288D20);

extern "C" int func_00288D88(int a, int params) {
    int x = 0;
    return func_0027D470(params, 0xEE2A952F, &x, 0) != 0;
}

extern "C" int func_00288DC0(int a, int params) {
    int x = 0;
    return func_0027D470(params, 0x2AAE172E, &x, 0) != 0;
}

extern "C" int func_00288DF8(int a, int params) {
    int x = 0;
    return func_0027D870(params, 0x7321A8D6, &x, 0) != 0;
}

extern "C" int func_00288E30(int a, int b) {
    int r = 0;
    if (func_00288DF8(a, b) || func_00288D88(a, b) || func_00288DC0(a, b)) {
        r = 1;
    }
    return r;
}

struct S288EA8 {
    int unk0;
    int *unk4;
    u32 unk8;
};
extern "C" int func_002890C8(S288EA8 *, int, int *);
extern "C" int func_00289048(int, int, S288_List *);

extern "C" int func_00288EA8(S288EA8 *p, int b, int *out) {
    int r = 0;
    if (p->unk4) {
        if (((p->unk8 >> 4) & 3) == 0) {
            r = func_00288F90((int)p, b, (char *)*p->unk4);
            if (out) *out = 0x7321A8D6;
        }
        int t = (p->unk8 >> 4) & 3;
        if (t == 1) {
            r = func_00289048((int)p, b, (S288_List *)p->unk4);
            if (out) *out = 0xEE2A952F;
        } else if (t == 2) {
            r = func_002890C8(p, b, p->unk4);
            if (out) *out = 0x2AAE172E;
        }
    }
    return r;
}

INCLUDE_ASM("asm/nonmatchings/game/t_288B10", func_00288F90);

extern "C" int func_00289048(int a, int b, S288_List *list) {
    int r = 0;
    for (u32 i = 0; i < list->unk4; i++) {
        r = func_00288F90(a, b, list->unk0 + i * 16);
        if (r) {
            break;
        }
    }
    return r;
}

INCLUDE_ASM("asm/nonmatchings/game/t_288B10", func_002890C8);

INCLUDE_ASM("asm/nonmatchings/game/t_288B10", func_002891A8);

INCLUDE_ASM("asm/nonmatchings/game/t_288B10", func_00289228);

INCLUDE_ASM("asm/nonmatchings/game/t_288B10", func_002892B0);

extern "C" void func_00289608(S00289608* p, int b) {
    if (p->unk0 == b) {
        func_00288888(p);
    }
}

extern "C" void func_002896E0(S288_Val *);
extern "C" void func_00289710(S288_Val *);
extern "C" void func_00289750(S288_Val *);
extern "C" void func_002897E8(S288_Val *);
extern "C" void func_00289868(S288_Val *, int);
extern "C" void func_00289898(S288_Val *, int);
extern "C" void func_002898E8(S288_Val *, int);
extern "C" void func_00289630(S288_Val *p, int a) {
    switch (p->unk8 & 0xF) {
    case 0:
    case 4:
        break;
    case 1:
        func_002896E0(p);
        break;
    case 14:
        func_00289710(p);
        break;
    case 2:
    case 3:
        func_00289750(p);
        break;
    case 5:
        func_002897E8(p);
        break;
    case 8:
    case 9:
    case 10:
    case 11:
    case 12:
    case 13:
        func_00289868(p, a);
        break;
    case 6:
        func_00289898(p, a);
        break;
    case 7:
        func_002898E8(p, a);
        break;
    }
}

extern "C" void func_002896E0(S288_Val *p) {
    if (p->unk4) {
        p->unk4--;
    } else {
        func_00288888(p);
    }
}

GP_DATA(D_0037141C);
extern "C" void func_00289710(S288_Val *p) {
    if (p->unk4) {
        p->unk4--;
    } else if (!D_0037141C) {
        D_0037141C = 1;
        func_00288888(p);
    }
}

extern "C" void func_00289750(S288_Val *p) {
    f32 now;
    if ((p->unk8 & 0xF) == 3) {
        now = func_0011ED18();
    } else {
        now = func_0011ED10();
    }
    if (*(f32 *)&p->unk4 < now) {
        if (((u32)p->unk8 >> 6) & 1) {
            func_00288888(p);
        } else {
            p->unk4 = 0;
        }
    } else {
        *(f32 *)&p->unk4 = *(f32 *)&p->unk4 - now;
    }
    p->unk8 |= 0x40;
}

extern "C" void func_002897E8(S288_Val *p) {
    if (*(f32 *)&p->unk4 <= (f32)(D_00370F40[0] + func_00275570())) {
        func_00288888(p);
    }
}

extern "C" void func_00289868(S288_Val *p, int a) {
    ((S288_V18 *)p->unk0)->v7(a, p->unk4);
}

extern "C" void func_00289898(S288_Val *p, int a) {
    if (((u32)p->unk8 >> 6) & 1) {
        ((S288_V18 *)p->unk0)->v7(a, p->unk4);
    } else {
        p->unk8 |= 0x40;
    }
}

extern "C" void func_002898E8(S288_Val *p, int a) {
    if (((u32)p->unk8 >> 6) & 1) {
        ((S288_V0 *)p->unk0)->v2(a, p->unk4);
    } else {
        p->unk8 |= 0x40;
    }
}

INCLUDE_ASM("asm/nonmatchings/game/t_288B10", func_00289938);

extern "C" int func_002899A8(void) {
    return D_00371484;
}

extern "C" int func_002899B0(S002899B0* p) {
    if (p == 0) {
        return D_0037148C;
    }
    return p->unk8;
}

INCLUDE_ASM("asm/nonmatchings/game/t_288B10", func_002899C8);

struct S289_X {
    int a;
    int b;
    int f;
};
struct S289_Q {
    int a, b, c, d;
};
struct S289_A {
    char pad0[0x1C];
    int a1;
    int b1;
    int f1;
    char pad28[0x24];
    int a2;
    int b2;
    int f2;
};
struct S289_Obj {
    int unk0;
    S289_Obj *unk4;
    S289_Obj *unk8;
    S289_Obj *unkC;
    char pad10[0x2C];
    int unk3C;
    char pad40[4];
    S289_A unk44;
    char pad9C[8];
    int unkA4;
    S289_X unkA8;
    int unkB4;
    char unkB8;
    char padB9[0xB];
    int unkC4;
    S289_X unkC8;
    char padD4[0x18];
    int unkEC;
    int unkF0;
    int unkF4;
    int unkF8;
    int unkFC;
};
static inline void S289_XInit(S289_X *x) {
    x->a = 0;
    x->b = 0;
    x->f &= ~0xF;
    x->f &= ~0x40;
    x->f &= ~0x80;
}
extern "C" S289_Obj *D_0037148C_o asm("D_0037148C");
extern "C" int D_00371490;
extern "C" int D_00371494;
extern "C" void func_001CE7A8(void *, int, int, int);
extern "C" void func_001CE888_3(int, void *, void *) asm("func_001CE888");

GP_DATA(D_0037148C);
GP_DATA(D_00371490);
GP_DATA(D_00371494);
extern "C" S289_Obj *func_002899D8(S289_Obj *o) {
    S289_A *ap = &o->unk44;
    S289_X *c = &o->unkC8;
    ap->b1 = 0;
    ap->a1 = 0;
    ap->f1 &= ~0xF;
    ap->f1 &= ~0x40;
    ap->f1 &= ~0x80;
    ap->a2 = 0;
    ap->b2 = 0;
    ap->f2 &= ~0xF;
    ap->f2 &= ~0x40;
    ap->f2 &= ~0x80;
    S289_XInit(&o->unkA8);
    o->unkB8 = 0;
    c->b = 0;
    c->f = 0;
    func_001CE7A8((char *)o + 0x100, -0x81, -0x41, -0x10);
    c->a = 0;
    o->unk0 = 0;
    o->unk4 = 0;
    o->unk8 = 0;
    S289_Q *e = (S289_Q *)((char *)o + 0xC);
    for (int i = 0; i < 16; i++) {
        e->a = 0;
        e->b = 0;
        e->c = 0;
        e->d = 0;
        e++;
    }
    o->unk8 = D_0037148C_o;
    if (D_0037148C_o) D_0037148C_o->unkC = o;
    D_0037148C_o = o;
    D_00371490 += 1;
    o->unkB4 = D_00371494;
    o->unk4 = 0;
    D_00371494 += 1;
    int c8 = c->a;
    o->unkA4 = (int)ap;
    o->unk3C = (int)((char *)o + 0x28);
    o->unkC4 = 0;
    o->unkF0 = 0;
    o->unkF4 = 0;
    o->unkF8 = 0;
    o->unkFC = 0;
    if (c8) {
        func_001CE888_3(c8, c, (char *)o + 0x28);
        c->a = 0;
    }
    c->a = 0;
    o->unkEC = 0;
    return o;
}

INCLUDE_ASM("asm/nonmatchings/game/t_288B10", func_00289B40);

extern "C" int func_00289C80(S00289C80* p) {
    return p->unkEC;
}

extern "C" void func_00289C88(S288_Obj *p, int size) {
    int heap = D_00368A38_lui[0];
    func_00119490(heap, func_00119610(heap, 5));
    void *m = func_0011A380(size);
    int h = D_00368A38_lui[0];
    p->unkEC = m;
    func_001194B8(h);
}

extern "C" void func_00289CF8(S288_Obj *p) {
    if (p->unkEC) {
        func_0011A470(p->unkEC);
        p->unkEC = 0;
    }
}

INCLUDE_ASM("asm/nonmatchings/game/t_288B10", func_00289D30);

extern "C" int func_00289E08(S00289E08* p) {
    return p->unkC8;
}

INCLUDE_ASM("asm/nonmatchings/game/t_288B10", func_00289E10);

extern "C" int func_00289EA0(S00289EA0* p, int m) {
    if (p->unkC8 != 0 && (p->unkC8->unkC & m)) {
        return 1;
    }
    return 0;
}

INCLUDE_ASM("asm/nonmatchings/game/t_288B10", func_00289EC8);

INCLUDE_ASM("asm/nonmatchings/game/t_288B10", func_00289ED8);

extern "C" void func_00289F48(char* a) {
    func_00288910(a + 0xA8);
}

INCLUDE_ASM("asm/nonmatchings/game/t_288B10", func_00289F68);

extern "C" void func_00289F70(char* a) {
    func_00288998(a + 0xA8);
}

extern "C" void func_00289F90(char* a) {
    func_00288888(a + 0xA8);
}

extern "C" void func_00289FB0(char* a, int b) {
    func_00288D20(a + 0xA8, a, b);
}

extern "C" void func_00289FD8(char* a) {
    func_00289F90(a);
}

INCLUDE_ASM("asm/nonmatchings/game/t_288B10", func_00289FF8);

extern "C" int func_0028A000(S0028A000* p) {
    return p->unk14 != 0;
}

extern "C" void func_0028A010(void) {
}

extern "C" void func_0028A018(void) {
}

INCLUDE_ASM("asm/nonmatchings/game/t_288B10", func_0028A020);

INCLUDE_ASM("asm/nonmatchings/game/t_288B10", func_0028A140);

extern "C" void func_0028A2A8(int a, int b, int c, int d) {
    func_0028A020(a, b, 0, c, d);
}

extern "C" void func_0028A2D0(int a, int b, int c, int d) {
    func_0028A020(a, b, 0, c, d);
}

INCLUDE_ASM("asm/nonmatchings/game/t_288B10", func_0028A2F8);

INCLUDE_ASM("asm/nonmatchings/game/t_288B10", func_0028A300);

extern "C" void func_0028A558(S288_Obj *p) {
    if (p->unkF0) {
        func_001DA0C8(p->unkF0, p);
        func_001D9658(p->unkF0, 0x8B713E0E);
    }
}

extern "C" void func_0028A5A0(S28A5A0 *p, int v) {
    if (v) {
        int i;
        for (i = 0; i < p->unk40; i++) {
            if (p->unkA4[i].unkC == v) {
                func_001CEB48(v, p);
                p->unkA4[i].unkC = 0;
            }
        }
        if (p->unkC8 == v) {
            func_00289E10(p, 0);
        }
        func_00289F90((char *)p);
    }
}

INCLUDE_ASM("asm/nonmatchings/game/t_288B10", func_0028A650);

INCLUDE_ASM("asm/nonmatchings/game/t_288B10", func_0028AAB8);

INCLUDE_ASM("asm/nonmatchings/game/t_288B10", func_0028AAC0);
