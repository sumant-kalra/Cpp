cmake_minimum_required(VERSION 3.10.1)
project(TestSetup)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Werror -std=c++14")

set(source_dir "${PROJECT_SOURCE_DIR}/src")
file(GLOB source_code_files "${source_dir}/*.cpp")

add_executable(HelloWorld "${source_code_files}")