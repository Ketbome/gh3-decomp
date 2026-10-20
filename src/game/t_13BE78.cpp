#include "common.h"

struct S13B_X;

struct S13B_C { u8 r; u8 g; u8 b; u8 a; };

struct S13B_R {
    S13B_X* p;
    int unk4;
    int unk8;
};

struct S13B_X {
    char pad0[0x8];
    void* unk8;
    u32 unkC;
    char pad10[0x10];
    int unk20;
    char pad24[0x48];
    S13B_X* unk6C;
    char pad70[0x8];
    S13B_X* unk78;
    char pad7C[0x8];
    S13B_X* unk84;
    char pad88[0x174];
    float unk1FC;
    char pad200[0x4];
    int unk204;
    char pad208[0x38];
    int unk240;
    int unk244;
    int unk248;
    char pad24C[0xC];
    int unk258;
    int unk25C;
    char pad260[0x8];
    S13B_C unk268;
    int unk26C;
    int unk270;
    char pad274[0x4];
    int unk278;
};

struct S_0013DA80 { char pad0[0x240]; int unk240; };

struct S_0013D818 { char pad0[0xC]; int unkC; char pad1[0x268]; int unk278; };
struct S_0013DA60_b { int unk0; };
struct S_0013DA60 { char pad0[0x24C]; S_0013DA60_b* unk24C; };

struct S_0013CEA0 { char pad0[0x208]; u32 unk208; };

extern "C" {
int func_0014CD98(int, int);
int func_0014CF50(int);
void func_00153478(int);
void func_001534C0(int, int, int);
int func_00276008(int, int);
void func_00139510(void*, float*, float*);
int func_0027D470(void*, int, void**, int);
float func_0027EFA0(void*, int);
extern u8 D_0033AE18[];
void func_00153488(int);
void func_0013DEB8(S13B_X*);
void func_0013EB38(S13B_X*, int);
extern int D_00368A38;
void Heap_Free(int, void*);
void func_001CE888(S13B_X*, S13B_R*);
S13B_R* func_0013C1B0(S13B_R*, S13B_X*);
void func_0013E870(S13B_X*, int, int);
void func_001CE868(S13B_X*, S13B_R*);
extern u8 D_0033AB98[];
void func_00139420(S13B_X*, int);
S13B_X* func_00138F20(S13B_X*);
void func_001CEDE0(S13B_X*, u32);
void func_0014ACB8(int, int, int);
void func_0013B2C8(S13B_X*, int);
int func_0027D870(void*, u32, int*, int);
void func_0013A100(S13B_X*, void*);
int func_00113900(int);
void func_00113960(char*, int, int);
void func_00113AC8(char*, int, int);
void func_0013D838(void*, char*);
void func_00154078(int);
}

struct S_0013CFC0 { char pad0[0x204]; int unk204; };

INCLUDE_ASM("asm/nonmatchings/game/t_13BE78", func_0013BE78);

INCLUDE_ASM("asm/nonmatchings/game/t_13BE78", func_0013C080);

extern "C" S13B_R* func_0013C1B0(S13B_R* r, S13B_X* x) {
    r->unk4 = 0;
    r->unk8 = 0;
    r->p = x->unk6C;
    if (r->p) {
        func_001CE868(r->p, r);
    }
    return r;
}

INCLUDE_ASM("asm/nonmatchings/game/t_13BE78", func_0013C1F0);

INCLUDE_ASM("asm/nonmatchings/game/t_13BE78", func_0013C280);

struct A13C550 { char pad0[0x1E0]; float unk1E0; float unk1E4; char pad1E8[8]; float unk1F0; float unk1F4; };
struct B13C550 { char pad0[0x20]; float unk20; float unk24; float unk28; float unk2C; char pad30[4]; float unk34; float unk38; };

extern "C" void func_0013C550(A13C550* a, B13C550* b) {
    float x, y;
    x = b->unk34 * a->unk1F0 * (a->unk1E0 + 1.0f) * 0.5f;
    y = b->unk38 * a->unk1F4 * (a->unk1E4 + 1.0f) * 0.5f;
    func_00139510(b, &x, &y);
    b->unk28 = b->unk20 - x;
    b->unk2C = b->unk24 - y;
}

extern "C" void func_0013C5F8(S13B_X* self, float f) {
    if (!(self->unkC & 0x8000)) {
        self->unk1FC = f;
        self->unkC |= 0x1000;
    }
    for (S13B_X* c = self->unk78; c; c = c->unk84) {
        func_0013C5F8(c, f + 1.0f);
    }
}

extern "C" void func_0013C678(S13B_X* self, int v) {
    self->unk204 = v;
    self->unkC |= 0x10000000;
    for (S13B_X* c = self->unk78; c; c = c->unk84) {
        func_0013C678(c, v);
    }
}

INCLUDE_ASM("asm/nonmatchings/game/t_13BE78", func_0013C6E0);

struct N13C { char pad0[2]; u8 unk2; char pad3; int unk4; int* unk8; };

extern "C" {
int func_0027D470_n(int, int, N13C**, int) __asm__("func_0027D470");
float func_0027EFA0_n(N13C*, int) __asm__("func_0027EFA0");
}

extern "C" int func_0013C948(int self, int params, int key, float* a, float* b) {
    N13C* arr;
    if (func_0027D470_n(params, key, &arr, 0) != 0) {
        switch (arr->unk2) {
        case 2:
            *a = func_0027EFA0_n(arr, 0);
            *b = func_0027EFA0_n(arr, 1);
            break;
        case 13: {
            float t[2];
            int i = 0;
            do {
                int v;
                if (arr->unk4 == 1) {
                    v = (int)arr->unk8;
                } else {
                    v = arr->unk8[i];
                }
                int f1 = 0;
                if (v == (int)0x85981897 || v == (int)0xE126E035) {
                    f1 = 1;
                }
                if (f1 != 0) {
                    t[i] = -1.0f;
                } else {
                    int f2 = 0;
                    if (v == 0x4B358AEB || v == 0x76A08D5B) {
                        f2 = 1;
                    }
                    if (f2 != 0) {
                        t[i] = 1.0f;
                    } else {
                        *(int*)&t[i] = 0;
                    }
                }
                i++;
            } while (i < 2);
            *a = t[0];
            *b = t[1];
            break;
        }
        default:
            return 1;
        }
        return 1;
    }
    return 0;
}

extern "C" int func_0013CAA0(S13B_X* self, void* params, int key, float* a, float* b) {
    void* arr;
    if (func_0027D470(params, key, &arr, 0)) {
        *a = -func_0027EFA0(arr, 0);
        *b = func_0027EFA0(arr, 1);
        return 1;
    }
    return 0;
}

INCLUDE_ASM("asm/nonmatchings/game/t_13BE78", func_0013CB18);

extern "C" S13B_X* func_0013CC28(S13B_X* self) {
    func_00138F20(self);
    self->unk240 = 0;
    self->unk8 = D_0033AB98;
    func_001CEDE0(self, 0x5B9DA842);
    return self;
}

extern "C" void func_0013CC70(S13B_X* self, int flags) {
    self->unk8 = D_0033AB98;
    func_00139420(self, flags);
}

extern "C" void func_0013CC98(S13B_X* self, void* params) {
    func_0027D870(params, 0xF1822B9C, &self->unk240, 0);
    func_0013A100(self, params);
}

struct E13C { u32 unk0; char pad4[0xC]; int unk10; };
struct S13C { char pad0[0x10]; int unk10; char pad14[0x18]; int unk2C; char pad30[0x210]; int unk240; };
struct P13C { char pad[0x10]; };

extern "C" {
int func_00146E68(int);
int func_001468A8(int, u32);
int func_0013CF78(S13C*);
int func_00146E78(int, int);
int func_001D00B0(S13C*, E13C*);
int func_001D8A50(E13C*);
void func_0027AA70_c(P13C*) __asm__("func_0027AA70");
void func_0027ABB0(P13C*, int);
void func_0027C160_c(P13C*, u32, int) __asm__("func_0027C160");
void func_001DAC78_c(int, u32, int, int, P13C*, int, float) __asm__("func_001DAC78");
void func_0027AC90_c(P13C*) __asm__("func_0027AC90");
void func_001D8A08(E13C*, int, int);
extern int D_0036D554;
}

extern "C" int func_0013CCE8(S13C* self, E13C* ev) {
    int a = 0;
    int h = self->unk10;
    if (func_00146E68(h) != 0 && func_001468A8(h, ev->unk0) != 0 && (func_0013CF78(self) == 0 || func_00146E78(h, self->unk2C) == 0)) {
        a = 1;
    }
    int r = 0;
    if (a == 0) {
        if (func_001D00B0(self, ev) == 0) {
            return 0;
        }
        int k = 0;
        if (ev->unk0 == 0x9D3FB516 || ev->unk0 == 0x4ADF0CD3) {
            k = 1;
        }
        r = 1;
        if (k != 0) {
            if (self->unk240 != 0) {
                P13C par;
                int v = func_001D8A50(ev);
                func_0027AA70_c(&par);
                if (ev->unk10 != 0) {
                    func_0027ABB0(&par, ev->unk10);
                }
                func_0027C160_c(&par, 0xB30D9965, v);
                func_001DAC78_c(D_0036D554, ev->unk0, self->unk240, 0x36B2EE74, &par, 0, -1.0f);
                func_0027AC90_c(&par);
            }
            func_001D8A08(ev, self->unk2C, 0);
            r = 1;
        }
    }
    return r;
}

INCLUDE_ASM("asm/nonmatchings/game/t_13BE78", func_0013CE58);

extern "C" bool func_0013CEA0(S_0013CEA0* self, int bit) {
    if (self->unk208 == 0) return true;
    return (self->unk208 & (1 << bit)) != 0;
}

INCLUDE_ASM("asm/nonmatchings/game/t_13BE78", func_0013CEC8);

struct T_0013CED0 { char pad0[4]; int unk4; int unk8; };
struct B_0013CED0 { char pad0[0x80]; int unk80; int unk84; T_0013CED0* unk88; };
struct A_0013CED0 { char pad0[0x208]; int unk208; };

extern "C" void func_0013CED0(A_0013CED0* a, B_0013CED0* b) {
    int v;
    if (b->unk80 != 0 || b->unk88 != 0) {
        a->unk208 = 0;
        if (b->unk80 != 0) {
            v = b->unk84;
            if (v >= 0) a->unk208 = 1 << v;
        } else {
            T_0013CED0* t = b->unk88;
            if (t) {
                u32 i = 0;
                if (t->unk4 != 0) {
                    do {
                        v = (int)b->unk88;
                        int k = ((T_0013CED0*)v)->unk4;
                        v = ((T_0013CED0*)v)->unk8;
                        if (k != 1) v = ((int*)v)[i];
                        if (v >= 0) a->unk208 |= 1 << v;
                        i++;
                    } while (i < (u32)b->unk88->unk4);
                }
            }
        }
    }
}

INCLUDE_ASM("asm/nonmatchings/game/t_13BE78", func_0013CF78);

extern "C" int func_0013CFC0(S_0013CFC0* self) {
    return self->unk204;
}

extern "C" void func_0013CFC8(S13B_X* self, int flag) {
    if (flag) {
        self->unkC |= 0x400000;
    } else {
        self->unkC = (self->unkC & ~0x400000) | 0x1000;
    }
}

extern "C" int func_0013D000(S13B_X* self) {
    S13B_X* p;
    if (self->unkC & 0x400000) {
        return 1;
    }
    for (p = self->unk6C; p; p = p->unk6C) {
        if (p->unkC & 0x400000) {
            return 1;
        }
    }
    return 0;
}

struct E_func_0013D048 { int key; int val; E_func_0013D048* next; };
struct T_func_0013D048 { int bits; E_func_0013D048* buckets; int count; };

extern "C" void func_0011C408(int, E_func_0013D048*);

extern "C" void func_0013D048(T_func_0013D048* t, int* key) {
    if (!t->buckets) {
        return;
    }
    E_func_0013D048* e = &t->buckets[*key & ((1 << t->bits) - 1)];
    E_func_0013D048* prev = 0;
    while (e) {
        E_func_0013D048* next = e->next;
        if (e->key == *key && e->val) {
            if (prev) {
                prev->next = next;
                func_0011C408(0, e);
            } else {
                e->key = 0;
                e->val = 0;
            }
            t->count--;
            return;
        }
        prev = e;
        e = next;
    }
}

struct P_0013D100 {
    u32 unk0;
    u32 unk4;
    int Has(u32 p) { return !(p < unk0) && p < unk4; }
};
extern "C" {
extern P_0013D100* D_00371288[2];
extern int D_00371298;
void func_0011C2E8(P_0013D100*, void*);
}

extern "C" void func_0013D100(void* p) {
    P_0013D100* pool = D_00371288[D_00371298];
    if ((pool && pool->Has((u32)p)) || ((pool = D_00371288[D_00371298 ^ 1]) && pool->Has((u32)p))) {
        func_0011C2E8(pool, p);
    } else if (p) {
        Heap_Free(D_00368A38, p);
    }
}

INCLUDE_ASM("asm/nonmatchings/game/t_13BE78", func_0013D1B8);

extern "C" void func_0013D2C8(void) {
}

extern "C" S13B_X* func_0013D2D0(S13B_X* self) {
    S13B_C* c;
    func_00138F20(self);
    c = &self->unk268;
    c->r = 0;
    self->unk8 = D_0033AE18;
    c->a = 0x80;
    c->b = 0;
    c->g = 0;
    self->unk244 = 0;
    self->unk248 = 0;
    self->unk240 = 0;
    self->unk258 = 0;
    self->unk25C = 0;
    func_0013E870(self, 1, 0);
    self->unk26C = 0;
    self->unk270 = 0;
    self->unk278 = 1;
    func_001CEDE0(self, 0x5200DFB6);
    return self;
}

extern "C" void func_0013D360(S13B_X* self, int flags) {
    self->unk8 = D_0033AE18;
    if (self->unk248) {
        func_00153488(self->unk248);
    }
    func_0013DEB8(self);
    func_0013EB38(self, 0);
    if (self->unk240) {
        Heap_Free(D_00368A38, (void*)self->unk240);
    }
    func_00139420(self, flags);
}

INCLUDE_ASM("asm/nonmatchings/game/t_13BE78", func_0013D3E0);

extern "C" void func_0013D6E8(S13B_X* self, int a) {
    if (self->unk258) {
        func_0014ACB8(self->unk258, a, 0);
    }
    func_0013B2C8(self, a);
}

struct S13D730 { char pad0[0xC]; unsigned int unkC; char pad10[0x234]; int unk244; int unk248; char pad24C[0x2C]; int unk278; };

extern "C" void func_0013D730(S13D730* self, int a) {
    self->unk244 = a;
    if (a == 0x0A77F6AE || a == 0x0D53096F) {
        self->unk244 = 0x7D70C638;
    }
    if (self->unk248) func_00153488(self->unk248);
    self->unk248 = func_0014CD98(self->unk244, 1);
    if (func_0014CF50(self->unk244) == 0) {
        int t = func_00276008(0x8751015E, 0);
        self->unk244 = t;
        if (t == 0) self->unk244 = 0x35C0114B;
        self->unk248 = func_0014CD98(self->unk244, 1);
    }
    if (self->unk248) {
        func_00153478(self->unk248);
        func_001534C0(self->unk248, self->unk278, 0);
    }
    self->unkC |= 0x1000;
}

extern "C" void func_0013D818(S_0013D818* self, int v) {
    if (v >= 0) {
        self->unk278 = v;
        self->unkC |= 0x1000;
    }
}

INCLUDE_ASM("asm/nonmatchings/game/t_13BE78", func_0013D838);

extern "C" void func_0013DA60(S_0013DA60* self) {
    func_00154078(self->unk24C->unk0);
}

extern "C" void func_0013DA80(S_0013DA80* self) {
    func_00113900(self->unk240);
}

struct I_13DAA0 { int unk0; };
struct S_13DAA0 { char pad0[0x240]; int unk240; char pad244[8]; I_13DAA0* unk24C; I_13DAA0* unk250; char pad254[8]; int unk25C; };
struct P_13DAA0 { char pad0[4]; u32 unk4; int unk8; };
extern "C" {
void func_00153DE0(int, int);
int func_0027D1F8(int, u32, void*, int);
int func_0027D268(int, u32, float*, int);
int func_0027D378(int, u32, float*, float*, int);
void func_00153C28(int, int, float);
void func_00153958(int, int, int, int);
void func_00153AB0(int, int, float, float);
}

extern "C" void func_0013DAA0(S_13DAA0* self, P_13DAA0* pr) {
    u32 i = 0;
    func_00153DE0(self->unk24C->unk0, self->unk240);
    if (pr->unk4 != 0) {
        do {
            int o;
            if (pr->unk4 == 1) {
                o = pr->unk8;
            } else {
                o = ((int*)pr->unk8)[i];
            }
            int id = 0;
            func_0027D1F8(o, 0x7F8C98FE, &id, 1);
            float a = 0.0f;
            if (func_0027D268(o, 0xED344E1B, &a, 0)) {
                a = a * 0.017453294f;
                func_00153C28(self->unk24C->unk0, id, a);
                if (self->unk25C) {
                    func_00153C28(self->unk250->unk0, id, a);
                }
            }
            float b = 0.0f;
            float c = 0.0f;
            if (func_0027D378(o, 0xA6F5352F, &b, &c, 0)) {
                func_00153958(self->unk24C->unk0, id, (int)b, (int)c);
                if (self->unk25C) {
                    func_00153958(self->unk250->unk0, id, (int)b, (int)c);
                }
            }
            float d = 0.0f;
            float e = 0.0f;
            if (func_0027D378(o, 0x13B9DA7B, &d, &e, 0)) {
                func_00153AB0(self->unk24C->unk0, id, d, e);
                if (self->unk25C) {
                    func_00153AB0(self->unk250->unk0, id, d, e);
                }
            }
            i++;
        } while (i < pr->unk4);
    }
}

struct S_0013DCA8 { char pad0[0x240]; int unk240; };

extern "C" int func_0013DCA8(S_0013DCA8* self, int s) {
    int a = 0;
    if (self->unk240) a = func_00113900(self->unk240);
    int n = a + func_00113900(s);
    if (n + 1 < 0x80) {
        if (n > 0) {
            char buf[0x80];
            buf[0] = 0;
            if (self->unk240) func_00113960(buf, 0x80, self->unk240);
            func_00113AC8(buf, 0x80, s);
            func_0013D838(self, buf);
            return 1;
        }
    }
    return 0;
}

struct S_0013DD50 { char pad0[0x240]; int unk240; };

extern "C" int func_0013DD50(S_0013DD50* self) {
    char buf[0x80];
    int len;
    if (!self->unk240) return 0;
    len = func_00113900(self->unk240);
    if (!len) return 0;
    func_00113960(buf, 0x80, self->unk240);
    if (len >= 2) {
        char c = buf[len - 1];
        if (c == 0x5C) {
            if (buf[len - 2] == c) buf[len - 2] = 0;
        }
    }
    buf[len - 1] = 0;
    func_0013D838(self, buf);
    return 1;
}

struct CP_0013DDF8 { u8 r; u8 g; u8 b; u8 a; };
struct C_0013DDF8 {
    CP_0013DDF8 c;
    C_0013DDF8(const C_0013DDF8& o) : c(o.c) {}
    C_0013DDF8& operator=(const C_0013DDF8& o) { *(u32*)this = *(const u32*)&o; return *this; }
};
struct T_0013DDF8 { char pad0[0x538]; C_0013DDF8 unk538; };
struct S_0013DDF8 { char pad0[0xE8]; C_0013DDF8 unkE8; char padEC[0x16C]; T_0013DDF8* unk258; };

extern "C" {
int func_00119610(int, int);
void func_00119490(int, int);
void func_001194B8(int);
void* Heap_Alloc(int, int, int, int);
T_0013DDF8* func_0014A7A8(void*);
void func_0013EB38_1(void*, int) __asm__("func_0013EB38");
void func_0013E870_1(void*, int, int) __asm__("func_0013E870");
}

extern "C" void func_0013DDF8(S_0013DDF8* self) {
    if (self->unk258 == 0) {
        func_0013EB38_1(self, 0);
        int h = D_00368A38;
        func_00119490(h, func_00119610(h, 0x3A));
        T_0013DDF8* t = func_0014A7A8(Heap_Alloc(D_00368A38, 0x540, 1, 0));
        self->unk258 = t;
        C_0013DDF8 tmp(self->unkE8);
        t->unk538 = tmp;
        C_0013DDF8 tmp2(t->unk538);
        func_001194B8(D_00368A38);
        func_0013E870_1(self, 0x11, 0);
    }
}
