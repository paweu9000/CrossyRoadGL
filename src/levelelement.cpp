#include "LevelElement.h"
#include "Constants.h"
#include <iostream>

LevelElement::LevelElement(ObjectType type, int depth)
{
    this->type = type;
    this->inBounds = true;

    switch (type) {
        case ObjectType::GRASS:
            vertices = Constant::Grass;
            this->model = glm::translate(this->model, ConfigureDepth(Constant::GrassBaseVec, depth)) * model;
            BindVertices();
            break;
        case ObjectType::LINE:
            vertices = Constant::Lines;
            this->model = glm::translate(glm::mat4(1.0f),  ConfigureDepth(Constant::LineBaseVec, depth)) * model;
            BindVertices();
            break;
        case ObjectType::ROAD:
            vertices = Constant::Road;
            this->model = glm::translate(glm::mat4(1.0f),  ConfigureDepth(Constant::RoadBaseVec, depth)) * model;
            BindVertices();
            break;
        default:
            break;
    }
    this->model = glm::rotate(this->model, glm::radians(-90.f), glm::vec3(1.f, 0.f, 0.f));
}

void LevelElement::Update()
{
    
}

void LevelElement::Draw(glm::mat4 view)
{
    shader->Use();
    shader->Use();
    shader->SetMat4("model", this->model);
    shader->SetMat4("view", view);
    shader->SetMat4("projection", this->projection);
    auto color = cos(glfwGetTime());
    shader->SetFloat("colorChange", color < 0.8f ? 0.8f : color);
    glBindVertexArray(this->VAO);
    glDrawArrays(GL_TRIANGLES, 0, vertices.size() / 6);
}

void LevelElement::BindVertices()
{
    this->shader = new Shader("src/shaders/level_vertex.vs", "src/shaders/level_fragment.fs");

    glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(float), &vertices.front(), GL_STATIC_DRAW);
    glVertexAttribPointer(10, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(10);
    glVertexAttribPointer(11, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(3*sizeof(float)));
    glEnableVertexAttribArray(11);
}