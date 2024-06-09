#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include "shader.h"
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <vector>

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
    int width;
    int height;
    float vertices[18*6*3];
    float levelVertices[36];
    unsigned int VAO[2], VBO[2];
    unsigned int vertexShader, fragmentShader;
    std::vector<Shader*> shaderPrograms;
    float lastFrame, deltaTime;
    glm::mat4 projection;
    glm::mat4 model;
    glm::mat4 view;
    glm::mat4 levelProjection;
    glm::mat4 levelModel;
    glm::mat4 levelView;
    Direction direction;
    bool isMoving;
    float movementAngle;
};