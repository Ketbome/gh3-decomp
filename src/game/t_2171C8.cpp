#include "common.h"

struct S217 {
    char pad0[0x20];
    void* unk20;
};

extern "C" {
void func_00217A80(int, int);
void* operator_new(u32 size);
void* func_00218088(void*);
void* func_001D0F68(void*);
void func_0016C5C0(void*, int);
void func_00276D68(u32, void*, int);
extern u8 D_00390198[];
int func_0027D058(int, int, void*, int);
void func_0016CA18(int, f32);
void func_0016C4F8(int);
void func_0016C6B8(int, f32);
void func_0016C6C0(int, int, f32);
int func_0027D000(int, int, void*, int);
int func_0027D118(int, int, void*, int);
int func_0011A5B8(int, int);
int func_0016C878(int, int, void*);
int func_0016C8F8(int, void*);
void func_001CE888(void*, void*);
void func_001D0F90(void*, int);
extern u8 D_00351368[];
}

struct D217 {
    char pad0[0x8];
    virtual ~D217();
};

static inline void Release217(void** pp) {
    if (*pp) {
        func_001CE888(*pp, pp);
        *pp = 0;
    }
}

extern "C" int func_002171C8(int* p, int a) {
    f32 v[4];
    func_0027D058(a, 0, v, 1);
    if (p[8]) {
        func_0016CA18(p[8], v[0]);
        func_0016C4F8(p[8]);
    }
    return 1;
}

extern "C" int func_00217220(int* p, int a) {
    f32 v[4];
    func_0027D058(a, 0, v, 1);
    if (p[8]) {
        func_0016C6B8(p[8], v[0]);
        func_0016C4F8(p[8]);
    }
    return 1;
}

extern "C" int func_00217278(int* p, int a) {
    f32 v[4];
    func_0027D058(a, 0, v, 1);
    if (p[8]) {
        func_0016C6C0(p[8], 0, v[0]);
        func_0016C4F8(p[8]);
    }
    return 1;
}

extern "C" int func_002172D0(int* p, int a) {
    f32 v[4];
    func_0027D058(a, 0, v, 1);
    if (p[8]) {
        func_0016C6C0(p[8], 1, v[0]);
        func_0016C4F8(p[8]);
    }
    return 1;
}

extern "C" int func_00217328(int* p, int a) {
    f32 v[4];
    func_0027D058(a, 0, v, 1);
    if (p[8]) {
        func_0016C6C0(p[8], 2, v[0]);
        func_0016C4F8(p[8]);
    }
    return 1;
}

extern "C" int func_00217380(int* p, int a) {
    u8 c[4];
    int h;
    func_0027D118(a, 0, &h, 1);
    if (p[8]) {
        c[0] = func_0011A5B8(h, 0);
        c[1] = func_0011A5B8(h, 1);
        c[2] = func_0011A5B8(h, 2);
        c[3] = func_0011A5B8(h, 3);
        func_0016C878(p[8], 0, c);
    }
    return 1;
}

extern "C" int func_00217410(int* p, int a) {
    u8 c[4];
    int h;
    func_0027D118(a, 0, &h, 1);
    if (p[8]) {
        c[0] = func_0011A5B8(h, 0);
        c[1] = func_0011A5B8(h, 1);
        c[2] = func_0011A5B8(h, 2);
        c[3] = func_0011A5B8(h, 3);
        func_0016C878(p[8], 1, c);
    }
    return 1;
}

extern "C" int func_002174A0(int* p, int a) {
    u8 c[4];
    int h;
    func_0027D118(a, 0, &h, 1);
    if (p[8]) {
        c[0] = func_0011A5B8(h, 0);
        c[1] = func_0011A5B8(h, 1);
        c[2] = func_0011A5B8(h, 2);
        c[3] = func_0011A5B8(h, 3);
        func_0016C878(p[8], 2, c);
    }
    return 1;
}

extern "C" int func_00217530(int* p, int a) {
    int v[4];
    v[0] = 0;
    func_0027D000(a, 0, v, 0);
    if (p[8]) {
        *(int*)(p[8] + 0x1A0) = v[0] == 1;
    }
    return 1;
}

extern "C" int func_00217588(int* p, int a) {
    u8 c[4];
    int h;
    func_0027D118(a, 0, &h, 1);
    if (p[8]) {
        c[0] = func_0011A5B8(h, 0);
        c[1] = func_0011A5B8(h, 1);
        c[2] = func_0011A5B8(h, 2);
        c[3] = func_0011A5B8(h, 3);
        func_0016C8F8(p[8], c);
    }
    return 1;
}

INCLUDE_ASM("asm/nonmatchings/game/t_2171C8", func_00217618);

extern "C" int func_00217A48(S217* self) {
    if (self->unk20) {
        func_0016C5C0(self->unk20, 1);
    }
    return 1;
}

INCLUDE_ASM("asm/nonmatchings/game/t_2171C8", func_00217A78);

INCLUDE_ASM("asm/nonmatchings/game/t_2171C8", func_00217A80);

extern "C" void func_00218010(void) {
    func_00217A80(1, 0xFFFF);
}

extern "C" void* func_00218030(void) {
    return func_00218088(operator_new(0x70));
}

extern "C" void func_00218058(void) {
    func_00276D68(0xC5BCEB9E, D_00390198, 0x10);
}

struct C217 {
    u8 r, g, b, a;
    C217(u8 r_, u8 g_, u8 b_, u8 a_) {
        r = r_;
        g = g_;
        b = b_;
        a = a_;
    }
};

extern "C" void* func_00218088(void* self) {
    int* p = (int*)self;
    func_001D0F68(p);
    p[6] = (int)D_00351368;
    int* q = p + 7;
    q[1] = 0;
    q[2] = 0;
    p[1] = 0xC5BCEB9E;
    C217 c(0, 0x80, 0x80, 0xFF);
    p[7] = 0;
    p[10] = 0;
    p[11] = 0;
    p[21] = 0;
    p[22] = 0;
    p[26] = 0;
    p[20] = 0;
    p[12] = 0;
    p[13] = 0;
    p[23] = 0;
    p[24] = 0;
    p[25] = 0;
    return p;
}

extern "C" void func_00218120(int* p, int flags) {
    void** r = (void**)&p[7];
    p[6] = (int)D_00351368;
    if (*r) {
        delete (D217*)*r;
        Release217(r);
        *r = 0;
    }
    Release217((void**)&p[7]);
    func_001D0F90(p, flags);
}

INCLUDE_ASM("asm/nonmatchings/game/t_2171C8", func_002181C8);
