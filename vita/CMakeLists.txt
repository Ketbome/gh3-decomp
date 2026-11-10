# ---------------------------------------------------------------------------
# Alvo Vita: camada de plataforma + empacotamento .self/.vpk.
# ---------------------------------------------------------------------------

set(GH3_VITA_TITLEID "GHVI00001" CACHE STRING "Title ID do VPK")
set(GH3_VITA_VERSION "01.00"     CACHE STRING "Versao do VPK")
set(GH3_VITA_NAME    "Guitar Hero III" CACHE STRING "Nome exibido no LiveArea")

# --- Dependencias -----------------------------------------------------------
# O VitaSDK instala tudo em $VITASDK/arm-vita-eabi (headers em include/, libs em
# lib/); SDL2 e vitaGL vem de `vdpm SDL2` / `vdpm vitaGL`. Nao usamos
# pkg-config: em cross-compile o .pc do host se mistura com o do alvo e o
# resultado depende do ambiente. O layout do VitaSDK e' fixo, entao
# find_path/find_library com HINTS e' deterministico.
set(GH3_VITASDK_PREFIX "$ENV{VITASDK}/arm-vita-eabi")

find_path(GH3_SDL2_INCLUDE_DIR SDL.h
    HINTS "${GH3_VITASDK_PREFIX}/include"
    PATH_SUFFIXES SDL2)
find_library(GH3_SDL2_LIBRARY NAMES SDL2
    HINTS "${GH3_VITASDK_PREFIX}/lib")
if(NOT GH3_SDL2_LIBRARY OR NOT GH3_SDL2_INCLUDE_DIR)
    message(FATAL_ERROR
        "SDL2 nao encontrado em ${GH3_VITASDK_PREFIX}. Instale com: vdpm SDL2")
endif()

find_library(GH3_VITAGL_LIBRARY NAMES vitaGL
    HINTS "${GH3_VITASDK_PREFIX}/lib")
if(NOT GH3_VITAGL_LIBRARY)
    message(FATAL_ERROR
        "vitaGL nao encontrado em ${GH3_VITASDK_PREFIX}. Instale com: vdpm vitaGL")
endif()

set(GH3_SDL2_LIBS     ${GH3_SDL2_LIBRARY})
set(GH3_SDL2_INCLUDES ${GH3_SDL2_INCLUDE_DIR})
set(GH3_VITAGL_LIBS   ${GH3_VITAGL_LIBRARY})

# --- Fontes -----------------------------------------------------------------
set(GH3_VITA_SOURCES
    src/main.cpp
    src/platform_vita.cpp
    src/fs_vita.cpp
    src/ps2hle.cpp
    src/engine_stub.cpp
)

add_executable(gh3_vita ${GH3_VITA_SOURCES})

target_include_directories(gh3_vita PRIVATE
    "${CMAKE_CURRENT_SOURCE_DIR}/include"
    ${GH3_SDL2_INCLUDES}
)

target_compile_definitions(gh3_vita PRIVATE GH3_VITA=1)

target_compile_options(gh3_vita PRIVATE
    -Wall -Wextra -Wno-unused-parameter
    -ffunction-sections -fdata-sections
)

target_link_options(gh3_vita PRIVATE -Wl,--gc-sections)

target_link_libraries(gh3_vita PRIVATE
    ${GH3_SDL2_LIBS}
    ${GH3_VITAGL_LIBS}
    # Dependencias estaticas do vitaGL. libvitaGL.a referencia estes simbolos
    # sem arrasta-los junto, entao precisam vir DEPOIS dela na linha de link.
    #   vitashark + SceShaccCgExt + SceShaccCg_stub : tradutor GLSL (shark_*)
    #   taihen_stub                                 : taiHookRelease/taiInject*
    #                                                 (SceShaccCgExt e' um
    #                                                 plugin taiHEN)
    #   mathneon                                    : matmul4_neon
    #   SceCommonDialog_stub                        : sceCommonDialogUpdate
    #   SceAppMgr_stub                              : sceAppMgrGetBudgetInfo
    #   SceKernelDmacMgr_stub                       : sceDmacMemcpy
    vitashark
    SceShaccCgExt
    SceShaccCg_stub
    taihen_stub
    mathneon
    SceCommonDialog_stub
    SceAppMgr_stub
    SceKernelDmacMgr_stub
    # Stubs do sysmodule usados por vitaGL/SDL2. Se o .pc do pkg-config ja os
    # trouxe, repetir aqui e' inofensivo (o linker so resolve uma vez).
    SceGxm_stub
    SceCtrl_stub
    SceDisplay_stub
    SceAudio_stub
    SceAudioIn_stub
    SceHid_stub
    SceTouch_stub
    SceMotion_stub
    SceIofilemgr_stub
    SceProcessmgr_stub
    SceSysmodule_stub
    ScePower_stub
    # sceKernelGetModuleList/GetModuleInfo: base do eboot para o relatorio de
    # alcance dos stubs (gh3::platform::module_base).
    SceKernelModulemgr_stub
    m
)

# --- Empacotamento ----------------------------------------------------------
include("$ENV{VITASDK}/share/vita.cmake" OPTIONAL)

if(COMMAND vita_create_self)
    vita_create_self(gh3_vita.self gh3_vita)

    # Icone opcional: se existir vita/sce_sys/icon0.png, entra no VPK.
    set(GH3_VPK_EXTRA "")
    if(EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/sce_sys/icon0.png")
        list(APPEND GH3_VPK_EXTRA
            FILE "${CMAKE_CURRENT_SOURCE_DIR}/sce_sys/icon0.png" sce_sys/icon0.png)
    endif()

    vita_create_vpk(gh3_vita.vpk ${GH3_VITA_TITLEID} gh3_vita.self
        VERSION "${GH3_VITA_VERSION}"
        NAME    "${GH3_VITA_NAME}"
        ${GH3_VPK_EXTRA}
    )
else()
    message(WARNING "vita.cmake nao encontrado: .self/.vpk nao serao gerados.")
endif()

# --- Build experimental da engine -------------------------------------------
# OFF por padrao: a arvore decompilada ainda tem 2.852 funcoes em assembly MIPS
# (INCLUDE_ASM) e globais em enderecos absolutos. Ligue quando quiser medir
# quanto do src/game ja compila em ARM:
#
#   cmake -S . -B build -DGH3_BUILD_ENGINE=ON
#
# gen_stubs.py roda no configure, detecta os arquivos que o gcc do ARM recusa
# (asm MIPS inline e mode(TI)) e os exclui do build. As funcoes desses
# arquivos, mais as INCLUDE_ASM, viram stubs fracos.
option(GH3_BUILD_ENGINE "Compilar src/game (gh3-decomp) no alvo Vita" OFF)

if(GH3_BUILD_ENGINE)
    find_package(Python3 COMPONENTS Interpreter REQUIRED)

    set(GH3_GEN_DIR "${CMAKE_BINARY_DIR}/generated")
    file(MAKE_DIRECTORY "${GH3_GEN_DIR}")

    # Roda no configure, nao no build: a lista de fontes e a lista de stubs sao
    # entradas do grafo do CMake (add_library depende delas). Um
    # add_custom_command so geraria os arquivos depois que o alvo ja foi
    # configurado. Reconfigure (cmake -S . -B build) apos mexer em
    # config/functions.txt ou em tools/gen_stubs.py.
    execute_process(
        COMMAND "${Python3_EXECUTABLE}"
                "${CMAKE_CURRENT_SOURCE_DIR}/tools/gen_stubs.py"
                --repo "${GH3_DECOMP_DIR}"
                --out  "${GH3_GEN_DIR}"
        RESULT_VARIABLE GH3_GEN_RESULT
        OUTPUT_VARIABLE GH3_GEN_OUTPUT
        ERROR_VARIABLE  GH3_GEN_ERROR
        WORKING_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}")

    if(NOT GH3_GEN_RESULT EQUAL 0)
        message(FATAL_ERROR
            "gen_stubs.py falhou (${GH3_GEN_RESULT}):\n"
            "${GH3_GEN_OUTPUT}\n${GH3_GEN_ERROR}")
    endif()
    message(STATUS "gen_stubs:\n${GH3_GEN_OUTPUT}")

    include("${GH3_GEN_DIR}/engine_sources.cmake")

    list(LENGTH GH3_ENGINE_SOURCES GH3_ENGINE_COUNT)
    list(LENGTH GH3_ENGINE_EXCLUDED GH3_ENGINE_EXCLUDED_COUNT)

    if(GH3_ENGINE_COUNT EQUAL 0)
        message(FATAL_ERROR
            "GH3_ENGINE_SOURCES vazio: gen_stubs.py nao encontrou fontes em "
            "${GH3_DECOMP_DIR}/src/game")
    endif()

    message(STATUS
        "engine: ${GH3_ENGINE_COUNT} arquivo(s) compilavel(is), "
        "${GH3_ENGINE_EXCLUDED_COUNT} excluido(s) (ver "
        "${GH3_GEN_DIR}/port_blockers.txt)")

    add_library(gh3_engine STATIC ${GH3_ENGINE_SOURCES})

    # O decomp foi escrito para o ee-gcc em modo GNU; extensoes (statement
    # expressions, typeof, asm no escopo de arquivo) podem aparecer.
    set_property(TARGET gh3_engine PROPERTY CXX_EXTENSIONS ON)
    set_property(TARGET gh3_engine PROPERTY C_EXTENSIONS ON)
    target_include_directories(gh3_engine PRIVATE
        "${GH3_DECOMP_DIR}/include"
        "${CMAKE_CURRENT_SOURCE_DIR}/include"
    )
    # O prelude precisa vir antes de include/common.h em cada TU.
    # -ffunction-sections: cada funcao em sua secao, para o --gc-sections do
    # executavel descartar o que o port nao chama.
    #
    # -fno-strict-aliasing: o decomp faz type punning o tempo todo
    # (`*(int*)((char*)self + off)`). O ee-gcc 2.95 nem tinha strict aliasing;
    # o GCC atual tem, em -O2, e miscompilaria esse padrao.
    # -fwrapv: o codigo conta com overflow de signed (RNG em func_0010C050).
    # -fpermissive: o decomp passa ponteiro de funcao onde o parametro e'
    # void* (`func_001D4600_r(h, key, func_X, func_Y)`), o que o ee-gcc 2.95
    # aceitava e o C++ moderno trata como erro. Vira warning (silenciado por
    # -w); nao muda a ABI.
    target_compile_options(gh3_engine PRIVATE
        -include "${CMAKE_CURRENT_SOURCE_DIR}/include/gh3/port_prelude.h"
        -w
        -fpermissive
        -ffunction-sections
        -fdata-sections
        -fno-strict-aliasing
        -fwrapv
        $<$<COMPILE_LANGUAGE:CXX>:-fno-exceptions>
        $<$<COMPILE_LANGUAGE:CXX>:-fno-rtti>
    )
    target_compile_definitions(gh3_engine PRIVATE GH3_PORT=1)

    # Biblioteca separada e linkada DEPOIS da engine: assim os simbolos fortes
    # da engine sao resolvidos primeiro e os stubs fracos so preenchem lacunas.
    add_library(gh3_engine_stubs STATIC
        "${GH3_GEN_DIR}/stubs_asm.cpp"
        "${GH3_GEN_DIR}/data_arena.cpp")
    target_include_directories(gh3_engine_stubs PRIVATE
        "${CMAKE_CURRENT_SOURCE_DIR}/include")
    target_compile_options(gh3_engine_stubs PRIVATE
        -w -ffunction-sections -fdata-sections)

    # engine_vita.cpp define as versoes fortes de port::* e chama a entrada do
    # jogo (func_0010C000). So pode entrar no build junto com a arena gerada,
    # e e' o que faz o linker puxar gh3_engine para o binario.
    target_sources(gh3_vita PRIVATE src/engine_vita.cpp)

    target_link_libraries(gh3_vita PRIVATE gh3_engine gh3_engine_stubs)
endif()
