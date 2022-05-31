cmake_minimum_required(VERSION 3.22)
project(dankai)

if(WIN32)
include_directories($ENV{OPT_PATH}/include)
link_directories($ENV{OPT_PATH}/lib)
else()
include_directories(/usr/local/include)
link_directories(/usr/local/lib)
endif()

add_subdirectory(tetris)
add_subdirectory(arkanoid)
