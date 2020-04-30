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
    glGenBuffers(1, &buffer);
    glBindBuffer(GL_ARRAY_BUFFER, buffer);
    glBufferData(GL_ARRAY_BUFFER, 4 * 2 * sizeof(float), positions, GL_STATIC_DRAW);

    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(float), 0);

    // index buffer object
    unsigned int ibo;
    glGenBuffers(1, &ibo);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ibo);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, 6 * sizeof(unsigned int), indices, GL_STATIC_DRAW);

    Shader::programSource source = Shader::parse("res/shaders/basic.shader");
    unsigned int shader = Shader::create(source.vertexSource, source.fragmentSource);
    glUseProgram(shader);
    while (!glfwWindowShouldClose(*window)) {
        glClear(GL_COLOR_BUFFER_BIT);
        glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, nullptr);
        glfwSwapBuffers(*window);
        glfwPollEvents();
    }
    glDeleteProgram(shader);
    return 0;
}