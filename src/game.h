#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include "shader.h"
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <vector>
#include "level.h"

enum class Direction
{
    NORTH, EAST, WEST, SOUTH, NONE
};

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
    float vertices[18*6*3];
    float levelVertices[36];
    unsigned int VAO, VBO;
    Shader* shaderProgram;
    float lastFrame, deltaTime;
    glm::mat4 projection;
    glm::mat4 model;
    glm::mat4 view;
    Direction direction;
    bool isMoving;
    float movementAngle;
};