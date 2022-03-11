add_executable(RunProgram
    Main.cpp
    Timer.h
    Timer.cpp
    Entity.h
    Entity.cpp)
set_target_properties(RunProgram PROPERTIES COMPILE_FLAGS "-save-temps")
