#include "common.h"

struct S22B {
    char pad0[0x10];
    int unk10;
    char pad14[0x8];
    int unk1C;
    u32 unk20_0 : 24;
    u32 unk20_24 : 7;
    u32 unk20_31 : 1;
};

extern "C" {
extern u8 D_00352CB8[];
extern u8 D_00352F78[];
extern u8 D_0036F838[];
extern u8 D_003532D0[];
void func_0022C4F0(int, int);
void func_0011A470(int);
extern u8 D_00352F88[];
void* func_0022BA90(void*);
extern u8 D_00353480[];
int func_001162E8(void*);
extern u8 D_00372E50;
extern u8 D_00393AD8[];
void* func_0022C3C8(void);
void func_0030A2F4(void*, int, int);
}

INCLUDE_ASM("asm/nonmatchings/game/t_22BD90", func_0022BD90);

extern "C" void func_0022BDE8(S22B* self) {
    self->unk20_24 = 5;
}

inline int type_0022BE08(S22B* self) {
    return self->unk20_24;
}

extern "C" int func_0022BE08(S22B* self) {
    return type_0022BE08(self) == 4;
}

extern "C" int func_0022BE20(char* p) {
    struct VT {
        char pad[0x68];
        s16 delta;
        s16 pad6A;
        int (*fn)(char*, int, u32);
    };
    VT* v = *(VT**)(p + 0x34);
    return v->fn(p + v->delta, *(int*)(p + 0x14), *(u32*)(p + 0x20) & 0xFFFFFF);
}

INCLUDE_ASM("asm/nonmatchings/game/t_22BD90", func_0022BE60);

INCLUDE_ASM("asm/nonmatchings/game/t_22BD90", func_0022BEE0);

INCLUDE_ASM("asm/nonmatchings/game/t_22BD90", func_0022BF58);

extern "C" void func_0022C030(int* p) {
    if (p[5]) {
        func_0011A470(p[5]);
        p[5] = 0;
    }
}

extern "C" void func_0022C068(char* p, int a) {
    void* r = func_0022C3C8();
    *(void**)(p + 0x18) = r;
    if (a) {
        func_0030A2F4(r, a, 0x80);
    }
}

extern "C" int func_0022C0B0(void) {
    return 0x90;
}

extern "C" void* func_0022C0B8(void) {
    return D_00352CB8;
}

extern "C" int func_0022C0C8(S22B* self) {
    return self->unk10;
}

extern "C" void func_0022C0D0(S22B* self, int v) {
    self->unk10 = v;
}

extern "C" void func_0022C0D8(char* p, char* q) {
    char* o = *(char**)(p + 0x1C);
    if (o) {
        o[0xC] = o[0xC] - 1;
    }
    *(char**)(p + 0x1C) = q;
    if (q) {
        q[0xC] = q[0xC] + 1;
    }
}

extern "C" int func_0022C110(S22B* self) {
    return self->unk1C;
}

INCLUDE_ASM("asm/nonmatchings/game/t_22BD90", func_0022C118);

extern "C" int func_0022C120(S22B* self) {
    return self->unk20_24;
}

INCLUDE_ASM("asm/nonmatchings/game/t_22BD90", func_0022C130);

INCLUDE_ASM("asm/nonmatchings/game/t_22BD90", func_0022C210);

INCLUDE_ASM("asm/nonmatchings/game/t_22BD90", func_0022C308);

extern "C" int func_0022C380(char* p) {
    int r = 0;
    if (*(char**)(p + 0x30) == p + 0x2C) {
        if (*(u8*)(p + 0xC) == 0) {
            r = func_0022C120((S22B*)p) == 5;
        }
    }
    return r;
}

INCLUDE_ASM("asm/nonmatchings/game/t_22BD90", func_0022C3C8);

INCLUDE_ASM("asm/nonmatchings/game/t_22BD90", func_0022C498);

INCLUDE_ASM("asm/nonmatchings/game/t_22BD90", func_0022C4E8);

GP_DATA(D_00372E50);
extern "C" void func_0022C4F0(int a, int b) {
    if (b == 0xFFFF) {
        if (a) {
            func_001162E8(&D_00372E50);
            u16* d = (u16*)D_00393AD8;
            u16* t = d + 1;
            t[1] = 0;
            t[2] = 0;
        }
    }
}

extern "C" void func_0022C538(void) {
    func_0022C4F0(1, 0xFFFF);
}

INCLUDE_ASM("asm/nonmatchings/game/t_22BD90", func_0022C558);

INCLUDE_ASM("asm/nonmatchings/game/t_22BD90", func_0022C768);

INCLUDE_ASM("asm/nonmatchings/game/t_22BD90", func_0022C850);

INCLUDE_ASM("asm/nonmatchings/game/t_22BD90", func_0022CA20);

INCLUDE_ASM("asm/nonmatchings/game/t_22BD90", func_0022CB10);

INCLUDE_ASM("asm/nonmatchings/game/t_22BD90", func_0022CB18);

INCLUDE_ASM("asm/nonmatchings/game/t_22BD90", func_0022CBA8);

INCLUDE_ASM("asm/nonmatchings/game/t_22BD90", func_0022CBC0);

INCLUDE_ASM("asm/nonmatchings/game/t_22BD90", func_0022CC78);

extern "C" void* func_0022CD30(char* p) {
    func_0022BA90(p);
    *(int*)(p + 0x38) = 0;
    *(u8**)(p + 0x34) = D_00352F88;
    return p;
}

INCLUDE_ASM("asm/nonmatchings/game/t_22BD90", func_0022CD68);

INCLUDE_ASM("asm/nonmatchings/game/t_22BD90", func_0022CEF8);

INCLUDE_ASM("asm/nonmatchings/game/t_22BD90", func_0022CF80);

INCLUDE_ASM("asm/nonmatchings/game/t_22BD90", func_0022D048);

INCLUDE_ASM("asm/nonmatchings/game/t_22BD90", func_0022D0C0);

extern "C" void* func_0022D118(void) {
    return D_00352F78;
}

extern "C" int func_0022D128(void) {
    return 6;
}

INCLUDE_ASM("asm/nonmatchings/game/t_22BD90", func_0022D130);

INCLUDE_ASM("asm/nonmatchings/game/t_22BD90", func_0022D160);

INCLUDE_ASM("asm/nonmatchings/game/t_22BD90", func_0022D240);

INCLUDE_ASM("asm/nonmatchings/game/t_22BD90", func_0022D2C8);

INCLUDE_ASM("asm/nonmatchings/game/t_22BD90", func_0022D360);

INCLUDE_ASM("asm/nonmatchings/game/t_22BD90", func_0022D538);

extern "C" void* func_0022D5A0(void) {
    return D_0036F838;
}

extern "C" int func_0022D5B0(void) {
    return 3;
}

INCLUDE_ASM("asm/nonmatchings/game/t_22BD90", func_0022D5B8);

extern "C" int func_0022D5E0(void) {
    return 0xA4;
}

INCLUDE_ASM("asm/nonmatchings/game/t_22BD90", func_0022D5E8);

INCLUDE_ASM("asm/nonmatchings/game/t_22BD90", func_0022D6A0);

INCLUDE_ASM("asm/nonmatchings/game/t_22BD90", func_0022D728);

INCLUDE_ASM("asm/nonmatchings/game/t_22BD90", func_0022D7E0);

INCLUDE_ASM("asm/nonmatchings/game/t_22BD90", func_0022D940);

extern "C" void* func_0022D9A8(void) {
    return D_003532D0;
}

extern "C" int func_0022D9B8(void) {
    return 5;
}

INCLUDE_ASM("asm/nonmatchings/game/t_22BD90", func_0022D9C0);

extern "C" int func_0022D9E8(void) {
    return 0x98;
}

extern "C" void* func_0022D9F0(char* p) {
    func_0022BA90(p);
    *(int*)(p + 0x38) = 0;
    *(u8**)(p + 0x34) = D_00353480;
    return p;
}

INCLUDE_ASM("asm/nonmatchings/game/t_22BD90", func_0022DA28);

INCLUDE_ASM("asm/nonmatchings/game/t_22BD90", func_0022DAF0);

INCLUDE_ASM("asm/nonmatchings/game/t_22BD90", func_0022DBB0);

INCLUDE_ASM("asm/nonmatchings/game/t_22BD90", func_0022DC38);

INCLUDE_ASM("asm/nonmatchings/game/t_22BD90", func_0022DD30);
