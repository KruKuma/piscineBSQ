/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solve_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfurst <nfurst@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/13 20:00:22 by nfurst            #+#    #+#             */
/*   Updated: 2026/07/13 20:00:22 by nfurst           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int		**ft_create_square_sizes(t_map *map);
void	ft_free_square_sizes(int **square_sizes, int rows);
void	ft_fill_square(t_map *map, t_square square);

int ft_fill_square_sizes(t_map *map, int **square_sizes, t_square *largest_square)
{
    int row;
    int col;

    row = 0;
    while (row < map->rows)
    {
        col = 0;
        while (col < map->cols)
        {
            square_sizes[row][col] = ft_cell_value(map, square_sizes, row, col);
            ft_update_largest_square(largest_square, square_sizes[row][col], row, col);
            col++;
        }
        row++;
    }
    return (1);
}

int ft_solve_map(t_map *map)
{
    int **square_sizes;
    t_square largest_square;

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
