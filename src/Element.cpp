#include "Element.h"
#include "Shared/Constants.h"

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

void Element::SetMaterial(Material material)
{
    shader->Use();
    shader->SetInt("material.diffuse", material.diffuse);
    shader->SetInt("material.specular", material.specular);
    shader->SetFloat("material.shininess", material.shininess);
}

void Element::SetDirectionLight()
{
    shader->Use();
    shader->SetVec3("dirLight.direction", glm::vec3(-0.2f, -1.0f, -0.3f));
    shader->SetVec3("dirLight.ambient", glm::vec3(0.05f, 0.05f, 0.05f));
    shader->SetVec3("dirLight.diffuse", glm::vec3(0.4f, 0.4f, 0.4f));
    shader->SetVec3("dirLight.specular", glm::vec3(0.5f, 0.5f, 0.5f));
}
