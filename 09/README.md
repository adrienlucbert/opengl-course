# Episode 09: Index Buffers in OpenGL

Every shape in video games is made out of triangles. Wanna draw a square? Draw 
2 triangles side by side. But when doing so, 2 vertices are repeated, consuming 
memory space worthlessly.

```
3      2
o------o
|    / |
|  /   |
|/     |
o------o
0      1
```

To draw this shape, we may use 6 vertices
- first triangle: { 0, 1, 2 }
- second triangle: { 2, 3, 0 }

By doing so, if we define 3 vertices for our first triangle, and 3 vertices for 
our second triangle, vertices 0 and 2 are duplicated. We don't want to waste 
GPU memory.

To solve this, we can make index buffers. Our vertex buffer will contain all our 
vertices, each designated by an index. Our index buffer will contain which 
vertices (designated by their index) must be drawn.

We then have
```c++
// Defining vertices positions
float positions[] = {
    -0.5f, -0.5f,
    0.5f, -0.5f,
    0.5f, 0.5f,
    -0.5f, 0.5f
};

// Defining vertices to be drawn
unsigned int indices[] = {
    0, 1, 2,
    2, 3, 0
};
```

To create the index buffer in OpenGL, we pretty much do as we did to create the positions array buffer:

```c++
// Index buffer object
unsigned int ibo;
glGenBuffers(1, &ibo);
glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ibo);
glBufferData(GL_ELEMENT_ARRAY_BUFFER, 6 * sizeof(unsigned int), indices, GL_STATIC_DRAW);
```

In the rendering loop, we then replace the `glDrawArray` with a `glDrawElements` call:
```c++
glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, nullptr);
```

> Index buffer elements **MUST** always be unsigned (u char, u int, ...)
> If not, you will face a black screen in most cases.