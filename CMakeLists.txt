cmake_minimum_required(VERSION 3.5)
project(CppPractiseProblems)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Werror -std=c++14")

add_compile_definitions(PR_RELEASE=1)

add_subdirectory(ExternalLibs/timer)

add_executable(runProgram
                src/Main.cpp
                src/Entity.h
                src/Entity.cpp
                src/Utilities.h
                src/Unions.h
                src/Unions.cpp
                src/Random.h
                src/Random.cpp
                src/Polymorphism.h
                src/Polymorphism.cpp)

target_link_libraries(runProgram PUBLIC Timer)

target_include_directories(runProgram PUBLIC "${PROJECT_SOURCE_DIR}/ExternalLibs")