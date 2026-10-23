#include "common.h"

struct S29D730 {
    char pad0[0x2418];
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual int v5();
    virtual void v6(int);
    virtual void v7(int);
};

struct S29D8C8_0 {
    char pad0[0x2294];
    s32 unk2294;
};

struct S29E200_0 {
    char pad0[0xC];
    void *unkC;
    void *unk10;
    void *unk14;
};

struct S29E4C8_0 {
    char pad0[0x8];
    void *unk8;
};

struct S29D_Node {
    int unk0;
    int unk4;
    char pad8[0x4];
    S29D_Node *unkC;
    S29D_Node *unk10;
};

struct S29D_It {
    int unk0;
    S29D_Node *cur;
    char *vptr;
};

struct S29D_Big {
    char pad0[0x3160];
    virtual ~S29D_Big();
};

static inline S29D_Node *S29D_Valid(S29D_Node *n) {
    if (n->unk4 == -1) {
        return 0;
    }
    return n;
}

struct S29D_Self {
    char pad0[0x2418];
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6(int);
    virtual void v7(int);
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
};

extern "C" {
void func_0029A7B8(char *, int, char *, int, int *);
int func_002FEC68(int, int, int, int);
int func_0029D600(int, S29D_It *);
int func_0029F5B8(int);
void func_0029DE80(void *, int);
extern char D_0034ACA8[];
void func_0029C4C0(void *, int, int);
void func_0029EAC8(void *);
void func_0029F288(void *);
void func_0029EC40(void *);
u32 func_0029F630(void *);
int func_0029F640(void *);
int func_0029D5C8(char *, S29D_It *);
extern int D_0035C4E8[];
extern int D_0035C5B0[];
extern char D_0035C528[];
extern char D_0035C540[];
extern char D_0035C510[];
extern int D_0035C5C8[];
extern int D_0035C720[];
extern int D_0035C768[];
extern s32 D_00368A38[] __attribute__((section(".sdata")));
int func_00113F38(void);
int Heap_Free(s32, void *);
int memset(s32, int, int);
void func_0029F638(int, int);
int func_0029D8C8(S29D8C8_0 *);
}

INCLUDE_ASM("asm/nonmatchings/game/t_29D230", func_0029D230);

extern "C" void func_0029D238(char *obj, int a) {
    S29D_It it;
    it.vptr = D_0034ACA8;
    it.cur = 0;
    int x = func_0029D5C8(obj, &it);
    if (x) {
        func_0029C4C0(obj, *(int *)(x + 0x3124), a);
    }
    it.vptr = D_0034ACA8;
}

INCLUDE_ASM("asm/nonmatchings/game/t_29D230", func_0029D2A0);

struct S29D370_Self {
    char pad0[0x1820];
    int unk1820;
    char pad1824[0x186C - 0x1824];
    char unk186C[0xA28];
    int unk2294;
    char pad2298[0x2418 - 0x2298];
    virtual void v1();
    virtual void v2();
    virtual int v3(int);
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8(void *, int);
};
struct S29D370_P {
    s16 unk0;
    s16 unk2;
    int unk4;
};
extern "C" {
int func_002FF0D8(int);
int func_002FEE38(int, void *, int, int, void *, int);
void func_0030A2F4(void *, void *, int);
int Heap_Alloc(s32, int, int, int);
int memset_(void *, int, int) __asm__("memset");
}
static inline void S29D370_Pick(int &c, int flags, u32 a6) {
    if (flags & 0x80) {
        c = a6 != 0;
    }
}

extern "C" int func_0029D370(S29D370_Self *o, int x, u32 key, char *src, int len, int a5, u32 a6) {
    char buf[0x10];
    S29D370_P *pk = (S29D370_P *)buf;
    u32 k = key & 0xFFFF;
    o->v8(buf, 0x10);
    memset_(buf, 0, 0x10);
    pk->unk0 = 2;
    pk->unk2 = func_002FF0D8(k);
    int r;
    pk->unk4 = x;
    if (o->unk2294 & 0x20) {
        int t;
        func_0029A7B8((char *)o, (int)src, o->unk186C, len, &t);
        r = func_002FEE38(o->unk1820, o->unk186C, t, a5, buf, 0x10);
    } else {
        int heaped = 0;
        char *ptr = src;
        int c = 0;
        S29D370_Pick(c, o->unk2294, a6);
        if (c != 0) {
            int l2 = len + 2;
            heaped = 1;
            ptr = (char *)Heap_Alloc(D_00368A38[0], l2, 1, 0);
            *(s16 *)ptr = len;
            func_0030A2F4(ptr + 2, src, len);
            len = l2;
        }
        r = func_002FEE38(o->unk1820, ptr, len, a5, buf, 0x10);
        if (heaped && ptr) {
            Heap_Free(D_00368A38[0], ptr);
        }
    }
    if (r < 0) {
        int t = o->v3(r);
        if (t != 0) {
            return 0;
        }
    }
    return 1;
}

extern "C" int func_0029D530(char *obj, int a, int b, int c) {
    if (!*(int *)(obj + 0x183C)) {
        return 0;
    }
    int r;
    if (*(int *)(obj + 0x2294) & 0x20) {
        int t;
        func_0029A7B8(obj, a, obj + 0x186C, b, &t);
        r = func_002FEC68(*(int *)(obj + 0x1820), (int)(obj + 0x186C), t, c);
    } else {
        r = func_002FEC68(*(int *)(obj + 0x1820), a, b, c);
    }
    return r != -1;
}

extern "C" int func_0029D5C8(char *list, S29D_It *it) {
    S29D_Node *head = (S29D_Node *)(list + 0x22DC);
    it->cur = head;
    S29D_Node *n = S29D_Valid(head->unkC);
    it->cur = n;
    if (n) {
        return n->unk4;
    }
    return 0;
}

extern "C" int func_0029D600(int unused, S29D_It *it) {
    S29D_Node *n = S29D_Valid(it->cur->unkC);
    it->cur = n;
    if (n) {
        return n->unk4;
    }
    return 0;
}

extern "C" void func_0029D630(int unused, char *obj) {
    S29D_Node *n = (S29D_Node *)(obj + 0x30B0);
    n->unk10->unkC = n->unkC;
    n->unkC->unk10 = n->unk10;
    n->unkC = n;
    n->unk10 = n;
    if (obj) {
        delete (S29D_Big *)obj;
    }
}

extern "C" void func_0029D688(S29D_Self *p) {
    S29D_It it;
    it.cur = 0;
    it.vptr = D_0034ACA8;
    p->v6(1);
    for (int x = func_0029D5C8((char *)p, &it); x; x = func_0029D600((int)p, &it)) {
        func_0029DE80(p, x);
    }
    p->v7(1);
    it.vptr = D_0034ACA8;
}

extern "C" void func_0029D730(S29D730 *obj, int a) {
    S29D_It it;
    it.vptr = D_0034ACA8;
    it.cur = 0;
    if (!a) {
        ((int *)obj)[0]++;
        int x = func_0029D5C8((char *)obj, &it);
        if (x) {
            do {
                func_0029F638(x, 1);
                x = func_0029D600((int)obj, &it);
            } while (x);
        }
    }
    if (!func_0029D8C8((S29D8C8_0 *)obj)) {
        if (obj->v5()) {
            obj->v6(0);
        }
    }
    func_0029D688((S29D_Self *)obj);
    if (!func_0029D8C8((S29D8C8_0 *)obj)) {
        if (obj->v5()) {
            obj->v7(0);
        }
    }
    it.vptr = D_0034ACA8;
}

extern "C" int func_0029D838(u32 *p, char *q) {
    u32 d = *p - *(u32 *)(q + 0x3154);
    if (d >= func_0029F630(q) || func_0029F640(q)) {
        return 1;
    }
    return 0;
}

extern "C" void func_0029D898(S29D_Self *p) {
    p->v11();
}

INCLUDE_ASM("asm/nonmatchings/game/t_29D230", func_0029D8C0);

extern "C" s32 func_0029D8C8(S29D8C8_0 *arg0) {
    s32 x = arg0->unk2294 & 8;
    return x != 0;
}

INCLUDE_ASM("asm/nonmatchings/game/t_29D230", func_0029D8D8);

extern "C" s32 func_0029D8E0(S29D8C8_0 *arg0) {
    s32 x = arg0->unk2294 & 0x10;
    return x != 0;
}

INCLUDE_ASM("asm/nonmatchings/game/t_29D230", func_0029D8F0);

INCLUDE_ASM("asm/nonmatchings/game/t_29D230", func_0029D8F8);

extern "C" int func_0029D9A8(char *obj) {
    S29D_It it;
    int total = 0;
    it.vptr = D_0034ACA8;
    it.cur = 0;
    for (int x = func_0029D5C8(obj, &it); x; x = func_0029D600((int)obj, &it)) {
        if (func_0029F5B8(x)) {
            total += *(int *)(x + 0x30A8);
        }
    }
    it.vptr = D_0034ACA8;
    return total;
}

INCLUDE_ASM("asm/nonmatchings/game/t_29D230", func_0029DA40);

INCLUDE_ASM("asm/nonmatchings/game/t_29D230", func_0029DB70);

extern "C" void func_0029DB78(void) {
}

extern "C" s8 func_0029DB80(s32 arg0, s32 arg1) {
    return (*(s8 *)((char *)((arg0 + (arg1 & 0xFF))) + 0x2314));
}

extern "C" void func_0029DB90(s32 arg0, s32 arg1, s8 arg2) {
    (*(s8 *)((char *)((arg0 + (arg1 & 0xFF))) + 0x2314)) = arg2;
}

INCLUDE_ASM("asm/nonmatchings/game/t_29D230", func_0029DBA0);

INCLUDE_ASM("asm/nonmatchings/game/t_29D230", func_0029DE80);

extern "C" void func_0029E200(S29E200_0 *arg0, s32 arg1) {
    void *temp_6;

    temp_6 = arg0->unk10;
    arg0->unk14 = D_0035C4E8;
    (*(void **)((char *)(temp_6) + 0xC)) = (void *) arg0->unkC;
    (*(void **)((char *)(arg0->unkC) + 0x10)) = (void *) arg0->unk10;
    arg0->unkC = arg0;
    arg0->unk10 = arg0;
    if (arg1 & 1) {
        Heap_Free(D_00368A38[0], arg0);
    }
}

extern "C" void func_0029E260(S29E200_0 *arg0, s32 arg1) {
    void *temp_6;

    temp_6 = arg0->unk10;
    arg0->unk14 = D_0035C720;
    (*(void **)((char *)(temp_6) + 0xC)) = (void *) arg0->unkC;
    (*(void **)((char *)(arg0->unkC) + 0x10)) = (void *) arg0->unk10;
    arg0->unkC = arg0;
    arg0->unk10 = arg0;
    if (arg1 & 1) {
        Heap_Free(D_00368A38[0], arg0);
    }
}

extern "C" void func_0029E2C0(S29E200_0 *arg0, s32 arg1) {
    void *temp_6;

    temp_6 = arg0->unk10;
    arg0->unk14 = D_0035C720;
    (*(void **)((char *)(temp_6) + 0xC)) = (void *) arg0->unkC;
    (*(void **)((char *)(arg0->unkC) + 0x10)) = (void *) arg0->unk10;
    arg0->unkC = arg0;
    arg0->unk10 = arg0;
    if (arg1 & 1) {
        Heap_Free(D_00368A38[0], arg0);
    }
}

extern "C" void func_0029E320(void) {
    func_00113F38();
}

extern "C" s32 func_0029E340(void) {
    return 0;
}

extern "C" void func_0029E348(void) {
}

extern "C" void func_0029E350(void) {
}

extern "C" void func_0029E358(int arg0, s32 arg1) {
    memset(arg1 + 8, 0, 8);
}

extern "C" s32 func_0029E380(void) {
    return -1;
}

INCLUDE_ASM("asm/nonmatchings/game/t_29D230", func_0029E388);

extern "C" void func_0029E408(S29E200_0 *arg0, s32 arg1) {
    void *temp_6;

    temp_6 = arg0->unk10;
    arg0->unk14 = D_0035C768;
    (*(void **)((char *)(temp_6) + 0xC)) = (void *) arg0->unkC;
    (*(void **)((char *)(arg0->unkC) + 0x10)) = (void *) arg0->unk10;
    arg0->unkC = arg0;
    arg0->unk10 = arg0;
    if (arg1 & 1) {
        Heap_Free(D_00368A38[0], arg0);
    }
}

extern "C" void func_0029E468(S29E200_0 *arg0, s32 arg1) {
    void *temp_6;

    temp_6 = arg0->unk10;
    arg0->unk14 = D_0035C720;
    (*(void **)((char *)(temp_6) + 0xC)) = (void *) arg0->unkC;
    (*(void **)((char *)(arg0->unkC) + 0x10)) = (void *) arg0->unk10;
    arg0->unkC = arg0;
    arg0->unk10 = arg0;
    if (arg1 & 1) {
        Heap_Free(D_00368A38[0], arg0);
    }
}

extern "C" void func_0029E4C8(S29E4C8_0 *arg0, s32 arg1) {
    arg0->unk8 = D_0035C5C8;
    if (arg1 & 1) {
        Heap_Free(D_00368A38[0], arg0);
    }
}

extern "C" void func_0029E508(S29E4C8_0 *arg0, s32 arg1) {
    arg0->unk8 = D_0035C5B0;
    if (arg1 & 1) {
        Heap_Free(D_00368A38[0], arg0);
    }
}

INCLUDE_ASM("asm/nonmatchings/game/t_29D230", func_0029E548);

INCLUDE_ASM("asm/nonmatchings/game/t_29D230", func_0029E570);

INCLUDE_ASM("asm/nonmatchings/game/t_29D230", func_0029E578);

INCLUDE_ASM("asm/nonmatchings/game/t_29D230", func_0029E818);

struct S29E_Obj {
    char pad0[0x14];
    virtual ~S29E_Obj();
};
struct S29E_Base {
    char pad0[0x14];
    virtual ~S29E_Base();
};
struct S29E_El : S29E_Base {
    char pad18[0x14];
    S29E_Obj *unk2C;
};
struct S29E_Lk {
    int unk0;
    int unk4;
    int unk8;
    S29E_Lk *unkC;
};
struct S29E_It {
    int pad0;
    S29E_Lk *cur;
    char *vptr;
    S29E_It(S29E_Lk *l) { cur = l; vptr = D_0035C528; }
    ~S29E_It() { vptr = D_0035C528; }
};

static inline void S29E_Pick(S29E_El *&o, S29E_Lk *c) {
    if (!c) o = 0;
    else o = (S29E_El *)c->unk4;
}

static inline S29E_El *S29E_Get0(S29E_Lk *c) {
    S29E_El *r;
    S29E_Pick(r, c);
    return r;
}

extern "C" void func_00296EC0(S29E_Obj *, int);

extern "C" void func_0029EAC8(void *obj) {
    char *base = (char *)obj;
    S29E_Lk *m1, *mm, *n1, *nn;
    S29E_El *e, *nx;
    S29E_It *pa, *pb;
    S29E_It it(0);
    pa = &it;
    for (int i = 0; i < 0x100; i++) {
        it.cur = (S29E_Lk *)(base + i * 0x18 + 0x804);
        n1 = it.cur->unkC;
        nn = 0;
        if (~n1->unk4 != 0) nn = n1;
        pa->cur = nn;
        e = S29E_Get0(nn);
        if (e) {
            pb = &it;
            while (e) {
                m1 = it.cur->unkC;
                mm = 0;
                if (~m1->unk4 != 0) mm = m1;
                pb->cur = mm;
                S29E_Pick(nx, mm);
                if (e->unk2C) func_00296EC0(e->unk2C, 3);
                delete e;
                e = nx;
            }
        }
    }
}

extern "C" void func_0029EC08(void *p) {
    func_0029EAC8(p);
    func_0029F288(p);
    func_0029EC40(p);
}

struct S29F_RcA {
    char pad0[0xC];
    int unkC;
};
struct S29F_RcB {
    char pad0[0x10];
    int unk10;
};
struct S29F_ElA : S29E_Base {
    char pad18[4];
    S29F_RcA *unk1C;
};
struct S29F_ElB : S29E_Base {
    char pad18[0x14];
    S29F_RcB *unk2C;
};
struct S29F_ItA {
    int pad0;
    S29E_Lk *cur;
    char *vptr;
    S29F_ItA(S29E_Lk *l) { cur = l; vptr = D_0035C540; }
    ~S29F_ItA() { vptr = D_0035C540; }
};
struct S29F_ItC {
    int pad0;
    S29E_Lk *cur;
    char *vptr;
    S29F_ItC(S29E_Lk *l) { cur = l; vptr = (char *)D_0035C5B0; }
    ~S29F_ItC() { vptr = (char *)D_0035C5B0; }
};

static inline void S29F_Adv(S29E_Lk *&cur) {
    S29E_Lk *n = cur->unkC;
    cur = (~n->unk4 == 0) ? 0 : n;
}

struct S29G_ItD {
    int pad0;
    S29E_Lk *cur;
    char *vptr;
    S29G_ItD(S29E_Lk *l) { cur = l; vptr = D_0035C510; }
    ~S29G_ItD() { vptr = D_0035C510; }
};
struct S29G_ElD : S29E_Base {
    int *unk18;
};

extern "C" void func_00296A90(void *, int);

extern "C" void func_0029EC40(void *obj) {
    char *base = (char *)obj;
    S29E_Lk *n1, *nn, *m1, *mm, *k1, *kk, *p1, *pp, *q1, *qq, *r1, *rr, *n0, *nf, *l2, *l3, *l4, *l5;
    S29F_ItC *pa;
    S29F_ItC c((S29E_Lk *)(base + 0x30DC));
    S29F_ItA a(0);
    S29E_It b(0);
    S29G_ItD d(0);
    S29E_Base *e, *nx, *f, *fx, *g, *gx, *h, *hx;
    S29G_ElD *x, *xx, *y, *yx;
    int i;
    S29F_Adv(c.cur);
    e = (S29E_Base *)S29E_Get0(c.cur);
    l2 = (S29E_Lk *)(base + 0x30F4);
    l3 = (S29E_Lk *)(base + 0x310C);
    l4 = (S29E_Lk *)(base + 0x2004);
    l5 = (S29E_Lk *)(base + 0x201C);
    if (e) {
        pa = &c;
        while (e) {
            n1 = c.cur->unkC;
            nn = 0;
            if (~n1->unk4 != 0) nn = n1;
            pa->cur = nn;
            S29E_Pick((S29E_El *&)nx, nn);
            delete e;
            e = nx;
        }
    }
    a.cur = l2;
    S29F_Adv(a.cur);
    f = (S29E_Base *)S29E_Get0(a.cur);
    while (f) {
        m1 = a.cur->unkC;
        mm = 0;
        if (~m1->unk4 != 0) mm = m1;
        a.cur = mm;
        S29E_Pick((S29E_El *&)fx, mm);
        delete f;
        f = fx;
    }
    b.cur = l3;
    S29F_Adv(b.cur);
    g = (S29E_Base *)S29E_Get0(b.cur);
    while (g) {
        k1 = b.cur->unkC;
        kk = 0;
        if (~k1->unk4 != 0) kk = k1;
        b.cur = kk;
        S29E_Pick((S29E_El *&)gx, kk);
        delete g;
        g = gx;
    }
    i = 0;
    do {
        b.cur = (S29E_Lk *)(base + i * 0x18 + 0x804);
        n0 = b.cur->unkC;
        nf = 0;
        if (~n0->unk4 != 0) nf = n0;
        b.cur = nf;
        h = (S29E_Base *)S29E_Get0(nf);
        while (h) {
            p1 = b.cur->unkC;
            pp = 0;
            if (~p1->unk4 != 0) pp = p1;
            b.cur = pp;
            S29E_Pick((S29E_El *&)hx, pp);
            delete h;
            h = hx;
        }
        i++;
    } while (i < 0x100);
    d.cur = l4;
    S29F_Adv(d.cur);
    x = (S29G_ElD *)S29E_Get0(d.cur);
    while (x) {
        q1 = d.cur->unkC;
        qq = 0;
        if (~q1->unk4 != 0) qq = q1;
        d.cur = qq;
        S29E_Pick((S29E_El *&)xx, qq);
        if (x->unk18) func_00296A90(x->unk18, 3);
        delete x;
        x = xx;
    }
    d.cur = l5;
    S29F_Adv(d.cur);
    y = (S29G_ElD *)S29E_Get0(d.cur);
    while (y) {
        r1 = d.cur->unkC;
        rr = 0;
        if (~r1->unk4 != 0) rr = r1;
        d.cur = rr;
        S29E_Pick((S29E_El *&)yx, rr);
        if (y->unk18) func_00296A90(y->unk18, 3);
        delete y;
        y = yx;
    }
}

extern "C" void func_00296D88(void *, int);

extern "C" void func_0029F090(char *base) {
    S29E_Lk *n1, *n2, *nn, *l2;
    S29F_ItC c(0);
    S29F_ItA a((S29E_Lk *)(base + 0x30F4));
    S29E_It b(0);
    S29F_ElA *e, *nx;
    S29F_ElB *f, *fx;
    S29F_Adv(a.cur);
    e = (S29F_ElA *)S29E_Get0(a.cur);
    if (e) {
        while (e) {
            n1 = a.cur->unkC;
            nn = 0;
            if (~n1->unk4 != 0) nn = n1;
            a.cur = nn;
            nx = (S29F_ElA *)S29E_Get0(nn);
            S29F_RcA *o = e->unk1C;
            int *rc = (int *)((char *)o + 8);
            if (--rc[1] == 0 && o) func_00296D88(o, 3);
            delete e;
            e = nx;
        }
    }
    l2 = (S29E_Lk *)(base + 0x310C);
    b.cur = l2;
    S29F_Adv(b.cur);
    f = (S29F_ElB *)S29E_Get0(b.cur);
    while (f) {
        n2 = b.cur->unkC;
        nn = 0;
        if (~n2->unk4 != 0) nn = n2;
        b.cur = nn;
        fx = (S29F_ElB *)S29E_Get0(nn);
        S29F_RcB *o = f->unk2C;
        int *rc = (int *)((char *)o + 0xC);
        if (--rc[1] == 0 && o) func_00296EC0((S29E_Obj *)o, 3);
        delete f;
        f = fx;
    }
}
