#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include "shader.h"
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

class Game
{
public:
    Game();
    ~Game();
    bool initialize();
    void run_loop();

private:
    void process_input();
    void update();
    void draw();
    void calculate_delta();
    GLFWwindow* window;
    int width;
    int height;
    float vertices[18*6*3];
    unsigned int VAO, VBO;
    unsigned int vertexShader, fragmentShader;
    Shader* shaderProgram;
    float lastFrame, deltaTime;
    glm::mat4 projection;
    glm::mat4 model;
    glm::mat4 view;
};