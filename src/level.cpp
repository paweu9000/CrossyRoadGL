#include "level.h"

Level::Level() :
vertices{
    -20.f, -20.f, -1.f, 1.f, 0.f, 0.0f,
    20.f, -20.f, -1.f, 0.0f, 1.f, 1.f,
    20.f,  20.f, -1.f, 1.f, 1.f, 0.0f,
    20.f,  20.f, -1.f, 1.f, 1.f, 0.0f,
    -20.f,  20.f, -1.f, 0.f, 0.f, 1.f,
    -20.f, -20.f, -1.f, 1.f, 0.f, 0.0f,
}{
    this->shader = new Shader("src/shaders/level_vertex.vs", "src/shaders/level_fragment.fs");
    this->projection = glm::mat4(1.f);
    this->model = glm::mat4(1.f);
    this->view = glm::mat4(1.f);
    this->projection = glm::perspective(glm::radians(45.f), 1280.f/720.f, 0.1f, 100.f);
    this->model = glm::translate(model, glm::vec3(0.f, -5.f, 0.f));
    this->view = glm::translate(view, glm::vec3(0.f, 0.f, -10.f));
    
    glGenVertexArrays(1, &this->VAO);
    glGenBuffers(1, &this->VBO);
    glBindVertexArray(VAO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
    glVertexAttribPointer(10, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(10);
    glVertexAttribPointer(11, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(3*sizeof(float)));
    glEnableVertexAttribArray(11);
}

const float* Level::get_vertices() const {
    return this->vertices;
}

void Level::update()
{
    shader->use();
    shader->set_mat4("model", this->model);
    shader->set_mat4("view", this->view);
    shader->set_mat4("projection", this->projection);
    auto color = cos(glfwGetTime());
    shader->set_float("colorChange", color < 0.8f ? 0.8f : color);
}

void Level::draw()
{
    glBindVertexArray(VAO);
    glDrawArrays(GL_TRIANGLES, 0, 6);
}