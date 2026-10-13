// cflags: -funroll-loops
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
extern u8 D_0036FC00[];
extern u8 D_0036FC10[];
extern u8 D_0036FC18[];
extern u8 D_0036FC20[];
extern u8 D_0036FC28[];
extern u8 D_0036FC30[];
extern u8 D_0036FC38[];
extern u8 D_0036FC40[];
extern u8 D_0036FC48[];
extern u8 D_0036FC50[];
extern u8 D_0036FC58[];
extern u8 D_0036FC60[];
extern u8 D_0036FC68[];
extern u8 D_0036FC70[];
extern u8 D_0036FC78[];
extern u8 D_0036FC80[];
extern u8 D_0036FC88[];
extern u8 D_0036FC90[];
extern u8 D_0036FC98[];
extern u8 D_0036FCA0[];
extern u8 D_0036FCA8[];
extern u8 D_0036FCB0[];
extern u8 D_0036FCB8[];
extern u8 D_0036FCC0[];
void func_00277378(u32 k, void* p);
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
void func_0014CC88(int);
extern u8 D_00354218[];
void* func_0022BA90(void*);
extern u8 D_00396F70[];
void func_0030A1C8(int, int);
void func_00115EE8(int, int, int);
int* func_0014C870(int, int, int, int, int, int, int, int);
void func_00230BA8(int, int, void*, int, int, int);
}

extern "C" void func_0022FD98(char* p) {
    struct VT {
        char pad[0x10];
        s16 delta;
        s16 pad12;
        int (*fn)(char*);
    };
    VT* v = *(VT**)(p + 0x34);
    if (v->fn(p + v->delta)) {
        func_0014CC88(*(int*)p);
    }
    func_0022BD90(p);
}

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

extern "C" void* func_0022FE90(char* p) {
    func_0022BA90(p);
    *(u8**)(p + 0x34) = D_00354218;
    func_0022FE40((S22F*)(p + 0x38));
    *(int*)(p + 0xE0) = 0;
    *(int*)(p + 0xE4) = 0;
    *(int*)(p + 0xDC) = 0;
    *(int*)(p + 0xE8) = 0;
    return p;
}

INCLUDE_ASM("asm/nonmatchings/game/t_22FD98", func_0022FEE0);

INCLUDE_ASM("asm/nonmatchings/game/t_22FD98", func_0022FFD0);

extern "C" void func_00230128(void* self) {
    func_0022BD90(self);
}

extern "C" void func_00230148(char* p, int a1) {
    func_0030A1C8(0, 0);
    func_00115EE8(*(int*)(p + 0xE0), a1, *(int*)(p + 0xE4));
    *func_0014C870(*(int*)p, a1, *(int*)(p + 0xE8), *(int*)(p + 0xC8), *(int*)(p + 0xCC), *(int*)(p + 0xD0), *(int*)(p + 0xD4), *(int*)(p + 0xD8)) = *(int*)p;
}

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

struct E22F {
    int flag;
    char pad[0x34];
};

extern "C" void func_002303D0(void) {
    E22F* d = (E22F*)D_00396F70;
    for (int i = 0x2F; i >= 0; i--) d[i].flag = 0;
}

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

GP_DATA(D_0036FBD0);
GP_DATA(D_0036FBD8);
GP_DATA(D_0036FBD4);
GP_DATA(D_0036FBDC);
INCLUDE_ASM("asm/nonmatchings/game/t_22FD98", func_00230578);

INCLUDE_ASM("asm/nonmatchings/game/t_22FD98", func_002305B8);

INCLUDE_ASM("asm/nonmatchings/game/t_22FD98", func_002305C0);

INCLUDE_ASM("asm/nonmatchings/game/t_22FD98", func_00230820);

INCLUDE_ASM("asm/nonmatchings/game/t_22FD98", func_00230A70);

INCLUDE_ASM("asm/nonmatchings/game/t_22FD98", func_00230BA8);

typedef void (*CB22F)(int, int, int, int, int);

extern "C" void func_00231478(char* p) {
    CB22F fn = *(CB22F*)(p + 0x1C);
    if (fn) fn(1, 0, *(int*)(p + 0x18), *(int*)(p + 0x2C), 0);
    *(int*)(p + 0x30) = 0;
    if (*(int*)(p + 4) == 0) func_00230BA8(0, *(int*)(p + 0x14), p + 0x30, *(int*)(p + 0x20), *(int*)(p + 0x2C), *(int*)(p + 0xC));
    CB22F fn2 = *(CB22F*)(p + 0x1C);
    if (fn2) fn2(0, *(int*)(p + 0x30), *(int*)(p + 0x18), *(int*)(p + 0x2C), 0);
}

INCLUDE_ASM("asm/nonmatchings/game/t_22FD98", func_00231500);

INCLUDE_ASM("asm/nonmatchings/game/t_22FD98", func_00231510);

INCLUDE_ASM("asm/nonmatchings/game/t_22FD98", func_002316D0);

INCLUDE_ASM("asm/nonmatchings/game/t_22FD98", func_002317B0);

extern "C" void func_00231838(void) {
    func_00277378(0x7330095C, D_0036FC10);
    func_00277378(0x745DCD45, D_0036FC18);
    func_00277378(0x9DE9087F, D_0036FC20);
    func_00277378(0x2F1A6A09, D_0036FC28);
    func_00277378(0x4BC1E85E, D_0036FC30);
    func_00277378(0x2B0A3095, D_0036FC38);
    func_00277378(0x64112E85, D_0036FC40);
    func_00277378(0x9BCC234D, D_0036FC48);
    func_00277378(0x6290993B, D_0036FC50);
    func_00277378(0xDAD5E950, D_0036FC58);
    func_00277378(0x689028A5, D_0036FC60);
    func_00277378(0x8BFA5E8E, D_0036FC68);
    func_00277378(0x7EA7357B, D_0036FC70);
    func_00277378(0x72A6D78C, D_0036FC78);
    func_00277378(0x5D796624, D_0036FC80);
    func_00277378(0xA7F505C4, D_0036FC00);
    func_00277378(0xA7DEA591, D_0036FC88);
    func_00277378(0x49875607, D_0036FC90);
    func_00277378(0x91E1028D, D_0036FC98);
    func_00277378(0x199F902B, D_0036FCA0);
    func_00277378(0x7E1ABC70, D_0036FCA8);
    func_00277378(0xFDC939B7, D_0036FCB0);
    func_00277378(0xFF2D0E91, D_0036FCB8);
    func_00277378(0x559566CC, D_0036FCC0);
    func_002303D0();
}

INCLUDE_ASM("asm/nonmatchings/game/t_22FD98", func_00231A38);

INCLUDE_ASM("asm/nonmatchings/game/t_22FD98", func_00231A80);

INCLUDE_ASM("asm/nonmatchings/game/t_22FD98", func_00231BE8);
