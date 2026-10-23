// cflags: -funroll-loops
#include "common.h"

struct S29B510_H {
    char pad0[0x21C];
    int unk21C;
};
struct S29B510_N {
    char pad0[0xC];
    S29B510_N *unkC;
    S29B510_N *unk10;
};
struct S29B510_O {
    char pad0[0x30B0];
    S29B510_N unk30B0;
    char pad30C4[0x60];
    int unk3124;
    int unk3128;
    u16 unk312C;
    char pad312E[0x1E];
    void *unk314C;
    int unk3150;
};
struct S29B510_P {
    char pad0[0x1864];
    int unk1864;
    int unk1868;
    char pad186C[0xA70];
    S29B510_N unk22DC;
};

extern "C" {
S29B510_O *func_0029E578(int, int);
int func_00299E18(void *);
int func_0011EF10(void);
void func_001194B8(S29B510_H *);
void func_00119490(S29B510_H *, int);
extern S29B510_H *D_00368A38_p asm("D_00368A38");
extern int D_00368A38;
int Heap_Alloc(int, int, int, int);
int func_00118F20_h(S29B510_H *, int, int, int) asm("Heap_Alloc");
void func_00296DE0(int, int, int, int, int, int);
void *memset(void *, int, int);
}

struct S0029BDA0 {
    char pad[0x3138];
    u32 unk3138;
    u32 unk313C;
};

struct S29AA58 {
    int unk0;
    char unk4[0x28];
    int unk2C;
    int unk30;
    int unk34;
};
extern "C" S29AA58 *func_0029AA58(S29AA58 *p) {
    memset(p->unk4, 0, 0x28);
    p->unk0 = 0x3E8;
    p->unk2C = 0;
    p->unk30 = 0;
    p->unk34 = 0;
    return p;
}

struct S29AA_R {
    int unk0;
    int v[10];
    int unk2C;
};

extern "C" void func_0029AAA0(S29AA_R *r, int x) {
    int sum = 0;
    int n = 0;
    r->v[r->unk2C] = x;
    r->unk2C = (u32)(r->unk2C + 1) % 10;
    for (int i = 0; i < 10; i++) {
        if (r->v[i]) {
            sum += r->v[i];
            n++;
        }
    }
    if (n > 0)
        r->unk0 = sum / n;
}

INCLUDE_ASM("asm/nonmatchings/game/t_29AA58", func_0029ABB8);

INCLUDE_ASM("asm/nonmatchings/game/t_29AA58", func_0029AFF0);

INCLUDE_ASM("asm/nonmatchings/game/t_29AA58", func_0029B258);

INCLUDE_ASM("asm/nonmatchings/game/t_29AA58", func_0029B3A8);

INCLUDE_ASM("asm/nonmatchings/game/t_29AA58", func_0029B468);

extern "C" S29B510_O *func_0029B510(S29B510_P *p, int a, u16 b, int c) {
    S29B510_O *o = 0;
    func_00119490(D_00368A38_p, D_00368A38_p->unk21C);
    if (p->unk1864 < p->unk1868) {
        o = func_0029E578(func_00118F20_h(D_00368A38_p, 0x3164, 1, 0), c);
        o->unk3128 = a;
        o->unk312C = b;
        o->unk3124 = func_00299E18(p);
        o->unk314C = p;
        o->unk3150 = func_0011EF10();
        S29B510_N *n = &o->unk30B0;
        S29B510_N *h = &p->unk22DC;
        n->unk10 = h->unk10;
        n->unkC = h;
        h->unk10->unkC = n;
        h->unk10 = n;
    }
    func_001194B8(D_00368A38_p);
    return o;
}

extern "C" void func_0029B5F8(int a, u8 b, u16 c, int d, u8 e, s8 f) {
    func_00296DE0(Heap_Alloc(D_00368A38, 0x14, 1, 0), b, c, d, e, f);
}

INCLUDE_ASM("asm/nonmatchings/game/t_29AA58", func_0029B680);

INCLUDE_ASM("asm/nonmatchings/game/t_29AA58", func_0029B8D0);

INCLUDE_ASM("asm/nonmatchings/game/t_29AA58", func_0029BB28);

extern "C" int func_0029BDA0(void* a, S0029BDA0* p) {
    return p->unk313C > p->unk3138;
}

INCLUDE_ASM("asm/nonmatchings/game/t_29AA58", func_0029BDB0);

INCLUDE_ASM("asm/nonmatchings/game/t_29AA58", func_0029BF58);

struct S29A_Base {
    char pad0[0x14];
    virtual ~S29A_Base();
};
struct S29A_Obj {
    u8 unk0;
};
struct S29A_Lk {
    int unk0;
    int unk4;
    int unk8;
    S29A_Lk *unkC;
};
struct S29A_El0 : S29A_Base {
    S29A_Obj *unk18;
};
struct S29A_El1 : S29A_Base {
    char pad18[4];
    S29A_Obj *unk1C;
};
struct S29A_El2 : S29A_Base {
    char pad18[0x14];
    S29A_Obj *unk2C;
};
extern "C" char D_0035C528[];
extern "C" char D_0035C540[];
extern "C" char D_0035C5B0[];
struct S29A_ItA {
    int pad0;
    S29A_Lk *cur;
    char *vptr;
    S29A_ItA(S29A_Lk *l) { cur = l; vptr = D_0035C540; }
    ~S29A_ItA() { vptr = D_0035C540; }
};
struct S29A_ItB {
    int pad0;
    S29A_Lk *cur;
    char *vptr;
    S29A_ItB(S29A_Lk *l) { cur = l; vptr = D_0035C528; }
    ~S29A_ItB() { vptr = D_0035C528; }
};
struct S29A_ItC {
    int pad0;
    S29A_Lk *cur;
    char *vptr;
    S29A_ItC(S29A_Lk *l) { cur = l; vptr = D_0035C5B0; }
    ~S29A_ItC() { vptr = D_0035C5B0; }
};

static inline void S29A_Pick(void *&o, S29A_Lk *c) {
    if (!c) o = 0;
    else o = (void *)c->unk4;
}

static inline void *S29A_Get0(S29A_Lk *c) {
    void *r;
    S29A_Pick(r, c);
    return r;
}

extern "C" void func_00296D88(S29A_Obj *, int);
extern "C" void func_00296EC0(S29A_Obj *, int);

extern "C" void func_0029C1C0(void *self, char *base, int which, u32 key0) {
    u8 key = key0;
    S29A_Lk *n0, *n1, *nn, *nf;
    S29A_Lk *p0, *p1, *pn, *pf;
    S29A_Lk *q0, *q1, *qn, *qf;
    switch (which) {
    case 0: {
        S29A_ItC *pa;
        S29A_ItC it((S29A_Lk *)(base + 0x30DC));
        S29A_El0 *e, *nx;
        n0 = it.cur->unkC;
        it.cur = ((u32)which < (u32)~n0->unk4) ? n0 : 0;
        e = (S29A_El0 *)S29A_Get0(it.cur);
        if (e) {
            pa = &it;
            while (e) {
                n1 = it.cur->unkC;
                nn = 0;
                if (~n1->unk4 != 0) nn = n1;
                pa->cur = nn;
                nx = (S29A_El0 *)S29A_Get0(nn);
                S29A_Obj *o = e->unk18;
                if (o->unk0 == key) {
                    int *rc = (int *)((char *)o + 8);
                    if (--rc[1] == 0 && o) func_00296D88(o, 3);
                    delete e;
                }
                e = nx;
            }
        }
        break;
    }
    case 1: {
        S29A_ItA *pa;
        S29A_ItA it((S29A_Lk *)(base + 0x30F4));
        S29A_El1 *e, *nx;
        p0 = it.cur->unkC;
        pf = 0;
        if (~p0->unk4 != 0) pf = p0;
        it.cur = pf;
        e = (S29A_El1 *)S29A_Get0(it.cur);
        if (e) {
            pa = &it;
            while (e) {
                p1 = it.cur->unkC;
                pn = 0;
                if (~p1->unk4 != 0) pn = p1;
                pa->cur = pn;
                nx = (S29A_El1 *)S29A_Get0(pn);
                S29A_Obj *o = e->unk1C;
                if (o->unk0 == key) {
                    int *rc = (int *)((char *)o + 8);
                    if (--rc[1] == 0 && o) func_00296D88(o, 3);
                    delete e;
                }
                e = nx;
            }
        }
        break;
    }
    case 2: {
        S29A_ItB *pa;
        S29A_ItB it((S29A_Lk *)(base + 0x310C));
        S29A_El2 *e, *nx;
        q0 = it.cur->unkC;
        qf = 0;
        if (~q0->unk4 != 0) qf = q0;
        it.cur = qf;
        e = (S29A_El2 *)S29A_Get0(it.cur);
        if (e) {
            pa = &it;
            while (e) {
                q1 = it.cur->unkC;
                qn = 0;
                if (~q1->unk4 != 0) qn = q1;
                pa->cur = qn;
                nx = (S29A_El2 *)S29A_Get0(qn);
                S29A_Obj *o = e->unk2C;
                if (o->unk0 == key) {
                    int *rc = (int *)((char *)o + 0xC);
                    if (--rc[1] == 0 && o) func_00296EC0(o, 3);
                    delete e;
                }
                e = nx;
            }
        }
        break;
    }
    }
}

INCLUDE_ASM("asm/nonmatchings/game/t_29AA58", func_0029C4C0);
