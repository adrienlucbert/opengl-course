/**
 * @brief Renderer class
 * @date 2020-04-30
 */

#pragma once

#include <GL/glew.h>

#define ASSERT(x) \
    if (!(x))     \
    __builtin_trap()

#define glCall(x)   \
    glClearError(); \
    x;              \
    ASSERT(glLogCall(#x, __FILE__, __LINE__))

void glClearError();
bool glLogCall(const char *function, const char *file, int line);