#pragma once
#include "levelelement.h"

class Level
{
public:
    Level();
    void update(float player_depth);
    void draw(glm::mat4 view);
    void add_element(int depth);
private:
    void remove_oob_elements(float player_depth);
    std::vector<LevelElement*> elements;
};