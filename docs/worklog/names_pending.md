# Names waiting to be applied

Suggested by workers from evidence. They go into `config/symbols/game.txt` only when no worker is running (renaming
changes the names workers use): then `apply_names.py`, `configure.py`, `sync_src.py`, `configure.py`, `ninja`.

| Address | Name | Evidence |
|---|---|---|
| 0x002DFF28 | SndDrv_CmdBegin | -O0 sound driver: starts a 16-bit command block for the IOP (O0 worker) |
| 0x002DFF78 | SndDrv_CmdEnd | ends the command block |
| 0x002E00C8 | SndDrv_Push16 | appends a 16-bit word |
| 0x002E0140 | SndDrv_Push32 | appends a 32-bit word |
| 0x002E01E8 | SndDrv_PushString | appends a string |
| 0x002E1BB0 | SndDrv_ParseIopState | reads the state returned by the IOP |
| 0x002E3248 | SndDrv_FlushCommands | sends the double buffer to the IOP thread |
| 0x002E4FD0 | SndDrv_ScaleVolume | volume scaling |
| 0x002E5F38 | SndDrv_Alloc | allocator of the driver |
