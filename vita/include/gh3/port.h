// ---------------------------------------------------------------------------
// gh3::port — contrato entre o laco de plataforma e a engine.
//
// main.cpp chama init() -> frame()* -> shutdown(). Quando a engine portada
// existir, ela define versoes fortes destas funcoes e o engine_stub.cpp (fraco)
// e' descartado pelo linker. Ate la, o binario roda com o stub.
// ---------------------------------------------------------------------------
#pragma once

#include <cstdint>

namespace gh3::port {

// Equivalente ao main() da engine: init de subsistemas, carga do .pak, etc.
// Retorna false se um asset essencial faltar.
bool init();

// Uma iteracao do laco do jogo (update + render). Nao faz swap.
void frame();

void shutdown();

// Chamado pela thread de audio do SDL. Deve preencher `frames` blocos
// estereo intercalados (int16). Se a engine ainda nao tem mixer, silencio.
void audio_render(int16_t* interleaved_stereo, int frames);

}  // namespace gh3::port
