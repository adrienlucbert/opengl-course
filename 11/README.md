# Episode 11: Uniforms in OpenGL

Uniforms are another way to pass data to a shader. Uniforms are declared in the 
shader source code, via the line `uniform <type> <name>`, then bound a value 
from C++ via :
- `glGetUniformLocation(<shader>, <name>)` (to get a uniform's id), and
- `glUniform<type>(<location>, <value>...)` (to set its actual value).

For instance:

*Shader source code*
```
uniform vec4 u_color;
```

*C++ code*
```c++
int location = glGetUniformLocation(shader, "u_color");
glUniform4f(location, r, 0.3f, 0.8f, 1.0f);
```

Uniforms are used to pass a value to a shader, which can be the pixels color or 
so. Uniforms values are set for a draw, which means a uniform cannot take 2 
different values in the same draw call (vertex attributes are used to do that).

We've also added `glfwSwapInterval(<interval>)` to the window init, which 
specifies "*the number of screen updates to wait from the time glfwSwapBuffers 
was called before swapping the buffers and returning.*"

*See https://www.glfw.org/docs/3.3/group__context.html#ga6d4e0cdf151b5e579bd67f13202994ed*