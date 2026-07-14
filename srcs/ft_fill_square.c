/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill_square.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amathey <arn.mathey@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/13 20:28:37 by nfurst            #+#    #+#             */
/*   Updated: 2026/07/14 13:32:37 by amathey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

void	ft_fill_square(t_map *map, t_square square)
{
	int	row;
	int	col;
	int	start_row;
	int	start_col;

	if (square.size <= 0)
		return ;
	start_row = square.row - square.size + 1;
	start_col = square.col - square.size + 1;
	row = start_row;
	while (row <= square.row)
	{
		col = start_col;
		while (col <= square.col)
		{
			map->grid[row][col] = map->full;
			col++;
		}
		row++;
	}
}
