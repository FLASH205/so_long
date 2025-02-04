/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_moves_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybahmaz <ybahmaz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 13:26:46 by ybahmaz           #+#    #+#             */
/*   Updated: 2025/02/03 14:44:17 by ybahmaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_print_moves(int nbr)
{
	if (nbr >= 0 && nbr <= 9)
		ft_putchar(nbr + '0');
	else if (nbr >= 10)
	{
		ft_print_moves(nbr / 10);
		ft_putchar(nbr % 10 + '0');
	}
}
