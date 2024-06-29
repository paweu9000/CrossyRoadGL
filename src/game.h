#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include "shader.h"
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <vector>
#include "level.h"
#include "player.h"
#include "camera.h"

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
    bool check_collision();
    void generate_level();
    void remove_oob_elements();
    GLFWwindow* window;
    Level* level;
    int width;
    int height;
    Shader* shaderProgram;
    Player* player;
    Camera* camera;
    std::vector<Entity*> entities;
    float lastFrame, deltaTime;
    int depth;
};