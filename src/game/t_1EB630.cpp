// cflags: -funroll-loops
#include "common.h"

struct S1ECC40_N {
    S1ECC40_N* unk0;
    S1ECC40_N* unk4;

    void Init() {
        unk0 = this;
        unk4 = this;
    }
};

struct S1ECC40 {
    s32 unk0;
    S1ECC40_N unk4;

    void Init() {
        unk4.Init();
    }
};

struct S1ECD18 {
    char pad0[0x18];
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8(int);
};

struct S1EC018 {
    u32 unk0;
    void* unk4;
    void* unk8;
};

struct S1EBAE8 {
    char pad0[0x4];
    u32 unk4;
    void** unk8;

    void* Get(u32 i) {
        if (unk4 == 1) {
            return (void*)unk8;
        }
        return unk8[i];
    }
};

extern "C" {
extern S1ECC40 D_0038EE00;
extern void* D_0032C550[];
extern u32 D_0036E060;
void func_001ECC40(int, int);
void* func_002763C0(void*, int);
void func_001EC0A0(void*);
void func_001EBCB0();
void func_001EBAE8(S1EBAE8*);
void func_0030A49C(void*, int, int);
s32 func_0027DD88(void*, u32);
void func_0027C7D0(void*, void*, void*);
}

INCLUDE_ASM("asm/nonmatchings/game/t_1EB630", func_001EB630);

INCLUDE_ASM("asm/nonmatchings/game/t_1EB630", func_001EBA98);

GP_DATA(D_0036E060);
extern "C" void func_001EBAB0(void* v) {
    if (D_0036E060 < 0x60) {
        D_0032C550[D_0036E060++] = v;
    }
}

extern "C" void func_001EBAE8(S1EBAE8* p) {
    u32 n = p->unk4;
    u32 i;
    for (i = 0; i < n; i++) {
        func_001EBAB0(p->Get(i));
    }
}

extern "C" void func_001EBC80(S1EBAE8* p) {
    func_001EBCB0();
    func_001EBAE8(p);
}

extern "C" void func_001EBCB0() {
    func_0030A49C(D_0032C550, 0, 0x180);
    D_0036E060 = 0;
}

INCLUDE_ASM("asm/nonmatchings/game/t_1EB630", func_001EBCE0);

INCLUDE_ASM("asm/nonmatchings/game/t_1EB630", func_001EBFE0);

extern "C" void func_001EBFF0(void* p) {
    func_001EC0A0(func_002763C0(p, 1));
}

extern "C" void func_001EC018(S1EC018* p, void* a) {
    if ((p->unk0 & 0xFE00) == 0x1400) {
        if (func_0027DD88(p->unk8, 0x4BB2084E)) {
            func_0027C7D0(a, p->unk4, p->unk8);
        }
        if (func_0027DD88(p->unk8, 0xD81C03B0)) {
            func_0027C7D0(a, p->unk4, p->unk8);
        }
    }
}

INCLUDE_ASM("asm/nonmatchings/game/t_1EB630", func_001EC0A0);

INCLUDE_ASM("asm/nonmatchings/game/t_1EB630", func_001EC608);

INCLUDE_ASM("asm/nonmatchings/game/t_1EB630", func_001EC818);

INCLUDE_ASM("asm/nonmatchings/game/t_1EB630", func_001EC8D0);

INCLUDE_ASM("asm/nonmatchings/game/t_1EB630", func_001EC998);

extern "C" void func_001ECC40(int a, int b) {
    if (b == 0xFFFF && a) {
        D_0038EE00.Init();
    }
}

extern "C" void func_001ECC70() {
    func_001ECC40(1, 0xFFFF);
}

INCLUDE_ASM("asm/nonmatchings/game/t_1EB630", func_001ECC90);

extern "C" void func_001ECD18(S1ECD18* p) {
    p->v8(1);
}

INCLUDE_ASM("asm/nonmatchings/game/t_1EB630", func_001ECD48);

INCLUDE_ASM("asm/nonmatchings/game/t_1EB630", func_001ED0F0);
