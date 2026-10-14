// cflags: -funroll-loops
#include "common.h"

INCLUDE_ASM("asm/nonmatchings/game/t_141FE0", func_00141FE0);

struct R_141 { int p; char pad4[0x1C]; };
struct D_141 { char pad0[8]; char* unk8; char padC[0x234]; R_141 unk240[25]; };

extern "C" {
void func_00142398(void);
void func_001CE888(int, void*);
void func_00139420(void*, int);
extern char D_0033B318[];
}

extern "C" void func_001422A8(D_141* self, int flags) {
    self->unk8 = D_0033B318;
    func_00142398();
    R_141* b = &self->unk240[0];
    if (b) {
        R_141* e = &self->unk240[25];
        while (b != e) {
            e--;
            if (e->p) { func_001CE888(e->p, e); e->p = 0; }
        }
    }
    func_00139420(self, flags);
}

INCLUDE_ASM("asm/nonmatchings/game/t_141FE0", func_00142398);

INCLUDE_ASM("asm/nonmatchings/game/t_141FE0", func_001424C0);

INCLUDE_ASM("asm/nonmatchings/game/t_141FE0", func_001427B0);

INCLUDE_ASM("asm/nonmatchings/game/t_141FE0", func_00142948);

INCLUDE_ASM("asm/nonmatchings/game/t_141FE0", func_001431D0);

INCLUDE_ASM("asm/nonmatchings/game/t_141FE0", func_00143BC0);

INCLUDE_ASM("asm/nonmatchings/game/t_141FE0", func_00143C60);
