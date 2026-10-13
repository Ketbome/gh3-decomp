#include "common.h"

struct E1DA5 {
    u32 unk0;
    char pad4[0x10];
    s32 unk14;
};

struct N1DA5 {
    char pad0[4];
    N1DA5* unk4;
    E1DA5* unk8;
};

struct I1DA5 {
    s32 unk0;
    N1DA5* unk4;
};

struct L1DA5 {
    char pad0[0x1C];
    N1DA5* unk1C;
};

struct S1D85E8_N {
    char pad0[0xC];
    S1D85E8_N* unkC;
    S1D85E8_N* unk10;
};

struct S1D8BF0 {
    s32 unk0;
    s32 unk4;
    s32 unk8;
    s32 unkC;
    s32 unk10;
};

struct S1D8A88_S {
    s32 unk0;
    s32 unk4;
    s32 unk8;
};

struct S1D8A88 {
    s32 unk0;
    S1D8A88_S unk4;
    s32 unk10;
    s32 unk14;
    void* unk18;
};

struct S1D8BA0 {
    char pad0[0x18];
    virtual void v1();
    virtual void v2(void* q);
    virtual void v3(void* q);
};

struct S1D8930 {
    char pad0[0xC];
    s32 unkC;
};

struct S1D87B8_N {
    char pad0[0xC];
    S1D87B8_N* unkC;
    S1D87B8_N* unk10;
    void* unk14;
};

struct S1D87B8 {
    char pad0[0x4];
    S1D87B8_N unk4;
    char pad1C[0x10];
    void* unk2C;
};

struct S1D8B30 {
    char pad0[0x4];
    void* unk4;
};

struct S1DA1A0 {
    char pad0[0x210];
    virtual void v1(int);
};

struct E1DA028 {
    void* unk0;
    u32 unk4;
    u32 unk8;
    void* unkC;
    char pad10[0x4];
};

extern "C" {
void func_00113F38(void* p);
extern s32 D_00372DA0;
extern s32 D_00372DB0;
extern u32 D_00372DA8;
extern char D_0034C118[];
void func_0027D1F8(s32 p, u32 key, s32* out, s32 d);
extern s32 D_0036D554[] __attribute__((section(".sdata")));
void func_001DB570(s32 a, void* p, s32 b, s32 c);
void func_001DB568(s32 a, void* p, s32 b, s32 c);
extern char D_0034BFA8[];
extern char D_0033B510[];
extern s32 D_00368A38[] __attribute__((section(".sdata")));
void Heap_Free(s32 heap, void* p);
void func_001CE888(void* p, void* q);
void func_001CE868(void* p, void* q);
void func_001DB580(s32 a, void* p);
void func_0027AC90(void* p);
void func_00113250(void* p);
void func_001DB638(s32 a, void* p);
void func_001DB8A8(s32 a, void* p, void* q);
extern u32 D_0036D558;
void func_001DB708(s32 a, void* p, void* q);
void* func_00113DF0(u32, int, int);
s32 func_001DA7B8(void*);
void func_001D8BC8_3(void* p, s32 a, f32 t) __asm__("func_001D8BC8");
void func_001D8BA0_2(void* p, s32 a) __asm__("func_001D8BA0");
}

extern "C" void func_001D85E8(char* p, char* q) {
    S1D85E8_N* n = (S1D85E8_N*)(p + 0x30);
    S1D85E8_N* m = (S1D85E8_N*)(q + 0x38);
    m->unk10 = n;
    m->unkC = n->unkC;
    n->unkC->unk10 = m;
    n->unkC = m;
}

INCLUDE_ASM("asm/nonmatchings/game/t_1D85E8", func_001D8610);

INCLUDE_ASM("asm/nonmatchings/game/t_1D85E8", func_001D8618);

INCLUDE_ASM("asm/nonmatchings/game/t_1D85E8", func_001D8718);

GP_DATA(D_00372DA0);
GP_DATA(D_00372DB0);
GP_DATA(D_00372DA8);
extern "C" void func_001D8720(s32 a, s32 b) {
    if (b == 0xFFFF && a != 0) {
        D_00372DA0 = 0;
        D_00372DB0 = 0;
        D_00372DA8 = 0xFFFFFFFF;
    }
}

INCLUDE_ASM("asm/nonmatchings/game/t_1D85E8", func_001D8750);

extern "C" void func_001D87B8(S1D87B8* p, s32 flags) {
    p->unk2C = D_0034BFA8;
    S1D87B8_N* n = &p->unk4;
    n->unk14 = D_0033B510;
    n->unk10->unkC = n->unkC;
    n->unkC->unk10 = n->unk10;
    n->unkC = n;
    n->unk10 = n;
    if (flags & 1) {
        Heap_Free(D_00368A38[0], p);
    }
}

extern "C" void func_001D8828(void* p) {
    func_00113F38(p);
}

extern "C" void* func_001D8848(S1D8BF0* p) {
    return &p->unk4;
}

INCLUDE_ASM("asm/nonmatchings/game/t_1D85E8", func_001D8850);

extern "C" void func_001D8878(void) {
    func_001D8720(1, 0xFFFF);
}

INCLUDE_ASM("asm/nonmatchings/game/t_1D85E8", func_001D8898);

extern "C" void func_001D88C0(char* p, int flags) {
    if (*(u32*)(p + 0xC) & 4) {
        void* m = *(void**)(p + 0x10);
        if (m) {
            func_0027AC90(m);
            func_00113250(m);
        }
    }
    if (flags & 1) {
        Heap_Free(D_00368A38[0], p);
    }
}

extern "C" void func_001D8930(S1D8930* p, s32 a, s32 b) {
    func_001DB570(D_0036D554[0], p, a, b);
    p->unkC |= 1;
}

extern "C" void func_001D8978(S1D8930* p, s32 a, s32 b) {
    func_001DB570(D_0036D554[0], p, a, b);
    p->unkC |= 1;
}

extern "C" void func_001D89C0(S1D8930* p, s32 a, s32 b) {
    func_001DB568(D_0036D554[0], p, a, b);
    p->unkC |= 2;
}

extern "C" void func_001D8A08(S1D8930* p, s32 a, s32 b) {
    func_001DB568(D_0036D554[0], p, a, b);
    p->unkC |= 2;
}

extern "C" s32 func_001D8A50(S1D8A88* p) {
    s32 v = 0;
    if (p->unk10 != 0) {
        func_0027D1F8(p->unk10, 0xB30D9965, &v, 0);
    }
    return v;
}

extern "C" S1D8A88* func_001D8A88(S1D8A88* p, s32 v) {
    p->unk0 = v;
    p->unk18 = D_0034C118;
    S1D8A88_S* q = &p->unk4;
    q->unk4 = 0;
    q->unk8 = 0;
    q->unk0 = 0;
    p->unk10 = 0;
    p->unk14 = 0;
    return p;
}

INCLUDE_ASM("asm/nonmatchings/game/t_1D85E8", func_001D8AB8);

extern "C" void func_001D8B30(S1D8B30* p, void* q) {
    void** r = &p->unk4;
    if (p->unk4 != 0) {
        func_001CE888(p->unk4, r);
        p->unk4 = 0;
    }
    p->unk4 = q;
    if (q != 0) {
        func_001CE868(q, r);
    }
    func_001DB580(D_0036D554[0], p);
}

extern "C" void func_001D8BA0(S1D8BA0* p, void* q) {
    p->v2(q);
}

extern "C" void func_001D8BC8(S1D8BA0* p, void* q) {
    p->v3(q);
}

extern "C" S1D8BF0* func_001D8BF0(S1D8BF0* p) {
    p->unk4 = 0;
    p->unk8 = 1;
    p->unk0 = 0;
    p->unk10 = 0;
    p->unkC = 0;
    return p;
}

INCLUDE_ASM("asm/nonmatchings/game/t_1D85E8", func_001D8C10);

INCLUDE_ASM("asm/nonmatchings/game/t_1D85E8", func_001D8CD0);

INCLUDE_ASM("asm/nonmatchings/game/t_1D85E8", func_001D9180);

INCLUDE_ASM("asm/nonmatchings/game/t_1D85E8", func_001D9588);

INCLUDE_ASM("asm/nonmatchings/game/t_1D85E8", func_001D9658);

INCLUDE_ASM("asm/nonmatchings/game/t_1D85E8", func_001D9740);

extern "C" void func_001D97A0(char** p, void* a) {
    for (s32 i = 0; i < *(s32*)(p + 1); i++) {
        char* e = p[0] + i * 0x14;
        if ((*(u32*)(e + 0x10) >> 2) & 1) {
            if (*(void**)e) {
                func_001DB8A8(D_0036D554[0], *(void**)e, a);
            }
            void* m = *(void**)(e + 0xC);
            *(u32*)(e + 4) = 0xC377C572;
            if (m) {
                func_0027AC90(m);
                func_00113250(m);
                *(void**)(e + 0xC) = 0;
            }
        }
    }
}

INCLUDE_ASM("asm/nonmatchings/game/t_1D85E8", func_001D9878);

INCLUDE_ASM("asm/nonmatchings/game/t_1D85E8", func_001D9BE0);

extern "C" void func_001D9F40(E1DA028** p, void* a, u32 key) {
    E1DA028* e = p[0];
    for (s32 i = 0; i < *(s32*)(p + 1); i++, e++) {
        bool all = key == 0x8B713E0E;
        if (e->unk8 == key || all) {
            if (e->unk0) {
                func_001DB8A8(D_0036D554[0], e->unk0, a);
            }
            void* m = e->unkC;
            e->unk4 = 0xC377C572;
            if (m) {
                func_0027AC90(m);
                func_00113250(m);
                e->unkC = 0;
            }
        }
    }
}

extern "C" void func_001DA028(E1DA028** p, void* a) {
    E1DA028* e = p[0];
    for (s32 i = 0; i < *(s32*)(p + 1); i++, e++) {
        if (e->unk0 && e->unk4 && e->unk4 != 0xC377C572) {
            func_001DB708(D_0036D554[0], e->unk0, a);
        }
    }
}

extern "C" void func_001DA0C8(E1DA028** p, void* a) {
    E1DA028* e = p[0];
    for (s32 i = 0; i < *(s32*)(p + 1); i++, e++) {
        if (e->unk0) {
            func_001DB8A8(D_0036D554[0], e->unk0, a);
        }
    }
}

INCLUDE_ASM("asm/nonmatchings/game/t_1D85E8", func_001DA140);

GP_DATA(D_0036D554);
GP_DATA(D_0036D558);
extern "C" s32 func_001DA150(int create) {
    if (!D_0036D554[0] && create) {
        D_0036D554[0] = func_001DA7B8(func_00113DF0(0x214, 0, 1));
    }
    D_0036D558++;
    return D_0036D554[0];
}

extern "C" void func_001DA1A0() {
    if (D_0036D558 >= 2) {
        D_0036D558--;
        return;
    }
    if (D_0036D554[0]) {
        ((S1DA1A0*)D_0036D554[0])->v1(3);
    }
    D_0036D554[0] = 0;
    D_0036D558 = 0;
}

INCLUDE_ASM("asm/nonmatchings/game/t_1D85E8", func_001DA1F8);

INCLUDE_ASM("asm/nonmatchings/game/t_1D85E8", func_001DA368);

extern "C" void func_001DA448(L1DA5* l, s32 a, s32 k) {
    I1DA5 end;
    I1DA5 it;
    it.unk4 = l->unk1C;
    end.unk4 = (N1DA5*)((char*)l + 0x18);
    if (it.unk4 != end.unk4) {
        do {
            E1DA5* e = it.unk4->unk8;
            if (e->unk0 & 1) {
                e->unk14++;
                if (k == 0 || *(s32*)((char*)it.unk4->unk8 + 4) == k) {
                    func_001D8BA0_2(it.unk4->unk8, a);
                }
                it.unk4->unk8->unk14--;
            }
            it.unk4 = it.unk4->unk4;
        } while (it.unk4 != end.unk4);
    }
}

extern "C" void func_001DA500(L1DA5* l, s32 a, f32 t) {
    I1DA5 end;
    I1DA5 it;
    it.unk4 = l->unk1C;
    end.unk4 = (N1DA5*)((char*)l + 0x18);
    if (it.unk4 != end.unk4) {
        do {
            E1DA5* e = it.unk4->unk8;
            if (e->unk0 & 2) {
                e->unk14++;
                func_001D8BC8_3(it.unk4->unk8, a, t);
                it.unk4->unk8->unk14--;
            }
            it.unk4 = it.unk4->unk4;
        } while (it.unk4 != end.unk4);
    }
}

INCLUDE_ASM("asm/nonmatchings/game/t_1D85E8", func_001DA5A0);
