#include "common.h"

struct S139_X;

static inline int S139_Locked(struct S139_X* self);

struct S139_R {
    S139_X* p;
    int unk4;
    int unk8;
};

struct S139_X {
    char pad0[0xC];
    u32 unkC;
    char pad10[0x1C];
    int unk2C;
    char pad30[0x48];
    S139_X* unk78;
    char pad7C[0x8];
    S139_X* unk84;
    char pad88[0x18];
    float unkA0;
    char padA4[0x4C];
    float unkF0;
    char padF4[0x4C];
    float unk140;
};

extern "C" {
void* func_0015DB00(int);
float func_001230D0(void*, void*, float*, float*, int*, int);
void func_00139AE8(void*, int, int, float, float);
void func_0013C550(void*, void*);
void func_001CE868(S139_X*, S139_R*);
void func_001CE888(S139_X*, S139_R*);
void func_0013C080(S139_R*, S139_X*, int, int*);
void func_0013A8C0(S139_X*, int, void*);
void func_001CF538(S139_X*, int, void*);
int func_0027B300(void*, int);
extern int D_0036D554;
int func_001DAC78(int, int, int, int, int, int, f32);
}

struct S139_Ref {
    S139_X* p;
    int unk4;
    int unk8;
    S139_Ref(S139_X* const& x) {
        unk4 = 0;
        unk8 = 0;
        p = x;
        if (p) {
            func_001CE868(p, (S139_R*)this);
        }
    }
    ~S139_Ref() {
        if (p) {
            func_001CE888(p, (S139_R*)this);
            p = 0;
        }
    }
    S139_Ref& operator=(S139_X* x) {
        if (p) {
            func_001CE888(p, (S139_R*)this);
            p = 0;
        }
        p = x;
        if (p) {
            func_001CE868(p, (S139_R*)this);
        }
        return *this;
    }
};

static inline int S139_Locked(S139_X* self) {
    if (self->unkC & 0x4000) {
        return 1;
    }
    return 0;
}


struct S_00139E98 { char pad0[0xC]; int unkC; char pad1[0x1EC]; float unk1FC; };

extern "C" void func_00139CE8(S139_X* self, float v, int both) {
    if (self->unkF0 != v) {
        self->unkF0 = v;
        self->unk140 = self->unkA0;
        self->unkC |= 0x400;
    }
    if (both && self->unkA0 != v) {
        self->unkA0 = v;
        self->unk140 = v;
        self->unkC |= 0x400;
    }
}

INCLUDE_ASM("asm/nonmatchings/game/t_139CE8", func_00139D50);

extern "C" void func_00139E98(S_00139E98* self, float v) {
    self->unk1FC = v;
    self->unkC |= 0x9000;
}

extern "C" void func_00139EB0(S139_X* self, int flag) {
    if (flag) {
        self->unkC |= 0x20000;
    } else {
        self->unkC &= ~0x20000;
    }
}

extern "C" void func_00139EE0(S139_X* self, int on) {
    if (on == S139_Locked(self)) {
        return;
    }
    if (on == 1) {
        self->unkC |= 0x4000;
    } else {
        self->unkC &= ~0x4000;
    }
    int d = D_0036D554;
    if (on == 1) {
        func_001DAC78(d, 0x3056434F /* notify_child_lock */, self->unk2C, 0x36B2EE74 /* system */, 0, 0, -1.0f);
    } else {
        func_001DAC78(d, 0x4A57316B /* notify_child_unlock */, self->unk2C, 0x36B2EE74 /* system */, 0, 0, -1.0f);
    }
}

extern "C" S139_X* func_00139F98(S139_X* self) {
    S139_X* c = self->unk78;
    while (c) {
        if (!*(S139_X* volatile*)&c->unk84) break;
        c = c->unk84;
    }
    return c;
}

extern "C" S139_X* func_00139FC0(S139_X* self, int a, int* b) {
    S139_R r;
    S139_X* p;
    func_0013C080(&r, self, a, b);
    p = r.p;
    if (p) {
        func_001CE888(p, &r);
        r.p = 0;
    }
    return p;
}

extern "C" S139_X* func_0013A010(S139_X* self, int a) {
    S139_R r;
    S139_X* p;
    func_0013C080(&r, self, 0, &a);
    p = r.p;
    if (p) {
        func_001CE888(p, &r);
        r.p = 0;
    }
    return p;
}

extern "C" int func_0013A060(S139_X* self) {
    S139_Ref r(self->unk78);
    int n = 0;
    while (r.p) {
        r = r.p->unk84;
        n++;
    }
    return n;
}

INCLUDE_ASM("asm/nonmatchings/game/t_139CE8", func_0013A100);

INCLUDE_ASM("asm/nonmatchings/game/t_139CE8", func_0013A288);

INCLUDE_ASM("asm/nonmatchings/game/t_139CE8", func_0013A770);

INCLUDE_ASM("asm/nonmatchings/game/t_139CE8", func_0013A8C0);

extern "C" void func_0013B038(S139_X* self, void* list) {
    int it = func_0027B300(list, 0);
    while (it) {
        func_0013A8C0(self, it, list);
        func_001CF538(self, it, list);
        it = func_0027B300(list, it);
    }
}

struct C139 { u8 r, g, b, a; };
struct Q139 {
    float unk0;
    char pad4[0x1C];
    float unk20;
    float unk24;
    char pad28[0xC];
    float unk34;
    float unk38;
    char pad3C[8];
    float unk44;
};
struct P13B {
    char pad0[0xA0];
    Q139 unkA0;
    char pad_[0x48 - sizeof(Q139)];
    C139 unkE8;
    char padEC[0xF4];
    float unk1E0;
    float unk1E4;
    char pad1E8[0x14];
    float unk1FC;
};

extern "C" {
void func_0027C1F8(int, u32, float);
void func_0027C5B0(int, u32, float, float);
void func_0027C160_b(int, u32, int) __asm__("func_0027C160");
void* func_00138790_b(int, int) __asm__("func_00138790");
int func_0027E698(void*);
void func_0027E760(int, int, int);
void func_0027EDE0(int, int, int);
void func_0027EE08(int, int, float);
void func_0027C678(int, u32, int);
void func_0027C740(int, u32, int);
void func_002798B8(int);
void func_0027E6B0(int, int);
int func_0013CE58(void*);
}

extern "C" void func_0013B0B0(P13B* self, int params) {
    Q139* q = &self->unkA0;
    func_0027C1F8(params, 0x2F1FC695, self->unkA0.unk0);
    C139 c = self->unkE8;
    int arr = func_0027E698(func_00138790_b(0xC, 1));
    func_0027E760(arr, 4, 1);
    func_0027EDE0(arr, 0, c.r);
    func_0027EDE0(arr, 1, c.g);
    func_0027EDE0(arr, 2, c.b);
    func_0027EDE0(arr, 3, c.a);
    func_0027C678(params, 0x3F6BCDBA, arr);
    func_002798B8(arr);
    if (arr) {
        func_0027E6B0(arr, 3);
    }
    float a = q->unk34;
    float b = q->unk38;
    if (a == b) {
        func_0027C1F8(params, 0x13B9DA7B, a);
    } else {
        func_0027C5B0(params, 0x13B9DA7B, a, b);
    }
    Q139* r = &self->unkA0;
    func_0027C5B0(params, 0x7F261953, r->unk20, r->unk24);
    func_0027C1F8(params, 0xED344E1B, r->unk44 * 57.295776f);
    if (func_0013CE58(self) != 0) {
        func_0027C160_b(params, 0x73CB6D65, 1);
    } else {
        func_0027C160_b(params, 0x73CB6D65, 0);
    }
    func_0027C1F8(params, 0x57710F31, self->unk1FC);
    int arr2 = func_0027E698(func_00138790_b(0xC, 1));
    func_0027E760(arr2, 2, 2);
    func_0027EE08(arr2, 0, self->unk1E0);
    func_0027EE08(arr2, 1, self->unk1E4);
    func_0027C740(params, 0x8B60022F, arr2);
}

INCLUDE_ASM("asm/nonmatchings/game/t_139CE8", func_0013B2C8);

INCLUDE_ASM("asm/nonmatchings/game/t_139CE8", func_0013B608);

INCLUDE_ASM("asm/nonmatchings/game/t_139CE8", func_0013B7E0);

INCLUDE_ASM("asm/nonmatchings/game/t_139CE8", func_0013B8F8);

INCLUDE_ASM("asm/nonmatchings/game/t_139CE8", func_0013BA48);
