#include "common.h"

INCLUDE_ASM("asm/nonmatchings/game/t_23A4F0", func_0023A4F0);

extern "C" char* func_0023A4F8(char** p, int i) {
    return p[2] + i * 0x13C;
}

INCLUDE_ASM("asm/nonmatchings/game/t_23A4F0", func_0023A510);

INCLUDE_ASM("asm/nonmatchings/game/t_23A4F0", func_0023A720);

INCLUDE_ASM("asm/nonmatchings/game/t_23A4F0", func_0023A758);

extern "C" int func_0023A858(f32* out, f32 a, f32 b, f32 c, f32 d, f32 e, f32 f, f32 g, f32 h) {
    f32 nc = -d;
    f32 x = a - e;
    f32 y = b - f;
    f32 den = g * nc + h * c;
    f32 n1 = x * -h + y * g;
    f32 n2 = x * nc + y * c;
    if (0.0f < den) {
        if (n1 < 0.0f || den < n1) return 0;
    } else {
        if (0.0f < n1 || n1 < den) return 0;
    }
    if (den > 0.0f) {
        if (n2 < 0.0f || den < n2) return 0;
    } else {
        if (n2 > 0.0f || n2 < den) return 0;
    }
    if (__builtin_fabsf(den) < 1e-11f) {
        *out = 0.0f;
        return 1;
    }
    *out = n1 / den;
    return 1;
}

INCLUDE_ASM("asm/nonmatchings/game/t_23A4F0", func_0023A988);

INCLUDE_ASM("asm/nonmatchings/game/t_23A4F0", func_0023AEA0);

INCLUDE_ASM("asm/nonmatchings/game/t_23A4F0", func_0023BD90);
