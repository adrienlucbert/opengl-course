CC	=	g++

SRCDIR	=	src/
SRC	=	main.cpp			\
		Renderer.cpp		\
		BufferObject.cpp	\
		VertexBuffer.cpp	\
		IndexBuffer.cpp		\
		BufferLayout.cpp	\
		VertexArray.cpp

OBJ	=	$(addprefix $(SRCDIR),$(SRC:.cpp=.o))

DEBUG		=	-g
CXXFLAGS	=	-Iinclude
LDFLAGS		=	-lGLEW -lglfw -lGL

NAME	=	opengl

all:	$(NAME)

$(NAME):	$(OBJ)
	$(CC) $(OBJ) -o $(NAME) $(LDFLAGS)

run:	$(NAME)
	sh $(NAME)

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)

re:	fclean all

debug: CXXFLAGS += $(DEBUG)
debug: all

.PHONY: all clean fclean re