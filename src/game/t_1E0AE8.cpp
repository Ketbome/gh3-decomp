#include "common.h"

struct S1E277 {
    s32 unk0;
    s32 unk4;
    s32 unk8;
    s32 unkC;
    f32 unk10;
    s32 unk14;
    s32 unk18;
    s32 unk1C;
    s32 unk20;
    s32 unk24;
    s32 unk28;
    s32 unk2C;
    s32 unk30;
};

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

struct S1E0E70V {
    s16 delta;
    s16 index;
    void* fn;
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
s32 func_0028C200(s32 a, s32 b);
s32 func_001E0FF8(void* p, s32 v);
void func_002763E0(u32 key, s32 v);
s32 func_002763E0_i(u32 key, s32 v) __asm__("func_002763E0");
void func_001E1B28(void* p, s32 a);
void func_0027C160(s32 a, s32 b, s32 c);
void* func_001CE8D0(void* p);
s32 func_00123200(void* p);
extern u8 D_0034CC60[];
void func_00113250(s32 a);
void func_0015D750(s32 a);
void func_001CE990(void* p, s32 a);
void func_0027AC90(s32 a);
s32 func_001E1698(void* p);
s32 func_0028D1D8(s32 a, s32 b, s32 c, s32 d, s32 e, s32 f, s32 g, s32 h, s32 i, s32 j);
void* operator_new(u32 size);
void* func_001E0768(void* p, void* q);
void func_001E0F18(struct S1E0AE8* p);
s32 func_0011EF10(void);
s32 func_00275570(void);
extern s32 D_00370F40;
void func_001DE7C8(void* p, s32 a);
}

INCLUDE_ASM("asm/nonmatchings/game/t_1E0AE8", func_001E0AE8);

INCLUDE_ASM("asm/nonmatchings/game/t_1E0AE8", func_001E0B60);

INCLUDE_ASM("asm/nonmatchings/game/t_1E0AE8", func_001E0BB0);

extern "C" s32 func_001E0BC0(S1E0AE8* p) {
    return p->unkA8;
}

extern "C" void* func_001E0BC8(char* p, s32 a) {
    func_001CE8D0(p);
    *(void**)(p + 8) = D_0034CC60;
    *(s32*)(p + 0x6C) = func_00123200(operator_new(0x100));
    *(s32*)(p + 0x78) = a;
    *(s32*)(p + 0x80) = 1;
    *(s32*)(p + 0x70) = 0;
    *(s32*)(p + 0x74) = 0;
    *(s32*)(p + 0x7C) = 0;
    *(s32*)(p + 0x84) = 0;
    *(s32*)(p + 0x88) = 0;
    *(s32*)(p + 0x8C) = 0;
    return p;
}

extern "C" void func_001E0C40(char* p, s32 flags) {
    s32 t = *(s32*)(p + 0x88);
    *(void**)(p + 8) = D_0034CC60;
    if (t != 0) {
        func_0027AC90(t);
        func_00113250(t);
    }
    s32 u = *(s32*)(p + 0x6C);
    if (u != 0) {
        func_0015D750(u);
    }
    func_001CE990(p, flags);
}

INCLUDE_ASM("asm/nonmatchings/game/t_1E0AE8", func_001E0CB8);

extern "C" s32 func_001E0E10(char* p) {
    if (*(s32*)(p + 0x80) != 0) {
        s32 t = *(s32*)(p + 0x84);
        if (t != 0) {
            return func_0028D1D8(t, *(s32*)(p + 0x88), 0, 0, 0, 0, 0, 0, 0, 0);
        }
        return 0;
    }
    return 0;
}

extern "C" void func_001E0E70(char* p, s32 a) {
    func_0027C160(a, 0x8DDE72C0, *(s32*)(p + 0x70));
    func_0027C160(a, 0xB8CA12C5, *(s32*)(p + 0x74));
    S1E0E70V* e = (S1E0E70V*)(*(char**)(p + 8) + 0x80);
    ((void (*)(char*, s32))e->fn)(p + e->delta, a);
}

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
        r = func_001E0768(operator_new(0xAC), p);
    }
    return r;
}

extern "C" s32 func_001E0FF8(void* pv, s32 v) {
    S1E0AE8* p = (S1E0AE8*)pv;
    S1E0AE8_I it;
    S1E0AE8_I end;
    it.unk4 = (S1E0AE8_N*)p->unk70.unk4;
    end.unk4 = (S1E0AE8_N*)&p->unk70;
    if (it.unk4 != end.unk4) {
        do {
            if (func_001E0F00((S1E0AE8*)it.unk4->unk8) == v) {
                return (s32)it.unk4->unk8;
            }
            it.unk4 = it.unk4->unk4;
        } while (it.unk4 != end.unk4);
    }
    return 0;
}

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

extern "C" s32 func_001E1308(S1E0AE8* p, s32 v) {
    S1E0AE8_I it;
    S1E0AE8_I end;
    it.unk4 = (S1E0AE8_N*)p->unk70.unk4;
    end.unk4 = (S1E0AE8_N*)&p->unk70;
    if (it.unk4 != end.unk4) {
        do {
            if (func_001E0F00((S1E0AE8*)it.unk4->unk8) == v) {
                func_001E0EE0((S1E0AE8*)it.unk4->unk8, 1);
            }
            it.unk4 = it.unk4->unk4;
        } while (it.unk4 != end.unk4);
    }
    return 1;
}

INCLUDE_ASM("asm/nonmatchings/game/t_1E0AE8", func_001E1378);

INCLUDE_ASM("asm/nonmatchings/game/t_1E0AE8", func_001E1650);

INCLUDE_ASM("asm/nonmatchings/game/t_1E0AE8", func_001E1698);

INCLUDE_ASM("asm/nonmatchings/game/t_1E0AE8", func_001E18A8);

extern "C" s32 func_001E1978(S1E0AE8* p, s32 a, s32 b) {
    s32 v;
    if (a == 0) {
        S1E0AE8_I it;
        S1E0AE8_N* h = (S1E0AE8_N*)p->unk70.unk4;
        if (h != (S1E0AE8_N*)&p->unk70) {
            it.unk4 = h;
            char* q = (char*)it.unk4->unk8;
            if (q == 0) {
                return 0;
            }
            func_001E0E70(q, b);
            return 1;
        }
    }
    v = func_001E0FF8(p, a);
    if (v == 0) {
        return 0;
    }
    func_001E0E70((char*)v, b);
    return 1;
}

INCLUDE_ASM("asm/nonmatchings/game/t_1E0AE8", func_001E19F0);

extern "C" s32 func_001E1A28(S1E0AE8* p) {
    return p->unk70.unk4 != &p->unk70;
}

INCLUDE_ASM("asm/nonmatchings/game/t_1E0AE8", func_001E1A40);

extern "C" void* func_001E1AD0(char* p) {
    *(s32*)p = 0;
    *(s32*)(p + 4) = 0;
    *(s32*)(p + 8) = 0;
    *(f32*)(p + 0xC) = 1.0f;
    func_001E1B28(p, func_002763E0_i(0x99DD8474, 0));
    return p;
}

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

extern "C" void func_001E2770(S1E277* p) {
    p->unk0 = 0;
    p->unk4 = 0;
    p->unk8 = 0;
    p->unkC = 0;
    p->unk14 = 0;
    p->unk18 = 0;
    p->unk1C = 0;
    p->unk20 = 0;
    p->unk24 = 0;
    p->unk28 = 0;
    p->unk2C = 0;
    p->unk30 = 0;
    p->unk10 = 0.11f;
    func_001DE7C8((char*)p + 0x38, 0);
    func_001DE7C8((char*)p + 0x5C, 0);
    func_001DE7C8((char*)p + 0x80, 0);
    func_001DE7C8((char*)p + 0xA4, 0);
    func_001DE7C8((char*)p + 0xC8, 0);
    func_001DE7C8((char*)p + 0xEC, 0);
    func_001DE7C8((char*)p + 0x110, 0);
    func_001DE7C8((char*)p + 0x134, 0);
    func_001DE7C8((char*)p + 0x158, 0);
    func_001DE7C8((char*)p + 0x17C, 0);
}

INCLUDE_ASM("asm/nonmatchings/game/t_1E0AE8", func_001E2848);

INCLUDE_ASM("asm/nonmatchings/game/t_1E0AE8", func_001E2850);

extern "C" s32 func_001E2968(s32* p, s32 k) {
    if (k != 0) {
        if (*p != 0) {
            return func_0011EF10() - k;
        }
        return D_00370F40 + func_00275570() - k;
    }
    if (*p != 0) {
        return func_0011EF10();
    }
    return D_00370F40 + func_00275570();
}

INCLUDE_ASM("asm/nonmatchings/game/t_1E0AE8", func_001E29F0);
