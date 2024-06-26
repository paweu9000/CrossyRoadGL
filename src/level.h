#pragma once
#include "levelelement.h"

class Level
{
public:
    Level();
    void update();
    void draw(glm::mat4 view);
private:
    std::vector<LevelElement*> elements;
};