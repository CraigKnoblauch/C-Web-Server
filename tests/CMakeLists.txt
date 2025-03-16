file(GLOB SOURCES "${CWebServer_SOURCE_DIR}/src/*.c")
file(GLOB HEADERS "${CWebServer_SOURCE_DIR}/src/*.h")
file(GLOB TESTS "${CMAKE_CURRENT_SOURCE_DIR}/*.test.c")

file(COPY ${TESTS} DESTINATION ${CMAKE_CURRENT_BINARY_DIR})
file(COPY ${SOURCES} DESTINATION ${CMAKE_CURRENT_BINARY_DIR})
file(COPY ${HEADERS} DESTINATION ${CMAKE_CURRENT_BINARY_DIR})


add_executable(llist ${CMAKE_CURRENT_BINARY_DIR}/llist.test.c)
add_executable(cache ${CMAKE_CURRENT_BINARY_DIR}/cache.test.c)
add_executable(http ${CMAKE_CURRENT_BINARY_DIR}/http.test.c)


add_library(srclib ${SOURCES})
set_target_properties(srclib PROPERTIES LINKER_LANGUAGE C)

# llist tests 
target_link_libraries(llist srclib)
target_include_directories(llist PRIVATE ${CMAKE_CURRENT_BINARY_DIR})
add_test(NAME "llist" COMMAND llist)

# cache tests
target_link_libraries(cache srclib)
target_include_directories(cache PRIVATE ${CMAKE_CURRENT_BINARY_DIR})
# add_test(NAME "cache" COMMAND cache)

# http tests
target_link_libraries(http srclib)
target_include_directories(http PRIVATE ${CMAKE_CURRENT_BINARY_DIR})
add_test(NAME "http" COMMAND http)


