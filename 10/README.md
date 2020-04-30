# Episode 10: Dealing with Errors in OpenGL

OpenGL stores internally a queue of error codes whenever an error occurs. This 
queue can be polled with successive calls to `glGetError`().
Each call to it returns an error code, which can be printer for debug reasons.

This method, although not super convenient, is available since the first OpenGL 
versions. Nevertheless, there is another solution, from OpenGL 4.3: 
`glDebugMessageCallback`, which will be discussed in a future episode.

With the help of a few macros, we can call `glCall(<glFunction>)` in order to :
- clear OpenGL error queue
- call the given `glFunction`
- assert that no error occured. If an error occured, we log it to the console