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
#include "Renderer.hpp"
#include "VertexArray.hpp"
#include "VertexBuffer.hpp"
#include "IndexBuffer.hpp"

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

    VertexArray vao;
    VertexBuffer vbo(positions, sizeof(float) * 4 * 2);

    BufferLayout layout;
    layout.push<float>(2);
    vao.AddBuffer(vbo, layout);

    IndexBuffer ibo(indices, 6);

    Shader::programSource source = Shader::parse("res/shaders/basic.shader");
    unsigned int shader = Shader::create(source.vertexSource, source.fragmentSource);
    glCall(glUseProgram(shader));

    glCall(int location = glGetUniformLocation(shader, "u_color"));
    float r = 0.0f;
    float increment = 0.05f;

    vao.unbind();
    glUseProgram(0);
    vbo.unbind();
    ibo.unbind();

    while (!glfwWindowShouldClose(*window)) {
        glClear(GL_COLOR_BUFFER_BIT);

        glUseProgram(shader);
        glCall(glUniform4f(location, r, 0.3f, 0.8f, 1.0f));

        vao.bind();
        ibo.bind();

        glCall(glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, nullptr));

        if (r > 1.0f || r < 0.0f)
            increment *= -1;
        r += increment;

        glfwSwapBuffers(*window);
        glfwPollEvents();
    }
    glDeleteProgram(shader);
    return (0);
}