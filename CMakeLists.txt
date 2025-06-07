cmake_minimum_required(VERSION 3.16)
project(GAM_DL LANGUAGES C)

set(CMAKE_C_STANDARD 99)

# Option pour choisir la plateforme
option(BUILD_WASM "Build for WebAssembly" OFF)

# Fichiers sources
set(SOURCES
    src/main.c
    src/GAM_DL_MainComplet.c
    src/GAM_DL_CoreWindowPop.c
    src/GAM_DL_TextureLoad.c
    src/GAM_DL_EventHandle.c
    src/GAM_DL_CoreLoadWorld.c
)

# Headers
include_directories(include)

if(BUILD_WASM)
    # === WEBASSEMBLY ===
    message(STATUS "🌐 Configuration WebAssembly")
    
    # Flags Emscripten
    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -s USE_SDL=3")
    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -s WASM=1")
    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} --preload-file sprite@sprite")
    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -s ALLOW_MEMORY_GROWTH=1")
    
    # Exécutable WebAssembly
    add_executable(GAM_DL ${SOURCES})
    set_target_properties(GAM_DL PROPERTIES SUFFIX ".html")
    
else()
    # === LINUX ===
    message(STATUS "🐧 Configuration Linux")
    
    # SDL3 pour Linux
    add_subdirectory(lib/SDL3)
    
    # Exécutable Linux
    add_executable(GAM_DL ${SOURCES})
    target_link_libraries(GAM_DL SDL3::SDL3)
    
endif()

# Copier les sprites
file(COPY sprite DESTINATION ${CMAKE_BINARY_DIR})