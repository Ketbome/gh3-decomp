// cflags: -funroll-loops
#include "common.h"

struct S_00120C60 { char pad0[0x10]; int unk10; };

struct SA11F_E {
    int unk0;
    int unk4;
    int unk8;
};

struct SA11F_W {
    char pad0[0x4];
    int unk4;
    int unk8;
    char padC[0x4];
    int unk10;
    int unk14;
};

extern "C" {
extern volatile int D_00368C04;
int func_00120A40(void*, void*, int, int);
int func_0011E190(void);
int func_001203A8(int, int, int, int, int);
void func_0011E3B8(int);
struct E11F768 { char pad0[8]; char* unk8; int unkC; };
struct S11F768 { char pad0[0xC]; int unkC; char pad10[0x14]; s16 unk24; s16 unk26; char unk28[1]; };
E11F768* func_0011F9A8_2(void*, int) __asm__("func_0011F9A8");
void func_0030A2F4(char*, char*, int);
int func_002FF920(void*, int);
int func_00116E70(void);
int func_0030B550(char*, char*, ...);
extern char D_00338EB8[];
extern int D_00368D74;
extern int D_00368D70;
void func_0011DCD8(int, int);
void* func_0011D9A8(void*);
int func_002EEA00(int);
void func_002EA460(void);
extern int D_00368748[] __attribute__((section(".sdata")));
extern int D_00368D80;
extern int D_00368C18[] __attribute__((section(".sdata")));
extern int D_00368C08[] __attribute__((section(".sdata")));
extern SA11F_E D_00415170[];
extern u8 D_00338F30[];
void func_0011DA60(void*, int);
int func_0011F110(void*);
int func_0011F028(void*);
void func_0011A470(int);
void func_002F2400(int);
void func_002F3B80(void);
void func_002F3BD0(void);
S_00120C60* func_001208C0_v(void) __asm__("func_001208C0");
extern int D_00368DA4;
struct E_1208C0 { char pad0[4]; int unk4; char pad8[0xC]; };
extern E_1208C0 D_00415188[];
extern int D_00368D78;
int func_00120F78(void*, int);
void func_0011DBE8(void*, int, int);
int func_0011DB60(void*);
}

struct S_0011FB38 { char pad0[0x48]; int unk48; char pad1[0x100]; int unk14C; int unk150; int unk154; int unk158; };

GP_DATA(D_00368D78);
extern "C" int func_0011F000(void* self) {
    return func_00120F78(self, D_00368D78) != 0;
}

struct S6_11F { int a; u16 b; };

extern "C" {
int func_0030A684(int, int);
void func_0030ADA0(char*, int, int, ...);
int func_002F2170(char*, int);
void func_002F2400(int);
int func_002F2578(int, int, int);
extern S6_11F D_00368D88;
}

extern "C" int func_0011F028(void* name_) {
    int name = (int)name_;
    char buf[0x100];
    if (func_0030A684(name, 0x3A)) {
        func_0030ADA0(buf, name, 0xFF);
    } else {
        u16 b = D_00368D88.b;
        *(int*)buf = D_00368D88.a;
        *(u16*)(buf + 4) = b;
        func_0030ADA0(buf + 5, name, 0xFA, b);
    }
    buf[0xFF] = 0;
    if (buf[0]) {
        char* p = buf;
        do {
            if (*p == '\\') *p = '/';
            p++;
        } while (*p);
    }
    int fd = func_002F2170(buf, 1);
    if (fd >= 0) {
        int r = func_002F2578(fd, 0, 2);
        func_002F2400(fd);
        return !(r < 0);
    }
    return 0;
}

INCLUDE_ASM("asm/nonmatchings/game/t_11F000", func_0011F110);

INCLUDE_ASM("asm/nonmatchings/game/t_11F000", func_0011F238);

INCLUDE_ASM("asm/nonmatchings/game/t_11F000", func_0011F3A8);

GP_DATA(D_00368D74);
GP_DATA(D_00368D70);
extern "C" void func_0011F3E8(int a) {
    int out[12];
    char buf[0x80];
    func_0030B550(buf, D_00338EB8, func_00116E70(), a);
    do {
    } while (!func_002FF920(out, (int)buf));
    D_00368D74 = 1;
    D_00368D70 = out[0];
}

extern "C" unsigned int func_0011F478(int a, int* out) {
    int buf[10];
    if (D_00368748[0] && func_002FF920(buf, a)) {
        if (out) *out = buf[1];
        return buf[0];
    }
    return 0xFFFFFFFF;
}

extern "C" int func_0011F4D8(void* self) {
    if (D_00368748[0]) {
        return 0;
    }
    return func_0011F110(self);
}

extern "C" int func_0011F510(void* self) {
    if (D_00368748[0]) {
        return func_0011F000(self);
    }
    return func_0011F028(self);
}

struct S11F548 { char pad0[0x44]; void* unk44; int unk48; char pad4C[0xFC]; int unk148; int unk14C; int unk150; int unk154; int unk158; };

extern "C" S11F548* func_0011F548(S11F548* self) {
    func_0011D9A8(self);
    self->unk48 = -1;
    self->unk44 = D_00338F30;
    self->unk14C = 0;
    self->unk150 = 0;
    self->unk154 = 0;
    self->unk158 = 0;
    return self;
}

extern "C" void func_0011F598(void* self, int flags) {
    ((void**)self)[0x11] = D_00338F30;
    func_0011DA60(self, flags);
}

INCLUDE_ASM("asm/nonmatchings/game/t_11F000", func_0011F5C0);

extern "C" void func_0011F710(int a, int b) {
    if (b != 0) func_002F3B80();
    func_0011DCD8(a, b);
    if (b != 0) func_002F3BD0();
}

extern "C" void func_0011F768(void* a, S11F768* self) {
    E11F768* e = func_0011F9A8_2(a, self->unkC);
    if (e) {
        char* t = e->unk8;
        if (t) {
            int s = self->unk26;
            if (s) {
                func_0030A2F4(t + (e->unkC - s), self->unk28, s);
            } else {
                func_0030A2F4(t, self->unk28, self->unk24);
            }
        }
    }
}

INCLUDE_ASM("asm/nonmatchings/game/t_11F000", func_0011F7E0);

struct S_11F8D0 { char pad0[0x4C]; int unk4C[1]; char pad50[0xFC]; int unk14C; };

extern "C" int func_0011F8D0(S_11F8D0* self, int key) {
    int i;
    for (i = 0; i < self->unk14C; i++) {
        if (self->unk4C[i * 4] == key) {
            return self->unk4C[i * 4 + 1];
        }
    }
    return 0;
}

struct E_11F9A8 { int unk0; char pad4[0xC]; };
struct S_11F9A8 { char pad0[0x4C]; E_11F9A8 unk4C[1]; char pad5C[0xF0]; int unk14C; };

extern "C" E_11F9A8* func_0011F9A8(S_11F9A8* self, int key) {
    int i;
    for (i = 0; i < self->unk14C; i++) {
        if (self->unk4C[i].unk0 == key) {
            return &self->unk4C[i];
        }
    }
    return 0;
}


INCLUDE_ASM("asm/nonmatchings/game/t_11F000", func_0011FA98);

extern "C" void func_0011FB38(S_0011FB38* self) {
    self->unk48 = -1;
    self->unk14C = 0;
    self->unk150 = 0;
    self->unk154 = 0;
    self->unk158 = 0;
}

extern "C" int func_0011FB58(void) {
    return 0;
}

extern "C" int func_0011FB60(void) {
    return 0;
}

extern "C" int func_0011FB68(void) {
    return 0;
}

INCLUDE_ASM("asm/nonmatchings/game/t_11F000", func_0011FB70);

INCLUDE_ASM("asm/nonmatchings/game/t_11F000", func_0011FBE0);

INCLUDE_ASM("asm/nonmatchings/game/t_11F000", func_0011FC50);

INCLUDE_ASM("asm/nonmatchings/game/t_11F000", func_0011FCC0);

extern "C" void func_0011FD30(void) {
}

struct VE_0011FD38 { s16 unk0; s16 unk2; void (*unk4)(void*, int, int, int); };
struct V_0011FD38 { char pad0[0x88]; VE_0011FD38 unk88; };
struct S_0011FD38 { char pad0[0x14]; int unk14; char pad18[0x1C]; int unk34; char pad38[0xC]; V_0011FD38* unk44; };

INCLUDE_ASM("asm/nonmatchings/game/t_11F000", func_0011FD38);

INCLUDE_ASM("asm/nonmatchings/game/t_11F000", func_0011FDC0);

INCLUDE_ASM("asm/nonmatchings/game/t_11F000", func_0011FF58);

extern "C" int func_00120008(void) {
    return 0;
}

INCLUDE_ASM("asm/nonmatchings/game/t_11F000", func_00120010);

struct L_001200D0 { char pad0[0x10]; int unk10; char pad14[0x58]; int unk6C; };
struct VE_001200D0 { char pad0[8]; s16 unk8; s16 unkA; void (*unkC)(void*); };
struct S_001200D0 { char pad0[0x20]; int unk20; char pad24[0x1C]; volatile int unk40; VE_001200D0* unk44; int unk48; };

INCLUDE_ASM("asm/nonmatchings/game/t_11F000", func_001200D0);

INCLUDE_ASM("asm/nonmatchings/game/t_11F000", func_00120180);

INCLUDE_ASM("asm/nonmatchings/game/t_11F000", func_001203A8);

INCLUDE_ASM("asm/nonmatchings/game/t_11F000", func_001204D8);

extern "C" int func_00120598(int a, int b, int c, int d) {
    int t = func_0011E190();
    if (t) {
        if (func_001203A8(t, a, b, c, d) == 0) {
            func_0011E3B8(t);
            return 0;
        }
        return t;
    }
    return 0;
}

INCLUDE_ASM("asm/nonmatchings/game/t_11F000", func_00120628);

INCLUDE_ASM("asm/nonmatchings/game/t_11F000", func_001206C8);

INCLUDE_ASM("asm/nonmatchings/game/t_11F000", func_001206D0);

INCLUDE_ASM("asm/nonmatchings/game/t_11F000", func_00120710);

INCLUDE_ASM("asm/nonmatchings/game/t_11F000", func_001207A0);

GP_DATA(D_00368DA4);
extern "C" E_1208C0* func_001208C0(int id) {
    int i = 0x5F;
    if (D_00368DA4 >= 1) {
        i = D_00368DA4 - 1;
    }
    E_1208C0* e = &D_00415188[i];
    E_1208C0* p = e;
    do {
        if (p->unk4 != id) {
            int j = 0x5F;
            if (i >= 1) {
                j = i - 1;
            }
            i = j;
            p = &D_00415188[i];
        } else {
            return p;
        }
    } while (p != e);
    return 0;
}

INCLUDE_ASM("asm/nonmatchings/game/t_11F000", func_00120938);

INCLUDE_ASM("asm/nonmatchings/game/t_11F000", func_00120A40);

struct S120BC0 { char pad0[8]; int unk8; int unkC; };

extern "C" void func_00120BC0(void) {
    S120BC0* p = (S120BC0*)func_001208C0_v();
    while (func_002EEA00(p->unk8) >= 0) {
        func_002EA460();
    }
}

INCLUDE_ASM("asm/nonmatchings/game/t_11F000", func_00120C08);

INCLUDE_ASM("asm/nonmatchings/game/t_11F000", func_00120C58);

extern "C" int func_00120C60(void) {
    return func_001208C0_v()->unk10;
}

INCLUDE_ASM("asm/nonmatchings/game/t_11F000", func_00120C80);

extern "C" int func_00120DF0(void) {
    return 1;
}

extern "C" void func_00120DF8(void) {
}

INCLUDE_ASM("asm/nonmatchings/game/t_11F000", func_00120E00);

INCLUDE_ASM("asm/nonmatchings/game/t_11F000", func_00120E40);

INCLUDE_ASM("asm/nonmatchings/game/t_11F000", func_00120F78);
