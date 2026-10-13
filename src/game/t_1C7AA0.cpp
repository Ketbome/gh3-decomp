#include "common.h"

struct G10 {
    s32 unk0;
    char pad4[0xC];
};

struct S001C82D8 {
    char pad0[0x81A4];
    u32 unk81A4;
    char pad81A8[0x20];
    s32 unk81C8;
    s32 unk81CC;

    bool Test(u32 m) {
        u32* f = &unk81A4;
        return (*f & m) != 0;
    }
};

struct VEnt {
    s16 delta;
    s16 index;
    void (*fn)(void*, void*);
};

struct S001C8470_20 {
    char pad0[0xEE00];
    VEnt* unkEE00;
};

struct S001C8470 {
    char pad0[0x1C];
    void (*unk1C)(void);
    S001C8470_20* unk20;
    char pad24[0x4];
    void (*unk28)(void);
};

struct S1C97E0_L {
    char pad0[4];
    s32 unk4;
    s32* unk8;
};

extern "C" {
S1C97E0_L* func_002764C8(u32 key, s32 b);
s32 func_0027D870_k(s32 a, u32 key, s32* v, s32 req) __asm__("func_0027D870");
s32 func_0027D188(s32 a, u32 key, s32* v, s32 req);
s32 func_00122718(char* p);
s32 CFunc_ObjectExists(s32 a, s32 b);
void func_00122770(void);
extern G10 D_00368740;
void func_00113F38(void* p);
extern char D_00342398[];
void Heap_Free(s32 heap, void* p);
extern s32 D_00368A38;
void func_001CD318(void);
extern u8 D_0034A8D0[];
void func_001163F0(void);
void func_00116400(void);
struct S001C82D8;
s32 func_001C82D8(S001C82D8*);
s32 func_0029D8C8(s32);
int func_0027AA70(int);
int func_001287F0(int, int);
void func_0027C448(int, int, int);
void func_0028C9D0(int, int, int, int, int, int);
void func_0027AC90(int);
void func_00113250(int);
s32 func_001CB558(char* p);
s32 func_0011EF10(void);
void func_00113FB8(s32 a);
void func_002981A0_c(s32 a, s32 b, void (*c)(void), s32 d, void* e, s32 f) __asm__("func_002981A0");
void func_001CC748(void);
void func_001CC9E8(void);
void func_001CC400(void);
void func_001CCA58(void);
void func_001CCA20(void);
void func_001CC330(void);
void func_001CCDC8(void);
int func_001CA020(char* p, int i);
void func_001CB550(char* p, int v);
}

extern "C" void func_001C7AA0(S001C8470* p) {
    *(void**)((char*)p + 0x18) = D_00342398;
    func_00113F38(p);
}

extern "C" void func_001C7AC8(char* p, s32 flags) {
    *(void**)(p + 0xC) = D_0034A8D0;
    func_001CD318();
    if (flags & 1) {
        Heap_Free(D_00368A38, p);
    }
}

extern "C" void func_001C7B18(S001C8470* p) {
    p->unk28();
}

extern "C" void func_001C7B38(S001C8470* p) {
    p->unk1C();
}

INCLUDE_ASM("asm/nonmatchings/game/t_1C7AA0", func_001C7B58);

extern "C" s32 func_001C7B70(void) {
    s32 v = D_00368740.unk0;

    return v != 4 && v != 6;
}

extern "C" void func_001C7B98(char* s, char* d) {
    while (*s != 0) {
        if (*s == '\n') {
            *d++ = '\\';
            *d++ = 'n';
        } else {
            *d++ = *s;
        }
        s++;
    }
    *d = 0;
}

INCLUDE_ASM("asm/nonmatchings/game/t_1C7AA0", func_001C7BE8);

INCLUDE_ASM("asm/nonmatchings/game/t_1C7AA0", func_001C8040);

extern "C" s32 func_001C8258(char* p) {
    if (func_001C82D8((S001C82D8*)p) != 0) {
        s32 a = *(s32*)(p + 0x81A8);
        if (a != 0 && func_0029D8C8(a) == 0) {
            return 1;
        }
        a = *(s32*)(p + 0x81AC);
        if (a != 0 && func_0029D8C8(a) == 0) {
            return 1;
        }
    }
    return 0;
}

extern "C" s32 func_001C82D8(S001C82D8* p) {
    u32* f = &p->unk81A4;

    return (*f & 0xC) != 0;
}

extern "C" void func_001C82F0(void) {
    int t = func_0027AA70(func_001287F0(8, 1));
    func_0027C448(t, 0, 0x7F07D3D4);
    func_0028C9D0(0x86B1AF56, t, 0, 0, 0, 0);
    if (t != 0) {
        func_0027AC90(t);
        func_00113250(t);
    }
}

INCLUDE_ASM("asm/nonmatchings/game/t_1C7AA0", func_001C8370);

extern "C" void func_001C8470(S001C8470* p) {
    S001C8470_20* o = p->unk20;

    o->unkEE00[64].fn((char*)o + o->unkEE00[64].delta, p);
}

INCLUDE_ASM("asm/nonmatchings/game/t_1C7AA0", func_001C84A8);

extern "C" void func_001C8568(S001C8470* p) {
    S001C8470_20* o = p->unk20;

    o->unkEE00[65].fn((char*)o + o->unkEE00[65].delta, p);
}

extern "C" void func_001C85A0(void) {
    char buf[0x100];
    if (func_00122718(buf) > 0) {
        s8 c = buf[0];
        if (c == 0x19 || c == 0x20) {
            int t = func_0027AA70(func_001287F0(8, 1));
            func_0027C448(t, 0x40C698AF, 0x31631B98);
            if (CFunc_ObjectExists(t, 0) == 0) {
                func_0027AC90(t);
                func_0027C448(t, 0x40C698AF, 0xF53D1D83);
                if (CFunc_ObjectExists(t, 0) == 0) {
                    func_0027AC90(t);
                    func_0027C448(t, 0x40C698AF, 0x3B56E746);
                    if (CFunc_ObjectExists(t, 0) == 0) {
                        func_0028C9D0(0x3B4548B8, 0, 0, 0, 0, 0);
                        func_00122770();
                    }
                }
            }
            if (t != 0) {
                func_0027AC90(t);
                func_00113250(t);
            }
        }
    }
}

extern "C" void func_001C86C8(char* p) {
    func_001163F0();
    char* o = *(char**)(p + 0x20);
    VEnt* e = (VEnt*)(*(char**)(o + 0xEE00) + 0x210);
    ((void (*)(char*, char*))e->fn)(o + e->delta, p);
    func_00116400();
}

extern "C" void func_001C8718(char* self) {
    switch (func_001CB558(self)) {
    case 1:
        func_0028C9D0(0xA107181A, 0, 0, 0, 0, 0);
        goto l;
    case 2:
        if (func_0029D8C8(func_001CA020(self, 0)) == 0) {
            func_0028C9D0(0xB0637172, 0, 0, 0, 0, 0);
        }
    l:
        func_001CB550(self, 0);
        break;
    case 3:
        func_0028C9D0(0x4E2ED110, 0, 0, 0, 0, 0);
        func_001CB550(self, 4);
        break;
    case 8: {
        int m = func_0027AA70(func_001287F0(8, 1));
        func_0027C448(m, 0xC44777F3, *(int*)(self + 0xB0));
        func_00113FB8(*(int*)(self + 0x20));
        func_00113FB8(*(int*)(self + 0x1C));
        func_0028C9D0(0x92528E98, m, 0, 0, 0, 0);
        if (m != 0) {
            func_0027AC90(m);
            func_00113250(m);
        }
        break;
    }
    case 7:
        func_0028C9D0(0x666B6A9D, 0, 0, 0, 0, 0);
        func_00113FB8(*(int*)(self + 0x1C));
    case 9:
        func_00113FB8(*(int*)(self + 0x20));
        break;
    case 0:
    case 4:
    case 5:
    case 6:
        break;
    }
}

INCLUDE_ASM("asm/nonmatchings/game/t_1C7AA0", func_001C88C8);

INCLUDE_ASM("asm/nonmatchings/game/t_1C7AA0", func_001C8A08);

extern "C" void func_001C8E98(S001C8470* p) {
    S001C8470_20* o = p->unk20;

    o->unkEE00[67].fn((char*)o + o->unkEE00[67].delta, p);
}

extern "C" void func_001C8ED0(S001C8470* p) {
    S001C8470_20* o = p->unk20;

    o->unkEE00[68].fn((char*)o + o->unkEE00[68].delta, p);
}

INCLUDE_ASM("asm/nonmatchings/game/t_1C7AA0", func_001C8F08);

extern "C" void func_001C91D8(S001C8470* p) {
    S001C8470_20* o = p->unk20;

    o->unkEE00[69].fn((char*)o + o->unkEE00[69].delta, p);
}

extern "C" void func_001C9210(char* p) {
    char* q = *(char**)(p + 0x20);
    if (func_001CB558(q) != 7) {
        if ((u32)(func_0011EF10() - *(s32*)(q + 0xD0)) > 0xEA60) {
            *(s32*)(q + 0xD0) = func_0011EF10();
            func_00113FB8(*(s32*)(q + 0x20));
            func_0028C9D0(0x3F7009B4, 0, 0, 0, 0, 0);
        }
    }
}

INCLUDE_ASM("asm/nonmatchings/game/t_1C7AA0", func_001C9298);

extern "C" void func_001C9368(S001C82D8* p, s32 v) {
    u32* f = &p->unk81A4;
    int t = (int)*f & ~0xC;

    *f = t;
    if (v == 1) {
        *f = t | 8;
    } else if (v == 2) {
        *f = t | 4;
    }
}

extern "C" void func_001C93B0(S001C82D8* p, s32 v) {
    p->unk81C8 = v;
}

INCLUDE_ASM("asm/nonmatchings/game/t_1C7AA0", func_001C93C0);

extern "C" s32 func_001C9458(S001C82D8* p) {
    return p->unk81CC;
}

extern "C" void func_001C9468(S001C82D8* p, s32 v) {
    if (v != 0) {
        u32* f = &p->unk81A4;
        *f |= 1;
    } else {
        u32* f = &p->unk81A4;
        *f = (int)*f & ~1;
    }
}

extern "C" bool func_001C94A8(S001C82D8* p) {
    return p->Test(8);
}

extern "C" bool func_001C94C0(S001C82D8* p) {
    return p->Test(4);
}

extern "C" s32 func_001C94D8(S001C82D8* p) {
    u32* f = &p->unk81A4;

    return *f & 1;
}

INCLUDE_ASM("asm/nonmatchings/game/t_1C7AA0", func_001C94F0);

INCLUDE_ASM("asm/nonmatchings/game/t_1C7AA0", func_001C95D8);

INCLUDE_ASM("asm/nonmatchings/game/t_1C7AA0", func_001C9658);

INCLUDE_ASM("asm/nonmatchings/game/t_1C7AA0", func_001C9778);

extern "C" s32 func_001C97E0(char* o) {
    s32 sp0;
    s32 sp4;
    s32 i = 0;
    S1C97E0_L* l = func_002764C8(0xCA5F7FFB, 0);
    if (l->unk4 > 0) {
        do {
            s32 h;
            if (l->unk4 == 1) {
                h = (s32)l->unk8;
            } else {
                h = l->unk8[i];
            }
            VEnt* e = (VEnt*)(*(char**)(o + 0xEE00) + 0x138);
            s32 r = ((s32 (*)(char*))e->fn)(o + e->delta);
            sp0 = 0;
            func_0027D870_k(h, 0x21902065, &sp0, 0);
            if (r == sp0) {
                func_0027D188(h, 0xA1DC81F9, &sp4, 1);
                return sp4;
            }
            i++;
        } while (i < l->unk4);
    }
    return 0;
}

extern "C" void func_001C98F0(char* p) {
    func_002981A0_c(*(s32*)(p + 0x81A8) + 4, 3, func_001CC748, 3, p, 0);
    func_002981A0_c(*(s32*)(p + 0x81A8) + 4, 0x53, func_001CC9E8, 2, p, 0x80);
    func_002981A0_c(*(s32*)(p + 0x81A8) + 4, 0x11, func_001CC400, 3, p, 0x80);
    func_002981A0_c(*(s32*)(p + 0x81A8) + 4, 0xB, func_001CCA58, 2, p, 0x80);
    func_002981A0_c(*(s32*)(p + 0x81A8) + 4, 0x4E, func_001CCA20, 2, p, 0x80);
    func_002981A0_c(*(s32*)(p + 0x81A8) + 4, 0x37, func_001CC330, 2, p, 0x80);
    func_002981A0_c(*(s32*)(p + 0x81A8) + 4, 0x58, func_001CCDC8, 0, p, 0x80);
}

INCLUDE_ASM("asm/nonmatchings/game/t_1C7AA0", func_001C9A20);

INCLUDE_ASM("asm/nonmatchings/game/t_1C7AA0", func_001C9A80);
