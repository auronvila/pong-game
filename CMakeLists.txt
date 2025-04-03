cmake_minimum_required(VERSION 3.28)
project(PongGame LANGUAGES CXX)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

# Help CMake find the Homebrew-installed SFML 3
set(CMAKE_PREFIX_PATH "/opt/homebrew/opt/sfml/lib/cmake")

find_package(SFML 3 REQUIRED COMPONENTS Graphics Window System)

add_executable(main
        src/main.cpp
        src/Player.cpp

        src/Game.cpp
        src/Game.h

        src/Ball.cpp
        src/Ball.h

        src/Scoreboard.cpp
        src/Scoreboard.h

        src/Arena.h
        src/Consts.h
)

target_compile_features(main PRIVATE cxx_std_17)

# Use modern imported targets for SFML 3
target_link_libraries(main
        PRIVATE
        SFML::Graphics
        SFML::Window
        SFML::System
)
