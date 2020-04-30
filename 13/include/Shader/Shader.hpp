/**
 * @brief Shader manager class
 * @date 2020-04-29
 */

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <unordered_map>
#include <GL/glew.h>

namespace Shader
{

enum shaderType {
    NONE = -1,
    VERTEX_SHADER = 0,
    FRAGMENT_SHADER = 1
};

static const std::unordered_map<std::string, shaderType> shaderTypes = {
    { "vertex", VERTEX_SHADER },
    { "fragment", FRAGMENT_SHADER }
};

struct programSource {
    std::string vertexSource;
    std::string fragmentSource;
};

/**
 * @brief Read a shader source from file
 * @param path file path
 */
static programSource parse(const std::string &path)
{
    std::ifstream stream(path);
    std::stringstream ss[2];
    std::string line;
    shaderType type = shaderType::NONE;

    while (getline(stream, line)) {
        if (line.find("#shader") != std::string::npos) {
            for (const auto &pair : shaderTypes) {
                if (line.find(pair.first) != std::string::npos) {
                    type = pair.second;
                }
            }
        } else if (type != shaderType::NONE) {
            ss[(int)type] << line << '\n';
        }
    }
    return ((programSource){ ss[0].str(), ss[1].str() });
}

/**
 * @brief Compile a shader of given type from source (as a string)
 * @param type shader source
 * @param source shader program source code
 */
static unsigned int compile(unsigned int type, const std::string &source)
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

/**
 * @brief Create a shader from source
 * @param vertexShader vertex shader source code
 * @param fragmentShader fragment shader source code
 */
static unsigned int create(const std::string &vertexShader,
                           const std::string &fragmentShader)
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

}; // namespace Shader