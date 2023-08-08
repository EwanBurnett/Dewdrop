cmake_minimum_required(VERSION 3.14)

# Build External Projects
find_package(Git QUIET)
if(GIT_FOUND AND EXISTS "${PROJECT_SOURCE_DIR}/.git") # Update the git submodules
	message(STATUS "Validating Git Submodules")
	execute_process(COMMAND ${GIT_EXECUTABLE} submodule update --init --recursive WORKING_DIRECTORY ${CMAKE_SOURCE_DIR} RESULT_VARIABLE GIT_SUBMODULES_VALID)

	if(NOT GIT_SUBMODULES_VALID EQUAL "0")
		message(WARNING "Failed to acquire Git Submodules. Falling back to fetch_content.")
	endif()

	# GLFW
	if(EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/GLFW/.git")
		add_subdirectory(GLFW)
	endif()
	
	# IMGUI
	if(EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/Imgui/.git")
        set(IMGUI_DIR "${CMAKE_CURRENT_SOURCE_DIR}/Imgui/")
	endif()


else()	# The project hasn't got any git information, so download dependencies using fetch_content
	include(FetchContent)

	# GLFW 
	FetchContent_Declare(
        glfw
        GIT_REPOSITORY https://github.com/glfw/glfw.git
		GIT_TAG 3eaf1255b29fdf5c2895856c7be7d7185ef2b241 # release 3.3.8
	)
	
	# IMGUI
	FetchContent_Declare(
		imgui
		GIT_REPOSITORY https://github.com/ocornut/imgui
		GIT_TAG bc3c0ce7728f39530020a979a19bfc176e4e8596 # release 1.89.8
	)

	FetchContent_MakeAvailable(glfw imgui)

	set(IMGUI_DIR ${imgui_SOURCE_DIR})
endif()

#Build ImGui
	add_library(imgui 
	"${IMGUI_DIR}/imgui.cpp" 
	"${IMGUI_DIR}/imgui_demo.cpp"
	"${IMGUI_DIR}/imgui_draw.cpp" 
	"${IMGUI_DIR}/imgui_tables.cpp" 
	"${IMGUI_DIR}/imgui_widgets.cpp" 
	"${IMGUI_DIR}/backends/imgui_impl_glfw.cpp"
	)
	target_link_libraries(imgui glfw)
	target_include_directories(imgui PUBLIC ${IMGUI_DIR})

