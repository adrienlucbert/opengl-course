/**
 * @brief OpenGL Buffer Object class
 * @date 2020-04-30
 */

#pragma once

#include "GLObject.hpp"
#include "VertexBuffer.hpp"

class BufferLayout;

class VertexArray : public A_GLObject
{
public:
    VertexArray();
    virtual ~VertexArray();

    virtual void bind() const override;
    virtual void unbind() const override;

    virtual void addBuffer(const VertexBuffer &vb, const BufferLayout &layout);
};