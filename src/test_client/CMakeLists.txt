cmake_minimum_required(VERSION 3.1.3)
project(test_client)
file(GLOB SOURCES ${CMAKE_SOURCE_DIR}/src *.h *.cpp .*hpp)

set(CMAKE_AUTOMOC ON)

find_package(Qt5 COMPONENTS
	Widgets
	Network
	REQUIRED)

add_executable(${PROJECT_NAME} ${SOURCES})

add_dependencies(${PROJECT_NAME} client)
target_link_libraries(${PROJECT_NAME}
	client
	Qt5::Widgets
	Qt5::Network
	)
