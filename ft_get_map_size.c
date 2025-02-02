/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_map_size.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youssef <youssef@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 15:14:20 by ybahmaz           #+#    #+#             */
/*   Updated: 2025/02/02 19:01:29 by youssef          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_get_size(int fd, int *width, int *height)
{
	char	*line;

	line = get_next_line(fd);
	if (!line)
	{
		close(fd);
		write(2, "Error\nMap file is empty\n", 24);
		exit(1);
	}
	while (line)
	{
		if (*width == 0)
			*width = ft_strlen(line) - 1;
		(*height)++;
		free(line);
		line = get_next_line(fd);
	}
}

void	ft_get_map_size(int *width, int *height, char *name_map)
{
	int		fd;

	*width = 0;
	*height = 0;
	fd = open(name_map, O_RDONLY);
	if (fd < 0)
	{
		write(2, "Error\nFailed to open file\n", 26);
		exit(1);
	}
	ft_get_size(fd, width, height);
	close(fd);
}
