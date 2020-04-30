/**
 * @brief OpenGL Buffer Object class
 * @date 2020-04-30
 */

#include "VertexArray.hpp"
#include "Renderer.hpp"

VertexArray::VertexArray()
{
    glCall(glGenVertexArrays(1, &_id));
    this->bind();
}

VertexArray::~VertexArray()
{
    glCall(glDeleteVertexArrays(1, &_id));
}

void VertexArray::bind() const
{
    glCall(glBindVertexArray(_id));
}

void VertexArray::unbind() const
{
    glCall(glBindVertexArray(0));
}