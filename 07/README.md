# Episode 07: Writer a Shader in OpenGL

As discussed before, shaders are programs that will run on the GPU.
Programs are made out of source code, which must be compiled. So far in the course, source is read from a file or from a string, and compiled with OpenGL functions.

We've made a function to compile a shader (with error handling) and another function to create a shader, which will compile the shader from a string, attach it to a program (created with the use of glCreateProgram), and then return the id of the program.
Once linked, the shaders are no more useful. They can be deleted via glDeleteShader.

We've created a vertex shader to calculate the on-screen position of each vertex, and a fragment shader to calculate the color of each pixels. Both being compiled and attacked to a program, we tell OpenGL to use the resulting program with glUseProgram (we can then delete the shader).

And *voilà*, we've got a red triangle drawn on the screen!