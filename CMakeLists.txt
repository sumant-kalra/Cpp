cmake_minimum_required(VERSION 3.10.1)
project(TestSetup)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Werror -std=c++14")

add_subdirectory(src)