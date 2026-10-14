#include "common.h"

struct R_144 { void* p; int unk4; int unk8; };
struct VE_144 { s16 delta; s16 unk2; void* fn; };
struct Sys_144 { char pad0[0x2C]; VE_144* unk2C; };
struct N_144 { char pad0[0x4]; void* unk4; char pad8[0x4]; N_144* unkC; };
struct L_144 { char pad0[0x10]; N_144* unk10; };

struct H_144;

extern "C" {
void func_00145068(int, H_144, int, int, void*);
extern int D_00372B20;
extern int D_00372B28;
extern int D_00372B30;
extern int D_00372B38;
extern Sys_144* D_00369798;
extern u32 D_0036979C;
void* func_00113DF0(int, int, int);
Sys_144* func_001444F0(void*);
int func_00145B10(int, void*, u32, int*);
void func_00145310(R_144*, int, int, int);
void func_001CE868(void*, R_144*);
void func_001CE888(void*, R_144*);
void func_00139EB0(void*, int);
void func_001443D8(int, int);
}

INCLUDE_ASM("asm/nonmatchings/game/t_1443D0", func_001443D0);

GP_DATA(D_00372B20);
GP_DATA(D_00372B28);
GP_DATA(D_00372B30);
GP_DATA(D_00372B38);
extern "C" void func_001443D8(int a, int b) {
    if (b == 0xFFFF && a) {
        D_00372B20 = 0x91C1EC93;
        D_00372B28 = 0xD2C041C2;
        D_00372B30 = 0xAEE1AF7D;
        D_00372B38 = 0xB1A55798;
    }
}

extern "C" void func_00144428(void) {
    func_001443D8(1, 0xFFFF);
}

GP_DATA(D_00369798);
GP_DATA(D_0036979C);
extern "C" Sys_144* func_00144448(int a) {
    if (!D_00369798 && a) {
        D_00369798 = func_001444F0(func_00113DF0(0x770, 0, 1));
    }
    D_0036979C++;
    return D_00369798;
}

extern "C" void func_00144498(void) {
    if (D_0036979C >= 2) {
        D_0036979C--;
        return;
    }
    if (D_00369798) {
        VE_144* e = &D_00369798->unk2C[1];
        ((void (*)(void*, int))e->fn)((char*)D_00369798 + e->delta, 3);
    }
    D_00369798 = 0;
    D_0036979C = 0;
}

INCLUDE_ASM("asm/nonmatchings/game/t_1443D0", func_001444F0);

INCLUDE_ASM("asm/nonmatchings/game/t_1443D0", func_00144858);

INCLUDE_ASM("asm/nonmatchings/game/t_1443D0", func_00144BC0);

struct H_144 {
    void* p;
    int unk4;
    int unk8;
    H_144(const R_144& o) : unk4(0), unk8(0) {
        p = o.p;
        if (p) func_001CE868(p, (R_144*)this);
    }
};

extern "C" void func_00144FC0(int sys, int id, int a, int b, void* script) {
    R_144 r;
    func_00145310(&r, sys, id, 1);
    func_00145068(sys, H_144(r), a, b, script);
    if (r.p) {
        func_001CE888(r.p, &r);
        r.p = 0;
    }
}

INCLUDE_ASM("asm/nonmatchings/game/t_1443D0", func_00145068);

INCLUDE_ASM("asm/nonmatchings/game/t_1443D0", func_001451C0);

INCLUDE_ASM("asm/nonmatchings/game/t_1443D0", func_00145310);

extern "C" R_144* func_00145488(R_144* out, int sys, void* params, u32 hash, int flag) {
    int id = 0;
    if (func_00145B10(sys, params, hash, &id)) {
        func_00145310(out, sys, id, flag);
    } else {
        out->unk4 = 0;
        out->unk8 = 0;
        out->p = 0;
    }
    return out;
}

INCLUDE_ASM("asm/nonmatchings/game/t_1443D0", func_00145508);

INCLUDE_ASM("asm/nonmatchings/game/t_1443D0", func_00145510);

struct RR_144 {
    void* p;
    int unk4;
    int unk8;
    RR_144(void* x) : unk4(0), unk8(0) {
        p = x;
        if (p) func_001CE868(p, (R_144*)this);
    }
    ~RR_144() {
        if (p) {
            func_001CE888(p, (R_144*)this);
            p = 0;
        }
    }
};

static inline N_144* N_144_Get(N_144* n) {
    return n->unk4 != (void*)-1 ? n : 0;
}

extern "C" void func_00145558(L_144* self, int x) {
    N_144* n = N_144_Get(self->unk10);
    while (n) {
        RR_144 r(n->unk4);
        func_00139EB0(r.p, x);
        n = N_144_Get(n->unkC);
    }
}

INCLUDE_ASM("asm/nonmatchings/game/t_1443D0", func_001455F0);

INCLUDE_ASM("asm/nonmatchings/game/t_1443D0", func_00145B10);

INCLUDE_ASM("asm/nonmatchings/game/t_1443D0", func_00145ED0);

INCLUDE_ASM("asm/nonmatchings/game/t_1443D0", func_00145EF8);

extern "C" void func_00146070(void) {
}

extern "C" char* func_00146078(char* p) {
    return p + 0x4;
}

INCLUDE_ASM("asm/nonmatchings/game/t_1443D0", func_00146080);

INCLUDE_ASM("asm/nonmatchings/game/t_1443D0", func_00146280);

INCLUDE_ASM("asm/nonmatchings/game/t_1443D0", func_00146378);
