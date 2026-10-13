#include "common.h"

struct S271_Slot {
    int unk0;
    char pad[0x3C];
};

struct S271_Voice {
    int unk0;
    char pad4[8];
    int unkC;
    int *unk10;
    char pad14[8];
    int unk1C;
};


struct S271_Params {
    f32 unk0;
    int unk4;
    f32 unk8;
    f32 unkC;
    f32 unk10;
    int unk14;
    f32 unk18;
    int unk1C;
};

struct S271_Chan {
    char pad[8];
    int unk8;
    char padC[0x20];
    int unk2C;
};

struct S271_Name {
    char c[10];
};

struct S271_C {
    char pad[0xC];
    u32 unkC;
    void *unk10;
};

struct S271_20 {
    int unk0;
    char pad4[0x18];
    int unk1C;
    char pad20[0x14];
    int unk34;
};

struct S00272290 {
    char pad[0x1C];
    int unk1C;
    int unk20;
};

struct S00272B28_2 {
    int unk0;
};

struct S00272B28 {
    char pad[0x10];
    S00272B28_2* unk10;
};

struct S002724F8_3 {
    char pad[0xC];
    u32 unkC;
    int unk10;
};

struct S002724F8_4 {
    char pad[0x10];
    S002724F8_3* unk10;
};

extern "C" {
extern int D_00370DBC;
void func_002715B8(int *, void *);
extern u8 D_0032E1D9[];
extern float D_0032D898[];
int func_00271910(float *, int, float);
int func_002730D0(int);
int func_00271A98(int, int, int, int, int, int);
extern void *D_003A9490[];
extern char D_0032E210[];
extern volatile u8 D_00370DD0;
extern volatile int D_00370DD4;
void func_00271628(u32 *, float, int);
void func_002716B8(u32 *, float);
void func_00271708(void *, float, float, int);
void func_00271880(u32 *, float, int);
void func_002F3B80(void);
void func_002F3BD0(void);
void memset(void *, int, int);
extern float *D_00370D44;
extern float *D_00370D48;
extern float D_0032E0D8[];
extern float D_0032E158[];
extern u8 D_0032E1D8[];
void func_00272058(void *, int, int);
int func_0011DAA0(int);
void func_00271C10(int, int, int);
extern u32 D_00370D30[2];
extern u32 D_00370D38[2];
extern u32 D_003733A8[];
extern int D_00370DE8;
extern int D_00370DA8;
extern int D_00372EC0;
extern char D_00358CA8[];
void func_00270DB8(int);
void func_00272E18(void);
void func_002F0488(char *);
long func_0011ED00(void);
extern char D_003A92D0[];
int func_00272B48(void *);
}

inline u8 *S271Flags(int id) {
    if (id == 0) {
        return D_0032E1D8;
    }
    u8 *base = D_0032E1D9;
    return base + (id - 1);
}

GP_DATA(D_00370D38);
GP_DATA(D_00370D30);
INCLUDE_ASM("asm/nonmatchings/game/t_271480", func_00271480);

INCLUDE_ASM("asm/nonmatchings/game/t_271480", func_00271570);

extern "C" void *func_00271590(void *p, void *params) {
    func_002715B8((int *)p, params);
    return p;
}

extern "C" void func_002715B8(int *p, void *params) {
    S271_Params *q = (S271_Params *)params;
    p[1] = 0;
    p[0] = 0;
    func_00271628((u32 *)p, q->unk0, q->unk4);
    func_002716B8((u32 *)p, q->unk8);
    func_00271708(p, q->unkC, q->unk10, q->unk14);
    func_00271880((u32 *)p, q->unk18, q->unk1C);
}

GP_DATA(D_00370D44);
GP_DATA(D_00370D48);
extern "C" void func_00271628(u32 *p, float v, int mode) {
    int idx = 0;
    int flag = 0;
    switch (mode) {
    case 0:
        idx = func_00271910(D_00370D44, 0x80, v);
        break;
    case 1:
        idx = func_00271910(D_00370D48, 0x80, v);
        flag = 0x8000;
        break;
    }
    *p = (*p & ~0xFF00) | (((idx & 0x7F) << 8) | flag);
}

extern "C" void func_002716B8(u32 *p, float v) {
    *p = (*p & ~0xF0) | ((func_00271910(D_0032D898, 16, v) & 0xF) << 4);
}

INCLUDE_ASM("asm/nonmatchings/game/t_271480", func_00271708);

extern "C" void func_00271880(u32 *p, float v, int mode) {
    int idx = 0;
    int flag = 0;
    switch (mode) {
    case 0:
        idx = func_00271910(D_0032E0D8, 0x20, v);
        break;
    case 1:
        idx = func_00271910(D_0032E158, 0x20, v);
        flag = 0x20;
        break;
    }
    p[1] = (p[1] & ~0x3F) | ((idx & 0x1F) | flag);
}

extern "C" int func_00271910(float *table, int n, float v) {
    int mid = 0;
    int hi = n - 1;
    int lo = 0;
    float f;
    while (lo <= hi) {
        mid = (hi + lo) >> 1;
        f = table[mid];
        if (f == v) {
            return mid;
        }
        if (f < v) {
            lo = mid + 1;
        } else {
            hi = mid - 1;
        }
    }
    f = table[mid];
    if (f < v && mid < n - 1) {
        if (table[mid + 1] - v < v - f) {
            mid++;
        }
    } else if (v < f && mid > 0) {
        if (v - table[mid - 1] < f - v) {
            mid--;
        }
    }
    return mid;
}

INCLUDE_ASM("asm/nonmatchings/game/t_271480", func_00271A00);

GP_DATA(D_00370DD0);
GP_DATA(D_00370DD4);
extern "C" int func_00271A08(S271_Name *name, u8 *out) {
    int r;
    func_002F3B80();
    *name = *(S271_Name *)D_0032E210;
    *out = D_00370DD0;
    r = D_00370DD4;
    memset(D_0032E210, 0, 10);
    D_00370DD0 = 0;
    D_00370DD4 = 0;
    func_002F3BD0();
    return r;
}

INCLUDE_ASM("asm/nonmatchings/game/t_271480", func_00271A98);

INCLUDE_ASM("asm/nonmatchings/game/t_271480", func_00271C10);

extern "C" void func_00271CE0(void) {
}

INCLUDE_ASM("asm/nonmatchings/game/t_271480", func_00271CE8);

extern "C" int func_00271CF0(int flags) {
    switch (flags & 0x7000000) {
    case 0:
        return 11025;
    case 0x1000000:
        return 16000;
    case 0x2000000:
        return 22050;
    case 0x3000000:
        return 24000;
    case 0x4000000:
        return 28000;
    case 0x5000000:
        return 36000;
    case 0x6000000:
        return 44100;
    case 0x7000000:
        return 48000;
    }
    return -1;
}

INCLUDE_ASM("asm/nonmatchings/game/t_271480", func_00271DC8);

extern "C" void func_00271DD0(S271_Voice *p) {
    if (p->unk0 == 0) {
        func_00271A98(0x180, p->unk1C / 2, 0, 0, 0, 0);
    } else if ((p->unkC >> 2) & 1) {
        func_00271A98((p->unk0 - 1) | 0x1A0, *p->unk10 - 1, p->unk1C / 2, 0, 0, 0);
    } else {
        func_00271A98((p->unk0 - 1) | 0x190, p->unk1C, 0, 0, 0, 0);
    }
}

INCLUDE_ASM("asm/nonmatchings/game/t_271480", func_00271E88);

INCLUDE_ASM("asm/nonmatchings/game/t_271480", func_00271F28);

struct S272020 {
    int unk0;
    char pad4[0x18];
    int unk1C;
    char pad20[0x14];
    int unk34;
};
extern "C" void func_00272020(S272020 *p) {
    func_00271A98((p->unk0 - 1) | 0x1D0, p->unk1C, p->unk34, 0, 0, 0);
}

INCLUDE_ASM("asm/nonmatchings/game/t_271480", func_00272058);

extern "C" int func_00272160(int *p) {
    int r = 0;
    u8 *q = S271Flags(*p);
    u8 c = *q;
    if (c & 1) {
        func_00272058(p, 0, 0);
        r = 1;
        *q = *q & 0xFE;
    } else if (c & 2) {
        func_00272058(p, 1, 0);
        r = 2;
        *q = *q & 0xFD;
    }
    return r;
}

extern "C" int func_002721F8(int *p, int *out, int flag) {
    u8 *f = S271Flags(p[0]);
    *out = 0;
    if (*f & 0x20) {
        *f &= 0xDF;
    }
    if (func_0011DAA0(p[5])) {
        return 0;
    }
    int n = p[1] - 1;
    if (flag) {
        func_00271C10(p[0], n, p[15] >> 1);
    }
    return 1;
}

extern "C" int func_00272290(S00272290* p) {
    return p->unk20 >= p->unk1C;
}

INCLUDE_ASM("asm/nonmatchings/game/t_271480", func_002722A8);

extern "C" int func_002724B0(int *p, int *q) {
    if (D_0032E1D9[*p - 1] & 3) {
        return 0;
    }
    ((S271_C *)p)->unk10 = q;
    ((S271_C *)q)->unk10 = p;
    ((S271_C *)p)->unkC |= 2;
    return 1;
}

extern "C" int func_002724F8(S002724F8_4* p) {
    S002724F8_3* q = p->unk10;
    p->unk10 = 0;
    q->unk10 = 0;
    q->unkC &= 0xFFFFFFFD;
    return 1;
}

INCLUDE_ASM("asm/nonmatchings/game/t_271480", func_00272520);

INCLUDE_ASM("asm/nonmatchings/game/t_271480", func_002727E8);

INCLUDE_ASM("asm/nonmatchings/game/t_271480", func_00272920);

INCLUDE_ASM("asm/nonmatchings/game/t_271480", func_002729C0);

extern "C" int func_00272B28(S00272B28* p) {
    if (p->unk10 != 0) {
        return p->unk10->unk0 - 1;
    }
    return -1;
}

INCLUDE_ASM("asm/nonmatchings/game/t_271480", func_00272B48);

extern "C" void func_00272DE8(S271_C *p, int on) {
    if (on) {
        p->unkC |= 8;
    } else {
        p->unkC &= ~8;
    }
}

INCLUDE_ASM("asm/nonmatchings/game/t_271480", func_00272E18);

GP_DATA(D_00370DE8);
GP_DATA(D_00370DA8);
GP_DATA(D_00372EC0);
INCLUDE_ASM("asm/nonmatchings/game/t_271480", func_00272F70);

INCLUDE_ASM("asm/nonmatchings/game/t_271480", func_00273060);

extern "C" void func_00273068(int v) {
    D_00370DBC = v;
}

extern "C" int func_00273070(float v) {
    int n = (int)(v * 163.83f);
    if (n >= 0x4000) {
        n = 0x3FFF;
    }
    func_00271A98(0xC0, (n << 16) | n, 0, 0, 0, 0);
    return 1;
}

INCLUDE_ASM("asm/nonmatchings/game/t_271480", func_002730D0);

extern "C" int func_00273240(float v) {
    if (v > 100.0f) {
        v = 100.0f;
    }
    if (0.0f <= v) {
        return (int)(v * 40.96f);
    }
    return -1;
}

extern "C" int func_00273298(int x) {
    int r = func_002730D0(x);
    ((S271_Chan *)D_003A9490[x])->unk2C = r;
    if (((S271_Chan *)D_003A9490[x])->unk8 == 5) {
        func_00271A98(x | 0xD0, ((S271_Chan *)D_003A9490[x])->unk2C, 0, 0, 0, 0);
    }
    return 1;
}

INCLUDE_ASM("asm/nonmatchings/game/t_271480", func_00273308);

extern "C" int func_002733E0(int a) {
    int r = func_002730D0(a);
    func_00271A98(a | 0x100, r, 0, 0, 0, 0);
    return 1;
}

INCLUDE_ASM("asm/nonmatchings/game/t_271480", func_00273428);
