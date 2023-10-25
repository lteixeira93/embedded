cmake_minimum_required(VERSION 3.12)
project(op_overload)

set(CMAKE_CXX_STANDARD 14)
set(SOURCE_FILES
        cpp/002-Pointers/main.cpp
)

add_executable(${PROJECT_NAME} ${SOURCE_FILES})
