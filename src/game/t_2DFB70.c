// cflags: -O0 -fno-opt-stack
#include "common.h"

void func_002DFF28(short);

void func_002DFF78(void);
void func_002E1BB0();
extern int D_00372808;
extern int *D_0037280C;
extern int D_00372814;
extern int D_0037281C;
int func_002F1550();
extern char D_003EAD40[];
extern char D_003E9900[];
void func_002DFE78(int);
extern int D_003727F0;
extern int D_003727F4;
int func_002E5758();
int func_002E3248();
extern int D_003726D8;
extern short *D_003726E0;
extern char D_003727A8;
extern short D_003727D0;
extern int D_003727F8;
void func_002F0D28();
int func_002F1370();
extern char D_00330BD8[];
extern char D_00330C08[];
extern short D_00330C38[];
extern short D_00330C98[];
extern int D_00330CF8[];
extern int D_00372720;
extern int D_00372730;
extern short D_003727E0[];
extern short D_003727E8[];
extern char D_00372818;
extern int D_003731F0;
extern int D_003EA400;
extern char D_003EA600[];
extern char D_003EA660[];
extern char D_003EA6C0[];
extern int D_003EACC0;
extern int D_003EAD64;
extern int D_00428794;
extern int D_00428798;
int func_002E0CD0();
int func_002E0DA8();
void func_002E4DD8();
void func_002E4EF8();
extern unsigned short D_00330820[];
extern unsigned char D_00330880[];
extern int D_003727A4;
extern int D_0037320C;
extern int D_00373210;
extern int D_003EAB20[];
extern int D_003EABE0[];
void func_002E46F0();
void func_002E4750();
void func_002E1B50();
extern int D_003308B0[];
int func_002E3C28();
extern int D_0037272C;
extern int D_00372744;
extern unsigned int D_00330970[];
extern unsigned int D_00330A30[];
extern unsigned int D_00330AF0[];
extern char D_003727D8;
int *func_002E5F38();
char *strcpy(char *, const char *);
unsigned int strlen(const char *);

GP_DATA(D_0037281C);
GP_DATA(D_0037280C);
GP_DATA(D_00372808);
GP_DATA(D_00372814);
void func_002DFB70(void) {
    int i;

    for (i = 0; i < D_0037281C; i++) {
        D_0037280C[i] = 0;
    }
    D_00372808 = 1;
    D_00372814 = 1;
}

GP_DATA(D_00372720);
GP_DATA(D_00372818);
GP_DATA(D_00372730);
GP_DATA(D_003727E0);
GP_DATA(D_003727E8);
int func_002DFBF8(void) {
    int i;

    D_003EACC0 = 0;
    D_003EA400 = 0;
    D_003731F0 = 0;
    D_00372720 = 0x28;
    D_00428794 = 0;
    D_00428798 = 0;
    D_00372808 = 1;
    D_00372818 = 0;
    D_00372730 = 0x5010;
    i = 0;
    while (i < 0x30) {
        D_003EA600[i] = 0;
        D_003EA6C0[i] = 0;
        D_003EA660[i] = 0;
        D_00330BD8[i] = 0;
        D_00330C38[i] = 0;
        D_00330C98[i] = 0;
        D_00330CF8[i] = 0;
        D_00330C08[i] = -1;
        i++;
    }
    i = 0;
    while (i < 4) {
        D_003727E0[i] = 0x1000;
        D_003727E8[i] = 0x1000;
        i++;
    }
    func_002F0D28(0);
    while (1) {
        if (func_002F1370(D_003EAD40, 0x12345, 0) < 0) {
            while (1) {
            }
        }
        i = 0x2710;
        while (--i != -1) {
        }
        if (D_003EAD64 != 0) {
            break;
        }
    }
    return 0;
}

void func_002DFE78(int a) {
    func_002E1BB0();
}

int func_002DFEB0(int a, int b, int c) {
    func_002F1550(D_003EAD40, a, c, b, 0x400, D_003E9900, 0x800, func_002DFE78, 0);
    return 0;
}

GP_DATA(D_003727F4);
GP_DATA(D_003727F0);
void func_002DFF28(short a) {
    if (D_003727F4 != -1) {
        return;
    }
    D_003727F0 = 0;
    D_003727F4 = a;
}

GP_DATA(D_003726D8);
GP_DATA(D_003727A8);
GP_DATA(D_003727D0);
GP_DATA(D_003726E0);
GP_DATA(D_003727F8);
void func_002DFF78(void) {
    int i;
    int r;

    if (D_003727F4 == -1) {
        return;
    }
    if ((unsigned)(D_003726D8 + D_003727F0 + 3) >= 0x200) {
        D_003727A8 = 1;
        r = func_002E5758();
        while (r == 1) {
            r = func_002E5758();
        }
        i = func_002E3248(0);
        D_003727A8 = 0;
        if (i == -1) {
            D_003727D0 = 1;
            return;
        } else {
        }
    }
    D_003727D0 = 0;
    D_003726E0[D_003726D8 + 2] = (unsigned short)D_003727F4;
    D_003726E0[D_003726D8 + 3] = (unsigned short)D_003727F0;
    D_003726D8 += 2;
    D_003726D8 += D_003727F0;
    D_003727F8++;
    D_003727F0 = 0;
    D_003727F4 = -1;
}

void func_002E00C8(a)
unsigned short a;
{
    if (D_003727D0 == 1) {
        return;
    }
    D_003726E0[D_003727F0++ + D_003726D8 + 4] = a;
}

void func_002E0140(unsigned int a) {
    if (D_003727D0 == 1) {
        return;
    }
    D_003726E0[D_003727F0++ + D_003726D8 + 4] = (short)(a >> 16);
    D_003726E0[D_003727F0++ + D_003726D8 + 4] = (unsigned short)a;
}

int func_002E01E8(char *s) {
    int len;
    char *p;

    if (D_003727D0 == 1) {
        return 0;
    }
    p = (char *)D_003726E0;
    p = p + (D_003727F0 + (4 + D_003726D8)) * 2;
    strcpy(p, s);
    len = strlen(s);
    p = p + len;
    *p = 0;
    len += 2;
    len = len / 2;
    D_003727F0 += len;
    return len;
}

GP_DATA(D_003727A4);
int func_002E02D8(int a, int b, int c, int d, int e, int f, int g, int h, int i) {
    int v20;
    int v24;
    int v28;

    v28 = 1;
    if (b == 0x80) {
        b = func_002E0CD0();
    } else if (b == 0x81) {
        while (1) {
            b = func_002E0DA8(v28, D_003727A4 - 1);
            if (b != -1 && D_00330880[b] == 1) {
                break;
            }
            v28 = b + 1;
            if (v28 == D_003727A4) {
                v28 = -1;
                break;
            }
        }
    } else if (b == 0x82) {
        while (1) {
            b = func_002E0DA8(v28, D_003727A4 - 1);
            if (b != -1 && D_00330880[b] == 0) {
                break;
            }
            v28 = b + 1;
            if (v28 == D_003727A4) {
                v28 = -1;
                break;
            }
        }
    }
    if (b < 0) {
        return -1;
    }
    if (b >= D_003727A4) {
        return -1;
    }
    D_003EA600[b] = 2;
    D_00330820[b] = 0x8080;
    D_003EA6C0[b] = 0;
    v24 = c & 0xFFFF0000;
    c = c & 0xFFFF;
    if (c < 0 || c >= 0x30) {
        return -1;
    }
    if (g == 1 || g == 0) {
        D_00330BD8[c] = 3;
        func_002E4DD8(c, v24);
        func_002E4EF8(c, (short)d, (short)e);
        d = D_0037320C;
        e = D_00373210;
    }
    D_00330C08[c] = (unsigned char)b;
    v20 = h;
    v20 += i << 8;
    c += b << 8;
    if (g == 0x7E) {
        D_003EAB20[b] = 0;
    }
    D_003EABE0[b] = 0;
    func_002DFF28(1);
    func_002E0140(a);
    func_002E00C8((short)c);
    func_002E00C8((short)d);
    func_002E00C8((short)e);
    func_002E00C8((short)f);
    func_002E00C8((short)g);
    func_002E00C8((short)v20);
    func_002DFF78();
    return b;
}

int func_002E0718(int a, int b, int c, int d, int e, int f, int g, int h, int i, int j, int k, int l) {
    int v20;
    int v24;
    int v28;

    v28 = 1;
    if (b == 0x80) {
        b = func_002E0CD0();
    } else if (b == 0x81) {
        while (1) {
            b = func_002E0DA8(v28, D_003727A4 - 1);
            if (b != -1 && D_00330880[b] == 1) {
                break;
            }
            v28 = b + 1;
            if (v28 == D_003727A4) {
                v28 = -1;
                break;
            }
        }
    } else if (b == 0x82) {
        while (1) {
            b = func_002E0DA8(v28, D_003727A4 - 1);
            if (b != -1 && D_00330880[b] == 0) {
                break;
            }
            v28 = b + 1;
            if (v28 == D_003727A4) {
                v28 = -1;
                break;
            }
        }
    }
    if (b < 0) {
        return -1;
    }
    if (b >= D_003727A4) {
        return -1;
    }
    D_003EA600[b] = 2;
    D_00330820[b] = 0x8080;
    D_003EA6C0[b] = 0;
    v24 = c & 0xFFFF0000;
    c = c & 0xFFFF;
    if (c < 0 || c >= 0x30) {
        return -1;
    }
    if (g == 1 || g == 0) {
        D_00330BD8[c] = 3;
        func_002E4DD8(c, v24);
        func_002E4EF8(c, (short)d, (short)e);
        d = D_0037320C;
        e = D_00373210;
    }
    D_00330C08[c] = (unsigned char)b;
    v20 = h;
    v20 += i << 8;
    c += b << 8;
    if (g == 0x7E) {
        D_003EAB20[b] = 0;
    }
    func_002DFF28(0x74);
    func_002E0140(a);
    func_002E0140(j);
    func_002E0140(k);
    func_002E0140(l);
    func_002E00C8((short)c);
    func_002E00C8((short)d);
    func_002E00C8((short)e);
    func_002E00C8((short)f);
    func_002E00C8((short)g);
    func_002E00C8((short)v20);
    func_002DFF78();
    return b;
}

int func_002E0B60(int a, int b, int c, int d) {
    int r;

    if (a != 0x7E && a != 0x7B && a != 0x7D && a != 0x7F && a != 0x7F) {
        return -2;
    }
    if (d != 0) {
        if (a == 0x7E) {
            func_002E46F0(d);
        } else if (a == 0x7F || a == 0x7F) {
            func_002E1B50(d);
        } else if (a == 0x7D) {
            func_002E4750(d);
        }
    }
    r = func_002E02D8(c, b, 0, 0, 0, 0, a, 0, 0);
    return r;
}
TEXT_PAD(20);

int func_002E0CD0(void) {
    int i;

    for (i = 0; i < D_003727A4; i++) {
        if (D_003EA600[i] == 0 || D_003EA600[i] == 3) {
            D_003EA600[i] = 7;
            return i;
        }
    }
    return -1;
}

int func_002E0DA8(int a, int b) {
    int i = 0;

    if (b >= D_003727A4) {
        return -1;
    }
    i = a;
    while (i <= b) {
        if (D_003EA600[i] == 0 || D_003EA600[i] == 3) {
            return i;
        }
        i++;
    }
    return -1;
}

int func_002E0E90(int a, int b, int c, int d, int e, int f, int g) {
    int v1C;
    int v20;

    v20 = b & 0xFFFF0000;
    b &= 0xFFFF;
    if (b < 0 || b >= 0x30) {
        return -1;
    }
    D_00330BD8[b] = 3;
    v1C = f;
    v1C += g << 8;
    D_003308B0[b] = a;
    func_002E4DD8(b, v20);
    func_002E4EF8(b, (short)c, (short)d);
    func_002DFF28(0);
    func_002E0140(a);
    func_002E00C8((short)b);
    func_002E00C8((short)D_0037320C);
    func_002E00C8((short)D_00373210);
    func_002E00C8((short)e);
    func_002E00C8((short)v1C);
    func_002DFF78();
    return 0;
}

int func_002E1028(int a, int b, int c, int d, int e, int f, int g, unsigned int h) {
    int v20;
    int v24;

    v24 = b & 0xFFFF0000;
    b &= 0xFFFF;
    if (b < 0 || b >= 0x30) {
        return -1;
    }
    if (h > 0xFFFF) {
        return -2;
    }
    D_00330BD8[b] = 3;
    v20 = f;
    v20 += g << 8;
    D_003308B0[b] = a;
    func_002E4DD8(b, v24);
    func_002E4EF8(b, (short)c, (short)d);
    func_002DFF28(0x39);
    func_002E0140(a);
    func_002E00C8((short)b);
    func_002E00C8((short)D_0037320C);
    func_002E00C8((short)D_00373210);
    func_002E00C8((short)e);
    func_002E00C8((short)v20);
    func_002E00C8((short)h);
    func_002DFF78();
    return 0;
}

int func_002E11F0(int a, int b, int c) {
    a &= 0xFFFF;
    if (a < 0 || a >= 0x30) {
        return -1;
    }
    func_002E4EF8(a, (short)b, (short)c);
    func_002DFF28(2);
    func_002E00C8((short)a);
    func_002E00C8((short)D_0037320C);
    func_002E00C8((short)D_00373210);
    func_002DFF78();
    return 0;
}

int func_002E12D8(int a, int b) {
    if (a < 0 || a >= 0x30) {
        return -1;
    }
    func_002DFF28(3);
    func_002E0140(a);
    func_002E0140(b);
    func_002DFF78();
    return 0;
}

int func_002E1370(int a) {
    int r;

    if (a < 0) {
        return -1;
    }
    if (a >= 0x40) {
        a -= 0x40;
        r = func_002E3C28(a);
        if (r >= 0) {
            D_00330C08[a] = -1;
            D_003EA600[r] = 3;
            a = r;
        } else {
            return -1;
        }
    } else {
        D_003EA600[a] = 3;
    }
    func_002DFF28(5);
    func_002E00C8((short)a);
    func_002DFF78();
    return 0;
}

int func_002E1488(int a) {
    if (a < 0 || a >= 0x30) {
        return -1;
    }
    func_002DFF28(4);
    func_002E00C8((short)a);
    func_002DFF78();
    return 0;
}

GP_DATA(D_0037272C);
GP_DATA(D_00372744);
void func_002E1518(int a, int b) {
    if (a != -1) {
        D_0037272C = 1;
        D_00372744 = -1;
    }
    func_002DFF28(9);
    func_002E00C8((short)a);
    func_002E00C8((short)b);
    func_002DFF78();
    D_003727A8 = 1;
}
TEXT_PAD(20);

void func_002E15B8(void) {
    func_002DFF28(7);
    func_002DFF78();
}

int func_002E15F8(int a, int b, int c) {
    func_002DFF28(0xC);
    func_002E00C8((short)a);
    func_002E00C8((short)b);
    func_002E00C8((short)c);
    func_002E00C8((short)D_00372720);
    func_002DFF78();
    D_003731F0 = 1;
    D_0037281C = b;
    if (D_0037280C != 0) {
        return -1;
    }
    D_0037280C = func_002E5F38(4, D_0037281C);
    if (D_0037280C == 0) {
        return -2;
    }
    func_002DFB70();
    return 0;
}
TEXT_PAD(12);

int func_002E16F8(unsigned int a) {
    if (a >= 0x30) {
        return -1;
    }
    D_003727A4 = a;
    func_002DFF28(0x10);
    func_002E00C8((short)a);
    func_002DFF78();
    return 0;
}

int func_002E1778(int a, int b, int c) {
    if (a >= 0x30) {
        return -1;
    }
    D_00330970[a] = c;
    D_00330A30[a] = c;
    D_00330AF0[a] = c;
    if (b == 1) {
        b = 0;
        D_00330880[a] = 1;
    } else {
        D_00330880[a] = 0;
    }
    func_002DFF28(0xD);
    func_002E00C8((short)a);
    func_002E0140(b);
    func_002E0140(c);
    func_002DFF78();
    return 0;
}

int func_002E18B8(int a, unsigned int b) {
    if (a >= D_003727A4) {
        return -1;
    }
    if (b > D_00330970[a]) {
        return -1;
    }
    D_00330A30[a] = b;
    if (b < D_00330AF0[a]) {
        D_00330AF0[a] = b;
    }
    func_002DFF28(0x47);
    func_002E00C8((short)a);
    func_002E0140(b);
    func_002DFF78();
    return 0;
}

int func_002E19E8(int a, unsigned int b) {
    unsigned int c;

    if (a >= D_003727A4) {
        return -1;
    }
    if (b < 0x400 && b != 0) {
        return -2;
    }
    if (D_00330970[a] == 0) {
        return -1;
    }
    c = (b + 0x3F) & 0xFFFFFFC0;
    if (b != c) {
    }
    if (c > D_00330A30[a]) {
        return -1;
    }
    D_00330AF0[a] = c;
    func_002DFF28(0x52);
    func_002E00C8((short)a);
    func_002E0140(c);
    func_002DFF78();
    return 0;
}

GP_DATA(D_003727D8);
void func_002E1B50(int a) {
    D_003727D8 = 1;
    D_00372730 = a;
    func_002DFF28(0xE);
    func_002E0140(a);
    func_002DFF78();
}

INCLUDE_ASM("asm/nonmatchings/game/t_2DFB70", func_002E1BB0);

INCLUDE_ASM("asm/nonmatchings/game/t_2DFB70", func_002E2FB0);

INCLUDE_ASM("asm/nonmatchings/game/t_2DFB70", func_002E3140);

INCLUDE_ASM("asm/nonmatchings/game/t_2DFB70", func_002E3248);

INCLUDE_ASM("asm/nonmatchings/game/t_2DFB70", func_002E33F0);

INCLUDE_ASM("asm/nonmatchings/game/t_2DFB70", func_002E3610);

INCLUDE_ASM("asm/nonmatchings/game/t_2DFB70", func_002E3660);

INCLUDE_ASM("asm/nonmatchings/game/t_2DFB70", func_002E36B0);

INCLUDE_ASM("asm/nonmatchings/game/t_2DFB70", func_002E3700);

INCLUDE_ASM("asm/nonmatchings/game/t_2DFB70", func_002E3770);

INCLUDE_ASM("asm/nonmatchings/game/t_2DFB70", func_002E37B8);

INCLUDE_ASM("asm/nonmatchings/game/t_2DFB70", func_002E3830);

INCLUDE_ASM("asm/nonmatchings/game/t_2DFB70", func_002E3908);

INCLUDE_ASM("asm/nonmatchings/game/t_2DFB70", func_002E39C8);

INCLUDE_ASM("asm/nonmatchings/game/t_2DFB70", func_002E3AC0);

INCLUDE_ASM("asm/nonmatchings/game/t_2DFB70", func_002E3B08);

INCLUDE_ASM("asm/nonmatchings/game/t_2DFB70", func_002E3B78);

INCLUDE_ASM("asm/nonmatchings/game/t_2DFB70", func_002E3BC8);

INCLUDE_ASM("asm/nonmatchings/game/t_2DFB70", func_002E3C28);

INCLUDE_ASM("asm/nonmatchings/game/t_2DFB70", func_002E3CD8);

INCLUDE_ASM("asm/nonmatchings/game/t_2DFB70", func_002E3E50);

INCLUDE_ASM("asm/nonmatchings/game/t_2DFB70", func_002E3ED0);

INCLUDE_ASM("asm/nonmatchings/game/t_2DFB70", func_002E3F50);

INCLUDE_ASM("asm/nonmatchings/game/t_2DFB70", func_002E43A8);

INCLUDE_ASM("asm/nonmatchings/game/t_2DFB70", func_002E4548);

INCLUDE_ASM("asm/nonmatchings/game/t_2DFB70", func_002E4590);

INCLUDE_ASM("asm/nonmatchings/game/t_2DFB70", func_002E4670);

INCLUDE_ASM("asm/nonmatchings/game/t_2DFB70", func_002E46F0);

INCLUDE_ASM("asm/nonmatchings/game/t_2DFB70", func_002E4750);

INCLUDE_ASM("asm/nonmatchings/game/t_2DFB70", func_002E47B8);

INCLUDE_ASM("asm/nonmatchings/game/t_2DFB70", func_002E47F8);

INCLUDE_ASM("asm/nonmatchings/game/t_2DFB70", func_002E4850);

INCLUDE_ASM("asm/nonmatchings/game/t_2DFB70", func_002E4A30);

INCLUDE_ASM("asm/nonmatchings/game/t_2DFB70", func_002E4A78);

INCLUDE_ASM("asm/nonmatchings/game/t_2DFB70", func_002E4AC0);

INCLUDE_ASM("asm/nonmatchings/game/t_2DFB70", func_002E4B58);

INCLUDE_ASM("asm/nonmatchings/game/t_2DFB70", func_002E4CB8);

INCLUDE_ASM("asm/nonmatchings/game/t_2DFB70", func_002E4DD8);

INCLUDE_ASM("asm/nonmatchings/game/t_2DFB70", func_002E4E20);

INCLUDE_ASM("asm/nonmatchings/game/t_2DFB70", func_002E4EF8);

INCLUDE_ASM("asm/nonmatchings/game/t_2DFB70", func_002E4FD0);

INCLUDE_ASM("asm/nonmatchings/game/t_2DFB70", func_002E5088);

INCLUDE_ASM("asm/nonmatchings/game/t_2DFB70", func_002E50C8);

INCLUDE_ASM("asm/nonmatchings/game/t_2DFB70", func_002E5138);

INCLUDE_ASM("asm/nonmatchings/game/t_2DFB70", func_002E5188);

INCLUDE_ASM("asm/nonmatchings/game/t_2DFB70", func_002E53B8);

INCLUDE_ASM("asm/nonmatchings/game/t_2DFB70", func_002E5408);

INCLUDE_ASM("asm/nonmatchings/game/t_2DFB70", func_002E54D8);

INCLUDE_ASM("asm/nonmatchings/game/t_2DFB70", func_002E5598);

INCLUDE_ASM("asm/nonmatchings/game/t_2DFB70", func_002E5610);

INCLUDE_ASM("asm/nonmatchings/game/t_2DFB70", func_002E5660);

INCLUDE_ASM("asm/nonmatchings/game/t_2DFB70", func_002E56E8);

INCLUDE_ASM("asm/nonmatchings/game/t_2DFB70", func_002E5718);

INCLUDE_ASM("asm/nonmatchings/game/t_2DFB70", func_002E5758);

int func_002E5788(int a, int b) {
    if ((unsigned)a >= 0x30) {
        return -1;
    } else if ((unsigned)b >= 0x30) {
        return -2;
    } else if ((unsigned)a > (unsigned)b) {
        return -3;
    }
    func_002DFF28(0x65);
    func_002E00C8((short)a);
    func_002E00C8((short)b);
    func_002DFF78();
    return 0;
}

INCLUDE_ASM("asm/nonmatchings/game/t_2DFB70", func_002E5860);

INCLUDE_ASM("asm/nonmatchings/game/t_2DFB70", func_002E5938);

INCLUDE_ASM("asm/nonmatchings/game/t_2DFB70", func_002E59A0);

INCLUDE_ASM("asm/nonmatchings/game/t_2DFB70", func_002E5A78);

INCLUDE_ASM("asm/nonmatchings/game/t_2DFB70", func_002E5B50);

INCLUDE_ASM("asm/nonmatchings/game/t_2DFB70", func_002E5BB8);

INCLUDE_ASM("asm/nonmatchings/game/t_2DFB70", func_002E5CA8);

INCLUDE_ASM("asm/nonmatchings/game/t_2DFB70", func_002E5E28);

INCLUDE_ASM("asm/nonmatchings/game/t_2DFB70", func_002E5F38);

INCLUDE_ASM("asm/nonmatchings/game/t_2DFB70", func_002E5FF8);

INCLUDE_ASM("asm/nonmatchings/game/t_2DFB70", func_002E6108);

INCLUDE_ASM("asm/nonmatchings/game/t_2DFB70", func_002E6160);

INCLUDE_ASM("asm/nonmatchings/game/t_2DFB70", func_002E61D0);

INCLUDE_ASM("asm/nonmatchings/game/t_2DFB70", func_002E6270);
