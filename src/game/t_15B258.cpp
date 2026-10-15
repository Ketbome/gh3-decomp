#include "common.h"

struct VEntry {
    s16 delta;
    s16 unk2;
    void* fn;
};

struct S0015BA28 {
    int unk0;
    int unk4;
    char pad8[0xC];
    VEntry* unk14;
};

struct S0015BA58 {
    char pad0[0x8];
    int unk8;
    int unkC;
    char pad10[0x4];
    VEntry* unk14;
};

struct S0015B360 {
    char pad[0x16];
    u8 unk16;
};

struct S_0015B370 { int unk0; int unk4; int unk8; };

struct S15B_A { char pad0[0x8]; void* unk8; };
struct S15B_B { int unk0; int unk4; int unk8; int unkC; int unk10; void* unk14; };
struct S15B_C { char pad0[0x4]; s16 unk4; };
struct S15B_N { char pad0[0x10]; S15B_N* unk10; };
struct S15B_R { char pad0[0x14]; char unk14[0x4]; void* unk18; };

struct HI_15B { u32 key; void* value; HI_15B* next; };
struct HT_15B { int bits; HI_15B* items; int count; char padC[9]; u8 unk15; u8 unk16; };

struct S15B_O { char pad0[0x2C]; u32 unk2C; };
struct N15B { int unk0; N15B* unk4; S15B_O* unk8; char padC[0x18]; int unk24; };
struct L15B { int unk0; N15B unk4; };
struct It15B {
    int unk0;
    N15B* cur;
    It15B(N15B* n) : cur(n) {}
    bool operator!=(const It15B& o) const { return cur != o.cur; }
    void operator++() { cur = cur->unk4; }
    S15B_O*& operator*() { return cur->unk8; }
};

extern "C" {
void func_00189938(void);
void func_0015B968(int, int);
void func_0015BB80(int, int);
void func_002763E0(int, int);
int func_001574C0(int);
void func_0015B268(void*, int);
extern u8 D_0033CE10[];
extern u8 D_0033D0D0[];
extern int D_00368A38;
void Heap_Free(int, void*);
extern char D_00369D90[];
int func_0014F130(void);
void func_0030B550(char*, char*, ...);
int CrcFromPathLowercase(void*);
int func_00188520(int);
int* func_00188478(int, int, int, int, int, int, int);
void func_00188568(S15B_C*);
extern u8 D_00369DA8[];
extern int D_00372B8C;
extern int D_00372B88;
extern S15B_N* D_00369DB4;
int func_0015C0F8(int, S15B_O***);
void func_0011C408(int, void*);
void func_0015B380(HT_15B*);
void func_0030A554(char*, const char*);
extern char D_0033D0B0[];
extern char D_00369D98[];
extern char D_00369DA0[];
int func_0015BC80_r(void) __asm__("func_0015BC80");
int func_0027CC30(int, u32, int, int*);
void func_0027F1E0(int, int, int);
bool func_0027D870(int, int, int*, int);
extern L15B D_0037DAF0;
}

INCLUDE_ASM("asm/nonmatchings/game/t_15B258", func_0015B258);

INCLUDE_ASM("asm/nonmatchings/game/t_15B258", func_0015B268);

extern "C" void func_0015B2F0(void* self, int x) {
    func_0015B268(self, func_001574C0(x));
}

extern "C" int func_0015B328(void) {
    return 0;
}

extern "C" int func_0015B330(void) {
    return 0;
}

extern "C" int func_0015B338(void) {
    return 0;
}

extern "C" void func_0015B340(void) {
}

extern "C" int func_0015B348(void) {
    return 0;
}

extern "C" int func_0015B350(void) {
    return 0;
}

INCLUDE_ASM("asm/nonmatchings/game/t_15B258", func_0015B358);

extern "C" bool func_0015B360(S0015B360* self) {
    return self->unk16 != 0;
}

extern "C" void func_0015B370(S_0015B370* self) {
    self->unk0 = 0;
    self->unk4 = 0;
    self->unk8 = 0;
}

extern "C" void func_0015B380(HT_15B* t) {
    if (t->items) {
        u32 n = 1 << t->bits;
        HI_15B* e = t->items;
        for (u32 i = 0; i < n; i++) {
            HI_15B* c = e->next;
            while (c) {
                HI_15B* nx = c->next;
                func_0011C408(0, c);
                c = nx;
            }
            func_0015B370((S_0015B370*)e);
            e++;
        }
        t->count = 0;
    }
}

extern "C" void func_0015B438(HT_15B* self, int flags) {
    if (!self->unk16 && self->items) {
        func_0015B380(self);
        if (self->items) {
            Heap_Free(D_00368A38, self->items);
        }
        self->items = 0;
    }
    if (flags & 1) {
        Heap_Free(D_00368A38, self);
    }
}

extern "C" void func_0015B4B0(HT_15B* t, int* key) {
    if (!t->items) {
        return;
    }
    HI_15B* e = &t->items[*key & ((1 << t->bits) - 1)];
    HI_15B* prev = 0;
    while (e) {
        HI_15B* next = e->next;
        if (e->key == (u32)*key && e->value) {
            if (prev) {
                prev->next = next;
                func_0011C408(0, e);
            } else {
                e->key = 0;
                e->value = 0;
            }
            t->count--;
            return;
        }
        prev = e;
        e = next;
    }
}

extern "C" S_0015B370* func_0015B568(S_0015B370* self) {
    func_0015B370(self);
    return self;
}

INCLUDE_ASM("asm/nonmatchings/game/t_15B258", func_0015B590);

extern "C" void func_0015B770(S15B_A* self, int flags) {
    self->unk8 = D_0033CE10;
    if (flags & 1) {
        Heap_Free(D_00368A38, self);
    }
}

extern "C" void func_0015B7B0(char* buf, int a) {
    func_0030B550(buf, D_00369D90, a, func_0014F130());
}

extern "C" void func_0015B808(char* buf, char* p, int flag) {
    if (flag) {
        if (p[0] == '.' && p[1] == '.' && p[2] == '/') {
            func_0030B550(buf, D_00369D98, p + 3);
        } else {
            func_0030B550(buf, D_0033D0B0, p);
        }
    } else {
        func_0030B550(buf, D_00369D98, p);
    }
    func_0030A554(buf, D_00369DA0);
    func_0030A554(buf, (char*)func_0014F130());
}

extern "C" int func_0015B8C0(void* p) {
    return func_00188520(CrcFromPathLowercase(p));
}

extern "C" void func_0015B8E8(int a, int b, int c, int d, int e, int f, int g) {
    *func_00188478(a, b, c, d, f, g, 0) = a;
}

extern "C" int func_0015B920(S15B_C* self) {
    if (--self->unk4 == 0) {
        func_00188568(self);
        return 1;
    }
    return 0;
}

INCLUDE_ASM("asm/nonmatchings/game/t_15B258", func_0015B960);

GP_DATA(D_00372B8C);
GP_DATA(D_00372B88);
extern "C" void func_0015B968(int a, int b) {
    if (b == 0xFFFF && a) {
        int r = func_0015B8C0(D_00369DA8);
        D_00372B8C = D_00372B88 = r;
    }
}

extern "C" void func_0015B9A0(void) {
    func_0015B968(1, 65535);
}

extern "C" S15B_B* func_0015B9C0(S15B_B* self, int a, int b, int c, int d) {
    self->unk14 = D_0033D0D0;
    self->unk0 = a;
    self->unk4 = b;
    self->unk8 = c;
    self->unkC = d;
    self->unk10 = 0;
    return self;
}

extern "C" void func_0015B9E8(S15B_B* self, int flags) {
    self->unk14 = D_0033D0D0;
    if (flags & 1) {
        Heap_Free(D_00368A38, self);
    }
}

extern "C" void func_0015BA28(S0015BA28* self, int a1, int a2) {
    self->unk4 = a2;
    self->unk0 = a1;
    VEntry* e = &self->unk14[2];
    ((void (*)(void*))e->fn)((char*)self + e->delta);
}

extern "C" void func_0015BA58(S0015BA58* self, int a1, int a2) {
    self->unkC = a2;
    self->unk8 = a1;
    VEntry* e = &self->unk14[2];
    ((void (*)(void*))e->fn)((char*)self + e->delta);
}

extern "C" void func_0015BA88(void) {
}

extern "C" void func_0015BA90(void) {
    func_00189938();
}

GP_DATA(D_00369DB4);
extern "C" void* func_0015BAB0(int a, int b, int c, int d) {
    S15B_N* p = D_00369DB4;
    if (p) {
        D_00369DB4 = p->unk10;
    }
    func_0015BA28((S0015BA28*)p, a, b);
    func_0015BA58((S0015BA58*)p, c, d);
    return p;
}

GP_DATA(D_00369DB4);
extern "C" void func_0015BB20(S15B_N* n) {
    S15B_N* p = D_00369DB4;
    while (p->unk10) {
        p = p->unk10;
    }
    p->unk10 = n;
    n->unk10 = 0;
}

INCLUDE_ASM("asm/nonmatchings/game/t_15B258", func_0015BB60);

INCLUDE_ASM("asm/nonmatchings/game/t_15B258", func_0015BB80);

extern "C" void func_0015BC60(void) {
    func_0015BB80(1, 65535);
}

extern "C" void func_0015BC80(void) {
    func_002763E0(0xAE1FCC20, 1);
}

extern "C" int func_0015BCA8(u32 key) {
    int v[2];
    int s = func_0015BC80_r();
    if (func_0027CC30(s, 0x49A5050A, 10, &v[0])) {
        s = v[0];
    } else {
        func_0027F1E0(s, 0, 1);
        s = 0;
    }
    if (!func_0027CC30(s, key, 10, &v[1])) {
        func_0027F1E0(s, 0, 1);
        return 0;
    }
    return v[1];
}

struct V15B { int unk0; float x, y, z, w; };

static inline V15B Mk15B(float x, float y, float z, float w) {
    V15B v;
    v.x = x;
    v.y = y;
    v.z = z;
    v.w = w;
    return v;
}

extern "C" int func_0027DD88(int, int);
extern "C" float func_0027EFA0(int, int);

extern "C" int func_0015BD40(int s, V15B* out, int type, int key) {
    if (type == 1 || func_0027DD88(s, key)) {
        int t;
        if (func_0027CC30(s, key, 12, &t)) {
            s = t;
        } else {
            func_0027F1E0(s, 0, 1);
            s = 0;
        }
        float x = func_0027EFA0(s, 0);
        float y = func_0027EFA0(s, 1);
        float z = func_0027EFA0(s, 2);
        float w = func_0027EFA0(s, 3);
        V15B v;
        v.x = x;
        v.y = y;
        v.z = z;
        v.w = w;
        *out = v;
        return 1;
    }
    return 0;
}

static inline int Get_15B(int s, u32 key, int type) {
    int t;
    if (!func_0027CC30(s, key, type, &t)) {
        func_0027F1E0(s, 0, 1);
        return 0;
    }
    return t;
}

extern "C" int func_0015BE58(int a, int b) {
    int r = 0;
    bool missing = !func_0027D870(a, b, &r, 0);
    if (missing) {
        r = Get_15B(a, b, 1);
    }
    return r;
}

INCLUDE_ASM("asm/nonmatchings/game/t_15B258", func_0015BED8);

extern "C" int func_0015C0F8(int key, S15B_O*** out) {
    It15B it(D_0037DAF0.unk4.unk4);
    It15B end(&D_0037DAF0.unk4);
    for (; it != end; ++it) {
        S15B_O*& o = *it;
        if (it.cur->unk24 == key && !(o->unk2C & 0x20)) {
            *out = &o;
            return 1;
        }
    }
    return 0;
}

extern "C" int func_0015C178(int idx, S15B_O*** out) {
    It15B it(D_0037DAF0.unk4.unk4);
    It15B end(&D_0037DAF0.unk4);
    int n = 0;
    for (; it != end; ++it) {
        S15B_O*& o = *it;
        if (o->unk2C & 0x10) {
            if (n == idx) {
                *out = &o;
                return 1;
            }
            n++;
        }
    }
    return 0;
}

INCLUDE_ASM("asm/nonmatchings/game/t_15B258", func_0015C1F8);

INCLUDE_ASM("asm/nonmatchings/game/t_15B258", func_0015C200);

INCLUDE_ASM("asm/nonmatchings/game/t_15B258", func_0015C3B0);

extern "C" void func_0015C948(void) {
}

INCLUDE_ASM("asm/nonmatchings/game/t_15B258", func_0015C950);

INCLUDE_ASM("asm/nonmatchings/game/t_15B258", func_0015CD88);

INCLUDE_ASM("asm/nonmatchings/game/t_15B258", func_0015CFC8);

INCLUDE_ASM("asm/nonmatchings/game/t_15B258", func_0015D0D0);

extern "C" int func_0015D160(int a) {
    S15B_R* r = 0;
    func_0015C0F8(a, (S15B_O***)&r);
    if (r && r->unk18 != r->unk14) {
        return 1;
    }
    return 0;
}

INCLUDE_ASM("asm/nonmatchings/game/t_15B258", func_0015D1A0);
