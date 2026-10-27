#!/usr/bin/env bash
# Build and install SFML 2.5.1 + CSFML 2.5 into /usr/local (no apt upgrade).
set -euo pipefail

BUILD_DIR="$(mktemp -d)"
trap 'rm -rf "$BUILD_DIR"' EXIT

# Build dependencies only (no upgrade of existing packages)
sudo apt-get install -y --no-upgrade \
    cmake g++ make \
    libx11-dev libxrandr-dev libxcursor-dev libudev-dev libgl-dev \
    libfreetype-dev libopenal-dev libflac-dev libogg-dev libvorbis-dev

cd "$BUILD_DIR"
git clone --depth 1 --branch 2.5.1 https://github.com/SFML/SFML.git
git clone --depth 1 --branch 2.5   https://github.com/SFML/CSFML.git

cmake -S SFML -B SFML/build -DCMAKE_BUILD_TYPE=Release -DCMAKE_INSTALL_PREFIX=/usr/local
cmake --build SFML/build -j"$(nproc)"
sudo cmake --install SFML/build

cmake -S CSFML -B CSFML/build -DCMAKE_BUILD_TYPE=Release -DCMAKE_INSTALL_PREFIX=/usr/local \
    -DSFML_DIR=/usr/local/lib/cmake/SFML
cmake --build CSFML/build -j"$(nproc)"
sudo cmake --install CSFML/build

sudo ldconfig
echo "Installed:"
ls /usr/local/lib | grep -E "^lib(c)?sfml-.*\.so\.2\.5"
