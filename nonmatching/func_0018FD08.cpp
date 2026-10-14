#include "common.h"

struct S0018DE88 {
    char pad0[0x8];
    void* unk8;
    char padC[0x14];
    void* unk20;
};

extern "C" {
void func_00169BF0(void*, int, int);
void func_0022B0D0(void*, int, int, int);
void func_00134340(void*);
long func_001A4770(int, int);
extern int D_0036F658[] __attribute__((section(".sdata")));
extern u8 D_00345BE0[];
extern u8 D_00345BF8[];
extern u8 D_00345910[];
extern u8 D_00345928[];
void func_00167958(void);
extern u8 D_00345A78[];
extern u8 D_00345A90[];
void func_00169A70(void);
}

INCLUDE_ASM("asm/nonmatchings/game/t_18DD30", func_0018DD30);

INCLUDE_ASM("asm/nonmatchings/game/t_18DD30", func_0018DD68);

extern "C" void func_0018DE88(S0018DE88* self) {
    self->unk20 = D_00345910;
    self->unk8 = D_00345928;
    func_00167958();
}

INCLUDE_ASM("asm/nonmatchings/game/t_18DD30", func_0018DEB8);

INCLUDE_ASM("asm/nonmatchings/game/t_18DD30", func_0018E6C8);

extern "C" void func_0018E7F0(S0018DE88* self) {
    self->unk20 = D_00345A78;
    self->unk8 = D_00345A90;
    func_00169A70();
}

INCLUDE_ASM("asm/nonmatchings/game/t_18DD30", func_0018E820);

struct VE_0018FD08 { s16 unk0; s16 unk2; void* (*unk4)(void*, void*); };
struct VT_0018FD08 { char pad0[0x10]; VE_0018FD08 unk10; };
struct R_0018FD08 { char pad0[0x34]; VT_0018FD08* unk34; };
struct B_0018FD08 { void* unk0; char pad4[8]; void* unkC; };
struct V_0018FD08 { char pad0[4]; int unk4; char pad8[8]; B_0018FD08* unk10; };
struct S_0018FD08 { char pad0[8]; void* unk8; char padC[0x14]; void* unk20; char pad24[0x2DC]; long unk300; void* unk308; };

extern "C" S_0018FD08* func_0018FD08(S_0018FD08* self, int a1, int a2, int key, int p4, int p5) {
    R_0018FD08* r[4];
    V_0018FD08* v;
    int h;
    func_00169BF0(self, a1, a2);
    h = D_0036F658[0];
    self->unk308 = 0;
    self->unk20 = D_00345BE0;
    self->unk8 = D_00345BF8;
    func_0022B0D0(r, h, key, 1);
    key = 0;
    if (r[0]) {
        VE_0018FD08* e = &r[0]->unk34->unk10;
        key = (int)e->unk4((char*)r[0] + e->unk0, r[0]);
    }
    func_00134340(r);
    v = (V_0018FD08*)key;
    if (v) {
        void* t;
        if ((v->unk4 >> 2) & 1) {
            t = v->unk10->unkC;
            if (!t) goto get;
        } else {
        get:
            if ((v->unk4 >> 2) & 1) {
                t = v->unk10->unk0;
            } else {
                t = 0;
                if (v->unk4 & 1) t = v->unk10;
            }
        }
        self->unk308 = t;
    }
    self->unk300 = func_001A4770(p4, p5);
    return self;
}
