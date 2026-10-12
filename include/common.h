#ifndef COMMON_H
#define COMMON_H

#define INCLUDE_ASM_USE_MACRO_INC 1
#include "include_asm.h"

/* Padding the original has behind a function: the end of one of its object files (scripts/fix_padding.py). */
/* A small global the original object defined itself, so SN's one-pass assembler already knew its size and reached it
 * through $gp everywhere after this point (scripts/asm_filter.py, scripts/fix_gp_data.py). */
#define GP_DATA(sym) __asm__(".extern " #sym ", 4\n")

#define TEXT_PAD(n) __asm__(".section .text\n    .space " #n "\n")

typedef signed char s8;
typedef unsigned char u8;
typedef signed short s16;
typedef unsigned short u16;
typedef signed int s32;
typedef unsigned int u32;
typedef signed long s64;
typedef unsigned long u64;
typedef float f32;

#endif
