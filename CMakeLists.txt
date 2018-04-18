# Link to this with
# find_package(lib_name CONFIG REQUIRED)
# target_link_libraries(${PROJECT_NAME} lib_name::lib_name)


cmake_minimum_required(VERSION 3.0)

# Required for YCM to work
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

project(
	flat_matrix
	VERSION 1.1
	LANGUAGES CXX
)

add_library(
	${PROJECT_NAME}
	INTERFACE
)
target_compile_definitions(
	${PROJECT_NAME}
	INTERFACE LIBRARY_HEADER_ONLY
)
target_include_directories(
	${PROJECT_NAME}
	INTERFACE
		$<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/include>
		$<INSTALL_INTERFACE:include>
)

# =========
# Packaging
# =========

include(CMakePackageConfigHelpers)

write_basic_package_version_file(
	"${PROJECT_BINARY_DIR}/${PROJECT_NAME}ConfigVersion.cmake"
	VERSION ${PROJECT_VERSION}
	COMPATIBILITY AnyNewerVersion
)
configure_package_config_file(
	"${PROJECT_SOURCE_DIR}/cmake/${PROJECT_NAME}Config.cmake.in"
	"${PROJECT_BINARY_DIR}/${PROJECT_NAME}Config.cmake"
	INSTALL_DESTINATION lib/cmake/${PROJECT_NAME}
)
install(
	FILES
		"${PROJECT_BINARY_DIR}/${PROJECT_NAME}ConfigVersion.cmake"
		"${PROJECT_BINARY_DIR}/${PROJECT_NAME}Config.cmake"
	DESTINATION lib/cmake/${PROJECT_NAME}
)

install(
	TARGETS       ${PROJECT_NAME}
	EXPORT        ${PROJECT_NAME}Targets

	PUBLIC_HEADER DESTINATION include/${PROJECT_NAME} COMPONENT Development
)
install(
	EXPORT      ${PROJECT_NAME}Targets
	FILE        ${PROJECT_NAME}Targets.cmake
	NAMESPACE   ${PROJECT_NAME}::
	DESTINATION lib/cmake/${PROJECT_NAME}
)

install(
	DIRECTORY ${PROJECT_SOURCE_DIR}/include/
	DESTINATION include/${PROJECT_NAME}
)

# =======
# Testing
# =======

# To run the tests, Install https://github.com/catchorg/Catch2

include(CTest)
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


