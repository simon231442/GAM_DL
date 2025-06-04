cmake_minimum_required(VERSION 3.16)
project(GAM_DL LANGUAGES C)

set(CMAKE_C_STANDARD 99)

# Fichiers sources
set(SOURCES
    src/main.c
    src/GAM_DL_Main.c
    src/GAM_DL_CoreWindowPop.c
    src/GAM_DL_TextureLoad.c
    src/GAM_DL_EventHandle.c
)

# Dossier des headers
include_directories(include)

# Détection automatique : WebAssembly ou Linux
if(EMSCRIPTEN)
    # === COMPILATION WEBASSEMBLY ===
    message(STATUS "Compilation pour WebAssembly")
    
    # Configuration SDL3 pour WebAssembly
    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -s USE_SDL=3")
    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} --preload-file sprite@sprite")
    
    # Créer l'exécutable WebAssembly
    add_executable(GAM_DL_wasm ${SOURCES})
    set_target_properties(GAM_DL_wasm PROPERTIES SUFFIX ".html")
    
else()
    # === COMPILATION LINUX ===
    message(STATUS "Compilation pour Linux")
    
    # Utiliser SDL3 inclus dans le projet
    add_subdirectory(lib/SDL3)
    
    # Créer l'exécutable Linux
    add_executable(GAM_DL_linux ${SOURCES})
    target_link_libraries(GAM_DL_linux SDL3::SDL3)
    
endif()

# Copier les assets (images, etc.)
file(COPY sprite DESTINATION ${CMAKE_BINARY_DIR})
