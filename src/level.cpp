#include "level.h"

Level::Level()
{
    for (int i = 1; i <= 10; ++i)
    {
        add_element(i);
    }
}

void Level::update()
{
    for (const auto& element: elements)
    {
        element->update();
    }
}

void Level::draw(glm::mat4 view)
{
    for (const auto& element: elements)
    {
        element->draw(view);
    }
}

void Level::add_element(int depth)
{
    this->elements.push_back(new LevelElement(ObjectType::GRASS, depth));
    this->elements.push_back(new LevelElement(ObjectType::ROAD, depth));
    this->elements.push_back(new LevelElement(ObjectType::LINE, depth));
}