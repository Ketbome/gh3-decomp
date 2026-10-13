#include "common.h"

typedef unsigned int u128_21D __attribute__((mode(TI)));

struct M21D {
    u128_21D r[4];
};

struct VEntry21D {
    s16 delta;
    s16 unk2;
    void* fn;
};

struct S21Db {
    char pad0[0xA0];
    M21D unkA0;
    char padE0[0x20];
    M21D unk100;
};

struct S21D {
    char pad0[0xC];
    S21Db* unkC;
    char pad10[0x8];
    VEntry21D* unk18;
    int unk1C;
    char pad20[0x3C];
    int unk5C;
    S21D* unk60;
};

extern "C" {
void func_001D10A0(void*);
void func_0021DC50(int, int);
void func_0021DED8(int, int);
void func_0027AC90(void*);
extern int D_00372E28;
void func_00220110(void*);
void func_00289CF8(int);
void* func_00113D20(u32 size);
void* func_0021DDB8(void*);
void* func_0021DFB0(void*);
void func_001D0F90(void*, int);
extern u8 D_00351A30[];
void func_00276D68(u32, void*, int);
extern u8 D_00390580[];
void func_002210B8(void*);
int func_00220FE8(int, int, int);
int func_00174CE0(int);
}

INCLUDE_ASM("asm/nonmatchings/game/t_21DA40", func_0021DA40);

INCLUDE_ASM("asm/nonmatchings/game/t_21DA40", func_0021DB60);

extern "C" int func_0021DB98(void) {
    return 2;
}

INCLUDE_ASM("asm/nonmatchings/game/t_21DA40", func_0021DBA0);

extern "C" void func_0021DC40(void) {
}

INCLUDE_ASM("asm/nonmatchings/game/t_21DA40", func_0021DC48);

INCLUDE_ASM("asm/nonmatchings/game/t_21DA40", func_0021DC50);

extern "C" void func_0021DD70(void) {
    func_0021DC50(1, 0xFFFF);
}

extern "C" void* func_0021DD90(void) {
    return func_0021DDB8(func_00113D20(0x1C));
}

INCLUDE_ASM("asm/nonmatchings/game/t_21DA40", func_0021DDB8);

extern "C" void func_0021DE10(S21D* self, int flag) {
    self->unk18 = (VEntry21D*)D_00351A30;
    func_001D0F90(self, flag);
}

extern "C" void func_0021DE38(void) {
}

extern "C" void func_0021DE40(S21D* self, int a) {
    VEntry21D* e = &self->unk18[3];
    ((void (*)(void*, int))e->fn)((char*)self + e->delta, a);
}

inline void copy_0021DE68(M21D* d, M21D* s) {
    d->r[0] = s->r[0];
    d->r[1] = s->r[1];
    d->r[2] = s->r[2];
    d->r[3] = s->r[3];
}

extern "C" void func_0021DE68(S21D* self) {
    S21Db* p = self->unkC;
    copy_0021DE68(&p->unk100, &p->unkA0);
}

extern "C" int func_0021DE98(void) {
    return 2;
}

extern "C" void func_0021DEA0(void* self) {
    func_001D10A0(self);
}

INCLUDE_ASM("asm/nonmatchings/game/t_21DA40", func_0021DEC0);

INCLUDE_ASM("asm/nonmatchings/game/t_21DA40", func_0021DED8);

extern "C" void func_0021DF38(void) {
    func_0021DED8(1, 0xFFFF);
}

extern "C" void* func_0021DF58(void) {
    return func_0021DFB0(func_00113D20(0x70));
}

extern "C" void func_0021DF80(void) {
    func_00276D68(0x8536DBA5, D_00390580, 0x10);
}

INCLUDE_ASM("asm/nonmatchings/game/t_21DA40", func_0021DFB0);

INCLUDE_ASM("asm/nonmatchings/game/t_21DA40", func_0021E038);

INCLUDE_ASM("asm/nonmatchings/game/t_21DA40", func_0021E0C8);

INCLUDE_ASM("asm/nonmatchings/game/t_21DA40", func_0021E140);

INCLUDE_ASM("asm/nonmatchings/game/t_21DA40", func_0021E1A0);

INCLUDE_ASM("asm/nonmatchings/game/t_21DA40", func_0021E208);

extern "C" void func_0021E2E0(S21D* self) {
    self->unk60->unk5C = 0;
    self->unk60->unk60 = 0;
    self->unk5C = 0;
    self->unk60 = 0;
}

INCLUDE_ASM("asm/nonmatchings/game/t_21DA40", func_0021E300);

extern "C" int func_0021E3A0(void) {
    return 2;
}

INCLUDE_ASM("asm/nonmatchings/game/t_21DA40", func_0021E3A8);

extern "C" int func_0021E498(S21D* self) {
    if (!self->unk1C) {
        return 0;
    }
    func_002210B8(self);
    return 1;
}

GP_DATA(D_00372E28);
extern "C" void func_0021E4C8(void) {
    func_0027AC90(&D_00372E28);
}

INCLUDE_ASM("asm/nonmatchings/game/t_21DA40", func_0021E4E8);

INCLUDE_ASM("asm/nonmatchings/game/t_21DA40", func_0021E658);

extern "C" int func_0021E6B8(S21D* self) {
    VEntry21D* e = &self->unk18[2];
    ((void (*)(void*))e->fn)((char*)self + e->delta);
    return 1;
}

INCLUDE_ASM("asm/nonmatchings/game/t_21DA40", func_0021E6E8);

INCLUDE_ASM("asm/nonmatchings/game/t_21DA40", func_0021E750);

extern "C" int func_0021E790(void* self) {
    func_00220110(self);
    return 1;
}

INCLUDE_ASM("asm/nonmatchings/game/t_21DA40", func_0021E7B0);

extern "C" int func_0021E7F0(void) {
    return 1;
}

INCLUDE_ASM("asm/nonmatchings/game/t_21DA40", func_0021E7F8);

INCLUDE_ASM("asm/nonmatchings/game/t_21DA40", func_0021E848);

INCLUDE_ASM("asm/nonmatchings/game/t_21DA40", func_0021E8C8);

extern "C" int func_0021E970(int a, int b) {
    int r = func_00220FE8(a, b, 1);
    if (r == 0) {
        return 1;
    }
    return func_00174CE0(r);
}

INCLUDE_ASM("asm/nonmatchings/game/t_21DA40", func_0021E9A8);

INCLUDE_ASM("asm/nonmatchings/game/t_21DA40", func_0021EB20);

INCLUDE_ASM("asm/nonmatchings/game/t_21DA40", func_0021EBB0);

INCLUDE_ASM("asm/nonmatchings/game/t_21DA40", func_0021ED28);

INCLUDE_ASM("asm/nonmatchings/game/t_21DA40", func_0021EDB8);

INCLUDE_ASM("asm/nonmatchings/game/t_21DA40", func_0021EF30);

INCLUDE_ASM("asm/nonmatchings/game/t_21DA40", func_0021EFC8);

INCLUDE_ASM("asm/nonmatchings/game/t_21DA40", func_0021F020);

INCLUDE_ASM("asm/nonmatchings/game/t_21DA40", func_0021F248);

extern "C" int func_0021F2C8(void* self, int a, int b) {
    func_00289CF8(b);
    return 1;
}

INCLUDE_ASM("asm/nonmatchings/game/t_21DA40", func_0021F2E8);

extern "C" int func_0021F328(void* self, int a, int b) {
    func_00289CF8(b);
    return 1;
}

INCLUDE_ASM("asm/nonmatchings/game/t_21DA40", func_0021F348);

INCLUDE_ASM("asm/nonmatchings/game/t_21DA40", func_0021F748);

INCLUDE_ASM("asm/nonmatchings/game/t_21DA40", func_0021F8D8);

INCLUDE_ASM("asm/nonmatchings/game/t_21DA40", func_0021FA28);
