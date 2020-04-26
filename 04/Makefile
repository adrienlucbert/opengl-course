CC	=	g++

SRCDIR	=	src/
SRC	=	main.cpp

OBJ	=	$(addprefix $(SRCDIR),$(SRC:.cpp=.o))

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

.PHONY: all clean fclean re