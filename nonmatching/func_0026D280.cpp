// cflags: -funroll-loops
#include "common.h"

struct S0026DFE8 {
    int unk0;
    int unk4;
};

struct S0026D660 {
    char pad[0xC80];
    int unkC80;
    int unkC84;
    u64 unkC88;
    u64 unkC90;
    char padC98[0x18];
};

struct S26D_Ent {
    int key;
};

struct S26D_Cnt {
    int unk0;
    int unk4;
    int unk8[1];
};

struct S26E008 {
    int unk0;
    int unk4;
    int unk8;
    int unkC;
    char unk10[1];
};

struct S26D_P7 {
    int a;
    short b;
    char c;
};

extern "C" {
void func_0030B550(char *, const char *, ...);
extern char D_00358958[];
void *func_0011DF78(char *, int, int, int);
int func_0011DB60(void *);
int func_0011DBB8(void *, void *, int, int);
int func_0011E008(void *);
int func_001150B8(void);
int func_0026DCA0(int);
void func_00277378_i(int, int) asm("func_00277378");
extern int *D_00370CBC;
extern int D_004278B0[];
int func_0026E008(void *, int);
void func_0027C160(int, int, int);
S26D_Cnt *func_0026EAA0(char *);
u32 CrcFromPathLowercase(const char *);
int func_0027D470(int, u32, void *, int);
void *func_0027EF20(void *, u32);
int func_0028DAB8(void *);
extern char D_00370C70[];
void func_0026AE70(void);
int func_0026ABA8(void);
int func_002741B8(int);
extern int D_00370C08;
int func_00273DE8(void);
int func_00273D88(void);
extern char D_003A8050[];
extern int D_00370C50;
extern S26D_Ent D_003A34A0[];
extern int D_00370C14;
void func_00273498(void);
int func_0026E0B8(int *);
extern S0026D660 D_003A66F0;
extern S26D_P7 D_00370C68[2];
int func_002741F8(int, int);
void func_0026E1B0(int, int);
extern int D_00370C18;
void func_00273070(void);
int func_0026E5C8(int, int);
extern int D_00370CB8;
struct S26D_W {
    int unk0;
    int unk4;
    int unk8;
};
S26D_W *func_0027B300(int, S26D_W *);
int func_0010C050(int);
void func_0027C448(int, int, int);
void func_0027ABB0(int, int);
void func_0026DFE8(S0026DFE8 *);
}

struct S26D2_E {
    char pad0[0xC80];
    int unkC80;
    char padC84[4];
    u64 a0;
    u64 a1;
    u64 b0;
    u64 b1;
    int unkCA8;
    char padCAC[4];
};
extern "C" {
extern S26D2_E D_003A66F0_k[] asm("D_003A66F0");
extern int D_00370C28;
extern int D_00370C40;
void func_0026CCE0(void);
void func_0026C5E8(void *, int, void *, int, int);
void func_0026C5E8_b(void *, int) __asm__("func_0026C5E8");
int func_001287F0(int, int);
int func_0027AA70(int);
void func_0028C9D0(int, int, int, int, int, int);
void func_0027AC90(int);
void func_00113250(int);
}

GP_DATA(D_00370C18);
GP_DATA(D_00370C28);
GP_DATA(D_00370C14);
extern "C" void func_0026D280(void) {
    if (func_0026ABA8() == 0) {
        S26D2_E *e = &D_003A66F0_k[D_00370C18];
        if (e->unkCA8 == 0 && func_00273D88() == 1) {
            D_00370C40 = 0;
            func_0026CCE0();
            if (D_00370C28 != 0) {
                func_0026C5E8_b(D_003A8050, 1);
            } else {
                int n = e->unkC80;
                int k = 0;
                int t;
                u64 b;
                int h;
                char *p4 = (char *)e;
                char *p6 = (char *)e;
                if (n > 0) {
                    do {
                        if (!((int)(e->a0 >> k) & 1) && k < 0x40) {
                            b = e->b0;
                            if (!((int)(b >> k) & 1)) {
                                e->b0 = b | ((u64)1 << k);
                                goto found;
                            }
                        }
                        {
                            t = k - 0x40;
                            if (!((int)(e->a1 >> t) & 1) && k >= 0x40) {
                                b = e->b1;
                                if (!((int)(b >> t) & 1)) {
                                    e->b1 = b | ((u64)1 << t);
                                    p4 = p6;
                                found:
                                    func_0026C5E8(p4, 0, p6, 1, n);
                                    D_00370C14 = k;
                                    h = func_0027AA70(func_001287F0(8, 1));
                                    func_0027C160(h, 0x8D02705D, D_00370C14);
                                    func_0028C9D0(0x300CAD34, h, 0, 0, 0, 0);
                                    if (h != 0) {
                                        func_0027AC90(h);
                                        func_00113250(h);
                                    }
                                    return;
                                }
                            }
                        }
                        k++;
                        p6 += 0x28;
                        p4 += 0x28;
                    } while (k < n);
                }
                e->b0 = 0;
                e->b1 = 0;
            }
        }
    }
}

struct S26D4_R {
    char pad0[0x10];
    int unk10;
    char pad14[8];
    int unk1C;
    int unk20;
    char pad24[0x14];
    int unk38;
    char pad3C[0x44];
};

extern "C" {
extern S26D4_R D_003A44B0_r[] asm("D_003A44B0");
extern int D_00372E98;
extern int D_00370C2C;
extern float D_00370C1C_f asm("D_00370C1C");
extern int D_00370C34;
extern int D_00370C24;
int func_00272F70(void);
void func_0026AEA8(int);
void func_0026BD80(void);
int func_0026C3D8(int);
void func_0026CD30(void);
void func_0026D280(void);
int func_0026DC68(int);
void func_0026E190(int *);
}

GP_DATA(D_00370C2C);
GP_DATA(D_00370C50);
GP_DATA(D_00370C1C);
GP_DATA(D_00370C34);
GP_DATA(D_00370C24);
INCLUDE_ASM("asm/nonmatchings/game/t_26D280", func_0026D480);

extern "C" void func_0026D660(u64* a, u64* b) {
    *a = D_003A66F0.unkC88;
    *b = D_003A66F0.unkC90;
}

INCLUDE_ASM("asm/nonmatchings/game/t_26D280", func_0026D680);

GP_DATA(D_00370C18);
extern "C" void func_0026D688(void) {
    if (D_00370C18 == 1) {
        func_00273070();
    }
}

extern "C" void func_0026D6B0(void) {
    func_00273498();
}

INCLUDE_ASM("asm/nonmatchings/game/t_26D280", func_0026D6D0);

extern "C" int func_0026D9F8(int a, int b) {
    if (func_0026ABA8() == 0) {
        if (func_00273D88() != 1) {
            if (b < (&D_003A66F0)[a].unkC80) {
                int t = func_0028DAB8(D_003A8050);
                int u = func_0028DAB8((char *)&(&D_003A66F0)[a] + b * 0x28);
                int r = 0;
                if ((t ^ u) == 0)
                    r = 1;
                return r;
            }
        }
        return 0;
    }
    return 0;
}

extern "C" int func_0026DAB0(int i) {
    if (func_0026ABA8() != 0) {
        return 0;
    }
    return (&D_003A66F0)[i].unkC80;
}

extern "C" char *func_0026DAF8(int a, int b) {
    if (func_0026ABA8()) {
        S26D_P7 *d = (S26D_P7 *)&D_003A66F0;
        d->a = D_00370C68[0].a;
        d->b = D_00370C68[0].b;
        d->c = D_00370C68[0].c;
        return (char *)d;
    }
    char *q = (char *)&D_003A66F0 + b * 0xCB0;
    char *path = q + a * 0x28;
    char *p = path;
    int n = strlen(path);
    int i = 0;
    while (i < n) {
        char c = path[i];
        if (c == '\\' || c == '/')
            p = path + (i + 1);
        i++;
    }
    return p;
}

extern "C" void func_0026DBD8(int a) {
    if (func_0026ABA8() == 0) {
        if (D_00370C18 != a) {
            func_0026AE70();
        }
        D_00370C18 = a;
    }
}

GP_DATA(D_00370C08);
extern "C" int func_0026DC20(int a) {
    if (func_0026ABA8() != 0) {
        return 0;
    }
    int r = func_002741B8(a);
    D_00370C08 = r;
    return r;
}

INCLUDE_ASM("asm/nonmatchings/game/t_26D280", func_0026DC60);

GP_DATA(D_00370C50);
extern "C" int func_0026DC68(int a) {
    if (D_00370C50 == a) {
        return 0x20;
    }
    return func_00273DE8();
}

INCLUDE_ASM("asm/nonmatchings/game/t_26D280", func_0026DC98);

extern "C" int func_0026DCA0(int a) {
    return func_002741F8(a, 0) != 0;
}

INCLUDE_ASM("asm/nonmatchings/game/t_26D280", func_0026DCC0);

INCLUDE_ASM("asm/nonmatchings/game/t_26D280", func_0026DCC8);

struct S26DD48_T {
    int unk0;
    char pad[0x7C];
};
struct S26DD48 {
    char pad0[0x1C];
    int unk1C;
};
extern S26DD48_T D_003A44B0[];
extern "C" int func_0026ABB0(void);
extern "C" int func_0026AD48(int, int);

INCLUDE_ASM("asm/nonmatchings/game/t_26D280", func_0026DD48);

extern "C" int func_0026DE20(void) {
    return D_00370C14;
}

INCLUDE_ASM("asm/nonmatchings/game/t_26D280", func_0026DE28);

extern "C" S0026DFE8 *func_0026DFC0(S0026DFE8 *p) {
    func_0026DFE8(p);
    return p;
}

extern "C" void func_0026DFE8(S0026DFE8* p) {
    p->unk0 = 0;
    p->unk4 = 0;
}

INCLUDE_ASM("asm/nonmatchings/game/t_26D280", func_0026DFF8);

extern "C" int func_0026E008(void *vp, int key) {
    S26E008 *p = (S26E008 *)vp;
    char buf[256];
    func_0030B550(buf, D_00358958, key);
    void *h = func_0011DF78(buf, 1, 0x64, 0);
    if (h != 0) {
        int n = func_0011DB60(h);
        p->unk4 = n;
        if (n >= 0x1000) {
            func_0011E008(h);
            return 0;
        }
        func_0011DBB8(h, p->unk10, 1, n);
        func_0011E008(h);
        p->unk0 = key;
        return 1;
    }
    return 0;
}

extern "C" int func_0026E0B8(int *p) {
    if (*p) {
        func_0026DFE8((S0026DFE8 *)p);
        return 1;
    }
    return 0;
}

extern "C" S26D_Ent *func_0026E0E8(int k) {
    for (int i = 0; i < 1; i++) {
        if (D_003A34A0[i].key == 0) {
            if (func_0026E008(&D_003A34A0[i], k))
                return &D_003A34A0[i];
            return 0;
        }
    }
    return 0;
}

extern "C" S26D_Ent *func_0026E138(int k) {
    for (int i = 0; i < 1; i++) {
        if (D_003A34A0[i].key == k) {
            return &D_003A34A0[i];
        }
    }
    return 0;
}

INCLUDE_ASM("asm/nonmatchings/game/t_26D280", func_0026E158);

extern "C" void func_0026E190(int *p) {
    func_0026E0B8(p);
}

extern "C" void func_0026E1B0(int a, int b) {
    if (b == 0xFFFF) {
        if (a != 0) {
            for (int i = 0; i < 1; i++)
                func_0026DFC0((S0026DFE8 *)&D_003A34A0[i]);
        }
    }
}

extern "C" void func_0026E1E8(void) {
    func_0026E1B0(1, 0xFFFF);
}

INCLUDE_ASM("asm/nonmatchings/game/t_26D280", func_0026E208);

extern "C" void func_0026E470(char *pat, char *buf, void (*cb)(char *)) {
    char *out = buf + strlen(buf);
    char *o = out;
    while (*pat) {
        if (*pat == '?') {
            pat++;
            for (char c = '0'; c <= '9'; c++) {
                o[1] = 0;
                o[0] = c;
                func_0026E470(pat, buf, cb);
            }
            *out = 0;
            return;
        }
        *o = *pat;
        pat++;
        o++;
    }
    *o = 0;
    cb(buf);
    *out = 0;
}

GP_DATA(D_00370CBC);
extern "C" void func_0026E560(int a) {
    int t = func_001150B8();
    if (func_0026DCA0(t) != 0) {
        func_00277378_i(t, a);
        if (D_00370CBC < D_004278B0) {
            *D_00370CBC++ = t;
        }
    }
}

INCLUDE_ASM("asm/nonmatchings/game/t_26D280", func_0026E5C8);

INCLUDE_ASM("asm/nonmatchings/game/t_26D280", func_0026E638);

GP_DATA(D_00370CB8);
extern "C" void func_0026E890(int a) {
    D_00370CB8 = func_0026E5C8(D_00370CB8, a);
}

INCLUDE_ASM("asm/nonmatchings/game/t_26D280", func_0026E8B8);

INCLUDE_ASM("asm/nonmatchings/game/t_26D280", func_0026EAA0);

extern "C" int func_0026EB08(int list, int extra, int out) {
    int total = 0;
    for (S26D_W *n = func_0027B300(list, 0); n; n = func_0027B300(list, n))
        total += n->unk8;
    if (total == 0)
        return 0;
    int r = func_0010C050(total) + 1;
    S26D_W *sel = func_0027B300(list, 0);
    S26D_W *n = sel;
    while (n) {
        sel = n;
        r -= n->unk8;
        if (r <= 0)
            break;
        n = func_0027B300(list, n);
    }
    func_0027C448(out, 0, sel->unk4);
    if (extra)
        func_0027ABB0(out, extra);
    return 1;
}

struct S26D_Arr {
    int unk0;
    u32 unk4;
};

extern "C" void *func_0026EC08(int key, char c, int obj) {
    struct {
        char name[2];
        char pad[14];
        S26D_Arr *arr;
    } l;
    u32 i = 0;
    l.name[0] = c;
    l.name[1] = 0;
    l.arr = 0;
    func_0027D470(obj, CrcFromPathLowercase(l.name), &l.arr, 1);
    int n = l.arr->unk4;
    for (; i < n; i++) {
        void *p = func_0027EF20(l.arr, i);
        if (func_0028DAB8(p) == key)
            return p;
    }
    return D_00370C70;
}

extern "C" void func_0026ED98(int a, char *fmt, int c, int d, int *tbl) {
    char buf[256];
    char *o = buf;
    while (*fmt) {
        if (*fmt == '%') {
            fmt++;
            char t = *fmt;
            fmt++;
            char *s = (char *)func_0026EC08(tbl[t - 97], t, d);
            while (*s)
                *o++ = *s++;
        } else {
            *o++ = *fmt++;
        }
    }
    *o = 0;
    S26D_Cnt *r = func_0026EAA0(buf);
    if (r) {
        for (int i = 0; i < r->unk4; i++)
            func_0027C160(a, r->unk8[i], c);
    }
}

INCLUDE_ASM("asm/nonmatchings/game/t_26D280", func_0026EED8);

INCLUDE_ASM("asm/nonmatchings/game/t_26D280", func_0026F158);
