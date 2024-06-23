#include "enemy.h"
#include "constants.h"

Enemy::Enemy(Direction direction)
{
    vertices = Constant::enemy;
    this->direction = direction;
    this->model = glm::rotate(this->model, glm::radians(-30.f), glm::vec3(1.f, 0.f, 0.f));
    if (direction == Direction::EAST) 
    {
        this->view = glm::translate(this->view, glm::vec3(-15.f, 5.f, -29.f));
    }
    else
    {
        this->view = glm::translate(this->view, glm::vec3(15.f, 2.f, -29.f));
    }

    glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(float), &vertices.front(), GL_STATIC_DRAW);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(3*sizeof(float)));
    glEnableVertexAttribArray(1);

    shader = new Shader("src/shaders/vertex.vs", "src/shaders/fragment.fs");
}

void Enemy::update(float deltaTime)
{
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