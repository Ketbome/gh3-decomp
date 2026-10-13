#include "common.h"

struct VEntry21F {
    s16 delta;
    s16 unk2;
    void* fn;
};

struct S21Fb {
    char pad0[0x1C];
    void* unk1C;
};

struct S21F {
    char pad0[0xC];
    int unkC;
    char pad10[0x8];
    VEntry21F* unk18;
    void* unk1C;
    char pad20[0x14];
    char unk34[0x4];
    int unk38;
    S21Fb* unk3C;
    char pad40[0x24];
    void* unk64;
};

extern "C" {
void* func_00113D20(u32 size);
void* func_00221A88(void*);
void func_00276D68(u32, void*, int);
extern u8 D_00390790[];
void func_001F62D0(void*);
void func_001F6440(void*);
void func_00220948(S21F*, int);
S21F* func_001D1CF8(void*, u32);
void* func_00133F60(void*);
void func_001150E0(void*, void*);
extern u8 D_00351D18[];
void func_0012FA98(void*, int);
void func_0012FAC8(void*, int, int);
int func_00205B48(int, int);
}

INCLUDE_ASM("asm/nonmatchings/game/t_21FB88", func_0021FB88);

INCLUDE_ASM("asm/nonmatchings/game/t_21FB88", func_0021FDB0);

INCLUDE_ASM("asm/nonmatchings/game/t_21FB88", func_0021FEF0);

extern "C" void func_00220108(void) {
}

extern "C" void func_00220110(void) {
}

extern "C" void func_00220118(S21F* self, void* a) {
    VEntry21F* e;
    self->unk1C = a;
    e = &self->unk18[8];
    ((void (*)(void*, int))e->fn)((char*)self + e->delta, 0);
}

INCLUDE_ASM("asm/nonmatchings/game/t_21FB88", func_00220148);

INCLUDE_ASM("asm/nonmatchings/game/t_21FB88", func_00220270);

INCLUDE_ASM("asm/nonmatchings/game/t_21FB88", func_00220318);

INCLUDE_ASM("asm/nonmatchings/game/t_21FB88", func_002204D0);

extern "C" void func_002204D8(S21F* p) {
    u8* d = D_00351D18;
    func_001150E0(func_00133F60(p->unk3C->unk1C), d);
}

extern "C" void func_00220518(char* p, int a1, int a2) {
    if (*(int*)(p + 0x38)) func_0012FA98(p + 0x34, *(int*)(p + 0xC));
    *(int*)(p + 0x38) = a2;
    func_0012FAC8(p + 0x34, a1, *(int*)(p + 0xC));
}

extern "C" void func_00220578(S21F* p, int a) {
    if (p->unk38 == a) {
        func_0012FA98(p->unk34, p->unkC);
        p->unk38 = 0;
    }
}

INCLUDE_ASM("asm/nonmatchings/game/t_21FB88", func_002205B8);

INCLUDE_ASM("asm/nonmatchings/game/t_21FB88", func_002206C8);

extern "C" void func_002207F0(S21F* p) {
    func_001F62D0(p->unk3C);
    func_00220948(p, 0);
}

extern "C" void func_00220828(S21F* p) {
    func_001F6440(p->unk3C);
    func_00220948(p, 1);
}

extern "C" void* func_00220860(S21F* self) {
    if (!self->unk64) {
        return self->unk1C;
    }
    return func_001D1CF8(self->unk64, 0x8536DBA5)->unk1C;
}

INCLUDE_ASM("asm/nonmatchings/game/t_21FB88", func_00220898);

INCLUDE_ASM("asm/nonmatchings/game/t_21FB88", func_00220948);

struct BF21F {
    u64 pad : 1;
    u64 b0 : 1;
    u64 b1 : 1;
    bool B0() { return b0; }
    bool B1() { return b1; }
};

extern "C" void func_00220A80(char* p) {
    if (*(int*)(p + 0x20) == 0) {
        *(int*)(p + 0x54) = 0;
        return;
    }
    char* o = *(char**)(p + 0x40);
    if (o) {
        BF21F f = *(BF21F*)(*(char**)(o + 0x210) + 0x50);
        int v = 0;
        if (f.B0()) v = f.B1() ^ 1;
        if (!v) {
            *(int*)(p + 0x54) = 0;
            return;
        }
    }
    if (*(int*)(p + 0x44)) {
        *(int*)(p + 0x54) = func_00205B48(*(int*)(p + 0x44), 0);
    } else {
        *(int*)(p + 0x54) = 1;
    }
}

INCLUDE_ASM("asm/nonmatchings/game/t_21FB88", func_00220B10);

INCLUDE_ASM("asm/nonmatchings/game/t_21FB88", func_00220FE8);

INCLUDE_ASM("asm/nonmatchings/game/t_21FB88", func_002210B8);

INCLUDE_ASM("asm/nonmatchings/game/t_21FB88", func_00221178);

INCLUDE_ASM("asm/nonmatchings/game/t_21FB88", func_002212B8);

INCLUDE_ASM("asm/nonmatchings/game/t_21FB88", func_00221310);

INCLUDE_ASM("asm/nonmatchings/game/t_21FB88", func_00221318);

INCLUDE_ASM("asm/nonmatchings/game/t_21FB88", func_002219D8);

extern "C" int func_00221A00(void) {
    return 1;
}

extern "C" int func_00221A08(void) {
    return 1;
}

extern "C" int func_00221A10(void) {
    return 1;
}

extern "C" int func_00221A18(void) {
    return 1;
}

extern "C" int func_00221A20(void) {
    return 1;
}

extern "C" int func_00221A28(void) {
    return 1;
}

extern "C" void* func_00221A30(void) {
    return func_00221A88(func_00113D20(0x40));
}

extern "C" void func_00221A58(void) {
    func_00276D68(0xB38129F1, D_00390790, 0x10);
}

INCLUDE_ASM("asm/nonmatchings/game/t_21FB88", func_00221A88);
