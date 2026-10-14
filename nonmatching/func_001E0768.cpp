#include "common.h"

struct S1DE9A8 {
    char pad0[0x14];
    s32 unk14;
    s32 unk18;
    s32 unk1C;
    f32 unk20;
};

struct VE1E01 {
    s16 delta;
    s16 pad;
    void (*fn)(char*);
};

extern "C" {
s32 func_0027DD88(s32 p, u32 key);
s32 func_001D5CB0_i(s32 p, s32 a, s32 b, s32 c, u32 key, s32 d, s32 e) __asm__("func_001D5CB0");
void* func_001D6738(void* p, s32 a);
void func_001CEDE0(void* p, u32 key);
void func_001D1910(void* p, void* q, s32 a);
void func_001D54D8(void* p);
void func_001E04D8(s32 self, s32 params);
void func_001D67C8(void* p, void* q);
void* func_001D10A8(void* p);
void* operator_new(u32 size);
s32 func_001D1CF8(void* p, u32 key);
void func_001F1E10(s32 p);
void func_001DE7C8(void* p, s32 a);
void func_001E2770(void* p);
extern f32 D_0032C3B8[];
extern s32 D_0036D410[] __attribute__((section(".sdata")));
extern s32 D_0036D3B0[] __attribute__((section(".sdata")));
void* func_001D5BA0(s32 p, u32 key, s32 q);
s32 func_002764E8(u32 key, s32 v);
void func_001D5CB0(s32 p, s32 a, void* b, s32 c, u32 key, s32 d, s32 e);
void func_001D4480(s32 p, s32 a, void* b, s32 c);
void* func_001D4480_p(s32 p, s32 a, s32 b, s32 c) __asm__("func_001D4480");
void func_001DFD28(void* p, s32 a);
s32 func_0027DF00(s32 p, u32 key);
s32 func_0027D870(s32 p, u32 key, s32* out, s32 d);
void func_001DFFB0(s32 p);
void func_001E0198(u32 a, s32 p);
void func_001E02F8(s32 p);
s32 func_0027D400(s32 p, u32 key, s32* out, s32 d);
s32 func_0027D1F8(s32 p, u32 key, s32* out, s32 d);
void func_001D0330(s32 self, s32 a, s32 b);
s32 func_00223BF0(s32 p);
s32 func_0027AA70(s32 a);
s32 func_001287F0(s32 a, s32 b);
void func_0027C448(s32 a, u32 k, s32 v);
void func_0027C160(s32 a, u32 k, s32 v);
void func_0028C9D0(u32 a, s32 b, s32 c, s32 d, s32 e, s32 f);
void func_0027AC90(void* p);
void func_00113250(void* p);
s32 func_00275570(void);
extern s32 D_00370F40;
void func_001E0BC8(void* p);
extern char D_0034CAB8[];
}

INCLUDE_ASM("asm/nonmatchings/game/t_1DE968", func_001DE968);

extern "C" s32 func_001DE970(s32* p) {
    s32 v = p[2];
    return D_00370F40 + func_00275570() - v;
}

extern "C" void func_001DE9A8(S1DE9A8* p) {
    p->unk14 = 0;
}

extern "C" void func_001DE9B0(S1DE9A8* p) {
    p->unk18 = 0;
}

extern "C" void func_001DE9B8(S1DE9A8* p, s32 v) {
    p->unk1C = v;
}

extern "C" void func_001DE9C0(S1DE9A8* p, f32 v) {
    p->unk20 = v;
}

INCLUDE_ASM("asm/nonmatchings/game/t_1DE968", func_001DE9C8);

INCLUDE_ASM("asm/nonmatchings/game/t_1DE968", func_001DEC40);

INCLUDE_ASM("asm/nonmatchings/game/t_1DE968", func_001DF390);

INCLUDE_ASM("asm/nonmatchings/game/t_1DE968", func_001DF538);

extern "C" f32 func_001DF6E8(s32 a, s32 b, s32 c, s32 d) {
    return D_0032C3B8[a + b * 2 + c * 4 + d * 8];
}

extern "C" void func_001DF718(char* p) {
    func_001DE7C8(p + 0x4, 0);
    func_001DE7C8(p + 0x28, 0);
    func_001DE7C8(p + 0x4C, 0);
    func_001DE7C8(p + 0x70, 0);
    func_001DE7C8(p + 0x94, 0);
    func_001DE7C8(p + 0xB8, 0);
    func_001DE7C8(p + 0xDC, 0);
    func_001DE7C8(p + 0x100, 0);
    func_001DE7C8(p + 0x124, 0);
    func_001DE7C8(p + 0x148, 0);
    func_001DE7C8(p + 0x190, 0);
    func_001DE7C8(p + 0x16C, 0);
    func_001DE7C8(p + 0x1D8, 0);
    func_001DE7C8(p + 0x1B4, 0);
    func_001DE7C8(p + 0x1FC, 0);
    func_001DE7C8(p + 0x220, 0);
    func_001DE7C8(p + 0x244, 0);
    func_001DE7C8(p + 0x268, 0);
    func_001DE7C8(p + 0x28C, 0);
    func_001DE7C8(p + 0x2B0, 0);
    func_001DE7C8(p + 0x2D4, 0);
    func_001DE7C8(p + 0x2F8, 0);
    func_001DE7C8(p + 0x31C, 0);
    func_001DE7C8(p + 0x340, 0);
    *(s32*)(p + 0x364) = 0;
    *(s32*)(p + 0x368) = 0;
    *(s32*)(p + 0x36C) = 0;
    *(s32*)(p + 0x370) = 0;
    *(s32*)(p + 0x374) = 0;
    *(s32*)(p + 0x378) = 0;
    *(s32*)(p + 0x37C) = 0;
    *(s32*)(p + 0x380) = 0;
    *(s32*)(p + 0x390) = 0;
    *(s32*)(p + 0x394) = 0;
    *(s32*)(p + 0x398) = 0;
    *(s32*)(p + 0x39C) = 0;
    func_001E2770(p + 0x3A0);
}

INCLUDE_ASM("asm/nonmatchings/game/t_1DE968", func_001DF890);

extern "C" void func_001DF898(s32 p) {
    s32 g = D_0036D3B0[0];
    func_001CEDE0(func_001D4480_p(g, func_002764E8(0xDC6A59A5, 0), p, 1), 0xA0E52802);
}

extern "C" void func_001DF900(s32 p) {
    u32 v = 0;
    u32 t;
    if (func_0027DF00(p, 0x69C257E9) != 0) {
        t = 0x9EBA4BA8;
        goto set;
    }
    if ((func_0027D870(p, 0xCE05BD37, (s32*)&v, 0) ^ 1) != 0) {
        t = 0xAD1C652B;
set:
        v = t;
    }
    if (v == 0x9EBA4BA8) goto ca;
    if (v != 0xAD1C652B) goto cc;
    func_001DFFB0(p);
    return;
ca:
    func_001E02F8(p);
    return;
cc:
    func_001E0198(v, p);
}

INCLUDE_ASM("asm/nonmatchings/game/t_1DE968", func_001DF9C0);

INCLUDE_ASM("asm/nonmatchings/game/t_1DE968", func_001DFD28);

INCLUDE_ASM("asm/nonmatchings/game/t_1DE968", func_001DFFB0);

extern "C" void func_001E0198(u32 a, s32 b) {
    char* o;
    if (func_001D5BA0(D_0036D410[0], 0x3B5737A6, 0)) {
        char* t = (char*)func_001D6738(func_001D5BA0(D_0036D410[0], 0x3B5737A6, 1), 0);
        func_001CEDE0(t, 0xCDEB9229);
        o = t;
        asm("" : "+r"(o));
        func_001D1910(t, &a, b);
        VE1E01* e = (VE1E01*)(*(char**)(t + 8) + 0x50);
        e->fn(t + e->delta);
        func_001D54D8(t);
        func_001D67C8(func_001D5BA0(D_0036D410[0], 0x3B5737A6, 1), t);
    } else {
        o = (char*)func_001D10A8(operator_new(0x160));
        func_001CEDE0(o, 0xCDEB9229);
        func_001D1910(o, &a, b);
        VE1E01* e = (VE1E01*)(*(char**)(o + 8) + 0x50);
        e->fn(o + e->delta);
    }
    s32 r = func_001D1CF8(o, 0x286A8D26);
    if (r != 0) {
        func_001F1E10(r);
    }
    func_001E04D8((s32)o, b);
}

INCLUDE_ASM("asm/nonmatchings/game/t_1DE968", func_001E02F0);

extern "C" void func_001E02F8(s32 a) {
    char* o;
    if (func_001D5BA0(D_0036D410[0], 0x3B5737A6, 0) != 0) {
        s32 m = D_0036D410[0];
        o = (char*)func_001D5CB0_i(m, func_002764E8(0xABA8DD81, 1), a, 0, 0x3B5737A6, 0, 1);
        func_001DFD28(o, a);
        VE1E01* e = (VE1E01*)(*(char**)(o + 8) + 0x50);
        e->fn(o + e->delta);
        func_001D54D8(o);
        func_001D67C8(func_001D5BA0(D_0036D410[0], 0x3B5737A6, 1), o);
    } else {
        s32 m = D_0036D3B0[0];
        o = (char*)func_001D4480_p(m, func_002764E8(0xABA8DD81, 1), a, 0);
        func_001DFD28(o, a);
        VE1E01* e = (VE1E01*)(*(char**)(o + 8) + 0x50);
        e->fn(o + e->delta);
    }
    func_001E04D8((s32)o, a);
}

extern "C" void func_001E0428(void* p) {
    if (func_001D5BA0(D_0036D410[0], 0x3B5737A6, 0) != 0) {
        s32 m = D_0036D410[0];
        func_001D5CB0(m, func_002764E8(0x6003AF05, 1), p, 0, 0x3B5737A6, 1, 1);
    } else {
        s32 m = D_0036D3B0[0];
        func_001D4480(m, func_002764E8(0x6003AF05, 1), p, 1);
    }
}

extern "C" void func_001E04D8(s32 self, s32 params) {
    s32 a = 0;
    s32 b;
    s32 c;
    if (func_0027D870(params, 0x2CA8A299, &a, 0) != 0) {
        b = 0;
        func_0027D400(params, 0x7031F10C, &b, 0);
        func_001D0330(self, a, b);
    }
    if (func_0027D1F8(params, 0x99A9B716, &c, 0) != 0) {
        s32 h = func_00223BF0(params);
        s32 t = func_0027AA70(func_001287F0(8, 1));
        func_0027C448(t, 0xA1DC81F9, h);
        func_0027C160(t, 0x99A9B716, c);
        func_0028C9D0(0x413B766D, t, self, 0, 0, 0);
        if (t != 0) {
            func_0027AC90((void*)t);
            func_00113250((void*)t);
        }
    }
}

extern "C" void func_001E0600(s32 a) {
    s32 sp0;
    register u32 k1 asm("$16");
    register u32 k2 asm("$17");
    s32 t;
    func_0027D870(a, 0x984D6421, &sp0, 0);
    k1 = 0xA04D4CBA;
    if (sp0 != 0x56381AF6) {
        if (func_0027DD88(a, 0x7BB0A235) != 0) {
            k1 = 0x30670643;
            k2 = 0x3B5737A6;
        } else {
            k2 = 0x164C0E86;
        }
    } else if (func_0027DD88(a, 0x7BB0A235) != 0) {
        k1 = 0xDE235BD1;
        k2 = 0x3B5737A6;
    } else {
        k1 = 0xC7245586;
        k2 = 0x164C0E86;
    }
    t = func_002764E8(k1, 1);
    if (func_001D5BA0(D_0036D410[0], 0x3B5737A6, 0)) {
        if (func_001D5CB0_i(D_0036D410[0], t, a, 0, k2, 1, 0) == 0) {
            func_001D5CB0_i(D_0036D410[0], t, a, 0, 0x3B5737A6, 1, 0);
        }
    } else {
        func_001D4480(D_0036D3B0[0], t, (void*)a, 1);
    }
}

INCLUDE_ASM("asm/nonmatchings/game/t_1DE968", func_001E0760);

struct S1E076L {
    s32 a;
    s32 b;
    s32 c;
    void Init() {
        b = 0;
        c = 0;
    }
};

struct S1E076 {
    char pad0[8];
    char* unk8;
    char pad0C[0x84];
    s32 unk90;
    s32 unk94;
    s32 unk98;
    s32 unk9C;
    s32 unkA0;
    s32 unkA4;
    s32 unkA8;
};

extern "C" S1E076* func_001E0768(S1E076* o) {
    func_001E0BC8(o);
    o->unk90 = 0;
    o->unk94 = 0;
    S1E076L* t = (S1E076L*)&o->unk98;
    o->unk8 = D_0034CAB8;
    t->Init();
    o->unkA8 = 1;
    o->unk98 = 0;
    o->unkA4 = 0;
    return o;
}

INCLUDE_ASM("asm/nonmatchings/game/t_1DE968", func_001E07C0);

INCLUDE_ASM("asm/nonmatchings/game/t_1DE968", func_001E0878);
