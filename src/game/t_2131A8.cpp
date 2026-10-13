#include "common.h"

struct VEntry213 {
    s16 delta;
    s16 unk2;
    void* fn;
};

struct S213 {
    char pad0[0x18];
    VEntry213* unk18;
    int unk1C;
    char pad20[0x8];
    void* unk28;
    int unk2C;
    char pad30[0x20];
    int unk50;
    char pad54[0x20];
    int unk74;
    char pad78[0x20];
    int unk98;
    char pad9C[0x260];
    int unk2FC;
    char pad300[0x20];
    int unk320;
    char pad324[0x20];
    int unk344;
    char pad348[0x20];
    int unk368;
    char pad36C[0x798];
    int unkB04;
    int unkB08;
    int unkB0C;
};

extern "C" {
void func_002120E8(int, int);
void func_00213520(int, int);
void func_00214350(int, int);
void func_002143F8(int, int);
void func_00214AB8(int, int);
void func_00113F38(void*, int);
extern u8 D_00342398[];
void func_00276D68(u32, void*, int);
extern u8 D_0038FED8[];
extern u8 D_00390028[];
void func_00118570(int);
void func_001184C0(int);
void func_001D1030_4(void*, int, int, int) __asm__("func_001D1030");
void* func_001D0F68(void*);
void func_001DE9C8(void*);
extern u8 D_00350E98[];
extern u8 D_00351180[];
void func_0016CF48(int, int);
void func_001CE888(int, void*);
void func_001D0F90(void*, int);
extern int D_00369A50[] __attribute__((section(".sdata")));
int func_0027D870(int, u32, int*, int);
void func_0027C448(int, u32, int);
int func_002141A8(int, int);
int func_002141F8(void);
void func_001DF718(void*);
void func_001DEC40(void*, int);
int func_002141F8_p(void*) __asm__("func_002141F8");
void func_002145C8(void);
int func_0027D268(int, u32, void*, int);
int func_0027D1F8(int, u32, int*, int);
void func_002140D8(int, int, int, f32);
}

struct C213 {
    u8 r, g, b, a;
    C213(u8 r_, u8 g_, u8 b_, u8 a_) {
        r = r_;
        g = g_;
        b = b_;
        a = a_;
    }
};

struct VP213 {
    char pad0[0x18];
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual s32 v12(int);
};

struct AP213 {
    s32 unk0;
    s32 unk4;
    s32 (VP213::*unk8)(int, int);
};

INCLUDE_ASM("asm/nonmatchings/game/t_2131A8", func_002131A8);

extern "C" void func_002132B8(void) {
    func_002120E8(1, 0xFFFF);
}

INCLUDE_ASM("asm/nonmatchings/game/t_2131A8", func_002132D8);

INCLUDE_ASM("asm/nonmatchings/game/t_2131A8", func_002134C8);

extern "C" void func_002134D8(S213* p, int v) {
    *(int*)((char*)p + 0x38) = v;
    if (p->unk1C) {
        func_00118570(v);
    } else {
        func_001184C0(v);
    }
}

INCLUDE_ASM("asm/nonmatchings/game/t_2131A8", func_00213518);

INCLUDE_ASM("asm/nonmatchings/game/t_2131A8", func_00213520);

extern "C" void func_002135C8(void) {
    func_00213520(1, 0xFFFF);
}

INCLUDE_ASM("asm/nonmatchings/game/t_2131A8", func_002135E8);

extern "C" void func_00213620(void) {
    func_00276D68(0x27D7CD28, D_0038FED8, 0x10);
}

extern "C" void* func_00213650(void* self) {
    char* p = (char*)self;
    func_001D0F68(p);
    *(void**)(p + 0x18) = D_00350E98;
    func_001DE9C8(p + 0x24);
    func_001DE9C8(p + 0x590);
    *(int*)(p + 0xAFC) = 0;
    *(u32*)(p + 4) = 0x27D7CD28;
    *(int*)(p + 0xB10) = 0;
    return p;
}

INCLUDE_ASM("asm/nonmatchings/game/t_2131A8", func_002136A8);

INCLUDE_ASM("asm/nonmatchings/game/t_2131A8", func_00213770);

extern "C" void func_002138B0(S213* self, int a) {
    VEntry213* e = &self->unk18[3];
    ((void (*)(void*, int))e->fn)((char*)self + e->delta, a);
}

extern "C" void func_002138D8(S213* self) {
    VEntry213* e = &self->unk18[8];
    ((void (*)(void*, int))e->fn)((char*)self + e->delta, 1);
}

extern "C" int func_00213908(int a, int s) {
    int v = 0;
    if ((func_0027D870(s, 0, &v, 0) ^ 1) != 0) return 1;
    f32 x = 1.0f;
    func_0027D268(s, 0x906B67BA, &x, 0);
    int y = 0;
    func_0027D1F8(s, 0x1A4E0EF9, &y, 0);
    func_002140D8(a, v, y != 0, x);
    return 1;
}

extern "C" int func_002139B8(S213* self) {
    self->unkB04 = 1;
    return 1;
}

extern "C" int func_002139C8(S213* self) {
    self->unkB04 = 0;
    return 1;
}

extern "C" int func_002139D8(S213* self) {
    self->unkB08 = 1;
    return 1;
}

extern "C" int func_002139E8(S213* self) {
    self->unkB08 = 0;
    return 1;
}

extern "C" int func_002139F8(S213* self) {
    return self->unkB04 || self->unkB08;
}

extern "C" int func_00213A20(S213* self) {
    return self->unk74 != 0;
}

extern "C" int func_00213A30(S213* self) {
    return self->unk98 != 0;
}

extern "C" int func_00213A40(S213* self) {
    return self->unk2C != 0;
}

extern "C" int func_00213A50(S213* self) {
    return self->unk50 != 0;
}

extern "C" int func_00213A60(S213* self) {
    return self->unk344 != 0;
}

extern "C" int func_00213A70(S213* self) {
    return self->unk368 != 0;
}

extern "C" int func_00213A80(S213* self) {
    return self->unk2FC != 0;
}

extern "C" int func_00213A90(S213* self) {
    return self->unk320 != 0;
}

INCLUDE_ASM("asm/nonmatchings/game/t_2131A8", func_00213AA0);

INCLUDE_ASM("asm/nonmatchings/game/t_2131A8", func_00213B80);

extern "C" int func_00213CD0(S213* self) {
    self->unkB0C = 1;
    return 1;
}

extern "C" int func_00213CE0(S213* self) {
    self->unkB0C = 0;
    return 1;
}

extern "C" int func_00213CF0(int a, int s, char* c) {
    int v;
    func_0027D870(s, 0, &v, 1);
    int t = *(int*)(c + 0x20);
    func_0027C448(t, 0xF54E05D4, func_002141A8(a, v));
    return 1;
}

INCLUDE_ASM("asm/nonmatchings/game/t_2131A8", func_00213D60);

extern "C" void func_00213E10(VP213* p, AP213* a, int x, int y) {
    if (a->unk8) {
        (p->*a->unk8)(x, y);
        return;
    }
    func_001D1030_4(p, a->unk0, x, y);
}

extern "C" void func_00213EA0(void) {
}

INCLUDE_ASM("asm/nonmatchings/game/t_2131A8", func_00213EA8);

INCLUDE_ASM("asm/nonmatchings/game/t_2131A8", func_002140D8);

INCLUDE_ASM("asm/nonmatchings/game/t_2131A8", func_002141A8);

INCLUDE_ASM("asm/nonmatchings/game/t_2131A8", func_002141F8);

extern "C" void func_00214350(int pp, int a1) {
    char* p = (char*)pp;
    if (*(u32*)(*(char**)(p + 0xC) + 0x154) & 1) return;
    func_002145C8();
    int t = func_002141F8_p(p);
    int v = 0;
    if (*(int*)(p + 0xB04) || *(int*)(p + 0xB08)) v = 1;
    if (v || t) {
        func_001DF718(p + 0x24);
        if (t) {
            *(int*)(p + 0x20) = 0;
            return;
        }
        return;
    }
    func_001DEC40(p + 0x24, a1);
}

extern "C" void func_002143F8(int pp, int a1) {
    char* p = (char*)pp;
    if (*(u32*)(*(char**)(p + 0xC) + 0x154) & 1) return;
    int t = func_002141F8();
    int v = 0;
    if (*(int*)(p + 0xB04) || *(int*)(p + 0xB08)) v = 1;
    if (v || t) {
        func_001DF718(p + 0x590);
        if (t) {
            *(int*)(p + 0x20) = 0;
            return;
        }
        return;
    }
    func_001DEC40(p + 0x590, a1);
}

INCLUDE_ASM("asm/nonmatchings/game/t_2131A8", func_00214498);

INCLUDE_ASM("asm/nonmatchings/game/t_2131A8", func_002145C8);

extern "C" void func_00214A68(S213* self) {
    func_00214350(self->unk2C, self->unk1C);
}

extern "C" void func_00214A88(S213* self) {
    func_002143F8(self->unk2C, self->unk1C);
}

INCLUDE_ASM("asm/nonmatchings/game/t_2131A8", func_00214AA8);

INCLUDE_ASM("asm/nonmatchings/game/t_2131A8", func_00214AB8);

extern "C" void func_00214FD0(S213* self, int flag) {
    self->unk18 = (VEntry213*)D_00342398;
    func_00113F38(self, flag);
}

extern "C" void func_00214FF8(S213* self) {
    ((void (*)(S213*))self->unk28)(self);
}

extern "C" void func_00215018(void) {
    func_00214AB8(1, 0xFFFF);
}

INCLUDE_ASM("asm/nonmatchings/game/t_2131A8", func_00215038);

extern "C" void func_00215078(void) {
    func_00276D68(0xA9DB601E, D_00390028, 0x10);
}

extern "C" void* func_002150A8(void* self) {
    char* p = (char*)self;
    func_001D0F68(p);
    int* q = (int*)(p + 0x20);
    *(void**)(p + 0x18) = D_00351180;
    q[1] = 0;
    q[2] = 0;
    *(u32*)(p + 4) = 0xA9DB601E;
    C213 c(0, 0, 255, 255);
    *(int*)(p + 0x1C) = 0;
    *(int*)(p + 0x20) = 0;
    *(int*)(p + 0x30) = 0;
    *(int*)(p + 0x38) = 0;
    *(int*)(p + 0x34) = 0;
    *(int*)(p + 0x3C) = 0;
    *(int*)(p + 0x40) = 0;
    return p;
}

extern "C" void func_00215128(char* p, int flags) {
    char* r = p + 0x20;
    *(void**)(p + 0x18) = D_00351180;
    if (*(int*)r) func_0016CF48(D_00369A50[0], *(int*)r);
    int t = *(volatile int*)r;
    if (t) {
        func_001CE888(t, r);
        *(int*)r = 0;
    }
    func_001D0F90(p, flags);
}
