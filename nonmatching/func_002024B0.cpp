// cflags: -funroll-loops
#include "common.h"

typedef unsigned int u128_202 __attribute__((mode(TI)));

struct S202 {
    char pad0[0xC];
    char* unkC;
    char pad10[0xC];
    int unk1C;
    char pad20[0x130];
    int unk150;
    char pad154[0xAC];
    int unk200;
    f32 unk204;
    f32 unk208;
    void* unk20C;
    char pad210[0xC];
    f32 unk21C;
    int unk220;
    int unk224;
};

struct M202 {
    u128_202 r[4];
    M202& operator=(const M202& o) {
        r[0] = o.r[0];
        r[1] = o.r[1];
        r[2] = o.r[2];
        r[3] = o.r[3];
        return *this;
    }
};

extern "C" {
void func_00201BF8(S202*, int);
void func_00223628(int, void*);
void func_0010F970(void*, void*, float);
int func_0027D870(int, u32, int*, int);
int func_0027D1F8(int, u32, int*, int);
int func_00224220(int, int);
void func_00223590(int, u128_202*);
void func_00201DE8(S202*, int, u128_202*);
int func_00223460(int);
int func_00223548(int, int);
int func_00203858(S202*, int);
int func_0027DF00(int, u32);
int func_00201CE0(S202*);
int func_0010C050(int);
int func_002234E8(int, int);
void func_002235F0(int, u128_202*);
int func_0027D268(int, u32, float*, int);
int func_00202ED0(S202*, int, int, u128_202, int);
void func_00201CF0(S202*, int);
int func_00223BF0(int);
}

static inline u128_202 MakeVec(f32 x, f32 y, f32 z, f32 w) {
    u128_202 lo, hi;
    asm("pextlw %0, %1, %2" : "=r"(lo) : "r"(y), "r"(x));
    asm("pextlw %0, %1, %2" : "=r"(hi) : "r"(w), "r"(z));
    asm("pcpyld %0, %1, %2" : "=r"(lo) : "r"(hi), "0"(lo));
    return lo;
}

union U202 {
    u128_202 q;
    f32 f[4];
};

#define Q202(p, o) (*(u128_202*)((char*)(p) + (o)))

INCLUDE_ASM("asm/nonmatchings/game/t_202258", func_00202258);

INCLUDE_ASM("asm/nonmatchings/game/t_202258", func_00202400);

struct S2024 {
    char pad0[0x1C];
    s32 unk1C;
    s32 unk20;
    char pad24[0x13C];
    f32 a160[4];
    f32 a170[4];
    f32 a180[4];
    f32 a190[4];
    f32 a1A0[4];
    f32 a1B0[4];
};

extern "C" void func_00201B50(S2024*, s32);

static inline void Clr2024(s32& v, s32 m) {
    v &= ~m;
}

extern "C" void func_002024B0(S2024* p, s32 s, s32 unused, s32 i) {
    f32 sign = 1.0f;
    s32 t = p->unk1C;
    if (t & 0x40) {
        Clr2024(t, 0x40);
        Clr2024(t, 7);
        p->unk1C = t;
    }
    if (func_0027DF00(s, 0x26AF9DC9)) {
        switch (i) {
        case 0:
            sign = -1.0f;
            break;
        case 1:
            i = 2;
            break;
        case 2:
            i = 1;
            break;
        }
    }
    f32* r1B0 = p->a1B0;
    f32* r1A0 = p->a1A0;
    f32* r160 = p->a160;
    r1B0[i] = 0.0f;
    r1A0[i] = 0.0f;
    f32* c = &r160[i];
    *c = 0.0f;
    if (func_0027D268(s, 0xFF7EBAF6, c, 0)) {
        f32* b170 = p->a170;
        f32* b190 = p->a190;
        f32* d = &b190[i];
        *c = sign * 0.017453294f * *c;
        p->unk20 &= ~(0x20 << i);
        b170[i] = 0.0f;
        *d = 0.0f;
        if (*c == *d) {
            p->unk1C &= ~(1 << i);
            return;
        }
    }
    {
        f32* q = &r1B0[i];
        if (func_0027D268(s, 0xF59FF7D7, q, 0)) {
            f32* b180 = p->a180;
            f32* r = &b180[i];
            *q *= 0.017453294f;
            if (func_0027D268(s, 0xF0D90109, r, 0)) {
                *r *= 0.017453294f;
            }
        } else {
            f32* q2 = &r1A0[i];
            if (func_0027D268(s, 0x85894A84, q2, 0)) {
                f32* b180 = p->a180;
                f32* b190 = p->a190;
                f32* r = &b180[i];
                *q2 *= 0.017453294f;
                if (func_0027D268(s, 0xF0D90109, r, 0)) {
                    *r *= 0.017453294f;
                }
                if (((p->unk1C >> i) ^ 1) & 1) b190[i] = 0.0f;
            } else {
                f32* b190 = p->a190;
                f32* r = &b190[i];
                if (func_0027D268(s, 0xF0D90109, r, 0)) {
                    *r *= 0.017453294f;
                }
            }
        }
        if (r160[i] == 0.0f && r1B0[i] == 0.0f) {
            p->unk20 |= 0x20 << i;
        }
        if (!(p->unk20 & (0x20 << i))) {
            func_00201B50(p, i);
        }
        p->unk1C |= 1 << i;
    }
}

extern "C" void func_00202828(S202* p, int s) {
    int n = func_00223460(p->unk224);
    if (n) {
        int i = 1;
        func_0027D1F8(s, 0xE85997D0, &i, 0);
        i = i - 1;
        if (i < 0 || i >= n) i = 0;
        u128_202 t;
        func_00223590(func_00223548(p->unk224, i), &t);
        func_00201DE8(p, s, &t);
    }
}

extern "C" void func_002028D8(S202* p, int s) {
    int v = 0;
    func_0027D870(s, 0xA1DC81F9, &v, 0);
    if (v) {
        int o = func_00224220(v, 1);
        u128_202 t;
        func_00223590(o, &t);
        func_00201DE8(p, s, &t);
    }
}

INCLUDE_ASM("asm/nonmatchings/game/t_202258", func_00202960);

INCLUDE_ASM("asm/nonmatchings/game/t_202258", func_00202A20);

extern "C" void func_00202C88(S202* p, int s) {
    int o = func_0027DF00(s, 0x422E1FCE) ? p->unk220 : p->unk224;
    int n = func_00223460(o);
    if (n) {
        if (n >= 2 && func_00201CE0(p)) {
            func_00201BF8(p, func_002234E8(o, func_0010C050(n)));
        } else {
            func_00201BF8(p, func_002234E8(o, 0));
        }
        p->unk1C = (p->unk1C | 0x10) & ~8;
    }
}

extern "C" void func_00202D50(S202* p) {
    func_00201BF8(p, p->unk200);
    p->unk1C = (p->unk1C | 0x10) & ~8;
}

INCLUDE_ASM("asm/nonmatchings/game/t_202258", func_00202D90);

INCLUDE_ASM("asm/nonmatchings/game/t_202258", func_00202ED0);

INCLUDE_ASM("asm/nonmatchings/game/t_202258", func_00203058);

INCLUDE_ASM("asm/nonmatchings/game/t_202258", func_00203138);

extern "C" void func_00203208(S202* p, int s, int q) {
    int i = 0;
    int n = func_00223460(p->unk224);
    if (n) {
        if (func_0027D1F8(s, 0xE85997D0, &i, 0)) {
            i = i - 1;
        } else if (n >= 2 && func_0027DF00(s, 0x90A1C52A)) {
            i = func_0010C050(n);
        }
        int o = func_00223548(p->unk224, i);
        int id = func_00223BF0(o);
        u128_202 t;
        func_00223590(o, &t);
        if (func_00202ED0(p, s, q, t, 0)) {
            func_00201CF0(p, id);
        } else {
            p->unk150 = id;
        }
    }
}

INCLUDE_ASM("asm/nonmatchings/game/t_202258", func_00203318);

INCLUDE_ASM("asm/nonmatchings/game/t_202258", func_00203440);

extern "C" void func_00203448(S202* p, int o) {
    func_00223628(o, p->unkC + 0xA0);
    *(M202*)(p->unkC + 0x100) = *(M202*)(p->unkC + 0xA0);
}

extern "C" void func_002034A8(S202* p) {
    f32 t = p->unk208 + p->unk21C;
    f32 d = p->unk204;
    f32 r;
    p->unk208 = t;
    if (d == 0.0f || d <= t) {
        r = 1.0f;
        p->unk1C &= ~0x20;
    } else {
        r = t / d;
    }
    func_0010F970(p->unk20C, p->unkC + 0xA0, r);
}

INCLUDE_ASM("asm/nonmatchings/game/t_202258", func_00203528);

INCLUDE_ASM("asm/nonmatchings/game/t_202258", func_00203858);

extern "C" void func_00203A18(S202* p) {
    for (int i = 0; i < 3; i++) {
        if (((p->unk1C >> i) & 1) && func_00203858(p, i)) p->unk1C &= ~(1 << i);
    }
}

INCLUDE_ASM("asm/nonmatchings/game/t_202258", func_00203AD8);

INCLUDE_ASM("asm/nonmatchings/game/t_202258", func_00203C58);

extern "C" void func_00204248(S202* p) {
    u128_202 v = MakeVec(0.0f, 0.0f, 0.0f, 1.0f);
    Q202(p, 0x50) = v;
    Q202(p, 0x60) = v;
    Q202(p, 0x70) = v;
    Q202(p, 0x90) = v;
    Q202(p, 0xA0) = v;
    Q202(p, 0xB0) = v;
    Q202(p, 0xC0) = v;
    Q202(p, 0xD0) = v;
    Q202(p, 0xE0) = v;
    Q202(p, 0xF0) = v;
    Q202(p, 0x100) = v;
    Q202(p, 0x110) = v;
}
