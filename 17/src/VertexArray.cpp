/**
 * @brief OpenGL Buffer Object class
 * @date 2020-04-30
 */

#include "VertexArray.hpp"
#include "BufferLayout.hpp"
#include "Assertions.hpp"

VertexArray::VertexArray()
{
    glCall(glGenVertexArrays(1, &_id));
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

void VertexArray::addBuffer(const VertexBuffer &vb, const BufferLayout &layout)
{
    const auto &elements = layout.getElements();
    unsigned long int offset = 0;

    this->bind();
    vb.bind();
    for (unsigned int i = 0; i < elements.size(); ++i) {
        const auto &element = elements[i];
        glCall(glEnableVertexAttribArray(i));
        glCall(glVertexAttribPointer(i, element.count, element.type,
                                     element.normalized, layout.getStride(),
                                     (const void *)offset));
        offset += element.count * BufferElement::getSizeOfType(element.type);
    }
}