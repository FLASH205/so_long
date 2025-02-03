/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybahmaz <ybahmaz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 15:28:19 by ybahmaz           #+#    #+#             */
/*   Updated: 2025/02/03 13:07:57 by ybahmaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef  SO_LONG_H
# define SO_LONG_H

# include "include/minilibx-linux/mlx.h"
# include "get_next_line.h"
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>

# ifndef SIZE
#  define SIZE 32
# endif

typedef struct s_map
{
	int		n_move;
	int		width;
	int		height;
	char	**map_data;
	void	*wall_img;
	void	*player_img;
	void	*collect_img;
	void	*enemy_img;
	void	*exit_img;
	void	*bg;
	int		x;
	int		y;
	int		c;
}	t_map;

typedef struct s_mlx_data
{
	void	*mlx_ptr;
	void	*window;
	void	*img;
	t_map	*map;
}	t_mlx_data;

int		ft_get_map_size(int *width, int *height, char *name_map);
int		ft_read_map(t_map *map, char *name_map);
void	ft_check_map(t_map *map, t_mlx_data *data);
int		ft_close_window(t_mlx_data *data);
int		ft_check_error(t_map *map);
int		ft_check_path(t_map *map);
int		ft_check_components(t_map *map, char c);
void	ft_find_player(t_map *map);
void	ft_free(char **arr);
void	ft_print_moves(int nbr);
int		ft_handle_input(int key, t_mlx_data *data);
int		ft_strcmp(char *s1, char *s2);

#endif