cmake_minimum_required(VERSION 3.1.3)

set(INCLUDES_DIR ${CMAKE_SOURCE_DIR}/includes)

add_subdirectory(client)
add_subdirectory(server)

add_subdirectory(test_client)
add_subdirectory(test_server)
