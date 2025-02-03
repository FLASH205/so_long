/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_error.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybahmaz <ybahmaz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 10:12:06 by ybahmaz           #+#    #+#             */
/*   Updated: 2025/02/03 09:22:16 by ybahmaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_check_wall(t_map *map)
{
	int	x;
	int	y;

	y = 0;
	while (y < map->width)
	{
		if (map->map_data[0][y] != '1'
		|| map->map_data[map->height - 1][y] != '1')
			return (0);
		y++;
	}
	x = 1;
	while (x < map->height - 1)
	{
		if (map->map_data[x][0] != '1'
		|| map->map_data[x][map->width - 1] != '1')
			return (0);
		x++;
	}
	return (1);
}

int	ft_check_components(t_map *map, char c)
{
	int	i;
	int	j;
	int	n;

	i = 0;
	n = 0;
	while (i < map->height)
	{
		j = 0;
		while (j < map->width)
		{
			if (map->map_data[i][j] == c)
				n++;
			j++;
		}
		i++;
	}
	return (n);
}

int	ft_check_error(t_map *map)
{
	if (ft_check_wall(map) == 0)
		return (write(2, "Error\nInvalid map\n", 18), 0);
	else if (ft_check_components(map, 'P') > 1)
		return (write(2, "Error\nMore than one player in map\n", 34), 0);
	else if (ft_check_components(map, 'P') == 0)
		return (write(2, "Error\nThe player doesn't exist in map\n", 39), 0);
	else if (ft_check_components(map, 'E') > 1)
		return (write(2, "Error\nMore than one exit in map\n", 32), 0);
	else if (ft_check_components(map, 'E') == 0)
		return (write(2, "Error\nThe exit doesn't exist in map\n", 36), 0);
	else if (map->c < 1)
		return (write(2, "Error\nThe collectible doesn't exist in map\n", 43), 0);
	else if (ft_check_path(map) == 0)
		return (0);
	return (1);
}
