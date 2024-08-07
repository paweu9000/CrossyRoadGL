#include "Shader.h"

Shader::Shader(const char* vertexPath, const char* fragmentPath)
{
    std::string vertexCode, fragmentCode;
    std::ifstream vShaderFile, fShaderFile;

    vShaderFile.exceptions(std::ifstream::failbit | std::ifstream::badbit);
    fShaderFile.exceptions(std::ifstream::failbit | std::ifstream::badbit);

    try
    {
        vShaderFile.open(vertexPath);
        fShaderFile.open(fragmentPath);
        std::stringstream vShaderStream, fShaderStream;

        vShaderStream << vShaderFile.rdbuf();
        fShaderStream << fShaderFile.rdbuf();

        vShaderFile.close();
        fShaderFile.close();

        vertexCode = vShaderStream.str();
        fragmentCode = fShaderStream.str();
    }
    catch (std::ifstream::failure error)
    {
        std::cout << "ERROR::SHADER::BAD::LOAD::" << error.what() << "\n";
    }

    auto vShaderCode = vertexCode.c_str();
    auto fShaderCode = fragmentCode.c_str();

    unsigned int vertex, fragment;

    vertex = glCreateShader(GL_VERTEX_SHADER);
    fragment = glCreateShader(GL_FRAGMENT_SHADER);

    glShaderSource(vertex, 1, &vShaderCode, nullptr);
    glShaderSource(fragment, 1, &fShaderCode, nullptr);

    glCompileShader(vertex);
    glCompileShader(fragment);

    if (!IsShaderSuccessful(fragment))
    {
        std::cout << "ERROR::FRAGMENT::COMPILATION::FAILURE\n";
    }

    if (!IsShaderSuccessful(vertex))
    {
        std::cout << "ERROR::VERTEX::COMPILATION::FAILURE\n";
    }

    this->ID = glCreateProgram();
    glAttachShader(this->ID, vertex);
    glAttachShader(this->ID, fragment);
    glLinkProgram(this->ID);

    if (!IsProgramSuccesful())
    {
        std::cout << "ERROR::PROGRAM::LINKING::FAILURE\n";
    }

    glDeleteShader(vertex);
    glDeleteShader(fragment);
}

void Shader::Use()
{
    glUseProgram(this->ID);
}

void Shader::SetBool(const std::string& name, bool value)
{
    glUniform1i(glGetUniformLocation(this->ID, name.c_str()), (int) value);
}

void Shader::SetInt(const std::string& name, int value)
{
    glUniform1i(glGetUniformLocation(this->ID, name.c_str()), value);
}

void Shader::SetFloat(const std::string& name, float value)
{
    glUniform1f(glGetUniformLocation(this->ID, name.c_str()), value);
}

void Shader::SetMat4(const std::string& name, const glm::mat4& value)
{
    glUniformMatrix4fv(glGetUniformLocation(this->ID, name.c_str()), 1, GL_FALSE, glm::value_ptr(value));
}

void Shader::SetVec3(const std::string& name, const glm::vec3& value)
{
    glUniform3fv(glGetUniformLocation(this->ID, name.c_str()), 1, glm::value_ptr(value));
}

bool Shader::IsShaderSuccessful(unsigned int shader)
{
    int success;
    char infoLog[512];

    glGetShaderiv(shader, GL_COMPILE_STATUS, &success);

    if (!success)
    {
        glGetShaderInfoLog(shader, 512, nullptr, infoLog);
        std::cout << infoLog << "\n";
        return false;
    }
    return true;
}

bool Shader::IsProgramSuccesful()
{
    int success;
    char infoLog[512];

    glGetProgramiv(this->ID, GL_LINK_STATUS, &success);

    if (!success)
    {
        glGetProgramInfoLog(this->ID, 512, nullptr, infoLog);
        std::cout << infoLog << "\n";
        return false;
    }
    return true;
}
