#include "common.h"

struct F1FB6 {
    char pad0[0x10];
    f32 unk10;
    f32 unk14;
    f32 unk18;
    f32 unk1C;
    f32 unk20;
    f32 unk24;
};

struct S1F9D_N {
    s32 unk0;
    S1F9D_N* unk4;
    char* unk8;
};

struct S1F9D_I {
    s32 unk0;
    S1F9D_N* unk4;
};

typedef int TI128 __attribute__((mode(TI)));

struct S1FADE8 {
    char pad0[0x18];
    virtual void v1();
    virtual void v2();
};

extern "C" {
s32 func_0012CEE8(void* a, s32 b);
void func_0027DC58(s32 a, s32 b, s32* c, s32 d);
void func_00267760(s32 a, void* b, s32 c);
s32 func_001F9AA8(void);
s32 func_001F9B80(void);
void func_001FA348(int, int);
void func_001FB028(void*);
void func_001FB6C0(s32 self, s32 params);
void* operator_new(u32);
void* func_001FAC90(void*);
extern char D_0038F5B0[];
void func_00276D68(u32, void*, int);
void func_001FB480(void*, TI128);
TI128 func_001EAEA0(s32 a, s32 b);
s32 func_0027D870(s32 a, s32 key, s32* v, s32 req);
s32 func_001EB300(s32 a);
void func_002676F0(s32 a, void* b);
void func_001D0F90(void* a, s32 b);
extern u8 D_0034F6F0[];
extern s32 D_00370AE0;
void func_0027D1F8(s32 p, u32 key, s32* v, s32 req);
void func_001FAF90(char* self, s32 params);
void* func_00268EB8(s32 a, s32 b, s32 c, s32 d);
void* func_001FB450_o(s32 a, s32 b) __asm__("func_001FB450");
s32 func_0027D268(s32 p, u32 key, f32* v, s32 d);
}

INCLUDE_ASM("asm/nonmatchings/game/t_1F9A48", func_001F9A48);

extern "C" s32 func_001F9A50(s32 a, u32 k) {
    s32 r = 0;
    if (k != 0x26205DB6) {
        if (k == 0x7E1940A1) {
            r = func_001F9AA8();
        }
    } else {
        r = func_001F9B80();
    }
    return r;
}

INCLUDE_ASM("asm/nonmatchings/game/t_1F9A48", func_001F9AA8);

INCLUDE_ASM("asm/nonmatchings/game/t_1F9A48", func_001F9B80);

INCLUDE_ASM("asm/nonmatchings/game/t_1F9A48", func_001F9C58);

extern "C" s32 func_001F9D18(char* p, s32 v) {
    S1F9D_I it;
    S1F9D_I end;
    it.unk4 = *(S1F9D_N**)(p + 0x4C);
    end.unk4 = (S1F9D_N*)(p + 0x48);
    if (it.unk4 != end.unk4) {
        do {
            if (*(s32*)(it.unk4->unk8 + 0x10) == v) {
                return 1;
            }
            it.unk4 = it.unk4->unk4;
            end.unk4 = (S1F9D_N*)(p + 0x48);
        } while (it.unk4 != end.unk4);
    }
    return 0;
}

INCLUDE_ASM("asm/nonmatchings/game/t_1F9A48", func_001F9D68);

INCLUDE_ASM("asm/nonmatchings/game/t_1F9A48", func_001F9D70);

INCLUDE_ASM("asm/nonmatchings/game/t_1F9A48", func_001F9E80);

extern "C" s32 func_001F9EC0(char* p) {
    return *(s32*)(p + 0x2C);
}

extern "C" s32 func_001F9EC8(char* p, s32 k) {
    S1F9D_I it;
    S1F9D_I end;
    s32 r;
    it.unk4 = *(S1F9D_N**)(p + 0x40);
    end.unk4 = (S1F9D_N*)(p + 0x3C);
    if (it.unk4 != end.unk4) {
        do {
            r = func_0012CEE8((char*)it.unk4 + 8, k);
            if (r != 0) {
                goto done;
            }
            it.unk4 = it.unk4->unk4;
            end.unk4 = (S1F9D_N*)(p + 0x3C);
        } while (it.unk4 != end.unk4);
    }
    r = 0;
done:
    return r != 0;
}

INCLUDE_ASM("asm/nonmatchings/game/t_1F9A48", func_001F9F40);

INCLUDE_ASM("asm/nonmatchings/game/t_1F9A48", func_001FA218);

INCLUDE_ASM("asm/nonmatchings/game/t_1F9A48", func_001FA330);

INCLUDE_ASM("asm/nonmatchings/game/t_1F9A48", func_001FA348);

extern "C" void func_001FAC18() {
    func_001FA348(1, 0xFFFF);
}

extern "C" void* func_001FAC38() {
    return func_001FAC90(operator_new(0xE0));
}

extern "C" void func_001FAC60() {
    func_00276D68(0x07713C7B, D_0038F5B0, 0x10);
}

INCLUDE_ASM("asm/nonmatchings/game/t_1F9A48", func_001FAC90);

INCLUDE_ASM("asm/nonmatchings/game/t_1F9A48", func_001FAD10);

INCLUDE_ASM("asm/nonmatchings/game/t_1F9A48", func_001FAD68);

extern "C" void func_001FADB8(char* p) {
    TI128 a = *(TI128*)(p + 0xB0);
    *(TI128*)(p + 0xC0) = a;
    *(TI128*)(p + 0xB0) = *(TI128*)(*(char**)(p + 0xC) + 0x80);
    func_001FB480(p, a);
}

extern "C" void func_001FADE8(S1FADE8* p) {
    p->v2();
}

extern "C" s32 func_001FAE10(void* p) {
    func_001FB028(p);
    return 1;
}

extern "C" s32 func_001FAE30(void* p, s32 q) {
    func_001FB6C0((s32)p, q);
    return 1;
}

INCLUDE_ASM("asm/nonmatchings/game/t_1F9A48", func_001FAE50);

extern "C" s32 func_001FAEC0(void* p, s32 q) {
    func_001FAF90((char*)p, q);
    return 1;
}

extern "C" s32 func_001FAEE0() {
    return 2;
}

INCLUDE_ASM("asm/nonmatchings/game/t_1F9A48", func_001FAEE8);

extern "C" void func_001FAF88(void) {
}

struct A1FAF {
    char pad0[0x1C];
    s32 unk1C[9];
};

extern "C" void func_001FAF90(char* self, s32 params) {
    s32 a = -1;
    s32 b = 0;
    func_0027D1F8(params, 0x7321A8D6, &a, 0);
    func_0027DC58(params, 0, &b, 0);
    if (a != -1 && b != 0) {
        if (a < 9 && a != -1) {
            ((A1FAF*)self)->unk1C[a] = b;
        }
    }
}

INCLUDE_ASM("asm/nonmatchings/game/t_1F9A48", func_001FB028);

INCLUDE_ASM("asm/nonmatchings/game/t_1F9A48", func_001FB390);

INCLUDE_ASM("asm/nonmatchings/game/t_1F9A48", func_001FB3D0);

INCLUDE_ASM("asm/nonmatchings/game/t_1F9A48", func_001FB450);

INCLUDE_ASM("asm/nonmatchings/game/t_1F9A48", func_001FB480);

INCLUDE_ASM("asm/nonmatchings/game/t_1F9A48", func_001FB618);

extern "C" void func_001FB6C0(s32 self, s32 params) {
    f32 a = 100.0f;
    f32 b = 100.0f;
    s32 id;
    func_0027DC58(params, 0, &id, 0);
    F1FB6* o = (F1FB6*)func_00268EB8(D_00370AE0, self, id, 1);
    if (o != 0 || (o = (F1FB6*)func_001FB450_o(self, id), o != 0)) {
        if (func_0027D268(params, 0x330F3415, &a, 0) != 0) {
            o->unk24 = o->unk1C * a * 0.01f;
            if ((func_0027D268(params, 0xDAA9A3C2, (f32*)((char*)o + 0x2C), 0) ^ 1) != 0) {
                o->unk14 = o->unk24;
            }
        }
        if (func_0027D268(params, 0xEE616C13, &b, 0) != 0) {
            o->unk20 = o->unk18 * b * 0.01f;
            if ((func_0027D268(params, 0x7B090774, (f32*)((char*)o + 0x28), 0) ^ 1) != 0) {
                o->unk10 = o->unk20;
            }
        }
    }
}

INCLUDE_ASM("asm/nonmatchings/game/t_1F9A48", func_001FB820);

INCLUDE_ASM("asm/nonmatchings/game/t_1F9A48", func_001FB938);

INCLUDE_ASM("asm/nonmatchings/game/t_1F9A48", func_001FB998);
