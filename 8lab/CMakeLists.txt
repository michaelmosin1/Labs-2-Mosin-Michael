cmake_minimum_required(VERSION 3.15)
project(8lab)
enable_language(CXX)


add_executable(main main.cpp)
add_definitions(-DSFML_STATIC)
target_link_options(main PUBLIC -Llib)
include_directories("include/")
link_directories("lib/")
target_link_libraries(main
sfml-audio-s
sfml-graphics-s
sfml-network-s
sfml-system-s
sfml-window-s
FLAC
freetype
ogg
openal32
vorbis
vorbisenc
vorbisfile
)

