/**
 * @brief OpenGL Buffer Object class
 * @date 2020-04-30
 */

#include "IndexBuffer.hpp"
#include "OpenGL.hpp"

IndexBuffer::IndexBuffer(const unsigned int *data, unsigned int count)
    : BufferObject(GL_ELEMENT_ARRAY_BUFFER, data, sizeof(unsigned int) * count)
    , _count{ count }
{
}

unsigned int IndexBuffer::getCount() const
{
    return (_count);
}