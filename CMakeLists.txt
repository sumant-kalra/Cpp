# set the minimum cmake version requirement
cmake_minimum_required(VERSION 3.5)
# set the name of the project
project(HelloWorld)

# define variables and assign them values

# CMAKE_CXX_FLAGS = The default CMAKE_CXX_FLAGS variable value + additional flags
# Wall: display all the warnings
# Werror: display all the error messages
# set the c++ standard
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Werror -std=c++14")

# source_dir = The project source directory/src/
# PROJECT_SOURCE_DIR is the current directory
set(source_dir "${PROJECT_SOURCE_DIR}/src/")

# informing compiler about the files to compile
file(GLOB source_files "${source_dir}/*.cpp" )

# add the executable by providing the name of the executable
add_executable(HelloProgram ${source_files})
