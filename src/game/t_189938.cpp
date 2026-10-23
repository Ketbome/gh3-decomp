#include "common.h"

struct S_189 { void* unk0; char pad4[0x18]; void* unk1C; char pad20[0x24]; void* unk44; char pad48[0x10]; void* unk58; char pad5C[4]; int unk60; char pad64[0x3C]; void* unkA0; int unkA4; char padA8[4]; void* unkAC; char padB0[0x10]; void* unkC0; };

struct E_0018AD18 { int unk0; int unk4; };
struct S2_189 { char pad0[0x14]; char unk14[0x9C]; int unkB0; char padB4[0x20]; E_0018AD18* unkD4; int unkD8; };
struct S3_189 { char pad0[0x70]; int unk70; char pad74[0x1C]; void* unk90; char pad94[0xC]; int unkA0; int unkA4; int unkA8; void* unkAC; char padB0[0x10]; int unkC0; int unkC4; };
struct VEntry_189 { s16 delta; s16 unk2; void* fn; };
struct O_0018A800 { char pad0[0x18]; VEntry_189* unk18; };
struct N_189 { int unk0; N_189* unk4; void** unk8; };
struct It_189 {
    int unk0;
    N_189* cur;
    It_189(N_189* n) : cur(n) {}
    bool operator!=(const It_189& o) const { return cur != o.cur; }
    void operator++() { cur = cur->unk4; }
};

struct E_0018AF58 { u32 unk0; u16* unk4; };
struct S4_189 { char pad0[0xC8]; u64 unkC8; char padD0[4]; E_0018AF58* unkD4; int unkD8; };
struct VE0_189 { s16 delta; s16 unk2; void* fn; };
struct D_0018A898 { VE0_189* unk0; };
struct S5_189 { char pad0[0x58]; void* unk58; char pad5C[4]; D_0018A898* unk60; char pad64[0x3C]; void* unkA0; char padA4[4]; void* unkA8; };

extern "C" {
void func_001ACE58(void*, int);
void func_001AD048(void*, int);
void func_0015FC88(S5_189*, int);
int func_00161958(void*);
void* func_001618A0(void*, int);
int func_0015F1C8(void*, int);
void func_0014FA20(S3_189*, int);
extern char D_00344A68[];
int func_00187F48(int);
int func_001BD780(int, int);
void func_0016F0D0(void*, int);
void func_00122F88(S_189*, int);
void func_0030A1C8(int, int);
void func_001AD7B8(void*);
void func_0011D220(int);
void func_0015F398(void*, int);
extern int D_00368A38[] __attribute__((section(".sdata")));
void* Heap_Alloc(int, int, int, int);
void Heap_Free(int, void*);
void func_001ACD98(void*, int);
void func_001B1C38(void*);
void func_001B05B8(void*);
void func_001B18C8(void*);
void* func_001ACF70(void*);
void func_0018A090(S_189*, void*);
void func_0018A1F0(S_189*, void*);
void* func_001836F0(void*);
S_189* func_0015FBD8(S_189*);
extern char D_00344BE0[];
S_189* func_00122E60(S_189*, int, int);
extern char D_003446D0[];
void func_0016F0C0(void*);
extern char D_00344C98[];
extern char D_00344C80[];
extern char D_00344DD0[];
extern char D_00344F10[];
void* func_00113408(void*);
void func_0011D348(void*);
void func_001BD458(void*);
void func_0011A470(void*);
void func_00162420(void*, int);
void func_001B1728(void*, int);
void func_001AD9D0(void*);
void func_001ADBA8(void*, int);
void func_0015EFE8(void*, int);
}

struct S_0018AC50 { void* unk0; void* unk4; void* unk8; };
struct S_0018AEA0 { char pad0[0xBC]; void* unkBC; void* unkC0; void* unkC4; int unkC8; void* unkCC; void* unkD0; };
struct S_0018B128 { char pad0[0x8]; int unk8; char padC[0xC]; void* unk18; void* unk1C; char pad20[4]; void* unk24; void* unk28; };

struct S00189E30 {
    char pad[0x48];
    char unk48;
};

struct S0018A070 {
    char pad[0xA0];
    int unkA0;
};

struct S0018A088 {
    char pad[0xA8];
    int unkA8;
};

struct S0018A618 {
    char pad[0x60];
    int unk60;
};

INCLUDE_ASM("asm/nonmatchings/game/t_189938", func_00189938);

INCLUDE_ASM("asm/nonmatchings/game/t_189938", func_00189AA0);

extern "C" S_189* func_00189AA8(S_189* s, int a, int b) {
    func_00122E60(s, a, b);
    s->unk44 = D_003446D0;
    func_0016F0C0((char*)s + 0x48);
    return s;
}

extern "C" void func_00189AE8(S_189* s, int a) {
    s->unk44 = D_003446D0;
    func_0016F0D0((char*)s + 0x48, 2);
    func_00122F88(s, a);
}

INCLUDE_ASM("asm/nonmatchings/game/t_189938", func_00189B38);

INCLUDE_ASM("asm/nonmatchings/game/t_189938", func_00189BF8);

extern "C" void* func_00189E30(S00189E30* self) {
    return &self->unk48;
}

extern "C" S_189* func_00189E38(int a, int b) {
    return func_00189AA8((S_189*)Heap_Alloc(D_00368A38[0], 0x4C, 1, 0), a, b);
}

extern "C" S3_189* func_00189E90(S3_189* s) {
    func_0014FA20(s, 10);
    s->unkA0 = 0;
    s->unk90 = D_00344A68;
    s->unkA4 = 0;
    s->unkA8 = 0;
    s->unkAC = 0;
    return s;
}

struct HN189 { u32 key; void* val; HN189* next; };
struct HI189 {
    s32 bits;
    HN189* buckets;
    s32 unk8;
    s32 iterIdx;
    HN189* iterNode;
    u8 unk14;
    u8 unk15;

    bool Scan(s32 size) {
        for (;;) {
            if (!(++iterIdx < size)) {
                return false;
            }
            iterNode = &buckets[iterIdx];
            if (iterNode->val) {
                return true;
            }
            HN189* nx = iterNode->next;
            if (nx) {
                iterNode = nx;
                return true;
            }
        }
    }

    bool Next() {
        s32 size = 1 << bits;
        if (iterNode) {
            iterNode = iterNode->next;
        } else if (iterIdx >= 0) {
            return false;
        }
        if (iterNode) {
            return true;
        }
        return Scan(size);
    }

    void* GetNext() {
        void* r;
        if (!Next()) {
            r = 0;
        } else {
            HN189* n = iterNode;
            r = n ? n->val : 0;
        }
        return r;
    }

    void Start() {
        iterIdx = -1;
        iterNode = 0;
    }
};
struct Ob189 { char pad0[0x18]; VEntry_189* unk18; char pad1C[0x30]; void* unk4C; };
struct S189D { char pad0[0x58]; HI189* unk58; char pad5C[0x34]; void* unk90; char pad94[0x14]; Ob189* unkA8; };

extern "C" {
void func_00153278(void*, int);
void func_00152908(void*, int);
void func_001A0380(void*, int);
void func_0014FB78(void*, int);
}

extern "C" void func_00189ED8(S189D* self, int flags) {
    self->unk90 = D_00344A68;
    if (self->unkA8) {
        self->unk58->Start();
        for (;;) {
            Ob189* o = (Ob189*)self->unk58->GetNext();
            if (!o) {
                break;
            }
            func_00153278(o, 0x40);
            VEntry_189* e = &o->unk18[1];
            ((void (*)(void*, int))e->fn)((char*)o + e->delta, 3);
        }
        if (self->unk58) {
            func_00152908(self->unk58, 3);
        }
        self->unk58 = 0;
        func_001AD7B8(self->unkA8);
        Ob189* s = self->unkA8;
        if (s) {
            if (s->unk4C) {
                func_001A0380(s->unk4C, 3);
            }
            Heap_Free(D_00368A38[0], s);
        }
    }
    func_0014FB78(self, flags);
}

extern "C" int func_0018A070(S0018A070* self) {
    return self->unkA0;
}

extern "C" void func_0018A078(S_189* s, void* a, int b) {
    s->unkA0 = a;
    s->unkA4 = b;
}

extern "C" int func_0018A088(S0018A088* self) {
    return self->unkA8;
}

struct HE189 { int unk0; int unk4; HE189* unk8; };
struct HT189 { int unk0; HE189* unk4; char pad8[0xD]; u8 unk15; };
struct B189 { char pad0[0x24]; void* unk24; };
struct W189 { char pad0[0x58]; HT189* unk58; };

extern "C" {
int func_001ACD38(void*);
int func_001ACF30(void*);
void* func_001AD008(void*);
void func_00152C58(void*, int);
void func_00152C68(void*, void*);
void func_0014FF20(void*, void*);
void* operator_new(unsigned int);
void* func_0018B070(void*, int);
}

static inline int SHT189_Find(HT189* t, const int& k) {
    HE189* n;
    if (t->unk4 == 0) return 0;
    n = &t->unk4[k & ((1 << t->unk0) - 1)];
    if (n == 0) return 0;
    do {
        if (n->unk0 == k) {
            int v = n->unk4;
            if (t->unk15 != 0 || v != 0) return v;
        }
        n = n->unk8;
    } while (n);
    return 0;
}

extern "C" void func_0018A090(S_189* s, void* node) {
    if (node) {
        do {
            if (func_001ACD38(node)) {
                int k0 = func_001ACF30(node);
                HT189* t = ((W189*)s)->unk58;
                int k = k0;
                if (!SHT189_Find(t, k)) {
                    void* obj = func_001836F0(Heap_Alloc(D_00368A38[0], 0x1C, 1, 0));
                    func_00152C58(obj, func_001ACF30(node));
                    B189* b = (B189*)func_0018B070(operator_new(0x30), 0);
                    b->unk24 = node;
                    func_00152C68(obj, b);
                    func_0014FF20(s, obj);
                }
            } else {
                func_0018A090(s, func_001ACF70(node));
            }
            node = func_001AD008(node);
        } while (node);
    }
}

INCLUDE_ASM("asm/nonmatchings/game/t_189938", func_0018A1F0);

extern "C" void func_0018A350(S_189* s) {
    func_0018A090(s, func_001ACF70(s->unkA0));
}

extern "C" void func_0018A388(S_189* s) {
    func_0018A1F0(s, func_001ACF70(s->unkAC));
}

extern "C" int func_0018A3C0(void) {
    return 1;
}

extern "C" int func_0018A3C8(void) {
    return 1;
}

extern "C" int func_0018A3D0(void) {
    return 1;
}

extern "C" int func_0018A3D8(S3_189* s) {
    if (s->unkAC) {
        func_0030A1C8(0, 0);
        func_001AD7B8(s->unkAC);
        func_0011D220(s->unk70);
        s->unk70 = 0;
        return 1;
    }
    return 0;
}

extern "C" void* func_0018A430(void) {
    return func_001836F0(Heap_Alloc(D_00368A38[0], 0x1C, 1, 0));
}

extern "C" void func_0018A468(S5_189* s, int* p) {
    if (s->unkA0) {
        func_001ACE58(s->unkA0, 1);
        func_001AD048(s->unkA0, *p);
    }
    if (s->unkA8) {
        func_001ACE58(s->unkA8, 1);
        func_001AD048(s->unkA8, *p);
    }
}

INCLUDE_ASM("asm/nonmatchings/game/t_189938", func_0018A4D0);

extern "C" void func_0018A510(S_189* s, int v) {
    if (s->unkA0) func_001ACD98(s->unkA0, v);
}

INCLUDE_ASM("asm/nonmatchings/game/t_189938", func_0018A538);

extern "C" void func_0018A5A0(void* list, int a) {
    int n = func_00161958(list);
    int i;
    for (i = 0; i < n; i++) {
        if (func_0015F1C8(func_001618A0(list, i), a)) break;
    }
}

extern "C" int func_0018A618(S0018A618* self) {
    return self->unk60;
}

INCLUDE_ASM("asm/nonmatchings/game/t_189938", func_0018A620);

extern "C" void func_0018A7A0(S2_189* s, int a) {
    It_189 end((N_189*)s->unk14);
    It_189 it(((N_189*)s->unk14)->unk4);
    for (; it != end; ++it) func_0015F398(*it.cur->unk8, a);
}

extern "C" void func_0018A800(S2_189* s) {
    It_189 end((N_189*)s->unk14);
    It_189 it(((N_189*)s->unk14)->unk4);
    for (; it != end; ++it) {
        O_0018A800* o = (O_0018A800*)*it.cur->unk8;
        VEntry_189* e = &o->unk18[67];
        ((void (*)(void*))e->fn)((char*)o + e->delta);
    }
}

extern "C" S_189* func_0018A860(S_189* s) {
    func_0015FBD8(s);
    s->unk60 = 0;
    s->unk58 = D_00344BE0;
    return s;
}

extern "C" void func_0018A898(S5_189* s, int flag) {
    s->unk58 = D_00344BE0;
    if (s->unk60) {
        D_0018A898* d = s->unk60;
        VE0_189* e = &d->unk0[1];
        ((void (*)(void*, int))e->fn)((char*)d + e->delta, 3);
        s->unk60 = 0;
    }
    func_0015FC88(s, flag);
}

extern "C" int func_0018A900(S0018A618* self) {
    return self->unk60;
}

INCLUDE_ASM("asm/nonmatchings/game/t_189938", func_0018A908);

extern "C" void func_0018AC50(S_0018AC50* self, int flags) {
    self->unk0 = D_00344C80;
    if (self->unk4) {
        Heap_Free(D_00368A38[0], self->unk4);
    }
    if (self->unk8) {
        Heap_Free(D_00368A38[0], self->unk8);
    }
    self->unk0 = D_00344C98;
    if (flags & 1) {
        Heap_Free(D_00368A38[0], self);
    }
}

extern "C" void func_0018ACD8(S_189* s, int flag) {
    s->unk0 = D_00344C98;
    if (flag & 1) Heap_Free(D_00368A38[0], s);
}

extern "C" int func_0018AD18(S2_189* s, int* p, int base) {
    s->unkB0 = *p++;
    s->unkD8 = *p++;
    if (s->unkD8 > 0) {
        s->unkD4 = (E_0018AD18*)p;
        int i;
        for (i = 0; i < s->unkD8; i++) s->unkD4[i].unk4 += base;
    }
    return s->unkD8 > 0;
}

INCLUDE_ASM("asm/nonmatchings/game/t_189938", func_0018AD80);

extern "C" void func_0018AEA0(S_0018AEA0* self, int flags) {
    self->unkBC = D_00344DD0;
    if (self->unkC0) {
        func_001AD7B8(self->unkC0);
        if ((int)(*(long*)&self->unkC8 >> 1) & 1) {
            func_0011D348(func_00113408(&self->unkCC));
        }
    } else {
        func_001BD458(self->unkC4);
    }
    if (self->unkD0) {
        func_0011A470(self->unkD0);
    }
    if (self->unkCC) {
        Heap_Free(D_00368A38[0], self->unkCC);
    }
    func_00162420(self, flags);
}

extern "C" void func_0018AF58(S4_189* s, u32 mask) {
    if ((u32)s->unkC8 & 1) return;
    int i;
    for (i = 0; i < s->unkD8; i++) {
        if (s->unkD4[i].unk0 & mask) *s->unkD4[i].unk4 |= 0x8000;
    }
    s->unkC8 |= 1;
}

extern "C" int func_0018AFD8(S3_189* s, int a) {
    if (s->unkC0) return 0;
    return func_001BD780(s->unkC4, func_00187F48(a));
}

extern "C" int func_0018B028(S_189* s) {
    if (s->unkC0) {
        func_001B05B8(s->unkC0);
        return 1;
    }
    return 0;
}

INCLUDE_ASM("asm/nonmatchings/game/t_189938", func_0018B058);

INCLUDE_ASM("asm/nonmatchings/game/t_189938", func_0018B070);

extern "C" void func_0018B128(S_0018B128* self, int flags) {
    self->unk18 = D_00344F10;
    if (self->unk1C) {
        func_001B1728(self->unk1C, 3);
        self->unk1C = 0;
    }
    if (self->unk24) {
        if (self->unk8 == 1) {
            func_001AD9D0(self->unk24);
        } else if (self->unk8 == 2) {
            func_001ADBA8(self->unk24, 1);
        }
        self->unk24 = 0;
    }
    if (self->unk28) {
        Heap_Free(D_00368A38[0], self->unk28);
    }
    func_0015EFE8(self, flags);
}

INCLUDE_ASM("asm/nonmatchings/game/t_189938", func_0018B1D0);

extern "C" void func_0018B398(S_189* s) {
    if (s->unk1C) func_001B1C38(s->unk1C);
}

extern "C" int func_0018B3C0(S_189* s) {
    if (s->unk1C) {
        func_001B18C8(s->unk1C);
        return 1;
    }
    return 0;
}

INCLUDE_ASM("asm/nonmatchings/game/t_189938", func_0018B3F0);

INCLUDE_ASM("asm/nonmatchings/game/t_189938", func_0018B5C0);
