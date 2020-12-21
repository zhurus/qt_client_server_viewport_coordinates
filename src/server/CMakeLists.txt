cmake_minimum_required(VERSION 3.1.3)

project(server)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

file(GLOB SOURCES ${CMAKE_SOURCE_DIR}/src *.h *.cpp .*hpp)

add_library(${PROJECT_NAME}
	${SOURCES}
	${INCLUDES_DIR}/server/Server.h
	)

target_link_libraries(${PROJECT_NAME}
	Qt5::Network
	)
