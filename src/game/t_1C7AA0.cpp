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

extern "C" {
extern G10 D_00368740;
void func_00113F38(void* p);
extern char D_00342398[];
void Heap_Free(s32 heap, void* p);
extern s32 D_00368A38;
void func_001CD318(void);
extern u8 D_0034A8D0[];
void func_001163F0(void);
void func_00116400(void);
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

INCLUDE_ASM("asm/nonmatchings/game/t_1C7AA0", func_001C8258);

extern "C" s32 func_001C82D8(S001C82D8* p) {
    u32* f = &p->unk81A4;

    return (*f & 0xC) != 0;
}

INCLUDE_ASM("asm/nonmatchings/game/t_1C7AA0", func_001C82F0);

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

INCLUDE_ASM("asm/nonmatchings/game/t_1C7AA0", func_001C85A0);

extern "C" void func_001C86C8(char* p) {
    func_001163F0();
    char* o = *(char**)(p + 0x20);
    VEnt* e = (VEnt*)(*(char**)(o + 0xEE00) + 0x210);
    ((void (*)(char*, char*))e->fn)(o + e->delta, p);
    func_00116400();
}

INCLUDE_ASM("asm/nonmatchings/game/t_1C7AA0", func_001C8718);

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

INCLUDE_ASM("asm/nonmatchings/game/t_1C7AA0", func_001C9210);

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

INCLUDE_ASM("asm/nonmatchings/game/t_1C7AA0", func_001C97E0);

INCLUDE_ASM("asm/nonmatchings/game/t_1C7AA0", func_001C98F0);

INCLUDE_ASM("asm/nonmatchings/game/t_1C7AA0", func_001C9A20);

INCLUDE_ASM("asm/nonmatchings/game/t_1C7AA0", func_001C9A80);
