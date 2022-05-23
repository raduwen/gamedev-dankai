project(tetris)

file(GLOB_RECURSE SRCS "src/*.cpp")

add_executable(tetris ${SRCS})
target_compile_features(tetris PRIVATE cxx_std_20)
target_link_libraries(tetris PRIVATE sfml-graphics sfml-window sfml-system)
