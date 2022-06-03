if(APPLE)
set(SFML_DIR /usr/local)
elseif(WIN32)
set(SFML_DIR $ENV{OPT_PATH})
endif()

set(IMGUI_DIR ${dankai_SOURCE_DIR}/vendor/imgui)

set(BUILD_SHARED_LIBS ON)
add_subdirectory(imgui-sfml)
