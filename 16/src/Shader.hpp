/**
 * @brief Shader class
 * @date 2020-05-04
 */

#pragma once

#include <string>
#include <unordered_map>
#include "GLObject.hpp"

class Shader : A_GLObject
{
private:
    const std::string _filepath;
    std::unordered_map<std::string, int> _uniformLocationCache;

    struct programSource {
        std::string vertexSource;
        std::string fragmentSource;
    };

public:
    enum type {
        NONE = -1,
        VERTEX_SHADER = 0,
        FRAGMENT_SHADER = 1
    };

public:
    Shader(const std::string &filename);
    ~Shader();

    void bind() const override;
    void unbind() const override;

    void setUniform4f(const std::string &name,
                      float v0, float v1, float v2, float v3);
    unsigned int create(const std::string &vertexShader,
                        const std::string &fragmentShader) const;

private:
    programSource parse() const;
    unsigned int compile(unsigned int type, const std::string &source) const;
    unsigned int getUniformLocation(const std::string &name);
};