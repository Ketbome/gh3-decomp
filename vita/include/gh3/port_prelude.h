// ---------------------------------------------------------------------------
// Prelude do build de port — forcado com -include antes de cada .cpp/.c de
// gh3-decomp/src/game.
//
// A arvore de matching depende de `include/common.h` (que inclui
// include_asm.h e emite .include de assembly MIPS) e de macros que so fazem
// sentido para o ee-gcc: GP_DATA, TEXT_PAD, OBJECT_END. Aqui elas viram no-ops
// e os typedefs sao redefinidos com larguras corretas para ARM (u64/s64 sao
// 64-bit no PS2, mas `unsigned long` tem 32-bit no ARMv7).
//
// O header e' C e C++: t_2DFB70.c (driver de som) e' compilado como C.
//
// NAO use este header no build de matching.
// ---------------------------------------------------------------------------
#pragma once

#ifndef GH3_PORT_PRELUDE_H
#define GH3_PORT_PRELUDE_H

// Faz `#include "common.h"` virar no-op (o guard do header e' COMMON_H).
#define COMMON_H 1

#ifdef __cplusplus
#include <cstdint>
typedef std::int8_t   s8;
typedef std::uint8_t  u8;
typedef std::int16_t  s16;
typedef std::uint16_t u16;
typedef std::int32_t  s32;
typedef std::uint32_t u32;
typedef std::int64_t  s64;
typedef std::uint64_t u64;
#else
#include <stdint.h>
typedef int8_t   s8;
typedef uint8_t  u8;
typedef int16_t  s16;
typedef uint16_t u16;
typedef int32_t  s32;
typedef uint32_t u32;
typedef int64_t  s64;
typedef uint64_t u64;
#endif

typedef float f32;

// Uma funcao ainda em assembly MIPS nao existe no port: o linker a resolve
// pelo stub fraco gerado em build-vita/generated (vita/tools/gen_stubs.py).
#define INCLUDE_ASM(folder, name)
#define INCLUDE_RODATA(folder, name)

// Macros do build byte-identico: sem efeito fora do ee-gcc.
#define GP_DATA(sym)
#define TEXT_PAD(n)
#define OBJECT_END()

#endif  // GH3_PORT_PRELUDE_H
