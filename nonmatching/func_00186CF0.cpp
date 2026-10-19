// cflags: -fno-cse-skip-blocks
#include "common.h"

struct S001874D0 {
    char pad[0xC];
    u16 unkC;
};

struct S001874D8 {
    char pad[0xE];
    u16 unkE;
};

struct S_001873D8 { int unk0; int unk4; char pad8[8]; int* unk10; };

extern "C" {
void func_0030A2F4(int, int, int);
int func_001BF4A0(int, void*);
int func_001C3578(int, void*);
int func_001BF508(int, void*);
int func_001C35E0(int, void*);
int func_001BF560(int, void*);
int func_001C3638(int, void*);
extern int D_0036B594;
extern int D_00368A38;
extern u8 D_00415B00[];
void Heap_Free(int, int);
void func_001BE498(int);
void func_001BF230(int);
void func_001BF258(int);
}

INCLUDE_ASM("asm/nonmatchings/game/t_185918", func_00185918);

GP_DATA(D_0036B594);
extern "C" void func_00185B98(void) {
    if (D_0036B594) {
        Heap_Free(D_00368A38, D_0036B594);
    }
    D_0036B594 = 0;
}

INCLUDE_ASM("asm/nonmatchings/game/t_185918", func_00185BC0);

INCLUDE_ASM("asm/nonmatchings/game/t_185918", func_00185DD0);

INCLUDE_ASM("asm/nonmatchings/game/t_185918", func_00186060);

INCLUDE_ASM("asm/nonmatchings/game/t_185918", func_00186310);

INCLUDE_ASM("asm/nonmatchings/game/t_185918", func_001863D0);

INCLUDE_ASM("asm/nonmatchings/game/t_185918", func_00186788);

struct C186 { u8 r, g, b, a; };
struct VE186 { short delta; short pad; unsigned (*fn)(void*); };
struct VT186 { char pad0[0xE0]; VE186 e0; char padE8[0x10]; VE186 f8; };
struct G186 { char pad0[0x14]; u8* unk14; void* unk18; };
struct S186 { int unk0; int unk4; VT186* unk8; char padC[4]; void* unk10; };

extern "C" int func_00186CF0(S186* self, C186* col) {
    G186* g;
    if ((self->unk4 >> 2) & 1) {
        g = *(G186**)self->unk10;
    } else {
        g = 0;
        if (self->unk4 & 1) g = (G186*)self->unk10;
    }
    if (self->unk8->e0.fn((char*)self + self->unk8->e0.delta) < 9) {
        u8* idx = g->unk14;
        void* pal = g->unk18;
        unsigned v;
        if (self->unk8->e0.fn((char*)self + self->unk8->e0.delta) == 8) {
            v = D_00415B00[*idx];
        } else {
            v = *idx & 0xF;
        }
        if (self->unk8->f8.fn((char*)self + self->unk8->f8.delta) == 0x20) {
            ((int*)pal)[v] = *(int*)col;
            C186 t = ((C186*)pal)[v];
            (void)t;
        } else {
            int bb = (col->b >> 3) << 10;
            unsigned short r = (col->g >> 3) << 5;
            if (col->a >= 0x40) r |= 0x8000;
            *(short*)pal = (col->r >> 3) | r | bb;
        }
    }
    return 1;
}

static inline int S_001873D8_Get(S_001873D8* self) {
    if ((self->unk4 >> 2) & 1) {
        return *self->unk10;
    }
    if (self->unk4 & 1) {
        return (int)self->unk10;
    }
    return 0;
}

static inline int S_001873D8_Get2(S_001873D8* self) {
    if ((self->unk4 >> 1) & 1) {
        return (int)self->unk10;
    }
    return 0;
}

static inline int S_001873D8_GetF(S_001873D8* self, int f) {
    if ((f >> 2) & 1) {
        return *self->unk10;
    }
    if (f & 1) {
        return (int)self->unk10;
    }
    return 0;
}

static inline int S_001873D8_Get2F(S_001873D8* self, int f) {
    if ((f >> 1) & 1) {
        return (int)self->unk10;
    }
    return 0;
}

extern "C" int func_00186E40(S_001873D8* self) {
    if (S_001873D8_Get(self)) {
        return *(int*)(S_001873D8_Get(self) + 0x14);
    }
    int f = self->unk4;
    if (S_001873D8_Get2F(self, f)) {
        return *(int*)(S_001873D8_Get2F(self, f) + 0x28);
    }
    return 0;
}

extern "C" int func_00186EE8(S_001873D8* self) {
    if (S_001873D8_Get(self)) {
        return *(int*)(S_001873D8_Get(self) + 0x1C);
    }
    int f = self->unk4;
    if (S_001873D8_Get2F(self, f)) {
        return *(int*)(S_001873D8_Get2F(self, f) + 0x2C);
    }
    return 0;
}

extern "C" int func_00186F90(S_001873D8* self) {
    if (S_001873D8_Get(self)) {
        return *(int*)(S_001873D8_Get(self) + 0x18);
    }
    int f = self->unk4;
    if (S_001873D8_Get2F(self, f)) {
        return *(int*)(S_001873D8_Get2F(self, f) + 0x30);
    }
    return 0;
}

extern "C" int func_00187038(S_001873D8* self) {
    if (S_001873D8_Get(self)) {
        return *(int*)(S_001873D8_Get(self) + 0x20);
    }
    int f = self->unk4;
    if (S_001873D8_Get2F(self, f)) {
        return *(int*)(S_001873D8_Get2F(self, f) + 0x34);
    }
    return 0;
}

extern "C" int func_001870E0(S_001873D8* self) {
    if (S_001873D8_Get(self)) {
        return *(int*)(S_001873D8_Get(self) + 0xC);
    }
    return 0;
}

extern "C" int func_00187158(S_001873D8* self) {
    if (S_001873D8_Get(self)) {
        return *(int*)(S_001873D8_Get(self) + 0x24);
    }
    return 0;
}

INCLUDE_ASM("asm/nonmatchings/game/t_185918", func_001871D0);

extern "C" void func_001873D8(S_001873D8* self) {
    func_001BE498(S_001873D8_Get(self));
}

extern "C" int func_00187428(void) {
    return 96;
}

extern "C" void func_00187430(S_001873D8* self) {
    func_001BF230(S_001873D8_Get(self));
}

extern "C" void func_00187480(S_001873D8* self) {
    func_001BF258(S_001873D8_Get(self));
}

extern "C" u16 func_001874D0(S001874D0* self) {
    return self->unkC;
}

extern "C" u16 func_001874D8(S001874D8* self) {
    return self->unkE;
}

extern "C" int func_001874E0(S_001873D8* self) {
    if (S_001873D8_Get(self)) {
        return func_001BF4A0(S_001873D8_Get(self), self);
    }
    int f = self->unk4;
    if (S_001873D8_Get2F(self, f)) {
        return func_001C3578(S_001873D8_Get2F(self, f), self);
    }
    return 0;
}

extern "C" int func_001875A8(S_001873D8* self) {
    if (S_001873D8_Get(self)) {
        return *(int*)(S_001873D8_Get(self) + 0x18);
    }
    int f = self->unk4;
    if (S_001873D8_Get2F(self, f)) {
        return *(int*)(S_001873D8_Get2F(self, f) + 0x30);
    }
    return 0;
}

INCLUDE_ASM("asm/nonmatchings/game/t_185918", func_00187650);

extern "C" int func_00187708(S_001873D8* self) {
    if (S_001873D8_Get(self)) {
        return func_001BF508(S_001873D8_Get(self), self);
    }
    int f = self->unk4;
    if (S_001873D8_Get2F(self, f)) {
        return func_001C35E0(S_001873D8_Get2F(self, f), self);
    }
    return 0;
}

extern "C" int func_001877D0(S_001873D8* self) {
    if (S_001873D8_Get(self)) {
        return func_001BF560(S_001873D8_Get(self), self);
    }
    int f = self->unk4;
    if (S_001873D8_Get2F(self, f)) {
        return func_001C3638(S_001873D8_Get2F(self, f), self);
    }
    return 0;
}

INCLUDE_ASM("asm/nonmatchings/game/t_185918", func_00187898);
