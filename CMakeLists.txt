# CMakeLists.txt for C code
#
# Author: Julián Hinojosa Gil
# Original Author: Gustavo Pantuza Coelho Pinto
# Since: 24.03.2016

# CMake version
cmake_minimum_required(VERSION 3.10)

# Project name
project(PROJECT_NAME)

# Includes the project configurations
include(project.conf)

# Validating project variables defined in project.conf
if(NOT PROJECT_NAME)
    message(FATAL_ERROR "Missing PROJECT_NAME. Put variables at project.conf file")
endif()

if(NOT BINARY)
    message(FATAL_ERROR "Missing BINARY. Put variables at project.conf file")
endif()

if(NOT PROJECT_PATH)
    message(FATAL_ERROR "Missing PROJECT_PATH. Put variables at project.conf file")
endif()

# Source code directory structure
set(BINDIR "bin")
set(SRCDIR "src")
set(LIBDIR "lib")

# Source code file extension
set(SRCEXT "c")

# Defines the language standards for GCC
set(CMAKE_C_STANDARD 17)

# Protection for stack-smashing attack
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -fstack-protector-all -Wstack-protector")

# Specifies to GCC the required warnings
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Wextra")

# Debug options
set(CMAKE_C_FLAGS_DEBUG "${CMAKE_C_FLAGS_DEBUG} -g3 -DDEBUG=1")

# Dependency libraries
#set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -lm -I some/path/to/library")

# Source files
file(GLOB SOURCES "${SRCDIR}/*.${SRCEXT}")

# Object files
set(OBJECTS "")
foreach(SOURCE ${SOURCES})
    get_filename_component(NAME ${SOURCE} NAME_WE)
    list(APPEND OBJECTS "${LIBDIR}/${NAME}.o")
endforeach()

# Binary file
add_executable(${BINARY} ${SOURCES})
set_target_properties(${BINARY} PROPERTIES OUTPUT_DIRECTORY ${BINDIR})

# Rule for cleaning the project
add_custom_target(clean
        COMMAND ${CMAKE_COMMAND} -E remove_directory ${BINDIR}
        COMMAND ${CMAKE_COMMAND} -E remove_directory ${LIBDIR}
)

# Help message
add_custom_target(help
        COMMAND echo "S.M.S Unix Version"
        COMMAND echo
        COMMAND echo "Target rules:"
        COMMAND echo "    all      - Compiles and generates binary file"
        COMMAND echo "    run      - Run the current binary file"
        COMMAND echo "    clean    - Clean the project by removing binaries"
        COMMAND echo "    help     - Prints a help message with target rules"
        COMMAND echo
)

# Run command
add_custom_target(run
        COMMAND ./${BINDIR}/${BINARY}
)
