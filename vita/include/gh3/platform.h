// ---------------------------------------------------------------------------
// gh3::platform — unica superficie do jogo que toca o hardware.
//
// Tudo que no PS2 vinha de libgraph/libpad2/libcdvd/libmc2/sifrpc passa por
// aqui. A engine (decompilada) nao deve chamar SDL2/vitaGL/Sce* diretamente:
// ela chama esta camada, que em um port de desktop pode ter outro backend.
// ---------------------------------------------------------------------------
#pragma once

#include <cstddef>
#include <cstdint>

namespace gh3::platform {

struct Config {
    const char* title      = "Guitar Hero III";
    const char* data_dir   = "ux0:data/gh3";  // raiz dos assets no Vita
    int         width      = 960;
    int         height     = 544;
    int         audio_rate = 44100;
    int         audio_frames = 1024;          // amostras por bloco (~23 ms)
};

// Cria o diretorio de dados, sobe SDL2, vitaGL e o dispositivo de audio.
bool init(const Config& cfg);
void shutdown();

// Processa eventos (SDL_QUIT, combo de saida). false = encerrar.
bool pump_events();

// Delimita um frame. end_frame() faz o swap e espera o vsync.
void begin_frame();
void end_frame();

// Relogio monotonico em segundos (equivalente a sceKernelGetSystemTimeLow).
double   now_seconds();
uint64_t frame_index();

void log(const char* fmt, ...) __attribute__((format(printf, 1, 2)));

// Endereco de carga do modulo (eboot) em tempo de execucao, 0 se a plataforma
// nao souber informar. O eboot e' realocado no load, entao enderecos de retorno
// so viram offset estavel dentro do ELF depois de descontar esta base.
uintptr_t module_base();

// --- Entrada ---------------------------------------------------------------
// Layout de bits identico ao SceCtrlData do PS2 (libpad2). No Vita os bits
// SCE_CTRL_* tem exatamente os mesmos valores, entao a conversao e' uma copia
// dos 16 bits baixos.
namespace ps2pad {
enum : uint16_t {
    Select   = 0x0001, L3     = 0x0002, R3     = 0x0004, Start  = 0x0008,
    Up       = 0x0010, Right  = 0x0020, Down   = 0x0040, Left   = 0x0080,
    L2       = 0x0100, R2     = 0x0200, L1     = 0x0400, R1     = 0x0800,
    Triangle = 0x1000, Circle = 0x2000, Cross  = 0x4000, Square = 0x8000,
};
}  // namespace ps2pad

struct PadState {
    uint16_t buttons;      // ps2pad::*
    uint8_t  lx, ly;       // stick esquerdo, 0..255 (128 = centro)
    uint8_t  rx, ry;       // stick direito
    uint8_t  pressure[12]; // pressao por botao, se disponivel
};

PadState read_pad(int port = 0);
bool     pad_connected(int port = 0);

}  // namespace gh3::platform
