#include "entity.h"

Entity::Entity()
{
    vertices = {
    // Triangles         // Colors
    -0.5f, -0.5f, -0.5f, 1.f, 0.f, 0.f,
     0.5f, -0.5f, -0.5f, 1.f, 0.f, 0.f,
     0.5f,  0.5f, -0.5f, 1.f, 0.f, 0.f,
     0.5f,  0.5f, -0.5f, 1.f, 0.f, 0.f,
    -0.5f,  0.5f, -0.5f, 1.f, 0.f, 0.f,
    -0.5f, -0.5f, -0.5f, 1.f, 0.f, 0.f,

    -0.5f, -0.5f,  0.5f, 1.f, 0.1f, 0.f,
     0.5f, -0.5f,  0.5f, 1.f, 0.1f, 0.f,
     0.5f,  0.5f,  0.5f, 1.f, 0.1f, 0.f,
     0.5f,  0.5f,  0.5f, 1.f, 0.1f, 0.f,
    -0.5f,  0.5f,  0.5f, 1.f, 0.1f, 0.f,
    -0.5f, -0.5f,  0.5f, 1.f, 0.1f, 0.f,

    -0.5f,  0.5f,  0.5f, 1.f, 0.1f, 0.1f,
    -0.5f,  0.5f, -0.5f, 1.f, 0.1f, 0.1f,
    -0.5f, -0.5f, -0.5f, 1.f, 0.1f, 0.1f,
    -0.5f, -0.5f, -0.5f, 1.f, 0.1f, 0.1f,
    -0.5f, -0.5f,  0.5f, 1.f, 0.1f, 0.1f,
    -0.5f,  0.5f,  0.5f, 1.f, 0.1f, 0.1f,

     0.5f,  0.5f,  0.5f, 1.f, 0.2f, 0.2f,
     0.5f,  0.5f, -0.5f, 1.f, 0.2f, 0.2f,
     0.5f, -0.5f, -0.5f, 1.f, 0.2f, 0.2f,
     0.5f, -0.5f, -0.5f, 1.f, 0.2f, 0.2f,
     0.5f, -0.5f,  0.5f, 1.f, 0.2f, 0.2f,
     0.5f,  0.5f,  0.5f, 1.f, 0.2f, 0.2f,

    -0.5f, -0.5f, -0.5f, 1.f, 0.3f, 0.1f,
     0.5f, -0.5f, -0.5f, 1.f, 0.3f, 0.1f,
     0.5f, -0.5f,  0.5f, 1.f, 0.3f, 0.1f,
     0.5f, -0.5f,  0.5f, 1.f, 0.3f, 0.1f,
    -0.5f, -0.5f,  0.5f, 1.f, 0.3f, 0.1f,
    -0.5f, -0.5f, -0.5f, 1.f, 0.3f, 0.1f,

    -0.5f,  0.5f, -0.5f, 1.f, 0.3f, 0.3f,
     0.5f,  0.5f, -0.5f, 1.f, 0.3f, 0.3f,
     0.5f,  0.5f,  0.5f, 1.f, 0.3f, 0.3f,
     0.5f,  0.5f,  0.5f, 1.f, 0.3f, 0.3f,
    -0.5f,  0.5f,  0.5f, 1.f, 0.3f, 0.3f,
    -0.5f,  0.5f, -0.5f, 1.f, 0.3f, 0.3f
    };
    this->isMoving = false;
    this->movementAngle = 0.f;
    this->direction = Direction::NONE;

    this->projection = glm::mat4(1.f);
    this->model = glm::mat4(1.f);
    this->view = glm::mat4(1.f);
    this->projection = glm::perspective(glm::radians(45.f), (float)1280/(float)720, 0.1f, 100.f);
    this->model = glm::rotate(model, glm::radians(-90.f), glm::vec3(1.f, 0.f, 0.f));
    this->view = glm::translate(view, glm::vec3(0.f, 0.f, -10.f));

    glGenVertexArrays(1, &this->VAO);
    glGenBuffers(1, &this->VBO);
    glBindVertexArray(VAO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(float), &vertices.front(), GL_STATIC_DRAW);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(3*sizeof(float)));
    glEnableVertexAttribArray(1);

    shader = new Shader("src/shaders/vertex.vs", "src/shaders/fragment.fs");
}

void Entity::update(float deltaTime)
{
    if (this->direction == Direction::NONE) return;

    this->isMoving = true;
    this->movementAngle += deltaTime * 3;

    switch (this->direction)
    {
    case Direction::NORTH:
        model = glm::rotate(model, deltaTime*3, glm::vec3(-1.0f, 0.0f, 0.0f));
        view = glm::translate(view, glm::vec3(0.f, deltaTime*3, 0.0f));
        break;
    case Direction::SOUTH:
        model = glm::rotate(model, deltaTime*3, glm::vec3(1.0f, 0.0f, 0.0f));
        view = glm::translate(view, glm::vec3(0.f, -deltaTime*3, 0.0f));
        break;
    case Direction::EAST:
        model = glm::rotate(model, deltaTime*3, glm::vec3(0.0f, 1.0f, 0.0f));
        view = glm::translate(view, glm::vec3(deltaTime*3, 0.f, 0.f));
        break;
    case Direction::WEST:
        model = glm::rotate(model, deltaTime*3, glm::vec3(0.0f, -1.0f, 0.f));
        view = glm::translate(view, glm::vec3(-deltaTime*3, 0.f, 0.f));
        break;
    default:
        break;
    }

    if (this->movementAngle >= glm::radians(90.0f))
    {
        this->isMoving = false;
        this->movementAngle = 0;
        this->direction = Direction::NONE;
    }
}

void Entity::draw()
{
    shader->use();
    shader->set_mat4("model", this->model);
    shader->set_mat4("view", this->view);
    shader->set_mat4("projection", this->projection);
    
    glBindVertexArray(this->VAO);
    glDrawArrays(GL_TRIANGLES, 0, 36);
}

void Entity::set_direction(Direction direction)
{
    this->direction = direction;
}

void Entity::reset_direction()
{
    if (isMoving) return;
    
    this->model = glm::mat4(1.0f);

    this->direction = Direction::NONE;
}

bool Entity::is_moving() 
{
    return this->isMoving;
}