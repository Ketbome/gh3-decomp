#include "common.h"

struct S273498_A {
    char pad0[0x104];
    int unk104;
};

struct S273498_B {
    char pad0[0x8];
    int unk8;
};

struct S273498_C {
    char pad0[0x18];
    int unk18;
    char pad1C[0x14];
};

struct S273498_D {
    char pad0[0x8];
    int unk8;
};

struct S273B80 {
    char pad0[0xC];
    int unkC;
    char pad10[0x24];
    int unk34;
};

extern "C" {
void func_00273B48_2(int, int) asm("func_00273B48");
int func_002727E8(int, int, int, int, int);
int func_0026DC68(int);
extern int D_00370DA0;
int func_00273308(int, f32);
extern int D_003A92CC[];
int func_00272520(int, int, int, int, int, int);
int func_00273D88(void);
extern int D_00368A38;
void func_00114660(void *, int);
void Heap_Free(int, void *);
void func_001145D8(void *);
int func_00273EB0(void);
int func_002E91E8(void);
void func_002EA5F0(void);
void func_002EE510(int);
void func_00274350(void);
extern int D_00370DB8;
void func_002729C0(int);
extern int D_003A9490[];
int func_00272B28(int);
extern int D_00370E38;
int func_002E9140(void);
void func_00273600(int, int, int, int, int, int, int, int, f32);
extern int D_00368748[] __attribute__((section(".sdata")));
extern char D_003A91C8[];
int func_00274240(void *, int, int, int);
void memset(void *, int, int);
int func_002EE550(void);
void func_002EE560(int, void *);
extern S273498_A D_003A90C0[];
int func_00120F78(int, int);
S273498_B *func_001210C8(int, int);
extern int D_00370EE0;
extern int D_00370EE4;
void func_00275180(int, int);
int func_00113DF0(int, int, int);
int func_00275138(int);
extern int D_003A91C4[];
extern int D_00372EC4;
extern int D_00370DA4;
extern u8 D_0032E1E1[];
extern volatile u8 D_00370DB4;
void func_00271A98(int, int, int, int, int, int);
int func_002730D0(float, float);
int func_00273240(float);
extern u8 D_0032E1D8[];
extern float D_00370B08;
int func_00274BF8(void);
extern int D_00370E44;
void func_002746E8(int, int, int);
void func_00274F08(void);
extern int D_00372ED4[] __attribute__((section(".sdata")));
extern S273498_D *D_00370DB8_D asm("D_00370DB8");
extern int D_00372EC8;
extern int D_00372ECC;
void func_002EE4B0(int);
void func_002EE470(int);
int func_002EED08(int);
void func_002EE390(int, int);
int func_002EEC38(int);
void func_002EE360(int, int);
int func_002EECA0(int);
void func_00295060(int);
void func_002931E8(int);
void func_002934D0(int);
int func_002E8FF0(void);
void func_00294FD0(int);
void func_0019EE38(int, int, int, int);
void func_001B3B00(void);
}

GP_DATA(D_00370DA0);
INCLUDE_ASM("asm/nonmatchings/game/t_273498", func_00273498);

extern "C" int func_00273510(int a) {
    if (func_00273D88() == 1 && D_003A92CC[0]) {
        int r = func_00120F78(a, D_003A92CC[0]);
        if (r) {
            return func_00272520(D_00370DB8, r, 1, 0, 0, 0);
        }
    }
    return 0;
}

extern "C" int func_00273588(int a) {
    if (func_00273D88() == 1 && D_003A92CC[0]) {
        S273498_B *r = func_001210C8(a, D_003A92CC[0]);
        if (r) {
            return func_00272520(D_00370DB8, (int)r, 1, 0, 0, 0);
        }
    }
    return 0;
}

INCLUDE_ASM("asm/nonmatchings/game/t_273498", func_00273600);

INCLUDE_ASM("asm/nonmatchings/game/t_273498", func_00273748);

INCLUDE_ASM("asm/nonmatchings/game/t_273498", func_002738C0);

extern "C" int func_00273910(int i) {
    return func_00272B28(D_003A9490[i]);
}

GP_DATA(D_00370DA4);
GP_DATA(D_00370DB4);
extern "C" int func_00273940(int a, int b, int c, int d, float f0, float f1, float f) {
    int bit = 1;
    int i;
    for (i = 0; i < D_00370DA4; i++, bit <<= 1) {
        if ((D_0032E1D8[9] & bit) && !(D_00370DB4 & bit)) break;
    }
    if (i == D_00370DA4) return -1;
    D_00370DB4 |= bit;
    int r = func_002730D0(f0, f1);
    int t = func_00273240(f);
    func_00271A98(i | 0x90, a, b - 0x10, d | (c << 8), r, (int)((float)t * D_00370B08));
    return i;
}

extern "C" int func_00273A80(int a, int i, int c, int d, int e) {
    int r;
    if (func_0026DC68(i) != 1) {
        r = 0;
        if (d != 0) {
            goto call;
        }
    } else {
call:
        r = func_002727E8(D_003A9490[i], a, c, d, e);
    }
    return r;
}

INCLUDE_ASM("asm/nonmatchings/game/t_273498", func_00273B18);

GP_DATA(D_00370DB8);
extern "C" void func_00273B20(void) {
    if (D_00370DB8 != 0) {
        func_002729C0(D_00370DB8);
    }
}

extern "C" void func_00273B48(int i) {
    if (D_003A9490[i] != 0) {
        func_002729C0(D_003A9490[i]);
    }
}

extern "C" void func_00273B80(int a) {
    int i;
    for (i = 0; i < D_00370DA0; i++) {
        S273B80 *o = (S273B80 *)D_003A9490[i];
        if (o != 0) {
            int live = ((o->unkC >> 1) & 1) ^ 1;
            if (live) {
                if (a == 0 || o->unk34 == 0) {
                    func_00273B48_2(i, 1);
                }
            }
        }
    }
}

extern "C" void func_00273C20(int a, int) {
    if (func_00273EB0() != 1) {
        func_00271A98(0xA0, a, 0, 0, 0, 0);
    }
}

GP_DATA(D_00370DA4);
extern "C" void func_00273C68(void) {
    int i = 0;
    if (D_00370DA4 > 0) {
        do {
            func_00273C20(i, 1);
            i++;
        } while (i < D_00370DA4);
    }
}

extern "C" void func_00273CB8(int a, int b, int c, int d, int e) {
    func_00273600(a, b, 0, 0, c, 1, d, e, 0.0f);
}

INCLUDE_ASM("asm/nonmatchings/game/t_273498", func_00273CF0);

INCLUDE_ASM("asm/nonmatchings/game/t_273498", func_00273CF8);

INCLUDE_ASM("asm/nonmatchings/game/t_273498", func_00273D80);

extern "C" int func_00273D88(void) {
    int x = D_00370DB8_D->unk8;
    if (x == 1 || x == 2 || x == 4 || x == 3) {
        return 4;
    }
    if (x == 5) {
        return 2;
    }
    if (x == 0) {
        return 16;
    }
    int r = 16;
    if (x != 6) {
        r = 1;
    }
    return r;
}

struct S273DE8_V {
    char pad0[8];
    int unk8;
    int unkC;
    int *unk10;
};

INCLUDE_ASM("asm/nonmatchings/game/t_273498", func_00273DE8);

INCLUDE_ASM("asm/nonmatchings/game/t_273498", func_00273EB0);

extern "C" void func_00273F08(int a, int b) {
    if (b == 1) {
        func_00271A98(0x130, a, 0, 0, 0, 0);
    } else {
        func_00271A98(0x150, a, 0, 0, 0, 0);
    }
}

INCLUDE_ASM("asm/nonmatchings/game/t_273498", func_00273F68);

INCLUDE_ASM("asm/nonmatchings/game/t_273498", func_00273F78);

extern "C" int func_00274178(int a, int i) {
    int p = D_003A90C0[i].unk104;
    if (p == 0) {
        return 0;
    }
    return func_00120F78(a, p) != 0;
}

INCLUDE_ASM("asm/nonmatchings/game/t_273498", func_002741B8);

INCLUDE_ASM("asm/nonmatchings/game/t_273498", func_002741F0);

extern "C" int func_002741F8(int a, int i) {
    int p = D_003A90C0[i].unk104;
    if (p == 0) {
        return 0;
    }
    S273498_B *r = func_001210C8(a, p);
    if (r != 0) {
        return r->unk8;
    }
    return 0;
}

struct S274240 {
    char pad0[0x100];
    int unk100;
    int unk104;
};
extern char D_00358D18[];
extern "C" int func_00121240(int, int, int, int);
extern "C" int func_00273F78(int);
extern "C" void func_0030B550(void *, char *, int);
extern "C" void func_0011A470(int);

extern "C" int func_00274240(void *pp, int b, int c, int d) {
    S274240 *p = (S274240 *)pp;
    if (p->unk104) {
        func_0011A470(p->unk104);
        p->unk104 = 0;
    }
    p->unk104 = func_00121240(b, 0, c, d);
    if (p->unk104 == 0) return 0;
    if (D_00368748[0]) {
        p->unk100 = func_00273F78(b);
        if (p->unk100 == 0) {
            func_0011A470(p->unk104);
            p->unk104 = 0;
            return 0;
        }
    } else {
        func_0030B550(p, D_00358D18, b);
    }
    return p->unk104 != 0;
}

INCLUDE_ASM("asm/nonmatchings/game/t_273498", func_00274308);

extern "C" int func_00274310(void) {
    S273498_C buf;
    memset(&buf, 0, sizeof(buf));
    func_002EE560(func_002EE550(), &buf);
    return buf.unk18;
}

INCLUDE_ASM("asm/nonmatchings/game/t_273498", func_00274350);

extern "C" int func_00274688(void) {
    if (func_00274BF8()) {
        func_002746E8(D_00370E44 + 0x6F1600, D_00370E44 + 0x6A1580, D_00370E44 + 0x6F15C0);
    }
    func_00274F08();
    return D_00372ED4[0];
}

INCLUDE_ASM("asm/nonmatchings/game/t_273498", func_002746E8);

extern "C" void func_00274AB8(void) {
    func_002EE510(1);
}

GP_DATA(D_00370E38);
extern "C" int func_00274AD8(void) {
    if (D_00370E38 == 0) {
        return 1;
    }
    return func_002E9140();
}

extern char D_00358EE0[];
extern char D_00358EF8[];
extern "C" int func_00116E70(void);
extern "C" void func_0030B550_4(void *, char *, int, int) asm("func_0030B550");
extern "C" unsigned int strlen(const char *);

extern "C" void func_00274B08(char *dst, int n) {
    if (D_00368748[0]) {
        unsigned int i;
        func_0030B550_4(dst, D_00358EE0, func_00116E70(), n);
        for (i = 7; i < strlen(dst); i++) {
            u8 c = dst[i];
            if ((u8)(c - 'a') < 26) {
                dst[i] = c - 0x20;
            } else if ((char)c == '/') {
                dst[i] = '\\';
            }
        }
    } else {
        func_0030B550(dst, D_00358EF8, n);
    }
}

INCLUDE_ASM("asm/nonmatchings/game/t_273498", func_00274BF8);

GP_DATA(D_00370E44);
INCLUDE_ASM("asm/nonmatchings/game/t_273498", func_00274F08);

INCLUDE_ASM("asm/nonmatchings/game/t_273498", func_00275010);

extern "C" int func_00275038(void) {
    int r = 0;
    if (D_00370E38 != 0) {
        r = func_002E91E8();
        func_002EA5F0();
    }
    return r;
}

INCLUDE_ASM("asm/nonmatchings/game/t_273498", func_00275078);

extern "C" void func_00275080(void) {
    func_00274350();
}

GP_DATA(D_00370EE0);
GP_DATA(D_00370EE4);
extern "C" int func_002750A0(int a) {
    if (D_00370EE0 == 0 && a != 0) {
        D_00370EE0 = func_00275138(func_00113DF0(0x100, 0, 1));
    }
    D_00370EE4++;
    return D_00370EE0;
}

extern "C" void func_002750F0(void) {
    if ((u32)D_00370EE4 >= 2) {
        D_00370EE4--;
    } else {
        if (D_00370EE0 != 0) {
            func_00275180(D_00370EE0, 3);
        }
        D_00370EE0 = 0;
        D_00370EE4 = 0;
    }
}

struct S275138 {
    char pad0[4];
    int unk4;
    char pad8[0xE4];
    int unkEC;
    int unkF0;
};
extern "C" int func_00275138(int ip) {
    S275138 *p = (S275138 *)ip;
    func_001145D8((char *)p + 0x8);
    func_001145D8((char *)p + 0x54);
    func_001145D8((char *)p + 0xA0);
    p->unkEC = 0;
    p->unkF0 = 0;
    p->unk4 = 0;
    return ip;
}

extern "C" void func_00275180(int a, int b) {
    func_00114660((char *)a + 0xA0, 2);
    func_00114660((char *)a + 0x54, 2);
    func_00114660((char *)a + 0x8, 2);
    if (b & 1) {
        Heap_Free(D_00368A38, (void *)a);
    }
}

INCLUDE_ASM("asm/nonmatchings/game/t_273498", func_002751E8);
