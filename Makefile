CC = gcc
CFLAGS = -Wall -Werror -Wextra -pedantic -std=c89
SRC = monty.c stack_ops.c stack_ops2.c
OBJ = $(SRC:.c=.o)
NAME = monty

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(OBJ) -o $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re