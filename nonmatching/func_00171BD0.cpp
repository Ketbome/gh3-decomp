#include "common.h"

extern "C" {
void func_001999C8(void);
void func_00199AA0(void);
void func_00199B88(void);
}

INCLUDE_ASM("asm/nonmatchings/game/t_1707C0", func_001707C0);

INCLUDE_ASM("asm/nonmatchings/game/t_1707C0", func_001708F8);

INCLUDE_ASM("asm/nonmatchings/game/t_1707C0", func_00170940);

INCLUDE_ASM("asm/nonmatchings/game/t_1707C0", func_00170B00);

extern "C" void func_001711B8(void) {
    func_001999C8();
}

INCLUDE_ASM("asm/nonmatchings/game/t_1707C0", func_001711D8);

INCLUDE_ASM("asm/nonmatchings/game/t_1707C0", func_00171540);

INCLUDE_ASM("asm/nonmatchings/game/t_1707C0", func_001715F8);

INCLUDE_ASM("asm/nonmatchings/game/t_1707C0", func_00171708);

INCLUDE_ASM("asm/nonmatchings/game/t_1707C0", func_00171928);

extern "C" void func_00171BB0(void) {
    func_00199AA0();
}

typedef unsigned int u128_171 __attribute__((mode(TI)));

static inline f32 GetX171(u128_171 q) {
    f32 f;
    asm("mtc1 %1, %0" : "=f"(f) : "r"(q));
    return f;
}
static inline f32 GetY171(u128_171 q) {
    f32 f;
    asm("dsrl32 %0, %1, 0" : "=r"(f) : "0"(q));
    return f;
}
static inline f32 GetZ171(u128_171 q) {
    f32 f;
    asm("pcpyud %0, %1, %1" : "=r"(f) : "0"(q));
    return f;
}

struct S_00171BD0 { u32 unk0; char pad4[0x14]; float unk18; float unk1C; float unk20; float unk24; char pad28[8]; u128_171 unk30; u128_171 unk40; u128_171 unk50; char pad60[0x10]; int unk70; };

extern "C" {
void func_0027C160(int, u32, int);
void func_0027C1F8(int, u32, float);
int func_00138790(int, int);
int func_0027E698(int);
void func_0027E760(int, int, int);
void func_0027EE08(int, int, float);
void func_0027C678(int, u32, int);
}

extern "C" void func_00171BD0(S_00171BD0* self, int props) {
    func_0027C160(props, 0xF649D637, self->unk70 != 0);
    func_0027C1F8(props, 0xD5D55277, self->unk1C);
    func_0027C1F8(props, 0x2689291C, self->unk18);
    func_0027C1F8(props, 0x5CB2C5F7, self->unk20);
    func_0027C1F8(props, 0x29EAA411, self->unk24);
    int a = func_0027E698(func_00138790(0xC, 1));
    int b = func_0027E698(func_00138790(0xC, 1));
    int c = func_0027E698(func_00138790(0xC, 1));
    func_0027E760(a, 3, 2);
    func_0027E760(b, 3, 2);
    func_0027E760(c, 3, 2);
    func_0027EE08(a, 0, GetX171(self->unk30));
    func_0027EE08(a, 1, GetY171(self->unk30));
    func_0027EE08(a, 2, GetZ171(self->unk30));
    func_0027EE08(b, 0, GetX171(self->unk40));
    func_0027EE08(b, 1, GetY171(self->unk40));
    func_0027EE08(b, 2, GetZ171(self->unk40));
    func_0027EE08(c, 0, GetX171(self->unk50));
    func_0027EE08(c, 1, GetY171(self->unk50));
    func_0027EE08(c, 2, GetZ171(self->unk50));
    func_0027C678(props, 0x146FC080, a);
    func_0027C678(props, 0x51B4CB31, b);
    func_0027C678(props, 0x77B8ABE9, c);
    func_0027C1F8(props, 0x906B67BA, (float)self->unk0);
}

INCLUDE_ASM("asm/nonmatchings/game/t_1707C0", func_00171E60);

struct S171F08 { char pad0[0x18]; int unk18; char pad1C[8]; float unk24; };

extern "C" int func_00171F08(S171F08* self) {
    int r = 0;
    if (self->unk18 != 0 && self->unk24 > 0.0f) r = 1;
    return r;
}

INCLUDE_ASM("asm/nonmatchings/game/t_1707C0", func_00171F38);

INCLUDE_ASM("asm/nonmatchings/game/t_1707C0", func_00172098);

extern "C" void func_001724D0(void) {
    func_00199B88();
}

INCLUDE_ASM("asm/nonmatchings/game/t_1707C0", func_001724F0);
