cmake_minimum_required(VERSION 3.22)
project(dankai)

set(CMAKE_MODULE_PATH
  ${CMAKE_MODULE_PATH}
  ${dankai_SOURCE_DIR}/cmake
)
if(WIN32)
set(SFML_ROOT $ENV{OPT_PATH})
link_directories($ENV{OPT_PATH}/lib)
endif()

find_package(SFML 2.5 COMPONENTS system graphics audio window network)
if(NOT ${SFML_FOUND})
message(FATAL_ERROR "SFML not found")
else()
include_directories(${SFML_INCLUDE_DIR})
endif()

add_subdirectory(vendor)
add_subdirectory(tetris)
add_subdirectory(arkanoid)
