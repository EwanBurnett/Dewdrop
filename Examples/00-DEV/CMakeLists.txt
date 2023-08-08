cmake_minimum_required(VERSION 3.8)

project("Dewdrop-DEV")

add_executable(${PROJECT_NAME} main.cpp)

target_link_libraries(${PROJECT_NAME} Dewdrop imgui)
