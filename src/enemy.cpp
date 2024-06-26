#include "enemy.h"
#include "constants.h"
#include <iostream>

Enemy::Enemy(Direction direction)
{
    vertices = Constant::enemy;
    this->direction = direction;
    
    this->reset_position();

    glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(float), &vertices.front(), GL_STATIC_DRAW);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(3*sizeof(float)));
    glEnableVertexAttribArray(1);

    shader = new Shader("src/shaders/vertex.vs", "src/shaders/fragment.fs");
}

void Enemy::update(float deltaTime)
{
    if (this->model[3][0] > 18.f || this->model[3][0] < -18.f) reset_position();
    float movement_speed = deltaTime * Constant::enemy_speed;
    switch (this->direction)
    {
    case Direction::EAST:
        this->model = glm::translate(glm::mat4(1.f), glm::vec3(movement_speed, 0.f, 0.f)) * model;
        break;
    case Direction::WEST:
        this->model = glm::translate(glm::mat4(1.f), glm::vec3(-movement_speed, 0.f, 0.f)) * model;
    default:
        break;
    }
}

void Enemy::draw(glm::mat4 view)
{
    shader->use();
    shader->set_mat4("model", this->model);
    shader->set_mat4("view", view);
    shader->set_mat4("projection", this->projection);
    
    glBindVertexArray(this->VAO);
    glDrawArrays(GL_TRIANGLES, 0, 72);
}

void Enemy::reset_position()
{
    this->model = glm::mat4(1.f);
    if (direction == Direction::EAST) 
    {
        this->model = glm::translate(this->model, glm::vec3(-18.f, 0.f, -41.f));
    }
    else
    {
        this->model = glm::translate(this->model, glm::vec3(18.f, 0.f, -36.f));
    }
}