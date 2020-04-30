/**
 * @brief Renderer class
 * @date 2020-04-30
 */

#include <iostream>
#include "Renderer.hpp"

void glClearError()
{
    while (glGetError() != GL_NO_ERROR) {
    }
}

bool glLogCall(const char *function, const char *file, int line)
{
    while (GLenum error = glGetError()) {
        std::cerr << "[OpenGL Error] (" << error << "): "
                  << function << " " << file << ":" << line << std::endl;
        return (false);
    }
    return (true);
}