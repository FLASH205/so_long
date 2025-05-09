/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_map_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybahmaz <ybahmaz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 16:23:19 by ybahmaz           #+#    #+#             */
/*   Updated: 2025/02/04 17:05:21 by ybahmaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	ft_put_image(t_mlx_data *data, t_map *map, int i, int j)
{
	if (map->map_data[i][j] == '1')
		mlx_put_image_to_window(data->mlx_ptr, data->window,
			map->wall_img, map->x * j, map->y * i);
	else if (map->map_data[i][j] == 'P')
		mlx_put_image_to_window(data->mlx_ptr, data->window,
			map->player_img, map->x * j, map->y * i);
	else if (map->map_data[i][j] == 'C')
		mlx_put_image_to_window(data->mlx_ptr, data->window,
			map->collect_img, map->x * j, map->y * i);
	else if (map->map_data[i][j] == 'E')
		mlx_put_image_to_window(data->mlx_ptr, data->window,
			map->exit_img, map->x * j, map->y * i);
	else if (map->map_data[i][j] == 'M')
		mlx_put_image_to_window(data->mlx_ptr, data->window,
			map->enemy_img, map->x * j, map->y * i);
}

void	ft_check_map(t_map *map, t_mlx_data *data)
{
	int	i;
	int	j;

	map->wall_img = mlx_xpm_file_to_image(data->mlx_ptr,
			"textures/wall.xpm", &map->x, &map->y);
	map->player_img = mlx_xpm_file_to_image(data->mlx_ptr,
			"textures/player.xpm", &map->x, &map->y);
	map->collect_img = mlx_xpm_file_to_image(data->mlx_ptr,
			"textures/collect.xpm", &map->x, &map->y);
	map->exit_img = mlx_xpm_file_to_image(data->mlx_ptr,
			"textures/exit.xpm", &map->x, &map->y);
	map->enemy_img = mlx_xpm_file_to_image(data->mlx_ptr,
			"textures/enemy.xpm", &map->x, &map->y);
	map->bg = mlx_new_image(data->mlx_ptr, SIZE, SIZE);
	data->frames[0] = mlx_xpm_file_to_image(data->mlx_ptr, "textures/animation1.xpm", &map->x, &map->y);
	data->frames[1] = mlx_xpm_file_to_image(data->mlx_ptr, "textures/animation2.xpm", &map->x, &map->y);
	data->frames[2] = mlx_xpm_file_to_image(data->mlx_ptr, "textures/animation3.xpm", &map->x, &map->y);
	if (!map->wall_img || !map->player_img || !map->collect_img || !map->exit_img
		|| !map->bg || !data->frames[0] || !data->frames[1] || !data->frames[2])
		ft_close_window(data, 0);
	data->current = 0;
	ft_init_enemy(data, map);
	i = 0;
	while (i < map->height)
	{
		j = 0;
		while (j < map->width)
		{
			ft_put_image(data, map, i, j);
			j++;
		}
		i++;
	}
}
