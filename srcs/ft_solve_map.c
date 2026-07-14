/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solve_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amathey <arn.mathey@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/13 20:00:22 by nfurst            #+#    #+#             */
/*   Updated: 2026/07/14 13:47:20 by amathey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int		**ft_create_square_sizes(t_map *map);
void	ft_free_square_sizes(int **square_sizes, int rows);
void	ft_fill_square(t_map *map, t_square square);

int	ft_min(int a, int b, int c)
{
	int	min;

	min = a;
	if (b < min)
		min = b;
	if (c < min)
		min = c;
	return (min);
}

int	ft_cell_value(t_map *map, int **square_sizes, int row, int col)
{
	if (map->grid[row][col] == map->obstacle)
		return (0);
	if (row == 0 || col == 0)
		return (1);
	return (ft_min(square_sizes[row - 1][col],
		square_sizes[row][col - 1],
		square_sizes[row - 1][col - 1]) + 1);
}

void	ft_update_largest_square(t_square *largest_square, int size,
	int row, int col)
{
	if (size > largest_square->size)
	{
		largest_square->size = size;
		largest_square->row = row;
		largest_square->col = col;
	}
}

int	ft_fill_square_sizes(t_map *map, int **square_sizes,
	t_square *largest_square)
{
	int	row;
	int	col;

	row = 0;
	while (row < map->rows)
	{
		col = 0;
		while (col < map->cols)
		{
			square_sizes[row][col] = ft_cell_value(map, square_sizes, row, col);
			ft_update_largest_square(largest_square,
				square_sizes[row][col], row, col);
			col++;
		}
		row++;
	}
	return (1);
}

int	ft_solve_map(t_map *map)
{
	int			**square_sizes;
	t_square	largest_square;

	square_sizes = ft_create_square_sizes(map);
	if (square_sizes == 0)
		return (0);
	largest_square.size = 0;
	largest_square.row = 0;
	largest_square.col = 0;
	ft_fill_square_sizes(map, square_sizes, &largest_square);
	ft_fill_square(map, largest_square);
	ft_free_square_sizes(square_sizes, map->rows);
	return (1);
}
