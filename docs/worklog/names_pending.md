# Names waiting to be applied

Suggested by workers from evidence. They go into `config/symbols/game.txt` only when no worker is running (renaming
changes the names workers use): then `apply_names.py`, `configure.py`, `sync_src.py`, `configure.py`, `ninja`.

| Address | Name | Evidence |
|---|---|---|
| 0x00118798 | CreateSema | wraps the kernel semaphore creation (range A worker) |
| 0x001187D0 | WaitSema | wraps the kernel semaphore wait (range A worker) |
| 0x0014C390 | HashTable_GetItem | hash table lookup (range A worker) |
| 0x0014C4A8 | HashTable_FlushItem | hash table removal (range A worker) |
| 0x001824B8 | BcdToInt | `(v>>4)*10 + (v&0xF)` |
| 0x00115028 | CrcFromPathLowercase | CRC32 table D_0032A080, lowercases, '/' to '\\' |
| 0x001DCCB0 | PoolAlloc | picks a pool from D_0036D540, falls back to the main heap |
| 0x001DCE20 | PoolFree | frees into the pool whose range holds the pointer |
| 0x002979D8 | RbTreeIncrement | in-order successor walk (range C worker) |
| 0x00297838 | RbTreeDecrement | in-order predecessor walk (range C worker) |
| 0x002756A8 | StrDupHeap5 | strdup into heap 5 (range C worker) |
