cmake_minimum_required(VERSION 3.27)
project(TheMaze C)

set(CMAKE_C_STANDARD 11)

include_directories(/opt/homebrew/opt/sdl2/include/SDL2)

add_executable(TheMaze src/main.c
        inc/maze.h
        src/maze.c)

link_directories(/opt/homebrew/opt/sdl2/lib)
find_library(SDL2_LIBRARY NAMES SDL2 PATHS /opt/homebrew/opt/sdl2/lib)
find_library(SDL2MAIN_LIBRARY NAMES SDL2main PATHS /opt/homebrew/opt/sdl2/lib)
target_link_libraries(TheMaze ${SDL2_LIBRARY} ${SDL2MAIN_LIBRARY})
