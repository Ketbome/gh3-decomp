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

struct B50_161 {
    u64 f0 : 1;
    u64 f1 : 2;
    u64 f3 : 1;
    u64 f4 : 1;
    u64 f5 : 1;
    u64 f6 : 58;
};
struct S50_161 { char pad0[0x50]; B50_161 unk50; VEntry* unk58; };
struct I3_161 {
    int unk0;
    int unk4;
    int unk8;
};
struct C_161 {
    int unk0;
    int unk4;
    int unk8;
    I3_161 unkC;
    int unk18;
};
struct S8_161 { char pad0[0x8]; s8 unk8; };
struct N_161 { int unk0; N_161* unk4; int* unk8; };
struct It_161 {
    int unk0;
    N_161* cur;
    It_161(N_161* n) : cur(n) {}
    bool operator!=(const It_161& o) const { return cur != o.cur; }
    void operator++() { cur = cur->unk4; }
};
struct L_161 { char pad0[0x14]; N_161 unk14; };
struct SBC_161 { char pad0[0xBC]; void* unkBC; };
struct S1E0_161 { char pad0[0x1E0]; int unk1E0; };

extern "C" {
void func_0011D348(void*);
void func_001628B8(S8_161*);
void func_0015F1A0(int);
extern u8 D_0033DED0[];
extern int D_00368A38;
void func_00119400(int, void*);
int func_0028C200(int);
void func_00289B40(int, int);
}

INCLUDE_ASM("asm/nonmatchings/game/t_161580", func_00161580);

extern "C" int func_001618A0(L_161* self, int idx) {
    It_161 end(&self->unk14);
    It_161 it(self->unk14.unk4);
    int i = 0;
    for (; it != end; ++it) {
        if (idx == i) {
            return it.cur->unk8[0];
        }
        i++;
    }
    return 0;
}

extern "C" int func_001618F8(L_161* self, int idx) {
    It_161 end(&self->unk14);
    It_161 it(self->unk14.unk4);
    int i = 0;
    for (; it != end; ++it) {
        if (idx == i) {
            return it.cur->unk8[2];
        }
        i++;
    }
    return 0;
}

INCLUDE_ASM("asm/nonmatchings/game/t_161580", func_00161950);

extern "C" void func_00161960(L_161* self) {
    It_161 end(&self->unk14);
    It_161 it(self->unk14.unk4);
    for (; it != end; ++it) func_0015F1A0(*it.cur->unk8);
}

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

extern "C" void func_00161FD8(S50_161* self, int v) {
    self->unk50.f3 = v;
}

INCLUDE_ASM("asm/nonmatchings/game/t_161580", func_00161FF8);

INCLUDE_ASM("asm/nonmatchings/game/t_161580", func_00162070);

INCLUDE_ASM("asm/nonmatchings/game/t_161580", func_001620D8);

extern "C" void func_00162140(S50_161* self, int a) {
    self->unk50.f0 = 0;
    VEntry* e = &self->unk58[14];
    ((void (*)(void*, int))e->fn)((char*)self + e->delta, a);
}

extern "C" void func_00162178(S001619B0* self) {
    VEntry* e = &self->unk58[15];
    ((void (*)(void*))e->fn)((char*)self + e->delta);
}

INCLUDE_ASM("asm/nonmatchings/game/t_161580", func_001621A0);

extern "C" void func_00162358(S50_161* self, int v) {
    self->unk50.f5 = v;
}

extern "C" C_161* func_00162378(C_161* self) {
    I3_161* p = &self->unkC;
    p->unk0 = 0;
    p->unk4 = 0;
    p->unk8 = 0;
    self->unk0 = 0;
    self->unk4 = 0;
    self->unk18 = 0;
    self->unk8 = 0;
    return self;
}

INCLUDE_ASM("asm/nonmatchings/game/t_161580", func_001623A0);

INCLUDE_ASM("asm/nonmatchings/game/t_161580", func_001623B8);

extern "C" void func_00162420(SBC_161* self, int flags) {
    self->unkBC = D_0033DED0;
    func_001628B8((S8_161*)self);
    if (flags & 1) {
        func_00119400(D_00368A38, self);
    }
}

INCLUDE_ASM("asm/nonmatchings/game/t_161580", func_00162470);

extern "C" void func_001628B8(S8_161* self) {
    if (self->unk8) {
        func_0011D348(&self->unk8);
        self->unk8 = 0;
    }
}

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

extern "C" void func_00163328(S1E0_161* self) {
    if (self->unk1E0 && !func_0028C200(self->unk1E0)) {
        if (self->unk1E0) {
            func_00289B40(self->unk1E0, 3);
        }
        self->unk1E0 = 0;
    }
}

INCLUDE_ASM("asm/nonmatchings/game/t_161580", func_00163380);

INCLUDE_ASM("asm/nonmatchings/game/t_161580", func_00163410);
