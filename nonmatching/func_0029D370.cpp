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
int func_002FF0D8(int, int);
int func_002FEE38(int, void *, int, int, void *, int);
void func_0030A2F4(void *, void *, int);
int Heap_Alloc(s32, int, int, int);
int memset_(void *, int, int) __asm__("memset");
}
extern "C" int func_0029D370(S29D370_Self *o, int x, u32 key, char *src, int len, int a5, u32 a6) {
    char buf[0x10];
    S29D370_P *pk = (S29D370_P *)buf;
    u32 k = key & 0xFFFF;
    o->v8(buf, 0x10);
    memset_(buf, 0, 0x10);
    pk->unk0 = 2;
    pk->unk2 = func_002FF0D8(k, 2);
    int r;
    pk->unk4 = x;
    if (o->unk2294 & 0x20) {
        int t;
        func_0029A7B8((char *)o, (int)src, o->unk186C, len, &t);
        r = func_002FEE38(o->unk1820, o->unk186C, t, a5, buf, 0x10);
    } else {
        int heaped = 0;
        char *ptr = src;
        int c;
        if (o->unk2294 & 0x80) {
            c = a6 != 0;
        } else {
            c = 0;
        }
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
        if (o->v3(r) == 0) {
            return 1;
        }
        return 0;
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

INCLUDE_ASM("asm/nonmatchings/game/t_29D230", func_0029EAC8);

extern "C" void func_0029EC08(void *p) {
    func_0029EAC8(p);
    func_0029F288(p);
    func_0029EC40(p);
}

INCLUDE_ASM("asm/nonmatchings/game/t_29D230", func_0029EC40);

INCLUDE_ASM("asm/nonmatchings/game/t_29D230", func_0029F090);
