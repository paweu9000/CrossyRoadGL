#include "level.h"

Level::Level()
{
    this->elements.push_back(new LevelElement(ObjectType::GRASS));
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