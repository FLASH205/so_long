/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_close_window_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybahmaz <ybahmaz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 15:12:33 by ybahmaz           #+#    #+#             */
/*   Updated: 2025/02/04 17:29:36 by ybahmaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	ft_free(char **arr)
{
	int	y;

	y = 0;
	while (arr[y])
	{
		free(arr[y]);
		y++;
	}
	free(arr);
}

void	ft_close_window(t_mlx_data *data, int n)
{
	if (data->map->wall_img)
		mlx_destroy_image(data->mlx_ptr, data->map->wall_img);
	if (data->map->player_img)
		mlx_destroy_image(data->mlx_ptr, data->map->player_img);
	if (data->map->collect_img)
		mlx_destroy_image(data->mlx_ptr, data->map->collect_img);
	if (data->map->exit_img)
		mlx_destroy_image(data->mlx_ptr, data->map->exit_img);
	if (data->map->enemy_img)
		mlx_destroy_image(data->mlx_ptr, data->map->enemy_img);
	if (data->map->bg)
		mlx_destroy_image(data->mlx_ptr, data->map->bg);
	if (data->frames[0])
		mlx_destroy_image(data->mlx_ptr, data->frames[0]);
	if (data->frames[1])
		mlx_destroy_image(data->mlx_ptr, data->frames[1]);
	if (data->frames[2])
		mlx_destroy_image(data->mlx_ptr, data->frames[2]);
	if (data->window)
		mlx_destroy_window(data->mlx_ptr, data->window);
	if (data->mlx_ptr)
	{
		mlx_destroy_display(data->mlx_ptr);
		free(data->mlx_ptr);
	}
	if (data->map && data->map->map_data)
		ft_free(data->map->map_data);
	if (data->enemies)
		free(data->enemies);
	if (data)
		free(data);
	exit(n);
}
