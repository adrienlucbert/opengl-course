/**
 * @brief OpenGL Buffer Object class
 * @date 2020-04-30
 */

#pragma once

#include "GLObject.hpp"

class BufferObject : public A_GLObject
{
  public:
    BufferObject(unsigned int type, const void *data, unsigned int size);
    virtual ~BufferObject();

    virtual void bind() const;
    virtual void unbind() const;

  protected:
    unsigned int _type;
};