/**
 * @brief Shader manager class
 * @date 2020-04-29
 */

#include <fstream>
#include <GL/glew.h>

class ShaderManager
{
  public:
    ShaderManager() = delete;
    ShaderManager(const ShaderManager &) = delete;
    ShaderManager(const ShaderManager &&) = delete;

    /**
     * @brief Read a shader source from file
     * @param path file path
     */
    static bool readShaderFromFile(const std::string &path, std::string &buffer)
    {
        std::ifstream file(path);

        if (!file.good())
            return (false);
        buffer.assign((std::istreambuf_iterator<char>(file)),
                      (std::istreambuf_iterator<char>()));
        return (true);
    }

    static unsigned int compileShader(unsigned int type, const std::string &source)
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

    static unsigned int createShader(const std::string &vertexShader,
                                     const std::string &fragmentShader)
    {
        unsigned int program = glCreateProgram();
        unsigned int vs = ShaderManager::compileShader(GL_VERTEX_SHADER, vertexShader);
        unsigned int fs = ShaderManager::compileShader(GL_FRAGMENT_SHADER, fragmentShader);

        glAttachShader(program, vs);
        glAttachShader(program, fs);
        glLinkProgram(program);
        glValidateProgram(program);
        glDeleteShader(vs);
        glDeleteShader(fs);
        return (program);
    }
};