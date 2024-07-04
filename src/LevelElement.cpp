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

    shader->Use();
    shader->SetInt("material.diffuse", 0);
    shader->SetInt("material.specular", 1);
}

void LevelElement::Update()
{
    
}

void LevelElement::Draw(glm::mat4 view)
{
    glm::vec3 viewPos = glm::vec3(view[3][0], view[3][1], view[3][2]);
    shader->Use();
    SetLightning(viewPos);
    shader->SetMat4("model", this->model);
    shader->SetMat4("view", view);
    shader->SetMat4("projection", this->projection);
    switch (type)
    {
        case ObjectType::GRASS:
            glActiveTexture(GL_TEXTURE0);
            glBindTexture(GL_TEXTURE_2D, TextureManager::GetTexture("grass"));
            glActiveTexture(GL_TEXTURE1);
            glBindTexture(GL_TEXTURE_2D, TextureManager::GetTexture("grass_specular"));
            break;
        case ObjectType::ROAD:
            glActiveTexture(GL_TEXTURE0);
            glBindTexture(GL_TEXTURE_2D, TextureManager::GetTexture("road"));
            glActiveTexture(GL_TEXTURE1);
            glBindTexture(GL_TEXTURE_2D, TextureManager::GetTexture("road_specular"));
            break;
        case ObjectType::LINE:
            glActiveTexture(GL_TEXTURE0);
            glBindTexture(GL_TEXTURE_2D, TextureManager::GetTexture("lines"));
            glActiveTexture(GL_TEXTURE1);
            glBindTexture(GL_TEXTURE_2D, TextureManager::GetTexture("lines_specular"));
            break;
    }
    glBindVertexArray(this->VAO);
    glDrawArrays(GL_TRIANGLES, 0, type == ObjectType::LINE ? 108 : 36);
}

void LevelElement::BindVertices()
{
    this->shader = new Shader("src/shaders/vertex.vs", "src/shaders/fragment.fs");

    glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(float), &vertices.front(), GL_STATIC_DRAW);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(3 * sizeof(float)));
    glEnableVertexAttribArray(1);
    glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(6 * sizeof(float)));
    glEnableVertexAttribArray(2);
}

void LevelElement::SetLightning(glm::vec3 viewPos)
{
    shader->Use();
    shader->SetVec3("viewPos", viewPos);
    SetDirectionLight();
    switch (type)
    {
        case ObjectType::GRASS:
            SetMaterial(Materials::Grass);
            break;
        case ObjectType::LINE:
            SetMaterial(Materials::Lines);
            break;
        case ObjectType::ROAD:
            SetMaterial(Materials::Road);
            break;
        default:
            break;
    }
}