#include "common.h"

struct S22F {
    int unk0;
    int unk4;
    char pad8[0x14];
    int unk1C;
    char pad20[0x70];
    int unk90;
    int unk94;
    int unk98;
    int unk9C;
    int unkA0;
};

extern "C" {
extern u8 D_0036FB78[];
extern u8 D_00354208[];
void func_0022FE28(S22F*);
void func_0022BD90(void*);
void func_0022BAF8(void*);
int func_002304F8(S22F*);
char* func_00230540(S22F*);
S22F* func_0022FE00(S22F*);
void func_0022FE70(S22F*);
extern int D_0036FBD0;
extern char* D_0036FBD4;
extern char* D_0036FBD8;
extern int D_0036FBDC;
}

INCLUDE_ASM("asm/nonmatchings/game/t_22FD98", func_0022FD98);

extern "C" void* func_0022FDE8(void) {
    return D_0036FB78;
}

extern "C" int func_0022FDF8(void) {
    return 0x12;
}

extern "C" S22F* func_0022FE00(S22F* p) {
    func_0022FE28(p);
    return p;
}

extern "C" void func_0022FE28(S22F* self) {
    self->unk90 = 0;
    self->unk94 = 0;
    self->unk98 = 0;
    self->unk9C = 0;
    self->unkA0 = 0;
}

extern "C" S22F* func_0022FE40(S22F* p) {
    func_0022FE00(p);
    func_0022FE70(p);
    return p;
}

extern "C" void func_0022FE70(S22F* self) {
    func_0022FE28(self);
}

INCLUDE_ASM("asm/nonmatchings/game/t_22FD98", func_0022FE90);

INCLUDE_ASM("asm/nonmatchings/game/t_22FD98", func_0022FEE0);

INCLUDE_ASM("asm/nonmatchings/game/t_22FD98", func_0022FFD0);

extern "C" void func_00230128(void* self) {
    func_0022BD90(self);
}

INCLUDE_ASM("asm/nonmatchings/game/t_22FD98", func_00230148);

extern "C" void* func_002301C0(void) {
    return D_00354208;
}

extern "C" int func_002301D0(void) {
    return 0x13;
}

INCLUDE_ASM("asm/nonmatchings/game/t_22FD98", func_002301D8);

extern "C" int func_00230200(void) {
    return 0xA4;
}

extern "C" void func_00230208(void* self) {
    func_0022BAF8(self);
}

extern "C" int func_00230228(void) {
    return 0xA4;
}

INCLUDE_ASM("asm/nonmatchings/game/t_22FD98", func_00230230);

INCLUDE_ASM("asm/nonmatchings/game/t_22FD98", func_002302D0);

INCLUDE_ASM("asm/nonmatchings/game/t_22FD98", func_002303D0);

INCLUDE_ASM("asm/nonmatchings/game/t_22FD98", func_00230428);

extern "C" void func_002304F0(S22F* self) {
    self->unk0 = 0;
}

extern "C" int func_002304F8(S22F* self) {
    return (self->unk1C & 0x20) ? 0xC0 : 0x20;
}

extern "C" S22F* func_00230510(S22F* self) {
    return self;
}

extern "C" int func_00230518(S22F* p) {
    return (int)p + func_002304F8(p);
}

extern "C" char* func_00230540(S22F* self) {
    return (char*)self + 0x20;
}

extern "C" char* func_00230548(S22F* self) {
    if (self->unk1C & 0x20) {
        return func_00230540(self);
    }
    return 0;
}

INCLUDE_ASM("asm/nonmatchings/game/t_22FD98", func_00230578);

INCLUDE_ASM("asm/nonmatchings/game/t_22FD98", func_002305B8);

INCLUDE_ASM("asm/nonmatchings/game/t_22FD98", func_002305C0);

INCLUDE_ASM("asm/nonmatchings/game/t_22FD98", func_00230820);

INCLUDE_ASM("asm/nonmatchings/game/t_22FD98", func_00230A70);

INCLUDE_ASM("asm/nonmatchings/game/t_22FD98", func_00230BA8);

INCLUDE_ASM("asm/nonmatchings/game/t_22FD98", func_00231478);

INCLUDE_ASM("asm/nonmatchings/game/t_22FD98", func_00231500);

INCLUDE_ASM("asm/nonmatchings/game/t_22FD98", func_00231510);

INCLUDE_ASM("asm/nonmatchings/game/t_22FD98", func_002316D0);

INCLUDE_ASM("asm/nonmatchings/game/t_22FD98", func_002317B0);

INCLUDE_ASM("asm/nonmatchings/game/t_22FD98", func_00231838);

INCLUDE_ASM("asm/nonmatchings/game/t_22FD98", func_00231A38);

INCLUDE_ASM("asm/nonmatchings/game/t_22FD98", func_00231A80);

INCLUDE_ASM("asm/nonmatchings/game/t_22FD98", func_00231BE8);
