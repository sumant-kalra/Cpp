cmake_minimum_required(VERSION 3.5)
project(BitwiseOperations)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Werror -std=c++14")

add_executable(ExeProgram
                src/Main.cpp
                src/Entity.h
                src/Entity.cpp
                src/Timer.h
                src/Timer.cpp)