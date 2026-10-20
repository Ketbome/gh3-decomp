#include "common.h"

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

INCLUDE_ASM("asm/nonmatchings/game/t_29F288", func_0029F288);

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

INCLUDE_ASM("asm/nonmatchings/game/t_29F288", func_0029F648);

INCLUDE_ASM("asm/nonmatchings/game/t_29F288", func_0029F790);

INCLUDE_ASM("asm/nonmatchings/game/t_29F288", func_0029F840);

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
struct S29FA_Lk {
    int unk0;
    int unk4;
    int unk8;
    S29FA_Lk *unkC;
};
extern "C" char D_0035C528[];
extern "C" char D_0035C540[];
struct S29FA_ItA {
    int pad0;
    S29FA_Lk *cur;
    char *vptr;
    S29FA_ItA(S29FA_Lk *l) { cur = l; vptr = D_0035C540; }
    ~S29FA_ItA() { vptr = D_0035C540; }
};
struct S29FA_ItB {
    int pad0;
    S29FA_Lk *cur;
    char *vptr;
    S29FA_ItB(S29FA_Lk *l) { cur = l; vptr = D_0035C528; }
    ~S29FA_ItB() { vptr = D_0035C528; }
};

template <class T> static inline void S29FA_Adv(T &it) {
    S29FA_Lk *n = it.cur->unkC;
    it.cur = (~n->unk4 == 0) ? 0 : n;
}

static inline void S29FA_Pick(S29FA_El *&o, S29FA_Lk *c) {
    if (!c) o = 0;
    else o = (S29FA_El *)c->unk4;
}

template <class T> static inline S29FA_El *S29FA_Get0(T &it) {
    S29FA_El *r;
    S29FA_Pick(r, it.cur);
    return r;
}


extern "C" void func_0029FA08(char *base, int key) {
    S29FA_ItA a((S29FA_Lk *)(base + 0x30F4));
    S29FA_ItB b(0);
    S29FA_Adv(a);
    S29FA_El *e = S29FA_Get0(a);
    for (; e; e = a.cur ? (S29FA_El *)a.cur->unk4 : 0) {
        if (e->unk20 == key) e->unk18 = 0;
        S29FA_Adv(a);
    }
    b.cur = (S29FA_Lk *)(base + 0x310C);
    S29FA_Adv(b);
    S29FA_El *f = S29FA_Get0(b);
    for (; f; f = b.cur ? (S29FA_El *)b.cur->unk4 : 0) {
        if (f->unk1C == key) f->unk20 = 0;
        S29FA_Adv(b);
    }
}