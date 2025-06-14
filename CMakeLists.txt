cmake_minimum_required(VERSION 3.31)
project(Yet_Another_Renderer)

set(CMAKE_CXX_STANDARD 20)

add_executable(Yet_Another_Renderer src/main.cpp
        src/renderer.cpp
        include/renderer.h
        src/color.cpp
        include/color.h
        src/point.cpp
        include/point.h)

set(SDL3_DIR "C:\\libs\\external\\SDL3-3.1.3\\cmake")
find_package(SDL3 3.1.3 REQUIRED)

target_link_libraries(Yet_Another_Renderer PRIVATE SDL3::SDL3)
target_compile_definitions(Yet_Another_Renderer PRIVATE SDL_MAIN_USE_CALLBACKS)
target_link_options(Yet_Another_Renderer PRIVATE -static)
