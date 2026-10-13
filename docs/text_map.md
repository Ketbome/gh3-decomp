# Map of .text

From string references and the call graph (inferred, not byte-verified). The game's object files come first in
link order, then the libraries; nothing above `0x2EC0B0` calls back into the game except `operator delete`
(`func_00297CF0`).

| Range | Contents | Evidence |
|---|---|---|
| `0x100000`-`0x103E88` | crt0 (`.temp_init`) | `crt0.s detected ProView` |
| `0x10C000`-`0x2EC0B0` | Game: Neversoft nxcommon engine (THUG2 lineage) and GH3 code | Neversoft class names, `THUG2 Viewer`, GH3 HUD/gem/whammy strings |
| `0x2DFB70`-`0x2E62C0` | Unoptimised C library inside the game range (`-O0 -fno-opt-stack`, `src/game/t_2DFB70.c`, written in C) | frame pointer `$fp`, empty delay slots |
| `0x2EC0B0`-`0x2ED018` | GameSpy SDK (what survived of it: query/reporting) | `%s.master.gamespy.com`, `final\\queryid\\1.1` |
| `0x2ED018`-`0x30C6C8` | Sony SDK 3.0: libpad2, libdma, libkernl, sifrpc, stdio, libdbc, libmc2, SN socket, libcdvd, libipu/libmpeg | `libpad2:`, `SceSifrpcBind`, `libmc2:`, `SNSOCKET.C`, `Libcdvd`, `sceMpegGetPicture` |
| `0x30C6C8`-`0x30E9E8` | Sony libccc (character code conversion) | `C-SJIS`, `C-EUCJP` |
| `0x30E9E8`-`0x3175E8` | libc (printf family, stdio) | `-Inf`, `(null)`, `ungetc error` |
| `0x3175E8`-`0x31B650` | libstdc++ / libgcc runtime of gcc 2.95 (`bad_alloc`, type_info, exceptions) | `9bad_alloc`, `17__class_type_info` |
| `0x31B650`-`0x31F5D0` | libm | `fmod`, `acosf`, `powf` |
| `0x31F5D0`-`0x32101C` | Sony libgraph | `sceGsPutDrawEnv`, `rom0:ROMVER` |

In `config/SLUS_216.72.yaml` everything from `0x2EC0B0` is still split as two assembly files (`lib/gamespy`,
`lib/sce`); only the game range is counted by `scripts/progress.py`.

## Known functions

| Address | What | Evidence |
|---|---|---|
| `0x113D20` | `operator new` (`__builtin_new`) | `new X` pattern, size argument |
| `0x297CF0` | `operator delete` | called from the libstdc++ type_info destructors; frees through a global heap |
