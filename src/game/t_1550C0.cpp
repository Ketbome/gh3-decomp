#include "common.h"

struct S_001563B0 { char pad0[0x60]; int unk60; };

typedef unsigned int u128_155 __attribute__((mode(TI)));

struct E160_155 { u64 unk0; char pad8[0x158]; };
struct EB0_155 { char pad0[0x90]; int unk90; char pad94[4]; const char* unk98; int unk9C; char padA0[0x10]; };
struct VE_155 { s16 delta; s16 unk2; void* fn; };
struct O_155 { char pad0[0x20]; VE_155* unk20; };
struct S90_155 { char pad0[0x90]; int unk90; };
struct S20_155 { char pad0[0x14]; void* unk14; char pad18[8]; void* unk20; };
struct S60_155 { char pad0[0x60]; int unk60; };

extern "C" {
void func_00156CB8(float, float, float, float);
extern int D_00368A38;
void* func_00118F20(int, int, int, int);
void* func_00156FD8(void*);
void func_00155788(void*);
void* func_00223BF0(void*);
void* func_001552F0_p(void*) __asm__("func_001552F0");
extern EB0_155 D_00378220[];
int func_001550C0(const char*);
void func_00154750(void*);
void func_001547C8(void*, int);
int func_001551A8_p(void*) __asm__("func_001551A8");
extern int D_00369BE8;
extern S60_155* D_0032A558[];
EB0_155* func_001566B8(const char*);
extern int D_00369BEC;
extern u8 D_0033CBF8[];
void func_00119400(int, void*);
extern u128_155 D_00378210;
void func_001551A8(void);
void func_001561C8(int);
void func_00156878(int, int);
void* func_00113D20(u32 size);
void* func_00154670(void*);
}

struct S_00156FA8 { char pad0[0x160]; };

GP_DATA(D_00369BEC);
extern "C" int func_001550C0(const char* name) {
    EB0_155* e = func_001566B8(name);
    if (e) {
        return e->unk90;
    }
    int i = D_00369BEC;
    D_00369BEC = i + 1;
    EB0_155* n = &D_00378220[i];
    n->unk9C = 2;
    n->unk90 = i;
    D_00378220[i].unk98 = name;
    return i;
}

extern "C" u128_155 func_00155128(void) {
    return D_00378210;
}

extern "C" void* func_00155138(void) {
    return func_00156FD8(func_00118F20(D_00368A38, 0x24, 1, 0));
}

extern "C" int func_00155170(O_155* obj) {
    if (obj) {
        VE_155* e = &obj->unk20[1];
        ((void (*)(void*, int))e->fn)((char*)obj + e->delta, 3);
    }
    return 1;
}

INCLUDE_ASM("asm/nonmatchings/game/t_1550C0", func_001551A8);

INCLUDE_ASM("asm/nonmatchings/game/t_1550C0", func_00155290);

INCLUDE_ASM("asm/nonmatchings/game/t_1550C0", func_001552E8);

extern "C" void func_001552F0(void) {
    func_001551A8();
}

INCLUDE_ASM("asm/nonmatchings/game/t_1550C0", func_00155310);

extern "C" void* func_00155640(void) {
    return func_00154670(func_00113D20(0x90));
}

extern "C" void* func_00155668(void* self) {
    func_00155788(self);
    return func_001552F0_p(func_00223BF0(self));
}

INCLUDE_ASM("asm/nonmatchings/game/t_1550C0", func_001556A0);

INCLUDE_ASM("asm/nonmatchings/game/t_1550C0", func_001556A8);

INCLUDE_ASM("asm/nonmatchings/game/t_1550C0", func_00155788);

INCLUDE_ASM("asm/nonmatchings/game/t_1550C0", func_00155D40);

INCLUDE_ASM("asm/nonmatchings/game/t_1550C0", func_001561C8);

extern "C" void func_001563B0(S_001563B0* self) {
    func_001561C8(self->unk60);
}

INCLUDE_ASM("asm/nonmatchings/game/t_1550C0", func_001563D0);

INCLUDE_ASM("asm/nonmatchings/game/t_1550C0", func_00156470);

extern "C" void func_00156550(S90_155* self, void* x) {
    func_00154750(x);
    func_001547C8(x, self->unk90);
}

extern "C" void func_00156590(const char* name, int v) {
    int i = func_001550C0(name);
    EB0_155* e = &D_00378220[i];
    e->unk9C = v;
}

INCLUDE_ASM("asm/nonmatchings/game/t_1550C0", func_001565D0);

INCLUDE_ASM("asm/nonmatchings/game/t_1550C0", func_001566B8);

INCLUDE_ASM("asm/nonmatchings/game/t_1550C0", func_00156790);

INCLUDE_ASM("asm/nonmatchings/game/t_1550C0", func_00156870);

INCLUDE_ASM("asm/nonmatchings/game/t_1550C0", func_00156878);

INCLUDE_ASM("asm/nonmatchings/game/t_1550C0", func_00156978);

INCLUDE_ASM("asm/nonmatchings/game/t_1550C0", func_00156AB0);

extern "C" void func_00156B40(void) {
    func_00156878(1, 0xFFFF);
}

INCLUDE_ASM("asm/nonmatchings/game/t_1550C0", func_00156B60);

extern "C" void func_00156C88(float a, float b, float c) {
    func_00156CB8(0.0f, a, b, c);
}

INCLUDE_ASM("asm/nonmatchings/game/t_1550C0", func_00156CB8);

INCLUDE_ASM("asm/nonmatchings/game/t_1550C0", func_00156DF8);

INCLUDE_ASM("asm/nonmatchings/game/t_1550C0", func_00156E00);

struct B_00156ED0 { u64 f0 : 1; u64 f1 : 63; };

extern "C" int func_00156ED0(char* p) {
    int n = 0;
    for (;;) {
        if (!((B_00156ED0*)(p + 0x0))->f0) {
            ((B_00156ED0*)(p + 0x0))->f0 = 1;
            return n + 1;
        }
        if (!((B_00156ED0*)(p + 0x160))->f0) {
            ((B_00156ED0*)(p + 0x160))->f0 = 1;
            return n + 2;
        }
        if (!((B_00156ED0*)(p + 0x2c0))->f0) {
            ((B_00156ED0*)(p + 0x2c0))->f0 = 1;
            return n + 3;
        }
        if (!((B_00156ED0*)(p + 0x420))->f0) {
            ((B_00156ED0*)(p + 0x420))->f0 = 1;
            return n + 4;
        }
        if (((B_00156ED0*)(p + 0x580))->f0) {
            n += 5;
            p += 0x6E0;
            if (n >= 0x1E) return 0;
            continue;
        }
        ((B_00156ED0*)(p + 0x580))->f0 = 1;
        return n + 5;
    }
}

INCLUDE_ASM("asm/nonmatchings/game/t_1550C0", func_00156F80);

extern "C" S_00156FA8* func_00156FA8(S_00156FA8* p, int n) {
    n--;
    return &p[n];
}
TEXT_PAD(12);

INCLUDE_ASM("asm/nonmatchings/game/t_1550C0", func_00156FC8);

INCLUDE_ASM("asm/nonmatchings/game/t_1550C0", func_00156FD8);

extern "C" void func_00157098(S20_155* self, int flags) {
    self->unk20 = D_0033CBF8;
    if (self->unk14) {
        func_00119400(D_00368A38, self->unk14);
        self->unk14 = 0;
    }
    if (flags & 1) {
        func_00119400(D_00368A38, self);
    }
}
