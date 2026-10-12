#include "common.h"

struct S_001143E0 { char pad0[0x24]; int unk24; };
struct S_00114030 { char pad0[0x8]; struct S_00114030* unk8; char pad1[0x4]; struct S_00114030* unk10; };

struct S_00114958 { char pad0[0x40]; int unk40; };
struct S_001149B8 { char pad0[0x3C]; int unk3C; };

extern "C" {
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

INCLUDE_ASM("asm/nonmatchings/game/t_112D48", func_00113528);

INCLUDE_ASM("asm/nonmatchings/game/t_112D48", func_001135A0);

INCLUDE_ASM("asm/nonmatchings/game/t_112D48", func_00113640);

INCLUDE_ASM("asm/nonmatchings/game/t_112D48", func_00113770);

INCLUDE_ASM("asm/nonmatchings/game/t_112D48", func_001137E8);

INCLUDE_ASM("asm/nonmatchings/game/t_112D48", func_001138F8);

INCLUDE_ASM("asm/nonmatchings/game/t_112D48", func_00113930);

extern "C" void func_00113960(int a, int b, int c) {
    func_0030ADA0(a, c, b);
}

INCLUDE_ASM("asm/nonmatchings/game/t_112D48", func_00113988);

INCLUDE_ASM("asm/nonmatchings/game/t_112D48", func_001139E0);

INCLUDE_ASM("asm/nonmatchings/game/t_112D48", func_00113A70);

INCLUDE_ASM("asm/nonmatchings/game/t_112D48", func_00113AC8);

INCLUDE_ASM("asm/nonmatchings/game/t_112D48", func_00113B20);

INCLUDE_ASM("asm/nonmatchings/game/t_112D48", func_00113B68);

INCLUDE_ASM("asm/nonmatchings/game/t_112D48", func_00113BA0);

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

INCLUDE_ASM("asm/nonmatchings/game/t_112D48", func_001140B0);

INCLUDE_ASM("asm/nonmatchings/game/t_112D48", func_001140F0);

INCLUDE_ASM("asm/nonmatchings/game/t_112D48", func_00114150);

INCLUDE_ASM("asm/nonmatchings/game/t_112D48", func_00114298);

INCLUDE_ASM("asm/nonmatchings/game/t_112D48", func_00114340);

extern "C" void func_001143E0(S_001143E0* self) {
    self->unk24 = 1;
}

INCLUDE_ASM("asm/nonmatchings/game/t_112D48", func_001143F0);

INCLUDE_ASM("asm/nonmatchings/game/t_112D48", func_00114460);

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

INCLUDE_ASM("asm/nonmatchings/game/t_112D48", func_001149D8);

INCLUDE_ASM("asm/nonmatchings/game/t_112D48", func_00114A18);

INCLUDE_ASM("asm/nonmatchings/game/t_112D48", func_00114A78);

INCLUDE_ASM("asm/nonmatchings/game/t_112D48", func_00114AD8);

extern "C" void func_00114C50(void) {
    func_00114AD8();
}

INCLUDE_ASM("asm/nonmatchings/game/t_112D48", func_00114C70);
