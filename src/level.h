#pragma once
#include "shader.h"
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glad/glad.h>
#include <GLFW/glfw3.h>

class Level
{
public:
    Level();
    const float* get_vertices() const;
    void update();
    void draw();
private:
    float vertices[36];
    Shader* shader;
    glm::mat4 projection;
    glm::mat4 model;
    glm::mat4 view;
    unsigned int VAO;
    unsigned int VBO;
};