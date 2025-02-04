/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_animation_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybahmaz <ybahmaz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 16:03:57 by ybahmaz           #+#    #+#             */
/*   Updated: 2025/02/04 17:59:26 by ybahmaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	ft_find_enemies(t_mlx_data *data, t_map *map)
{
	int	i;
	int	j;
	int	k;

	k = 0;
	i = 0;
	while (i < map->height)
	{
		j = 0;
		while (j < map->width)
		{
			if (map->map_data[i][j] == 'M')
			{
				data->enemies[k].x = j;
				data->enemies[k].y = i;
				data->enemies[k].direction = 1;
				k++;
			}
			j++;
		}
		i++;
	}
}

void	ft_init_enemy(t_mlx_data *data, t_map *map)
{
	int	i;
	int	j;

	data->count_enemy = 0;
	i = 0;
	while (i < map->height)
	{
		j = 0;
		while (j < map->width)
		{
			if (map->map_data[i][j] == 'M')
				data->count_enemy++;
			j++;
		}
		i++;
	}
	data->enemies = malloc(sizeof(t_enemy) * data->count_enemy);
	if (!data->enemies)
		ft_close_window(data, 1);
	ft_find_enemies(data, map);
}

void	ft_move_enemy(t_mlx_data *data, t_enemy *enemy)
{
	int	new_x;

	new_x = enemy->x;
	if (enemy->direction == 1)
	{
		if (data->map->map_data[enemy->y][enemy->x] != '1')
			new_x++;
		else
			enemy->direction = -1;
	}
	else if (enemy->direction == -1)
	{
		if (data->map->map_data[enemy->y][enemy->x] != '1')
			new_x--;
		else
			enemy->direction = 1;
	}
	mlx_put_image_to_window(data->mlx_ptr, data->window, data->map->enemy_img,
		enemy->x * SIZE, enemy->y * SIZE);
}

int	ft_animation(t_mlx_data *data)
{
	static size_t	n;
	int				i;

	if (n % 12000 == 0)
	{
		data->current = (data->current + 1) % 3;
		mlx_put_image_to_window(data->mlx_ptr, data->window, data->frames[data->current], data->map->x * SIZE, data->map->y * SIZE);
	}
		i = 0;
	if (n % 20000 == 0)
	{
		while (i < data->count_enemy)
		{
			ft_move_enemy(data, &data->enemies[i]);
			i++;
		}
	}
	n++;
	return (1);
}
