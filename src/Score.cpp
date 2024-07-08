#include "Score.h"
#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <glm/gtc/matrix_transform.hpp>
#include <string>

int Score::score = 0;

Score::Score(TextRenderer* textRenderer)
{
    this->textRenderer = textRenderer;
}

void Score::RenderScore()
{
    textRenderer->RenderText("Score: " + std::to_string(score), 25.f, 670.f);
}

void Score::AddScore()
{
    score += 1;
}

void Score::ResetScore()
{
    score = 0;
}