#include "Player.h"
#include "Shared/Constants.h"
#include <iostream>
#include "TextureManager.h"
#include "Score.h"

Player::Player()
{
    vertices = Constant::Player;
    this->isMoving = false;
    this->movementAngle = 0.f;
    this->direction = Direction::NONE;

    this->model = glm::translate(this->model, glm::vec3(0.f, 0.f, -29.f));

    glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(float), &vertices.front(), GL_STATIC_DRAW);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(3 * sizeof(float)));
    glEnableVertexAttribArray(1);
    glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(6 * sizeof(float)));
    glEnableVertexAttribArray(2);

    shader = std::make_unique<Shader>("src/Assets/Shaders/vertex.vs", "src/Assets/Shaders/fragment.fs");

    shader->Use();
    shader->SetInt("material.diffuse", 1);
    shader->SetInt("material.specular", 1);
    shader->SetInt("spotLight[0].isInitialized", 0);
    shader->SetInt("pointLights[0].isInitialized", 0);
}

void Player::Update(float deltaTime)
{
    if (this->direction == Direction::NONE) return;
    if (this->direction != Direction::NONE && !isMoving)
    {
        // check if following movements will go out of bounds
        if (MoveOutOfBounds()) return;
    }
    this->isMoving = true;
    float movement = deltaTime * Constant::PlayerSpeed;
    if (this->movementAngle + movement > glm::radians(90.f))
    {
        movement = glm::radians(90.f) - movementAngle;
    }
    this->movementAngle += movement;

    switch (this->direction)
    {
    case Direction::NORTH:
        model = glm::rotate(model, movement, glm::vec3(-1.f, 0.0f, 0.0f));
        model = glm::translate(glm::mat4(1.f), glm::vec3(0.f, 0.0f, -movement)) * model;
        break;
    case Direction::SOUTH:
        model = glm::rotate(model, movement, glm::vec3(1.0f, 0.0f, 0.0f));
        model = glm::translate(glm::mat4(1.f), glm::vec3(0.f, 0.0f, movement)) * model;
        break;
    case Direction::EAST:
        model = glm::rotate(model, movement, glm::vec3(0.0f, 0.0f, -1.0f));
        model = glm::translate(glm::mat4(1.f), glm::vec3(movement, 0.f, 0.0f)) * model;
        break;
    case Direction::WEST:
        model = glm::rotate(model, movement, glm::vec3(0.0f, 0.0f, 1.f));
        model = glm::translate(glm::mat4(1.f), glm::vec3(-movement, 0.f, 0.0f)) * model;
        break;
    default:
        break;
    }

    if (this->movementAngle >= glm::radians(90.0f))
    {
        this->isMoving = false;
        this->movementAngle = 0;
        switch (this->direction)
        {
        case Direction::NORTH:
            model = glm::rotate(model, glm::radians(90.f), glm::vec3(1.0f, 0.0f, 0.0f));
            Score::AddScore();
            break;
        case Direction::SOUTH:
            model = glm::rotate(model, glm::radians(-90.f), glm::vec3(1.0f, 0.0f, 0.0f));
            break;
        case Direction::EAST:
            model = glm::rotate(model, glm::radians(90.f), glm::vec3(0.0f, 0.0f, 1.0f));
            break;
        case Direction::WEST:
            model = glm::rotate(model, glm::radians(90.f), glm::vec3(0.0f, 0.0f, -1.0f));
            break;
        default:
            break;
        }
        this->direction = Direction::NONE;
    }
}

void Player::Draw(glm::mat4 view)
{
    glm::vec3 viewPos = glm::vec3(view[3][0], view[3][1], view[3][2]);
    shader->Use();
    SetLightning(viewPos);
    shader->SetMat4("model", this->model);
    shader->SetMat4("view", view);
    shader->SetMat4("projection", this->projection);

    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D, TextureManager::GetTexture("player"));
    glActiveTexture(GL_TEXTURE1);
    glBindTexture(GL_TEXTURE_2D, TextureManager::GetTexture("player_specular"));
    
    glBindVertexArray(this->VAO);
    glDrawArrays(GL_TRIANGLES, 0, 36);
}

bool Player::IsMoving() 
{
    return this->isMoving;
}

void Player::ShowCollision(bool collides)
{
    this->shader->Use();
    if (collides)
    {
        this->shader->SetVec3("collision_color", glm::vec3(1.0f, 0.5f, 0.0f));
    }
    else
    {
        this->shader->SetVec3("collision_color", glm::vec3(0.f, 0.f, 0.f));
    }
}

bool Player::MoveOutOfBounds()
{
    bool outOfBounds = false;
    switch (this->direction)
    {
        case Direction::SOUTH:
            outOfBounds = this->model[3][2] + glm::radians(90.f) > -24.f;
            break;
        case Direction::WEST:
            outOfBounds = this->model[3][0] - glm::radians(90.f) < -18.f;
            break;
        case Direction::EAST:
            outOfBounds = this->model[3][0] + glm::radians(90.f) > 18.f;
            break;
        default:
            break;
    }
    if (outOfBounds) this->direction = Direction::NONE;
    return outOfBounds;
}

void Player::SetLightning(glm::vec3 viewPos)
{
    shader->Use();
    shader->SetVec3("viewPos", viewPos);
    SetDirectionLight();
    SetMaterial(Materials::Player);
}
