#include "common.h"

extern "C" {
void func_0013F4F8(void*, int*, int);
}

struct S_0013DF78 { char pad0[0x260]; float unk260; float unk264; };

INCLUDE_ASM("asm/nonmatchings/game/t_13DEB8", func_0013DEB8);

INCLUDE_ASM("asm/nonmatchings/game/t_13DEB8", func_0013DF18);

extern "C" void func_0013DF78(S_0013DF78* self, float a, float b) {
    self->unk260 = a;
    self->unk264 = b;
}

INCLUDE_ASM("asm/nonmatchings/game/t_13DEB8", func_0013DF88);

INCLUDE_ASM("asm/nonmatchings/game/t_13DEB8", func_0013E870);

INCLUDE_ASM("asm/nonmatchings/game/t_13DEB8", func_0013EB38);

INCLUDE_ASM("asm/nonmatchings/game/t_13DEB8", func_0013EC10);

INCLUDE_ASM("asm/nonmatchings/game/t_13DEB8", func_0013EC98);

INCLUDE_ASM("asm/nonmatchings/game/t_13DEB8", func_0013ED28);

INCLUDE_ASM("asm/nonmatchings/game/t_13DEB8", func_0013ED80);

INCLUDE_ASM("asm/nonmatchings/game/t_13DEB8", func_0013F258);

INCLUDE_ASM("asm/nonmatchings/game/t_13DEB8", func_0013F3E8);

INCLUDE_ASM("asm/nonmatchings/game/t_13DEB8", func_0013F4F8);

extern "C" void func_0013FC50(void* self, int v) {
    func_0013F4F8(self, &v, 1);
}

INCLUDE_ASM("asm/nonmatchings/game/t_13DEB8", func_0013FC78);

INCLUDE_ASM("asm/nonmatchings/game/t_13DEB8", func_0013FE00);
