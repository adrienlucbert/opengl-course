/**
 * @brief OpenGL Buffer Object class
 * @date 2020-04-30
 */

#pragma once

#include "ABindable.hpp"
#include "VertexBuffer.hpp"
#include "BufferLayout.hpp"

class VertexArray : public ABindable
{
public:
    VertexArray();
    virtual ~VertexArray();

    virtual void bind() const override;
    virtual void unbind() const override;

    virtual void addBuffer(const VertexBuffer &vb, const BufferLayout &layout);
};