/**
 * @brief OpenGL Buffer Object class
 * @date 2020-04-30
 */

#pragma once

#include "GLObject.hpp"

class VertexArray : public A_GLObject
{
  public:
    VertexArray();
    virtual ~VertexArray();

    virtual void bind() const;
    virtual void unbind() const;
};