cmake_minimum_required(VERSION 3.5)
project(CppPractiseProblems)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Werror -std=c++14")

add_compile_definitions(PR_RELEASE=1)

add_executable(runProgram
                src/Main.cpp
                src/Entity.h
                src/Entity.cpp
                src/Timer.h
                src/Timer.cpp
                src/Utilities.h
                src/Unions.h
                src/Unions.cpp
                src/Random.h
                src/Random.cpp
                src/Polymorphism.h
                src/Polymorphism.cpp)