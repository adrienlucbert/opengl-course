/**
 * @brief OpenGL Object class
 * @date 2020-04-30
 */

#pragma once

/**
 * @brief OpenGL Object abstract class
 */
class A_GLObject
{
  public:
    virtual ~A_GLObject() = default;

    virtual void bind() const = 0;
    virtual void unbind() const = 0;

  protected:
    unsigned int _id;
};