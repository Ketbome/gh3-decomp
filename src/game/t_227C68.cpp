#include "common.h"

struct VEntry227 {
    s16 delta;
    s16 unk2;
    void* fn;
};

struct S227 {
    VEntry227* unk0;
    char pad4[0x28];
    int unk2C;
    char pad30[0x380];
    int unk3B0;
    char pad3B4[0xD4];
    int unk488;
};

struct S227b {
    char pad0[0xC];
    int unkC;
    int unk10;
};

extern "C" {
void func_001DF898(int);
void func_0014EAE8(int, int);
void func_002285E8(int, int);
void func_001CEBA8(S227*, int*);
}

extern "C" void func_00227C68(S227* self, int a, S227b* b) {
    if (!b->unk10 && b->unkC) {
        VEntry227* e = &self->unk0[2];
        ((void (*)(void*, int))e->fn)((char*)self + e->delta, a);
    }
}

extern "C" void func_00227CA8(void* self, int a) {
    func_001DF898(a);
}

INCLUDE_ASM("asm/nonmatchings/game/t_227C68", func_00227CC8);

INCLUDE_ASM("asm/nonmatchings/game/t_227C68", func_00227D20);

INCLUDE_ASM("asm/nonmatchings/game/t_227C68", func_00227E00);

INCLUDE_ASM("asm/nonmatchings/game/t_227C68", func_00227EA8);

extern "C" void func_00227F00(S227* self, int a, S227b* b) {
    if (!b->unk10 && b->unkC) {
        VEntry227* e = &self->unk0[2];
        ((void (*)(void*, int))e->fn)((char*)self + e->delta, a);
    }
}

extern "C" void func_00227F40(void) {
}

extern "C" void func_00227F48(void* self, int a, int b) {
    func_0014EAE8(b, 0);
}

extern "C" void func_00227F68(S227* self, int a, S227b* b) {
    if (!b->unk10 && b->unkC) {
        VEntry227* e = &self->unk0[2];
        ((void (*)(void*, int))e->fn)((char*)self + e->delta, a);
    }
}

INCLUDE_ASM("asm/nonmatchings/game/t_227C68", func_00227FA8);

INCLUDE_ASM("asm/nonmatchings/game/t_227C68", func_00228050);

INCLUDE_ASM("asm/nonmatchings/game/t_227C68", func_002280A8);

extern "C" void func_00228148(void) {
}

extern "C" void func_00228150(void) {
}

INCLUDE_ASM("asm/nonmatchings/game/t_227C68", func_00228158);

INCLUDE_ASM("asm/nonmatchings/game/t_227C68", func_00228278);

extern "C" void func_00228360(void) {
}

INCLUDE_ASM("asm/nonmatchings/game/t_227C68", func_00228368);

INCLUDE_ASM("asm/nonmatchings/game/t_227C68", func_00228408);

INCLUDE_ASM("asm/nonmatchings/game/t_227C68", func_002285E8);

extern "C" void func_00228820(S227* self, int* b) {
    int v = *b;
    if (self->unk2C == v) {
        func_001CEBA8(self, b);
    }
}

INCLUDE_ASM("asm/nonmatchings/game/t_227C68", func_00228850);

extern "C" void func_00228860(void) {
}

extern "C" void func_00228868(int a, int b) {
    func_002285E8(b, a);
}

INCLUDE_ASM("asm/nonmatchings/game/t_227C68", func_00228890);

INCLUDE_ASM("asm/nonmatchings/game/t_227C68", func_00229538);

INCLUDE_ASM("asm/nonmatchings/game/t_227C68", func_00229718);

extern "C" int func_002297A8(S227* self) {
    if (self->unk488 || self->unk3B0) {
        return 1;
    }
    return 0;
}

INCLUDE_ASM("asm/nonmatchings/game/t_227C68", func_002297D0);

INCLUDE_ASM("asm/nonmatchings/game/t_227C68", func_00229820);

INCLUDE_ASM("asm/nonmatchings/game/t_227C68", func_002299B0);

INCLUDE_ASM("asm/nonmatchings/game/t_227C68", func_00229BA0);
