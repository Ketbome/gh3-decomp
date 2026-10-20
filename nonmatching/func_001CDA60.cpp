// cflags: -funroll-loops
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

INCLUDE_ASM("asm/nonmatchings/game/t_1CBB50", func_001CC400);

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

struct R1CDA {
    char pad0[1];
    s8 unk1;
    u8 d[0x24];
    char pad26[2];
    u32 unk28;
};

struct D1CDA {
    char pad0[0x1C];
    s32 unk1C;
    char pad20[4];
    u8 in[0x24];
    char pad48[0x5C];
    u16 h[4];
    char padAC[0x2C];
    s32 unkD8;
    s32 unkDC;
    char padE0[0x14];
    s32 unkF4;
};

struct T1CDA {
    s32 unk0;
    u8 b[0x24];
    char pad25[0xB];
    s32 unk30;
    u32 unk34;
    u32 unk38;
    u32 unk3C;
    u32 unk40;
    u32 unk44;
    u32 unk48;
    s32 unk4C;
};

struct P1CDA {
    D1CDA* unk0;
    char pad4[0x4C];
    T1CDA t;
};

extern "C" {
void func_001148F8_c(void*, s32) __asm__("func_001148F8");
void func_00116638_c(void*, s32) __asm__("func_00116638");
void func_001C4200(s32, s32, s32);
s32 func_001CD6B8_g(s32) __asm__("func_001CD6B8");
void func_001CE0A8(void*);
void func_001CE410(void*);
void func_001CE4C8(void*);
void func_001CE5A0(void*);
void func_001CE670(void*);
void* func_0030A2F4_c(void*, void*, s32) __asm__("func_0030A2F4");
extern s32 D_00368750;
extern s32 D_003719F0;
extern s32 D_003719F4;
extern s32 D_003719F8;
extern s32 D_003719FC;
extern s32 D_00372D78[];
extern s32 D_00372D80[];
extern s32 D_00372D88[];
}

OBJECT_END();
#define W(o) (*(s32*)(P + (o)))
#define U(o) (*(u32*)(P + (o)))
#define B(o) (*(u8*)(P + (o)))
extern "C" void func_001CDA60(char* P) {
    char* r = *(char**)(P + 0xA0);
    if (r != 0 && r[1] != 0) {
        u32 a = U(0x94);
        s32 i = 0;
        u8* b = (u8*)P + 0x51;
        U(0x98) = a;
        u32 c = *(u32*)(r + 0x28);
        u32 x = a ^ c;
        U(0x88) = x & c;
        U(0x8C) = x & ~c;
        U(0x94) = c;
        U(0x90) = x;
        U(0x84) = c;
        do {
            b[i] = (*(u8**)(P + 0xA0))[i + 2];
            i++;
        } while (i < 0x24);
        func_001148F8_c(P + 4, 0);
        *(char**)(P + 0xA0) += 0x2C;
    } else {
        char* d = *(char**)P;
        char* t;
        s32 type;
        if (d != 0) {
            if (*(s32*)(d + 0x1C) != 0) {
                u8* in = (u8*)d + 0x24;
                char* r2 = *(char**)(P + 0xA8);
                u16* hp = (u16*)(d + 0xA4);
                s32 g = D_0036D020;
                t = P + 0x50;
                s32 flags = *(s32*)(d + 0xD8);
                if (r2 != 0) {
                    r2[1] = 0;
                }
                if (((u8*)d)[0x24] == 0) {
                    u32 old = *(u32*)(t + 0x44);
                    type = (u8)(*(char**)P)[0xC];
                    *(u32*)(t + 0x48) = old;
                    u32 v = ((in[2] << 8) | in[3]) ^ 0xFFFF;
                    *(u32*)(t + 0x44) = v;
                    v |= in[0x14] << 16;
                    u32 xx = old ^ v;
                    *(u32*)(t + 0x38) = xx & v;
                    *(u32*)(t + 0x3C) = xx & ~v;
                    *(u32*)(t + 0x44) = v;
                    *(u32*)(t + 0x40) = xx;
                    *(u32*)(t + 0x34) = v;
                    if (type == 6) {
                        goto join;
                    }
                    if (type < 7) {
                        if (type == 4) {
                            goto c4;
                        }
                        if (type > 4) {
                            goto c5;
                        }
                        goto join;
                    }
                    if (type == 0x100) {
                        goto join;
                    }
                    if (type >= 0x101) {
                        goto join;
                    }
                    if (type >= 9) {
                        goto join;
                    }
                    goto dflt;
                c4:
                    func_001CE670(t);
                    goto join;
                c5:
                    t[1] = in[4];
                    t[2] = in[5];
                    t[3] = in[6];
                    t[4] = in[7];
                    func_001CE670(t);
                    if (func_001CD6B8_g(g) != 0) {
                        func_001CE410(t);
                    }
                    func_001CE5A0(t);
                    func_001CE4C8(t);
                    goto join;
                dflt: {
                    u8 e;
                    if (*(s32*)(*(char**)P + 0xDC) == 1) {
                        func_0030A2F4_c(t + 1, in + 4, 0x24);
                        e = in[0x15];
                    } else {
                        t[1] = in[4];
                        t[2] = in[5];
                        t[3] = in[6];
                        t[4] = in[7];
                        func_001CE670(t);
                        func_001CE0A8(t);
                        if (func_001CD6B8_g(g) != 0 && *(s32*)(t + 0x4C) != 0 && type != 8) {
                            func_001CE410(t);
                        }
                        func_001CE5A0(t);
                        func_001CE4C8(t);
                        e = in[0x15];
                    }
                    t[0x23] = e;
                    t[0x24] = in[0x16];
                    if ((flags & 8) != 0) {
                        *(s32*)(t + 0x30) = 1;
                        *(u16*)(t + 0x26) = hp[0];
                        *(u16*)(t + 0x28) = hp[1];
                        *(u16*)(t + 0x2A) = hp[2];
                        *(u16*)(t + 0x2C) = hp[3];
                    } else {
                        *(s32*)(t + 0x30) = 0;
                    }
                }
                join:;
                } else {
                    return;
                }
            } else {
                return;
            }
        } else {
            return;
        }
        char* q = *(char**)(P + 0xA8);
        if (q != 0) {
            u8* sb = (u8*)t + 1;
            *(u32*)(q + 0x28) = *(u32*)(t + 0x44);
            (*(char**)(P + 0xA8))[1] = 1;
            s32 i = 0;
            do {
                (*(u8**)(P + 0xA8))[i + 2] = sb[i];
                i++;
            } while (i < 0x24);
            *(char**)(P + 0xA8) += 0x2C;
        }
        if (*(char**)P != 0) {
            D_00372D78[(*(s32**)P)[0xF4 / 4]] = W(0x84);
            D_00372D88[(*(s32**)P)[0xF4 / 4]] = W(0x88);
            D_00372D80[(*(s32**)P)[0xF4 / 4]] = W(0x8C);
            func_001C4200(W(0x84), W(0x88), W(0x8C));
            if (D_00368750 != 0) {
                s32 f = 0;
                if (W(0x84) == 0) {
                    if ((*(u32*)t & 0xFFFFFF00) != 0x80808000 || (u8)t[4] != 0x80) {
                        D_003719F8 = D_003719F4;
                    }
                } else {
                    D_003719F8 = D_003719F4;
                }
                if ((*(s32**)P)[0xF4 / 4] == 0) {
                    if (D_003719F8 != 0) {
                        D_003719F8 -= 1;
                        if (D_003719F8 == 0) {
                            D_003719F0 = 2;
                            f = 1;
                        }
                    }
                    if (D_003719FC != 0) {
                        D_003719FC -= 1;
                        if (D_003719FC == 0) {
                            D_003719F0 = 3;
                            f = 1;
                        }
                    }
                }
                if ((W(0x84) & 0x900) == 0x900) {
                    f = 1;
                    D_003719F0 = 5;
                }
                if (f != 0) {
                    func_00116638_c(P + 4, f);
                }
            }
        }
        func_001148F8_c(P + 4, 0);
    }
}
