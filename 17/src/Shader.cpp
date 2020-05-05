/**
 * @brief Shader class
 * @date 2020-05-04
 */

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <unordered_map>
#include "Assertions.hpp"
#include "Shader.hpp"
#include "Assertions.hpp"

static const std::unordered_map<std::string, Shader::type> shaderTypes = {
    { "vertex", Shader::type::VERTEX_SHADER },
    { "fragment", Shader::type::FRAGMENT_SHADER }
};

Shader::Shader(const std::string &filepath)
    : _filepath{ filepath }
{
    Shader::programSource source = this->parse();
    _id = this->create(source.vertexSource, source.fragmentSource);
}

Shader::~Shader()
{
    glCall(glDeleteProgram(_id));
}

void Shader::bind() const
{
    glCall(glUseProgram(_id));
}

void Shader::unbind() const
{
    glCall(glUseProgram(0));
}

void Shader::setUniform1i(const std::string &name, int value)
{
    glCall(glUniform1i(this->getUniformLocation(name), value));
}

void Shader::setUniform1f(const std::string &name, float value)
{
    glCall(glUniform1f(this->getUniformLocation(name), value));
}

void Shader::setUniform4f(const std::string &name, float v0, float v1, float v2, float v3)
{
    glCall(glUniform4f(this->getUniformLocation(name), v0, v1, v2, v3));
}

int Shader::getUniformLocation(const std::string &name)
{
    if (_uniformLocationCache.find(name) != _uniformLocationCache.end())
        return (_uniformLocationCache[name]);
    glCall(int location = glGetUniformLocation(_id, name.c_str()));
    if (location == -1)
        std::cerr << "Warning: uniform '" << name << "' doesn't exist!" << std::endl;
    _uniformLocationCache[name] = location;
    return (location);
}

Shader::programSource Shader::parse() const
{
    std::ifstream stream(_filepath);
    std::stringstream ss[2];
    std::string line;
    Shader::type type = Shader::type::NONE;

    while (getline(stream, line)) {
        if (line.find("#shader") != std::string::npos) {
            for (const auto &pair : shaderTypes) {
                if (line.find(pair.first) != std::string::npos) {
                    type = pair.second;
                }
            }
        } else if (type != Shader::type::NONE) {
            ss[(int)type] << line << '\n';
        }
    }
    return ((programSource){ ss[0].str(), ss[1].str() });
}

unsigned int Shader::create(const std::string &vertexShader,
                            const std::string &fragmentShader) const
{
    unsigned int program = glCreateProgram();
    unsigned int vs = compile(GL_VERTEX_SHADER, vertexShader);
    unsigned int fs = compile(GL_FRAGMENT_SHADER, fragmentShader);

    glAttachShader(program, vs);
    glAttachShader(program, fs);
    glLinkProgram(program);
    glValidateProgram(program);
    glDeleteShader(vs);
    glDeleteShader(fs);
    return (program);
}

unsigned int Shader::compile(unsigned int type, const std::string &source) const
{
    unsigned int id = glCreateShader(type);
    const char *src = source.c_str();

    glShaderSource(id, 1, &src, nullptr);
    glCompileShader(id);

    int status;
    glGetShaderiv(id, GL_COMPILE_STATUS, &status);
    if (status == GL_FALSE) {
        int length;
        glGetShaderiv(id, GL_INFO_LOG_LENGTH, &length);
        char *message = (char *)alloca(length * sizeof(char));
        glGetShaderInfoLog(id, length, &length, message);
        std::cerr << "Failed to compile shader" << std::endl;
        std::cerr << message << std::endl;
        glDeleteShader(id);
        return (0);
    }
    return (id);
}