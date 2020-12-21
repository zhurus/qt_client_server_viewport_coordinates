cmake_minimum_required(VERSION 3.1.3)

project(viewport_coordinates)

set (CMAKE_CXX_STANDARD 17)

include_directories(${PROJECT_SOURCE_DIR}/includes)

find_package(Qt5 COMPONENTS
	Widgets
	Network
	REQUIRED)

add_subdirectory(src)
