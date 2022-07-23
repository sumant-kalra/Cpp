cmake_minimum_required(VERSION 3.5)
project(CppPractiseProblems)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -std=c++17")
#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Werror -std=c++17")

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

# In case the library is a header only library, then all we have to do is add the include directory
#       A. add_executable(TARGET LIST_OF_SRC_H_CPP_FILES)
#       B. target_include_directory(TARGET PUBLIC LIB_PATH_FROM_PROJECT_SOURCE_DIR)


add_subdirectory(Libraries/timer)
add_subdirectory(Libraries/random)
add_subdirectory(Libraries/memoryTrace)

add_executable(runProgram
                src/Main.cpp
                src/Entity.h
                src/Entity.cpp
                src/Unions.h
                src/Unions.cpp
                src/Polymorphism.h
                src/Polymorphism.cpp
                src/Templates.h
                src/templates.cpp
                src/MultipleReturnValues.h
                src/MultipleReturnValues.cpp
                src/Benchmarking.cpp
                src/SocketServer.cpp
                src/Callback.h
                src/Callback.cpp
                src/TypeCasting.h
                src/TypeCasting.cpp
                src/VectorOptimized.cpp
                src/Arrow.cpp
                src/Constants.cpp
                src/This.cpp
                src/Move.cpp
                src/General.cpp
                src/StBind-OptData.cpp)

target_link_libraries(runProgram PUBLIC Timer)
target_link_libraries(runProgram PUBLIC Random)
target_link_libraries(runProgram PUBLIC MemoryTrace)

target_include_directories(runProgram PUBLIC "${PROJECT_SOURCE_DIR}/Libraries")