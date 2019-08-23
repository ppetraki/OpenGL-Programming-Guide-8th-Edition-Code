project('vermilion8',
    'c', 'cpp',
    version : '8.0.0',
    default_options : ['warning_level=3',  'c_std=c11', 'cpp_std=c++11']
    )

cpp_flags = [
   '-O3',
   '-Wall',
   '-Wextra',
   '-Wshadow',
   '-Wnon-virtual-dtor',
   '-Wold-style-cast',
   '-Wcast-align',
   '-Wunused',
   '-Woverloaded-virtual',
   '-Wpedantic',
   '-Wconversion',
   '-Wsign-conversion',
   '-Wmisleading-indentation',
   '-Wduplicated-cond',
   '-Wduplicated-branches',
   '-Wlogical-op',
   '-Wnull-dereference',
   '-Wuseless-cast',
   '-Wdouble-promotion',
   '-Wformat=2'
]

link_flags = ['-flto']

#c = meson.get_compiler('c')
#add_project_arguments(c.get_supported_arguments(cpp_args), language : 'c')
#add_project_link_arguments(c.get_supported_link_arguments(link_flags), language : 'c')

cpp = meson.get_compiler('cpp')
add_project_arguments(cpp.get_supported_arguments(cpp_flags), language : 'cpp')
add_project_link_arguments(cpp.get_supported_link_arguments(link_flags), language : 'cpp')

include_dirs = include_directories('include')

opengl_dep  = dependency('gl')
glfw_dep    = dependency('glfw3')
gl_dep      = dependency('GL')
rt_dep      = cpp.find_library('rt')
dlopen_dep  = cpp.find_library('dl')

common_dep = [opengl_dep, glfw_dep, gl_dep, rt_dep, dlopen_dep]

vermilion_sources = files('''
  lib/targa.cpp
  lib/glew.c
  lib/LoadShaders.cpp'''.split())

vermilion_lib = both_libraries('vermilion',
  vermilion_sources,
  include_directories: include_dirs,
  dependencies: common_dep)
