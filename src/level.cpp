#include "level.h"

Level::Level()
{
    this->elements.push_back(new LevelElement(ObjectType::GRASS));
    this->elements.push_back(new LevelElement(ObjectType::ROAD));
    this->elements.push_back(new LevelElement(ObjectType::LINE));
}

void Level::update()
{
    for (const auto& element: elements)
    {
        element->update();
    }
}

void Level::draw()
{
    for (const auto& element: elements)
    {
        element->draw();
    }
}