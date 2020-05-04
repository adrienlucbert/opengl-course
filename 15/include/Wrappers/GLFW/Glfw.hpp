/**
 * @file Glfw.hpp
 * @author Adrien Lucbert (adrien.lucbert@epitech.eu)
 * @brief GLFW initializer wrapper
 * @version 0.1
 * @date 2020-04-26
 */

#include <GLFW/glfw3.h>
#include <stdexcept>

namespace GLFW
{

/**
 * @brief GLFW initializer
 */
class Glfw
{
  public:
    /**
     * @brief Initializes GLFW
     * @throws std::runtime_error init failed
     */
    Glfw()
        : _isInit{ glfwInit() == GLFW_TRUE }
    {
        if (!this->isInit()) {
            throw std::runtime_error("GLFW::Glfw init failed");
        }

        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
        glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    }
    Glfw(const Glfw &other) = delete;
    Glfw(const Glfw &&other) = delete;
    /**
     * @brief Terminates GLFW
     */
    ~Glfw()
    {
        if (this->isInit()) {
            glfwTerminate();
        }
    }
    Glfw &operator=(Glfw &other) = delete;
    Glfw &operator=(Glfw &&other) = delete;

    /**
     * @brief Returns true if GLFW was correctly initialized
     */
    bool isInit() const
    {
        return (_isInit);
    }

  private:
    bool _isInit{ false };
};

} // namespace GLFW