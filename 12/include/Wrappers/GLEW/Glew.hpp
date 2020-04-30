/**
 * @file Glew.hpp
 * @author Adrien Lucbert (adrien.lucbert@epitech.eu)
 * @brief Glew initializer wrapper
 * @version 0.1
 * @date 2020-04-26
 */

#include <GL/glew.h>
#include <stdexcept>

namespace GLEW
{

/**
 * @brief Glew initializer wrapper
 */
class Glew
{
  public:
    /**
     * @brief Initializes Glew
     * @throws std::runtime_error init failed
     */
    Glew()
        : _isInit{ glewInit() == GLEW_OK }
    {
        if (!this->isInit()) {
            throw std::runtime_error("GLEW::Glew init failed");
        }
    }
    Glew(const Glew &other) = delete;
    Glew(const Glew &&other) = delete;
    ~Glew() = default;

    Glew &operator=(const Glew &other) = delete;
    Glew &operator=(const Glew &&other) = delete;

    /**
     * @brief Returns true if Glew was correctly initialized
     */
    bool isInit() const
    {
        return (_isInit);
    }

  private:
    bool _isInit{ false };
};

} // namespace GLEW