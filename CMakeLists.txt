cmake_minimum_required(VERSION 3.28)
project(S_M_S_Unix_Version VERSION 0.5)

set(CMAKE_C_STANDARD 17)

# Generate compile_commands.json
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Dependencies
set(RAYLIB_VERSION 5.0)
find_package(raylib ${RAYLIB_VERSION} QUIET) # QUIET or REQUIRED
if (NOT raylib_FOUND) # If there's none, fetch and build raylib
    include(FetchContent)
    FetchContent_Declare(
            raylib
            DOWNLOAD_EXTRACT_TIMESTAMP OFF
            URL https://github.com/raysan5/raylib/archive/refs/tags/${RAYLIB_VERSION}.tar.gz
    )
    FetchContent_GetProperties(raylib)
    if (NOT raylib_POPULATED) # Have we downloaded raylib yet?
        set(FETCHCONTENT_QUIET NO)
        FetchContent_Populate(raylib)
        set(BUILD_EXAMPLES OFF CACHE BOOL "" FORCE) # don't build the supplied examples
        add_subdirectory(${raylib_SOURCE_DIR} ${raylib_BINARY_DIR})
    endif()
endif()

file(GLOB_RECURSE SOURCES "src/*.c")
add_executable(${PROJECT_NAME} ${SOURCES})

#[[add_subdirectory(deps/glad/)
set(SDL2 /Library/Frameworks/SDL2.framework)
set(SDL2_image /Library/Frameworks/SDL2_image.framework)
set(SDL2_ttf /Library/Frameworks/SDL2_ttf.framework)
set(SDL2_mixer /Library/Frameworks/SDL2_mixer.framework)]]

target_link_libraries(
        ${PROJECT_NAME}
        #glad
        raylib
        #${SDL2}/Versions/A/SDL2
        #${SDL2_image}/Versions/A/SDL2_image
        #${SDL2_ttf}/Versions/A/SDL2_ttf
        #${SDL2_mixer}/Versions/A/SDL2_mixer
)

target_include_directories(
        ${PROJECT_NAME} PUBLIC
        #glad
        include
        deps
        #${SDL2}/Versions/A/Headers
        #${SDL2_image}/Versions/A/Headers
        #${SDL2_ttf}/Versions/A/Headers
        #${SDL2_mixer}/Versions/A/Headers
)



#set(raylib_VERBOSE 1)
# Checks if OSX and links appropriate frameworks (Only required on MacOS)
if (APPLE)
    target_link_libraries(${PROJECT_NAME} "-framework IOKit")
    target_link_libraries(${PROJECT_NAME} "-framework Cocoa")
    target_link_libraries(${PROJECT_NAME} "-framework OpenGL")
endif()