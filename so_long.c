/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybahmaz <ybahmaz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 13:28:28 by ybahmaz           #+#    #+#             */
/*   Updated: 2025/02/03 12:58:51 by ybahmaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_so_long(t_map *map, char *name_map)
{
	int	n;

	n = ft_get_map_size(&map->width, &map->height, name_map);
	if (n == 0)
		return (0);
	map->map_data = malloc(sizeof(char *) * (map->height + 1));
	if (!map->map_data)
		return (0);
	if (ft_read_map(map, name_map) == 0)
	{
		ft_free(map->map_data);
		return (0);
	}
	map->c = ft_check_components(map, 'C');
	if (ft_check_error(map) == 0)
	{
		ft_free(map->map_data);
		return (0);
	}
	return (1);
}

int	so_long(char *name_map)
{
	t_mlx_data	*data;
	t_map		map;

	data = malloc(sizeof(t_mlx_data));
	if (!data)
		return (0);
	if (ft_so_long(&map, name_map) == 0)
	{
		free(data);
		return (0);
	}
	data->map = &map;
	data->mlx_ptr = mlx_init();
	if (!data->mlx_ptr)
		return (free(data), 0);
	data->window = mlx_new_window(data->mlx_ptr,
			map.width * SIZE, map.height * SIZE, "Window");
	if (!data->window)
		return (mlx_destroy_display(data->mlx_ptr),
			free(data->mlx_ptr), free(data), 0);
	ft_check_map(&map, data);
	map.n_move = 0;
	mlx_key_hook(data->window, ft_handle_input, data);
	mlx_hook(data->window, 17, 0, ft_close_window, data);
	return (mlx_loop(data->mlx_ptr), 1);
}

int	main(int argc, char *argv[])
{
	if (argc != 2)
	{
		write(2, "Error\nShould be 2 argument\n", 27);
		return (1);
	}
	if (ft_strcmp(argv[1], ".ber") == 0)
	{
		write(2, "Error\nThe name of map doesn't end with .ber\n", 44);
		return (1);
	}	
	if (!so_long(argv[1]))
		return (1);
	return (0);
}
