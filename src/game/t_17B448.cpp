// cflags: -funroll-loops
#include "common.h"

struct S0017B460 {
    char pad[0x14];
    void* unk14;
};

extern "C" {
int func_00172CC0(void*, u32, int);
int func_0027D268(int, u32, void*, int);
int func_0027D470(int, u32, void*, int);
int func_0027D870(int, u32, void*, int);
float func_00220270(int, int);
void func_0017D0E0(void*, float, int);
extern u8 D_00342B38[];
void func_00172A00(void*);
extern u8 D_00342CB8[];
extern u8 D_00342E28[];
}

INCLUDE_ASM("asm/nonmatchings/game/t_17B448", func_0017B448);

extern "C" void func_0017B460(S0017B460* self) {
    self->unk14 = D_00342B38;
    func_00172A00(self);
}

INCLUDE_ASM("asm/nonmatchings/game/t_17B448", func_0017B488);

struct S17B528 { int unk0[0x82]; int unk208; };

extern "C" void func_0017B528(S17B528* self, int v) {
    int n = self->unk208;
    self->unk0[n] = v;
    self->unk208 = n + 1;
}

INCLUDE_ASM("asm/nonmatchings/game/t_17B448", func_0017B548);

extern "C" void func_0017B678(S17B528* self) {
    int i;
    for (i = 0; i < self->unk208; i++) {
    }
}

INCLUDE_ASM("asm/nonmatchings/game/t_17B448", func_0017B6E0);

INCLUDE_ASM("asm/nonmatchings/game/t_17B448", func_0017B810);

extern "C" void func_0017BAE8(void) {
}

extern "C" u32 func_0017BAF0(void) {
    return 0x1BF9C2D5 /* applydifference */;
}

extern "C" void func_0017BB00(S0017B460* self) {
    self->unk14 = D_00342CB8;
    func_00172A00(self);
}

INCLUDE_ASM("asm/nonmatchings/game/t_17B448", func_0017BB28);

INCLUDE_ASM("asm/nonmatchings/game/t_17B448", func_0017BD50);

extern "C" void func_0017C1C0(void) {
}

extern "C" u32 func_0017C1C8(void) {
    return 0x02E58C18 /* ADD */;
}

extern "C" void func_0017C1D8(S0017B460* self) {
    self->unk14 = D_00342E28;
    func_00172A00(self);
}

INCLUDE_ASM("asm/nonmatchings/game/t_17B448", func_0017C200);

INCLUDE_ASM("asm/nonmatchings/game/t_17B448", func_0017C800);

INCLUDE_ASM("asm/nonmatchings/game/t_17B448", func_0017CA00);

struct S17CFB8 { char pad0[0xC]; int unkC; char pad10[8]; float unk18; };

extern "C" int func_0017CFB8(S17CFB8* self, u32 key, int p) {
    int t;
    float f;
    int n;
    switch (key) {
    case 0xB899A41D:
        func_0027D268(p, 0x29461E27, &self->unk18, 0);
        return 1;
    case 0xD05EEC52:
        f = 0.3f;
        if (func_0027D870(p, 0x98549BA4, &t, 0)) {
            f = func_00220270(self->unkC, t);
        } else {
            func_0027D268(p, 0xBF237659, &f, 0);
            func_0027D268(p, 0x25356C3B, &f, 0);
        }
        n = 0;
        func_0027D470(p, 0x326C4FF5, &n, 0);
        func_0017D0E0(self, f, n);
        return 1;
    default:
        return func_00172CC0(self, key, p);
    }
}

INCLUDE_ASM("asm/nonmatchings/game/t_17B448", func_0017D0E0);

INCLUDE_ASM("asm/nonmatchings/game/t_17B448", func_0017D2B0);
