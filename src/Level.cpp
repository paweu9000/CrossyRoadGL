#include "Level.h"
#include <algorithm>

Level::Level()
{
    for (int i = 1; i <= 10; ++i)
    {
        AddElement(i);
    }
}

void Level::Update(float playerDepth)
{
    this->RemoveOOBElements(playerDepth);
    for (const auto &element : elements)
    {
        element->Update();
    }
}

void Level::Draw(glm::mat4 view)
{
    auto viewPos = glm::vec3(view[3][0], view[3][1], view[3][2]);
    for (const auto &element : elements)
    {
        element->SetLightning(viewPos);
        element->Draw(view);
    }
}

void Level::AddElement(int depth)
{
    this->elements.push_back(new LevelElement(ObjectType::GRASS, depth));
    this->elements.push_back(new LevelElement(ObjectType::ROAD, depth));
    this->elements.push_back(new LevelElement(ObjectType::LINE, depth));
}

void Level::RemoveOOBElements(float playerDepth)
{
    std::vector<LevelElement *> oobElements;
    for (auto element : elements)
    {
        if (element->GetDepth() > playerDepth + 60.f)
        {
            oobElements.emplace_back(element);
        }
    }

    for (auto element : oobElements)
    {
        auto iter = std::find(elements.begin(), elements.end(), element);
        if (iter != elements.end())
        {
            std::iter_swap(iter, elements.end() - 1);
            elements.pop_back();
        }
    }
}
