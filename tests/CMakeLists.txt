cmake_minimum_required(VERSION 3.14)

project("Dewdrop-Tests")

include(FetchContent)
FetchContent_Declare(
	googletest
	URL https://github.com/google/googletest/archive/46db91ef6ffcc128b2d5f31118ae1108109e3400.zip
)

if(WIN32)
	set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
endif()

FetchContent_MakeAvailable(googleTest)

enable_testing()

add_executable(${PROJECT_NAME} tests.cpp)

target_link_libraries(${PROJECT_NAME} GTest::gtest_main Dewdrop)

include(GoogleTest)
gtest_discover_tests(${PROJECT_NAME})
