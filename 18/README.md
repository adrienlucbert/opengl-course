# Episode 18: Blending in OpenGL

## What is blending

Blending determines how we combine output color with what is already in our
target buffer.

## Control blending

### Enable/Disable blending

By default, OpenGL doesn't enable blending. To enable it, use `glEnable(GL_BLEND)`.
To disable it, use `glDisable(GL_BLEND)`.

### Define blending factors

`glBlendFunc(src, dest)`

- src: how the src rgba factor is computed (default is GL_ONE: src rgba * 1)
- src: how dest rgba factor is computed (default is GL_ZERO: dest rgba * 0)

`glBendEquation(mode)`

- mode: how we combine the src and dest colors (default is GL_FUNC_ADD: 1+0=1
 -> use source value)

