#include "Element.h"
#include "Constants.h"

Element::Element()
{
    this->projection = glm::mat4(1.f);
    this->model = glm::mat4(1.f);
    this->projection = glm::perspective(glm::radians(45.f), 1280.f/720.f, 0.1f, 100.f);
    
    glGenVertexArrays(1, &this->VAO);
    glGenBuffers(1, &this->VBO);
    glBindVertexArray(VAO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
}

void Element::Draw(glm::mat4 view){}

glm::vec3 Element::ConfigureDepth(glm::vec3 vec, int depth)
{
    auto new_vec = vec;
    new_vec[2] += (Constant::DepthOffset * depth);
    return new_vec;
}

float Element::GetDepth()
{
    return this->model[3][2];
}
