#include "common.h"

struct S2A6648_1 {
    char pad0[0x20];
    s32 unk20;
};

extern "C" {
extern s32 D_00368E48[] __attribute__((section(".sdata")));
extern s32 D_00370AE0;
extern s32 D_00371D7C;
int func_00115028(void);
s32 func_001218A0(s32, int, int);
int func_001E5050(void);
int func_002691B0(s32);
int func_0026D480(int);
int func_002764E8(int, int);
int func_0027C448(s32, int, int);
int func_00288410(int, int, int, int, int);
int func_002884A8(void);
void func_002A6C10(void);
int func_002A6C40_r(void) asm("func_002A6C40");
void func_002A6C10_a(int) asm("func_002A6C10");
}

INCLUDE_ASM("asm/nonmatchings/game/t_2A53A8", func_002A53A8);

INCLUDE_ASM("asm/nonmatchings/game/t_2A53A8", func_002A53E0);

INCLUDE_ASM("asm/nonmatchings/game/t_2A53A8", func_002A5478);

INCLUDE_ASM("asm/nonmatchings/game/t_2A53A8", func_002A54C8);

INCLUDE_ASM("asm/nonmatchings/game/t_2A53A8", func_002A5510);

INCLUDE_ASM("asm/nonmatchings/game/t_2A53A8", func_002A5638);

INCLUDE_ASM("asm/nonmatchings/game/t_2A53A8", func_002A5748);

INCLUDE_ASM("asm/nonmatchings/game/t_2A53A8", CFunc_GetMemCardSpaceAvailable);

INCLUDE_ASM("asm/nonmatchings/game/t_2A53A8", CFunc_GetMemCardSpaceRequired);

INCLUDE_ASM("asm/nonmatchings/game/t_2A53A8", CFunc_MemCardGetUniqueFileName);

INCLUDE_ASM("asm/nonmatchings/game/t_2A53A8", CFunc_MemCardFileExists);

INCLUDE_ASM("asm/nonmatchings/game/t_2A53A8", CFunc_DeleteMemCardFile);

INCLUDE_ASM("asm/nonmatchings/game/t_2A53A8", CFunc_FormatCard);

extern "C" s32 CFunc_CardIsInSlot(void) {
    return func_001218A0(D_00368E48[0], 0, 0) != 0;
}

INCLUDE_ASM("asm/nonmatchings/game/t_2A53A8", CFunc_CardIsNew);

INCLUDE_ASM("asm/nonmatchings/game/t_2A53A8", CFunc_CardIsFormatted);

extern "C" s32 CFunc_SaveFailedDueToInsufficientSpace(void) {
    return D_00371D7C;
}

INCLUDE_ASM("asm/nonmatchings/game/t_2A53A8", CFunc_GetSummaryInfo);

extern "C" void func_002A5DB0(void) {
    func_0026D480(0);
    func_002691B0(D_00370AE0);
}

INCLUDE_ASM("asm/nonmatchings/game/t_2A53A8", CFunc_SaveToMemoryCard);

INCLUDE_ASM("asm/nonmatchings/game/t_2A53A8", CFunc_LoadFromMemoryCard);

INCLUDE_ASM("asm/nonmatchings/game/t_2A53A8", func_002A5EF8);

extern "C" void CFunc_GetMemCardDirectoryListing(void) {
    func_001E5050();
}

extern "C" s32 CFunc_ShowStorageSelector(void) {
    return 0;
}

extern "C" s32 CFunc_StorageSelectorFinished(void) {
    return 1;
}

INCLUDE_ASM("asm/nonmatchings/game/t_2A53A8", CFunc_MemCardSystemInitialize);

INCLUDE_ASM("asm/nonmatchings/game/t_2A53A8", CFunc_SetSaveFileName);

extern "C" s32 CFunc_EnumContentFiles(void) {
    return 0;
}

extern "C" s32 CFunc_EnumContentFilesFinished(void) {
    return 0;
}

extern "C" s32 CFunc_NewShowStorageSelector(void) {
    return 0;
}

extern "C" s32 CFunc_GetContentFolderIndexFromFile(int arg0, S2A6648_1 *arg1) {
    func_0027C448(arg1->unk20, 0xF6D04971 /* DEVICE */, 0x1CA1FF20 /* DEFAULT */);
    return 0;
}

INCLUDE_ASM("asm/nonmatchings/game/t_2A53A8", func_002A6678);

INCLUDE_ASM("asm/nonmatchings/game/t_2A53A8", func_002A6700);

INCLUDE_ASM("asm/nonmatchings/game/t_2A53A8", func_002A6730);

INCLUDE_ASM("asm/nonmatchings/game/t_2A53A8", func_002A67B8);

INCLUDE_ASM("asm/nonmatchings/game/t_2A53A8", func_002A67E8);

INCLUDE_ASM("asm/nonmatchings/game/t_2A53A8", func_002A6B70);

extern "C" int func_002A6BD0(int arg0, int arg1, int arg2, int arg3) {
    return func_00288410(arg0, arg1, arg2, arg3, 0);
}

extern "C" void func_002A6BF0(void) {
    func_002A6C10();
}

extern "C" void func_002A6C10(void) {
    func_002884A8();
    func_002764E8(0xC472ECC5 /* nodearray */, 0);
}

extern "C" void func_002A6C40(void) {
    func_00115028();
}

extern "C" void func_002A6C60(void) {
    func_002A6C10_a(func_002A6C40_r());
}

INCLUDE_ASM("asm/nonmatchings/game/t_2A53A8", func_002A6C88);

INCLUDE_ASM("asm/nonmatchings/game/t_2A53A8", func_002A6E50);

INCLUDE_ASM("asm/nonmatchings/game/t_2A53A8", func_002A6EA8);

INCLUDE_ASM("asm/nonmatchings/game/t_2A53A8", func_002A6EB8);

INCLUDE_ASM("asm/nonmatchings/game/t_2A53A8", func_002A6F60);

INCLUDE_ASM("asm/nonmatchings/game/t_2A53A8", func_002A7008);

INCLUDE_ASM("asm/nonmatchings/game/t_2A53A8", func_002A70B0);

INCLUDE_ASM("asm/nonmatchings/game/t_2A53A8", func_002A7158);

INCLUDE_ASM("asm/nonmatchings/game/t_2A53A8", func_002A7200);

INCLUDE_ASM("asm/nonmatchings/game/t_2A53A8", func_002A72A8);

INCLUDE_ASM("asm/nonmatchings/game/t_2A53A8", func_002A7350);
