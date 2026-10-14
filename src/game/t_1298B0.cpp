// cflags: -ffast-math -funroll-loops
#include "common.h"

struct SA129_A {
    char pad0[0x8];
    void* unk8[50];
    char padD0[0xD8];
    int unk1A8;
    int unk1AC;
};


struct SA129_Pool {
    u32 unk0;
    u32 unk4;
    int Has(u32 p) { return !(p < unk0) && p < unk4; }
};

struct SA129_L {
    char pad0[0x4];
    void* unk4;
    int unk8;
    SA129_L* unkC;
    SA129_L* unk10;
    void* unk14;
    float unk18;
    float unk1C;
    float unk20;
    float unk24;
    int unk28;
    int unk2C;
    int unk30;
    int unk34;
};

struct SA129_M {
    char pad0[0x14];
    int unk14;
    char pad18[0x14];
    int unk2C;
};

struct SA129_K {
    char pad0[0x4];
    u32 unk4;
    int unk8;
    SA129_K* unkC;
    SA129_K* unk10;
    void* unk14;
    int unk18;
    float unk1C;
    float unk20;
    float unk24;
    int unk28;
    int unk2C;
    int unk30;
    int unk34;
    int unk38;
    int unk3C;
    int unk40;
    int unk44;
    int unk48;
    int unk4C;
    int unk50;
    int unk54;
    SA129_M* unk58;
    int unk5C;
    char pad60[0x4];
    void* unk64;
};


extern "C" {
int func_0027D870(void*, u32, int*, int);
int func_0027D268(void*, u32, float*, int);
int func_0027DF00(void*, u32);
void func_0012BDD0(SA129_K*, int, float);
void func_0012C0B0(SA129_K*, int, int);
void func_0012C1F8(SA129_K*, int);
void func_0012C200(SA129_K*, int);
void* operator_new(u32);
void* func_00128B08(void*);
extern u8 D_00339AA8[];
extern u8 D_00339AE8[];
void func_0012A778(SA129_K*);
float func_0012A1B0(void*);
void func_0012A448(SA129_L*);
void func_0012A510(SA129_L*);
extern u8 D_00339920[];
extern u8 D_00339958[];
extern int D_00368A38;
void Heap_Free(int, void*);
void func_0012C8A8(void*);
void func_00289FD8(int);
void func_0012BE38(void*, u32, int, int, int, float, float, float, float);
int* func_001CA020(int, int);
extern int D_00372580;
void func_0012C780(void*, int, int, int, int);
void func_0012A4D0(SA129_L*, float);
extern int D_003690E8;
extern SA129_Pool* D_003690D8[2];
void func_0011C2E8(SA129_Pool*, void*);
void* func_0011C2A8(SA129_Pool*);
int func_00119610(int, int);
void func_00119490(int, int);
void* Heap_Alloc(int, u32, int, int);
void func_001194B8(int);
}

struct S_00129968 { char pad0[0x198]; int unk198; };
struct S_00129970 { char pad0[0x19C]; int unk19C; };

INCLUDE_ASM("asm/nonmatchings/game/t_1298B0", func_001298B0);

extern "C" int func_00129968(S_00129968* self) {
    return self->unk198;
}

extern "C" int func_00129970(S_00129970* self) {
    return self->unk19C;
}

INCLUDE_ASM("asm/nonmatchings/game/t_1298B0", func_00129978);

extern "C" void func_00129F70(SA129_A* self, int a, int b) {
    int i;
    for (i = 0; i < 50; i++) {
        self->unk8[i] = func_00128B08(operator_new(0x490));
    }
    self->unk1A8 = a;
    self->unk1AC = b;
}

INCLUDE_ASM("asm/nonmatchings/game/t_1298B0", func_0012A038);

GP_DATA(D_003690E8);
GP_DATA(D_003690D8);
extern "C" void func_0012A048(void* p) {
    SA129_Pool* pool = D_003690D8[D_003690E8];
    if ((pool && pool->Has((u32)p)) || ((pool = D_003690D8[D_003690E8 ^ 1]) && pool->Has((u32)p))) {
        func_0011C2E8(pool, p);
    } else if (p) {
        Heap_Free(D_00368A38, p);
    }
}

extern "C" void* func_0012A0F8(u32 size) {
    SA129_Pool* pool = D_003690D8[D_003690E8];
    if (pool) {
        void* r = func_0011C2A8(pool);
        if (!r) {
            int heap = D_00368A38;
            func_00119490(heap, func_00119610(heap, 1));
            r = Heap_Alloc(D_00368A38, size, 1, 0);
            func_001194B8(D_00368A38);
        }
        return r;
    }
    return Heap_Alloc(D_00368A38, size, 1, 0);
}

INCLUDE_ASM("asm/nonmatchings/game/t_1298B0", func_0012A1B0);

extern "C" SA129_L* func_0012A3A0(SA129_L* self) {
    self->unk4 = self;
    self->unk8 = 0;
    self->unkC = self;
    self->unk10 = self;
    self->unk14 = D_00339920;
    func_0012A448(self);
    return self;
}

extern "C" void func_0012A3E8(SA129_L* self, int flags) {
    self->unk14 = D_00339958;
    self->unk10->unkC = self->unkC;
    self->unkC->unk10 = self->unk10;
    self->unkC = self;
    self->unk10 = self;
    if (flags & 1) {
        Heap_Free(D_00368A38, self);
    }
}

extern "C" void func_0012A448(SA129_L* self) {
    self->unk18 = 0;
    self->unk1C = 0;
    self->unk20 = 0;
    self->unk24 = 0;
    self->unk28 = 0;
    self->unk2C = 1;
    self->unk30 = 0;
    self->unk34 = 0xF60C9090;
}

extern "C" void func_0012A478(SA129_L* self, float* a, float* b, float* c) {
    *b = self->unk1C;
    if (self->unk28 == 0) {
        *a = self->unk18;
        *c = self->unk20;
    } else {
        *a = self->unk20;
        *c = self->unk18;
    }
}

extern "C" void func_0012A4B0(SA129_L* self, float f) {
    func_0012A4D0(self, self->unk1C + f);
}

extern "C" void func_0012A4D0(SA129_L* self, float f) {
    float t = self->unk24;
    self->unk24 = 0;
    self->unk1C = f;
    func_0012A510(self);
    self->unk24 = t;
}

extern "C" void func_0012A510(SA129_L* self) {
    self->unk1C = func_0012A1B0(self);
}

extern "C" int func_0012A538(SA129_L* self) {
    if (self->unk2C == 0) {
        if (self->unk28 == 0) {
            return self->unk1C == self->unk20;
        }
        return self->unk1C == self->unk18;
    }
    return 0;
}

extern "C" int func_0012A590(SA129_L* self, float a, float b, float c, int d, int e) {
    self->unk18 = a < b ? a : b;
    self->unk20 = a < b ? b : a;
    self->unk1C = a;
    self->unk24 = c * 0.016666668f;
    self->unk28 = b <= a ? -1 : 0;
    self->unk2C = e;
    self->unk30 = 0;
    self->unk34 = d;
}

extern "C" void func_0012A5E0(void) {
}

extern "C" void func_0012A5E8(SA129_L* self, int flags) {
    self->unk14 = D_00339958;
    self->unk10->unkC = self->unkC;
    self->unkC->unk10 = self->unk10;
    self->unkC = self;
    self->unk10 = self;
    if (flags & 1) {
        Heap_Free(D_00368A38, self);
    }
}

extern "C" SA129_K* func_0012A648(SA129_K* self, SA129_M* a, int b, int c) {
    self->unk64 = D_00339AA8;
    self->unk4 = 0xFFFFFFFF;
    self->unk14 = D_00339AE8;
    self->unk58 = a;
    self->unk5C = b;
    self->unk3C = 1;
    self->unk8 = 0;
    self->unkC = self;
    self->unk10 = self;
    self->unk44 = 0;
    self->unk18 = 0;
    self->unk38 = 0;
    if (c) {
        self->unk28 = 0;
        self->unk1C = 1.0f;
        self->unk20 = 1.0f;
        self->unk24 = 1.0f;
        self->unk2C = 0;
        self->unk50 = 0;
    } else {
        self->unk1C = 0;
        self->unk20 = 0;
        self->unk24 = 0;
        self->unk28 = 0;
        self->unk2C = 0;
        self->unk50 = 0;
    }
    func_0012A778(self);
    return self;
}

extern "C" void func_0012A6F8(SA129_K* self, int flags) {
    self->unk64 = D_00339AA8;
    func_0012A778(self);
    self->unk14 = D_00339958;
    self->unk10->unkC = self->unkC;
    self->unkC->unk10 = self->unk10;
    self->unkC = self;
    self->unk10 = self;
    if (flags & 1) {
        Heap_Free(D_00368A38, self);
    }
}

extern "C" void func_0012A778(SA129_K* self) {
    func_0012C8A8(self);
    self->unk30 = 0;
    self->unk34 = 0;
    if (self->unk50) {
        self->unk50 = 0;
        if (self->unk58->unk14) {
            func_00289FD8(self->unk58->unk14);
        }
    }
    self->unk54 = 0;
    self->unk4C = 0;
    self->unk40 = 0;
}

extern "C" void func_0012A7D8(SA129_K* self, int a) {
    self->unk44 = a;
    func_0012BE38(self, 0x1CA1FF20, 0, 0, 0, 0.0f, 1000.0f, 0.3f, 1.0f);
}

INCLUDE_ASM("asm/nonmatchings/game/t_1298B0", func_0012A828);

INCLUDE_ASM("asm/nonmatchings/game/t_1298B0", func_0012A9A0);

INCLUDE_ASM("asm/nonmatchings/game/t_1298B0", func_0012A9F8);

INCLUDE_ASM("asm/nonmatchings/game/t_1298B0", func_0012B700);

extern "C" void func_0012B758(void) {
}

INCLUDE_ASM("asm/nonmatchings/game/t_1298B0", func_0012B760);

INCLUDE_ASM("asm/nonmatchings/game/t_1298B0", func_0012B768);
