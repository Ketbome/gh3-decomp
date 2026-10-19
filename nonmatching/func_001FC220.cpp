// cflags: -funroll-loops
#include "common.h"

struct VEntry1FB {
    s16 delta;
    s16 unk2;
    void (*fn)(void*, int);
};

struct S1FB {
    u32 unk0;
    u32 unk4;
    u32 unk8;
    char pad[0xC];
    VEntry1FB* unk18;
    void* unk1C;
    void* unk20;
    void* unk24;
    void* unk28;
    void* unk2C;
};

struct E1FB {
    u32 unk0;
    u32 unk4;
    u32 unk8;
};

struct S1FD {
    char pad0[0x18];
    VEntry1FB* unk18;
    char pad1C[0x14];
    char unk30[0x4C];
    s32 unk7C;
    s32 unk80;
    char pad84[0xC];
    char unk90[4];
};

typedef int TI128 __attribute__((mode(TI)));

extern "C" {
void func_001FB998(int, int);
int func_001FC608(void*, int);
int func_001FC690(void*, int);
int func_001FC468(S1FB*, int);
void func_001FC718(int, int);
int func_0027DC58(int, int, void*, int);
int func_001FBB70(int);
int func_0026DD48(int, void*);
void func_001CE888(void*, void*);
u32 func_00275570(void);
extern u32 D_00370F40;
extern u8 D_0034FAC8[];
void func_001D0F90(void*, int);
void func_001D0F68(void*);
void func_0010F748(void*);
int func_0027D268(int, u32, float*, int);
int func_0027D1F8(int, u32, int*, int);
int func_00266780(int);
void* func_001EA9E0(int);
int func_0026BEA8(void*, int, int, int, int, float, float, float);
void func_001FBC50(u32, u32);
int func_001FC1E0(S1FB*);
int func_0026B770(void*, int, int, int, int, int, int, float, float, float);
extern E1FB D_0038F600[];
void* func_001287F0(int, int);
void* func_0027AA70(void*);
void func_0027AC90(void*);
void func_00113250(void*);
int func_0026F3B8(int, void*);
int func_001FC220(void*, void*, int);
void func_001FDB00(void*);
int func_003174C0(float);
void func_0010F750(void*, void*, int);
int func_0027D870(int, int, void*, int);
int func_0026C120(int, int, void*);
int func_0026C250(int, int, void*);
void func_0026AF28(void*);
int func_001EB338(void*);
TI128 func_001EB638(void*, int);
int func_001EAA68(void*);
TI128 func_001EAEA0(void*, int);
}

static inline void Release1FB(void** pp) {
    if (*pp) {
        func_001CE888(*pp, pp);
        *pp = 0;
    }
}

extern "C" void func_001FBAF0(void) {
}

extern "C" void func_001FBAF8(void) {
    func_001FB998(1, 0xFFFF);
}

extern "C" void func_001FBB18(E1FB* p) {
    u32 v = p->unk4;
    if (p->unk8 < D_00370F40 + func_00275570() - v) {
        p->unk0 = 0;
        p->unk4 = 0;
        p->unk8 = 0;
    }
}

extern "C" int func_001FBB70(int key) {
    for (int i = 0; i < 50; i++) {
        E1FB* e = &D_0038F600[i];
        if (e->unk0 == key) {
            func_001FBB18(e);
            if (e->unk0) return 1;
            return 0;
        }
    }
    return 0;
}

extern "C" void func_001FBC50(u32 key, u32 time) {
    for (int i = 0; i < 50; i++) {
        E1FB* e = &D_0038F600[i];
        func_001FBB18(e);
        if (!e->unk0) {
            e->unk0 = key;
            e->unk8 = time;
            e->unk4 = D_00370F40 + func_00275570();
            return;
        }
    }
}

INCLUDE_ASM("asm/nonmatchings/game/t_1FBAF0", func_001FBD68);

extern "C" int func_001FBDA0(void* self, int s) {
    func_001FC608(self, s);
    return 1;
}

extern "C" int func_001FBDC0(void* self, int s) {
    func_001FC690(self, s);
    return 1;
}

extern "C" int func_001FBDE0(S1FB* p) {
    for (int i = 0; i < 3; i++) {
        void** q = &(&p->unk1C)[i];
        if (*q) {
            func_0026AF28(*q);
            *q = 0;
        }
    }
    return 1;
}

INCLUDE_ASM("asm/nonmatchings/game/t_1FBAF0", func_001FBE50);

INCLUDE_ASM("asm/nonmatchings/game/t_1FBAF0", func_001FBEA8);

extern "C" int func_001FBEF0(S1FB* self, int s) {
    return func_001FC468(self, s) != 0;
}

extern "C" int func_001FBF10(void* self, int a, int b) {
    void* o = func_0027AA70(func_001287F0(8, 1));
    if (func_0026F3B8(a, o)) {
        func_001FC220(self, o, b);
        if (o) {
            func_0027AC90(o);
            func_00113250(o);
        }
        return 1;
    }
    if (o) {
        func_0027AC90(o);
        func_00113250(o);
    }
    return 0;
}

INCLUDE_ASM("asm/nonmatchings/game/t_1FBAF0", func_001FBFC8);

struct S1FBFD_R {
    char pad0[0x80];
    TI128 unk80;
};

struct S1FBFD {
    char pad0[0xC];
    S1FBFD_R* unkC;
    char pad10[0x18];
    void* unk28;
};

extern "C" TI128 func_001FBFD0(S1FBFD* p, int a) {
    if (func_001EAA68(p->unk28) && a) {
        return func_001EAEA0(p->unk28, a + 0x80);
    }
    return p->unkC->unk80;
}

extern "C" int func_001FC030(S1FB* p, int a, TI128* out) {
    if (!a) return 0;
    if (!p->unk2C) return 0;
    if (!func_001EB338(p->unk2C)) return 0;
    *out = func_001EB638(p->unk2C, a + 0x80);
    return 1;
}

INCLUDE_ASM("asm/nonmatchings/game/t_1FBAF0", func_001FC0A8);

extern "C" int func_001FC1E0(S1FB* p) {
    for (int i = 0; i < 3; i++) {
        if (!(&p->unk1C)[i]) return i + 1;
    }
    return 0;
}

extern "C" void func_001FC0A8_x(int a0, int a1, int a2, int a3, int t0, int t1, int t2, int t3, float f0, float f1, float f2, float f3, int stk) __asm__("func_001FC0A8");

extern "C" int func_001FC220(void* pv, void* av, int c) {
    S1FB* p = (S1FB*)pv;
    int a = (int)av;
    float sp10;
    float sp14;
    int sp18;
    int sp1C;
    int sp20;
    float sp24;
    int sp28;
    int sp2C;
    int sp30;
    float sp34;
    int sp38;
    int sp3C;
    int v17;
    int v20;
    if (func_001FC1E0(p) != 0) {
        sp10 = 100.0f;
        sp24 = 0.0f;
        sp18 = 0x32;
        sp14 = 100.0f;
        sp1C = 0;
        v20 = 0;
        func_0027D268(a, 0xF6A36814, &sp10, 0);
        func_0027D268(a, 0xD8604126, &sp14, 0);
        func_0027D1F8(a, 0x9D5923D8, &sp18, 0);
        func_0027D1F8(a, 0xE46111E0, &sp1C, 0);
        sp20 = 0;
        func_0027D870(a, 0x40C698AF, &sp20, 0);
        int v20b = sp20;
        if (func_0027D268(a, 0xFF2020EC, &sp24, 0) != 0) {
            sp24 *= 12.0f;
        }
        sp28 = 0;
        if (func_0027D870(a, 0x0C6AC50A, &sp28, 0) != 0) {
            v20 = func_00266780(sp28);
        }
        sp2C = 0;
        v17 = 0;
        if (func_0027D870(a, 0x8A7132CE, &sp2C, 0) != 0) {
            v17 = (int)func_001EA9E0(sp2C);
        }
        if (func_0027DC58(a, 0, &sp30, 0) != 0) {
            sp34 = 0.0f;
            func_0027D268(a, 0x14021E42, &sp34, 0);
            sp38 = 1;
            func_0027D1F8(a, 0xC9B0DEB7, &sp38, 0);
            sp3C = 0;
            func_0027D1F8(a, 0xB5A36116, &sp3C, 0);
            func_001FC0A8_x((int)p, sp30, sp1C, sp18, v20, v20b, sp3C != 0, sp38 != 0, sp24, sp10, sp14, sp34, v17);
        }
    }
    return 0;
}

INCLUDE_ASM("asm/nonmatchings/game/t_1FBAF0", func_001FC468);

INCLUDE_ASM("asm/nonmatchings/game/t_1FBAF0", func_001FC608);

INCLUDE_ASM("asm/nonmatchings/game/t_1FBAF0", func_001FC690);

INCLUDE_ASM("asm/nonmatchings/game/t_1FBAF0", func_001FC718);

extern "C" void func_001FCA18(void) {
    func_001FC718(1, 0xFFFF);
}

INCLUDE_ASM("asm/nonmatchings/game/t_1FBAF0", func_001FCA38);

INCLUDE_ASM("asm/nonmatchings/game/t_1FBAF0", func_001FCA90);

extern "C" void func_001FCB08(S1FB* p, int flags) {
    p->unk18 = (VEntry1FB*)D_0034FAC8;
    Release1FB(&p->unk1C);
    func_001D0F90(p, flags);
}

INCLUDE_ASM("asm/nonmatchings/game/t_1FBAF0", func_001FCB68);

extern "C" void func_001FD3E8(void) {
}

extern "C" void func_001FD3F0(void) {
}

INCLUDE_ASM("asm/nonmatchings/game/t_1FBAF0", func_001FD3F8);

INCLUDE_ASM("asm/nonmatchings/game/t_1FBAF0", func_001FD628);

extern "C" void func_001FD9B0(void) {
}

extern "C" void func_001FD9B8(S1FD* p, int a) {
    func_001FDB00(p);
    p->unk18[3].fn((char*)p + p->unk18[3].delta, a);
    p->unk18[8].fn((char*)p + p->unk18[8].delta, 0);
    ((void (*)(void*))p->unk18[2].fn)((char*)p + p->unk18[2].delta);
}

extern "C" void func_001FDA30(S1FB* p) {
    Release1FB(&p->unk1C);
    p->unk1C = 0;
    p->unk18[8].fn((char*)p + p->unk18[8].delta, 1);
}

extern "C" void func_001FDA88(S1FD* p, float t, int a) {
    p->unk7C = D_00370F40 + func_00275570();
    p->unk80 = p->unk7C + func_003174C0(t * 1000.0f);
    func_0010F750(p->unk90, p->unk30, a);
}
