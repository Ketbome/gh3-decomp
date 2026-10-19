#include "common.h"

struct S00283EE8 {
    u8 unk0;
};

struct S00283520 {
    int unk0;
};

struct S282ED0 {
    char pad0[0x24];
    int unk24;
};

struct S283498 {
    int unk0;
    char pad4[0x14];
    int unk18;
    char pad1C[4];
    int unk20;
};

extern "C" {
int func_00283098(S283498 *, u32);
S282ED0 *Heap_Alloc(int, int, int, int);
int func_00119610(int, int);
void func_00119490(int, int);
void func_001194B8(int);
int func_0027B300(int, int);
int func_002763E0(int, int);
int func_002764E8(int, int);
int func_00276200(int, int);
int func_002762F0(int, int);
void Heap_Free(int, int);
extern int D_00368A38;
void func_00282F48(void *);
bool func_00282398(void);
void func_00282268(int, int *, int *);
int func_0027E0A0(int, int);
unsigned int strlen(const char *);
}

struct S2822_N {
    u32 unk0;
    int unk4;
    u8 unk8[4];
    int unkC;
    S2822_N *unk10;
};

extern S2822_N **D_003710A4;

static inline S2822_N *S2822_Find(int key) {
    for (S2822_N *n = D_003710A4[key & 0x7FFF]; n; n = n->unk10) {
        if (n->unk4 == key) {
            return n;
        }
    }
    return 0;
}

extern "C" void func_00282268(int nodei, int *type, int *val) {
    S2822_N *node = (S2822_N *)nodei;
    int t;
    *val = *(int *)((char *)node + 8);
    t = (node->unk0 >> 9) & 0x7F;
    *type = t;
    if (t == 0xD || t == 0x1A) {
        S2822_N *cur = S2822_Find(*val);
        S2822_N *res = cur;
        if (cur && (*((u8 *)cur + 2) == 0xD || *((u8 *)cur + 2) == 0x1A)) {
            for (;;) {
                S2822_N *r = S2822_Find(cur->unkC);
                if (!r) {
                    res = cur;
                    break;
                }
                cur = r;
                if (*((u8 *)cur + 2) != 0xD && *((u8 *)cur + 2) != 0x1A) {
                    res = cur;
                    break;
                }
            }
        }
        if (res) {
            *val = res->unkC;
            *type = *((u8 *)res + 2);
        }
    }
}

INCLUDE_ASM("asm/nonmatchings/game/t_282268", func_00282398);

extern "C" bool func_002826A0(void) {
    return !func_00282398();
}

INCLUDE_ASM("asm/nonmatchings/game/t_282268", func_002826C0);

struct S282838 {
    int ta;
    int va;
    int tb;
    int vb;
};
INCLUDE_ASM("asm/nonmatchings/game/t_282268", func_00282838);

INCLUDE_ASM("asm/nonmatchings/game/t_282268", func_002829B0);

INCLUDE_ASM("asm/nonmatchings/game/t_282268", func_00282CC8);

extern "C" S282ED0 *func_00282ED0(S282ED0 *p) {
    p->unk24 = 0;
    func_00282F48(p);
    return p;
}

extern "C" void func_00282F00(int a, int b) {
    func_00282F48((void *)a);
    if (b & 1) {
        Heap_Free(D_00368A38, a);
    }
}

struct S282F48 {
    int unk0;
    int unk4;
    int unk8;
    int unkC;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    int unk24;
};
extern "C" void func_00282F48(void *vp) {
    S282F48 *p = (S282F48 *)vp;
    p->unk0 = 10;
    int t = p->unk24;
    p->unk4 = 0;
    p->unkC = 0;
    p->unk14 = 0;
    p->unk18 = 0;
    p->unk1C = 0;
    p->unk8 = 0;
    p->unk10 = 0;
    p->unk20 = 0;
    if (t != 0) {
        func_00282F00(t, 3);
        p->unk24 = 0;
    }
}

struct S282FA8 {
    char pad0[0x24];
    S282ED0 *unk24;
};
extern "C" void func_00282FA8(S282FA8 *p) {
    int h = D_00368A38;
    func_00119490(h, func_00119610(h, 5));
    p->unk24 = func_00282ED0(Heap_Alloc(D_00368A38, 0x28, 1, 0));
    func_001194B8(D_00368A38);
}

struct S283020 {
    int unk0;
    int unk4;
    int unk8;
    char padC[8];
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
};
extern "C" void func_00283020(S283020 *p, int a, int b, int c) {
    p->unk20 = 0;
    p->unk14 = b;
    p->unk18 = b;
    p->unk1C = c;
    p->unk4 = a;
    p->unk8 = func_0027B300(a, 0);
    p->unk0 = 0;
}

INCLUDE_ASM("asm/nonmatchings/game/t_282268", func_00283070);

INCLUDE_ASM("asm/nonmatchings/game/t_282268", func_00283098);

extern "C" u32 func_00283498(S283498 *p, u32 n) {
    u32 tot = 0;
    int t;
    do {
        t = func_00283098(p, n);
        tot += t;
        p->unk20 += t;
        p->unk18 += t;
    } while ((u32)(p->unk0 - 9) >= 2 && tot < n);
    return tot;
}

extern "C" int func_00283520(S00283520* p) {
    return (u32)(p->unk0 - 9) < 2;
}

extern "C" int func_00283530(S00283520* p) {
    return p->unk0 == 9;
}

INCLUDE_ASM("asm/nonmatchings/game/t_282268", func_00283540);

INCLUDE_ASM("asm/nonmatchings/game/t_282268", func_00283698);

INCLUDE_ASM("asm/nonmatchings/game/t_282268", func_002837C0);

struct S2838E8 {
    int unk0;
    int pad4;
    int unk8;
};
extern "C" int func_002838E8(S2838E8 *p) {
    int t = p->unk0 & 0xFE00;
    if (t == 0xA00) {
        return p->unk8;
    }
    if (t == 0x3400) {
        return func_002762F0(p->unk8, 0);
    }
    return 0;
}

extern "C" int func_00283930(S2838E8 *p) {
    int t = p->unk0 & 0xFE00;
    if (t == 0xC00) {
        return p->unk8;
    }
    if (t == 0x3400) {
        return func_00276200(p->unk8, 0);
    }
    return 0;
}

extern "C" int func_00283978(S2838E8 *p) {
    int t = p->unk0 & 0xFE00;
    if (t == 0x1800) {
        return p->unk8;
    }
    if (t == 0x3400) {
        return func_002764E8(p->unk8, 0);
    }
    return 0;
}

extern "C" int func_002839C0(S2838E8 *p) {
    int t = p->unk0 & 0xFE00;
    if (t == 0x1400) {
        return p->unk8;
    }
    if (t == 0x3400) {
        return func_002763E0(p->unk8, 0);
    }
    return 0;
}

extern "C" u8 *func_00283A08(u8 *p) {
    switch (*p) {
    case 2:
    case 22:
    case 23:
    case 24:
    case 26:
    case 39:
    case 46:
    case 67:
    case 68:
    case 70:
        p += 5;
        break;
    case 30:
        p += 0xD;
        break;
    case 31:
        p += 9;
        break;
    case 27: {
        int a = *++p;
        a += *++p << 8;
        a += *++p << 16;
        a += *++p << 24;
        p++;
        p += a;
        break;
    }
    case 43:
        p += 5;
        while (*p != 0) {
            p++;
        }
    case 1:
    case 3:
    case 4:
    case 5:
    case 6:
    case 7:
    case 8:
    case 9:
    case 10:
    case 11:
    case 12:
    case 13:
    case 14:
    case 15:
    case 17:
    case 18:
    case 19:
    case 20:
    case 21:
    case 32:
    case 33:
    case 34:
    case 35:
    case 36:
    case 37:
    case 38:
    case 40:
    case 41:
    case 44:
    case 45:
    case 48:
    case 50:
    case 51:
    case 52:
    case 53:
    case 54:
    case 56:
    case 57:
    case 58:
    case 59:
    case 60:
    case 61:
    case 62:
    case 63:
    case 66:
    case 69:
    case 75:
    case 76:
        p++;
        break;
    case 47:
    case 55:
    case 64:
    case 65: {
        int a = *++p;
        a += *++p << 8;
        a += *++p << 16;
        a += *++p << 24;
        p++;
        p += a * 6;
        break;
    }
    case 71:
    case 72:
    case 73:
        p += 3;
        break;
    case 74: {
        p++;
        int a = *p;
        p++;
        int b = *p;
        p = (u8 *)(((u32)(p + 4)) & ~3u);
        p += a + (b << 8);
        break;
    }
    case 0:
    case 16:
    case 25:
    case 28:
    case 29:
    case 42:
    case 49:
        break;
    }
    return p;
}

INCLUDE_ASM("asm/nonmatchings/game/t_282268", func_00283B48);

extern "C" {
u8 *func_00283A08(u8 *);
}
extern "C" u8 *func_00283DB8(u8 *p) {
    int n;
    switch (*p) {
    case 22:
    case 23:
    case 24:
    case 26:
        p += 5;
        break;
    case 31:
        p += 9;
        break;
    case 30:
        p += 0xD;
        break;
    case 27: {
        u8 *q = p + 1;
        int v = p[1] | (q[1] << 8) | (q[2] << 16) | (q[3] << 24);
        p += v + 5;
        break;
    }
    case 3:
        n = 1;
        do {
            p = func_00283A08(p);
            if (*p == 3) {
                n++;
            } else if (*p == 4) {
                n--;
            }
        } while (n != 0);
        p += 1;
        break;
    case 5:
        n = 1;
        do {
            p = func_00283A08(p);
            if (*p == 5) {
                n++;
            } else if (*p == 6) {
                n--;
            }
        } while (n != 0);
        p += 1;
        break;
    case 75:
        p += 6;
        break;
    }
    return p;
}

extern "C" int func_00283EE8(S00283EE8* p) {
    return p->unk0 < 3;
}

INCLUDE_ASM("asm/nonmatchings/game/t_282268", func_00283EF8);
