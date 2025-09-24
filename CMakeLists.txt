cmake_minimum_required(VERSION 3.22)
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
        src/canvas.cpp
        include/canvas.h
        src/viewport.cpp
        include/viewport.h
        src/sphere.cpp
        include/sphere.h
        src/light.cpp
        include/light.h
        include/world.h
)

# SDL
target_link_libraries(Yet_Another_Renderer PRIVATE SDL3::SDL3)

# UTs TODO: Fix this is not compiling
# add_subdirectory(tests)