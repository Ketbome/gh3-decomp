#include "common.h"

struct S2DF2F8_0 {
    char pad0[0xEE88];
    s32 unkEE88;
};

struct S2DF308_0 {
    char pad0[0xEE5C];
    s32 unkEE5C;
};

struct S2DF328_0 {
    char pad0[0xEE00];
    void *unkEE00;
};

struct S2DF398_0 {
    char pad0[0xC];
    void *unkC;
    void *unk10;
    void *unk14;
};

struct S2DF898_0 {
    char pad0[0x8C];
    void *unk8C;
};

struct S2DF978_0 {
    char pad0[0x8C];
    s32 unk8C;
};

struct S2DF988_0 {
    char pad0[0x9C];
    s32 unk9C;
};

extern "C" {
extern int D_00363DB8[];
extern s32 D_00368A38[] __attribute__((section(".sdata")));
int func_00119400(s32, void *);
}

extern "C" s32 func_002DEE90(void) {
    return 0;
}

extern "C" s32 func_002DEE98(void) {
    return 0;
}

extern "C" void func_002DEEA0(void) {
}

extern "C" void func_002DEEA8(void) {
}

extern "C" void func_002DEEB0(void) {
}

extern "C" void func_002DEEB8(void) {
}

INCLUDE_ASM("asm/nonmatchings/game/t_2DEE90", func_002DEEC0);

INCLUDE_ASM("asm/nonmatchings/game/t_2DEE90", func_002DEF48);

INCLUDE_ASM("asm/nonmatchings/game/t_2DEE90", func_002DF050);

extern "C" s32 func_002DF110(void) {
    return 0;
}

extern "C" void func_002DF118(void) {
}

extern "C" void func_002DF120(void) {
}

extern "C" void func_002DF128(void) {
}

extern "C" void func_002DF130(void) {
}

extern "C" void func_002DF138(void) {
}

extern "C" void func_002DF140(void) {
}

extern "C" void func_002DF148(void) {
}

INCLUDE_ASM("asm/nonmatchings/game/t_2DEE90", func_002DF150);

extern "C" s32 func_002DF188(void) {
    return 4;
}

extern "C" void func_002DF190(void) {
}

extern "C" void func_002DF198(void) {
}

INCLUDE_ASM("asm/nonmatchings/game/t_2DEE90", func_002DF1A0);

extern "C" void func_002DF1E0(void) {
}

extern "C" s32 func_002DF1E8(void) {
    return 0;
}

INCLUDE_ASM("asm/nonmatchings/game/t_2DEE90", func_002DF1F0);

extern "C" void func_002DF298(void) {
}

extern "C" void func_002DF2A0(void) {
}

extern "C" s32 func_002DF2A8(void) {
    return 0;
}

extern "C" s32 func_002DF2B0(void) {
    return 0;
}

extern "C" s32 func_002DF2B8(void) {
    return 0;
}

INCLUDE_ASM("asm/nonmatchings/game/t_2DEE90", func_002DF2C0);

extern "C" s32 func_002DF2F8(S2DF2F8_0 *arg0) {
    return arg0->unkEE88;
}

extern "C" void func_002DF308(S2DF308_0 *arg0, s32 arg1) {
    arg0->unkEE5C = arg1;
}

extern "C" s32 func_002DF318(S2DF308_0 *arg0) {
    return arg0->unkEE5C;
}

extern "C" void func_002DF328(S2DF328_0 *arg0) {
    s16 temp_6;
    void *temp_3;

    temp_3 = arg0->unkEE00;
    temp_6 = (*(s16 *)((char *)(temp_3) + 0x88));
    (*(int (**)(void *, int, s16))((char *)(temp_3) + 0x8C))((char *)arg0 + temp_6, 1, temp_6);
}

extern "C" void func_002DF360(S2DF328_0 *arg0) {
    s16 temp_6;
    void *temp_3;

    temp_3 = arg0->unkEE00;
    temp_6 = (*(s16 *)((char *)(temp_3) + 0x88));
    (*(int (**)(void *, int, s16))((char *)(temp_3) + 0x8C))((char *)arg0 + temp_6, 0, temp_6);
}

extern "C" void func_002DF398(S2DF398_0 *arg0, s32 arg1) {
    void *temp_6;

    temp_6 = arg0->unk10;
    arg0->unk14 = D_00363DB8;
    (*(void **)((char *)(temp_6) + 0xC)) = (void *) arg0->unkC;
    (*(void **)((char *)(arg0->unkC) + 0x10)) = (void *) arg0->unk10;
    arg0->unkC = arg0;
    arg0->unk10 = arg0;
    if (arg1 & 1) {
        func_00119400(D_00368A38[0], arg0);
    }
}

extern "C" void func_002DF3F8(S2DF398_0 *arg0, s32 arg1) {
    void *temp_6;

    temp_6 = arg0->unk10;
    arg0->unk14 = D_00363DB8;
    (*(void **)((char *)(temp_6) + 0xC)) = (void *) arg0->unkC;
    (*(void **)((char *)(arg0->unkC) + 0x10)) = (void *) arg0->unk10;
    arg0->unkC = arg0;
    arg0->unk10 = arg0;
    if (arg1 & 1) {
        func_00119400(D_00368A38[0], arg0);
    }
}

INCLUDE_ASM("asm/nonmatchings/game/t_2DEE90", func_002DF458);

INCLUDE_ASM("asm/nonmatchings/game/t_2DEE90", func_002DF4A0);

extern "C" s32 func_002DF4C0(void) {
    return 4;
}

extern "C" s32 func_002DF4C8(void) {
    return 4;
}

extern "C" s32 func_002DF4D0(void) {
    return 4;
}

extern "C" s32 func_002DF4D8(void) {
    return 4;
}

extern "C" s32 func_002DF4E0(void) {
    return 4;
}

extern "C" s32 func_002DF4E8(void) {
    return 4;
}

extern "C" s32 func_002DF4F0(void) {
    return 4;
}

extern "C" s32 func_002DF4F8(void) {
    return 4;
}

extern "C" s32 func_002DF500(void) {
    return 4;
}

extern "C" s32 func_002DF508(void) {
    return 4;
}

extern "C" s32 func_002DF510(void) {
    return 4;
}

extern "C" s32 func_002DF518(void) {
    return 4;
}

extern "C" s32 func_002DF520(void) {
    return 4;
}

extern "C" s32 func_002DF528(void) {
    return 4;
}

extern "C" s32 func_002DF530(void) {
    return 4;
}

extern "C" s32 func_002DF538(void) {
    return 4;
}

extern "C" s32 func_002DF540(void) {
    return 4;
}

extern "C" s32 func_002DF548(void) {
    return 4;
}

extern "C" s32 func_002DF550(void) {
    return 4;
}

extern "C" s32 func_002DF558(void) {
    return 4;
}

extern "C" s32 func_002DF560(void) {
    return 4;
}

extern "C" s32 func_002DF568(void) {
    return 4;
}

extern "C" s32 func_002DF570(void) {
    return 4;
}

extern "C" s32 func_002DF578(void) {
    return 4;
}

extern "C" s32 func_002DF580(void) {
    return 4;
}

extern "C" s32 func_002DF588(void) {
    return 4;
}

extern "C" s32 func_002DF590(void) {
    return 4;
}

extern "C" s32 func_002DF598(void) {
    return 4;
}

extern "C" s32 func_002DF5A0(void) {
    return 4;
}

extern "C" s32 func_002DF5A8(void) {
    return 4;
}

extern "C" s32 func_002DF5B0(void) {
    return 4;
}

extern "C" s32 func_002DF5B8(void) {
    return 4;
}

extern "C" s32 func_002DF5C0(void) {
    return 4;
}

extern "C" s32 func_002DF5C8(void) {
    return 4;
}

extern "C" s32 func_002DF5D0(void) {
    return 4;
}

extern "C" s32 func_002DF5D8(void) {
    return 4;
}

extern "C" s32 func_002DF5E0(void) {
    return 4;
}

extern "C" s32 func_002DF5E8(void) {
    return 4;
}

extern "C" s32 func_002DF5F0(void) {
    return 4;
}

extern "C" s32 func_002DF5F8(void) {
    return 4;
}

extern "C" s32 func_002DF600(void) {
    return 4;
}

extern "C" s32 func_002DF608(void) {
    return 4;
}

extern "C" s32 func_002DF610(void) {
    return 4;
}

extern "C" s32 func_002DF618(void) {
    return 4;
}

INCLUDE_ASM("asm/nonmatchings/game/t_2DEE90", func_002DF620);

INCLUDE_ASM("asm/nonmatchings/game/t_2DEE90", func_002DF630);

INCLUDE_ASM("asm/nonmatchings/game/t_2DEE90", func_002DF718);

extern "C" s32 func_002DF748(void) {
    return 0;
}

INCLUDE_ASM("asm/nonmatchings/game/t_2DEE90", func_002DF750);

INCLUDE_ASM("asm/nonmatchings/game/t_2DEE90", func_002DF7E8);

INCLUDE_ASM("asm/nonmatchings/game/t_2DEE90", func_002DF830);

INCLUDE_ASM("asm/nonmatchings/game/t_2DEE90", func_002DF880);

extern "C" s32 func_002DF898(S2DF898_0 *arg0) {
    return (*(s32 *)((char *)(arg0->unk8C) + 0x160));
}

INCLUDE_ASM("asm/nonmatchings/game/t_2DEE90", func_002DF8A8);

INCLUDE_ASM("asm/nonmatchings/game/t_2DEE90", func_002DF940);

extern "C" s32 func_002DF978(S2DF978_0 *arg0) {
    return arg0->unk8C;
}

extern "C" void func_002DF980(S2DF978_0 *arg0, s32 arg1) {
    arg0->unk8C = arg1;
}

extern "C" s32 func_002DF988(S2DF988_0 *arg0) {
    return arg0->unk9C;
}

INCLUDE_ASM("asm/nonmatchings/game/t_2DEE90", func_002DF990);

INCLUDE_ASM("asm/nonmatchings/game/t_2DEE90", func_002DF9B8);

INCLUDE_ASM("asm/nonmatchings/game/t_2DEE90", func_002DFA08);

INCLUDE_ASM("asm/nonmatchings/game/t_2DEE90", func_002DFAC0);

INCLUDE_ASM("asm/nonmatchings/game/t_2DEE90", func_002DFB48);

extern "C" s32 func_002DFB68(void) {
    return 0;
}

INCLUDE_ASM("asm/nonmatchings/game/t_2DEE90", func_002DFB70);

INCLUDE_ASM("asm/nonmatchings/game/t_2DEE90", func_002DFBF8);

INCLUDE_ASM("asm/nonmatchings/game/t_2DEE90", func_002DFE78);

INCLUDE_ASM("asm/nonmatchings/game/t_2DEE90", func_002DFEB0);

INCLUDE_ASM("asm/nonmatchings/game/t_2DEE90", func_002DFF28);

INCLUDE_ASM("asm/nonmatchings/game/t_2DEE90", func_002DFF78);

INCLUDE_ASM("asm/nonmatchings/game/t_2DEE90", func_002E00C8);

INCLUDE_ASM("asm/nonmatchings/game/t_2DEE90", func_002E0140);

INCLUDE_ASM("asm/nonmatchings/game/t_2DEE90", func_002E01E8);

INCLUDE_ASM("asm/nonmatchings/game/t_2DEE90", func_002E02D8);

INCLUDE_ASM("asm/nonmatchings/game/t_2DEE90", func_002E0718);

INCLUDE_ASM("asm/nonmatchings/game/t_2DEE90", func_002E0B60);

INCLUDE_ASM("asm/nonmatchings/game/t_2DEE90", func_002E0CD0);

INCLUDE_ASM("asm/nonmatchings/game/t_2DEE90", func_002E0DA8);
