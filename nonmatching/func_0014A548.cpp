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

INCLUDE_ASM("asm/nonmatchings/game/t_148688", func_00148E98);

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

INCLUDE_ASM("asm/nonmatchings/game/t_148688", func_00149AC0);

INCLUDE_ASM("asm/nonmatchings/game/t_148688", func_00149CA8);

INCLUDE_ASM("asm/nonmatchings/game/t_148688", func_00149E78);

extern "C" void func_00149FF0(S_148* self, P_148** p) {
    self->unk260 = (*p)->unk2C;
    self->unk270 = 1;
}

INCLUDE_ASM("asm/nonmatchings/game/t_148688", func_0014A008);

struct O_0014A548 { char pad0[0x1F0]; float unk1F0; float unk1F4; };
struct S_0014A548 { char pad0[0x25C]; char* unk25C; };

extern "C" {
void func_00139590(O_0014A548*, float*, float*);
void func_001395C0(O_0014A548*, float*, float*);
float func_00148248(void*);
float func_00148250(void*);
}

extern "C" void func_0014A548(S_0014A548* self, O_0014A548** pp, float* a, float* b, float* c, float* d) {
    float s[2];
    func_00139590(*pp, a, b);
    *a *= func_00148248(self->unk25C + 0xA0);
    *b *= func_00148250(self->unk25C + 0xA0);
    O_0014A548* o = *pp;
    float f = o->unk1F0;
    *c = f * func_00148248((char*)o + 0xA0) * func_00148248(self->unk25C + 0xA0);
    o = *pp;
    f = o->unk1F4;
    *d = f * func_00148250((char*)o + 0xA0) * func_00148250(self->unk25C + 0xA0);
    func_001395C0(*pp, s, &s[1]);
    *a -= (s[0] + 1.0f) * *c * 0.5f;
    *b -= (s[1] + 1.0f) * *d * 0.5f;
}
