// ---------------------------------------------------------------------------
// main do port.
//
// Este e' o unico ponto de entrada do binario Vita. O laco abaixo NAO e' o
// laco original do jogo (esse vive em .text, ver docs/text_map.md); ele e' o
// laco de plataforma, que delega a engine em gh3::port::frame().
//
// Ordem de inicializacao (mesma do crt0 do PS2 -> main):
//   1. fs      : ux0:data/gh3 existe e e' a raiz dos assets
//   2. hle     : servicos que substituem libpad2/libcdvd/libgraph/sifrpc
//   3. port    : init da engine (carrega .pak, sobe threads internas)
//   4. loop    : pump -> begin_frame -> vblank -> frame -> end_frame
// ---------------------------------------------------------------------------
#include <cstdio>

#include "gh3/fs.h"
#include "gh3/platform.h"
#include "gh3/port.h"
#include "gh3/ps2hle.h"

int main(int argc, char** argv) {
    (void)argc;
    (void)argv;

    gh3::platform::Config cfg;
    cfg.title    = "Guitar Hero III";
    // cfg.data_dir usa o default de platform.h: "ux0:data/gh3".

    if (!gh3::platform::init(cfg)) {
        gh3::platform::log("falha ao inicializar a plataforma");
        return 1;
    }

    if (!gh3::fs::init(cfg.data_dir)) {
        gh3::platform::log("falha ao preparar %s", cfg.data_dir);
        gh3::platform::shutdown();
        return 1;
    }

    gh3::hle::init();

    if (!gh3::port::init()) {
        gh3::platform::log("engine nao inicializou (assets ausentes em %s?)",
                           cfg.data_dir);
        gh3::hle::shutdown();
        gh3::platform::shutdown();
        return 1;
    }

    while (gh3::platform::pump_events()) {
        gh3::platform::begin_frame();

        // O vblank do PS2 e' a fronteira de frame: a libgraph troca o buffer e
        // a libpad2 publica o estado novo. Mantemos a mesma ordem.
        gh3::hle::vblank();

        gh3::port::frame();

        gh3::platform::end_frame();
    }

    gh3::port::shutdown();
    gh3::hle::shutdown();
    gh3::platform::shutdown();

    return 0;
}
