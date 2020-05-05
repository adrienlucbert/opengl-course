# Episode 17: Textures in OpenGL

## Loading an image file

First, we need to parse an image file as an array of pixels. To do that, we 
used the **STB Image library** (https://github.com/nothings/stb).

Next we can parse an image file using `stbi_load` (from **STB**). We get a 
pixels buffer as an allocated `unsigned char *`.

*Note that OpenGL expects the pixel buffers to start from the bottom-left of 
the image. Thus, we need to flip vertically to image when loading it, using the 
`stbi_set_flip_vertically_on_load` function (from **STB** as well).*

## Rendering the texture

After that, as for any other *dindable* data structure, we can generate and bind 
the texture, using `glGenTextures` and `glBindTexture`.
We then need to set a few parameters through `glTexParameteri`, to tell OpenGL 
how to handle our texture:
- how to minify it (`GL_TEXTURE_MIN_FILTER`)
- how to magnify it (`GL_TEXTURE_MAG_FILTER`)
- how to horizontally wrap it (`GL_TEXTURE_WRAP_S`)
- how to vertically wrap it (`GL_TEXTURE_WRAP_T`)

Then we send the texture data to OpenGL via `glTexImage2D`, and free the image 
pixels buffer (no longer needed).

Before binding the texture, we need to make the texture *active* with 
`glActiveTexture(<slot>)`. This will tell the next texture we will bind will be 
bound to slot \<slot\>. Slot here is defined by the enum GL_TEXTURE\<0-31\>.
Depending on the platform, you will be able to support more or less slots.
Usually, mobile devices may have 8 slots, ...

We abstracted the GL_TEXTURE\<id\> enum with our `Texture::bind` method. It 
takes an unsigned int as parameter, which is the id of the desired slot.

### Shader and textures

Now we need to modify the shaders to be able to render a texture. We send the 
texture slot to the fragment shader as a `sampler2D` uniform.

We also have to define texture coordinates. Tell the geometry being rendered 
which part of the texture to sample from. For that, we added 2 coordinates to 
each *position* (vertex coordinates), defining the corresponding x and y 
coordinates on the texture.

The texture coordinates (as a `vec2`) is passed to our vertex shader, but it 
also needs to be passed to the fragment shader:
- in the vertex shader, we use `out vec2 v_texCoord;`, and set `v_texCoord = texCoord` in the main function to send it to the fragment shader
- in the fragment shader, we retrieve it, using `in vec2 v_texCoord`, then determine a pixel's color in the main function with `vec4 texColor = texture(u_texture, v_texCoord` (u_texture being the texture slot uniform), and assign this color to the current pixel, with `color = texColor`.

## Misc improvements

I renamed the OpenGL Object abstract class from A_GLObject to ABindable (because it can be bound, and a texture can be bound, without being an OpenGL Object).

I also extracted OpenGL includes and assert macros from `Renderer.hpp` into `OpenGL.hpp` and `Assertions.hpp`.