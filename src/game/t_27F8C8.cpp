#include "common.h"

extern "C" {
extern int D_00368A38;

int func_0027F1E8(int, int, int);
int func_0027FAC8(int, char *, int, int, void (*)(void));
void func_0011A470(int);
int func_0011A380(int);
int func_00119610(int, int);
void func_001194B8(int);
void func_00119490(int, int);
}

INCLUDE_ASM("asm/nonmatchings/game/t_27F8C8", func_0027F8C8);

INCLUDE_ASM("asm/nonmatchings/game/t_27F8C8", func_0027F938);

INCLUDE_ASM("asm/nonmatchings/game/t_27F8C8", func_0027F9B0);

INCLUDE_ASM("asm/nonmatchings/game/t_27F8C8", func_0027FA40);

struct S27FAC8_N {
    u32 unk0;
    int unk4;
    int unk8;
};
extern "C" {
S27FAC8_N *func_0027B300(int, S27FAC8_N *);
int func_0027F410(int, int, char *, int);
int func_0027F610(int, char *, int, float);
int func_0027F6C8(int, int, char *, int);
int func_0027F728(int, int, char *, int);
int func_0027F788(int, int, char *, int);
int func_0027F8C8(int, int, char *, int);
int func_0027F938(int, int, char *, int);
int func_0027F9B0(int, int, char *, int, int);
int func_0027FA40(int, int, char *, int, int);
}
extern "C" int func_0027FAC8(int a, char *p, int len, int f, void (*cb)(void)) {
    int rem = len;
    S27FAC8_N *n = 0;
    if (a != 0) {
        n = func_0027B300(a, 0);
    }
    while (n != 0) {
        if (cb != 0) {
            cb();
        }
        int r = 0;
        switch ((n->unk0 >> 9) & 0x7F) {
        case 1:
            r = func_0027F410(n->unk4, n->unk8, p, rem);
            break;
        case 2:
            r = func_0027F610(n->unk4, p, rem, *(float *)&n->unk8);
            break;
        case 13:
            r = func_0027F6C8(n->unk4, n->unk8, p, rem);
            break;
        case 26:
            r = func_0027F728(n->unk4, n->unk8, p, rem);
            break;
        case 3:
            r = func_0027F788(n->unk4, n->unk8, p, rem);
            break;
        case 5:
            r = func_0027F8C8(n->unk4, n->unk8, p, rem);
            break;
        case 6:
            r = func_0027F938(n->unk4, n->unk8, p, rem);
            break;
        case 10:
            r = func_0027F9B0(n->unk4, n->unk8, p, rem, f);
            break;
        case 12:
            r = func_0027FA40(n->unk4, n->unk8, p, rem, f);
            break;
        case 7:
            r = func_0027F6C8(n->unk4, 0xB9C4F664, p, rem);
            break;
        }
        if (r == 0) {
            return 0;
        }
        rem -= r;
        p += r;
        n = func_0027B300(a, n);
    }
    if (rem == 0) {
        return 0;
    }
    rem--;
    *p = 0;
    return len - rem;
}

INCLUDE_ASM("asm/nonmatchings/game/t_27F8C8", func_0027FCD8);

extern "C" int func_0027FDF8(int a, int n) {
    int h = D_00368A38;
    int buf;
    int r;
    func_00119490(h, func_00119610(h, 0));
    buf = func_0011A380(n);
    r = func_0027FAC8(a, (char *)buf, n, 1, 0);
    func_0011A470(buf);
    func_001194B8(D_00368A38);
    return r;
}

INCLUDE_ASM("asm/nonmatchings/game/t_27F8C8", func_0027FE88);

INCLUDE_ASM("asm/nonmatchings/game/t_27F8C8", func_00280380);

INCLUDE_ASM("asm/nonmatchings/game/t_27F8C8", func_00280D08);

INCLUDE_ASM("asm/nonmatchings/game/t_27F8C8", func_002811F0);
