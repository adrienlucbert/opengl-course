/**
 * @file Window.hpp
 * @author Adrien Lucbert (adrien.lucbert@epitech.eu)
 * @brief GLFW Window wrapper
 * @version 0.1
 * @date 2020-04-26
 */

#include <GLFW/glfw3.h>
#include <stdexcept>

namespace GLFW
{

/**
 * @brief GLFW Window wrapper
 */
class Window
{
  public:
    /**
     * @brief  Create a new GLFWwindow and make the context of the specified
     * window current for the calling thread.
     * @param width The desired width, in screen coordinates, of the window.
     * This must be greater than zero.
     * @param height The desired height, in screen coordinates, of the window.
     * This must be greater than zero.
     * @param title The initial, UTF-8 encoded window title.
     * @param monitor The monitor to use for full screen mode, or `NULL` for
     * windowed mode.
     * @param share The window whose context to share resources with, or `NULL`
     * to not share resources.
     */
    Window(int width, int height, const char *title = "OpenGL",
           GLFWmonitor *monitor = NULL, GLFWwindow *share = NULL)
        : _window{ glfwCreateWindow(width, height, title, monitor, share) }
    {
        if (!this->isInit()) {
            throw std::runtime_error("GLFW::Window init failed");
        }
        glfwMakeContextCurrent(_window);
        glfwSwapInterval(1);
    }

    Window(const Window &other) = delete;
    Window(const Window &&other) = delete;
    /**
     * @brief Destroy the Window
     */
    ~Window()
    {
        if (this->isInit()) {
            glfwDestroyWindow(_window);
        }
        _window = nullptr;
    }

    Window &operator=(const Window &other) = delete;
    Window &operator=(const Window &&other) = delete;
    /**
     * @brief Returns stored GLFWwindow pointer
     */
    GLFWwindow *operator*()
    {
        return (_window);
    }

    /**
     * @brief Returns true if window was created successfully
     */
    bool isInit() const
    {
        return (_window != nullptr);
    }

  private:
    GLFWwindow *_window{ nullptr };
};

} // namespace GLFW