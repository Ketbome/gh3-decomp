#include "common.h"

struct S_0019B668 { int unk0; int unk4; int unk8; };
struct E_0019CFE8 { int unk0; int unk4; u64 unk8; };

extern "C" {
int func_0019D0B0(int, int, long);
void func_0030A2F4(void*, void*, int);
void func_0019B550(S_0019B668*, int, int);
void func_0011A470(int);
extern int D_0036C0C4;
extern int D_0036C118;
extern E_0019CFE8 D_00415D00[];
extern char* D_00373270;
extern int D_003732A0;
extern char* D_003732A4;
extern int D_0037328C;
extern int D_00373284;
void func_0019C3F0(int, int, int);
void func_00119490(void*, int);
void func_001194B8(void*);
int func_0019B448(void*);
void func_00199EA8(void*, int, int, int, int, float);
void func_0019AF20(int, int, void*);
}

struct H_0019B6B8 { char pad0[0x1DC]; int unk1DC; };
extern H_0019B6B8* D_00368A38;

INCLUDE_ASM("asm/nonmatchings/game/t_19B448", func_0019B448);

extern int D_0036C0C8;
extern short D_0036C0CC;
extern short D_0036C0CE;

GP_DATA(D_0036C0CE);
GP_DATA(D_0036C0C8);
GP_DATA(D_0036C0CC);
extern "C" void func_0019B550(S_0019B668* a, int n, int depth) {
    if (D_0036C0CE != 0) {
        func_0011A470(D_0036C0C8);
        D_0036C0C8 = 0;
        D_0036C0CC = 0;
        D_0036C0CE = 0;
    } else if (n) {
        if (depth > 0) {
            int d = depth - 1;
            int* p = (int*)n;
            int c = 15;
            do {
                c -= 8;
                func_0019B550(a, p[0], d);
                func_0019B550(a, p[1], d);
                func_0019B550(a, p[2], d);
                func_0019B550(a, p[3], d);
                func_0019B550(a, p[4], d);
                func_0019B550(a, p[5], d);
                func_0019B550(a, p[6], d);
                func_0019B550(a, p[7], d);
                p += 8;
            } while (c >= 0);
        }
        func_0011A470(n);
    }
}

GP_DATA(D_0036C0C4);
extern "C" void func_0019B668(S_0019B668* self) {
    func_0019B550(self, self->unk8, 5);
    self->unk8 = 0;
    func_0011A470(self->unk4);
    func_0011A470(self->unk0);
    func_0011A470(D_0036C0C4);
    D_0036C0C4 = 0;
}

extern "C" void func_0019B6B8(int a0, int a1, int a2, int a3, int a4, int a5) {
    char l[0x10];
    func_00119490(D_00368A38, D_00368A38->unk1DC);
    if (func_0019B448(l)) {
        func_00199EA8(l, a1, a2, a3, a4, 1.0f);
        func_0019AF20(a0, a5, l);
        func_0019B668((S_0019B668*)l);
        func_001194B8(D_00368A38);
    }
}

extern "C" void func_0019B778(int a) {
    char* p = D_00373270;
    char* end = (char*)(((int)p + 15) & ~15);
    for (; p < end; ) {
        *p = 0;
        D_00373270 = p + 1;
        p = D_00373270;
    }
    D_003732A0 = a;
    D_003732A4 = D_00373270;
    D_0037328C = 0;
    D_00373284 = 0;
}

extern "C" long func_0019B7E0(void) {
    char* p = D_00373270;
    char* end = (char*)(((int)p + 15) & ~15);
    for (; p < end; ) {
        *p = 0;
        D_00373270 = p + 1;
        p = D_00373270;
    }
    long r = ((long)D_003732A4 << 32) | ((long)(u32)D_003732A0 << 28) | (u32)((D_00373284 & 0x3FF) << 16);
    if (D_003732A0 == 3) {
        r |= (D_00373270 - D_003732A4) >> 4;
    }
    return r;
}

INCLUDE_ASM("asm/nonmatchings/game/t_19B448", func_0019B880);

INCLUDE_ASM("asm/nonmatchings/game/t_19B448", func_0019B978);

INCLUDE_ASM("asm/nonmatchings/game/t_19B448", func_0019B9C8);

INCLUDE_ASM("asm/nonmatchings/game/t_19B448", func_0019BA98);

INCLUDE_ASM("asm/nonmatchings/game/t_19B448", func_0019BCA0);

typedef unsigned int u128_19B __attribute__((mode(TI)));
struct P_0019BE48 { char pad0[0x28]; int unk28; char* unk2C; };
struct K_0019BE48 { u32 unk0; char* unk4; };
extern "C" {
extern P_0019BE48* D_00373294;
extern K_0019BE48* D_0037327C;
}

extern "C" void func_0019BE48(P_0019BE48* a) {
    if (D_00373294) {
        u32 t = D_0037327C->unk0 >> 28;
        if (t == 5 || t == 3) {
            char* p = D_00373270;
            D_0037327C = (K_0019BE48*)p;
            D_00373270 = p + 16;
            *(u128_19B*)p = (u128_19B)0x20000000;
        } else if (t == 1) {
            ((char*)D_0037327C)[3] = 0x20;
        }
        D_00373294->unk28 = D_00373284;
        D_00373294->unk2C = (char*)D_0037327C;
    }
    D_00373294 = a;
    if (a) {
        int w = a->unk28;
        char* p = a->unk2C;
        D_00373284 = w;
        D_0037327C = (K_0019BE48*)p;
        ((K_0019BE48*)p)->unk4 = D_00373270;
    }
}

extern "C" int func_0019BF10(u16* p) {
    return (*p + 1) << 4;
}

INCLUDE_ASM("asm/nonmatchings/game/t_19B448", func_0019BF20);

INCLUDE_ASM("asm/nonmatchings/game/t_19B448", func_0019BFC8);

extern "C" void func_0019C208(u16* src, void* dst) {
    func_0030A2F4(dst, src, (*src + 1) << 4);
}

INCLUDE_ASM("asm/nonmatchings/game/t_19B448", func_0019C238);

INCLUDE_ASM("asm/nonmatchings/game/t_19B448", func_0019C3F0);

INCLUDE_ASM("asm/nonmatchings/game/t_19B448", func_0019C648);

INCLUDE_ASM("asm/nonmatchings/game/t_19B448", func_0019C700);

INCLUDE_ASM("asm/nonmatchings/game/t_19B448", func_0019C908);

extern "C" void func_0019CCF8(int a0, int a1) {
    func_0019C3F0(a0, a1, 0);
}

extern "C" void func_0019CD18(int a0, int a1) {
    func_0019C3F0(a0, a1, 1);
}

INCLUDE_ASM("asm/nonmatchings/game/t_19B448", func_0019CD38);

extern "C" int func_0019CFE8(int a, int b, u64 c) {
    int n = D_0036C118;
    if (n >= 40) {
        return 0;
    }
    E_0019CFE8* e = &D_00415D00[n];
    e->unk0 = a;
    e->unk4 = b;
    D_00415D00[n].unk8 = c;
    D_0036C118 = n + 1;
    return 1;
}

extern "C" void func_0019D038(void) {
    E_0019CFE8* p = D_00415D00;
    int i = 0;
    if (D_0036C118 > 0) {
        do {
            i++;
            func_0019D0B0(p->unk0, p->unk4, p->unk8);
            p++;
        } while (i < D_0036C118);
    }
    D_0036C118 = 0;
}

INCLUDE_ASM("asm/nonmatchings/game/t_19B448", func_0019D0B0);

INCLUDE_ASM("asm/nonmatchings/game/t_19B448", func_0019D248);

INCLUDE_ASM("asm/nonmatchings/game/t_19B448", func_0019D290);

struct U64P_19B { u64 v; } __attribute__((packed));
extern "C" {
extern U64P_19B* D_00373270_u __asm__("D_00373270");
void func_0019E178_g(void) __asm__("func_0019E178");
void func_0019E318_g(u64, u64) __asm__("func_0019E318");
void func_0019E1B0_g(int) __asm__("func_0019E1B0");
void func_0019E090_g(int, int, int, int, int) __asm__("func_0019E090");
void func_0019E0D8_g(int) __asm__("func_0019E0D8");
}

static inline void Put_19B(u64 v) {
    U64P_19B* p = D_00373270_u;
    p->v = v;
    D_00373270_u = p + 1;
}

extern "C" void func_0019D2A0(int w, int h, int a2, int a3, int a4, int a5, int a6, int a7) {
    int s = a6 << 4;
    func_0019E178_g();
    func_0019E318_g(0x3F, 0);
    u64 hp = (u64)((h - 1) & 0x3FF) << 34;
    u64 wp = (u64)((w - 1) & 0x3FF) << 14;
    u64 q = hp | 0xA;
    func_0019E318_g(9, wp | q);
    func_0019E318_g(0x41, ((u64)(((w >> 1) - 1) & 0x7FF) << 16) | ((u64)(((h >> 1) - 1) & 0x7FF) << 48));
    func_0019E318_g(7, ((a4 << 5) & 0x3FE0) | ((u64)((a2 >> 6) & 0x3F) << 14) | ((u64)0xD500 << 19));
    func_0019E318_g(0x15, 0x60);
    func_0019E318_g(0x4D, (a5 & 0x1FF) | ((u64)((a3 >> 6) & 0x3F) << 16));
    func_0019E318_g(0x43, a7);
    func_0019E318_g(0, 0x356);
    func_0019E1B0_g(0);
    func_0019E090_g(0x53, 2, 1, 0, 0);
    int n = w << 4;
    int v = 0;
    if (n > 0) {
        do {
            Put_19B(0x100000 | ((v + 0x10) & 0x3FFF));
            Put_19B(0x800000 | (((v >> 1) + 0x80) & 0xFFFF));
            int u = v + s;
            Put_19B(((u64)(((h << 4) + 0x10) & 0x3FF0) << 16) | ((u + 0x10) & 0x3FFF));
            Put_19B((((u >> 1) + 0x80) & 0xFFFF) | ((u64)(((h << 3) + 0x80) & 0xFFF8) << 16));
            v = u;
        } while (v < n);
    }
    func_0019E0D8_g(0);
}
