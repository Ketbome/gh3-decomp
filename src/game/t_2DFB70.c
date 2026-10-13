// cflags: -O0 -fno-opt-stack
#include "common.h"

struct S3F50 {
    int unk0;
    unsigned char unk4, unk5, unk6, unk7, unk8, unk9;
    char pad0[2];
    int unkC;
    unsigned char unk10, unk11, unk12, unk13, unk14;
    char pad1;
    unsigned short unk16;
    int unk18, unk1C, unk20, unk24, unk28, unk2C, unk30, unk34, unk38, unk3C;
    unsigned short unk40;
    char unk42, unk43, unk44;
    char pad2[3];
    int unk48;
};

struct S43A8 {
    int unk0;
    unsigned char unk4;
    char pad0[3];
    int unk8, unkC;
    unsigned char unk10, unk11;
    char pad1[2];
    int unk14;
    int a18[9], a3C[9], a60[9], a84[9];
    int unkA8, unkAC;
};

struct S4670 {
    int unk0, unk4, unk8, unkC, unk10, unk14;
};

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
extern unsigned char D_00330BD8[];
extern char D_00330C08[];
extern short D_00330C38[];
extern short D_00330C98[];
extern int D_00330CF8[];
extern int D_00372720;
extern int D_00372730;
extern short D_003727E0[];
extern short D_003727E8[];
extern unsigned char D_00372818;
extern int D_003731F0;
extern int D_003EA400;
extern char D_003EA600[];


extern int D_003EACC0;
extern int D_003EAD64;
extern int D_00428794;
extern int D_00428798;
int func_002E0CD0();
int func_002E0DA8();
void func_002E4DD8();
void func_002E4EF8();
extern unsigned short D_00330820[];
extern int D_00372758;
extern int D_003727CC;
extern int D_00373208;
int func_002E56E8();
void func_002E53B8();
extern int D_003726F0;
int func_002E4FD0();
int func_002F2170();
void func_002F2400();
extern char D_00372844;
extern int D_00372848;
extern int D_0037284C;
extern int D_00372850;
extern int D_003726F4;
extern int D_003726F8;
extern char D_003EADC0[];
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
extern int D_00372734;
extern char D_003727DA;
extern int D_00372738;
extern char D_003727D9;
extern int D_00372784;
extern int D_00372788;
extern int D_0037278C;
extern int D_00372790;
extern int D_00372794;
extern int D_00372798;
extern int D_00372810;
extern int D_00372754;
extern unsigned char D_003727A0;
extern int D_003731F4;
extern int D_00373204;
extern unsigned char D_003731FC;
extern unsigned char D_003731F8;
extern int D_00373200;
extern int D_003EA8B8[];
extern int D_003EA890[];
extern int D_003EA868[];
extern int D_003EA840[];
extern unsigned int D_00330AF0[];
extern char D_003727D8;
extern unsigned int D_00372820;
extern unsigned int D_00372824;
int func_002F1750();
extern short *D_003726E4;
extern int D_003726DC;
extern int D_00372700;
extern int D_00372838;
extern short D_00427F80[];
extern short D_00428380[];
extern int D_00330BB0[];
extern int D_00372760;
extern int D_00372764;
extern int D_00372768[];
extern int D_0037279C;
extern unsigned char D_00372740;
extern unsigned char D_0037273C;
extern unsigned char D_00372780;
extern unsigned char D_00372781;
extern unsigned char D_00372782;
extern int D_003727AC;
extern int D_003727B0;
extern int D_003727C8;
extern short D_003307C0[];
extern unsigned int D_003EA540[];
extern int D_003EA8E0[];
extern int D_003EA9A0[];
extern unsigned char D_003EA660[];
extern unsigned char D_003EA6C0[];
extern unsigned char D_003EA690[];
extern int D_003EA480[];
extern int D_003EA780[];
extern unsigned char D_003EA6F0[];
extern unsigned short D_003EA720[];
extern int D_003EAA60[];
void func_002EE8E0();
int func_002EEA00();
int func_002EEA20();
extern int D_00372840;
extern unsigned int D_003733D4;
int func_002E4590();
unsigned char func_002E4548();
void func_002E5E28();
extern int D_00372770[];
extern int D_00372778[];
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

GP_DATA(D_00372820);
int func_002E2FB0(int a, int b) {
    int i;

    if (a < 0 || a >= 0x30) {
        return -2;
    }
    if (b < a || b >= 0x30) {
        return -3;
    }
    i = a;
    while (i <= b) {
        if (D_00330BD8[i] == 0) {
            if (i < 0x18 ? (int)((long)D_00372820 >> i & 1) : (int)((long)D_00372824 >> (i - 0x18) & 1)) {
                D_00330BD8[i] = 3;
                return i;
            }
        }
        i++;
    }
    return -1;
}

int func_002E3140(int a) {
    if (a < 0 || a >= 0x30) {
        return -1;
    }
    if ((a < 0x18 ? (int)((long)D_00372820 >> a & 1) : (int)((long)D_00372824 >> (a - 0x18) & 1)) == 0) {
        return -1;
    }
    return D_00330BD8[a];
}
TEXT_PAD(24);

GP_DATA(D_003726E4);
GP_DATA(D_003726DC);
GP_DATA(D_00372700);
GP_DATA(D_00372838);
int func_002E3248(int a) {
    int ret;
    int r;

    if (a == 0) {
        while (func_002E5758() == 1) {
        }
    } else if (func_002E5758() == 1) {
        return -1;
    }
    r = func_002F1750(D_003EAD40);
    if (r != 0) {
        return -1;
    }
    if (D_003727A8 == 0) {
        func_002E1518(-1, 0);
    }
    D_003727A8 = 0;
    D_003726E0[0] = 0x49;
    D_003726E0[1] = (unsigned short)D_003727F8;
    if (D_003726E0 == D_00427F80) {
        D_003726E0 = D_00428380;
        D_003726E4 = D_00427F80;
    } else {
        D_003726E0 = D_00427F80;
        D_003726E4 = D_00428380;
    }
    if (D_003726D8 > D_003726DC) {
        D_003726DC = D_003726D8;
    }
    D_00372700 = 1;
    if (D_00372838 == 1) {
        D_00372838 = 2;
    }
    func_002DFEB0(0, (int)D_003726E4, a);
    ret = D_003726D8;
    D_003726D8 = 0;
    D_003727F8 = 0;
    return ret;
}

GP_DATA(D_00372768);
GP_DATA(D_00372770);
GP_DATA(D_00372760);
GP_DATA(D_00372778);
int func_002E33F0(int a, int b, int c, int d, int e, int f) {
    int o;

    if (a >= 2 || a < 0) {
        return -1;
    } else if (b >= 0xA) {
        return -1;
    }
    o = 1 - a;
    if (D_00372768[o] == 0) {
        D_00372770[a] = D_00372760;
    } else if (D_00372770[o] == D_00372760) {
        D_00372770[a] = D_00372764;
    } else {
        D_00372770[a] = D_00372760;
    }
    D_00372768[a] = b;
    D_00372778[a] = D_00330BB0[b];
    func_002DFF28(0x13);
    func_002E00C8((short)a);
    func_002E00C8((short)b);
    func_002E00C8((short)c);
    func_002E00C8((short)d);
    func_002E00C8((short)e);
    func_002E00C8((short)f);
    func_002DFF78();
    return 0;
}

void func_002E3610(int a) {
    func_002DFF28(0x18);
    func_002E00C8((short)a);
    func_002DFF78();
}

void func_002E3660(int a) {
    func_002DFF28(0x19);
    func_002E00C8((short)a);
    func_002DFF78();
}

void func_002E36B0(int a) {
    func_002DFF28(0x17);
    func_002E00C8((short)a);
    func_002DFF78();
}

void func_002E3700(int a, int b) {
    func_002DFF28(0x1C);
    func_002E0140(a);
    func_002E0140(b);
    func_002DFF78();
    func_002E5E28(a, b);
}

unsigned int func_002E3770(int a) {
    return (unsigned)(a * 4096) / 48000;
}

unsigned char func_002E37B8(char *a) {
    unsigned char r;

    r = func_002E4548();
    func_002DFF28(0x1D);
    func_002E00C8(r);
    func_002E01E8(a);
    func_002DFF78();
    return r;
}

int func_002E3830(int a, int b, int c, int d, int e) {
    if (a == -1) {
        a = func_002E4590();
    }
    if (a < 0) {
        return a;
    }
    func_002DFF28(0x1E);
    func_002E0140(a);
    func_002E0140(b);
    func_002E0140(c);
    func_002E00C8((short)d);
    func_002E0140(e);
    func_002DFF78();
    return a;
}

int func_002E3908(int a, char *b, int c) {
    if (a == -1) {
        a = func_002E4590();
    }
    if (a < 0) {
        return a;
    }
    func_002DFF28(0x1F);
    func_002E0140(a);
    func_002E0140(c);
    func_002E01E8(b);
    func_002DFF78();
    return a;
}
TEXT_PAD(12);

int func_002E39C8(int a) {
    if (a < 0 || a >= D_0037281C) {
        return -1;
    }
    if (D_0037280C[a] != 1) {
        return -2;
    }
    D_0037280C[a] = 0;
    D_00372814 -= 1;
    func_002DFF28(0x20);
    func_002E0140(a);
    func_002DFF78();
    return 0;
}
TEXT_PAD(24);

void func_002E3AC0(void) {
    func_002DFF28(0x27);
    func_002DFF78();
}
TEXT_PAD(12);

void func_002E3B08(int a, int b, int c) {
    func_002DFF28(0x29);
    func_002E0140(a);
    func_002E0140(b);
    func_002E0140(c);
    func_002DFF78();
}

void func_002E3B78(int a) {
    func_002DFF28(0x2A);
    func_002E00C8((short)a);
    func_002DFF78();
}

void func_002E3BC8(void) {
    func_002DFF28(0x2A);
    func_002E00C8(6);
    func_002DFF78();
}
TEXT_PAD(24);

int func_002E3C28(unsigned int a) {
    int r;

    if (a >= 0x30) {
        return -2;
    }
    r = D_00330C08[a];
    if (r == 0xFF) {
        r = -1;
    }
    return r;
}
TEXT_PAD(48);

GP_DATA(D_00372840);
int func_002E3CD8(int a, int b, unsigned int c, int d) {
    int v[4];

    if (d != 1 && d != 0) {
        return -1;
    }
    if (c > 0xFFFFF) {
        return -1;
    }
    func_002EE8E0(0);
    if (D_00372840 != 0) {
        while (func_002EEA00(D_003733D4) >= 0) {
        }
    }
    D_00372840 = 1;
    func_002EE8E0(0);
    v[0] = a;
    v[1] = b;
    v[2] = c;
    v[3] = 0;
    if ((D_003733D4 = func_002EEA20(v, 1)) == 0) {
        D_00372840 = 0;
        return -1;
    }
    if (d == 1) {
        while (func_002EEA00(D_003733D4) >= 0) {
        }
    }
    return 0;
}

int func_002E3E50(int a) {
    if (a >= D_003727A4) {
        return -1;
    }
    func_002DFF28(0x2e);
    func_002E00C8((short)a);
    func_002DFF78();
    return 0;
}

int func_002E3ED0(int a) {
    if (a >= D_003727A4) {
        return -1;
    }
    func_002DFF28(0x2f);
    func_002E00C8((short)a);
    func_002DFF78();
    return 0;
}

GP_DATA(D_0037279C);
GP_DATA(D_00372740);
GP_DATA(D_0037273C);
GP_DATA(D_00372780);
GP_DATA(D_00372782);
GP_DATA(D_00372781);
GP_DATA(D_003727AC);
GP_DATA(D_003727B0);
GP_DATA(D_003727C8);
int func_002E3F50(int a, struct S3F50 *s) {
    unsigned int t;

    s->unk0 = D_0037279C;
    s->unk9 = D_00372740;
    s->unk7 = D_0037273C;
    s->unk8 = D_0037272C;
    s->unk4 = D_00372780;
    s->unk5 = D_00372782;
    s->unk6 = D_00372781;
    s->unk2C = D_003727AC;
    s->unk30 = D_003727B0;
    s->unk3C = D_003727C8;
    if (a >= D_003727A4) {
        return -1;
    }
    if (D_003EA600[a] == 0 || D_003EA600[a] == 3) {
        s->unk11 = 0;
        s->unk20 = 0;
        s->unk42 = 0;
        s->unk43 = 0;
        s->unk44 = 0;
        s->unk48 = 0;
    } else if (D_003EA600[a] == 2 || D_003EA600[a] == 5) {
        s->unk11 = 6;
        s->unk20 = 0;
        s->unk42 = 0;
        s->unk43 = 0;
        s->unk44 = 0;
        s->unk48 = 0;
    } else {
        s->unk11 = 1;
        s->unk20 = D_003307C0[a];
        t = D_003EA540[a];
        s->unk42 = t % 60;
        s->unk43 = (t / 60) % 60;
        s->unk44 = (t / 3600) % 60;
        s->unk48 = (t / 216000) & 0xFF;
    }
    s->unk40 = D_00330820[a] & 0x7FFF;
    s->unk38 = D_003EA8E0[a];
    s->unkC = D_003EA9A0[a];
    s->unk10 = D_003EA660[a];
    s->unk12 = D_003EA6C0[a];
    s->unk13 = D_003EA690[a];
    s->unk18 = D_003EA480[a];
    s->unk1C = D_003EA780[a];
    s->unk24 = D_003EA780[a];
    s->unk14 = D_003EA6F0[a];
    s->unk16 = D_003EA720[a];
    s->unk34 = D_003EAA60[a];
    s->unk28 = D_003EAB20[a];
    return 0;
}

GP_DATA(D_00372754);
GP_DATA(D_003727A0);
void func_002E43A8(struct S43A8 *s) {
    int i;

    s->unk0 = D_00372754;
    s->unk4 = D_003727A0;
    s->unk8 = D_003731F4;
    s->unkC = D_00373204;
    s->unk10 = D_003731FC;
    s->unk11 = D_003731F8;
    s->unk14 = D_00373200;
    for (i = 0; i < 9; i++) {
        s->a18[i] = D_003EA8B8[i];
        s->a3C[i] = D_003EA890[i];
        s->a60[i] = D_003EA868[i];
        s->a84[i] = D_003EA840[i];
    }
}

unsigned char func_002E4548(void) {
    unsigned char r;

    r = D_00372818;
    D_00372818 += 1;
    return r;
}

GP_DATA(D_00372810);
int func_002E4590(void) {
    int i;

    for (i = 1; i < D_0037281C; i++) {
        if (D_0037280C[i] == 0) {
            D_0037280C[i] = 1;
            if (D_00372810 < ++D_00372814) {
                D_00372810 = D_00372814;
            }
            return i;
        }
    }
    return -1;
}

GP_DATA(D_00372784);
GP_DATA(D_00372788);
GP_DATA(D_0037278C);
GP_DATA(D_00372794);
GP_DATA(D_00372798);
GP_DATA(D_00372790);
unsigned char func_002E4670(struct S4670 *s) {
    s->unk0 = D_00372784;
    s->unk4 = D_00372788;
    s->unk8 = D_0037278C;
    s->unk10 = D_00372794;
    s->unk14 = D_00372798;
    s->unkC = D_00372790;
    return D_00372790;
}

GP_DATA(D_003727D9);
GP_DATA(D_00372738);
void func_002E46F0(int a) {
    D_003727D9 = 1;
    D_00372738 = a;
    func_002DFF28(0x31);
    func_002E0140(a);
    func_002DFF78();
}

GP_DATA(D_003727DA);
GP_DATA(D_00372734);
void func_002E4750(int a) {
    D_003727DA = 1;
    D_00372734 = a;
    func_002DFF28(0x32);
    func_002E0140(a);
    func_002DFF78();
}
TEXT_PAD(12);

void func_002E47B8(void) {
    func_002DFF28(0x35);
    func_002DFF78();
}

void func_002E47F8(void) {
    func_002DFF28(0x37);
    func_002DFF78();
}
TEXT_PAD(28);

GP_DATA(D_00372850);
GP_DATA(D_003726F8);
GP_DATA(D_0037284C);
GP_DATA(D_00372844);
GP_DATA(D_00372848);
GP_DATA(D_003726F4);
int func_002E4850(void) {
    int a = -1;
    int b = 0;
    int c = 0;

    if (D_00372850 != D_003726F8) {
    }
    if (D_00372780 == 1) {
        if (D_0037284C == 0) {
        }
        D_0037284C = D_00372780;
        func_002E47F8();
        while (a < 0) {
            a = func_002E3248(0);
        }
        if (D_00372782 == 0) {
            if (D_00372844 == 1) {
                c = func_002F2170(D_003EADC0, 1);
                if (c >= 0) {
                    func_002F2400(c);
                    b = 1;
                }
            } else {
                b = 1;
            }
        }
        if (b != 0 && D_00372782 == 0) {
            func_002E47B8();
            func_002E3248(0);
        }
    } else {
        D_0037284C = 0;
    }
    if (D_00372848 == 1 && D_00372781 == 0) {
    }
    D_00372848 = D_00372781;
    if (D_00372780 == 1 && D_00372782 == 0 && b == 0) {
        return -3;
    }
    if (D_00372780 == 1) {
        return -1;
    }
    if (D_00372781 == 1) {
        return -2;
    }
    return D_003726F4;
}

void func_002E4A30(void) {
    func_002DFF28(0x3E);
    func_002E00C8(1);
    func_002DFF78();
}

void func_002E4A78(void) {
    func_002DFF28(0x3E);
    func_002E00C8(0);
    func_002DFF78();
}

int func_002E4AC0(int a) {
    if (a < 0 || a >= 0x30) {
        return -1;
    }
    func_002DFF28(0x3F);
    func_002E00C8((short)a);
    func_002DFF78();
    return 0;
}
TEXT_PAD(12);

int func_002E4B58(int a, int b, int c, int d) {
    int e;

    e = b & 0xFFFF0000;
    b &= 0xFFFF;
    func_002E4DD8(b, e);
    func_002E4EF8(b, (short)c, (short)d);
    c = D_0037320C;
    d = D_00373210;
    if (b < 0 || b >= 0x30) {
        return -1;
    }
    if (a < 0 || a >= D_003727A4) {
        return -2;
    }
    func_002DFF28(0x40);
    func_002E00C8((short)a);
    func_002E00C8((short)b);
    func_002E00C8((short)c);
    func_002E00C8((short)d);
    func_002DFF78();
    return 0;
}

int func_002E4CB8(int a, int b) {
    if (a < 0 || a >= D_003727A4) {
        return -1;
    }
    if (b != 0 && b != 1) {
        return -2;
    }
    func_002DFF28(0x44);
    func_002E00C8((short)a);
    func_002E00C8((short)b);
    func_002DFF78();
    return 0;
}
TEXT_PAD(84);

void func_002E4DD8(int a, int b) {
    D_00330CF8[a] = b;
}

void func_002E4E20(int a, int b) {
    a = a >> 16;
    a -= 1;
    D_0037320C = func_002E4FD0(D_003727E0[a], D_00330C38[b]);
    D_00373210 = func_002E4FD0(D_003727E8[a], D_00330C98[b]);
}

void func_002E4EF8(a, b, c)
int a;
unsigned short b;
unsigned short c;
{
    int r;

    D_00330C38[a] = b;
    D_00330C98[a] = c;
    r = D_00330CF8[a];
    if (r == 0) {
        D_0037320C = (short)b;
        D_00373210 = (short)c;
    } else {
        func_002E4E20(r, a);
    }
}

int func_002E4FD0(int a, int b) {
    int c = 0;

    if (b >= 0x4000) {
        b = 0x7FFF - b;
        c = 1;
    }
    b = (b * a) / 4096;
    if (c == 1) {
        b = 0x7FFF - b;
    }
    return b;
}
TEXT_PAD(16);

GP_DATA(D_003726F0);
void func_002E5088(void) {
    int *p;

    p = (int *)((int)&D_003EACC0 | 0x20000000);
    D_003726F0 = *p;
}

int func_002E50C8(void) {
    int *p;

    p = (int *)((int)&D_003EACC0 | 0x20000000);
    if (*p != D_003726F0) {
        D_003726F0 = *p;
        return 1;
    }
    return 0;
}

void func_002E5138(void) {
    func_002DFF28(0x49);
    func_002E0140((unsigned int)&D_003EACC0);
    func_002DFF78();
}

int func_002E5188(int a, int b) {
    struct S3F50 s;
    struct S3F50 *p;
    int r;
    unsigned int c;
    struct S43A8 t;
    struct S43A8 *q;

    c = (unsigned)(a & 0xFF00) >> 8;
    a &= 0xFF;
    if (a >= D_003727A4) {
        return -1;
    }
    p = &s;
    r = func_002E5758();
    while (r == 1) {
        r = func_002E5758();
    }
    if (b == 0) {
        func_002E5138();
    }
    func_002E1518(-1, 0);
    r = func_002E3248(0);
    func_002E5088();
    func_002E3F50(a, p);
    q = &t;
    while (p->unk11 != 0) {
        if (func_002E50C8() == 1) {
            r = func_002E56E8();
            if (r != -1 && (c == 0 || r == a)) {
                func_002E43A8(q);
                if (q->unk4 != 0x7C) {
                    if (b == 0) {
                        func_002E53B8();
                        func_002E3248(0);
                    }
                    return r + 1;
                }
                func_002E1518(r, 0);
            }
            func_002E3248(0);
            func_002E4850();
        }
        func_002E3F50(a, p);
    }
    if (b == 0) {
        func_002E53B8();
        func_002E3248(0);
    }
    return 0;
}
TEXT_PAD(8);

void func_002E53B8(void) {
    func_002DFF28(0x49);
    func_002E0140(0);
    func_002DFF78();
}
TEXT_PAD(8);

GP_DATA(D_00372758);
GP_DATA(D_003727CC);
int func_002E5408(void) {
    struct S43A8 s;
    struct S43A8 *p;

    if (D_00372744 == -1) {
        D_00373208 = -1;
        return -1;
    }
    p = &s;
    func_002E43A8(p);
    if (p->unk4 == 0x7C) {
        D_00373208 = D_00372744;
        D_003727CC = D_00372758;
        return 0;
    }
    if (D_003727CC == D_00372758) {
        return -1;
    }
    D_00373208 = D_00372744;
    D_003727CC = D_00372758;
    return 1;
}

int func_002E54D8(struct S43A8 *s) {
    func_002E43A8(s);
    if (D_00372744 == D_00373208 && D_00372758 == D_003727CC) {
        s->unkA8 = D_00373208;
        s->unkAC = D_003727CC;
        return 0;
    }
    return -1;
}
TEXT_PAD(48);

void func_002E5598(int a) {
    func_002DFF28(0x55);
    func_002E00C8((short)a);
    func_002DFF78();
}
TEXT_PAD(40);

void func_002E5610(int a, int b) {
    func_002E1518(a, b);
}
TEXT_PAD(16);

void func_002E5660(short a, short b) {
    func_002DFF28(0x5C);
    func_002E00C8(a);
    func_002E00C8(b);
    func_002DFF78();
}
TEXT_PAD(28);

int func_002E56E8(void) {
    return D_00372744;
}

int func_002E5718(void) {
    return D_00372730;
}
TEXT_PAD(16);

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
