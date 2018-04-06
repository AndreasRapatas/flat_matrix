cmake_minimum_required(VERSION 3.0)

add_executable(
	test_flat_matrix
	tests/main.cpp
	tests/logic.cpp
	)

add_subdirectory(./third_party/catch2)

target_link_libraries(
	test_flat_matrix
	PRIVATE
		Catch
	)
