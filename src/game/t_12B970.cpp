#include "common.h"

struct SB12_V {
    char pad0[0x4];
    u32 unk4;
    char pad8[0x4];
    SB12_V* unkC;
    char pad10[0x4];
    virtual ~SB12_V();
    SB12_V* Get() { return unk4 == 0xFFFFFFFF ? 0 : this; }
};

struct SB12_O {
    char pad0[0x18];
    void* unk18;
    char pad1C[0x20];
    int unk3C;
    SB12_V* unk40[6];
    int unk58;
    float unk5C;
    int unk60;
    int unk64;
    int unk68;
    int unk6C;
    int unk70;
    int unk74;
};

struct SB12_Node {
    char pad0[0x4];
    int unk4;
};

struct SB12_Item {
    char pad0[0x28];
    float unk28;
    char pad2C[0x4];
    int unk30;
    char pad34[0x40];
    int unk74;
};

struct SB12_Self {
    char pad0[0xC];
    SB12_Node* unkC;
    char pad10[0x8];
    int unk18;
    char pad1C[0x20];
    int unk3C;
    char pad40[0x4];
    char* unk44;
    u32 unk48;
    char pad4C[0xC];
    int unk58;
    char pad5C[0x4];
    int unk60;
};

struct SB12_Link {
    SB12_Link* unk0;
    SB12_Link* unk4;
};

struct SB12_List {
    int unk0;
    char pad4[0x4];
    SB12_Link unk8;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
};

static inline SB12_Item* SB12_First(SB12_Self* self) {
    SB12_Node* n = self->unkC;
    if (n->unk4 == -1) {
        n = 0;
    }
    return n ? (SB12_Item*)((char*)n - 4) : 0;
}

struct S_0012BC90_c { char pad0[0x8]; float unk8; };
struct S_0012BC90_b { char pad0[0xC]; S_0012BC90_c* unkC; };

extern "C" {

void func_0012BE38(void*, int, int, int, int, float, float, float, float);
void func_0012D630(SB12_O*);
void func_0012DF30(SB12_O*);
void func_0012A3E8(void*, int);
void* func_0012A3A0(void*);
void func_0012D0E8(void*);
extern u8 D_00339C30[];
int func_0015FAA0(char*, int, int);
int func_0012A538(void*);
int func_001D1CF8(int, u32);
void func_0012D1A0(int, int);
int func_0012BD10(SB12_Self*, int);
float func_0012BC90(SB12_Self*, int);
}

struct SB12_Pool {
    u32 unk0;
    u32 unk4;
    int Has(u32 p) { return !(p < unk0) && p < unk4; }
};

extern "C" {
extern int D_00368A38;
extern int D_00371480;
extern SB12_Pool* D_00371470[2];
extern int D_00369208;
extern SB12_Pool* D_003691F8[2];
void func_00119400(int, void*);
void func_0011C2E8(SB12_Pool*, void*);
void* func_0011C2A8(SB12_Pool*);
int func_00119610(int, int);
void func_00119490(int, int);
void* func_00118F20(int, u32, int, int);
void func_001194B8(int);
}

struct S_0012C1F8 { char pad0[0x38]; int unk38; };
struct S_0012D208 { char pad0[0x8]; int unk8; };

INCLUDE_ASM("asm/nonmatchings/game/t_12B970", func_0012B970);

INCLUDE_ASM("asm/nonmatchings/game/t_12B970", func_0012BA98);

extern "C" float func_0012BC90(SB12_Self* self, int n) {
    return ((S_0012BC90_b*)func_0012BD10(self, n))->unkC->unk8;
}

extern "C" int func_0012BCB8(SB12_Self* self, int n) {
    return func_0012BD10(self, n) != 0;
}

INCLUDE_ASM("asm/nonmatchings/game/t_12B970", func_0012BCD8);

extern "C" int func_0012BD10(SB12_Self* self, int n) {
    return func_0015FAA0(self->unk44 + n, 0, 1);
}

INCLUDE_ASM("asm/nonmatchings/game/t_12B970", func_0012BD38);

extern "C" int func_0012BD58(SB12_Self* self) {
    SB12_Item* it = SB12_First(self);
    if (it) {
        return func_0012A538((char*)it + 4);
    }
    return 0;
}

extern "C" int func_0012BD98(SB12_Self* self) {
    SB12_Item* it = SB12_First(self);
    if (it) {
        return it->unk30 == 1 || it->unk30 == 2;
    }
    return 0;
}

extern "C" void func_0012BDD0(SB12_Self* self, int anim, float blend) {
    func_0012BE38(self, anim, 0, 0, 0, 0.0f, func_0012BC90(self, anim), blend, 1.0f);
}

INCLUDE_ASM("asm/nonmatchings/game/t_12B970", func_0012BE38);

INCLUDE_ASM("asm/nonmatchings/game/t_12B970", func_0012BF38);

INCLUDE_ASM("asm/nonmatchings/game/t_12B970", func_0012C0B0);

extern "C" float func_0012C1B8(SB12_Self* self) {
    SB12_Item* it = SB12_First(self);
    if (it) {
        return it->unk28 * 60.0f;
    }
    return 0.0f;
}

extern "C" void func_0012C1F8(S_0012C1F8* self, int v) {
    self->unk38 = v;
}

extern "C" void func_0012C200(SB12_Self* self, int v) {
    SB12_Item* it = SB12_First(self);
    if (it) {
        self->unk3C = v;
        it->unk74 = v;
    }
}

INCLUDE_ASM("asm/nonmatchings/game/t_12B970", func_0012C238);

INCLUDE_ASM("asm/nonmatchings/game/t_12B970", func_0012C750);

INCLUDE_ASM("asm/nonmatchings/game/t_12B970", func_0012C780);

extern "C" void func_0012C878(SB12_Self* self, int flag) {
    u32 v;
    self->unk48 &= ~0x20000000;
    v = self->unk48;
    if (flag) {
        v |= 0x20000000;
    }
    self->unk48 = v;
}

extern "C" void func_0012C8A8(SB12_Self* self) {
    SB12_V* n = ((SB12_V*)self->unkC)->Get();
    while (n) {
        SB12_V* next = n->unkC->Get();
        delete n;
        n = next;
    }
}

extern "C" void func_0012C920(SB12_Self* self) {
    self->unk60 = func_001D1CF8(self->unk58, 0x222756D5);
}

extern "C" SB12_List* func_0012C958(SB12_List* self, int a) {
    self->unk0 = a;
    SB12_Link* l = &self->unk8;
    l->unk0 = l;
    l->unk4 = l;
    self->unk10 = 0;
    self->unk14 = 0;
    self->unk18 = 0;
    self->unk1C = 0;
    return self;
}

INCLUDE_ASM("asm/nonmatchings/game/t_12B970", func_0012C980);

INCLUDE_ASM("asm/nonmatchings/game/t_12B970", func_0012CAA8);

INCLUDE_ASM("asm/nonmatchings/game/t_12B970", func_0012CBD0);

INCLUDE_ASM("asm/nonmatchings/game/t_12B970", func_0012CCF0);

INCLUDE_ASM("asm/nonmatchings/game/t_12B970", func_0012CDE8);

INCLUDE_ASM("asm/nonmatchings/game/t_12B970", func_0012CEE0);

INCLUDE_ASM("asm/nonmatchings/game/t_12B970", func_0012CF40);

INCLUDE_ASM("asm/nonmatchings/game/t_12B970", func_0012D000);

extern "C" void* func_0012D028(u32 size) {
    SB12_Pool* pool = D_00371470[D_00371480];
    if (pool) {
        void* r = func_0011C2A8(pool);
        if (!r) {
            int heap = D_00368A38;
            func_00119490(heap, func_00119610(heap, 1));
            r = func_00118F20(D_00368A38, size, 1, 0);
            func_001194B8(D_00368A38);
        }
        return r;
    }
    return func_00118F20(D_00368A38, size, 1, 0);
}

extern "C" void func_0012D0E8(void* p) {
    SB12_Pool* pool = D_003691F8[D_00369208];
    if ((pool && pool->Has((u32)p)) || ((pool = D_003691F8[D_00369208 ^ 1]) && pool->Has((u32)p))) {
        func_0011C2E8(pool, p);
    } else if (p) {
        func_00119400(D_00368A38, p);
    }
}

extern "C" void func_0012D1A0(int a, int b) {
    if (b == 0xFFFF && a) {
        int i;
        for (i = 0x7F; i != -1; i -= 0x20) {
        }
        for (i = 0x7F; i != -1; i -= 0x20) {
        }
    }
}

extern "C" int func_0012D208(S_0012D208* self) {
    return self->unk8;
}

INCLUDE_ASM("asm/nonmatchings/game/t_12B970", func_0012D210);

extern "C" void func_0012D278(void) {
    func_0012D1A0(1, 0xFFFF);
}

extern "C" SB12_O* func_0012D298(SB12_O* self, int a) {
    func_0012A3A0((char*)self + 4);
    self->unk18 = D_00339C30;
    self->unk3C = 2;
    self->unk58 = 0;
    self->unk5C = 0.016666668f;
    self->unk60 = 0;
    self->unk64 = 0;
    self->unk68 = a;
    self->unk6C = 0;
    self->unk70 = 0;
    self->unk74 = 1;
    return self;
}

extern "C" void func_0012D318(SB12_O* self, int flags) {
    self->unk18 = D_00339C30;
    func_0012D630(self);
    func_0012DF30(self);
    func_0012A3E8((char*)self + 4, 0);
    if (flags & 1) {
        func_0012D0E8(self);
    }
}

INCLUDE_ASM("asm/nonmatchings/game/t_12B970", func_0012D380);

INCLUDE_ASM("asm/nonmatchings/game/t_12B970", func_0012D530);

extern "C" void func_0012D630(SB12_O* self) {
    int i;
    for (i = 0; i < self->unk58; i++) {
        delete self->unk40[i];
        self->unk40[i] = 0;
    }
    self->unk58 = 0;
}

INCLUDE_ASM("asm/nonmatchings/game/t_12B970", func_0012D6B0);

INCLUDE_ASM("asm/nonmatchings/game/t_12B970", func_0012D790);

INCLUDE_ASM("asm/nonmatchings/game/t_12B970", func_0012D870);
