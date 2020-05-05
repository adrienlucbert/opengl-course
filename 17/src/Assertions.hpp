/**
 * @brief Assertions utils
 * @date 2020-05-05
 */

#pragma once

#include "OpenGL.hpp"

#define ASSERT(x) \
    if (!(x))     \
    __builtin_trap()

#define glCall(x)   \
    glClearError(); \
    x;              \
    ASSERT(glLogCall(#x, __FILE__, __LINE__))

void glClearError();
bool glLogCall(const char *function, const char *file, int line);
