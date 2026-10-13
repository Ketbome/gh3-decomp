#include "common.h"

struct N1BFC {
    s32 unk0;
    char pad4[0x18];
    N1BFC* unk1C;
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
};

struct S001C1468 {
    char pad0[0x80];
    s32 unk80;
    s32 unk84;
    f32 unk88;
    u32 unk8C;
};

struct N1C {
    char pad0[0xC];
    f32 unkC;
    char pad10[0x8];
    N1C* unk18;
    N1C* unk1C;
};

struct S001C14E0 {
    char pad0[0x60];
    s32 unk60;
    s32 unk64;
    s32 unk68;
    s32 unk6C;
    s32 unk70;
    f32 unk74;
    f32 unk78;
    s32 unk7C;
};

extern "C" {
void func_001BF288(s32 a);
f32 func_0015E0A8(void);
f32 func_0015E0C8(void);
f32 func_0015E0D0(void);
f32 func_0015E0F0(void);
extern f32 D_0036CBC4;
extern f32 D_0036CBC8;
extern f32 D_0036CBCC;
extern f32 D_0036CBD0;
void func_001BFD58(N1C* n, N1C** list);
void func_001BF960_d(void* p, s32 v) __asm__("func_001BF960");
void func_001BFDD8(N1C* n, N1C** list);
void func_001BFE40_0(void) __asm__("func_001BFE40");
extern N1C* D_0036CBDC;
extern N1C* D_0036CBE0;
extern s32 D_00369A64;
extern u8 D_00372D58[] __attribute__((section(".sdata")));
void func_001BFE40(N1C* p);
void Heap_Free(s32 heap, void* p);
extern s32 D_00368A38;
extern u8 D_00349EA8[];
extern u8 D_00349E68[];
void func_001BFFE8(void* p, s32 v);
void func_001BF960(void* p);
void func_001BF2E8(s32 a, s32 b);
extern int D_00369A64;
}

GP_DATA(D_0036CBDC);
extern "C" void* func_001BF628(char* p, s32 v, f32 f) {
    *(void**)(p + 0x20) = D_00349EA8;
    *(s32*)(p + 8) = 1;
    *(f32*)(p + 0xC) = f;
    *(s32*)(p + 0x10) = 0xFFFFFF;
    *(void**)(p + 0x14) = D_00372D58;
    *(s32*)p = v;
    *(s32*)(p + 4) = 0;
    *(s32*)(p + 0x18) = 0;
    *(s32*)(p + 0x1C) = 0;
    if (v == 0) {
        func_001BFD58((N1C*)p, &D_0036CBDC);
    }
    return p;
}

extern "C" void func_001BF6A0(char* p, s32 flags) {
    *(void**)(p + 0x20) = D_00349EA8;
    func_001BFE40((N1C*)p);
    if (flags & 1) {
        Heap_Free(D_00368A38, p);
    }
}

INCLUDE_ASM("asm/nonmatchings/game/t_1BF628", func_001BF6F0);

INCLUDE_ASM("asm/nonmatchings/game/t_1BF628", func_001BF798);

INCLUDE_ASM("asm/nonmatchings/game/t_1BF628", func_001BF838);

GP_DATA(D_0036CBE0);
extern "C" void func_001BF8F8(N1C* p, s32 v) {
    if (*(s32*)((char*)p + 0x10) != v) {
        *(s32*)((char*)p + 0x10) = v;
        if (*(s32*)((char*)p + 4) == 0) {
            if (*(s32*)p == 0) {
                func_001BFE40_0();
                func_001BFDD8(p, &D_0036CBE0);
            }
        }
        *(s32*)((char*)p + 0xC) = 0;
        *(s32*)((char*)p + 4) = 1;
    }
}

GP_DATA(D_0036CBDC);
extern "C" void func_001BF960_d(void* pv, s32 v) {
    char* p = (char*)pv;
    if (*(s32*)p != v) {
        *(s32*)p = v;
        if (*(s32*)(p + 4) != 0) {
            if (v == 0) {
                func_001BFDD8((N1C*)p, &D_0036CBE0);
                return;
            }
            goto fe;
        }
        if (v != 0) {
fe:
            func_001BFE40_0();
            return;
        }
        func_001BFD58((N1C*)p, &D_0036CBDC);
    }
}

extern "C" void func_001BF9C8(char* p, void* x) {
    if (x) {
        *(void**)(p + 0x14) = x;
    } else {
        *(void**)(p + 0x14) = D_00372D58;
    }
}

INCLUDE_ASM("asm/nonmatchings/game/t_1BF628", func_001BF9E8);

extern "C" void func_001BFC58(N1BFC* p) {
    if (p != 0) {
        do {
            if (p->unk0 == 0) {
                p->v3();
                p->v4();
                p->v5();
            } else {
                p->v2();
            }
            p = p->unk1C;
        } while (p != 0);
    }
}

GP_DATA(D_0036CBCC);
GP_DATA(D_0036CBC8);
GP_DATA(D_0036CBC4);
GP_DATA(D_0036CBD0);
extern "C" void func_001BFCE8(void) {
    D_0036CBCC = 0.0f;
    D_0036CBC4 = 1.0f;
    D_0036CBC8 = 1.0f;
    D_0036CBD0 = 0.0f;
    D_0036CBC4 *= func_0015E0A8();
    D_0036CBC8 *= func_0015E0C8();
    D_0036CBCC += func_0015E0D0();
    D_0036CBD0 += func_0015E0F0();
}

INCLUDE_ASM("asm/nonmatchings/game/t_1BF628", func_001BFD58);

extern "C" void func_001BFDD8(N1C* n, N1C** list) {
    if (!*list) {
        n->unk18 = 0;
        n->unk1C = *list;
        *list = n;
        return;
    }
    N1C* c = *list;
    while (c->unk1C) c = c->unk1C;
    N1C* x = c->unk1C;
    n->unk1C = x;
    if (x) x->unk18 = n;
    c->unk1C = n;
    n->unk18 = c;
}

extern "C" void func_001BFE40(N1C* n) {
    if (D_0036CBE0 == n) {
        D_0036CBE0 = n->unk1C;
    }
    if (D_0036CBDC == n) {
        D_0036CBDC = n->unk1C;
    }
    if (n->unk18 != 0) {
        n->unk18->unk1C = n->unk1C;
    }
    if (n->unk1C != 0) {
        n->unk1C->unk18 = n->unk18;
    }
    n->unk18 = 0;
    n->unk1C = 0;
}

INCLUDE_ASM("asm/nonmatchings/game/t_1BF628", func_001BFEA0);

extern "C" void func_001BFF98(char* p, s32 flags) {
    *(void**)(p + 0x20) = D_00349E68;
    func_001BFFE8(p, 1);
    func_001BF6A0(p, flags);
}

extern "C" void func_001BFFE8(void* pv, s32 v0) {
    register s32 v asm("$17") = v0;
    register char* p asm("$16") = (char*)pv;
    register s32 old asm("$18") = *(s32*)p;
    func_001BF960(p);
    s32 t = *(s32*)(p + 0xAC);
    if (t != 0 && old != v) {
        func_001BF2E8(t, v ^ 1);
    }
}

extern "C" void func_001C0040(char* p, s32 v) {
    if (v != 0 && *(s32*)(p + 0xAC) != v) {
        func_001BF288(v);
        if (*(s32*)p == 0) {
            func_001BF2E8(v, 1);
            s32 t = *(s32*)(p + 0xAC);
            if (t != 0) {
                func_001BF2E8(t, 0);
            }
        }
    }
    *(s32*)(p + 0xAC) = v;
}

extern "C" void func_001C00B8(void) {
}

INCLUDE_ASM("asm/nonmatchings/game/t_1BF628", func_001C00C0);

INCLUDE_ASM("asm/nonmatchings/game/t_1BF628", func_001C0408);

INCLUDE_ASM("asm/nonmatchings/game/t_1BF628", func_001C1318);

extern "C" void func_001C1468(S001C1468* p, f32 dt) {
    if ((p->unk8C & 1) && D_00369A64 == 0 && dt > 0.0f) {
        s32 n = p->unk84;
        s32 v = p->unk80 + (s32)((f32)n * p->unk88 * dt);
        p->unk80 = v;
        if (n < v) {
            p->unk80 = v - n;
        }
    }
}

extern "C" void func_001C14E0(S001C14E0* p, f32 dt) {
    if (p->unk60 != 0 && D_00369A64 == 0 && 0.0f < dt) {
        if (p->unk74 > p->unk78) {
            p->unk74 = p->unk74 - p->unk78;
            if (++p->unk6C == p->unk64) {
                p->unk6C = 0;
                if (p->unk7C != 0) {
                    if (--p->unk70 < 0) {
                        p->unk70 = p->unk70 + p->unk68;
                    }
                } else {
                    if (++p->unk70 == p->unk68) {
                        p->unk70 = 0;
                    }
                }
            }
        }
        p->unk74 = p->unk74 + dt;
    }
}

INCLUDE_ASM("asm/nonmatchings/game/t_1BF628", func_001C1598);
