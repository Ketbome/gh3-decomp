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
int func_00114030(void*);
void func_00113FB8(void*);
void func_0027C1F8(int, u32, f32);
f32 func_001DF538(void*, f32, f32, f32);
int func_001DF390(void*);
u32 func_0011EF10(void);
void func_001DE9C0(int, f32);
void func_001DE8E8(int, int);
void func_001DE9A8(int);
void func_001DE9B0(int);
int func_0027D400(int, u32, int*, int);
int func_0027DF00(int, u32);
int func_001CD6C0(int, int);
void func_00213EA8(char*, int);
extern int D_0036D020;
extern int D_00368740;
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

struct V3520 {
    int a;
    int b;
};

struct E3520 {
    u32 key;
    u32 type;
    V3520 v;
};

extern E3520 T3520[] __asm__("D_0038FEB8");
extern V3520 S3520_0[] __asm__("D_0036ED10");
extern "C" void* memset(void*, int, unsigned int);

extern "C" void func_00213520(int a, int b) {
    if (b == 0xFFFF && a != 0) {
        E3520* e = T3520;
        V3520 t;
        e->key = 0xDF8A5F0A;
        t = *S3520_0;
        e->type = 0x404EB936;
        e->v = t;
        e++;
        memset(&t, 0, 8);
        e->key = 0;
        e->type = 0x404EB936;
        e->v = t;
    }
}

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

struct D213 {
    char pad0[0x18];
    virtual void v1();
    virtual ~D213();
};

extern "C" void func_002136A8(char* p, int flags) {
    *(void**)(p + 0x18) = D_00350E98;
    if (*(void**)(p + 0xAFC)) {
        if (func_00114030(*(void**)(p + 0xAFC))) func_00113FB8(*(void**)(p + 0xAFC));
        if (*(void**)(p + 0xAFC)) delete (D213*)*(void**)(p + 0xAFC);
    }
    if (*(void**)(p + 0xB00)) {
        if (func_00114030(*(void**)(p + 0xB00))) func_00113FB8(*(void**)(p + 0xB00));
        if (*(void**)(p + 0xB00)) delete (D213*)*(void**)(p + 0xB00);
    }
    func_001D0F90(p, flags);
}

extern "C" void func_00213770(char* self, int params) {
    int a;
    int b;
    u32 k;
    if (func_0027D1F8(params, 0x67E6859A, &a, 0)) {
        func_00213EA8(self, func_001CD6C0(D_0036D020, a));
    } else if (func_0027D1F8(params, 0xB30D9965, &a, 0)) {
        func_00213EA8(self, a);
    }
    if (func_0027D400(params, 0xB9B1E3B6, &b, 0)) {
        switch (D_00368740) {
        case 6:
            k = 0xF6A179C0;
            break;
        case 7:
            k = 0xEF8D059E;
            break;
        case 5:
            k = 0xBCF00D45;
            break;
        case 4:
            k = 0x87D839B8;
            break;
        case 1:
        case 2:
        case 3:
        case 8:
        case 9:
        default:
            k = 0x988A3508;
            break;
        }
        func_0027D870(b, k, (int*)(self + 0xB10), 1);
    }
    int f = func_0027DF00(params, 0xE20E54C5) ^ 1;
    *(int*)(self + 0x584) = f;
    *(int*)(self + 0xAF0) = f;
}

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

extern "C" int func_00213AA0(char* p, int a1, char* c) {
    char* t = p + 0x24;
    func_0027C1F8(*(int*)(c + 0x20), 0x737F15CF, *(f32*)(p + 0x3BC) * 57.295776f);
    int u = *(int*)(c + 0x20);
    func_0027C1F8(u, 0x686AD1C2, func_001DF538(t, *(f32*)(t + 0x36C), *(f32*)(t + 0x370), *(f32*)(t + 0x398)));
    func_0027C1F8(*(int*)(c + 0x20), 0xD6030CEA, *(f32*)(p + 0x3B4) * 57.295776f);
    int w = *(int*)(c + 0x20);
    func_0027C1F8(w, 0xC94777AC, func_001DF538(t, *(f32*)(t + 0x364), *(f32*)(t + 0x368), *(f32*)(t + 0x390)));
    return 1;
}

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

extern "C" {
void func_001CE218(void*, int);
void func_001CE248(void*, u32);
void func_00214498(void*, void*, int, int, u32, u32, void*);
int func_002765E0(u32, int);
void func_002145C8_d(char*, char*) __asm__("func_002145C8");
}

extern "C" void func_002145C8_d(char* self, char* a) {
    int t = *(int*)(self + 0x20);
    *(int*)(self + 0x20) = 0;
    *(int*)(self + 0x1C) = t;
    if (func_002765E0(0xF3E055E1, 1) != 0 && (*(u32*)(a + 0x34) & 0x100)) {
        func_001CE218(a, -0x101);
        func_001CE248(a, 0xDFFFFFFF);
    }
    if (*(int*)(self + 0xB0C) != 0 && *(int*)(self + 0xB04) == 0) {
        func_00214498(self, a, 6, 0x40, 0x5C8FAA09, 0xB27804A2, self + 0x28);
        func_00214498(self, a, 7, 0x80, 0xD26ADAE9, 0xAEF7DFD3, self + 0x4C);
        func_00214498(self, a, 5, 0x20, 0xB4F2ADBA, 0xC86FA880, self + 0x70);
        func_00214498(self, a, 4, 0x10, 0x0EDBBC2B, 0xC8ABF89C, self + 0x94);
        func_00214498(self, a, 9, 0x200, 0xB069B600, 0xE5AAE06B, self + 0x190);
        func_00214498(self, a, 0xB, 0x800, 0xA93DBBD0, 0xFCFEEDBB, self + 0x1B4);
        func_00214498(self, a, 8, 0x100, 0x7F695A77, 0x7B684919, self + 0x1D8);
        func_00214498(self, a, 0xA, 0x400, 0x42717176, 0xBBBEF674, self + 0x1FC);
        func_00214498(self, a, 0xC, 0x1000, 0xC6547217, 0x28A3DCBC, self + 0xB8);
        func_00214498(self, a, 0xE, 0x4000, 0x5F5D23AD, 0xB1AA8D06, self + 0xDC);
        func_00214498(self, a, 0x10, 0x10000, 0x285A133B, 0xC6ADBD90, self + 0x100);
        func_00214498(self, a, 0xD, 0x2000, 0x12154DC8, 0xFCE2E363, self + 0x124);
        func_00214498(self, a, 0xF, 0x8000, 0x8B1C1C72, 0x65EBB2D9, self + 0x148);
        func_00214498(self, a, 0x11, 0x20000, 0xFC1B2CE4, 0x12EC824F, self + 0x16C);
        func_00214498(self, a, 0x1A, 0x04000000, 0x33947317, 0xF5E437A0, 0);
        func_00214498(self, a, 0x1B, 0x08000000, 0xF8DE049B, 0x3EAE402C, 0);
        func_00214498(self, a, 0x1D, 0x20000000, 0x2F2C39B9, 0x7AEF6FD2, self + 0x244);
        func_00214498(self, a, 0x1C, 0x10000000, 0xAC7F105A, 0x55B09758, 0);
        func_00214498(self, a, 0x14, 0x100000, 0xC61BDD1D, 0xC71B4373, self + 0x268);
        func_00214498(self, a, 0x15, 0x200000, 0x32A573B7, 0xDE6C8ADD, self + 0x28C);
        func_00214498(self, a, 0x13, 0x80000, 0x543D04E4, 0xB8F4FD8E, self + 0x2B0);
        func_00214498(self, a, 0x12, 0x40000, 0x82E80F71, 0x2F634ECE, self + 0x2D4);
        func_00214498(self, a, 0x18, 0x01000000, 0x9E4CBA43, 0x45A3D202, self + 0x2F8);
        func_00214498(self, a, 0x19, 0x02000000, 0xC54BAFC1, 0x6F40E300, self + 0x31C);
        func_00214498(self, a, 0x17, 0x800000, 0xA3D3D892, 0x09D89453, self + 0x340);
        func_00214498(self, a, 0x16, 0x400000, 0x3B7935A4, 0xD7B0CCCE, self + 0x364);
    }
}

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
