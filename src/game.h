#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include "shader.h"
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <vector>
#include "level.h"
#include "entity.h"

class Game
{
public:
    Game();
    ~Game();
    bool initialize();
    void run_loop();

private:
    void process_input(GLFWwindow* window);
    void update();
    void draw();
    void calculate_delta();
    void reset_direction();
    GLFWwindow* window;
    Level* level;
    int width;
    int height;
    Shader* shaderProgram;
    Entity* player;
    float lastFrame, deltaTime;
};