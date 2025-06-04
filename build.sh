#!/bin/bash

# Script simple pour compiler GAM_DL

# Fonctions de base
build_linux() {
    echo "Compilation Linux..."
    mkdir -p build-linux
    cd build-linux
    cmake -DBUILD_WASM=OFF ..
    make
    echo "✓ Terminé: build-linux/GAM_DL_linux"
    cd ..
}

build_wasm() {
    echo "Compilation WebAssembly..."
    if ! command -v emcc &> /dev/null; then
        echo "Erreur: Emscripten non trouvé"
        echo "Installez avec: git clone https://github.com/emscripten-core/emsdk.git"
        exit 1
    fi
    
    mkdir -p build-wasm
    cd build-wasm
    emcmake cmake -DBUILD_WASM=ON ..
    make
    echo "✓ Terminé: build-wasm/GAM_DL_wasm.html"
    echo "Pour tester: python3 -m http.server 8000"
    cd ..
}

clean() {
    echo "Nettoyage..."
    rm -rf build-linux build-wasm
    echo "✓ Terminé"
}

# Menu simple
case "${1:-help}" in
    "linux")  build_linux ;;
    "wasm")   build_wasm ;;
    "all")    build_linux && build_wasm ;;
    "clean")  clean ;;
    *)
        echo "Usage: $0 [linux|wasm|all|clean]"
        echo "  linux  - Compile pour Linux"
        echo "  wasm   - Compile pour WebAssembly"
        echo "  all    - Compile les deux"
        echo "  clean  - Nettoie les builds"
        ;;
esac
