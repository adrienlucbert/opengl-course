/**
 * @brief OpenGL Buffer Object class
 * @date 2020-04-30
 */

#pragma once

#include "BufferObject.hpp"

class VertexBuffer : public BufferObject
{
public:
    VertexBuffer(const void *data, unsigned int size);
};