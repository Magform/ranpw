cmake_minimum_required(VERSION 3.19)
cmake_policy(VERSION 3.19)

# Initialize Mbed OS build system. 
# Note: This block must be before the include of app.cmake
set(MBED_APP_JSON_PATH mbed_app.json)

include(mbed-os/tools/cmake/app.cmake)
add_subdirectory(mbed-os)

project(ranpw)

# Build libraries
add_subdirectory(C12832)
add_subdirectory(LM75B)

# Build application
set(RANPW_SOURCES
    lib/Bag/Bag.cpp
    lib/ConcurrentData/ConcurrentData.cpp
    lib/Cronometer/Cronometer.cpp
    lib/DataSaver/DataSaver.cpp
    lib/Food/Food.cpp
    lib/Interaction/Interaction.cpp
    lib/Kraken/Kraken.cpp
    lib/LCatch/LCatch.cpp
    lib/Pong/Pong.cpp
    lib/Temp/Temp.cpp
    main.cpp)

add_executable(ranpw ${RANPW_SOURCES})
target_include_directories(ranpw PRIVATE include)
target_link_libraries(ranpw LM75B C12832 mbed-os)
mbed_set_post_build(ranpw)

mbed_finalize_build()