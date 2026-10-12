#include "common.h"

typedef unsigned int u128_206 __attribute__((mode(TI)));

struct VEntry206 {
    s16 delta;
    s16 unk2;
    void* fn;
};

struct S206b {
    char pad0[0x8];
    VEntry206* unk8;
};

struct S206 {
    char pad0[0x18];
    VEntry206* unk18;
    S206b* unk1C;
    u128_206 unk20;
};

extern "C" {
void func_00207DD8(void*);
int func_00206728(void*);
void func_00207E58(int, int);
int func_00206BD0(void*, int, int, int, int);
void* func_00113D20(u32 size);
void* func_00206FF8(void*);
void* func_00208038(void*);
void func_001D0F90(void*, int);
extern u8 D_00350428[];
void func_00276D48(u32, void*, int);
extern u8 D_0038FCB8[];
}

INCLUDE_ASM("asm/nonmatchings/game/t_2062E8", func_002062E8);

INCLUDE_ASM("asm/nonmatchings/game/t_2062E8", func_00206520);

INCLUDE_ASM("asm/nonmatchings/game/t_2062E8", func_00206668);

INCLUDE_ASM("asm/nonmatchings/game/t_2062E8", func_00206728);

INCLUDE_ASM("asm/nonmatchings/game/t_2062E8", func_00206788);

INCLUDE_ASM("asm/nonmatchings/game/t_2062E8", func_002069F8);

INCLUDE_ASM("asm/nonmatchings/game/t_2062E8", func_00206BD0);

extern "C" int func_00206D58(void* self, int a, int b) {
    return func_00206BD0(self, a, b, 0, 0) != 0;
}

INCLUDE_ASM("asm/nonmatchings/game/t_2062E8", func_00206D80);

extern "C" int func_00206E10(void* self) {
    return func_00206728(self) != 0;
}

INCLUDE_ASM("asm/nonmatchings/game/t_2062E8", func_00206E30);

INCLUDE_ASM("asm/nonmatchings/game/t_2062E8", func_00206E48);

INCLUDE_ASM("asm/nonmatchings/game/t_2062E8", func_00206F70);

extern "C" void* func_00206FA0(void) {
    return func_00206FF8(func_00113D20(0x60));
}

extern "C" void func_00206FC8(void) {
    func_00276D48(0x8A897DD2, D_0038FCB8, 0x10);
}

INCLUDE_ASM("asm/nonmatchings/game/t_2062E8", func_00206FF8);

INCLUDE_ASM("asm/nonmatchings/game/t_2062E8", func_00207090);

INCLUDE_ASM("asm/nonmatchings/game/t_2062E8", func_002070F8);

extern "C" void func_002071C0(S206* self) {
    VEntry206* e = &self->unk18[2];
    ((void (*)(void*))e->fn)((char*)self + e->delta);
}

INCLUDE_ASM("asm/nonmatchings/game/t_2062E8", func_002071E8);

INCLUDE_ASM("asm/nonmatchings/game/t_2062E8", func_002074E0);

extern "C" void func_00207748(S206* self, int a) {
    S206b* p = self->unk1C;
    VEntry206* e = &p->unk8[8];
    ((void (*)(void*, int))e->fn)((char*)p + e->delta, a);
}

extern "C" void func_00207778(void* self) {
    func_00207DD8(self);
}

INCLUDE_ASM("asm/nonmatchings/game/t_2062E8", func_00207798);

INCLUDE_ASM("asm/nonmatchings/game/t_2062E8", func_002077E0);

INCLUDE_ASM("asm/nonmatchings/game/t_2062E8", func_002078A8);

extern "C" int func_00207A18(S206* self) {
    VEntry206* e = &self->unk18[4];
    ((void (*)(void*))e->fn)((char*)self + e->delta);
    return 1;
}

INCLUDE_ASM("asm/nonmatchings/game/t_2062E8", func_00207A48);

INCLUDE_ASM("asm/nonmatchings/game/t_2062E8", func_00207B78);

extern "C" int func_00207BD0(void) {
    return 2;
}

INCLUDE_ASM("asm/nonmatchings/game/t_2062E8", func_00207BD8);

INCLUDE_ASM("asm/nonmatchings/game/t_2062E8", func_00207C78);

INCLUDE_ASM("asm/nonmatchings/game/t_2062E8", func_00207D70);

INCLUDE_ASM("asm/nonmatchings/game/t_2062E8", func_00207DD8);

extern "C" void func_00207E28(S206* self, u128_206* v) {
    self->unk20 = *v;
}

INCLUDE_ASM("asm/nonmatchings/game/t_2062E8", func_00207E38);

INCLUDE_ASM("asm/nonmatchings/game/t_2062E8", func_00207E58);

extern "C" void func_00207FF0(void) {
    func_00207E58(1, 0xFFFF);
}

extern "C" void* func_00208010(void) {
    return func_00208038(func_00113D20(0x20));
}

INCLUDE_ASM("asm/nonmatchings/game/t_2062E8", func_00208038);

extern "C" void func_00208098(S206* self, int flag) {
    self->unk18 = (VEntry206*)D_00350428;
    func_001D0F90(self, flag);
}

INCLUDE_ASM("asm/nonmatchings/game/t_2062E8", func_002080C0);

INCLUDE_ASM("asm/nonmatchings/game/t_2062E8", func_002081A8);

extern "C" void func_00208218(S206* self) {
    VEntry206* e = &self->unk18[8];
    ((void (*)(void*, int))e->fn)((char*)self + e->delta, 1);
}

extern "C" int func_00208248(void) {
    return 2;
}

INCLUDE_ASM("asm/nonmatchings/game/t_2062E8", func_00208250);

extern "C" S206b* func_00208260(S206* self) {
    return self->unk1C;
}

INCLUDE_ASM("asm/nonmatchings/game/t_2062E8", func_00208268);
