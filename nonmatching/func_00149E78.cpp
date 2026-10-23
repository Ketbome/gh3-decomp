#include "common.h"

struct S_148 { char pad0[0x8]; void* unk8; char padC[0x234]; int unk240; int unk244; char pad248[0x10]; int unk258; char pad25C[4]; int unk260; char pad264[0xC]; int unk270; };
struct P_148 { char pad0[0x2C]; int unk2C; };

struct S25C_148 { char pad0[0x25C]; float unk25C; };

extern "C" {
int func_0027D1F8(void*, int, int*, int);
bool func_0027DF00(void*, u32);
int func_0013A060(void*);
int func_0013B608(void*, u32, void*);
extern u8 D_0033B838[];
extern u8 D_0033B7C0[];
extern u8 D_0033BB78[];
extern u8 D_0033BBA0[];
void func_00148508(void*);
void* func_00148490(void*);
void func_001CEDE0(void*, u32);
void* func_00138F20(void*);
void func_001D8A88(void*, int);
void func_001D8B30(void*, void*);
void func_001CEE88(void*, u32, int);
void func_001CEE38(void*, u32, int);
void func_001D8AB8(void*, int);
void func_00139420(void*, int);
}

INCLUDE_ASM("asm/nonmatchings/game/t_148688", func_00148688);

extern "C" int func_00148C98(S25C_148* self, float* out) {
    *out = self->unk25C;
    return self->unk25C > 0.0001f;
}

INCLUDE_ASM("asm/nonmatchings/game/t_148688", func_00148CD0);

struct H148 { int unk0; int unk4; int unk8; };
struct P148 { char pad[0x10]; };

extern "C" {
void func_00145310_n(H148*, int, int, int) __asm__("func_00145310");
void func_00148CD0_n(S_148*, int, int, int) __asm__("func_00148CD0");
void func_001CE888_n(int, H148*) __asm__("func_001CE888");
void func_001CEF58_n(int, u32, int*) __asm__("func_001CEF58");
void func_001DAC78_p(int, u32, int, int, P148*, int, float) __asm__("func_001DAC78");
void func_0027AA70_p(P148*) __asm__("func_0027AA70");
void func_0027AC90_p(P148*) __asm__("func_0027AC90");
void func_0027C160_p(P148*, u32, int) __asm__("func_0027C160");
extern int D_0036D554;
extern int D_00369798;
}

static inline void H148_Rel(H148* h) {
    int p = h->unk0;
    if (p) {
        func_001CE888_n(p, h);
        h->unk0 = 0;
    }
}

extern "C" void func_00148E98(S_148* self, int a1) {
    int g = D_0036D554;
    int idx = -1;
    P148 p;
    H148* hp = (H148*)&p;
    if (self->unk244) {
        func_00145310_n(hp, D_00369798, self->unk244, 0);
        int t = hp->unk0;
        H148_Rel(hp);
        if (t) func_001CEF58_n(t, 0x8321DD71, &idx);
        func_001DAC78_p(g, 0x4ADF0CD3, self->unk244, 0x36B2EE74, 0, 0, -1.0f);
    }
    func_00148CD0_n(self, a1, 0, 1);
    if (self->unk244) {
        func_0027AA70_p(&p);
        func_0027C160_p(&p, 0xB30D9965, *(int*)((char*)self + 0x24C));
        if (idx != -1) func_0027C160_p(&p, 0xFACF9A8B, idx);
        func_001DAC78_p(g, 0x9D3FB516, self->unk244, 0x36B2EE74, &p, 0, -1.0f);
        func_0027AC90_p(&p);
    }
}

extern "C" void func_00148FF0(S_148* self) {
    func_001CEE88(self, 0xAC988EBE, self->unk244);
    func_001CEE38(self, 0xF2239871, self->unk240);
    func_001CEE38(self, 0x8321DD71, self->unk270);
}

INCLUDE_ASM("asm/nonmatchings/game/t_148688", func_00149048);

extern "C" int func_00149658(S_148* self, u32 key, void* params) {
    if (key == 0x305B3C41) {
        int sel = self->unk240;
        int res = 0;
        if (sel == -1) {
            return 0;
        }
        int idx;
        if (func_0027D1F8(params, 0, &idx, 0)) {
            res = sel == idx;
        } else if (func_0027DF00(params, 0x6D8E11A8)) {
            res = sel == 0;
        } else if (func_0027DF00(params, 0xB524565F)) {
            res = sel == func_0013A060(self) - 1;
        }
        return res;
    }
    return func_0013B608(self, key, params);
}

extern "C" S_148* func_00149730(S_148* self) {
    func_00148490(self);
    self->unk8 = D_0033B838;
    self->unk258 = 1;
    func_001CEDE0(self, 0x130EF802);
    return self;
}

extern "C" void func_00149780(S_148* self) {
    self->unk8 = D_0033B838;
    func_00148508(self);
}

extern "C" S_148* func_001497A8(S_148* self) {
    func_00148490(self);
    self->unk8 = D_0033B7C0;
    self->unk258 = 0;
    func_001CEDE0(self, 0xCCDED1E1);
    return self;
}

extern "C" void func_001497F0(S_148* self) {
    self->unk8 = D_0033B7C0;
    func_00148508(self);
}

INCLUDE_ASM("asm/nonmatchings/game/t_148688", func_00149818);

struct S_149820 {
    char pad0[0x8];
    void* unk8;
    char padC[0x234];
    char unk240[0x18];
    void* unk258;
    int unk25C;
    int unk260;
    char pad264[8];
    int unk26C;
    int unk270;
    int unk274;
    float unk278;
    int unk27C;
    int unk280;
    float unk284;
};

extern "C" S_149820* func_00149820(S_149820* self) {
    func_00138F20(self);
    func_001D8A88(self->unk240, 1);
    void* x = D_0033BB78;
    void* y = D_0033BBA0;
    self->unk8 = y;
    self->unk258 = x;
    func_001D8B30(self->unk240, self);
    self->unk25C = 0;
    self->unk260 = 0;
    self->unk26C = 0;
    self->unk270 = 0;
    self->unk274 = 0;
    self->unk280 = 0;
    self->unk278 = 10000.0f;
    self->unk27C = -1;
    self->unk284 = -1.0f;
    func_001CEDE0(self, 0x84298A3C);
    return self;
}

extern "C" void func_001498D0(S_148* self, int flags) {
    self->unk258 = (int)D_0033BB78;
    self->unk8 = D_0033BBA0;
    func_001D8AB8(&self->unk240, 0);
    func_00139420(self, flags);
}

INCLUDE_ASM("asm/nonmatchings/game/t_148688", func_00149930);

struct E149 { u32 unk0; char pad4[0xC]; int unk10; };
struct VT149 { char pad0[0x68]; s16 delta; s16 pad6A; void (*fn)(void*); };
struct T149 { char pad0[0x2C]; int unk2C; };
struct S149 {
    char pad0[8];
    VT149* unk8;
    char padC[4];
    int unk10;
    char pad14[0x18];
    int unk2C;
    char pad30[0x22C];
    T149* unk25C;
    char pad260[0xC];
    int unk26C;
    int unk270;
};

extern "C" {
int func_00146E68_n(int) __asm__("func_00146E68");
int func_001468A8_n(int, u32) __asm__("func_001468A8");
int func_0013CF78_n(S149*) __asm__("func_0013CF78");
int func_00146E78_n(int, int) __asm__("func_00146E78");
int func_001D00B0_n(S149*, E149*) __asm__("func_001D00B0");
void func_00149E78(S149*);
void func_001D8A08_n(E149*, int, int) __asm__("func_001D8A08");
void func_001DAC78_n(int, u32, int, int, int, int, float) __asm__("func_001DAC78");
extern int D_0036D554;
}

extern "C" int func_00149AC0(S149* self, E149* ev) {
    int a = 0;
    int h = self->unk10;
    if (func_00146E68_n(h) != 0 && func_001468A8_n(h, ev->unk0) != 0 && (func_0013CF78_n(self) == 0 || func_00146E78_n(h, self->unk2C) == 0)) {
        a = 1;
    }
    if (a != 0) {
        return 0;
    }
    if (func_001D00B0_n(self, ev) == 0) {
        return 0;
    }
    int g = D_0036D554;
    if (ev->unk0 == 0x3056434F) {
        func_00149E78(self);
        self->unk270 = 1;
        self->unk8->fn((char*)self + self->unk8->delta);
        func_001D8A08_n(ev, self->unk2C, 0);
    }
    if (ev->unk0 == 0x9D3FB516) {
        if (self->unk25C == 0) {
            func_00149E78(self);
        }
        if (self->unk26C == 0) {
            self->unk26C = 1;
            func_001DAC78_n(g, 0x9D3FB516, self->unk25C->unk2C, 0x36B2EE74, ev->unk10, 0, -1.0f);
            func_001D8A08_n(ev, self->unk2C, 0);
        }
    }
    int k = 0;
    if (ev->unk0 == 0x4ADF0CD3) {
        k = self->unk26C != 0;
    }
    if (k != 0) {
        func_00149E78(self);
        self->unk26C = 0;
        func_001DAC78_n(g, 0x4ADF0CD3, self->unk25C->unk2C, 0x36B2EE74, 0, 0, -1.0f);
        func_001D8A08_n(ev, self->unk2C, 0);
    }
    return 1;
}

INCLUDE_ASM("asm/nonmatchings/game/t_148688", func_00149CA8);

struct O_00149E78 { char pad0[0x20]; u32 unk20; char pad24[0x60]; O_00149E78* unk84; };
struct S_00149E78 {
    char pad0[0x78];
    O_00149E78* unk78;
    char pad7C[0x174];
    float unk1F0;
    float unk1F4;
    char pad1F8[0x64];
    O_00149E78* unk25C;
    char pad260[0x1C];
    int unk27C;
    float unk280;
    float unk284;
    int unk288;
};
struct H_00149E78;
extern "C" {
void func_001CE868_h(void*, H_00149E78*) __asm__("func_001CE868");
void func_001CE888_h(void*, H_00149E78*) __asm__("func_001CE888");
int func_00148C98_o(void*, float*) __asm__("func_00148C98");
}
struct H_00149E78 {
    O_00149E78* p;
    int unk4;
    int unk8;
    H_00149E78(O_00149E78* x) : unk4(0), unk8(0) {
        p = x;
        if (p) func_001CE868_h(p, this);
    }
    void Set(O_00149E78* x) {
        if (p) {
            func_001CE888_h(p, this);
            p = 0;
        }
        p = x;
        if (p) func_001CE868_h(p, this);
    }
};

extern "C" void func_00149E78_x(S_00149E78* self) __asm__("func_00149E78");
extern "C" void func_00149E78_x(S_00149E78* self) {
    H_00149E78 it(self->unk78);
    while (it.p) {
        u32 k = it.p->unk20;
        int c = 0;
        if (k == 0x130EF802) {
            c = 1;
            if (self->unk288 == 0) c = 0;
        }
        int d = 0;
        if (c == 0) {
            if (k == 0xCCDED1E1) {
                d = 1;
                if (self->unk288 != 0) d = 0;
            }
        }
        if (c != 0 || d != 0) self->unk25C = it.p;
        O_00149E78* n = it.p->unk84;
        it.Set(n);
    }
    float sp10 = -1.0f;
    if (func_00148C98_o(self->unk25C, &sp10)) {
        int c = self->unk27C;
        if (c >= 0) {
            self->unk284 = sp10;
            self->unk280 = sp10 * (float)c;
            goto done;
        }
    }
    self->unk27C = -1;
    self->unk280 = self->unk288 ? self->unk1F4 : self->unk1F0;
done:
    if (it.p) {
        func_001CE888_h(it.p, &it);
        it.p = 0;
    }
}

extern "C" void func_00149FF0(S_148* self, P_148** p) {
    self->unk260 = (*p)->unk2C;
    self->unk270 = 1;
}

INCLUDE_ASM("asm/nonmatchings/game/t_148688", func_0014A008);

INCLUDE_ASM("asm/nonmatchings/game/t_148688", func_0014A548);
