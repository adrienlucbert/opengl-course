/**
 * @file main.cpp
 * @author Adrien Lucbert (adrien.lucbert@epitech.eu)
 * @brief main file
 * @version 0.1
 * @date 2020-04-26
 */

#define ERRCODE (-1)
#define SUCCODE (0)

#include "Wrappers/GLEW/Glew.hpp"
#include "Wrappers/GLFW/Glfw.hpp"
#include "Wrappers/GLFW/Window.hpp"
#include <iostream>

int main(void)
{
    GLFW::Glfw glfw;
    GLFW::Window window(640, 480, "Hello world");
    GLEW::Glew glew;

    std::cout << glGetString(GL_VERSION) << std::endl;

    // clang-format off
    float positions[] = {
        -0.5f, -0.5f,
        0.0f, 0.5f,
        0.5f, -0.5f
    };
    // clang-format on

    GLuint buffer;
    glGenBuffers(1, &buffer);
    glBindBuffer(GL_ARRAY_BUFFER, buffer);
    glBufferData(GL_ARRAY_BUFFER, 9 * sizeof(float), positions, GL_STATIC_DRAW);

    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(float), 0);

    while (!glfwWindowShouldClose(*window)) {
        glClear(GL_COLOR_BUFFER_BIT);
        glDrawArrays(GL_TRIANGLES, 0, 3);
        glfwSwapBuffers(*window);
        glfwPollEvents();
    }
    return 0;
}