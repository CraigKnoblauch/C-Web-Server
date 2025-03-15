file(COPY "${CMAKE_CURRENT_SOURCE_DIR}/llist.test.c" DESTINATION ${CMAKE_CURRENT_BINARY_DIR})
file(COPY ${CWebServer_SOURCE_DIR}/src/llist.c DESTINATION ${CMAKE_CURRENT_BINARY_DIR})
file(COPY ${CWebServer_SOURCE_DIR}/src/llist.h DESTINATION ${CMAKE_CURRENT_BINARY_DIR})

file(GLOB TESTS "${CMAKE_CURRENT_SOURCE_DIR}/*.test.c")
add_executable(tests ${TESTS})

file(GLOB SOURCES "${CWebServer_SOURCE_DIR}/src/*.c")
add_library(srclib ${SOURCES})
set_target_properties(srclib PROPERTIES LINKER_LANGUAGE C)
target_link_libraries(tests srclib)
target_include_directories(tests PRIVATE ${CMAKE_CURRENT_BINARY_DIR})

add_test(NAME "llist" COMMAND tests)

