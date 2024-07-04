#version 330 core

layout (location = 0) in vec3 aPos;
layout (location = 1) in vec2 aTexCoords;

uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;
uniform vec3 collision_color;

out vec2 TexCoords;
out vec3 color;

void main()
{
   gl_Position = projection * view * model * vec4(aPos, 1.0);
   if (collision_color != 0)
   {
      color = collision_color;
   }
   else
   {
      color = vec3(1.0, 1.0, 1.0);
   }
   TexCoords = aTexCoords;
}