/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_map_size.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybahmaz <ybahmaz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 15:14:20 by ybahmaz           #+#    #+#             */
/*   Updated: 2025/02/01 15:15:53 by ybahmaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_get_map_size(int *width, int *height, char *name_map)
{
	int		fd;
	char	*line;

	*width = 0;
	*height = 0;
	fd = open(name_map, O_RDONLY);
	line = get_next_line(fd);
	while (line)
	{
		if (*width == 0)
			*width = ft_strlen(line) - 1;
		(*height)++;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
}
