# Decompiling a function

Every function of the game lives in a file under `src/game/` (`t_<address of its first function>.cpp`), either as
C++ or as `INCLUDE_ASM("asm/nonmatchings/game/<file>", func_XXXXXXXX);`, which pulls in the original assembly.
Decompiling a function means replacing its INCLUDE_ASM line with C++ that compiles to the same bytes.

## Loop

1. Read the function: `asm/nonmatchings/game/<file>/func_XXXXXXXX.s` (run `configure.py` once to create them).
2. Get a draft: `.venv/bin/m2c -t mipsee-gcc-c asm/nonmatchings/game/<file>/func_XXXXXXXX.s`.
3. Replace the INCLUDE_ASM line with C++ at the same place in the file (the order of functions is the order in the
   executable).
4. Check: `.venv/bin/python scripts/fcheck.py src/game/<file>.cpp func_XXXXXXXX`. It compiles the file privately and
   compares that function only; several checks can run at once. Repeat until `MATCH`.
5. If it does not match after a reasonable effort, put the INCLUDE_ASM line back. Never leave a non-matching
   function in C++.
6. `ninja` (one at a time) confirms the whole executable is still byte-identical.

## Rules that keep the build matching

- **Names and linkage.** The executable is stripped. Until a function's real class and name are known, write it as
  `extern "C"` with the splat name, and declare what it calls the same way:
  ```cpp
  extern "C" {
  void* func_00113D20(u32 size);
  extern int D_00368778;
  }

  extern "C" void func_001170C8(int v) {
      D_00368778 = v;
  }
  ```
  A member function is a plain function whose first argument is `this` (`$a0`); the code is the same.
  Declarations go at the top of the file, in one `extern "C" { }` block.
- **No data of the file's own.** The rodata/data of the game stays in `asm/data` for now, so C++ must not create any:
  no string literals (`(char*)D_00364338` for an existing string: declare `extern char D_00364338[];`), no float
  literals that the compiler would put in `.lit4` (declare the existing constant: `extern float D_0036A0F0;`, it is
  loaded the same way), no `static` variables, no `switch` that becomes a jump table (`jtbl_` in the asm: leave it
  as INCLUDE_ASM). `fcheck.py` reports a file that has data of its own. Small strings and constants (8 bytes or
  less) live in `.sdata` and are reached through `$gp` (`%gp_rel`); larger ones through `%hi`/`%lo`.
  A float constant whose low 16 bits are zero is built with `lui`+`mtc1`: that one is a literal (`1.0f`).
- **Structs.** Use a struct with the fields the function touches, named by offset (`unk18`), padded with
  `char pad[...]`. Define it at the top of the file. Do not edit shared headers.
- **Types.** `s8 u8 s16 u16 s32 u32 f32` (`include/common.h`). `int`/pointers are 32 bits; `long` is 64 bits
  (`ld`/`sd` on values that are not saved registers mean a 64-bit type or a `u_long128` copy).
- **Compiler habits** (SN ee-gcc 2.95.3, `-O2 -G8`): register moves are `daddu rd, rs, $0`; constructors return
  `this`; no tail calls; `bool` is one byte; `new` is `func_00113D20(size)` and `delete` is `func_00297CF0(p)`.
- Neversoft names things by CRC32 checksums (`0x0A015E17`): keep them as hex constants.

## Useful facts

- `docs/toolchain.md`: compiler, flags, sections.
- `docs/text_map.md`: what is game code and what is library code.
