#include "common.h"

struct VEntry {
    s16 delta;
    s16 unk2;
    void* fn;
};

struct S001628F0 {
    char pad[0xBC];
    VEntry* unkBC;
};

struct S001619B0 {
    char pad[0x58];
    VEntry* unk58;
};

struct S00162918 {
    char pad[0xB8];
    int unkB8;
};

INCLUDE_ASM("asm/nonmatchings/game/t_161580", func_00161580);

INCLUDE_ASM("asm/nonmatchings/game/t_161580", func_001618A0);

INCLUDE_ASM("asm/nonmatchings/game/t_161580", func_001618F8);

INCLUDE_ASM("asm/nonmatchings/game/t_161580", func_00161950);

INCLUDE_ASM("asm/nonmatchings/game/t_161580", func_00161960);

extern "C" void func_001619B0(S001619B0* self, int a1) {
    VEntry* e = &self->unk58[16];
    ((void (*)(void*, int))e->fn)((char*)self + e->delta, a1);
}

INCLUDE_ASM("asm/nonmatchings/game/t_161580", func_001619D8);

INCLUDE_ASM("asm/nonmatchings/game/t_161580", func_00161AC8);

INCLUDE_ASM("asm/nonmatchings/game/t_161580", func_00161BA0);

INCLUDE_ASM("asm/nonmatchings/game/t_161580", func_00161CC8);

INCLUDE_ASM("asm/nonmatchings/game/t_161580", func_00161D40);

INCLUDE_ASM("asm/nonmatchings/game/t_161580", func_00161DD8);

INCLUDE_ASM("asm/nonmatchings/game/t_161580", func_00161E78);

INCLUDE_ASM("asm/nonmatchings/game/t_161580", func_00161EE0);

INCLUDE_ASM("asm/nonmatchings/game/t_161580", func_00161F48);

INCLUDE_ASM("asm/nonmatchings/game/t_161580", func_00161FD8);

INCLUDE_ASM("asm/nonmatchings/game/t_161580", func_00161FF8);

INCLUDE_ASM("asm/nonmatchings/game/t_161580", func_00162070);

INCLUDE_ASM("asm/nonmatchings/game/t_161580", func_001620D8);

INCLUDE_ASM("asm/nonmatchings/game/t_161580", func_00162140);

extern "C" void func_00162178(S001619B0* self) {
    VEntry* e = &self->unk58[15];
    ((void (*)(void*))e->fn)((char*)self + e->delta);
}

INCLUDE_ASM("asm/nonmatchings/game/t_161580", func_001621A0);

INCLUDE_ASM("asm/nonmatchings/game/t_161580", func_00162358);

INCLUDE_ASM("asm/nonmatchings/game/t_161580", func_00162378);

INCLUDE_ASM("asm/nonmatchings/game/t_161580", func_001623A0);

INCLUDE_ASM("asm/nonmatchings/game/t_161580", func_001623B8);

INCLUDE_ASM("asm/nonmatchings/game/t_161580", func_00162420);

INCLUDE_ASM("asm/nonmatchings/game/t_161580", func_00162470);

INCLUDE_ASM("asm/nonmatchings/game/t_161580", func_001628B8);

extern "C" int func_001628F0(S001628F0* self, int a1, int a2, int a3) {
    VEntry* e = &self->unkBC[4];
    return ((int (*)(void*, int, int, int))e->fn)((char*)self + e->delta, a1, a2, a3);
}

extern "C" int func_00162918(S00162918* self) {
    return self->unkB8;
}

INCLUDE_ASM("asm/nonmatchings/game/t_161580", func_00162920);

extern "C" int func_001629B0(void) {
    return 0;
}

extern "C" int func_001629B8(void) {
    return 0;
}

INCLUDE_ASM("asm/nonmatchings/game/t_161580", func_001629C0);

INCLUDE_ASM("asm/nonmatchings/game/t_161580", func_001629E0);

extern "C" void func_00162B98(void) {
}

extern "C" int func_00162BA0(void) {
    return 0;
}

extern "C" int func_00162BA8(void) {
    return 0;
}

INCLUDE_ASM("asm/nonmatchings/game/t_161580", func_00162BB0);

INCLUDE_ASM("asm/nonmatchings/game/t_161580", func_00162E08);

INCLUDE_ASM("asm/nonmatchings/game/t_161580", func_00162EE8);

INCLUDE_ASM("asm/nonmatchings/game/t_161580", func_00162F48);

INCLUDE_ASM("asm/nonmatchings/game/t_161580", func_00162FB8);

INCLUDE_ASM("asm/nonmatchings/game/t_161580", func_00163128);

INCLUDE_ASM("asm/nonmatchings/game/t_161580", func_00163320);

INCLUDE_ASM("asm/nonmatchings/game/t_161580", func_00163328);

INCLUDE_ASM("asm/nonmatchings/game/t_161580", func_00163380);

INCLUDE_ASM("asm/nonmatchings/game/t_161580", func_00163410);
