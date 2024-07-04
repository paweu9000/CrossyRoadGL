#include "Enemy.h"
#include "Constants.h"
#include <iostream>
#include <cstdlib>
#include "TextureManager.h"

Enemy::Enemy(Direction direction, int depth)
{
    vertices = Constant::Enemy;
    this->direction = direction;
    this->depth = depth;
    this->ResetPosition();

    this->speedMultiplier = 0.5f + static_cast<float>(rand() / (static_cast<float> (RAND_MAX / (2.0f - 0.5f))));

    glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(float), &vertices.front(), GL_STATIC_DRAW);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)(3*sizeof(float)));
    glEnableVertexAttribArray(1);
    
    textureID = TextureManager::GetTexture("enemy");

    shader = new Shader("src/shaders/vertex.vs", "src/shaders/fragment.fs");
}

void Enemy::Update(float deltaTime)
{
    if (this->model[3][0] > 18.f || this->model[3][0] < -18.f) ResetPosition();
    float movementSpeed = deltaTime * Constant::EnemySpeed * this->speedMultiplier;
    switch (this->direction)
    {
    case Direction::EAST:
        this->model = glm::translate(glm::mat4(1.f), glm::vec3(movementSpeed, 0.f, 0.f)) * model;
        break;
    case Direction::WEST:
        this->model = glm::translate(glm::mat4(1.f), glm::vec3(-movementSpeed, 0.f, 0.f)) * model;
    default:
        break;
    }
}

void Enemy::Draw(glm::mat4 view)
{
    shader->Use();
    shader->SetMat4("model", this->model);
    shader->SetMat4("view", view);
    shader->SetMat4("projection", this->projection);
    
    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D, textureID);

    glBindVertexArray(this->VAO);
    glDrawArrays(GL_TRIANGLES, 0, 36);
}

void Enemy::ResetPosition()
{
    this->model = glm::mat4(1.f);
    if (direction == Direction::EAST) 
    {
        this->model = glm::translate(this->model, ConfigureDepth(Constant::EnemyEVec, depth));
    }
    else
    {
        this->model = glm::translate(this->model, ConfigureDepth(Constant::EnemyWVec, depth));
    }
}

glm::vec3 Enemy::ConfigureDepth(glm::vec3 vec, int depth)
{
    auto new_vec = vec;
    new_vec[2] += Constant::DepthOffset * (depth - 1);
    return new_vec;
}