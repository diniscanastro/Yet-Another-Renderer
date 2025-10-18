cmake_minimum_required(VERSION 3.22)
project(Yet_Another_Renderer_Rasterizer)

set(CMAKE_CXX_STANDARD 20)

Include(FetchContent)

FetchContent_Declare(
        SDL3
        GIT_REPOSITORY https://github.com/libsdl-org/SDL.git
        GIT_TAG        release-3.2.16
)
FetchContent_MakeAvailable(SDL3)

add_executable(Yet_Another_Renderer_Rasterizer main.cpp)

# SDL
target_link_libraries(Yet_Another_Renderer_Rasterizer PRIVATE SDL3::SDL3)
