cmake_minimum_required(VERSION 3.27)
project(TheMaze C)

set(CMAKE_C_STANDARD 11)

include_directories(/opt/homebrew/opt/sdl2/include/SDL2)

add_executable(TheMaze src/main.c
        inc/maze.h
        src/maze.c)

link_directories(
        /opt/homebrew/opt/sdl2/lib
        /opt/homebrew/Cellar/sdl2_image/2.8.2_1/include/SDL2/
)

include_directories(/opt/homebrew/Cellar/sdl2_image/2.8.2_1/include/SDL2/)
find_library(SDL2_LIBRARY NAMES SDL2 PATHS /opt/homebrew/opt/sdl2/lib)
find_library(SDL2MAIN_LIBRARY NAMES SDL2main PATHS /opt/homebrew/opt/sdl2/lib)
find_library(SDL2_IMAGE_LIBRARY NAMES SDL2_image PATHS /opt/homebrew/Cellar/sdl2_image/2.8.2_1/include/SDL2/)
target_link_libraries(TheMaze PRIVATE ${SDL2_IMAGE_LIBRARY} ${SDL2_LIBRARY} ${SDL2MAIN_LIBRARY})
