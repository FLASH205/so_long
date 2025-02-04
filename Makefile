NAME = so_long
BNAME = so_long_bonus

SRC = ft_check_error.c  ft_check_map.c  ft_check_path.c  ft_close_window.c  ft_get_map_size.c ft_handle_input.c	\
		ft_print_moves.c  ft_read_map.c  get_next_line.c  get_next_line_utils.c	so_long.c	ft_strcmp.c
BSRC = 	ft_check_error_bonus.c  ft_check_map_bonus.c  ft_check_path_bonus.c  ft_close_window_bonus.c  ft_get_map_size_bonus.c  \
		ft_handle_input_bonus.c  ft_print_moves_bonus.c  ft_read_map_bonus.c  ft_strcmp_bonus.c  ft_animation_bonus.c	\
		so_long_bonus.c  get_next_line_utils_bonus.c  get_next_line_bonus.c

OBJ = $(SRC:.c=.o)
BOBJ = $(BSRC:.c=.o)

MLX = -L include/minilibx-linux -lmlx -lX11 -lXext
FLAG = -Wextra -Wall -Werror

all : $(NAME)

$(NAME) : $(OBJ)
	cc $(FLAG) $(OBJ) $(MLX) -o $(NAME)
$(BNAME) : $(BOBJ)
	cc $(FLAG) $(BOBJ) $(MLX) -o $(BNAME)

bonus: $(BNAME)

$(OBJ): %.o: %.c so_long.h get_next_line.h
	cc $(FLAG) -c $< -o $@
$(BOBJ): %.o: %.c so_long_bonus.h get_next_line.h
	cc $(FLAG) -c $< -o $@

clean :
	rm -f $(OBJ) $(BOBJ)

fclean : clean
	rm -f $(NAME) $(BNAME)

re : fclean all