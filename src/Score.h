#pragma once
#include "TextRenderer.h"

class Score
{
public:
    Score(TextRenderer* textRenderer);
    void RenderScore();
    static void AddScore();
    static void ResetScore();
private:
    TextRenderer* textRenderer;
    static int score;
};