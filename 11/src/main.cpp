/**
 * @file main.cpp
 * @author Adrien Lucbert (adrien.lucbert@epitech.eu)
 * @brief main file
 * @version 0.1
 * @date 2020-04-26
 */

#define ERRCODE (-1)
#define SUCCODE (0)

#include <iostream>
#include "Shader/Shader.hpp"
#include "Wrappers/GLEW/Glew.hpp"
#include "Wrappers/GLFW/Glfw.hpp"
#include "Wrappers/GLFW/Window.hpp"

#define ASSERT(x) \
    if (!(x))     \
    __builtin_trap()

#define glCall(x)   \
    glClearError(); \
    x;              \
    ASSERT(glLogCall(#x, __FILE__, __LINE__))

static void glClearError()
{
    while (glGetError() != GL_NO_ERROR) {
    }
}

static bool glLogCall(const char *function, const char *file, int line)
{
    while (GLenum error = glGetError()) {
        std::cerr << "[OpenGL Error] (" << error << "): " << function << " " << file << ":" << line << std::endl;
        return (false);
    }
    return (true);
}

int main(void)
{
    std::string content;

    GLFW::Glfw glfw;
    GLFW::Window window(640, 480, "Hello world");
    GLEW::Glew glew;

    // clang-format off
    float positions[] = {
        -0.5f, -0.5f,
        0.5f, -0.5f,
        0.5f, 0.5f,
        -0.5f, 0.5f
    };

    unsigned int indices[] = {
        0, 1, 2,
        2, 3, 0
    };
    // clang-format on

    unsigned int buffer;
    glCall(glGenBuffers(1, &buffer));
    glCall(glBindBuffer(GL_ARRAY_BUFFER, buffer));
    glCall(glBufferData(GL_ARRAY_BUFFER, 4 * 2 * sizeof(float), positions, GL_STATIC_DRAW));

    glCall(glEnableVertexAttribArray(0));
    glCall(glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(float), 0));

    // index buffer object
    unsigned int ibo;
    glCall(glGenBuffers(1, &ibo));
    glCall(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ibo));
    glCall(glBufferData(GL_ELEMENT_ARRAY_BUFFER, 6 * sizeof(float), indices, GL_STATIC_DRAW));

    Shader::programSource source = Shader::parse("res/shaders/basic.shader");
    unsigned int shader = Shader::create(source.vertexSource, source.fragmentSource);
    glUseProgram(shader);

    glCall(int location = glGetUniformLocation(shader, "u_color"));

    float r = 0.0f;
    float increment = 0.05f;
    while (!glfwWindowShouldClose(*window)) {
        glClear(GL_COLOR_BUFFER_BIT);
        glCall(glUniform4f(location, r, 0.3f, 0.8f, 1.0f));
        glCall(glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, nullptr));
        if (r > 1.0f || r < 0.0f)
            increment *= -1;
        r += increment;
        glfwSwapBuffers(*window);
        glfwPollEvents();
    }
    glDeleteProgram(shader);
    return 0;
}