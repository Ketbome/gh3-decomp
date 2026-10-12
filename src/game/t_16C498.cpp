#include "common.h"

struct VEntry {
    s16 delta;
    s16 unk2;
    void* fn;
};

struct S0016C8C8 {
    char pad0[0x8];
    VEntry* unk8;
    char padC[0x40];
    float unk4C;
};

struct S0016CA18 {
    char pad0[0x8];
    VEntry* unk8;
    char padC[0x144];
    float unk150;
};

struct S0016C4E8 {
    char pad[0x10];
    char unk10;
};

struct S0016C6A8 {
    char pad[0x40];
    float unk40;
};

struct S0016C6B0 {
    char pad[0x44];
    float unk44;
};

struct S0016C6B8 {
    char pad[0x48];
    float unk48;
};

extern "C" {
void func_0016D318(int, int);
void func_0016D3E8(int, int);
}

INCLUDE_ASM("asm/nonmatchings/game/t_16C498", func_0016C498);

INCLUDE_ASM("asm/nonmatchings/game/t_16C498", func_0016C4A0);

extern "C" void* func_0016C4E8(S0016C4E8* self) {
    return &self->unk10;
}

INCLUDE_ASM("asm/nonmatchings/game/t_16C498", func_0016C4F0);

INCLUDE_ASM("asm/nonmatchings/game/t_16C498", func_0016C4F8);

INCLUDE_ASM("asm/nonmatchings/game/t_16C498", func_0016C5C0);

INCLUDE_ASM("asm/nonmatchings/game/t_16C498", func_0016C620);

INCLUDE_ASM("asm/nonmatchings/game/t_16C498", func_0016C638);

INCLUDE_ASM("asm/nonmatchings/game/t_16C498", func_0016C650);

extern "C" void func_0016C6A8(S0016C6A8* self, float v) {
    self->unk40 = v;
}

extern "C" void func_0016C6B0(S0016C6B0* self, float v) {
    self->unk44 = v;
}

extern "C" void func_0016C6B8(S0016C6B8* self, float v) {
    self->unk48 = v;
}

INCLUDE_ASM("asm/nonmatchings/game/t_16C498", func_0016C6C0);

INCLUDE_ASM("asm/nonmatchings/game/t_16C498", func_0016C6D0);

INCLUDE_ASM("asm/nonmatchings/game/t_16C498", func_0016C6E8);

INCLUDE_ASM("asm/nonmatchings/game/t_16C498", func_0016C798);

INCLUDE_ASM("asm/nonmatchings/game/t_16C498", func_0016C7B0);

INCLUDE_ASM("asm/nonmatchings/game/t_16C498", func_0016C878);

extern "C" void func_0016C8C8(S0016C8C8* self, float f0) {
    self->unk4C = f0;
    VEntry* e = &self->unk8[6];
    ((void (*)(void*, float))e->fn)((char*)self + e->delta, f0);
}

INCLUDE_ASM("asm/nonmatchings/game/t_16C498", func_0016C8F8);

INCLUDE_ASM("asm/nonmatchings/game/t_16C498", func_0016C9C0);

extern "C" void func_0016CA18(S0016CA18* self, float f0) {
    self->unk150 = f0;
    VEntry* e = &self->unk8[6];
    ((void (*)(void*, float))e->fn)((char*)self + e->delta, f0);
}

extern "C" void func_0016CA48(void) {
}

extern "C" void func_0016CA50(void) {
}

extern "C" void func_0016CA58(void) {
}

extern "C" int func_0016CA60(void) {
    return 1;
}

extern "C" int func_0016CA68(void) {
    return 0;
}

extern "C" void func_0016CA70(void) {
}

INCLUDE_ASM("asm/nonmatchings/game/t_16C498", func_0016CA78);

INCLUDE_ASM("asm/nonmatchings/game/t_16C498", func_0016CA80);

extern "C" int func_0016CCA8(void) {
    return 0;
}

INCLUDE_ASM("asm/nonmatchings/game/t_16C498", func_0016CCB0);

INCLUDE_ASM("asm/nonmatchings/game/t_16C498", func_0016CD28);

INCLUDE_ASM("asm/nonmatchings/game/t_16C498", func_0016CDF0);

INCLUDE_ASM("asm/nonmatchings/game/t_16C498", func_0016CF48);

INCLUDE_ASM("asm/nonmatchings/game/t_16C498", func_0016D060);

INCLUDE_ASM("asm/nonmatchings/game/t_16C498", func_0016D0D0);

INCLUDE_ASM("asm/nonmatchings/game/t_16C498", func_0016D0F8);

INCLUDE_ASM("asm/nonmatchings/game/t_16C498", func_0016D108);

INCLUDE_ASM("asm/nonmatchings/game/t_16C498", func_0016D130);

INCLUDE_ASM("asm/nonmatchings/game/t_16C498", func_0016D138);

INCLUDE_ASM("asm/nonmatchings/game/t_16C498", func_0016D318);

extern "C" void func_0016D350(void) {
    func_0016D318(1, 65535);
}

INCLUDE_ASM("asm/nonmatchings/game/t_16C498", func_0016D370);

INCLUDE_ASM("asm/nonmatchings/game/t_16C498", func_0016D3E8);

extern "C" void func_0016D448(void) {
    func_0016D3E8(1, 65535);
}

INCLUDE_ASM("asm/nonmatchings/game/t_16C498", func_0016D468);

INCLUDE_ASM("asm/nonmatchings/game/t_16C498", func_0016D4B0);

INCLUDE_ASM("asm/nonmatchings/game/t_16C498", func_0016D4B8);

INCLUDE_ASM("asm/nonmatchings/game/t_16C498", func_0016DD90);

INCLUDE_ASM("asm/nonmatchings/game/t_16C498", func_0016DDA0);

INCLUDE_ASM("asm/nonmatchings/game/t_16C498", func_0016DDB0);

INCLUDE_ASM("asm/nonmatchings/game/t_16C498", func_0016DDD8);

INCLUDE_ASM("asm/nonmatchings/game/t_16C498", func_0016DFB8);

INCLUDE_ASM("asm/nonmatchings/game/t_16C498", func_0016E070);

INCLUDE_ASM("asm/nonmatchings/game/t_16C498", func_0016E120);

INCLUDE_ASM("asm/nonmatchings/game/t_16C498", func_0016E168);

INCLUDE_ASM("asm/nonmatchings/game/t_16C498", func_0016E170);

INCLUDE_ASM("asm/nonmatchings/game/t_16C498", func_0016E448);

INCLUDE_ASM("asm/nonmatchings/game/t_16C498", func_0016E458);

INCLUDE_ASM("asm/nonmatchings/game/t_16C498", func_0016E468);

INCLUDE_ASM("asm/nonmatchings/game/t_16C498", func_0016E490);
