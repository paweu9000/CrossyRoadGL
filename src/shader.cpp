#include "shader.h"

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

    if (!is_shader_successful(fragment))
    {
        std::cout << "ERROR::FRAGMENT::COMPILATION::FAILURE";
    }

    if (!is_shader_successful(vertex))
    {
        std::cout << "ERROR::VERTEX::COMPILATION::FAILURE";
    }

    this->ID = glCreateProgram();
    glAttachShader(this->ID, vertex);
    glAttachShader(this->ID, fragment);
    glLinkProgram(this->ID);

    if (!is_program_succesful())
    {
        std::cout << "ERROR::PROGRAM::LINKING::FAILURE";
    }

    glDeleteShader(vertex);
    glDeleteShader(fragment);
}

void Shader::use()
{
    glUseProgram(this->ID);
}

void Shader::set_bool(const std::string& name, bool value)
{
    glUniform1i(glGetUniformLocation(this->ID, name.c_str()), (int) value);
}

void Shader::set_int(const std::string& name, int value)
{
    glUniform1i(glGetUniformLocation(this->ID, name.c_str()), value);
}

void Shader::set_float(const std::string& name, float value)
{
    glUniform1f(glGetUniformLocation(this->ID, name.c_str()), value);
}

void Shader::set_mat4(const std::string& name, const glm::mat4& value)
{
    glUniformMatrix4fv(glGetUniformLocation(this->ID, name.c_str()), 1, GL_FALSE, glm::value_ptr(value));
}

void Shader::set_vec3(const std::string& name, const glm::vec3& value)
{
    glUniform3fv(glGetUniformLocation(this->ID, name.c_str()), 1, glm::value_ptr(value));
}

bool Shader::is_shader_successful(unsigned int shader)
{
    int success;
    char infoLog[512];

    glGetShaderiv(shader, GL_COMPILE_STATUS, &success);

    if (!success)
    {
        glGetShaderInfoLog(shader, 512, nullptr, infoLog);
        std::cout << "ERROR::SHADER::COMPILATION::FAILED\n";
        return false;
    }
    return true;
}

bool Shader::is_program_succesful()
{
    int success;
    char infoLog[512];

    glGetShaderiv(this->ID, GL_COMPILE_STATUS, &success);

    if (!success)
    {
        glGetProgramInfoLog(this->ID, 512, nullptr, infoLog);
        std::cout << "ERROR::PROGRAM::LIMKING::FAILED\n";
        return false;
    }
    return true;
}