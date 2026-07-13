NAME = bsq

CC = cc
CFLAGS = -Wall -Wextra -Werror -g
INC = includes

SRC = srcs/main.c \
	srcs/ft_read_file.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

srcs/%.o: srcs/%.c includes/bsq.h
	$(CC) $(CFLAGS) -I $(INC) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
