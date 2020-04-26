# Episode 04: Vertex Buffers and Drawing a Triangle in OpenGL

Creating and binding a data buffer. The triangle is not rendered yet, because 
OpenGL misses information about how to use the data buffer to render it.

> OpenGL being a state machine, glBindBuffers tells OpenGL to use the given 
> buffer for the rest of the code, until a new buffer is binded.