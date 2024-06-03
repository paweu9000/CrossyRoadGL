#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include "shader.h"

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
    GLFWwindow* window;
    int width;
    int height;
    float vertices[9];
    unsigned int VAO, VBO;
    unsigned int vertexShader, fragmentShader;
    Shader* shaderProgram;
};