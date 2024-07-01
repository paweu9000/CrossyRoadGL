#pragma once
#include "Shader.h"
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <vector>

class Element
{
public:
    Element();
    virtual void Draw(glm::mat4 view);
    float GetDepth();
protected:
    virtual glm::vec3 ConfigureDepth(glm::vec3 vec, int depth);
    std::vector<float> vertices;
    Shader* shader;
    unsigned int VBO, VAO;
    glm::mat4 projection;
    glm::mat4 model;
};