#pragma once
#include "levelelement.h"

class Level
{
public:
    Level();
    void update();
    void draw(glm::mat4 view);
    void add_element(int depth);
private:
    std::vector<LevelElement*> elements;
};