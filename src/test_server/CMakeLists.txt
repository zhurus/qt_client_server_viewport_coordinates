project(test_server)

file(GLOB SOURCES ${CMAKE_SOURCE_DIR}/src *.h *.cpp .*hpp)

set(CMAKE_AUTOMOC ON)

find_package(Qt5 COMPONENTS
	Widgets
	Network
	REQUIRED)

add_executable(${PROJECT_NAME} ${SOURCES})

add_dependencies(${PROJECT_NAME} server)
target_link_libraries(${PROJECT_NAME}
	server
	Qt5::Widgets
	Qt5::Network
	)
