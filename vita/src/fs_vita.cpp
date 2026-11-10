// ---------------------------------------------------------------------------
// VFS do port: caminhos do jogo -> ux0:data/gh3.
//
// O jogo no PS2 usa caminhos com prefixo de dispositivo ("cdrom0:\\...",
// "mc0:...") e separador '\\'. No Vita tudo vive em ux0:data/gh3 e o
// separador e' '/'. A normalizacao fica aqui, uma unica vez, em vez de espalhar
// #ifdef pelo codigo decompilado.
// ---------------------------------------------------------------------------
#include "gh3/fs.h"

#include <cstring>
#include <new>

namespace gh3::fs {
namespace {

char g_root[512] = "ux0:data/gh3";

bool has_prefix(const char* s, const char* p) {
    return std::strncmp(s, p, std::strlen(p)) == 0;
}

}  // namespace

bool init(const char* data_dir) {
    if (!data_dir || !*data_dir) {
        return false;
    }
    std::snprintf(g_root, sizeof(g_root), "%s", data_dir);
    return true;
}

const char* root() { return g_root; }

bool resolve(const char* game_path, char* out, std::size_t out_size) {
    if (!game_path || !out || out_size == 0) {
        return false;
    }

    const char* p = game_path;

    // Prefixos de dispositivo do PS2/PSP. "cdrom0:" e' o DVD do jogo.
    static const char* const kPrefixes[] = {
        "cdrom0:", "cdrom:", "host0:", "mass:", "mc0:", "ms0:", "disc0:",
    };
    for (const char* prefix : kPrefixes) {
        if (has_prefix(p, prefix)) {
            p += std::strlen(prefix);
            break;
        }
    }

    // Letra de unidade do Windows ("D:\\...").
    if (p[0] && p[1] == ':') {
        p += 2;
    }

    while (*p == '/' || *p == '\\') {
        ++p;
    }

    // Copia normalizando separador e colapsando '//'.
    char rel[512];
    std::size_t n = 0;
    bool last_slash = false;
    for (; *p && n + 1 < sizeof(rel); ++p) {
        char c = (*p == '\\') ? '/' : *p;
        if (c == '/') {
            if (last_slash) {
                continue;
            }
            last_slash = true;
        } else {
            last_slash = false;
        }
        rel[n++] = c;
    }
    rel[n] = '\0';

    // Recusa traversal: ".." nunca deve sair de ux0:data/gh3.
    if (std::strstr(rel, "..") != nullptr) {
        return false;
    }

    const int written = std::snprintf(out, out_size, "%s/%s", g_root, rel);
    return written > 0 && static_cast<std::size_t>(written) < out_size;
}

std::FILE* open(const char* game_path, const char* mode) {
    char path[1024];
    if (!resolve(game_path, path, sizeof(path))) {
        return nullptr;
    }
    return std::fopen(path, mode);
}

bool exists(const char* game_path) {
    char path[1024];
    if (!resolve(game_path, path, sizeof(path))) {
        return false;
    }
    std::FILE* f = std::fopen(path, "rb");
    if (!f) {
        return false;
    }
    std::fclose(f);
    return true;
}

std::size_t size(const char* game_path) {
    char path[1024];
    if (!resolve(game_path, path, sizeof(path))) {
        return 0;
    }
    std::FILE* f = std::fopen(path, "rb");
    if (!f) {
        return 0;
    }
    std::fseek(f, 0, SEEK_END);
    const long end = std::ftell(f);
    std::fclose(f);
    return end > 0 ? static_cast<std::size_t>(end) : 0;
}

std::uint8_t* read_all(const char* game_path, std::size_t* out_size) {
    if (out_size) {
        *out_size = 0;
    }

    char path[1024];
    if (!resolve(game_path, path, sizeof(path))) {
        return nullptr;
    }

    std::FILE* f = std::fopen(path, "rb");
    if (!f) {
        return nullptr;
    }

    std::fseek(f, 0, SEEK_END);
    const long end = std::ftell(f);
    std::fseek(f, 0, SEEK_SET);
    if (end <= 0) {
        std::fclose(f);
        return nullptr;
    }

    auto* buf = new (std::nothrow) std::uint8_t[static_cast<std::size_t>(end)];
    if (!buf) {
        std::fclose(f);
        return nullptr;
    }

    const std::size_t got = std::fread(buf, 1, static_cast<std::size_t>(end), f);
    std::fclose(f);

    if (got != static_cast<std::size_t>(end)) {
        delete[] buf;
        return nullptr;
    }

    if (out_size) {
        *out_size = got;
    }
    return buf;
}

}  // namespace gh3::fs
