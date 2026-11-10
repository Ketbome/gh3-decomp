// ---------------------------------------------------------------------------
// HLE das bibliotecas do PS2.
//
// Estado atual: o mapa de .text (docs/text_map.md) identifica as faixas, mas
// nenhuma funcao da Sony SDK foi nomeada. Portanto este arquivo entrega:
//   - o contrato (init/vblank/ticks),
//   - o registro simbolo -> handler,
//   - a telemetria de stubs (Marco B1): quem foi chamado, quantas vezes e de
//     onde veio a chamada, despejada em ux0:data/gh3/reachability.txt.
//
// Ordem pratica de implementacao (por faixa de endereco):
//   0x2ED018.. libpad2   -> read_pad()          (ja existe em platform)
//   0x2F....  libcdvd    -> gh3::fs
//   0x2F....  libmc2     -> ux0:data/gh3/saves
//   0x2E....  sifrpc     -> chamadas sincronas: no Vita viram chamadas diretas
//   0x31F5D0.. libgraph  -> vitaGL
//   0x2ED018.. libkernl  -> sceKernel* (threads, semaforos)
// ---------------------------------------------------------------------------
#include "gh3/ps2hle.h"

#include <algorithm>
#include <cstdio>
#include <cstring>

#include "gh3/fs.h"
#include "gh3/platform.h"

namespace gh3::hle {
namespace {

constexpr int kMaxBindings = 512;

// Teto da tabela de alcance. O gerador emite ~3.2k stubs hoje; 4096 da folga
// para a engine crescer sem perder registro (o excedente so deixa de aparecer
// no relatorio, nao quebra nada).
constexpr int kMaxReached = 4096;

// Periodo do dump automatico: 300 frames ~ 5 s a 60 fps. Se o jogo travar no
// meio do bring-up, o relatorio em disco ainda tem o que foi alcancado.
constexpr unsigned kDumpEveryFrames = 300;

struct Binding {
    const char* symbol;
    Handler     fn;
};

Binding g_bindings[kMaxBindings];
int     g_binding_count = 0;

// Simbolos reportados por unimplemented(). Lista separada e pequena: esses
// simbolos passam pelo caminho lento e precisam de deduplicacao por nome.
const char* g_reported[kMaxBindings];
int         g_reported_count = 0;

// Tabela de alcance dos stubs. Append-only e sem deduplicacao: o gerador cria
// exatamente um stub por nome unico e cada um chama stub_hit() uma unica vez
// (once-flag no proprio stub). O contador aponta para o static do stub e e'
// lido ao vivo no dump.
struct Reached {
    const char*     symbol;
    const unsigned* counter;
    const void*     caller;
};

Reached  g_reached[kMaxReached];
int      g_reached_count = 0;
bool     g_reach_dirty   = false;
unsigned g_reach_frames  = 0;

bool already_reported(const char* symbol) {
    for (int i = 0; i < g_reported_count; ++i) {
        if (std::strcmp(g_reported[i], symbol) == 0) {
            return true;
        }
    }
    return false;
}

bool already_reached(const char* symbol) {
    for (int i = 0; i < g_reached_count; ++i) {
        if (std::strcmp(g_reached[i].symbol, symbol) == 0) {
            return true;
        }
    }
    return false;
}

const char* reachability_path() {
    static char path[512];
    const char* root = fs::root();
    std::snprintf(path, sizeof(path), "%s/reachability.txt",
                  root ? root : "ux0:data/gh3");
    return path;
}

bool by_hits_desc(const Reached& a, const Reached& b) {
    const unsigned ha = a.counter ? *a.counter : 0;
    const unsigned hb = b.counter ? *b.counter : 0;
    if (ha != hb) {
        return ha > hb;
    }
    return std::strcmp(a.symbol, b.symbol) < 0;
}

}  // namespace

void init() {
    platform::log("HLE: servicos do PS2 inicializados");
}

void shutdown() {
    if (g_reached_count > 0) {
        dump_reachability(reachability_path());
    }
    g_binding_count  = 0;
    g_reported_count = 0;
    g_reached_count  = 0;
    g_reach_dirty    = false;
}

void vblank() {
    // O estado do pad e' lido sob demanda em platform::read_pad(); o resto e'
    // contabilidade. O dump periodico existe para sobreviver a um travamento.
    ++g_reach_frames;
    if (g_reach_dirty && (g_reach_frames % kDumpEveryFrames) == 0) {
        g_reach_dirty = false;
        dump_reachability(reachability_path());
    }
}

uint64_t ticks() {
    // sceKernelGetSystemTimeLow devolve microssegundos.
    return static_cast<uint64_t>(platform::now_seconds() * 1000000.0);
}

void bind(const char* symbol, Handler fn) {
    if (!symbol || !fn || g_binding_count >= kMaxBindings) {
        return;
    }
    for (int i = 0; i < g_binding_count; ++i) {
        if (std::strcmp(g_bindings[i].symbol, symbol) == 0) {
            g_bindings[i].fn = fn;
            return;
        }
    }
    g_bindings[g_binding_count++] = Binding{symbol, fn};
}

Handler lookup(const char* symbol) {
    if (!symbol) {
        return nullptr;
    }
    for (int i = 0; i < g_binding_count; ++i) {
        if (std::strcmp(g_bindings[i].symbol, symbol) == 0) {
            return g_bindings[i].fn;
        }
    }
    return nullptr;
}

void unimplemented(const char* symbol) {
    if (!symbol || already_reported(symbol)) {
        return;
    }
    if (g_reported_count < kMaxBindings) {
        g_reported[g_reported_count++] = symbol;
    }
    platform::log("HLE nao implementado: %s", symbol);
}

void stub_hit(const char* symbol, const unsigned* counter, const void* caller) {
    if (!symbol) {
        return;
    }
    // Duas guardas: o teto da tabela e a chamada repetida do mesmo simbolo
    // (possivel se um stub forte for substituido em tempo de execucao).
    if (g_reached_count >= kMaxReached || already_reached(symbol)) {
        return;
    }
    g_reached[g_reached_count++] = Reached{symbol, counter, caller};
    g_reach_dirty = true;

    // Uma linha por simbolo, na primeira execucao. A contagem fica no
    // relatorio; aqui o objetivo e' a ordem de descoberta no console.
    platform::log("[STUB REACHED] %s <- %p", symbol, caller);
}

unsigned reached_count() {
    return static_cast<unsigned>(g_reached_count);
}

unsigned long long stub_calls() {
    unsigned long long total = 0;
    for (int i = 0; i < g_reached_count; ++i) {
        if (g_reached[i].counter) {
            total += *g_reached[i].counter;
        }
    }
    return total;
}

bool dump_reachability(const char* path) {
    if (!path) {
        return false;
    }
    std::FILE* f = std::fopen(path, "w");
    if (!f) {
        platform::log("relatorio de alcance: nao consegui abrir %s", path);
        return false;
    }

    // O eboot e' realocado no load (ASLR): o endereco de retorno so vira
    // offset estavel depois de descontar a base do modulo.
    const uintptr_t base = platform::module_base();

    std::fprintf(f, "=== GH3 Vita - alcance dos stubs ===\n");
    std::fprintf(f, "frame       : %llu\n",
                 static_cast<unsigned long long>(platform::frame_index()));
    std::fprintf(f, "tempo       : %.2f s\n", platform::now_seconds());
    std::fprintf(f, "modulo      : 0x%08lX\n", static_cast<unsigned long>(base));
    // Ancora: permite ao symbolize.py calibrar a diferenca entre a base do
    // modulo em execucao e o primeiro PT_LOAD do ELF.
    std::fprintf(f, "ancora      : 0x%08lX\n",
                 static_cast<unsigned long>(
                     reinterpret_cast<uintptr_t>(&stub_hit)));
    std::fprintf(f, "stubs       : %d alcancados, %llu chamadas\n",
                 g_reached_count, stub_calls());
    std::fprintf(f, "\n");
    std::fprintf(f, "# chamadas  offset      retorno     simbolo\n");
    std::fprintf(f, "# simbolize: vita/tools/symbolize.py <elf> <este arquivo>\n");
    std::fprintf(f, "\n");

    // Ordena no proprio vetor: a ordem de registro nao e' usada por ninguem.
    // vblank() roda na thread principal, antes de gh3::port::frame(), entao nao
    // ha stub sendo registrado durante o dump.
    const int n = g_reached_count;
    std::sort(g_reached, g_reached + n, by_hits_desc);

    for (int i = 0; i < n; ++i) {
        const Reached& e = g_reached[i];
        const unsigned hits = e.counter ? *e.counter : 0;
        const uintptr_t caller = reinterpret_cast<uintptr_t>(e.caller);

        char offset[24] = "-";
        if (base != 0 && caller >= base) {
            std::snprintf(offset, sizeof(offset), "+0x%lX",
                          static_cast<unsigned long>(caller - base));
        }
        std::fprintf(f, "%10u  %-11s 0x%08lX  %s\n", hits, offset,
                     static_cast<unsigned long>(caller), e.symbol);
    }

    std::fclose(f);
    platform::log("relatorio de alcance: %d stubs em %s", n, path);
    return true;
}

bool was_reported(const char* symbol) {
    return symbol && (already_reported(symbol) || already_reached(symbol));
}

}  // namespace gh3::hle
