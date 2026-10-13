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

struct S5E28 {
    int unk0;
    char pad0[8];
    int unkC;
    char unk10;
    char pad1[3];
};

int *SndDrv_Alloc();
void SndDrv_CmdBegin(short);

void SndDrv_CmdEnd(void);
void SndDrv_ParseIopState();
extern int D_00372808;
extern int *D_0037280C;
extern int D_00372814;
extern int D_0037281C;
int func_002F1550();
extern char D_003EAD40[];
extern unsigned int D_003E9900[];
void func_002DFE78(int);
extern int D_003727F0;
extern int D_003727F4;
int func_002E5758();
int SndDrv_FlushCommands();
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
extern int D_0037283C;
extern int D_00372748;
extern int D_003727D4;
extern char D_003EA630[];
extern int D_00372728;
extern int D_00372718;
extern int D_0037271C;
extern int D_0037274C;
extern int D_003726E8;
extern unsigned char D_00372750;
extern int D_003727B4;
extern int D_003727B8;
extern int D_003727BC;
extern int D_003727C0;
extern int D_003727C4;
extern int D_00330DB8[];
extern int D_003307A0[];
struct S12 {
    int unk0;
    int pad[2];
};
extern struct S12 D_003EA100[];
extern struct S12 D_003EA104[];
extern struct S12 D_003EA108[];


extern int D_003EACC0;
extern int D_003EAD64;
extern int D_00428794;
extern int D_00428798;
int func_002E0CD0();
int func_002E0DA8();
void func_002E4DD8();
void func_002E4EF8();
int *func_0030C5D0();
extern int *(*D_00372828)();
extern int D_00372830;
extern struct S5E28 *D_00372854;
extern unsigned short D_00373214;
extern unsigned short D_00330820[];
extern int D_00372758;
extern int D_003727CC;
extern int D_00373208;
int func_002E56E8();
void func_002E53B8();
extern int D_003726F0;
int SndDrv_ScaleVolume();
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
extern unsigned char D_003727DA;
extern int D_00372738;
extern unsigned char D_003727D9;
extern int D_00372784;
extern int D_00372788;
extern int D_0037278C;
extern int D_00372790;
extern int D_00372794;
extern int D_00372798;
extern int D_00372810;
extern int D_00372754;
extern int D_003727A0;
extern int D_003731F4;
extern int D_00373204;
extern int D_003731FC;
extern int D_003731F8;
extern int D_00373200;
extern int D_003EA8B8[];
extern int D_003EA890[];
extern int D_003EA868[];
extern int D_003EA840[];
extern unsigned int D_00330AF0[];
extern unsigned char D_003727D8;
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
extern int D_00372740;
extern int D_0037273C;
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
extern char D_003EA660[];
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
int func_002E5E28();
extern int D_00372770[];
extern int D_00372778[];
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
    SndDrv_ParseIopState();
}

int func_002DFEB0(int a, int b, int c) {
    func_002F1550(D_003EAD40, a, c, b, 0x400, D_003E9900, 0x800, func_002DFE78, 0);
    return 0;
}

GP_DATA(D_003727F4);
GP_DATA(D_003727F0);
void SndDrv_CmdBegin(short a) {
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
void SndDrv_CmdEnd(void) {
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
        i = SndDrv_FlushCommands(0);
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

void SndDrv_Push16(a)
unsigned short a;
{
    if (D_003727D0 == 1) {
        return;
    }
    D_003726E0[D_003727F0++ + D_003726D8 + 4] = a;
}

void SndDrv_Push32(unsigned int a) {
    if (D_003727D0 == 1) {
        return;
    }
    D_003726E0[D_003727F0++ + D_003726D8 + 4] = (short)(a >> 16);
    D_003726E0[D_003727F0++ + D_003726D8 + 4] = (unsigned short)a;
}

int SndDrv_PushString(char *s) {
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
    SndDrv_CmdBegin(1);
    SndDrv_Push32(a);
    SndDrv_Push16((short)c);
    SndDrv_Push16((short)d);
    SndDrv_Push16((short)e);
    SndDrv_Push16((short)f);
    SndDrv_Push16((short)g);
    SndDrv_Push16((short)v20);
    SndDrv_CmdEnd();
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
    SndDrv_CmdBegin(0x74);
    SndDrv_Push32(a);
    SndDrv_Push32(j);
    SndDrv_Push32(k);
    SndDrv_Push32(l);
    SndDrv_Push16((short)c);
    SndDrv_Push16((short)d);
    SndDrv_Push16((short)e);
    SndDrv_Push16((short)f);
    SndDrv_Push16((short)g);
    SndDrv_Push16((short)v20);
    SndDrv_CmdEnd();
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
    SndDrv_CmdBegin(0);
    SndDrv_Push32(a);
    SndDrv_Push16((short)b);
    SndDrv_Push16((short)D_0037320C);
    SndDrv_Push16((short)D_00373210);
    SndDrv_Push16((short)e);
    SndDrv_Push16((short)v1C);
    SndDrv_CmdEnd();
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
    SndDrv_CmdBegin(0x39);
    SndDrv_Push32(a);
    SndDrv_Push16((short)b);
    SndDrv_Push16((short)D_0037320C);
    SndDrv_Push16((short)D_00373210);
    SndDrv_Push16((short)e);
    SndDrv_Push16((short)v20);
    SndDrv_Push16((short)h);
    SndDrv_CmdEnd();
    return 0;
}

int func_002E11F0(int a, int b, int c) {
    a &= 0xFFFF;
    if (a < 0 || a >= 0x30) {
        return -1;
    }
    func_002E4EF8(a, (short)b, (short)c);
    SndDrv_CmdBegin(2);
    SndDrv_Push16((short)a);
    SndDrv_Push16((short)D_0037320C);
    SndDrv_Push16((short)D_00373210);
    SndDrv_CmdEnd();
    return 0;
}

int func_002E12D8(int a, int b) {
    if (a < 0 || a >= 0x30) {
        return -1;
    }
    SndDrv_CmdBegin(3);
    SndDrv_Push32(a);
    SndDrv_Push32(b);
    SndDrv_CmdEnd();
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
    SndDrv_CmdBegin(5);
    SndDrv_Push16((short)a);
    SndDrv_CmdEnd();
    return 0;
}

int func_002E1488(int a) {
    if (a < 0 || a >= 0x30) {
        return -1;
    }
    SndDrv_CmdBegin(4);
    SndDrv_Push16((short)a);
    SndDrv_CmdEnd();
    return 0;
}

GP_DATA(D_0037272C);
GP_DATA(D_00372744);
void func_002E1518(int a, int b) {
    if (a != -1) {
        D_0037272C = 1;
        D_00372744 = -1;
    }
    SndDrv_CmdBegin(9);
    SndDrv_Push16((short)a);
    SndDrv_Push16((short)b);
    SndDrv_CmdEnd();
    D_003727A8 = 1;
}
TEXT_PAD(20);

void func_002E15B8(void) {
    SndDrv_CmdBegin(7);
    SndDrv_CmdEnd();
}

int func_002E15F8(int a, int b, int c) {
    SndDrv_CmdBegin(0xC);
    SndDrv_Push16((short)a);
    SndDrv_Push16((short)b);
    SndDrv_Push16((short)c);
    SndDrv_Push16((short)D_00372720);
    SndDrv_CmdEnd();
    D_003731F0 = 1;
    D_0037281C = b;
    if (D_0037280C != 0) {
        return -1;
    }
    D_0037280C = SndDrv_Alloc(4, D_0037281C);
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
    SndDrv_CmdBegin(0x10);
    SndDrv_Push16((short)a);
    SndDrv_CmdEnd();
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
    SndDrv_CmdBegin(0xD);
    SndDrv_Push16((short)a);
    SndDrv_Push32(b);
    SndDrv_Push32(c);
    SndDrv_CmdEnd();
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
    SndDrv_CmdBegin(0x47);
    SndDrv_Push16((short)a);
    SndDrv_Push32(b);
    SndDrv_CmdEnd();
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
    SndDrv_CmdBegin(0x52);
    SndDrv_Push16((short)a);
    SndDrv_Push32(c);
    SndDrv_CmdEnd();
    return 0;
}

GP_DATA(D_003727D8);
void func_002E1B50(int a) {
    D_003727D8 = 1;
    D_00372730 = a;
    SndDrv_CmdBegin(0xE);
    SndDrv_Push32(a);
    SndDrv_CmdEnd();
}

GP_DATA(D_00372700);
GP_DATA(D_00372838);
GP_DATA(D_0037283C);
GP_DATA(D_0037273C);
GP_DATA(D_00372748);
GP_DATA(D_003727D4);
GP_DATA(D_00372740);
GP_DATA(D_00372728);
GP_DATA(D_00372754);
GP_DATA(D_00372758);
GP_DATA(D_0037279C);
GP_DATA(D_00372790);
GP_DATA(D_0037278C);
GP_DATA(D_00372788);
GP_DATA(D_00372784);
GP_DATA(D_003727D9);
GP_DATA(D_00372738);
GP_DATA(D_003727DA);
GP_DATA(D_00372734);
GP_DATA(D_00372780);
GP_DATA(D_00372781);
GP_DATA(D_00372782);
GP_DATA(D_003727A0);
GP_DATA(D_003727B4);
GP_DATA(D_003727AC);
GP_DATA(D_003727B0);
GP_DATA(D_003727B8);
GP_DATA(D_003727BC);
GP_DATA(D_003727C0);
GP_DATA(D_003727C4);
GP_DATA(D_003727C8);
GP_DATA(D_00372718);
GP_DATA(D_0037274C);
GP_DATA(D_003726E8);
GP_DATA(D_00372750);
GP_DATA(D_003726F4);
GP_DATA(D_003726F8);
GP_DATA(D_00372794);
GP_DATA(D_00372798);
void SndDrv_ParseIopState(void) {
    int i;
    int w;
    int a;
    int b;
    unsigned char q;
    int cnt;
    unsigned char p;
    int off;

    D_00372700 = 0;
    if (D_00372838 == 2) {
        D_00372838 = 0;
        D_0037283C = 0;
    }
    D_0037273C = 0;
    cnt = D_003E9900[0] & 0xFF;
    off = cnt * 9;
    D_00372748 = D_003E9900[off + 1];
    if (D_00372748 == D_003727D4) {
        return;
    }
    D_003727D4 = D_00372748;
    for (i = 0; i < 0x30; i++) {
        if (D_003EA600[i] == 5) {
            D_003EA630[i]--;
            if (D_003EA630[i] == 0) {
                D_003EA600[i] = 0;
            }
        }
        if (D_003EA600[i] == 1) {
            D_003EA630[i] = 3;
            D_003EA600[i] = 0;
        } else if (D_003EA600[i] == 2) {
            D_003EA600[i] = 5;
        }
        D_00330C08[i] = -1;
    }
    off = 0;
    i = 0;
    while (i < cnt) {
        w = D_003E9900[off + 1];
        p = (w >> 4) & 0x3F;
        if (D_003EA600[p] != 3) {
            D_003EA600[p] = 1;
        } else {
            D_003EA600[p] = 4;
        }
        q = (w >> 10) & 0x3F;
        D_003EA6F0[p] = (w >> 2) & 3;
        if (w & 3) {
            D_0037273C = w & 3;
            D_00372740 = p;
        }
        D_003EA720[p] = (w >> 16) & 0xFFFFFFFFL;
        D_003EA780[p] = D_003E9900[off + 2] & 0xFFFFFF;
        D_003EA480[p] = D_003E9900[off + 3];
        D_003EA660[p] = D_003E9900[off + 4];
        D_003EA6C0[p] = (D_003E9900[off + 4] >> 31) & 1;
        if (D_003EA660[p] == 0) {
            D_00330C08[D_003EA690[p]] = p;
        }
        D_003EA690[p] = q;
        D_003EA9A0[p] = D_003E9900[off + 5];
        D_003EAA60[p] = D_003E9900[off + 6];
        if (D_003EA600[p] == 1) {
            D_003EAB20[p] = D_003E9900[off + 7];
        } else {
            D_003EAB20[p] = 0;
        }
        a = (short)D_003E9900[off + 8];
        D_003307C0[p] = (a & 0xFFFF) & 0xFFFFFFFFL;
        a = D_003E9900[off + 8];
        a = a >> 16;
        a &= 0xFFFF;
        if (((D_00330820[p] & 0x8000) & 0xFFFF) == 0) {
            D_00330820[p] = a;
        } else {
            D_00330820[p] = D_00330820[p] & 0x7FFF;
        }
        D_003EABE0[p] = D_003E9900[off + 9];
        off += 9;
        i++;
    }
    i = 0;
    while (i < 0x30) {
        if (D_003EA600[i] == 4) {
            D_003EA600[i] = 3;
        } else if (D_003EA600[i] == 3) {
            D_003EA600[i] = 0;
        }
        i++;
    }
    D_00372744 = D_003E9900[off + 2];
    D_0037272C = D_003E9900[off + 3];
    if (D_003727D8 == 0) {
        D_00372730 = D_003E9900[off + 4];
    } else {
        D_003727D8 = 0;
    }
    D_00372728 = D_003E9900[off + 5];
    i = 0;
    while (i < 3) {
        a = 0;
        while (a < 0x10) {
            b = D_003E9900[i + (6 + off)];
            b = b >> (0x1E - a * 2);
            b = b & 3;
            if (b == 0 && D_00330BD8[i * 16 + a] == 3) {
                D_00330BD8[i * 16 + a] = 4;
            } else if (b == 0 && D_00330BD8[i * 16 + a] == 4) {
                D_00330BD8[i * 16 + a] = 0;
            } else {
                D_00330BD8[i * 16 + a] = b;
            }
            a++;
        }
        i++;
    }
    D_00372754 = D_003E9900[off + 9];
    D_003731F4 = D_003E9900[off + 0xA];
    D_00372758 = D_003E9900[off + 0xB];
    w = off + 0xC;
    i = 0;
    while (i < 9) {
        D_003EA840[i] = D_003E9900[w + i];
        D_003EA868[i] = D_003E9900[w + i + 9];
        D_003EA8B8[i] = D_003E9900[w + i + 0x12];
        D_003EA890[i] = D_003E9900[w + i + 0x1B];
        i++;
    }
    w = w + 0x24;
    D_003731F8 = D_003E9900[w];
    D_003731FC = D_003E9900[w + 1];
    D_0037279C = D_003E9900[w + 2];
    D_00372790 = (int)D_003E9900[w + 3] >> 8;
    D_0037278C = D_003E9900[w + 3] & 0xFF;
    D_00372788 = D_003E9900[w + 4];
    D_00372784 = D_003E9900[w + 5];
    D_00373200 = D_003E9900[w + 6];
    D_00373204 = D_003E9900[w + 7];
    if (D_003727D9 == 0) {
        D_00372738 = D_003E9900[w + 8];
    } else {
        D_003727D9 = 0;
    }
    if (D_003727DA == 0) {
        D_00372734 = D_003E9900[w + 9];
    } else {
        D_003727DA = 0;
    }
    D_00372780 = D_003E9900[w + 0xA] & 1;
    D_00372781 = (D_003E9900[w + 0xA] >> 1) & 1;
    D_00372782 = (D_003E9900[w + 0xA] >> 2) & 1;
    D_003727A0 = D_003E9900[w + 0xB];
    D_003727B4 = D_003E9900[w + 0xC];
    D_003727AC = D_003E9900[w + 0xD];
    D_003727B0 = D_003E9900[w + 0xE];
    D_003727B8 = D_003E9900[w + 0xF];
    D_003727BC = D_003E9900[w + 0x10];
    D_003727C0 = D_003E9900[w + 0x11];
    D_003727C4 = D_003E9900[w + 0x12];
    a = D_003E9900[w + 0x13];
    i = 0;
    while (i < a) {
        D_003EA8E0[i] = D_003E9900[i + (0x14 + w)];
        i++;
    }
    w = w + i;
    D_003727C8 = D_003E9900[w + 0x15];
    i = 0;
    while (i < 0x30) {
        D_00330DB8[i] = D_003E9900[i + (0x16 + w)];
        i++;
    }
    w = w + i;
    D_00372718 = D_003E9900[w + 0x17];
    D_0037271C = D_003E9900[w + 0x18];
    i = 0;
    while (i < 8) {
        D_003307A0[i] = D_003E9900[i + (0x19 + w)];
        i++;
    }
    D_0037274C = D_003E9900[w + 0x21];
    w = w + 0x22;
    b = 0;
    a = 0;
    D_003726E8 = D_003E9900[w];
    i = 0;
    while (i < D_003726E8) {
        if (a == 0) {
            D_003EA108[b].unk0 = D_003EA108[b].unk0 | 0x8000;
            D_003EA108[b].unk0 = D_003E9900[i * 3 + (1 + w)];
            D_003EA100[b].unk0 = D_003E9900[i * 3 + (2 + w)];
            D_003EA104[b].unk0 = D_003E9900[i * 3 + (3 + w)];
            b++;
        }
        i++;
    }
    w = w + (1 + i * 3);
    D_00372750 = D_003E9900[w];
    D_003726F4 = D_003E9900[w + 1];
    D_003726F8 = w + 1;
    D_00372794 = D_003E9900[w + 2];
    D_00372798 = D_003E9900[w + 3];
}

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
int SndDrv_FlushCommands(int a) {
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
    SndDrv_CmdBegin(0x13);
    SndDrv_Push16((short)a);
    SndDrv_Push16((short)b);
    SndDrv_Push16((short)c);
    SndDrv_Push16((short)d);
    SndDrv_Push16((short)e);
    SndDrv_Push16((short)f);
    SndDrv_CmdEnd();
    return 0;
}

void func_002E3610(int a) {
    SndDrv_CmdBegin(0x18);
    SndDrv_Push16((short)a);
    SndDrv_CmdEnd();
}

void func_002E3660(int a) {
    SndDrv_CmdBegin(0x19);
    SndDrv_Push16((short)a);
    SndDrv_CmdEnd();
}

void func_002E36B0(int a) {
    SndDrv_CmdBegin(0x17);
    SndDrv_Push16((short)a);
    SndDrv_CmdEnd();
}

void func_002E3700(int a, int b) {
    SndDrv_CmdBegin(0x1C);
    SndDrv_Push32(a);
    SndDrv_Push32(b);
    SndDrv_CmdEnd();
    func_002E5E28(a, b);
}

unsigned int func_002E3770(int a) {
    return (unsigned)(a * 4096) / 48000;
}

unsigned char func_002E37B8(char *a) {
    unsigned char r;

    r = func_002E4548();
    SndDrv_CmdBegin(0x1D);
    SndDrv_Push16(r);
    SndDrv_PushString(a);
    SndDrv_CmdEnd();
    return r;
}

int func_002E3830(int a, int b, int c, int d, int e) {
    if (a == -1) {
        a = func_002E4590();
    }
    if (a < 0) {
        return a;
    }
    SndDrv_CmdBegin(0x1E);
    SndDrv_Push32(a);
    SndDrv_Push32(b);
    SndDrv_Push32(c);
    SndDrv_Push16((short)d);
    SndDrv_Push32(e);
    SndDrv_CmdEnd();
    return a;
}

int func_002E3908(int a, char *b, int c) {
    if (a == -1) {
        a = func_002E4590();
    }
    if (a < 0) {
        return a;
    }
    SndDrv_CmdBegin(0x1F);
    SndDrv_Push32(a);
    SndDrv_Push32(c);
    SndDrv_PushString(b);
    SndDrv_CmdEnd();
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
    SndDrv_CmdBegin(0x20);
    SndDrv_Push32(a);
    SndDrv_CmdEnd();
    return 0;
}
TEXT_PAD(24);

void func_002E3AC0(void) {
    SndDrv_CmdBegin(0x27);
    SndDrv_CmdEnd();
}
TEXT_PAD(12);

void func_002E3B08(int a, int b, int c) {
    SndDrv_CmdBegin(0x29);
    SndDrv_Push32(a);
    SndDrv_Push32(b);
    SndDrv_Push32(c);
    SndDrv_CmdEnd();
}

void func_002E3B78(int a) {
    SndDrv_CmdBegin(0x2A);
    SndDrv_Push16((short)a);
    SndDrv_CmdEnd();
}

void func_002E3BC8(void) {
    SndDrv_CmdBegin(0x2A);
    SndDrv_Push16(6);
    SndDrv_CmdEnd();
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
    SndDrv_CmdBegin(0x2e);
    SndDrv_Push16((short)a);
    SndDrv_CmdEnd();
    return 0;
}

int func_002E3ED0(int a) {
    if (a >= D_003727A4) {
        return -1;
    }
    SndDrv_CmdBegin(0x2f);
    SndDrv_Push16((short)a);
    SndDrv_CmdEnd();
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
    SndDrv_CmdBegin(0x31);
    SndDrv_Push32(a);
    SndDrv_CmdEnd();
}

GP_DATA(D_003727DA);
GP_DATA(D_00372734);
void func_002E4750(int a) {
    D_003727DA = 1;
    D_00372734 = a;
    SndDrv_CmdBegin(0x32);
    SndDrv_Push32(a);
    SndDrv_CmdEnd();
}
TEXT_PAD(12);

void func_002E47B8(void) {
    SndDrv_CmdBegin(0x35);
    SndDrv_CmdEnd();
}

void func_002E47F8(void) {
    SndDrv_CmdBegin(0x37);
    SndDrv_CmdEnd();
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
            a = SndDrv_FlushCommands(0);
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
            SndDrv_FlushCommands(0);
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
    SndDrv_CmdBegin(0x3E);
    SndDrv_Push16(1);
    SndDrv_CmdEnd();
}

void func_002E4A78(void) {
    SndDrv_CmdBegin(0x3E);
    SndDrv_Push16(0);
    SndDrv_CmdEnd();
}

int func_002E4AC0(int a) {
    if (a < 0 || a >= 0x30) {
        return -1;
    }
    SndDrv_CmdBegin(0x3F);
    SndDrv_Push16((short)a);
    SndDrv_CmdEnd();
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
    SndDrv_CmdBegin(0x40);
    SndDrv_Push16((short)a);
    SndDrv_Push16((short)b);
    SndDrv_Push16((short)c);
    SndDrv_Push16((short)d);
    SndDrv_CmdEnd();
    return 0;
}

int func_002E4CB8(int a, int b) {
    if (a < 0 || a >= D_003727A4) {
        return -1;
    }
    if (b != 0 && b != 1) {
        return -2;
    }
    SndDrv_CmdBegin(0x44);
    SndDrv_Push16((short)a);
    SndDrv_Push16((short)b);
    SndDrv_CmdEnd();
    return 0;
}
TEXT_PAD(84);

void func_002E4DD8(int a, int b) {
    D_00330CF8[a] = b;
}

void func_002E4E20(int a, int b) {
    a = a >> 16;
    a -= 1;
    D_0037320C = SndDrv_ScaleVolume(D_003727E0[a], D_00330C38[b]);
    D_00373210 = SndDrv_ScaleVolume(D_003727E8[a], D_00330C98[b]);
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

int SndDrv_ScaleVolume(int a, int b) {
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
    SndDrv_CmdBegin(0x49);
    SndDrv_Push32((unsigned int)&D_003EACC0);
    SndDrv_CmdEnd();
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
    r = SndDrv_FlushCommands(0);
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
                        SndDrv_FlushCommands(0);
                    }
                    return r + 1;
                }
                func_002E1518(r, 0);
            }
            SndDrv_FlushCommands(0);
            func_002E4850();
        }
        func_002E3F50(a, p);
    }
    if (b == 0) {
        func_002E53B8();
        SndDrv_FlushCommands(0);
    }
    return 0;
}
TEXT_PAD(8);

void func_002E53B8(void) {
    SndDrv_CmdBegin(0x49);
    SndDrv_Push32(0);
    SndDrv_CmdEnd();
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
    SndDrv_CmdBegin(0x55);
    SndDrv_Push16((short)a);
    SndDrv_CmdEnd();
}
TEXT_PAD(40);

void func_002E5610(int a, int b) {
    func_002E1518(a, b);
}
TEXT_PAD(16);

void func_002E5660(a, b)
short a;
short b;
{
    SndDrv_CmdBegin(0x5C);
    SndDrv_Push16(a);
    SndDrv_Push16(b);
    SndDrv_CmdEnd();
}
TEXT_PAD(28);

int func_002E56E8(void) {
    return D_00372744;
}

int func_002E5718(void) {
    return D_00372730;
}
TEXT_PAD(16);

int func_002E5758(void) {
    return D_00372700;
}

int func_002E5788(int a, int b) {
    if ((unsigned)a >= 0x30) {
        return -1;
    } else if ((unsigned)b >= 0x30) {
        return -2;
    } else if ((unsigned)a > (unsigned)b) {
        return -3;
    }
    SndDrv_CmdBegin(0x65);
    SndDrv_Push16((short)a);
    SndDrv_Push16((short)b);
    SndDrv_CmdEnd();
    return 0;
}

int func_002E5860(unsigned int a, unsigned int b) {
    if (a >= 0x30) {
        return -1;
    } else if (b >= 0x30) {
        return -2;
    } else if (a > b) {
        return -3;
    }
    SndDrv_CmdBegin(0x7a);
    SndDrv_Push16((short)a);
    SndDrv_Push16((short)b);
    SndDrv_CmdEnd();
    return 0;
}

int func_002E5938(unsigned int a) {
    if (a >= 0x30) {
        return -1;
    }
    return func_002E5788(a, a);
}

int func_002E59A0(unsigned int a, unsigned int b) {
    if (a >= 0x30) {
        return -1;
    } else if (b >= 0x30) {
        return -2;
    } else if (a > b) {
        return -3;
    }
    SndDrv_CmdBegin(0x66);
    SndDrv_Push16((short)a);
    SndDrv_Push16((short)b);
    SndDrv_CmdEnd();
    return 0;
}

int func_002E5A78(unsigned int a, unsigned int b) {
    if (a >= 0x30) {
        return -1;
    } else if (b >= 0x30) {
        return -2;
    } else if (a > b) {
        return -3;
    }
    SndDrv_CmdBegin(0x7B);
    SndDrv_Push16((short)a);
    SndDrv_Push16((short)b);
    SndDrv_CmdEnd();
    return 0;
}

int func_002E5B50(unsigned int a) {
    if (a >= 0x30) {
        return -1;
    }
    return func_002E59A0(a, a);
}

int func_002E5BB8(unsigned int a, unsigned int b) {
    unsigned int c;
    unsigned int d;

    if (b >= 0x20) {
        return -1;
    }
    if (a >= 0x30) {
        return -2;
    }
    c = a % 24;
    c = c << 1;
    d = a / 24;
    b |= 0x1FC0;
    func_002E5660(((unsigned short)d | (unsigned short)c | 0x400) & 0xFFFF, (unsigned short)b);
    return 0;
}
TEXT_PAD(16);

int func_002E5CA8(int a, int b, int c) {
    int i;
    int r;

    if (a >= 0x30 || a < 0) {
        return -2;
    }
    if (b >= 0x30 || b < 0) {
        return -3;
    }
    if (a > b) {
        return -4;
    }
    i = a;
    while (i <= b) {
        r = func_002E3C28(i);
        if (r == -1) {
            r = func_002E3140(i);
            if (D_003308B0[i] == c && r != 0) {
                return i;
            }
        }
        i++;
    }
    return -1;
}
TEXT_PAD(16);

GP_DATA(D_00372854);
int func_002E5E28(int a, int b) {
    int i;
    struct S5E28 *p;

    if (D_00372854 == 0) {
        return -2;
    }
    p = D_00372854;
    i = 0;
    while (i < D_00373214) {
        if (p->unk0 == b) {
            p->unkC = a;
            p->unk10 = 1;
            return 0;
        }
        p++;
        i++;
    }
    return -1;
}
TEXT_PAD(64);

GP_DATA(D_00372830);
GP_DATA(D_00372828);
int *SndDrv_Alloc(int a, int b) {
    D_00372830++;
    if (D_00372828 == 0) {
        return func_0030C5D0(a, b);
    } else {
        return D_00372828(a, b);
    }
}
TEXT_PAD(44);

void func_002E5FF8(unsigned short a, unsigned short b, unsigned short c, unsigned short d, unsigned short e, unsigned short f, unsigned short g, unsigned short h) {
    short x;
    short y;

    x = (a << 15) | (b << 8) | (c << 4) | d;
    y = (e << 13) | (f << 6) | (g << 5) | h;
    SndDrv_CmdBegin(0x77);
    SndDrv_Push16(x);
    SndDrv_Push16(y);
    SndDrv_CmdEnd();
}

void func_002E6108(short a) {
    SndDrv_CmdBegin(0x79);
    SndDrv_Push16(a);
    SndDrv_CmdEnd();
}

void func_002E6160(short a, short b) {
    SndDrv_CmdBegin(0x76);
    SndDrv_Push16(a);
    SndDrv_Push16(b);
    SndDrv_CmdEnd();
}

void func_002E61D0(void) {
    int i;

    SndDrv_CmdBegin(0x7C);
    SndDrv_CmdEnd();
    for (i = 1; i < D_0037281C; i++) {
        D_0037280C[i] = 0;
    }
    D_00372814 = 1;
    D_00372808 = 1;
}

int func_002E6270(int a) {
    return D_003EABE0[a];
}
