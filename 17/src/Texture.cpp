/**
 * @brief Texture class
 * @date 2020-05-05
 */

#include "Texture.hpp"
#include "stb/stb_image.h"

Texture::Texture(const std::string &path)
    : _filepath{ path }
{
    stbi_set_flip_vertically_on_load(1);
    _localBuffer = stbi_load(path.c_str(), &_width, &_height, &_bpp, 4);

    glCall(glGenTextures(1, &_id));
    glCall(glBindTexture(GL_TEXTURE_2D, _id));

    glCall(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR));
    glCall(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR));
    glCall(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE));
    glCall(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE));

    glCall(glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA8, _width, _height, 0, GL_RGBA, GL_UNSIGNED_BYTE, _localBuffer));
    this->unbind();

    if (_localBuffer) {
        stbi_image_free(_localBuffer);
        _localBuffer = nullptr;
    }
}

Texture::~Texture()
{
    if (_localBuffer) {
        stbi_image_free(_localBuffer);
        _localBuffer = nullptr;
    }
    glCall(glDeleteTextures(1, &_id));
}

void Texture::bind() const
{
    this->bind(0);
}

void Texture::bind(unsigned int slot) const
{
    glCall(glActiveTexture(GL_TEXTURE0 + slot));
    glCall(glBindTexture(GL_TEXTURE_2D, _id));
}

void Texture::unbind() const
{
    glCall(glBindTexture(GL_TEXTURE_2D, 0));
}

inline int Texture::getWidth() const
{
    return (_width);
}

inline int Texture::getHeight() const
{
    return (_height);
}