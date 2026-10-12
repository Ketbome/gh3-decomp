#include "common.h"

struct S001A9D98 {
    char pad[0x1C];
    int unk1C;
};

INCLUDE_ASM("asm/nonmatchings/game/t_1A9A60", func_001A9A60);

INCLUDE_ASM("asm/nonmatchings/game/t_1A9A60", func_001A9A98);

INCLUDE_ASM("asm/nonmatchings/game/t_1A9A60", func_001A9B08);

INCLUDE_ASM("asm/nonmatchings/game/t_1A9A60", func_001A9B80);

INCLUDE_ASM("asm/nonmatchings/game/t_1A9A60", func_001A9C68);

INCLUDE_ASM("asm/nonmatchings/game/t_1A9A60", func_001A9CF0);

INCLUDE_ASM("asm/nonmatchings/game/t_1A9A60", func_001A9D28);

INCLUDE_ASM("asm/nonmatchings/game/t_1A9A60", func_001A9D68);

extern "C" int func_001A9D98(S001A9D98* self) {
    return ((self->unk1C >> 26) & 1);
}

INCLUDE_ASM("asm/nonmatchings/game/t_1A9A60", func_001A9DA8);

INCLUDE_ASM("asm/nonmatchings/game/t_1A9A60", func_001A9E78);

INCLUDE_ASM("asm/nonmatchings/game/t_1A9A60", func_001A9ED0);

INCLUDE_ASM("asm/nonmatchings/game/t_1A9A60", func_001A9F70);

INCLUDE_ASM("asm/nonmatchings/game/t_1A9A60", func_001AA448);

INCLUDE_ASM("asm/nonmatchings/game/t_1A9A60", func_001AAB00);
