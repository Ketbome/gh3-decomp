// cflags: -fno-gcse
#include "common.h"

struct S17F4F0 { char pad0[4]; int unk4; float* unk8; };

struct N_001800E8 { char pad0[4]; N_001800E8* unk4; };
struct L_001800E8 { char pad0[4]; void* unk4; void* unk8; };
struct S_001800E8 { char pad0[0x14]; void* unk14; void* unk18; };

extern "C" {
void Heap_Free(int, void*);
void func_00172A00(void*, int);
extern u8 D_003435E0[];
extern int D_00368A38[] __attribute__((section(".sdata")));
}

INCLUDE_ASM("asm/nonmatchings/game/t_17F4F0", func_0017F4F0);

INCLUDE_ASM("asm/nonmatchings/game/t_17F4F0", func_0017F590);

INCLUDE_ASM("asm/nonmatchings/game/t_17F4F0", func_0017F598);

INCLUDE_ASM("asm/nonmatchings/game/t_17F4F0", func_0017F630);

INCLUDE_ASM("asm/nonmatchings/game/t_17F4F0", func_0017F690);

INCLUDE_ASM("asm/nonmatchings/game/t_17F4F0", func_0017F7F0);

INCLUDE_ASM("asm/nonmatchings/game/t_17F4F0", func_0017F810);

INCLUDE_ASM("asm/nonmatchings/game/t_17F4F0", func_0017F9A0);

extern "C" void func_001800E8(S_001800E8* self, int flags) {
    self->unk14 = D_003435E0;
    if (self->unk18) {
        Heap_Free(D_00368A38[0], self->unk18);
        self->unk18 = 0;
    }
    L_001800E8* l = (L_001800E8*)((char*)self + 0x1C);
    N_001800E8* end = (N_001800E8*)((char*)self + 0x20);
    N_001800E8* p = (N_001800E8*)l->unk8;
    l->unk8 = end;
    l->unk4 = end;
    if (p != end) {
        N_001800E8* e = (N_001800E8*)((char*)l + 4);
        do {
            N_001800E8* n = p;
            p = p->unk4;
            Heap_Free(D_00368A38[0], n);
        } while (p != e);
    }
    func_00172A00(self, flags);
}

INCLUDE_ASM("asm/nonmatchings/game/t_17F4F0", func_00180190);

INCLUDE_ASM("asm/nonmatchings/game/t_17F4F0", func_00180578);

INCLUDE_ASM("asm/nonmatchings/game/t_17F4F0", func_00180660);
