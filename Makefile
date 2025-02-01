NAME = so_long
SRC = ft_check_error.c  ft_check_map.c  ft_check_path.c  ft_close_window.c  ft_get_map_size.c	\
	  ft_handle_input.c	ft_print_moves.c  ft_read_map.c  get_next_line.c  get_next_line_utils.c	\
	  so_long.c	ft_strcmp.c
OBJ = $(SRC:.c=.o)
MLX = -L include/minilibx-linux -lmlx -lX11 -lXext
FLAG = -Wextra -Wall -Werror

all : $(NAME)

$(NAME) : $(OBJ)
	cc $(FLAG) $(OBJ) $(MLX) -o $(NAME)

%.o: %.c so_long.h
	cc $(FLAG) -c $< -o $@

clean :
	rm -f $(OBJ)

fclean : clean
	rm -f $(NAME)

re : fclean all