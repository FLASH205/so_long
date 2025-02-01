/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_path.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybahmaz <ybahmaz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 10:16:08 by ybahmaz           #+#    #+#             */
/*   Updated: 2025/02/01 16:29:16 by ybahmaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**ft_copy_map(t_map *map)
{
	char	**copy;
	int		i;

	copy = malloc(sizeof(char *) * (map->height + 1));
	if (!copy)
		return (NULL);
	i = 0;
	while (i < map->height)
	{
		copy[i] = ft_strdup(map->map_data[i]);
		if (!copy[i])
			return (ft_free(copy, map->height), NULL);
		i++;
	}
	copy[i] = NULL;
	return (copy);
}

int	ft_flood_fill(char **copy, int a, int b, t_map *map)
{
	int	i;

	i = 0;
	if (copy[b][a] == 'E')
		return (copy[b][a] = '1', 1);
	if (copy[b][a] == '1')
		return (0);
	if (copy[b][a] == 'C')
		i++;
	copy[b][a] = '1';
	i += ft_flood_fill(copy, a - 1, b, map);
	i += ft_flood_fill(copy, a + 1, b, map);
	i += ft_flood_fill(copy, a, b - 1, map);
	i += ft_flood_fill(copy, a, b + 1, map);
	return (i);
}

int	ft_check_path(t_map *map)
{
	char	**copy;

	copy = ft_copy_map(map);
	if (!copy)
		return (0);
	ft_find_player(map);
	if (ft_flood_fill(copy, map->x, map->y, map) != map->c + 1)
		return (write(2, "Error\nthe player is trapped\n", 28), 0);
	return (ft_free(copy, map->height), 1);
}
