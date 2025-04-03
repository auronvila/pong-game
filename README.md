# 🏓 Pong Game – C++ SFML 3 + CMake

This is a simple, modular Pong game written in modern **C++** using **SFML 3** and built using **CMake**.

It features:
- A structured game loop with multiple game states (`START_MENU`, `PLAYING`, `PAUSED`, `GAME_OVER`)
- A main menu system
- AI-controlled paddle opponent
- Scoreboard and increasing game speed over time
- Clean separation of concerns and object-oriented architecture

---

## ✅ Requirements

- [CMake](https://cmake.org/download/) `>= 3.28`
- [SFML 3](https://www.sfml-dev.org/) (see install instructions below)
- A C++17-capable compiler (GCC, Clang, MSVC, etc.)

---

## Mac Installing SFML 3 on macOS (via Homebrew)

```bash
brew install sfml
```

## Linux

```bash
sudo apt install libxrandr-dev libxcursor-dev libxi-dev libudev-dev \
libfreetype-dev libflac-dev libvorbis-dev libgl1-mesa-dev libegl1-mesa-dev
```

## Windows
Install vcpkg
```bash
git clone https://github.com/microsoft/vcpkg.git
cd vcpkg
# sets up vcpkg.exe
.\bootstrap-vcpkg.bat
```

Install SFML 3
```bash
.\vcpkg.exe install sfml
```

Integrate vcpkg with CMake
```bash
.\vcpkg.exe integrate install
```

Build your project with CMake + vcpkg
```bash
cmake -B build -DCMAKE_TOOLCHAIN_FILE=C:/path/to/vcpkg/scripts/buildsystems/vcpkg.cmake
cmake --build build
```


# Build Instructions (Command Line)
> ⚠️ **Warning:** The porject is tested in mac so if you are having trouble running or building the project in other operating systems please open an issue, I would be happy to help.

```bash
# Create build directory 
mkdir build && cd build

# Run CMake (macOS users with Homebrew SFML may need to set the prefix)
cmake .. -DCMAKE_PREFIX_PATH=$(brew --prefix sfml)/lib/cmake

# Build
cmake --build .

# Run the game from the bin directory
cd bin
./main
```