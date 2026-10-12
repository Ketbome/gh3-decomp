#include "common.h"

struct S1E0AE8_L {
    S1E0AE8_L* unk0;
    S1E0AE8_L* unk4;
    void Init() {
        unk0 = this;
        unk4 = this;
    }
};

struct S1E0AE8_N {
    S1E0AE8_N* unk0;
    S1E0AE8_N* unk4;
    void* unk8;
};

struct S1E0AE8_I {
    s32 unk0;
    S1E0AE8_N* unk4;
};

struct S1E0AE8_H {
    char pad0[0xC];
    struct S1E0AE8_C* unkC;
};

struct S1E0AE8_C {
    char pad0[0x2C];
    s32 unk2C;
};

struct S1E0AE8 {
    char pad0[0x8];
    void* unk8;
    char padC[0x64];
    S1E0AE8_L unk70;
    s32 unk78;
    s32 unk7C;
    s32 unk80;
    S1E0AE8_L unk84;
    s32 unk8C;
    char pad90[0x8];
    S1E0AE8_H* unk98;
    char pad9C[0xC];
    s32 unkA8;
    S1E0AE8_C* Get() {
        if (unk98 != 0) {
            return unk98->unkC;
        }
        return 0;
    }
};

extern "C" {
s32 func_001E0FF8(void* p, s32 v);
void func_002763E0(u32 key, s32 v);
void* func_00113D20(u32 size);
void* func_001E0768(void* p, void* q);
void func_001E0F18(struct S1E0AE8* p);
}

INCLUDE_ASM("asm/nonmatchings/game/t_1E0AE8", func_001E0AE8);

INCLUDE_ASM("asm/nonmatchings/game/t_1E0AE8", func_001E0B60);

INCLUDE_ASM("asm/nonmatchings/game/t_1E0AE8", func_001E0BB0);

extern "C" s32 func_001E0BC0(S1E0AE8* p) {
    return p->unkA8;
}

INCLUDE_ASM("asm/nonmatchings/game/t_1E0AE8", func_001E0BC8);

INCLUDE_ASM("asm/nonmatchings/game/t_1E0AE8", func_001E0C40);

INCLUDE_ASM("asm/nonmatchings/game/t_1E0AE8", func_001E0CB8);

INCLUDE_ASM("asm/nonmatchings/game/t_1E0AE8", func_001E0E10);

INCLUDE_ASM("asm/nonmatchings/game/t_1E0AE8", func_001E0E70);

extern "C" void func_001E0EE0(S1E0AE8* p, s32 v) {
    p->unk80 = v;
    func_001E0F18(p);
}

extern "C" s32 func_001E0F00(S1E0AE8* p) {
    return p->unk78;
}

extern "C" void func_001E0F08(S1E0AE8* p) {
    p->unk8C = 1;
}

extern "C" void func_001E0F18(S1E0AE8* p) {
    if (p->unk8C != 3) {
        p->unk8C = 2;
    }
}

extern "C" void func_001E0F38(S1E0AE8* p) {
    p->unk8C = 3;
}

extern "C" s32 func_001E0F48(void) {
    return 0;
}

INCLUDE_ASM("asm/nonmatchings/game/t_1E0AE8", func_001E0F50);

extern "C" void func_001E0F78(S1E0AE8* p) {
    func_001E0F38(p);
}

extern "C" void func_001E0F98(void) {
}

extern "C" void func_001E0FA0(void) {
}

extern "C" void* func_001E0FA8(void* p, s32 a, u32 key) {
    void* r = 0;
    if (key == 0x03986CD2) {
        r = func_001E0768(func_00113D20(0xAC), p);
    }
    return r;
}

INCLUDE_ASM("asm/nonmatchings/game/t_1E0AE8", func_001E0FF8);

INCLUDE_ASM("asm/nonmatchings/game/t_1E0AE8", func_001E1068);

INCLUDE_ASM("asm/nonmatchings/game/t_1E0AE8", func_001E10C0);

INCLUDE_ASM("asm/nonmatchings/game/t_1E0AE8", func_001E1220);

extern "C" s32 func_001E12A8(S1E0AE8* p) {
    S1E0AE8_I it;
    S1E0AE8_N* n = (S1E0AE8_N*)p->unk70.unk4;
    if (n == (S1E0AE8_N*)&p->unk70) {
        return 0;
    }
    it.unk4 = n;
    func_001E0EE0((S1E0AE8*)it.unk4->unk8, 1);
    return 1;
}

extern "C" s32 func_001E12E8(void* p, s32* q) {
    return func_001E0FF8(p, *q) == 0;
}

INCLUDE_ASM("asm/nonmatchings/game/t_1E0AE8", func_001E1308);

INCLUDE_ASM("asm/nonmatchings/game/t_1E0AE8", func_001E1378);

INCLUDE_ASM("asm/nonmatchings/game/t_1E0AE8", func_001E1650);

INCLUDE_ASM("asm/nonmatchings/game/t_1E0AE8", func_001E1698);

INCLUDE_ASM("asm/nonmatchings/game/t_1E0AE8", func_001E18A8);

INCLUDE_ASM("asm/nonmatchings/game/t_1E0AE8", func_001E1978);

INCLUDE_ASM("asm/nonmatchings/game/t_1E0AE8", func_001E19F0);

extern "C" s32 func_001E1A28(S1E0AE8* p) {
    return p->unk70.unk4 != &p->unk70;
}

INCLUDE_ASM("asm/nonmatchings/game/t_1E0AE8", func_001E1A40);

INCLUDE_ASM("asm/nonmatchings/game/t_1E0AE8", func_001E1AD0);

INCLUDE_ASM("asm/nonmatchings/game/t_1E0AE8", func_001E1B28);

INCLUDE_ASM("asm/nonmatchings/game/t_1E0AE8", func_001E1C90);

INCLUDE_ASM("asm/nonmatchings/game/t_1E0AE8", func_001E1CA0);

INCLUDE_ASM("asm/nonmatchings/game/t_1E0AE8", func_001E1E58);

extern "C" void func_001E1F88(void) {
    func_002763E0(0x8EAD9B0C, 1);
}

INCLUDE_ASM("asm/nonmatchings/game/t_1E0AE8", func_001E1FB0);

INCLUDE_ASM("asm/nonmatchings/game/t_1E0AE8", func_001E2260);

INCLUDE_ASM("asm/nonmatchings/game/t_1E0AE8", func_001E24B0);

INCLUDE_ASM("asm/nonmatchings/game/t_1E0AE8", func_001E2558);

INCLUDE_ASM("asm/nonmatchings/game/t_1E0AE8", func_001E2628);

INCLUDE_ASM("asm/nonmatchings/game/t_1E0AE8", func_001E2770);

INCLUDE_ASM("asm/nonmatchings/game/t_1E0AE8", func_001E2848);

INCLUDE_ASM("asm/nonmatchings/game/t_1E0AE8", func_001E2850);

INCLUDE_ASM("asm/nonmatchings/game/t_1E0AE8", func_001E2968);

INCLUDE_ASM("asm/nonmatchings/game/t_1E0AE8", func_001E29F0);
