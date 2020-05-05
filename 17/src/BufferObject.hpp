/**
 * @brief OpenGL Buffer Object class
 * @date 2020-04-30
 */

#pragma once

#include "ABindable.hpp"

class BufferObject : public ABindable
{
public:
    BufferObject(unsigned int type, const void *data, unsigned int size);
    virtual ~BufferObject();

    virtual void bind() const override;
    virtual void unbind() const override;

protected:
    unsigned int _type;
};