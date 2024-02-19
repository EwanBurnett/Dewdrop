# Dewdrop Library Project File
# Ewan Burnett - 2023
cmake_minimum_required(VERSION 3.14) 

project("Dewdrop" LANGUAGES CXX VERSION 0.0.0.1)

find_package(Vulkan REQUIRED)

add_subdirectory("ThirdParty")

# Build Dewdrop
configure_file("${CMAKE_SOURCE_DIR}/tools/Version.h.in" "${CMAKE_SOURCE_DIR}/include/Dewdrop/Version.h")

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

option(DEWDROP_BUILD_STATIC "Build Dewdrop as a Static Library" ON)
option(DEWDROP_BUILD_EXAMPLES "Build Example Projects" ON)
option(DEWDROP_BUILD_TESTS "Build Tests" ON)

set(DEWDROP_SOURCES "include/Dewdrop/Dewdrop.h" "src/Dewdrop.cpp" "include/Dewdrop/Version.h" "include/Dewdrop/Platform.h"  "src/Version.cpp" "include/Dewdrop/Window.h" "src/Window.cpp" "include/Dewdrop/Renderer.h" "src/Renderer.cpp" "include/Dewdrop/Graphics/Context.h" "include/Dewdrop/Graphics/Swapchain.h" "include/Dewdrop/Timer.h" "src/Timer.cpp")

set(DEWDROP_DEPS glfw Vulkan::Vulkan)
set(DEWDROP_DEFINES )

if(WIN32)
	# DX11 and DX12 are windows only 
	set(DEWDROP_DEPS ${DEWDROP_DEPS} d3d11.lib d3d12.lib)

		set(DEWDROP_SOURCES ${DEWDROP_SOURCES} "src/Platform/DD_Win32.cpp" "src/Graphics/DX11/DX11_Common.h" "src/Graphics/DX11/DX11_Context.h" "src/Graphics/DX11/DX11_Context.cpp" "src/Graphics/DX11/DX11_Swapchain.h" "src/Graphics/DX11/DX11_Swapchain.cpp")

	set(DEWDROP_DEFINES ${DEWDROP_DEFINES} DEWDROP_WIN32=1)
endif()

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

target_link_libraries(${PROJECT_NAME} ${DEWDROP_DEPS})
target_compile_definitions(${PROJECT_NAME} PUBLIC ${DEWDROP_DEFINES})
if(DEWDROP_BUILD_TESTS)
	add_subdirectory("tests")
endif()

if(DEWDROP_BUILD_EXAMPLES)
	add_subdirectory("Examples")
endif()

