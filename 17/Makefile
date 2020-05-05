CC	=	g++

SRCDIR	=	src/
SRC	=	main.cpp			\
		Renderer.cpp		\
		BufferObject.cpp	\
		VertexBuffer.cpp	\
		IndexBuffer.cpp		\
		BufferLayout.cpp	\
		VertexArray.cpp		\
		Shader.cpp			\
		Texture.cpp

OBJ	=	$(addprefix $(SRCDIR),$(SRC:.cpp=.o))

VENDORDIR	=	$(SRCDIR)vendor/
VENDOR	=	stb/stb_image.cpp

VENDOROBJ	=	$(addprefix $(VENDORDIR),$(VENDOR:.cpp=.o))

DEBUG		=	-g
CXXFLAGS	=	-Iinclude -Isrc/vendor
LDFLAGS		=	-lGLEW -lglfw -lGL

NAME	=	opengl

all:	$(NAME)

$(NAME):	$(OBJ) $(VENDOROBJ)
	$(CC) $(OBJ) $(VENDOROBJ) -o $(NAME) $(LDFLAGS)

vendor:	$(VENDOROBJ)

run:	$(NAME)
	sh $(NAME)

clean:
	rm -f $(OBJ)
	rm -f $(VENDOROBJ)

fclean:	clean
	rm -f $(NAME)

re:	fclean all

debug: CXXFLAGS += $(DEBUG)
debug: all

.PHONY: all clean fclean re