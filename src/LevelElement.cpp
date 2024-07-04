#include "LevelElement.h"
#include "Constants.h"
#include <iostream>
#include "TextureManager.h"

LevelElement::LevelElement(ObjectType type, int depth)
{
    this->type = type;
    this->inBounds = true;

    switch (type) {
        case ObjectType::GRASS:
            vertices = Constant::Grass;
            this->model = glm::translate(this->model, ConfigureDepth(Constant::GrassBaseVec, depth)) * model;
            BindVertices();
            this->textureID = TextureManager::GetTexture("grass");
            break;
        case ObjectType::LINE:
            vertices = Constant::Lines;
            this->model = glm::translate(glm::mat4(1.0f),  ConfigureDepth(Constant::LineBaseVec, depth)) * model;
            BindVertices();
            this->textureID = TextureManager::GetTexture("lines");
            break;
        case ObjectType::ROAD:
            vertices = Constant::Road;
            this->model = glm::translate(glm::mat4(1.0f),  ConfigureDepth(Constant::RoadBaseVec, depth)) * model;
            BindVertices();
            this->textureID = TextureManager::GetTexture("road");
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
    shader->SetMat4("model", this->model);
    shader->SetMat4("view", view);
    shader->SetMat4("projection", this->projection);
    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D, textureID);
    glBindVertexArray(this->VAO);
    glDrawArrays(GL_TRIANGLES, 0, type == ObjectType::LINE ? 108 : 36);
}

void LevelElement::BindVertices()
{
    this->shader = new Shader("src/shaders/vertex.vs", "src/shaders/fragment.fs");

    glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(float), &vertices.front(), GL_STATIC_DRAW);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)(3*sizeof(float)));
    glEnableVertexAttribArray(1);
}