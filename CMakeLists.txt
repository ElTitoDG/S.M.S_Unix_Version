cmake_minimum_required(VERSION 3.28)
project(S_M_S_Gui_Version VERSION 0.5)

set(CMAKE_C_STANDARD 17)

file(GLOB_RECURSE SOURCES "src/*.c")
add_executable(S_M_S_Gui_Version ${SOURCES})

add_subdirectory(deps/glad/)
set(SDL2 /Library/Frameworks/SDL2.framework)
set(SDL2_image /Library/Frameworks/SDL2_image.framework)
set(SDL2_ttf /Library/Frameworks/SDL2_ttf.framework)
set(SDL2_mixer /Library/Frameworks/SDL2_mixer.framework)
set(FRAMEWORK_LIBS "-framework Cocoa -framework OpenGL -framework IOKit -framework AudioToolbox")

target_link_libraries(
        S_M_S_Gui_Version PUBLIC
        glad
        ${SDL2}/Versions/A/SDL2
        ${SDL2_image}/Versions/A/SDL2_image
        ${SDL2_ttf}/Versions/A/SDL2_ttf
        ${SDL2_mixer}/Versions/A/SDL2_mixer
        ${FRAMEWORK_LIBS}
)

target_include_directories(
        S_M_S_Gui_Version PUBLIC
        glad
        deps
        include
        ${SDL2}/Versions/A/Headers
        ${SDL2_image}/Versions/A/Headers
        ${SDL2_ttf}/Versions/A/Headers
        ${SDL2_mixer}/Versions/A/Headers
)