add_library(MMA7660 
    MMA7660.cpp
    )
target_include_directories(MMA7660 PUBLIC .)
target_link_libraries(MMA7660 mbed-core-flags)