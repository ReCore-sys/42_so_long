NAME := so_long

CC := gcc

CFLAGS := -Wall -Wextra -Werror -Iheaders/ -O2

SOURCE := game_logic/*.c
GETNEXTLINE := get_next_line/*c
LIBRARY := -Lminilibx -lmlx -framework OpenGL -framework AppKit -Llibft -lft



all: $(NAME)

$(NAME): minilibx/libmlx.a libft/libft.a $(SOURCE)
	$(CC) $(CFLAGS) $(SOURCE) $(GETNEXTLINE) $(LIBRARY) -o $(NAME)

minilibx/libmlx.a:
	@make -C minilibx

libft/libft.a:
	@make -C libft

clean:
	make clean -C minilibx
	make clean -C libft

fclean:
	make clean -C minilibx
	make fclean -C libft
	rm -rf $(NAME)

re: fclean all

.PHONY: all fclean re clean