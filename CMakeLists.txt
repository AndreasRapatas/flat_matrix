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
add_executable(
	${PROJECT_NAME}_test
	tests/main.cpp
	tests/logic.cpp
	tests/copy_move.cpp
)

add_subdirectory(./third_party/catch2)
target_link_libraries(
	${PROJECT_NAME}_test
	PRIVATE
		Catch
)

include(CTest)
if (BUILD_TESTING)
	add_test(
		NAME ${PROJECT_NAME}_test
		COMMAND ${PROJECT_NAME}_test
	)
endif()


