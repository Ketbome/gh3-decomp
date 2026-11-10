// ---------------------------------------------------------------------------
// Cola entre a plataforma Vita e a engine decompilada.
//
// Este arquivo define as versoes FORTES de gh3::port::*; os weak de
// engine_stub.cpp perdem no link. Ele so entra no build com
// -DGH3_BUILD_ENGINE=ON, porque depende de gh3_data_arena (gerado).
//
// O que ele faz hoje:
//   1. copia o bloco de dados inicializados do executavel do PS2
//      (.data/.rodata/.sdata, ROM 0x22A080..0x272A40) para a arena .bss
//      gerada por gen_stubs.py, preservando os offsets originais;
//   2. no primeiro frame, chama a entrada do jogo (func_0010C000).
//
// Estado da entrada: func_0010C000 ainda e' INCLUDE_ASM, entao hoje ela e' um
// stub fraco que loga "HLE nao implementado" e devolve 0. O port sobe, carrega
// os dados e para. Quando a entrada for decompilada (ou substituida por um
// reimplemento), este arquivo nao muda: o linker passa a usar a versao forte.
//
// Efeito colateral util: hoje a unica funcao da engine que o binario chama e'
// func_0010C050 (RNG, decompilada em t_10C000.cpp), como smoke test. E' o que
// faz o linker puxar o primeiro objeto real de gh3_engine; sem isso a
// biblioteca inteira ficaria de fora do .self.
//
// Quando a entrada real rodar, ela NAO volta: o laco do jogo e' dela. A
// fronteira de frame passa a ser gh3::hle::vblank() (chamado pela libgraph),
// e e' la que o swap do vitaGL e o pump de eventos vao morar.
// ---------------------------------------------------------------------------
#include <cstddef>
#include <cstdio>
#include <cstring>

#include "gh3/fs.h"
#include "gh3/platform.h"
#include "gh3/port.h"
#include "gh3/ps2hle.h"

extern "C" {

// Entrada do jogo. O crt0 do PS2 (.temp_init, 0x00103D08) salta para a
// primeira funcao de .text; ver docs/text_map.md. Sem chamadores em C++.
int func_0010C000(void);

// RNG do jogo (mesmo arquivo, t_10C000.cpp), ja decompilado em C++. Serve de
// smoke test: se ele roda, o codigo real da engine linkou e a arena responde.
int func_0010C050(int n);

// Arena gerada por vita/tools/gen_stubs.py (data_arena.cpp).
extern unsigned char gh3_data_arena[];
extern unsigned char gh3_data_arena_end[];

}  // extern "C"

namespace gh3::port {
namespace {

// Bloco de dados inicializados do executavel: .data + .rodata +
// .gcc_except_table + .sdata, sem os buracos de alinhamento entre secoes
// (config/SLUS_216.72.yaml, "cada subsegmento vai ate o proximo").
constexpr unsigned kDataVramStart = 0x0032A080;  // inicio de .data
constexpr unsigned kDataVramEnd   = 0x00372A40;  // fim de .sdata
constexpr std::size_t kDataSize   = kDataVramEnd - kDataVramStart;  // 0x489C0

constexpr const char* kDataFile = "gh3_data.bin";
constexpr const char* kEntry    = "func_0010C000";

bool  g_entry_started = false;
bool  g_data_loaded   = false;

// Copia o blob para a arena. Os simbolos do jogo sao rotulos em
// gh3_data_arena + (endereco - 0x32A080), entao o memcpy direto reconstroi
// strings, tabelas de salto e constantes float nos enderecos originais.
bool load_data() {
    const std::size_t arena_size =
        static_cast<std::size_t>(gh3_data_arena_end - gh3_data_arena);
    if (arena_size < kDataSize) {
        platform::log("arena de dados pequena: %zu < %zu bytes",
                      arena_size, kDataSize);
        return false;
    }

    char path[512];
    std::snprintf(path, sizeof(path), "%s/%s", fs::root(), kDataFile);

    std::FILE* f = std::fopen(path, "rb");
    if (!f) {
        platform::log("sem %s: a arena fica zerada", path);
        platform::log("  gere com: python vita/tools/extract_data.py");
        return false;
    }

    std::fseek(f, 0, SEEK_END);
    const long size = std::ftell(f);
    std::fseek(f, 0, SEEK_SET);

    if (size < static_cast<long>(kDataSize)) {
        platform::log("%s tem %ld bytes, esperado %zu", path, size, kDataSize);
        std::fclose(f);
        return false;
    }

    const std::size_t got = std::fread(gh3_data_arena, 1, kDataSize, f);
    std::fclose(f);

    if (got != kDataSize) {
        platform::log("leitura curta de %s: %zu de %zu bytes", path, got,
                      kDataSize);
        return false;
    }

    platform::log("dados: %zu KiB de 0x%08X..0x%08X em %s", kDataSize / 1024,
                  kDataVramStart, kDataVramEnd, path);
    return true;
}

}  // namespace

bool init() {
    g_data_loaded   = load_data();
    g_entry_started = false;

    if (!g_data_loaded) {
        // Nao e' fatal: a entrada ainda e' stub e nao le nada. Vira fatal
        // quando a engine comecar a rodar de verdade.
        platform::log("engine: seguindo com a arena zerada");
    }
    return true;
}

void frame() {
    if (g_entry_started) {
        return;
    }
    g_entry_started = true;

    platform::log("engine: entrando em %s (0x0010C000)", kEntry);
    const int rc = func_0010C000();

    // O stub chama hle::unimplemented() antes de devolver; se ele foi
    // reportado, quem respondeu foi o stub, nao a engine.
    if (hle::was_reported(kEntry)) {
        platform::log("engine: %s ainda e' stub (INCLUDE_ASM) - nada executou",
                      kEntry);

        // Smoke test: funcao decompilada de verdade (mesmo arquivo do entry).
        // Prova que o codigo da engine linkou em ARM e que a arena responde:
        // func_0010C050 usa os 6 seeds D_00372A8x do .data do PS2.
        const int r1 = func_0010C050(1);
        const int r2 = func_0010C050(1000);
        platform::log("smoke: RNG %d, %d (0 = arena zerada, sem gh3_data.bin)",
                      r1, r2);
    } else {
        platform::log("engine: %s retornou %d", kEntry, rc);
    }
}

void shutdown() {
    platform::log("engine: shutdown (dados %s)",
                  g_data_loaded ? "carregados" : "ausentes");
}

void audio_render(int16_t* out, int frames) {
    // O driver de som do PS2 (0x2DFB70) ainda nao foi portado: silencio.
    std::memset(out, 0, static_cast<std::size_t>(frames) * 2 * sizeof(int16_t));
}

}  // namespace gh3::port
