// cflags: -funroll-loops
#include "common.h"

struct S002998C0 {
    char pad[0x10];
    int unk10;
    int unk14;
    int unk18;
    char pad1[0x208];
    int unk224;
};

struct S298_D8 {
    char pad0[0x8];
    void *vptr;
};

struct S298_DL {
    char pad0[0xC];
    S298_DL *unkC;
    S298_DL *unk10;
    void *vptr;
};

struct S298_Self {
    char pad0[0x1804];
    int unk1804;
    char pad1808[0xC10];
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual int v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
};

struct S298_Owner {
    char pad0[0x20];
    S298_Self *unk20;
};

struct S298_It {
    int unk0;
    void *cur;
    char *vptr;
};

struct S298_Msg {
    u8 b0;
    char pad1;
    u16 unk2;
    void *unk4;
    char pad8[0x28];
    int unk30;
    char pad34[0xC];
};

struct S298_Peer {
    char pad0[0x2034];
    char unk2034[0x30];
    int unk2064;
    int unk2068;
    char pad206C[0x10B8];
    int unk3124;
    int unk3128;
    u16 unk312C;
    char pad312E[0x16];
    int unk3144;
};

struct S298_Task {
    int *unk0;
    char pad4[0xC];
    int *unk10;
    S298_Peer *unk14;
    int unk18;
};

extern "C" {
int func_0029B468(int, int);
extern char *D_00370EE0;
extern u32 D_003718C0;
extern char D_0034ACA8[];
void func_00114958(char *, int);
void func_00296AF0(S298_Msg *);
int func_00296AF0_i(S298_Msg *) __asm__("func_00296AF0");
int func_0029D8E0(int *);
void func_0029D2A0(int *, int, int, int, int, u16, int);
void func_0029C4C0(int *, int, S298_Msg *);
void func_002961C8(char *, int);
int func_0029D5C8(int *, S298_It *);
int func_0029D600(int *, S298_It *);
int func_0029F5A8(S298_Peer *);
void func_0029AAA0(char *, u32);
extern char D_0035C510[];
extern char D_0035C528[];
extern char D_0035C540[];
extern char D_0035C4B8[];
extern int D_00368A38;
extern char D_0035C4E8[];
void Heap_Free(int, void *);
void func_0029A218(S298_Self *);
void func_0029A0E8(S298_Self *);
void func_0029DBA0(void);
void func_0029D730(int, int);
void func_0029D630(int, int);
}

extern "C" void func_00298A30(S298_D8 *p, int flags) {
    p->vptr = D_0035C4B8;
    if (flags & 1) {
        Heap_Free(D_00368A38, p);
    }
}

extern "C" void func_00298A70(S298_DL *p, int flags) {
    p->vptr = D_0035C4E8;
    p->unk10->unkC = p->unkC;
    p->unkC->unk10 = p->unk10;
    p->unkC = p;
    p->unk10 = p;
    if (flags & 1) {
        Heap_Free(D_00368A38, p);
    }
}

struct S298A_Base {
    char pad0[0x14];
    virtual ~S298A_Base();
};
struct S298A_Lk {
    int unk0;
    int unk4;
    int unk8;
    S298A_Lk *unkC;
};
struct S298A_ElA : S298A_Base {
    int unk18;
    int *unk1C;
    u16 unk20;
};
struct S298A_ElB : S298A_Base {
    int pad18;
    u16 unk1C;
    char pad1E[2];
    int unk20;
    char pad24[8];
    int *unk2C;
};
struct S298A_ItA {
    int pad0;
    S298A_Lk *cur;
    char *vptr;
    S298A_ItA(S298A_Lk *l) { cur = l; vptr = D_0035C540; }
    ~S298A_ItA() { vptr = D_0035C540; }
};
struct S298A_ItB {
    int pad0;
    S298A_Lk *cur;
    char *vptr;
    S298A_ItB(S298A_Lk *l) { cur = l; vptr = D_0035C528; }
    ~S298A_ItB() { vptr = D_0035C528; }
};
struct S298A_One {
    int v;
    S298A_One(int x) { v = x; }
};

static inline void S298A_Pick(void *&o, S298A_Lk *c) {
    if (!c) o = 0;
    else o = (void *)c->unk4;
}

static inline void *S298A_Get0(S298A_Lk *c) {
    void *r;
    S298A_Pick(r, c);
    return r;
}

extern "C" {
void func_00296D88(void *, int);
void func_00296EC0(void *, int);
int func_0029F5B8(S298_Peer *);
}

struct S298A_Pl {
    int pad0;
    S298A_Lk *cur;
    char *vptr;
};

INCLUDE_ASM("asm/nonmatchings/game/t_298A30", func_00298AD0);

INCLUDE_ASM("asm/nonmatchings/game/t_298A30", func_00298DA8);

INCLUDE_ASM("asm/nonmatchings/game/t_298A30", func_00299260);

INCLUDE_ASM("asm/nonmatchings/game/t_298A30", func_00299418);

extern "C" int func_00299640(S298_Task *t) {
    S298_Msg m;
    func_00296AF0(&m);
    m.unk30 = 8;
    if (t->unk14->unk3144 & 8) {
        return 4;
    }
    m.b0 = 0xC;
    func_0029C4C0(t->unk10, t->unk14->unk3124, &m);
    S298_Peer *q = t->unk14;
    m.unk30 = 8;
    q->unk3144 |= 8;
    return 1;
}

INCLUDE_ASM("asm/nonmatchings/game/t_298A30", func_002996C0);

extern "C" int func_002997D0(S298_Task *t) {
    S298_Msg m;
    func_00296AF0(&m);
    m.unk30 = *t->unk0;
    m.unk4 = &m.unk30;
    m.unk2 = 4;
    m.b0 = 2;
    func_0029C4C0(t->unk10, t->unk14->unk3124, &m);
    return 1;
}

extern "C" int func_00299838(S298_Task *t) {
    S298_Peer *q = t->unk14;
    int *r = t->unk0;
    if (func_0029F5A8(q)) {
        return 1;
    }
    int now = *t->unk10;
    if (*r == q->unk2064) {
        q->unk2068 = *r;
        u32 d = now - *r;
        if (d > D_003718C0) {
            d = D_003718C0;
        }
        func_0029AAA0(q->unk2034, d);
    }
    return 1;
}

extern "C" int func_002998C0(S002998C0* p) {
    int f = p->unk18;
    p->unk224 = 1;
    if (f & 1) {
        p->unk18 = f ^ 1;
    }
    return 1;
}

extern "C" int func_002998E8(S002998C0* p) {
    func_0029D630(p->unk10, p->unk14);
    return 2;
}

struct S298_Small {
    u8 b0;
    char pad1[7];
    int unk8;
    int unkC;
    char pad10[0x20];
};

extern "C" int func_00299910(S298_Task *t) {
    S298_Small m;
    func_00296AF0_i((S298_Msg *)(void *)&m);
    if (t->unk18 & 1) {
        if (!func_0029D8E0(t->unk10)) goto fail;
        S298_Peer *q = t->unk14;
        func_0029D2A0(t->unk10, 4, 0, 0, q->unk3128, q->unk312C, 0);
        return 1;
    }
    if (!func_0029F5A8(t->unk14)) {
fail:
        return 4;
    }
    m.b0 = 4;
    m.unk8 = 0xFF;
    m.unkC = 1;
    func_0029C4C0(t->unk10, t->unk14->unk3124, (S298_Msg *)(void *)&m);
    return 1;
}

extern "C" void func_002999C8(S298_D8 *p, int flags) {
    p->vptr = D_0035C540;
    if (flags & 1) {
        Heap_Free(D_00368A38, p);
    }
}

extern "C" void func_00299A08(S298_D8 *p, int flags) {
    p->vptr = D_0035C528;
    if (flags & 1) {
        Heap_Free(D_00368A38, p);
    }
}

extern "C" void func_00299A48(S298_D8 *p, int flags) {
    p->vptr = D_0035C510;
    if (flags & 1) {
        Heap_Free(D_00368A38, p);
    }
}

INCLUDE_ASM("asm/nonmatchings/game/t_298A30", func_00299A88);

extern "C" void func_00299CB8(char *p) {
    char *m = D_00370EE0 + 8;
    func_00114958(m, *(int *)(p + 0x185C));
    func_00114958(m, *(int *)(p + 0x1858));
    func_00114958(m, *(int *)(p + 0x1854));
    func_00114958(m, *(int *)(p + 0x1860));
}

INCLUDE_ASM("asm/nonmatchings/game/t_298A30", func_00299D20);

extern "C" int func_00299E18(int a) {
    int i;
    for (i = 1; i < 0x100; i++) {
        if (func_0029B468(a, i) == 0) {
            return i;
        }
    }
    return 0;
}

struct S299E_P {
    u8 unk0;
    char pad1;
    u16 unk2;
    int unk4;
};
struct S299E_El : S298A_Base {
    char pad18;
    u8 unk19;
    char pad1A[0xA];
    int unk24;
    char pad28[4];
    S299E_P *unk2C;
};
struct S299E_Msg {
    int a;
    u8 b;
    char pad15[3];
    long c;
    int f20;
    int f24;
    int f28;
    char pad2C[0x230 - 0x1C];
};
extern "C" {
void func_00296F18(S299E_Msg *);
int func_00298858(char *, S299E_Msg *);
}

INCLUDE_ASM("asm/nonmatchings/game/t_298A30", func_00299ED0);

INCLUDE_ASM("asm/nonmatchings/game/t_298A30", func_0029A0E8);

INCLUDE_ASM("asm/nonmatchings/game/t_298A30", func_0029A218);

INCLUDE_ASM("asm/nonmatchings/game/t_298A30", func_0029A590);

extern "C" void func_0029A5F0(S298_Owner *o) {
    S298_Self *p = o->unk20;
    p->v15();
    func_0029A0E8(p);
    p->v12();
}

extern "C" void func_0029A640(void) {
    func_0029DBA0();
}

extern "C" void func_0029A660(S298_Self *p) {
    p->v4();
}

extern "C" void func_0029A688(int a) {
    func_0029D730(a, 1);
}

extern "C" void func_0029A6A8(S298_Owner *o) {
    S298_It it;
    it.cur = 0;
    it.vptr = D_0034ACA8;
    int *p = (int *)o->unk20;
    for (int x = func_0029D5C8(p, &it); x; x = func_0029D600(p, &it)) {
        func_002961C8((char *)x + 0x206C, *p);
        func_002961C8((char *)x + 0x288C, *p);
    }
    it.vptr = D_0034ACA8;
}

extern "C" void func_0029A740(S298_Owner *o) {
    S298_Self *p = o->unk20;
    p->unk1804++;
    p->v13();
}

extern "C" void func_0029A778(S298_Owner *o) {
    S298_Self *p = o->unk20;
    func_0029A218(p);
    p->v14();
}

struct S29A_P2 {
    s8 a, b;
};
extern "C" u32 func_00114C50(u8 *, int);

extern "C" void func_0029A7B8(int self, u8 *src, s8 *dst, int n, int *out) {
    int m = n;
    u32 c = func_00114C50(src, m);
    s16 k = (c >> 16) + c;
    u8 key = *(u8 *)&k;
    *(S29A_P2 *)dst = *(S29A_P2 *)&k;
    s8 *d = dst + 2;
    if (m > 0) {
        int i = m;
        do {
            *d++ = *src++ ^ key;
        } while (--i);
    }
    *out = n + 2;
}

extern "C" void func_0030A2F4(u8 *, u8 *, int);

extern "C" int func_0029A8E8(char *self, u8 *src, u8 *dst, int n) {
    if (n < 3) return 0;
    if (!(*(int *)(self + 0x2294) & 0x20)) {
        func_0030A2F4(dst, src, n);
        return 1;
    }
    u8 buf[0x520];
    S29A_P2 h;
    h = *(S29A_P2 *)src;
    int m = n - 2;
    int len = m;
    func_0030A2F4(buf, src + 2, m);
    u8 key = *(u8 *)&h;
    u8 *p = buf;
    if (len > 0) {
        int i = len;
        do {
            *p++ ^= key;
        } while (--i);
    }
    u32 c = func_00114C50(buf, len);
    if ((u16)((c >> 16) + c) != *(u16 *)&h) return 0;
    func_0030A2F4(dst, buf, len);
    return 1;
}
