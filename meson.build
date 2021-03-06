project('vermilion8',
    'c', 'cpp',
    version : '8.0.0',
    #    default_options : ['warning_level=3',  'c_std=c11', 'cpp_std=c++11']
        default_options : ['c_std=c11', 'cpp_std=c++11']
    )

# XXX detect OS
add_global_arguments('-D_LINUX',language : 'c')
add_global_arguments('-D_LINUX',language : 'cpp')

cc_flags   = []
cpp_flags  = [] #['-Wfatal-errors']
link_flags = []

cc = meson.get_compiler('c')
add_project_arguments(cc.get_supported_arguments(cc_flags), language : 'c')
add_project_link_arguments(cc.get_supported_link_arguments(link_flags), language : 'c')

cpp = meson.get_compiler('cpp')
add_project_arguments(cpp.get_supported_arguments(cpp_flags), language : 'cpp')
add_project_link_arguments(cpp.get_supported_link_arguments(link_flags), language : 'cpp')

opengl_dep  = dependency('gl')
glfw_dep    = dependency('glfw3')
glut_dep    = cpp.find_library('glut')
rt_dep      = cpp.find_library('rt')
dlopen_dep  = cpp.find_library('dl')

common_dep = [opengl_dep, glfw_dep, glut_dep, rt_dep, dlopen_dep]

linuxcompat_lib = static_library('linux_compat',
  ['linuxcompat/gettickcount.cpp', 'linuxcompat/sleep.cpp',],
  include_directories: include_directories('linuxcompat/include')
  )

linuxcompat_dep = declare_dependency(
  link_with: linuxcompat_lib,
  include_directories: include_directories('linuxcompat/include')
  )

vermilion_lib = static_library('vermilion',
  '''
  lib/vbm.cpp
  lib/targa.cpp
  lib/glew.c
  lib/LoadShaders.cpp
  vermilion/vermilion/vdds.cpp
  vermilion/vermilion/loadtexture.cpp
  '''.split(),
  dependencies: [linuxcompat_dep, common_dep],
  include_directories: include_directories('include'),
  )

vermilion_dep = declare_dependency(
  link_with: vermilion_lib,
  dependencies: [linuxcompat_dep],
  include_directories: include_directories('include'),
  )

example_sources = [
'Chapter01-OG/Triangle/Triangle.cpp',
'Chapter02-OG/UniformBlock/main.cpp',
'Chapter03-OG/3.4_DrawIndirect/DrawIndirect.cpp',
'Chapter03-OG/3.5_EasyMultiInstancing/MultiDraw.cpp',
'Chapter03-OG/ch03_drawcommands/ch03_drawcommands.cpp',
'Chapter03-OG/MultiBuffer/MultiBuffer.cpp',
'Chapter03-OG/ch03_pointsprites/ch03_pointsprites.cpp',
'Chapter03-OG/ch03_primitive_restart/ch03_primitive_restart.cpp',
'Chapter04-OG/4.5.11 LogicOpTest/LogicOpTest.cpp',
'Chapter04-OG/4.5.12 QueryTest/4.5.12QueryTest.cpp',
'Chapter04-OG/4.5.13 ConditinalRender/4.5.13ConditinalRender.cpp',
'Chapter04-OG/4.5.4 StencilTest/StencilTest.cpp',
'Chapter04-OG/4.5.5 DepthTest/DepthTest.cpp',
'Chapter04-OG/4.5.6 BlendTest/BlendTest.cpp',
'Chapter04-OG/4.6 Smooth/4.6Smooth.cpp',
'Chapter04-OG/4.7 FrameBuffer/4.7FrameBuffer.cpp',
'Chapter04-OG/gouraud-float/gouraud-float.cpp',
'Chapter04-OG/Gouraud/gouraud.cpp',
'Chapter04-OG/VertexColor/VertexColor.cpp',
'Chapter05-OG/5.3.1ClipDistance/5.3.1ClipDistance.cpp',
'Chapter05-OG/5.4TransformFeedback2/5.4TransformFeedback2.cpp',
'Chapter05-OG/5.4TransformFeedback/5.4TransformFeedback.cpp',
'Chapter06-OG/6.13PointSprite/PointSprite.cpp',
'Chapter06-OG/6.14FrameTex/FrameTex.cpp',
'Chapter06-OG/6.5SetTexData/6.5SetTexData.cpp',
'Chapter06-OG/6.6Sampler/Sampler.cpp',
'Chapter06-OG/6.9TextureView/TextureView.cpp',
'Chapter06-OG/ch06_cube_map/ch06_cube_map.cpp',
'Chapter06-OG/ch06_load_texture/ch06_load_texture.cpp',
'Chapter06-OG/ch06_mip_filters/ch06_mip_filters.cpp',
'Chapter06-OG/ch06_mipmap/ch06_mipmap.cpp',
'Chapter06-OG/ch06_multi_texture/ch06_multi_texture.cpp',
'Chapter06-OG/ch06_pointsprites/ch06_pointsprites.cpp',
'Chapter06-OG/ch06_static_texture/ch06_static_texture.cpp',
'Chapter06-OG/ch06_texture_wrapping/ch06_texture_wrapping.cpp',
'Chapter06-OG/ch06_volume_texture/ch06_volume_texture.cpp',
'Chapter07-OG/7.2-1ambient/7.2ambient.cpp',
'Chapter07-OG/7.2-2LightDirectionDiffuse/7.2LightDirectionDiffuse.cpp',
'Chapter07-OG/7.2.2VertexLight/7.2.2VertexLight.cpp',
'Chapter07-OG/7.2-3LightDirectionSpecular/7.2LightDirectionSpecular.cpp',
'Chapter07-OG/7.2-4LightPoint/7.2LightPoint.cpp',
'Chapter07-OG/7.2-5LightSpot/7.2LightSpot.cpp',
'Chapter07-OG/7.3.1HemisphereLight/7.3.1HemisphereLight.cpp',
'Chapter07-OG/7.4Shadow/7.4Shadow.cpp',
'Chapter07-OG/7.4Shadow-test01/test.cpp',
'Chapter07-OG/7.4Shadow-test02-LightTexMap/7.4Shadow-LightTexMap.cpp',
'Chapter07-OG/7.4Shadow-test03-LightDepthTex/test.cpp',
'Chapter07-OG/7.4Shadow-test04-NoTextureporj/7.4Shadow.cpp',
'Chapter08-OG/8.1.1BrickColor-Ball/BrickTex.cpp',
'Chapter08-OG/8.1.1BrickColor/BrickSquare.cpp',
'Chapter08-OG/8.1.1Stripe/stripeTex.cpp',
'Chapter08-OG/8.1.2StartBall/SartBall.cpp',
'Chapter08-OG/8.1.2TriangleBall/TriangleBall.cpp',
'Chapter08-OG/8.1.3Lattice/Lattice.cpp',
'Chapter08-OG/8.2-02Bump-tours/Bump.cpp',
'Chapter08-OG/8.2Bump/Bump.cpp',
'Chapter08-OG/8.3.4-01StripesBall/StripesBall.cpp',
'Chapter08-OG/8.3.4-02Test_dFdx_dFdy/test_dFdx_dFdy.cpp',
'Chapter08-OG/8.3.4-03BrickConvolution/8.3.4BrickConvolution.cpp',
'Chapter08-OG/8.3.5-02BallCheckerboard/8.3.5BallCheckerboard.cpp',
'Chapter08-OG/8.3.5Checkerboard/8.3.5Checkerboard.cpp',
'Chapter08-OG/8.4-01Noise1/8.4Noise1.cpp',
'Chapter08-OG/8.4.4NoiseCloudy-01/8.4.4NoiseCloudy.cpp',
'Chapter08-OG/8.4.5-01Turbulence/Turbulence.cpp',
'Chapter08-OG/8.4.5-02SimpleFire/SimpleFire.cpp',
'Chapter08-OG/ch08_lightmodels/ch08_lightmodels.cpp',
'Chapter09-OG/9.5-01quads/quad.cpp',
'Chapter09-OG/9.5-02Line/line.cpp',
'Chapter09-OG/9.5Triangel/Triangle.cpp',
'Chapter09-OG/Simple/simple.cpp',
'Chapter09-OG/teapot/teapot.cpp',
'Chapter10-OG/10.3.1-01Tetrahedron/Tetrahedron.cpp',
'Chapter10-OG/10.4-01TransformFeedback/TransformTriangle.cpp',
'Chapter11-OG/11.1-01ImageTex/ImageTex.cpp',
'Chapter11-OG/11.2-01BufferObject/BufferObject.cpp',
'Chapter11-OG/ch11_doublewrite/ch11_doublewrite.cpp',
'Chapter11-OG/ch11_OIT/ch11_OIT.cpp',
'Chapter11-OG/ch11_overdrawcount/ch11_overdrawcount.cpp',
'Chapter12-OG/ch12_imageprocessing/ch12_imageprocessing.cpp',
'Chapter12-OG/ch12_particlesimulator/ch12_particlesimulator.cpp',
'Chapter12-OG/ch12_simplecompute/ch12_simplecompute.cpp',
'Chapter12-OG/particleBall/particleBall.cpp',
'Chapter12-OG/ParticleTest1/particleBall.cpp'
]

foreach example_file: example_sources
  # mangle a unique target by combining the filename and it's parent directory with '-'
  dir_name = (example_file.split('/')[-2])
  executable_name = dir_name + '-' + (example_file.split('/')[-1]).split('.')[0]
  executable(executable_name,
    example_file,
    dependencies: [common_dep, vermilion_dep]
    )
endforeach

# these examples insist on using their own vbm class
custom_vbm_sources = [
  [
    'Chapter03-OG/ch03_instancing/ch03_instancing.cpp',
    'Chapter03-OG/ch03_instancing/vbm.cpp',
  ],
  [
    'Chapter03-OG/ch03_instancing2/ch03_instancing2.cpp',
    'Chapter03-OG/ch03_instancing2/vbm.cpp'
  ],
  [
    'Chapter03-OG/ch03_instancing3/ch03_instancing3.cpp',
    'Chapter03-OG/ch03_instancing3/vbm.cpp',
  ],
  [
    'Chapter03-OG/ch03_xfb/ch03_xfb.cpp',
    'Chapter03-OG/ch03_xfb/vbm.cpp',
  ],
  [
    'Chapter04-OG/ch04_shadowmap/ch04_shadowmap.cpp',
    'Chapter04-OG/ch04_shadowmap/vbm.cpp',
  ],
  [
    'Chapter05-OG/ch05_xfb/ch05_xfb.cpp',
    'Chapter05-OG/ch05_xfb/vbm.cpp',
  ],
  [
    'Chapter07-OG/ch07_shadowmap/ch07_shadowmap.cpp',
    'Chapter07-OG/ch07_shadowmap/vbm.cpp',
  ],
  [
    'Chapter10-OG/10.6-01FourViewport/FourViewport.cpp',
    'Chapter10-OG/10.6-01FourViewport/vbm.cpp',
  ],
  [
    'Chapter10-OG/10.6.2LayerRender/LayerRender.cpp',
    'Chapter10-OG/10.6.2LayerRender/vbm.cpp',
  ],
  [
    'Chapter10-OG/ch10_draw_xfb/ch10_draw_xfb.cpp',
    'Chapter10-OG/ch10_draw_xfb/vbm.cpp',
  ],
  [
    'Chapter10-OG/ch10_fur/ch10_fur.cpp',
    'Chapter10-OG/ch10_fur/vbm.cpp',
  ],
  [
    'Chapter10-OG/ch10_viewport_array/ch10_viewport_array.cpp',
    'Chapter10-OG/ch10_viewport_array/vbm.cpp',
  ]
]

foreach custom_vbm_project: custom_vbm_sources
  # mangle a unique target by combining the filename and it's parent directory with '-'
  example_file = custom_vbm_project[0]
  dir_name = (example_file.split('/')[-2])
  executable_name = dir_name + '-' + (example_file.split('/')[-1]).split('.')[0]
  executable(executable_name,
    custom_vbm_project,
    dependencies: [common_dep, vermilion_dep]
    )
endforeach

testvbm_sources = [
  ['TestVBM/teapot/teapot.cpp'],

  [
  'TestVBM/TestVBM/TestVBM.cpp',
  'TestVBM/TestVBM/vbm.h',
  'TestVBM/TestVBM/vbm.cpp'
  ],

  ['TestVBM/TestVBM2/TestVBM2.cpp'],

  ['TestVBM/VBMTexture/TestVBM2.cpp'],

  [
    'TestVBM/VBM1Texture/VBM1Texture.cpp',
    'TestVBM/VBM1Texture/vbm.h',
    'TestVBM/VBM1Texture/vbm.cpp'
  ]
]

foreach custom_vbm_project: testvbm_sources
  # mangle a unique target by combining the filename and it's parent directory with '-'
  example_file = custom_vbm_project[0]
  dir_name = (example_file.split('/')[-2])
  root_name = (example_file.split('/')[-3])
  executable_name = root_name + '-' + dir_name + '-' + (example_file.split('/')[-1]).split('.')[0]
  executable(executable_name,
    custom_vbm_project,
    dependencies: [common_dep, vermilion_dep]
    )
endforeach
