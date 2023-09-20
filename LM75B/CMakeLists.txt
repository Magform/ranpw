add_library(LM75B 
    LM75B.cpp)
target_include_directories(LM75B PUBLIC .)
target_link_libraries(LM75B mbed-core-flags)