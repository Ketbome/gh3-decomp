#include "common.h"

struct S00167DF0 {
    char pad[0x2F0];
    int unk2F0;
};

struct S00167958 {
    char pad0[0x8];
    void* unk8;
    char padC[0x14];
    void* unk20;
};

extern "C" {
void func_00162FC8_2(void*, int) __asm__("func_00162FC8");
extern u8 D_0033E6D8[];
extern u8 D_0033E2A0[];
extern u8 D_0033E2B8[];
extern u8 D_0033E6F0[];
void Heap_Free(int, void*);
extern int D_00368A38[] __attribute__((section(".sdata")));
extern u8 D_0033E570[];
extern u8 D_0033E588[];
extern u8 D_0033E408[];
extern u8 D_0033E420[];
void func_00162FC8(void);
void func_0014EB28(void*);
}

INCLUDE_ASM("asm/nonmatchings/game/t_1662C8", func_001662C8);

INCLUDE_ASM("asm/nonmatchings/game/t_1662C8", func_00166A30);

INCLUDE_ASM("asm/nonmatchings/game/t_1662C8", func_00166A38);

struct S_00166F40 {
    char pad0[0x8];
    void* unk8;
    char padC[0x14];
    void* unk20;
    char pad24[0x2CC];
    int unk2F0;
    char pad2F4[4];
    void* unk2F8;
    char pad2FC[4];
    void** unk300;
};

extern "C" void func_00166F40(S_00166F40* self, int flags) {
    self->unk20 = D_0033E2A0;
    self->unk8 = D_0033E2B8;
    if (self->unk2F8) {
        Heap_Free(D_00368A38[0], self->unk2F8);
        self->unk2F8 = 0;
    }
    if (self->unk300) {
        u32 i = 0;
        u32 n;
        if (self->unk2F0) {
            do {
                func_0014EB28(self->unk300[i]);
                i++;
                n = self->unk2F0;
            } while (i < n);
        }
        if (self->unk300) {
            Heap_Free(D_00368A38[0], self->unk300);
        }
        self->unk300 = 0;
    }
    func_00162FC8_2(self, flags);
}

extern "C" int func_00167010(void) {
    return 1;
}

extern "C" int func_00167018(void) {
    return 1;
}

INCLUDE_ASM("asm/nonmatchings/game/t_1662C8", func_00167020);

INCLUDE_ASM("asm/nonmatchings/game/t_1662C8", func_00167738);

INCLUDE_ASM("asm/nonmatchings/game/t_1662C8", func_00167740);

extern "C" int func_00167948(void) {
    return 1;
}

extern "C" int func_00167950(void) {
    return 1;
}

extern "C" void func_00167958(S00167958* self) {
    self->unk20 = D_0033E408;
    self->unk8 = D_0033E420;
    func_00162FC8();
}

INCLUDE_ASM("asm/nonmatchings/game/t_1662C8", func_00167988);

struct S167D70 { char pad0[8]; void* unk8; char padC[0x14]; void* unk20; char pad24[0x1B8]; void* unk1DC; };

extern "C" void func_00167D70(S167D70* self, int flags) {
    void* p = self->unk1DC;
    self->unk20 = D_0033E570;
    self->unk8 = D_0033E588;
    if (p) {
        Heap_Free(D_00368A38[0], p);
        self->unk1DC = 0;
    }
    func_00162FC8_2(self, flags);
}

extern "C" int func_00167DE0(S00167DF0* self) {
    return self->unk2F0 + 3;
}

extern "C" int func_00167DF0(S00167DF0* self) {
    return self->unk2F0;
}

INCLUDE_ASM("asm/nonmatchings/game/t_1662C8", func_00167DF8);

struct S_00168170 { char pad0[8]; void* unk8; char padC[0x14]; void* unk20; char pad24[0x2D8]; void* unk2FC; };

extern "C" void func_00168170(S_00168170* self, int flags) {
    void* p = self->unk2FC;
    self->unk20 = D_0033E6D8;
    self->unk8 = D_0033E6F0;
    if (p) {
        Heap_Free(D_00368A38[0], p);
        self->unk2FC = 0;
    }
    func_00162FC8_2(self, flags);
}

INCLUDE_ASM("asm/nonmatchings/game/t_1662C8", func_001681E0);
