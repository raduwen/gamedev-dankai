project(arkanoid)

file(GLOB_RECURSE SRCS "src/*.cpp")

add_executable(arkanoid ${SRCS})
target_compile_features(arkanoid PRIVATE cxx_std_20)
target_link_libraries(arkanoid PRIVATE ${SFML_LIBRARIES} ${SFML_DEPENDENCIES} ImGui-SFML)
