cmake_minimum_required(VERSION 3.0)

project(
	flat_matrix
	VERSION 1.2
	LANGUAGES CXX
)

# Definitions {{{

set(
	${PROJECT_NAME}_headers
	./include/flat_matrix.h
)

add_library(
	${PROJECT_NAME}
	INTERFACE
)

# }}}

# Install {{{

set(destination lib/cmake/${PROJECT_NAME})

# Packaging {{{

include(CMakePackageConfigHelpers)

write_basic_package_version_file(
	"${PROJECT_BINARY_DIR}/${PROJECT_NAME}ConfigVersion.cmake"
	VERSION ${PROJECT_VERSION}
	COMPATIBILITY AnyNewerVersion
)

install(
	FILES "${PROJECT_BINARY_DIR}/${PROJECT_NAME}ConfigVersion.cmake"
	DESTINATION ${destination}
)

configure_package_config_file(
	"${PROJECT_SOURCE_DIR}/cmake/configs/${PROJECT_NAME}Config.cmake.in"
	"${PROJECT_BINARY_DIR}/${PROJECT_NAME}Config.cmake"
	INSTALL_DESTINATION ${destination}
)

install(
	FILES "${PROJECT_BINARY_DIR}/${PROJECT_NAME}Config.cmake"
	DESTINATION ${destination}
)

# }}}

install(
	TARGETS ${PROJECT_NAME}
	EXPORT  ${PROJECT_NAME}Targets
)

install(
	EXPORT      ${PROJECT_NAME}Targets
	FILE        ${PROJECT_NAME}Targets.cmake
	NAMESPACE   ${PROJECT_NAME}::
	DESTINATION ${destination}
)

install(
	FILES ${${PROJECT_NAME}_headers}
	DESTINATION include/${PROJECT_NAME}
)

# }}}

# Tests {{{

# Use cmake .. -DBUILD_TESTING=1
if (BUILD_TESTING)

	# To run the tests, Install https://github.com/catchorg/Catch2
	find_package(Catch2 CONFIG REQUIRED)

	add_executable(
		${PROJECT_NAME}_test
		tests/main.cpp
		tests/logic.cpp
		tests/copy_move.cpp
	)

	target_link_libraries(
		${PROJECT_NAME}_test
		PRIVATE
		Catch2::Catch2
	)

	add_test(
		NAME ${PROJECT_NAME}_test
		COMMAND ${PROJECT_NAME}_test
	)

endif()

# }}}
