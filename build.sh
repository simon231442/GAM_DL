#!/bin/bash

# Couleurs pour les messages
GREEN='\033[0;32m'
BLUE='\033[0;34m'
RED='\033[0;31m'
NC='\033[0m' # No Color

# Fonction pour configurer Emscripten
setup_emscripten() {
    if [ -d "lib/emsdk" ]; then
        echo -e "${BLUE}🔧 Configuration Emscripten...${NC}"
        cd lib/emsdk
        source ./emsdk_env.sh
        cd ../..
    else
        echo -e "${RED}❌ Emscripten non trouvé dans lib/emsdk${NC}"
        echo "Installez avec: git submodule update --init --recursive"
        exit 1
    fi
}

build_linux() {
    echo -e "${BLUE}🐧 Compilation Linux...${NC}"
    
    # Configuration
    cmake -S . -B build-linux -DBUILD_WASM=OFF
    
    # Compilation
    cmake --build build-linux
    
    if [ $? -eq 0 ]; then
        echo -e "${GREEN}✅ Linux: build-linux/GAM_DL${NC}"
    else
        echo -e "${RED}❌ Erreur compilation Linux${NC}"
        exit 1
    fi
}

build_wasm() {
    echo -e "${BLUE}🌐 Compilation WebAssembly...${NC}"
    
    # Configuration Emscripten
    setup_emscripten
    
    # Vérifier emcc
    if ! command -v emcc &> /dev/null; then
        echo -e "${RED}❌ emcc non trouvé${NC}"
        exit 1
    fi
    
    # Configuration
    emcmake cmake -S . -B build-wasm -DBUILD_WASM=ON
    
    # Compilation
    cmake --build build-wasm
    
    if [ $? -eq 0 ]; then
        echo -e "${GREEN}✅ WebAssembly: build-wasm/GAM_DL.html${NC}"
        echo -e "${BLUE}🚀 Test: cd build-wasm && python3 -m http.server 8000${NC}"
    else
        echo -e "${RED}❌ Erreur compilation WebAssembly${NC}"
        exit 1
    fi
}

test_linux() {
    if [ -f "build-linux/GAM_DL" ]; then
        echo -e "${BLUE}🎮 Lancement Linux...${NC}"
        ./build-linux/GAM_DL
    else
        echo -e "${RED}❌ Exécutable Linux non trouvé${NC}"
        echo "Compilez avec: ./build.sh linux"
    fi
}

test_wasm() {
    if [ -f "build-wasm/GAM_DL.html" ]; then
        echo -e "${BLUE}🌐 Démarrage serveur WebAssembly...${NC}"
        cd build-wasm
        echo -e "${GREEN}Ouvrez: http://localhost:8000/GAM_DL.html${NC}"
        python3 -m http.server 8000
    else
        echo -e "${RED}❌ Fichier WebAssembly non trouvé${NC}"
        echo "Compilez avec: ./build.sh wasm"
    fi
}

clean() {
    echo -e "${BLUE}🧹 Nettoyage...${NC}"
    rm -rf build-linux build-wasm
    echo -e "${GREEN}✅ Nettoyage terminé${NC}"
}

# Menu principal
case "${1:-help}" in
    "linux")
        build_linux
        ;;
    "wasm")
        build_wasm
        ;;
    "all")
        build_linux
        build_wasm
        ;;
    "test-linux")
        test_linux
        ;;
    "test-wasm")
        test_wasm
        ;;
    "clean")
        clean
        ;;
    *)
        echo -e "${BLUE}GAM_DL Build System${NC}"
        echo ""
        echo "Usage: $0 [commande]"
        echo ""
        echo "Compilation:"
        echo "  linux      - Compile pour Linux"
        echo "  wasm       - Compile pour WebAssembly"
        echo "  all        - Compile les deux"
        echo ""
        echo "Test:"
        echo "  test-linux - Lance l'exécutable Linux"
        echo "  test-wasm  - Lance le serveur WebAssembly"
        echo ""
        echo "Maintenance:"
        echo "  clean      - Nettoie les builds"
        echo ""
        ;;
esac