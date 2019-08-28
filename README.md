# OpenGL-Programming-Guide-8th-Edition-Code

Forked from [https://github.com/Kylewlk/OpenGL-Programming-Guide-8th-Edition-Code](https://github.com/Kylewlk/OpenGL-Programming-Guide-8th-Edition-Code)        

This is a work in progress. Everything is being ported to mesonbuild. Everything current builds, however several executables fail to run because they cannot locate resource files relative to their execution path.


Missing functions Sleep and GetTickCounts are implemented in a local lib and conditionally compiled into libvermilion ifndef _WIN32

# Getting started
    pip3 install meson
    make # drives mesonbuild

# TODO
 * fix relative resource loading for shaders etc
 * cross platform build
 * travis ci