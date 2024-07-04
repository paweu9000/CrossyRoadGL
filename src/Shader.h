#pragma once

#include <glad.h>
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>

class Shader
{
public:
    unsigned int ID;

    Shader(const char* vertexPath, const char* fragmentPath);

    void Use();

    void SetBool(const std::string& name, bool value);
    void SetInt(const std::string& name, int value);
    void SetFloat(const std::string& name, float value);
    void SetMat4(const std::string& name, const glm::mat4& value);
    void SetVec3(const std::string& name, const glm::vec3& value);
    bool IsShaderSuccessful(unsigned int shader);
    bool IsProgramSuccesful();
};
