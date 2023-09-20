add_library(C12832 
    C12832.cpp
    GraphicsDisplay.cpp
    TextDisplay.cpp)
target_include_directories(C12832 PUBLIC .)
target_link_libraries(C12832 mbed-core-flags)