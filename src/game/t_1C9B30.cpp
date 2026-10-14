#include "common.h"

struct O1CAF {
    char pad0[0xEE00];
    virtual void a0(); virtual void a1(); virtual void a2(); virtual void a3();
    virtual void a4(); virtual void a5(); virtual void a6(); virtual void a7();
    virtual s32 b0(); virtual void b1(s32 x); virtual void b2(); virtual void b3();
    virtual void b4(); virtual void b5(); virtual void b6(); virtual void b7();
    virtual void c0(s32 x); virtual void c1(); virtual void c2(); virtual void c3();
    virtual void c4(); virtual void c5(); virtual void c6(); virtual void c7();
    virtual void d0(); virtual void d1(); virtual void d2(); virtual void d3();
    virtual void d4(); virtual void d5(); virtual void d6(); virtual void d7();
    virtual void e0(); virtual void e1(); virtual void e2(); virtual void e3(u32 k, s32 x);
};

struct S001C9FB0 {
    char pad0[0x3C];
    s32 unk3C;
    s32 unk40;
    char pad44[0x78];
    s32 unkBC;
    char padC0[0x4];
    s32 unkC4;
    s32 unkC8;
    char padCC[0x81A8 - 0xCC];
    s32 unk81A8;
    s32 unk81AC[2];
    s32 unk81B4;
};

struct S001CB080 {
    char pad0[0x18];
    void* unk18;
};

struct S001C9B30 {
    char pad0[0x30];
    s32 unk30;
};

#define V8(n) virtual void n##0(); virtual void n##1(); virtual void n##2(); virtual void n##3(); \
    virtual void n##4(); virtual void n##5(); virtual void n##6(); virtual void n##7();

struct S001CB578 {
    char pad0[0xEE00];
    V8(a) V8(b) V8(c) V8(d) V8(e) V8(f)
    virtual void g0();
};

struct S001CB6D8 {
    char pad0[0x28];
    s32 unk28;
};

struct B1CA3 {
    u8 unk0;
    char pad1[0xB];
    s32 unkC;
    u8 unk10;
    char pad11[0x1F];
};

extern "C" {
void func_00113FB8(void* p);
s32 func_0011EF10(void);
void func_00114958(void* p, s32 v);
void func_00295FA8(s32 a, s32 b);
void func_0029D2A0(s32 a, s32 b, s32 c, void* d, s32 e, s32 f, s32 g);
int func_0027D000(void* params, s32 name, s32* out, s32 d);
void func_001C93B0(s32 p, s32 v);
void func_001C93C0(s32 p, s32 v);
void func_002981A0_r(s32 a, s32 b, void (*c)(void), s32 d, void* e, s32 f) __asm__("func_002981A0");
s32 func_0029D8C8(s32 a);
void func_001CCA90(void);
void func_001CCB10(void);
void func_001CCB60(void);
void func_001CCC00(void);
void func_001CCD50(void);
void func_001CC310(void);
void func_001CC330(void);
void func_001CD108(void);
void func_001CD058(void);
void func_001CCE08(void);
void func_001CCE00(void);
void func_001CC298(void);
void func_001CCD88(void);
void func_001CC2D8(void);
void func_001CD158(void);
void func_001CD198(void);
void func_00296AF0(void* p);
void func_0029FF00(s32 a);
void func_0029D730(s32 a, s32 b);
s32 func_001CB558(S001C9FB0* p);
s32 func_001CA020(S001C9FB0* p, s32 i);
s32 func_001CC0B0(void* p);
void func_0029D238(s32 a, void* b);
extern char* D_00370EE0;
extern s32 D_00372D6C;
extern s32 D_003717E0;
extern s32 D_00369A60[] __attribute__((section(".sdata")));
extern S001CB578* D_00369A60_vt[] __asm__("D_00369A60") __attribute__((section(".sdata")));
extern S001CB6D8* D_00369A60_lv[] __asm__("D_00369A60") __attribute__((section(".sdata")));
s32 func_001C8258(s32 g);
s32 func_001C94D8(s32 g);
s32 func_001C9458(s32 g);
void* func_001CA768(s32 g);
u64 func_001CC0A0(void* p);
s32 func_00114030(s32 v);
void func_001CB478(void* p);
void func_001CB180(void* p, s32 a);
void func_0028C9D0(s32 a, s32 b, s32 c, s32 d, s32 e, s32 f);
}

struct It1CA8 {
    s32 unk0;
    s32 unk4;
    void* unk8;
};

extern "C" {
extern s32 D_0034AC90[];
s32 func_001CA458(s32, It1CA8*, s32);
s32 func_001CA6D0(s32, It1CA8*, s32);
s32 func_001CC0E8(s32);
s32 func_001CC090(s32);
s32 func_001CC198(s32);
}

extern "C" void func_001C9B30(S001C9B30* p) {
    char* t = D_00370EE0;
    D_00372D6C = func_0011EF10();
    func_00114958(t + 8, p->unk30);
}

INCLUDE_ASM("asm/nonmatchings/game/t_1C9B30", func_001C9B70);

struct S1C9B7 {
    char pad0[0x81AC];
    s32 unk81AC;
};

struct S1C9B7_B {
    s32 unk0;
};

extern "C" void func_001C9B78(S1C9B7* self, S1C9B7_B* b, s32 f) {
    s32 e = (s32)b + 4;
    func_002981A0_r(e, 0x49, func_001CCA90, 2, self, 0x80);
    func_002981A0_r(e, 0x50, func_001CCB10, 2, self, 0x80);
    func_002981A0_r(e, 0x51, func_001CCB60, 2, self, 0x80);
    func_002981A0_r(e, 0x4b, func_001CCC00, 2, self, 0x80);
    func_002981A0_r(e, 0x52, func_001CCD50, 2, self, 0x80);
    func_002981A0_r(e, 0x36, func_001CC310, 2, self, 0x80);
    func_002981A0_r(e, 0x37, func_001CC330, 2, self, 0x80);
    func_002981A0_r(e, 0x47, func_001CD108, 2, self, 0x80);
    func_002981A0_r(e, 0x4f, func_001CD058, 2, 0, 0x80);
    if (f) {
        func_002981A0_r(self->unk81AC + 4, 0x4A, func_001CCE08, 0, self, 0xFF);
        func_002981A0_r(self->unk81AC + 4, 0x4A, func_001CCE00, 0, self, 0xFF);
        if (func_0029D8C8(self->unk81AC) == 0) {
            func_002981A0_r(e, 0x33, func_001CC298, 0, self, 0x80);
            func_002981A0_r(e, 0x5E, func_001CCD88, 0, self, 0x80);
        }
        func_002981A0_r(e, 0x5F, func_001CC2D8, 0, self, 0x80);
        func_002981A0_r(e, 0x59, func_001CD158, 0, self, 0x80);
        func_002981A0_r(e, 0x5B, func_001CD198, 0, self, 0x80);
    }
}

INCLUDE_ASM("asm/nonmatchings/game/t_1C9B30", func_001C9DD8);

struct VE1C9D {
    s16 delta;
    s16 pad;
    void (*fn)(char*);
};

extern "C" void func_001C9DE0(S001C9FB0* sp) {
    char* p = (char*)sp;
    char buf[0x30];
    func_00296AF0(buf);
    if (func_001CB558(sp) != 9 && func_001CB558(sp) != 7 && func_001CB558(sp) != 8) {
        s32 h = func_001CA020(sp, 0);
        buf[0] = 0xB;
        func_0029D238(h, buf);
        func_0029D730(h, 0);
        VE1C9D* e = (VE1C9D*)(*(char**)(p + 0xEE00) + 0x20);
        e->fn(p + e->delta);
        func_00113FB8(*(void**)(p + 0x1C));
        e = (VE1C9D*)(*(char**)(p + 0xEE00) + 0x240);
        e->fn(p + e->delta);
    }
}

INCLUDE_ASM("asm/nonmatchings/game/t_1C9B30", func_001C9EB8);

extern "C" void func_001C9FB0(S001C9FB0* p) {
    if (p->unk81B4 != 0) {
        func_00295FA8(D_003717E0, p->unk81B4);
        p->unk81B4 = 0;
    }
}

INCLUDE_ASM("asm/nonmatchings/game/t_1C9B30", func_001C9FF0);

extern "C" s32 func_001CA000(S001C9FB0* p) {
    return p->unkC4;
}

extern "C" s32 func_001CA008(S001C9FB0* p) {
    return p->unkC8;
}

extern "C" s32 func_001CA010(S001C9FB0* p) {
    return p->unk81A8;
}

extern "C" s32 func_001CA020(S001C9FB0* p, s32 i) {
    return p->unk81AC[i];
}

extern "C" s32 func_001CA038(S001C9FB0* p) {
    return p->unk81B4;
}

struct O1CA0 {
    char pad0[0xEE00];
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
    virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
    virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11();
    virtual void v12(); virtual void v13(); virtual s32 v14(s32 x); virtual s32 v15();
};

struct N1CA0 {
    char pad0[0x38];
    s32 unk38;
};

extern "C" s32 func_001CA048(O1CA0* o) {
    It1CA8 it;
    s32 n = 0;
    it.unk8 = D_0034AC90;
    it.unk4 = 0;
    N1CA0* r = (N1CA0*)func_001CA6D0((s32)o, &it, 1);
    if (r) {
        do {
            if (func_001CC0B0(r) == 0 || (r->unk38 & 8)) n++;
            r = (N1CA0*)func_001CA458((s32)o, &it, 1);
        } while (r);
    }
    s32 v = o->v14(-1);
    it.unk8 = D_0034AC90;
    return n + v;
}

extern "C" s32 func_001CA120(O1CA0* o) {
    It1CA8 it;
    s32 n = 0;
    it.unk8 = D_0034AC90;
    it.unk4 = 0;
    s32 r = func_001CA6D0((s32)o, &it, 1);
    if (r) {
        do {
            if (func_001CC0B0((void*)r) != 0 && func_001CC198(r) == 0 &&
                (func_001CC090(r) == 0 || func_001C9458((s32)o) == 0))
                n++;
            r = func_001CA458((s32)o, &it, 1);
        } while (r);
    }
    s32 v = o->v15();
    it.unk8 = D_0034AC90;
    return n + v;
}

INCLUDE_ASM("asm/nonmatchings/game/t_1C9B30", func_001CA210);

extern "C" void func_001CA3E8(char* p) {
    B1CA3 b;
    func_00296AF0(&b);
    if (func_001CC0B0(func_001CA768((s32)p)) == 0) {
        b.unk0 = 0x4E;
        b.unkC = 2;
        b.unk10 = 8;
        func_0029D238(*(s32*)(p + 0x81AC), &b);
    }
}

INCLUDE_ASM("asm/nonmatchings/game/t_1C9B30", func_001CA458);

struct N1CA4 {
    char pad0[0x18];
    s32 unk18;
};

extern "C" N1CA4* func_001CA4E8(s32 a, s32 k) {
    It1CA8 it;
    it.unk8 = D_0034AC90;
    it.unk4 = 0;
    N1CA4* r = (N1CA4*)func_001CA6D0(a, &it, 1);
    if (r) {
        do {
            if (r->unk18 == k) {
                it.unk8 = D_0034AC90;
                return r;
            }
            r = (N1CA4*)func_001CA458(a, &it, 1);
        } while (r);
    }
    it.unk8 = D_0034AC90;
    return 0;
}

struct V1CA5 {
    char pad0[0x2C];
    u32 unk2C;
};

struct R1CA5 {
    char pad0[0x14];
    virtual void v0(); virtual void v1(); virtual void v2();
    virtual V1CA5* v3();
};

extern "C" void* func_001CA590(s32 a, u16 k) {
    It1CA8 it;
    it.unk8 = D_0034AC90;
    it.unk4 = 0;
    R1CA5* r = (R1CA5*)func_001CA6D0(a, &it, 0);
    if (r) {
        do {
            if (r->v3() && r->v3()->unk2C == k) {
                it.unk8 = D_0034AC90;
                return r;
            }
            r = (R1CA5*)func_001CA458(a, &it, 0);
        } while (r);
    }
    it.unk8 = D_0034AC90;
    return 0;
}

extern "C" void func_001CA670(S001C9FB0* p) {
    if (p->unk81B4 != 0) {
        s32 t[1];
        t[0] = func_0011EF10();
        func_0029D2A0(p->unk81B4, 0x11, 4, t, -1, 0x141E, 0);
    }
}

INCLUDE_ASM("asm/nonmatchings/game/t_1C9B30", func_001CA6D0);

extern "C" void* func_001CA768(s32 a) {
    It1CA8 it;
    it.unk8 = D_0034AC90;
    it.unk4 = 0;
    s32 r = func_001CA6D0(a, &it, 1);
    if (r) {
        do {
            if (func_001CC090(r)) {
                it.unk8 = D_0034AC90;
                return (void*)r;
            }
            r = func_001CA458(a, &it, 1);
        } while (r);
    }
    it.unk8 = D_0034AC90;
    return 0;
}

extern "C" s32 func_001CA808(s32 a) {
    It1CA8 it;
    s32 n = 0;
    it.unk8 = D_0034AC90;
    it.unk4 = 0;
    s32 r = func_001CA6D0(a, &it, 0);
    if (r) {
        do {
            if (func_001CC0E8(r) == 0) n++;
            r = func_001CA458(a, &it, 0);
        } while (r);
    }
    it.unk8 = D_0034AC90;
    return n;
}

struct P1CA8 {
    char pad0[0x14];
    virtual void v0(); virtual void v1(); virtual void v2();
    virtual s32 v3();
};

struct O1CA8 {
    char pad0[0xEE00];
    virtual void w0(); virtual void w1(); virtual void w2(); virtual void w3(); virtual void w4(); virtual void w5(); virtual void w6(void* r, s32 k); virtual void w7(); virtual void w8(); virtual void w9(); virtual void w10(); virtual void w11(); virtual void w12(); virtual void w13(); virtual void w14(); virtual void w15(); virtual void w16(); virtual void w17(); virtual void w18(); virtual void w19(); virtual void w20(); virtual void w21(); virtual void w22(s32 x);
};

extern "C" void func_001CA898(O1CA8* o) {
    It1CA8 it;
    it.unk8 = D_0034AC90;
    it.unk4 = 0;
    P1CA8* r = (P1CA8*)func_001CA6D0((s32)o, &it, 0);
    if (r) {
        do {
            P1CA8* nx = (P1CA8*)func_001CA458((s32)o, &it, 0);
            if (func_001CC0E8((s32)r) == 0) {
                s32 v = r->v3();
                o->w6(r, 6);
                o->w22(v);
            }
            r = nx;
        } while (r);
    }
    it.unk8 = D_0034AC90;
}

extern "C" void* func_001CA998(S001C9FB0* p) {
    return &p->unk40;
}

INCLUDE_ASM("asm/nonmatchings/game/t_1C9B30", func_001CA9A0);

extern "C" void func_001CAFB0(O1CAF* o) {
    s32 r = o->b0();
    o->e3(0x1C471C60, 1);
    o->b1(r);
    o->c0(0);
    o->a7();
    func_001CB478(o);
    *(s32*)((char*)o + 0xD4) = func_0011EF10();
}

INCLUDE_ASM("asm/nonmatchings/game/t_1C9B30", func_001CB078);

extern "C" void func_001CB080(S001CB080* p) {
    func_00113FB8(p->unk18);
}

extern "C" void func_001CB0A0(char* self) {
    char* q = *(char**)(D_003717E0 + 0x20);
    switch (*(u32*)(q + 4)) {
    case 9:
        if (*(s32*)(q + 8) == 3) goto l9;
    case 0:
    case 1:
        func_001CB080((S001CB080*)self);
        func_001CB180(self, 0);
        break;
    l9:
        func_0028C9D0(*(s32*)(self + 0xEC), 0, 0, 0, 0, 0);
        func_001CB080((S001CB080*)self);
        break;
    case 5:
        func_001CB080((S001CB080*)self);
        func_0028C9D0(*(s32*)(self + 0xEC), 0, 0, 0, 0, 0);
        break;
    case 2:
        *(s32*)(q + 4) = 6;
        break;
    }
}

extern "C" void func_001CB180(void* pv, s32 a) {
    char* p = (char*)pv;
    char* t = D_00370EE0;
    s32 v = D_003717E0;
    *(s32*)(p + 0xCC) = -1;
    if (a != 0) {
        *(s32*)(p + 0xEC) = a;
    }
    func_00114958(t + 8, *(s32*)(p + 0x18));
    VE1C9D* e = (VE1C9D*)(*(char**)(p + 0xEE00) + 0x168);
    ((void (*)(char*, s32))e->fn)(p + e->delta, 2);
    func_0029FF00(v);
}

INCLUDE_ASM("asm/nonmatchings/game/t_1C9B30", func_001CB200);

INCLUDE_ASM("asm/nonmatchings/game/t_1C9B30", func_001CB478);

INCLUDE_ASM("asm/nonmatchings/game/t_1C9B30", func_001CB548);

extern "C" void func_001CB550(S001C9FB0* p, s32 v) {
    p->unkBC = v;
}

extern "C" s32 func_001CB558(S001C9FB0* p) {
    return p->unkBC;
}

extern "C" void func_001CB560(S001C9FB0* p, s32 v) {
    p->unk3C = v;
}

extern "C" s32 func_001CB568(S001C9FB0* p) {
    return p->unk3C;
}

INCLUDE_ASM("asm/nonmatchings/game/t_1C9B30", func_001CB570);

extern "C" int CFunc_MarkGameOver(void) {
    D_00369A60_vt[0]->g0();
    return 1;
}

extern "C" int CFunc_SetJoinMode(void* params) {
    s32 g = D_00369A60[0];
    s32 v = 0;
    func_0027D000(params, 0, &v, 0);
    if (v == 0) {
        func_001C93B0(g, 0);
    } else {
        func_001C93B0(g, 1);
    }
    return 1;
}

extern "C" int CFunc_SetHostMode(void* params) {
    s32 g = D_00369A60[0];
    s32 v = 0;
    func_0027D000(params, 0, &v, 0);
    func_001C93C0(g, v);
    return 1;
}

INCLUDE_ASM("asm/nonmatchings/game/t_1C9B30", CFunc_IsHost);

extern "C" s32 CFunc_ChangeLevelPending(void) {
    return func_00114030(D_00369A60_lv[0]->unk28);
}

extern "C" void func_001CB708(char* p) {
    func_00114958(D_00370EE0 + 8, *(s32*)(p + 0x14));
    *(s32*)(p + 0x81D8) = 1;
}

INCLUDE_ASM("asm/nonmatchings/game/t_1C9B30", func_001CB750);

INCLUDE_ASM("asm/nonmatchings/game/t_1C9B30", CFunc_EnterSurveyorMode);

INCLUDE_ASM("asm/nonmatchings/game/t_1C9B30", CFunc_ExitSurveyorMode);

INCLUDE_ASM("asm/nonmatchings/game/t_1C9B30", func_001CB8D8);

INCLUDE_ASM("asm/nonmatchings/game/t_1C9B30", func_001CBAE0);
