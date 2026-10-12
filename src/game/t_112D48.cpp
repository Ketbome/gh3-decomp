#include "common.h"

struct S_001143E0 { char pad0[0x24]; int unk24; };
struct S_00114030 { char pad0[0x8]; struct S_00114030* unk8; char pad1[0x4]; struct S_00114030* unk10; };

struct S_00114958 { char pad0[0x40]; int unk40; };
struct S_001149B8 { char pad0[0x3C]; int unk3C; };

struct SA112_L {
    char pad0[0xC];
    SA112_L* unkC;
    SA112_L* unk10;
    void* unk14;
};

struct SA112_C {
    char pad0[0x4];
    int unk4;
    char pad8[0x4];
    u32 unkC;
    int unk10;
    void* unk14;
    void* unk18;
    void* unk1C;
    int unk20;
    int unk24;
};

struct SA112_N {
    char pad0[0x4];
    u32 unk4;
    int unk8;
    SA112_N* unkC;
    SA112_N* unk10;
    void* unk14;
};

struct SA112_D {
    char pad0[0x8];
    void* unk8;
};

extern "C" {
extern int D_00368A38[] __attribute__((section(".sdata")));
extern u8 D_00337EE0[];
extern u8 D_00337EC8[];
extern u8 D_00337F08[];
extern u8 D_00337F38[];
extern u8 D_00337DA0[];
void func_00119400(int, void*);
extern int D_00368390;
void func_00113D88(int, int);
void func_00114298(int);
void func_00114340(int);
void func_00114AD8(void);
extern int D_00368388[];
void func_0030ADA0(int, int, int);
}

INCLUDE_ASM("asm/nonmatchings/game/t_112D48", func_00112D48);

INCLUDE_ASM("asm/nonmatchings/game/t_112D48", func_00112DB0);

INCLUDE_ASM("asm/nonmatchings/game/t_112D48", func_00112E60);

INCLUDE_ASM("asm/nonmatchings/game/t_112D48", func_00112F68);

INCLUDE_ASM("asm/nonmatchings/game/t_112D48", func_00113228);

INCLUDE_ASM("asm/nonmatchings/game/t_112D48", func_00113308);

extern "C" void func_001133C0(int p) {
    if (p == 0) {
        D_00368390 = (int)D_00368388;
    } else {
        D_00368390 = p;
    }
}

extern "C" int func_001133E0(void) {
    return D_00368390;
}

INCLUDE_ASM("asm/nonmatchings/game/t_112D48", func_001133E8);

INCLUDE_ASM("asm/nonmatchings/game/t_112D48", func_00113420);

extern "C" void func_00113528(char* s) {
    while (*s) {
        char c = *s;
        if (c >= 'A' && c <= 'Z') {
            c += 0x20;
        } else {
            switch (c) {
            case -0x40 ... -0x2A:
            case -0x28 ... -0x22:
                c += 0x20;
                break;
            }
        }
        *s = c;
        s++;
    }
}

INCLUDE_ASM("asm/nonmatchings/game/t_112D48", func_001135A0);

INCLUDE_ASM("asm/nonmatchings/game/t_112D48", func_00113640);

INCLUDE_ASM("asm/nonmatchings/game/t_112D48", func_00113770);

INCLUDE_ASM("asm/nonmatchings/game/t_112D48", func_001137E8);

INCLUDE_ASM("asm/nonmatchings/game/t_112D48", func_001138F8);

extern "C" void func_00113930(char* d, const char* s) {
    while (*s) {
        *d++ = *s++;
    }
    *d = 0;
}

extern "C" void func_00113960(int a, int b, int c) {
    func_0030ADA0(a, c, b);
}

INCLUDE_ASM("asm/nonmatchings/game/t_112D48", func_00113988);

INCLUDE_ASM("asm/nonmatchings/game/t_112D48", func_001139E0);

INCLUDE_ASM("asm/nonmatchings/game/t_112D48", func_00113A70);

INCLUDE_ASM("asm/nonmatchings/game/t_112D48", func_00113AC8);

INCLUDE_ASM("asm/nonmatchings/game/t_112D48", func_00113B20);

extern "C" void func_00113B68(char* s) {
    while (*s) {
        if (*s >= 'a' && *s <= 'z') {
            *s -= 0x20;
        }
        s++;
    }
}

extern "C" char* func_00113BA0(char* s, char* sub) {
    char* a = s;
    char* b = sub;
    while (*a && *b && *a == *b) {
        a++;
        b++;
    }
    if (*b == 0) {
        return s;
    }
    if (*a == 0) {
        return 0;
    }
    return func_00113BA0(s + 1, sub);
}

INCLUDE_ASM("asm/nonmatchings/game/t_112D48", func_00113BF8);

INCLUDE_ASM("asm/nonmatchings/game/t_112D48", func_00113D20);

INCLUDE_ASM("asm/nonmatchings/game/t_112D48", func_00113D80);

INCLUDE_ASM("asm/nonmatchings/game/t_112D48", func_00113D88);

INCLUDE_ASM("asm/nonmatchings/game/t_112D48", func_00113DE8);

extern "C" void func_00113E48(int p0, int p1, int p2) {
    func_00113D88(p0, p2);
}

INCLUDE_ASM("asm/nonmatchings/game/t_112D48", func_00113E68);

INCLUDE_ASM("asm/nonmatchings/game/t_112D48", func_00113EA8);

INCLUDE_ASM("asm/nonmatchings/game/t_112D48", func_00113F38);

INCLUDE_ASM("asm/nonmatchings/game/t_112D48", func_00113FB8);

extern "C" int func_00114030(S_00114030* self) {
    return self->unk8->unk10 != self->unk8;
}

INCLUDE_ASM("asm/nonmatchings/game/t_112D48", func_00114048);

extern "C" SA112_C* func_001140B0(SA112_C* self) {
    SA112_N* p;
    self->unk4 = 0;
    p = (SA112_N*)((char*)self + 8);
    p->unk4 = 0xFFFFFFFF;
    p->unk8 = 0;
    p->unkC = p;
    p->unk10 = p;
    p->unk14 = D_00337EE0;
    self->unk20 = 0;
    self->unk24 = 0;
    return self;
}

extern "C" void func_001140F0(void* self, int flags) {
    SA112_L* p = (SA112_L*)((char*)self + 8);
    p->unk14 = D_00337DA0;
    p->unk10->unkC = p->unkC;
    p->unkC->unk10 = p->unk10;
    p->unkC = p;
    p->unk10 = p;
    if (flags & 1) {
        func_00119400(D_00368A38[0], self);
    }
}

INCLUDE_ASM("asm/nonmatchings/game/t_112D48", func_00114150);

INCLUDE_ASM("asm/nonmatchings/game/t_112D48", func_00114298);

INCLUDE_ASM("asm/nonmatchings/game/t_112D48", func_00114340);

extern "C" void func_001143E0(S_001143E0* self) {
    self->unk24 = 1;
}

INCLUDE_ASM("asm/nonmatchings/game/t_112D48", func_001143F0);

extern "C" void func_00114460(SA112_D* self, int flags) {
    self->unk8 = D_00337EC8;
    if (flags & 1) {
        func_00119400(D_00368A38[0], self);
    }
}

INCLUDE_ASM("asm/nonmatchings/game/t_112D48", func_001144A0);

INCLUDE_ASM("asm/nonmatchings/game/t_112D48", func_00114528);

INCLUDE_ASM("asm/nonmatchings/game/t_112D48", func_00114580);

INCLUDE_ASM("asm/nonmatchings/game/t_112D48", func_001145D8);

INCLUDE_ASM("asm/nonmatchings/game/t_112D48", func_00114660);

INCLUDE_ASM("asm/nonmatchings/game/t_112D48", func_00114770);

INCLUDE_ASM("asm/nonmatchings/game/t_112D48", func_001147D0);

INCLUDE_ASM("asm/nonmatchings/game/t_112D48", func_001148F8);

extern "C" void func_00114958(S_00114958* self) {
    func_00114298(self->unk40);
}

INCLUDE_ASM("asm/nonmatchings/game/t_112D48", func_00114978);

extern "C" void func_001149B8(S_001149B8* self) {
    func_00114340(self->unk3C);
}

extern "C" void func_001149D8(SA112_D* self, int flags) {
    self->unk8 = D_00337F08;
    if (flags & 1) {
        func_00119400(D_00368A38[0], self);
    }
}

extern "C" void func_00114A18(SA112_L* self, int flags) {
    self->unk14 = D_00337F38;
    self->unk10->unkC = self->unkC;
    self->unkC->unk10 = self->unk10;
    self->unkC = self;
    self->unk10 = self;
    if (flags & 1) {
        func_00119400(D_00368A38[0], self);
    }
}

extern "C" void func_00114A78(SA112_L* self, int flags) {
    self->unk14 = D_00337F38;
    self->unk10->unkC = self->unkC;
    self->unkC->unk10 = self->unk10;
    self->unkC = self;
    self->unk10 = self;
    if (flags & 1) {
        func_00119400(D_00368A38[0], self);
    }
}

INCLUDE_ASM("asm/nonmatchings/game/t_112D48", func_00114AD8);

extern "C" void func_00114C50(void) {
    func_00114AD8();
}

INCLUDE_ASM("asm/nonmatchings/game/t_112D48", func_00114C70);
