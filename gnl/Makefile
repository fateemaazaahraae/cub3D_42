NAME = gnl
CFLAGS = -Wall -Wextra -Werror
CC = cc
SRC = get_next_line.c get_next_line_utils.c

OBJ = $(SRC:.c=.o)

all : $(NAME)

$(NAME) : $(OBJ)
		ar rc $(NAME) $(OBJ)

clean : 
		rm -f $(OBJ)

fclean : clean
		rm -f $(NAME)

re : fclean all

.PHONY : all clean fclean re
