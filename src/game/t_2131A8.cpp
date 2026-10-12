#include "common.h"

struct VEntry213 {
    s16 delta;
    s16 unk2;
    void* fn;
};

struct S213 {
    char pad0[0x18];
    VEntry213* unk18;
    int unk1C;
    char pad20[0x8];
    void* unk28;
    int unk2C;
    char pad30[0x20];
    int unk50;
    char pad54[0x20];
    int unk74;
    char pad78[0x20];
    int unk98;
    char pad9C[0x260];
    int unk2FC;
    char pad300[0x20];
    int unk320;
    char pad324[0x20];
    int unk344;
    char pad348[0x20];
    int unk368;
    char pad36C[0x798];
    int unkB04;
    int unkB08;
    int unkB0C;
};

extern "C" {
void func_002120E8(int, int);
void func_00213520(int, int);
void func_00214350(int, int);
void func_002143F8(int, int);
void func_00214AB8(int, int);
void func_00113F38(void*, int);
extern u8 D_00342398[];
void func_00276D68(u32, void*, int);
extern u8 D_0038FED8[];
extern u8 D_00390028[];
}

INCLUDE_ASM("asm/nonmatchings/game/t_2131A8", func_002131A8);

extern "C" void func_002132B8(void) {
    func_002120E8(1, 0xFFFF);
}

INCLUDE_ASM("asm/nonmatchings/game/t_2131A8", func_002132D8);

INCLUDE_ASM("asm/nonmatchings/game/t_2131A8", func_002134C8);

INCLUDE_ASM("asm/nonmatchings/game/t_2131A8", func_002134D8);

INCLUDE_ASM("asm/nonmatchings/game/t_2131A8", func_00213518);

INCLUDE_ASM("asm/nonmatchings/game/t_2131A8", func_00213520);

extern "C" void func_002135C8(void) {
    func_00213520(1, 0xFFFF);
}

INCLUDE_ASM("asm/nonmatchings/game/t_2131A8", func_002135E8);

extern "C" void func_00213620(void) {
    func_00276D68(0x27D7CD28, D_0038FED8, 0x10);
}

INCLUDE_ASM("asm/nonmatchings/game/t_2131A8", func_00213650);

INCLUDE_ASM("asm/nonmatchings/game/t_2131A8", func_002136A8);

INCLUDE_ASM("asm/nonmatchings/game/t_2131A8", func_00213770);

extern "C" void func_002138B0(S213* self, int a) {
    VEntry213* e = &self->unk18[3];
    ((void (*)(void*, int))e->fn)((char*)self + e->delta, a);
}

extern "C" void func_002138D8(S213* self) {
    VEntry213* e = &self->unk18[8];
    ((void (*)(void*, int))e->fn)((char*)self + e->delta, 1);
}

INCLUDE_ASM("asm/nonmatchings/game/t_2131A8", func_00213908);

extern "C" int func_002139B8(S213* self) {
    self->unkB04 = 1;
    return 1;
}

extern "C" int func_002139C8(S213* self) {
    self->unkB04 = 0;
    return 1;
}

extern "C" int func_002139D8(S213* self) {
    self->unkB08 = 1;
    return 1;
}

extern "C" int func_002139E8(S213* self) {
    self->unkB08 = 0;
    return 1;
}

extern "C" int func_002139F8(S213* self) {
    return self->unkB04 || self->unkB08;
}

extern "C" int func_00213A20(S213* self) {
    return self->unk74 != 0;
}

extern "C" int func_00213A30(S213* self) {
    return self->unk98 != 0;
}

extern "C" int func_00213A40(S213* self) {
    return self->unk2C != 0;
}

extern "C" int func_00213A50(S213* self) {
    return self->unk50 != 0;
}

extern "C" int func_00213A60(S213* self) {
    return self->unk344 != 0;
}

extern "C" int func_00213A70(S213* self) {
    return self->unk368 != 0;
}

extern "C" int func_00213A80(S213* self) {
    return self->unk2FC != 0;
}

extern "C" int func_00213A90(S213* self) {
    return self->unk320 != 0;
}

INCLUDE_ASM("asm/nonmatchings/game/t_2131A8", func_00213AA0);

INCLUDE_ASM("asm/nonmatchings/game/t_2131A8", func_00213B80);

extern "C" int func_00213CD0(S213* self) {
    self->unkB0C = 1;
    return 1;
}

extern "C" int func_00213CE0(S213* self) {
    self->unkB0C = 0;
    return 1;
}

INCLUDE_ASM("asm/nonmatchings/game/t_2131A8", func_00213CF0);

INCLUDE_ASM("asm/nonmatchings/game/t_2131A8", func_00213D60);

INCLUDE_ASM("asm/nonmatchings/game/t_2131A8", func_00213E10);

extern "C" void func_00213EA0(void) {
}

INCLUDE_ASM("asm/nonmatchings/game/t_2131A8", func_00213EA8);

INCLUDE_ASM("asm/nonmatchings/game/t_2131A8", func_002140D8);

INCLUDE_ASM("asm/nonmatchings/game/t_2131A8", func_002141A8);

INCLUDE_ASM("asm/nonmatchings/game/t_2131A8", func_002141F8);

INCLUDE_ASM("asm/nonmatchings/game/t_2131A8", func_00214350);

INCLUDE_ASM("asm/nonmatchings/game/t_2131A8", func_002143F8);

INCLUDE_ASM("asm/nonmatchings/game/t_2131A8", func_00214498);

INCLUDE_ASM("asm/nonmatchings/game/t_2131A8", func_002145C8);

extern "C" void func_00214A68(S213* self) {
    func_00214350(self->unk2C, self->unk1C);
}

extern "C" void func_00214A88(S213* self) {
    func_002143F8(self->unk2C, self->unk1C);
}

INCLUDE_ASM("asm/nonmatchings/game/t_2131A8", func_00214AA8);

INCLUDE_ASM("asm/nonmatchings/game/t_2131A8", func_00214AB8);

extern "C" void func_00214FD0(S213* self, int flag) {
    self->unk18 = (VEntry213*)D_00342398;
    func_00113F38(self, flag);
}

extern "C" void func_00214FF8(S213* self) {
    ((void (*)(S213*))self->unk28)(self);
}

extern "C" void func_00215018(void) {
    func_00214AB8(1, 0xFFFF);
}

INCLUDE_ASM("asm/nonmatchings/game/t_2131A8", func_00215038);

extern "C" void func_00215078(void) {
    func_00276D68(0xA9DB601E, D_00390028, 0x10);
}

INCLUDE_ASM("asm/nonmatchings/game/t_2131A8", func_002150A8);

INCLUDE_ASM("asm/nonmatchings/game/t_2131A8", func_00215128);
