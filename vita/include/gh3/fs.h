// ---------------------------------------------------------------------------
// gh3::fs — VFS do port.
//
// A engine do PS2 abre arquivos por caminhos do tipo "cdrom0:\\DATA\\X.PAK" ou
// pelo gerenciador de PAK proprio (CrcFromPathLowercase/HashTable_*). No Vita
// esses caminhos precisam virar "ux0:data/gh3/...". Esta camada normaliza o
// caminho e concentra o acesso, para que o resto do port nunca use paths
// absolutos de plataforma.
// ---------------------------------------------------------------------------
#pragma once

#include <cstddef>
#include <cstdint>
#include <cstdio>

namespace gh3::fs {

// Cria data_dir e subdiretorios (data/, saves/) se nao existirem.
bool init(const char* data_dir);

const char* root();

// Converte um caminho do jogo ("cdrom0:\\DATA\\A.PAK", "D:/x", "/x") em um
// caminho dentro de root(). Retorna false se o caminho escapar da raiz.
bool resolve(const char* game_path, char* out, std::size_t out_size);

// fopen() sobre resolve(). `mode` usa a semantica de stdio.
std::FILE* open(const char* game_path, const char* mode);
bool       exists(const char* game_path);
std::size_t size(const char* game_path);

// Le o arquivo inteiro para um buffer alocado com new[]. Retorna nullptr em
// erro; o chamador libera com delete[].
std::uint8_t* read_all(const char* game_path, std::size_t* out_size);

}  // namespace gh3::fs
