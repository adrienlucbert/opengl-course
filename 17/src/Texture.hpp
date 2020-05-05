/**
 * @brief Texture class
 * @date 2020-05-05
 */

#pragma once

#include <string>
#include "ABindable.hpp"
#include "Assertions.hpp"

class Texture : public ABindable
{
private:
    std::string _filepath;
    unsigned char *_localBuffer{ nullptr };
    int _width{ 0 };
    int _height{ 0 };
    int _bpp{ 0 };

public:
    Texture(const std::string &path);
    ~Texture();

    virtual void bind() const override;
    virtual void bind(unsigned int slot = 0) const;
    virtual void unbind() const override;

    inline int getWidth() const;
    inline int getHeight() const;
};