#include "common.h"

struct S_00117F10 { char pad0[0xF8]; int unkF8; };
struct S_00118570 { char pad0[0xD4]; int unkD4; };

struct S_00117D20 { char pad0[0x1C]; void (*unk1C)(void); };

struct VEntry {
    s16 delta;
    s16 unk2;
    void* fn;
};

struct SA116_V {
    char pad0[0x20];
    VEntry* unk20;
};

struct SA116_C {
    int unk0;
    int unk4;
};

struct SA116_P {
    char pad0[0x18];
    int unk18;
    char pad1C[0x48];
    u8 unk64[0x20];
    u8 unk84[0x28];
    u8 unkAC[0x20];
    SA116_C unkCC;
    int unkD4;
    int unkD8;
    char padDC[0x8];
    int unkE4;
    char padE8[0x4];
    int unkEC;
};

struct SA116_D {
    char pad0[0x8];
    void* unk8;
};

struct SA116_L {
    char pad0[0xC];
    SA116_L* unkC;
    SA116_L* unk10;
    void* unk14;
};

struct SA116_Sema {
    int unk0;
    int unk4;
    int unk8;
    int unkC;
    int unk10;
    int unk14;
};

extern "C" {
void func_0011A470(int);
extern u8 D_00338510[];
void* func_00113D20(u32);
void func_00118168(void*, int, int, int);
void func_002ED120(int);
u32 func_001180D8();
void func_00117F50(void*);
extern int D_00368A38[] __attribute__((section(".sdata")));
extern SA116_V* D_003688E8;
extern u32 D_003688EC;
extern u32 D_00368738;
extern u8 D_00338448[];
extern u8 D_00338490[];
extern u8 D_003687C8[];
extern u8 D_003687D0[];
extern u8 D_003687D8[];
extern u8 D_003687E0[];
extern u8 D_003687E8[];
extern u8 D_003687F0[];
extern u8 D_003687F8[];
void func_00119400(int, void*);
int func_00113DF0(int, int, int);
void func_002ED798(int, int, void*, int, void*);
SA116_V* func_00117520(int);
extern int D_00368778;
extern u8 D_00375308[];
void func_00122DE0(void);
void func_00113F38(void);
extern int D_00368750;
extern u8 D_003687C0[];
extern u8 D_003686F0[];
void func_0030A970(u8*, int);
extern int D_003689E0;
extern int D_00373248;
void func_002EE6A0(int);
void func_002EE680(int);
int func_002EE660(void*);
void func_002EE670(int);
}

extern "C" u8* func_00116E38(void) {
    return D_00375308;
}

extern "C" void func_00116E48(int a) {
    func_0030A970(D_00375308, a);
}

GP_DATA(D_00368750);
extern "C" u8* func_00116E70(void) {
    if (D_00368750) return D_003687C0;
    return D_003686F0;
}

GP_DATA(D_00368738);
extern "C" u8* func_00116E90(void) {
    switch (D_00368738) {
    case 0x4C9908C7:
        return D_003687C8;
    case 0x41D88638:
        return D_003687D0;
    case 0x99CAE6AB:
        return D_003687D8;
    case 0x6F2ADD9F:
        return D_003687E0;
    case 0x0C8B4164:
        return D_003687E8;
    case 0x28979C12:
        return D_003687F0;
    case 0x84678404:
        return D_003687F8;
    case 0x77B12AAB:
    default:
        return D_003686F0;
    }
}

INCLUDE_ASM("asm/nonmatchings/game/t_116E38", func_00116F90);

INCLUDE_ASM("asm/nonmatchings/game/t_116E38", func_00117030);

extern "C" void func_001170A8(void) {
    func_00122DE0();
}

extern "C" void func_001170C8(int v) {
    D_00368778 = v;
}

extern "C" int func_001170D0(void) {
    return D_00368778;
}

INCLUDE_ASM("asm/nonmatchings/game/t_116E38", func_001170D8);

extern "C" void func_00117108(void) {
}

extern "C" int CFunc_CreatePlatformMessageBox(void) {
    return 0;
}

GP_DATA(D_003688E8);
GP_DATA(D_003688EC);
extern "C" SA116_V* func_00117118(int a) {
    if (D_003688E8 == 0 && a) {
        D_003688E8 = func_00117520(func_00113DF0(0x24, 0, 1));
    }
    D_003688EC++;
    return D_003688E8;
}

extern "C" void func_00117168(void) {
    if (D_003688EC >= 2) {
        D_003688EC--;
    } else {
        SA116_V* p = D_003688E8;
        if (p) {
            VEntry* e = &p->unk20[1];
            ((void (*)(void*, int))e->fn)((char*)p + e->delta, 3);
        }
        D_003688E8 = 0;
        D_003688EC = 0;
    }
}

INCLUDE_ASM("asm/nonmatchings/game/t_116E38", func_001171C0);

extern "C" void func_00117270(int a, int b, int c, int d) {
    func_00118168(func_00113D20(0x100), b, c, d);
}

INCLUDE_ASM("asm/nonmatchings/game/t_116E38", func_001172C8);

INCLUDE_ASM("asm/nonmatchings/game/t_116E38", func_00117520);

INCLUDE_ASM("asm/nonmatchings/game/t_116E38", func_001177D8);

INCLUDE_ASM("asm/nonmatchings/game/t_116E38", func_00117940);

INCLUDE_ASM("asm/nonmatchings/game/t_116E38", func_001179F8);

INCLUDE_ASM("asm/nonmatchings/game/t_116E38", func_00117AA0);

INCLUDE_ASM("asm/nonmatchings/game/t_116E38", func_00117B50);

extern "C" void func_00117C00(void) {
    func_00113F38();
}

extern "C" void func_00117C20(SA116_D* self, int flags) {
    self->unk8 = D_00338448;
    if (flags & 1) {
        func_00119400(D_00368A38[0], self);
    }
}

extern "C" void func_00117C60(SA116_L* self, int flags) {
    self->unk14 = D_00338490;
    self->unk10->unkC = self->unkC;
    self->unkC->unk10 = self->unk10;
    self->unkC = self;
    self->unk10 = self;
    if (flags & 1) {
        func_00119400(D_00368A38[0], self);
    }
}

extern "C" void func_00117CC0(SA116_L* self, int flags) {
    self->unk14 = D_00338490;
    self->unk10->unkC = self->unkC;
    self->unkC->unk10 = self->unk10;
    self->unkC = self;
    self->unk10 = self;
    if (flags & 1) {
        func_00119400(D_00368A38[0], self);
    }
}

extern "C" void func_00117D20(S_00117D20* self) {
    self->unk1C();
}

INCLUDE_ASM("asm/nonmatchings/game/t_116E38", func_00117D40);

struct S117DD0 { char pad0[0xEC]; int unkEC; int unkF0; };

extern "C" void func_00117DD0(S117DD0* self) {
    if (func_001180D8() != 3) {
        int t = self->unkF0;
        self->unkF0 = 0;
        self->unkEC = t;
    }
}

INCLUDE_ASM("asm/nonmatchings/game/t_116E38", func_00117E10);

extern "C" int func_00117F10(S_00117F10* self) {
    return self->unkF8;
}

extern "C" void func_00117F18(void* self) {
    if (func_001180D8() < 2U) {
        func_00117F50(self);
    }
}

INCLUDE_ASM("asm/nonmatchings/game/t_116E38", func_00117F50);

INCLUDE_ASM("asm/nonmatchings/game/t_116E38", func_001180D8);

INCLUDE_ASM("asm/nonmatchings/game/t_116E38", func_00118168);

struct VE_118290 { s16 unk0; s16 unk2; void (*unk4)(void*, int); };
struct V_118290 { char pad0[8]; VE_118290 unk8; };
struct O_118290 { char pad0[0x14]; V_118290* unk14; };
struct S_118290 { char pad0[4]; O_118290* unk4; char pad8[0xE0]; int unkE8; char padEC[0x10]; void* unkFC; };

extern "C" void func_00118290(S_118290* self, int flags) {
    self->unkFC = D_00338510;
    func_0011A470(self->unkE8);
    O_118290* o = self->unk4;
    if (o) {
        V_118290* v = o->unk14;
        v->unk8.unk4((char*)o + v->unk8.unk0, 3);
    }
    if (flags & 1) {
        func_00119400(D_00368A38[0], self);
    }
}

INCLUDE_ASM("asm/nonmatchings/game/t_116E38", func_00118308);

struct S118388 { char pad0[0x18]; int unk18; char pad1C[0xD0]; int unkEC; };

extern "C" void func_00118388(S118388* self) {
    if (self->unkEC == 2) {
        func_002ED120(self->unk18);
    }
    self->unkEC = 0;
}

INCLUDE_ASM("asm/nonmatchings/game/t_116E38", func_001183C8);

INCLUDE_ASM("asm/nonmatchings/game/t_116E38", func_001184C0);

extern "C" void func_00118570(S_00118570* self) {
    self->unkD4 = 0;
}

INCLUDE_ASM("asm/nonmatchings/game/t_116E38", func_00118578);

INCLUDE_ASM("asm/nonmatchings/game/t_116E38", func_00118580);

extern "C" void func_00118640(SA116_P* self) {
    u8 mask;
    u16 h;
    int i;
    SA116_C* c = &self->unkCC;
    if (c->unk4 == 0) {
        return;
    }
    if (--c->unk4 != 0) {
        return;
    }
    if (self->unkEC != 2) {
        return;
    }
    if (!(self->unkD8 & 2)) {
        return;
    }
    for (i = 0; i < self->unkE4; i++) {
        self->unk64[i] = self->unkAC[i];
    }
    mask = (1 << self->unkE4) - 1;
    h = self->unk64[0] | (self->unk64[1] << 1);
    func_002ED798(self->unk18, 1, &mask, 2, &h);
}

extern "C" void func_00118700(SA116_P* self) {
    u8 mask;
    int z;
    int i;
    if (self->unkEC != 2) {
        return;
    }
    if (!(self->unkD8 & 2)) {
        return;
    }
    for (i = 0; i < self->unkE4; i++) {
        self->unk64[i] = 0;
        self->unkAC[i] = 0;
    }
    z = 0;
    mask = (1 << self->unkE4) - 1;
    func_002ED798(self->unk18, 1, &mask, 2, &z);
}

INCLUDE_ASM("asm/nonmatchings/game/t_116E38", func_00118790);

extern "C" void CreateSemaphore(void) {
    SA116_Sema s;
    s.unk8 = 1;
    s.unk4 = 10;
    D_00373248 = func_002EE660(&s);
}

extern "C" void WaitSemaphore(void) {
    func_002EE670(D_00373248);
}

GP_DATA(D_003689E0);
extern "C" void func_001187F8(void) {
    if (D_003689E0) func_002EE6A0(D_00373248);
}

extern "C" void func_00118820(void) {
    if (D_003689E0) func_002EE680(D_00373248);
}

INCLUDE_ASM("asm/nonmatchings/game/t_116E38", func_00118848);

INCLUDE_ASM("asm/nonmatchings/game/t_116E38", func_00118BD8);
