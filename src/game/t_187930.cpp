#include "common.h"

struct S00187F48 {
    char pad[0x14];
    int unk14;
};

struct S00188F40 {
    char pad[0x20];
    int unk20;
};

struct S001891E0 {
    char pad[0xC];
    int unkC;
};

struct S00188F18 {
    char pad0[0xC];
    float unkC;
    char pad10[0x10];
    int unk20;
};

struct S00188730_1 {
    int unk0;
};

struct S00188730 {
    char pad[0x14];
    S00188730_1* unk14;
};

struct S00188740_1 {
    char pad[0x4];
    int unk4;
};

struct S00188740 {
    char pad[0x14];
    S00188740_1* unk14;
};

struct S00188750_1 {
    char pad[0x4];
    int unk4;
};

struct S00188750 {
    char pad[0x14];
    S00188750_1* unk14;
};

struct S00188760_1 {
    char pad[0x8];
    int unk8;
};

struct S00188760 {
    char pad[0x14];
    S00188760_1* unk14;
};

struct S00188770_1 {
    char pad[0x8];
    int unk8;
};

struct S00188770 {
    char pad[0x14];
    S00188770_1* unk14;
};

struct S001888B0_1 {
    char pad[0xC];
    float unkC;
};

struct S001888B0 {
    char pad[0x14];
    S001888B0_1* unk14;
};

struct S001888C0_1 {
    char pad[0x10];
    int unk10;
};

struct S001888C0 {
    char pad[0x14];
    S001888C0_1* unk14;
};

struct S00188920_1 {
    char pad[0x24];
    float unk24;
};

struct S00188920 {
    char pad[0x14];
    S00188920_1* unk14;
};

struct S00188930_1 {
    char pad[0x28];
    float unk28;
};

struct S00188930 {
    char pad[0x14];
    S00188930_1* unk14;
};

struct S00188958_1 {
    char pad[0x30];
    float unk30;
};

struct S00188958 {
    char pad[0x14];
    S00188958_1* unk14;
};

struct S00188968_1 {
    char pad[0x34];
    float unk34;
};

struct S00188968 {
    char pad[0x14];
    S00188968_1* unk14;
};

struct S00188978_1 {
    char pad[0x48];
    float unk48;
};

struct S00188978 {
    char pad[0x14];
    S00188978_1* unk14;
};

struct S00188988_1 {
    char pad[0x48];
    float unk48;
};

struct S00188988 {
    char pad[0x14];
    S00188988_1* unk14;
};

struct S001889B0_1 {
    char pad[0x38];
    float unk38;
};

struct S001889B0 {
    char pad[0x14];
    S001889B0_1* unk14;
};

struct S001889C0_1 {
    char pad[0x3C];
    float unk3C;
};

struct S001889C0 {
    char pad[0x14];
    S001889C0_1* unk14;
};

struct S00188A18_1 {
    char pad[0x2C];
    u16 unk2C;
};

struct S00188A18 {
    char pad[0x14];
    S00188A18_1* unk14;
};

struct S00188A28_1 {
    char pad[0x2E];
    u16 unk2E;
};

struct S00188A28 {
    char pad[0x14];
    S00188A28_1* unk14;
};

struct S00188A50_1 {
    char pad[0x50];
    int unk50;
};

struct S00188A50 {
    char pad[0x14];
    S00188A50_1* unk14;
};

struct S00188A60_1 {
    char pad[0x54];
    int unk54;
};

struct S00188A60 {
    char pad[0x14];
    S00188A60_1* unk14;
};

struct S00188B00_1 {
    char pad[0x88];
    float unk88;
};

struct S00188B00 {
    char pad[0x14];
    S00188B00_1* unk14;
};

struct S00188B50_1 {
    char pad[0x7C];
    int unk7C;
};

struct S00188B50 {
    char pad[0x14];
    S00188B50_1* unk14;
};

struct S00188B60_1 {
    char pad[0x78];
    float unk78;
};

struct S00188B60 {
    char pad[0x14];
    S00188B60_1* unk14;
};

struct S001889D0_1 {
    char pad[0x4C];
    int unk4C;
};

struct S001889D0 {
    char pad[0x14];
    S001889D0_1* unk14;
};

struct S001889D0_2 {
    int unk0;
};

extern "C" {
void func_001C1468(int);
void func_001C14E0(int);
void func_001C2C20(int);
void func_001C2C30(int);
void func_001B1F08(int);
void func_001B1F10(int);
void func_001B1F18(int);
void func_00153588(void);
void func_001C32A0(int);
void func_001BF838(int, float);
void func_001B2168(int, int);
void func_001B21A0(int, int);
}

INCLUDE_ASM("asm/nonmatchings/game/t_187930", func_00187930);

INCLUDE_ASM("asm/nonmatchings/game/t_187930", func_00187E08);

INCLUDE_ASM("asm/nonmatchings/game/t_187930", func_00187E58);

INCLUDE_ASM("asm/nonmatchings/game/t_187930", func_00187F00);

extern "C" int func_00187F48(S00187F48* self) {
    return self->unk14;
}

INCLUDE_ASM("asm/nonmatchings/game/t_187930", func_00187F50);

INCLUDE_ASM("asm/nonmatchings/game/t_187930", func_00188060);

extern "C" int func_00188100(S00187F48* self) {
    func_001C32A0(self->unk14);
    return 0;
}

INCLUDE_ASM("asm/nonmatchings/game/t_187930", func_00188120);

INCLUDE_ASM("asm/nonmatchings/game/t_187930", func_001881A0);

INCLUDE_ASM("asm/nonmatchings/game/t_187930", func_001882A8);

extern "C" int func_00188358(void) {
    return 0;
}

INCLUDE_ASM("asm/nonmatchings/game/t_187930", func_00188360);

extern "C" void func_00188398(void) {
}

extern "C" int func_001883A0(void) {
    return 0;
}

INCLUDE_ASM("asm/nonmatchings/game/t_187930", func_001883A8);

INCLUDE_ASM("asm/nonmatchings/game/t_187930", func_001883F0);

INCLUDE_ASM("asm/nonmatchings/game/t_187930", func_00188420);

INCLUDE_ASM("asm/nonmatchings/game/t_187930", func_00188448);

INCLUDE_ASM("asm/nonmatchings/game/t_187930", func_00188470);

INCLUDE_ASM("asm/nonmatchings/game/t_187930", func_00188478);

INCLUDE_ASM("asm/nonmatchings/game/t_187930", func_00188520);

INCLUDE_ASM("asm/nonmatchings/game/t_187930", func_00188568);

INCLUDE_ASM("asm/nonmatchings/game/t_187930", func_001885B0);

INCLUDE_ASM("asm/nonmatchings/game/t_187930", func_00188618);

INCLUDE_ASM("asm/nonmatchings/game/t_187930", func_00188680);

INCLUDE_ASM("asm/nonmatchings/game/t_187930", func_00188700);

extern "C" int func_00188730(S00188730* self) {
    return self->unk14->unk0;
}

extern "C" S00188740_1* func_00188740(S00188740* self, int a1) {
    S00188740_1* t1 = self->unk14;
    t1->unk4 = a1;
    return t1;
}

extern "C" int func_00188750(S00188750* self) {
    return self->unk14->unk4;
}

extern "C" S00188760_1* func_00188760(S00188760* self, int a1) {
    S00188760_1* t1 = self->unk14;
    t1->unk8 = a1;
    return t1;
}

extern "C" int func_00188770(S00188770* self) {
    return self->unk14->unk8;
}

INCLUDE_ASM("asm/nonmatchings/game/t_187930", func_00188780);

INCLUDE_ASM("asm/nonmatchings/game/t_187930", func_00188870);

extern "C" float func_001888B0(S001888B0* self) {
    return self->unk14->unkC;
}

extern "C" int func_001888C0(S001888C0* self) {
    return self->unk14->unk10;
}

INCLUDE_ASM("asm/nonmatchings/game/t_187930", func_001888D0);

INCLUDE_ASM("asm/nonmatchings/game/t_187930", func_00188908);

extern "C" float func_00188920(S00188920* self) {
    return self->unk14->unk24;
}

extern "C" float func_00188930(S00188930* self) {
    return self->unk14->unk28;
}

INCLUDE_ASM("asm/nonmatchings/game/t_187930", func_00188940);

extern "C" float func_00188958(S00188958* self) {
    return self->unk14->unk30;
}

extern "C" float func_00188968(S00188968* self) {
    return self->unk14->unk34;
}

extern "C" S00188978_1* func_00188978(S00188978* self, float f0) {
    S00188978_1* t1 = self->unk14;
    t1->unk48 = f0;
    return t1;
}

extern "C" float func_00188988(S00188988* self) {
    return self->unk14->unk48;
}

INCLUDE_ASM("asm/nonmatchings/game/t_187930", func_00188998);

extern "C" float func_001889B0(S001889B0* self) {
    return self->unk14->unk38;
}

extern "C" float func_001889C0(S001889C0* self) {
    return self->unk14->unk3C;
}

extern "C" void func_001889D0(S001889D0* self, S001889D0_2* a1) {
    self->unk14->unk4C = a1->unk0;
}

INCLUDE_ASM("asm/nonmatchings/game/t_187930", func_001889E0);

INCLUDE_ASM("asm/nonmatchings/game/t_187930", func_00188A00);

extern "C" u16 func_00188A18(S00188A18* self) {
    return self->unk14->unk2C;
}

extern "C" u16 func_00188A28(S00188A28* self) {
    return self->unk14->unk2E;
}

INCLUDE_ASM("asm/nonmatchings/game/t_187930", func_00188A38);

extern "C" int func_00188A50(S00188A50* self) {
    return self->unk14->unk50;
}

extern "C" int func_00188A60(S00188A60* self) {
    return self->unk14->unk54;
}

INCLUDE_ASM("asm/nonmatchings/game/t_187930", func_00188A70);

INCLUDE_ASM("asm/nonmatchings/game/t_187930", func_00188AA8);

INCLUDE_ASM("asm/nonmatchings/game/t_187930", func_00188AD0);

INCLUDE_ASM("asm/nonmatchings/game/t_187930", func_00188AE8);

extern "C" S00188B00_1* func_00188B00(S00188B00* self, float f0) {
    S00188B00_1* t1 = self->unk14;
    t1->unk88 = f0;
    return t1;
}

extern "C" void func_00188B10(S00187F48* self) {
    func_001C1468(self->unk14);
}

extern "C" void func_00188B30(S00187F48* self) {
    func_001C14E0(self->unk14);
}

extern "C" S00188B50_1* func_00188B50(S00188B50* self, int a1) {
    S00188B50_1* t1 = self->unk14;
    t1->unk7C = a1;
    return t1;
}

extern "C" S00188B60_1* func_00188B60(S00188B60* self, float f0) {
    S00188B60_1* t1 = self->unk14;
    t1->unk78 = f0;
    return t1;
}

INCLUDE_ASM("asm/nonmatchings/game/t_187930", func_00188B70);

extern "C" void func_00188BB0(void) {
}

INCLUDE_ASM("asm/nonmatchings/game/t_187930", func_00188BB8);

INCLUDE_ASM("asm/nonmatchings/game/t_187930", func_00188C50);

INCLUDE_ASM("asm/nonmatchings/game/t_187930", func_00188C70);

INCLUDE_ASM("asm/nonmatchings/game/t_187930", func_00188C88);

INCLUDE_ASM("asm/nonmatchings/game/t_187930", func_00188D00);

INCLUDE_ASM("asm/nonmatchings/game/t_187930", func_00188D68);

INCLUDE_ASM("asm/nonmatchings/game/t_187930", func_00188DD0);

INCLUDE_ASM("asm/nonmatchings/game/t_187930", func_00188E38);

INCLUDE_ASM("asm/nonmatchings/game/t_187930", func_00188E68);

extern "C" void func_00188F18(S00188F18* self) {
    func_001BF838(self->unk20, self->unkC);
}

extern "C" void func_00188F38(void) {
}

extern "C" void func_00188F40(S00188F40* self) {
    func_001C2C20(self->unk20);
}

extern "C" void func_00188F60(S00188F40* self) {
    func_001C2C30(self->unk20);
}

INCLUDE_ASM("asm/nonmatchings/game/t_187930", func_00188F80);

INCLUDE_ASM("asm/nonmatchings/game/t_187930", func_00188FB8);

INCLUDE_ASM("asm/nonmatchings/game/t_187930", func_00189010);

INCLUDE_ASM("asm/nonmatchings/game/t_187930", func_00189040);

INCLUDE_ASM("asm/nonmatchings/game/t_187930", func_00189078);

INCLUDE_ASM("asm/nonmatchings/game/t_187930", func_00189098);

INCLUDE_ASM("asm/nonmatchings/game/t_187930", func_00189180);

INCLUDE_ASM("asm/nonmatchings/game/t_187930", func_001891A0);

extern "C" void func_001891E0(S001891E0* self) {
    func_001B1F08(self->unkC);
}

extern "C" void func_00189200(S001891E0* self) {
    func_001B1F10(self->unkC);
}

extern "C" void func_00189220(S001891E0* self) {
    func_001B1F18(self->unkC);
}

extern "C" void func_00189240(S001891E0* self, int a1) {
    func_001B2168(self->unkC, ((a1 << 24) >> 24));
}

extern "C" void func_00189268(S001891E0* self, int a1) {
    func_001B21A0(self->unkC, ((a1 << 24) >> 24));
}

INCLUDE_ASM("asm/nonmatchings/game/t_187930", func_00189290);

INCLUDE_ASM("asm/nonmatchings/game/t_187930", func_001892F8);

INCLUDE_ASM("asm/nonmatchings/game/t_187930", func_00189360);

INCLUDE_ASM("asm/nonmatchings/game/t_187930", func_001893D0);

INCLUDE_ASM("asm/nonmatchings/game/t_187930", func_00189400);

INCLUDE_ASM("asm/nonmatchings/game/t_187930", func_001894C8);

INCLUDE_ASM("asm/nonmatchings/game/t_187930", func_00189508);

INCLUDE_ASM("asm/nonmatchings/game/t_187930", func_00189540);

INCLUDE_ASM("asm/nonmatchings/game/t_187930", func_00189710);

INCLUDE_ASM("asm/nonmatchings/game/t_187930", func_00189718);

extern "C" void func_00189798(void) {
    func_00153588();
}

INCLUDE_ASM("asm/nonmatchings/game/t_187930", func_001897B8);

INCLUDE_ASM("asm/nonmatchings/game/t_187930", func_00189818);

INCLUDE_ASM("asm/nonmatchings/game/t_187930", func_00189878);
