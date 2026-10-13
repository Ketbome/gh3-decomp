#include "common.h"

extern "C" {
extern int D_0036D3B8;
extern int D_00368738;
s32 func_00249A88(u8);
void func_0024A4E8(int, int);
s32 func_00249B78(s32 a, s32 b, s32 c);
extern int D_0036D3B0;
void func_001D8180(int);
void func_001D48D0(int, int);
extern u8 D_00399A68[];
extern u8 D_00399A88[];
void func_00249FB8(void*);
void func_0011C408(int, void*);
void func_00249F48(int*);
void func_00249F80(int*);
void func_0024A070(void*);
void func_0027C448(int, u32, int);
void func_0024A128(void*, int, int);
void func_0024A308(void*, int, int);
int func_0027D870(int, u32, int*, int);
int func_001D0680(int);
s32 func_002763C0(s32 a, s32 b);
s32 func_0027D400(s32 a, s32 b, s32 c, s32 d);
}

INCLUDE_ASM("asm/nonmatchings/game/t_249620", func_00249620);

extern "C" void func_00249888(char* p) {
    func_00249A88(p[0x6A]);
}

INCLUDE_ASM("asm/nonmatchings/game/t_249620", func_002498A8);

INCLUDE_ASM("asm/nonmatchings/game/t_249620", func_00249A88);

INCLUDE_ASM("asm/nonmatchings/game/t_249620", func_00249B70);

extern "C" s32 func_00249B78(s32 a, s32 b, s32 c) {
    s32 t = func_002763C0(func_00249A88(a & 0xFF), 0);
    if (t != 0 && func_0027D400(t, c, b, 0) != 0) {
        return 1;
    }
    s32 u = func_002763C0(0x5B80CFCB, 0);
    if (u != 0 && func_0027D400(u, c, b, 0) != 0) {
        return 1;
    }
    return 0;
}

INCLUDE_ASM("asm/nonmatchings/game/t_249620", func_00249C10);

extern "C" void func_00249EF0(void) {
    func_00249FB8(D_00399A68);
    func_0024A070(D_00399A88);
}

extern "C" void func_00249F20(int a, int b, int c) {
    func_00249B78(b & 0xFF, a, c);
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

extern "C" void func_00249FB8(void* self) {
    int* p = (int*)self;
    char* t = (char*)p[1];
    if (t) {
        char* q = t;
        u32 n = 1 << p[0];
        u32 i = 0;
        if (n) {
            do {
                char* c = *(char**)(q + 8);
                if (c) {
                    do {
                        char* nx = *(char**)(c + 8);
                        func_0011C408(0, c);
                        c = nx;
                    } while (c);
                }
                func_00249F48((int*)q);
                i++;
                q += 12;
            } while (i < n);
        }
        p[2] = 0;
    }
}

extern "C" void func_0024A070(void* self) {
    int* p = (int*)self;
    char* t = (char*)p[1];
    if (t) {
        char* q = t;
        u32 n = 1 << p[0];
        u32 i = 0;
        if (n) {
            do {
                char* c = *(char**)(q + 8);
                if (c) {
                    do {
                        char* nx = *(char**)(c + 8);
                        func_0011C408(0, c);
                        c = nx;
                    } while (c);
                }
                func_00249F80((int*)q);
                i++;
                q += 12;
            } while (i < n);
        }
        p[2] = 0;
    }
}

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

extern "C" int CFunc_CompositeObjectExists(int s) {
    int v;
    if ((func_0027D870(s, 0xA1DC81F9, &v, 0) ^ 1) != 0) func_0027D870(s, 0, &v, 1);
    return func_001D0680(v) != 0;
}

INCLUDE_ASM("asm/nonmatchings/game/t_249620", CFunc_Orient);

INCLUDE_ASM("asm/nonmatchings/game/t_249620", CFunc_GetDistance);

INCLUDE_ASM("asm/nonmatchings/game/t_249620", CFunc_AddArrayElement);

INCLUDE_ASM("asm/nonmatchings/game/t_249620", CFunc_RemoveArrayElement);
