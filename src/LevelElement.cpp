#include "LevelElement.h"
#include "Constants.h"
#include <iostream>
#include "TextureManager.h"
#include "Lightning.h"

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
        case ObjectType::LAMP:
            vertices = Constant::Lamp;
            this->model = glm::translate(glm::mat4(1.0f),  ConfigureDepth(Constant::LampBaseVec, depth)) * model;
            BindVertices();
        default:
            break;
    }

    if (type != ObjectType::LAMP)
    {
        this->model = glm::rotate(this->model, glm::radians(-90.f), glm::vec3(1.f, 0.f, 0.f));
        shader->Use();
        shader->SetInt("material.diffuse", 1);
        shader->SetInt("material.specular", 1);
        shader->SetInt("spotLight[0].isInitialized", 1);
        shader->SetInt("pointLights[0].isInitialized", 1);
    }
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
            glBindVertexArray(this->VAO);
            glDrawArrays(GL_TRIANGLES, 0, 36);
            break;
        case ObjectType::ROAD:
            glActiveTexture(GL_TEXTURE0);
            glBindTexture(GL_TEXTURE_2D, TextureManager::GetTexture("road"));
            glActiveTexture(GL_TEXTURE1);
            glBindTexture(GL_TEXTURE_2D, TextureManager::GetTexture("road_specular"));
            glBindVertexArray(this->VAO);
            glDrawArrays(GL_TRIANGLES, 0, 36);
            break;
        case ObjectType::LINE:
            glActiveTexture(GL_TEXTURE0);
            glBindTexture(GL_TEXTURE_2D, TextureManager::GetTexture("lines"));
            glActiveTexture(GL_TEXTURE1);
            glBindTexture(GL_TEXTURE_2D, TextureManager::GetTexture("lines_specular"));
            glBindVertexArray(this->VAO);
            glDrawArrays(GL_TRIANGLES, 0, 108);
            break;
        case ObjectType::LAMP:
            glBindVertexArray(this->VAO);
            glDrawArrays(GL_TRIANGLES, 0, 72);
            break;
    }
}

void LevelElement::BindVertices()
{
    if (type == ObjectType::LAMP)
    {
        this->shader = std::make_unique<Shader>("src/Assets/Shaders/lamp_vertex.vs", "src/Assets/Shaders/lamp_fragment.fs");

        glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(float), &vertices.front(), GL_STATIC_DRAW);
        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)0);
        glEnableVertexAttribArray(0);
        glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(3 * sizeof(float)));
        glEnableVertexAttribArray(1);
    }
    else
    {
        this->shader = std::make_unique<Shader>("src/Assets/Shaders/vertex.vs", "src/Assets/Shaders/fragment.fs");

        glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(float), &vertices.front(), GL_STATIC_DRAW);
        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)0);
        glEnableVertexAttribArray(0);
        glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(3 * sizeof(float)));
        glEnableVertexAttribArray(1);
        glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(6 * sizeof(float)));
        glEnableVertexAttribArray(2);
    }
}

void LevelElement::SetLightning(glm::vec3 viewPos)
{
    if (type == ObjectType::LAMP) return;
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

void LevelElement::SetSpotLightning(const std::vector<std::shared_ptr<Entity>> entities)
{
    shader->Use();
    for (int i = 1; i < entities.size(); ++i)
    {
        shader->SetInt("maxSpotLights", entities.size()-1);
        std::string base = "spotLight[" + std::to_string(i - 1) + "]";
        glm::vec3 position;
        if (entities[i]->getDirection() == Direction::EAST) position = glm::vec3(entities[i]->GetModel()[3][0]+0.5f, entities[i]->GetModel()[3][1], entities[i]->GetModel()[3][2]);
        else position = glm::vec3(entities[i]->GetModel()[3][0], entities[i]->GetModel()[3][1], entities[i]->GetModel()[3][2]);
        shader->SetVec3(base + ".position", position);
        shader->SetVec3(base + ".direction", entities[i]->getDirection() == Direction::WEST ? Lightning::West : Lightning::East);
        shader->SetVec3(base + ".ambient", Lightning::SpotAmbient);
        shader->SetVec3(base + ".diffuse", Lightning::SpotDiffuse);
        shader->SetVec3(base + ".specular", Lightning::SpotSpecular);
        shader->SetFloat(base + ".constant", Lightning::Constant);
        shader->SetFloat(base + ".linear", Lightning::Linear);
        shader->SetFloat(base + ".quadratic", Lightning::Quadratic);
        shader->SetFloat(base + ".cutOff", Lightning::SpotCutOff);
        shader->SetFloat(base + ".outerCutOff", Lightning::SpotOuterCutOff); 
    }
}

ObjectType LevelElement::GetType() const
{
    return this->type;
}

void LevelElement::SetPointLight(const std::vector<std::shared_ptr<LevelElement>> lamps)
{
    if (type == ObjectType::LAMP) return;
    shader->Use();
    for (int i = 0; i < lamps.size(); ++i)
    {
        shader->SetInt("maxPointLights", lamps.size());
        std::string base = "pointLights[" + std::to_string(i) + "]";
        auto position = glm::vec3(lamps[i]->model[3][0]+2.f, lamps[i]->model[3][1]+2.f, lamps[i]->model[3][2]-2.f);
        shader->SetVec3(base + ".position", position);
        shader->SetVec3(base + ".ambient", Lightning::PointAmbient);
        shader->SetVec3(base + ".diffuse", Lightning::PointDiffuse);
        shader->SetVec3(base + ".specular", Lightning::PointSpecular);
        shader->SetFloat(base + ".constant", Lightning::Constant);
        shader->SetFloat(base + ".linear", Lightning::Linear);
        shader->SetFloat(base + ".quadratic", Lightning::Quadratic);
    }
}