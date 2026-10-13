#include "common.h"

struct O1D017 {
    char pad0[0x2C];
    virtual void v0();
    virtual void v1();
    virtual void v2(void* a);
    virtual void v3();
    virtual void v4();
    virtual void v5(void* a);
};

struct X1D017 {
    char pad0[0xC];
    u32 unkC;
    O1D017* unk10;
    s32 unk14;
};

struct G1D00 {
    void* o;
    s32 a;
    s32 b;
};

struct VEnt {
    s16 delta;
    s16 index;
    void* fn;
};

struct N1548 {
    char pad0[0x10];
    N1548* next;
    char pad14[4];
    char* vt;
};

struct S001D0F68 {
    char pad0[0x4];
    s32 unk4;
    VEnt* unk8;
    s32 unkC;
    s32 unk10;
    s32 unk14;
    VEnt* unk18;
};

extern "C" {
void func_001D0330_0(void) __asm__("func_001D0330");
void func_001CE7C0(void);
void func_001D12E0(void);
void func_0027D188(void* p, s32 key, void* v, s32 req);
extern s32 D_00372D90;
extern char D_0034B698[];
void func_001D09C0(s32 a, s32 b);
void func_001CEBA8(void);
void func_001DAC78(s32 a, s32 b, s32 c, s32 d, s32 e, s32 f, f32 g);
extern s32 D_0036D554;
void func_001D1548(void* p);
void func_0027D2D8(void* a, s32 key, void* v, s32 req);
void func_001D1E20(void* a, f32 b);
s32 func_0027D268(void* a, s32 key, void* v, s32 req);
s32 func_0027D870(void* a, s32 key, void* v, s32 req);
s32 func_001D1CF8(void* a, s32 b);
void Heap_Free(s32 heap, void* p);
extern s32 D_00368A38[] __attribute__((section(".sdata")));
void func_0028DBD0(void);
void func_001D0170(void* p);
void func_00289E10(s32 a, s32 b);
s32 func_0028D1D8(s32 a, s32 b, s32 c, s32 d, u32 e, s32 f, s32 g, s32 h, s32 i, s32 j);
void func_00119490(s32 a, s32 b);
void func_001194B8(s32 a);
s32 func_00119610(s32 a, s32 b);
s32 func_001287F0(s32 a, s32 b);
s32 func_0027AA70(s32 a);
s32 func_0012D028(s32 a, s32 b);
s32 func_002899D8(s32 a);
void func_0028A2A8(s32 a, s32 b, s32 c, void* d);
void func_0028A2D0(s32 a, void* b, s32 c, void* d);
void func_0028A000(s32 a);
void func_001D1998(void* p, s32 a);
void func_001D4560(s32 a, void* b, s32 c, s32 d);
void func_001CE868(void* p, void* g);
void func_001CE888(void* p, void* g);
void func_0028E010(s32 a, s32 b);
void func_00289FB0(s32 a, s32 b);
void func_0028DB28(void* p);
void func_001CE810(void* p);
}

struct S1D1F {
    char pad0[0x18];
    s32 unk18;
    s32 unk1C[1];
};

extern "C" {
extern s32 D_0036D3B0[] __attribute__((section(".sdata")));
extern S1D1F* D_0036F658[] __attribute__((section(".sdata")));
}

struct S1D14 {
    char pad0[0x10];
    S1D14* unk10;
    VEnt* unk18;
};

struct S1D14P {
    char pad0[0x14];
    s32 unk14;
    char pad18[0x138];
    S1D14* unk150;
    s32 unk154;

    bool Test(s32 m) {
        return (unk154 & m) != 0;
    }
};

extern "C" s32 func_001D00B0(char* p, s32 k) {
    if (*(s32*)(p + 0x14) == 0) {
        return 1;
    }
    G1D00 g;
    g.a = 0;
    g.b = 0;
    g.o = p;
    if (p != 0) {
        func_001CE868(p, &g);
    }
    func_0028E010(*(s32*)(p + 0x14), k);
    bool r = g.o != 0;
    if (g.o != 0) {
        func_001CE888(g.o, &g);
        g.o = 0;
    }
    return r;
}

extern "C" void func_001D0130(char* p, s32 a, s32 b) {
    s32 t = *(s32*)(p + 0x2C);
    func_001DAC78(D_0036D554, a, t, t, b, 0, -1.0f);
}

extern "C" void func_001D0170(void* pv) {
    X1D017* p = (X1D017*)pv;
    if ((p->unkC & 1) == 0) {
        if (p->unk14 != 0) {
            func_00289FB0(p->unk14, 0);
        }
        func_0028DB28(p);
        O1D017* o = p->unk10;
        p->unkC = p->unkC & 0xFFFFFFFD;
        if (o != 0) {
            o->v2(p);
            o->v5(p);
        }
        p->unkC = p->unkC | 1;
        func_001CE810((char*)p + 0x5C);
    }
}

extern "C" void func_001D0228(char* p) {
    if (*(s32*)(p + 0x28) == 0) {
        s32 h = D_00368A38[0];
        func_00119490(h, func_00119610(h, 0x3A));
        s32 r = func_0027AA70(func_001287F0(8, 1));
        s32 h2 = D_00368A38[0];
        *(s32*)(p + 0x28) = r;
        func_001194B8(h2);
    }
}

extern "C" void func_001D02A0(S1D14P* p) {
    if (p->unk14 == 0) {
        s32 h = D_00368A38[0];
        func_00119490(h, func_00119610(h, 5));
        p->unk14 = func_002899D8(func_0012D028(0x10C, 1));
        func_0028A2A8(p->unk14, 0x3F5CDB8A, 0, p);
        func_001194B8(D_00368A38[0]);
    }
}

extern "C" s32 func_001D0330(S1D14P* p, void* a, s32 b) {
    if (p->unk14 != 0) {
        func_0028A2D0(p->unk14, a, b, p);
    } else {
        s32 t = func_002899D8(func_0012D028(0x10C, 1));
        p->unk14 = t;
        func_0028A2D0(t, a, b, p);
    }
    func_0028A000(p->unk14);
    return p->unk14;
}

extern "C" void func_001D03B8(void) {
    func_001D0330_0();
}

extern "C" s32 func_001D03D8(s32 a, s32 b, s32 c, s32 d, s32 e) {
    s32 r = func_0028D1D8(b, c, 0, 0, 0xFFFFFFFF, d, 0, 0, 0, e);
    if (r != 0) {
        func_00289E10(r, a);
    }
    return r;
}

INCLUDE_ASM("asm/nonmatchings/game/t_1D00B0", func_001D0450);

INCLUDE_ASM("asm/nonmatchings/game/t_1D00B0", func_001D0518);

INCLUDE_ASM("asm/nonmatchings/game/t_1D00B0", func_001D0548);

extern "C" void func_001D0570(void) {
}

INCLUDE_ASM("asm/nonmatchings/game/t_1D00B0", func_001D0578);

INCLUDE_ASM("asm/nonmatchings/game/t_1D00B0", func_001D0680);

extern "C" s32 func_001D0788(void) {
    return D_00372D90;
}

INCLUDE_ASM("asm/nonmatchings/game/t_1D00B0", func_001D0790);

INCLUDE_ASM("asm/nonmatchings/game/t_1D00B0", func_001D0798);

INCLUDE_ASM("asm/nonmatchings/game/t_1D00B0", func_001D0848);

INCLUDE_ASM("asm/nonmatchings/game/t_1D00B0", func_001D0900);

INCLUDE_ASM("asm/nonmatchings/game/t_1D00B0", func_001D09C0);

extern "C" void func_001D0F18(void) {
    func_001CE7C0();
}

extern "C" int func_001D0F38(void) {
    return 1;
}

INCLUDE_ASM("asm/nonmatchings/game/t_1D00B0", func_001D0F40);

extern "C" S001D0F68* func_001D0F68(S001D0F68* p) {
    p->unk4 = 0;
    p->unk18 = (VEnt*)D_0034B698;
    p->unk8 = 0;
    p->unkC = 0;
    p->unk10 = 0;
    p->unk14 = 0;
    return p;
}

extern "C" void func_001D0F90(char* p, s32 flags) {
    *(void**)(p + 0x18) = D_0034B698;
    if (*(s32*)(p + 8) & 2) {
        func_0028DBD0();
    }
    if (flags & 1) {
        Heap_Free(D_00368A38[0], p);
    }
}

extern "C" void func_001D0FF0(void) {
}

extern "C" void func_001D0FF8(void) {
}

extern "C" void func_001D1000(S001D0F68* p, void* a) {
    ((void (*)(void*, void*))p->unk18[3].fn)((char*)p + p->unk18[3].delta, a);
}

extern "C" void func_001D1028(void) {
}

extern "C" int func_001D1030(void) {
    return 2;
}

extern "C" s32 func_001D1038(S001D0F68* p, s32* q, void* a, void* b) {
    return ((s32 (*)(void*, s32, void*, void*))p->unk18[12].fn)((char*)p + p->unk18[12].delta, *q, a, b);
}

extern "C" void func_001D1068(S001D0F68* p, s32 v) {
    if (v != 0) {
        p->unk8 = (VEnt*)((s32)p->unk8 | 1);
    } else {
        p->unk8 = (VEnt*)((s32)p->unk8 & ~1);
    }
}

extern "C" void func_001D1090(void) {
}

extern "C" void func_001D1098(void) {
}

extern "C" void func_001D10A0(void) {
}

INCLUDE_ASM("asm/nonmatchings/game/t_1D00B0", func_001D10A8);

INCLUDE_ASM("asm/nonmatchings/game/t_1D00B0", func_001D11B0);

extern "C" void func_001D1270(void* q) {
    S1D14P* p = (S1D14P*)q;
    if ((*(s32*)((char*)p + 0xC) & 1) == 0) {
        N1548* n = (N1548*)p->unk150;
        if (n != 0) {
            do {
                VEnt* e = (VEnt*)(n->vt + 0x28);
                ((void (*)(char*))e->fn)((char*)n + e->delta);
                n = n->next;
            } while (n != 0);
        }
        func_001D0170(p);
    }
}

INCLUDE_ASM("asm/nonmatchings/game/t_1D00B0", func_001D12E0);

extern "C" void func_001D1418(void) {
    func_001D12E0();
}

INCLUDE_ASM("asm/nonmatchings/game/t_1D00B0", func_001D1438);

INCLUDE_ASM("asm/nonmatchings/game/t_1D00B0", func_001D14C0);

extern "C" void func_001D1548(void* q) {
    S1D14P* p = (S1D14P*)q;
    N1548* n = (N1548*)p->unk150;
    if (n != 0) {
        do {
            VEnt* e = (VEnt*)(n->vt + 0x50);
            ((void (*)(char*))e->fn)((char*)n + e->delta);
            n = n->next;
        } while (n != 0);
    }
}

INCLUDE_ASM("asm/nonmatchings/game/t_1D00B0", func_001D1598);

extern "C" s32 func_001D1610(S001D0F68* p, void* a, void* b) {
    return ((s32 (*)(void*, void*, void*))p->unk8[12].fn)((char*)p + p->unk8[12].delta, a, b);
}

INCLUDE_ASM("asm/nonmatchings/game/t_1D00B0", func_001D1638);

INCLUDE_ASM("asm/nonmatchings/game/t_1D00B0", func_001D17B0);

INCLUDE_ASM("asm/nonmatchings/game/t_1D00B0", func_001D1910);

INCLUDE_ASM("asm/nonmatchings/game/t_1D00B0", func_001D1998);

INCLUDE_ASM("asm/nonmatchings/game/t_1D00B0", func_001D1B28);

INCLUDE_ASM("asm/nonmatchings/game/t_1D00B0", func_001D1CF0);

INCLUDE_ASM("asm/nonmatchings/game/t_1D00B0", func_001D1CF8);

INCLUDE_ASM("asm/nonmatchings/game/t_1D00B0", func_001D1D90);

extern "C" void func_001D1DD8(void* p, void* a) {
    f32 v = 0;
    func_0027D268(a, 0x7E832F08, &v, 1);
    func_001D1E20(p, v);
}

INCLUDE_ASM("asm/nonmatchings/game/t_1D00B0", func_001D1E20);

extern "C" int func_001D1EA8(void* a, void* params) {
    s32 v;

    func_0027D188(params, 0, &v, 0);
    return 1;
}

extern "C" int func_001D1ED8(S001D0F68* p, void* a) {
    ((void (*)(void*, void*, s32))p->unk8[11].fn)((char*)p + p->unk8[11].delta, a, 0);
    return 1;
}

extern "C" s32 func_001D1F08(void* p, void* a) {
    s32 v = 0;
    func_0027D870(a, 0xA1DC81F9, &v, 1);
    return func_001D1CF8(p, v) != 0;
}

extern "C" s32 func_001D1F58(char* p, void* a) {
    func_0027D2D8(a, 0xB9D31B0A, p + 0x80, 0);
    func_001D1548(p);
    return 1;
}

INCLUDE_ASM("asm/nonmatchings/game/t_1D00B0", func_001D1FA0);

INCLUDE_ASM("asm/nonmatchings/game/t_1D00B0", func_001D2030);
