cmake_minimum_required(VERSION 3.10)
project(CWebServer LANGUAGES C)

# All source files in the src directory root level
file(GLOB SOURCES "src/*.c")
add_executable(server ${SOURCES})

# Testing
enable_testing()
add_subdirectory(tests)