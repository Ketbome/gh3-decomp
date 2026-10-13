#include "common.h"

struct S0016A328 {
    char pad[0x2F0];
    int unk2F0;
};

struct S0016A810 {
    char pad[0x2F8];
    float unk2F8;
};

struct S0016C158 {
    char pad[0x8];
    void* unk8;
};

struct S0016A2F0 {
    char pad0[0x8];
    void* unk8;
    char padC[0x14];
    void* unk20;
};

extern "C" {
void func_00162FC8_2(void*, int) __asm__("func_00162FC8");
extern u8 D_0033F4E8[];
extern u8 D_0033F500[];
void func_00119400(int, void*);
extern u8 D_0033F380[];
extern u8 D_0033F398[];
void* func_001CE7A8(void*);
void func_0016BF28(void*);
void func_0010F690(void*);
void func_001342B0(void*);
void func_00119990(int, int);
extern int D_00368A38[] __attribute__((section(".sdata")));
extern u8 D_0033F7C8[];
void func_001CE7C0(void*);
extern u8 D_0033F218[];
extern u8 D_0033F230[];
void func_00162FC8(void);
}

extern "C" void func_0016A2F0(S0016A2F0* self) {
    self->unk20 = D_0033F218;
    self->unk8 = D_0033F230;
    func_00162FC8();
}

extern "C" int func_0016A320(void) {
    return 4;
}

extern "C" int func_0016A328(S0016A328* self) {
    return self->unk2F0;
}

INCLUDE_ASM("asm/nonmatchings/game/t_16A2F0", func_0016A330);

struct S_0016A6A8 { char pad0[8]; void* unk8; char padC[0x14]; void* unk20; char pad24[0x2D8]; void* unk2FC; };

extern "C" void func_0016A6A8(S_0016A6A8* self, int flags) {
    void* p = self->unk2FC;
    self->unk20 = D_0033F380;
    self->unk8 = D_0033F398;
    if (p) {
        func_00119400(D_00368A38[0], p);
        self->unk2FC = 0;
    }
    func_00162FC8_2(self, flags);
}

INCLUDE_ASM("asm/nonmatchings/game/t_16A2F0", func_0016A718);

extern "C" void func_0016A810(S0016A810* self, float v) {
    self->unk2F8 = v;
}

extern "C" int func_0016A818(void) {
    return 3;
}

extern "C" int func_0016A820(void) {
    return 1;
}

INCLUDE_ASM("asm/nonmatchings/game/t_16A2F0", func_0016A828);

struct S_0016ABA0 { char pad0[8]; void* unk8; char padC[0x14]; void* unk20; char pad24[0x2D8]; void* unk2FC; };

extern "C" void func_0016ABA0(S_0016ABA0* self, int flags) {
    void* p = self->unk2FC;
    self->unk20 = D_0033F4E8;
    self->unk8 = D_0033F500;
    if (p) {
        func_00119400(D_00368A38[0], p);
        self->unk2FC = 0;
    }
    func_00162FC8_2(self, flags);
}

INCLUDE_ASM("asm/nonmatchings/game/t_16A2F0", func_0016AC10);

extern "C" void func_0016AD08(S0016A810* self, float v) {
    self->unk2F8 = v;
}

extern "C" int func_0016AD10(void) {
    return 3;
}

extern "C" int func_0016AD18(void) {
    return 1;
}

INCLUDE_ASM("asm/nonmatchings/game/t_16A2F0", func_0016AD20);

INCLUDE_ASM("asm/nonmatchings/game/t_16A2F0", func_0016ADD8);

INCLUDE_ASM("asm/nonmatchings/game/t_16A2F0", func_0016AF18);

struct S16AFC0 { char pad0[4]; int unk4; char pad8[4]; int unkC; };

extern "C" int func_0016AFC0(S16AFC0* self) {
    int r = self->unkC;
    if (r == 0) r = self->unk4;
    return r;
}

INCLUDE_ASM("asm/nonmatchings/game/t_16A2F0", func_0016AFD8);

struct VE_16AFE0 { s16 unk0; s16 unk2; void (*unk4)(void*, int); };
struct V_16AFE0 { char pad0[8]; VE_16AFE0 unk8; };
struct O_16AFE0 { char pad0[0x20]; V_16AFE0* unk20; };
struct S_16AFE0 { char pad0[8]; O_16AFE0* unk8; int unkC; };

extern "C" void func_0016AFE0(S_16AFE0* self) {
    if (self->unkC) {
        func_00119990(D_00368A38[0], self->unkC);
        O_16AFE0* o = self->unk8;
        if (o) {
            V_16AFE0* v = o->unk20;
            v->unk8.unk4((char*)o + v->unk8.unk0, 3);
        }
        self->unkC = 0;
        self->unk8 = 0;
    }
}

INCLUDE_ASM("asm/nonmatchings/game/t_16A2F0", func_0016B040);

INCLUDE_ASM("asm/nonmatchings/game/t_16A2F0", func_0016B1B8);

INCLUDE_ASM("asm/nonmatchings/game/t_16A2F0", func_0016B238);

struct N16BAF0 { char pad0[0xC]; N16BAF0* unkC; N16BAF0* unk10; };

extern "C" void func_0016BAF0(int unused, char* p) {
    if (p) {
        N16BAF0* n = (N16BAF0*)(p + 0xC);
        n->unk10->unkC = n->unkC;
        n->unkC->unk10 = n->unk10;
        n->unkC = n;
        n->unk10 = n;
    }
}

INCLUDE_ASM("asm/nonmatchings/game/t_16A2F0", func_0016BB20);

INCLUDE_ASM("asm/nonmatchings/game/t_16A2F0", func_0016BBC0);

INCLUDE_ASM("asm/nonmatchings/game/t_16A2F0", func_0016BC70);

INCLUDE_ASM("asm/nonmatchings/game/t_16A2F0", func_0016BCE0);

INCLUDE_ASM("asm/nonmatchings/game/t_16A2F0", func_0016BCE8);

INCLUDE_ASM("asm/nonmatchings/game/t_16A2F0", func_0016BE38);

INCLUDE_ASM("asm/nonmatchings/game/t_16A2F0", func_0016BEB0);

INCLUDE_ASM("asm/nonmatchings/game/t_16A2F0", func_0016BF28);

struct S16C0F8 { char pad0[8]; void* unk8; char padC[4]; char unk10[1]; };

extern "C" S16C0F8* func_0016C0F8(S16C0F8* self) {
    func_001CE7A8(self);
    char* t = (char*)self + 0x1B0;
    self->unk8 = D_0033F7C8;
    func_0016BF28(self->unk10);
    func_0010F690(t);
    func_0010F690((char*)self + 0x1C0);
    func_001342B0(t);
    return self;
}

extern "C" void func_0016C158(S0016C158* self) {
    self->unk8 = D_0033F7C8;
    func_001CE7C0(self);
}

INCLUDE_ASM("asm/nonmatchings/game/t_16A2F0", func_0016C180);
