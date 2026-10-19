// cflags: -funroll-loops
#include "common.h"

struct V4_1C77 {
    f32 a, b, c, d;
};

struct L10 {
    char pad0[0xC];
    L10* unkC;
    L10* unk10;
};

struct S001C5A68 {
    char pad0[0x8];
    L10 unk8;
    char pad1C[0x4];
    s32 unk20;
};

struct S001C5A68_B {
    char pad0[0x8];
    s32 unk8;
    s32 unkC;
    L10* unk10;
};

struct VEnt {
    s16 delta;
    s16 index;
    void (*fn)(void*, s32);
};

struct S001C5CB8 {
    char pad0[0x1C];
    void (*unk1C)(void);
};

struct S0036CDB4 {
    char pad0[0x14];
    VEnt* unk14;
    char pad18[0x2E8];
    s32 unk300;
};

struct S1C6188 {
    char pad0[0x1C];
    s32 unk1C;
    char pad20[0x2E0];
    s32 unk300;
    s32 unk304;
    s32 unk308;
    s32 unk30C;
};

extern "C" {
s32 func_00122718(char* p);
s32 func_001287F0(s32 a, s32 b);
s32 func_0027AA70(s32 a);
void func_0027C448(s32 a, s32 b, u32 c);
void func_0027C028(s32 a, u32 key, char* s);
void func_0027C160(s32 a, u32 key, s32 v);
void func_0027AC90(s32 a);
void func_00113250(s32 a);
extern s32 D_0036CDB0;
s32 func_00114030(s32 a);
void func_00122770(void);
void func_001CE778(void);
s32 func_001E1650(s32 a, s32 b);
void func_001E1698(s32 a);
void func_00265008(void);
s32 func_00275F08(u32 a, s32 b);
void func_0028C9D0(u32 a, s32 b, s32 c, s32 d, s32 e, s32 f);
void func_002BE288(void);
void func_001C6F60(S0036CDB4* p, void* params);
bool func_0027DF00(void* p, u32 key);
void* func_00113DF0(s32 size, s32 a, s32 b);
S0036CDB4* func_001C5D80(void* p);
void func_0027D1F8(void* p, s32 key, s32* v, s32 req);
void func_001C7668(S0036CDB4* p, s32 v);
s32 func_001CD2C8(s32 a);
void func_001CD318(void);
void func_001CD6B0(s32 a, s32 b);
extern u8 D_0034A8D0[];
extern S0036CDB4* D_0036CDB4;
extern u32 D_0036CDB8;
void func_00113FB8(s32 a);
void Heap_Free(s32 heap, void* p);
extern s32 D_00368A38[] __attribute__((section(".sdata")));
extern u8 D_0034A6A0[];
extern u8 D_0034A968[];
extern u8 D_0034A8E8[];
void func_00265680(void);
void func_001C5610(void* p, s32 a);
s32 func_00117F10(s32 a);
void func_00119490(s32 a, s32 b);
void func_001194B8(s32 a);
s32 func_00119610(s32 a, s32 b);
void func_001C6188(void* p, s32 a);
void func_00275648(void* p);
void func_0027DD38(void* p, s32 a, void* v, s32 b);
s32 func_003174C0(f32 f);
}

struct N1C79 {
    char pad0[0xC];
    N1C79* unkC;
    N1C79* unk10;
    void* unk14;
};

struct P1C74 {
    char pad0[0x20];
    s32 unk20;
};

struct KV1C6 {
    s32 key;
    s32 val;
};

struct B1C6 {
    char pad0[0xF4];
    KV1C6 e[1][32];
};

extern "C" void func_001C5A68(S001C5A68* p, S001C5A68_B* b) {
    L10* n = b->unk10;
    L10* h = &p->unk8;

    L10* nx = h->unk10;

    n->unkC = h;
    n->unk10 = nx;
    h->unk10->unkC = n;
    h->unk10 = n;
}

extern "C" void func_001C5A90(S001C5A68* p, S001C5A68_B* b) {
    L10* n = b->unk10;

    n->unk10->unkC = n->unkC;
    n->unkC->unk10 = n->unk10;
    n->unkC = n;
    n->unk10 = n;
}

extern "C" void func_001C5AB8(S001C5A68* p, S001C5A68_B* b) {
    if (b->unkC == 0) {
        b->unk8 = 1;
        p->unk20 = 1;
    }
}

INCLUDE_ASM("asm/nonmatchings/game/t_1C5A68", func_001C5AD8);

struct VE1C5 {
    s16 delta;
    s16 unk2;
    void (*fn)(char*);
};

struct N1C5 {
    char pad0[4];
    N1C5* unk4;
    s32 unk8;
    N1C5* unkC;
};

struct It1C5 {
    s32 unk0;
    N1C5* unk4;
    u8* unk8;

    It1C5() {
        unk8 = D_0034A6A0;
    }
    ~It1C5() {
        unk8 = D_0034A6A0;
    }
};

struct O1C5 {
    char pad0[4];
    s32 unk4;
    s32 unk8;
    s32 unkC;
    VE1C5* unk14;
};

extern "C" void func_001C5AE0(char* self) {
    It1C5 it;
    it.unk4 = (N1C5*)(self + 8);
    N1C5* n = it.unk4->unkC;
    n = (~(u32)n->unk4 == 0) ? 0 : n;
    it.unk4 = n;
    N1C5* cur = n ? n->unk4 : 0;
    if (cur) {
        do {
            N1C5* c = cur;
            N1C5* m = it.unk4->unkC;
            m = (~(u32)m->unk4 != 0) ? m : 0;
            it.unk4 = m;
            cur = m ? m->unk4 : 0;
            if (*(s32*)((char*)c + 0xC) == 0 && c->unk4 == (N1C5*)1) {
                VE1C5* e = *(VE1C5**)((char*)c + 0x14);
                e = (VE1C5*)((char*)e + 0x18);
                e->fn((char*)c + e->delta);
                c->unk4 = 0;
                c->unk8 = 0;
            }
        } while (cur);
    }
}

INCLUDE_ASM("asm/nonmatchings/game/t_1C5A68", func_001C5BE0);

INCLUDE_ASM("asm/nonmatchings/game/t_1C5A68", func_001C5C10);

extern "C" void func_001C5C78(char* p, s32 flags) {
    *(void**)(p + 8) = D_0034A6A0;
    if (flags & 1) {
        Heap_Free(D_00368A38[0], p);
    }
}

extern "C" void func_001C5CB8(S001C5CB8* p) {
    p->unk1C();
}

GP_DATA(D_0036CDB4);
GP_DATA(D_0036CDB8);
extern "C" S0036CDB4* func_001C5CD8(s32 a) {
    if (D_0036CDB4 == 0 && a != 0) {
        D_0036CDB4 = func_001C5D80(func_00113DF0(0x328, 0, 1));
    }
    D_0036CDB8++;
    return D_0036CDB4;
}

extern "C" void func_001C5D28(void) {
    S0036CDB4* p;

    if (D_0036CDB8 > 1) {
        D_0036CDB8--;
    } else {
        p = D_0036CDB4;
        if (p != 0) {
            p->unk14[1].fn((char*)p + p->unk14[1].delta, 3);
        }
        D_0036CDB4 = 0;
        D_0036CDB8 = 0;
    }
}

INCLUDE_ASM("asm/nonmatchings/game/t_1C5A68", func_001C5D80);

struct VE1C60 {
    s16 delta;
    s16 pad;
    void* fn;
};

static inline void Del1C60(char* o, s32 vp, s32 off) {
    VE1C60* e = (VE1C60*)(*(char**)(o + vp) + off);
    ((void (*)(char*, s32))e->fn)(o + e->delta, 3);
}

extern "C" void func_001C6058(char* p, s32 flags) {
    *(void**)(p + 0x14) = D_0034A8E8;
    char* o = *(char**)(p + 0x18);
    if (o != 0) {
        Del1C60(o, 0x18, 0x10);
    }
    N1C79* n = (N1C79*)(p + 0x310);
    char** a = (char**)(p + 0x28);
    for (s32 i = 0; i < 2; i++) {
        o = a[i];
        if (o != 0) {
            Del1C60(o, 0x18, 0x10);
        }
        a[i] = 0;
    }
    o = *(char**)(p + 0x308);
    if (o != 0) {
        Del1C60(o, 8, 8);
    }
    o = *(char**)(p + 0x30C);
    if (o != 0) {
        Del1C60(o, 8, 8);
    }
    func_00265680();
    n->unk14 = D_0034A968;
    n->unk10->unkC = n->unkC;
    n->unkC->unk10 = n->unk10;
    n->unkC = n;
    n->unk10 = n;
    func_001C5610(p, flags);
}

GP_DATA(D_0036CDB0);
extern "C" void func_001C6188(void* self, s32 flag) {
    S1C6188* p = (S1C6188*)self;
    if (D_0036CDB0 == 0 && func_00114030(p->unk1C) == 0) {
        func_00122770();
    }
    func_001CE778();
    if (flag == 0 && p->unk300 != 0) {
        func_001E1698(p->unk308);
        if (func_001E1650(p->unk308, 0) != 0) {
            if (p->unk304 != 0) {
                if (func_00275F08(0xE997DB9F, 1) == 0) {
                    func_0028C9D0(0x15041EEF, 0, 0, 0, 0, 0);
                }
            }
            p->unk304 = 1;
        } else if (p->unk304 != 0) {
            func_0028C9D0(0x15674315, 0, 0, 0, 0, 0);
            p->unk304 = 0;
        }
        func_001E1698(p->unk30C);
    }
    func_002BE288();
    func_00265008();
}

INCLUDE_ASM("asm/nonmatchings/game/t_1C5A68", func_001C6298);

extern "C" void func_001C63B8(char* p) {
    func_00113FB8(*(s32*)(p + 0x18));
    func_00113FB8(*(s32*)(p + 0x28));
    func_00113FB8(*(s32*)(p + 0x2C));
}

extern "C" void func_001C63F0(char* p) {
    s32 h = D_00368A38[0];
    func_00119490(h, func_00119610(h, 0x3A));
    char* q = *(char**)(p + 0x20);
    func_001C6188(q, *(s32*)(q + 0xB8));
    func_001194B8(D_00368A38[0]);
}

INCLUDE_ASM("asm/nonmatchings/game/t_1C5A68", func_001C6450);

extern "C" void func_001C6650(char* self) {
    char buf[0x100];
    char t[2];
    s32 o = *(s32*)(self + 0x20);
    s32 r = func_00122718(buf);
    s32 n;
    char* p;
    if (r > 0) {
        n = r;
        asm("" : "+r"(n));
        s32 k19 = 0x19;
        s32 k18 = 0x18;
        p = buf;
        do {
            u8 c = *p;
            if ((u32)(c - 0x20) < 0x5F || (s8)c == k19 || (s8)c == k18) {
                s32 h = func_0027AA70(func_001287F0(8, 1));
                s8 c2 = *p;
                if (c2 == k19) {
                    func_0027C448(h, 0, 0xB292CC42);
                } else if (c2 == k18) {
                    func_0027C448(h, 0, 0x86C0FC77);
                } else {
                    t[0] = *p;
                    t[1] = 0;
                    func_0027C028(h, 0xC4745838, t);
                }
                func_0027C160(h, 0x69E3A1C4, *(s32*)(o + 0xC4));
                func_0028C9D0(0xA6ED4911, h, 0, 0, 0, 0);
                if (h != 0) {
                    func_0027AC90(h);
                    func_00113250(h);
                }
            }
            n--;
            p++;
        } while (n != 0);
    }
    func_00122770();
}

extern "C" s32 func_001C67C0(char* p, s32 key, s32 idx) {
    for (int i = 0; i < 32; i++) {
        if (((B1C6*)p)->e[idx][i].key == key) return ((B1C6*)p)->e[idx][i].val;
    }
    return 0;
}

INCLUDE_ASM("asm/nonmatchings/game/t_1C5A68", func_001C6868);

INCLUDE_ASM("asm/nonmatchings/game/t_1C5A68", func_001C68D8);

INCLUDE_ASM("asm/nonmatchings/game/t_1C5A68", func_001C6BE8);

INCLUDE_ASM("asm/nonmatchings/game/t_1C5A68", func_001C6F60);

INCLUDE_ASM("asm/nonmatchings/game/t_1C5A68", func_001C74F8);

INCLUDE_ASM("asm/nonmatchings/game/t_1C5A68", func_001C7548);

struct L1C76 {
    s32 unk0;
    s32 unk4;
    s32 unk8;
    void* unkC;
};

extern "C" void func_001C7668(S0036CDB4* unused, s32 v) {
    L1C76 l;
    l.unkC = D_0034A8D0;
    s32 r = func_001CD2C8(0);
    L1C76* q = (L1C76*)((char*)&l + 4);
    q->unk4 = r;
    func_001CD6B0(r, v);
    l.unkC = D_0034A8D0;
    func_001CD318();
}

INCLUDE_ASM("asm/nonmatchings/game/t_1C5A68", func_001C76C0);

extern "C" s32 func_001C7760(void) {
    return 0;
}

extern "C" int CFunc_SetMenuAutoRepeatTimes(void* params) {
    V4_1C77 v;
    func_00275648(&v);
    func_0027DD38(params, 0, &v, 1);
    char* p = (char*)D_0036CDB4;
    s32 x = func_003174C0(v.b * 1000.0f);
    *(s32*)(p + 0xC0) = func_003174C0(v.c * 1000.0f);
    *(s32*)(p + 0xBC) = x;
    return 1;
}

INCLUDE_ASM("asm/nonmatchings/game/t_1C5A68", CFunc_SetMenuPadMappings);

extern "C" int CFunc_SetButtonEventMappings(void* params) {
    S0036CDB4* p = D_0036CDB4;
    func_001C6F60(p, params);
    if (func_0027DF00(params, 0xDB96E524)) {
        *(s32*)((char*)p + 0xF0) = 1;
    } else if (func_0027DF00(params, 0x4F653B0B)) {
        *(s32*)((char*)p + 0xF0) = 0;
    }
    return 1;
}

extern "C" int CFunc_SetAnalogStickActiveForMenus(void* params) {
    s32 v = 1;

    func_0027D1F8(params, 0, &v, 0);
    func_001C7668(D_0036CDB4, v != 0);
    return 1;
}

extern "C" int CFunc_SetEnableMovies(void* params) {
    s32 v = 1;

    func_0027D1F8(params, 0, &v, 0);
    D_0036CDB4->unk300 = v != 0;
    return 1;
}

INCLUDE_ASM("asm/nonmatchings/game/t_1C5A68", func_001C79B0);

extern "C" void func_001C79E0(N1C79* n, s32 flags) {
    n->unk14 = D_0034A968;
    n->unk10->unkC = n->unkC;
    n->unkC->unk10 = n->unk10;
    n->unkC = n;
    n->unk10 = n;
    if (flags & 1) {
        Heap_Free(D_00368A38[0], n);
    }
}

extern "C" void func_001C7A40(N1C79* n, s32 flags) {
    n->unk14 = D_0034A968;
    n->unk10->unkC = n->unkC;
    n->unkC->unk10 = n->unk10;
    n->unkC = n;
    n->unk10 = n;
    if (flags & 1) {
        Heap_Free(D_00368A38[0], n);
    }
}
