# Run: rm -rf build/ && cmake -S . -B build && cmake --build build && cd build && ctest
cmake_minimum_required(VERSION 3.14)
project(my_project)

# GoogleTest requires at least C++14
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

include(FetchContent)
FetchContent_Declare(
	googletest
	GIT_REPOSITORY https://github.com/google/googletest.git
	GIT_TAG		     v1.14.0
)
FetchContent_MakeAvailable(googletest)

enable_testing()

file(GLOB_RECURSE SOURCES RELATIVE ${CMAKE_SOURCE_DIR} "src/*.cpp")

add_executable(mytests
  ${SOURCES}
  "${CMAKE_SOURCE_DIR}/test/unit_test.cc"
)
target_include_directories(mytests PUBLIC ${CMAKE_SOURCE_DIR})

target_link_libraries(
  mytests
  PUBLIC
  GTest::gtest_main
  GTest::gmock_main
)

include(GoogleTest)
# Run tests
# gtest_discover_tests(mytests)