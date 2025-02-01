/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybahmaz <ybahmaz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 15:13:51 by ybahmaz           #+#    #+#             */
/*   Updated: 2025/02/01 16:17:13 by ybahmaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_read(t_map *map, int fd)
{
	int		i;
	int		nb;
	char	*line;

	i = 0;
	nb = 0;
	line = get_next_line(fd);
	while (line)
	{
		nb = ft_strlen(line);
		if (ft_strchr(line))
			nb -= 1;
		map->map_data[i] = ft_strdup(line);
		i++;
		if (!map->map_data)
			return (free(line), ft_free(map->map_data, map->height), 0);
		if (nb != map->width)
			return (write(2, "Error\nThe map isn't rectangular\n", 32), 0);
		free(line);
		line = get_next_line(fd);
	}
	map->map_data[i] = NULL;
	return (1);
}

int	ft_read_map(t_map *map, char *name_map)
{
	int		fd;

	fd = open(name_map, O_RDONLY);
	if (fd < 0)
		return (write(2, "Error\nFailed open file\n", 23), 0);
	if (ft_read(map, fd) == 0)
		return (0);
	return (close(fd), 1);
}
