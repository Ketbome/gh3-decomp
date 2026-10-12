#include "common.h"

struct S1F0010_M {
    char pad0[0x30];
    void* unk30;
};

struct S1F0010 {
    char pad0[0x1FC];
    s32 unk1FC;
    char pad200[0x10];
    S1F0010_M* unk210;
    char pad214[0x50];
    s32 unk264;
};

extern "C" {
void func_001EE608(void*, int, int, int);
void func_001EF5F0(void*, int);
void func_001F23E8(void*);
void func_001EDD30(void*);
void func_001F1D08(void*);
void func_001571F8(void*, int);
void func_001EF548(void*, void*);
void func_00160DE8(void*, u32);
s32 func_0027D268(void*, u32, f32*, int);
bool func_0027D870(void*, u32, s32*, int);
s32 func_0027D1F8(void*, u32, s32*, int);
void func_001EF688(void*, f32);
s32 func_001EE6F8(void*, s32);
void func_00157220(void*, s32, int);
void func_001619D8(void*, s32);
void func_0014E098(void*, char*);
void func_00113528(char*);
u32 func_00115028(char*);
void* func_00160170(void*, u32, int, int, int, int);
void func_0015F4B8(void*, s32);
}

extern "C" void func_001EF6D0(S1F0010* p) {
    func_001F1D08(p);
    p->unk264 = 0;
}

extern "C" void func_001EF6F8(S1F0010* p, int a, void* b, s32* c) {
    char buf[0x200];
    func_0014E098(b, buf);
    func_00113528(buf);
    void* r = func_00160170(p->unk210, func_00115028(buf), a, 0, 0, 1);
    if (r) {
        func_0015F4B8(r, *c);
    }
}

extern "C" void func_001EF780(void* p, int a) {
    func_001EE608(p, a, 1, 1);
}

extern "C" s32 func_001EF7A0(void* p) {
    func_001EF5F0(p, 1);
    return 1;
}

extern "C" s32 func_001EF7C0(void* p) {
    func_001EF5F0(p, 0);
    return 1;
}

INCLUDE_ASM("asm/nonmatchings/game/t_1EF6D0", func_001EF7E0);

INCLUDE_ASM("asm/nonmatchings/game/t_1EF6D0", func_001EF898);

INCLUDE_ASM("asm/nonmatchings/game/t_1EF6D0", func_001EF950);

INCLUDE_ASM("asm/nonmatchings/game/t_1EF6D0", func_001EF9A0);

INCLUDE_ASM("asm/nonmatchings/game/t_1EF6D0", func_001EFA78);

extern "C" s32 func_001EFB28(S1F0010* p) {
    if (p->unk210) {
        func_00160DE8(p->unk210, 0xC4E78E22);
    }
    return 1;
}

INCLUDE_ASM("asm/nonmatchings/game/t_1EF6D0", func_001EFB58);

INCLUDE_ASM("asm/nonmatchings/game/t_1EF6D0", func_001EFC60);

extern "C" s32 func_001EFD18(S1F0010* p, void* a) {
    if (p->unk210) {
        s32 s[3];
        s[0] = 0xC4E78E22;
        func_0027D268(a, 0xA6F5352F, (f32*)&s[1], 1);
        func_0027D870(a, 0x83418A6A, &s[2], 1);
        func_0027D870(a, 0xE7308C1F, &s[0], 0);
    }
    return 1;
}

INCLUDE_ASM("asm/nonmatchings/game/t_1EF6D0", func_001EFD98);

INCLUDE_ASM("asm/nonmatchings/game/t_1EF6D0", func_001EFF40);

extern "C" s32 func_001EFFF0(void* p) {
    func_001F23E8(p);
    return 1;
}

extern "C" bool func_001F0010(S1F0010* p) {
    return p->unk210->unk30 != 0;
}

extern "C" s32 func_001F0020() {
    return 1;
}

extern "C" s32 func_001F0028(S1F0010* p) {
    func_001571F8(p->unk210->unk30, 1);
    return 1;
}

extern "C" s32 func_001F0050(S1F0010* p) {
    func_001571F8(p->unk210->unk30, 0);
    return 1;
}

extern "C" s32 func_001F0078(S1F0010* p, void* a) {
    s32 v;
    func_0027D1F8(a, 0x7F8C98FE, &v, 0);
    func_00157220(p->unk210->unk30, v, 1);
    return 1;
}

extern "C" s32 func_001F00C8(S1F0010* p, void* a) {
    s32 v;
    func_0027D1F8(a, 0x7F8C98FE, &v, 0);
    func_00157220(p->unk210->unk30, v, 0);
    return 1;
}

INCLUDE_ASM("asm/nonmatchings/game/t_1EF6D0", func_001F0118);

INCLUDE_ASM("asm/nonmatchings/game/t_1EF6D0", func_001F01D0);

INCLUDE_ASM("asm/nonmatchings/game/t_1EF6D0", func_001F0360);

INCLUDE_ASM("asm/nonmatchings/game/t_1EF6D0", func_001F0438);

INCLUDE_ASM("asm/nonmatchings/game/t_1EF6D0", func_001F04F8);

extern "C" bool func_001F07A8(S1F0010* p) {
    p->unk1FC = 1;
    return true;
}

extern "C" s32 func_001F07B8(S1F0010* p) {
    p->unk1FC = 0;
    return 1;
}

extern "C" s32 func_001F07C8(void* p) {
    func_001EDD30(p);
    return 1;
}

INCLUDE_ASM("asm/nonmatchings/game/t_1EF6D0", func_001F07E8);

INCLUDE_ASM("asm/nonmatchings/game/t_1EF6D0", func_001F08D8);

extern "C" s32 func_001F0950(void* p, void* a) {
    s32 v = 0;
    func_0027D870(a, 0, &v, 1);
    func_001EF780(p, v);
    return 1;
}

extern "C" s32 func_001F0998(void* p, void* a) {
    s32 v = 0;
    func_0027D870(a, 0, &v, 1);
    func_001EE608(p, v, 0, 1);
    return 1;
}

extern "C" bool func_001F09E8(void* p, void* a) {
    s32 v = 0;
    func_0027D870(a, 0, &v, 1);
    return func_001EE6F8(p, v) != 0;
}

INCLUDE_ASM("asm/nonmatchings/game/t_1EF6D0", func_001F0A30);

extern "C" s32 func_001F0B00(void* p, void* a) {
    f32 v;
    func_0027D268(a, 0, &v, 1);
    func_001EF688(p, v);
    return 1;
}

INCLUDE_ASM("asm/nonmatchings/game/t_1EF6D0", func_001F0B48);

INCLUDE_ASM("asm/nonmatchings/game/t_1EF6D0", func_001F0B70);

INCLUDE_ASM("asm/nonmatchings/game/t_1EF6D0", func_001F0EF8);

INCLUDE_ASM("asm/nonmatchings/game/t_1EF6D0", func_001F0FC8);

INCLUDE_ASM("asm/nonmatchings/game/t_1EF6D0", func_001F10D0);

INCLUDE_ASM("asm/nonmatchings/game/t_1EF6D0", func_001F16C0);
