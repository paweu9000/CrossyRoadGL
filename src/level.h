#pragma once
#include "LevelElement.h"

class Level
{
public:
    Level();
    void Update(float playerDepth);
    void Draw(glm::mat4 view);
    void AddElement(int depth);
private:
    void RemoveOOBElements(float playerDepth);
    std::vector<LevelElement*> elements;
};