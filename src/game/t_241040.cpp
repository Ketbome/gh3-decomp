#include "common.h"

extern "C" {
f32 func_0010F698(s32 a);
f32 func_0010F6A8(s32 a);
f32 func_0010F6C0(s32 a);
void func_0023F270(void*);
void func_002411D0(void*);
void func_0023F2A0(void*);
void func_0023F2E0(void*);
s32 Heap_Alloc(s32 a, s32 b, s32 c, s32 d);
s32 func_002433A8(s32 a, void* b);
void func_00241640(char* p, char* q);
extern s32 D_00368A38[] __attribute__((section(".sdata")));
}

typedef int TI128 __attribute__((mode(TI)));

INCLUDE_ASM("asm/nonmatchings/game/t_241040", func_00241040);

INCLUDE_ASM("asm/nonmatchings/game/t_241040", func_00241078);

extern "C" void func_002410B0(void* p) {
    func_0023F270(p);
    func_002411D0(p);
}

extern "C" void func_002410E0(void* p) {
    func_0023F2A0(p);
    func_002411D0(p);
}

extern "C" void func_00241110(void* p) {
    func_0023F2E0(p);
    func_002411D0(p);
}

extern "C" void func_00241140(void) {
}

INCLUDE_ASM("asm/nonmatchings/game/t_241040", func_00241148);

INCLUDE_ASM("asm/nonmatchings/game/t_241040", func_002411D0);

extern "C" s32 func_002414B8(s32 a, s32 b) {
    s32 p18 = a + 0xB0;
    s32 p19 = a + 0xA0;
    f32 t = func_0010F698(b);
    if (func_0010F698(p18) < t) {
        return 0;
    }
    s32 p17 = b + 0x10;
    t = func_0010F698(p19);
    if (func_0010F698(p17) < t) {
        return 0;
    }
    t = func_0010F6C0(b);
    if (func_0010F6C0(p18) < t) {
        return 0;
    }
    t = func_0010F6C0(p19);
    if (func_0010F6C0(p17) < t) {
        return 0;
    }
    t = func_0010F6A8(b);
    if (func_0010F6A8(p18) < t) {
        return 0;
    }
    t = func_0010F6A8(p19);
    if (func_0010F6A8(p17) < t) {
        return 0;
    }
    return 1;
}

extern "C" s32 func_002415E0(char* p) {
    s32 t = func_002433A8(Heap_Alloc(D_00368A38[0], 0xD0, 1, 0), p);
    func_00241640((char*)t, *(char**)(p + 8));
    return t;
}

extern "C" void func_00241640(char* p, char* q) {
    *(int*)(p + 8) = (int)q;
    *(u16*)(p + 4) |= 0xC000;
    *(TI128*)(p + 0xA0) = *(TI128*)(q + 0x10);
    *(TI128*)(p + 0xB0) = *(TI128*)(q + 0x20);
    *(int*)(p + 0xC0) = 0;
}

INCLUDE_ASM("asm/nonmatchings/game/t_241040", func_00241668);

INCLUDE_ASM("asm/nonmatchings/game/t_241040", func_00241D88);

INCLUDE_ASM("asm/nonmatchings/game/t_241040", func_002428C0);

INCLUDE_ASM("asm/nonmatchings/game/t_241040", func_00242D80);
