#include "player.h"
#include "constants.h"

Player::Player()
{
    vertices = Constant::player;
    this->isMoving = false;
    this->movementAngle = 0.f;
    this->direction = Direction::NONE;

    this->model = glm::rotate(this->model, glm::radians(-30.f), glm::vec3(1.f, 0.f, 0.f));
    this->view = glm::translate(this->view, glm::vec3(0.f, -5.f, -29.f));

    glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(float), &vertices.front(), GL_STATIC_DRAW);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(3*sizeof(float)));
    glEnableVertexAttribArray(1);

    shader = new Shader("src/shaders/vertex.vs", "src/shaders/fragment.fs");
}

void Player::update(float deltaTime)
{
    if (this->direction == Direction::NONE) return;

    this->isMoving = true;
    float movement = deltaTime * 3;
    if (this->movementAngle + movement > 90.f)
    {
        movement = 90.f - movementAngle;
    }
    this->movementAngle += movement;

    switch (this->direction)
    {
    case Direction::NORTH:
        model = glm::rotate(model, movement, glm::vec3(-1.0f, 0.0f, 0.0f));
        view = glm::translate(glm::mat4(1.f), glm::vec3(0.f, movement, 0.0f)) * view;
        break;
    case Direction::SOUTH:
        model = glm::rotate(model, movement, glm::vec3(1.0f, 0.0f, 0.0f));
        view = glm::translate(glm::mat4(1.f), glm::vec3(0.f, -movement, 0.0f)) * view;
        break;
    case Direction::EAST:
        model = glm::rotate(model, movement, glm::vec3(0.0f, 1.0f, 0.0f));
        view = glm::translate(glm::mat4(1.f), glm::vec3(movement, 0.f, 0.f)) * view;
        break;
    case Direction::WEST:
        model = glm::rotate(model, movement, glm::vec3(0.0f, -1.0f, 0.f));
        view = glm::translate(glm::mat4(1.f), glm::vec3(-movement, 0.f, 0.f)) * view;
        break;
    default:
        break;
    }

    if (this->movementAngle >= glm::radians(90.0f))
    {
        this->isMoving = false;
        this->movementAngle = 0;
        this->model = glm::mat4(1.f);
        this->model = glm::rotate(this->model, glm::radians(-30.f), glm::vec3(1.f, 0.f, 0.f));
        this->direction = Direction::NONE;
    }
}

void Player::draw()
{
    shader->use();
    shader->set_mat4("model", this->model);
    shader->set_mat4("view", this->view);
    shader->set_mat4("projection", this->projection);
    
    glBindVertexArray(this->VAO);
    glDrawArrays(GL_TRIANGLES, 0, 72);
}

bool Player::is_moving() 
{
    return this->isMoving;
}