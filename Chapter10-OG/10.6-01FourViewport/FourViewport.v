#version 430 core

uniform mat4 model_matrix;

layout (location = 0) in vec4 position;
layout (location = 1) in vec3 normal;

out vec3 vs_gs_normal;

void main(void)
{
    vec4 pos = (model_matrix * (position * vec4(1.0, 1.0, 1.0, 1.0)));
    vs_gs_normal = normalize((model_matrix * vec4(normal, 0.0)).xyz);
    gl_Position = pos;
}
