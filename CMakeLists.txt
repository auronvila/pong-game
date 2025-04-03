cmake_minimum_required(VERSION 3.28)
project(PongGame LANGUAGES CXX)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

# Conditionally set SFML path for macOS/Homebrew users
if(APPLE AND NOT DEFINED SFML_DIR)
    set(SFML_DIR "/opt/homebrew/opt/sfml/lib/cmake/SFML")
endif()

# Let CMake find SFML 3
find_package(SFML 3 REQUIRED COMPONENTS Graphics Window System)

if(NOT SFML_FOUND)
    message(FATAL_ERROR "SFML 3 not found! If you're on macOS and using Homebrew, try setting: -DCMAKE_PREFIX_PATH=$(brew --prefix sfml)/lib/cmake")
endif()


add_executable(main
        src/main.cpp
        src/Player.cpp

        src/StartMenu.cpp
        src/StartMenu.h

        src/Game.cpp
        src/Game.h

        src/Ball.cpp
        src/Ball.h

        src/Scoreboard.cpp
        src/Scoreboard.h

        src/Arena.h
        src/Consts.h
)

# Copy assets directory to build/bin after build
add_custom_command(TARGET main POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_directory
        ${CMAKE_SOURCE_DIR}/assets
        ${CMAKE_BINARY_DIR}/bin/assets)

# Set C++ standard
target_compile_features(main PRIVATE cxx_std_17)

# Link SFML 3 targets
target_link_libraries(main
        PRIVATE
        SFML::Graphics
        SFML::Window
        SFML::System
)
