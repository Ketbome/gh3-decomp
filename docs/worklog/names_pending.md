# Names waiting to be applied

Suggested by workers from evidence. They go into `config/symbols/game.txt` only when no worker is running (renaming
changes the names workers use): then `apply_names.py`, `configure.py`, `sync_src.py`, `configure.py`, `ninja`.

| Address | Name | Evidence |
|---|---|---|
| 0x00118F20 | Heap_Alloc | (heap, size, align, 0); `new` falls back to it on D_00368A38 (range A worker) |
| 0x00119400 | Heap_Free | (heap, p); operator delete calls it with D_00368A38 (range A worker) |
| 0x00113D20 | operator_new | `new X` pattern, size argument (toolchain probe) |
| 0x00297CF0 | operator_delete | called by the libstdc++ type_info destructors |
