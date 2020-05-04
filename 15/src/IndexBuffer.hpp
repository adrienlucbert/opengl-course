/**
 * @brief OpenGL Buffer Object class
 * @date 2020-04-30
 */

#pragma once

#include "BufferObject.hpp"

class IndexBuffer : public BufferObject
{
public:
    IndexBuffer(const unsigned int *data, unsigned int count);

protected:
    unsigned int _count;
};