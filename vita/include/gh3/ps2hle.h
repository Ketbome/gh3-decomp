// ---------------------------------------------------------------------------
// gh3::hle — substituicao das bibliotecas do PS2.
//
// O executavel original chama a Sony SDK 3.0 em 0x2ED018..0x30C6C8 (libpad2,
// libdma, libkernl, sifrpc, stdio, libdbc, libmc2, socket, libcdvd,
// libipu/libmpeg) e libgraph em 0x31F5D0..0x32101C. No port essas chamadas nao
// podem existir como codigo MIPS: cada simbolo dessas faixas precisa de uma
// implementacao C++ sobre a camada gh3::platform.
//
// Enquanto a faixa nao estiver mapeada (docs/text_map.md ainda a marca como
// "none of their ranges are mapped"), `unimplemented()` registra o simbolo uma
// vez e devolve um valor neutro. Isso permite subir a engine e descobrir, por
// ordem de chamada, qual funcao da SDK precisa ser implementada primeiro.
// ---------------------------------------------------------------------------
#pragma once

#include <cstdint>

namespace gh3::hle {

void init();
void shutdown();

// Uma vez por frame, antes de gh3::port::frame(). Equivale ao vblank do PS2:
// e' onde a libgraph espera o flip e onde a libpad2 atualiza o estado.
void vblank();

// Tempo do sistema em microssegundos (sceKernelGetSystemTimeLow).
uint64_t ticks();

// Registro de handlers por nome de simbolo splat ("func_002ED120").
// O gerador de stubs (vita/tools/gen_hle_stubs.py) cria uma definicao fraca por
// endereco da faixa da SDK que chama call(symbol, args...).
using Handler = void (*)();

void bind(const char* symbol, Handler fn);
Handler lookup(const char* symbol);

// Loga "HLE nao implementado: <symbol>" na primeira chamada de cada simbolo.
void unimplemented(const char* symbol);

// true se `symbol` ja foi alcancado por um stub fraco (ou por unimplemented()),
// ou seja: quem respondeu por ele nao foi uma implementacao real.
bool was_reported(const char* symbol);

// --- Telemetria de stubs (Marco B1) ----------------------------------------
// Cada stub gerado por vita/tools/gen_stubs.py guarda um contador estatico e
// chama stub_hit() UMA vez, na primeira execucao (once-flag). O caminho quente
// fica com um unico incremento; nada de strcmp por chamada.
//
// `counter` aponta para o contador estatico do proprio stub (lido ao vivo no
// dump) e `caller` e' __builtin_return_address(0), o endereco de retorno para
// dentro da engine — e' o que responde "quem chamou o stub".
void stub_hit(const char* symbol, const unsigned* counter, const void* caller);

// Quantidade de stubs distintos ja executados.
unsigned reached_count();

// Soma das chamadas de todos os stubs alcancados ate agora.
unsigned long long stub_calls();

// Grava o relatorio em `path` (ux0:data/gh3/reachability.txt). Ordenado por
// numero de chamadas. Chamado periodicamente por vblank() e no shutdown();
// devolve false se o arquivo nao puder ser aberto.
bool dump_reachability(const char* path);

}  // namespace gh3::hle
