#include "common.h"

typedef unsigned int U128_1DC968 __attribute__((mode(TI)));

struct S1DE2B0 {
    char pad0[0x50];
    U128_1DC968 unk50;
};

struct S1DC968 {
    s32 unk0;
    s32 unk4;
    s32 unk8;
    s32 unkC;
};

struct S1DD960 {
    char pad0[0x104];
    void* unk104;
};

struct S1DCED0 {
    char pad0[0xC];
    S1DCED0* unkC;
    S1DCED0* unk10;
    void* unk14;
};

struct S1DE1B0 {
    char pad0[0x74];
    void* unk74;
    char pad78[0x18];
    char unk90[0x34];
    s32 unkC4;
};

struct S1DD658_E {
    s32 unk0;
    s32 unk4;
};

struct S1DD658 {
    S1DD658_E* unk0;
};

struct S1DE8E8 {
    s32 unk0;
    s32 unk4;
    s32 unk8;
    char padC[0x8];
    s32 unk14;
    s32 unk18;
};

struct Pool1DC {
    char* unk0;
    char* unk4;
    bool Contains(void* p) { return (char*)p >= unk0 && (char*)p < unk4; }
};

extern "C" {
void func_001CE888(void* a, void* b);
void func_001CE888_3(s32 a, void* b, void* c) __asm__("func_001CE888");
void func_001CE868_2(s32 a, void* b) __asm__("func_001CE868");
extern s32 D_00368A38[] __attribute__((section(".sdata")));
void Heap_Free(s32 heap, void* p);
void* Heap_Alloc(s32 heap, s32 size, s32 a, s32 b);
extern char D_0034C828[];
extern char D_0034C290[];
extern S1DC968* D_0036D6C8;
void* func_00224220(void* p, s32 v);
void func_00223590(void* p, void* q);
s32 func_00223460(void* p);
S1DC968* func_001DD640(S1DC968* p);
s32 func_00275570(void);
extern s32 D_00370F40[] __attribute__((section(".sdata")));
void func_001DCB80(void*);
void* func_001D1CF8(void* p, u32 key);
void* func_002234E8(void* a, s32 b);
s32 func_00201CE0(void* p);
s32 func_0010C050(s32 a);
extern Pool1DC* D_0036D540[2];
extern s32 D_0036D550;
void* func_0011C2A8(Pool1DC*);
s32 func_00119610(s32, int);
void func_00119490(s32, s32);
void func_001194B8(s32);
void func_0011C2E8(Pool1DC*, void*);
}

extern "C" void func_001DC968(S1DC968* p) {
    p->unk0 = 0;
    p->unk4 = 0;
    p->unk8 = 0;
}

extern "C" S1DC968* func_001DC978(S1DC968* p) {
    func_001DC968(p);
    return p;
}

INCLUDE_ASM("asm/nonmatchings/game/t_1DC968", func_001DC9A0);

INCLUDE_ASM("asm/nonmatchings/game/t_1DC968", func_001DCB80);

extern "C" void func_001DCC38(char* p, int flags) {
    if (!*(u8*)(p + 0x16)) {
        if (*(void**)(p + 4)) {
            func_001DCB80(p);
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

GP_DATA(D_0036D550);
GP_DATA(D_0036D540);
extern "C" void* PoolAlloc(s32 size) {
    Pool1DC* pool = D_0036D540[D_0036D550];
    if (pool) {
        void* r = func_0011C2A8(pool);
        if (!r) {
            s32 h = D_00368A38[0];
            func_00119490(h, func_00119610(h, 1));
            r = Heap_Alloc(D_00368A38[0], size, 1, 0);
            func_001194B8(D_00368A38[0]);
        }
        return r;
    }
    return Heap_Alloc(D_00368A38[0], size, 1, 0);
}

INCLUDE_ASM("asm/nonmatchings/game/t_1DC968", func_001DCD68);

extern "C" void PoolFree(void* p) {
    Pool1DC* a = D_0036D540[D_0036D550];
    if ((a && a->Contains(p)) || ((a = D_0036D540[D_0036D550 ^ 1]) && a->Contains(p))) {
        func_0011C2E8(a, p);
    } else if (p) {
        Heap_Free(D_00368A38[0], p);
    }
}

extern "C" void func_001DCED0(S1DCED0* p, s32 flags) {
    p->unk14 = D_0034C290;
    p->unk10->unkC = p->unkC;
    p->unkC->unk10 = p->unk10;
    p->unkC = p;
    p->unk10 = p;
    if (flags & 1) {
        Heap_Free(D_00368A38[0], p);
    }
}

extern "C" void func_001DCF30(S1DCED0* p, s32 flags) {
    p->unk14 = D_0034C290;
    p->unk10->unkC = p->unkC;
    p->unkC->unk10 = p->unk10;
    p->unkC = p;
    p->unk10 = p;
    if (flags & 1) {
        Heap_Free(D_00368A38[0], p);
    }
}

INCLUDE_ASM("asm/nonmatchings/game/t_1DC968", func_001DCF90);

struct Q1DD0 {
    char pad0[0x20];
    s32 unk20;
};

struct N1DD0 {
    char pad0[4];
    Q1DD0* unk4;
    char pad8[4];
    N1DD0* unkC;
};

struct I1DD0 {
    char pad0[4];
    N1DD0* unk4;
    char pad8[4];
    s32 unkC;
};

static inline N1DD0* Adv1DD(I1DD0* it) {
    N1DD0* n = it->unk4->unkC;
    N1DD0* r = 0;
    if (~(s32)n->unk4 != 0) {
        r = n;
    }
    it->unk4 = r;
    return r;
}

INCLUDE_ASM("asm/nonmatchings/game/t_1DC968", func_001DD018);

INCLUDE_ASM("asm/nonmatchings/game/t_1DC968", func_001DD0A0);

extern "C" void func_001DD118(void* p, s32 flags) {
    if (flags & 1) {
        Heap_Free(D_00368A38[0], p);
    }
}

INCLUDE_ASM("asm/nonmatchings/game/t_1DC968", func_001DD148);

INCLUDE_ASM("asm/nonmatchings/game/t_1DC968", func_001DD190);

INCLUDE_ASM("asm/nonmatchings/game/t_1DC968", func_001DD260);

INCLUDE_ASM("asm/nonmatchings/game/t_1DC968", func_001DD488);

INCLUDE_ASM("asm/nonmatchings/game/t_1DC968", func_001DD4C8);

struct E1DD4 {
    s32 unk0;
    s32 unk4;
    s32 unk8;
};

struct S1DD4 {
    E1DD4* unk0;
    s32 unk4;
};

INCLUDE_ASM("asm/nonmatchings/game/t_1DC968", func_001DD4D0);

struct E1DD5 {
    s32 unk0;
    char pad4[8];
};

struct S1DD5 {
    s32 unk0;
    s32 unk4;
};

static inline void Set1DD5(E1DD5* e, S1DD5* p, s32 a) {
    if (e->unk0 != 0) {
        func_001CE888_3(e->unk0, e, p);
        e->unk0 = 0;
    }
    e->unk0 = a;
    if (a) {
        func_001CE868_2(a, e);
    }
}

INCLUDE_ASM("asm/nonmatchings/game/t_1DC968", func_001DD568);

GP_DATA(D_0036D6C8);
extern "C" S1DC968* func_001DD5F8(void) {
    if (D_0036D6C8 == 0) {
        D_0036D6C8 = func_001DD640((S1DC968*)Heap_Alloc(D_00368A38[0], 0x10, 1, 0));
    }
    return D_0036D6C8;
}

extern "C" S1DC968* func_001DD640(S1DC968* p) {
    p->unk8 = 0;
    p->unkC = 0;
    p->unk0 = 0;
    p->unk4 = 0;
    return p;
}

INCLUDE_ASM("asm/nonmatchings/game/t_1DC968", func_001DD658);

INCLUDE_ASM("asm/nonmatchings/game/t_1DC968", func_001DD6D8);

INCLUDE_ASM("asm/nonmatchings/game/t_1DC968", func_001DD8C8);

extern "C" void func_001DD960(S1DD960* p, s32 flags) {
    p->unk104 = D_0034C828;
    if (flags & 1) {
        Heap_Free(D_00368A38[0], p);
    }
}

INCLUDE_ASM("asm/nonmatchings/game/t_1DC968", func_001DD9A0);

INCLUDE_ASM("asm/nonmatchings/game/t_1DC968", func_001DD9A8);

INCLUDE_ASM("asm/nonmatchings/game/t_1DC968", func_001DDA68);

INCLUDE_ASM("asm/nonmatchings/game/t_1DC968", func_001DDE28);

INCLUDE_ASM("asm/nonmatchings/game/t_1DC968", func_001DDE68);

INCLUDE_ASM("asm/nonmatchings/game/t_1DC968", func_001DDFA0);

INCLUDE_ASM("asm/nonmatchings/game/t_1DC968", func_001DDFD8);

INCLUDE_ASM("asm/nonmatchings/game/t_1DC968", func_001DE0F8);

extern "C" void func_001DE1B0(S1DE1B0* p) {
    func_00223590(func_00224220(p->unk74, 1), p->unk90);
    if (func_00223460(p->unk74) == 0) {
        p->unkC4 |= 2;
    } else {
        p->unkC4 &= ~2;
    }
}

struct S1DE21 {
    char pad0[0x20];
    void* unk20;
    char pad24[0x4C];
    void* unk70;
    void* unk74;
    char pad78[8];
    U128_1DC968 unk80;
    U128_1DC968 unk90;
};

extern "C" s32 func_001DE210(S1DE21* p) {
    s32 r = func_00223460(p->unk74);
    if (r) {
        void* a;
        s32 b;
        p->unk70 = p->unk74;
        if (func_00201CE0(func_001D1CF8(p->unk20, 0x0A015E17 /* Motion */))) {
            a = p->unk74;
            b = func_0010C050(r);
        } else {
            a = p->unk74;
            b = 0;
        }
        p->unk74 = func_002234E8(a, b);
        p->unk80 = p->unk90;
        func_001DE1B0((S1DE1B0*)p);
        return 1;
    }
    return 0;
}

extern "C" void func_001DE2B0(S1DE2B0* p, U128_1DC968* q) {
    *q = p->unk50;
}

INCLUDE_ASM("asm/nonmatchings/game/t_1DC968", func_001DE2C0);

INCLUDE_ASM("asm/nonmatchings/game/t_1DC968", func_001DE3C0);

extern "C" void func_001DE7A0(void) {
}

INCLUDE_ASM("asm/nonmatchings/game/t_1DC968", func_001DE7A8);

extern "C" void func_001DE8E8(S1DE8E8* p, s32 on) {
    if (on != 0) {
        if (p->unk4 == 0) {
            s32 t = func_00275570();
            s32 base = D_00370F40[0];
            p->unk14 = 1;
            p->unk8 = base + t;
        }
        p->unk4 = 1;
    } else {
        if (p->unk4 != 0) {
            p->unk18 = 1;
        }
        p->unk4 = 0;
    }
    p->unk4 = on;
}
