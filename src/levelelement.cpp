#include "levelelement.h"
#include "constants.h"

LevelElement::LevelElement(ObjectType type)
{
    this->type = type;

    vertices = Constant::grass;

    this->shader = new Shader("src/shaders/level_vertex.vs", "src/shaders/level_fragment.fs");
    
    this->view = glm::translate(view, glm::vec3(0.f, -5.f, -35.f));
    
    glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(float), &vertices.front(), GL_STATIC_DRAW);
    glVertexAttribPointer(10, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(10);
    glVertexAttribPointer(11, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(3*sizeof(float)));
    glEnableVertexAttribArray(11);
}

void LevelElement::update()
{
    shader->use();
    shader->set_mat4("model", this->model);
    shader->set_mat4("view", this->view);
    shader->set_mat4("projection", this->projection);
    auto color = cos(glfwGetTime());
    shader->set_float("colorChange", color < 0.8f ? 0.8f : color);
}

void LevelElement::draw()
{
    glBindVertexArray(VAO);
    glDrawArrays(GL_TRIANGLES, 0, vertices.size()/9);
}