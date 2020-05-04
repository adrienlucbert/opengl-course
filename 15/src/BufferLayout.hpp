/**
 * @brief Buffer Layout class
 * @date 2020-04-30
 */

#pragma once

#include <vector>
#include <stdexcept>
#include <iostream>
#include "Renderer.hpp"

struct BufferElement {
    unsigned int type;
    unsigned int count;
    bool normalized;

    static unsigned int getSizeOfType(unsigned int type)
    {
        switch (type) {
            case GL_FLOAT:
                return (sizeof(GLfloat));
                break;
            case GL_UNSIGNED_INT:
                return (sizeof(GLuint));
                break;
            case GL_UNSIGNED_BYTE:
                return (sizeof(GLubyte));
                break;
        }
        ASSERT(false);
        return (0);
    }
};

class BufferLayout
{
public:
    BufferLayout()
    {
    }
    ~BufferLayout() = default;

    template<typename T>
    void push(unsigned int count)
    {
        std::cerr << "[Error] BufferLayout<?>::push(): Not implemented" << std::endl;
        ASSERT(false);
    }

    inline unsigned int getStride() const
    {
        return (_stride);
    }

    inline const std::vector<BufferElement> getElements() const
    {
        return (_elements);
    }

private:
    std::vector<BufferElement> _elements;
    unsigned int _stride{ 0 };
};