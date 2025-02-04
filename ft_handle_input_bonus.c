/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_input_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybahmaz <ybahmaz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 13:26:49 by ybahmaz           #+#    #+#             */
/*   Updated: 2025/02/04 13:18:55 by ybahmaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	ft_find_player(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	map->y = 0;
	map->x = 0;
	while (i < map->height)
	{
		j = 0;
		while (j < map->width)
		{
			if (map->map_data[i][j] == 'P')
			{
				map->y = i;
				map->x = j;
			}
			j++;
		}
		i++;
	}
}

void	ft_move_player(t_mlx_data *data, int new_x, int new_y, t_map *map)
{
	if (new_x < 0 || new_y < 0 || new_x >= map->width || new_y >= map->height)
		return ;
	if (map->map_data[new_y][new_x] == 'E' && map->c == 0)
		ft_close_window(data, 0);
	if (map->map_data[new_y][new_x] == '1'
	|| map->map_data[new_y][new_x] == 'E' )
		return ;
	if (map->map_data[new_y][new_x] == 'M')
		ft_close_window(data, 0);
	if (map->map_data[new_y][new_x] == 'C')
		map->c--;
	map->map_data[new_y][new_x] = 'P';
	map->map_data[map->y][map->x] = '0';
	mlx_put_image_to_window(data->mlx_ptr,
		data->window, data->map->bg,
		map->x * SIZE, map->y * SIZE);
	mlx_put_image_to_window(data->mlx_ptr,
		data->window, data->map->player_img,
		new_x * SIZE, new_y * SIZE);
	map->y = new_y;
	map->x = new_x;
	map->n_move++;
	write(1, "Move: ", 6);
	ft_print_moves(map->n_move);
	write(1, "\n", 1);
}

int	ft_handle_input(int key, t_mlx_data *data)
{
	t_map	*map;

	map = data->map;
	if (key == 65307)
		ft_close_window(data, 0);
	ft_find_player(map);
	if (key == 119)
		ft_move_player(data, map->x, map->y - 1, map);
	if (key == 115)
		ft_move_player(data, map->x, map->y + 1, map);
	if (key == 100)
		ft_move_player(data, map->x + 1, map->y, map);
	if (key == 97)
		ft_move_player(data, map->x - 1, map->y, map);
	return (0);
}
