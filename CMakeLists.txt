cmake_minimum_required(VERSION 3.0)

project(
	flat_matrix
	VERSION 1.0
	LANGUAGES CXX
)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_library(
	${PROJECT_NAME}
	INTERFACE
)
target_include_directories(
	${PROJECT_NAME}
	INTERFACE
		./include
)

# Testing

include(CTest)
# To run the tests, Install https://github.com/catchorg/Catch2
find_package(Catch2 CONFIG QUIET)
if (BUILD_TESTING AND Catch2_FOUND)

	add_executable(
		${PROJECT_NAME}_test
		tests/main.cpp
		tests/logic.cpp
		tests/copy_move.cpp
	)

	target_link_libraries(
		${PROJECT_NAME}_test
		PRIVATE
		Catch2::Catch
	)

	add_test(
		NAME ${PROJECT_NAME}_test
		COMMAND ${PROJECT_NAME}_test
	)
endif()


