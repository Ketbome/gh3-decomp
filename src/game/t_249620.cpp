#include "common.h"

extern "C" {
extern int D_0036D3B8;
extern int D_00368738;
void func_00249A88(u8);
void func_0024A4E8(int, int);
void func_00249B78(int, int);
extern int D_0036D3B0;
void func_001D8180(int);
void func_001D48D0(int, int);
extern u8 D_00399A68[];
extern u8 D_00399A88[];
void func_00249FB8(void*);
void func_0024A070(void*);
void func_0027C448(int, u32, int);
void func_0024A128(void*, int, int);
void func_0024A308(void*, int, int);
}

INCLUDE_ASM("asm/nonmatchings/game/t_249620", func_00249620);

extern "C" void func_00249888(char* p) {
    func_00249A88(p[0x6A]);
}

INCLUDE_ASM("asm/nonmatchings/game/t_249620", func_002498A8);

INCLUDE_ASM("asm/nonmatchings/game/t_249620", func_00249A88);

INCLUDE_ASM("asm/nonmatchings/game/t_249620", func_00249B70);

INCLUDE_ASM("asm/nonmatchings/game/t_249620", func_00249B78);

INCLUDE_ASM("asm/nonmatchings/game/t_249620", func_00249C10);

extern "C" void func_00249EF0(void) {
    func_00249FB8(D_00399A68);
    func_0024A070(D_00399A88);
}

extern "C" void func_00249F20(int a, int b) {
    func_00249B78(b & 0xFF, a);
}

extern "C" void func_00249F48(int* p) {
    p[0] = 0;
    p[1] = 0;
    p[2] = 0;
}

extern "C" int* func_00249F58(int* p) {
    func_00249F48(p);
    return p;
}

extern "C" void func_00249F80(int* p) {
    p[0] = 0;
    p[1] = 0;
    p[2] = 0;
}

extern "C" int* func_00249F90(int* p) {
    func_00249F80(p);
    return p;
}

INCLUDE_ASM("asm/nonmatchings/game/t_249620", func_00249FB8);

INCLUDE_ASM("asm/nonmatchings/game/t_249620", func_0024A070);

INCLUDE_ASM("asm/nonmatchings/game/t_249620", func_0024A128);

INCLUDE_ASM("asm/nonmatchings/game/t_249620", func_0024A308);

extern "C" void func_0024A4E8(int a, int b) {
    if (b == 0xFFFF) {
        if (a) {
            func_0024A128(D_00399A68, 8, 0);
            func_0024A308(D_00399A88, 8, 0);
        }
    }
}

extern "C" void func_0024A530(void) {
    func_0024A4E8(1, 0xFFFF);
}

INCLUDE_ASM("asm/nonmatchings/game/t_249620", func_0024A550);

extern "C" int CFunc_GetLanguage(int a, char* b) {
    func_0027C448(*(int*)(b + 0x20), 0x2B248E4A, D_00368738);
    return 1;
}

extern "C" int CFunc_German(void) {
    return D_00368738 == 0x41D88638;
}

extern "C" int CFunc_French(void) {
    return D_00368738 == 0x4C9908C7;
}

extern "C" int CFunc_Spanish(void) {
    return D_00368738 == 0x6F2ADD9F;
}

extern "C" int CFunc_Italian(void) {
    return D_00368738 == 0xC8B4164;
}

extern "C" int CFunc_English(void) {
    return D_00368738 == 0x77B12AAB;
}

extern "C" int CFunc_IsCompositeObjectManagerEnabled(void) {
    return D_0036D3B8;
}

INCLUDE_ASM("asm/nonmatchings/game/t_249620", CFunc_CreateCompositeObject);

INCLUDE_ASM("asm/nonmatchings/game/t_249620", CFunc_GetUniqueCompositeObjectID);

INCLUDE_ASM("asm/nonmatchings/game/t_249620", CFunc_CreateCompositeObjectInstance);

extern "C" int CFunc_PauseObjects(void) {
    func_001D48D0(D_0036D3B0, 1);
    return 1;
}

extern "C" int CFunc_UnPauseObjects(void) {
    func_001D48D0(D_0036D3B0, 0);
    return 1;
}

extern "C" int CFunc_FlushDeadObjects(void) {
    func_001D8180(D_0036D3B0);
    return 1;
}

INCLUDE_ASM("asm/nonmatchings/game/t_249620", CFunc_CompositeObjectExists);

INCLUDE_ASM("asm/nonmatchings/game/t_249620", CFunc_Orient);

INCLUDE_ASM("asm/nonmatchings/game/t_249620", CFunc_GetDistance);

INCLUDE_ASM("asm/nonmatchings/game/t_249620", CFunc_AddArrayElement);

INCLUDE_ASM("asm/nonmatchings/game/t_249620", CFunc_RemoveArrayElement);
