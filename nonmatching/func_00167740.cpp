// cflags: -funroll-loops
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
int func_0014EB28(void*);
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

extern "C" int D_003689E8[] __attribute__((section(".sdata")));
extern "C" void* Heap_Alloc(int, int, int, int);
extern "C" void func_00162F48(void*);

struct S_167740 {
    char pad0[8]; void* unk8; char padC[0x14]; void* unk20; char pad24[0x7C]; int unkA0; char padA4[0x1C];
    int unkC0; char padC4[0x10]; float unk1EC_dummy;
};
struct B_167740 { char b[4]; };
struct S2_167740 {
    char pad0[8]; void* unk8; char padC[0x14]; void* unk20; char pad24[0x7C]; int unkA0; char padA4[0x1C];
    int unkC0; char padC4[0x10C]; int unk1D4; char pad1D8[4]; void* unk1DC; char pad1E0[0xC]; float unk1EC;
    B_167740* unk1F0; B_167740* unk1F4; B_167740* unk1F8; char pad1FC[0xD8]; void* unk2D4; u32 unk2D8;
};

extern "C" S2_167740* func_00167740(S2_167740* self, int a1, int a2) {
    func_00162F48(self);
    self->unk1D4 = a1;
    self->unkA0 = a2;
    self->unkC0 = 0;
    self->unk20 = D_0033E408;
    self->unk8 = D_0033E420;
    char* p = (char*)Heap_Alloc(D_00368A38[0], a2 * 0x30, D_003689E8[0], 0);
    if (p) {
        int k = a2 - 1;
        if (a2 != 0) {
            do {
                k--;
            } while (k != -1);
        }
    }
    self->unk1DC = p;
    if (p) {
        int h = D_003689E8[0];
        self->unk2D4 = Heap_Alloc(D_00368A38[0], a2 * 0xC, h, 0);
        if (self->unk2D4) {
            self->unk1F0 = (B_167740*)Heap_Alloc(D_00368A38[0], 4, h, 0);
            if (self->unk1F0) {
                self->unk1F4 = (B_167740*)Heap_Alloc(D_00368A38[0], 4, h, 0);
                if (self->unk1F4) {
                    self->unk1F8 = (B_167740*)Heap_Alloc(D_00368A38[0], 4, h, 0);
                    if (self->unk1F8) {
                        self->unk1F0->b[0] = 0x80;
                        self->unk1F0->b[1] = 0x80;
                        self->unk1F0->b[2] = 0x80;
                        self->unk1F0->b[3] = 0x80;
                        self->unk1F4->b[0] = 0x80;
                        self->unk1F4->b[1] = 0x80;
                        self->unk1F4->b[2] = 0x80;
                        self->unk1F4->b[3] = 0x80;
                        self->unk1F8->b[0] = 0x80;
                        self->unk1F8->b[1] = 0x80;
                        self->unk1F8->b[2] = 0x80;
                        self->unk1F8->b[3] = 0x80;
                        self->unk1EC = -1.0f;
                        self->unk2D8 |= 4;
                    }
                }
            }
        }
    }
    return self;
}

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

struct S_0016A718 { char pad0[0xA0]; int unkA0; char padA4[0x258]; float* unk2FC; };

extern "C" int func_0010C050(int);
extern "C" void func_001681E0(S_0016A718* self, float a, float b) {
    int i;
    if (self->unk2FC || (self->unk2FC = (float*)Heap_Alloc(D_00368A38[0], self->unkA0 * 4, D_003689E8[0], 0))) {
        if (self->unkA0 > 0) {
            float d = b - a;
            i = 0;
            do {
                self->unk2FC[i] = (a + d * (float)func_0010C050(10000) * 0.0001f) * 6.2831855f;
                i++;
            } while (i < self->unkA0);
        }
    }
}
