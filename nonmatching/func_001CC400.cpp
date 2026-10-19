#include "common.h"

struct S001CBCC8 {
    char pad0[0x81B8];
    s32 unk81B8;
    char pad81BC[0x1C];
    s32 unk81D8;
};

struct S001CBD30 {
    char pad0[0x34];
    s32 unk34;
    char pad38[0xA8];
    s32 unkE0;
};

struct S001CBFE8 {
    char pad0[0x18];
    void* unk18;
};

struct S001CC050 {
    char pad0[0x1C];
    void (*unk1C)(void);
    char pad20[0x8];
    void (*unk28)(void);
};

struct S001CC090 {
    char pad0[0x38];
    union {
        u32 unk38;
        struct {
            u64 b0 : 7;
            u64 b7 : 1;
        };
    };

    bool Test(u32 m) {
        return (unk38 & m) != 0;
    }
};

struct S001CC170_18 {
    char pad0[0x3124];
    s32 unk3124;
};

struct S001CC170 {
    char pad0[0x18];
    S001CC170_18* unk18;
};

struct S001CC2D8 {
    s8* unk0;
    char pad4[0x10];
    s32 unk14;
};

struct N1CBB {
    char pad0[0xC];
    N1CBB* unkC;
    N1CBB* unk10;
    void* unk14;
};

struct VE1CC {
    s16 delta;
    s16 unk2;
    void* fn;
};

struct S001CD640 {
    char pad0[0x8];
    void* unk8;
    char padC[0xA4];
};

struct S001CD6B0 {
    char pad0[0x168];
    s32 unk168;
    char pad16C[0x8];
    s32 unk174[1];
};

extern "C" {
void func_00113F38(void* p);
void func_001184C0(void* p);
void func_00118570(void* p);
void func_0029F500(s32 a, s32 b);
int func_0029F5B8(s32 a);
u32 func_0011EF10(int a, u8* b);
void func_00113FB8(int a);
extern u32 D_00372D70;
void func_00114660(char* a, int b);
int func_00114030(int a);
void func_00119490(char* a, int b);
void func_001194B8(char* a);
int func_001C94A8();
int func_001C9A80(char* a);
void func_001C9FB0(char* a);
int func_0030B550(char* buf, u8* fmt, int a, char* b, char* c);
void func_0027C028(int a, int b, char* c);
extern u8 D_0034B2F0[];
int func_001CA4E8(char* g, int a);
void func_001CC100(int a, int b);
extern int D_0038E3A0[];
void func_001CB200(char* g, int a, int b, char* c, char* d, int e, int f, int g2, int h);
int func_001CD360(int a);
void func_001CD470(int a, int b);
int func_00113DF0(int a, int b, int c);
extern s32 D_0036D020;
extern s32 D_0036D024;
void Heap_Free(s32 heap, void* p);
extern s32 D_00368A38[] __attribute__((section(".sdata")));
extern char* D_00369A60[] __attribute__((section(".sdata")));
extern u8 D_0034AFD0[];
extern u8 D_0034AF30[];
extern u8 D_0034AFE8[];
extern u8 D_0034B190[];
extern u8 D_0034ACA8[];
extern u8 D_0034AC90[];
extern u8 D_0034AC78[];
int CFunc_ExitSurveyorMode(int a, int b);
int func_001287F0(int a, int b);
int func_0027AA70(int a);
void func_0027AC90(int a);
void func_0027C448(int a, int b, int c);
void func_0028C9D0(int a, int b, int c, int d, int e, int f);
void func_00113250(int a);
void func_0029F090(s32 a);
int func_0029D8C8(s32 a);
void func_00114958(s32 a, s32 b);
extern s32 D_00370EE0;
void func_001CD6E0(s32 a, s32 b);
extern char D_00342398[];
int func_001CB558(void* p);
void func_001C9DE0(void* p);
void func_001CB550(void* p, int a);
}

extern "C" void func_001CBB50(N1CBB* n, int flags) {
    n->unk14 = D_0034AFD0;
    n->unk10->unkC = n->unkC;
    n->unkC->unk10 = n->unk10;
    n->unkC = n;
    n->unk10 = n;
    if (flags & 1) {
        Heap_Free(D_00368A38[0], n);
    }
}

extern "C" void func_001CBBB0(N1CBB* n, int flags) {
    n->unk14 = D_0034AFD0;
    n->unk10->unkC = n->unkC;
    n->unkC->unk10 = n->unk10;
    n->unkC = n;
    n->unk10 = n;
    if (flags & 1) {
        Heap_Free(D_00368A38[0], n);
    }
}

extern "C" void func_001CBC10(void* p) {
    func_00113F38(p);
}

extern "C" void func_001CBC30(void) {
}

extern "C" void func_001CBC38(void) {
}

extern "C" void func_001CBC40(void) {
}

extern "C" void func_001CBC48(void) {
}

extern "C" void func_001CBC50(void) {
}

extern "C" int func_001CBC58(void) {
    return 0;
}

extern "C" int func_001CBC60(void) {
    return 0;
}

extern "C" void func_001CBC68(void) {
}

extern "C" int func_001CBC70(void) {
    return 0;
}

extern "C" int func_001CBC78(void) {
    return 0;
}

extern "C" void func_001CBC80(void) {
}

extern "C" void func_001CBC88(void) {
}

extern "C" void func_001CBC90(void) {
}

extern "C" int func_001CBC98(void) {
    return -1;
}

extern "C" void func_001CBCA0(void) {
}

extern "C" void func_001CBCA8(void) {
}

extern "C" void func_001CBCB0(void) {
}

extern "C" void func_001CBCB8(void) {
}

extern "C" int func_001CBCC0(void) {
    return 0;
}

extern "C" void func_001CBCC8(S001CBCC8* p, s32 v) {
    p->unk81B8 = v;
}

extern "C" s32 func_001CBCD8(S001CBCC8* p) {
    return p->unk81B8;
}

extern "C" void func_001CBCE8(void) {
}

extern "C" int func_001CBCF0(void) {
    return 0;
}

extern "C" void func_001CBCF8(S001CBCC8* p) {
    p->unk81D8 ^= 1;
}

extern "C" int func_001CBD10(void) {
    return 0;
}

extern "C" void func_001CBD18(void) {
}

extern "C" int func_001CBD20(void) {
    return -1;
}

extern "C" int func_001CBD28(void) {
    return -1;
}

extern "C" void func_001CBD30(S001CBD30* p, s32 v) {
    p->unk34 = v;
}

extern "C" void func_001CBD38(void) {
}

extern "C" void func_001CBD40(void) {
}

extern "C" int func_001CBD48(void) {
    return 0;
}

extern "C" void func_001CBD50(void) {
}

extern "C" void func_001CBD58(void) {
}

extern "C" void func_001CBD60(void) {
}

extern "C" void func_001CBD68(void) {
}

extern "C" int func_001CBD70(void) {
    return -1;
}

extern "C" int func_001CBD78(void) {
    return -1;
}

extern "C" void func_001CBD80(void) {
}

extern "C" int func_001CBD88(void) {
    return 0;
}

extern "C" int func_001CBD90(void) {
    return 0;
}

extern "C" int func_001CBD98(void) {
    return 0;
}

extern "C" int func_001CBDA0(void) {
    return 0;
}

extern "C" int func_001CBDA8(void) {
    return 0;
}

extern "C" int func_001CBDB0(void) {
    return 0;
}

extern "C" int func_001CBDB8(void) {
    return 0;
}

extern "C" void func_001CBDC0(void) {
}

extern "C" void func_001CBDC8(void) {
}

extern "C" void func_001CBDD0(void) {
}

extern "C" void func_001CBDD8(void) {
}

extern "C" void func_001CBDE0(void) {
}

extern "C" void func_001CBDE8(N1CBB* n, int flags) {
    n->unk14 = D_0034AFE8;
    n->unk10->unkC = n->unkC;
    n->unkC->unk10 = n->unk10;
    n->unkC = n;
    n->unk10 = n;
    if (flags & 1) {
        Heap_Free(D_00368A38[0], n);
    }
}

extern "C" void func_001CBE48(N1CBB* n, int flags) {
    n->unk14 = D_0034AFD0;
    n->unk10->unkC = n->unkC;
    n->unkC->unk10 = n->unk10;
    n->unkC = n;
    n->unk10 = n;
    if (flags & 1) {
        Heap_Free(D_00368A38[0], n);
    }
}

extern "C" void func_001CBEA8(N1CBB* n, int flags) {
    n->unk14 = D_0034AF30;
    n->unk10->unkC = n->unkC;
    n->unkC->unk10 = n->unk10;
    n->unkC = n;
    n->unk10 = n;
    if (flags & 1) {
        Heap_Free(D_00368A38[0], n);
    }
}

extern "C" void func_001CBF08(N1CBB* n, int flags) {
    n->unk14 = D_0034AF30;
    n->unk10->unkC = n->unkC;
    n->unkC->unk10 = n->unk10;
    n->unkC = n;
    n->unk10 = n;
    if (flags & 1) {
        Heap_Free(D_00368A38[0], n);
    }
}

extern "C" void func_001CBF68(char* p, int flags) {
    *(void**)(p + 8) = D_0034ACA8;
    if (flags & 1) {
        Heap_Free(D_00368A38[0], p);
    }
}

extern "C" void func_001CBFA8(char* p, int flags) {
    *(void**)(p + 8) = D_0034AC90;
    if (flags & 1) {
        Heap_Free(D_00368A38[0], p);
    }
}

extern "C" void func_001CBFE8(S001CBFE8* p) {
    p->unk18 = D_00342398;
    func_00113F38(p);
}

extern "C" void func_001CC010(char* p, int flags) {
    *(void**)(p + 8) = D_0034AC78;
    if (flags & 1) {
        Heap_Free(D_00368A38[0], p);
    }
}

extern "C" void func_001CC050(S001CC050* p) {
    p->unk28();
}

extern "C" void func_001CC070(S001CC050* p) {
    p->unk1C();
}

extern "C" u32 func_001CC090(S001CC090* p) {
    return p->unk38 & 1;
}

extern "C" u64 func_001CC0A0(S001CC090* p) {
    return p->b7;
}

extern "C" bool func_001CC0B0(S001CC090* p) {
    return p->Test(4);
}

extern "C" bool func_001CC0C0(S001CC090* p) {
    return p->Test(0x400);
}

extern "C" void func_001CC0D0(S001CC090* p) {
    p->unk38 |= 2;
}

INCLUDE_ASM("asm/nonmatchings/game/t_1CBB50", func_001CC0E0);

extern "C" bool func_001CC0E8(S001CC090* p) {
    return (p->unk38 & 0x21) != 0;
}

INCLUDE_ASM("asm/nonmatchings/game/t_1CBB50", func_001CC0F8);

INCLUDE_ASM("asm/nonmatchings/game/t_1CBB50", func_001CC100);

extern "C" s32 func_001CC170(S001CC170* p) {
    if (p->unk18 != 0) {
        return p->unk18->unk3124;
    }
    return 0;
}

INCLUDE_ASM("asm/nonmatchings/game/t_1CBB50", func_001CC190);

extern "C" bool func_001CC198(S001CC090* p) {
    return p->Test(8);
}

INCLUDE_ASM("asm/nonmatchings/game/t_1CBB50", func_001CC1A8);

extern "C" void func_001CC1F8(N1CBB* n, int flags) {
    n->unk14 = D_0034AFE8;
    n->unk10->unkC = n->unkC;
    n->unkC->unk10 = n->unk10;
    n->unkC = n;
    n->unk10 = n;
    if (flags & 1) {
        Heap_Free(D_00368A38[0], n);
    }
}

extern "C" int func_001CC258(void) {
    return 0;
}

extern "C" int func_001CC260(void) {
    return 0;
}

extern "C" void func_001CC268(void) {
}

extern "C" int func_001CC270(void) {
    return 1;
}

extern "C" void func_001CC278(void) {
}

extern "C" void func_001CC280(void) {
}

INCLUDE_ASM("asm/nonmatchings/game/t_1CBB50", func_001CC288);

extern "C" int func_001CC298(char* p) {
    char* o = *(char**)(p + 0x1C);
    VE1CC* e = (VE1CC*)(*(char**)(o + 0xEE00) + 0x230);
    ((void (*)(char*, int))e->fn)(o + e->delta, *(int*)p);
    return 1;
}

extern "C" int func_001CC2D8(S001CC2D8* p) {
    func_0029F500(p->unk14, *p->unk0 * 1000);
    return 1;
}

INCLUDE_ASM("asm/nonmatchings/game/t_1CBB50", func_001CC310);

extern "C" int func_001CC330(char* p) {
    char* g = D_00369A60[0];
    int* q = *(int**)p;
    *(int*)(p + 0x224) = 1;
    int r = func_001CA4E8(g, *(int*)(p + 0x14));
    if (r != 0) {
        func_001CC100(r, *q);
    }
    return 1;
}

INCLUDE_ASM("asm/nonmatchings/game/t_1CBB50", func_001CC388);

struct Ctx1CC {
    int pad0;
    int unk4;
    u8* unk8;

    Ctx1CC() {
        unk8 = D_0034AC90;
        unk4 = 0;
    }
    ~Ctx1CC() {
        unk8 = D_0034AC90;
    }
};

struct Rec1CC {
    u8 b0;
    u8 b1;
    u8 b2;
    u8 b3;
    u8 b4;
    u8 b5;
    u8 b6;
    u8 b7;
    char n8[0x10];
    char n18[0x20];
    char n38[0x20];
    s8 b58;
    char pad59[3];
    s32 unk5C;
};

struct A1CC {
    s32* unk0;
    char pad4[4];
    s64 unk8;
    char padC[8];
    char* unk14;
};

extern "C" {
void func_0030ADA0(char*, char*, int);
int strcmp(const char*, const char*);
int func_001C94C0(char*);
s32 func_0029FDA8(s32, u32);
void func_0027D188(s32, u32, char**, int);
s32 func_001CA010(char*);
s8 func_001CA048(char*);
s8 func_001C94F0(char*);
s8 func_001CA120(char*);
s8 func_001C9668(char*);
char* func_001C9780(char*, u8);
s8 func_001C9458(char*);
char* func_001C97E0(char*);
S001CC090* func_001CA6D0(char*, Ctx1CC*, int);
S001CC090* func_001CA458(char*, Ctx1CC*, int);
void func_0029D2A0(s32, int, int, Rec1CC*, s32, u16, int);
void func_0030B550_3(char*, char*, char*) __asm__("func_0030B550");
extern char D_0036CF40[];
extern char D_0036CF88[];
}

extern "C" s32 func_001CC400(A1CC* a) {
    Ctx1CC ctx;
    Rec1CC rec;
    char ents[8][0x10];
    char buf[0x10];
    char* name;
    if (a->unk8 != 4) return 4;
    char* o = D_00369A60[0];
    if (func_001C94C0(o)) return 4;
    VE1CC* e = (VE1CC*)(*(char**)(o + 0xEE00) + 0x100);
    func_0027D188(func_0029FDA8(((s32 (*)(char*))e->fn)(o + e->delta), 0x2A5CF019), 0x96875C0F, &name, 1);
    s32* q = a->unk0;
    func_0030ADA0(buf, name, 0xF);
    buf[0xF] = 0;
    s32 t = func_001CA010(o);
    e = (VE1CC*)(*(char**)(o + 0xEE00) + 0xC0);
    rec.b58 = ((s32 (*)(char*))e->fn)(o + e->delta);
    rec.b0 = func_001CA048(o);
    rec.b1 = func_001C94F0(o);
    rec.b2 = func_001CA120(o);
    rec.b3 = func_001C9668(o);
    if ((s8)rec.b1 < (s8)rec.b0) rec.b1 = rec.b0;
    if ((s8)rec.b3 < (s8)rec.b2) rec.b3 = rec.b2;
    if (strcmp(func_001C9780(o, rec.b0), D_0036CF40) == 0) rec.b4 = 0;
    else rec.b4 = 1;
    e = (VE1CC*)(*(char**)(o + 0xEE00) + 0x98);
    if (((s32 (*)(char*))e->fn)(o + e->delta)) rec.b5 = 0;
    else rec.b5 = 1;
    rec.b6 = func_001C9458(o);
    rec.b7 = 0;
    func_001C94C0(o);
    func_0030ADA0(rec.n8, buf, 0xF);
    rec.n8[0xF] = 0;
    e = (VE1CC*)(*(char**)(o + 0xEE00) + 0x90);
    func_0030B550_3(rec.n18, D_0036CF88, (char*)((s32 (*)(char*, int))e->fn)(o + e->delta, 1));
    func_0030B550_3(rec.n38, D_0036CF88, func_001C97E0(o));
    rec.unk5C = *q;
    S001CC090* v = func_001CA6D0(o, &ctx, 1);
    if (v) {
        char* pe = ents[0];
        char* pt = &ents[0][0xF];
        do {
            if (!func_001CC0B0(v) || func_001CC198(v)) {
                func_0030ADA0(pe, (char*)v + 0x28, 0xF);
                pe += 0x10;
                *pt = 0;
                pt += 0x10;
            }
            v = func_001CA458(o, &ctx, 1);
        } while (v);
    }
    e = (VE1CC*)(*(char**)(o + 0xEE00) + 0x130);
    ((void (*)(char*, char*))e->fn)(o + e->delta, ents[0]);
    func_0029D2A0(t, 0x10, 0xE0, &rec, *(s32*)(a->unk14 + 0x3128), *(u16*)(a->unk14 + 0x312C), 0);
    return 1;
}

INCLUDE_ASM("asm/nonmatchings/game/t_1CBB50", func_001CC748);

extern "C" void func_001CC9E8(char* p) {
    char* o = *(char**)(p + 0x1C);
    VE1CC* e = (VE1CC*)(*(char**)(o + 0xEE00) + 0x1C0);
    ((void (*)(char*, char*))e->fn)(o + e->delta, p);
}

extern "C" void func_001CCA20(char* p) {
    char* o = *(char**)(p + 0x1C);
    VE1CC* e = (VE1CC*)(*(char**)(o + 0xEE00) + 0x1C8);
    ((void (*)(char*, char*))e->fn)(o + e->delta, p);
}

extern "C" void func_001CCA58(char* p) {
    char* o = *(char**)(p + 0x1C);
    VE1CC* e = (VE1CC*)(*(char**)(o + 0xEE00) + 0x1D0);
    ((void (*)(char*, char*))e->fn)(o + e->delta, p);
}

extern "C" int func_001CCA90(char* p) {
    char* o = *(char**)(p + 0x1C);
    s32 g = D_00370EE0;
    VE1CC* e = (VE1CC*)(*(char**)(o + 0xEE00) + 0x150);
    ((void (*)(char*, int))e->fn)(o + e->delta, 1);
    if (func_0029D8C8(*(s32*)(p + 0x10)) == 0) {
        func_00114958(g + 8, *(s32*)(o + 4));
    }
    return 1;
}

extern "C" int func_001CCB10(char* p) {
    char* o = *(char**)(p + 0x1C);
    CFunc_ExitSurveyorMode(0, 0);
    VE1CC* e = (VE1CC*)(*(char**)(o + 0xEE00) + 0xE8);
    ((void (*)(char*))e->fn)(o + e->delta);
    return 1;
}

extern "C" int func_001CCB60(void) {
    int r = func_0027AA70(func_001287F0(8, 1));
    func_0027C448(r, 0xC44777F3, 0xDDE5676F);
    func_0027C448(r, 0xF6694E96, 0);
    func_0028C9D0(0x92528E98, r, 0, 0, 0, 0);
    if (r != 0) {
        func_0027AC90(r);
        func_00113250(r);
    }
    return 1;
}

extern "C" s32 func_001CCC00(char** pp) {
    char* t = pp[0];
    char* o = pp[7];
    u32 k;
    switch (*(s8*)t) {
    case 4:
        k = 0xE5A65DEC;
        break;
    case 0:
        k = 0x7782B5B7;
        break;
    case 5:
        k = 0xDDE5676F;
        break;
    case 1:
        if (func_001CB558(o) == 4 || func_001CB558(o) == 3) {
            k = 0x3104C1F1;
            break;
        }
        func_00119490((char*)D_00368A38[0], *(int*)((char*)D_00368A38[0] + 0x1E8));
        func_0028C9D0(0x7721B33A, 0, 0, 0, 0, 0);
        func_00113FB8(*(int*)(o + 0x1C));
        func_001194B8((char*)D_00368A38[0]);
        return 1;
    case 3:
        func_0028C9D0(0x89E9B82D, 0, 0, 0, 0, 0);
        func_00113FB8(*(int*)(o + 0x1C));
        return 1;
    case 6:
        k = 0x922B12AD;
        break;
    case 7:
        k = 0x2AB1E499;
        break;
    default:
        k = 0xBA9CB8E8;
        break;
    }
    *(u32*)(o + 0xB0) = k;
    func_001C9DE0(o);
    func_001CB550(o, 8);
    return 3;
}

extern "C" void func_001CCD50(char* p) {
    char* o = *(char**)(p + 0x1C);
    VE1CC* e = (VE1CC*)(*(char**)(o + 0xEE00) + 0x1D8);
    ((void (*)(char*, char*))e->fn)(o + e->delta, p);
}

extern "C" int func_001CCD88(S001CC2D8* p) {
    if (func_0029F5B8(p->unk14) != 0) {
        func_0029F090(p->unk14);
    }
    return 1;
}

extern "C" void func_001CCDC8(char* p) {
    char* o = *(char**)(p + 0x1C);
    VE1CC* e = (VE1CC*)(*(char**)(o + 0xEE00) + 0x1E0);
    ((void (*)(char*, char*))e->fn)(o + e->delta, p);
}

extern "C" int func_001CCE00(void) {
    return 1;
}

INCLUDE_ASM("asm/nonmatchings/game/t_1CBB50", func_001CCE08);

extern "C" int func_001CD058(s8** p) {
    s8* q = *p;
    char buf[0x100];
    int r = func_0027AA70(func_001287F0(8, 1));
    func_0030B550(buf, D_0034B2F0, *q + 2, (char*)q + 1, (char*)q + 0x11);
    func_0027C028(r, 0xC4745838, buf);
    func_0028C9D0(0xCCB19938, r, 0, 0, 0, 0);
    if (r != 0) {
        func_0027AC90(r);
        func_00113250(r);
    }
    return 1;
}

extern "C" int func_001CD108(char** p) {
    char* o = *p;
    func_001CB200(D_00369A60[0], 0, *(int*)(o + 4), o + 0xC, o + 0x1C, 0, 0, 0, *(int*)(o + 8));
    return 1;
}

extern "C" void func_001CD158(int a) {
    char* o = D_00369A60[0];
    VE1CC* e = (VE1CC*)(*(char**)(o + 0xEE00) + 0x1E8);
    ((void (*)(char*, int))e->fn)(o + e->delta, a);
}

extern "C" void func_001CD198(int a) {
    char* o = D_00369A60[0];
    VE1CC* e = (VE1CC*)(*(char**)(o + 0xEE00) + 0x1F0);
    ((void (*)(char*, int))e->fn)(o + e->delta, a);
}

INCLUDE_ASM("asm/nonmatchings/game/t_1CBB50", func_001CD1D8);

extern "C" int func_001CD1F0(void) {
    return 1;
}

INCLUDE_ASM("asm/nonmatchings/game/t_1CBB50", func_001CD1F8);

extern "C" void func_001CD2A0(void) {
}

INCLUDE_ASM("asm/nonmatchings/game/t_1CBB50", func_001CD2A8);

extern "C" s32 func_001CD2B8(S001CBD30* p) {
    return p->unkE0;
}

INCLUDE_ASM("asm/nonmatchings/game/t_1CBB50", func_001CD2C0);

GP_DATA(D_0036D020);
GP_DATA(D_0036D024);
extern "C" int func_001CD2C8(int a) {
    if (D_0036D020 == 0 && a != 0) {
        D_0036D020 = func_001CD360(func_00113DF0(0x17C, 0, 1));
    }
    D_0036D024 += 1;
    return D_0036D020;
}

extern "C" void func_001CD318(void) {
    if ((u32)D_0036D024 >= 2U) {
        D_0036D024 -= 1;
        return;
    }
    if (D_0036D020 != 0) {
        func_001CD470(D_0036D020, 3);
    }
    D_0036D020 = 0;
    D_0036D024 = 0;
}

INCLUDE_ASM("asm/nonmatchings/game/t_1CBB50", func_001CD360);

INCLUDE_ASM("asm/nonmatchings/game/t_1CBB50", func_001CD470);

INCLUDE_ASM("asm/nonmatchings/game/t_1CBB50", func_001CD500);

INCLUDE_ASM("asm/nonmatchings/game/t_1CBB50", func_001CD5C0);

extern "C" void func_001CD640(S001CD640* p, s32 i) {
    if (p[i].unk8 != 0) {
        func_001184C0(p[i].unk8);
    }
}

extern "C" void func_001CD678(S001CD640* p, s32 i) {
    if (p[i].unk8 != 0) {
        func_00118570(p[i].unk8);
    }
}

extern "C" void func_001CD6B0(S001CD6B0* p, s32 v) {
    p->unk168 = v;
}

extern "C" s32 func_001CD6B8(S001CD6B0* p) {
    return p->unk168;
}

extern "C" s32 func_001CD6C0(S001CD6B0* p, s32 i) {
    return p->unk174[i];
}

extern "C" void func_001CD6D0(S001CD6B0* p, s32 i, s32 v) {
    p->unk174[i] = v;
}

extern "C" void func_001CD6E0_d(s32 a, s32 b) __asm__("func_001CD6E0");
extern "C" void func_001CD6E0_d(s32 a, s32 b) {
    if (b == 0xFFFF && a != 0) {
        int* p = D_0038E3A0;
        *p = 0;
        *++p = 0xBC6B118F;
        *++p = 0xE3006FC4;
        *++p = 0x85981897;
        *++p = 0x4B358AEB;
        *++p = 0xB7231A95;
        *++p = 0xA50950C5;
        *++p = 0xD8847EFA;
        *++p = 0x786B8B68;
        *++p = 0x2B489A86;
        *++p = 0x321C9756;
        *++p = 0x7323E97C;
        *++p = 0x20689278;
        *++p = 0x26B0C991;
        *++p = 0xBFB9982B;
        *++p = 0xC8BEA8BD;
        *++p = 0xF2F1F64E;
        *++p = 0x6BF8A7F4;
        *++p = 0x1CFF9762;
        *++p = 0xCB53A789;
        *++p = 0x9758A9C3;
        *++p = 0xF1C0DE90;
        *++p = 0xD525478E;
        *++p = 0x8A659F8F;
        *++p = 0x5856EF3A;
        *++p = 0xF57BCEC8;
        *++p = 0xB0912558;
        *++p = 0xBB5C10C9;
        *++p = 0x3224B0E6;
        *++p = 0x54BCC7B5;
        *++p = 0x9E84EFD0;
        *++p = 0x6FD42D4;
        *++p = 0xA463FF9B;
        *++p = 0x545668A6;
        *++p = 0x1A3A44A1;
        *++p = 0x767A45D7;
        *++p = 0xBD30325B;
        *++p = 0xB40D153F;
        *++p = 0x9D2D8850;
        *++p = 0x6AE9700F;
        *++p = 0xE23670C3;
        *++p = 0x84AE0790;
        *++p = 0xD5502957;
        *++p = 0xFFE1765D;
        *++p = 0x83D87F28;
        *++p = 0xE540087B;
        *++p = 0xE2E9FCA8;
        *++p = 0x5775A6C1;
        *++p = 0xC9EF9394;
    }
}

extern "C" void func_001CDA00(void* p) {
    func_00113F38(p);
}

extern "C" void func_001CDA20(S001CC050* p) {
    p->unk1C();
}

extern "C" void func_001CDA40(void) {
    func_001CD6E0(1, 0xFFFF);
}

INCLUDE_ASM("asm/nonmatchings/game/t_1CBB50", func_001CDA60);
