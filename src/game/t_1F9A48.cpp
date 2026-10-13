#include "common.h"

typedef int TI128 __attribute__((mode(TI)));

struct S1FADE8 {
    char pad0[0x18];
    virtual void v1();
    virtual void v2();
};

extern "C" {
void func_001FA348(int, int);
void func_001FB028(void*);
void func_001FB6C0(void*);
void func_001FAF90(void*);
void* func_00113D20(u32);
void* func_001FAC90(void*);
extern char D_0038F5B0[];
void func_00276D68(u32, void*, int);
void func_001FB480(void*, TI128);
TI128 func_001EAEA0(s32 a, s32 b);
s32 func_0027D870(s32 a, s32 key, s32* v, s32 req);
s32 func_001EB300(s32 a);
void func_002676F0(s32 a, void* b);
void func_001D0F90(void* a, s32 b);
extern u8 D_0034F6F0[];
extern s32 D_00370AE0;
}

INCLUDE_ASM("asm/nonmatchings/game/t_1F9A48", func_001F9A48);

INCLUDE_ASM("asm/nonmatchings/game/t_1F9A48", func_001F9A50);

INCLUDE_ASM("asm/nonmatchings/game/t_1F9A48", func_001F9AA8);

INCLUDE_ASM("asm/nonmatchings/game/t_1F9A48", func_001F9B80);

INCLUDE_ASM("asm/nonmatchings/game/t_1F9A48", func_001F9C58);

INCLUDE_ASM("asm/nonmatchings/game/t_1F9A48", func_001F9D18);

INCLUDE_ASM("asm/nonmatchings/game/t_1F9A48", func_001F9D68);

INCLUDE_ASM("asm/nonmatchings/game/t_1F9A48", func_001F9D70);

INCLUDE_ASM("asm/nonmatchings/game/t_1F9A48", func_001F9E80);

extern "C" s32 func_001F9EC0(char* p) {
    return *(s32*)(p + 0x2C);
}

INCLUDE_ASM("asm/nonmatchings/game/t_1F9A48", func_001F9EC8);

INCLUDE_ASM("asm/nonmatchings/game/t_1F9A48", func_001F9F40);

INCLUDE_ASM("asm/nonmatchings/game/t_1F9A48", func_001FA218);

INCLUDE_ASM("asm/nonmatchings/game/t_1F9A48", func_001FA330);

INCLUDE_ASM("asm/nonmatchings/game/t_1F9A48", func_001FA348);

extern "C" void func_001FAC18() {
    func_001FA348(1, 0xFFFF);
}

extern "C" void* func_001FAC38() {
    return func_001FAC90(func_00113D20(0xE0));
}

extern "C" void func_001FAC60() {
    func_00276D68(0x07713C7B, D_0038F5B0, 0x10);
}

INCLUDE_ASM("asm/nonmatchings/game/t_1F9A48", func_001FAC90);

INCLUDE_ASM("asm/nonmatchings/game/t_1F9A48", func_001FAD10);

INCLUDE_ASM("asm/nonmatchings/game/t_1F9A48", func_001FAD68);

extern "C" void func_001FADB8(char* p) {
    TI128 a = *(TI128*)(p + 0xB0);
    *(TI128*)(p + 0xC0) = a;
    *(TI128*)(p + 0xB0) = *(TI128*)(*(char**)(p + 0xC) + 0x80);
    func_001FB480(p, a);
}

extern "C" void func_001FADE8(S1FADE8* p) {
    p->v2();
}

extern "C" s32 func_001FAE10(void* p) {
    func_001FB028(p);
    return 1;
}

extern "C" s32 func_001FAE30(void* p) {
    func_001FB6C0(p);
    return 1;
}

INCLUDE_ASM("asm/nonmatchings/game/t_1F9A48", func_001FAE50);

extern "C" s32 func_001FAEC0(void* p) {
    func_001FAF90(p);
    return 1;
}

extern "C" s32 func_001FAEE0() {
    return 2;
}

INCLUDE_ASM("asm/nonmatchings/game/t_1F9A48", func_001FAEE8);

extern "C" void func_001FAF88(void) {
}

INCLUDE_ASM("asm/nonmatchings/game/t_1F9A48", func_001FAF90);

INCLUDE_ASM("asm/nonmatchings/game/t_1F9A48", func_001FB028);

INCLUDE_ASM("asm/nonmatchings/game/t_1F9A48", func_001FB390);

INCLUDE_ASM("asm/nonmatchings/game/t_1F9A48", func_001FB3D0);

INCLUDE_ASM("asm/nonmatchings/game/t_1F9A48", func_001FB450);

INCLUDE_ASM("asm/nonmatchings/game/t_1F9A48", func_001FB480);

INCLUDE_ASM("asm/nonmatchings/game/t_1F9A48", func_001FB618);

INCLUDE_ASM("asm/nonmatchings/game/t_1F9A48", func_001FB6C0);

INCLUDE_ASM("asm/nonmatchings/game/t_1F9A48", func_001FB820);

INCLUDE_ASM("asm/nonmatchings/game/t_1F9A48", func_001FB938);

INCLUDE_ASM("asm/nonmatchings/game/t_1F9A48", func_001FB998);
