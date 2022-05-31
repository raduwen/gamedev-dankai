project(arkanoid)

file(GLOB_RECURSE SRCS "src/*.cpp")

add_executable(arkanoid ${SRCS})
target_compile_features(arkanoid PRIVATE cxx_std_20)
target_link_libraries(arkanoid PRIVATE sfml-graphics sfml-window sfml-system)
