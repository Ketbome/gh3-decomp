#include "common.h"

struct S0016A328 {
    char pad[0x2F0];
    int unk2F0;
};

struct S0016A810 {
    char pad[0x2F8];
    float unk2F8;
};

struct S0016C158 {
    char pad[0x8];
    void* unk8;
};

struct S0016A2F0 {
    char pad0[0x8];
    void* unk8;
    char padC[0x14];
    void* unk20;
};

extern "C" {
extern u8 D_0033F7C8[];
void func_001CE7C0(void*);
extern u8 D_0033F218[];
extern u8 D_0033F230[];
void func_00162FC8(void);
}

extern "C" void func_0016A2F0(S0016A2F0* self) {
    self->unk20 = D_0033F218;
    self->unk8 = D_0033F230;
    func_00162FC8();
}

extern "C" int func_0016A320(void) {
    return 4;
}

extern "C" int func_0016A328(S0016A328* self) {
    return self->unk2F0;
}

INCLUDE_ASM("asm/nonmatchings/game/t_16A2F0", func_0016A330);

INCLUDE_ASM("asm/nonmatchings/game/t_16A2F0", func_0016A6A8);

INCLUDE_ASM("asm/nonmatchings/game/t_16A2F0", func_0016A718);

extern "C" void func_0016A810(S0016A810* self, float v) {
    self->unk2F8 = v;
}

extern "C" int func_0016A818(void) {
    return 3;
}

extern "C" int func_0016A820(void) {
    return 1;
}

INCLUDE_ASM("asm/nonmatchings/game/t_16A2F0", func_0016A828);

INCLUDE_ASM("asm/nonmatchings/game/t_16A2F0", func_0016ABA0);

INCLUDE_ASM("asm/nonmatchings/game/t_16A2F0", func_0016AC10);

extern "C" void func_0016AD08(S0016A810* self, float v) {
    self->unk2F8 = v;
}

extern "C" int func_0016AD10(void) {
    return 3;
}

extern "C" int func_0016AD18(void) {
    return 1;
}

INCLUDE_ASM("asm/nonmatchings/game/t_16A2F0", func_0016AD20);

INCLUDE_ASM("asm/nonmatchings/game/t_16A2F0", func_0016ADD8);

INCLUDE_ASM("asm/nonmatchings/game/t_16A2F0", func_0016AF18);

INCLUDE_ASM("asm/nonmatchings/game/t_16A2F0", func_0016AFC0);

INCLUDE_ASM("asm/nonmatchings/game/t_16A2F0", func_0016AFD8);

INCLUDE_ASM("asm/nonmatchings/game/t_16A2F0", func_0016AFE0);

INCLUDE_ASM("asm/nonmatchings/game/t_16A2F0", func_0016B040);

INCLUDE_ASM("asm/nonmatchings/game/t_16A2F0", func_0016B1B8);

INCLUDE_ASM("asm/nonmatchings/game/t_16A2F0", func_0016B238);

INCLUDE_ASM("asm/nonmatchings/game/t_16A2F0", func_0016BAF0);

INCLUDE_ASM("asm/nonmatchings/game/t_16A2F0", func_0016BB20);

INCLUDE_ASM("asm/nonmatchings/game/t_16A2F0", func_0016BBC0);

INCLUDE_ASM("asm/nonmatchings/game/t_16A2F0", func_0016BC70);

INCLUDE_ASM("asm/nonmatchings/game/t_16A2F0", func_0016BCE0);

INCLUDE_ASM("asm/nonmatchings/game/t_16A2F0", func_0016BCE8);

INCLUDE_ASM("asm/nonmatchings/game/t_16A2F0", func_0016BE38);

INCLUDE_ASM("asm/nonmatchings/game/t_16A2F0", func_0016BEB0);

INCLUDE_ASM("asm/nonmatchings/game/t_16A2F0", func_0016BF28);

INCLUDE_ASM("asm/nonmatchings/game/t_16A2F0", func_0016C0F8);

extern "C" void func_0016C158(S0016C158* self) {
    self->unk8 = D_0033F7C8;
    func_001CE7C0(self);
}

INCLUDE_ASM("asm/nonmatchings/game/t_16A2F0", func_0016C180);
