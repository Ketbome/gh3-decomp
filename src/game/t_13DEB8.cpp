#include "common.h"

struct S13D_C { u8 r; u8 g; u8 b; u8 a; };

struct S13D_X {
    char pad0[0x8];
    void* unk8;
    char padC[0x6C];
    S13D_X* unk78;
    char pad7C[0x8];
    S13D_X* unk84;
    char pad88[0x1B8];
    int unk240;
    char pad244[0x8];
    int* unk24C;
    int* unk250;
    int unk254;
    int unk258;
    int unk25C;
    int unk260;
    float unk264;
    float unk268;
    int unk26C;
    int unk270;
    int unk274;
    char pad278[0x4];
    int unk27C;
    char pad280[0x8];
    S13D_C unk288;
    int unk28C;
    int unk290;
};

extern "C" {
extern u8 D_0033AD98[];
extern u8 D_00369660[];
extern u8 D_00369668[];
void func_0014A910(int, int);
void func_00139420(S13D_X*, int);
void func_0013EB38(S13D_X*, int);
void func_0013E870(S13D_X*, int, int);
void* func_0013C1F0(S13D_X*);
int func_00148348(void*);
void func_00154108(int, int);
S13D_X* func_00138F20(S13D_X*);
void func_001CEDE0(S13D_X*, u32);
void func_001541A0(int);
extern int D_00368A38[] __attribute__((section(".sdata")));
void Heap_Free(int, void*);
void func_001CE868(S13D_X*, void*);
void func_001CE888(S13D_X*, void*);
int func_0013DA80(S13D_X*);
void func_0013F4F8(void*, int*, int);
}

struct S13D_Ref {
    S13D_X* p;
    int unk4;
    int unk8;
    S13D_Ref(S13D_X* x) {
        unk4 = 0;
        unk8 = 0;
        p = x;
        if (p) {
            func_001CE868(p, this);
        }
    }
    ~S13D_Ref() {
        if (p) {
            func_001CE888(p, this);
            p = 0;
        }
    }
    S13D_Ref& operator=(const S13D_Ref& o) {
        if (p) {
            func_001CE888(p, this);
            p = 0;
        }
        p = o.p;
        if (p) {
            func_001CE868(p, this);
        }
        return *this;
    }
};

struct S_0013DF78 { char pad0[0x260]; float unk260; float unk264; };

extern "C" void func_0013DEB8(S13D_X* self) {
    if (self->unk258) {
        func_0013EB38(self, 0);
        if (self->unk258) {
            func_0014A910(self->unk258, 3);
        }
        self->unk258 = 0;
        func_0013E870(self, 1, 0);
    }
}

extern "C" void func_0013DF18(S13D_X* self, int on) {
    if (on) {
        if (!self->unk25C) {
            self->unk25C = 1;
            func_0013E870(self, self->unk254, 1);
        }
    } else {
        if (self->unk25C) {
            self->unk25C = 0;
            func_0013EB38(self, 1);
        }
    }
}

extern "C" void func_0013DF78(S_0013DF78* self, float a, float b) {
    self->unk260 = a;
    self->unk264 = b;
}

INCLUDE_ASM("asm/nonmatchings/game/t_13DEB8", func_0013DF88);

INCLUDE_ASM("asm/nonmatchings/game/t_13DEB8", func_0013E870);

extern "C" void func_0013EB38(S13D_X* self, int keep) {
    int i;
    if (self->unk250) {
        for (i = 0; i < self->unk254; i++) {
            func_001541A0(self->unk250[i]);
        }
        Heap_Free(D_00368A38[0], self->unk250);
        self->unk250 = 0;
    }
    if (!keep) {
        for (i = 0; i < self->unk254; i++) {
            func_001541A0(self->unk24C[i]);
        }
        Heap_Free(D_00368A38[0], self->unk24C);
        self->unk254 = 0;
    }
}

extern "C" void func_0013EC10(S13D_X* self) {
    void* p = func_0013C1F0(self);
    if (p) {
        if (self->unk254) {
            func_00154108(*self->unk24C, func_00148348(p));
        }
        if (self->unk25C) {
            func_00154108(*self->unk250, func_00148348(p));
        }
    }
}

extern "C" S13D_X* func_0013EC98(S13D_X* self) {
    S13D_C* c;
    func_00138F20(self);
    c = &self->unk288;
    c->r = 0;
    self->unk8 = D_0033AD98;
    c->a = 0x80;
    c->b = 0;
    c->g = 0;
    self->unk240 = 0;
    self->unk25C = 0;
    self->unk260 = 0;
    self->unk26C = 0;
    self->unk270 = 0;
    self->unk274 = 0;
    self->unk27C = 0;
    self->unk28C = 0;
    self->unk290 = 0;
    self->unk264 = 1.0f;
    self->unk268 = 1.0f;
    func_001CEDE0(self, 0x40D92263);
    return self;
}

extern "C" void func_0013ED28(S13D_X* self, int flags) {
    self->unk8 = D_0033AD98;
    if (self->unk274) {
        func_0014A910(self->unk274, 3);
    }
    func_00139420(self, flags);
}

INCLUDE_ASM("asm/nonmatchings/game/t_13DEB8", func_0013ED80);

INCLUDE_ASM("asm/nonmatchings/game/t_13DEB8", func_0013F258);

struct S13F3 {
    char pad0[0xC];
    u32 unkC;
    char pad10[0x1E4];
    float unk1F4;
    char pad1F8[0x48];
    int unk240;
    char pad244[0x14];
    int unk258;
    char pad25C[8];
    float unk264;
};

extern "C" {
int func_0014CD98_h(int, int) __asm__("func_0014CD98");
int func_0014CF50(int);
void func_001534C0(int, int, int);
void func_001535C0(int, u8*, float*, float*, int);
int func_00276008_h(int, int) __asm__("func_00276008");
}

extern "C" void func_0013F3E8(S13F3* self, int key) {
    self->unk240 = key;
    if (key == 0x0D53096F || key == 0x0A77F6AE) {
        self->unk240 = 0x7D70C638;
    }
    int h = func_0014CD98_h(self->unk240, 1);
    if (func_0014CF50(self->unk240) == 0) {
        int t = func_00276008_h(0x8751015E, 0);
        self->unk240 = t;
        if (t == 0) {
            self->unk240 = 0x35C0114B;
        }
        h = func_0014CD98_h(self->unk240, 1);
    }
    func_001534C0(h, 1, 0);
    float a, b;
    func_001535C0(h, D_00369660, &a, &b, -1);
    self->unkC |= 0x1000;
    self->unk258 = (int)self->unk1F4 / (int)(b * self->unk264);
}

INCLUDE_ASM("asm/nonmatchings/game/t_13DEB8", func_0013F4F8);

extern "C" void func_0013FC50(void* self, int v) {
    func_0013F4F8(self, &v, 1);
}

extern "C" {
int func_00113900(char*);
void func_00113AC8(char*, int, char*);
}

extern "C" int func_0013FC78(S13D_X* self, char* buf, int cap) {
    int len = 0;
    *buf = 0;
    S13D_Ref r(self->unk78);
    while (r.p) {
        S13D_Ref next(r.p->unk84);
        char* s = (char*)r.p->unk240;
        len += func_00113900(s);
        if (next.p) {
            len++;
        }
        if (len < cap) {
            func_00113AC8(buf, cap, s);
            if (next.p) {
                func_00113AC8(buf, cap, (char*)D_00369668);
            }
        } else {
            return 0;
        }
        r = next;
    }
    return 1;
}

extern "C" int func_0013FE00(S13D_X* self) {
    int n = 0;
    S13D_Ref r(self->unk78);
    while (r.p) {
        S13D_Ref next(r.p->unk84);
        n += func_0013DA80(r.p);
        if (next.p) {
            n++;
        }
        r = next;
    }
    return n;
}
