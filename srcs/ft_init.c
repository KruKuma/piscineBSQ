/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfurst <nfurst@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/15 13:20:49 by nfurst            #+#    #+#             */
/*   Updated: 2026/07/15 13:23:07 by nfurst           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

void	ft_init_map(t_map *map)
{
	map->rows = 0;
	map->cols = 0;
	map->empty = '\0';
	map->obstacle = '\0';
	map->full = '\0';
	map->grid = 0;
}

void	ft_init_square(t_square *square)
{
	square->row = 0;
	square->col = 0;
	square->size = 0;
}
