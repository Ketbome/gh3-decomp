#include "common.h"

typedef unsigned int u128_14E __attribute__((mode(TI)));

struct S14E_L {
    char pad0[0x4];
    u32 unk4;
    int unk8;
    S14E_L* unkC;
    S14E_L* unk10;
    void* unk14;
};

struct S14E_V {
    int unk0;
    char pad4[0x8C];
    virtual void v1();
    virtual void v2();
};

extern "C" {
void func_0014F910(int, int);
extern int D_00373254[] __attribute__((section(".sdata")));
extern int D_00373258;
extern S14E_L* D_00378204[];
void func_0014E6A8(void);
int func_0028DAB8(void);
int func_0014E7E8(int);
extern u8 D_0033C3A0[];
extern u8 D_0033C388[];
void func_0014F978(S14E_L*, int);
int func_0027D268(void*, u32, float*, int);
void func_0014F150(void*);
void func_001820D0(void*);
void func_00182180(void*);
int func_001150B8(int);
extern S14E_L D_003781F8;
int func_0015D6F0(void*);
int func_00182468(void*, float);
extern int D_00368A38[] __attribute__((section(".sdata")));
void func_00119400(int, void*);
extern int D_00369A70;
extern int D_00369A78;
extern u8 D_004159F0[];
extern int D_00369A6C;
void func_001822F0(void);
void func_00182338(void);
void func_00182370(void);
void func_001823A8(void);
void func_00182448(void);
void func_00182428(void);
void func_00182078(void);
void func_00182110(void);
void func_001821B8(void);
void func_001821E0(void);
void func_001822A8(void);
void func_001822E0(void);
void func_00182488(void);
void func_00182498(void*);
void func_001827B0(void);
void func_00182798(void);
void func_001827F0(void);
void func_001827A8(void);
void func_00182818(void);
void func_00182820(void);
void func_00182828(void);

}

INCLUDE_ASM("asm/nonmatchings/game/t_14E7E0", func_0014E7E0);

INCLUDE_ASM("asm/nonmatchings/game/t_14E7E0", func_0014E7E8);

extern "C" int func_0014E850(void) {
    return func_0014E7E8(func_0028DAB8());
}

INCLUDE_ASM("asm/nonmatchings/game/t_14E7E0", func_0014E878);

INCLUDE_ASM("asm/nonmatchings/game/t_14E7E0", func_0014E8E0);

extern "C" S14E_L* func_0014E948(void) {
    S14E_L* p = D_00378204[0];
    if (p->unk4 == 0xFFFFFFFF) {
        p = 0;
    }
    return p;
}

INCLUDE_ASM("asm/nonmatchings/game/t_14E7E0", func_0014E960);

extern "C" void func_0014E968(void) {
    func_001822F0();
}

extern "C" void func_0014E988(void) {
    func_00182338();
}

extern "C" void func_0014E9A8(void) {
    func_00182370();
}

extern "C" void func_0014E9C8(void) {
    func_001823A8();
}

INCLUDE_ASM("asm/nonmatchings/game/t_14E7E0", func_0014E9E8);

INCLUDE_ASM("asm/nonmatchings/game/t_14E7E0", func_0014EA70);

extern "C" void func_0014EAC8(void) {
    func_00182448();
}

extern "C" void func_0014EAE8(void) {
    func_00182428();
}

extern "C" void func_0014EB08(void) {
    func_00182078();
}

extern "C" void func_0014EB28(void* self) {
    func_0014F150(self);
    func_001820D0(self);
}

extern "C" void func_0014EB58(void) {
    func_00182110();
}

extern "C" void func_0014EB78(void* self) {
    func_0014F150(self);
    func_00182180(self);
}

extern "C" void func_0014EBA8(void) {
    func_001821B8();
}

extern "C" void func_0014EBC8(void) {
    func_001821E0();
}

INCLUDE_ASM("asm/nonmatchings/game/t_14E7E0", func_0014EBE8);

INCLUDE_ASM("asm/nonmatchings/game/t_14E7E0", func_0014EC58);

extern "C" void func_0014ED00(void) {
    func_001822A8();
}

extern "C" void func_0014ED20(void) {
    func_001822E0();
}

INCLUDE_ASM("asm/nonmatchings/game/t_14E7E0", func_0014ED40);

INCLUDE_ASM("asm/nonmatchings/game/t_14E7E0", func_0014ED50);

extern "C" u8* func_0014F0D0(void) {
    return D_004159F0;
}

INCLUDE_ASM("asm/nonmatchings/game/t_14E7E0", func_0014F0E0);

extern "C" void func_0014F130(void) {
    func_00182488();
}

extern "C" void func_0014F150(void* self) {
    func_00182498(self);
}

INCLUDE_ASM("asm/nonmatchings/game/t_14E7E0", func_0014F170);

GP_DATA(D_00369A6C);
extern "C" void func_0014F1A0(void) {
    D_00369A6C ^= 1;
}

extern "C" void func_0014F1B0(void) {
    func_001827B0();
}

extern "C" void func_0014F1D0(int a, int b) {
    D_00373254[0] = b;
    D_00373258 = a;
}

extern "C" int func_0014F1E0(void* self, float f) {
    if (func_0015D6F0(self) >= 2) {
        return 0;
    }
    return func_00182468(self, f);
}

INCLUDE_ASM("asm/nonmatchings/game/t_14E7E0", func_0014F230);

INCLUDE_ASM("asm/nonmatchings/game/t_14E7E0", func_0014F268);

extern "C" int CFunc_ToggleAddScenes(void) {
    func_0014E6A8();
    return 1;
}

INCLUDE_ASM("asm/nonmatchings/game/t_14E7E0", func_0014F298);

extern "C" void func_0014F708(void) {
    func_00182798();
}

INCLUDE_ASM("asm/nonmatchings/game/t_14E7E0", func_0014F728);

extern "C" int func_0014F738(void) {
    return D_00369A70;
}

extern "C" void func_0014F740(int v) {
    D_00369A78 = v;
}

extern "C" int func_0014F748(void) {
    return D_00369A78;
}

INCLUDE_ASM("asm/nonmatchings/game/t_14E7E0", func_0014F750);

extern "C" void func_0014F7B8(void) {
    func_001827F0();
}

INCLUDE_ASM("asm/nonmatchings/game/t_14E7E0", func_0014F7D8);

extern "C" void func_0014F800(void) {
    func_001827A8();
}

INCLUDE_ASM("asm/nonmatchings/game/t_14E7E0", func_0014F820);

extern "C" int CFunc_CheckFlexibleParticleStructure(void* params) {
    float f;
    return func_0027D268(params, 0x8E9A640E, &f, 0) != 0;
}

extern "C" int CFunc_CheckSplineParticleStructure(void* params) {
    float f;
    return func_0027D268(params, 0x35B65BD4, &f, 0) != 0;
}

extern "C" int CFunc_EngineConfig(void) {
    return 0;
}

extern "C" int CFunc_EngineCreateWaterRipple(void) {
    return 0;
}

extern "C" int CFunc_EngineWind(void) {
    return 0;
}

extern "C" int CFunc_EngineUpdateFXMaterial(void) {
    return 0;
}

extern "C" void func_0014F8A8(void) {
    func_00182818();
}

extern "C" void func_0014F8C8(void) {
    func_00182820();
}

extern "C" void func_0014F8E8(void) {
    func_00182828();
}

INCLUDE_ASM("asm/nonmatchings/game/t_14E7E0", func_0014F908);

INCLUDE_ASM("asm/nonmatchings/game/t_14E7E0", func_0014F910);

extern "C" void func_0014F958(u128_14E* dst, u128_14E a, u128_14E b) {
    dst[0] = a;
    dst[1] = b;
}
TEXT_PAD(20);

extern "C" void func_0014F978(S14E_L* self, int flags) {
    self->unk14 = D_0033C388;
    self->unk10->unkC = self->unkC;
    self->unkC->unk10 = self->unk10;
    self->unkC = self;
    self->unk10 = self;
    if (flags & 1) {
        func_00119400(D_00368A38[0], self);
    }
}

extern "C" void func_0014F9D8(S14E_L* self, int flags) {
    self->unk14 = D_0033C3A0;
    func_0014F978(self, flags);
}

extern "C" void func_0014FA00(void) {
    func_0014F910(1, 0xFFFF);
}

INCLUDE_ASM("asm/nonmatchings/game/t_14E7E0", func_0014FA20);

INCLUDE_ASM("asm/nonmatchings/game/t_14E7E0", func_0014FB78);

INCLUDE_ASM("asm/nonmatchings/game/t_14E7E0", func_0014FD50);

INCLUDE_ASM("asm/nonmatchings/game/t_14E7E0", func_0014FF18);

INCLUDE_ASM("asm/nonmatchings/game/t_14E7E0", func_0014FF20);

INCLUDE_ASM("asm/nonmatchings/game/t_14E7E0", func_0014FFF0);

INCLUDE_ASM("asm/nonmatchings/game/t_14E7E0", func_00150190);

INCLUDE_ASM("asm/nonmatchings/game/t_14E7E0", func_00150358);

INCLUDE_ASM("asm/nonmatchings/game/t_14E7E0", func_00150400);

extern "C" void func_00150520(S14E_V* self, int x) {
    self->unk0 = func_001150B8(x);
    self->v2();
}

INCLUDE_ASM("asm/nonmatchings/game/t_14E7E0", func_00150560);
