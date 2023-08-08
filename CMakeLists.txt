# Dewdrop Library Project File
# Ewan Burnett - 2023
cmake_minimum_required(VERSION 3.8) 

project("Dewdrop" LANGUAGES CXX)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)

option(DEWDROP_BUILD_STATIC "Build Dewdrop as a Static Library" ON)
option(DEWDROP_BUILD_EXAMPLES "Build Example Projects" ON)

#set(DEWDROP_INCLUDE_DIRS "${PROJECT_SOURCE_DIR}/include" CACHE INTERNAL "${PROJECT_NAME}: Include Directories" FORCE)
set(DEWDROP_SOURCES "include/Dewdrop.h" "src/Dewdrop.cpp")
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

if(DEWDROP_BUILD_EXAMPLES)
	add_subdirectory("Examples")
endif()
