#include "common.h"

struct S00173F90 {
    char pad[0x14];
    void* unk14;
};

struct S172940b { char pad0[0x208]; int unk208; };
struct S172940a { char pad0[0x1C]; char* unk1C; };
struct S172940 { char pad0[0x3C]; S172940a* unk3C; };

extern "C" {
void func_00172E18(void);
extern u8 D_00340B00[];
void func_00172A00(void*);
extern S172940* D_0036AA94;
}

INCLUDE_ASM("asm/nonmatchings/game/t_1727C8", func_001727C8);

INCLUDE_ASM("asm/nonmatchings/game/t_1727C8", func_001728A0);

GP_DATA(D_0036AA94);
extern "C" void func_00172940(int* a, S172940b** b) {
    S172940b* p = (S172940b*)(D_0036AA94->unk3C->unk1C + 0xC);
    *a = p->unk208;
    *b = p;
}

extern "C" int func_00172960(void) {
    char buf[0x40];
    return 0;
}

INCLUDE_ASM("asm/nonmatchings/game/t_1727C8", func_00172970);

INCLUDE_ASM("asm/nonmatchings/game/t_1727C8", func_001729C8);

INCLUDE_ASM("asm/nonmatchings/game/t_1727C8", func_00172A00);

INCLUDE_ASM("asm/nonmatchings/game/t_1727C8", func_00172B38);

struct VEntry_00172C30 { s16 delta; s16 unk2; void* fn; };
struct VT_00172C30 { char pad0[0x28]; VEntry_00172C30 unk28; VEntry_00172C30 unk30; };
struct O_00172C30 { char pad0[0x14]; VT_00172C30* unk14; };
struct N_00172C30 { int unk0; N_00172C30* unk4; O_00172C30* unk8; };
struct It_00172C30 {
    int unk0;
    N_00172C30* cur;
    It_00172C30(N_00172C30* n) : cur(n) {}
    bool operator!=(const It_00172C30& o) const { return cur != o.cur; }
    void operator++() { cur = cur->unk4; }
};
struct S_00172C30 { char pad0[4]; N_00172C30 unk4; char pad10[4]; VT_00172C30* unk14; };

extern "C" void func_00172C30(S_00172C30* self, float f) {
    VEntry_00172C30* e = &self->unk14->unk28;
    ((void (*)(void*, float*))e->fn)((char*)self + e->delta, &f);
    for (It_00172C30 it(self->unk4.unk4); it != It_00172C30(&self->unk4); ++it) {
        O_00172C30* o = it.cur->unk8;
        VEntry_00172C30* e = &o->unk14->unk30;
        ((void (*)(void*, void*, float))e->fn)((char*)o + e->delta, o, f);
    }
}

extern "C" int func_00172CC0(void) {
    return 1;
}

INCLUDE_ASM("asm/nonmatchings/game/t_1727C8", func_00172CC8);

INCLUDE_ASM("asm/nonmatchings/game/t_1727C8", func_00172D00);

INCLUDE_ASM("asm/nonmatchings/game/t_1727C8", func_00172D80);

extern "C" void func_00172E00(void) {
}

extern "C" void func_00172E08(void) {
}

extern "C" void func_00172E10(void) {
}

INCLUDE_ASM("asm/nonmatchings/game/t_1727C8", func_00172E18);

INCLUDE_ASM("asm/nonmatchings/game/t_1727C8", func_00173C78);

extern "C" void func_00173F60(void) {
    func_00172E18();
}

extern "C" u32 func_00173F80(void) {
    return 0xDA3403B0 /* null */;
}

extern "C" void func_00173F90(S00173F90* self) {
    self->unk14 = D_00340B00;
    func_00172A00(self);
}

INCLUDE_ASM("asm/nonmatchings/game/t_1727C8", func_00173FB8);

INCLUDE_ASM("asm/nonmatchings/game/t_1727C8", func_00174058);

INCLUDE_ASM("asm/nonmatchings/game/t_1727C8", func_001746A8);
