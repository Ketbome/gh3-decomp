// ---------------------------------------------------------------------------
// Stub fraco da engine.
//
// Permite que o binario Vita compile, linke e rode ANTES de a engine estar
// portada: tela preta, pad lido, audio em silencio, combo START+SELECT sai.
//
// Quando vita/src/engine.cpp existir com as versoes fortes, este arquivo
// continua no build sem conflito: o linker prefere a definicao forte.
// ---------------------------------------------------------------------------
#include <cstddef>
#include <cstring>

#include "gh3/fs.h"
#include "gh3/platform.h"
#include "gh3/port.h"

namespace gh3::port {

__attribute__((weak)) bool init() {
    platform::log("engine: stub ativo (nenhuma engine linkada)");
    platform::log("engine: esperando assets em %s", fs::root());
    return true;
}

__attribute__((weak)) void frame() {
    // Nada a fazer: o frame e' so o clear + swap da plataforma.
}

__attribute__((weak)) void shutdown() {
    platform::log("engine: stub encerrado");
}

__attribute__((weak)) void audio_render(int16_t* out, int frames) {
    if (out && frames > 0) {
        std::memset(out, 0,
                    static_cast<std::size_t>(frames) * 2 * sizeof(int16_t));
    }
}

}  // namespace gh3::port
