/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfurst <nfurst@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/13 09:59:39 by nfurst            #+#    #+#             */
/*   Updated: 2026/07/14 11:30:30 by nfurst           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int	ft_is_digit(char c)
{
	return (c >= '0' && c <= '9');
}

int	ft_is_printable(char c)
{
	return (c >= 32 && c <= 126);
}

int	ft_atoi_n(char *str, int n)
{
	int	i;
	int	nb;

	i = 0;
	nb = 0;
	while (i < n)
	{
		nb = nb * 10 + (str[i] - '0');
		i++;
	}
	return (nb);
}

void	ft_init_map(t_map *map)
{
	map->rows = 0;
	map->cols = 0;
	map->empty = '\0';
	map->obstacle = '\0';
	map->full = '\0';
	map->grid = 0;
}
