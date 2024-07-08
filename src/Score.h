#include <ft2build.h>
#include FT_FREETYPE_H
#include "glm/glm.hpp"
#include <unordered_map>
#include "Shader.h"

struct Character 
{
    unsigned int TextureID;
    glm::ivec2 Size;
    glm::ivec2 Bearing;
    unsigned int Advance;
};

class Score
{
public:
    Score();
    void RenderScore();
    static void AddScore();
private:
    std::unordered_map<char, Character> characters;
    glm::mat4 projection;
    Shader* shader;
    unsigned int VAO, VBO;
    static int score;
};