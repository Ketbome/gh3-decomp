#include "common.h"

extern "C" {
void func_001773F8(void*, int, int, float, int, int);
int func_00172CC0(void*, u32, int);
int func_0027D268(int, u32, void*, int);
int func_0027D400(int, u32, void*, int);
int func_0027D470(int, u32, void*, int);
void Heap_Free(int, void*);
extern int D_00368A38[] __attribute__((section(".sdata")));
extern u8 D_003417B0[];
void func_00172CC8(void);
}


struct S176C78 { char pad0[0x20]; float unk20; char pad24[0xC]; int unk30; };

extern "C" int func_00176C78(S176C78* self, u32 key, int p) {
    int a;
    int b;
    float f;
    int c;
    float g;
    switch (key) {
    case 0x167F93A5:
        func_0027D400(p, 0x48C1A123, &a, 1);
        b = 0;
        func_0027D400(p, 0x7031F10C, &b, 0);
        f = -1.0f;
        func_0027D268(p, 0xBF237659, &f, 0);
        c = 0;
        func_0027D470(p, 0x326C4FF5, &c, 0);
        func_001773F8(self, a, b, f, c, 0);
        return 1;
    case 0x36ADB38E:
        func_0027D268(p, 0, &g, 1);
        self->unk20 = g;
        return 1;
    case 0x290D266C:
        self->unk30 = 1;
        return 1;
    default:
        return func_00172CC0(self, key, p);
    }
}

INCLUDE_ASM("asm/nonmatchings/game/t_176C78", func_00176DC0);

INCLUDE_ASM("asm/nonmatchings/game/t_176C78", func_00176FE0);

extern "C" void func_001773F0(void) {
}

INCLUDE_ASM("asm/nonmatchings/game/t_176C78", func_001773F8);

extern "C" u32 func_00177828(void) {
    return 0xF221474C /* linear */;
}

extern "C" void func_00177838(void** self, int flags) {
    *self = D_003417B0;
    if (flags & 1) {
        Heap_Free(D_00368A38[0], self);
    }
}

extern "C" float func_00177878(float v) {
    return v;
}

extern "C" u32 func_00177880(void) {
    return 0xF1B82F5A /* degenerateblend */;
}

extern "C" void func_00177890(void** self, int flags) {
    *self = D_003417B0;
    if (flags & 1) {
        Heap_Free(D_00368A38[0], self);
    }
}

INCLUDE_ASM("asm/nonmatchings/game/t_176C78", func_001778D0);

struct N177 { N177* prev; N177* next; void* val; };
struct It177 { int unk0; N177* cur; int pad8[2]; };
struct V177 { void* unk0; void* unk4; };
struct S177 { char pad0[0x18]; float unk18; float unk1C; int unk20; char pad24[4]; N177 sent; };
extern "C" {
void* Heap_Alloc(int, int, int, int);
int func_0027D650(int, u32, void*, int);
void func_001785D0(void*, int, int, float, int, int);
void* func_0017F298(void*, int);
extern u8 D_00341788[];
}

extern "C" int func_001779F0(void* self_, u32 key, int p) {
    S177* self = (S177*)self_;
    int a;
    int b;
    float f;
    int c;
    int t;
    It177 r, end, e2;
    switch (key) {
    case 0xF24B98E6:
        a = 0;
        func_0027D650(p, 0x48C1A123, &a, 1);
        b = 0;
        func_0027D400(p, 0x7031F10C, &b, 0);
        f = -1.0f;
        func_0027D268(p, 0xBF237659, &f, 0);
        c = 0;
        func_0027D470(p, 0x326C4FF5, &c, 0);
        func_001785D0(self, a, b, f, c, 0);
        self->unk20 = 0;
        return 1;
    case 0x8D940652: {
        self->unk18 = self->unk1C;
        self->unk20 = 1;
        func_0027D268(p, 0xBF237659, &self->unk18, 0);
        t = 0;
        func_0027D470(p, 0xF3D2E0A4, &t, 0);
        N177* sp = &self->sent;
        N177* first = self->sent.next;
        int cnt = 0;
        end.cur = sp;
        r.cur = first;
        e2.cur = first;
        if (first != sp) {
            do {
                cnt++;
                e2.cur = e2.cur->next;
            } while (e2.cur != sp);
        }
        if (cnt != 0) {
            if (t != 0) {
                r.cur = self->sent.prev;
                V177* v = (V177*)r.cur->val;
                v->unk4 = func_0017F298(Heap_Alloc(D_00368A38[0], 0xC, 1, 0), t);
            } else {
                r.cur = self->sent.prev;
                V177* v = (V177*)r.cur->val;
                void** q = (void**)Heap_Alloc(D_00368A38[0], 4, 1, 0);
                *q = D_00341788;
                v->unk4 = q;
            }
        }
        return 1;
    }
    default:
        return func_00172CC0(self, key, p);
    }
}

INCLUDE_ASM("asm/nonmatchings/game/t_176C78", func_00177BD8);

INCLUDE_ASM("asm/nonmatchings/game/t_176C78", func_00177FB0);

extern "C" void func_001785C8(void) {
}

INCLUDE_ASM("asm/nonmatchings/game/t_176C78", func_001785D0);

INCLUDE_ASM("asm/nonmatchings/game/t_176C78", func_00178860);

INCLUDE_ASM("asm/nonmatchings/game/t_176C78", func_00178880);

INCLUDE_ASM("asm/nonmatchings/game/t_176C78", func_00178910);

extern "C" void func_00178920(void) {
    func_00172CC8();
}

INCLUDE_ASM("asm/nonmatchings/game/t_176C78", func_00178940);

INCLUDE_ASM("asm/nonmatchings/game/t_176C78", func_00178AB0);
