#pragma once
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include "Shader.h"
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <vector>
#include "Level.h"
#include "Player.h"
#include "Camera.h"
#include "TextureManager.h"
#include <unordered_map>
#include "Score.h"
#include "TextRenderer.h"
#include "ResetScene.h"

class Game
{
public:
    Game();
    ~Game();
    bool Initialize();
    void RunLoop();

private:
    void ProcessInput(GLFWwindow* window);
    void Update();
    void Draw();
    void CalculateDelta();
    void ResetDirection();
    bool CheckCollision();
    void GenerateLevel();
    void RemoveOOBElements();
    void ResetGame();
    GLFWwindow* window;
    std::unique_ptr<Level> level;
    int width;
    int height;
    std::shared_ptr<Player> player;
    std::unique_ptr<Camera> camera;
    std::unique_ptr<Score> score;
    std::unique_ptr<ResetScene> resetScene;
    std::shared_ptr<TextRenderer> textRenderer;
    std::shared_ptr<TextureManager> textureManager;
    std::vector<std::shared_ptr<Entity>> entities;
    float lastFrame, deltaTime;
    int depth;
};
