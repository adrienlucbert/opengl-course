# Episode 16: Writing a Basic Renderer in OpenGL

A renderer is an entity we tell "draw this". It abstracts a lot of stuff, among 
which a "rendering pipeline", and avoids repeating code.

For now, all our renderer does is clear the screen, and draw triangles, using 
a vertex array, an index buffer, and a shader. Pretty simple until now, but it 
will be subject to improvement in the future.

One problem that persists is our call to `shader.setUniform4f`. It cannot be 
moved in a *generic* renderer draw method. The solution to that is passing 
the draw method a **material** instead of a **shader**. This is to be done in 
the future as well.