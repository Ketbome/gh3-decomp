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
int func_0011DF78(int, int, int, int);
int func_0011DBB8(int, int, int, int);
void func_0011DC18(int);
void func_0011E008(int);
void func_0026AC60(void *, int);
int func_0026DC68(int);
int func_00273D88(void);
extern char D_003A44B0[];
int func_0028DAB8(int);
int func_0011DB60(int);
void func_0011DB08(int, int);
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

struct S271708 {
    u32 unk0;
    u32 unk4;
};
extern float D_0032D8D8[];
extern float D_0032DAD8[];
extern float D_0032DCD8[];
extern float D_0032DED8[];
extern "C" int func_003174C0(float, float);

static inline void S271_Zero(int &n) {
    if (n <= -1) n = 0;
}

extern "C" void func_00271708(void *pp, float a, float b, int sel) {
    S271708 *p = (S271708 *)pp;
    float t = b * 16.0f;
    int n;
    int idx = 0;
    int hi = 0;
    n = func_003174C0(t - 1.0f, t);
    int m = n; if (m >= 0x10) m = 0xF; n = m;
    S271_Zero(n);
    switch (sel) {
    case 0:
        idx = func_00271910(D_0032DCD8, 0x80, a);
        hi = 0x4000;
        break;
    case 1:
        idx = func_00271910(D_0032D8D8, 0x80, a);
        break;
    case 2:
        idx = func_00271910(D_0032DED8, 0x80, a);
        hi = 0xC000;
        break;
    case 3:
        idx = func_00271910(D_0032DAD8, 0x80, a);
        hi = 0x8000;
        break;
    }
    p->unk0 = (p->unk0 & 0xFFFFFFF0) | (n & 0xF);
    p->unk4 = (p->unk4 & 0xFFFF003F) | (((idx & 0x7F) << 6) | hi);
}

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

struct S271_Req {
    char pad0[0x10];
    int unk10;
    int unk14;
    int unk18;
};

extern "C" int func_002EEA00(int);
extern "C" int func_002F0AB0(int, S271_Req *, int, int, int, int);
extern "C" S271_Req D_003A9690;
extern "C" char D_00358C40[];
extern "C" int D_00370DC0;

GP_DATA(D_00370DC0);
extern "C" void func_00271C10(int a, int b, int c) {
    if (D_00370DC0) {
        while (func_002EEA00(D_00370DC0) >= 0) {}
    }
    D_003A9690.unk18 = c;
    D_003A9690.unk14 = b;
    D_003A9690.unk10 = a - 1;
    int i = 0;
    for (;;) {
        int r = func_002F0AB0(2, &D_003A9690, 0x20, 0, 0, 0);
        D_00370DC0 = r;
        int m = i % 1000;
        i++;
        if (r) break;
        if (m == 0) func_002F0488(D_00358C40);
    }
}

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

struct S271_Ev {
    int unk0;
    char pad4[8];
    int unkC;
    char pad10[0x18];
    int unk28;
    int unk2C;
};
extern float D_00370B08;

extern "C" void func_00271E88(S271_Ev *p) {
    if (p->unk0 == 0) {
        func_00271A98(0x1B0, 0, 0, 0, 0, 0);
        return;
    }
    int v;
    if (!((p->unkC >> 3) & 1)) {
        v = (int)(p->unk28 * D_00370B08);
    } else {
        v = p->unk28;
    }
    func_00271A98((p->unk0 - 1) | 0x1C0, p->unk2C, v, 0, 0, 0);
}

struct S271F28 {
    int unk0;
    char pad4[8];
    int unkC;
    int *unk10;
    char pad14[8];
    int unk1C;
    char pad20[8];
    int unk28;
    int unk2C;
};

extern "C" void func_00271F28(S271F28 *p) {
    if (p->unk0 == 0) {
        func_00271A98(0x20, p->unk1C / 2, 0, 0, 0, 0);
        return;
    }
    int v;
    if (!((p->unkC >> 3) & 1)) {
        v = (int)(p->unk28 * D_00370B08);
    } else {
        v = p->unk28;
    }
    if ((p->unkC >> 2) & 1) {
        func_00271A98((p->unk0 - 1) | 0x50, p->unk1C / 2, *p->unk10 - 1, p->unk2C, v, 0);
        return;
    }
    func_00271A98((p->unk0 - 1) | 0x40, p->unk1C, p->unk2C, v, 0, 0);
}

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

struct S272_B {
    int unk0;
    char pad4[8];
    int unkC;
    S272_B *unk10;
    int unk14;
    char pad18[4];
    volatile int unk1C;
    volatile int unk20;
    char pad24[0x14];
    int unk38;
    int unk3C;
};

extern "C" void func_00272058(void *vp, int a, int b) {
    S272_B *p = (S272_B *)vp;
    if (p->unk14 != 0) {
        int v;
        if (p->unk0 == 0) {
            int h = p->unk3C >> 1;
            func_0011DBB8(p->unk14, p->unk38 + h * a, 1, h);
            int h2 = p->unk3C >> 1;
            int u = p->unk20;
            v = u + h2;
        } else {
            int n;
            int off;
            if ((p->unkC >> 2) & 1) {
                if (a == 0)
                    off = p->unk38;
                else
                    off = p->unk10->unk38;
                n = p->unk3C;
            } else {
                int h = p->unk3C >> 1;
                off = p->unk38 + h * a;
                n = h;
            }
            if (b != 0) {
                int r = p->unk20 % n;
                off += r;
                n = r == 0 ? 0 : n - r;
            }
            if (n > 0)
                func_0011DBB8(p->unk14, off, 1, n);
            v = p->unk20 + n;
        }
        p->unk20 = v;
        int x = p->unk20;
        int y = p->unk1C;
        if (y < x) x = y;
        p->unk20 = x;
    }
}

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

struct S2722_Ent {
    u32 unk0;
    int unk4;
    int unk8;
};
struct S2722_Pool {
    char pad0[0xC];
    char *unkC;
};
struct S2722_G {
    char pad0[0x100];
    int unk100;
    S2722_Pool *unk104;
};
struct S2722_Obj {
    int unk0;
    int unk4;
    char pad8[4];
    int unkC;
    char pad10[4];
    int unk14;
    int unk18;
    int unk1C;
};
extern "C" {
extern S2722_G D_003A90C0;
extern int D_00368748;
extern char D_00370DD8[];
extern char D_00370DE0[];
S2722_Ent *func_001210C8(int, S2722_Pool *);
int func_00120598(int, int, int, int);
void func_0011DBE8(int, u64, int);
char *strcpy(char *, const char *);
void func_0030A554(int, char *);
}

static inline void S2722_Sel(u64 &out, int f) {
    if ((f >> 2) & 1) {
        out = 0;
    } else {
        out = 0x30;
    }
}

extern "C" int func_002722A8(S2722_Obj *o, int key) {
    char buf[0x100];
    S2722_G *g = &D_003A90C0;
    S2722_Ent *e = func_001210C8(key, g->unk104);
    if (e) {
        if (key != o->unk18) {
            int h = g->unk100;
            func_0011E008(o->unk14);
            if (D_00368748 != 0) {
                o->unk14 = func_00120598(h, 0, 0x5A, 0);
            } else {
                char *p = (char *)g;
                if (e->unk4 < 0) {
                    strcpy(buf, D_003A90C0.unk104->unkC + (e->unk0 & 0xFFFFFF));
                    if ((o->unkC >> 2) & 1) {
                        func_0030A554((int)buf, D_00370DD8);
                    } else {
                        func_0030A554((int)buf, D_00370DE0);
                    }
                    p = (char *)((int)buf | 1);
                }
                o->unk14 = func_0011DF78((int)p, 0, 0x5A, 0);
            }
            if (o->unk14 == 0) return 0;
            func_0011DB08(o->unk14, 1);
            o->unk18 = e->unk8;
        }
        o->unk1C += e->unk4 & 0x7FFFFFFF;
        int n;
        if ((o->unkC >> 2) & 1) {
            n = (u32)(e->unk4 & 0x7FFFFFFF) >> 1;
        } else {
            n = e->unk4 & 0x7FFFFFFF;
        }
        func_00271A98((o->unk0 - 1) | 0x60, n, 0, 0, 0, 0);
        if (e->unk4 < 0) {
            u64 v;
            S2722_Sel(v, o->unkC);
            func_0011DBE8(o->unk14, v, 0);
        } else {
            func_0011DBE8(o->unk14, (u32)(e->unk0 << 11), 0);
        }
        func_00272058(o, o->unk4 - 1, 1);
        return 1;
    }
    return 0;
}

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

struct S2727E8 {
    int pad0i;
    int unk4;
    int unk8;
    int unkC;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    char pad24[0x10];
    int unk34;
};

extern "C" int func_002727E8(S2727E8 *p, int a, int b, int c, int d) {
    int h = func_0011DF78(a, 0, 0x6E, 0);
    p->unk14 = h;
    if (h == 0) return 0;
    p->unk34 = b;
    p->unk20 = 0;
    p->unk18 = func_0028DAB8(a);
    if (d != 0) {
        p->unk1C = d;
    } else {
        p->unk1C = func_0011DB60(p->unk14);
    }
    func_0011DB08(p->unk14, 1);
    int t = p->unk1C;
    if (t & 0x3F) {
        p->unk1C = (t + 0x3F) & 0xFFFFFFC0;
    }
    if (c != 0 && p->unk8 == 0) {
        p->unkC |= 1;
    }
    if (p->unk10 != 0) {
        func_002724F8((S002724F8_4 *)p);
    }
    p->unkC &= 0xFFFFFFFB;
    p->unk4 = 1;
    p->unk8 = 7;
    func_00272058(p, 0, 0);
    return 1;
}

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

extern int D_00370DA0;
extern u8 D_00370DB4;

GP_DATA(D_00370DA0);
GP_DATA(D_00370DB4);
INCLUDE_ASM("asm/nonmatchings/game/t_271480", func_00272E18);

GP_DATA(D_00370DE8);
GP_DATA(D_00370DA8);
GP_DATA(D_00372EC0);
struct S271Ent {
    int id;
    char pad4[0x3C];
};

extern "C" int func_00272F70(void) {
    int i;
    int r;
    func_00272E18();
    if ((D_0032E1D8[0] & 0x40) && D_00370DE8) {
        D_00370DE8 = 0;
        func_002F0488(D_00358CA8);
    }
    for (i = 0; i < D_00370DA8; i++) {
        S271Ent *e = &((S271Ent *)D_003A92D0)[i];
        r = func_00272B48(e);
        if (r) {
            return r;
        }
        if (*S271Flags(e->id) & 3) {
            func_0011ED00();
        }
    }
    D_00372EC0 = func_0011ED00();
    return 0;
}

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

extern "C" int func_002730D0_f(float l, float r) asm("func_002730D0");
GP_DATA(D_00370DBC);
extern "C" int func_002730D0_f(float l, float r) {
    u32 m = D_00370DBC;
    int vl = (int)(l * (float)m * 0.01f);
    vl = (int)((float)vl * 81.909996f);
    if (vl >= 0x4000) {
        vl = 0x3FFF;
    } else if (vl <= -0x4000) {
        vl = -0x3FFF;
    }
    int vr = vl;
    if (r != l) {
        vr = (int)(r * (float)m * 0.01f);
        vr = (int)((float)vr * 81.909996f);
        if (vr >= 0x4000) {
            vr = 0x3FFF;
        } else if (vr <= -0x4000) {
            vr = -0x3FFF;
        }
    }
    if (vl < 0) vl += 0x7FFF;
    if (vr < 0) vr += 0x7FFF;
    return ((vl & 0x7FFF) << 16) | (vr & 0x7FFF);
}

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

struct S273308 {
    char pad0[8];
    int unk8;
    int unkC;
    char pad10[0x18];
    int unk28;
};

extern "C" int func_00273308(int x, float v) {
    int r = func_00273240(v);
    if (r > 0) ((S273308 *)D_003A9490[x])->unk28 = r;
    S273308 *e = (S273308 *)D_003A9490[x];
    int p;
    if (!((e->unkC >> 3) & 1)) {
        p = (int)(e->unk28 * D_00370B08);
    } else {
        p = e->unk28;
    }
    if (((S273308 *)D_003A9490[x])->unk8 == 5) {
        func_00271A98(x | 0xF0, p, 0, 0, 0, 0);
    }
    return r != 0;
}

extern "C" int func_002733E0(int a) {
    int r = func_002730D0(a);
    func_00271A98(a | 0x100, r, 0, 0, 0, 0);
    return 1;
}

extern "C" int func_00273240_i(int) asm("func_00273240");

extern "C" int func_00273428(int p) {
    int n = func_00273240_i(p);
    if (n > 0) {
        func_00271A98(p | 0x120, (int)((float)n * D_00370B08), 0, 0, 0, 0);
    }
    return n > 0;
}
