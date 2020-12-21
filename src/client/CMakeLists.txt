cmake_minimum_required(VERSION 3.1.3)

project(client)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

file(GLOB SOURCES ${CMAKE_SOURCE_DIR}/src *.h *.cpp .*hpp)
file(GLOB INCL ${INCLUDES_DIR}/client *.h *.hpp)

add_library(${PROJECT_NAME}
	${SOURCES}
	${INCLUDES_DIR}/client/Client.h
)

target_link_libraries(${PROJECT_NAME} PRIVATE
	Qt5::Widgets
	Qt5::Network
	)
