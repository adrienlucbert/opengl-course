#define ERRCODE (-1)
#define SUCCODE (0)

#include <iostream>
#include <GL/glew.h>
#include <GLFW/glfw3.h>

int setup(void)
{
    if (glfwInit() != GLFW_TRUE) {
        std::cerr << "Glew init failed" << std::endl;
        return (ERRCODE);
    }
    return (SUCCODE);
}

int display(void)
{
    glClear(GL_COLOR_BUFFER_BIT);
    glBegin(GL_TRIANGLES);
        glVertex2f(-0.5f, -0.5f);
        glVertex2f(0.0f, 0.5f);
        glVertex2f(0.5f, -0.5f);
    glEnd();
    return (SUCCODE);
}

int main(void)
{
    GLFWwindow* window;

    if (setup() == ERRCODE)
        return (1);
    window = glfwCreateWindow(640, 480, "Hello World", NULL, NULL);
    if (window == NULL) {
        glfwTerminate();
        return (-1);
    }
    glfwMakeContextCurrent(window);
    if (glewInit() != GLEW_OK) {
        std::cerr << "Glew init failed" << std::endl;
        return (ERRCODE);
    }
    std::cout << glGetString(GL_VERSION) << std::endl;
    while (!glfwWindowShouldClose(window)) {
        display();
        glfwSwapBuffers(window);
        glfwPollEvents();
    }
    glfwTerminate();
    return 0;
}