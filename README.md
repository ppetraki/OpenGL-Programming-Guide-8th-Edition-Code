# OpenGL-Programming-Guide-8th-Edition-Code

Forked from [https://github.com/Kylewlk/OpenGL-Programming-Guide-8th-Edition-Code](https://github.com/Kylewlk/OpenGL-Programming-Guide-8th-Edition-Code)        

This is a work in progress. Everything is being ported to [meson](http://www.mesonbuild.com).

# Status
Everything current builds, however several executables fail to run because they cannot locate resource files relative to their execution path. A temporary workaround is to copy said files into build/

Missing functions Sleep and GetTickCounts are implemented in a local lib and conditionally compiled into libvermilion

Tested on Ubuntu 16.04 and Ubuntu 18.04

Many of the examples requires a graphics card capable of OpenGL Version 4.3 or higher e.g.

    glxinfo | grep 'OpenGL version'
    OpenGL version string: 4.4.0 NVIDIA 21.5

# Getting started
    pip3 install meson
    # install ninja >= 1.5
    make # drives mesonbuild

# TODO
 * fix relative resource loading for shaders etc
 * cross platform build
 * travis ci
