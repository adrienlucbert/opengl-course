/**
 * @brief OpenGL Buffer Object class
 * @date 2020-04-30
 */

#include "VertexBuffer.hpp"
#include "Renderer.hpp"

VertexBuffer::VertexBuffer(const void *data, unsigned int size)
    : BufferObject(GL_ARRAY_BUFFER, data, size)
{
}