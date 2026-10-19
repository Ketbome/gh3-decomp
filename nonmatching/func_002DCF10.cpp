#include "common.h"

struct S2DCE78_A {
    char pad0[0x1C];
    int (*unk1C)(S2DCE78_A *);
};

struct S2DCE78_B {
    char pad0[0xEE5C];
    int unkEE5C;
};

struct S2DCE78_V {
    char pad0[0xEE00];
    virtual ~S2DCE78_V();
};

struct S2DE5B8_V {
    s16 delta;
    s16 index;
    void (*fn)(void *);
};
struct S2DE4C8_V {
    s16 delta;
    s16 index;
    void (*fn)(void *, int);
};
struct S2DE5B8 {
    char pad0[0xEE00];
    S2DE5B8_V *unkEE00;
};

struct S2DD8F8 {
    int unk0;
    int unk4;
    char pad8[8];
    void *unk10;
};

struct S2DD9F0 {
    char pad0[0x20];
    float f20;
    float f24;
    float f28;
    float unk2C;
};

struct S2DD810 {
    char pad0[4];
    int unk4;
};

struct S2DE418_V {
    char pad0[0x18];
    virtual void v0();
    virtual ~S2DE418_V();
};
struct S2DE418_N {
    char pad0[0xC];
    S2DE418_N *unkC;
    S2DE418_N *unk10;
    void *unk14;
};
struct S2DE418 {
    char pad0[4];
    S2DE418_V *unk4;
    char pad8[0xEDF8];
    void *unkEE00;
    char padEE04[0x3C];
    S2DE418_N unkEE40;
};

struct S2DCE78_T {
    char pad0[0x1C];
    int unk1C;
    int unk20;
};
struct S2DCE78 {
    char pad0[0x20];
    S2DCE78_T *unk20;
};

extern "C" {
float func_002DDBB0();
int func_0027DF00(int, int);
int func_0027D058(int, int, void *, int);
void func_002DCD68(S2DCE78_T *, int);
void func_002DCF10(S2DCE78_T *, int);
extern int D_00369798;
void func_0028C9F0(int, int, int, int, int, int);
void func_00145510(int);
int func_00119610(int, int);
void func_001194B8(int);
void func_00119490(int, int);
extern char D_00363DB8[];
extern char D_00363B20[];
void func_001C8040(void *, int);
void func_0029FD40(void *, int);
void func_002BDEA8(int);
int func_002BDC48(int);
void func_0027F1E0(int, int, int);
int func_0027D870(int, int, int *, int);
int func_0027CC30(int, int, int, int *);
extern char D_00362400[];
extern int D_00368A38;
void Heap_Free(int, void *);
void func_00113250(int);
void func_0027AC90(int);
int func_001CB568(void *);
int func_001CA210(void *);
void func_001CB560(void *, int);
int func_00225F80(void);
int func_002297A8(int);
extern int D_0036F608;
void func_001CA898(void);
int func_002DD108(void);
int func_002DD288(void);
int func_002DD160(void);
long func_0011ED00(void);
extern s32 D_00372368;
extern s32 D_0037237C;
extern s32 D_00372380;
extern s32 D_00372384;
extern long D_003731E8;
extern s32 D_0037236C;
extern f32 D_00372370;
extern f32 D_00372374;
extern f32 D_00372378;
extern s32 D_00372580;
extern s32 D_00372584;
extern s32 D_00372DC8[] __attribute__((section(".sdata")));
extern s32 D_00372DF8[] __attribute__((section(".sdata")));
extern s32 D_00372E10[] __attribute__((section(".sdata")));
extern int D_0038EE10[];
extern int D_0038F1F0[];
extern int D_0038F230[];
s32 operator_new(int);
s32 func_00113DF0(int, int, int);
int func_001ECC90(s32);
int func_001F35D0(s32);
int func_001F4070(s32);
int func_00276D68(s32, void *, int);
void func_002DD738(int, int);
void func_002DDBD8(int, int);
s32 func_002DE280(s32);
}

extern "C" void func_002DCE78(S2DCE78 *p) {
    int h = D_00368A38;
    S2DCE78_T *t;
    func_00119490(h, func_00119610(h, 0x3A));
    t = p->unk20;
    func_002DCF10(t, t->unk20);
    func_002DCD68(t, t->unk1C);
    func_00145510(D_00369798);
    func_0028C9F0(0x2CF7F9CF, 0, 0, 0, 0, 0);
    func_001194B8(D_00368A38);
}

struct S2DCF_Col {
    u8 r;
    u8 g;
    u8 b;
    u8 a;
    void Set(u8 r_, u8 g_, u8 b_, u8 a_) {
        r = r_;
        g = g_;
        b = b_;
        a = a_;
    }
};

extern "C" {
void func_002EA460(void);
void func_0028CF40(void);
int func_0028D1D8(int, int, int, int, int, int, int, int, int, int);
void func_0028C200(int);
extern int D_00372228;
}

GP_DATA(D_00372228);
extern "C" void func_002DCF10(S2DCE78_T *unused, int flag) {
    S2DCF_Col c;
    c.Set(0xFF, 0xFF, 0xFF, 0xFF);
    func_002EA460();
    int h = D_00368A38;
    if (flag == 0) {
        func_00119490(h, func_00119610(h, 1));
        func_001194B8(D_00368A38);
        h = D_00368A38;
    }
    func_00119490(h, func_00119610(h, 1));
    c.Set(0xFF, 0xFF, 0xFF, 0xFF);
    func_0028C9F0(0xE8B7F73A, 0, 0, 0, 0, 0);
    c.Set(0xFF, 0xFF, 0xFF, 0xFF);
    func_0028CF40();
    c.Set(0xFF, 0xFF, 0xFF, 0xFF);
    func_0028C9F0(0xEF54EC55, 0, 0, 0, 0, 0);
    c.Set(0xFF, 0xFF, 0xFF, 0xFF);
    if (D_00372228 != 0) {
        D_00372228 = 0;
        func_0028C200(func_0028D1D8(0xFB11E6CD, 0, 0, 0, 0, 0, 0, 0, 0, 0));
    }
    func_001194B8(D_00368A38);
}

INCLUDE_ASM("asm/nonmatchings/game/t_2DCE78", func_002DD080);

extern "C" int func_002DD0B0(S2DCE78_A *p) {
    return p->unk1C(p);
}

extern "C" void func_002DD0D0(void) {
    if (func_002DD108()) {
        while (func_002DD288()) {
        }
    }
}

extern "C" int func_002DD108(void) {
    int r = 0;
    if (D_0036F608 != 0) {
        r = func_002297A8(D_0036F608);
    }
    int x = 0;
    if (r != 0 || func_00225F80() != 0) {
        x = 1;
    }
    return x;
}

GP_DATA(D_00372368);
GP_DATA(D_0037237C);
GP_DATA(D_00372380);
GP_DATA(D_00372374);
GP_DATA(D_0037236C);
GP_DATA(D_00372370);
extern "C" int func_002DD160(void) {
    if (func_002DD108() == 0) {
        D_00372368 = 0;
        D_0037237C = 0;
        D_00372380 = 0;
        D_003731E8 = func_0011ED00();
        D_00372384 = 0;
        goto no;
    }
    if (func_0011ED00() == D_003731E8) {
        return 1;
    }
    if (D_00372368 != 0) {
        if ((int)((float)(D_00372380 * D_0037236C) * D_00372374) < D_0037237C) {
            D_00372368 = 0;
        }
        if (D_00372368 != 0) goto act;
    }
    if (D_0037237C < (int)((float)(D_00372380 * D_0037236C) * D_00372370)) {
        D_00372368 = (int)((float)D_0037236C * D_00372378);
    }
    if (D_00372368 == 0) goto no;
act:
    if (D_00372384 < D_00372368) {
        D_00372384 += 1;
        return 1;
    }
no:
    return 0;
}

INCLUDE_ASM("asm/nonmatchings/game/t_2DCE78", func_002DD288);

GP_DATA(D_00372380);
GP_DATA(D_00372368);
GP_DATA(D_0037237C);
GP_DATA(D_00372384);
extern "C" int func_002DD308(int a) {
    if (a != 0) {
        D_00372380 = D_00372380 + 1;
        if (func_002DD108() == 0) {
            D_00372368 = 0;
            D_0037237C = 0;
            D_00372380 = 0;
            D_003731E8 = func_0011ED00();
            D_00372384 = 0;
            return 0;
        }
        int r = 0;
        while (func_002DD160() != 0) {
            if (func_002DD288() != 0) {
                r = 1;
                D_0037237C = D_0037237C + 1;
            }
        }
        D_003731E8 = func_0011ED00();
        D_00372384 = 0;
        return r;
    }
    D_003731E8 = func_0011ED00();
    return func_002DD288();
}

GP_DATA(D_0037236C);
GP_DATA(D_00372370);
GP_DATA(D_00372374);
extern "C" void func_002DD3C0(s32 arg0, f32 fparg0, f32 fparg1, f32 fparg2) {
    D_0037236C = arg0;
    D_00372370 = fparg0;
    D_00372374 = fparg1;
    D_00372378 = fparg2;
}

INCLUDE_ASM("asm/nonmatchings/game/t_2DCE78", func_002DD3D8);

INCLUDE_ASM("asm/nonmatchings/game/t_2DCE78", func_002DD3E0);

INCLUDE_ASM("asm/nonmatchings/game/t_2DCE78", func_002DD490);

INCLUDE_ASM("asm/nonmatchings/game/t_2DCE78", func_002DD578);

INCLUDE_ASM("asm/nonmatchings/game/t_2DCE78", func_002DD670);

extern "C" void func_002DD738(int init, int prio) {
    if (prio == 0xFFFF && init) {
        int i = 0x63;
        do {
            i -= 0x19;
        } while (i != -1);
    }
}

extern "C" void func_002DD778(void) {
    func_002DD738(1, 0xFFFF);
}

extern "C" s32 func_002DD798(void) {
    return 0;
}

INCLUDE_ASM("asm/nonmatchings/game/t_2DCE78", func_002DD7A0);

extern "C" s32 func_002DD808(void) {
    return 1;
}

extern "C" int func_002DD810(S2DD810 *p) {
    int vd;
    int vc;
    int vb;
    int va;
    int h = p->unk4;
    int s;
    int t;
    if (func_0027CC30(h, 0x51691862, 0xA, &va)) {
        s = va;
    } else {
        func_0027F1E0(h, 0, 1);
        s = 0;
    }
    func_0027D870(func_002BDC48(0x33FFBCC2), 0x33FFBCC2, &vb, 1);
    int x = vb;
    if (func_0027CC30(s, 0x33FFBCC2, 0xA, &vc)) {
        t = vc;
    } else {
        func_0027F1E0(s, 0, 1);
        t = 0;
    }
    func_0027D870(t, 0x33FFBCC2, &vd, 1);
    if (x == vd) {
        func_002BDEA8(s);
        return 1;
    }
    return 0;
}

extern "C" void func_002DD8F8(S2DD8F8 *p, int b) {
    int h = p->unk0;
    p->unk10 = D_00362400;
    if (h != 0) {
        func_0027AC90(h);
        func_00113250(h);
    }
    h = p->unk4;
    if (h != 0) {
        func_0027AC90(h);
        func_00113250(h);
    }
    if (b & 1) {
        Heap_Free(D_00368A38, p);
    }
}

extern "C" s32 func_002DD980(void) {
    return 0xDDFE0DB9 /* PROGRESS */;
}

INCLUDE_ASM("asm/nonmatchings/game/t_2DCE78", func_002DD990);

extern "C" int func_002DD9F0(S2DD9F0 *p, int a) {
    if (func_0027D058(a, 0, &p->f20, 0)) {
        p->f20 = p->f20 * p->f20;
    }
    return 1;
}

extern "C" int func_002DDA40(S2DD9F0 *p, int a) {
    if (func_0027D058(a, 0, &p->f24, 0)) {
        p->f24 = p->f24 * p->f24;
    }
    return 1;
}

extern "C" int func_002DDA90(S2DD9F0 *p, int a) {
    if (func_0027D058(a, 0, &p->f28, 0)) {
        p->f28 = p->f28 * p->f28;
    }
    return 1;
}

extern "C" int func_002DDAE0(S2DD9F0 *p, int a) {
    if (func_0027DF00(a, 0xFD2EACAD) && p->unk2C != 0.0f) {
        return 1;
    }
    if (!func_0027D058(a, 0, &p->unk2C, 0)) {
        return 1;
    }
    p->unk2C = p->unk2C * p->unk2C;
    return 1;
}

extern "C" int func_002DDB68(S2DD9F0 *p) {
    char buf[8];
    return func_002DDBB0(p, buf) <= p->unk2C;
}

INCLUDE_ASM("asm/nonmatchings/game/t_2DCE78", func_002DDBA8);

extern "C" float func_002DDBB0(void) {
    return 16899999744.0f;
}
TEXT_PAD(12);

INCLUDE_ASM("asm/nonmatchings/game/t_2DCE78", func_002DDBD0);

struct V2DDB {
    int a;
    int b;
};

struct E2DDB {
    u32 key;
    u32 type;
    V2DDB v;
};

extern E2DDB T2DDB[] __asm__("D_003E96F0");
extern V2DDB V2DDB_0[] __asm__("D_003724C0");
extern V2DDB V2DDB_1[] __asm__("D_003724C8");
extern V2DDB V2DDB_2[] __asm__("D_003724D0");
extern V2DDB V2DDB_3[] __asm__("D_003724D8");
extern V2DDB V2DDB_4[] __asm__("D_003724E0");
extern V2DDB V2DDB_5[] __asm__("D_003724E8");
extern "C" void* memset(void*, int, unsigned int);

extern "C" void func_002DDBD8(int a, int b) {
    if (b == 0xFFFF && a != 0) {
        E2DDB* e = T2DDB;
        V2DDB t;
        e->key = 0x82A0A873;
        t = *V2DDB_0;
        e->type = 0x1D5B1AE6;
        e->v = t;
        e++;
        e->key = 0x8CB5D0C0;
        t = *V2DDB_1;
        e->type = 0x1D5B1AE6;
        e->v = t;
        e++;
        e->key = 0x50F28D36;
        t = *V2DDB_2;
        e->type = 0x1D5B1AE6;
        e->v = t;
        e++;
        e->key = 0x2D703B94;
        t = *V2DDB_3;
        e->type = 0x1D5B1AE6;
        e->v = t;
        e++;
        e->key = 0x13C0D8DC;
        t = *V2DDB_4;
        e->type = 0x1D5B1AE6;
        e->v = t;
        e++;
        e->key = 0x9522F906;
        t = *V2DDB_5;
        e->type = 0x1D5B1AE6;
        e->v = t;
        e++;
        memset(&t, 0, 8);
        e->key = 0;
        e->type = 0x1D5B1AE6;
        e->v = t;
    }
}

extern "C" void func_002DDDA8(void) {
    func_002DDBD8(1, 0xFFFF);
}

INCLUDE_ASM("asm/nonmatchings/game/t_2DCE78", func_002DDDC8);

INCLUDE_ASM("asm/nonmatchings/game/t_2DCE78", func_002DE0C0);

extern "C" void func_002DE0C8(void) {
    func_001F4070(operator_new(0x160));
}

extern "C" void func_002DE0F0(void) {
    func_00276D68(D_00372E10[0], D_0038F230, 0x10);
}

extern "C" void func_002DE120(void) {
    func_001F35D0(operator_new(0xC0));
}

extern "C" void func_002DE148(void) {
    func_00276D68(D_00372DF8[0], D_0038F1F0, 0x10);
}

extern "C" void func_002DE178(void) {
    func_001ECC90(operator_new(0xA0));
}

extern "C" void func_002DE1A0(void) {
    func_00276D68(D_00372DC8[0], D_0038EE10, 0x10);
}

GP_DATA(D_00372580);
GP_DATA(D_00372584);
extern "C" s32 func_002DE1D0(s32 arg0) {
    if ((D_00372580 == 0) && (arg0 != 0)) {
        D_00372580 = func_002DE280(func_00113DF0(0x10F00, 0, 1));
    }
    D_00372584 += 1;
    return D_00372580;
}

extern "C" void func_002DE220(void) {
    if ((u32)D_00372584 >= 2) {
        D_00372584--;
    } else {
        delete (S2DCE78_V *)D_00372580;
        D_00372580 = 0;
        D_00372584 = 0;
    }
}

INCLUDE_ASM("asm/nonmatchings/game/t_2DCE78", func_002DE280);

extern "C" void func_002DE418(S2DE418 *p, int b) {
    p->unkEE00 = D_00363B20;
    if (p->unk4) {
        delete p->unk4;
    }
    func_0029FD40((char *)p + 0xF748, 2);
    S2DE418_N *n = &p->unkEE40;
    n->unk14 = D_00363DB8;
    n->unk10->unkC = n->unkC;
    n->unkC->unk10 = n->unk10;
    n->unkC = n;
    n->unk10 = n;
    func_001C8040(p, b);
}

extern "C" void func_002DE4C8(void) {
    S2DE5B8 *p = (S2DE5B8 *)D_00372580;
    if (func_001CB568(p) == 1) {
        int r = func_001CA210(p);
        S2DE4C8_V *v = (S2DE4C8_V *)p->unkEE00;
        v[28].fn((char *)p + v[28].delta, r);
        func_001CB560(p, 0);
    }
}

extern "C" void func_002DE530(void) {
}

INCLUDE_ASM("asm/nonmatchings/game/t_2DCE78", func_002DE538);

struct S2DE578_Node {
    int unk0;
    int unk4;
    char pad8[0x4];
    S2DE578_Node *unkC;
};

struct S2DE578_It {
    int unk0;
    S2DE578_Node *cur;
};

static inline S2DE578_Node *S2DE578_Valid(S2DE578_Node *n) {
    if (n->unk4 == -1) {
        return 0;
    }
    return n;
}

extern "C" int func_002DE578(int unused, S2DE578_It *it) {
    S2DE578_Node *n = S2DE578_Valid(it->cur->unkC);
    it->cur = n;
    if (n) {
        return n->unk4;
    }
    return 0;
}

INCLUDE_ASM("asm/nonmatchings/game/t_2DCE78", func_002DE5A8);

extern "C" void func_002DE5B0(void) {
}

extern "C" void func_002DE5B8(S2DE5B8 *p) {
    func_001CA898();
    p->unkEE00[72].fn((char *)p + p->unkEE00[72].delta);
}

extern "C" void func_002DE5F8(void) {
}

extern "C" void func_002DE600(void) {
}

extern "C" void func_002DE608(void) {
}

extern "C" void func_002DE610(void) {
}

extern "C" s32 func_002DE618(void) {
    return 0;
}

extern "C" void func_002DE620(void) {
}

extern "C" void func_002DE628(void) {
}

extern "C" void func_002DE630(void) {
}

INCLUDE_ASM("asm/nonmatchings/game/t_2DCE78", func_002DE638);

extern "C" s32 func_002DE700(void) {
    return 0;
}

extern "C" s32 func_002DE708(void) {
    return 0;
}

extern "C" s32 func_002DE710(void) {
    return 0;
}

extern "C" void func_002DE718(void) {
}

extern "C" void func_002DE720(void) {
}

extern "C" void func_002DE728(void) {
}

extern "C" s32 func_002DE730(void) {
    return 0;
}

INCLUDE_ASM("asm/nonmatchings/game/t_2DCE78", func_002DE738);

INCLUDE_ASM("asm/nonmatchings/game/t_2DCE78", func_002DEA78);

extern "C" void func_002DEE18(S2DCE78_B *p, int b) {
    if (b) {
        int *q = (int *)((char *)p + 0x10ED0);
        *q = 0;
    }
    p->unkEE5C = 0;
}

extern "C" s32 func_002DEE40(void) {
    return 0;
}

INCLUDE_ASM("asm/nonmatchings/game/t_2DCE78", func_002DEE48);

extern "C" s32 CFunc_StartNetworkGame(void) {
    return 0;
}
