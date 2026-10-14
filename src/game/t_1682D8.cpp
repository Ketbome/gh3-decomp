#include "common.h"

struct S001682D8 {
    char pad[0x2F8];
    float unk2F8;
};

struct S00168888 {
    char pad[0x2D0];
    int unk2D0;
};

struct S00168C98 {
    char pad[0x2F0];
    int unk2F0;
};

struct S00169BD8 {
    char pad[0x2F0];
    float unk2F0;
};

struct S00168C60 {
    char pad0[0x8];
    void* unk8;
    char padC[0x14];
    void* unk20;
};

extern "C" {
void func_00162FC8_2(void*, int) __asm__("func_00162FC8");
extern u8 D_0033F0B0[];
extern u8 D_0033F0C8[];
extern u8 D_0033EF48[];
extern u8 D_0033EF60[];
void Heap_Free(int, void*);
void* Heap_Alloc(int, int, int, int);
int func_0010C050(int);
extern int D_003689E8[] __attribute__((section(".sdata")));
extern int D_00368A38[] __attribute__((section(".sdata")));
extern u8 D_0033E840[];
extern u8 D_0033E858[];
extern u8 D_0033E9A8[];
extern u8 D_0033E9C0[];
void func_00162FC8(void);
extern u8 D_0033EB10[];
extern u8 D_0033EB28[];
extern u8 D_0033EC78[];
extern u8 D_0033EC90[];
extern u8 D_0033EDE0[];
extern u8 D_0033EDF8[];
}

extern "C" void func_001682D8(S001682D8* self, float v) {
    self->unk2F8 = v;
}

extern "C" int func_001682E0(void) {
    return 3;
}

extern "C" int func_001682E8(void) {
    return 1;
}

INCLUDE_ASM("asm/nonmatchings/game/t_1682D8", func_001682F0);

struct S_00168708 { char pad0[8]; void* unk8; char padC[0x14]; void* unk20; char pad24[0x2D8]; void* unk2FC; };

extern "C" void func_00168708(S_00168708* self, int flags) {
    void* p = self->unk2FC;
    self->unk20 = D_0033E840;
    self->unk8 = D_0033E858;
    if (p) {
        Heap_Free(D_00368A38[0], p);
        self->unk2FC = 0;
    }
    func_00162FC8_2(self, flags);
}

struct S_00168778 { char pad0[0xA0]; int unkA0; char padA4[0x258]; float* unk2FC; };

extern "C" void func_00168778(S_00168778* self, float a, float b) {
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

extern "C" void func_00168870(S001682D8* self, float v) {
    self->unk2F8 = v;
}

extern "C" int func_00168878(S00168888* self) {
    return self->unk2D0 + 3;
}

extern "C" int func_00168888(S00168888* self) {
    return self->unk2D0;
}

INCLUDE_ASM("asm/nonmatchings/game/t_1682D8", func_00168890);

extern "C" void func_00168C60(S00168C60* self) {
    self->unk20 = D_0033E9A8;
    self->unk8 = D_0033E9C0;
    func_00162FC8();
}

extern "C" int func_00168C90(void) {
    return 2;
}

extern "C" int func_00168C98(S00168C98* self) {
    return self->unk2F0;
}

INCLUDE_ASM("asm/nonmatchings/game/t_1682D8", func_00168CA0);

extern "C" void func_00168F28(S00168C60* self) {
    self->unk20 = D_0033EB10;
    self->unk8 = D_0033EB28;
    func_00162FC8();
}

extern "C" int func_00168F58(void) {
    return 2;
}

extern "C" int func_00168F60(S00168C98* self) {
    return self->unk2F0;
}

INCLUDE_ASM("asm/nonmatchings/game/t_1682D8", func_00168F68);

extern "C" void func_00169338(S00168C60* self) {
    self->unk20 = D_0033EC78;
    self->unk8 = D_0033EC90;
    func_00162FC8();
}

extern "C" int func_00169368(S00168C98* self) {
    return self->unk2F0;
}

extern "C" int func_00169370(S00168C98* self) {
    return self->unk2F0;
}

INCLUDE_ASM("asm/nonmatchings/game/t_1682D8", func_00169378);

extern "C" void func_00169738(S00168C60* self) {
    self->unk20 = D_0033EDE0;
    self->unk8 = D_0033EDF8;
    func_00162FC8();
}

extern "C" int func_00169768(S00168888* self) {
    return self->unk2D0;
}

extern "C" int func_00169770(S00168888* self) {
    return self->unk2D0;
}

INCLUDE_ASM("asm/nonmatchings/game/t_1682D8", func_00169778);

struct S_00169A70 { char pad0[8]; void* unk8; char padC[0x14]; void* unk20; char pad24[0x2D0]; void* unk2F4; };

extern "C" void func_00169A70(S_00169A70* self, int flags) {
    void* p = self->unk2F4;
    self->unk20 = D_0033EF48;
    self->unk8 = D_0033EF60;
    if (p) {
        Heap_Free(D_00368A38[0], p);
        self->unk2F4 = 0;
    }
    func_00162FC8_2(self, flags);
}

struct S_00169AE0 { char pad0[0xA0]; int unkA0; char padA4[0x250]; float* unk2F4; };

extern "C" void func_00169AE0(S_00169AE0* self, float a, float b) {
    int i;
    if (self->unk2F4 || (self->unk2F4 = (float*)Heap_Alloc(D_00368A38[0], self->unkA0 * 4, D_003689E8[0], 0))) {
        if (self->unkA0 > 0) {
            float d = b - a;
            i = 0;
            do {
                self->unk2F4[i] = (a + d * (float)func_0010C050(10000) * 0.0001f) * 6.2831855f;
                i++;
            } while (i < self->unkA0);
        }
    }
}

extern "C" void func_00169BD8(S00169BD8* self, float v) {
    self->unk2F0 = v;
}

extern "C" int func_00169BE0(void) {
    return 4;
}

extern "C" int func_00169BE8(void) {
    return 1;
}

INCLUDE_ASM("asm/nonmatchings/game/t_1682D8", func_00169BF0);

struct S_00169E70 { char pad0[8]; void* unk8; char padC[0x14]; void* unk20; char pad24[0x2D0]; void* unk2F4; };

extern "C" void func_00169E70(S_00169E70* self, int flags) {
    void* p = self->unk2F4;
    self->unk20 = D_0033F0B0;
    self->unk8 = D_0033F0C8;
    if (p) {
        Heap_Free(D_00368A38[0], p);
        self->unk2F4 = 0;
    }
    func_00162FC8_2(self, flags);
}

extern "C" void func_00169EE0(S_00169AE0* self, float a, float b) {
    int i;
    if (self->unk2F4 || (self->unk2F4 = (float*)Heap_Alloc(D_00368A38[0], self->unkA0 * 4, D_003689E8[0], 0))) {
        if (self->unkA0 > 0) {
            float d = b - a;
            i = 0;
            do {
                self->unk2F4[i] = (a + d * (float)func_0010C050(10000) * 0.0001f) * 6.2831855f;
                i++;
            } while (i < self->unkA0);
        }
    }
}

extern "C" void func_00169FD8(S00169BD8* self, float v) {
    self->unk2F0 = v;
}

extern "C" int func_00169FE0(void) {
    return 2;
}

extern "C" int func_00169FE8(void) {
    return 1;
}

INCLUDE_ASM("asm/nonmatchings/game/t_1682D8", func_00169FF0);
