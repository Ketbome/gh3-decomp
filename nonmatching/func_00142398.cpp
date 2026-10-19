// cflags: -funroll-loops
#include "common.h"

INCLUDE_ASM("asm/nonmatchings/game/t_141FE0", func_00141FE0);

INCLUDE_ASM("asm/nonmatchings/game/t_141FE0", func_001422A8);

typedef unsigned int u128_141 __attribute__((mode(TI)));

static inline u128_141 MakeVec141(f32 x, f32 y, f32 z, int w) {
    u128_141 lo, hi;
    asm("pextlw %0, %1, %2" : "=r"(lo) : "r"(y), "r"(x));
    asm("pextlw %0, %1, %2" : "=r"(hi) : "r"(w), "r"(z));
    asm("pcpyld %0, %1, %2" : "=r"(lo) : "r"(hi), "0"(lo));
    return lo;
}

struct VT141 { char pad0[0x40]; s16 delta; s16 pad42; void (*fn)(void*); };
struct O141 { char pad0[8]; VT141* vt; };
struct E141 { O141* obj; char pad4[0xC]; u128_141 vec; };
struct S141 { char pad0[0x240]; E141 e[25]; int unk560; };

extern "C" void func_001D1438(void*, int);

extern "C" void func_00142398(S141* self) {
    E141* end = &self->e[25];
    for (E141* e = self->e; e != end; e++) {
        if (e->obj) {
            func_001D1438(e->obj, 1);
            O141* o = e->obj;
            o->vt->fn((char*)o + o->vt->delta);
        }
        e->vec = MakeVec141(0.0f, 0.0f, 0.0f, 0x3F800000);
    }
    self->unk560 = 0;
}

INCLUDE_ASM("asm/nonmatchings/game/t_141FE0", func_001424C0);

INCLUDE_ASM("asm/nonmatchings/game/t_141FE0", func_001427B0);

INCLUDE_ASM("asm/nonmatchings/game/t_141FE0", func_00142948);

INCLUDE_ASM("asm/nonmatchings/game/t_141FE0", func_001431D0);

INCLUDE_ASM("asm/nonmatchings/game/t_141FE0", func_00143BC0);

INCLUDE_ASM("asm/nonmatchings/game/t_141FE0", func_00143C60);
