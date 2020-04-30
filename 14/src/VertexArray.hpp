/**
 * @brief OpenGL Buffer Object class
 * @date 2020-04-30
 */

#pragma once

#include "GLObject.hpp"
#include "VertexBuffer.hpp"
#include "BufferLayout.hpp"

class VertexArray : public A_GLObject
{
  public:
    VertexArray();
    virtual ~VertexArray();

    virtual void bind() const;
    virtual void unbind() const;

    virtual void AddBuffer(const VertexBuffer &vb, const BufferLayout &layout);
};