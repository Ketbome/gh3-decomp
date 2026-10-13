#include "common.h"

struct S2DF2F8_0 {
    char pad0[0xEE88];
    s32 unkEE88;
};

struct S2DF308_0 {
    char pad0[0xEE5C];
    s32 unkEE5C;
};

struct S2DF328_0 {
    char pad0[0xEE00];
    void *unkEE00;
};

struct S2DF398_0 {
    char pad0[0xC];
    void *unkC;
    void *unk10;
    void *unk14;
};

struct S2DF898_0 {
    char pad0[0x8C];
    void *unk8C;
};

struct S2DF978_0 {
    char pad0[0x8C];
    s32 unk8C;
};

struct S2DF988_0 {
    char pad0[0x9C];
    s32 unk9C;
};

struct S2DEE90_A {
    char pad0[0x1C];
    int (*unk1C)(S2DEE90_A *);
};

struct S2DF630_V {
    char pad0[0x18];
    virtual void v0();
    virtual ~S2DF630_V();
};
struct S2DF630 {
    char pad0[0xC];
    S2DF630 *unkC;
    S2DF630 *unk10;
    void *unk14;
    char pad18[0xDC];
    char *unkF4;
    char padF8[0x138];
    void *unk230;
    S2DF630_V *unk234;
};

struct S2DEEC0_V {
    char pad0[0x100];
    s16 delta;
    s16 pad102;
    int (*fn)(void *);
};
struct S2DEEC0 {
    char pad0[0xEE00];
    S2DEEC0_V *vt;
};

struct S2DFA08_H {
    char pad0[0x21C];
    int unk21C;
};

extern "C" {
void func_001CA670(void *);
void func_001CD208(void *);
void func_001CD2A0(void *);
void func_001194B8(S2DFA08_H *);
void func_00119490(S2DFA08_H *, int);
extern int D_0036CEA4;
extern int D_0036CEA0;
extern S2DFA08_H *D_00368A38_h asm("D_00368A38");
int func_0027D870(int, int, int *, int);
int func_0029FDA8(int, int);
extern char D_0034AFE8[];
extern char D_00364028[];
void func_00134748(char *, int);
void func_0027AC90(char *);
int func_001C94C0(void);
int func_001C94C0_a(void *) asm("func_001C94C0");
int func_001CA038(void *);
void func_00298448(int);
void func_001CB708(void);
void func_00114958(int, int);
extern int D_00370EE0;
void func_001C9EB8(void *);
void func_00113FB8(int);
int func_0011EF10(void);
void func_001CC0D0(void *);
extern int D_00363DB8[];
extern s32 D_00368A38[] __attribute__((section(".sdata")));
int Heap_Free(s32, void *);
}

extern "C" s32 CFunc_SendNetMessage(void) {
    return 0;
}

extern "C" s32 func_002DEE98(void) {
    return 0;
}

extern "C" void func_002DEEA0(void) {
}

extern "C" void func_002DEEA8(void) {
}

extern "C" void func_002DEEB0(void) {
}

extern "C" void func_002DEEB8(void) {
}

extern "C" int func_002DEEC0(S2DEEC0 *p) {
    int v;
    int s = func_0029FDA8(p->vt->fn((char *)p + p->vt->delta), 0x2120910C);
    v = 0;
    func_0027D870(s, 0x21902065, &v, 1);
    if (v != 0x3C6F2B1A) {
        return ((v ^ 0x46D173AB) != 0) ? 0 : 2;
    }
    return 1;
}

extern "C" int func_002DEF48(S2DEEC0 *p) {
    int v;
    int s = func_0029FDA8(p->vt->fn((char *)p + p->vt->delta), 0xAD6D5802);
    v = 0;
    func_0027D870(s, 0x21902065, &v, 1);
    if (v == 0x6FCC88B2) {
        return 0;
    }
    if (v == 0xF6C5D908) {
        return 1;
    }
    if (v == 0x81C2E99E) {
        return 2;
    }
    if (v == 0x1FA67C3D) {
        return 3;
    }
    if (v == 0x68A14CAB) {
        return 4;
    }
    if (v == 0xF1A81D11) {
        return 5;
    }
    if (v == 0x86AF2D87) {
        return 6;
    }
    if (v != 0x16103016) {
        return (v != 0x61170080) ? 9 : 8;
    }
    return 7;
}

extern "C" int func_002DF050(S2DEEC0 *p) {
    int v;
    int s = func_0029FDA8(p->vt->fn((char *)p + p->vt->delta), 0x403DA0D0);
    v = 0;
    func_0027D870(s, 0x21902065, &v, 1);
    if (v == 0x6FCC88B2) {
        return 0;
    }
    if (v == 0xF6C5D908) {
        return 1;
    }
    if (v == 0x81C2E99E) {
        return 2;
    }
    if (v != 0x1FA67C3D) {
        return (v != 0x68A14CAB) ? 2 : 4;
    }
    return 3;
}

extern "C" s32 func_002DF110(void) {
    return 0;
}

extern "C" void func_002DF118(void) {
}

extern "C" void func_002DF120(void) {
}

extern "C" void func_002DF128(void) {
}

extern "C" void func_002DF130(void) {
}

extern "C" void func_002DF138(void) {
}

extern "C" void func_002DF140(void) {
}

extern "C" void func_002DF148(void) {
}

struct S2DF150 {
    char pad0[0xEF04];
    int unkEF04;
};
extern "C" void func_002DF150(S2DF150 *p) {
    func_001C9EB8(p);
    func_00113FB8(p->unkEF04);
}

extern "C" s32 func_002DF188(void) {
    return 4;
}

extern "C" void func_002DF190(void) {
}

extern "C" void func_002DF198(void) {
}

struct S2DF1A0 {
    char pad0[0xEF04];
    int unkEF04;
};
extern "C" void func_002DF1A0(S2DF1A0 *p) {
    func_001CB708();
    func_00114958(D_00370EE0 + 8, p->unkEF04);
}

extern "C" void func_002DF1E0(void) {
}

extern "C" s32 func_002DF1E8(void) {
    return 0;
}

INCLUDE_ASM("asm/nonmatchings/game/t_2DEE90", func_002DF1F0);

extern "C" void func_002DF298(void) {
}

extern "C" void func_002DF2A0(void) {
}

extern "C" s32 func_002DF2A8(void) {
    return 0;
}

extern "C" s32 func_002DF2B0(void) {
    return 0;
}

extern "C" s32 func_002DF2B8(void) {
    return 0;
}

INCLUDE_ASM("asm/nonmatchings/game/t_2DEE90", func_002DF2C0);

extern "C" s32 func_002DF2F8(S2DF2F8_0 *arg0) {
    return arg0->unkEE88;
}

extern "C" void func_002DF308(S2DF308_0 *arg0, s32 arg1) {
    arg0->unkEE5C = arg1;
}

extern "C" s32 func_002DF318(S2DF308_0 *arg0) {
    return arg0->unkEE5C;
}

extern "C" void func_002DF328(S2DF328_0 *arg0) {
    s16 temp_6;
    void *temp_3;

    temp_3 = arg0->unkEE00;
    temp_6 = (*(s16 *)((char *)(temp_3) + 0x88));
    (*(int (**)(void *, int, s16))((char *)(temp_3) + 0x8C))((char *)arg0 + temp_6, 1, temp_6);
}

extern "C" void func_002DF360(S2DF328_0 *arg0) {
    s16 temp_6;
    void *temp_3;

    temp_3 = arg0->unkEE00;
    temp_6 = (*(s16 *)((char *)(temp_3) + 0x88));
    (*(int (**)(void *, int, s16))((char *)(temp_3) + 0x8C))((char *)arg0 + temp_6, 0, temp_6);
}

extern "C" void func_002DF398(S2DF398_0 *arg0, s32 arg1) {
    void *temp_6;

    temp_6 = arg0->unk10;
    arg0->unk14 = D_00363DB8;
    (*(void **)((char *)(temp_6) + 0xC)) = (void *) arg0->unkC;
    (*(void **)((char *)(arg0->unkC) + 0x10)) = (void *) arg0->unk10;
    arg0->unkC = arg0;
    arg0->unk10 = arg0;
    if (arg1 & 1) {
        Heap_Free(D_00368A38[0], arg0);
    }
}

extern "C" void func_002DF3F8(S2DF398_0 *arg0, s32 arg1) {
    void *temp_6;

    temp_6 = arg0->unk10;
    arg0->unk14 = D_00363DB8;
    (*(void **)((char *)(temp_6) + 0xC)) = (void *) arg0->unkC;
    (*(void **)((char *)(arg0->unkC) + 0x10)) = (void *) arg0->unk10;
    arg0->unkC = arg0;
    arg0->unk10 = arg0;
    if (arg1 & 1) {
        Heap_Free(D_00368A38[0], arg0);
    }
}

INCLUDE_ASM("asm/nonmatchings/game/t_2DEE90", func_002DF458);

extern "C" int func_002DF4A0(S2DEE90_A *p) {
    return p->unk1C(p);
}

extern "C" s32 func_002DF4C0(void) {
    return 4;
}

extern "C" s32 func_002DF4C8(void) {
    return 4;
}

extern "C" s32 func_002DF4D0(void) {
    return 4;
}

extern "C" s32 func_002DF4D8(void) {
    return 4;
}

extern "C" s32 func_002DF4E0(void) {
    return 4;
}

extern "C" s32 func_002DF4E8(void) {
    return 4;
}

extern "C" s32 func_002DF4F0(void) {
    return 4;
}

extern "C" s32 func_002DF4F8(void) {
    return 4;
}

extern "C" s32 func_002DF500(void) {
    return 4;
}

extern "C" s32 func_002DF508(void) {
    return 4;
}

extern "C" s32 func_002DF510(void) {
    return 4;
}

extern "C" s32 func_002DF518(void) {
    return 4;
}

extern "C" s32 func_002DF520(void) {
    return 4;
}

extern "C" s32 func_002DF528(void) {
    return 4;
}

extern "C" s32 func_002DF530(void) {
    return 4;
}

extern "C" s32 func_002DF538(void) {
    return 4;
}

extern "C" s32 func_002DF540(void) {
    return 4;
}

extern "C" s32 func_002DF548(void) {
    return 4;
}

extern "C" s32 func_002DF550(void) {
    return 4;
}

extern "C" s32 func_002DF558(void) {
    return 4;
}

extern "C" s32 func_002DF560(void) {
    return 4;
}

extern "C" s32 func_002DF568(void) {
    return 4;
}

extern "C" s32 func_002DF570(void) {
    return 4;
}

extern "C" s32 func_002DF578(void) {
    return 4;
}

extern "C" s32 func_002DF580(void) {
    return 4;
}

extern "C" s32 func_002DF588(void) {
    return 4;
}

extern "C" s32 func_002DF590(void) {
    return 4;
}

extern "C" s32 func_002DF598(void) {
    return 4;
}

extern "C" s32 func_002DF5A0(void) {
    return 4;
}

extern "C" s32 func_002DF5A8(void) {
    return 4;
}

extern "C" s32 func_002DF5B0(void) {
    return 4;
}

extern "C" s32 func_002DF5B8(void) {
    return 4;
}

extern "C" s32 func_002DF5C0(void) {
    return 4;
}

extern "C" s32 func_002DF5C8(void) {
    return 4;
}

extern "C" s32 func_002DF5D0(void) {
    return 4;
}

extern "C" s32 func_002DF5D8(void) {
    return 4;
}

extern "C" s32 func_002DF5E0(void) {
    return 4;
}

extern "C" s32 func_002DF5E8(void) {
    return 4;
}

extern "C" s32 func_002DF5F0(void) {
    return 4;
}

extern "C" s32 func_002DF5F8(void) {
    return 4;
}

extern "C" s32 func_002DF600(void) {
    return 4;
}

extern "C" s32 func_002DF608(void) {
    return 4;
}

extern "C" s32 func_002DF610(void) {
    return 4;
}

extern "C" s32 func_002DF618(void) {
    return 4;
}

INCLUDE_ASM("asm/nonmatchings/game/t_2DEE90", func_002DF620);

extern "C" void func_002DF630(S2DF630 *p, int b) {
    char *r = p->unkF4;
    p->unk14 = D_00364028;
    if (r) {
        func_0027AC90(r + 0x80);
        func_00134748(r + 4, 2);
        Heap_Free(D_00368A38[0], r);
    }
    if (p->unk234) {
        delete p->unk234;
    }
    if (p->unk230) {
        Heap_Free(D_00368A38[0], p->unk230);
        p->unk230 = 0;
    }
    p->unk14 = D_0034AFE8;
    int f = b & 1;
    p->unk10->unkC = p->unkC;
    p->unkC->unk10 = p->unk10;
    p->unkC = p;
    p->unk10 = p;
    if (f) {
        Heap_Free(D_00368A38[0], p);
    }
}

struct S2DF718 {
    char pad0[0x228];
    int unk228;
};
extern "C" void func_002DF718(S2DF718 *p) {
    p->unk228 = func_0011EF10();
    func_001CC0D0(p);
}

extern "C" s32 func_002DF748(void) {
    return 0;
}

INCLUDE_ASM("asm/nonmatchings/game/t_2DEE90", func_002DF750);

struct S2DF7E8_V {
    s16 delta;
    s16 index;
    void (*fn)(void *, int);
};
struct S2DF7E8_O {
    char pad0[0x18];
    S2DF7E8_V *unk18;
};
struct S2DF7E8 {
    char pad0[0x234];
    S2DF7E8_O *unk234;
};
extern "C" void func_002DF7E8(S2DF7E8 *p) {
    S2DF7E8_O *o = p->unk234;
    if (o != 0) {
        o->unk18[2].fn((char *)o + o->unk18[2].delta, 3);
    }
    p->unk234 = 0;
}

INCLUDE_ASM("asm/nonmatchings/game/t_2DEE90", func_002DF830);

INCLUDE_ASM("asm/nonmatchings/game/t_2DEE90", func_002DF880);

extern "C" s32 func_002DF898(S2DF898_0 *arg0) {
    return (*(s32 *)((char *)(arg0->unk8C) + 0x160));
}

INCLUDE_ASM("asm/nonmatchings/game/t_2DEE90", func_002DF8A8);

INCLUDE_ASM("asm/nonmatchings/game/t_2DEE90", func_002DF940);

extern "C" s32 func_002DF978(S2DF978_0 *arg0) {
    return arg0->unk8C;
}

extern "C" void func_002DF980(S2DF978_0 *arg0, s32 arg1) {
    arg0->unk8C = arg1;
}

extern "C" s32 func_002DF988(S2DF988_0 *arg0) {
    return arg0->unk9C;
}

INCLUDE_ASM("asm/nonmatchings/game/t_2DEE90", func_002DF990);

struct S2DF9B8 {
    char pad0[0x2C];
    int unk2C;
};
extern "C" void func_002DF9B8(S2DF9B8 *p) {
    if (func_001C94C0() == 0) {
        int t = func_001CA038(p);
        if (t != 0) {
            func_00298448(t + 4);
        }
        func_00113FB8(p->unk2C);
    }
}

struct S2DFA08_V {
    char pad0[0x170];
    s16 delta;
    s16 pad172;
    void (*fn)(void *);
};
struct S2DFA08 {
    char pad0[0xEE00];
    S2DFA08_V *vt;
};
extern "C" void func_002DFA08(S2DFA08 *p, int force) {
    if (force != 0 || (u32)(func_0011EF10() - D_0036CEA0) >= 0x1388) {
        D_0036CEA0 = func_0011EF10();
        D_0036CEA4 = 1;
        func_00119490(D_00368A38_h, D_00368A38_h->unk21C);
        p->vt->fn((char *)p + p->vt->delta);
        func_001CD2A0(p);
        func_001CD208(p);
        if (func_001C94C0_a(p) == 0) {
            func_001CA670(p);
        }
        func_001194B8(D_00368A38_h);
    }
}

INCLUDE_ASM("asm/nonmatchings/game/t_2DEE90", func_002DFAC0);

INCLUDE_ASM("asm/nonmatchings/game/t_2DEE90", func_002DFB48);

extern "C" s32 func_002DFB68(void) {
    return 0;
}

INCLUDE_ASM("asm/nonmatchings/game/t_2DEE90", func_002DFB70);

INCLUDE_ASM("asm/nonmatchings/game/t_2DEE90", func_002DFBF8);

INCLUDE_ASM("asm/nonmatchings/game/t_2DEE90", func_002DFE78);

INCLUDE_ASM("asm/nonmatchings/game/t_2DEE90", func_002DFEB0);

INCLUDE_ASM("asm/nonmatchings/game/t_2DEE90", func_002DFF28);

INCLUDE_ASM("asm/nonmatchings/game/t_2DEE90", func_002DFF78);

INCLUDE_ASM("asm/nonmatchings/game/t_2DEE90", func_002E00C8);

INCLUDE_ASM("asm/nonmatchings/game/t_2DEE90", func_002E0140);

INCLUDE_ASM("asm/nonmatchings/game/t_2DEE90", func_002E01E8);

INCLUDE_ASM("asm/nonmatchings/game/t_2DEE90", func_002E02D8);

INCLUDE_ASM("asm/nonmatchings/game/t_2DEE90", func_002E0718);

INCLUDE_ASM("asm/nonmatchings/game/t_2DEE90", func_002E0B60);

INCLUDE_ASM("asm/nonmatchings/game/t_2DEE90", func_002E0CD0);

INCLUDE_ASM("asm/nonmatchings/game/t_2DEE90", func_002E0DA8);
