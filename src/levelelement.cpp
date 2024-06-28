#include "levelelement.h"
#include "constants.h"
#include <iostream>

LevelElement::LevelElement(ObjectType type, int depth)
{
    this->type = type;
    this->inBounds = true;

    switch (type) {
        case ObjectType::GRASS:
            vertices = Constant::grass;
            this->model = glm::translate(this->model, configure_depth(Constant::grass_base_vec, depth)) * model;
            bind_vertices();
            break;
        case ObjectType::LINE:
            vertices = Constant::lines;
            this->model = glm::translate(glm::mat4(1.0f),  configure_depth(Constant::line_base_vec, depth)) * model;
            bind_vertices();
            break;
        case ObjectType::ROAD:
            vertices = Constant::road;
            this->model = glm::translate(glm::mat4(1.0f),  configure_depth(Constant::road_base_vec, depth)) * model;
            bind_vertices();
            break;
        default:
            break;
    }
    this->model = glm::rotate(this->model, glm::radians(-90.f), glm::vec3(1.f, 0.f, 0.f));
}

void LevelElement::update()
{
    
}

void LevelElement::draw(glm::mat4 view)
{
    shader->use();
    shader->use();
    shader->set_mat4("model", this->model);
    shader->set_mat4("view", view);
    shader->set_mat4("projection", this->projection);
    auto color = cos(glfwGetTime());
    shader->set_float("colorChange", color < 0.8f ? 0.8f : color);
    glBindVertexArray(this->VAO);
    glDrawArrays(GL_TRIANGLES, 0, vertices.size() / 6);
}

void LevelElement::bind_vertices()
{
    this->shader = new Shader("src/shaders/level_vertex.vs", "src/shaders/level_fragment.fs");

    glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(float), &vertices.front(), GL_STATIC_DRAW);
    glVertexAttribPointer(10, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(10);
    glVertexAttribPointer(11, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(3*sizeof(float)));
    glEnableVertexAttribArray(11);
}