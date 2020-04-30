/**
 * @brief OpenGL Buffer Object class
 * @date 2020-04-30
 */

#include "BufferObject.hpp"
#include "Renderer.hpp"

BufferObject::BufferObject(unsigned int type, const void *data, unsigned int size)
    : _type{ type }
{
    glCall(glGenBuffers(1, &_id));
    this->bind();
    glCall(glBufferData(_type, size, data, GL_STATIC_DRAW));
}

BufferObject::~BufferObject()
{
    glCall(glDeleteBuffers(1, &_id));
}

void BufferObject::bind() const
{
    glCall(glBindBuffer(_type, _id));
}

void BufferObject::unbind() const
{
    glCall(glBindBuffer(_type, 0));
}