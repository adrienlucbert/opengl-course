/**
 * @brief Buffer Layout class
 * @date 2020-04-30
 */

#include "BufferLayout.hpp"

template<>
void BufferLayout::push<float>(unsigned int count)
{
    _elements.push_back({ GL_FLOAT, count, false });
    _stride += count * BufferElement::getSizeOfType(GL_FLOAT);
}

template<>
void BufferLayout::push<unsigned int>(unsigned int count)
{
    _elements.push_back({ GL_UNSIGNED_INT, count, false });
    _stride += count * BufferElement::getSizeOfType(GL_UNSIGNED_INT);
}

template<>
void BufferLayout::push<unsigned char>(unsigned int count)
{
    _elements.push_back({ GL_UNSIGNED_BYTE, count, true });
    _stride += count * BufferElement::getSizeOfType(GL_UNSIGNED_BYTE);
}