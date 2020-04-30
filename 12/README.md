# Episode 12: Vertex Arrays in OpenGL

Vertex arrays store the format of the vertex data, as well as a reference to 
the vertex buffers (bound to it via `glBufferData` call, after `glBindBuffer`).

*see https://www.khronos.org/opengl/wiki/Vertex_Specification#Vertex_Array_Object*

By default, GLFW runs the *GLFW_OPENGL_COMPAT_PROFILE*, which creates a default 
Vertex Array Object (VAO), and uses it. If we want more control over it, or if 
we want to add multiple VAOs, we shall run GLFW in *GLFW_OPENGL_CORE_PROFILE*.

This is done like so:
```c++
// specify the glfw version (here, using 3.3.0)
glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
// define profile to use
glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
```

This implies we create and bind our own VAO(s), like so:
```c++
unsigned int vao;

glGenVertexArrays(1, &vao);
glBindVertexArray(vao);
```

Recommendation
---
A few years ago, NVIDIA recommended not to use VAOs (or more likely, to use only 
the default one, profided by the *GLFW_OPENGL_COMPAT_PROFILE*).

OpenGL recommends using them. Whether we choose to use them or not may depend 
on the project. In some cases, using them would be more efficient, in other 
cases, not. We could benchmark both solutions and make a choice. But by default, 
we will use them.