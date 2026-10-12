#include "common.h"

struct VEntry {
    s16 delta;
    s16 unk2;
    void* fn;
};

struct S0015BA28 {
    int unk0;
    int unk4;
    char pad8[0xC];
    VEntry* unk14;
};

struct S0015BA58 {
    char pad0[0x8];
    int unk8;
    int unkC;
    char pad10[0x4];
    VEntry* unk14;
};

struct S0015B360 {
    char pad[0x16];
    u8 unk16;
};

extern "C" {
void func_00189938(void);
void func_0015B968(int, int);
void func_0015BB80(int, int);
void func_002763E0(int, int);
}

INCLUDE_ASM("asm/nonmatchings/game/t_15B258", func_0015B258);

INCLUDE_ASM("asm/nonmatchings/game/t_15B258", func_0015B268);

INCLUDE_ASM("asm/nonmatchings/game/t_15B258", func_0015B2F0);

extern "C" int func_0015B328(void) {
    return 0;
}

extern "C" int func_0015B330(void) {
    return 0;
}

extern "C" int func_0015B338(void) {
    return 0;
}

extern "C" void func_0015B340(void) {
}

extern "C" int func_0015B348(void) {
    return 0;
}

extern "C" int func_0015B350(void) {
    return 0;
}

INCLUDE_ASM("asm/nonmatchings/game/t_15B258", func_0015B358);

extern "C" bool func_0015B360(S0015B360* self) {
    return self->unk16 != 0;
}

INCLUDE_ASM("asm/nonmatchings/game/t_15B258", func_0015B370);

INCLUDE_ASM("asm/nonmatchings/game/t_15B258", func_0015B380);

INCLUDE_ASM("asm/nonmatchings/game/t_15B258", func_0015B438);

INCLUDE_ASM("asm/nonmatchings/game/t_15B258", func_0015B4B0);

INCLUDE_ASM("asm/nonmatchings/game/t_15B258", func_0015B568);

INCLUDE_ASM("asm/nonmatchings/game/t_15B258", func_0015B590);

INCLUDE_ASM("asm/nonmatchings/game/t_15B258", func_0015B770);

INCLUDE_ASM("asm/nonmatchings/game/t_15B258", func_0015B7B0);

INCLUDE_ASM("asm/nonmatchings/game/t_15B258", func_0015B808);

INCLUDE_ASM("asm/nonmatchings/game/t_15B258", func_0015B8C0);

INCLUDE_ASM("asm/nonmatchings/game/t_15B258", func_0015B8E8);

INCLUDE_ASM("asm/nonmatchings/game/t_15B258", func_0015B920);

INCLUDE_ASM("asm/nonmatchings/game/t_15B258", func_0015B960);

INCLUDE_ASM("asm/nonmatchings/game/t_15B258", func_0015B968);

extern "C" void func_0015B9A0(void) {
    func_0015B968(1, 65535);
}

INCLUDE_ASM("asm/nonmatchings/game/t_15B258", func_0015B9C0);

INCLUDE_ASM("asm/nonmatchings/game/t_15B258", func_0015B9E8);

extern "C" void func_0015BA28(S0015BA28* self, int a1, int a2) {
    self->unk4 = a2;
    self->unk0 = a1;
    VEntry* e = &self->unk14[2];
    ((void (*)(void*))e->fn)((char*)self + e->delta);
}

extern "C" void func_0015BA58(S0015BA58* self, int a1, int a2) {
    self->unkC = a2;
    self->unk8 = a1;
    VEntry* e = &self->unk14[2];
    ((void (*)(void*))e->fn)((char*)self + e->delta);
}

extern "C" void func_0015BA88(void) {
}

extern "C" void func_0015BA90(void) {
    func_00189938();
}

INCLUDE_ASM("asm/nonmatchings/game/t_15B258", func_0015BAB0);

INCLUDE_ASM("asm/nonmatchings/game/t_15B258", func_0015BB20);

INCLUDE_ASM("asm/nonmatchings/game/t_15B258", func_0015BB60);

INCLUDE_ASM("asm/nonmatchings/game/t_15B258", func_0015BB80);

extern "C" void func_0015BC60(void) {
    func_0015BB80(1, 65535);
}

extern "C" void func_0015BC80(void) {
    func_002763E0(0xAE1FCC20, 1);
}

INCLUDE_ASM("asm/nonmatchings/game/t_15B258", func_0015BCA8);

INCLUDE_ASM("asm/nonmatchings/game/t_15B258", func_0015BD40);

INCLUDE_ASM("asm/nonmatchings/game/t_15B258", func_0015BE58);

INCLUDE_ASM("asm/nonmatchings/game/t_15B258", func_0015BED8);

INCLUDE_ASM("asm/nonmatchings/game/t_15B258", func_0015C0F8);

INCLUDE_ASM("asm/nonmatchings/game/t_15B258", func_0015C178);

INCLUDE_ASM("asm/nonmatchings/game/t_15B258", func_0015C1F8);

INCLUDE_ASM("asm/nonmatchings/game/t_15B258", func_0015C200);

INCLUDE_ASM("asm/nonmatchings/game/t_15B258", func_0015C3B0);

extern "C" void func_0015C948(void) {
}

INCLUDE_ASM("asm/nonmatchings/game/t_15B258", func_0015C950);

INCLUDE_ASM("asm/nonmatchings/game/t_15B258", func_0015CD88);

INCLUDE_ASM("asm/nonmatchings/game/t_15B258", func_0015CFC8);

INCLUDE_ASM("asm/nonmatchings/game/t_15B258", func_0015D0D0);

INCLUDE_ASM("asm/nonmatchings/game/t_15B258", func_0015D160);

INCLUDE_ASM("asm/nonmatchings/game/t_15B258", func_0015D1A0);
