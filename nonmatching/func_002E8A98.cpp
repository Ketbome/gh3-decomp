// cflags: -funroll-loops
#include "common.h"

extern "C" {
int func_002E5718(void);
void func_002E3700(int, int);
void func_002E3B08(int, int, int);
void func_002E0B60(int, int, int, int);
void func_002E5188(int, int);
extern int D_0037321C;
extern int D_003728B0;
void func_002E3AC0(void);
void func_002E1B50(int);
int func_002E5CA8(int, int, int);
int func_002E1488(int);
int func_002E5BB8(int, int);
int SndDrv_FlushCommands(int);
int func_002E5788(int, int);
int func_002E5860(int, int);
int func_002E59A0(int, int);
int func_002E5A78(int, int);
void func_002E11F0(int, int, int);
extern int D_003728F4;
}

GP_DATA(D_003728B8);
INCLUDE_ASM("asm/nonmatchings/game/t_2E7010", func_002E7010);

INCLUDE_ASM("asm/nonmatchings/game/t_2E7010", func_002E70B0);

INCLUDE_ASM("asm/nonmatchings/game/t_2E7010", func_002E71A8);

INCLUDE_ASM("asm/nonmatchings/game/t_2E7010", func_002E7B60);

extern "C" void func_002E7BC8(void) {
    func_002E5860(0x10, 0x2F);
}

extern "C" void func_002E7BE8(void) {
    func_002E5A78(0x10, 0x2F);
}

extern "C" void func_002E7C08(void) {
    func_002E5788(0, 0x2F);
    SndDrv_FlushCommands(1);
}

extern "C" void func_002E7C30(void) {
    func_002E59A0(0, 0x2F);
    SndDrv_FlushCommands(1);
}

INCLUDE_ASM("asm/nonmatchings/game/t_2E7010", func_002E7C58);

INCLUDE_ASM("asm/nonmatchings/game/t_2E7010", func_002E7D80);

extern "C" int func_002E7E20(f32 x) {
    int r;
    if (x > 1.0f) {
        x = 1.0f;
    }
    r = 0x3FFF;
    if (!(x > 0.99f)) {
        r = (int)(x * 16383.0f);
    }
    return r;
}

GP_DATA(D_003728F4);
extern "C" void func_002E7E80(int a, int b, int c, f32 unused, f32 x) {
    int t = func_002E7E20(unused);
    int h = func_002E5CA8(0, 0x2F, a);
    if (h != -1) {
        if (c) {
            c = func_002E7E20(x);
            int h2 = func_002E5CA8(0, 0x2F, b);
            if (D_003728F4) {
                t = (t + c) / 2;
                func_002E11F0(h, t, t);
                func_002E11F0(h2, t, t);
            } else {
                func_002E11F0(h, t, 0);
                func_002E11F0(h2, 0, c);
            }
        } else {
            func_002E11F0(h, t, t);
        }
    }
}

INCLUDE_ASM("asm/nonmatchings/game/t_2E7010", func_002E7F90);

struct S2E81_E {
    u32 unk0;
    char pad4[0x10];
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    char pad24[0x10];
    int unk34;
    char pad38[0x14];
};

extern "C" {
u32 func_002E3770(int);
void func_002E12D8(u32, int);
extern S2E81_E D_003EB000[2];
extern float D_003728B4;
}

GP_DATA(D_003728B4);
INCLUDE_ASM("asm/nonmatchings/game/t_2E7010", func_002E81B8);

extern "C" int func_002E8318(void) {
    for (int i = 0x10; i < 0x30; i++) {
        func_002E5BB8(i, 0xD);
        func_002E1488(i);
    }
    return 1;
}

extern "C" void func_002E8440(void) {
    for (int i = 0x10; i < 0x30; i++) {
        func_002E1488(i);
    }
    SndDrv_FlushCommands(0);
    func_002E1B50(0x25010);
    func_002E3AC0();
}

GP_DATA(D_003728B0);
extern "C" int func_002E8510(int a, int b, int c, int d, int, int flag) {
    func_002E3700(a, func_002E5718());
    func_002E3B08(D_0037321C, c, d);
    func_002E0B60(0x7F, D_003728B0, D_0037321C, 0);
    SndDrv_FlushCommands(0);
    func_002E5188(D_003728B0, 0);
    if (flag != 0) {
        func_002E3700(b, func_002E5718());
        func_002E3B08(D_0037321C, c + d, d);
        func_002E0B60(0x7F, D_003728B0, D_0037321C, 0);
        SndDrv_FlushCommands(0);
        func_002E5188(D_003728B0, 0);
    }
    return 1;
}

INCLUDE_ASM("asm/nonmatchings/game/t_2E7010", func_002E8610);

INCLUDE_ASM("asm/nonmatchings/game/t_2E7010", func_002E8960);

extern "C" void func_002E8968(void) {
    for (int i = 0x10; i < 0x30; i++) {
        func_002E1488(i);
    }
}

extern "C" int func_002E8A18(int a) {
    int i = func_002E5CA8(0, 0x2F, a);
    int n = 0;
    if (i >= 0) {
        do {
            n++;
            func_002E1488(i);
            i = func_002E5CA8(i + 1, 0x2F, a);
        } while (i >= 0);
    }
    SndDrv_FlushCommands(1);
    return n;
}

struct S2E8A_E {
    int unk0;
    char pad4[0x10];
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    int unk24;
    int unk28;
    int unk2C;
    int unk30;
    int unk34;
    char pad38[0x14];
};

extern "C" S2E8A_E D_003EB000_a[2] asm("D_003EB000");
extern "C" int func_002E8A98(int id, int mode, float f) {
    S2E8A_E *p = D_003EB000_a;
    int i = 0;
    int m = (u32)(mode - 1) < 2;
    do {
        if (p->unk0 == id) {
            if (m) {
                int v = (int)((f - D_003728B4) * (float)p->unk34);
                D_003EB000_a[i].unk24 = v;
                if (D_003EB000_a[i].unk2C != v) {
                    func_002E12D8(D_003EB000_a[i].unk14, v);
                    func_002E12D8(p->unk18, D_003EB000_a[i].unk24);
                    D_003EB000_a[i].unk2C = D_003EB000_a[i].unk24;
                }
            }
            if (mode == 2 || mode == 0) {
                int v = (int)((f - D_003728B4) * (float)p->unk34);
                D_003EB000_a[i].unk28 = v;
                if (D_003EB000_a[i].unk30 != v) {
                    func_002E12D8(D_003EB000_a[i].unk1C, v);
                    func_002E12D8(D_003EB000_a[i].unk20, D_003EB000_a[i].unk28);
                    D_003EB000_a[i].unk30 = D_003EB000_a[i].unk28;
                }
                return 1;
            }
            return 1;
        }
        p++;
        i++;
    } while (p < D_003EB000_a + 2);
    return 0;
}

INCLUDE_ASM("asm/nonmatchings/game/t_2E7010", func_002E8C08);

struct S2E8C_E {
    u32 unk0;
    char pad4[0x10];
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    char pad24[0x28];
};

extern "C" {
extern S2E8C_E D_003EB000_e[2] asm("D_003EB000");
void func_002E3610(int);
void func_002E3660(int);
void func_002E5598(int);
int SndDrv_FlushCommands(int);
}

INCLUDE_ASM("asm/nonmatchings/game/t_2E7010", func_002E8C28);

INCLUDE_ASM("asm/nonmatchings/game/t_2E7010", func_002E8D68);

GP_DATA(D_003728C4);
GP_DATA(D_003728C0);
GP_DATA(D_00372900);
GP_DATA(D_003728FC);
INCLUDE_ASM("asm/nonmatchings/game/t_2E7010", func_002E8FF0);
