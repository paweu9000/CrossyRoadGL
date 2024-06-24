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
    if (this->view[3][0] > 24.f || this->view[3][0] < -24.f) reset_position();
    float movement_speed = deltaTime * 4;
    switch (this->direction)
    {
    case Direction::EAST:
        this->view = glm::translate(glm::mat4(1.f), glm::vec3(movement_speed, 0.f, 0.f)) * view;
        break;
    case Direction::WEST:
        this->view = glm::translate(glm::mat4(1.f), glm::vec3(-movement_speed, 0.f, 0.f)) * view;
    default:
        break;
    }
}

void Enemy::draw()
{
    shader->use();
    shader->set_mat4("model", this->model);
    shader->set_mat4("view", this->view);
    shader->set_mat4("projection", this->projection);
    
    glBindVertexArray(this->VAO);
    glDrawArrays(GL_TRIANGLES, 0, 72);
}

void Enemy::reset_position()
{
    this->model = glm::mat4(1.f);
    this->model = glm::rotate(this->model, glm::radians(-30.f), glm::vec3(1.f, 0.f, 0.f));
    this->view = glm::mat4(1.f);
    if (direction == Direction::EAST) 
    {
        this->view = glm::translate(this->view, glm::vec3(-15.f, 5.f, -29.f));
    }
    else
    {
        this->view = glm::translate(this->view, glm::vec3(15.f, 2.f, -29.f));
    }
}