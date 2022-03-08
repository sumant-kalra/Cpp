# 3 primary steps

# 1. Minimum version requirement
# 2. Project name
# -  Set compiler flags [CXXFLAGS environment variable]
# -  Set source directory
# -  Set source files from the source directory
# 3. Executable file created by compiling the source files

# [1]
# set the minimum cmake version requirement by setting the value in CMAKE_MINIMUM_REQUIRED_VERSION variable
# reports an error if the version is < specifiedVersionValue
cmake_minimum_required(VERSION 3.5)

# [2]
# set the name of the project by setting the value in PROJECT_NAME variable
# when called from the top-level CMakeLists.txt, both CMAKE_PROJECT_NAME and PROJECT_NAME are set
project(HelloWorld)

# [----------------------------------------------------------------------------------------------------------------]
# define variables, assign them values, and their scopes
# set() command - sets a normal, cache, or environment variable to a given value.
# variable can be a single variable or a list (Refer to the documentation)

# [-]
# CMAKE_CXX_FLAGS = The default CMAKE_CXX_FLAGS variable value + additional flags
# Wall: display all the warnings
# Werror: display all the error messages
# set the c++ standard
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Werror -std=c++14")

# [--]
# source_dir = The project source directory/src/
# PROJECT_SOURCE_DIR is the current directory
# It is the source directory of the last call to the project() command made in the current directory scope or
# one of its parents. (Refer to the documentation)
set(source_dir "${PROJECT_SOURCE_DIR}/src/")

# [---]
# Generate a list of files from the Filesystem that match the globbing expression specified in ""
# and store it in the variable source_files
file(GLOB source_files "${source_dir}/*.cpp" )
# [WARNING] - BE CAREFUL IF GLOB IS USED
# Usage of GLOB is not recommended as with addition/removal of files from the source directory does need
# a change in CMakeList.txt file, hence the build system will not know if the cmake needs to run again.
# Manual approach of creating the list of files is recommended.

# [----------------------------------------------------------------------------------------------------------------]

# [3]
# add an executable Target named 'HelloProgram' to be built from the source files listed in the command invocation
add_executable(HelloProgram ${source_files})

# Note that the directory structure of the project and the one in the actual filesystem are two different things.
# PREFERABLY CREATE THE PROJECT DIRECTORY STRUCTURE SAME AS THE FILESYSTEM DIRECTORY STRUCTURE
# BY USING add_subdirectory COMMAND.
# In our current example, we have not created any subdirectory for the project. The src directory of filesystem
# contains the source code files. We provided the file names './src/main.cpp', directly to add_executable command
# instead of keeping the sub directory 'src' in the project directory.
# Hence the project directory structure created with the script above is described below:
# HelloWorld
#   main.cpp


# the cmake can be run for this CMakeLists.txt by using the command below
#cmake <PathToCMakeLists.txt> -G "Unix Makefiles" -D CMAKE_BUILD_TYPE=Debug
# -G : Generator type
# -D : Sets the cache variables at the command line