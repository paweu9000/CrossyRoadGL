#include "enemy.h"
#include "constants.h"
#include <iostream>
#include <cstdlib>

Enemy::Enemy(Direction direction, int depth)
{
    vertices = Constant::enemy;
    this->direction = direction;
    this->depth = depth;
    this->reset_position();

    this->speed_multiplier = 0.5f + static_cast<float>(rand() / (static_cast<float> (RAND_MAX / (2.0f - 0.5f))));

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
    float movement_speed = deltaTime * Constant::enemy_speed * this->speed_multiplier;
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
        this->model = glm::translate(this->model, configure_depth(Constant::enemy_e_vec, depth));
    }
    else
    {
        this->model = glm::translate(this->model, configure_depth(Constant::enemy_w_vec, depth));
    }
}

glm::vec3 Enemy::configure_depth(glm::vec3 vec, int depth)
{
    auto new_vec = vec;
    new_vec[2] += Constant::depth_offset * (depth - 1);
    return new_vec;
}