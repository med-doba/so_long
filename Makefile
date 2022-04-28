NAME = so_long

CC = gcc 

CFLAGS = -Wall -Wextra -Werror

MLX_FLAGS = -lmlx -framework OpenGL -framework AppKit

HDR = so_long.h

SRC = so_long.c utils/so_long_utils.c utils/map_fct.c utils/print_map.c\
		get_next_line/get_next_line.c \
		get_next_line/get_next_line_utils.c \

OBJ = $(SRC:%.c=%.o)

LIBFT = libft/libft.a

PRINTF = printf/libftprintf.a

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT) $(PRINTF)
	@$(CC) $(CFLAGS) $(OBJ) $(LIBFT) $(PRINTF) $(MLX_FLAGS) -o $(NAME)

$(LIBFT):
	@make -C libft

$(PRINTF):
	@make -C printf

clean:
	@rm -rf $(OBJ)
	@make clean -C libft
	@make clean -C printf

fclean: clean
	@rm -rf $(NAME)
	@make fclean -C libft
	@make fclean -C printf

re: fclean all