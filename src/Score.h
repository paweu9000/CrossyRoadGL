#pragma once
#include "TextRenderer.h"

class Score
{
public:
    Score(std::shared_ptr<TextRenderer> textRenderer);
    void RenderScore();
    static void AddScore();
    static void ResetScore();
private:
    std::shared_ptr<TextRenderer> textRenderer;
    static int score;
};