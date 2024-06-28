#include "level.h"

Level::Level()
{
    for (int i = 1; i <= 10; ++i)
    {
        this->elements.push_back(new LevelElement(ObjectType::GRASS, i));
        this->elements.push_back(new LevelElement(ObjectType::ROAD, i));
        this->elements.push_back(new LevelElement(ObjectType::LINE, i));
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