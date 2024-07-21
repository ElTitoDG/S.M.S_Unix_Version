cmake_minimum_required(VERSION 3.28)
project(S_M_S_Unix_Version VERSION 0.5)

set(CMAKE_C_STANDARD 17)
set(CMAKE_OSX_ARCHITECTURES x86_64;arm64)

# Dependencies
find_package(SDL2 REQUIRED)
find_package(SDL2_image REQUIRED)
find_package(SDL2_ttf REQUIRED)

file(GLOB_RECURSE SOURCES "src/*.c")
add_executable(${PROJECT_NAME} ${SOURCES})

add_subdirectory(include/glad/)
target_link_libraries(
        ${PROJECT_NAME} PRIVATE
        glad
        SDL2::SDL2
        SDL2_image::SDL2_image
        SDL2_ttf::SDL2_ttf
)