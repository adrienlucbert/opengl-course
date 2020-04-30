# Episode 13: Abstracting OpenGL into Classes

Many OpenGL components have a lifecycle. For instance, an OpenGL Object (such 
as a VertexArray or an IndexBuffer) will be created with `glGen*(...)`, and 
destroyed with `glDestroy*(...)`.

This behaviour can therefore be easily abstracted into classes. We can also add 
function calls we need to initialize / bind / unbind / ... each data type.

This way, we have abstracted OpenGL Objects, Buffer Objects, IndexBuffers, 
VertexBuffers, and VertexArrays.