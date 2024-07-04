#version 330 core

in vec3 color;
in vec2 TexCoords;
out vec4 FragColor;

uniform sampler2D texture1;
    
void main()
{
    FragColor = texture(texture1, TexCoords) * vec4(color, 1.0);
};