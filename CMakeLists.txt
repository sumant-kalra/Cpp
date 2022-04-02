cmake_minimum_required(VERSION 3.5)
project(CppPractiseProblems)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Werror -std=c++14")

add_compile_definitions(PR_RELEASE=1)

# Inside -> Out
# 1. In the folder with souce files of the library,
#    CMakeLists.txt
#       add_library(CPP_FILE_NAMES)
# 2. In the PROJECT_SOURCE_DIR,
#    the root CMakeLists.txt
#       A. add_subdirectory(DIR_LIBRARY_FROM_CURRENT_DIR) 
#       B. add_executable(TARGET LIST_OF_SRC_H_CPP_FILES)
#       C. target_link_library(TARGET PUBLIC LIB_NAME)
#       D. target_include_directory(TARGET PUBLIC LIB_PATH_FROM_PROJECT_SOURCE_DIR)
#


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