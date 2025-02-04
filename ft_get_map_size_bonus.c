/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_map_size_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybahmaz <ybahmaz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 15:14:20 by ybahmaz           #+#    #+#             */
/*   Updated: 2025/02/03 14:44:09 by ybahmaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	ft_get_size(int fd, int *width, int *height)
{
	char	*line;

	line = get_next_line(fd);
	if (!line)
	{
		write(2, "Error\nMap file is empty\n", 24);
		return (0);
	}
	while (line)
	{
		if (*width == 0)
			*width = ft_strlen(line) - 1;
		(*height)++;
		free(line);
		line = get_next_line(fd);
	}
	return (1);
}

int	ft_get_map_size(int *width, int *height, char *name_map)
{
	int		fd;
	int		n;

	*width = 0;
	*height = 0;
	fd = open(name_map, O_RDONLY);
	if (fd < 0)
	{
		write(2, "Error\nFailed to open file\n", 26);
		return (0);
	}
	n = ft_get_size(fd, width, height);
	close(fd);
	return (n);
}
