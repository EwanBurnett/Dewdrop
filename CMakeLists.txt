# Dewdrop Library Project File
# Ewan Burnett - 2023
cmake_minimum_required(VERSION 3.14) 

project("Dewdrop" LANGUAGES CXX VERSION 0.0.0.1)


add_subdirectory("ThirdParty")

# Build Dewdrop
configure_file("${CMAKE_SOURCE_DIR}/tools/Version.h.in" "${CMAKE_SOURCE_DIR}/include/Dewdrop/Version.h")

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

option(DEWDROP_BUILD_STATIC "Build Dewdrop as a Static Library" ON)
option(DEWDROP_BUILD_EXAMPLES "Build Example Projects" ON)
option(DEWDROP_BUILD_TESTS "Build Tests" ON)

set(DEWDROP_SOURCES "src/Dewdrop.cpp")
include_directories("${CMAKE_SOURCE_DIR}/include")

if(DEWDROP_BUILD_STATIC)
	message(STATUS "Building Dewdrop Static")
	add_library(${PROJECT_NAME} STATIC ${DEWDROP_SOURCES})
else()
	message(STATUS "Building Dewdrop Shared Library.") 
	add_library(${PROJECT_NAME} SHARED ${DEWDROP_SOURCES})
endif()


set_target_properties(${PROJECT_NAME} PROPERTIES
	CXX_STANDARD 17
	LINKER_LANGUAGE CXX
	)

target_link_libraries(${PROJECT_NAME} glfw)

if(DEWDROP_BUILD_TESTS)
	add_subdirectory("tests")
endif()

if(DEWDROP_BUILD_EXAMPLES)
	add_subdirectory("Examples")
endif()

