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
#include "Wrappers/GLEW/Glew.hpp"
#include "Wrappers/GLFW/Glfw.hpp"
#include "Wrappers/GLFW/Window.hpp"
#include "Renderer.hpp"
#include "BufferLayout.hpp"
#include "VertexArray.hpp"
#include "VertexBuffer.hpp"
#include "IndexBuffer.hpp"
#include "Shader.hpp"

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
    vao.addBuffer(vbo, layout);

    IndexBuffer ibo(indices, 6);

    Shader shader("res/shaders/basic.shader");
    shader.bind();

    shader.setUniform4f("u_color", 0.8f, 0.3f, 0.8f, 1.0f);
    float r = 0.0f;
    float increment = 0.05f;

    vao.unbind();
    vbo.unbind();
    ibo.unbind();
    shader.unbind();

    Renderer renderer;

    while (!glfwWindowShouldClose(*window)) {
        renderer.clear();

        shader.bind();
        shader.setUniform4f("u_color", r, 0.3f, 0.8f, 1.0f);

        renderer.draw(vao, ibo, shader);

        if (r > 1.0f || r < 0.0f)
            increment *= -1;
        r += increment;

        glfwSwapBuffers(*window);
        glfwPollEvents();
    }
    return (0);
}