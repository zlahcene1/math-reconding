SRC	=	$(wildcard *.cpp)

NAME	=	groundhog

CC	=	g++

CPPFLAGS	+=	-I./ -g3

CXXFLAGS = -Wall -Wextra -Werror

OBJ	=	$(SRC:.cpp=.o)

all:	$(NAME)

$(NAME):  $(OBJ)
	$(CC) -o $(NAME) $(OBJ) -lstdc++fs
	rm -f $(OBJ)
clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)
	rm -f $(OBJ)

re:	fclean all

.PHONY:	all clean fclean re
