NAME = bsq

CC = cc
CFLAGS = -Wall -Wextra -Werror -g
INC = includes

SRC = srcs/main.c \
	srcs/ft_read_file.c \
	srcs/ft_parse_map.c \
	srcs/ft_parse_header.c \
	srcs/ft_parse_grid.c \
	srcs/ft_fill_square.c \
	srcs/ft_print_map.c \
	srcs/ft_solve_map.c \
	srcs/ft_square_sizes.c \
	srcs/ft_free_map.c \
	srcs/ft_print_error.c \
	srcs/ft_process_file.c \
	srcs/ft_utils.c

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
