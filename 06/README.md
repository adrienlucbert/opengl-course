# Episode 06: How Shaders Work in OpenGL

> Shaders are no more than programs run on GPU (instead of CPU)

There are 2 main types of shaders:
- vertex shaders
- fragment (pixel) shader

## Vertex shader

The vertex shader will run once for each *vertex* of the rendered data.
For a simple triangle, defined by 3 vertices, a vertex shader will be run 3 
times, and calculate the positions on the screen at which vertices should be 
rendered.

## Fragment shader

The fragment shader will run once for each *pixel* of the rendered data.
For a simple triangle, defined by 3 vertices, a fragment shader will be run an 
amount of times equivalent to the number of pixels in the triangle (which 
could be millions of times).
A fragment shader will calculate essentially the color of a pixel (taking into 
account to lightnings, colors, ...).

> In terms of optimization, we must chose wisely where to do calculations, 
> whether on vertex shaders, fragment shaders, or CPU.