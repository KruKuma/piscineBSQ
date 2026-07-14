/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_grid.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfurst <nfurst@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/13 19:26:11 by nfurst            #+#    #+#             */
/*   Updated: 2026/07/13 19:26:11 by nfurst           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int	ft_get_cols(char *content, int start)
{
	int	cols;

	cols = 0;
	while (content[start + cols] != '\n'
		&& content[start + cols] != '\0')
		cols++;
	return (cols);
}

int	ft_alloc_grid(t_map *map)
{
	int	i;

	map->grid = malloc(sizeof(char *) * map->rows);
	if (map->grid == 0)
		return (0);
	i = 0;
	while (i < map->rows)
	{
		map->grid[i] = 0;
		i++;
	}
	return (1);
}

int	ft_valid_cell(t_map *map, char c)
{
	return (c == map->empty || c == map->obstacle);
}

int	ft_fill_row(t_map *map, char *content, int *i, int row)
{
	int	col;

	map->grid[row] = malloc(sizeof(char) * (map->cols + 1));
	if (map->grid[row] == 0)
		return (0);
	col = 0;
	while (col < map->cols)
	{
		if (!ft_valid_cell(map, content[*i]))
			return (0);
		map->grid[row][col] = content[*i];
		(*i)++;
		col++;
	}
	if (content[*i] != '\n')
		return (0);
	map->grid[row][col] = '\0';
	(*i)++;
	return (1);
}

int	ft_fill_grid(t_map *map, char *content, int start)
{
	int	i;
	int	row;

	i = start;
	row = 0;
	while (row < map->rows)
	{
		if (!ft_fill_row(map, content, &i, row))
			return (0);
		row++;
	}
	if (content[i] != '\0')
		return (0);
	return (1);
}
