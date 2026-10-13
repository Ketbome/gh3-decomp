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
void* func_0015D5A0(int);
extern int D_00369A44;
extern u8 D_0033F688[];
void func_0016AFE0_v(void*) __asm__("func_0016AFE0");
void func_00162FC8_2(void*, int) __asm__("func_00162FC8");
extern u8 D_0033F4E8[];
extern u8 D_0033F500[];
void Heap_Free(int, void*);
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
        Heap_Free(D_00368A38[0], p);
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
        Heap_Free(D_00368A38[0], p);
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

struct O_16AD20 { char pad0[0x2E0]; u8 unk2E0; };

extern "C" int func_0016AD20(O_16AD20** pa, O_16AD20** pb) {
    char* cam = (char*)func_0015D5A0(D_00369A44);
    O_16AD20* a = *pa;
    O_16AD20* b = *pb;
    float fa;
    float fb;
    int t;
    asm("lqc2 $vf3, 0x80(%0)\n\tlqc2 $vf1, 0x30(%3)\n\tvsub.xyzw $vf1, $vf1, $vf3\n\tlqc2 $vf2, 0x30(%4)\n\tvsub.xyzw $vf2, $vf2, $vf3\n\tvmul.xyzw $vf1, $vf1, $vf1\n\tvaddy.x $vf3, $vf1, $vf1y\n\tvmul.xyzw $vf2, $vf2, $vf2\n\tvaddz.x $vf3, $vf3, $vf1z\n\tvaddy.x $vf4, $vf2, $vf2y\n\tqmfc2.ni %0, $vf3\n\tvaddz.x $vf4, $vf4, $vf2z\n\tmtc1 %0, %1\n\tqmfc2.ni %0, $vf4"
        : "=r"(t), "=f"(fa) : "0"(cam), "r"(a), "r"(b));
    asm("mtc1 %1, %0" : "=f"(fb) : "r"(t));
    float d = fb - fa;
    if (d > 0.0f) {
        return 1;
    }
    if (d < 0.0f) {
        return -1;
    }
    return b->unk2E0 - a->unk2E0;
}

INCLUDE_ASM("asm/nonmatchings/game/t_16A2F0", func_0016ADD8);

struct VE_16AF18 { s16 unk0; s16 unk2; void (*unk4)(void*, int); };
struct V1_16AF18 { char pad0[8]; VE_16AF18 unk8; };
struct O1_16AF18 { char pad0[0x14]; V1_16AF18* unk14; };
struct O2_16AF18 { char pad0[0x20]; V1_16AF18* unk20; };
struct S_16AF18 { O2_16AF18* unk0; int unk4; char pad8[8]; O1_16AF18* unk10; char pad14[0x24]; void* unk38; };

extern "C" void func_0016AF18(S_16AF18* self, int flags) {
    self->unk38 = D_0033F688;
    O1_16AF18* o = self->unk10;
    if (o) {
        V1_16AF18* v = o->unk14;
        v->unk8.unk4((char*)o + v->unk8.unk0, 3);
    }
    func_0016AFE0_v(self);
    func_00119990(D_00368A38[0], self->unk4);
    O2_16AF18* p = self->unk0;
    if (p) {
        V1_16AF18* v = p->unk20;
        v->unk8.unk4((char*)p + v->unk8.unk0, 3);
    }
    if (flags & 1) {
        Heap_Free(D_00368A38[0], self);
    }
}

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

struct M_0016B1B8 { char pad0[4]; u32 unk4; };
struct O_0016B1B8 { char pad0[0x18]; M_0016B1B8* unk18; char pad1C[0x1B8]; int unk1D4; };
struct H_0016B1B8 { char pad0[0xC]; M_0016B1B8* unkC; };
struct S_0016B1B8 { char pad0[0x10]; H_0016B1B8* unk10; };

inline M_0016B1B8* Get_0016B1B8(M_0016B1B8* m) {
    if (~m->unk4 == 0) return 0;
    return m;
}

inline O_0016B1B8* Cast_0016B1B8(M_0016B1B8* m) {
    if (m) return (O_0016B1B8*)((char*)m - 0xC);
    return 0;
}

extern "C" O_0016B1B8* func_0016B1B8(S_0016B1B8* self, int key) {
    if (self->unk10) {
        O_0016B1B8* o = Cast_0016B1B8(Get_0016B1B8(self->unk10->unkC));
        while (o) {
            if (o->unk1D4 == key) return o;
            o = Cast_0016B1B8(Get_0016B1B8(o->unk18));
        }
    }
    return 0;
}

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

struct M_0016BBC0 { char pad0[4]; u32 unk4; char pad8[4]; M_0016BBC0* unkC; };
struct VE_0016BBC0 { char pad0[8]; s16 unk8; s16 unkA; void (*unkC)(void*, int); };
struct O_0016BBC0 { char pad0[8]; VE_0016BBC0* unk8; char padC[0xC]; M_0016BBC0* unk18; char pad1C[0x1BC]; int unk1D8; };
struct H_0016BBC0 { char pad0[0xC]; M_0016BBC0* unkC; };
struct S_0016BBC0 { char pad0[0x10]; H_0016BBC0* unk10; };

extern "C" void func_0016BBC0(S_0016BBC0* self, int key) {
    if (self->unk10) {
        M_0016BBC0* m = self->unk10->unkC;
        if (~m->unk4 == 0) m = 0;
        O_0016BBC0* o = 0;
        if (m) o = (O_0016BBC0*)((char*)m - 0xC);
        if (o) {
            O_0016BBC0* nx;
            do {
                O_0016BBC0* cur = o;
                M_0016BBC0* n = cur->unk18;
                if (~n->unk4 == 0) n = 0;
                nx = 0;
                if (n) nx = (O_0016BBC0*)((char*)n - 0xC);
                o = nx;
                if (cur->unk1D8 == key && cur) {
                    VE_0016BBC0* e = cur->unk8;
                    e->unkC((char*)cur + e->unk8, 3);
                }
            } while (nx);
        }
    }
}

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
