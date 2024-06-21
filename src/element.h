#pragma once
#include "shader.h"
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <vector>

class Element
{
public:
    Element();
    virtual void draw();
protected:
    std::vector<float> vertices;
    Shader* shader;
    unsigned int VBO, VAO;
    glm::mat4 projection;
    glm::mat4 model;
    glm::mat4 view;
};