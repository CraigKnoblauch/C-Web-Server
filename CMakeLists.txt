cmake_minimum_required(VERSION 3.10)
project(CWebServer)

# All source files in the src directory root level
file(GLOB SOURCES "src/*.c")
add_executable(server ${SOURCES} )