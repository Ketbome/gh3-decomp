# Decompiling a function

Every function of the game lives in a file under `src/game/` (`t_<address of its first function>.cpp`), either as
C++ or as `INCLUDE_ASM("asm/nonmatchings/game/<file>", func_XXXXXXXX);`, which pulls in the original assembly.
Decompiling a function means replacing its INCLUDE_ASM line with C++ that compiles to the same bytes.

## Loop

Commands are `scripts/dk.py` (run as `.venv/bin/python scripts/dk.py ...`, configured by `decomp.toml`).

1. Pick: `dk next <files> --untried [--max-size 0x400]` (smallest first; flags `jtbl`, `vu0:N%`, `fragment?`).
2. Look: `dk show <func>`: the original assembly (from `asm/`, made by `configure.py`), its labels, an m2c draft and
   the file that holds it.
3. Replace the INCLUDE_ASM line with C++ at the same place in the file (the order of functions is the order in the
   executable).
4. Check: `dk try <file> <func>`. It adds the GP_DATA lines the file needs (`scripts/fix_gp_data.py`, see Globals),
   compiles the file privately and compares that function only; several checks can run at once. Repeat until `MATCH`.
5. If it does not match after a reasonable effort, put the INCLUDE_ASM line back (`dk revert <file> <func>`). Never
   leave a non-matching function in C++.
6. `dk done <file> <worklog> "<message>"`: adds `TEXT_PAD(n);` where the original has 8+ bytes of padding after a
   function (the end of one of its object files, `scripts/fix_padding.py`), refuses unless every function of the
   file matches, and commits the file and the worklog.
7. `ninja -j4` (one at a time; integrator only) confirms the whole executable is still byte-identical.

After adding names to `config/symbols/`, run `scripts/apply_names.py`, `configure.py`, `scripts/sync_src.py` and
`configure.py` again: a new name can split a function in two, and sync_src adds the INCLUDE_ASM line for the new one.

## Working in parallel (agents)

Each worker owns a set of `src/game` files and nobody else edits them. The protocol is `docs/agent_protocol.md`.
To survive a crash without losing work:

- Keep a log in `docs/worklog/<your range>.md`: per file, what was matched and every function you gave up on with
  one line on why (so nobody retries it blindly). Read the notes at its top when you start; `dk next --untried`
  leaves out every function the worklogs mention, and `grep -n <func> docs/worklog/*.md` gives one's history.
- Commit after each file or every few functions with `dk done` (it retries if git's `index.lock` exists). Never
  `git add -A`, never push, never commit someone else's file.
- Do not run `configure.py`, `ninja` or splat: one integrator does that.

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
  loaded the same way), no `static` variables. `dk check` reports a file that has data of its own. Small strings and constants (8 bytes or
  less) live in `.sdata` and are reached through `$gp` (`%gp_rel`); larger ones through `%hi`/`%lo`.
  Float constants built inline (`lui`/`ori`/`mtc1 $at`) are plain literals (`57.29578f`): the build rewrites
  `li.s` like SN's assembler did. Constants loaded with `lwc1` from a `D_` symbol are variables: declare them.
- **`switch` with a jump table** (`jtbl_` in the asm) is fine: the build drops the table the compiler writes and
  points the code at the game's own table (`scripts/asm_filter.py`), and configure.py defines the case labels
  (`build/jlabels.ld`). The cases must come out in the original order and addresses, which a byte match proves.
- **Globals: `$gp` or `lui`.** Declare globals plainly (`extern int D_X;`). The build reproduces SN's one-pass
  assembler (`scripts/asm_filter.py`): a global is reached with `lui`+`%lo` outside delay slots and with `%gp_rel`
  inside them, unless the original object defined the symbol itself; then the original uses `%gp_rel` everywhere
  after that point, and the file needs `GP_DATA(D_X);` before the first function using it.
  `scripts/fix_gp_data.py <file>` adds those lines from the original assembly: run it before judging a DIFFERS.
- **A lone `nop` that 8-aligns a label** (often after a `beql` slot, with no loop in sight) is the head of a loop
  that `-funroll-loops` unrolled completely: write the original loop (e.g. two fields 0x38 apart are
  `for (i = 0; i < 2; i++)` over an array of 0x38-byte elements) and give the file `// cflags: -funroll-loops`.
- **VU0 code** (`lqc2`/`sqc2`/`vadd`/`vmul`/`qmfc2`..., flagged `vu0` by `dk next`) was inline asm in the
  original, with the VU registers written out (`$vf1`, `$vf2`...). Write the same instructions in an `asm()` with
  the GPR operands as constraints; the compiler places it, the assembler fills delay slots as it did then.
  Verified (func_0010F6D8, a vector add returning 128 bits):
  ```cpp
  typedef unsigned int u128 __attribute__((mode(TI)));
  extern "C" u128 func_0010F6D8(const u128* a, const u128* b) {
      u128 r;
      asm("lqc2 $vf2, 0(%1)\n\tlqc2 $vf1, 0(%2)\n\tvadd.xyzw $vf3, $vf2, $vf1\n\tqmfc2.ni %0, $vf3"
          : "=r"(r) : "r"(a), "r"(b));
      return r;
  }
  ```
  In a larger function, put each run of VU0 instructions in its own asm() where the original has it, and let
  the compiler do the rest; `asm volatile` and `"memory"` clobbers keep the order when it matters. Functions that
  are almost all VU0 (>40%) were probably whole asm functions: leave those.
- **`sqrt.s`** is encoded the R5900 way (operand in the ft field) by the prelude: write `sqrtf`/`__builtin_sqrtf`
  with `-ffast-math`, or the plain instruction in VU0 asm, and it assembles like the original (`c1 0xC0304` in splat's
  listing).
- **VU0 stages:** separate non-volatile `asm()` blocks chained through a dummy `"=r"`/`"+r"` operand let gcc
  interleave ordinary instructions between stages; `asm volatile` and output-less asms pin the order instead.
- **Inline asm.** PS2 instructions the compiler cannot emit (MMI such as `pextlw`/`pcpyld`/`pcpyud`, COP2/VU0)
  were written as inline asm in the original too: fine. Empty `asm("" : "+r"(x))` barriers and
  `register T x asm("$N")` pins are a last resort. Ordinary instructions in asm only to force the compiler's hand
  (`asm("li ...")`, `asm("nop")`) are not source code: don't (two old cases, t_1C7AA0 and t_12B970, wait to be
  rewritten).
- **Per-file flags.** Some original objects were built with more than `-O2` (loops unrolled only with
  `-funroll-loops`). A file can ask for flags with a line `// cflags: -funroll-loops` in its first 10 lines;
  configure.py and dk both read it. Seen so far: `-funroll-loops`, `-ffast-math`
  (`min.s`/`max.s`), and `-O0 -fno-opt-stack` for the unoptimised C library in `t_2DFB70.c` (a C file: plain C, no
  `extern "C"`; C++ at -O0 emits extra jumps)
  (0x2DFB70-0x2E62C0: frame pointer, empty delay slots; the assembler then also runs with `-O0`). It applies to the whole file, so only use it when every C++ function
  of the file still matches.
- **Structs.** Use a struct with the fields the function touches, named by offset (`unk18`), padded with
  `char pad[...]`. Define it at the top of the file. Do not edit shared headers.
- **Types.** `s8 u8 s16 u16 s32 u32 f32` (`include/common.h`). `int`/pointers are 32 bits; `long` is 64 bits
  (`ld`/`sd` on values that are not saved registers mean a 64-bit type or a `u_long128` copy).
- **`sq` saves of `$s` registers** (ascending offsets) mean those registers hold 128-bit values in the function:
  with `-fopt-stack` each register is saved at the width it is used. Declare the values as
  `typedef unsigned int u128 __attribute__((mode(TI)));` (arguments in `$a3`/`$t0`.. moved with `daddu` are often
  such values). It is not a toolchain gap.
- **Compiler habits** (SN ee-gcc 2.95.3, `-O2 -G8`): register moves are `daddu rd, rs, $0`; constructors return
  `this`; no tail calls; `bool` is one byte; `new` is `func_00113D20(size)` and `delete` is `func_00297CF0(p)`.
- **libc names** (`strlen`, `strcpy`, `strcmp`, `memset`, see `config/symbols/lib.txt`): declare them with their
  standard signatures (`unsigned int strlen(const char*)`), or gcc warns that they conflict with its built-ins.
- Neversoft names things by checksums of their names (`0x0A015E17` is `"Motion"`): keep them as hex constants
  with the name in a comment, `0x0A015E17 /* Motion */`. `config/qbkeys.txt` lists the known ones;
  `scripts/qbkeys.py key <name>` computes one.

## Near misses: the permuter

`scripts/permute.py <file with the attempt> <func> -j 2` sets up decomp-permuter with our toolchain and runs it:
it mutates the attempt at random and writes each better version to `build/permute/<func>/output-<score>-N/`.
Score 0 is a match. It is CPU-heavy: one at a time, few threads.

## Useful facts

- `docs/toolchain.md`: compiler, flags, sections.
- `docs/text_map.md`: what is game code and what is library code.
- `config/symbols/cfuncs.txt`: the 941 script commands (`CFunc_<name>`), named from the game's own command table.
