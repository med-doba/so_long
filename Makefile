NAME = so_long

CC = cc

CFLAGS = -Wall -Wextra -Werror

MLX_FLAGS = -lmlx -framework OpenGL -framework AppKit

HDR = mandatory/so_long.h

SRC = mandatory/so_long.c mandatory/utils/so_long_utils.c mandatory/utils/map_fct.c mandatory/utils/print_map.c mandatory/utils/moves01.c mandatory/utils/moves02.c\
		get_next_line/get_next_line.c \
		get_next_line/get_next_line_utils.c \

SRC_BONUS = bonus/so_long_bonus.c bonus/utils/so_long_utils_bonus.c bonus/utils/map_fct_bonus.c bonus/utils/print_map_bonus.c bonus/utils/moves01_bonus.c bonus/utils/moves02_bonus.c\
		get_next_line/get_next_line.c \
		get_next_line/get_next_line_utils.c \

OBJ_BONUS = $(SRC_BONUS:%.c=%.o)

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

bonus: $(LIBFT) $(PRINTF) $(OBJ_BONUS)
	@$(CC) $(CFLAGS) $(OBJ_BONUS) $(LIBFT) $(PRINTF) $(MLX_FLAGS) -o so_long_bonus

clean:
	@rm -rf $(OBJ) $(OBJ_BONUS)
	@make clean -C libft
	@make clean -C printf

fclean: clean
	@rm -rf $(NAME) so_long_bonus
	@make fclean -C libft
	@make fclean -C printf

re: fclean all

.PHONY : bonus re all clean fclean
