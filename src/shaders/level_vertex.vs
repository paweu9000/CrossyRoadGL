#version 330 core

layout (location = 10) in vec3 aPos;
layout (location = 11) in vec3 aColor;

uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;
uniform float colorChange;

out vec3 color;

void main()
{
    gl_Position = projection * view * model * vec4(aPos, 1.f);
    color = colorChange * aColor;
}