#include "common.h"

struct S29F6_El {
    char pad0[0x18];
    u8 unk18;
    char pad19[0xB];
    u8 unk24;
};
struct S29F6_Lk {
    int unk0;
    int unk4;
    int unk8;
    S29F6_Lk *unkC;
};
extern "C" char D_0035C528[];
extern "C" char D_0035C540[];
extern "C" char D_0035C5B0[];
struct S29F6_ItA {
    int pad0;
    S29F6_Lk *cur;
    char *vptr;
    S29F6_ItA(S29F6_Lk *l) { cur = l; vptr = D_0035C540; }
    ~S29F6_ItA() { vptr = D_0035C540; }
};
struct S29F6_ItB {
    int pad0;
    S29F6_Lk *cur;
    char *vptr;
    S29F6_ItB(S29F6_Lk *l) { cur = l; vptr = D_0035C528; }
    ~S29F6_ItB() { vptr = D_0035C528; }
};

struct S29F6_ItC {
    int pad0;
    S29F6_Lk *cur;
    char *vptr;
    S29F6_ItC(S29F6_Lk *l) { cur = l; vptr = D_0035C5B0; }
    ~S29F6_ItC() { vptr = D_0035C5B0; }
};

template <class T> static inline void S29F6_Adv(T &it) {
    S29F6_Lk *n = it.cur->unkC;
    it.cur = (~n->unk4 == 0) ? 0 : n;
}

static inline void S29F6_Pick(S29F6_El *&o, S29F6_Lk *c) {
    if (!c) o = 0;
    else o = (S29F6_El *)c->unk4;
}

template <class T> static inline S29F6_El *S29F6_Get0(T &it) {
    S29F6_El *r;
    S29F6_Pick(r, it.cur);
    return r;
}

static inline S29F6_El *S29F6_GetL(S29F6_Lk *c) {
    S29F6_El *r;
    S29F6_Pick(r, c);
    return r;
}

struct S29F598_0 {
    char pad0[0x3148];
    s32 unk3148;
};

struct S29F628_0 {
    char pad0[0x3158];
    s32 unk3158;
};

struct S29F638_0 {
    char pad0[0x30AC];
    s32 unk30AC;
};

struct S29F970_0 {
    char pad0[0x30CC];
    s32 unk30CC;
};

struct S29FA00_0 {
    char pad0[0x30D8];
    s32 unk30D8;
};

struct S29F288_A {
    char pad0[0x30D8];
    int unk30D8;
};

extern "C" {
void func_0027AC90(void *);
extern char D_0035CC10[];
void func_00121668(void);
extern char D_0035CC28[];
void func_00117168(void);
extern char D_0035CC40[];
void func_001C5730(void);
extern char D_0035CC58[];
void func_002750F0(void);
void Heap_Free(int, void *);
void *Heap_Alloc(int, int, int, int);
int func_00297458(void *);
extern int D_00368A38;
int func_0011EF10(void);
int func_002763E0(int, int);
void func_0027ABB0(int, int);
void func_0029ABB8(void *, int);
extern char D_0035C858[];
void func_0027AA70(void *);
extern char D_0035C830[];
int func_0011A128(void);
int func_0027D400(int, int, int, int);
int func_0029AFF0(void);
void func_0029F9F8(int, int);
}

struct S29F2_E {
    char pad0[0x18];
    int *unk18;
    int *unk1C;
    char pad20[0xC];
    int *unk2C;
};

extern "C" void func_00296D88(void *, int);
extern "C" void func_00296EC0(void *, int);

extern "C" void func_0029F288(char *base) {
    S29F6_Lk *n1, *n2, *n3, *nn, *mm, *kk, *l2, *l3;
    S29F6_ItC *pa;
    S29F6_ItC c((S29F6_Lk *)(base + 0x30DC));
    S29F6_ItA a(0);
    S29F6_ItB b(0);
    S29F2_E *e, *nx, *f, *fx, *g, *gx;
    S29F6_Adv(c);
    e = (S29F2_E *)S29F6_Get0(c);
    l2 = (S29F6_Lk *)(base + 0x30F4);
    l3 = (S29F6_Lk *)(base + 0x310C);
    if (e) {
        pa = &c;
        while (e) {
            n1 = c.cur->unkC;
            nn = 0;
            if (~n1->unk4 != 0) nn = n1;
            pa->cur = nn;
            nx = (S29F2_E *)S29F6_GetL(nn);
            int *o = e->unk18;
            int *rc = (int *)((char *)o + 8);
            if (--rc[1] == 0 && o) func_00296D88(o, 3);
            e = nx;
        }
    }
    a.cur = l2;
    S29F6_Adv(a);
    f = (S29F2_E *)S29F6_Get0(a);
    while (f) {
        n2 = a.cur->unkC;
        mm = 0;
        if (~n2->unk4 != 0) mm = n2;
        a.cur = mm;
        fx = (S29F2_E *)S29F6_GetL(mm);
        int *o = f->unk1C;
        int *rc = (int *)((char *)o + 8);
        if (--rc[1] == 0 && o) func_00296D88(o, 3);
        f = fx;
    }
    b.cur = l3;
    S29F6_Adv(b);
    g = (S29F2_E *)S29F6_Get0(b);
    while (g) {
        n3 = b.cur->unkC;
        kk = 0;
        if (~n3->unk4 != 0) kk = n3;
        b.cur = kk;
        gx = (S29F2_E *)S29F6_GetL(kk);
        int *o = g->unk2C;
        int *rc = (int *)((char *)o + 0xC);
        if (--rc[1] == 0 && o) func_00296EC0(o, 3);
        g = gx;
    }
}

INCLUDE_ASM("asm/nonmatchings/game/t_29F288", func_0029F4F8);

struct S29F500 {
    char pad0[0x3150];
    u32 unk3150;
};
extern "C" void func_0029F500(S29F500 *p, int n) {
    u32 t = func_0011EF10() + n;
    if (p->unk3150 < t) {
        p->unk3150 = t;
    }
}

INCLUDE_ASM("asm/nonmatchings/game/t_29F288", func_0029F548);

struct S29F550 {
    char pad0[0x3144];
    int unk3144;
};
extern "C" void func_0029F550(S29F550 *p) {
    volatile int v = 4;
    p->unk3144 = (p->unk3144 & ~1) | 4;
}

INCLUDE_ASM("asm/nonmatchings/game/t_29F288", func_0029F578);

extern "C" s32 func_0029F598(S29F598_0 *arg0) {
    s32 x = arg0->unk3148 & 4;
    return x != 0;
}

extern "C" s32 func_0029F5A8(S29F598_0 *arg0) {
    return arg0->unk3148 & 1;
}

extern "C" s32 func_0029F5B8(S29F598_0 *arg0) {
    s32 x = arg0->unk3148 & 2;
    return x != 0;
}

INCLUDE_ASM("asm/nonmatchings/game/t_29F288", func_0029F5C8);

extern "C" void func_0029F628(S29F628_0 *arg0, s32 arg1) {
    arg0->unk3158 = arg1;
}

extern "C" s32 func_0029F630(S29F628_0 *arg0) {
    return arg0->unk3158;
}

extern "C" void func_0029F638(S29F638_0 *arg0, s32 arg1) {
    arg0->unk30AC = arg1;
}

extern "C" s32 func_0029F640(S29F638_0 *arg0) {
    return arg0->unk30AC;
}

extern "C" u8 func_0029F648(char *base) {
    S29F6_Lk *n1, *n2, *nn;
    S29F6_ItA *pa;
    S29F6_ItA a((S29F6_Lk *)(base + 0x30F4));
    S29F6_ItB b(0);
    u8 m = 0;
    S29F6_Adv(a);
    S29F6_El *e = S29F6_Get0(a);
    if (e) {
        pa = &a;
        while (e) {
            int v = e->unk24;
            n1 = a.cur->unkC;
            if (m < v) m = v;
            nn = 0;
            if (~n1->unk4 != 0) nn = n1;
            pa->cur = nn;
            S29F6_Pick((S29F6_El *&)e, nn);
        }
    }
    b.cur = (S29F6_Lk *)(base + 0x310C);
    S29F6_Adv(b);
    S29F6_El *f = S29F6_Get0(b);
    while (f) {
        int v = f->unk18;
        n2 = b.cur->unkC;
        if (m < v) m = v;
        nn = 0;
        if (~n2->unk4 != 0) nn = n2;
        b.cur = nn;
        S29F6_Pick(f, nn);
    }
    return m;
}

INCLUDE_ASM("asm/nonmatchings/game/t_29F288", func_0029F790);

extern "C" void func_0029F840(char *base) {
    S29F6_Lk *n1, *n2, *nn, *l2;
    S29F6_ItA *pa;
    S29F6_ItA a((S29F6_Lk *)(base + 0x30F4));
    S29F6_ItB b(0);
    S29F6_Adv(a);
    S29F6_El *e = S29F6_Get0(a);
    if (e) {
        pa = &a;
        while (e) {
            e->unk24 = 0;
            n1 = a.cur->unkC;
            nn = 0;
            if (~n1->unk4 != 0) nn = n1;
            pa->cur = nn;
            S29F6_Pick(e, nn);
        }
    }
    l2 = (S29F6_Lk *)(base + 0x310C);
    b.cur = l2;
    S29F6_Adv(b);
    S29F6_El *f = S29F6_Get0(b);
    while (f) {
        f->unk18 = 0;
        n2 = b.cur->unkC;
        nn = 0;
        if (~n2->unk4 != 0) nn = n2;
        b.cur = nn;
        S29F6_Pick(f, nn);
    }
}

extern "C" s32 func_0029F970(S29F970_0 *arg0) {
    return arg0->unk30CC;
}

extern "C" void func_0029F978(S29F970_0 *arg0, s32 arg1) {
    arg0->unk30CC = arg1;
    switch (arg1) {                                 /* irregular */
    case 1:
        func_0029F9F8((s32) arg0, 0x1068);
        return;
    case 0:
        func_0029F9F8((s32) arg0, 0x61A80);
        break;
    case 2:
        func_0029F9F8((s32) arg0, 0xC3500);
        break;
    }
}

extern "C" void func_0029F9F8(int p, int v) {
    ((S29F288_A *)p)->unk30D8 = v;
}

extern "C" s32 func_0029FA00(S29FA00_0 *arg0) {
    return arg0->unk30D8;
}

struct S29FA_El {
    char pad0[0x18];
    int unk18, unk1C, unk20;
};

extern "C" void func_0029FA08(char *base, int key) {
    S29F6_Lk *n1, *n2, *nn;
    S29F6_ItA a((S29F6_Lk *)(base + 0x30F4));
    S29F6_ItB b(0);
    S29F6_Adv(a);
    S29FA_El *e = (S29FA_El *)S29F6_Get0(a);
    if (e) {
        while (e) {
            if (e->unk20 == key) e->unk18 = 0;
            n1 = a.cur->unkC;
            nn = 0;
            if (~n1->unk4 != 0) nn = n1;
            a.cur = nn;
            S29F6_Pick((S29F6_El *&)e, nn);
        }
    }
    b.cur = (S29F6_Lk *)(base + 0x310C);
    S29F6_Adv(b);
    S29FA_El *f = (S29FA_El *)S29F6_Get0(b);
    while (f) {
        if (f->unk1C == key) f->unk20 = 0;
        n2 = b.cur->unkC;
        nn = 0;
        if (~n2->unk4 != 0) nn = n2;
        b.cur = nn;
        S29F6_Pick((S29F6_El *&)f, nn);
    }
}

INCLUDE_ASM("asm/nonmatchings/game/t_29F288", func_0029FB40);

INCLUDE_ASM("asm/nonmatchings/game/t_29F288", func_0029FBA8);

INCLUDE_ASM("asm/nonmatchings/game/t_29F288", func_0029FC10);

INCLUDE_ASM("asm/nonmatchings/game/t_29F288", func_0029FC80);

INCLUDE_ASM("asm/nonmatchings/game/t_29F288", func_0029FCE8);

struct S29FD08 {
    char pad0[4];
    char unk4[8];
    void *unkC;
};
extern "C" S29FD08 *func_0029FD08(S29FD08 *p) {
    p->unkC = D_0035C830;
    func_0027AA70(p->unk4);
    return p;
}

extern "C" void func_0029FD40(S29FD08 *p, int b) {
    p->unkC = D_0035C830;
    func_0027AC90(p->unk4);
    if (b & 1) {
        Heap_Free(D_00368A38, p);
    }
}

INCLUDE_ASM("asm/nonmatchings/game/t_29F288", func_0029FD98);

extern "C" s32 func_0029FDA8(s32 arg0, s32 arg1) {
    s32 sp0;

    sp0 = 0;
    func_0027D400(arg0 + 4, arg1, (s32) &sp0, 0);
    return sp0;
}

INCLUDE_ASM("asm/nonmatchings/game/t_29F288", func_0029FDD8);

extern "C" int func_0029FE00(int a, int b, int c) {
    int out = 0;
    if ((func_0027D400(a + 4, b, (int)&out, 0) ^ 1) != 0) {
        return 0;
    }
    if (c != 0) {
        func_0027ABB0(out, c);
    }
    return 1;
}

INCLUDE_ASM("asm/nonmatchings/game/t_29F288", func_0029FE58);

extern "C" int func_0029FE60(int a, int b) {
    int r = func_002763E0(b, 1);
    if (r != 0) {
        func_0027ABB0(a + 4, r);
    }
    return 1;
}

INCLUDE_ASM("asm/nonmatchings/game/t_29F288", func_0029FEA0);

struct S29FEA8 {
    char pad0[0x20];
    int unk20;
};
extern "C" int func_0029FEA8(S29FEA8 *p) {
    p->unk20 = func_00297458(Heap_Alloc(D_00368A38, 0x98, 1, 0));
    return 1;
}

extern "C" s32 func_0029FEF0(void) {
    return 1;
}

extern "C" s32 func_0029FEF8(void) {
    return 0;
}

extern "C" s32 func_0029FF00(void) {
    return 1;
}

extern "C" s32 func_0029FF08(void) {
    return 0;
}

extern "C" s32 func_0029FF10(void) {
    return 0;
}

extern "C" s32 func_0029FF18(void) {
    return 0;
}

struct S29FF20 {
    char pad0[0x2418];
    void *unk2418;
};
extern "C" S29FF20 *func_0029FF20(S29FF20 *p) {
    func_0029ABB8(p, 0);
    p->unk2418 = D_0035C858;
    return p;
}

extern "C" s32 func_0029FF58(void) {
    return 0;
}

extern "C" void func_0029FF60(void) {
}

extern "C" void func_0029FF68(void) {
}

extern "C" void func_0029FF70(void) {
}

extern "C" s32 func_0029FF78(void) {
    return 0;
}

extern "C" s32 func_0029FF80(void) {
    return 1;
}

extern "C" void func_0029FF88(void) {
}

extern "C" void func_0029FF90(void) {
}

extern "C" void func_0029FF98(void) {
}

extern "C" void func_0029FFA0(void) {
}

extern "C" void func_0029FFA8(void) {
}

extern "C" s32 func_0029FFB0(void) {
    return 0;
}

INCLUDE_ASM("asm/nonmatchings/game/t_29F288", func_0029FFB8);

extern "C" void func_002A0000(void) {
    func_0029AFF0();
}

INCLUDE_ASM("asm/nonmatchings/game/t_29F288", func_002A0020);

extern "C" void func_002A0098(void) {
    func_0011A128();
}

INCLUDE_ASM("asm/nonmatchings/game/t_29F288", func_002A00B8);

INCLUDE_ASM("asm/nonmatchings/game/t_29F288", func_002A1078);

INCLUDE_ASM("asm/nonmatchings/game/t_29F288", func_002A1110);

struct Sfunc_002A1170 {
    char pad0[0xC];
    void *unkC;
};
extern "C" void func_002A1170(Sfunc_002A1170 *p, int b) {
    p->unkC = D_0035CC58;
    func_002750F0();
    if (b & 1) {
        Heap_Free(D_00368A38, p);
    }
}

struct Sfunc_002A11C0 {
    char pad0[0xC];
    void *unkC;
};
extern "C" void func_002A11C0(Sfunc_002A11C0 *p, int b) {
    p->unkC = D_0035CC40;
    func_001C5730();
    if (b & 1) {
        Heap_Free(D_00368A38, p);
    }
}

struct Sfunc_002A1210 {
    char pad0[0xC];
    void *unkC;
};
extern "C" void func_002A1210(Sfunc_002A1210 *p, int b) {
    p->unkC = D_0035CC28;
    func_00117168();
    if (b & 1) {
        Heap_Free(D_00368A38, p);
    }
}

struct Sfunc_002A1260 {
    char pad0[0xC];
    void *unkC;
};
extern "C" void func_002A1260(Sfunc_002A1260 *p, int b) {
    p->unkC = D_0035CC10;
    func_00121668();
    if (b & 1) {
        Heap_Free(D_00368A38, p);
    }
}
