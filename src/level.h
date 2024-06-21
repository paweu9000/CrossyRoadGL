#pragma once
#include "levelelement.h"

class Level
{
public:
    Level();
    void update();
    void draw();
private:
    std::vector<LevelElement*> elements;
};