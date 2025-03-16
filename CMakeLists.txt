cmake_minimum_required(VERSION 3.10)
project(CWebServer LANGUAGES C)

# All source files in the src directory root level
file(GLOB SOURCES "src/*.c")
add_executable(server ${SOURCES})

# Copy all serverfiles and serverroot files to build dir
file(COPY "src/serverfiles" DESTINATION ${CMAKE_BINARY_DIR})
file(COPY "src/serverroot" DESTINATION ${CMAKE_BINARY_DIR})

# Testing
enable_testing()
add_subdirectory(tests)