/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_map_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybahmaz <ybahmaz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 15:13:51 by ybahmaz           #+#    #+#             */
/*   Updated: 2025/02/03 14:44:20 by ybahmaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	ft_read(t_map *map, int fd)
{
	int		i;
	int		nb;
	char	*line;

	i = 0;
	nb = 0;
	line = get_next_line(fd);
	while (i < map->height)
	{
		nb = ft_strlen(line);
		if (ft_strchr(line))
			nb -= 1;
		map->map_data[i] = line;
		map->map_data[i + 1] = NULL;
		if (!map->map_data[i])
			return (get_next_line(-1), 0);
		i++;
		if (nb != map->width)
			return (get_next_line(-1),
				write(2, "Error\nThe map isn't rectangular\n", 32), 0);
		line = get_next_line(fd);
	}
	return (1);
}

int	ft_read_map(t_map *map, char *name_map)
{
	int		fd;
	int		n;

	fd = open(name_map, O_RDONLY);
	if (fd < 0)
		return (write(2, "Error\nFailed open file\n", 23), 0);
	n = ft_read(map, fd);
	close(fd);
	return (n);
}
