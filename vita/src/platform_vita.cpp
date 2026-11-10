// ---------------------------------------------------------------------------
// Backend Vita de gh3::platform.
//
// Responsabilidades:
//   - video : vitaGL (GXM) direto no framebuffer 960x544
//   - audio : SDL2 (sceAudio por baixo), 44.1 kHz estereo S16
//   - input : SceCtrl, publicado no layout de bits da libpad2 do PS2
//   - tempo : relogio monotonico de alta resolucao
//   - log   : stderr + ux0:data/gh3/log.txt (o bring-up depende disso)
//
// Nao criamos janela SDL de proposito: no Vita o driver de video do SDL2 e o
// vitaGL disputam o GXM (contexto + framebuffers). Como o jogo fala OpenGL
// direto, quem manda no video e' o vitaGL; o SDL2 fica so com audio, timer e
// eventos. Nada aqui conhece a engine.
// ---------------------------------------------------------------------------
#include <cstdarg>
#include <cstdio>
#include <cstring>

#include <SDL.h>
#include <vitaGL.h>
// vitaGL declara a API GL; algumas instalacoes tambem trazem GL/gl.h. Incluir
// so quando existir evita quebrar o build em versoes diferentes do pacote.
#if defined(__has_include)
#  if __has_include(<GL/gl.h>)
#    include <GL/gl.h>
#  endif
#endif

#include <psp2/ctrl.h>
#include <psp2/gxm.h>
#include <psp2/io/fcntl.h>
#include <psp2/io/stat.h>   // sceIoMkdir
#include <psp2/kernel/modulemgr.h>

#include "gh3/platform.h"
#include "gh3/port.h"

namespace gh3::platform {
namespace {

SDL_AudioDeviceID g_audio = 0;
Config            g_cfg;
uint64_t          g_frame = 0;
Uint64            g_t0    = 0;
Uint64            g_freq  = 1;
std::FILE*        g_log   = nullptr;

// Combo de saida: START+SELECT segurados por 1 s. Sem isso o usuario fica
// preso no app (o Vita nao tem Alt+F4).
uint32_t g_exit_hold_ms = 0;

void sdl_audio_callback(void* /*userdata*/, Uint8* stream, int len) {
    // len em bytes; 2 canais * 2 bytes por amostra = 4.
    const int frames = len / 4;
    gh3::port::audio_render(reinterpret_cast<int16_t*>(stream), frames);
}

void init_dirs(const char* data_dir) {
    // sceIoMkdir devolve 0, ou um codigo negativo se o diretorio ja existe.
    // Nos dois casos seguimos em frente; a falha real aparece no fopen.
    sceIoMkdir("ux0:data", 0777);
    sceIoMkdir(data_dir, 0777);

    char buf[256];
    std::snprintf(buf, sizeof(buf), "%s/data", data_dir);
    sceIoMkdir(buf, 0777);
    std::snprintf(buf, sizeof(buf), "%s/saves", data_dir);
    sceIoMkdir(buf, 0777);
}

void init_log(const char* data_dir) {
    char path[256];
    std::snprintf(path, sizeof(path), "%s/log.txt", data_dir);
    g_log = std::fopen(path, "a");
}

bool init_video() {
    // 16 MB de pool de vertices/indices + 2 MB extra. Ajustar depois de medir a
    // cena mais pesada (o PS2 tinha 4 MB de RAM de video).
    vglInitExtended(0x1000000, g_cfg.width, g_cfg.height,
                    0x200000, SCE_GXM_MULTISAMPLE_NONE);
    // `vglUseVram` existia ate a r1470 e foi removida: hoje o vitaGL decide
    // sozinho onde alocar cada recurso (CDRAM para texturas, RAM para o resto),
    // a partir dos pools passados para vglInit*. Nao ha substituto 1:1 —
    // `vglUseExtraMem` e' outra coisa (fallback para a heap do newlib) e
    // `vglUseVramForUSSE` mexe so nos buffers internos do USSE.
    vglUseExtraMem(GL_TRUE);

    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LEQUAL);
    return true;
}

bool init_audio() {
    if (SDL_InitSubSystem(SDL_INIT_AUDIO) != 0) {
        log("SDL audio indisponivel: %s", SDL_GetError());
        return false;
    }

    SDL_AudioSpec want;
    SDL_zero(want);
    want.freq     = g_cfg.audio_rate;
    want.format   = AUDIO_S16SYS;
    want.channels = 2;
    want.samples  = static_cast<Uint16>(g_cfg.audio_frames);
    want.callback = sdl_audio_callback;

    g_audio = SDL_OpenAudioDevice(nullptr, 0, &want, nullptr, 0);
    if (g_audio == 0) {
        log("SDL_OpenAudioDevice falhou: %s", SDL_GetError());
        return false;
    }

    SDL_PauseAudioDevice(g_audio, 0);
    return true;
}

}  // namespace

bool init(const Config& cfg) {
    g_cfg = cfg;

    // Antes de qualquer log, para o timestamp sair coerente.
    g_freq = SDL_GetPerformanceFrequency();
    g_t0   = SDL_GetPerformanceCounter();
    if (g_freq == 0) {
        g_freq = 1;
    }

    init_dirs(cfg.data_dir);
    init_log(cfg.data_dir);

    if (SDL_Init(SDL_INIT_TIMER | SDL_INIT_GAMECONTROLLER) != 0) {
        log("SDL_Init falhou: %s", SDL_GetError());
        return false;
    }

    if (!init_video()) {
        return false;
    }

    // O audio nao e' critico para o bring-up: a engine sobe sem ele.
    if (!init_audio()) {
        log("seguindo sem audio");
    }

    sceCtrlSetSamplingMode(SCE_CTRL_MODE_ANALOG_WIDE);

    log("plataforma pronta: %dx%d, dados em %s", cfg.width, cfg.height,
        cfg.data_dir);
    return true;
}

void shutdown() {
    if (g_audio) {
        SDL_CloseAudioDevice(g_audio);
        g_audio = 0;
    }
    SDL_Quit();
    // vitaGL nao tem teardown publico; o processo termina em seguida.
    if (g_log) {
        std::fclose(g_log);
        g_log = nullptr;
    }
}

bool pump_events() {
    SDL_Event ev;
    while (SDL_PollEvent(&ev)) {
        if (ev.type == SDL_QUIT) {
            return false;
        }
    }

    // Combo de saida.
    const PadState pad = read_pad(0);
    const uint16_t combo = ps2pad::Start | ps2pad::Select;
    if ((pad.buttons & combo) == combo) {
        g_exit_hold_ms += 16;
        if (g_exit_hold_ms >= 1000) {
            return false;
        }
    } else {
        g_exit_hold_ms = 0;
    }

    return true;
}

void begin_frame() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void end_frame() {
    // GL_TRUE espera o vsync do display (60 Hz). E' o "flip" da libgraph.
    vglSwapBuffers(GL_TRUE);
    ++g_frame;
}

double now_seconds() {
    return static_cast<double>(SDL_GetPerformanceCounter() - g_t0) /
           static_cast<double>(g_freq);
}

uint64_t frame_index() { return g_frame; }

uintptr_t module_base() {
    // O eboot nao expoe a propria base: procuramos, na lista de modulos do
    // processo, aquele cujos segmentos contem o endereco desta funcao. A base
    // reportada e' o inicio do primeiro segmento (o .text), que e' o que o
    // loader soma aos VAs do ELF.
    static uintptr_t cached = 0;
    static bool      tried  = false;
    if (tried) {
        return cached;
    }
    tried = true;

    const uintptr_t self = reinterpret_cast<uintptr_t>(&module_base);

    SceUID  ids[64];
    SceSize num = 64;
    // type: bit 0 = modulos de usuario, 0x80 = sistema (ver samples/prx_loader).
    if (sceKernelGetModuleList(0x1, ids, &num) < 0) {
        return 0;
    }

    for (SceSize i = 0; i < num; ++i) {
        SceKernelModuleInfo info;
        std::memset(&info, 0, sizeof(info));
        info.size = sizeof(info);
        if (sceKernelGetModuleInfo(ids[i], &info) < 0) {
            continue;
        }
        for (int s = 0; s < 4; ++s) {
            const uintptr_t start =
                reinterpret_cast<uintptr_t>(info.segments[s].vaddr);
            const uintptr_t size = info.segments[s].memsz;
            if (size == 0 || self < start || self >= start + size) {
                continue;
            }
            cached = reinterpret_cast<uintptr_t>(info.segments[0].vaddr);
            return cached;
        }
    }
    return 0;
}

void log(const char* fmt, ...) {
    char buf[1024];
    va_list ap;
    va_start(ap, fmt);
    std::vsnprintf(buf, sizeof(buf), fmt, ap);
    va_end(ap);

    std::fprintf(stderr, "[gh3] %s\n", buf);
    std::fflush(stderr);

    if (g_log) {
        std::fprintf(g_log, "[%8.3f] %s\n", now_seconds(), buf);
        std::fflush(g_log);
    }
}

PadState read_pad(int port) {
    PadState out;
    std::memset(&out, 0, sizeof(out));
    out.lx = out.ly = out.rx = out.ry = 128;

    SceCtrlData d;
    std::memset(&d, 0, sizeof(d));
    if (sceCtrlPeekBufferPositive(port, &d, 1) < 0) {
        return out;
    }

    // No Vita os bits SCE_CTRL_* coincidem com os da libpad2 do PS2.
    out.buttons = static_cast<uint16_t>(d.buttons & 0xFFFF);
    out.lx = d.lx;
    out.ly = d.ly;
    out.rx = d.rx;
    out.ry = d.ry;
    return out;
}

bool pad_connected(int port) {
    SceCtrlData d;
    std::memset(&d, 0, sizeof(d));
    return sceCtrlPeekBufferPositive(port, &d, 1) >= 0;
}

}  // namespace gh3::platform
