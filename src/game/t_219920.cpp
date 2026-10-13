#include "common.h"

typedef int TI128 __attribute__((mode(TI)));

struct VEntry219 {
    s16 delta;
    s16 unk2;
    void* fn;
};

struct S219c {
    char pad0[0xC0];
    int unkC0;
    char padC4[0x21C];
    u64 unk2E0_0 : 14;
    u64 unk2E0_14 : 1;
    u64 unk2E0_15 : 3;
    u64 unk2E0_18 : 1;
};

struct S219b {
    char pad0[0x8];
    VEntry219* unk8;
};

struct S219 {
    char pad0[0xC];
    S219b* unkC;
    char pad10[0x8];
    VEntry219* unk18;
    S219c* unk1C;
    char pad20[0x2C];
    int unk4C;
    char pad50[0x4];
    void* unk54;
    char pad58[0x20];
    f32 unk78;
};

extern "C" {
void func_0021A750(int, int);
void func_0021B0F8(int, int);
void func_0021B290(S219*, int);
void func_0021B6B8(int, int);
void func_00163B00(void*, int);
int func_00163B50(void*);
int func_001D1CF8(void*, u32);
void func_00205B00(void*);
int func_0027D268(int, int, void*, int);
int func_0027D470(int, int, void*, int);
void func_0021B368(void*, int);
int func_0027D2D8(int, u32, void*, int);
}

INCLUDE_ASM("asm/nonmatchings/game/t_219920", func_00219920);

extern "C" void func_00219C50(S219* self, int a) {
    VEntry219* e = &self->unk18[3];
    ((void (*)(void*, int))e->fn)((char*)self + e->delta, a);
}

extern "C" void func_00219C78(char* p) {
    void* r = (void*)func_001D1CF8(*(void**)(p + 0xC), 0xCE0CA665);
    *(void**)(p + 0x54) = r;
    if (r) {
        func_00205B00(r);
    }
}

extern "C" void func_00219CB8(S219* self) {
    if (self->unk1C) {
        func_00163B00(self->unk1C, 0);
    }
}

INCLUDE_ASM("asm/nonmatchings/game/t_219920", func_00219CE0);

extern "C" void func_00219D38(S219* self, int v) {
    S219c* p = self->unk1C;
    if (p) {
        p->unk2E0_18 = v;
    }
}

extern "C" void func_00219D68(void) {
}

INCLUDE_ASM("asm/nonmatchings/game/t_219920", func_00219D70);

INCLUDE_ASM("asm/nonmatchings/game/t_219920", func_0021A100);

INCLUDE_ASM("asm/nonmatchings/game/t_219920", func_0021A198);

extern "C" void func_0021A230(void) {
}

extern "C" int func_0021A238(S219* self) {
    if (self->unk1C) {
        return func_00163B50(self->unk1C);
    }
    return 0;
}

INCLUDE_ASM("asm/nonmatchings/game/t_219920", func_0021A260);

INCLUDE_ASM("asm/nonmatchings/game/t_219920", func_0021A298);

extern "C" int func_0021A320(S219* self) {
    if (self->unk1C) {
        self->unk1C->unkC0 = 0;
    }
    return 1;
}

INCLUDE_ASM("asm/nonmatchings/game/t_219920", func_0021A338);

extern "C" int func_0021A3F8(char* p) {
    char* t = *(char**)(p + 0x1C);
    if (t) {
        int r = 0;
        if ((*(u64*)(t + 0x2E0) & 0x4000) || *(f32*)(t + 0xA8) > 0.0f) {
            r = 1;
        }
        return r;
    }
    return 0;
}

inline void set_0021A448(S219c* p, int v) {
    p->unk2E0_14 = v;
}

extern "C" int func_0021A448(S219* self) {
    S219c* p = self->unk1C;
    if (p) {
        set_0021A448(p, 1);
    }
    return 1;
}

extern "C" int func_0021A470(S219* self) {
    S219c* p = self->unk1C;
    if (p) {
        p->unk2E0_14 = 0;
    }
    return 1;
}

INCLUDE_ASM("asm/nonmatchings/game/t_219920", func_0021A490);

extern "C" int func_0021A510(S219* self, int a, int b) {
    VEntry219* e = &self->unk18[3];
    ((void (*)(void*, int))e->fn)((char*)self + e->delta, b);
    return 1;
}

INCLUDE_ASM("asm/nonmatchings/game/t_219920", func_0021A540);

INCLUDE_ASM("asm/nonmatchings/game/t_219920", func_0021A698);

INCLUDE_ASM("asm/nonmatchings/game/t_219920", func_0021A748);

INCLUDE_ASM("asm/nonmatchings/game/t_219920", func_0021A750);

extern "C" int func_0021AEA0(void) {
    return 0;
}

extern "C" int func_0021AEA8(void) {
    return 0;
}

extern "C" void func_0021AEB0(void) {
    func_0021A750(1, 0xFFFF);
}

INCLUDE_ASM("asm/nonmatchings/game/t_219920", func_0021AED0);

INCLUDE_ASM("asm/nonmatchings/game/t_219920", func_0021AFD8);

INCLUDE_ASM("asm/nonmatchings/game/t_219920", func_0021B058);

extern "C" int func_0021B0A0(char** p, int a) {
    TI128 v;
    func_0027D2D8(a, 0xC4C809E, &v, 1);
    *(TI128*)(p[3] + 0xE0) = v;
    return 1;
}

INCLUDE_ASM("asm/nonmatchings/game/t_219920", func_0021B0E8);

INCLUDE_ASM("asm/nonmatchings/game/t_219920", func_0021B0F8);

extern "C" void func_0021B250(void) {
    func_0021B0F8(1, 0xFFFF);
}

INCLUDE_ASM("asm/nonmatchings/game/t_219920", func_0021B270);

INCLUDE_ASM("asm/nonmatchings/game/t_219920", func_0021B290);

extern "C" void func_0021B360(S219* self, f32 v) {
    self->unk78 = v;
}

INCLUDE_ASM("asm/nonmatchings/game/t_219920", func_0021B368);

extern "C" int func_0021B5E8(S219* self) {
    func_0021B290(self, 1);
    return 1;
}

extern "C" int func_0021B608(S219* self) {
    func_0021B290(self, 0);
    return 1;
}

extern "C" int func_0021B628(S219* self, int a) {
    f32 x;
    func_0027D268(a, 0, &x, 1);
    func_0021B360(self, x);
    return 1;
}

extern "C" int func_0021B670(S219* self, int a) {
    int x;
    func_0027D470(a, 0, &x, 1);
    func_0021B368(self, x);
    return 1;
}

INCLUDE_ASM("asm/nonmatchings/game/t_219920", func_0021B6B8);

extern "C" void func_0021B810(void) {
    func_0021B6B8(1, 0xFFFF);
}

INCLUDE_ASM("asm/nonmatchings/game/t_219920", func_0021B830);

extern "C" S219* func_0021B870(S219* self) {
    self->unk4C = 0;
    return self;
}

INCLUDE_ASM("asm/nonmatchings/game/t_219920", func_0021B880);

INCLUDE_ASM("asm/nonmatchings/game/t_219920", func_0021B8E8);
