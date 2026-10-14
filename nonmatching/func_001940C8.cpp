#include "common.h"

struct S001941E8 {
    char pad0[0x8];
    void* unk8;
    char padC[0x14];
    void* unk20;
};

extern "C" {
extern u8 D_003465B8[];
extern u8 D_003465D0[];
void func_00169738(void);
extern u8 D_00346720[];
extern u8 D_00346738[];
void func_0016A2F0(void);
extern u8 D_00346888[];
extern u8 D_003468A0[];
void func_00168708(void);
}

struct VE_1940C8 { s16 delta; s16 unk2; void* fn; };
struct VO_1940C8 { char pad0[0x34]; VE_1940C8* unk34; };
struct H_1940C8 { VO_1940C8* unk0; int unk4; int unk8; };
struct R_1940C8 { char pad0[4]; int unk4; char pad8[8]; int* unk10; };
struct S_1940C8 { char pad0[8]; void* unk8; char padC[0x14]; void* unk20; char pad24[0x2CC]; u64 unk2F0; char pad2F8[0]; R_1940C8* unk2F8; };

extern "C" {
extern int D_0036F658;
void func_00169378(void);
void func_0022B0D0(H_1940C8*, int, int, int);
void func_00134340(H_1940C8*);
long func_001A4770(int, int);
}

extern "C" S_1940C8* func_001940C8(S_1940C8* self, int a1, int a2, int key, int x, int y) {
    func_00169378();
    self->unk2F8 = 0;
    self->unk20 = D_003465B8;
    self->unk8 = D_003465D0;
    H_1940C8 h;
    func_0022B0D0(&h, D_0036F658, key, 1);
    VO_1940C8* o = h.unk0;
    R_1940C8* r = o ? ((R_1940C8* (*)(void*))o->unk34[2].fn)((char*)o + o->unk34[2].delta) : 0;
    func_00134340(&h);
    if (r) {
        int f = r->unk4;
        int v;
        if ((f >> 2) & 1) {
            v = r->unk10[3];
        } else {
            v = 0;
        }
        if (!v) {
            if ((f >> 2) & 1) {
                v = r->unk10[0];
            } else {
                v = 0;
                if (f & 1) v = (int)r->unk10;
            }
        }
        self->unk2F8 = (R_1940C8*)v;
    }
    self->unk2F0 = func_001A4770(x, y);
    return self;
}

extern "C" void func_001941E8(S001941E8* self) {
    self->unk20 = D_003465B8;
    self->unk8 = D_003465D0;
    func_00169738();
}

INCLUDE_ASM("asm/nonmatchings/game/t_1940C8", func_00194218);

INCLUDE_ASM("asm/nonmatchings/game/t_1940C8", func_00194C18);

extern "C" void func_00194D38(S001941E8* self) {
    self->unk20 = D_00346720;
    self->unk8 = D_00346738;
    func_0016A2F0();
}

INCLUDE_ASM("asm/nonmatchings/game/t_1940C8", func_00194D68);

INCLUDE_ASM("asm/nonmatchings/game/t_1940C8", func_00195388);

extern "C" void func_001954C0(S001941E8* self) {
    self->unk20 = D_00346888;
    self->unk8 = D_003468A0;
    func_00168708();
}

INCLUDE_ASM("asm/nonmatchings/game/t_1940C8", func_001954F0);
