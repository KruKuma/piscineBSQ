/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amathey <arn.mathey@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/14 12:09:35 by nfurst            #+#    #+#             */
/*   Updated: 2026/07/14 13:50:53 by amathey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

void	ft_free_map(t_map *map)
{
	int	row;

	if (map == 0 || map-> grid == 0)
		return ;
	row = 0;
	while (row < map->rows)
	{
		if (map->grid[row] != 0)
			free(map->grid[row]);
		row++;
	}
	free(map->grid);
	map->grid = 0;
}
