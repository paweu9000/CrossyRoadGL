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
    GLFWwindow* window;
    Level* level;
    int width;
    int height;
    Player* player;
    Camera* camera;
    TextureManager* textureManager;
    std::vector<Entity*> entities;
    float lastFrame, deltaTime;
    int depth;
};
