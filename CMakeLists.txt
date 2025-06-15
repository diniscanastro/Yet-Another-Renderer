cmake_minimum_required(VERSION 3.31)
project(Yet_Another_Renderer)

set(CMAKE_CXX_STANDARD 20)

Include(FetchContent)

FetchContent_Declare(
        SDL3
        GIT_REPOSITORY https://github.com/libsdl-org/SDL.git
        GIT_TAG        release-3.2.16
)
FetchContent_MakeAvailable(SDL3)

add_executable(Yet_Another_Renderer main.cpp
        src/renderer.cpp
        include/renderer.h
        src/color.cpp
        include/color.h
        src/point.cpp
        include/point.h
)

# SDL
target_link_libraries(Yet_Another_Renderer PRIVATE SDL3::SDL3)
target_compile_definitions(Yet_Another_Renderer PRIVATE SDL_MAIN_USE_CALLBACKS)
target_link_options(Yet_Another_Renderer PRIVATE -static)

# UTs
add_subdirectory(tests)