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
void func_00296AF0(void* p);
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
}

extern "C" void func_001C9B30(S001C9B30* p) {
    char* t = D_00370EE0;
    D_00372D6C = func_0011EF10();
    func_00114958(t + 8, p->unk30);
}

INCLUDE_ASM("asm/nonmatchings/game/t_1C9B30", func_001C9B70);

INCLUDE_ASM("asm/nonmatchings/game/t_1C9B30", func_001C9DD8);

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

INCLUDE_ASM("asm/nonmatchings/game/t_1C9B30", func_001CA048);

INCLUDE_ASM("asm/nonmatchings/game/t_1C9B30", func_001CA120);

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

INCLUDE_ASM("asm/nonmatchings/game/t_1C9B30", func_001CA4E8);

INCLUDE_ASM("asm/nonmatchings/game/t_1C9B30", func_001CA590);

extern "C" void func_001CA670(S001C9FB0* p) {
    if (p->unk81B4 != 0) {
        s32 t[1];
        t[0] = func_0011EF10();
        func_0029D2A0(p->unk81B4, 0x11, 4, t, -1, 0x141E, 0);
    }
}

INCLUDE_ASM("asm/nonmatchings/game/t_1C9B30", func_001CA6D0);

INCLUDE_ASM("asm/nonmatchings/game/t_1C9B30", func_001CA768);

INCLUDE_ASM("asm/nonmatchings/game/t_1C9B30", func_001CA808);

INCLUDE_ASM("asm/nonmatchings/game/t_1C9B30", func_001CA898);

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

INCLUDE_ASM("asm/nonmatchings/game/t_1C9B30", func_001CB0A0);

INCLUDE_ASM("asm/nonmatchings/game/t_1C9B30", func_001CB180);

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
