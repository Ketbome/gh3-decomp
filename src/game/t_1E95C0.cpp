// cflags: -funroll-loops
#include "common.h"

struct S1E9E48 {
    s32 unk0;
    s32 unk4;
    s32 unk8;
};

struct S1EA1E0 {
    char pad0[0x2C];
    void* unk2C;
};

struct S1EB190 {
    char pad0[0x4];
    s32 unk4;
    char pad8[0x8];
    s32 unk10;
};

struct S1EB1C0_N {
    char pad0[0xB8];
    S1EB1C0_N* unkB8;
};

struct S1EA4A0 {
    int unk0;
    int unk4;
};

struct HNode {
    u32 key;
    void* val;
    HNode* next;
};

struct HTable {
    s32 bits;
    HNode* buckets;
    s32 unk8;
    s32 iterIdx;
    HNode* iterNode;
    u8 unk14;
    u8 unk15;

    void* Get(const u32& key) {
        if (!buckets) {
            return 0;
        }
        HNode* n = &buckets[key & ((1 << bits) - 1)];
        if (!n) {
            return 0;
        }
        do {
            if (n->key == key) {
                if (unk15 || n->val) {
                    return n->val;
                }
            }
            n = n->next;
        } while (n);
        return 0;
    }

    bool Scan(s32 size) {
        for (;;) {
            if (!(++iterIdx < size)) {
                return false;
            }
            iterNode = &buckets[iterIdx];
            if (iterNode->val) {
                return true;
            }
            HNode* nx = iterNode->next;
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
            HNode* n = iterNode;
            r = n ? n->val : 0;
        }
        return r;
    }

    void Start() {
        iterIdx = -1;
        iterNode = 0;
    }

};

struct S1E9DA8 {
    HTable* unk0;
};

struct S1EA6F0 {
    char pad0[0xC];
    void* unkC;
    char pad10[0x10];
    s32 unk20;
    void* unk24;
};

struct S1EA600_X {
    char pad0[0xB4];
    s32 unkB4;
    char padB8[0x20];
    u32 unkD8;
};

struct S1EA600 {
    char pad0[0x30];
    s32 unk30;
};

struct S1EA510 {
    char pad0[0x2C];
    void* unk2C;
    s32 unk30;
    s32 unk34;
};

struct S1E9858 {
    char pad0[0x10];
    S1E9DA8* unk10;
    char unk14[0x10];
    u32 unk24;
    u32* unk28;
    u32 unk2C;
};

extern "C" {
extern int D_00368A38[] __attribute__((section(".sdata")));
extern char D_0034E100[];
extern char D_0034E380[];
extern HTable* D_0036DFC0;
extern S1EB190* D_0036E010;
void* operator_new(u32 size);
void func_001E8660(void*);
void func_001E88F8(void*);
s32 func_001E8838(void*);
void* Heap_Alloc(int, int, int, int);
void* func_001EAF90(void*, int, int);
extern char D_0034DFD8[];
void Heap_Free(int, void*);
void* func_001E9E80(void*, int, int);
s32 func_0027D870(int, u32, void*, int);
s32 func_0027D470(int, u32, void*, int);
void func_0011A558(u32, int, int);
void func_0011A568();
s32 func_001EA318(int, void*);
void* func_001EA218(u32, int*);
extern char D_0034E4F0[];
void* func_001E8CA8(void*, int*);
void func_001E9010(void*, int);
s32 func_0027D400(int, u32, void*, int);
void* func_001287F0(int, int);
void* func_0027AA98(void*, s32);
S1EA600_X* func_002899B0(S1EA600_X*);
s32 func_0028AB28(S1EA600_X*);
void func_001E8A88(void*);
void* func_001E82F0(void*, int*);
S1EA510* func_001EA510(S1EA510*, int*);
void* func_001E8E48(void*, int*);
bool func_001E9DA8(S1E9DA8*, u32);
bool func_001E9C08(S1E9DA8*, u32);
s32 func_001E9390(void*, s32, s32);
void func_001E8E20(void*, int);
extern char D_0034DE98[];
extern char D_0034D6A8[];
void func_001E92B0(void*, int);
void func_001E9A68(void*);
void func_001EA118(void*, int);
extern char D_0034E4F0[];
void func_0027AC90(void*);
void func_00113250(void*);
void func_001EA060(void*);
void* func_001E95F0(void*, int*);
void* func_001E7998(void*, int*);
void* func_001E7B48(void*, int*);
struct S1EA6F0* func_001EA6F0(struct S1EA6F0*, int*);
void func_0011C408(void*, void*);
bool func_00222F90(int);
void func_001EB378(void*, int);
}

INCLUDE_ASM("asm/nonmatchings/game/t_1E95C0", func_001E95C0);

struct S1E95Src {
    int unk0;
    u32 unk4;
    int* unk8;
};

static inline void* Alloc95(int sz) {
    return Heap_Alloc(D_00368A38[0], sz, 1, 0);
}

INCLUDE_ASM("asm/nonmatchings/game/t_1E95C0", func_001E95F0);

extern "C" void func_001E97C8(char* p, int flags) {
    *(char**)(p + 0xC) = D_0034DE98;
    if (*(void**)(p + 0x28)) {
        Heap_Free(D_00368A38[0], *(void**)(p + 0x28));
    }
    func_001E92B0(p + 0x14, 2);
    int h = D_00368A38[0];
    *(char**)(p + 0xC) = D_0034D6A8;
    Heap_Free(h, *(void**)(p + 4));
    if (flags & 1) {
        Heap_Free(D_00368A38[0], p);
    }
}

extern "C" void func_001E9858(S1E9858* p) {
    s32 count = 0;
    u32 i;
    for (i = 0; i < p->unk24; i++) {
        u32 k = p->unk28[i];
        if (k == 0x8D113B8C) {
            continue;
        }
        bool m = false;
        if (p->unk2C == 0x196F630F) {
            if (func_001E9DA8(p->unk10, k)) {
                m = true;
            }
        }
        if (m) {
            count++;
        } else {
            bool n = false;
            if (p->unk2C == 0xFEF4E1E8) {
                if (!func_001E9C08(p->unk10, p->unk28[i])) {
                    n = true;
                }
            }
            count += n;
        }
    }
    if (func_001E9390(p->unk14, count, p->unk24)) {
        func_001E8E20(p, 1);
    }
}

INCLUDE_ASM("asm/nonmatchings/game/t_1E95C0", func_001E9980);

extern "C" s32 func_001E9998() {
    return 1;
}

INCLUDE_ASM("asm/nonmatchings/game/t_1E95C0", func_001E99A0);

extern "C" void func_001E9A00(char* p, int flags) {
    *(char**)(p + 4) = D_0034DFD8;
    func_001E9A68(p);
    if (*(void**)p) {
        func_001EA118(*(void**)p, 3);
    }
    if (flags & 1) {
        Heap_Free(D_00368A38[0], p);
    }
}

extern "C" void func_001E9A68(void* pp) {
    S1E9DA8* p = (S1E9DA8*)pp;
    p->unk0->Start();
    void* v = p->unk0->GetNext();
    while (v) {
        void* n = p->unk0->GetNext();
        Heap_Free(D_00368A38[0], v);
        v = n;
    }
}

extern "C" bool func_001E9C08(S1E9DA8* p, u32 key) {
    u32* v = (u32*)p->unk0->Get(key);
    if (!v) {
        return false;
    }
    return *v == 0x152D376E;
}

INCLUDE_ASM("asm/nonmatchings/game/t_1E95C0", func_001E9CA8);

extern "C" s32 func_001E9CB0(S1E9DA8* p) {
    s32 count = 0;
    u32* v;
    p->unk0->Start();
    for (;;) {
        v = (u32*)p->unk0->GetNext();
        if (!v) {
            break;
        }
        if (*v == 0x196F630F) {
            count++;
        }
    }
    return count;
}

extern "C" s32 func_001E9D98(s32** p) {
    return (*p)[2];
}

extern "C" bool func_001E9DA8(S1E9DA8* p, u32 key) {
    return *(u32*)p->unk0->Get(key) == 0x196F630F;
}

INCLUDE_ASM("asm/nonmatchings/game/t_1E95C0", func_001E9E40);

extern "C" void func_001E9E48(S1E9E48* p) {
    p->unk0 = 0;
    p->unk4 = 0;
    p->unk8 = 0;
}

extern "C" S1E9E48* func_001E9E58(S1E9E48* p) {
    func_001E9E48(p);
    return p;
}

INCLUDE_ASM("asm/nonmatchings/game/t_1E95C0", func_001E9E80);

extern "C" void func_001EA060(void* self) {
    HTable* t = (HTable*)self;
    if (!t->buckets) return;
    HNode* b = t->buckets;
    u32 n = 1 << t->bits;
    for (u32 i = 0; i < n; i++) {
        HNode* c = b->next;
        while (c) {
            HNode* nx = c->next;
            func_0011C408(0, c);
            c = nx;
        }
        func_001E9E48((S1E9E48*)b);
        b++;
    }
    t->unk8 = 0;
}

extern "C" void func_001EA118(void* v, int flags) {
    char* p = (char*)v;
    if (!*(u8*)(p + 0x16)) {
        if (*(void**)(p + 4)) {
            func_001EA060(p);
            if (*(void**)(p + 4)) {
                Heap_Free(D_00368A38[0], *(void**)(p + 4));
            }
            *(void**)(p + 4) = 0;
        }
    }
    if (flags & 1) {
        Heap_Free(D_00368A38[0], p);
    }
}

extern "C" void func_001EA190(S1E9E48* p) {
    func_001E88F8(p);
    if (!func_001E8838(p)) {
        ((u32*)p)[3] = 0x152D376E;
    }
}

extern "C" u32 func_001EA1D0() {
    return 0x1EEA667A;
}

extern "C" void func_001EA1E0(S1EA1E0* p) {
    p->unk2C = D_0034E100;
    func_001E8660(p);
}

extern "C" s32 func_001EA208() {
    return 0;
}

extern "C" void func_001EA210(void) {
}

extern "C" void* func_001EA218(u32 type, int* a) {
    switch (type) {
    case 0xA6D2D890:
        return func_001EA510((S1EA510*)Heap_Alloc(D_00368A38[0], 0x38, 1, 0), a);
    case 0xF5012F52:
        return func_001E8E48(Heap_Alloc(D_00368A38[0], 0x34, 1, 0), a);
    case 0x1EEA667A: {
        S1EA510* p = (S1EA510*)Heap_Alloc(D_00368A38[0], 0x30, 1, 0);
        func_001E82F0(p, a);
        p->unk2C = D_0034E100;
        return p;
    }
    }
    return 0;
}

extern "C" s32 func_001EA318(int type, void* v) {
    int* a = (int*)v;
    switch ((u32)type) {
    case 0xDFBF1A84:
        return (s32)func_001E7B48(Heap_Alloc(D_00368A38[0], 0x2C, 1, 0), a);
    case 0x032314D1:
        return (s32)func_001E95F0(Heap_Alloc(D_00368A38[0], 0x30, 1, 0), a);
    case 0xB4BA8031:
        return (s32)func_001E7998(Heap_Alloc(D_00368A38[0], 0x24, 1, 0), a);
    case 0xA6D2D890:
        return (s32)func_001EA6F0((S1EA6F0*)Heap_Alloc(D_00368A38[0], 0x28, 1, 0), a);
    }
    return 0;
}

extern "C" s32 func_001EA430(int a, int b) {
    S1EA4A0 s;
    int v;
    s32 r;
    s.unk0 = a;
    s.unk4 = b;
    func_0027D870(a, 0x7321A8D6, &v, 1);
    int x = v;
    func_0011A558(0x2306D8A5, 0, 0);
    r = (s32)func_001EA218(x, (int*)&s);
    func_0011A568();
    return r;
}

extern "C" s32 func_001EA4A0(int a, int b) {
    S1EA4A0 s;
    int v;
    s32 r;
    s.unk0 = a;
    s.unk4 = b;
    func_0027D870(a, 0x7321A8D6, &v, 1);
    func_0011A558(0xD0A7AAFA, 0, 0);
    r = func_001EA318(v, &s);
    func_0011A568();
    return r;
}

extern "C" S1EA510* func_001EA510(S1EA510* p, int* a) {
    s32 v;
    func_001E82F0(p, a);
    p->unk30 = 0;
    p->unk2C = D_0034E380;
    func_0027D870(a[0], 0x4A6A66D1, &v, 1);
    p->unk34 = v;
    return p;
}

INCLUDE_ASM("asm/nonmatchings/game/t_1E95C0", func_001EA578);

extern "C" void func_001EA600(S1EA600* p) {
    bool found = false;
    S1EA600_X* x;
    for (x = func_002899B0(0); x && !found; x = func_002899B0(x)) {
        bool m = false;
        if (x->unkD8 & 1) {
            if (x->unkB4 == p->unk30) {
                if (!func_0028AB28(x)) {
                    m = true;
                }
            }
        }
        if (m) {
            found = true;
        }
    }
    if (!found) {
        func_001E8A88(p);
    }
}

extern "C" u32 func_001EA6B0() {
    return 0xA6D2D890;
}

extern "C" void func_001EA6C0(S1EA1E0* p) {
    p->unk2C = D_0034E380;
    func_001E8660(p);
}

extern "C" s32 func_001EA6E8() {
    return 1;
}

extern "C" S1EA6F0* func_001EA6F0(S1EA6F0* p, int* a) {
    s32 v;
    func_001E8CA8(p, a);
    p->unkC = D_0034E4F0;
    func_001E9010((char*)p + 0x10, a[0]);
    func_0027D870(a[0], 0xA6D2D890, &p->unk20, 1);
    v = 0;
    if (func_0027D400(a[0], 0x7031F10C, &v, 0)) {
        p->unk24 = func_0027AA98(func_001287F0(8, 1), v);
    } else {
        p->unk24 = 0;
    }
    return p;
}

extern "C" void func_001EA798(char* p, int flags) {
    void* m = *(void**)(p + 0x24);
    *(char**)(p + 0xC) = D_0034E4F0;
    if (m) {
        func_0027AC90(m);
        func_00113250(m);
    }
    func_001E92B0(p + 0x10, 2);
    int h = D_00368A38[0];
    *(char**)(p + 0xC) = D_0034D6A8;
    Heap_Free(h, *(void**)(p + 4));
    if (flags & 1) {
        Heap_Free(D_00368A38[0], p);
    }
}

INCLUDE_ASM("asm/nonmatchings/game/t_1E95C0", func_001EA830);

INCLUDE_ASM("asm/nonmatchings/game/t_1E95C0", func_001EA970);

extern "C" s32 func_001EA988() {
    return 1;
}

GP_DATA(D_0036DFC0);
extern "C" void func_001EA990() {
    if (!D_0036DFC0) {
        D_0036DFC0 = (HTable*)func_001EAF90(Heap_Alloc(D_00368A38[0], 0x1C, 1, 0), 4, 0);
    }
}

INCLUDE_ASM("asm/nonmatchings/game/t_1E95C0", func_001EA9D8);

extern "C" void* func_001EA9E0(u32 key) {
    return D_0036DFC0->Get(key);
}

INCLUDE_ASM("asm/nonmatchings/game/t_1E95C0", func_001EAA68);

INCLUDE_ASM("asm/nonmatchings/game/t_1E95C0", func_001EABC0);

INCLUDE_ASM("asm/nonmatchings/game/t_1E95C0", func_001EAD28);

INCLUDE_ASM("asm/nonmatchings/game/t_1E95C0", func_001EAEA0);

INCLUDE_ASM("asm/nonmatchings/game/t_1E95C0", func_001EAF50);

extern "C" void func_001EAF58(S1E9E48* p) {
    p->unk0 = 0;
    p->unk4 = 0;
    p->unk8 = 0;
}

extern "C" S1E9E48* func_001EAF68(S1E9E48* p) {
    func_001EAF58(p);
    return p;
}

INCLUDE_ASM("asm/nonmatchings/game/t_1E95C0", func_001EAF90);

INCLUDE_ASM("asm/nonmatchings/game/t_1E95C0", func_001EB170);

GP_DATA(D_0036E010);
extern "C" void func_001EB1C0() {
    if (D_0036E010) {
        S1EB1C0_N* n = (S1EB1C0_N*)D_0036E010->unk4;
        if (n) {
            while (n) {
                S1EB1C0_N* c = n;
                n = n->unkB8;
                Heap_Free(D_00368A38[0], c);
            }
        }
        D_0036E010->unk4 = 0;
    }
}

extern "C" void func_001EB218() {
    if (D_0036E010) {
        S1EB1C0_N* c = (S1EB1C0_N*)D_0036E010->unk4;
        S1EB1C0_N* prev = 0;
        while (c) {
            S1EB1C0_N* next = c->unkB8;
            bool missing = !func_00222F90(*(int*)((char*)c + 4));
            if (missing) {
                func_001EB378(c, 0);
                Heap_Free(D_00368A38[0], c);
                if (!prev) {
                    D_0036E010->unk4 = (s32)next;
                } else {
                    prev->unkB8 = next;
                }
            } else {
                prev = c;
            }
            c = next;
        }
    }
}

extern "C" void func_001EB2B0() {
    if (D_0036E010) {
        S1EB1C0_N* n = (S1EB1C0_N*)D_0036E010->unk4;
        if (n) {
            S1EB1C0_N* c = n;
            do c = c->unkB8; while (c);
        }
    }
}

INCLUDE_ASM("asm/nonmatchings/game/t_1E95C0", func_001EB2F0);

extern "C" int func_001EB338(S1EB1C0_N* n) {
    int r = 0;
    for (S1EB1C0_N* c = (S1EB1C0_N*)D_0036E010->unk4; c; c = c->unkB8) {
        if (c == n) {
            r = 1;
            break;
        }
    }
    return r;
}
TEXT_PAD(12);

INCLUDE_ASM("asm/nonmatchings/game/t_1E95C0", func_001EB378);

INCLUDE_ASM("asm/nonmatchings/game/t_1E95C0", func_001EB4D0);
